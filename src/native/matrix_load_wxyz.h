/* matrix_load_wxyz.h - native port of the wxyz matrix load leaf
 * (0x8C03EFB0), operating on the `vf3_native_aim` context.
 *
 * See matrix_load_wxyz.c and docs/re/native_matrix_load_wxyz.md. */
#ifndef VF3_NATIVE_MATRIX_LOAD_WXYZ_H
#define VF3_NATIVE_MATRIX_LOAD_WXYZ_H

#include "motion_aim.h"

/* Run 0x8C03EFB0.  Self-contained leaf (call-free, no stack frame, no FPU).
 * Loads the matrix at r4 into XMTRX (a->xm[16]) with every column rotated to
 * (w, x, y) and a negated w behind it: (a b c d) -> (d a b -d); c is dropped.
 * r4 advances by 64.  Only r4 and XMTRX move.  See
 * docs/re/native_matrix_load_wxyz.md. */
void vf3_native_matrix_load_wxyz(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_LOAD_WXYZ_H */
