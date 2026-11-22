/* matrix_rotate_z.c - SH-4 0x8C03C940 (rotate_z), natively.
 *
 * A plain-C transcription of the readable port src/fight/leaf_math.c
 * (`vf3_rotate_z_entry`) onto `vf3_native_aim`.  The guest keeps the current
 * transform (XMTRX) in the XF bank - v[37..52] in a readable state, `a->xm[16]`
 * here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained FP leaf (call-free, no stack frame, no general register
 * touched).  The caller leaves the Z-rotation angle in r4 (65536 = one turn) and
 * the body derives sin/cos from it with fsca (reproduced here with sinf/cosf of
 * the angle converted to radians, the aim-math convention), then builds the two
 * FV column vectors
 *
 *     v0 = { cos,  sin, 0, 0 }        (FR0, FR1, FR2, FR3)
 *     v1 = { -sin, cos, 0, 0 }        (FR4, FR5, FR6, FR7)
 *
 * runs each through XMTRX with ftrv (the column-major product
 * out[r] = sum_k xm[4k+r] * v[k]), and writes the results back into FR0..FR7
 * and into XMTRX columns 0 and 1 (XF0..XF3 and XF4..XF7).  Columns 2 and 3
 * (XF8..XF15), FR8..FR15, r15, SR, pr and every general register are untouched.
 * FPUL is left as the angle (the guest sets FPUL = r4 before fsca).
 *
 * The sign of the second column's x (the `-sin`) is the negation bit
 * 0x80000000 toggled on FR4 -> v1's first component.
 *
 * See docs/re/native_matrix_rotate_z.md. */
#include "matrix_rotate_z.h"

#include "aim_math.h"

#include <math.h>
#include <stdint.h>

static const double ROT_TURN = 3.14159265358979323846 / 32768.0;

int vf3_native_matrix_rotate_z(vf3_native_aim *a)
{
    const uint32_t angle = a->r[4] & 0xFFFFu;
    const float radians = (float)((double)angle * ROT_TURN);
    const float sin_ = sinf(radians);
    const float cos_ = cosf(radians);
    a->fpul = a->r[4];

    /* v0 = { cos, sin, 0, 0 }, v1 = { -sin, cos, 0, 0 } */
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
