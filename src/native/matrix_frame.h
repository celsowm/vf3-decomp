/* matrix_frame.h - native ports of the matrix_frame leaves 0x8C03D260,
 * 0x8C03D280 and 0x8C03D2B0 on the `vf3_native_aim` context.
 *
 * See matrix_frame.c and docs/re/native_matrix_frame.md. */
#ifndef VF3_NATIVE_MATRIX_FRAME_H
#define VF3_NATIVE_MATRIX_FRAME_H

#include "motion_aim.h"

/* Run 0x8C03D260 (matrix_frame_a).  Push the matrix *(node+8) on the matrix
 * stack, multiply in the parent chain (the matrix just below the stack top),
 * store XMTRX to the flat slot 0x0C19D4D8, pop the stack back, and restore
 * r15/pr. */
void vf3_native_matrix_frame_a(vf3_native_aim *a);

/* Run 0x8C03D280 (matrix_frame_b): like A but first multiplies in the
 * parent matrix *(0x0C19D304) before the parent chain. */
void vf3_native_matrix_frame_b(vf3_native_aim *a);

/* Run 0x8C03D2B0 (matrix_frame_c): push *(0x0C19D304), multiply in the
 * parent chain, store to 0x0C19D498, pop. */
void vf3_native_matrix_frame_c(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_FRAME_H */
