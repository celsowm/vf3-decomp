/* matrix_concat_pair.c - SH-4 0x8C03DD00 (matrix_concat_pair), natively.
 *
 * A self-contained FP leaf: XMTRX becomes XMTRX * A * B where A is the 16
 * floats at the pointer held in [0x0C19D308 + 8] and B the 16 floats at
 * 0x0C19D518.  The guest reads A and B as row vectors in order and runs every
 * XMTRX row through A and then through B (the ftrv bank-swap dance of
 * src/fight/matrix_concat_pair.c); the net effect is the single row-major
 * product XMTRX * A * B - which is exactly what this port computes with the
 * plain row-major loops below (the XF bank is stored row-major, so the native
 * column-major vf3_native_matrix_multiply does not fit).
 *
 * FR12..FR15 travel through the stack (sp0-16..-4) and come back untouched;
 * FR0..FR11 end as B.  r4 = B + 32, r5 = B + 64; r15, pr and SR are
 * untouched.  The SZ-bit guard (the body's own fschg dance needs FPSCR.SZ
 * clear) mirrors the readable `if (FPSCR & 0x100000) return 0`.
 *
 * See docs/re/native_matrix_concat_pair.md. */
#include "matrix_concat_pair.h"

#include "aim_math.h"

#include <string.h>

enum { FIRST_PTR = 0x0C19D308u, SECOND = 0x0C19D518u, SZ_BIT = 0x00100000u };

static void rowmajor_prod(const float l[16], const float r[16], float out[16])
{
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < 4; ++col)
            out[row * 4 + col] =
                l[row * 4 + 0] * r[0 * 4 + col] +
                l[row * 4 + 1] * r[1 * 4 + col] +
                l[row * 4 + 2] * r[2 * 4 + col] +
                l[row * 4 + 3] * r[3 * 4 + col];
}

int vf3_native_matrix_concat_pair(vf3_native_aim *a)
{
    if (a->fpscr & SZ_BIT)
        return 0;

    const uint32_t sp0 = a->r[15];
    const uint32_t first = vf3_aim_u32(a, FIRST_PTR + 8u);
    const float saved[4] = { a->fr[15], a->fr[14], a->fr[13], a->fr[12] };

    /* FR12..FR15 round-trip through the stack (sp0-4, -8, -12, -16). */
    vf3_aim_set_u32(a, sp0 - 4u, vf3_aim_ubits(saved[0]));
    vf3_aim_set_u32(a, sp0 - 8u, vf3_aim_ubits(saved[1]));
    vf3_aim_set_u32(a, sp0 - 12u, vf3_aim_ubits(saved[2]));
    vf3_aim_set_u32(a, sp0 - 16u, vf3_aim_ubits(saved[3]));

    float A[16], B[16], t[16], out[16];
    memcpy(A, vf3_aim_p(a, first), sizeof A);
    memcpy(B, vf3_aim_p(a, SECOND), sizeof B);

    /* XMTRX = XMTRX * A * B (row-major, exactly the readable's net effect). */
    rowmajor_prod(a->xm, A, t);
    rowmajor_prod(t, B, out);
    memcpy(a->xm, out, sizeof out);

    /* FR0..FR11 = B, FR12..FR15 back as they were */
    memcpy(a->fr, B, 12u * sizeof(float));

    a->r[4] = SECOND + 32u;
    a->r[5] = SECOND + 64u;
    return 1;
}
