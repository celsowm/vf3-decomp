/* matrix_rotate_x.h - native port of the XMTRX rotate-X leaf 0x8C03C6C0
 * on the `vf3_native_aim` context.
 *
 * See matrix_rotate_x.c and docs/re/native_matrix_rotate_x.md. */
#ifndef VF3_NATIVE_MATRIX_ROTATE_X_H
#define VF3_NATIVE_MATRIX_ROTATE_X_H

#include "motion_aim.h"

/* Run 0x8C03C6C0 (rotate_x).  A self-contained FP leaf (call-free, no stack
 * frame): it takes the X-rotation angle in r4 (65536 = one turn), derives
 * sin/cos from it (the fsca angle -> sin/cos step, FPUL = r4), post-multiplies
 * XMTRX by the X rotation and writes the two result columns into XMTRX
 * columns 1 and 2 (XF4..XF11).  FR0..FR7 hold the two ftrv outputs on return.
 * FPUL is left as r4.  FR8..FR15, XF0..XF3, XF12..XF15, r15 and SR are
 * untouched. */
int vf3_native_matrix_rotate_x(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_ROTATE_X_H */
