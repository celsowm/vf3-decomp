/* float_scale.c - SH-4 0x8C039C50 and 0x8C039C70: the fight engine's
 * unsigned-32-to-float scale, natively.
 *
 * A plain-C transcription of the readable port src/fight/float_scale.c
 * (`vf3_float_scale_a_entry` / `vf3_float_scale_b_entry`).  It operates on
 * `vf3_native_aim`: the flat RAM, the FR bank, the register file and FPUL.
 * A self-contained leaf - it calls nobody and keeps **no stack frame**, but
 * it reads one 32-bit value through a global pointer, converts it to a float,
 * folds the sign bit back in with the textbook 2^32 addition when it is set,
 * scales the result by a constant read from the literal pool and returns the
 * truncated integer.
 *
 *   POOL_P1 -> the value's address (0x0c039d4c or 0x0c039d58)
 *   POOL_PLUS -> 4294967296.0f (0x4f800000) - the 2^32 the sign bit folds in
 *   POOL_SCALE -> 1.28f (0x3fa3d70a) - the scale
 *
 * The "add 2^32 when negative" is the unsigned-wrapping trick: the SH-4's
 * `float FPUL,FRn` converts its 32-bit integer as signed, so to get the
 * float of the unsigned interpretation the guest loads the pool's 0x4f800000
 * straight into FPUL (via `lds`) and adds it as a float.
 *
 * The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
 * the other FP native ports use (the corpus FPSCR 0x00040001 sets RM=truncate
 * and FTZ), so the stored floats match the guest bit for bit.
 *
 * Details the port has to keep: the `bt/s` **delay slot** (`float FPUL,FR3`)
 * runs on **both** paths, so `fr3` always holds `float(value)` before the
 * branch is resolved; the add's operand is the **raw bits** of the pool word,
 * reused as a float; the multiplier is loaded and overwrites `fr2` on every
 * path, so the final `fr2` is the multiplier either way; the **T bit** the
 * caller sees is the `cmp/ge #0` at the very start, so it is `(value >= 0)`;
 * and `ftrc` leaves the truncated integer in FPUL and the exit copies it into
 * `r0`, so both carry the answer.
 *
 * See docs/re/native_float_scale.md. */
#include "float_scale.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero FPU wrappers (as byte_color.c) ---- */
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
        case '*': z = x * y; break;
        default:  z = x + y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

#define POOL_PLUS  0x0c039d50u   /* 4294967296.0f, the sign-bit fold */
#define POOL_SCALE 0x0c039d54u   /* 1.28f, the multiplier */

void vf3_native_float_scale(vf3_native_aim *a, uint32_t pool_p1)
{
    /* The value: read through the pool's pointer, as a signed 32-bit word. */
    uint32_t p1 = vf3_aim_u32(a, pool_p1);
    int32_t v = (int32_t)vf3_aim_u32(a, p1);
    R(3) = (uint32_t)v;
    R(2) = p1;                    /* overwritten by P2 on the v < 0 path */

    /* The delay slot: fr3 = float(value) on both paths.  The guest's
     * `float FPUL,FRn` rounds the signed integer toward zero (FPSCR bit 0,
     * RM=truncate), so `0x80000001` becomes -2147483520, not the
     * round-to-nearest -2147483648. */
    {
        const int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float conv = (float)v;
        fesetround(saved);
        F(3) = conv;
    }
    set_t(a, v >= 0);

    if (v < 0) {
        /* The sign bit is set: fold it back in by adding the pool's 2^32,
         * whose raw bits were loaded straight into FPUL. */
        uint32_t plus_bits = vf3_aim_u32(a, POOL_PLUS);
        R(2) = plus_bits;
        F(3) = fadd(a, F(3), bits2f(plus_bits));
    }

    /* The multiplier, loaded with fmov.s @r0,FR2 on every path. */
    uint32_t scale_bits = vf3_aim_u32(a, POOL_SCALE);
    float mul = bits2f(scale_bits);
    F(3) = fmul(a, F(3), mul);

    /* ftrc FR3,FPUL: the truncated integer, in both FPUL and r0.  The SH-4's
     * FTRC saturates at the int32 bounds: a value below -2^31 gives 0x80000000,
     * one at or above 2^31 gives 0x7fffffff, else the truncated value. */
    float ftv = F(3);
    uint32_t res;
    {
        double d = (double)ftv;
        if (isnan(d) || d < -2147483648.0) res = 0x80000000u;
        else if (d >= 2147483648.0) res = 0x7fffffffu;
        else res = (uint32_t)(int32_t)d;
    }
    a->fpul = res;
    R(0) = res;
    F(2) = mul;
}
