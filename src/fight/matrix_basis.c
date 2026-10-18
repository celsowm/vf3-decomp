/* matrix_basis.c - 0x8C09E4C8  build the camera basis of a record from its two angle shorts and publish the
 * resulting axis vectors.
 *
 * r4 = record (r14), r5 = destination block (r13). In order:
 *   1. 0x0C09D480 on record+0x1F86, then 0x0C03C940 rotates by the angle table entry 0x0C10DAEA[byte +0x61],
 *      0x0C03C880 by the short at +0x22BC and 0x0C03C940 again by minus the short at +0x22BE.
 *   2. 0x0C03B620 extracts the 3x3 result at f+12 .. f+34; its rows go to dest+0x10 .. 0x18 and dest+0x20 .. 0x28
 *      (the first row is kept at f+0, the last at f+0x1C / 0x20 / 0x24 negated) and 0x0C03B530 copies the block to
 *      record+0x440.
 *   3. record+0x22C0 .. 0x22C8 = f[+60 ..] + 0.25 * row0, then the 0.1 / 0.2 pair at f+88 / f+96 is rotated through
 *      0x0C03C4F0 / 0x0C03B450 / 0x0C03C4A0 to give the vectors at record+0x22CC .. 0x22D4 and +0x22D8; the sign of
 *      f+96 is flipped and the rotation is repeated for +0x22DC .. +0x22E0.
 *
 * The routine mirrors the original's registers and frame (f = sp - 112): f+0 .. +8 row 0, f+C .. +14 matrix rows,
 * f+1C .. +24 negated axis, f+2C .. +34 the 0x0C03B620 output, f+4C .. +54 rotation result, f+58 .. +60 inputs. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define S16(a)      ((uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, (a)))
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))
#define SIGN        0x80000000u
#define LDF(fr, off)  (F(fr) = m32(ram, f + (off)))
#define STF(fr, off)  w32(ram, f + (off), F(fr))

int vf3_matrix_basis_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 112, saved14 = R(14), saved13 = R(13);
    w32(ram, sp0 - 4, saved14);
    w32(ram, sp0 - 8, saved13);
    w32(ram, sp0 - 12, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(14) = R(4);
    R(13) = R(5);
    R(15) = f;
    R(4) = 0x1F86u + R(14);
    R(3) = 0x0C09D480u;
    CALL(0x0C09D480u, 0x8C09E4DCu);

    R(0) = 97;
    R(3) = 0x0C03C940u;
    R(4) = S8(R(14) + R(0));
    R(0) = 0x0C10DAEAu;
    R(4) &= 0xFFu;
    R(4) <<= 1;
    R(4) = S16(R(0) + R(4));
    CALL(0x0C03C940u, 0x8C09E4ECu);

    R(3) = 0x0C03C880u;
    R(0) = 0x22BCu;
    R(4) = S16(R(14) + R(0));
    CALL(0x0C03C880u, 0x8C09E4F4u);

    R(0) = 0x22BEu;
    R(3) = 0x0C03C940u;
    R(4) = S16(R(14) + R(0));
    R(4) = 0u - R(4);
    CALL(0x0C03C940u, 0x8C09E4FEu);

    R(2) = 0x0C03B620u;
    R(4) = f + 12;
    CALL(0x0C03B620u, 0x8C09E506u);

    R(0) = 12;
    R(4) = f;
    LDF(3, 12); R(0) = 16; w32(ram, R(13) + R(0), F(3));
    LDF(3, 16); R(0) = 20; w32(ram, R(13) + R(0), F(3));
    LDF(3, 20); R(0) = 24; w32(ram, R(13) + R(0), F(3));
    LDF(3, 12); R(0) = 16; w32(ram, R(4), F(3));
    LDF(3, 16); R(0) = 4;  w32(ram, R(4) + R(0), F(3));
    LDF(3, 20); R(0) = 8;  w32(ram, R(4) + R(0), F(3));
    LDF(3, 44); R(0) = 32; w32(ram, R(13) + R(0), F(3));
    LDF(3, 48); R(0) = 36; w32(ram, R(13) + R(0), F(3));
    LDF(3, 52); R(0) = 40; w32(ram, R(13) + R(0), F(3));
    LDF(3, 28); R(0) = 12; F(3) ^= SIGN; STF(3, 12);
    LDF(3, 32); R(0) = 16; F(3) ^= SIGN; STF(3, 16);
    LDF(3, 36); R(0) = 20; F(3) ^= SIGN; STF(3, 20);
    LDF(3, 12); R(0) = 16; w32(ram, R(13), F(3));
    LDF(3, 16); R(0) = 4;  w32(ram, R(13) + R(0), F(3));
    LDF(3, 20); R(0) = 8;  w32(ram, R(13) + R(0), F(3));
    R(0) = 28; F(3) = m32(ram, R(4)); STF(3, 28);
    R(0) = 4;  F(3) = m32(ram, R(4) + R(0));
    R(0) = 32; R(5) = R(13); STF(3, 32);
    R(0) = 8;  F(3) = m32(ram, R(4) + R(0));
    R(0) = 36; STF(3, 36);
    R(4) = 0x0440u + R(14);
    R(3) = 0x0C03B530u;
    CALL(0x0C03B530u, 0x8C09E5A2u);

    R(0) = 0x8C09E67Cu;
    F(4) = 0x3E800000u;                                /* 0.25f */
    R(0) = 60; LDF(3, 60);
    R(0) = 12; LDF(2, 12);
    FMOV(0, 4);
    FMAC(3, 2);
    R(0) = 0x22C0u; w32(ram, R(14) + R(0), F(3));
    R(0) = 64; LDF(3, 64);
    R(0) = 16; LDF(2, 16);
    R(0) = 0x22C4u;
    FMAC(3, 2);
    w32(ram, R(14) + R(0), F(3));
    R(0) = 68; LDF(3, 68);
    R(0) = 20; LDF(2, 20);
    R(0) = 0x22C8u;
    FMAC(3, 2);
    w32(ram, R(14) + R(0), F(3));
    R(0) = 0x8C09E680u;
    F(3) = 0x3DCCCCCCu;                                /* 0.1f */
    R(0) = 88; STF(3, 88);
    R(0) = 92; F(3) = 0; STF(3, 92);
    R(0) = 0x8C09E684u;
    F(3) = 0x3E4CCCCCu;                                /* 0.2f */
    R(0) = 96;
    R(4) = f;
    STF(3, 96);
    R(3) = 0x0C03BD80u;
    R(4) += 12;
    CALL(0x0C03BD80u, 0x8C09E5F0u);

    R(2) = 0x0C03C4F0u; R(4) = 0; CALL(0x0C03C4F0u, 0x8C09E5F6u);
    R(3) = 0x0C03B450u; R(5) = f + 76; R(4) = f + 88; CALL(0x0C03B450u, 0x8C09E602u);
    R(2) = 0x0C03C4A0u; R(4) = 1; CALL(0x0C03C4A0u, 0x8C09E608u);
    R(0) = 76; LDF(3, 76); R(0) = 0x22CCu; w32(ram, R(14) + R(0), F(3));
    R(0) = 80; LDF(3, 80); R(0) = 0x22D0u; w32(ram, R(14) + R(0), F(3));
    R(0) = 84; LDF(3, 84); R(0) = 0x22D4u; w32(ram, R(14) + R(0), F(3));
    R(0) = 96; LDF(3, 96); R(0) = 96; F(3) ^= SIGN; STF(3, 96);

    R(3) = 0x0C03C4F0u; R(4) = 0; CALL(0x0C03C4F0u, 0x8C09E630u);
    R(2) = 0x0C03B450u; R(5) = f + 76; R(4) = f + 88; CALL(0x0C03B450u, 0x8C09E63Cu);
    R(3) = 0x0C03C4A0u; R(4) = 1; CALL(0x0C03C4A0u, 0x8C09E642u);
    R(0) = 76; LDF(3, 76); R(0) = 0x22D8u; w32(ram, R(14) + R(0), F(3));

    R(0) = 80; LDF(3, 80); R(0) = 0x22DCu; w32(ram, R(14) + R(0), F(3));
    R(0) = 84; LDF(3, 84);
    R(0) = 0x22E0u; w32(ram, R(14) + R(0), F(3));
    R(13) = saved13;
    R(14) = saved14;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
