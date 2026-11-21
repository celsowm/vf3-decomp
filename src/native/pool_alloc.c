/* pool_alloc.c - SH-4 0x8C07B2BE: the sprite-pool allocator, natively.
 *
 * A plain-C transcription of the readable port src/fight/glyph_cache.c
 * (`vf3_pool_alloc_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained integer leaf (call-free, no FP, no
 * stack frame), so there are no guest callees to inline and no FPU wrappers.
 *
 * The layer (r4) keeps a pool of 120 entries of 68 bytes at *(layer + 12) and
 * a rotating allocation cursor (u16 at layer + 42).  An entry is "free" when
 * its first halfword is zero.
 *
 *   - if the cursor's entry is free, it is handed out (the cursor advances,
 *     wrapping to zero at 120), r0 = r5 = the entry;
 *   - otherwise the pool is scanned from the base for the first free entry
 *     (r0 = r5 = it, r1 = its index);
 *   - if the pool is exhausted, r0 = 0 and the full-table registers are set.
 *
 * Every path is a tail transfer to pr, so the C port leaves pr untouched and
 * simply returns.  See docs/re/native_pool_alloc.md. */
#include "pool_alloc.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

#define POOL_ENTRIES 120u
#define ENTRY_BYTES 68u
#define LAYER_POOL 12u
#define LAYER_CURSOR 42u
#define FULL_TABLE 0x0C29F2F0u
#define FULL_STRIDE 44u
#define FULL_EXTRA 0x84u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (uint32_t)(value != 0);
}

void vf3_native_pool_alloc(vf3_native_aim *a)
{
    const uint32_t layer = R(4), sp = R(15);
    const uint32_t pool = vf3_aim_u32(a, layer + LAYER_POOL);
    const uint32_t cursor = vf3_aim_h16(a, layer + LAYER_CURSOR);
    uint32_t entry = pool + cursor * ENTRY_BYTES;
    R(6) = 1;
    R(7) = POOL_ENTRIES;
    R(2) = cursor;
    R(3) = cursor * ENTRY_BYTES;

    if (vf3_aim_h16(a, entry) == 0) {
        uint32_t next = cursor + 1;
        vf3_aim_set_u16(a, layer + LAYER_CURSOR, (uint16_t)next);
        R(2) = next;
        R(3) = vf3_aim_h16(a, layer + LAYER_CURSOR);
        if (R(3) >= POOL_ENTRIES) {
            R(2) = 0;
            vf3_aim_set_u16(a, layer + LAYER_CURSOR, 0);
            set_t(a, 1);
        } else {
            set_t(a, 0);
        }
        R(0) = R(5) = entry;
        return;   /* tail transfer to pr */
    }

    /* the cursor's entry is taken: scan for the first free one */
    entry = pool;
    uint32_t index = 0;
    for (;;) {
        if (vf3_aim_h16(a, entry) == 0) {
            R(1) = index;
            R(5) = R(0) = entry;
            set_t(a, 0);
            return;
        }
        ++index;
        entry += ENTRY_BYTES;
        if (index >= POOL_ENTRIES) break;
    }

    /* the pool is exhausted: the full-table registers */
    const uint32_t full_a = FULL_TABLE + FULL_STRIDE;
    vf3_aim_set_u32(a, sp - 4u, full_a);        /* dead spill, part of the RAM */
    R(1) = index;
    R(0) = 0;
    R(2) = R(3) = full_a;
    R(5) = FULL_TABLE + FULL_EXTRA;
    R(6) = FULL_TABLE;
    R(7) = FULL_TABLE + 2u * FULL_STRIDE;
    set_t(a, R(4) == R(5));
}
