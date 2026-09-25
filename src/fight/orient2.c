/* See orient2.h. Single-precision IEEE arithmetic, same as SH-4 FPU
 * round-to-nearest; the caller at 0x8C068FF6 issues this five times per
 * vertex and folds the bits into a mask, so the numeric return values are
 * part of the ABI and must not be renumbered. */
#include "fight/orient2.h"

int vf3_orient2_bits(float fr4, float fr5, float fr6,
                     float fr7, float fr8, float fr9)
{
    float a = (fr7 - fr5) * (fr8 - fr6);
    float b = (fr6 - fr4) * (fr9 - fr7);
    float d = a - b;

    if (d > 0.0f)
        return VF3_ORIENT_POS;
    if (d == 0.0f)
        return VF3_ORIENT_ON;
    return VF3_ORIENT_NEG;
}
