/* ring_probe.c - 0x8C0CA6C6  per-frame summary of the 13 ring points around a fighter: the centroid offset at
 * +0x224C .. +0x2254 and the per-point clearance codes at +0x185C.
 *
 * r4 = fighter record (r14). 0x8C06911C is called on the floats at +0x430 / +0x438; it fills f+4 .. f+C with a
 * triple (stored as fr15 / fr13 / fr14, y negated) and returns a word that goes to +0x1890. The low nibble of the
 * global byte 0x0C29B880 selects the mode:
 *   15          : every one of the 13 point indices in the byte list at 0x0C0EA1B0 gets a code 0x4000 or 0x4004 at
 *                 +0x185C[index], 0x4000 when (x*x + z*z) of the point at the list pointer +0x138C and its mirror
 *                 exceeds 64.0, else 0x4004; the triple is left unscaled.
 *   4 or 1      : the 7 indices of the list at 0x0C0EA1DA are summed (via 0x8C06911C per point) into the triple and
 *                 scaled by 0.125; the codes returned by the callee go to +0x185C[index].
 *   otherwise   : the 13 indices of 0x0C0EA1B0 are summed the same way and scaled by 0.0714285746.
 * Finally the triple goes to +0x224C / +0x2250 / +0x2254 and the frame is torn down.
 *
 * The routine mirrors the original's registers and stack slots. Frame (f = sp - 64): f+0 list cursor, f+4 .. f+C the
 * 0x8C06911C output triple. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))
#define SIGN        0x80000000u
#define CLEAR_FN    0x0C06911Cu

int vf3_ring_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 64;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_fr[4] = { F(15), F(14), F(13), F(12) };
    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 32 - 4u * (uint32_t)i, saved_fr[i]);
    w32(ram, sp0 - 48, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);

    R(14) = R(4);
    R(0) = 0x0438;
    R(11) = CLEAR_FN;
    R(15) = f;
    F(5) = m32(ram, R(14) + R(0));
    R(4) = f;
    R(0) -= 8;
    R(4) += 4;
    F(4) = m32(ram, R(14) + R(0));                     /* delay slot of the jsr */
    CALL(CLEAR_FN, 0x8C0CA6F2u);
    R(4) = R(0);
    R(0) = 0x1890;
    w32(ram, R(14) + R(0), R(4));
    R(0) = 4;  F(15) = m32(ram, f + R(0));
    R(0) = 8;  F(13) = m32(ram, f + R(0));
    R(0) = 12;
    R(3) = 0x0C29B880u;
    R(4) = 15;
    F(14) = m32(ram, f + R(0));
    R(0) = vf3_mem_u8(ram, R(3));
    R(5) = 0x0C0EA1B0u;
    F(14) ^= SIGN;
    R(4) &= R(0);
    R(0) = R(4);
    SET_T(R(0) == 15);
    R(6) = 13;                                         /* delay slot of the bt/s */
    if (R(VF3_REG_SR) & 1u) goto probe_mode;

    R(0) = 0x138C;
    R(9) = 0x185C;
    R(7) = m32(ram, R(14) + R(0));
    R(0) = R(4);
    SET_T(R(0) == 4);
    R(10) = R(7);
    R(8) = R(7);
    R(10) += 8;
    R(9) += R(14);                                     /* delay slot of the bt/s */
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = R(4);
        SET_T(R(0) == 1);
        if (!(R(VF3_REG_SR) & 1u)) goto wide;
    }
    R(3) = 0x0C0EA1DAu;
    R(0) = 0x8C0CA7D0u;
    R(13) = 7;
    w32(ram, f, R(3));
    F(4) = 0x3E000000u;                                /* 0.125f */
    goto start_sum;
wide:
    R(0) = 0x8C0CA7D4u;
    R(13) = R(6);
    w32(ram, f, R(5));
    F(4) = 0x3D924924u;                                /* 1/14 */
start_sum:
    FMOV(12, 4);
    while (R(13) != 0) {
        R(12) = m32(ram, f);
        R(12) += 1;
        w32(ram, f, R(12));
        R(12) -= 1;
        R(12) = S8(R(12));
        R(5) = R(12) << 1;
        R(3) = R(12);
        R(5) += R(3);
        R(5) <<= 2;
        R(0) = R(5);
        F(4) = m32(ram, R(8) + R(0));
        F(5) = m32(ram, R(10) + R(0));
        R(4) = R(5);
        R(4) = f;
        R(4) += 4;
        CALL(CLEAR_FN, 0x8C0CA76Eu);
        R(4) = R(0);
        R(0) = 4;  F(3) = m32(ram, f + R(0));
        R(0) = 8;
        R(13) -= 1;
        FADD(15, 3);
        F(3) = m32(ram, f + R(0));
        R(0) = 12;
        FADD(13, 3);
        F(3) = m32(ram, f + R(0));
        R(0) = R(12);
        R(0) <<= 2;
        FSUB(14, 3);
        w32(ram, R(9) + R(0), R(4));
    }
    FMUL(13, 12);
    FMUL(15, 12);
    FMUL(14, 12);
    goto finish;

probe_mode:
    R(0) = 0x138C;
    R(10) = R(5);
    R(9) = 0x185C;
    R(4) = m32(ram, R(14) + R(0));
    R(0) = 0x8C0CA7D8u;
    R(11) = 0x4004;
    R(9) += R(14);
    R(8) = R(4);
    F(6) = 0x42800000u;                                /* 64.0f */
    R(8) += 8;
    R(7) = R(11);
    R(13) = R(4);
    R(7) -= 4;
    while (R(6) != 0) {
        R(5) = S8(R(10));
        R(10) += 1;
        R(4) = R(5) << 1;
        R(3) = R(5);
        R(4) += R(3);
        R(4) <<= 2;
        R(0) = R(4);
        F(4) = m32(ram, R(13) + R(0));
        F(5) = m32(ram, R(8) + R(0));
        R(12) = R(4);
        FMOV(7, 4);
        FMUL(7, 4);
        FMOV(0, 5);
        FMOV(4, 6);
        FMAC(7, 5);
        FMOV(5, 7);
        SET_T(GT(4, 5));
        R(4) = R(7);                                   /* delay slot of the bt/s */
        if (!(R(VF3_REG_SR) & 1u)) R(4) = R(11);
        R(0) = R(5);
        R(0) <<= 2;
        R(6) -= 1;
        w32(ram, R(9) + R(0), R(4));
    }

finish:
    R(0) = 0x224C;
    w32(ram, R(14) + R(0), F(15));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(13));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(14));
    F(12) = saved_fr[3];
    F(13) = saved_fr[2];
    F(14) = saved_fr[1];
    F(15) = saved_fr[0];
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3];
    R(10) = saved[4]; R(9) = saved[5]; R(8) = saved[6];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
