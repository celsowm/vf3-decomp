/* scaled_vec_add.h - native port of 0x8C09302A (scaled_vec_add), operating on
 * the `vf3_native_aim` context.  See scaled_vec_add.c and
 * docs/re/native_scaled_vec_add.md. */
#ifndef VF3_NATIVE_SCALED_VEC_ADD_H
#define VF3_NATIVE_SCALED_VEC_ADD_H

#include "aim_math.h"

/* Run 0x8C09302A (scaled_vec_add).  A self-contained FP leaf (call-free, uses
 * a 20-byte frame, saves/restores fr15).  dest += w * owner.vec, where:
 *   r4 = actor  (its halfword at +16 holds mode bits)
 *   r5 = owner  (flag word at +72, source vector at +92)
 *   r6 = source record (the weight, a float at +16)
 *   r7 = mode flags
 *   [sp0+0] = destination vector pointer
 * The weight w = [r6+16] (nothing happens when it is 0) is scaled by:
 *   1.1  when owner.flags & 0x04000000
 *   else 0.75, then (unless actor.s16[16] & 1) 0.45 more when r7 & 0x100 is
 *        set, and the whole routine is skipped when r7 & 0x1000 is set (and
 *        actor bit 0 clear).
 * fr15 is callee-saved; only fr0..fr5 carry results out.  See
 * docs/re/native_scaled_vec_add.md. */
void vf3_native_scaled_vec_add(vf3_native_aim *a);

#endif /* VF3_NATIVE_SCALED_VEC_ADD_H */
