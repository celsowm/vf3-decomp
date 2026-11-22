/* matrix_translate_by.c - SH-4 0x8C03CC60 (matrix_translate_by), natively.
 *
 * A plain-C transcription of the readable port src/fight/leaf_math.c
 * (`vf3_matrix_translate_by_entry`) onto `vf3_native_aim`.  The guest keeps
 * the current transform (XMTRX) in the XF bank - v[37..52] in a readable
 * state, `a->xm[16]` here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no general register
 * touched).  It runs the local offset (FR4, FR5, FR6, 1) through XMTRX via
 * ftrv - the column-major product out[r] = sum_k xm[4k+r] * v[k] with the
 * w=1 component, so the translation contributes - and writes the result
 * (FR4..FR7) into XMTRX's translation column (XF12..XF15).  FR7 is set to
 * 1.0 first.  FR8..FR15, r15, SR, pr and every general register are
 * untouched.
 *
 * See docs/re/native_matrix_translate_by.md. */
#include "matrix_translate_by.h"

#include "aim_math.h"

int vf3_native_matrix_translate_by(vf3_native_aim *a)
{
    /* FR7 = 1: the local offset becomes (FR4, FR5, FR6, 1) */
    a->fr[7] = 1.0f;

    /* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX), v = FR4..FR7 */
    const float v[4] = { a->fr[4], a->fr[5], a->fr[6], a->fr[7] };
    float out[4];
    for (int r = 0; r < 4; ++r) {
        float s = 0.0f;
        for (int k = 0; k < 4; ++k)
            s += a->xm[4 * k + r] * v[k];
        out[r] = s;
    }

    /* the result lands in FR4..FR7 and becomes XF12..XF15 */
    for (int i = 0; i < 4; ++i) a->fr[4 + i] = out[i];
    for (int i = 0; i < 4; ++i) a->xm[12 + i] = out[i];
    return 1;
}
