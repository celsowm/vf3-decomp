/* aim_frame_b.c - 0x8C09E6B2  the second aim-frame builder: the same helper chain as aim_frame.c (0x8C09E060),
 *   writing a rotation block and a translated point pair instead of three matrices.
 *
 *   r4 -> a pointer kept at [sp + 20], r5 -> record A (floats at +0 / +8 / +12 / +24), r6 -> object (floats at
 *   +4.., the clearance at +8), r7 -> object, FR4 -> a float kept at [sp + 16], and on the caller's stack
 *   [sp + 12] -> output block B (rotation at +0, translation at +48..+56), [sp + 20] -> vec3 pair C
 *   (+12 / +24..+32 / +36 / +48 / +60), [sp + 28] -> the matrix block, [sp + 32] -> the last matrix.
 *
 *   The clamped ratios and square roots in the middle are the same arithmetic as aim_frame.c; here the first
 *   rotation (0x8C03C970 with -sqrt(1 - FR5^2)) is applied to a matrix at +0xB0 and the second through r11.
 *   The tail multiplies the result into the matrix block (0x8C03B530) and writes the -0.1 / -0.2 / 0.0 offsets
 *   (the literal 0xBDCCCCCC at 0x8C09EA4C) before the final 0x8C03B450 stores.
 *
 *   Frame (0x130 bytes under seven saved registers, three FRs and pr). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 44, FRAME = 0x130, LIT_TWO = 0x40000000u, LIT_MINUS_ONE = 0xBF800000u, LIT_HALF = 0x3F000000u,
       LIT_ONE = 0x3F800000u, LIT = 0x33D6BF94u, LIT_TENTH = 0xBDCCCCCCu };

#define M(off)      m32(ram, f + (off))
#define W(off, v)   w32(ram, f + (off), (v))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

/* frame[dst + k] += FR0 * frame[src + k] for the three components */
static void fma_row(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t f, uint32_t dst, uint32_t src)
{
    for (uint32_t k = 0; k < 12; k += 4) {
        F(3) = M(dst + k);
        F(2) = M(src + k);
        FMAC(3, 2);
        W(dst + k, F(3));
    }
}

