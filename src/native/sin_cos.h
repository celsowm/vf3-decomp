/* sin_cos.h - native ports of the 16-bit-angle sine (0x8C03A6E0) and cosine
 * (0x8C03A140), operating on the `vf3_native_aim` context.
 *
 * See sin_cos.c and docs/re/native_sin_cos.md. */
#ifndef VF3_NATIVE_SIN_COS_H
#define VF3_NATIVE_SIN_COS_H

#include "aim_math.h"

/* Run 0x8C03A6E0 (sin of a 16-bit angle; 65536 = one turn).  A self-contained
 * FP leaf (call-free, no stack frame).  r4 = the angle (low 16 bits are used).
 * Returns the sine in FR0.
 *
 * theta = angle*2pi/65536, h = theta/2, the half angle is reduced to
 * y = h - n*pi/2 (n = nearest quadrant), tan(y) comes from the continued
 * fraction y / (1 - y^2/(3 - y^2/(5 - .../11))), and
 * sin(theta) = +-2t/(1 + t^2) with t = tan(y) (sign flips for odd n).
 * The result lands in FR0.  r4 is untouched.  See docs/re/native_sin_cos.md. */
void vf3_native_sin_u16(vf3_native_aim *a);

/* Run 0x8C03A140 (cos of a 16-bit angle).  cos(a) = sin(0x4000 - a') where
 * a' folds the angle into the first half turn (a' = 0x10000 - a when
 * a > 0x8000).  Tail-calls the sine routine, so the result lands in FR0.
 * r4 is left as 0x4000 - a' (and the original pushes r14 to sp-4 as a dead
 * word).  See docs/re/native_sin_cos.md. */
void vf3_native_cos_u16(vf3_native_aim *a);

#endif /* VF3_NATIVE_SIN_COS_H */
