/* facing_update.c - 0x8C09DCDC  turn a character's heading and pitch toward a target direction and refresh its
 * orientation matrix.
 *
 *   r4 -> the character (flags at +0, kind bytes at +4 / +0x61, kind halfword at +0x3C, position at +0x1FC8 ..
 *   +0x1FD0, heading at +0x1FD4, pitch at +0x1FD8, +0x1F14 / +0x1F18 / +0x1F1C the anchor, +0xC0 the blend
 *   weight), r5 -> the target point.
 *
 *   Phase 1: the anchor is parked in the frame. Unless the 0x400 flag is set (it is cleared instead) or the
 *   0x100 flag is, the position at +0x1FC8 is moved: when the mask 0x88836020 hits +0x48 the offset at +0x2308 is
 *   added to its y, otherwise it becomes 3.0 * 0.25-weighted fmac of the part table's point and the position.
 *   The result goes back to +0x1FC8 .. +0x1FD0.
 *
 *   Phase 2: the offset vector at frame +0x34 is blended with the frame matrix (fmac with the blend weight), the
 *   direction (dx, dz) it yields at frame +0xA8 / +0xAC is turned into a heading by 0x8C069624; the delta against
 *   the current heading (+0x1FD4) is clamped (+-0x300 for ordinary characters; kinds 0x886 / 0x88D are limited
 *   around 0xC000 instead) and added in. The pitch (+0x1FD8) follows from the length (sqrt of dx*dx + dz*dz, 0
 *   below the epsilon at 0x8C09DF90), a per-kind table bias and a clamp of +-0x100 (+-0x800 / 0x1000 for the
 *   special kinds). The new angles go through 0x8C03C940 / 0x8C03C880, the matrix is rebuilt (0x8C09D4E6) and
 *   committed to the character (+0x1C0 through 0x8C03B530).
 *
 *   Frame: r14..r10, fr15, pr pushed (28 bytes), then 0xC0 bytes of locals. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 220, KIND_CELL = 0x0C29BB84u, MASK_FLAGS = 0x88836020u,
       FLAG_400 = 0x400u, FLAG_100 = 0x100u, SZ_BIT = 0x00100000u, PR_BIT = 0x00080000u,
       HEADING = 0x1FD4u, PITCH = 0x1FD8u, TURN_TABLE = 0x0C10DAD0u,
       CONST_A = 0x0C09DEC4u, CONST_B = 0x0C09DEC8u, EPSILON = 0x0C09DF90u };

#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define L(off)      (f + (uint32_t)(off))

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

static uint32_t clamp_s(uint32_t v, int32_t lo, int32_t hi)
{
    int32_t x = (int32_t)v;
    if (x > hi) x = hi;
    if (x < lo) x = lo;
    return (uint32_t)x;
}

int vf3_facing_update_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & (SZ_BIT | PR_BIT))) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED;
    const uint32_t saved_r[5] = { R(14), R(13), R(12), R(11), R(10) };
    const uint32_t saved_f15 = F(15);
    static const int pushed[5] = { 14, 13, 12, 11, 10 };

    R(14) = R(4);
    for (int i = 0; i < 5; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 24, saved_f15);
    w32(ram, sp0 - 28, pr0);
    R(15) = f;
    w32(ram, L(0), R(5));

    const uint32_t obj = R(14);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, obj + 4);
    R(4) = KIND_CELL;
    R(11) = m32(ram, KIND_CELL + (R(0) != 0 ? 16u : 20u));
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C09DD06u);
    CALL(0x8C03CCB0u, 0x8C09DD0Cu);
    R(4) = f + 68;
    CALL(0x8C03B620u, 0x8C09DD14u);
    R(4) = 1;
    CALL(0x8C03C4A0u, 0x8C09DD1Au);

    /* phase 1: the mixed position */
    R(4) = f + 0x84;
    F(3) = m32(ram, obj + 0x1F14); w32(ram, R(4), F(3));
    F(3) = m32(ram, obj + 0x1F18); w32(ram, R(4) + 4, F(3));
    F(3) = m32(ram, obj + 0x1F1C); w32(ram, R(4) + 8, F(3));
    R(3) = FLAG_400;
    R(10) = FLAG_100;
    R(12) = m32(ram, obj) & R(3);
    if (R(12) != 0) {
        R(1) = m32(ram, obj) & 0xFFFFFBFFu;
        w32(ram, obj, R(1));
    } else if ((m32(ram, obj) & R(10)) == 0) {
        R(6) = MASK_FLAGS;
        R(5) = m32(ram, obj + 72);
        R(13) = R(6) & R(5);
        if (R(13) != 0) {
            R(1) = 0x2308u + obj;
            F(2) = m32(ram, R(4) + 4);
            F(3) = m32(ram, R(1));
            FADD(2, 3);
            w32(ram, R(4) + 4, F(2));
        } else {
            R(6) = 0x9Cu + f;
            F(3) = m32(ram, R(11) + 0x1F0); w32(ram, R(6), F(3));
            F(3) = m32(ram, R(11) + 0x1F4); w32(ram, R(6) + 4, F(3));
            F(3) = m32(ram, R(11) + 0x1F8); w32(ram, R(6) + 8, F(3));
            R(5) = 0x90u + f;
            F(3) = m32(ram, obj + 0x1FC8); w32(ram, R(5), F(3));
            F(3) = m32(ram, obj + 0x1FCC); w32(ram, R(5) + 4, F(3));
            F(3) = m32(ram, obj + 0x1FD0); w32(ram, R(5) + 8, F(3));
            F(5) = m32(ram, CONST_A);
            F(4) = m32(ram, CONST_B);
            for (uint32_t i = 0; i < 12; i += 4) {
                F(3) = m32(ram, R(6) + i);
                F(0) = F(4);
                F(2) = m32(ram, R(5) + i);
                FMAC(3, 2);
                FMUL(3, 5);
                w32(ram, R(4) + i, F(3));
            }
            R(0) = 8;
        }
    }
    F(3) = m32(ram, R(4));     w32(ram, obj + 0x1FC8, F(3));
    F(3) = m32(ram, R(4) + 4); w32(ram, obj + 0x1FCC, F(3));
    F(3) = m32(ram, R(4) + 8); w32(ram, obj + 0x1FD0, F(3));

    /* phase 2: the offset vector through the frame's matrix */
    R(4) = f;
    F(15) = m32(ram, obj + 0xC0);
    R(4) += 4;
    CALL(0x8C03B620u, 0x8C09DE22u);
    F(0) = F(15);
    for (uint32_t i = 0; i < 12; i += 4) {
        F(3) = m32(ram, f + 52 + i);
        F(2) = m32(ram, f + 4 + i);
        FMAC(3, 2);
        w32(ram, f + 116 + i, F(3));
    }
    R(0) = 124;
    R(3) = m32(ram, L(0));
    F(6) = 0;
    F(4) = m32(ram, R(3));
    F(5) = 0;
    CALL(0x8C03CC60u, 0x8C09DE5Au);
    R(4) = obj + 0x1F5C;
    CALL(0x8C09D480u, 0x8C09DE60u);
    F(3) = m32(ram, obj + 0x1FC8); w32(ram, L(0xB4), F(3));
    F(3) = m32(ram, obj + 0x1FCC); w32(ram, L(0xB8), F(3));
    F(3) = m32(ram, obj + 0x1FD0); w32(ram, L(0xBC), F(3));
    R(5) = L(0xA8);
    R(4) = L(0xB4);
    CALL(0x8C09DBC0u, 0x8C09DE82u);

    R(0) = 60;
    R(4) = vf3_mem_u16(ram, obj + 60);
    R(1) = 0x886u;
    R(11) = (R(4) == 0x886u || R(4) == 0x88Du) ? 0 : 1;
    const int special = (R(11) == 0);

    R(0) = 0xA8;
    F(5) = m32(ram, L(0xA8));
    R(0) = 0xAC;
    F(4) = m32(ram, L(0xAC));
    CALL(0x8C069624u, 0x8C09DEE2u);
    R(4) = sext16(R(0));

    if (!special) {
        if (R(13) != 0) {
            R(0) = vf3_mem_u16(ram, obj + 60);
            if (R(0) == 72 && ((int32_t)R(4) < 0 || (int32_t)R(4) > 0x8000)) R(4) = 0x4000;
        }
        R(6) = 0xC000u;
        R(0) = vf3_mem_u8(ram, obj + 97);
        R(4) = sext16(R(4) + R(6));
        R(5) = (R(0) == 12) ? 0x2800u : 0x3800u;
        if ((int32_t)R(4) > (int32_t)R(5)) R(4) = R(5);
        R(5) = (uint32_t)(0 - R(5));
        if (!((int32_t)R(4) >= (int32_t)R(5))) R(4) = R(5);
        R(4) -= R(6);
    }
    R(0) = HEADING;
    R(3) = m32(ram, obj + HEADING);
    R(4) = sext16(R(4) - R(3));
    if (R(12) == 0 && R(13) == 0) R(4) = clamp_s(R(4), -0x300, 0x300);
    R(3) = m32(ram, obj + HEADING);
    R(4) += R(3);
    w32(ram, obj + HEADING, R(4));

    R(0) = 0xA8;
    F(5) = m32(ram, L(0xA8));
    R(0) = 0xAC;
    F(0) = F(5);
    F(4) = m32(ram, L(0xAC));
    F(2) = m32(ram, EPSILON);
    F(3) = F(4);
    FMUL(3, 4);
    FMAC(3, 5);
    F(4) = F(3);
    if (GT(4, 2)) {
        F(5) = 0;
    } else {
        F(5) = F(4);
        F(5) = vf3_fpu_sqrt(F(5), R(VF3_REG_FPSCR));
    }
    R(0) = 0xB0;
    F(4) = m32(ram, L(0xB0));
    CALL(0x8C069624u, 0x8C09DFA0u);
    R(0) = sext16(R(0));
    R(5) = (uint32_t)(0 - R(0));
    if (R(12) == 0 && R(13) == 0) {
        R(0) = 97;
        R(4) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, obj + 97);
        R(0) = TURN_TABLE;
        R(4) = (R(4) & 0xFFu) << 1;
        R(4) = sext16(vf3_mem_u16(ram, R(0) + R(4)));
        R(4) &= 0xFFFFu;
        R(5) += R(4);
    }
    R(0) = PITCH;
    R(4) = m32(ram, obj + PITCH);
    R(5) -= R(4);
    if (R(12) == 0 && R(13) == 0) R(5) = clamp_s(R(5), -0x100, 0x100);
    R(4) += R(5);
    if (!special) {
        R(0) = vf3_mem_u8(ram, obj + 97);
        R(5) = (R(0) == 12) ? 0x800u : 0x1000u;
        if ((int32_t)R(4) > (int32_t)R(5)) R(4) = R(5);
        R(5) = sext16(0xE000u);
        if (!((int32_t)R(4) >= (int32_t)R(5))) R(4) = R(5);
    }
    R(0) = PITCH;
    w32(ram, obj + PITCH, R(4));
    R(0) = HEADING;
    R(4) = m32(ram, obj + HEADING);
    CALL(0x8C03C940u, 0x8C09E00Cu);
    R(0) = PITCH;
    R(4) = m32(ram, obj + PITCH);
    CALL(0x8C03C880u, 0x8C09E014u);
    R(4) = f + 68;
    CALL(0x8C09D4E6u, 0x8C09E01Au);
    R(3) = 0x0C03B530u;
    R(4) = 0x1C0u + obj;
    R(5) = f + 68;
    CALL(0x8C03B530u, 0x8C09E026u);

    R(1) = 0xC0;
    for (int i = 0; i < 5; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f15;
    R(VF3_REG_PR) = pr0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
