/* matrix_copy.h - native port of the matrix copy leaf (0x8C03B530),
 * operating on the `vf3_native_aim` context.
 *
 * See matrix_copy.c and docs/re/native_matrix_copy.md. */
#ifndef VF3_NATIVE_MATRIX_COPY_H
#define VF3_NATIVE_MATRIX_COPY_H

#include "motion_aim.h"

/* Run 0x8C03B530.  Self-contained leaf.  dst = r4, src = r5: a dead
 * [sp-4] = r14 push first; a null dst loads XMTRX from src (r4 = src+64), a
 * null src stores XMTRX to dst (r0 = r4 = dst), and both non-null copies the
 * 16 words src -> dst leaving FR3 = the last copied word, r4 = 0,
 * r5 = dst+64, r6 = src+64.  r14 and r15 are unchanged.  See
 * docs/re/native_matrix_copy.md. */
void vf3_native_matrix_copy(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_COPY_H */
