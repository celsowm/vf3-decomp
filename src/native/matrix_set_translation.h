/* matrix_set_translation.h - native port of the XMTRX set-translation leaf
 * (0x8C03CBD0), operating on the `vf3_native_aim` context.
 *
 * See matrix_set_translation.c and docs/re/native_matrix_set_translation.md. */
#ifndef VF3_NATIVE_MATRIX_SET_TRANSLATION_H
#define VF3_NATIVE_MATRIX_SET_TRANSLATION_H

#include "motion_aim.h"

/* Run 0x8C03CBD0.  Call-free leaf: r4 -> three floats; copies them into the
 * XMTRX translation words a->xm[12..14] and advances r4 by 12.  No other
 * register, SR bit or FR cell is touched. */
void vf3_native_matrix_set_translation(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_SET_TRANSLATION_H */
