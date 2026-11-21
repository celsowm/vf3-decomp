/* vec_lerp21.h - native port of 0x8C09F354 (vec_lerp21), operating on the
 * `vf3_native_aim` context.  See vec_lerp21.c and
 * docs/re/native_vec_lerp21.md. */
#ifndef VF3_NATIVE_VEC_LERP21_H
#define VF3_NATIVE_VEC_LERP21_H

#include "aim_math.h"

/* Run 0x8C09F354 (vec_lerp21).  A self-contained FP leaf (call-free, no stack
 * frame).  r4 = destination array, r5 = source array, fr4 = blend factor t.
 * For each of 21 consecutive 3-float vectors, component-wise:
 *     dst = src + t * (dst - src)      (fused mac, one rounding)
 * r4 ends = dst + 240, r5 = src + 240, T = 1, r0 = 8, and the FR bank carries
 * the last vector's blend results (see docs/re/native_vec_lerp21.md). */
void vf3_native_vec_lerp21(vf3_native_aim *a);

#endif /* VF3_NATIVE_VEC_LERP21_H */
