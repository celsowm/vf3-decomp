/* pose_blend.c - 0x8C091DE6  advance a blend weight and mix two 26-halfword poses into a third.
 *
 *   r4 -> object. The weight at +0x9C grows by the step at +0xA0 and is clamped to 1.0 (and stored back).
 *   The poses are 26 signed halfwords each: A at +0, B at +52, the result at +104. With w = trunc(weight *
 *   16384) the result is (A * (0x4000 - w) + B * w) >> 14, element by element (32-bit products, arithmetic
 *   shift).
 *
 *   The entry falls into the shared mixing body at 0x8C091E0E. Frame: none; the body pushes r13, r12 and
 *   macl on top of the entry's r14 slot, so the slot at sp - 4 ends up holding r13. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { WEIGHT = 0x9C, STEP = 0xA0, POSE_B = 52, POSE_OUT = 104, COUNT = 26, ONE_Q14 = 0x4000, SHIFT = 14 };

#define SCALE_BITS 0x46800000u                                  /* 16384.0f */

int vf3_pose_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    const uint32_t r12_0 = R(12), r13_0 = R(13), macl0 = R(VF3_REG_MACL);
    const uint32_t obj = R(4);

    w32(ram, sp0 - 4, R(14));
    F(4) = m32(ram, obj + WEIGHT);
    F(5) = m32(ram, obj + STEP);
    FADD(4, 5);
    F(5) = 0x3F800000u;                                         /* fldi1 */
    const int over = GT(5, 4);
    if (over) FMOV(4, 5);
    w32(ram, obj + WEIGHT, F(4));

    w32(ram, sp0 - 4, r13_0);
    w32(ram, sp0 - 8, r12_0);
    w32(ram, sp0 - 12, macl0);
    F(3) = SCALE_BITS;
    FMUL(4, 3);
    const int32_t w = vf3_f_trunc(fl(s, 4));
    const int32_t a = ONE_Q14 - w;

    uint32_t dst = obj + POSE_OUT;
    int32_t sum = 0, bw = 0;
    for (uint32_t i = 0; i < COUNT; ++i) {
        const int32_t va = (int16_t)vf3_mem_u16(ram, obj + 2 * i);
        const int32_t vb = (int16_t)vf3_mem_u16(ram, obj + POSE_B + 2 * i);
        bw = (int32_t)((uint32_t)vb * (uint32_t)w);
        sum = (int32_t)((uint32_t)va * (uint32_t)a + (uint32_t)bw) >> SHIFT;
        vf3_mem_set_u16(ram, dst, (uint16_t)sum);
        dst += 2;
    }

    R(0) = (uint32_t)a; R(1) = dst; R(3) = (uint32_t)-SHIFT; R(4) = (uint32_t)sum; R(5) = (uint32_t)bw;
    R(6) = 0; R(7) = (uint32_t)w; R(VF3_REG_FPUL) = (uint32_t)w;
    R(VF3_REG_SR) |= 1u;
    R(12) = r12_0; R(13) = r13_0; R(VF3_REG_MACL) = macl0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
