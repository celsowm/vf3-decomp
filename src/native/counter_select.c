/* counter_select.c - SH-4 0x8C0C10A2: the four-threshold counter selection,
 * natively.
 *
 * A plain-C transcription of the readable port
 * src/fight/readable/counter_select.c (`vf3_counter_select_entry`).  A
 * self-contained 124 B leaf (0x0C0C10A2..0x0C0C111A), call-free and
 * integer-only (no FP at all).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.
 *
 * r4 is a mask.  The body keeps two running selection counters - r6 (even,
 * starts 0) and r5 (odd, starts 4) - and for each of four threshold masks
 * decides which counter to hand out and advances it:
 *
 *   if (mN & r4in) == 0  -> hand out the odd counter, then r5 += 1;
 *   else                 -> hand out the even counter, then r6 += 1.
 *
 * Tests 1..3 advance the counter they hand out; test 4 does NOT advance (it
 * only reads).  The data comes from the literal pool:
 *
 *   base  = read32(0x0c0c11e0)
 *   hw_ce = (int16)read16(0x0c0c11ce)
 *   m1..m4 = (int16)read16(0x0c0c11d0/d2/d4/d6)
 *
 * and the body pushes r14 then r13 (entry r15 = SP0), allocates a 16-byte
 * frame at SP0-24 holding base, base+0x58, base+hw_ce and base+0x2c, then
 * writes four 16-bit thresholds at +0x26 into those four destinations.  r15
 * is net unchanged (the frame is popped before the fourth write and the two
 * saved registers are restored).
 *
 * See docs/re/native_counter_select.md. */
#include "counter_select.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_h16(a, addr); }
static void wr16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{ vf3_aim_set_u16(a, addr, v); }

void vf3_native_counter_select(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    const uint32_t mask = R(4);
    const uint32_t r13_in = R(13);
    const uint32_t r14_in = R(14);

    /* 0x0c0c11e0 / 0x0c0c11ce..11d6: the pool data. */
    const uint32_t base = rd32(a, 0x0c0c11e0u);
    const int32_t hw_ce = (int16_t)rd16(a, 0x0c0c11ceu);
    const int32_t m1 = (int16_t)rd16(a, 0x0c0c11d0u);
    const int32_t m2 = (int16_t)rd16(a, 0x0c0c11d2u);
    const int32_t m3 = (int16_t)rd16(a, 0x0c0c11d4u);
    const int32_t m4 = (int16_t)rd16(a, 0x0c0c11d6u);

    /* 0x0c0c10a2/10a6: push r14, r13; 0x0c0c10aa allocates the 16-byte frame. */
    vf3_aim_set_u32(a, R(15) - 4u, r14_in);
    vf3_aim_set_u32(a, R(15) - 8u, r13_in);
    vf3_aim_set_u32(a, R(15) - 24u, base);
    vf3_aim_set_u32(a, R(15) - 20u, base + 0x58u);
    vf3_aim_set_u32(a, R(15) - 16u, base + (uint32_t)hw_ce);
    vf3_aim_set_u32(a, R(15) - 12u, base + 0x2cu);

    /* 0x0c0c10c0..10cc: the two selection counters. */
    uint32_t r6c = 0;
    uint32_t r5c = 4;
    uint32_t t1, t2, t3, r4out;

    if ((m1 & (int32_t)mask) == 0) {          /* T set at 0x0c0c10c2 */
        t1 = r5c; r5c += 1;
    } else {                                   /* T clear */
        t1 = r6c; r6c += 1;
    }
    if ((m2 & (int32_t)mask) == 0) {          /* 0x0c0c10d4 */
        t2 = r5c; r5c += 1;
    } else {
        t2 = r6c; r6c += 1;
    }
    if ((m3 & (int32_t)mask) == 0) {          /* 0x0c0c10e4 */
        t3 = r5c; r5c += 1;
    } else {
        t3 = r6c; r6c += 1;
    }
    if ((m4 & (int32_t)mask) == 0) {          /* 0x0c0c10f4; no advance */
        r4out = r5c;
        a->sr = (a->sr & ~1u) | 1u;           /* T = 1 */
    } else {
        r4out = r6c;
        a->sr = (a->sr & ~1u);                /* T = 0 */
    }

    /* 0x0c0c1100..1116: the four halfword threshold writes. */
    wr16(a, base + 0x26u, (uint16_t)t1);
    wr16(a, base + 0x2cu + 0x26u, (uint16_t)t2);
    wr16(a, base + 0x58u + 0x26u, (uint16_t)t3);
    wr16(a, base + (uint32_t)hw_ce + 0x26u, (uint16_t)r4out);

    /* 0x0c0c1118/111a: restore r13, r14; r15 is net back at SP0. */
    R(13) = r13_in;
    R(14) = r14_in;
    R(15) = sp0;

    R(0) = 0x26u;
    R(2) = (uint32_t)m3;
    R(3) = base + (uint32_t)hw_ce;
    R(4) = r4out;
    R(5) = r5c;
    R(6) = r6c;
    R(7) = t1;
}
