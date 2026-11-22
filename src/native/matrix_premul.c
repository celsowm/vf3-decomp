/* matrix_premul.c - SH-4 0x8C03C1C0 (matrix_premul), natively.
 *
 * A self-contained FP leaf in the column-major matrix family
 * (0x8C03B620..0x8C03C1FE, src/fight/matrix_lib.c): XMTRX becomes
 * M(r4) * XMTRX, where M is the 16 floats at r4.  The guest runs each old
 * XMTRX column through ftrv(m, ...), i.e. out = m * old_xmtrx in the
 * column-major convention (M[4*c + r] = row r of column c) - exactly the
 * product vf3_native_matrix_multiply computes.  FR0..FR11 end as the first
 * twelve floats of M (fr[i] = m[i] for every i, then FR12..FR15 are
 * restored); FR12..FR15 travel through the stack (sp0-16..-4, in the order
 * FR15, FR14, FR13, FR12) and come back untouched.  r4 advances by 64.
 * r15 and SR are untouched.
 *
 * See docs/re/native_matrix_premul.md. */
#include "matrix_premul.h"

#include "aim_math.h"

#include <string.h>

enum { MATRIX_BYTES = 64u };

int vf3_native_matrix_premul(vf3_native_aim *a)
{
    const uint32_t sp0 = a->r[15];
    uint32_t saved[4];
    for (int i = 0; i < 4; ++i) saved[i] = vf3_aim_ubits(a->fr[12 + i]);

    /* push FR15, FR14, FR13, FR12 onto the stack (sp0-4 .. sp0-16) */
    vf3_aim_set_u32(a, sp0 - 4u,  saved[3]);
    vf3_aim_set_u32(a, sp0 - 8u,  saved[2]);
    vf3_aim_set_u32(a, sp0 - 12u, saved[1]);
    vf3_aim_set_u32(a, sp0 - 16u, saved[0]);

    float m[16], out[16];
    memcpy(m, vf3_aim_p(a, a->r[4]), sizeof m);
    a->r[4] += MATRIX_BYTES;

    /* out = m * XMTRX (column-major: out[4c+r] = sum_k m[4k+r] * xm[4c+k]) */
    for (int c = 0; c < 4; ++c)
        for (int r = 0; r < 4; ++r) {
            float sum = 0.0f;
            for (int k = 0; k < 4; ++k)
                sum += m[4 * k + r] * a->xm[4 * c + k];
            out[4 * c + r] = sum;
        }

    /* fr[i] = m[i]; XMTRX = out; then FR12..FR15 restored */
    memcpy(a->fr, m, 12u * sizeof(float));
    memcpy(a->xm, out, sizeof out);
    for (int i = 0; i < 4; ++i) {
        float f; memcpy(&f, &saved[i], 4);
        a->fr[12 + i] = f;
    }
    return 1;
}
