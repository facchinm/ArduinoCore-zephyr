/*
  Camera to Display

  Requirements:
  - An Arduino board with both a supported camera and a display, for example a
    GIGA R1 with the GIGA Display Shield.

  Shows the camera output on the display. The sensor is landscape and the panel
  is portrait, so each frame is rotated 90 degrees clockwise and scaled up by
  whatever whole number fits, then written into the display framebuffer.

  How to use this example:

  1. Change CAMERA_WIDTH / CAMERA_HEIGHT below if you want a different mode.
     The rotation, scale factor and centring all follow from it.

  2. Upload this sketch to the board.

  The frame rate is printed to Serial once a second. Most of the frame time
  goes on the rotation, since neither the LTDC nor DMA2D can transpose.

  Set CONFIG_STM32_LTDC_FB_NUM=2 to avoid tearing, at the cost of one more full
  screen buffer in SDRAM.
*/

#include "camera.h"
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

#if !DT_HAS_CHOSEN(zephyr_display)
#warning "This example needs a board with a display, it does nothing here."

void setup() {
  Serial.begin(115200);
  Serial.println("This example needs a board with a display.");
}

void loop() {
}

#else

// Capture settings.
#define CAMERA_WIDTH  320
#define CAMERA_HEIGHT 240

#define DISPLAY_NODE  DT_CHOSEN(zephyr_display)
#define DISPLAY_W     DT_PROP(DISPLAY_NODE, width)
#define DISPLAY_H     DT_PROP(DISPLAY_NODE, height)
#define DISPLAY_BYTES (DISPLAY_W * DISPLAY_H * 2)

// Two or more buffers means no tearing, one means the frame is drawn into the
// buffer being scanned out. Zero means the application owns them, unsupported.
#define FB_COUNT      CONFIG_STM32_LTDC_FB_NUM

#if FB_COUNT < 1
#error "Set CONFIG_STM32_LTDC_FB_NUM to 1 or more."
#endif

// Rotating 90 degrees swaps the axes.
#define ROT_W         CAMERA_HEIGHT
#define ROT_H         CAMERA_WIDTH

// Largest whole number scale that still fits the panel, then centre the result.
#define SCALE         MIN(DISPLAY_W / ROT_W, DISPLAY_H / ROT_H)
#define OUT_X         ((DISPLAY_W - (ROT_W * SCALE)) / 2)
#define OUT_Y         ((DISPLAY_H - (ROT_H * SCALE)) / 2)

#if SCALE < 1
#error "Rotated camera frame is larger than the display, pick a smaller mode."
#endif

// The camera and display buffers both live in external SDRAM, where a strided
// write costs a row activation. Walking the frame in tiles keeps each tile's
// reads and writes inside a few open rows.
#define TILE          16

Camera cam;
const struct device *display_dev;

// The driver's buffers are one contiguous allocation, so the base is enough.
static uint8_t *fb_base;

void fatal_error(const char *msg) {
  pinMode(LED_BUILTIN, OUTPUT);
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    Serial.println(msg);
  }
}

// Any buffer that is not the one on display, so display_write() can swap it in
// on the vertical blank. Falls back to the displayed one if it is the only one.
static uint16_t *draw_buffer(void) {
  uint8_t *front = (uint8_t *)display_get_framebuffer(display_dev);

  for (int i = 0; i < FB_COUNT; i++) {
    uint8_t *buf = fb_base + i * DISPLAY_BYTES;

    if (buf != front) {
      return (uint16_t *)buf;
    }
  }

  return (uint16_t *)front;
}

/*
 * Rotate clockwise and scale up in one pass: panel pixel (x, y) comes from
 * camera pixel (CAMERA_HEIGHT - 1 - x / SCALE, y / SCALE). Iterating over the
 * source instead of the destination keeps the sensor reads sequential and
 * turns the scale into a small block store, which is why nothing here
 * interpolates. With SCALE == 1 the block loops fold away entirely.
 */
static void rotate_and_scale(const uint16_t *src, uint16_t *dst) {
  for (int tx = 0; tx < ROT_W; tx += TILE) {
    int x_end = MIN(tx + TILE, ROT_W);

    for (int ty = 0; ty < ROT_H; ty += TILE) {
      int y_end = MIN(ty + TILE, ROT_H);

      for (int x = tx; x < x_end; x++) {
        const uint16_t *s = src + (CAMERA_HEIGHT - 1 - x) * CAMERA_WIDTH + ty;
        uint16_t *d = dst + (OUT_Y + ty * SCALE) * DISPLAY_W + OUT_X + x * SCALE;

        for (int y = ty; y < y_end; y++) {
          uint16_t pixel = *s++;

          for (int sy = 0; sy < SCALE; sy++) {
            for (int sx = 0; sx < SCALE; sx++) {
              d[sy * DISPLAY_W + sx] = pixel;
            }
          }

          d += DISPLAY_W * SCALE;
        }
      }
    }
  }
}

void setup(void) {
  Serial.begin(115200);

  if (!cam.begin(CAMERA_WIDTH, CAMERA_HEIGHT, CAMERA_RGB565, true)) {
    fatal_error("Camera begin failed");
  }

  cam.setVerticalFlip(false);
  cam.setHorizontalMirror(false);

  display_dev = DEVICE_DT_GET(DISPLAY_NODE);
  if (!device_is_ready(display_dev)) {
    fatal_error("Display not ready");
  }

  // The scale factor and the offsets are computed from the devicetree, so a
  // driver reporting a different geometry would have us writing out of bounds.
  struct display_capabilities caps;
  display_get_capabilities(display_dev, &caps);
  if (caps.x_resolution != DISPLAY_W || caps.y_resolution != DISPLAY_H) {
    fatal_error("Display geometry does not match the devicetree");
  }
  if (caps.current_pixel_format != PIXEL_FORMAT_RGB_565) {
    fatal_error("Display is not in RGB565");
  }

  fb_base = (uint8_t *)display_get_framebuffer(display_dev);

  // Clear every buffer, so the border left by centring stays black whichever is
  // on display. The per-frame pass only ever touches the image itself.
  display_blanking_on(display_dev);
  memset(fb_base, 0, FB_COUNT * DISPLAY_BYTES);
  display_blanking_off(display_dev);

  Serial.print("camera ");
  Serial.print(CAMERA_WIDTH);
  Serial.print("x");
  Serial.print(CAMERA_HEIGHT);
  Serial.print(" -> display ");
  Serial.print(DISPLAY_W);
  Serial.print("x");
  Serial.print(DISPLAY_H);
  Serial.print(" rotated, scale ");
  Serial.println(SCALE);
}

void loop() {
  static struct display_buffer_descriptor desc = {
    .buf_size = DISPLAY_BYTES,
    .width = DISPLAY_W,
    .height = DISPLAY_H,
    .pitch = DISPLAY_W,
  };
  static unsigned long last_report = 0;
  static unsigned int frames = 0;
  FrameBuffer fb;

  if (!cam.grabFrame(fb, 100)) {
    return;
  }

  uint16_t *dst = draw_buffer();

  rotate_and_scale((const uint16_t *)fb.getBuffer(), dst);
  cam.releaseFrame(fb);

  // A full screen write, so the driver takes this buffer as is. When it is not
  // the one on display it blocks until the LTDC has been pointed at it.
  display_write(display_dev, 0, 0, &desc, dst);

  frames++;
  if (millis() - last_report >= 1000) {
    Serial.print(frames);
    Serial.println(" fps");
    frames = 0;
    last_report = millis();
  }
}

#endif // DT_HAS_CHOSEN(zephyr_display)
