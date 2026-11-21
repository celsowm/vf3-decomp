/* atan_table.c - SH-4 0x8C069624: the atan-of-vector lookup table, natively.
 *
 * A plain-C transcription of the readable port src/fight/atan_table.c
 * (`vf3_atan_table_entry`) onto `vf3_native_aim`: the flat RAM (the halfword
 * table), the FR bank, the register file and FPUL.
 *
 * A self-contained integer/FP leaf (call-free, no stack frame, no
 * tail-transfer).  FR4 = x, FR5 = y.  Returns r0 = 0 for the zero vector.
 * Otherwise the smaller absolute value is divided by the larger and scaled to
 * index the halfword table at 0x0C0EAF60 (the angle of that slope, up to
 * 0x2000).  The octant is then folded back: 0x4000 - angle when |y| < |x| is
 * false, and by the signs of y and x the result is -angle, 0x8000 - angle,
 * angle - 0x8000 or the angle itself.
 *
 * The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
 * the other FP native ports use; divisons and multiplies round toward zero,
 * and the float-to-int step (ftrc) is the SH-4's saturating truncation.
 *
 * See docs/re/native_atan_table.md. */
#include "atan_table.h"

#include <fenv.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define TABLE      0x0C0EAF60u
#define SCALE_BITS 0x466A6000u
#define QUARTER    0x4000
#define HALF       0x8000
#define SIGN       0x80000000u

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* ---- round-toward-zero + FTZ wrappers (as glyph_cache.c) ---- */
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
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fdivv(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '/'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '*'); }

/* ftrc: the SH-4's float-to-integer truncation (toward zero), saturating. */
static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

void vf3_native_atan_table(vf3_native_aim *a)
{
    F(3) = 0;
    if (F(5) == F(3) && F(4) == F(3)) { R(0) = 0; return; }

    /* |y| */
    F(3) = 0;
    F(6) = F(5);
    if (F(3) > F(5)) F(6) = bits2f(fbits(F(6)) ^ SIGN);
    /* |x| */
    F(3) = 0;
    F(7) = F(4);
    if (F(3) > F(4)) F(7) = bits2f(fbits(F(7)) ^ SIGN);

    /* the smaller |value| divided by the larger */
    if (F(6) > F(7)) { F(8) = F(7); F(8) = fdivv(a, F(8), F(6)); }
    else             { F(8) = F(6); F(8) = fdivv(a, F(8), F(7)); }

    /* fr2 = |ratio| * scale */
    F(2) = F(8);
    F(3) = bits2f(SCALE_BITS);
    F(2) = fmul(a, F(2), F(3));

    const float v = F(2);
    int32_t t = v >= 2147483648.0f ? INT32_MAX : v <= -2147483648.0f ? INT32_MIN : (int32_t)v;
    a->fpul = (uint32_t)t;   /* FPUL = the table index */

    int32_t ang = (int16_t)vf3_aim_h16(a, TABLE + ((uint32_t)t << 1));
    if (F(7) > F(6)) ang = QUARTER - ang;

    F(3) = 0;
    if (F(3) > F(5)) {                              /* y < 0 */
        if (F(3) > F(4)) ang += (int16_t)HALF;      /* x < 0 */
        else             ang = HALF - ang;
    } else if (F(3) > F(4)) {                       /* y >= 0, x < 0 */
        ang = -ang;
    }
    R(4) = (uint32_t)ang;
    R(0) = (uint32_t)ang;
}
