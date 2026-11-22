/* matrix_rotate_z.h - native port of the XMTRX rotate-Z leaf 0x8C03C940
 * on the `vf3_native_aim` context.
 *
 * See matrix_rotate_z.c and docs/re/native_matrix_rotate_z.md. */
#ifndef VF3_NATIVE_MATRIX_ROTATE_Z_H
#define VF3_NATIVE_MATRIX_ROTATE_Z_H

#include "motion_aim.h"

/* Run 0x8C03C940 (rotate_z).  A self-contained FP leaf (call-free, no stack
 * frame): it takes the Z-rotation angle in r4 (65536 = one turn), derives
 * sin/cos from it (the fsca angle -> sin/cos step, FPUL = r4), post-multiplies
 * XMTRX by the Z rotation and writes the two result columns into XMTRX
 * columns 0 and 1 (XF0..XF7).  FR0..FR7 hold the two ftrv outputs on return.
 * FPUL is left as r4.  FR8..FR15, XF8..XF15, r15 and SR are untouched. */
int vf3_native_matrix_rotate_z(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_ROTATE_Z_H */
