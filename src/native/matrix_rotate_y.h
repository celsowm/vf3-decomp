/* matrix_rotate_y.h - native port of the XMTRX rotate-Y leaf 0x8C03C880
 * on the `vf3_native_aim` context.
 *
 * See matrix_rotate_y.c and docs/re/native_matrix_rotate_y.md. */
#ifndef VF3_NATIVE_MATRIX_ROTATE_Y_H
#define VF3_NATIVE_MATRIX_ROTATE_Y_H

#include "motion_aim.h"

/* Run 0x8C03C880 (rotate_y).  A self-contained FP leaf (call-free, no stack
 * frame): it takes the Y-rotation angle in r4 (65536 = one turn), derives
 * sin/cos from it (the fsca angle -> sin/cos step, FPUL = r4), post-multiplies
 * XMTRX by the Y rotation and writes the two result columns into XMTRX
 * columns 0 and 2 (XF0..XF3, XF8..XF11).  FR0..FR7 hold the two ftrv outputs
 * on return.  FPUL is left as r4.  FR8..FR15, XF4..XF7, XF12..XF15, r15 and
 * SR are untouched. */
int vf3_native_matrix_rotate_y(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_ROTATE_Y_H */
