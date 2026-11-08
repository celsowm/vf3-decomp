/* counter_select.c - SH-4 0x8C0C10A2: the four-threshold counter selection.
 *
 * A self-contained leaf (124 B, 0x0C0C10A2..0x0C0C111A), call-free and
 * integer-only (no FP at all).  r4 is a mask.  The body keeps two running
 * selection counters - r6 (even, starts 0) and r5 (odd, starts 4) - and for
 * each of four threshold masks decides which counter to hand out and
 * advances it:
 *
 *   if (mN & r4in) == 0   -> hand out the odd counter, then r5 += 1;
 *   else                  -> hand out the even counter, then r6 += 1.
 *
 * Tests 1..3 advance the counter they hand out; test 4 does NOT advance (it
 * only reads).  The four handed-out values go into r7 (test 1), two locals
 * (tests 2 and 3) and r4 (test 4).
 *
 * The body reads its data from the literal pool:
 *
 *   base = read32(0x0c0c11e0)          the target structure's base pointer
 *   hw_ce = (int16)read16(0x0c0c11ce)  a signed halfword offset
 *   m1 = (int16)read16(0x0c0c11d0)
 *   m2 = (int16)read16(0x0c0c11d2)
 *   m3 = (int16)read16(0x0c0c11d4)
 *   m4 = (int16)read16(0x0c0c11d6)
 *
 * and pushes r14 then r13 (entry r15 = SP0), then allocates a 16-byte frame
 * at SP0-24 holding base, base+0x58, base+hw_ce and base+0x2c, and finally
 * writes four 16-bit thresholds (the handed-out values) at +0x26 into those
 * four addresses:
 *
 *   set_u16(base,          + 0x26, t1)
 *   set_u16(base+0x2c,     + 0x26, t2)
 *   set_u16(base+0x58,     + 0x26, t3)
 *   set_u16(base+hw_ce,    + 0x26, r4out)
 *
 * r15 is net unchanged (the frame is popped before the fourth write and the
 * two saved registers are restored).  The registers the body leaves are
 * r0 = 0x26, r2 = (uint32_t)m3, r3 = frame[2] = base+hw_ce (reloaded from
 * the frame at the 4th write - the trap the captured corpus confirms),
 * r4 = r4out, r5/r6 = the two counters' end values, r7 = t1, r13/r14 = their
 * entry values (restored from the stack), and SR's T bit from the last
 * (test-4) comparison, (m4 & r4in) == 0.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_counter_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t mask = R(4);
    const uint32_t sp0 = R(15);
    const uint32_t r13_in = R(13);
    const uint32_t r14_in = R(14);

    /* 0x0c0c11e0 / 0x0c0c11ce..11d6: the pool data. */
    const uint32_t base = vf3_mem_u32(ram, 0x0c0c11e0u);
    const int32_t hw_ce = (int16_t)vf3_mem_u16(ram, 0x0c0c11ceu);
    const int32_t m1 = (int16_t)vf3_mem_u16(ram, 0x0c0c11d0u);
    const int32_t m2 = (int16_t)vf3_mem_u16(ram, 0x0c0c11d2u);
    const int32_t m3 = (int16_t)vf3_mem_u16(ram, 0x0c0c11d4u);
    const int32_t m4 = (int16_t)vf3_mem_u16(ram, 0x0c0c11d6u);

    /* 0x0c0c10a2/10a6: push r14, r13; 0x0c0c10aa allocates the 16-byte frame. */
    vf3_mem_set_u32(ram, sp0 - 4u, r14_in);
    vf3_mem_set_u32(ram, sp0 - 8u, r13_in);
    vf3_mem_set_u32(ram, sp0 - 24u, base);
    vf3_mem_set_u32(ram, sp0 - 20u, base + 0x58u);
    vf3_mem_set_u32(ram, sp0 - 16u, base + (uint32_t)hw_ce);
    vf3_mem_set_u32(ram, sp0 - 12u, base + 0x2cu);

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
        R(17) = (R(17) & ~1u) | 1u;           /* T = 1 */
    } else {
        r4out = r6c;
        R(17) = (R(17) & ~1u);                /* T = 0 */
    }

    /* 0x0c0c1100..1116: the four halfword threshold writes. */
    vf3_mem_set_u16(ram, base + 0x26u, (uint16_t)t1);
    vf3_mem_set_u16(ram, base + 0x2cu + 0x26u, (uint16_t)t2);
    vf3_mem_set_u16(ram, base + 0x58u + 0x26u, (uint16_t)t3);
    vf3_mem_set_u16(ram, base + (uint32_t)hw_ce + 0x26u, (uint16_t)r4out);

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

    s->pc = R(16);
    return ram->oob == 0;
}
