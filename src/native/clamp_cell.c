/* clamp_cell.c - SH-4 0x8C055B28: the clamp-cell leaf, natively.
 *
 * A plain-C transcription of the readable port src/fight/misc_wrappers.c
 * (`vf3_clamp_cell_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained integer leaf (call-free, no FP, no
 * stack frame), so there are no guest callees to inline and no FPU wrappers.
 *
 * The function clamps the sign-extended halfword at R(4)+2 to a cell number
 * (values below 9 keep themselves, 9..16 become 9, 17 and above become 10),
 * stores four times the clamped value at the global 0x0C058FDC, advances R(4)
 * by 4 and tail-transfers to pr.
 *
 * Register contract: r0 = 4 * clamped value (a signed shift of the
 * sign-extended halfword, so a negative halfword gives a negative result),
 * r1 = 0x0C058FDC, r4 advanced by 4; SR.T = (value >= 17) on the high path
 * and (value >= 9) on the low path; r2, r3, r5.., r15 and pr untouched.
 *
 * See docs/re/native_clamp_cell.md. */
#include "clamp_cell.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (uint32_t)(value != 0);
}

void vf3_native_clamp_cell(vf3_native_aim *a)
{
    /* the value to clamp, sign-extended from the halfword at r4 + 2 */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(4) + 2u);
    R(1) = 17;
    set_t(a, (int32_t)R(0) >= (int32_t)R(1));
    if ((int32_t)R(0) >= (int32_t)R(1)) {
        R(0) = 10;
    } else {
        R(1) = 9;
        set_t(a, (int32_t)R(0) >= (int32_t)R(1));
        if ((int32_t)R(0) >= (int32_t)R(1))
            R(0) = R(1);
    }
    R(0) <<= 2;                       /* four times the clamped value */
    R(1) = 0x0C058FDCu;               /* the global */
    vf3_aim_set_u32(a, R(1), R(0));
    R(4) += 4;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
