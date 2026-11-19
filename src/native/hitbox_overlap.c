/* hitbox_overlap.c - SH-4 0x8C073AAC: fighter-vs-fighter capsule overlap
 * scan, natively.
 *
 * A plain-C transcription of the readable port src/fight/hitbox_overlap.c
 * (`vf3_hitbox_overlap_entry`).  It operates on `vf3_native_aim`: the flat
 * RAM (every guest address resolves through `ram_base`), the FR bank and the
 * register file.
 *
 * The function decides hit / no-hit for each of the 28*28 capsule pairs and
 * folds those decisions into integer hit words and a pair count, so the float
 * arithmetic must agree with the guest (round-toward-zero) bit for bit; the
 * native port therefore runs the same vf3_fpu_* helpers the readable uses,
 * fed with `a->fpscr`.  (The neighbouring capsule_chain family uses plain-C
 * sqrtf/fmaf and tolerated a float residual because its outputs are all
 * floats; hitbox_overlap's integer outputs are not tolerant.)
 *
 *   r4 = out (a result block: +48 min distance float, +52 pair count byte),
 *   r5 = A, r6 = B (the two fighter objects).  Each holds 28 capsules: a
 *   12-byte segment at the pointer in +0x138C (second end at +0x1390), a
 *   radius in the float array at +0x12AC, and a per-capsule hit word at
 *   +0x131C this routine fills in.  On exit the hit words, the radius
 *   array(s), the min distance and the pair count are written and the saved
 *   registers (r8..r14, fr12..fr15, pr, sp) restored.
 *
 * The function keeps a 196-byte frame under the entry sp (44 saved bytes +
 * a 152-byte working area).  The transient working area (sp0-196..sp0-44) is
 * not compared in the family tests, so the port keeps it as a local buffer;
 * the saved block (sp0-44..sp0) and the caller frame (sp0..sp0+32) are
 * written to the flat RAM exactly as the guest writes them.  See
 * docs/re/native_hitbox_overlap.md. */
#include "hitbox_overlap.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])
/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

/* the readable's frame-slot offsets (bytes) */
enum {
    SAVED_BYTES = 44, FRAME_BYTES = 152,
    S_BIT = 0, S_P = 4, S_Q = 8, S_MASK = 12, S_ACC = 16, S_HITP = 20,
    S_AZ = 24, S_BZ = 28, S_PZ = 32, S_DZ = 36, S_END_B = 40, S_SQ = 44,
    S_MIN = 48, S_COUNT = 56, S_END_A = 60,
    S_NUM_A = 52,
    COUNT_CAPS = 28, RADIUS_OFF = 0x12AC, HITWORD_OFF = 0x131C,
    SEG_A_OFF = 0x138C, SEG_B_OFF = 0x1390
};

#define LIT_GROW      0x3F999999u    /* 1.2f */
#define LIT_TWO       0x40000000u    /* 2.0f */
#define LIT_EPSILON   0x33D6BF94u    /* 1e-7f */
#define FLAG_OFF      0x1A04u
#define TOP           0x80000000u
#define SIGN          0x80000000u

/* ---- round-toward-zero FPU wrappers ----
 * The readable authority (vf3_hitbox_overlap_entry) routes every FP op through
 * vf3_f_* / vf3_fpu_* with the capture FPSCR 0x00040001, whose RM bit 0 selects
 * FE_TOWARDZERO.  hitbox_overlap's outputs are integer (the hit words, the pair
 * count) decided by float comparisons, so the float arithmetic has to be
 * bit-exact: plain C round-to-nearest would flip a near-boundary decision.
 * These reproduce sh4_fpu's begin/op/end (toward-zero + flush) locally, with
 * no dependency on vf3core. */
