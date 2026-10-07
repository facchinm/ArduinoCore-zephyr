/*
 * Copyright (c) Arduino s.r.l. and/or its affiliated companies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ARDUINO_ZEPHYR_PDMCONFIG_H
#define ARDUINO_ZEPHYR_PDMCONFIG_H

#include <stdint.h>

/* The number of samples the user receive
 * For performance reason the user is strongly suggested to use this
 * dimension for its application buffer that take the audio samples */
#ifndef PDM_NUMBER_OF_SAMPLES
#define PDM_NUMBER_OF_SAMPLES 512
#endif

/* size in bit of an audio sample.
 * NANO 33 BLE works only with 16; GIGA / NICLA VISION also support 24.
 * Default is 16 on every board. If you switch a GIGA/Nicla sketch to 24-bit,
 * also set SAMPLE_WIDTH_BITS to 24 in
 * extras/PDMSerialAudioRecorder/PDMSerialAudioRecorder.py so recordings are
 * decoded at the right width. */
#ifndef PDM_SAMPLE_BIT_WIDTH
#define PDM_SAMPLE_BIT_WIDTH 16
#endif

/* PCM output sample rate in Hz.
 * Default is 16000 on every board. If you change the sketch sample rate, also
 * set SAMPLE_RATE in extras/PDMSerialAudioRecorder/PDMSerialAudioRecorder.py so
 * recordings play back at the right speed/pitch. */
#ifndef PDM_SAMPLE_RATE
#define PDM_SAMPLE_RATE 16000
#endif

/* Default number of input channels */
#ifndef PDM_DEFAULT_CHANNELS
#define PDM_DEFAULT_CHANNELS 1
#endif

/* Storage type for one PCM sample */
#if PDM_SAMPLE_BIT_WIDTH == 24
typedef int32_t PDMSample;
#else
typedef int16_t PDMSample;
#endif

/* Default digital gain (linear multiplier) for boards with no analog mic gain,
 * e.g. GIGA/DFSDM. Applied per sample with saturation; override with setGain(). */
#ifndef PDM_DEFAULT_GAIN
#define PDM_DEFAULT_GAIN 4
#endif

/* receiving thread configuration */
#ifndef PDM_THREAD_STACK_SIZE
#define PDM_THREAD_STACK_SIZE 1024
#endif
#ifndef PDM_THREAD_PRIORITY
#define PDM_THREAD_PRIORITY 7
#endif

/* memory slab configuration */
#if defined(ARDUINO_NANO33BLE)
#define SLAB_BLOCK_NUM 4
#define SLAB_ALIGN     4
#if PDM_SAMPLE_BIT_WIDTH != 16
#error "PDM_SAMPLE_BIT_WIDTH must be set to 16 for ARDUINO_NANO33BLE"
#endif
#define SLAB_BLOCK_SIZE (PDM_NUMBER_OF_SAMPLES * 2)
#elif defined(ARDUINO_GIGA) || defined(ARDUINO_NICLA_VISION)
#define SLAB_BLOCK_NUM 4
#define SLAB_ALIGN     32
#if PDM_SAMPLE_BIT_WIDTH == 16
#define SLAB_BLOCK_SIZE (PDM_NUMBER_OF_SAMPLES * 2)
#elif PDM_SAMPLE_BIT_WIDTH == 24
#define SLAB_BLOCK_SIZE (PDM_NUMBER_OF_SAMPLES * 4)
#else
#error "PDM_SAMPLE_BIT_WIDTH must be 16 or 24 for ARDUINO_GIGA / ARDUINO_NICLA_VISION"
#endif
#endif

#endif // ARDUINO_ZEPHYR_PDMCONFIG_H
