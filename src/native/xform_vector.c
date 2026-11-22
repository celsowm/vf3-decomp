/* xform_vector.c - SH-4 0x8C03B4B0 (xform_vector), natively.
 *
 * A self-contained FP leaf (call-free, no stack frame), in the column-major
 * matrix family.  It reads the three floats at r4 as a vector, runs it
 * through XMTRX as (x, y, z, 0) via ftrv (the column-major product
 * out[r] = sum_k xm[4k+r] * v[k]; the w=0 component drops the translation,
 * so this is rotation-only), lands the full four-component result in
 * FR4..FR7 and writes the three floats out to r5.  r4 advances by 12.
 *
 * FR4..FR7 end as the transformed vector; FR8..FR15, r15 and SR are
 * untouched.
 *
 * See docs/re/native_xform_vector.md. */
#include "xform_vector.h"

#include "aim_math.h"

int vf3_native_xform_vector(vf3_native_aim *a)
{
    /* load the vector (x, y, z, 0) from r4 */
    float v[4];
    for (int i = 0; i < 3; ++i)
        v[i] = *vf3_aim_p(a, a->r[4] + 4u * (uint32_t)i);
    v[3] = 0.0f;

    /* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX) */
    float out[4];
    for (int r = 0; r < 4; ++r) {
        float s = 0.0f;
        for (int k = 0; k < 4; ++k)
            s += a->xm[4 * k + r] * v[k];
        out[r] = s;
    }

    /* the result lands in FR4..FR7 (the full ftrv output) */
    for (int i = 0; i < 4; ++i) a->fr[4 + i] = out[i];

    /* and x/y/z are written out to r5 */
    for (int i = 0; i < 3; ++i)
        *vf3_aim_p(a, a->r[5] + 4u * (uint32_t)i) = out[i];

    /* r4 advances by 12 */
    a->r[4] += 12u;
    return 1;
}
