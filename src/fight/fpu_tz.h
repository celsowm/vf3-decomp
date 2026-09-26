/* fpu_tz.h — SH-4 FPU helpers matching the game's FPSCR (RM=1, DN=1).
 *
 * Golden snapshots show FPSCR = 0x240001 in fight code: round toward zero
 * and denormals-are-zero. C's default round-to-nearest differs by ~1 ULP on
 * many ops; these helpers compute the exact (long double) result and step
 * toward zero, which reproduces the emulator bit-exactly for the value
 * ranges seen in the engine.
 */
#ifndef VF3_FIGHT_FPU_TZ_H
#define VF3_FIGHT_FPU_TZ_H

#include <math.h>
#include <stdint.h>
#include <string.h>

static float f32_tz(long double x)
{
    float f = (float)x;                        /* nearest */
    if (f != 0.0f && fabsl((long double)f) > fabsl(x))
        f = nextafterf(f, 0.0f);               /* step toward zero */
    return f;
}

static float fmul_tz(float a, float b) { return f32_tz((long double)a * b); }
static float fdiv_tz(float a, float b) { return f32_tz((long double)a / b); }
static float fadd_tz(float a, float b) { return f32_tz((long double)a + b); }
static float fsub_tz(float a, float b) { return f32_tz((long double)a - b); }
static float fmac_tz(float a, float b, float c)
{
    return f32_tz(fmal((long double)a, (long double)b, (long double)c));
}

static float fpu_bits_to_f32(uint32_t bits)
{
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static uint32_t fpu_f32_to_bits(float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    return bits;
}

/* DN=1 denormal flush (FPSCR bit 21): subnormal op results flush to
 * signed zero. float/fldi/fmov/ftrc never produce subnormals. */
static float fpu_dn_fix(float f, uint32_t fpscr)
{
    uint32_t bits;
    if ((fpscr & 0x00200000u) == 0)
        return f;
    memcpy(&bits, &f, 4);
    if ((bits & 0x7F800000u) == 0 && (bits & 0x007FFFFFu) != 0) {
        bits &= 0x80000000u;
        memcpy(&f, &bits, 4);
    }
    return f;
}

#endif /* VF3_FIGHT_FPU_TZ_H */
