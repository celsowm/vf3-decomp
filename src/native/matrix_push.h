/* matrix_push.h - native port of the matrix push leaf (0x8C03C4F0),
 * operating on the `vf3_native_aim` context.
 *
 * See matrix_push.c and docs/re/native_matrix_push.md. */
#ifndef VF3_NATIVE_MATRIX_PUSH_H
#define VF3_NATIVE_MATRIX_PUSH_H

#include "motion_aim.h"

/* Run 0x8C03C4F0.  Self-contained leaf (call-free, no stack frame, no FPU).
 * Pushes XMTRX (a->xm[16]) on the matrix stack (control block 0x0C19D2E4),
 * increments the count, and optionally loads the matrix at r4 as the new
 * XMTRX (r4 advancing past it).  Writes r0, r4, SR.T and XMTRX.  See
 * docs/re/native_matrix_push.md. */
void vf3_native_matrix_push(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_PUSH_H */
