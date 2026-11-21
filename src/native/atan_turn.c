/* atan_turn.c - SH-4 0x8C039FD0: the arctangent-of-fr4 in 16-bit turns,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/atan_turn.c
 * (`vf3_atan_turn_entry`) onto `vf3_native_aim`: the FR bank and the register
 * file (the leaf reads nothing from RAM).
 *
 * A self-contained FP leaf (call-free, no stack frame, no tail-transfer).
 * FR4 = x.  The argument is folded into [-1, 1] (u = 1/x when |x| > 1, else
 * u = x) and atan(u) is evaluated as a 13-term continued fraction in u^2:
 *
 *     t = 0;  for n = 13 .. 2:  t = (n^2 * u^2) / (2n + t + 1)
 *     atan = u / (1 + t)
 *
 * scaled to turns as (atan + 2pi) * 65536 / 2pi + 0.5, truncated and masked
 * to 16 bits.  For x > 1 the result is 0x4000 - angle, for x < -1 it is
 * 0xC000 - angle (the quadrant fold), otherwise the angle itself, all
 * zero-extended from 16 bits.
 *
 * The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
 * the other FP native ports use (the body confirms it with the FPU-supported
 * test and the precision guard, so the corpus FPSCR 0x00024001 - RM=truncate
 * and FTZ - is in force), so the stored floats match the guest bit for bit;
 * the truncation (`ftrc`) is the SH-4's toward-zero conversion, and its
 * corner cases (NaN or < -2^31 -> 0x80000000, >= 2^31 -> 0x7fffffff) are
 * kept.
 *
 * See docs/re/native_atan_turn.md. */
#include "atan_turn.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define TWO_PI_BITS  0x40C90FDAu
#define SCALE_BITS   0x47800000u
#define HALF_BITS    0x3F000000u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* ---- round-toward-zero + FTZ wrappers (as glyph_cache.c/float_scale.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
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
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fdivv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }

/* ftrc: the SH-4's float-to-integer truncation (toward zero). */
static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

void vf3_native_atan_turn(vf3_native_aim *a)
{
    const float x = F(4);
    const float one = 1.0f;

    float u = x;
    if (bits2f(fbits(x) & 0x7FFFFFFFu) > one) u = fdivv(a, one, x);

    float t = 0.0f, num = 0.0f, den = 0.0f, sq = 0.0f;
    int32_t n = 13;
    for (;;) {
        const int32_t cur = n;
        n -= 1;
        float fn = (float)cur;                       /* vf3_f_from_int */
        den = (float)(cur << 1);                     /* vf3_f_from_int */
        sq = fmul(a, fn, fn);
        den = fadd(a, den, t);
        num = fmul(a, sq, u);
        den = fadd(a, den, one);
        num = fmul(a, num, u);
        t = fdivv(a, num, den);                      /* the delay slot, last pass too */
        F(8) = fn;
        if (n < 1) break;
    }
    t = fadd(a, t, one);
    const float atan = fdivv(a, u, t);
    const float two_pi = bits2f(TWO_PI_BITS), scale = bits2f(SCALE_BITS), half = bits2f(HALF_BITS);
    float v = fadd(a, atan, two_pi);
    v = fmul(a, v, scale);
    v = fdivv(a, v, two_pi);
    v = fadd(a, v, half);
    const uint32_t raw = ftrc(v), ang = raw & 0xFFFFu;

    uint32_t r0;
    if (x > one) r0 = 0x4000u - ang;
    else if (bits2f(0xBF800000u) > x) r0 = 0xC000u - ang;
    else r0 = ang;
    r0 &= 0xFFFFu;

    R(0) = r0;
    R(3) = 0xFFFFu;
    R(4) = ang;
    R(5) = 1;
    const int tflag = x > one ? 1 : (bits2f(0xBF800000u) > x);
    set_t(a, tflag);
    F(1) = half;
    F(2) = scale;
    F(3) = x > one ? v : -1.0f;        /* the x <= 1 path reloads fr3 with the -1 bound */
    F(5) = atan;
    F(6) = one;
    F(7) = two_pi;
    a->fpul = raw;
}
