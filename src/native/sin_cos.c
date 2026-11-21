/* sin_cos.c - SH-4 0x8C03A6E0 (sin) / 0x8C03A140 (cos) of a 16-bit angle,
 * natively.
 *
 * Plain-C transcriptions of the readable ports src/fight/geom_readable.c
 * (`vf3_sin_u16_entry` / `vf3_cos_u16_entry`) onto `vf3_native_aim`: the FR
 * bank and the register file (the leaves read nothing from RAM).
 *
 * Self-contained FP leaves (call-free, no stack frame).  r4 = the angle (low
 * 16 bits are used).  sin: theta = angle*2pi/65536, h = theta/2, the half
 * angle is reduced to y = h - n*pi/2 (n = nearest quadrant), tan(y) comes
 * from the continued fraction y / (1 - y^2/(3 - y^2/(5 - .../11))), and
 * sin(theta) = +-2t/(1 + t^2) with t = tan(y) (sign flips for odd n).  The
 * result lands in FR0.  cos = sin(0x4000 - a') with the half-turn fold.
 *
 * The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
 * the other FP native ports use; the fused multiply-add (the single `fmac`)
 * uses `fmaf` so it rounds once, and the `ftrc` is the SH-4's saturating
 * toward-zero truncation.
 *
 * See docs/re/native_sin_cos.md. */
#include "sin_cos.h"

#include <fenv.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define K_TWO     0x40000000u
#define K_TWO_PI  0x40c90fdau
#define K_TURN    0x47800000u   /* 65536.0f */
#define K_HALF_PI 0x3fc90fdau
#define K_HALF    0x3f000000u

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* ---- round-toward-zero + FTZ wrappers (as float_scale.c/atan_turn.c) ---- */
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
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fdivv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }
static inline float fmac0(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flz(a, z);
}

/* ftrc: the SH-4's float-to-integer truncation (toward zero). */
static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

void vf3_native_sin_u16(vf3_native_aim *a)
{
    const uint32_t angle = R(4) & 0xFFFFu;
    const float two = bits2f(K_TWO), two_pi = bits2f(K_TWO_PI),
                turn = bits2f(K_TURN), half_pi = bits2f(K_HALF_PI),
                half = bits2f(K_HALF);

    const float theta = fdivv(a, fmul(a, (float)angle, two_pi), turn);
    const float h = fdivv(a, theta, two);

    const int32_t quadrant = (int32_t)ftrc(fadd(a, fdivv(a, h, half_pi), half));
    const float y = fsub(a, h, fmul(a, (float)quadrant, half_pi));
    const float y_sq = fmul(a, y, y);

    float frac = 0.0f;
    for (int k = 11; k >= 3; k -= 2)
        frac = fdivv(a, y_sq, fsub(a, (float)k, frac));

    const float t = fdivv(a, y, fsub(a, 1.0f, frac));
    const float denom = fmac0(a, t, t, 1.0f);
    const float sine = fdivv(a, fmul(a, t, two), denom);

    F(0) = (quadrant & 1) ? -sine : sine;
}

void vf3_native_cos_u16(vf3_native_aim *a)
{
    /* the original pushes r14 and pops it again; the dead stack word is
     * visible in RAM */
    vf3_aim_set_u32(a, R(15) - 4u, R(14));
    uint32_t angle = R(4) & 0xFFFFu;
    if (angle > 0x8000u) angle = 0x10000u - angle;
    R(4) = 0x4000u - angle;
    vf3_native_sin_u16(a);
}
