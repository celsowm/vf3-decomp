/* point_wrap.c - 0x8C09F5F8  clamp a point to +-655360 and fold it back into the ring's period.
 *
 * r4 = pointer to the point (x, y, z). Nothing happens when the global word at 0x0C29B864 has a bit of 0x0C000000
 * set. Otherwise each component is clamped to +-655360.0 (fr1 / fr0 hold the bounds), then x and z are folded into
 * [fr8 .. fr4] by adding / subtracting the period fr9 (fr6 / fr4 are the lower / upper thresholds), and if either
 * |x| or |z| is still not below fr7 the y component is reflected about fr5 and the folding starts over. The three
 * components are written back and r4 advances by 12 (returned in r0).
 *
 * The routine is a leaf: it takes fr4 .. fr9 as inputs and mirrors every float register it touches, so the register
 * file it leaves (fr0 .. fr3, fr10, fr11, r5, r6, T) is the original's. Frame: the two |component| values are left at
 * sp-4 / sp-8 (f+4 / f+0). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)

/* clamp one component held in FR[x] to [fr0, fr1] the way the original does (fr1 = upper, fr0 = lower) */
static void clamp(vf3_matrix_state *s, int x)
{
    SET_T(GT(1, x));
    if (R(VF3_REG_SR) & 1u) { FMOV(x, 1); return; }
    SET_T(GT(x, 0));
    if (R(VF3_REG_SR) & 1u) { FMOV(x, 0); return; }
    SET_T(GT(1, x));
    if (R(VF3_REG_SR) & 1u) { FMOV(x, 1); return; }
    SET_T(GT(x, 0));
    if (!(R(VF3_REG_SR) & 1u)) return;
    FMOV(x, 1);
}

/* the fold loop for FR[x] (x or z): returns 0 at the exit to the next component, with T as the original leaves it */
static void fold(vf3_matrix_state *s, int x)
{
    for (;;) {
        SET_T(GT(x, 8));
        if (R(VF3_REG_SR) & 1u) {
            SET_T(GT(6, x));
            if (R(VF3_REG_SR) & 1u) return;
            FMOV(3, x);
            FMOV(x, 9);
            FADD(x, 3);
            continue;
        }
        SET_T(GT(4, x));
        if (!(R(VF3_REG_SR) & 1u)) return;
        FSUB(x, 9);
    }
}

int vf3_point_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8;
    R(5) = 0x0C29B864u;
    R(15) = f;
    R(3) = 0x0C000000u;
    R(2) = m32(ram, R(5));
    TST(R(3), R(2));
    if (!(R(VF3_REG_SR) & 1u)) goto done;
    R(0) = 0x8C09F6C8u;                                /* mova: +655360.0 */
    F(10) = m32(ram, R(4));
    F(1) = 0x49200000u;
    R(6) = R(4);
    R(5) = R(4);
    R(6) += 8;
    SET_T(GT(1, 10));
    R(5) += 4;
    F(2) = m32(ram, R(5));
    R(0) = 0x8C09F6CCu;                                /* mova: -655360.0 */
    F(11) = m32(ram, R(6));
    F(0) = 0xC9200000u;
    /* the bt/s at 0x8C09F61A takes the delay-slot load of fr0 either way */
    if (R(VF3_REG_SR) & 1u) { FMOV(10, 1); goto clamp_z; }
    clamp(s, 10);
clamp_z:
    clamp(s, 11);
    clamp(s, 2);

refold:
    fold(s, 10);
    fold(s, 11);
    FMOV(3, 10);
    R(0) = 4;
    F(3) &= 0x7FFFFFFFu;
    SET_T(GT(3, 7));
    w32(ram, f + R(0), F(3));                          /* delay slot of the bt/s below */
    if (R(VF3_REG_SR) & 1u) goto store;
    FMOV(3, 11);
    F(3) &= 0x7FFFFFFFu;
    SET_T(GT(3, 7));
    w32(ram, f, F(3));
    if (R(VF3_REG_SR) & 1u) goto store;
    FSUB(2, 5);
    FSUB(10, 4);
    FSUB(11, 4);
    F(2) ^= 0x80000000u;
    FMOV(3, 2);
    FMOV(2, 5);
    FADD(2, 3);
    goto refold;

store:
    w32(ram, R(4), F(10));
    R(4) += 12;
    w32(ram, R(5), F(2));
    w32(ram, R(6), F(11));
done:
    R(0) = R(4);
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
