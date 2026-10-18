/* vec_lerp21.c - 0x8C09F354  blend 21 consecutive 3-float vectors toward a source array.
 *
 * r4 = destination array (updated in place), r5 = source array, fr4 = blend factor t. For each of the 21 vectors,
 * component-wise:
 *     dst = src + t * (dst - src)
 * with the engine's round-toward-zero FPSCR (fmac, one rounding). The original unrolls the last three vectors; the
 * register file it leaves is that of the final vector (fr0 = t, fr5 = the z difference, fr4 / fr6 = new z,
 * fr7 / fr9 = new y, fr8 / fr10 = new x), r4 = dst + 240, r5 = src + 240 (the last vector does not advance it), T = 1 from the loop counter, r0 = 8, r3 / r6 / r7 = the z / z / y addresses of the last loop and last tail vectors.
 * The loop also parks its z pointer at sp-4 on every iteration, so that slot holds the last loop vector's z address. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define VECTORS      21
#define LOOP_VECTORS 18

static float ldf(const vf3_ram_map *ram, uint32_t addr) { return vf3_bits_f32(m32(ram, addr)); }
static void stf(const vf3_ram_map *ram, uint32_t addr, float v) { w32(ram, addr, vf3_f32_bits(v)); }

int vf3_vec_lerp21_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 4;
    const uint32_t dst = R(4), src = R(5);
    const float t = fl(s, 4);

    float diff_z = 0, new_x = 0, new_y = 0, new_z = 0;
    for (int i = 0; i < VECTORS; ++i) {
        const uint32_t d = dst + 12u * (uint32_t)i, o = src + 12u * (uint32_t)i;
        const float dx = vf3_f_sub(s, ldf(ram, d), ldf(ram, o));
        const float dy = vf3_f_sub(s, ldf(ram, d + 4), ldf(ram, o + 4));
        diff_z = vf3_f_sub(s, ldf(ram, d + 8), ldf(ram, o + 8));
        new_x = vf3_f_mac(s, t, dx, ldf(ram, o));
        new_y = vf3_f_mac(s, t, dy, ldf(ram, o + 4));
        new_z = vf3_f_mac(s, t, diff_z, ldf(ram, o + 8));
        stf(ram, d, new_x);
        stf(ram, d + 4, new_y);
        if (i < LOOP_VECTORS) w32(ram, f, d + 8);      /* the loop keeps its z pointer on the stack */
        stf(ram, d + 8, new_z);
    }

    R(0) = 8;
    R(3) = dst + 12u * (LOOP_VECTORS - 1) + 8u;
    R(6) = dst + 12u * (VECTORS - 1) + 8u;
    R(7) = dst + 12u * (VECTORS - 1) + 4u;
    R(4) = dst + 12u * (VECTORS - 1);
    R(5) = src + 12u * (VECTORS - 1);
    R(VF3_REG_SR) |= 1u;
    set_fl(s, 0, t);
    set_fl(s, 4, new_z);
    set_fl(s, 5, diff_z);
    set_fl(s, 6, new_z);
    set_fl(s, 7, new_y);
    set_fl(s, 8, new_x);
    set_fl(s, 9, new_y);
    set_fl(s, 10, new_x);
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
