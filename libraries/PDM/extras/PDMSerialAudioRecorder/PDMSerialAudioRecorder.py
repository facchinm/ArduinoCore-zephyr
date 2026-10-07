# Copyright (c) Arduino s.r.l. and/or its affiliated companies
#
# SPDX-License-Identifier: Apache-2.0

import struct
import time
import wave

import serial

# --- CONFIGURATION ---
SERIAL_PORT = "/dev/ttyACM0"  # CHECK YOUR ARDUINO IDE FOR THE CORRECT PORT!
BAUD_RATE = 115200
OUTPUT_FILENAME = "recording.wav"
RECORD_SECONDS = 5  # How long to record
SAMPLE_RATE = 16000  # Must match Arduino sketch
# Must match the sketch's PDM_SAMPLE_BIT_WIDTH (16 on Nano 33 BLE, 24 on GIGA).
# 24-bit samples are streamed sign-extended in a 4-byte little-endian int32.
SAMPLE_WIDTH_BITS = 16
# ---------------------


def record_audio():
    # Bytes per sample on the wire: 24-bit is sent as a 4-byte int32, 16-bit as 2 bytes
    in_bytes_per_sample = 4 if SAMPLE_WIDTH_BITS == 24 else 2
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
        print(f"Connected to {SERIAL_PORT}. Recording for {RECORD_SECONDS} seconds...")

        # Clear buffer to avoid old data
        ser.reset_input_buffer()

        audio_frames = []
        start_time = time.time()

        # Calculate how many bytes we expect
        total_bytes = SAMPLE_RATE * in_bytes_per_sample * RECORD_SECONDS
        bytes_received = 0

        while bytes_received < total_bytes:
            if ser.in_waiting > 0:
                # Read whatever is available
                data = ser.read(ser.in_waiting)
                audio_frames.append(data)
                bytes_received += len(data)

                # Simple progress indicator
                print(f"Recorded: {bytes_received} / {total_bytes} bytes", end="\r")

        print("\nRecording complete. Saving...")
        ser.close()

        raw = b"".join(audio_frames)

        if SAMPLE_WIDTH_BITS == 24:
            # Repack each little-endian int32 sample into packed 24-bit (3 bytes)
            # so the WAV plays back at the correct level.
            count = len(raw) // 4
            samples = struct.unpack(f"<{count}i", raw[: count * 4])
            packed = bytearray(count * 3)
            for idx, s in enumerate(samples):
                s &= 0xFFFFFF
                packed[idx * 3 : idx * 3 + 3] = (
                    s & 0xFF,
                    (s >> 8) & 0xFF,
                    (s >> 16) & 0xFF,
                )
            frames = bytes(packed)
            sampwidth = 3
        else:
            frames = raw
            sampwidth = 2

        # Save to WAV file
        with wave.open(OUTPUT_FILENAME, "wb") as wf:
            wf.setnchannels(1)  # Mono
            wf.setsampwidth(sampwidth)
            wf.setframerate(SAMPLE_RATE)
            wf.writeframes(frames)

        print(f"File saved: {OUTPUT_FILENAME}")

    except serial.SerialException:
        print(
            f"Error: Could not open port {SERIAL_PORT}. Is the Arduino Monitor open? Close it!"
        )
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    record_audio()
