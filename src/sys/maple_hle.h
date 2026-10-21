#ifndef VF3_MAPLE_HLE_H
#define VF3_MAPLE_HLE_H

#include <stdint.h>

/* Maple bus DMA, answered at the level of the transfer list (see docs/re/maple.md).
 *
 * A transfer list is a run of blocks: header (bit 31 last, 17:16 port, 7:0 frame words - 1), receive address, then the frame
 * (command | to << 8 | from << 16 | words << 24) and its payload. vf3_maple_dma walks the list in guest RAM and writes one
 * answer per block at its receive address. A bus can hold one standard pad
 * on each of the four ports; no sub-units are modelled. */

typedef struct {
    uint16_t buttons;               /* wire format, active low: 0xFFFF = nothing pressed */
    uint8_t rtrig, ltrig, joyx, joyy, joy2x, joy2y;
} vf3_maple_pad;

#define VF3_MAPLE_PORTS 4
typedef struct {
    vf3_maple_pad pads[VF3_MAPLE_PORTS];
    unsigned connected;            /* bit 0..3: a pad is present on A..D */
} vf3_maple_bus;

/* Neutral inputs, with only the requested ports connected. The frontend
 * updates this snapshot at the guest polling boundary, not on host render. */
void vf3_maple_bus_init(vf3_maple_bus *bus, unsigned connected);

typedef enum {
    VF3_MAPLE_DMA_OK,
    VF3_MAPLE_DMA_BAD_LIST,
    VF3_MAPLE_DMA_BAD_RECEIVE,
    VF3_MAPLE_DMA_UNSUPPORTED_PATTERN,
    VF3_MAPLE_DMA_BLOCK_LIMIT
} vf3_maple_dma_status;
typedef struct {
    vf3_maple_dma_status status;
    unsigned blocks;
    uint32_t address;              /* offending list/receive address on failure */
} vf3_maple_dma_result;

/* ram points at guest address ram_base. Every transfer uses this immutable
 * input snapshot. A failed transfer is not reported as DMA completion. */
vf3_maple_dma_result vf3_maple_dma_bus(uint8_t *ram, uint32_t ram_base,
    uint32_t ram_len, uint32_t list_addr, const vf3_maple_bus *bus);

/* Capture-harness compatibility: one standard pad on A. Returns the number
 * of blocks answered; live runtime callers should check dma_bus.status. */
unsigned vf3_maple_dma(uint8_t *ram, uint32_t ram_base, uint32_t ram_len, uint32_t list_addr, const vf3_maple_pad *pad);

#endif