/* flush a subnormal result to zero when FTZ (the capture FPSCR DN bit) is on,
 * exactly as sh4_fpu's flush() does.  The guest FPSCR here is always 0x00040001
 * (DN bit 0x40000 set), so subnormal results become signed zero. */
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
/* acc + x*y with a single (fused) rounding, as fmac does */
static inline float fma0(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flz(a, z);
}
static inline float sqrt0(vf3_native_aim *a, float x)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = sqrtf(x);
    fesetround(saved);
    return flz(a, z);
}
static inline float fadd(vf3_native_aim *a, float x, float y)
{ return ft0(a, x, y, '+'); }
static inline float fsub(vf3_native_aim *a, float x, float y)
{ return ft0(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y)
{ return ft0(a, x, y, '*'); }
static inline float fdivv(vf3_native_aim *a, float x, float y)
{ return ft0(a, x, y, '/'); }
static inline float fmacv(vf3_native_aim *a, float x, float y, float acc)
{ return fma0(a, x, y, acc); }
static inline float fsqrt(vf3_native_aim *a, float x)
{ return sqrt0(a, x); }

void vf3_native_hitbox_overlap(vf3_native_aim *a, uint32_t sp0, uint32_t out,
                               uint32_t A, uint32_t B)
{
    /* the working frame lives in a local buffer (not compared) */
    uint8_t nf[FRAME_BYTES];
#define LD(o)   ((uint32_t)nf[o] | ((uint32_t)nf[(o) + 1] << 8) | \
                 ((uint32_t)nf[(o) + 2] << 16) | ((uint32_t)nf[(o) + 3] << 24))
#define ST(o, v) do { uint32_t _v = (v); \
                     nf[(o)] = (uint8_t)_v; nf[(o) + 1] = (uint8_t)(_v >> 8); \
                     nf[(o) + 2] = (uint8_t)(_v >> 16); nf[(o) + 3] = (uint8_t)(_v >> 24); } while (0)
