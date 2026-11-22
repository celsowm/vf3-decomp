/* axis_extract.c - SH-4 0x8C03EE40 (axis_extract), natively.
 *
 * A self-contained FP leaf (call-free, no stack frame): it derives the
 * camera/body axes from a three-by-four direction table at 0x0C0EA624,
 * transforms two of its rows through the transpose of XMTRX's 3x3 part, and
 * writes the result to the vector block at 0x0C1A58A0.
 *
 * With M = XMTRX (column-major) and t = the table's four floats:
 *
 *   result[i] = sum_k M[4i + k] * v[k]        (the ftrv(M^T, v) row product)
 *
 *   block[+16..+18] = (t0, t1, t2) . M^T      (a transformed copy of row 0)
 *   block[+0..+2]   = norm((t0, t1, t3) . M^T)     (the unit axis)
 *
 * XMTRX is unchanged on exit.  r0 = 8, r4 = BLOCK, r5 = TABLE + 8.  The
 * transpose's FPUL choreography leaves a->fpul = xm[9] (the value that was
 * in slot 6 of the transposed matrix just before the last swap).
 *
 * See docs/re/native_axis_extract.md. */
#include "axis_extract.h"

#include "aim_math.h"

#include <math.h>

#define R(n) (a->r[(n)])

enum { BLOCK = 0x0C1A58A0u, TABLE = 0x0C0EA624u };

void vf3_native_axis_extract(vf3_native_aim *a)
{
    const float *t = vf3_aim_p(a, TABLE);
    const float t0 = t[0], t1 = t[1], t2 = t[2], t3 = t[3];
    const float *M = a->xm;
    float *blk = vf3_aim_p(a, BLOCK);

    /* first row copy: (t0, t1, t2) . M^T -> block[+16..+18] */
    float r[3];
    for (int i = 0; i < 3; ++i)
        r[i] = M[4 * i] * t0 + M[4 * i + 1] * t1 + M[4 * i + 2] * t2;
    blk[4] = r[0]; blk[5] = r[1]; blk[6] = r[2];   /* +16, +20, +24 bytes */

    /* unit axis: (t0, t1, t3) . M^T, normalised by 1/sqrt(|.|^2) */
    float s[3];
    for (int i = 0; i < 3; ++i)
        s[i] = M[4 * i] * t0 + M[4 * i + 1] * t1 + M[4 * i + 2] * t3;
    const float len2 = s[0] * s[0] + s[1] * s[1] + s[2] * s[2];
    const float inv = 1.0f / sqrtf(len2);   /* fsrra */
    blk[0] = s[0] * inv; blk[1] = s[1] * inv; blk[2] = s[2] * inv;

    R(0) = 8;
    R(4) = BLOCK;
    R(5) = TABLE + 8;
    a->fpul = vf3_aim_ubits(M[9]);   /* last transpose put-back swap */
}
