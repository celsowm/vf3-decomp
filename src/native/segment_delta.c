/* segment_delta.c - SH-4 0x8C092B4A (segment_delta), natively.
 *
 * A plain-C transcription of the readable port src/fight/segment_delta.c
 * (`vf3_segment_delta_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.  A self-contained FP leaf:
 *
 *   r4 = destination record, r5 = second record, r6 = scale float pointer,
 *   r7 = pointer to a record whose float at +0x14 gates the push.
 *   The caller's stack holds, from sp+0: two source vectors A / B (words 0 and
 *   1), a third vector (+8) and a flag word (+C).
 *
 *   rec[+0x18 .. +0x20] = A - B                    (frame f = sp - 28)
 *   scale = *r6, times 0.65 when flag 0x100 is set
 *   rec[+0x18 .. +0x20] *= scale
 *   unless flag 0x2, or gating[+0x14] is zero (2*float), or r5 is null:
 *       f[0xC .. 0x14] = third * (2 * gating[+0x14])
 *       r5.rec[+0x18 .. +0x20] += f[0xC .. 0x14]
 *
 * The float ops go through the round-toward-zero + FTZ wrapper (the corpus
 * FPSCR 0x00024001 is in force).  r14 is callee-saved (spilled to [sp0-4]).
 * See docs/re/native_segment_delta.md. */
#include "segment_delta.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as scaled_vec_add.c) ---- */
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
    volatile float z = (op == '*') ? x * y : (op == '-') ? x - y : x + y;
    fesetround(saved);
    return flz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

void vf3_native_segment_delta(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15);
    const uint32_t f = sp0 - 28;
    const uint32_t saved14 = R(14);
    vf3_aim_set_u32(a, sp0 - 4, saved14);
    R(14) = R(4);
    R(15) = f;
    R(4) = R(14);
    vf3_aim_set_u32(a, f, R(5));          /* f+0 = second record */
    R(4) += 24;
    vf3_aim_set_u32(a, f + 8, R(6));      /* f+8 = scale ptr */
    vf3_aim_set_u32(a, f + 4, R(7));      /* f+4 = gating ptr */
    R(5) = vf3_aim_u32(a, f + 28);        /* sp+0 -> A */
    R(6) = vf3_aim_u32(a, f + 32);        /* sp+4 -> B */

    /* rec[+0x18..+0x20] = A - B */
    F(0) = load_f(a, R(5)); R(5) += 4;
    F(3) = load_f(a, R(6)); R(6) += 4;
    F(1) = load_f(a, R(5)); R(5) += 4;
    F(4) = load_f(a, R(6)); R(6) += 4;
    F(0) = fsub(a, F(0), F(3));
    F(2) = load_f(a, R(5));
    F(5) = load_f(a, R(6));
    F(1) = fsub(a, F(1), F(4));
    F(2) = fsub(a, F(2), F(5));
    R(4) += 8;                            /* dest+32 */
    store_f(a, R(4), F(2));
    R(4) -= 4; store_f(a, R(4), F(1));    /* dest+28 */
    R(4) -= 4; store_f(a, R(4), F(0));    /* dest+24 */

    /* scale = *r6, times 0.65 when flag 0x100 */
    R(2) = vf3_aim_u32(a, f + 8);
    R(1) = vf3_aim_u32(a, f + 40);        /* sp+0xC flag word */
    R(3) = 0x100;
    F(4) = load_f(a, R(2));               /* *scale */
    set_t(a, (R(3) & R(1)) == 0);
    R(5) = R(14);                         /* delay slot of the bt/s */
    if (!(a->sr & 1u)) {                  /* flag 0x100 set */
        R(0) = 0x8C092BB0u;
        F(3) = vf3_aim_fbits(0x3F266666u);   /* 0.65f */
        F(4) = fmul(a, F(4), F(3));
    }
    R(4) = R(14) + 24;
    R(5) += 24;

    /* rec[+0x18..+0x20] *= scale */
    F(0) = load_f(a, R(5)); R(5) += 4;
    F(1) = load_f(a, R(5)); R(5) += 4;
    F(2) = load_f(a, R(5)); R(5) += 4;
    R(4) += 12;
    F(2) = fmul(a, F(2), F(4));
    F(1) = fmul(a, F(1), F(4));
    F(0) = fmul(a, F(0), F(4));
    R(4) -= 4; store_f(a, R(4), F(2));
    R(4) -= 4; store_f(a, R(4), F(1));
    R(4) -= 4; store_f(a, R(4), F(0));

    /* the push */
    R(0) = vf3_aim_u32(a, f + 40);
    set_t(a, (R(0) & 2) == 0);
    if (!(a->sr & 1u)) goto done;             /* flag 0x2 set -> skip */
    R(2) = vf3_aim_u32(a, f + 4);
    R(0) = 20;
    F(2) = 0.0f;
    F(4) = load_f(a, R(2) + R(0));            /* gating[+0x14] */
    F(3) = F(4);
    F(4) = fadd(a, F(4), F(3));               /* 2 * that */
    set_t(a, F(4) == F(2));                   /* T = (2*float == 0) */
    if (a->sr & 1u) goto done;
    R(1) = vf3_aim_u32(a, f);
    set_t(a, R(1) == 0);                      /* tst r1,r1 */
    if (a->sr & 1u) goto done;                /* r5 null -> skip */
    R(4) = f;
    R(5) = vf3_aim_u32(a, f + 36);            /* sp+8 -> third vector */
    R(4) += 12;

    /* f[0xC..0x14] = third * (2 * gating[+0x14]) */
    F(0) = load_f(a, R(5)); R(5) += 4;
    F(1) = load_f(a, R(5)); R(5) += 4;
    F(2) = load_f(a, R(5)); R(5) += 4;
    R(4) += 12;
    F(2) = fmul(a, F(2), F(4));
    F(1) = fmul(a, F(1), F(4));
    F(0) = fmul(a, F(0), F(4));
    R(4) -= 4; store_f(a, R(4), F(2));        /* f+20 */
    R(4) -= 4; store_f(a, R(4), F(1));        /* f+16 */
    R(4) -= 4; store_f(a, R(4), F(0));        /* f+12 */

    /* r5.rec[+0x18..+0x20] += f[0xC..0x14] */
    R(4) = vf3_aim_u32(a, f);
    R(5) = f;
    R(5) += 12;
    R(4) += 24;
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

done:
    R(15) = sp0;
    R(14) = saved14;
}
