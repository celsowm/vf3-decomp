/* steer_flags.c - 0x8C0C6770  per-frame steering inputs of a fighter: the 28 ring angles, the clearance flags and
 * the turn-rate words.
 *
 * r4 = fighter record (r14), r5 = second record (held at f+28h). In order:
 *   1. The mode nibble of the global byte 0x0C29B864+1C selects 0x0C2D0190's flags: [0] (mode != 2), [1C] =
 *      (mode != 7) | [0], [18] (mode == 13 clears, else 1).
 *   2. The 28 boundary points at the list pointer +0x138C (x at +0, z at +8) are turned into angles with
 *      0x8C068E0E (atan2 of x, -z) and stored in the ring at +0x15A8.
 *   3. Unless the state word has bit 0x200 clear / 0x20000000 set, the second record's float at +0x12E0 is added
 *      to every ring entry whose bit is set in the mask word 0x0C110994[type] (type = byte +0x1A20, bit 0x80000000 >> i).
 *   4. The min and max of ring[+0x1C] and ring[+0x30] are stored at +0x1594 / +0x1598, [10] is set from the
 *      0x20000000 bit and the working flags r13 start at 0.
 *   5. The state word (r9) and the contact words around +0x185C decide the flag bits of r13: 1 / 2 / 4 / 8 / 10 /
 *      20 / 40 / 80 / 100 / 200 / 400 / 800. Two turn-rate shorts (+0x22BE / +0x22BC or +0x22E4, +0x22E8 / +0x22EA)
 *      come from 0x8C069624 on angle differences, clamped to +-0x1800 / 0x2000.
 *   6. Finally the clearance value in fr13 becomes the contact normal at +0x13A8 .. +0x13B0 (clamped to +-0.1 /
 *      0.05 / 0.02), r13 is stored as a byte at +0x1FDD and the frame is torn down.
 *
 * The routine mirrors the original's registers and stack slots, so the full register file and the frame it leaves
 * are the original's. Frame (f = sp - 112): f+0 loop counter / mode, f+4 ring cursor / flag word, f+8 the global block
 * pointer, f+C .. f+30 float temporaries, f+28 second record, f+34 .. f+3C the 0x8C06911C result. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define U8(a)       ((uint32_t)vf3_mem_u8(ram, (a)))
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))
#define SIGN        0x80000000u
#define ANGLE_FN    0x8C068E0Eu
#define DIFF_FN     0x8C069624u
#define CLEAR_FN    0x8C06911Cu

/* jsr 0x8C068E0E with fneg fr5 in the delay slot: fr4 = x, fr3 = z, fr5 = -z. */
#define ANGLE(ret) do { F(5) = F(3) ^ SIGN; R(3) = 0x0C068E0Eu; CALL(ANGLE_FN, (ret)); } while (0)

/* SHLD: a negative count shifts right (logical), a positive one left; only the low 5 bits count. */
static uint32_t shld(uint32_t v, uint32_t n)
{
    const uint32_t c = n & 31u;
    if ((n & SIGN) == 0) return v << c;
    const uint32_t r = (0u - n) & 31u;
    return r == 0 ? 0u : v >> r;
}

