/* matrix_pop.h - native port of the matrix stack pop leaf (0x8C03C4A0),
 * operating on the `vf3_native_aim` context.
 *
 * See matrix_pop.c and docs/re/native_matrix_pop.md. */
#ifndef VF3_NATIVE_MATRIX_POP_H
#define VF3_NATIVE_MATRIX_POP_H

#include "motion_aim.h"

/* Run 0x8C03C4A0.  Self-contained leaf (call-free, no stack frame, no FPU).
 * Drops r4 matrices (at least one, never below an empty stack), loads the
 * new top into XMTRX (a->xm[16]) from the matrix stack (control block
 * 0x0C19D2E4), and writes r0/r2/r3/r4/r6/r7 + SR.T.  See
 * docs/re/native_matrix_pop.md. */
void vf3_native_matrix_pop(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_POP_H */
