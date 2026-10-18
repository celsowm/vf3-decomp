/* segment_delta.c - 0x8C092B4A  difference and scaled push of one motion segment against its neighbour.
 *
 * r4 = destination record (r14), r5 = second record (stored at f+0), r6 = pointer to a scale float (f+8), r7 = pointer
 * to a record whose float at +0x14 gates the push (f+4). The caller's stack holds, from sp+0: the two source vectors
 * A / B (words 0 and 1), a third vector (+8) and a flag word (+C).
 *
 *   rec[+0x18 .. +0x20] = A - B                                  (component-wise)
 *   scale = *r6, times 0.65 when flag 0x100 is set
 *   rec[+0x18 .. +0x20] *= scale
 *   unless flag 0x2 is set, f+4's float at +0x14 is zero, or r5 is null:
 *       f[0xC .. 0x14] = third vector * scale (scale = twice the +0x14 float of r7's record)
 *       r5.rec[+0x18 .. +0x20] += f[0xC .. 0x14]
 *
 * The scratch triple at f+0xC and the register file are those of the original (the routine mirrors both).
 * Frame (f = sp - 28): f+0 r5, f+4 r7, f+8 r6, f+C .. f+14 the scaled third vector. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)

/* mov.l @Rn+,FRm / mov.l FRm,@-Rn in the original's single-precision mode */
#define LD_POST(fr, reg)    do { F(fr) = m32(ram, R(reg)); R(reg) += 4; } while (0)
#define ST_PRE(fr, reg)     do { R(reg) -= 4; w32(ram, R(reg), F(fr)); } while (0)

int vf3_segment_delta_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 28, saved14 = R(14);
    w32(ram, sp0 - 4, saved14);
    R(14) = R(4);
    R(15) = f;
    R(4) = R(14);
    w32(ram, f, R(5));
    R(4) += 24;
    w32(ram, f + 8, R(6));
    w32(ram, f + 4, R(7));
    R(5) = m32(ram, f + 28);
    R(6) = m32(ram, f + 32);

    LD_POST(0, 5); LD_POST(3, 6);
    LD_POST(1, 5); LD_POST(4, 6);
    FSUB(0, 3);
    F(2) = m32(ram, R(5));
    F(5) = m32(ram, R(6));
    FSUB(1, 4);
    FSUB(2, 5);
    R(4) += 8;
    w32(ram, R(4), F(2));
    ST_PRE(1, 4);
    ST_PRE(0, 4);

    R(2) = m32(ram, f + 8);
    R(1) = m32(ram, f + 40);
    R(3) = 0x100;
    F(4) = m32(ram, R(2));
    TST(R(3), R(1));
    R(5) = R(14);                                      /* delay slot of the bt/s below */
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = 0x8C092BB0u;                            /* mova: 0.65f */
        F(3) = 0x3F266666u;
        FMUL(4, 3);
    }
    R(4) = R(14) + 24;
    R(5) += 24;

    LD_POST(0, 5); LD_POST(1, 5); LD_POST(2, 5);
    R(4) += 12;
    FMUL(2, 4); FMUL(1, 4); FMUL(0, 4);
    ST_PRE(2, 4); ST_PRE(1, 4); ST_PRE(0, 4);

    R(0) = m32(ram, f + 40);
    TST(R(0), 2);
    if (!(R(VF3_REG_SR) & 1u)) goto done;
    R(2) = m32(ram, f + 4);
    R(0) = 20;
    F(2) = 0;
    F(4) = m32(ram, R(2) + R(0));
    FMOV(3, 4);
    FADD(4, 3);
    SET_T(fl(s, 4) == fl(s, 2));
    if (R(VF3_REG_SR) & 1u) goto done;
    R(1) = m32(ram, f);
    TST(R(1), R(1));
    if (R(VF3_REG_SR) & 1u) goto done;
    R(4) = f;
    R(5) = m32(ram, f + 36);
    R(4) += 12;

    LD_POST(0, 5); LD_POST(1, 5); LD_POST(2, 5);
    R(4) += 12;
    FMUL(2, 4); FMUL(1, 4); FMUL(0, 4);
    ST_PRE(2, 4); ST_PRE(1, 4); ST_PRE(0, 4);

    R(4) = m32(ram, f);
    R(5) = f;
    R(5) += 12;
    R(4) += 24;
    LD_POST(0, 4); LD_POST(3, 5);
    LD_POST(1, 4); LD_POST(4, 5);
    LD_POST(2, 4); LD_POST(5, 5);
    FADD(0, 3);
    FADD(2, 5);
    FADD(1, 4);
    ST_PRE(2, 4); ST_PRE(1, 4); ST_PRE(0, 4);

done:
    R(15) = sp0;
    R(14) = saved14;
    s->pc = pr0;
    return 1;
}