int vf3_steer_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 112;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_fr[4] = { F(15), F(14), F(13), F(12) };
    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 32 - 4u * (uint32_t)i, saved_fr[i]);
    w32(ram, sp0 - 48, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(1) = 28;
    R(14) = R(4);
    R(4) = 15;
    R(10) = 4;
    R(8) = 0x00800000u;
    R(15) = f;
    w32(ram, f + 40, R(5));
    R(3) = 0x0C29B864u;
    R(0) = R(3);
    w32(ram, f + 8, R(3));
    R(0) = U8(R(0) + R(1));
    R(4) &= R(0);
    R(0) = 0x138C;
    R(3) = 0x15A8 + R(14);
    R(9) = m32(ram, R(14) + R(0));
    R(0) = R(4);
    w32(ram, f + 4, R(3));
    R(12) = 0x0C2D0190u;
    R(11) = 0;                                         /* delay slot of the bf/s below */
    w32(ram, R(12), R(4) == 2 ? 0u : 1u);
    w32(ram, R(12) + 28, R(4) == 7 ? 0u : 1u);
    w32(ram, R(12) + 24, R(4) == 13 ? 0u : 1u);
    R(0) = R(4);
    R(1) = m32(ram, R(12) + 28);
    R(13) = 28;
    R(3) = m32(ram, R(12));
    R(1) |= R(3);
    w32(ram, R(12) + 28, R(1));
    w32(ram, f, R(13));

    /* 28 boundary points -> angles in the ring at +0x15A8. */
    do {
        R(0) = 8;
        F(4) = m32(ram, R(9));
        F(3) = m32(ram, R(9) + R(0));
        R(0) = 44;
        R(9) += 12;
        w32(ram, f + R(0), F(3));
        ANGLE(0x8C0C681Cu);
        R(2) = m32(ram, f + 4);
        F(4) = F(0);
        w32(ram, R(2), F(4));
        R(3) = m32(ram, f + 4) + 4;
        w32(ram, f + 4, R(3));
        R(2) = m32(ram, f) - 1;
        w32(ram, f, R(2));
    } while (R(2) != 0);

    R(0) = 72;
    R(3) = 0x200;
    R(4) = m32(ram, R(14) + R(0));
    TST(R(4), R(3));
    if (R(VF3_REG_SR) & 1u) goto ring_done;
    R(2) = 0x20000000u;
    TST(R(2), R(4));
    if (!(R(VF3_REG_SR) & 1u)) goto ring_done;
    R(0) = 0x12E0;
    R(3) = m32(ram, f + 40);
    R(5) = 0x15A8;
    F(5) = m32(ram, R(3) + R(0));
    R(0) = 0x1A20;
    R(5) += R(14);
    R(4) = S8(R(14) + R(0));
    R(0) = 0x0C110994u;
    R(6) = R(4) & 0xFFu;
    R(4) = R(13);
    R(6) <<= 2;
    R(6) = m32(ram, R(0) + R(6));
    do {
        R(7) = R(13);
        R(3) = SIGN;
        R(7) -= R(4);
        R(7) = 0u - R(7);
        R(3) = shld(R(3), R(7));
        TST(R(6), R(3));
        if (!(R(VF3_REG_SR) & 1u)) {
            F(4) = m32(ram, R(5));
            FADD(4, 5);
            w32(ram, R(5), F(4));
        }
        R(4) -= 1;
        R(5) += 4;
    } while (R(4) != 0);

ring_done:
    R(4) = 0x15A8 + R(14);
    R(0) = 76;
    F(3) = 0;
    F(15) = m32(ram, R(4) + R(0));
    R(4) += 104;
    F(14) = m32(ram, R(4));
    FMOV(12, 15);
    FSUB(12, 14);
    if (GT(12, 3)) { F(3) = 0; FMOV(4, 15); } else { F(3) = 0; FMOV(4, 14); }
    if (GT(12, 3)) FMOV(5, 14); else FMOV(5, 15);
    R(0) = 0x1594;
    w32(ram, R(14) + R(0), F(4));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(5));
    R(4) = m32(ram, R(14));
    R(3) = 0x20000000u;
    TST(R(3), R(4));
    R(13) = R(11);
    w32(ram, R(12) + 16, (R(4) & R(3)) ? 1u : 0u);

    R(0) = 99;
    R(4) = U8(R(14) + R(0));
    R(0) = 0x138C;
    R(11) = m32(ram, R(14) + R(0));
    R(0) = 72;
    R(9) = m32(ram, R(14) + R(0));
    R(4) -= 1;
    R(0) = 0x1A04;
    R(3) = m32(ram, R(14) + R(0));
    w32(ram, f + 4, R(3));
    R(0) = 0x1A20;
    R(2) = U8(R(14) + R(0));
    w32(ram, f, R(2));
    w32(ram, R(12) + 12, R(4));
    R(3) = m32(ram, f + 8);
    R(2) = 0x00C03000u;
    R(1) = m32(ram, R(3));
    TST(R(2), R(1));
    if (!(R(VF3_REG_SR) & 1u)) goto check_1890;
    R(3) = m32(ram, f + 8);
    R(2) = 0x00038000u;
    R(1) = m32(ram, R(3) + 4);
    TST(R(2), R(1));
    if (R(VF3_REG_SR) & 1u) goto have_state;
