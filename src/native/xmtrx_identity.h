/* xmtrx_identity.h - native port of the current-transform identity reset
 * (0x8C03CCB0), operating on the `vf3_native_aim` context.
 *
 * See xmtrx_identity.c and docs/re/native_xmtrx_identity.md. */
#ifndef VF3_NATIVE_XMTRX_IDENTITY_H
#define VF3_NATIVE_XMTRX_IDENTITY_H

#include "motion_aim.h"

/* Run 0x8C03CCB0.  Self-contained leaf.  XMTRX (a->xm[16]) becomes the
 * column-major identity and FR0..FR3 become (1, 0, 0, 1).  No general
 * register, SR, pr or RAM is touched.  See docs/re/native_xmtrx_identity.md. */
void vf3_native_xmtrx_identity(vf3_native_aim *a);

#endif /* VF3_NATIVE_XMTRX_IDENTITY_H */
