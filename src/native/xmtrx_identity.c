/* xmtrx_identity.c - SH-4 0x8C03CCB0 matrix_identity, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_lib.c
 * (`vf3_matrix_identity_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no registers touched).
 * It sets XMTRX to the identity (column-major 16 floats) and FR0..FR3 to
 * (1, 0, 0, 1), which stay behind.  No general register, SR, pr or RAM is
 * touched.  The return pops pr (the caller's return address).
 *
 * See docs/re/native_xmtrx_identity.md. */
#include "xmtrx_identity.h"

#include "matrix.h"

void vf3_native_xmtrx_identity(vf3_native_aim *a)
{
    vf3_native_matrix_identity(a->xm);
    a->fr[0] = 1.0f;
    a->fr[1] = 0.0f;
    a->fr[2] = 0.0f;
    a->fr[3] = 1.0f;
}
