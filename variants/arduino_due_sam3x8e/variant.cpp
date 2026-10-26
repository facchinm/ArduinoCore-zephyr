/*
 * Copyright (c) Arduino s.r.l. and/or its affiliated companies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <soc.h>

/*
 * Boot the ROM SAM-BA on the next reset by clearing GPNVM1 (boot from flash),
 * so bossac can upload through the native USB port. bossac -b sets it back.
 */
void _on_1200_bps() {
	/* EEFC commands must not run from flash: use the ROM IAP entry point */
	typedef uint32_t (*iap_fn)(uint32_t efc_index, uint32_t fcr);
	iap_fn iap = (iap_fn)(*(volatile uint32_t *)(IROM_ADDR + 8));

	irq_lock();
	iap(0, (0x5AU << EEFC_FCR_FKEY_Pos) | EEFC_FCR_FARG(1) | EEFC_FCR_FCMD_CGPB);

	RSTC->RSTC_CR = RSTC_CR_KEY(0xA5) | RSTC_CR_PROCRST | RSTC_CR_PERRST;
	while (true) {
	}
}
