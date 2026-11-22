/* matrix_invert_rigid.h - native port of the in-place rigid-matrix inverse
 * leaf 0x8C03C5B0 on the `vf3_native_aim` context.
 *
 * See matrix_invert_rigid.c and docs/re/native_matrix_invert_rigid.md. */
#ifndef VF3_NATIVE_MATRIX_INVERT_RIGID_H
#define VF3_NATIVE_MATRIX_INVERT_RIGID_H

#include "motion_aim.h"

/* Run 0x8C03C5B0 (matrix_invert_rigid).  Self-contained FP leaf (call-free,
 * no stack frame).  It inverts a *rigid* (rotation + translation) XMTRX in
 * place: the 3x3 rotation is transposed (its inverse) and the translation
 * becomes -(R^T * t), the negated dot products of the translation against the
 * three axis columns.
 *
 * Operates purely on XMTRX (a->xm); the FR bank, r15 and SR are untouched.
 * The transpose's FPUL swaps leave a->fpul = the pre-swap value of the
 * element that was in slot 6. */
int vf3_native_matrix_invert_rigid(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_INVERT_RIGID_H */