check_1890:
    R(0) = 0x1890;
    R(4) = m32(ram, R(14) + R(0));
    TST(R(10), R(4));
    if (!(R(VF3_REG_SR) & 1u)) goto have_state;
    /* the original compares one nibble against 12, then 5, then 15 in turn; the three never hold together */
    goto exit_;

have_state:
    R(3) = 0x100;
    TST(R(9), R(3));
    if (!(R(VF3_REG_SR) & 1u)) goto exit_;
    R(0) = 60;
    R(3) = 0x424;
    R(2) = vf3_mem_u16(ram, R(14) + R(0));
    SET_T(R(2) == R(3));
    if (R(2) == R(3)) goto exit_;
    R(0) = 76;
    R(3) = 0x100;
    R(2) = m32(ram, R(14) + R(0));
    TST(R(3), R(2));
    R(4) = m32(ram, R(12) + 16);                       /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto l698a;
    R(5) = 0x0003B200u;
    TST(R(9), R(5));
    if (R(VF3_REG_SR) & 1u) goto l6aec;
    R(5) = 0x3200;
    TST(R(9), R(5));
    if (R(VF3_REG_SR) & 1u) goto l697a;
    R(3) = 0x200;
    TST(R(9), R(3));
    if (!(R(VF3_REG_SR) & 1u)) goto l6978;
    R(5) = 0x00028000u;
    TST(R(9), R(5));
    if (!(R(VF3_REG_SR) & 1u)) goto l697a;
l6978:
    R(13) = 32;
l697a:
    R(3) = R(9);
    TST(R(8), R(3));
    if (R(VF3_REG_SR) & 1u) goto l698a;
    R(2) = m32(ram, R(12) + 12);
    TST(R(2), R(2));
    if (R(VF3_REG_SR) & 1u) goto l698a;
    goto l6aec;
l698a:
    TST(R(4), R(4));
    R(1) = 1;
    R(13) |= R(1);                                     /* delay slot of the bt/s */
    if (R(VF3_REG_SR) & 1u) goto l69b8;
    R(3) = 32;
    R(13) |= R(3);
    goto exit_;

l69b8:
    R(6) = 0x185C;
    R(6) += R(14);
    R(4) = m32(ram, R(6) + R(0));
    R(0) = 104;
    R(5) = m32(ram, R(6) + R(0));
    R(7) = R(4);
    R(6) = m32(ram, R(6) + 8);
    R(7) |= R(5);
    R(7) |= R(6);
    TST(R(10), R(7));
    if (R(VF3_REG_SR) & 1u) goto l69e0;
    R(4) &= R(5);
    TST(R(10), R(4));
    if (!(R(VF3_REG_SR) & 1u)) goto l69d8;
    R(3) = 64;
    R(13) |= R(3);
l69d8:
    TST(R(10), R(6));
    if (!(R(VF3_REG_SR) & 1u)) goto l69e0;
    R(2) = 0x80;
    R(13) |= R(2);
l69e0:
    R(12) = 0xFFFFE000u;
    R(3) = 32;
    R(0) = 0x15DC;
    TST(R(13), R(3));
    R(11) = 0x2000;
    F(13) = m32(ram, R(14) + R(0));                    /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto l6a7a;
    R(0) = 0x22C0;
    F(4) = m32(ram, R(14) + R(0));
    R(0) += 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 32;
    w32(ram, f + R(0), F(3));
    ANGLE(0x8C0C6A02u);
    R(0) = 0x8C0C6AD8u;                                /* mova: 0.25f */
    R(3) = 0x0C069624u;
    F(5) = 0x3E800000u;
    FMOV(3, 0);
    FMOV(4, 13);
    FSUB(4, 3);
    CALL(DIFF_FN, 0x8C0C6A10u);
    R(2) = 0x00100000u;
    R(0) = (uint32_t)(int32_t)(int16_t)R(0);
    TST(R(9), R(2));
    R(4) = (uint32_t)(int32_t)(int16_t)R(0);
    if (!(R(VF3_REG_SR) & 1u)) R(4) = 0u - R(4);
    R(0) = 0x22BE;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(4));
    R(0) += 14;
    F(4) = m32(ram, R(14) + R(0));
    R(0) += 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 24;
    w32(ram, f + R(0), F(3));
    ANGLE(0x8C0C6A34u);
    R(0) = 12;
    w32(ram, f + R(0), F(0));
    R(0) = 0x22D8;
    F(4) = m32(ram, R(14) + R(0));
    R(0) += 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 28;
    w32(ram, f + R(0), F(3));
    ANGLE(0x8C0C6A4Cu);
    R(0) = 0x8C0C6AE4u;                                /* mova: 0.4f */
    R(3) = 0x0C069624u;
    F(5) = 0x3ECCCCCCu;
    R(0) = 12;
    F(3) = m32(ram, f + R(0));
    FMOV(4, 0);
    FSUB(4, 3);
    CALL(DIFF_FN, 0x8C0C6A5Cu);
    R(2) = 0x00100000u;
    R(0) = (uint32_t)(int32_t)(int16_t)R(0);
    TST(R(9), R(2));
    R(4) = (uint32_t)(int32_t)(int16_t)R(0);
    if (!(R(VF3_REG_SR) & 1u)) R(4) = 0u - R(4);
    if ((int32_t)R(4) > (int32_t)R(11)) R(4) = R(11);
    else if ((int32_t)R(4) < (int32_t)R(12)) R(4) = R(12);
    R(0) = 0x22BC;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(4));
