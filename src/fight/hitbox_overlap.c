/* hitbox_overlap.c - 0x8C073AAC  fighter-vs-fighter capsule overlap scan.
 *
 *   r4 = result block: +48 closest distance (float), +52 number of overlapping pairs (byte).
 *   r5 / r6 = the two fighter objects. Each holds 28 capsules: a 12-byte segment at the pointer in +0x138C
 *   (second end at +0x1390, so "own" and "other" lists), a radius in the float array at +0x12AC, and a hit
 *   word per capsule at +0x131C that this routine fills in.
 *
 * Steps:
 *   1. leave at once while [0x0C29BCC0] & 0x00080001 (the pause / demo flags);
 *   2. per fighter, flag bit 23 of +0x1A04 selects a per-character table (0x0C110994) that says which of the 28
 *      capsules take part, and +0x1560 bit 1 switches off step 3;
 *   3. (optional) rebuild both fighters' radius arrays from the shared radius tables at 0x0C10D390 (indexed by
 *      the byte at +97), growing masked entries by 1.2;
 *   4. clear fighter B's hit words;
 *   5. for every capsule i of A and every capsule j of B: reject by interval overlap on the three axes (the
 *      boxes inflated by the two radii), then do the closest-approach test between the two segments; on a hit
 *      the distance is kept as the minimum, B's hit word j gets A's capsule bit, A's collects B's bit j and
 *      the pair counter is bumped.
 *   The routine writes its working values to a 152-byte frame; every slot the original touches is written
 *   here too (the verification compares the stack), so the slot numbers below stay as in the original.
 *
 * Frame: +0 current A-capsule bit (starts 0x80000000, shifts right), +4 / +8 / +12 / +16 / +20 working
 * pointers and masks, +24 / +28 / +32 z of the three segment ends, +36 .. +44 temporaries, +48 minimum
 * distance, +56 pair count (byte), +60 end of A's list, +64 .. +100 interval bounds. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/sh4_fpu.h"
#include "fight/vec3_inline.h"

enum {
    SAVED_BYTES = 44, FRAME_BYTES = 152,
    S_BIT = 0, S_P = 4, S_Q = 8, S_MASK = 12, S_ACC = 16, S_HITP = 20,
    S_AZ = 24, S_BZ = 28, S_PZ = 32, S_DZ = 36, S_END_B = 40, S_SQ = 44,
    S_MIN = 48, S_COUNT = 56, S_END_A = 60,
    S_NUM_A = 52,
    COUNT_CAPS = 28, RADIUS_OFF = 0x12AC, HITWORD_OFF = 0x131C, SEG_A_OFF = 0x138C, SEG_B_OFF = 0x1390
};

#define LIT_GROW      0x3F999999u    /* 1.2f */
#define LIT_TWO       0x40000000u    /* 2.0f */
#define LIT_EPSILON   0x33D6BF94u    /* 1e-7f */
#define FLAG_OFF      0x1A04u
#define TOP           0x80000000u

/* the original's FR sequences, spelled out */
#define LD(o)       m32(ram, f + (o))
#define ST(o, v)    w32(ram, f + (o), (v))
#define FMOV(d, m)  (F(d) = F(m))
#define FADD(d, m)  set_fl(s, (d), vf3_f_add(s, fl(s, (d)), fl(s, (m))))
#define FSUB(d, m)  set_fl(s, (d), vf3_f_sub(s, fl(s, (d)), fl(s, (m))))
#define FMUL(d, m)  set_fl(s, (d), vf3_f_mul(s, fl(s, (d)), fl(s, (m))))
#define FMAC(n, m)  set_fl(s, (n), vf3_f_mac(s, fl(s, 0), fl(s, (m)), fl(s, (n))))   /* FRn += FR0 * FRm */
#define GT(m, n)    (fl(s, (n)) > fl(s, (m)))                                         /* fcmp/gt FRm,FRn */

