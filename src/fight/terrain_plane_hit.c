/* terrain_plane_hit.c - 0x8C0692A6  height of a terrain triangle's plane at (x, z), plus its normal.
 *
 *   r4 -> triangle record (+4 = offset of the shape record from the base at [0x0C113A0C]), r5 -> float for the
 *   height, r6 -> three floats for the normal, r7 = 4 selects the second vertex triple of the shape (vertex
 *   offsets +16 / +12 / +4) instead of the first (+12 / +8 / +4), FR4 / FR5 = x / z.
 *
 *   With the triangle P (the first vertex), Q and R, the edge vectors Q - P and R - P are crossed and the
 *   plane through them is solved for the height at (x, z), mirroring the original's FR sequence; the result
 *   goes to r5's float. The triangle's stored normal (floats at +20 / +24 / +28 of the shape record) is
 *   copied to r6, and the return value is the record's first word shifted left once and masked with
 *   0x1FFFC, or-ed with its low two bits.
 *
 *   Frame (12 bytes under two saved words): +0 / +4 x, z, +8 the shape record's second word. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 8, FRAME = 12, WORD_MASK = 0x1FFFCu };

int vf3_terrain_plane_hit_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r14 = R(14), saved_f14 = F(14);
    const uint32_t out_h = R(5), out_n = R(6);
    uint32_t p, q, rr;

    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, saved_f14);
    R(15) = f;

    const uint32_t base = m32(ram, 0x0C113A0Cu);
    const uint32_t shape = m32(ram, R(4) + 4) + base;
    w32(ram, f, F(4));
    w32(ram, f + 4, F(5));
    const uint32_t first = m32(ram, shape + 4);
    w32(ram, f + 8, first);
    if (R(7) == 4) { rr = m32(ram, shape + 16); q = m32(ram, shape + 12); }
    else           { q = m32(ram, shape + 8);   rr = m32(ram, shape + 12); }
    q += base; p = first + base; rr += base;                /* Q (r3), P (r7), R (r2 -> r14) */

    F(0) = m32(ram, q);
    F(2) = m32(ram, p + 4);
    F(1) = m32(ram, p + 8);
    F(4) = m32(ram, q + 4);
    F(11) = m32(ram, q + 8);
    R(14) = rr;
    F(9) = m32(ram, rr + 4);
    F(14) = m32(ram, p);
    FSUB(11, 1);
    F(8) = m32(ram, rr + 8);
    FSUB(4, 2);
    F(10) = m32(ram, rr);
    FSUB(0, 14);
    FSUB(8, 1);
    FSUB(9, 2);
    FMOV(5, 11);
    FSUB(10, 14);
    FMOV(7, 4);
    FMOV(6, 0);
    FMUL(7, 8);
    FMUL(6, 9);
    FMUL(5, 10);
    FMUL(11, 9);
    FMOV(3, 7);
    FMUL(0, 8);
    FMUL(4, 10);
    FMOV(7, 11);
    FSUB(7, 3);
    FMOV(3, 5);
    FMOV(5, 0);
    FSUB(5, 3);
    FMOV(3, 6);
    FMOV(0, 7);
    FMOV(6, 4);
    FSUB(6, 3);
    FMUL(2, 5);
    F(5) ^= SIGN;
    FMAC(2, 14);
    FMOV(0, 6);
    FMOV(4, 2);
    FMAC(4, 1);
    F(2) = m32(ram, f);
    FMUL(2, 7);
    FMOV(3, 4);
    FMOV(4, 2);
    FSUB(4, 3);
    F(3) = m32(ram, f + 4);
    FMOV(2, 4);
    FMAC(2, 3);
    FMOV(4, 2);
    FDIV(4, 5);
    w32(ram, out_h, F(4));

    const uint32_t rec = shape;
    F(3) = m32(ram, rec + 20);
    w32(ram, out_n, F(3));
    F(3) = m32(ram, rec + 24);
    w32(ram, out_n + 4, F(3));
    F(3) = m32(ram, rec + 28);
    w32(ram, out_n + 8, F(3));

    const uint32_t word = m32(ram, rec);
    R(1) = 3u & word;
    R(0) = ((word << 1) & WORD_MASK) | R(1);
    R(14) = saved_r14;
    F(14) = saved_f14;
    R(15) = sp0;
    s->pc = R(VF3_REG_PR);
    return 1;
}