l6a7a:
    R(4) = 0xA0;
    TST(R(13), R(4));
    if (!(R(VF3_REG_SR) & 1u)) goto l6e06;
    R(4) = 0x15A8;
    R(0) = 12;
    R(3) = 0x0C069624u;
    R(4) += R(14);
    F(4) = m32(ram, R(4) + R(0));
    R(0) = 32;
    F(6) = m32(ram, R(4) + R(0));
    R(0) = 0x8C0C6AE8u;                                /* mova: 0.5f */
    F(5) = 0x3F000000u;
    FSUB(4, 6);
    CALL(DIFF_FN, 0x8C0C6A9Au);
    R(2) = 0x00100000u;
    R(0) = (uint32_t)(int32_t)(int16_t)R(0);
    TST(R(2), R(9));
    R(4) = (uint32_t)(int32_t)(int16_t)R(0);
    if (!(R(VF3_REG_SR) & 1u)) R(4) = 0u - R(4);
    if ((int32_t)R(4) > (int32_t)R(11)) R(4) = R(11);
    else if ((int32_t)R(4) < (int32_t)R(12)) R(4) = R(12);
    R(0) = 0x22E4;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(4));
    goto l6e06;

l6aec:
    TST(R(4), R(4));
    if (!(R(VF3_REG_SR) & 1u)) goto exit_;
    R(2) = 32;
    TST(R(2), R(9));
    if (R(VF3_REG_SR) & 1u) goto l6b60;
    R(4) = 0x15A8;
    R(0) = 28;
    R(4) += R(14);
    F(15) = m32(ram, R(4) + R(0));
    R(0) = 48;
    F(14) = m32(ram, R(4) + R(0));
    R(4) = R(11);
    R(0) = 0x12C8;
    R(4) += 88;
    F(4) = m32(ram, R(4));
    F(5) = m32(ram, R(14) + R(0));
    FSUB(4, 5);
    SET_T(GT(15, 4));
    R(4) = 8;                                          /* delay slot of the bf/s below */
    if (!GT(15, 4)) goto l6b20;
    R(0) = 0x1878;
    R(5) = m32(ram, R(14) + R(0));
    TST(R(10), R(5));
    if (R(VF3_REG_SR) & 1u) goto l6b22;
l6b20:
    R(13) |= R(4);
l6b22:
    R(5) = 0x94;
    R(0) = 0x12DC;
    R(5) += R(11);
    F(5) = m32(ram, R(14) + R(0));
    F(4) = m32(ram, R(5));
    FSUB(4, 5);
    SET_T(GT(14, 4));
    if (!GT(14, 4)) goto l6b3a;
    R(0) = 0x188C;
    R(5) = m32(ram, R(14) + R(0));
    TST(R(10), R(5));
    if (R(VF3_REG_SR) & 1u) goto l6b3e;
l6b3a:
    R(3) = 16;
    R(13) |= R(3);
l6b3e:
    R(5) = 24;
    R(5) &= R(13);
    R(0) = R(5);
    if (R(0) != 24) goto l6b52;
    R(0) = 0x8C0C6C00u;                                /* mova: 0.25f */
    FMOV(5, 15);
    F(4) = 0x3E800000u;
    FSUB(5, 14);                                       /* delay slot of the bra */
    goto l6dac;
