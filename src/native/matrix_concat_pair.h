/* matrix_concat_pair.h - native port of the two-matrix concat leaf
 * 0x8C03DD00 on the `vf3_native_aim` context.
 *
 * See matrix_concat_pair.c and docs/re/native_matrix_concat_pair.md. */
#ifndef VF3_NATIVE_MATRIX_CONCAT_PAIR_H
#define VF3_NATIVE_MATRIX_CONCAT_PAIR_H

#include "motion_aim.h"

/* Run 0x8C03DD00.  Self-contained FP leaf: XMTRX becomes XMTRX * A * B where
 * A is the 16 floats at the pointer held in [0x0C19D308 + 8] and B the 16
 * floats at 0x0C19D518.  FR12..FR15 travel through the stack and come back
 * untouched; FR0..FR11 end as B.  r4 = B + 32, r5 = B + 64.  Returns 1 on
 * success, 0 when FPSCR carries the SZ bit (the body's own fschg dance needs
 * it clear). */
int vf3_native_matrix_concat_pair(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_CONCAT_PAIR_H */