int vf3_aim_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[3] = { F(15), F(14), F(13) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 3; ++i) w32(ram, sp0 - 28 - 4u * (uint32_t)(i + 1), saved_f[i]);
    w32(ram, sp0 - 44, pr0);
    R(15) = f;

    R(10) = R(5);
    W(20, R(4));
    W(4, R(6));
    W(0, R(7));
    R(11) = M(0x160);
    R(12) = M(0x168);
    R(14) = M(0x16C);
    W(16, F(4));
    R(8) = 0x0C03C4F0u; R(13) = 0x0C03B620u; R(9) = 0x0C03C4A0u;

    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E6EAu);
    CALL(0x8C03CCB0u, 0x8C09E6F0u);
    R(4) = f + 0xF0; CALL(0x8C03B620u, 0x8C09E6F8u);
    R(4) = f + 0xB0; CALL(0x8C03B620u, 0x8C09E6FEu);
    R(4) = f + 112; CALL(0x8C03B620u, 0x8C09E704u);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E70Au);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E70Eu);

    F(6) = m32(ram, R(10) + 8);
    F(15) = 0;
    F(5) = F(15);
    F(6) ^= SIGN;
    F(4) = m32(ram, R(10));
    CALL(0x8C03CC60u, 0x8C09E71Eu);
    R(4) = f + 0xF0; CALL(0x8C03B620u, 0x8C09E724u);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E728u);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E72Cu);

    R(2) = M(0);
    F(6) = m32(ram, R(2) + 4);
    F(5) = F(15);
    F(4) = m32(ram, R(2));
    CALL(0x8C03CC60u, 0x8C09E73Au);
    R(4) = M(0x164); CALL(0x8C09D480u, 0x8C09E742u);

    R(6) = f + 12; R(5) = f + 8;
    F(3) = m32(ram, M(0x15C));
    W(88, F(3));
    R(3) = M(0x15C);
    F(3) = M(16);
    F(2) = m32(ram, R(3) + 4);
    FADD(2, 3);
    W(92, F(2));
    F(2) = m32(ram, R(3) + 8);
    W(96, F(2));
    R(4) = f + 88; CALL(0x8C09DC34u, 0x8C09E774u);

    R(3) = M(0);
    F(6) = m32(ram, R(3) + 8);
    F(4) = m32(ram, R(3) + 12);
    FMOV(7, 6); FADD(7, 4);
    F(5) = M(8);
    if (!GT(5, 7)) {
        R(4) = f + 0xB0; CALL(0x8C09D4E6u, 0x8C09E894u);
        R(4) = R(11); CALL(0x8C09D4E6u, 0x8C09E89Au);
    } else {
        FMOV(10, 5); FMUL(10, 5);
        FMOV(8, 6); FMUL(8, 6);
        FMOV(7, 4); FMUL(7, 4);
        FMOV(2, 4); FMUL(2, 5);
        FMOV(3, 10);
        FSUB(3, 8);
        F(9) = LIT_TWO;
        FMUL(6, 4);
        F(4) = LIT_ONE;
        FMUL(2, 9);
        FADD(3, 7);
        FADD(7, 8);
        FMUL(6, 9);
        FMOV(5, 3);
        FDIV(5, 2);
        FSUB(7, 10);
        FMOV(14, 7);
        FDIV(14, 6);
        F(6) = LIT_MINUS_ONE;
        if (GT(4, 5)) FMOV(5, 4);
        else if (GT(5, 6)) FMOV(5, 6);
        if (GT(4, 14)) FMOV(14, 4);
        else if (GT(14, 6)) FMOV(14, 6);
        FMOV(3, 5); FMUL(3, 5);
        F(13) = LIT;
        FSUB(4, 3);
        if (GT(4, 13)) F(3) = 0;
        else { FMOV(3, 4); F(3) = vf3_fpu_sqrt(F(3), R(VF3_REG_FPSCR)); }
        FMOV(4, 3);
        F(4) ^= SIGN;
        CALL(0x8C03C970u, 0x8C09E830u);
        R(4) = f + 0xB0; CALL(0x8C09D4E6u, 0x8C09E838u);

        F(4) = LIT_HALF;
        FMOV(6, 14); FMUL(6, 4);
        FMOV(5, 6); FADD(5, 4);
        FSUB(4, 6);
        if (GT(5, 13)) F(14) = 0;
        else { FMOV(14, 5); F(14) = vf3_fpu_sqrt(F(14), R(VF3_REG_FPSCR)); }
        if (GT(4, 13)) F(13) = 0;
        else { FMOV(13, 4); F(13) = vf3_fpu_sqrt(F(13), R(VF3_REG_FPSCR)); }
        FMOV(5, 13); FMOV(4, 14);
        CALL(0x8C03C970u, 0x8C09E866u);
        R(4) = R(11); CALL(0x8C09D4E6u, 0x8C09E86Cu);
        FMOV(5, 13); FMOV(4, 14);
        CALL(0x8C03C970u, 0x8C09E874u);
    }

    R(4) = f + 0xF0; CALL(0x8C09D4E6u, 0x8C09E8A2u);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E8A6u);
    R(4) = f + 0xF0; CALL(0x8C03BD80u, 0x8C09E8AEu);
    R(4) = f + 100; CALL(0x8C03B820u, 0x8C09E8B6u);
    R(4) = M(4); CALL(0x8C03B620u, 0x8C09E8BAu);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E8BEu);
    R(4) = f + 100; CALL(0x8C03CBD0u, 0x8C09E8C6u);
    R(4) = R(14); CALL(0x8C03B820u, 0x8C09E8CCu);
    R(4) = f + 24; CALL(0x8C03B620u, 0x8C09E8D2u);
    R(4) = R(14) + 12;
    F(4) = m32(ram, R(12));
    CALL(0x8C09D52Eu, 0x8C09E8DCu);

    F(4) = m32(ram, R(10) + 12);
    F(0) = F(4);
    fma_row(s, ram, f, 72, 24);
    for (uint32_t k = 0; k < 12; k += 4) w32(ram, R(11) + 48 + k, M(72 + k));

    R(3) = M(4) + 64;
    W(0, R(3));
    W(0xE0, M(72));
    W(0xE4, M(76));
    W(0xE8, M(80));
    R(4) = f + 0xB0; CALL(0x8C03BD80u, 0x8C09E94Au);
    R(4) = M(0); CALL(0x8C03B620u, 0x8C09E94Eu);

    for (uint32_t k = 0; k < 12; k += 4) w32(ram, R(14) + 24 + k, M(72 + k));
    R(4) = R(14) + 36;
    F(4) = m32(ram, R(12) + 4);
    CALL(0x8C09D52Eu, 0x8C09E972u);
    R(4) = R(14) + 48;
    F(4) = m32(ram, R(12) + 8);
    CALL(0x8C09D52Eu, 0x8C09E97Eu);
    F(4) = m32(ram, R(10) + 24);
    F(6) = F(15);
    F(5) = F(15);
    CALL(0x8C03CC60u, 0x8C09E98Au);

    R(5) = M(20);
    R(4) = M(0x164) + 6;
    CALL(0x8C09DA1Eu, 0x8C09E994u);
    R(4) = f + 112; CALL(0x8C03B620u, 0x8C09E99Au);
    R(4) = M(4) + 0x80;
    R(5) = f + 112;
    CALL(0x8C03B530u, 0x8C09E9A8u);

    F(3) = LIT_TENTH;
    W(92, F(3));
    FMOV(4, 3); FADD(3, 4);
    W(96, F(3));
    F(4) = M(92);
    FMOV(3, 4); FSUB(3, 4);
    W(88, F(3));
    R(5) = M(0x170);
    R(4) = f + 88;
    CALL(0x8C03B450u, 0x8C09E9CEu);

    R(4) = R(14) + 60;
    F(4) = m32(ram, R(12) + 12);
    CALL(0x8C09D554u, 0x8C09E9DCu);
    W(100, F(15));
    W(104, m32(ram, R(12) + 16));
    W(108, m32(ram, R(12) + 20));
    R(5) = R(14) + 72;
    R(4) = f + 100;
    CALL(0x8C03B450u, 0x8C09E9FCu);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09EA00u);

    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