l6b52:
    TST(R(13), R(4));
    FMOV(13, 15);                                      /* delay slot of the bt/s */
    if (R(VF3_REG_SR) & 1u) goto l6d84;
    goto l6e06;

l6b60:
    R(4) = 0xE8;
    R(0) = 0x8C0C6C04u;                                /* mova: 0.05f */
    F(13) = 0x3D4CCCCCu;
    R(0) = 20;
    R(4) += R(11);
    F(5) = m32(ram, R(4));
    R(4) = 0x13C;
    R(4) += R(11);
    F(3) = m32(ram, R(4));
    w32(ram, f + R(0), F(3));
    R(0) = 0x8C0C6C08u;                                /* mova: 0.1f */
    FMOV(6, 5);
    FSUB(6, 3);
    F(4) = 0x3DCCCCCCu;
    R(0) = 16;
    F(6) &= 0x7FFFFFFFu;
    FSUB(6, 4);
    w32(ram, f + R(0), F(6));
    R(0) = 76;
    R(5) = 0x12AC;
    R(4) = 0xF4;
    R(5) += R(14);
    R(3) = 0x100;
    F(6) = m32(ram, R(5) + R(0));
    R(5) += 80;
    R(4) += R(11);
    F(7) = m32(ram, R(5));
    F(4) = m32(ram, R(4));
    FSUB(5, 6);
    FSUB(4, 7);
    FSUB(5, 13);
    FSUB(4, 13);
    SET_T(GT(15, 5));
    R(13) |= R(3);                                     /* delay slot of the bf/s below */
    if (!GT(15, 5)) goto l6bae;
    SET_T(GT(15, 4));
    if (!GT(15, 4)) goto l6bae;
    R(3) = 0xFFFFFEFFu;
    R(13) &= R(3);
l6bae:
    R(4) = 0xE4;
    R(2) = 0x0C06911Cu;
    R(4) += R(11);
    F(4) = m32(ram, R(4));
    R(4) = 0xEC;
    R(4) += R(11);
    F(5) = m32(ram, R(4));
    R(4) = R(15);
    R(4) += 52;
    CALL(CLEAR_FN, 0x8C0C6BC2u);
    R(9) = 0xFFFFF000u;
    R(4) = R(0);
    TST(R(10), R(4));
    if (R(VF3_REG_SR) & 1u) goto l6c6c;
    R(3) = m32(ram, f + 4);
    TST(R(8), R(3));
    if (R(VF3_REG_SR) & 1u) goto l6c2c;
    R(5) = 0x0C11096Au;
    for (;;) {
        R(3) = m32(ram, f);
        R(4) = S8(R(5));
        R(5) += 1;
        SET_T(R(4) == R(3));
        if (R(4) == R(3)) goto l6c14;
        TST(R(4), R(4));
        if (R(VF3_REG_SR) & 1u) goto l6c2c;
    }
l6c14:
    R(1) = m32(ram, R(12) + 12);
    SET_T((int32_t)R(1) >= 0);
    if ((int32_t)R(1) < 0) goto l6c2c;
    R(0) = 16;
    F(3) = 0;
    F(2) = m32(ram, f + R(0));
    R(3) = 0x400;
    SET_T(GT(3, 2));
    R(13) |= R(3);                                     /* delay slot of the bf/s below */
    if (!GT(3, 2)) goto l6c2c;
    R(3) = 32;
    R(13) |= R(3);
l6c2c:
    R(0) = 0x22EC;
    R(2) = 2;
    R(13) |= R(2);
    F(4) = m32(ram, R(14) + R(0));
    R(0) += 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 48;
    w32(ram, f + R(0), F(3));
    ANGLE(0x8C0C6C44u);
    R(0) = 0x15F4;
    R(3) = 0x0C069624u;
    F(6) = m32(ram, R(14) + R(0));
    R(0) = 0x8C0C6CE8u;                                /* mova: 0.2f */
    F(5) = 0x3E4CCCCCu;
    FMOV(4, 0);
    FSUB(4, 6);
    CALL(DIFF_FN, 0x8C0C6C54u);
    R(2) = 0x1800;
    R(0) = (uint32_t)(int32_t)(int16_t)R(0);
    R(4) = (uint32_t)(int32_t)(int16_t)R(0);
    if ((int32_t)R(4) > (int32_t)R(2)) R(4) = R(2);
    else if ((int32_t)R(4) < (int32_t)R(9)) R(4) = R(9);
    R(0) = 0x22E8;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(4));
