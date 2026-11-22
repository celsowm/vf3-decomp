/* matrix_concat.c - SH-4 0x8C03C0E0 (matrix_concat), natively.
 *
 * A self-contained FP leaf in the column-major matrix family
 * (0x8C03B620..0x8C03C1FE, src/fight/matrix_lib.c): XMTRX becomes
 * XMTRX * M(r4), where M is the 16 floats at r4.  The guest runs each M
 * column through ftrv(XMTRX, ...), i.e. out[4c] = XMTRX * m[4c] in the
 * column-major convention - the post-multiplied product (the opposite side
 * from matrix_premul, where the loaded matrix premultiplies).
 *
 * The bank-swap emulation of the guest's frchg puts the OLD XMTRX into
 * fr[0..11] (the readable copies xf into fr, then xf = out) and toggles
 * FPSCR.FR (0x00200000).  FR12..FR15 travel through the stack - pushed as
 * FR15, FR14, FR13 at sp0-4, sp0-8, sp0-12 - and are restored, so the stack
 * pointer is net flat and r15 is untouched.  r4 advances by 64.
 *
 * See docs/re/native_matrix_concat.md. */
#include "matrix_concat.h"

#include "aim_math.h"

#include <string.h>

enum { MATRIX_BYTES = 64u, FR_BIT = 0x00200000u };

int vf3_native_matrix_concat(vf3_native_aim *a)
{
    const uint32_t sp0 = a->r[15];
    float old_xm[12];
    memcpy(old_xm, a->xm, sizeof old_xm);
    const uint32_t saved[4] = { vf3_aim_ubits(a->fr[12]), vf3_aim_ubits(a->fr[13]),
                                vf3_aim_ubits(a->fr[14]), vf3_aim_ubits(a->fr[15]) };

    /* push FR15, FR14, FR13 onto the stack (sp0-4 .. sp0-12) */
    vf3_aim_set_u32(a, sp0 - 4u,  saved[3]);
    vf3_aim_set_u32(a, sp0 - 8u,  saved[2]);
    vf3_aim_set_u32(a, sp0 - 12u, saved[1]);
    a->fpul = saved[0];                         /* FPUL = fr12 */

    float m[16], out[16];
    memcpy(m, vf3_aim_p(a, a->r[4]), sizeof m);
    a->r[4] += MATRIX_BYTES;

    /* out = XMTRX * M (column-major: out[4c+r] = sum_k xm[4k+r] * m[4c+k]) */
    for (int c = 0; c < 4; ++c)
        for (int r = 0; r < 4; ++r) {
            float sum = 0.0f;
            for (int k = 0; k < 4; ++k)
                sum += a->xm[4 * k + r] * m[4 * c + k];
            out[4 * c + r] = sum;
        }

    /* frchg: the old XMTRX shows in FR0..FR11, XMTRX = out, FR bit toggles */
    for (int i = 0; i < 12; ++i) {
        float f; memcpy(&f, &old_xm[i], 4);
        a->fr[i] = f;
    }
    memcpy(a->xm, out, sizeof out);
    a->fpscr ^= FR_BIT;

    /* FR12..FR15 restored from the stack (fr[12] = saved fr12, then the
     * pushed FR13, FR14, FR15 come back); the stack pointer returns to sp0 */
    for (int i = 0; i < 4; ++i) {
        float f; memcpy(&f, &saved[i], 4);
        a->fr[12 + i] = f;
    }
    return 1;
}
