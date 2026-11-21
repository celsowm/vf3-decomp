/* extent_flip.c - SH-4 0x8C0CC3F0 (extent_flip), natively.
 *
 * A plain-C transcription of the readable port src/fight/extent_flip.c
 * (`vf3_extent_flip_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank
 * and the register file.
 *
 * A self-contained FP leaf (call-free, no stack frame): r4 -> six floats
 * a0 a1 a2 b0 b1 b2, r5 -> a flag word, fr4 = a limit.  It rewrites the
 * record, mirroring its y/z pair:
 *
 *     a0 = a0 + b0
 *     a1 = a1 + b1   (unless flag bit 1 is set, then floored at fr4)
 *     a2 = -(-b2 - a2) = a2 + b2   (the sign flipped twice)
 *
 * Unless the flag word's bit 1 (bit 0x2) is set, a1+b1 is floored at fr4:
 * when it is not above fr4 it is replaced by fr4 and the flag word's bit 0
 * is cleared.
 *
 * The float additions/subtraction go through the round-toward-zero + FTZ
 * wrapper (the corpus FPSCR 0x00024001 - RM=truncate and FTZ - is in
 * force), so the stored floats match the guest bit for bit.
 *
 * The FR bank sequence: fr6 = a0+b0, fr5 = a1+b1 (or fr4 when floored),
 * fr2 = a2 (entry), fr3 = -b2, fr7 = a2+b2.  See
 * docs/re/native_extent_flip.md. */
#include "extent_flip.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* ---- round-toward-zero + FTZ wrapper (as vec3_sub.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fadd(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x + y;
    fesetround(saved);
    return flz(a, z);
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
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

void vf3_native_extent_flip(vf3_native_aim *a)
{
    const uint32_t rec = R(4), flags_at = R(5);
    const uint32_t flags = vf3_aim_u32(a, flags_at);

    float fr3 = load_f(a, rec);             /* a0 */
    float fr6 = load_f(a, rec + 12);        /* b0 */
    fr6 = fadd(a, fr6, fr3);                /* x = a0 + b0 */
    fr3 = load_f(a, rec + 4);               /* a1 */
    float fr5 = load_f(a, rec + 16);        /* b1 */
    fr5 = fadd(a, fr5, fr3);                /* y = a1 + b1 */
    fr3 = load_f(a, rec + 20);              /* b2 */
    float fr2 = load_f(a, rec + 8);         /* a2 */
    fr3 = bits2f(fbits(fr3) ^ 0x80000000u); /* -b2 */
    float fr7 = fr3;                        /* fr7 = -b2 */
    fr7 = fsub(a, fr7, fr2);                /* -b2 - a2 */

    R(0) = flags;
    if (!(flags & 2u)) {
        const int over = (fr5 > F(4));      /* fcmp/gt FR4,FR5: fr5 > fr4 */
        a->sr = (a->sr & ~1u) | (over ? 1u : 0u);
        if (!over) {
            R(2) = vf3_aim_u32(a, flags_at) & 0xFFFFFFFEu;
            R(3) = 0xFFFFFFFEu;
            fr5 = F(4);                     /* FMOV(5,4) */
            vf3_aim_set_u32(a, flags_at, R(2));
        }
    } else {
        a->sr &= ~1u;                       /* tst #2 false: T clear */
    }

    R(0) = 8;
    vf3_aim_set_u32(a, rec, vf3_aim_ubits(fr6));
    vf3_aim_set_u32(a, rec + 4, vf3_aim_ubits(fr5));
    fr7 = bits2f(fbits(fr7) ^ 0x80000000u); /* -(-b2-a2) = a2+b2 */
    vf3_aim_set_u32(a, rec + 8, vf3_aim_ubits(fr7));

    F(2) = fr2; F(3) = fr3; F(5) = fr5; F(6) = fr6; F(7) = fr7;
}
