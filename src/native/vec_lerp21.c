/* vec_lerp21.c - SH-4 0x8C09F354 (vec_lerp21), natively.
 *
 * A plain-C transcription of the readable port src/fight/vec_lerp21.c
 * (`vf3_vec_lerp21_entry`) onto `vf3_native_aim`: the flat RAM and the FR bank.
 * A self-contained FP leaf (call-free, no stack frame): for each of 21
 * consecutive 3-float vectors, component-wise
 *     dst = src + t * (dst - src)          (fused mac, one rounding)
 * r4 = destination array (updated in place), r5 = source array, fr4 = t.
 *
 * The float subtracts/macs go through the round-toward-zero + FTZ wrapper (the
 * corpus FPSCR 0x00024001 - RM=truncate and FTZ - is in force).  The subtract
 * is one rounding and the `fmac` (fmaf) rounds once, so the stored floats match
 * the guest bit for bit.
 *
 * The body leaves the same register/FR signature as the guest's final vector:
 * r4 = dst + 240, r5 = src + 240 (the last vector does not advance them),
 * r0 = 8, r3 = the last loop vector's z address, r6/r7 = the last tail
 * vector's z/y addresses, T = 1, fr0 = t, fr5 = the z difference, fr4/fr6 =
 * new z, fr7/fr9 = new y, fr8/fr10 = new x.  The loop parks its z pointer at
 * sp-4 on every iteration, so that slot holds the last loop vector's z address.
 *
 * See docs/re/native_vec_lerp21.md. */
#include "vec_lerp21.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define VECTORS      21u
#define LOOP_VECTORS 18u

/* ---- round-toward-zero + FTZ wrapper (as corner_fan.c / float_scale.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fsub(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x - y;
    fesetround(saved);
    return flz(a, z);
}
static inline float fmac(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flz(a, z);
}

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

void vf3_native_vec_lerp21(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), f = sp0 - 4u;
    const uint32_t dst = R(4), src = R(5);
    const float t = F(4);

    float diff_z = 0, new_x = 0, new_y = 0, new_z = 0;
    for (uint32_t i = 0; i < VECTORS; ++i) {
        const uint32_t d = dst + 12u * i, o = src + 12u * i;
        const float dx = fsub(a, load_f(a, d), load_f(a, o));
        const float dy = fsub(a, load_f(a, d + 4u), load_f(a, o + 4u));
        diff_z = fsub(a, load_f(a, d + 8u), load_f(a, o + 8u));
        new_x = fmac(a, t, dx, load_f(a, o));
        new_y = fmac(a, t, dy, load_f(a, o + 4u));
        new_z = fmac(a, t, diff_z, load_f(a, o + 8u));
        store_f(a, d, new_x);
        store_f(a, d + 4u, new_y);
        if (i < LOOP_VECTORS) vf3_aim_set_u32(a, f, d + 8u); /* the loop keps its z pointer on the stack */
        store_f(a, d + 8u, new_z);
    }

    R(0) = 8;
    R(3) = dst + 12u * (LOOP_VECTORS - 1u) + 8u;
    R(6) = dst + 12u * (VECTORS - 1u) + 8u;
    R(7) = dst + 12u * (VECTORS - 1u) + 4u;
    R(4) = dst + 12u * (VECTORS - 1u);
    R(5) = src + 12u * (VECTORS - 1u);
    a->sr |= 1u;                    /* SR.T = 1 */
    F(0) = t;
    F(4) = new_z;
    F(5) = diff_z;
    F(6) = new_z;
    F(7) = new_y;
    F(8) = new_x;
    F(9) = new_y;
    F(10) = new_x;
    R(15) = sp0;
}
