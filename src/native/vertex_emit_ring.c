/* vertex_emit_ring.c - SH-4 0x8C048C20 (vertex_emit_ring), natively.
 *
 * Mirror of the readable authority src/fight/vertex_emit.c
 * (`vf3_vertex_emit_ring_entry`).  It packs the lit, transformed vertex -
 * FR4..FR7, r1, r2, FR2, FR3 - into slot r11&3 of the 4-slot clip ring at
 * RING_BASE 0x0C1A5960, and leaves r0 = slot*32, r10 = the slot's low
 * address.
 *
 * The slot layout, from its low address (+00), is
 *
 *     +00 FR4  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
 *
 * (the guest writes it backwards with pre-decrementing 64-bit moves under
 * FPSCR.SZ=1, so the words land low-address-first).  It runs only with
 * FPSCR.SZ clear on entry (the body assumes SZ=0) and the FPU enabled; it
 * returns 0 when the entry FPSCR would be rejected.
 *
 * The observable flat-RAM contract is the 32-byte ring slot written at
 * RING_BASE + (r11&3)*32 plus the register file (r0, r10).
 */
#include "vertex_emit_ring.h"

#include "aim_math.h"

#include <stdint.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum { SLOT_SIZE = 32u, RING_BASE = 0x0C1A5960u, RING_SLOTS_MASK = 3u, FPSCR_SZ = 0x00100000u };

int vf3_native_vertex_emit_ring(vf3_native_aim *a)
{
    if ((a->fpscr & 0x80000u) || (a->fpscr & 3u) > 1u || (a->fpscr & FPSCR_SZ)) return 0;

    const uint32_t offset = (R(11) & RING_SLOTS_MASK) * SLOT_SIZE;
    const uint32_t end = RING_BASE + SLOT_SIZE + offset;
    const uint32_t base = end - SLOT_SIZE;

    vf3_aim_set_u32(a, base + 0x00, vf3_aim_ubits(F(4)));
    vf3_aim_set_u32(a, base + 0x04, vf3_aim_ubits(F(5)));
    vf3_aim_set_u32(a, base + 0x08, vf3_aim_ubits(F(6)));
    vf3_aim_set_u32(a, base + 0x0C, vf3_aim_ubits(F(7)));
    vf3_aim_set_u32(a, base + 0x10, R(1));
    vf3_aim_set_u32(a, base + 0x14, R(2));
    vf3_aim_set_u32(a, base + 0x18, vf3_aim_ubits(F(2)));
    vf3_aim_set_u32(a, base + 0x1C, vf3_aim_ubits(F(3)));

    R(0) = offset;
    R(10) = base;
    return 1;
}