int vf3_hitbox_overlap_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_fr[4] = { F(15), F(14), F(13), F(12) };
    const uint32_t out = R(4), A = R(5), B = R(6);
    const uint32_t f = sp0 - SAVED_BYTES - FRAME_BYTES;
    uint32_t r5 = A, r8, r9, r10, r11, r12, r13;

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 28u - 4u * (uint32_t)(i + 1), saved_fr[i]);

    if (m32(ram, 0x0C29BCC0u) & 0x00080001u) {              /* pause / demo: out untouched */
        R(VF3_REG_SR) &= ~1u;
        goto leave;
    }

    vf3_mem_set_u8(ram, f + S_COUNT, 0);
    F(3) = 0;
    ST(S_MIN, F(3));
    w32(ram, out + 48, F(3));
    ST(S_BIT, m32(ram, A + FLAG_OFF));
    ST(S_Q, m32(ram, B + FLAG_OFF));
    r8 = r9 = r10 = r11 = 0;                                /* r8 / r9: capsules in play, r11 / r10: scale masks */

    /* per-fighter capsule participation */
    {
        uint32_t t = LD(S_BIT) & 0x00800000u;
        ST(S_BIT, t);
        if (t) {
            r8 = m32(ram, 0x0C110994u + 4u * vf3_mem_u8(ram, A + 0x1A20));
            r11 = 0xFEF7E7CFu;
            uint32_t b5 = m32(ram, A + 76) & 32u;
            ST(S_P, b5);
            ST(S_BIT, b5 << 26);
            r11 &= r8;
            if (b5 == 0) r8 |= LD(S_BIT); else r8 = 0;
        }
        t = LD(S_Q) & 0x00800000u;
        ST(S_BIT, t);
        if (t) {
            r9 = m32(ram, 0x0C110994u + 4u * vf3_mem_u8(ram, B + 0x1A20));
            r10 = 0xFEF7E7CFu;
            uint32_t b5 = m32(ram, B + 76) & 32u;
            ST(S_BIT, b5);
            ST(S_P, b5 << 26);
            r10 &= r9;
            if (LD(S_BIT) == 0) r9 |= LD(S_P); else r9 = 0;
        }
    }

    /* the radius arrays, unless the fighter's +0x1560 says no */
    if (!(vf3_mem_u8(ram, A + 0x1560) & 2)) {
        ST(S_Q, B + RADIUS_OFF);
        r13 = A + RADIUS_OFF;
        ST(S_ACC, r13 + 4 * COUNT_CAPS);
        ST(S_END_B, r13 + 8);
        ST(S_P, 0x0C10D390u);
        ST(S_BIT, m32(ram, 0x0C10D390u + 4u * vf3_mem_u8(ram, A + 97)));
        ST(S_P, m32(ram, 0x0C10D390u + 4u * vf3_mem_u8(ram, B + 97)));
        ST(S_MASK, r11);
        r11 = r10;
        ST(S_HITP, m32(ram, A));
        F(4) = LIT_GROW;
        r10 = m32(ram, B);
        do {
            F(5) = m32(ram, LD(S_P));
            F(6) = m32(ram, LD(S_BIT));
            if (LD(S_MASK) & TOP) FMUL(6, 4);
            const uint32_t shifted = LD(S_MASK) << 1;
            if (r11 & TOP) FMUL(5, 4);
            ST(S_MASK, shifted);
            r11 <<= 1;
            if (r13 == LD(S_END_B)) {                       /* capsule 2 also honours the 0x00800000 flag */
                if (LD(S_HITP) & 0x00800000u) FMUL(6, 4);
                if (r10 & 0x00800000u) FMUL(5, 4);
            }
            w32(ram, r13, F(6));
            w32(ram, LD(S_Q), F(5));
            r13 += 4;
            ST(S_BIT, LD(S_BIT) + 4);
            ST(S_P, LD(S_P) + 4);
            ST(S_Q, LD(S_Q) + 4);
        } while (r13 != LD(S_ACC));
    }

    for (r13 = B + HITWORD_OFF; r13 != B + HITWORD_OFF + 4 * COUNT_CAPS; r13 += 4) w32(ram, r13, 0);

    r11 = m32(ram, A + SEG_A_OFF);
    ST(S_END_A, r11 + 12 * COUNT_CAPS);
    ST(S_P, m32(ram, A + SEG_B_OFF));
    ST(S_NUM_A, A + RADIUS_OFF);
    ST(S_HITP, A + HITWORD_OFF);
    ST(S_BIT, TOP);

    while (r11 != LD(S_END_A)) {                            /* one capsule of A per pass */
        F(9) = m32(ram, r11); F(11) = m32(ram, r11 + 4);
        F(3) = m32(ram, r11 + 8); ST(S_AZ, F(3));
        r10 = LD(S_P);
        F(15) = m32(ram, r10 + 4); F(3) = m32(ram, r10 + 8); F(12) = m32(ram, r10); ST(S_PZ, F(3));
        ST(S_Q, B + HITWORD_OFF);
        r12 = B + RADIUS_OFF;
        ST(S_END_B, r12 + 4 * COUNT_CAPS);
        r13 = m32(ram, B + SEG_A_OFF);
        r5 = m32(ram, B + SEG_B_OFF);
        F(5) = m32(ram, LD(S_NUM_A));
        ST(S_ACC, 0);
        r10 = 0;

        do {                                                /* one capsule of B */
            int T = GT(15, 11);
            F(14) = m32(ram, r13 + 4); F(7) = m32(ram, r13 + 8);
            F(8) = m32(ram, r5 + 4); F(3) = m32(ram, r5 + 8);
            F(6) = m32(ram, r5); F(10) = m32(ram, r13);
            ST(S_BZ, F(3));
            F(4) = m32(ram, r12);

            /* y interval of A's segment inflated by A's radius (fr13 low, fr3 high) */
            if (T) { FMOV(13, 15); FSUB(13, 5); FMOV(3, 11); }
            else   { FMOV(13, 11); FSUB(13, 5); FMOV(3, 15); }
            T = GT(8, 14);
            FADD(3, 5);
            ST(88, F(3));
            if (T) { FMOV(3, 8); FSUB(3, 4); ST(72, F(3)); FMOV(2, 14); }
            else   { FMOV(3, 14); FSUB(3, 4); ST(72, F(3)); FMOV(2, 8); }
            FADD(2, 4); ST(68, F(2));
            F(3) = LD(72); F(2) = LD(88);
            if (GT(2, 3)) goto next;
            F(3) = LD(68);
            if (GT(3, 13)) goto next;

            /* x interval */
            T = GT(12, 9);
            if (T) { FMOV(3, 12); FSUB(3, 5); ST(92, F(3)); FMOV(13, 9); }
            else   { FMOV(3, 9); FSUB(3, 5); ST(92, F(3)); FMOV(13, 12); }
            T = GT(6, 10);
            FADD(13, 5);
            if (T) { FMOV(3, 6); FSUB(3, 4); ST(100, F(3)); FMOV(2, 10); }
            else   { FMOV(3, 10); FSUB(3, 4); ST(100, F(3)); FMOV(2, 6); }
            FADD(2, 4); ST(96, F(2));
            F(3) = LD(100);
            if (GT(13, 3)) goto next;
            F(3) = LD(92); F(2) = LD(96);
            if (GT(2, 3)) goto next;

            /* z interval */
            F(3) = LD(S_AZ); F(2) = LD(S_PZ);
            T = GT(2, 3);
            FSUB(2, 5);
            if (T) { ST(76, F(2)); F(13) = LD(S_AZ); }
            else   { F(3) = LD(S_AZ); FSUB(3, 5); ST(76, F(3)); FMOV(13, 2); }
            F(3) = LD(S_BZ);
            T = GT(3, 7);
            FADD(13, 5);
            if (T) { FSUB(3, 4); ST(84, F(3)); FMOV(3, 7); }
            else   { FMOV(2, 7); FSUB(2, 4); ST(84, F(2)); }
            FADD(3, 4); ST(80, F(3));
            F(3) = LD(84);
            if (GT(13, 3)) goto next;
            F(3) = LD(76); F(2) = LD(80);
            if (GT(2, 3)) goto next;

            /* closest approach of the two segments: d = (A0 - B0), e1 = A dir, e2 = B dir ... */
            FMOV(3, 12); FSUB(3, 6); ST(S_DZ, F(3));
            FMOV(1, 9); FSUB(1, 10);
            F(2) = LD(S_BZ);
            FMOV(13, 15); FSUB(13, 8);
            F(8) = LD(S_PZ);
            ST(64, F(1));
            FMOV(10, 11); FSUB(10, 14);
            F(6) = LD(S_AZ);
            F(3) = LD(S_DZ);
            FSUB(8, 2); FSUB(6, 7);
            FMOV(7, 1); FSUB(10, 13); FSUB(7, 3);
            FMOV(14, 6); FSUB(14, 8);
            FMOV(3, 10); FMUL(3, 10);
            FMOV(0, 7); FMAC(3, 7);
            FMOV(0, 14); FMAC(3, 14);
            F(0) = 0; FMOV(6, 3);                           /* fr6 = |u|^2 */
            if (fl(s, 6) == fl(s, 0)) goto next;            /* degenerate */
            FMOV(3, 5); FADD(3, 4); FMOV(2, 3); FMUL(2, 3); ST(S_SQ, F(2));   /* (ra + rb)^2 */
            FMOV(3, 13); FMUL(3, 10);
            F(0) = LD(S_DZ);
            FMOV(1, 6);
            FMAC(3, 7);
            FMOV(0, 8); FMAC(3, 14);
            F(0) = LD(S_DZ);
            FMOV(2, 0); FMOV(4, 3);                         /* fr4 = u . v */
            FMOV(3, 13); FMUL(3, 13); FMAC(3, 2);
            FMOV(0, 8); FMOV(2, 4); FMUL(2, 4); FMAC(3, 8);
            FMOV(10, 2); FMOV(7, 3);
            F(3) = LD(S_SQ);
            FMOV(8, 7); FSUB(8, 3);
            FMUL(1, 8); FSUB(10, 1);
            F(2) = 0;
            if (GT(10, 2)) goto next;                       /* discriminant < 0: no contact */

            F(3) = 0;
            T = GT(3, 8);
            FMOV(10, 4); F(10) ^= SIGN;
            if (T) {
                FMOV(3, 6); F(14) = LIT_TWO; F(2) = 0;
                FMOV(0, 14); FMAC(3, 4); FADD(3, 8);
                if (GT(2, 3)) {
                    F(3) = 0;
                    if (!GT(4, 3)) goto next;
                    if (!GT(10, 6)) goto next;
                }
            }

            {
                const uint32_t bit = LD(S_BIT);
                FMOV(8, 10); set_fl(s, 8, vf3_f_div(s, fl(s, 8), fl(s, 6)));
                if ((bit & r8) == 0 && ((r9 << r10) & TOP) == 0) {
                    F(3) = 0;
                    if (GT(3, 8)) {
                        F(6) = 0x3F800000u;
                        if (GT(8, 6)) { FMOV(0, 4); FMAC(7, 8); FMOV(6, 7); }
                        else          { FMOV(6, 4); FADD(6, 7); }
                    } else {
                        FMOV(6, 7);
                    }
                    F(4) = LIT_EPSILON;
                    if (GT(6, 4)) F(4) = 0;
                    else { FMOV(4, 6); F(4) = vf3_fpu_sqrt(F(4), R(VF3_REG_FPSCR)); }
                    F(3) = LD(S_MIN);
                    if (!GT(4, 3)) ST(S_MIN, F(4));
                }
            }
            ST(S_MASK, TOP >> (r10 & 31u));
            {
                const uint32_t hp = LD(S_Q);
                w32(ram, hp, m32(ram, hp) | LD(S_BIT));
            }
            ST(S_ACC, LD(S_ACC) | LD(S_MASK));
            vf3_mem_set_u8(ram, f + S_COUNT, (uint8_t)(vf3_mem_u8(ram, f + S_COUNT) + 1));

        next:
            ST(S_Q, LD(S_Q) + 4);
            r12 += 4; r10 += 1; r13 += 12; r5 += 12;
        } while (r12 != LD(S_END_B));

        r11 += 12;
        ST(S_BIT, LD(S_BIT) >> 1);
        w32(ram, LD(S_HITP), LD(S_ACC));
        ST(S_P, LD(S_P) + 12);
        ST(S_NUM_A, LD(S_NUM_A) + 4);
        ST(S_HITP, LD(S_HITP) + 4);
    }

    F(3) = LD(S_MIN);
    w32(ram, out + 48, F(3));
    vf3_mem_set_u8(ram, out + 52, vf3_mem_u8(ram, f + S_COUNT));
    R(VF3_REG_SR) |= 1u;                                    /* the closing cmp/eq was true */

leave:
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = saved_fr[0]; F(14) = saved_fr[1]; F(13) = saved_fr[2]; F(12) = saved_fr[3];
    s->pc = R(VF3_REG_PR);
    return 1;
}
