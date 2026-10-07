/*
  This example reads audio data from the on-board PDM microphones, and prints
  out the samples to the Serial console. The Serial Plotter built into the
  Arduino IDE can be used to plot the audio data (Tools -> Serial Plotter)

  Circuit:
  - Arduino Nano 33 BLE board

  This example code is in the public domain.
*/

#include <PDM.h>

// default number of output channels
// Nano 33 BLE only supports 1 channel
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

		// Print samples to the serial monitor or plotter
		for (int i = 0; i < samplesRead; i++) {
			if (channels == 2) {
				Serial.print("L:");
				Serial.print(sampleBuffer[i]);
				Serial.print(" R:");
				i++;
			}
			Serial.println(sampleBuffer[i]);
		}

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