#define STF(o, f) ST((o), vf3_aim_ubits(f))

    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const float saved_fr[4] = { F(15), F(14), F(13), F(12) };
    const uint32_t pr0 = a->pr;
    uint32_t r5 = A, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0;

    for (int i = 0; i < 7; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i)
        vf3_aim_set_u32(a, sp0 - 28u - 4u * (uint32_t)(i + 1), vf3_aim_ubits(saved_fr[i]));
    a->r[15] = sp0 - SAVED_BYTES - FRAME_BYTES;

    if (vf3_aim_u32(a, 0x0C29BCC0u) & 0x00080001u) {   /* pause / demo: out untouched */
        a->sr &= ~1u;
        goto leave;
    }

    w8(a, a->r[15] + S_COUNT, 0);
    F(3) = 0;
    STF(S_MIN, F(3));
    vf3_aim_set_u32(a, out + 48, vf3_aim_ubits(F(3)));
    ST(S_BIT, vf3_aim_u32(a, A + FLAG_OFF));
    ST(S_Q, vf3_aim_u32(a, B + FLAG_OFF));
    r8 = r9 = r10 = r11 = 0;

    /* per-fighter capsule participation */
    {
        uint32_t t = LD(S_BIT) & 0x00800000u;
        ST(S_BIT, t);
        if (t) {
            r8 = vf3_aim_u32(a, 0x0C110994u + 4u * vf3_aim_u8(a, A + 0x1A20));
            r11 = 0xFEF7E7CFu;
            uint32_t b5 = vf3_aim_u32(a, A + 76) & 32u;
            ST(S_P, b5);
            ST(S_BIT, b5 << 26);
            r11 &= r8;
            if (b5 == 0) r8 |= LD(S_BIT); else r8 = 0;
        }
        t = LD(S_Q) & 0x00800000u;
        ST(S_BIT, t);
        if (t) {
            r9 = vf3_aim_u32(a, 0x0C110994u + 4u * vf3_aim_u8(a, B + 0x1A20));
            r10 = 0xFEF7E7CFu;
            uint32_t b5 = vf3_aim_u32(a, B + 76) & 32u;
            ST(S_BIT, b5);
            ST(S_P, b5 << 26);
            r10 &= r9;
            if (LD(S_BIT) == 0) r9 |= LD(S_P); else r9 = 0;
        }
    }

    /* the radius arrays, unless the fighter's +0x1560 says no */
    if (!(vf3_aim_u8(a, A + 0x1560) & 2)) {
        ST(S_Q, B + RADIUS_OFF);
        r13 = A + RADIUS_OFF;
        ST(S_ACC, r13 + 4 * COUNT_CAPS);
        ST(S_END_B, r13 + 8);
        ST(S_P, 0x0C10D390u);
        ST(S_BIT, vf3_aim_u32(a, 0x0C10D390u + 4u * vf3_aim_u8(a, A + 97)));
        ST(S_P, vf3_aim_u32(a, 0x0C10D390u + 4u * vf3_aim_u8(a, B + 97)));
        ST(S_MASK, r11);
        r11 = r10;
        ST(S_HITP, vf3_aim_u32(a, A));
        F(4) = vf3_aim_fbits(LIT_GROW);
        r10 = vf3_aim_u32(a, B);
        do {
            F(5) = vf3_aim_fbits(vf3_aim_u32(a, LD(S_P)));
            F(6) = vf3_aim_fbits(vf3_aim_u32(a, LD(S_BIT)));
            if (LD(S_MASK) & TOP) F(6) = fmul(a, F(6), F(4));
            const uint32_t shifted = LD(S_MASK) << 1;
            if (r11 & TOP) F(5) = fmul(a, F(5), F(4));
            ST(S_MASK, shifted);
            r11 <<= 1;
            if (r13 == LD(S_END_B)) {                       /* capsule 2 also honours the 0x00800000 flag */
                if (LD(S_HITP) & 0x00800000u) F(6) = fmul(a, F(6), F(4));
                if (r10 & 0x00800000u) F(5) = fmul(a, F(5), F(4));
            }
            vf3_aim_set_u32(a, r13, vf3_aim_ubits(F(6)));
            vf3_aim_set_u32(a, LD(S_Q), vf3_aim_ubits(F(5)));
            r13 += 4;
            ST(S_BIT, LD(S_BIT) + 4);
            ST(S_P, LD(S_P) + 4);
            ST(S_Q, LD(S_Q) + 4);
        } while (r13 != LD(S_ACC));
    }

    for (r13 = B + HITWORD_OFF; r13 != B + HITWORD_OFF + 4 * COUNT_CAPS; r13 += 4)
        vf3_aim_set_u32(a, r13, 0);

    r11 = vf3_aim_u32(a, A + SEG_A_OFF);
    ST(S_END_A, r11 + 12 * COUNT_CAPS);
    ST(S_P, vf3_aim_u32(a, A + SEG_B_OFF));
    ST(S_NUM_A, A + RADIUS_OFF);
    ST(S_HITP, A + HITWORD_OFF);
    ST(S_BIT, TOP);

    while (r11 != LD(S_END_A)) {                            /* one capsule of A per pass */
        F(9) = vf3_aim_fbits(vf3_aim_u32(a, r11));
        F(11) = vf3_aim_fbits(vf3_aim_u32(a, r11 + 4));
        F(3) = vf3_aim_fbits(vf3_aim_u32(a, r11 + 8));
        STF(S_AZ, F(3));
        r10 = LD(S_P);
        F(15) = vf3_aim_fbits(vf3_aim_u32(a, r10 + 4));
        F(3) = vf3_aim_fbits(vf3_aim_u32(a, r10 + 8));
        F(12) = vf3_aim_fbits(vf3_aim_u32(a, r10));
        STF(S_PZ, F(3));
        ST(S_Q, B + HITWORD_OFF);
        r12 = B + RADIUS_OFF;
        ST(S_END_B, r12 + 4 * COUNT_CAPS);
        r13 = vf3_aim_u32(a, B + SEG_A_OFF);
        r5 = vf3_aim_u32(a, B + SEG_B_OFF);
        F(5) = vf3_aim_fbits(vf3_aim_u32(a, LD(S_NUM_A)));
        ST(S_ACC, 0);
        r10 = 0;

        do {                                                /* one capsule of B */
            int T = (F(11) > F(15));                        /* GT(15,11) = fl(11)>fl(15) */
            F(14) = vf3_aim_fbits(vf3_aim_u32(a, r13 + 4));
            F(7) = vf3_aim_fbits(vf3_aim_u32(a, r13 + 8));
            F(8) = vf3_aim_fbits(vf3_aim_u32(a, r5 + 4));
            F(3) = vf3_aim_fbits(vf3_aim_u32(a, r5 + 8));
            F(6) = vf3_aim_fbits(vf3_aim_u32(a, r5));
            F(10) = vf3_aim_fbits(vf3_aim_u32(a, r13));
            STF(S_BZ, F(3));
            F(4) = vf3_aim_fbits(vf3_aim_u32(a, r12));

            /* y interval of A's segment inflated by A's radius (fr13 low, fr3 high) */
            if (T) { F(13) = F(15); F(13) = fsub(a, F(13), F(5)); F(3) = F(11); }
            else   { F(13) = F(11); F(13) = fsub(a, F(13), F(5)); F(3) = F(15); }
            T = (F(14) > F(8));                             /* GT(8,14) */
            F(3) = fadd(a, F(3), F(5));
            STF(88, F(3));
            if (T) { F(3) = F(8); F(3) = fsub(a, F(3), F(4)); STF(72, F(3)); F(2) = F(14); }
            else   { F(3) = F(14); F(3) = fsub(a, F(3), F(4)); STF(72, F(3)); F(2) = F(8); }
            F(2) = fadd(a, F(2), F(4));
            STF(68, F(2));
            F(2) = vf3_aim_fbits(LD(88)); F(3) = vf3_aim_fbits(LD(72));
            if (F(3) > F(2)) goto next;                     /* GT(2,3) = fl(3)>fl(2) */
            F(3) = vf3_aim_fbits(LD(68));
            if (F(13) > F(3)) goto next;                    /* GT(3,13) = fl(13)>fl(3) */

            /* x interval */
            T = (F(9) > F(12));                             /* GT(12,9) */
            if (T) { F(3) = F(12); F(3) = fsub(a, F(3), F(5)); STF(92, F(3)); F(13) = F(9); }
            else   { F(3) = F(9); F(3) = fsub(a, F(3), F(5)); STF(92, F(3)); F(13) = F(12); }
            T = (F(10) > F(6));                             /* GT(6,10) */
            F(13) = fadd(a, F(13), F(5));
            if (T) { F(3) = F(6); F(3) = fsub(a, F(3), F(4)); STF(100, F(3)); F(2) = F(10); }
            else   { F(3) = F(10); F(3) = fsub(a, F(3), F(4)); STF(100, F(3)); F(2) = F(6); }
            F(2) = fadd(a, F(2), F(4));
            STF(96, F(2));
            F(3) = vf3_aim_fbits(LD(100));
            if (F(3) > F(13)) goto next;                    /* GT(13,3) */
            F(3) = vf3_aim_fbits(LD(92)); F(2) = vf3_aim_fbits(LD(96));
            if (F(3) > F(2)) goto next;                     /* GT(2,3) */

            /* z interval */
            F(3) = vf3_aim_fbits(LD(S_AZ)); F(2) = vf3_aim_fbits(LD(S_PZ));
            T = (F(3) > F(2));                              /* GT(2,3) */
            F(2) = fsub(a, F(2), F(5));
            if (T) { STF(76, F(2)); F(13) = vf3_aim_fbits(LD(S_AZ)); }
            else   { F(3) = vf3_aim_fbits(LD(S_AZ)); F(3) = fsub(a, F(3), F(5)); STF(76, F(3)); F(13) = F(2); }
            F(3) = vf3_aim_fbits(LD(S_BZ));
            T = (F(7) > F(3));                              /* GT(3,7) */
            F(13) = fadd(a, F(13), F(5));
            if (T) { F(3) = fsub(a, F(3), F(4)); STF(84, F(3)); F(3) = F(7); }
            else   { F(2) = F(7); F(2) = fsub(a, F(2), F(4)); STF(84, F(2)); }
            F(3) = fadd(a, F(3), F(4));
            STF(80, F(3));
            F(3) = vf3_aim_fbits(LD(84));
            if (F(3) > F(13)) goto next;                    /* GT(13,3) */
            F(3) = vf3_aim_fbits(LD(76)); F(2) = vf3_aim_fbits(LD(80));
            if (F(3) > F(2)) goto next;                     /* GT(2,3) */

            /* closest approach of the two segments */
            F(3) = F(12); F(3) = fsub(a, F(3), F(6));
            STF(S_DZ, F(3));
            F(1) = F(9); F(1) = fsub(a, F(1), F(10));
            F(2) = vf3_aim_fbits(LD(S_BZ));
            F(13) = F(15); F(13) = fsub(a, F(13), F(8));
            F(8) = vf3_aim_fbits(LD(S_PZ));
            STF(64, F(1));
            F(10) = F(11); F(10) = fsub(a, F(10), F(14));
            F(6) = vf3_aim_fbits(LD(S_AZ));
            F(3) = vf3_aim_fbits(LD(S_DZ));
            F(8) = fsub(a, F(8), F(2)); F(6) = fsub(a, F(6), F(7));
            F(7) = F(1); F(10) = fsub(a, F(10), F(13)); F(7) = fsub(a, F(7), F(3));
            F(14) = F(6); F(14) = fsub(a, F(14), F(8));
            F(3) = F(10); F(3) = fmul(a, F(3), F(10));
            F(0) = F(7); F(3) = fmacv(a, F(0), F(7), F(3)); /* FMAC(3,7): fr3 += fr0*fr7 */
            F(0) = F(14); F(3) = fmacv(a, F(0), F(14), F(3));/* FMAC(3,14) */
            F(0) = 0; F(6) = F(3);                          /* fr6 = |u|^2 */
            if (F(6) == F(0)) goto next;                    /* degenerate */
            F(3) = F(5); F(3) = fadd(a, F(3), F(4)); F(2) = F(3); F(2) = fmul(a, F(2), F(3));
            STF(S_SQ, F(2));                                /* (ra + rb)^2 */
            F(3) = F(13); F(3) = fmul(a, F(3), F(10));
            F(0) = vf3_aim_fbits(LD(S_DZ));
            F(1) = F(6);
            F(3) = fmacv(a, F(0), F(7), F(3));              /* FMAC(3,7) */
            F(0) = F(8); F(3) = fmacv(a, F(0), F(14), F(3));/* FMAC(3,14) */
            F(0) = vf3_aim_fbits(LD(S_DZ));
            F(2) = F(0); F(4) = F(3);                       /* fr4 = u . v */
            F(3) = F(13); F(3) = fmul(a, F(3), F(13)); F(3) = fmacv(a, F(0), F(2), F(3));
            F(0) = F(8); F(2) = F(4); F(2) = fmul(a, F(2), F(4)); F(3) = fmacv(a, F(0), F(8), F(3));
            F(10) = F(2); F(7) = F(3);
            F(3) = vf3_aim_fbits(LD(S_SQ));
            F(8) = F(7); F(8) = fsub(a, F(8), F(3));
            F(1) = fmul(a, F(1), F(8)); F(10) = fsub(a, F(10), F(1));
            F(2) = 0;
            if (F(2) > F(10)) goto next;                    /* GT(10,2): discriminant < 0 */

            F(3) = 0;
            T = (F(8) > F(3));                              /* GT(3,8) */
            F(10) = F(4); F(10) = vf3_aim_fbits(vf3_aim_ubits(F(10)) ^ 0x80000000u); /* F(10) ^= SIGN */
            if (T) {
                F(3) = F(6); F(14) = vf3_aim_fbits(LIT_TWO); F(2) = 0;
                F(0) = F(14); F(3) = fmacv(a, F(0), F(4), F(3)); F(3) = fadd(a, F(3), F(8));
                if (F(3) > F(2)) {                           /* GT(2,3) */
                    F(3) = 0;
                    if (!(F(3) > F(4))) goto next;           /* !GT(4,3) */
                    if (!(F(6) > F(10))) goto next;          /* !GT(10,6): fl(6)>fl(10) */
                }
            }

            {
                const uint32_t bit = LD(S_BIT);
                F(8) = F(10); F(8) = fdivv(a, F(8), F(6));
                if ((bit & r8) == 0 && ((r9 << r10) & TOP) == 0) {
                    F(3) = 0;
                    if (F(8) > F(3)) {                       /* GT(3,8) */
                        F(6) = vf3_aim_fbits(0x3F800000u);
                        if (F(6) > F(8)) {                   /* GT(8,6) */
                            F(0) = F(4); F(7) = fmacv(a, F(0), F(8), F(7)); F(6) = F(7);
                        } else {
                            F(6) = F(4); F(6) = fadd(a, F(6), F(7));
                        }
                    } else {
                        F(6) = F(7);
                    }
                    F(4) = vf3_aim_fbits(LIT_EPSILON);
                    if (F(4) > F(6)) F(4) = 0;               /* GT(6,4) = fl(4)>fl(6) */
                    else { F(4) = F(6); F(4) = fsqrt(a, F(4)); }
                    F(3) = vf3_aim_fbits(LD(S_MIN));
                    if (!(F(3) > F(4))) STF(S_MIN, F(4));    /* !GT(4,3): store when fl(3)<=fl(4) */
                }
            }
            ST(S_MASK, TOP >> (r10 & 31u));
            {
                const uint32_t hp = LD(S_Q);
                vf3_aim_set_u32(a, hp, vf3_aim_u32(a, hp) | LD(S_BIT));
            }
            ST(S_ACC, LD(S_ACC) | LD(S_MASK));
            w8(a, a->r[15] + S_COUNT,
               (uint8_t)(vf3_aim_u8(a, a->r[15] + S_COUNT) + 1));

        next:
            ST(S_Q, LD(S_Q) + 4);
            r12 += 4; r10 += 1; r13 += 12; r5 += 12;
        } while (r12 != LD(S_END_B));

        r11 += 12;
        ST(S_BIT, LD(S_BIT) >> 1);
        vf3_aim_set_u32(a, LD(S_HITP), LD(S_ACC));
        ST(S_P, LD(S_P) + 12);
        ST(S_NUM_A, LD(S_NUM_A) + 4);
        ST(S_HITP, LD(S_HITP) + 4);
    }

    F(3) = vf3_aim_fbits(LD(S_MIN));
    vf3_aim_set_u32(a, out + 48, vf3_aim_ubits(F(3)));
    w8(a, out + 52, vf3_aim_u8(a, a->r[15] + S_COUNT));
    a->sr |= 1u;                                            /* the closing cmp/eq was true */

leave:
    a->r[15] = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = saved_fr[0]; F(14) = saved_fr[1]; F(13) = saved_fr[2]; F(12) = saved_fr[3];
    a->pr = pr0;
}
