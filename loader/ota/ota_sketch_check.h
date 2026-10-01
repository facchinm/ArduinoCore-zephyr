/*
 * Copyright (c) Arduino s.r.l. and/or its affiliated companies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/storage/flash_map.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This function is meant to be used by the loader to check for a sketch ota update
 *
 * Install /ota:/UPDATE.BIN into the sketch partition if present. The sketch
 * validates the OTA payload (magic, CRC32, decompression) before writing it,
 * so the loader trusts the file and only re-checks the inner sketch_header_v1.
 *
 * On failure before the erase, UPDATE.BIN is removed and the existing sketch
 * boots. On failure after it, the partition is already partial so UPDATE.BIN
 * is kept and the next boot retries — the only way back without DFU.
 */
int try_ota_update(const struct flash_area *fa);

#ifdef __cplusplus
}
#endif