l6c6c:
    R(5) = 0x12AC;
    R(0) = 104;
    R(4) = 0x148;
    R(5) += R(14);
    R(3) = 0x200;
    F(5) = m32(ram, R(5) + R(0));
    R(0) = 20;
    R(4) += R(11);
    FMOV(3, 5);
    R(5) += 108;
    F(5) = m32(ram, f + R(0));
    F(4) = m32(ram, R(4));
    FSUB(5, 3);
    F(6) = m32(ram, R(5));
    FSUB(4, 6);
    FSUB(5, 13);
    FSUB(4, 13);
    SET_T(GT(14, 5));
    R(13) |= R(3);                                     /* delay slot of the bf/s below */
    if (!GT(14, 5)) goto l6c9c;
    SET_T(GT(14, 4));
    if (!GT(14, 4)) goto l6c9c;
    R(3) = 0xFFFFFDFFu;
    R(13) &= R(3);
l6c9c:
    R(4) = 0x138;
    R(2) = 0x0C06911Cu;
    R(4) += R(11);
    F(4) = m32(ram, R(4));
    R(4) = 0x140;
    R(4) += R(11);
    F(5) = m32(ram, R(4));
    R(4) = R(15);
    R(4) += 52;
    CALL(CLEAR_FN, 0x8C0C6CB0u);
    R(4) = R(0);
    TST(R(10), R(4));
    if (R(VF3_REG_SR) & 1u) goto l6d4e;
    R(3) = m32(ram, f + 4);
    TST(R(8), R(3));
    if (R(VF3_REG_SR) & 1u) goto l6d10;
    R(5) = 0x0C110976u;
    for (;;) {
        R(3) = m32(ram, f);
        R(4) = S8(R(5));
        R(5) += 1;
        SET_T(R(4) == R(3));
        if (R(4) == R(3)) goto l6cf8;
        TST(R(4), R(4));
        if (R(VF3_REG_SR) & 1u) goto l6d10;
    }
l6cf8:
    R(1) = m32(ram, R(12) + 12);
    SET_T((int32_t)R(1) >= 0);
    if ((int32_t)R(1) < 0) goto l6d10;
    R(0) = 16;
    F(3) = 0;
    F(2) = m32(ram, f + R(0));
    R(3) = 0x800;
    SET_T(GT(3, 2));
    R(13) |= R(3);                                     /* delay slot of the bf/s below */
    if (!GT(3, 2)) goto l6d10;
    R(3) = 32;
    R(13) |= R(3);
l6d10:
    R(0) = 0x22F8;
    R(13) |= R(10);
    F(4) = m32(ram, R(14) + R(0));
    R(0) += 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 36;
    w32(ram, f + R(0), F(3));
    ANGLE(0x8C0C6D26u);
    R(0) = 0x1610;
    R(3) = 0x0C069624u;
    F(6) = m32(ram, R(14) + R(0));
    R(0) = 0x8C0C6DE8u;                                /* mova: 0.2f */
    F(5) = 0x3E4CCCCCu;
    FMOV(4, 0);
    FSUB(4, 6);
    CALL(DIFF_FN, 0x8C0C6D36u);
    R(2) = 0x1800;
    R(0) = (uint32_t)(int32_t)(int16_t)R(0);
    R(4) = (uint32_t)(int32_t)(int16_t)R(0);
    if ((int32_t)R(4) > (int32_t)R(2)) R(4) = R(2);
    else if ((int32_t)R(4) < (int32_t)R(9)) R(4) = R(9);
    R(0) = 0x22EA;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(4));
l6d4e:
    R(4) = 6;
    R(4) &= R(13);
    R(0) = R(4);
    if (R(0) != 6) goto l6dfc;
    R(3) = 0x400;
    TST(R(13), R(3));
    if (!(R(VF3_REG_SR) & 1u)) goto l6d84;
    R(1) = 0x800;
    TST(R(13), R(1));
    if (!(R(VF3_REG_SR) & 1u)) goto l6d7a;
    R(3) = 32;
    TST(R(13), R(3));
    if (R(VF3_REG_SR) & 1u) goto l6d88;
    R(4) = 0x300;
    R(5) = R(4);
    R(5) &= R(13);
    SET_T(R(4) == R(5));
    if (R(4) == R(5)) goto l6d88;
    R(3) = 0x100;
    TST(R(13), R(3));
    if (R(VF3_REG_SR) & 1u) goto l6d7e;
