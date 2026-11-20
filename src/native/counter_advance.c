/* counter_advance.c - SH-4 0x8C08B338: the animation frame counters, natively.
 *
 * A plain-C transcription of the readable port src/fight/counter_advance.c
 * (`vf3_counter_advance_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained integer leaf - it calls nobody, uses
 * no FPU and keeps **no stack frame**.
 *
 * The engine keeps three counters in a record (r4) - seven bits at +12, two at
 * +14, four at +16 - and one counter in a block.  This function advances them:
 *
 *  - the first counter steps by one and keeps seven bits;
 *  - the low bit of that *incremented* counter is carried into the two narrow
 *    counters and into the block's counter - so the wide counter's own wrap
 *    (127 to zero) carries nothing, and the narrow counters move on every
 *    other step;
 *  - the block's counter (reached through the pool at 0x0c08b3f4, at +0x54)
 *    wraps at 127.
 *
 * A global says whether the counters move at all: the counters advance only
 * when the value the pool slot at 0x0c08b3f0 points at has *no* bit in common
 * with the mask at 0x0c08b3ec.  On the gated path the T bit is set and nothing
 * else changes.
 *
 * Two details the port keeps: the carried bit is the low bit of the
 * *incremented* wide counter (`R(6) = 1 & (R(5) + 1)`), so the wide counter's
 * own wrap carries nothing and the narrow counters move on every other step;
 * and the block's wrap test is a **signed** comparison on the sign-extended
 * halfword, so a counter of 32767 that takes the carry becomes -32768 and does
 * not wrap.  The block is reached through **two** indirections (the pool slot,
 * then a word that is the block).  The pool's values are not recoverable
 * offline, so the port reads the same addresses the guest reads.
 *
 * See docs/re/native_counter_advance.md. */
#include "counter_advance.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the globals */
#define G_ENABLE 0x0c08b3f0u   /* the global that says "go" */
#define G_MASK   0x0c08b3ecu   /* the mask the global is tested against */
#define G_BLOCK  0x0c08b3f4u   /* the block the block's counter lives in */

/* the block counter's slot */
#define COUNTER_OFFSET 0x54u

/* the widths of the three record counters */
#define WIDE_MASK   0x7fu
#define NARROW_MASK 0x03u
#define FOUR_MASK   0x0fu

void vf3_native_counter_advance(vf3_native_aim *a)
{
    /* the global says whether the counters move: they move only when its
     * value has no bit in common with the mask */
    R(1) = vf3_aim_u32(a, G_ENABLE);
    R(3) = vf3_aim_u32(a, G_MASK);
    R(2) = vf3_aim_u32(a, R(1));
    set_t(a, (R(3) & R(2)) == 0);
    if ((R(3) & R(2)) != 0) {
        /* nothing to do */
        return;
    }

    /* the first counter: seven bits wide, and the bit that falls out of it */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(4) + 12u);
    R(6) = 1u;
    R(3) = WIDE_MASK;
    R(5) = R(0);
    R(5) += 1u;
    R(6) &= R(5);
    R(5) &= R(3);
    R(0) = R(5);
    vf3_aim_set_u16(a, R(4) + 12u, (uint16_t)R(0));

    /* the block's counter: it wraps at 127 */
    R(2) = vf3_aim_u32(a, G_BLOCK);
    R(0) = COUNTER_OFFSET;
    R(1) = 0x7fu;
    R(7) = vf3_aim_u32(a, R(2));
    R(5) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(7) + R(0));
    R(5) += R(6);
    R(3) = (uint32_t)(int32_t)(int16_t)R(5);
    set_t(a, (int32_t)R(3) >= (int32_t)R(1));
    if ((int32_t)R(3) >= (int32_t)R(1)) R(5) = 0u;
    vf3_aim_set_u16(a, R(7) + R(0), (uint16_t)R(5));

    /* and the two narrow counters */
    R(3) = NARROW_MASK;
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(4) + 14u);
    R(2) = FOUR_MASK;
    R(5) = R(0);
    R(5) += R(6);
    R(5) &= R(3);
    R(0) = R(5);
    vf3_aim_set_u16(a, R(4) + 14u, (uint16_t)R(0));

    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(4) + 16u);
    R(5) = R(0);
    R(5) += R(6);
    R(5) &= R(2);
    R(0) = R(5);
    vf3_aim_set_u16(a, R(4) + 16u, (uint16_t)R(0));
}
