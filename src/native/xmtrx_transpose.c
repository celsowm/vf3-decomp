/* xmtrx_transpose.c - SH-4 0x8C03CC30 matrix_transpose, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_extra.c
 * (`vf3_matrix_transpose_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here.
 *
 * A self-contained leaf (call-free, no FPU math, no stack, no general
 * register touched).  It transposes the 4x4 column-major matrix in XMTRX by
 * swapping the six symmetric off-diagonal pairs:
 *
 *   (1,4) (2,8) (3,12) (6,9) (7,13) (11,14)
 *
 * swapping element i with element j leaves XMTRX[4*j+i] = XMTRX[i*4+j] ...
 * i.e. the true transpose.  SR, pr and every general register are untouched.
 * The return pops pr (the caller's return address).
 *
 * See docs/re/native_xmtrx_transpose.md. */
#include "xmtrx_transpose.h"

void vf3_native_matrix_transpose(vf3_native_aim *a)
{
    float t;
#define SWAP(i, j) do { t = a->xm[(j)]; a->xm[(j)] = a->xm[(i)]; a->xm[(i)] = t; } while (0)
    SWAP(1, 4);
    SWAP(2, 8);
    SWAP(3, 12);
    SWAP(6, 9);
    SWAP(7, 13);
    SWAP(11, 14);
#undef SWAP
}
