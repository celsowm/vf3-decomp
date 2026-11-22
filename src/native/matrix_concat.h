/* matrix_concat.h - native port of the concatenate leaf 0x8C03C0E0
 * on the `vf3_native_aim` context.
 *
 * See matrix_concat.c and docs/re/native_matrix_concat.md. */
#ifndef VF3_NATIVE_MATRIX_CONCAT_H
#define VF3_NATIVE_MATRIX_CONCAT_H

#include "motion_aim.h"

/* Run 0x8C03C0E0 (matrix_concat).  Self-contained FP leaf: XMTRX becomes
 * XMTRX * M(r4), where M is the 16 floats at r4 (each M column is the
 * ftrv input, i.e. the post-multiplied column-major product).  The old
 * XMTRX shows in fr[0..11]; FR12..FR15 are preserved (they travel through
 * the stack, sp0-12..-4, FR13 at sp0-12, FR14 at sp0-8, FR15 at sp0-4).
 * FPSCR.FR toggles.  r4 advances by 64 bytes; r15 and SR are untouched. */
int vf3_native_matrix_concat(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_CONCAT_H */
