/* matrix_invert_rigid.c - SH-4 0x8C03C5B0 (matrix_invert_rigid), natively.
 *
 * A self-contained FP leaf (call-free, no stack frame): it inverts a *rigid*
 * (rotation + translation) XMTRX in place.
 *
 * With t = the translation (columns 12..15) and c0, c1, c2 the three axis
 * columns (groups of four at 0, 4, 8):
 *
 *   1. the three axis columns' w elements become 0; t.w becomes 1
 *   2. tc_i = t . c_i          (a four-element FIPR dot, including t.w * c_i.w)
 *   3. t_i = -(tc_i)           (the translation becomes -(t . c_i), i.e. -(R^T t))
 *   4. the 3x3 block is transposed (swap the off-diagonal pairs (1,4) (2,8)
 *      (6,9) through FPUL)      -- the rotation inverse
 *   5. the w elements (3, 7, 11) are cleared again
 *
 * This is the rigid sibling of matrix_invert_scaled (0x8C03B5C0); it omits
 * the axis-length normalisation because a rigid matrix has unit columns.
 *
 * Operates purely on XMTRX (a->xm); the FR bank, r15 and SR are untouched.
 * The transpose's FPUL swaps leave a->fpul = the value that was in slot 6
 * just before the last swap.
 *
 * See docs/re/native_matrix_invert_rigid.md. */
#include "matrix_invert_rigid.h"

#include "aim_math.h"

int vf3_native_matrix_invert_rigid(vf3_native_aim *a)
{
    float *xm = a->xm;   /* column-major: col0 = xm[0..3], ..., t = xm[12..15] */

    /* 1. clear the axis columns' w elements; t.w = 1 */
    xm[3] = 0.0f; xm[7] = 0.0f; xm[11] = 0.0f; xm[15] = 1.0f;

    /* 2. tc_i = t . c_i (four-element dots; c_i.w is now 0, t.w = 1) */
    const float tc0 = xm[12] * xm[0] + xm[13] * xm[1] + xm[14] * xm[2] + xm[15] * xm[3];
    const float tc1 = xm[12] * xm[4] + xm[13] * xm[5] + xm[14] * xm[6] + xm[15] * xm[7];
    const float tc2 = xm[12] * xm[8] + xm[13] * xm[9] + xm[14] * xm[10] + xm[15] * xm[11];

    /* 3. t_i = -(t . c_i) */
    xm[12] = -tc0; xm[13] = -tc1; xm[14] = -tc2;

    /* 4. transpose the 3x3 block; the swaps ride FPUL */
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

    /* 5. clear the w elements again */
    xm[3] = 0.0f; xm[7] = 0.0f; xm[11] = 0.0f;
    return 1;
}
