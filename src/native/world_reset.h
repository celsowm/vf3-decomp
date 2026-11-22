/* world_reset.h - native port of 0x8C03E980 (world_reset) on the
 * `vf3_native_aim` context.
 *
 * See world_reset.c and docs/re/native_world_reset.md. */
#ifndef VF3_NATIVE_WORLD_RESET_H
#define VF3_NATIVE_WORLD_RESET_H

#include "motion_aim.h"

/* Run 0x8C03E980 (world_reset).  The callees it sequences - matrix_transpose
 * (0x8C03CC30) and xform_vector (0x8C03B4B0) - are already native ports, so
 * the whole body runs natively: transpose XMTRX, transform the vector at
 * 0x0C19D5B0+0x68 into +0x80, transform 0x0C0EA600 into 0x0C058FE0, then
 * transpose XMTRX back.  The net XMTRX is the identity of the two
 * transposes; the transforms run in the transposed frame. */
void vf3_native_world_reset(vf3_native_aim *a);

#endif /* VF3_NATIVE_WORLD_RESET_H */
