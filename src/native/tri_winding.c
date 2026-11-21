/* tri_winding.c - SH-4 0x8C068F92: the screen-space triangle winding test,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/geom_readable.c
 * (`vf3_tri_winding_entry`) onto `vf3_native_aim`: the FR bank and the
 * register file.
 *
 * A pure-FR, call-free, no-stack, no-RAM leaf.  The three points arrive as
 * (x,y) pairs in FR4/FR5, FR6/FR7 and FR8/FR9.  With d01 = p1-p0 and
 * d12 = p2-p1 it forms
 *
 *     area = d01.y * d12.x - d01.x * d12.y
 *
 * and returns 2 for area > 0, 1 for area == 0, 4 otherwise (negative or NaN).
 * Only r0 is a result; every other caller-saved register is scratch.  The
 * FP arithmetic goes through the round-toward-zero + FTZ wrappers the other
 * FP native ports use, so the stored floats match the guest bit for bit.
 *
 * See docs/re/native_tri_winding.md. */
#include "tri_winding.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

/* ---- round-toward-zero + FTZ wrappers (as float_scale.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fop(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x - y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fsub(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '*'); }

/* result enum */
enum { WINDING_POSITIVE = 2, WINDING_DEGENERATE = 1, WINDING_NEGATIVE = 4 };

void vf3_native_tri_winding(vf3_native_aim *a)
{
    const float x0 = a->fr[4], y0 = a->fr[5];
    const float x1 = a->fr[6], y1 = a->fr[7];
    const float x2 = a->fr[8], y2 = a->fr[9];

    const float d12x = fsub(a, x2, x1);
    const float d01y = fsub(a, y1, y0);
    const float d01x = fsub(a, x1, x0);
    const float d12y = fsub(a, y2, y1);
    const float p_a = fmul(a, d01y, d12x);
    const float p_b = fmul(a, d01x, d12y);
    const float area = fsub(a, p_a, p_b);

    uint32_t result;
    if (area > 0.0f)
        result = WINDING_POSITIVE;
    else
        result = (area == 0.0f) ? WINDING_DEGENERATE : WINDING_NEGATIVE;
    a->r[0] = result;
}
