/* vec3_sub.c - SH-4 0x8C03CEE0 (vec3_sub), natively.
 *
 * A plain-C transcription of the readable port src/fight/small_leaves.c
 * (`vf3_vec3_sub_entry`) onto `vf3_native_aim`: the flat RAM and the FR bank.
 * A self-contained FP leaf (call-free, no stack frame): r4[0..2] =
 * r5[0..2] - r6[0..2] component-wise; r4, r5, r6 each advance 8 bytes.
 *
 * The float subtractions go through the round-toward-zero + FTZ wrapper (the
 * corpus FPSCR 0x00024001 - RM=truncate and FTZ - is in force), so the stored
 * floats match the guest bit for bit.
 *
 * The FR bank sequence: it loads the three components of r5 into fr0/fr1/fr2
 * (and the three of r6 into fr4/fr5/fr6) as it advances the pointers, so the
 * differences land back in fr0/fr1/fr2 while fr4/fr5/fr6 hold the subtracted
 * vector's components.
 *
 * See docs/re/native_vec3_sub.md. */
#include "vec3_sub.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

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
static inline float fsub(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x - y;
    fesetround(saved);
    return flz(a, z);
}

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

void vf3_native_vec3_sub(vf3_native_aim *a)
{
    F(0) = load_f(a, R(5)); R(5) += 4;
    F(4) = load_f(a, R(6)); R(6) += 4;
    F(1) = load_f(a, R(5)); R(5) += 4;
    F(5) = load_f(a, R(6)); R(6) += 4;
    F(0) = fsub(a, F(0), F(4));
    F(2) = load_f(a, R(5));
    F(6) = load_f(a, R(6));
    F(1) = fsub(a, F(1), F(5));
    store_f(a, R(4), F(0)); R(4) += 4;
    F(2) = fsub(a, F(2), F(6));
    store_f(a, R(4), F(1)); R(4) += 4;
    store_f(a, R(4), F(2));
}
