/* scaled_vec_add.c - SH-4 0x8C09302A (scaled_vec_add), natively.
 *
 * A plain-C transcription of the readable port src/fight/scaled_vec_add.c
 * (`vf3_scaled_vec_add_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.  A self-contained FP leaf:
 *
 *   dest += w * owner.vec
 *
 * where the weight w = [r6+16] (nothing happens when it is 0) is scaled by
 * 1.1 when owner.flags & 0x04000000, else by 0.75 and then (unless the actor's
 * halfword at +16 has bit 0) by 0.45 more when r7 & 0x100 is set; the routine
 * is skipped when r7 & 0x1000 is set (with actor bit 0 clear).
 *
 * The float ops go through the round-toward-zero + FTZ wrapper (the corpus
 * FPSCR 0x00024001 is in force).  fr15 is callee-saved: it is spilled to
 * [sp0-4] on entry and restored on every leave, so the FR bank ends with fr15
 * = its entry value.  See docs/re/native_scaled_vec_add.md. */
#include "scaled_vec_add.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as terrain_wrap.c) ---- */
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
    volatile float z = (op == '*') ? x * y : x + y;
    fesetround(saved);
    return flz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

#define LIT_11  0x3F8CCCCCu   /* 1.1   (0x8C093098) */
#define LIT_075 0x3F400000u   /* 0.75  (0x8C09309C) */
#define LIT_045 0x3EE66666u   /* 0.45  (0x8C0930A0) */
#define LEAVE_R2 0x0C0930D8u

void vf3_native_scaled_vec_add(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15);
    const uint32_t f = sp0 - 20;
    const float saved_fr15 = F(15);
    vf3_aim_set_u32(a, sp0 - 4, vf3_aim_ubits(saved_fr15));
    R(15) = f;
    vf3_aim_set_u32(a, f, R(4));          /* actor @ f+0 */

    R(0) = 16;
    F(15) = load_f(a, R(6) + R(0));       /* the weight w */
    F(3) = 0.0f;
    set_t(a, F(15) == F(3));              /* w == 0 -> leave */
    if (a->sr & 1u) {
        R(3) = LEAVE_R2;
        goto leave;
    }

    R(0) = 72;
    R(3) = 0x04000000u;
    R(2) = vf3_aim_u32(a, R(5) + R(0));   /* owner.flags */
    set_t(a, (R(3) & R(2)) == 0);         /* T set when the bit is clear */
    if (!(a->sr & 1u)) {
        R(0) = 0x0C093098u;
        F(3) = vf3_aim_fbits(LIT_11);
        F(15) = fmul(a, F(15), F(3));     /* w *= 1.1 (delay slot) */
        goto apply;
    }

    R(0) = 0x0C09309Cu;
    F(3) = vf3_aim_fbits(LIT_075);
    R(0) = vf3_aim_u32(a, f);             /* actor */
    R(0) = (uint32_t)vf3_aim_u8(a, R(0) + 16) | ((uint32_t)vf3_aim_u8(a, R(0) + 17) << 8);
    set_t(a, (R(0) & 1u) == 0);
    F(15) = fmul(a, F(15), F(3));         /* w *= 0.75 (bf/s delay slot) */
    if (!(a->sr & 1u)) goto apply;        /* actor bit 0 set -> apply */
    R(1) = 0x1000u;
    set_t(a, (R(7) & R(1)) == 0);
    if (!(a->sr & 1u)) { R(2) = LEAVE_R2; goto leave; }   /* r7 & 0x1000 set */
    R(3) = 0x0100u;
    set_t(a, (R(7) & R(3)) == 0);
    if (a->sr & 1u) goto apply;           /* r7 & 0x100 clear -> apply */
    R(0) = 0x0C0930A0u;
    F(3) = vf3_aim_fbits(LIT_045);
    F(15) = fmul(a, F(15), F(3));         /* w *= 0.45 */

apply:
    {
        R(5) = vf3_aim_u32(a, f);         /* actor */
        R(4) = f + 4;
        F(4) = F(15);                     /* w */
        R(5) += 92;                       /* owner.vec */
        F(0) = load_f(a, R(5)); R(5) += 4;
        F(1) = load_f(a, R(5)); R(5) += 4;
        F(2) = load_f(a, R(5)); R(5) += 4;
        R(4) += 12;
        F(2) = fmul(a, F(2), F(4));
        F(1) = fmul(a, F(1), F(4));
        F(0) = fmul(a, F(0), F(4));
        R(4) -= 4; store_f(a, R(4), F(2));   /* f+12 */
        R(4) -= 4; store_f(a, R(4), F(1));   /* f+8  */
        R(4) -= 4; store_f(a, R(4), F(0));   /* f+4  */
        /* dest += owner.vec * w */
        R(4) = vf3_aim_u32(a, f + 20);       /* [sp0+0] the dest pointer */
        R(5) = f + 4;
        F(0) = load_f(a, R(4)); R(4) += 4;
        F(3) = load_f(a, R(5)); R(5) += 4;
        F(1) = load_f(a, R(4)); R(4) += 4;
        F(4) = load_f(a, R(5)); R(5) += 4;
        F(2) = load_f(a, R(4)); R(4) += 4;
        F(5) = load_f(a, R(5)); R(5) += 4;
        F(0) = fadd(a, F(0), F(3));
        F(2) = fadd(a, F(2), F(5));
        F(1) = fadd(a, F(1), F(4));
        R(4) -= 4; store_f(a, R(4), F(2));
        R(4) -= 4; store_f(a, R(4), F(1));
        R(4) -= 4; store_f(a, R(4), F(0));
    }

leave:
    F(15) = saved_fr15;
    R(15) = sp0;
}
