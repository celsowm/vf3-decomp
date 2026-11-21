/* xmtrx_transpose.h - native port of the current-transform transpose
 * (0x8C03CC30), operating on the `vf3_native_aim` context.
 *
 * See xmtrx_transpose.c and docs/re/native_xmtrx_transpose.md. */
#ifndef VF3_NATIVE_XMTRX_TRANSPOSE_H
#define VF3_NATIVE_XMTRX_TRANSPOSE_H

#include "motion_aim.h"

/* Run 0x8C03CC30.  Self-contained leaf.  XMTRX (a->xm[16]) is transposed by
 * swapping the six symmetric off-diagonal word pairs (1,4) (2,8) (3,12)
 * (6,9) (7,13) (11,14).  No general register, SR, pr or RAM is touched.  See
 * docs/re/native_xmtrx_transpose.md. */
void vf3_native_matrix_transpose(vf3_native_aim *a);

#endif /* VF3_NATIVE_XMTRX_TRANSPOSE_H */
