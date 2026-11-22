/* matrix_rotate_sc.c - SH-4 0x8C03C970 (matrix_rotate_sc), natively.
 *
 * A plain-C transcription of the readable port src/fight/leaf_math.c
 * (`vf3_matrix_rotate_sc_entry`), the body of 0x8C03C940, onto
 * `vf3_native_aim`.  The guest keeps the current transform (XMTRX) in the XF
 * bank - v[37..52] in a readable state, `a->xm[16]` here - and the FR bank
 * in v[21..36], `a->fr[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no general register
 * touched).  The caller leaves a Z-rotation's sin in FR4 and cos in FR5.  The
 * body builds two FV column vectors
 *
 *     v0 = { cos,  sin, 0, 0 }        (FR0, FR1, FR2, FR3)
 *     v1 = { -sin, cos, 0, 0 }        (FR4, FR5, FR6, FR7)
 *
 * (FR1 <- FR4, FR4 ^= sign bit, FR0 <- FR5, FR2/FR3 = 0, then FR6/FR7 = 0),
 * runs each through XMTRX with ftrv (the column-major product
 * out[r] = sum_k xm[4k+r] * v[k]), and writes the results back into FR0..FR7
 * and into XMTRX columns 0 and 1 (XF0..XF3 and XF4..XF7).  Columns 2 and 3
 * (XF8..XF15), FR8..FR15, r15, SR, pr and every general register are
 * untouched.
 *
 * The sign flip of the second column's x (the `-sin`) is the negation bit
 * 0x80000000 toggled on FR4 -> v1's first component.
 *
 * See docs/re/native_matrix_rotate_sc.md. */
#include "matrix_rotate_sc.h"

#include "aim_math.h"

#include <stdint.h>

int vf3_native_matrix_rotate_sc(vf3_native_aim *a)
{
    /* v0 = { cos, sin, 0, 0 }, v1 = { -sin, cos, 0, 0 } */
    const float sin_ = a->fr[4];
    const float cos_ = a->fr[5];
    const float v0[4] = { cos_, sin_, 0.0f, 0.0f };
    const float v1[4] = { -sin_, cos_, 0.0f, 0.0f };
    float out0[4], out1[4];

    /* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX) */
    for (int r = 0; r < 4; ++r) {
        float s0 = 0.0f, s1 = 0.0f;
        for (int k = 0; k < 4; ++k) {
            s0 += a->xm[4 * k + r] * v0[k];
            s1 += a->xm[4 * k + r] * v1[k];
        }
        out0[r] = s0;
        out1[r] = s1;
    }

    /* the results land in FR0..FR3 and FR4..FR7 */
    for (int i = 0; i < 4; ++i) a->fr[i] = out0[i];
    for (int i = 0; i < 4; ++i) a->fr[4 + i] = out1[i];

    /* and into XMTRX columns 0 and 1 (XF0..XF3, XF4..XF7) */
    for (int i = 0; i < 4; ++i) a->xm[i] = out0[i];
    for (int i = 0; i < 4; ++i) a->xm[4 + i] = out1[i];
    return 1;
}
