/* axis_angle_matrix.h - native port of 0x8C03C750 (axis_angle_matrix) on the
 * `vf3_native_aim` context.
 *
 * See axis_angle_matrix.c and docs/re/native_axis_angle_matrix.md. */
#ifndef VF3_NATIVE_AXIS_ANGLE_MATRIX_H
#define VF3_NATIVE_AXIS_ANGLE_MATRIX_H

#include "motion_aim.h"

/* Run 0x8C03C750 (axis_angle_matrix).  Builds the Rodrigues rotation matrix
 * of "rotate by (sin, cos) around axis" into a 16-float frame at f+4, then
 * tail-calls matrix_concat (0x8C03C0E0, already native) with r4 = f+4.
 * With k = 1 - cos: diagonal cos + k*a*a, off-diagonal k*a*b -/+ sin*c, the
 * fourth column and translation row zero, the corner = 1.0.  The FR bank is
 * restored to its entry values (fr13, fr14, fr15 are saved on the stack). */
void vf3_native_axis_angle_matrix(vf3_native_aim *a);

#endif /* VF3_NATIVE_AXIS_ANGLE_MATRIX_H */
