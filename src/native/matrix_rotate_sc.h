/* matrix_rotate_sc.h - native port of the XMTRX rotate-sc leaf 0x8C03C970
 * on the `vf3_native_aim` context.
 *
 * See matrix_rotate_sc.c and docs/re/native_matrix_rotate_sc.md. */
#ifndef VF3_NATIVE_MATRIX_ROTATE_SC_H
#define VF3_NATIVE_MATRIX_ROTATE_SC_H

#include "motion_aim.h"

/* Run 0x8C03C970 (matrix_rotate_sc).  A self-contained FP leaf (call-free,
 * no stack frame): it post-multiplies XMTRX by the Z rotation whose sin/cos
 * are in FR4/FR5 and writes the two result columns into XMTRX columns 0 and
 * 1 (XF0..XF7).  FR0..FR7 hold the two ftrv outputs on return.  FR8..FR15,
 * XF8..XF15, r15 and SR are untouched. */
int vf3_native_matrix_rotate_sc(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_ROTATE_SC_H */
