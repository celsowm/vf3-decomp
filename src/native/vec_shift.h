/* vec_shift.h - native port of the vec-shift (0x8C0748E0), operating on the
 * `vf3_native_aim` context.
 *
 * See vec_shift.c and docs/re/native_vec_shift.md. */
#ifndef VF3_NATIVE_VEC_SHIFT_H
#define VF3_NATIVE_VEC_SHIFT_H

#include "aim_math.h"

/* Run 0x8C0748E0.  A self-contained FP leaf (call-free, no stack frame, no
 * tail-transfer).  r4 -> object.  The offset (x, y, z) lives at +0x13A8 /
 * +0x13AC / +0x13B0 and is added to the vec3 at +0x1488; the point-record
 * pointer at +0x138C then walks 0x150 bytes (28 vec3s, 12 bytes each) and
 * every vec3 on the way gets the same offset added.  No frame, nothing
 * saved.  Leaves r0 = 8, r5 = r6 = the end pointer (one past the last point
 * record) and SR's T bit set.  r1..r4, r7..r15, the stack pointer and pr are
 * untouched.  See docs/re/native_vec_shift.md. */
void vf3_native_vec_shift(vf3_native_aim *a);

#endif /* VF3_NATIVE_VEC_SHIFT_H */
