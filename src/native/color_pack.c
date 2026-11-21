/* color_pack.c - SH-4 0x8C03FB80: the color-pack, natively.
 *
 * A plain-C transcription of the readable port src/fight/geom_readable.c
 * (`vf3_color_pack_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank,
 * the register file and FPUL.
 *
 * A self-contained FP leaf (call-free, no stack frame, no tail-transfer).
 * FR4..FR7 (a, r, g, b) are scaled by 255 (the constant read from the literal
 * pool at 0x0C03FC38), converted to unsigned integers (a value at or above
 * 2^31 wraps through a -2^32 bias read at 0x0C03FC40, with the half range
 * 2^31 at 0x0C03FC3C), clamped to 255 as unsigned, and packed a:r:g:b into
 * r0 (also left in r4).  r5..r7 keep the clamped r, g, b.
 *
 * The FP multiply goes through the round-toward-zero + FTZ wrapper the other
 * FP native ports use, so the stored floats match the guest bit for bit; the
 * truncation (`ftrc`) is the SH-4's toward-zero conversion, and its corner
 * cases (NaN or < -2^31 -> 0x80000000, >= 2^31 -> 0x7fffffff) are kept.
 *
 * See docs/re/native_color_pack.md. */
#include "color_pack.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])

#define COLOR_SCALE_ADDR      0x0C03FC38u
#define COLOR_HALF_RANGE_ADDR 0x0C03FC3Cu
#define COLOR_WRAP_BIAS_ADDR  0x0C03FC40u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as float_scale.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fmul(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x * y;
    fesetround(saved);
    return flz(a, z);
}
static inline float fadd(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x + y;
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

void vf3_native_color_pack(vf3_native_aim *a)
{
    const float scale = vf3_aim_fbits(vf3_aim_u32(a, COLOR_SCALE_ADDR));
    const float half_range = vf3_aim_fbits(vf3_aim_u32(a, COLOR_HALF_RANGE_ADDR));
    const float bias = vf3_aim_fbits(vf3_aim_u32(a, COLOR_WRAP_BIAS_ADDR));

    float scaled[4];
    uint32_t raw[4];
    for (int i = 0; i < 4; ++i) {
        scaled[i] = fmul(a, a->fr[4 + i], scale);
        a->fr[4 + i] = scaled[i];
    }
    float converted = 0;
    for (int i = 0; i < 4; ++i) {
        converted = scaled[i] > half_range ? fadd(a, scaled[i], bias) : scaled[i];
        raw[i] = ftrc(converted);
    }
    a->fr[8] = scaled[0];
    a->fr[9] = half_range;
    a->fr[3] = converted;
    a->fr[4] = scaled[3];
    a->fpul = raw[3];

    uint32_t packed = 0;
    for (int i = 0; i < 4; ++i) {
        const uint32_t byte = raw[i] > 0xFFu ? 0xFFu : raw[i];
        packed = (packed << 8) | byte;
        if (i > 0) R(4 + i) = byte;
    }
    R(4) = packed;
    R(0) = packed;
    R(1) = 0;
    set_t(a, raw[3] > 0xFFu);   /* last cmp/hi */
}
