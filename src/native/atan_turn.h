/* atan_turn.h - native port of the arctangent-turn (0x8C039FD0), operating on
 * the `vf3_native_aim` context.
 *
 * See atan_turn.c and docs/re/native_atan_turn.md. */
#ifndef VF3_NATIVE_ATAN_TURN_H
#define VF3_NATIVE_ATAN_TURN_H

#include "aim_math.h"

/* Run 0x8C039FD0.  A self-contained FP leaf (call-free, no stack frame, no
 * tail-transfer).  FR4 = x.  The argument is folded into [-1, 1] (u = 1/x
 * when |x| > 1, else u = x) and atan(u) is evaluated as a 13-term continued
 * fraction in u^2, scaled to turns as (atan + 2pi) * 65536 / 2pi + 0.5,
 * truncated and masked to 16 bits; the quadrant fold applies for x > 1
 * (0x4000 - angle) and x < -1 (0xC000 - angle).
 *
 * Leaves r0 = the masked angle (folded), r3 = 0xFFFF, r4 = the angle, r5 = 1,
 * FPUL = the raw truncated angle, SR's T bit = the quadrant fold flag, and
 * fr1 = 0.5, fr2 = 65536, fr3 = the scaled value (-1 once the quadrant test
 * has run on the |x| <= 1 path), fr5 = atan, fr6 = 1, fr7 = 2pi, fr8 = the
 * last n^2 helper.  r1, r2, r6..r15, the stack pointer and pr are untouched.
 * See docs/re/native_atan_turn.md. */
void vf3_native_atan_turn(vf3_native_aim *a);

#endif /* VF3_NATIVE_ATAN_TURN_H */