l6d7a:
    FMOV(13, 15);
    goto l6e06;
l6d7e:
    R(2) = 0x200;
    TST(R(13), R(2));
    if (R(VF3_REG_SR) & 1u) goto l6d88;
l6d84:
    FMOV(13, 14);
    goto l6e06;
l6d88:
    R(0) = 0x1A04;
    R(5) = m32(ram, R(14));
    R(4) = m32(ram, R(14) + R(0));
    R(0) = 0x8C0C6DF0u;                                /* mova: 0.15f */
    TST(R(8), R(5));
    F(4) = 0x3E199999u;                                /* delay slot of the bt/s */
    if (R(VF3_REG_SR) & 1u) goto l6da2;
    TST(R(8), R(4));
    R(0) = 0x8C0C6DF4u;                                /* mova: 0.5f */
    F(4) = 0x3F000000u;                                /* delay slot of the bf/s */
    if (!(R(VF3_REG_SR) & 1u)) goto l6daa;
    R(0) = 0x8C0C6DF8u;                                /* mova: 0.6f */
    F(4) = 0x3F199999u;
l6da2:
    R(0) = 97;
    R(0) = U8(R(14) + R(0));
    SET_T(R(0) == 1);
l6daa:
    FMOV(5, 12);
l6dac:
    F(3) = 0;
    SET_T(GT(5, 3));
    if (GT(5, 3)) { F(3) = 0; FMOV(6, 15); } else { F(3) = 0; FMOV(6, 14); }
    SET_T(GT(5, 3));
    if (GT(5, 3)) FMOV(5, 14); else FMOV(5, 15);
    FSUB(5, 6);
    FMOV(0, 4);
    FMAC(6, 5);
    FMOV(13, 6);
    goto l6e06;

l6dfc:
    R(2) = 2;
    TST(R(13), R(2));
    if (!(R(VF3_REG_SR) & 1u)) FMOV(13, 14); else FMOV(13, 15);

l6e06:
    R(0) = 20;
    FMOV(4, 13);
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 72;
    R(4) = m32(ram, R(14) + R(0));
    R(0) = 76;
    FSUB(4, 3);
    R(5) = m32(ram, R(14) + R(0));
    R(3) = R(4);
    TST(R(10), R(3));
    R(0) = 0x8C0C6EF8u;                                /* mova: 0.1f */
    F(5) = 0x3DCCCCCCu;                                /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto l6e32;
    R(2) = 0x00040000u;
    TST(R(2), R(5));
    if (!(R(VF3_REG_SR) & 1u)) goto l6e32;
    TST(R(8), R(4));
    R(0) = 0x8C0C6F00u;                                /* mova: 0.05f */
    F(5) = 0x3D4CCCCCu;                                /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto l6e32;
    R(0) = 0x8C0C6F04u;                                /* mova: 0.02f */
    F(5) = 0x3CA3D70Au;
l6e32:
    SET_T(GT(5, 4));
    FMOV(6, 5);
    F(6) ^= SIGN;                                      /* delay slot of the bt/s */
    if (GT(5, 4)) {
        FMOV(4, 5);
    } else {
        SET_T(GT(4, 6));
        if (GT(4, 6)) FMOV(4, 6);
    }
    R(0) = 0x13A8;
    TST(R(13), R(13));
    F(5) = 0;
    w32(ram, R(14) + R(0), F(5));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(4));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(5));                      /* delay slot of the bf/s below */
    if (R(13) != 0) goto exit_;
    R(0) = 0x13AC;
    w32(ram, R(14) + R(0), F(5));

exit_:
    R(15) = f + 64;
    R(0) = 0x1FDD;
    vf3_mem_set_u8(ram, R(14) + R(0), (uint8_t)R(13));
    F(12) = saved_fr[3];
    F(13) = saved_fr[2];
    F(14) = saved_fr[1];
    F(15) = saved_fr[0];
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3];
    R(10) = saved[4]; R(9) = saved[5]; R(8) = saved[6];
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
