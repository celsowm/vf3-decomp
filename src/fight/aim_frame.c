/* aim_frame.c - 0x8C09E060  build the 3x4 transform of an aimed segment from two endpoints and a hit record.
 *
 *   r4 -> record A (floats at +0 / +8 / +12 / +16 / +20 / +24 / +36), r5 -> output block B (matrices at
 *   +0x40, +0x80, +0xC0), r6 -> object, r7 -> object, and on the caller's stack [sp + 12], [sp + 4], [sp + 8],
 *   [sp + 16] four more pointers (the output vec3s and the matrix block).
 *
 *   Everything is a chain of small matrix helpers (0x8C03B620 copy, 0x8C03BD80 / 0x8C03B820 multiply and store,
 *   0x8C09D42C / 0x8C09D480 / 0x8C09D4E6 / 0x8C09D52E angle -> matrix builders, 0x8C03CC60 translate) on a
 *   0x128-byte frame of 4x4 temporaries. The one piece of arithmetic is the middle block: when FR7 = [r6+12] +
 *   [r6+16] exceeds the clearance [sp+8] it derives two clamped ratios (FR5, FR14, each limited to [-1, 1] from
 *   the squares of the three lengths) and the square roots 0x8C03C970 builds the two rotations from (zero
 *   below 1e-7); otherwise the rotations are skipped.
 *
 *   Frame (0x128 bytes under seven saved registers, three FRs and pr): the matrices live at +0x40 / +0x80 / +0xC0 / +0xD0 /
 *   +0x100 / +0x110 / +0x11C; +0 and +4 keep r6 / r7. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 44, FRAME = 0x128, LIT_TWO = 0x40000000u, LIT_MINUS_ONE = 0xBF800000u, LIT_HALF = 0x3F000000u,
       LIT_ONE = 0x3F800000u, LIT = 0x33D6BF94u };

#define M(off)      m32(ram, f + (off))
#define W(off, v)   w32(ram, f + (off), (v))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

/* one rotation step: FRd = FRd + FR0 * FRm, with the three components at frame +0x40 / +0x44 / +0x48 */
static void fma_row(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t f, uint32_t src_off)
{
    for (uint32_t k = 0; k < 12; k += 4) {
        F(3) = M(0x40 + k);
        F(2) = M(src_off + k);
        FMAC(3, 2);
        W(0x40 + k, F(3));
    }
}

