/* rotation_xmtrx.c - SH-4 0x8C03C8B0 (rotation_xmtrx), natively.
 *
 * A self-contained FP leaf (call-free, no stack), the matrix-family sibling
 * of the concat/premul leaves.  It takes two angles already in FR4 (sin) and
 * FR5 (cos), builds two FV column vectors
 *
 *     v0 = { cos, 0, -sin, 0 }        (FR0, FR1, FR2, FR3)
 *     v1 = { sin, 0,  cos, 0 }        (FR4, FR5, FR6, FR7)
 *
 * and runs each through XMTRX with ftrv (the column-major product
 * out[r] = sum_k xm[4k+r] * v[k]).  The results land back in FR0..FR3 and
 * FR4..FR7, and are written into XMTRX columns 0 and 2 (XF0..XF3 and
 * XF8..XF11); columns 1 and 3 are untouched.  FR8..FR15, r15 and SR are
 * untouched.
 *
 * See docs/re/native_rotation_xmtrx.md. */
#include "rotation_xmtrx.h"

#include "aim_math.h"

int vf3_native_rotation_xmtrx(vf3_native_aim *a)
{
    /* v0 = { cos, 0, -sin, 0 }, v1 = { sin, 0, cos, 0 } */
    const float cos_ = a->fr[5];
    const float sin_ = a->fr[4];
    const float v0[4] = { cos_, 0.0f, -sin_, 0.0f };
    const float v1[4] = { sin_, 0.0f, cos_, 0.0f };
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

    /* and into XMTRX columns 0 and 2 (XF0..XF3, XF8..XF11) */
    for (int i = 0; i < 4; ++i) a->xm[i] = out0[i];
    for (int i = 0; i < 4; ++i) a->xm[8 + i] = out1[i];
    return 1;
}
