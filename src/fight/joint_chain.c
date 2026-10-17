/* joint_chain.c - 0x8C091C20  pose a five-link joint chain: for each link, compose its rotations onto the
 * matrix stack and draw it.
 *
 *   r4 = (unused), r5 -> the pose record (+0x68 the angle table, five 10-byte entries of five halfwords,
 *   +0xA4 / +0xA8 the two pointers of the part table), r6 = the argument 0x8C03BD80 is called with,
 *   r7 = mirror flag (0 mirrors the link: its angles are negated and the offset's z flips twice).
 *
 *   Set-up: 0x8C03BD80(r6), 0x8C03C4F0(0), 0x8C03C610() when not mirrored, 0x8C03C4A0(1), then the first
 *   halfword of the part table's header goes to 0x8C0A7662 and 0x8C03C4F0(0) is called again.
 *
 *   Link loop (5 rounds, round counter at sp+0): the five angle halfwords are copied to the frame (sp+8, +28,
 *   +12, +4, +16), the link's offset (fr4 / fr5 / fr6 from the first pointer, fr13 / fr14 from the second) is
 *   loaded, and from the second link on 0x8C03CC60 pushes the offset. The rotations then run as angle pairs:
 *   0x8C03C940 / 0x8C03C6C0 / 0x8C03C880 with the first three angles, 0x8C0A7662 draws with the fourth,
 *   0x8C03CC60 / 0x8C03C880 move by the second offset, and so on. At the end of the round XMTRX is reloaded
 *   from the matrix stack entry [[0x8C19D2E4] + 8] - 64 (through FRCHG; the tail of the round only moves 16
 *   floats into the shadow bank).
 *
 *   Exit: pops the frame and jumps to 0x8C03C4A0(1) with the caller's pr. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 76, ANGLES = 104, PARTS = 0x00A4, MATRIX_CELL = 0x0C19D2E4u, ROUNDS = 5, ENTRY_BYTES = 10,
       SZ_BIT = 0x00100000u, PR_BIT = 0x00080000u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define LOCAL(off)  (f + (uint32_t)(off))

static uint32_t sext16(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

static void put16(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    vf3_mem_set_u16(ram, addr, (uint16_t)v);
}

int vf3_joint_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & (SZ_BIT | PR_BIT))) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[3] = { F(15), F(14), F(13) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 3; ++i) w32(ram, sp0 - 32u - 4u * (uint32_t)i, saved_f[i]);
    w32(ram, sp0 - 44, pr0);
    R(15) = f;
    R(13) = R(5) + ANGLES;
    R(11) = R(7);
    w32(ram, LOCAL(20), R(6));

    R(0) = PARTS;
    R(12) = m32(ram, R(0) + R(5));
    R(0) += 4;
    R(4) = m32(ram, R(0) + R(5));
    R(3) = sext16(ram, R(12));
    R(9) = R(4) + 60;
    put16(ram, LOCAL(0), R(3));
    R(10) = R(4);
    R(4) = m32(ram, LOCAL(20));
    CALL(0x8C03BD80u, 0x8C091C58u);
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C091C5Eu);
    SET_T(R(11) == 0);
    if (R(11) == 0) CALL(0x8C03C610u, 0x8C091C68u);
    R(4) = 1;
    CALL(0x8C03C4A0u, 0x8C091C6Eu);
    R(4) = vf3_mem_u16(ram, LOCAL(0));
    R(8) = 0x0C0A7662u;
    CALL(0x8C0A7662u, 0x8C091C76u);
    R(14) = R(12) + 2;
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C091C80u);
    R(2) = 0;
    w32(ram, LOCAL(0), R(2));
    R(3) = MATRIX_CELL;
    F(15) = 0;
    w32(ram, LOCAL(20), R(3));

    for (;;) {
        R(0) = sext16(ram, R(13));
        SET_T(R(11) == 0);
        put16(ram, LOCAL(8), R(0));
        R(0) = sext16(ram, R(13) + 2);  put16(ram, LOCAL(28), R(0));
        R(0) = sext16(ram, R(13) + 4);  put16(ram, LOCAL(12), R(0));
        R(0) = sext16(ram, R(13) + 6);  put16(ram, LOCAL(4), R(0));
        R(0) = sext16(ram, R(13) + 8);  put16(ram, LOCAL(16), R(0));
        F(4) = m32(ram, R(10)); R(10) += 4;
        F(13) = m32(ram, R(9)); R(9) += 4;
        F(5) = m32(ram, R(10)); R(10) += 4;
        F(6) = m32(ram, R(10)); R(10) += 4;
        F(14) = m32(ram, R(9)); R(9) += 4;                  /* bf/s delay slot */
        if (R(11) == 0) {                                   /* mirrored link */
            static const int slots[4] = { 8, 12, 4, 16 };
            for (int i = 0; i < 4; ++i) {
                R(0) = sext16(ram, LOCAL(slots[i]));
                R(0) = (uint32_t)(0 - R(0));
                put16(ram, LOCAL(slots[i]), R(0));
            }
            F(6) ^= SIGN;
        }
        R(3) = m32(ram, LOCAL(0));
        SET_T(R(3) == 0);
        F(6) ^= SIGN;                                       /* bt/s delay slot */
        if (R(3) != 0) CALL(0x8C03CC60u, 0x8C091CD4u);

        R(0) = sext16(ram, R(14)); R(14) += 2;
        put16(ram, LOCAL(24), R(0));
        R(0) = sext16(ram, LOCAL(28)); R(4) = R(0);
        CALL(0x8C03C940u, 0x8C091CE0u);
        R(0) = sext16(ram, LOCAL(8)); R(4) = R(0);
        CALL(0x8C03C6C0u, 0x8C091CE8u);
        R(0) = sext16(ram, LOCAL(12)); R(4) = R(0);
        CALL(0x8C03C880u, 0x8C091CF0u);
        R(0) = sext16(ram, LOCAL(24)); R(4) = R(0) & 0xFFFFu;
        CALL(0x8C0A7662u, 0x8C091CF8u);

        R(0) = sext16(ram, R(14)); R(14) += 2;
        put16(ram, LOCAL(8), R(0));
        F(5) = F(15);
        F(6) = F(15);
        F(4) = F(13);
        CALL(0x8C03CC60u, 0x8C091D06u);
        R(0) = sext16(ram, LOCAL(4)); R(4) = R(0);
        CALL(0x8C03C880u, 0x8C091D0Eu);
        R(0) = sext16(ram, LOCAL(8)); R(4) = R(0) & 0xFFFFu;
        CALL(0x8C0A7662u, 0x8C091D16u);

        R(0) = sext16(ram, R(14)); R(14) += 2;
        put16(ram, LOCAL(4), R(0));
        F(5) = F(15);
        F(6) = F(15);
        F(4) = F(14);
        CALL(0x8C03CC60u, 0x8C091D24u);
        R(0) = sext16(ram, LOCAL(16)); R(4) = R(0);
        CALL(0x8C03C880u, 0x8C091D2Cu);
        R(0) = sext16(ram, LOCAL(4)); R(4) = R(0) & 0xFFFFu;
        CALL(0x8C0A7662u, 0x8C091D34u);

        R(4) = m32(ram, LOCAL(20));
        R(3) = m32(ram, LOCAL(0));
        R(2) = ROUNDS;
        R(4) = m32(ram, R(4) + 8);
        R(13) += ENTRY_BYTES;
        R(3) += 1;
        R(4) -= 64;
        SET_T((int32_t)R(3) >= (int32_t)R(2));
        for (int i = 0; i < 16; ++i) s->v[VF3_REG_XF0 + i] = m32(ram, R(4) + 4u * (uint32_t)i);
        R(4) += 64;
        w32(ram, LOCAL(0), R(3));
        if (R(VF3_REG_SR) & 1u) break;
    }

    R(3) = 0x0C03C4A0u;
    R(VF3_REG_PR) = pr0;
    R(4) = 1;
    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