int vf3_aim_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[3] = { F(15), F(14), F(13) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 3; ++i) w32(ram, sp0 - 28 - 4u * (uint32_t)(i + 1), saved_f[i]);
    w32(ram, sp0 - 44, pr0);
    R(15) = f;

    R(13) = R(4);
    R(11) = R(5);
    W(0, R(6));
    W(4, R(7));
    R(10) = M(0x160);
    R(8) = 0x0C03C4F0u; R(9) = 0x0C03C4A0u; R(12) = 0x0C03BD80u; R(14) = 0x0C03B620u;

    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E08Cu);
    CALL(0x8C03CCB0u, 0x8C09E092u);
    R(4) = f + 0x90; CALL(0x8C03B620u, 0x8C09E09Au);
    R(4) = f + 80; CALL(0x8C03B620u, 0x8C09E0A0u);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E0A6u);

    F(4) = m32(ram, R(13));
    F(5) = m32(ram, R(13) + 8);
    F(5) ^= SIGN;
    R(4) = f + 0x11C; CALL(0x8C09D42Cu, 0x8C09E0B4u);
    R(4) = f + 0xD0; CALL(0x8C03B620u, 0x8C09E0BAu);

    W(0x100, M(0x11C));
    W(0x104, M(0x120));
    W(0x108, M(0x124));

    R(3) = M(0);
    F(6) = m32(ram, R(3) + 4);
    F(15) = 0;
    F(5) = F(15);
    F(4) = m32(ram, R(3));
    CALL(0x8C03CC60u, 0x8C09E0E2u);

    R(4) = M(0x158); CALL(0x8C09D480u, 0x8C09E0E8u);
    R(4) = f + 0xD0; CALL(0x8C09D4E6u, 0x8C09E0EEu);
    R(5) = f + 0xD0; R(4) = R(11); CALL(0x8C03B530u, 0x8C09E0F8u);
    R(4) = f + 0x90; CALL(0x8C09D4E6u, 0x8C09E0FEu);

    W(0xC0, M(0x100));
    W(0xC4, M(0x104));
    W(0xC8, M(0x108));
    R(4) = f + 16; CALL(0x8C03B620u, 0x8C09E11Cu);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E120u);
    R(4) = f + 0x90; CALL(0x8C03BD80u, 0x8C09E128u);

    F(6) = m32(ram, R(13) + 20);
    F(5) = F(15);
    F(6) ^= SIGN;
    F(4) = m32(ram, R(13) + 12);
    CALL(0x8C03CC60u, 0x8C09E13Cu);
    R(4) = f + 0xD0; CALL(0x8C03B620u, 0x8C09E13Eu);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E142u);

    R(2) = M(0);
    F(4) = m32(ram, R(2) + 8);
    F(0) = F(4);
    fma_row(s, ram, f, 0x30);
    R(4) = f + 16; CALL(0x8C03BD80u, 0x8C09E17Au);
    R(4) = M(0x158) + 6; CALL(0x8C09D480u, 0x8C09E182u);

    R(5) = f + 8; R(6) = f + 12;
    for (uint32_t k = 0; k < 12; k += 4) {
        F(2) = m32(ram, M(4) + k);
        F(3) = m32(ram, M(0x164) + k);
        FADD(2, 3);
        W(0x110 + k, F(2));
    }
    R(4) = f + 0x110; CALL(0x8C09DC34u, 0x8C09E1C4u);
    R(4) = R(11) + 0xC0; CALL(0x8C09D4E6u, 0x8C09E1CCu);

    R(2) = M(0);
    F(6) = m32(ram, R(2) + 12);
    F(4) = m32(ram, R(2) + 16);
    F(5) = M(8);
    FMOV(7, 4); FADD(7, 6);
    FMOV(14, 15);                                           /* delay slot of the branch */
    if (!GT(5, 7)) {
        R(4) = f + 80; CALL(0x8C09D4E6u, 0x8C09E2FAu);
        R(4) = M(0x154); CALL(0x8C09D4E6u, 0x8C09E300u);
    } else {
        FMOV(10, 5); FMUL(10, 5);
        FMOV(9, 6); FMUL(9, 6);
        FMOV(8, 4); FMUL(8, 4);
        FMOV(2, 4);
        FMUL(4, 6);
        FMOV(3, 10);
        FSUB(3, 9);
        F(7) = LIT_TWO;
        FMUL(2, 5);
        FMUL(4, 7);
        FADD(3, 8);
        FADD(8, 9);
        FMUL(2, 7);
        FMOV(5, 3);
        FSUB(8, 10);
        FDIV(5, 2);
        FMOV(14, 8);
        FDIV(14, 4);
        F(4) = LIT_ONE;
        F(6) = LIT_MINUS_ONE;
        if (GT(4, 14)) FMOV(14, 4);
        else if (GT(14, 6)) FMOV(14, 6);
        if (GT(4, 5)) FMOV(5, 4);
        else if (GT(5, 6)) FMOV(5, 6);
        FMOV(3, 5); FMUL(3, 5);
        F(13) = LIT;
        FSUB(4, 3);
        if (GT(4, 13)) F(4) = 0;
        else F(4) = vf3_fpu_sqrt(F(4), R(VF3_REG_FPSCR));
        CALL(0x8C03C970u, 0x8C09E292u);
        R(4) = f + 80; CALL(0x8C09D4E6u, 0x8C09E298u);

        F(5) = LIT_HALF;
        FMOV(6, 14); FMUL(6, 5);
        FMOV(4, 6); FADD(4, 5);
        if (GT(4, 13)) F(3) = 0;
        else { FMOV(3, 4); F(3) = vf3_fpu_sqrt(F(3), R(VF3_REG_FPSCR)); }
        FMOV(4, 5); FSUB(4, 6);
        FMOV(14, 3);
        F(14) ^= SIGN;
        if (GT(4, 13)) F(13) = 0;
        else { FMOV(13, 4); F(13) = vf3_fpu_sqrt(F(13), R(VF3_REG_FPSCR)); }
        FMOV(5, 13); FMOV(4, 14);
        CALL(0x8C03C970u, 0x8C09E2CCu);
        R(4) = M(0x154); CALL(0x8C09D4E6u, 0x8C09E2D2u);
        FMOV(5, 13); FMOV(4, 14);
        CALL(0x8C03C970u, 0x8C09E2DAu);
    }

    R(2) = R(11) + 64;
    W(0, R(2));
    R(4) = f + 0xD0; CALL(0x8C09D4E6u, 0x8C09E30Cu);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E310u);
    R(4) = f + 0xD0; CALL(0x8C03BD80u, 0x8C09E316u);
    R(4) = f + 0x11C; CALL(0x8C03B820u, 0x8C09E31Eu);
    R(4) = M(0); CALL(0x8C03B620u, 0x8C09E322u);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E326u);
    R(4) = f + 0x11C; CALL(0x8C03CBD0u, 0x8C09E32Eu);
    R(4) = R(10); CALL(0x8C03B820u, 0x8C09E334u);

    R(3) = M(0x15C);
    R(4) = R(10) + 12;
    F(4) = m32(ram, M(0x15C));
    CALL(0x8C09D52Eu, 0x8C09E340u);
    R(4) = f + 16; CALL(0x8C03B620u, 0x8C09E346u);

    F(4) = m32(ram, R(13) + 24);
    F(0) = F(4);
    fma_row(s, ram, f, 0x10);

    R(3) = M(0x154);
    w32(ram, R(3) + 48, F(14));
    R(3) = R(11) + 0x80;
    W(0, R(3));
    R(4) = f + 16; CALL(0x8C03BD80u, 0x8C09E38Au);
    R(4) = f + 0x80; CALL(0x8C03B820u, 0x8C09E392u);
    R(4) = 0; CALL(0x8C03C4F0u, 0x8C09E396u);
    R(4) = f + 80; CALL(0x8C03BD80u, 0x8C09E39Cu);
    R(4) = f + 16; CALL(0x8C03B620u, 0x8C09E3A2u);
    R(4) = M(0); CALL(0x8C03B620u, 0x8C09E3A6u);
    R(4) = 1; CALL(0x8C03C4A0u, 0x8C09E3AAu);
    R(4) = f + 16; CALL(0x8C03BD80u, 0x8C09E3B0u);
    R(4) = R(10) + 24; CALL(0x8C03B820u, 0x8C09E3B8u);

    R(2) = M(0x15C);
    R(4) = R(10) + 36;
    F(4) = m32(ram, R(2) + 4);
    CALL(0x8C09D52Eu, 0x8C09E3C6u);
    F(4) = m32(ram, R(13) + 36);
    F(6) = F(15);
    F(5) = F(15);
    CALL(0x8C03CC60u, 0x8C09E3D2u);
    R(4) = M(0x158) + 12; CALL(0x8C09D480u, 0x8C09E3DAu);
    R(4) = R(11) + 0xC0; CALL(0x8C03B620u, 0x8C09E3E0u);

    R(2) = M(0x15C);
    R(4) = R(10) + 48;
    F(4) = m32(ram, R(2) + 8);
    CALL(0x8C09D52Eu, 0x8C09E3EEu);

    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
