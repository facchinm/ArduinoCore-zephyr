/*
 * Copyright (c) Arduino s.r.l. and/or its affiliated companies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <soc.h>

/* Arm the SAM-BA bootloader double-tap magic in the last RAM word, then reset */
void _on_1200_bps() {
	irq_lock();
	*(volatile uint32_t *)(0x20000000 + 0x8000 - 4) = 0x07738135;
	NVIC_SystemReset();
	while (true) {
	}
}
