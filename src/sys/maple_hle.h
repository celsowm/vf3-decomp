#ifndef VF3_MAPLE_HLE_H
#define VF3_MAPLE_HLE_H

#include <stdint.h>

/* Maple bus DMA, answered at the level of the transfer list (see docs/re/maple.md).
 *
 * A transfer list is a run of blocks: header (bit 31 last, 17:16 port, 7:0 frame words - 1), receive address, then the frame
 * (command | to << 8 | from << 16 | words << 24) and its payload. vf3_maple_dma walks the list in guest RAM and writes one
 * answer per block at its receive address: a stand-in controller (standard pad, no sub-units) on port A, "no device" elsewhere. */

typedef struct {
    uint16_t buttons;               /* wire format, active low: 0xFFFF = nothing pressed */
    uint8_t rtrig, ltrig, joyx, joyy, joy2x, joy2y;
} vf3_maple_pad;

/* ram points at guest address ram_base. Returns the number of blocks answered. */
unsigned vf3_maple_dma(uint8_t *ram, uint32_t ram_base, uint32_t ram_len, uint32_t list_addr, const vf3_maple_pad *pad);

#endif
