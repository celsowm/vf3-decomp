/* motion_state_check.c - SH-4 0x8C0355CA: the motion state field checker,
 * with a conditional tail transfer, natively.
 *
 * A plain-C transcription of the readable port src/fight/motion_state_check.c
 * (`vf3_motion_state_check_entry`).  It operates on `vf3_native_aim`: the flat
 * RAM and the register file.  A self-contained integer leaf (call-free, no
 * FP, no stack frame), so there are no guest callees to inline and no FPU
 * wrappers.
 *
 * The function:
 *
 *   - if R(4) == 0, tail-transfers to pr with r0 = 0;
 *   - otherwise reads the sign-extended halfword at R(4)+0x48; if it is zero,
 *     tail-transfers with r0 = 0;
 *   - otherwise reads the word at R(4)+12, stores it through *R(5) and
 *     tail-transfers with r0 = 1.
 *
 * Every path is a tail transfer to pr (r16 in the readable's numbering, the
 * caller's return address), so the native port leaves pr untouched and simply
 * returns.  The T bit is set from each comparison: T = 1 on the two zero
 * paths, T = 0 on the success path (the last test is the halfword != 0).
 * r3 ends up 0 on the zero paths (the guest zeroes it) and the stored word on
 * the success path.  r4, r5, r15 and pr are untouched.
 *
 * See docs/re/native_motion_state_check.md. */
#include "motion_state_check.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (uint32_t)(value != 0);
}

void vf3_native_motion_state_check(vf3_native_aim *a)
{
    /* r4 == 0 -> tail-transfer, r0 = 0. */
    set_t(a, R(4) == 0);
    if (R(4) == 0) {
        R(0) = 0;
        return;
    }

    /* r0 = 0x48; r3 = sign-extended halfword at r4 + 0x48. */
    R(0) = 0x00000048u;
    R(3) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(4) + R(0));

    /* halfword == 0 -> tail-transfer, r0 = 0; r3 is the (zero) halfword. */
    set_t(a, R(3) == 0);
    if (R(3) == 0) {
        R(0) = 0;
        return;
    }

    /* word at r4 + 12 stored through *r5; r0 = 1. */
    R(3) = vf3_aim_u32(a, R(4) + 12u);
    vf3_aim_set_u32(a, R(5), R(3));
    R(0) = 1u;
}
