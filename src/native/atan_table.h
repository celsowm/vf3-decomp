/* atan_table.h - native port of the atan-table (0x8C069624), operating on
 * the `vf3_native_aim` context.
 *
 * See atan_table.c and docs/re/native_atan_table.md. */
#ifndef VF3_NATIVE_ATAN_TABLE_H
#define VF3_NATIVE_ATAN_TABLE_H

#include "aim_math.h"

/* Run 0x8C069624.  A self-contained integer/FP leaf (call-free, no stack
 * frame, no tail-transfer).  FR4 = x, FR5 = y.  Returns r0 = 0 for the zero
 * vector.  Otherwise the smaller absolute value is divided by the larger and
 * scaled to index the halfword table at 0x0C0EAF60 (the angle of that slope,
 * up to 0x2000).  The octant is then folded back: 0x4000 - angle when
 * |y| < |x| is false, and by the signs of y and x the result is -angle,
 * 0x8000 - angle, angle - 0x8000 or the angle itself.
 *
 * Leaves r4 = the signed angle, r0 = the same, FPUL = the table index, and
 * fr2 (the scaled slope), fr3 = 0, fr6 = |y|, fr7 = |x|, fr8 = the
 * smaller/larger ratio as the original does.  r1..r3, all of r5..r15 except
 * none, the stack pointer and pr are untouched.  See
 * docs/re/native_atan_table.md. */
void vf3_native_atan_table(vf3_native_aim *a);

#endif /* VF3_NATIVE_ATAN_TABLE_H */
