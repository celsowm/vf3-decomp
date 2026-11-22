/* matrix_invert_scaled.c - SH-4 0x8C03B5C0 (matrix_invert_scaled), natively.
 *
 * A self-contained FP leaf (call-free, no stack frame): it inverts a
 * rotation + scale + translation XMTRX in place.
 *
 * With t = the translation (columns 12..15) and c0, c1, c2 the three axis
 * columns (groups of four at 0, 4, 8):
 *
 *   1. tc_i = t . c_i          (a four-element FIPR dot, including t.w * c_i.w)
 *   2. t = (tc0, tc1, tc2); the three axis columns' w elements become 0
 *   3. l_i = |c_i|^2           (now with w = 0, so a true axis length squared)
 *      and t is negated        (-(t . c_i))
 *   4. inv_i = 1/sqrt(l_i)     (the fsrra 1/sqrt)
 *   5. c_i's first three elements AND t's i-th element are multiplied by
 *      inv_i (normalise the axes; the translation becomes -(t . c_i)/|c_i|)
 *   6. the 3x3 block is transposed (swap the off-diagonal pairs (1,4) (2,8)
 *      (6,9) through FPUL)      -- the rotation inverse
 *   7. the w elements (3, 7, 11) are cleared again
 *
 * Operates purely on XMTRX (a->xm); the FR bank, r15 and SR are untouched.
 * The transpose's FPUL swaps leave a->fpul = the value that was in slot 6
 * just before the last swap.
 *
 * See docs/re/native_matrix_invert_scaled.md. */
#include "matrix_invert_scaled.h"

#include "aim_math.h"

#include <math.h>

int vf3_native_matrix_invert_scaled(vf3_native_aim *a)
{
    float *xm = a->xm;   /* column-major: col0 = xm[0..3], ..., t = xm[12..15] */

    /* 1. t . c_i (four-element dots, including the w elements) */
    const float tc0 = xm[12] * xm[0] + xm[13] * xm[1] + xm[14] * xm[2] + xm[15] * xm[3];
    const float tc1 = xm[12] * xm[4] + xm[13] * xm[5] + xm[14] * xm[6] + xm[15] * xm[7];
    const float tc2 = xm[12] * xm[8] + xm[13] * xm[9] + xm[14] * xm[10] + xm[15] * xm[11];

    /* 2. t = the dots; the axis columns' w elements become 0 */
    xm[12] = tc0; xm[3] = 0.0f;
    xm[13] = tc1; xm[7] = 0.0f;
    xm[14] = tc2; xm[11] = 0.0f;

    /* 3. |c_i|^2 (w now 0), and negate t */
    const float l0 = xm[0] * xm[0] + xm[1] * xm[1] + xm[2] * xm[2];
    const float l1 = xm[4] * xm[4] + xm[5] * xm[5] + xm[6] * xm[6];
    const float l2 = xm[8] * xm[8] + xm[9] * xm[9] + xm[10] * xm[10];
    xm[12] = -xm[12]; xm[13] = -xm[13]; xm[14] = -xm[14];

    /* 4. inv_i = 1/sqrt(l_i) */
    const float inv0 = 1.0f / sqrtf(l0);
    const float inv1 = 1.0f / sqrtf(l1);
    const float inv2 = 1.0f / sqrtf(l2);

    /* 5. normalise the axes and the translation components */
    xm[0] *= inv0; xm[1] *= inv0; xm[2] *= inv0; xm[12] *= inv0;
    xm[4] *= inv1; xm[5] *= inv1; xm[6] *= inv1; xm[13] *= inv1;
    xm[8] *= inv2; xm[9] *= inv2; xm[10] *= inv2; xm[14] *= inv2;

    /* 6. transpose the 3x3 block; the swaps ride FPUL */
    /* swap (1,4) */
    {
        float t = xm[1]; a->fpul = vf3_aim_ubits(t); xm[1] = xm[4]; xm[4] = t;
    }
    /* swap (2,8) */
    {
        float t = xm[2]; a->fpul = vf3_aim_ubits(t); xm[2] = xm[8]; xm[8] = t;
    }
    /* swap (6,9) */
    {
        float t = xm[6]; a->fpul = vf3_aim_ubits(t); xm[6] = xm[9]; xm[9] = t;
    }

    /* 7. clear the w elements again */
    xm[3] = 0.0f; xm[7] = 0.0f; xm[11] = 0.0f;
    return 1;
}
