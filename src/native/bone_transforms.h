/* bone_transforms.h - native port of 0x8C03E8C0 (bone_transforms) on the
 * `vf3_native_aim` context.
 *
 * See bone_transforms.c and docs/re/native_bone_transforms.md. */
#ifndef VF3_NATIVE_BONE_TRANSFORMS_H
#define VF3_NATIVE_BONE_TRANSFORMS_H

#include "motion_aim.h"

/* Run 0x8C03E8C0 (bone_transforms).  All five callees it sequences are
 * already native in this library, so the whole body runs natively:
 * matrix_push (0x8C03C4F0), matrix_invert_scaled (0x8C03B5C0), and, per
 * non-empty entry of the sixteen-record TABLE, xform_vector (0x8C03B4B0)
 * and xform_point (0x8C03B450); then matrix_pop (0x8C03C4A0) as the tail
 * call.  It pushes XMTRX, inverts it in place, transforms every used entry's
 * point/vector through the inverted frame, and pops the original back. */
void vf3_native_bone_transforms(vf3_native_aim *a);

#endif /* VF3_NATIVE_BONE_TRANSFORMS_H */
