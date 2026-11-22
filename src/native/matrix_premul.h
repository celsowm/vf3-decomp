/* matrix_premul.h - native port of the pre-multiply leaf 0x8C03C1C0
 * on the `vf3_native_aim` context.
 *
 * See matrix_premul.c and docs/re/native_matrix_premul.md. */
#ifndef VF3_NATIVE_MATRIX_PREMUL_H
#define VF3_NATIVE_MATRIX_PREMUL_H

#include "motion_aim.h"

/* Run 0x8C03C1C0 (matrix_premul).  Self-contained FP leaf: XMTRX becomes
 * M(r4) * XMTRX where M is the 16 floats at r4 (each old XMTRX column is
 * transformed by M, i.e. the pre-multiplied product).  FR0..FR11 end as the
 * first twelve floats of M; FR12..FR15 are preserved.  r4 advances by 64.
 * r15 and SR are untouched (the four dead stack words hold the saved
 * FR12..FR15).  Returns 1 on success. */
int vf3_native_matrix_premul(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_PREMUL_H */
