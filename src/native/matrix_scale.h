/* matrix_scale.h - native port of the current-transform scale
 * (0x8C03CB70), operating on the `vf3_native_aim` context.
 *
 * See matrix_scale.c and docs/re/native_matrix_scale.md. */
#ifndef VF3_NATIVE_MATRIX_SCALE_H
#define VF3_NATIVE_MATRIX_SCALE_H

#include "motion_aim.h"

/* Run 0x8C03CB70.  Self-contained leaf.  Scales the three axis columns of
 * XMTRX (a->xm[16]) by the FR4, FR5, FR6 scales (FPU-exact toward-zero +
 * FTZ per the FPSCR), pushing FR6/FR5/FR4 to sp-4/sp-8/sp-12 and restoring
 * XMTRX[15] from FPUL (which parked XMTRX[15]'s entry value).  No general
 * register or r15 moves; SR untouched.  See docs/re/native_matrix_scale.md. */
void vf3_native_matrix_scale(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_SCALE_H */
