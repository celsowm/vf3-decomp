/* matrix_concat_save.c - SH-4 0x8C03C140 (matrix_concat_save) and 0x8C03C200
 * (matrix_concat_parent), natively.
 *
 * Self-contained FP leaves in the column-major matrix family
 * (0x8C03B620..0x8C03C1FE, src/fight/matrix_lib.c).  matrix_concat_save is
 * the sibling of matrix_concat (0x8C03C0E0): XMTRX becomes XMTRX * M(r4),
 * the banks end up swapped (the old XMTRX shows in FR0..FR11, FPSCR.FR
 * toggles).  The difference is in how the caller's FR12..FR15 are protected:
 * matrix_concat parks fr12 in FPUL and pushes only FR13..FR15, then reads
 * them back off the stack; matrix_concat_save pushes all four saved words
 * (a round trip of 16 on the stack pointer) and puts them straight back into
 * the new FR bank from the saved registers, so FPUL is untouched.
 *
 * matrix_concat_parent computes r4 as one matrix (64 bytes) below the matrix
 * stack top (*(0x0C19D2E4 + 8)) and then runs matrix_concat_save.
 *
 * See docs/re/native_matrix_concat_save.md. */
#include "matrix_concat_save.h"

#include "aim_math.h"

#include <string.h>

enum {
    MATRIX_BYTES = 64u,
    FR_BIT = 0x00200000u,
    MATRIX_STACK_TOP = 0x0C19D2ECu,     /* *(0x0C19D2E4 + 8) */
};

int vf3_native_matrix_concat_save(vf3_native_aim *a)
{
    const uint32_t sp0 = a->r[15];
    const uint32_t saved[4] = { vf3_aim_ubits(a->fr[12]), vf3_aim_ubits(a->fr[13]),
                                vf3_aim_ubits(a->fr[14]), vf3_aim_ubits(a->fr[15]) };

    /* push FR15, FR14, FR13, FR12 (saved[3] .. saved[0]) onto the stack */
    vf3_aim_set_u32(a, sp0 - 4u,  saved[3]);
    vf3_aim_set_u32(a, sp0 - 8u,  saved[2]);
    vf3_aim_set_u32(a, sp0 - 12u, saved[1]);
    vf3_aim_set_u32(a, sp0 - 16u, saved[0]);

    float m[16], out[16], old_xm[12];
    memcpy(m, vf3_aim_p(a, a->r[4]), sizeof m);
    a->r[4] += MATRIX_BYTES;
    memcpy(old_xm, a->xm, sizeof old_xm);

    /* out = XMTRX * M (column-major: out[4c+r] = sum_k xm[4k+r] * m[4c+k]) */
    for (int c = 0; c < 4; ++c)
        for (int r = 0; r < 4; ++r) {
            float sum = 0.0f;
            for (int k = 0; k < 4; ++k)
                sum += a->xm[4 * k + r] * m[4 * c + k];
            out[4 * c + r] = sum;
        }

    /* frchg: the old XMTRX shows in FR0..FR11, XMTRX = out, FR bit toggles */
    for (int i = 0; i < 12; ++i) a->fr[i] = old_xm[i];
    memcpy(a->xm, out, sizeof out);
    a->fpscr ^= FR_BIT;

    /* the caller's FR12..FR15 go straight back into the new FR bank */
    for (int i = 0; i < 4; ++i) {
        float f; memcpy(&f, &saved[i], 4);
        a->fr[12 + i] = f;
    }
    a->r[15] = sp0;                     /* the 16-byte round trip pops back */
    return 1;
}

int vf3_native_matrix_concat_parent(vf3_native_aim *a)
{
    /* r4 = the matrix just below the stack top, then matrix_concat_save */
    a->r[4] = vf3_aim_u32(a, MATRIX_STACK_TOP) - MATRIX_BYTES;
    return vf3_native_matrix_concat_save(a);
}
