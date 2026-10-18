/* scaled_vec_add.c - 0x8C09302A  add a scaled copy of an owner vector into a destination vector.
 *
 * r4 = actor (its halfword at +16 holds mode bits), r5 = owner (flag word at +72, the source vector at +92 as three
 * floats), r6 = source record (the weight, a float at +16), r7 = mode flags, and a destination vector pointer on the
 * caller's stack at [sp0 + 0]. The weight w = [r6+16] (nothing happens when it is 0) is scaled by:
 *     1.1   when owner.flags & 0x04000000
 *     else  0.75, then (unless actor.s16[16] & 1) 0.45 more when flags r7 & 0x100 is set, and the whole routine is
 *           skipped when r7 & 0x1000 is set (and actor bit 0 clear)
 * and dest += w * owner.vec. fr15 is callee-saved (pushed and popped), so only fr0 .. fr5 carry results out. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c) (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_scaled_vec_add_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 20;
    const uint32_t saved_fr15 = F(15);
    w32(ram, sp0 - 4, saved_fr15);
    R(15) = f;
    w32(ram, f, R(4));
    R(0) = 16;
    F(15) = m32(ram, R(6) + R(0));
    F(3) = 0;
    SET_T(fl(s, 15) == fl(s, 3));
    if (R(VF3_REG_SR) & 1u) { R(3) = 0x0C0930D8u; goto leave; }

    R(0) = 72;
    R(3) = 0x04000000u;
    R(2) = m32(ram, R(5) + R(0));
    SET_T((R(3) & R(2)) == 0);
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = 0x0C093098u;
        F(3) = 0x3F8CCCCCu;
        FMUL(15, 3);                                  /* delay slot of the bra */
        goto apply;
    }

    R(0) = 0x0C09309Cu;
    F(3) = 0x3F400000u;
    R(0) = m32(ram, f);
    {
        const uint32_t lo = vf3_mem_u8(ram, R(0) + 16), hi = vf3_mem_u8(ram, R(0) + 17);
        R(0) = lo | (hi << 8);
    }
    SET_T((R(0) & 1u) == 0);
    set_fl(s, 15, vf3_f_mul(s, fl(s, 15), fl(s, 3)));                /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto apply;
    R(1) = 0x1000u;
    SET_T((R(7) & R(1)) == 0);
    if (!(R(VF3_REG_SR) & 1u)) { R(2) = 0x0C0930D8u; goto leave; }
    R(3) = 0x0100u;
    SET_T((R(7) & R(3)) == 0);
    if (R(VF3_REG_SR) & 1u) goto apply;
    R(0) = 0x0C0930A0u;
    F(3) = 0x3EE66666u;
    set_fl(s, 15, vf3_f_mul(s, fl(s, 15), fl(s, 3)));

apply:
    R(5) = m32(ram, f);
    R(4) = f + 4;
    set_fl(s, 4, fl(s, 15));
    R(5) += 92;
    F(0) = m32(ram, R(5)); R(5) += 4;
    F(1) = m32(ram, R(5)); R(5) += 4;
    F(2) = m32(ram, R(5)); R(5) += 4;
    R(4) += 12;
    FMUL(2, 4);
    FMUL(1, 4);
    FMUL(0, 4);
    R(4) -= 4; w32(ram, R(4), F(2));
    R(4) -= 4; w32(ram, R(4), F(1));
    R(4) -= 4; w32(ram, R(4), F(0));
    R(4) = m32(ram, f + 20);
    R(5) = f + 4;
    F(0) = m32(ram, R(4)); R(4) += 4;
    F(3) = m32(ram, R(5)); R(5) += 4;
    F(1) = m32(ram, R(4)); R(4) += 4;
    F(4) = m32(ram, R(5)); R(5) += 4;
    F(2) = m32(ram, R(4)); R(4) += 4;
    F(5) = m32(ram, R(5)); R(5) += 4;
    FADD(0, 3);
    FADD(2, 5);
    FADD(1, 4);
    R(4) -= 4; w32(ram, R(4), F(2));
    R(4) -= 4; w32(ram, R(4), F(1));
    R(4) -= 4; w32(ram, R(4), F(0));

leave:
    F(15) = saved_fr15;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
