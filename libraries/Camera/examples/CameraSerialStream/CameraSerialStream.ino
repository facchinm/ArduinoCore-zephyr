/*
  Camera to Serial Streamer

  Requirements:
  - An Arduino board with a supported camera (e.g. Portenta H7, GIGA R1)

  Streams camera frames to a host PC over the USB serial port using a small
  framed protocol, so the viewer discovers the resolution and pixel format
  from the wire instead of having them hardcoded in two places.

  How to use this example:

  1. Change CAMERA_WIDTH / CAMERA_HEIGHT / CAMERA_FORMAT below if you want
     a different mode. Nothing needs to change on the host side.

  2. Upload this sketch to the board.

  3. Make sure no serial monitor or other program is keeping the serial
     port open.

  4. Run the host script provided in the library extras folder:
       extras/CameraSerialViewer/CameraSerialViewer.py
     It opens a live preview window and shows the frame rate and throughput.
*/

#include "camera.h"

// Capture settings. The host reads these from the frame header.
#define CAMERA_WIDTH  320
#define CAMERA_HEIGHT 240
#define CAMERA_FORMAT CAMERA_RGB565

// Set to true to emit little-endian RGB565. The header records which was
// used, so the viewer handles either.
#define CAMERA_BYTE_SWAP false

#define CAMERA_BPP    (CAMERA_FORMAT == CAMERA_RGB565 ? 2 : 1)
#define CAMERA_BYTES  (CAMERA_WIDTH * CAMERA_HEIGHT * CAMERA_BPP)

// Protocol
#define PROTO_VERSION      1
#define PROTO_CMD_REQUEST  'R'
#define PROTO_FLAG_LE      (1 << 0)

struct __attribute__((packed)) FrameHeader {
  uint8_t  sync[4];
  uint8_t  version;
  uint8_t  format;
  uint8_t  flags;
  uint8_t  reserved;
  uint16_t width;
  uint16_t height;
  uint32_t length;
  uint32_t seq;
};

Camera cam;
static uint32_t frame_seq = 0;
static uint32_t pending = 0;

void fatal_error(const char *msg) {
  Serial.println(msg);
  pinMode(LED_BUILTIN, OUTPUT);
  while (1) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
  }
}

// Returns false if no frame was ready, so the caller can keep the request
// outstanding and try again on the next pass instead of sending nothing.
bool send_frame() {
  FrameBuffer fb;

  if (!cam.grabFrame(fb, 100)) {
    return false;
  }

  if (fb.getBufferSize() != CAMERA_BYTES) {
    cam.releaseFrame(fb);
    fatal_error("Frame size does not match the configured resolution");
  }

  FrameHeader hdr;
  hdr.sync[0]  = 0xD5;
  hdr.sync[1]  = 0xAA;
  hdr.sync[2]  = 0x96;
  hdr.sync[3]  = 0x5A;
  hdr.version  = PROTO_VERSION;
  hdr.format   = CAMERA_FORMAT;
  hdr.flags    = CAMERA_BYTE_SWAP ? PROTO_FLAG_LE : 0;
  hdr.reserved = 0;
  hdr.width    = CAMERA_WIDTH;
  hdr.height   = CAMERA_HEIGHT;
  hdr.length   = CAMERA_BYTES;
  hdr.seq      = frame_seq++;

  Serial.write((uint8_t *)&hdr, sizeof(hdr));
  Serial.write(fb.getBuffer(), fb.getBufferSize());

  cam.releaseFrame(fb);
  return true;
}

void setup(void) {
  Serial.begin(115200);
  if (!cam.begin(CAMERA_WIDTH, CAMERA_HEIGHT, CAMERA_FORMAT, CAMERA_BYTE_SWAP)) {
    fatal_error("Camera begin failed");
  }
  cam.setVerticalFlip(false);
  cam.setHorizontalMirror(false);
}

void loop() {
  int cmd;

  // Drain every pending request. Sending a frame takes long enough that
  // reading only one byte per pass would never let requests accumulate.
  while ((cmd = Serial.read()) >= 0) {
    if (cmd == PROTO_CMD_REQUEST) {
      pending++;
    }
  }

  // A request stays outstanding until a frame is actually sent for it.
  if (pending && send_frame()) {
    pending--;
  }
}
