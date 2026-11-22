/* matrix_translate_by.h - native port of the XMTRX translate-by leaf
 * 0x8C03CC60 on the `vf3_native_aim` context.
 *
 * See matrix_translate_by.c and docs/re/native_matrix_translate_by.md. */
#ifndef VF3_NATIVE_MATRIX_TRANSLATE_BY_H
#define VF3_NATIVE_MATRIX_TRANSLATE_BY_H

#include "motion_aim.h"

/* Run 0x8C03CC60 (matrix_translate_by).  A self-contained FP leaf (call-free,
 * no stack frame): it sets XMTRX's translation column to XMTRX * (FR4, FR5,
 * FR6, 1) via ftrv - i.e. it moves the origin by the local offset the caller
 * left in FR4..FR6.  FR4..FR7 hold the transformed vector on return; FR7 is
 * set to 1.0 first.  FR8..FR15, r15 and SR are untouched. */
int vf3_native_matrix_translate_by(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_TRANSLATE_BY_H */
