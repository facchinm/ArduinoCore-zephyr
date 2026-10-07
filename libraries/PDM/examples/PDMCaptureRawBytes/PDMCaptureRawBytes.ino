/*
  Nano 33 BLE Microphone to Serial Streamer

  Circuit:
  - Arduino Nano 33 BLE board

  How to use this example:

  1. Upload this sketch to the board. Microphone acquisition starts
     immediately and raw audio samples are streamed over the serial port.

  2. Make sure no serial monitor or other program is keeping the serial
     port open.

  3. Run the host script provided in the library extras folder:
       extras/PDMSerialAudioRecorder/PDMSerialAudioRecorder.py
     It reads the samples streamed by this sketch and packs them into a
     WAV file you can play back on your PC.

  Notes:

  - The host script uses /dev/ttyACM0 as the default serial device; change
    it if your board enumerates as a different device.
  - The host script records about 5 seconds of audio.
*/

#include <PDM.h>
// default number of output channels
static const char channels = 1;
// default PCM output frequency
static const int frequency = PDM_SAMPLE_RATE;

// Buffer to read samples into. For best performance, match its size to the
// buffer used internally by the PDM library (PDM_NUMBER_OF_SAMPLES).
// PDMSample follows the configured PCM width (16- or 24-bit).
PDMSample sampleBuffer[PDM_NUMBER_OF_SAMPLES];

// Number of samples read
volatile int samplesRead;

void setup() {
	Serial.begin(115200);
	while (!Serial)
		;

	// Configure the data receive callback
	PDM.onReceive(onPDMdata);

	// Initialize PDM:
	// - one channel (Mono)
	// - 16 kHz sample rate (Standard for voice)
	if (!PDM.begin(channels, frequency)) {
		Serial.println("Failed to start PDM!");
		while (1)
			;
	}
}

void loop() {
	// Wait for samples to be read
	if (samplesRead) {

		// Write the raw bytes to the Serial port
		// We send byte-by-byte to keep it fast and binary
		Serial.write((uint8_t *)sampleBuffer, samplesRead * sizeof(PDMSample));
		// Clear the read count
		samplesRead = 0;
	}
}

// Callback for the PDM "on receive" event.
// The PDM library calls this function as soon as a new buffer of samples is
// ready to be read. Read from PDM as fast as possible, otherwise data will be
// lost.
void onPDMdata() {
	// Read into the sample buffer
	int bytesRead = PDM.read(sampleBuffer, sizeof(sampleBuffer));

	samplesRead = bytesRead / sizeof(PDMSample);
}
