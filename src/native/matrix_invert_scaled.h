/* matrix_invert_scaled.h - native port of the in-place scaled-matrix inverse
 * leaf 0x8C03B5C0 on the `vf3_native_aim` context.
 *
 * See matrix_invert_scaled.c and docs/re/native_matrix_invert_scaled.md. */
#ifndef VF3_NATIVE_MATRIX_INVERT_SCALED_H
#define VF3_NATIVE_MATRIX_INVERT_SCALED_H

#include "motion_aim.h"

/* Run 0x8C03B5C0 (matrix_invert_scaled).  Self-contained FP leaf (call-free,
 * no stack frame).  It inverts a rotation + scale + translation XMTRX in
 * place: the three axis columns are normalised by 1/|column|, transposed
 * (the rotation inverse), and the translation becomes -(t . c_i)/|c_i|.
 *
 * Operates purely on XMTRX (a->xm); the FR bank, r15 and SR are untouched.
 * The transpose's FPUL swaps leave a->fpul = the pre-swap value of the
 * element that was in slot 6. */
int vf3_native_matrix_invert_scaled(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_INVERT_SCALED_H */
