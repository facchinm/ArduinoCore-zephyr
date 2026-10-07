/*
 * Copyright (c) Arduino s.r.l. and/or its affiliated companies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ARDUINO_ZEPHYR_PDM_H
#define ARDUINO_ZEPHYR_PDM_H

#include <zephyr/devicetree.h>

#if !DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(dmic_dev))
#error "No enabled 'dmic_dev' devicetree node found: this board does not define a PDM microphone"
#endif

#include <Arduino.h>
#include <cstdint>
#include "PDMConfig.h"

namespace arduino {

class PDMClass {
public:
	PDMClass();
	virtual ~PDMClass();
	int begin(int channels = PDM_DEFAULT_CHANNELS, int sampleRate = PDM_SAMPLE_RATE);
	void end();
	virtual int available();
	virtual int read(void *buffer, size_t size);
	void onReceive(void (*)(void));
	void setGain(int gain);
	size_t getBufferSize();

private:
	bool pdm_init;
	bool active;

	struct {
		void *data;
		size_t size;
		size_t offset;
	} active_block;
};

} // namespace arduino

typedef arduino::PDMClass PDMClass;

extern PDMClass PDM;

#endif // ARDUINO_ZEPHYR_PDM_H
