/* axis_extract.h - native port of the in-place axis-extraction leaf 0x8C03EE40
 * on the `vf3_native_aim` context.
 *
 * See axis_extract.c and docs/re/native_axis_extract.md. */
#ifndef VF3_NATIVE_AXIS_EXTRACT_H
#define VF3_NATIVE_AXIS_EXTRACT_H

#include "motion_aim.h"

/* Run 0x8C03EE40 (axis_extract).  A self-contained FP leaf (call-free):
 * it derives the camera/body axes from a three-by-four direction table at
 * 0x0C0EA624, transforms two of its rows through the transpose of XMTRX's
 * 3x3 part, and writes the result to the vector block at 0x0C1A58A0:
 *
 *   block[+16..+18] = (t0, t1, t2) . M^T    (a transformed copy of row 0)
 *   block[+0..+2]   = norm((t0, t1, t3) . M^T)  (the unit axis)
 *
 * XMTRX is unchanged on exit.  r0 = 8, r4 = BLOCK, r5 = TABLE + 8, and the
 * FPUL side effect is the transpose choreography's last swap = xm[9]. */
void vf3_native_axis_extract(vf3_native_aim *a);

#endif /* VF3_NATIVE_AXIS_EXTRACT_H */
