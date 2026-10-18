/* wall_flags.c - 0x8C0CAB30  classify a fighter's contact with the ring boundary into three direction masks.
 *
 * r4 = fighter record (r14). Two helpers refresh it first (0x8C0CA6C6, 0x8C0CAA9C). A 28-step loop then walks one
 * bit per step (r4 = 0x80000000 >> step) over the boundary table at +0x185C, the 0x12AC / 0x15A8 / 0x138C vector
 * lists and a per-step type byte (table 0x0C0EA1E2 or 0x0C0EA1BE) and sets the bit in one of the masks r12 / r9 / r11
 * (stored at +0x14E0 / +0x13D0 / +0x13C8). Three bit-scan passes (0x8C0769C6 returns the lowest set bit or 32)
 * convert the masks into the bytes-of-bits words at +0x14D4 / +0x13C4 / +0x13B4. Last it derives the contact
 * normal (+0x13A8 .. +0x13B0): FR13 / FR15 / FR14 are cleared when the record is not in the wall state, otherwise
 * FR15 comes from a six-way depth scan (0x8C042C20 per entry) and FR14 / FR13 from the +0x2258 pair.
 *
 * The routine mirrors the original's registers and stack slots one for one, so the full caller-saved file and the
 * frame it leaves are those of the original. Frame (f = sp - 104): f+0 scratch, f+4 float scratch, f+8 loop count /
 * bit pattern, f+12 and f+20 float outputs of 0x8C06E8A2, f+16 / f+24 / f+36 flags, f+28 / f+32 the two globals,
 * f+40 / f+44 / f+48 / f+52 / f+56 the walking pointers. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { STEPS = 28, TYPE_A = 0x0C0EA1E2u, TYPE_B = 0x0C0EA1BEu, SCAN_FN = 0x0C0769C6u, SCAN_TABLE = 0x0C0EA1FEu,
       NEAR_FN = 0x0C06E8A2u, DEPTH_FN = 0x0C042C20u, SPEED_FN = 0x0C0BF4B2u, MASK_TABLE = 0x0C110994u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define U8(a)       ((uint32_t)vf3_mem_u8(ram, (a)))
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))

/* SHLD: a negative count shifts right (logical), a positive one left; only the low 5 bits count. */
static uint32_t shld(uint32_t v, uint32_t n)
{
    const uint32_t c = n & 31u;
    if ((n & 0x80000000u) == 0) return v << c;
    const uint32_t r = (0u - n) & 31u;                 /* negative n: logical right shift by -n, 32 yields 0 */
    return r == 0 ? 0u : v >> r;
}

int vf3_wall_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 104;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_fr[3] = { F(15), F(14), F(13) };
    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    w32(ram, sp0 - 32, saved_fr[0]);
    w32(ram, sp0 - 36, saved_fr[1]);
    w32(ram, sp0 - 40, saved_fr[2]);
    w32(ram, sp0 - 44, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(14) = R(4);
    R(3) = 0x0C29B864u;
    R(15) = f;
    w32(ram, f + 28, R(3));
    R(2) = 0x0C29BCC4u;
    w32(ram, f + 32, R(2));
    R(4) = R(14);
    CALL(0x8C0CA6C6u, 0x8C0CAB56u);
    R(4) = R(14);
    CALL(0x8C0CAA9Cu, 0x8C0CAB5Au);

    R(0) = 72;
    R(5) = m32(ram, R(14));
    R(3) = m32(ram, R(14) + R(0));
    w32(ram, f + 16, R(3));
    R(3) = 0x20000000u;
    TST(R(5), R(3));
    R(10) = 0;                                         /* delay slot of the bf/s below */
    if (!(R(VF3_REG_SR) & 1u)) { R(8) = 1; goto have_flag8; }
    R(2) = m32(ram, f + 16);
    R(3) = 0x100;
    TST(R(3), R(2));
    if (R(VF3_REG_SR) & 1u) R(8) = R(10); else R(8) = 1;
have_flag8:
    R(0) = 0x8C0CAC48u;                                /* mova: the pool holds 0.3f */
    R(11) = R(10);
    F(3) = 0x3E999999u;
    R(0) = 4;
    R(12) = R(11);
    R(9) = R(11);
    w32(ram, f + R(0), F(3));
    R(0) = 20;
    F(4) = m32(ram, R(14) + R(0));
    R(0) = 0x8C0CAC4Cu;                                /* mova: 0.05f */
    R(3) = 0x185C;
    F(7) = 0x3D4CCCCCu;
    R(0) = 4;
    R(3) += R(14);
    FMOV(3, 4);
    F(4) = m32(ram, f + R(0));
    R(0) = 0x138C;
    FADD(4, 3);
    R(13) = 0x80000000u;
    R(7) = m32(ram, R(14) + R(0));
    w32(ram, f + 48, R(3));
    R(4) = R(13);
    R(2) = 0x12AC;
    R(2) += R(14);
    w32(ram, f + 52, R(2));
    R(3) = 0x15A8;
    R(3) += R(14);
    w32(ram, f + 56, R(3));
    R(3) = 44;
    R(2) = 0x185C;
    R(2) += R(14);
    w32(ram, f + 40, R(2));
    R(1) = 28;
    w32(ram, f + 44, R(3));
    R(0) = m32(ram, f + 28);
    R(0) = U8(R(0) + R(1));
    R(0) &= 15;
    SET_T(R(0) == 4);
    w32(ram, f, R(0));                                 /* delay slot of the bt/s */
    if (R(0) == 4) goto type_a;
    SET_T(R(0) == 1);
    if (R(0) != 1) { R(6) = TYPE_B; goto type_done; }
type_a:
    R(6) = TYPE_A;
type_done:
    R(2) = STEPS;
    w32(ram, f + 8, R(2));

step:
    R(3) = m32(ram, f + 56);
    R(0) = 4;
    R(3) += 4;
    w32(ram, f + 56, R(3));
    R(3) -= 4;
    F(3) = m32(ram, R(3));
    R(3) = m32(ram, f + 52);
    F(5) = m32(ram, R(7) + R(0));
    R(7) += 12;
    R(3) += 4;
    w32(ram, f + 52, R(3));
    R(3) -= 4;
    R(2) = S8(R(6));
    F(8) = m32(ram, R(3));
    w32(ram, f + 24, R(2));
    R(2) <<= 2;
    R(0) = m32(ram, f + 48);
    FSUB(5, 8);
    R(3) = m32(ram, R(0) + R(2));
    w32(ram, f, R(3));
    R(2) = m32(ram, f + 44);
    R(2) &= R(3);
    w32(ram, f + 24, R(2));
    R(1) = m32(ram, f + 40);
    R(1) += 4;
    w32(ram, f + 40, R(1));
    R(1) -= 4;
    w32(ram, R(1), R(3));
    R(3) = m32(ram, f + 24);
    FMOV(6, 7);
    TST(R(3), R(3));
    FADD(6, 3);                                        /* delay slot */
    if (R(VF3_REG_SR) & 1u) {
        w32(ram, f + 24, R(10));
    } else {
        R(3) = 1;
        w32(ram, f + 24, R(3));
    }
    R(0) = m32(ram, f);
    TST(32, R(0));
    FMOV(8, 5);                                        /* delay slot */
    if (R(VF3_REG_SR) & 1u) {
        w32(ram, f + 36, R(10));
    } else {
        R(2) = 1;
        w32(ram, f + 36, R(2));
    }
    FSUB(8, 4);
    R(0) = m32(ram, f);
    TST(2, R(0));
    FSUB(5, 6);                                        /* delay slot */
    if (!(R(VF3_REG_SR) & 1u)) goto bit_b;

    R(3) = m32(ram, f + 24);
    TST(R(3), R(3));
    if (R(VF3_REG_SR) & 1u) goto scan_x;
    R(3) = 0x800;
    TST(R(5), R(3));
    if (R(VF3_REG_SR) & 1u) goto scan_y;
scan_x:
    F(3) = 0;
    SET_T(GT(3, 8));
    if (R(VF3_REG_SR) & 1u) goto scan_x2;
    TST(R(8), R(8));
    if (!(R(VF3_REG_SR) & 1u)) goto scan_x2;
    R(3) = m32(ram, f + 36);
    TST(R(3), R(3));
    if (R(VF3_REG_SR) & 1u) goto set_r12;
    R(2) = 0x800;
    TST(R(5), R(2));
    if (R(VF3_REG_SR) & 1u) goto scan_x2;
set_r12:
    R(12) |= R(4);
scan_x2:
    F(3) = 0;
    SET_T(GT(3, 5));
    if (!(R(VF3_REG_SR) & 1u)) R(9) |= R(4);
    goto step_end;
scan_y:
    F(3) = 0;
    SET_T(GT(3, 5));
    if (!(R(VF3_REG_SR) & 1u)) R(11) |= R(4);
    goto step_end;
bit_b:
    R(2) = m32(ram, f + 16);
    R(3) = 0x08000000u;
    TST(R(3), R(2));
    if (R(VF3_REG_SR) & 1u) R(11) |= R(4);
step_end:
    R(3) = m32(ram, f + 8);
    R(4) >>= 1;
    R(6) += 1;
    R(3) -= 1;
    TST(R(3), R(3));
    w32(ram, f + 8, R(3));                             /* delay slot */
    if (!(R(VF3_REG_SR) & 1u)) goto step;

    R(0) = 97;
    R(0) = U8(R(14) + R(0));
    SET_T(R(0) == 9);
    if (R(0) == 9) goto speed;
    R(0) = 0x98;
    R(3) = m32(ram, f + 32);
    R(2) = 0x2000;
    R(1) = m32(ram, R(3) + R(0));
    TST(R(2), R(1));
    if (!(R(VF3_REG_SR) & 1u)) goto check_speed;
speed:
    R(0) = 0x434;
    R(4) = R(15);
    R(3) = SPEED_FN;
    R(4) += 4;
    F(4) = m32(ram, R(14) + R(0));
    CALL(0x8C0BF4B2u, 0x8C0CACDAu);
    F(3) = 0;
    SET_T(GT(3, 0));
    if (!(R(VF3_REG_SR) & 1u)) { R(12) = R(10); goto masks_done; }
check_speed:
    TST(R(11), R(11));
    if (!(R(VF3_REG_SR) & 1u)) goto mask_filter;
    R(0) = 0x1A04;
    R(0) = m32(ram, R(14) + R(0));
    TST(4, R(0));
    if (!(R(VF3_REG_SR) & 1u)) goto mask_filter;
    R(12) = R(10);
    goto masks_done;
mask_filter:
    R(0) = 0x1A04;
    R(3) = 0x00800000u;
    R(2) = m32(ram, R(14) + R(0));
    TST(R(3), R(2));
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = 0x1A20;
        R(1) = U8(R(14) + R(0));
        R(0) = MASK_TABLE;
        R(1) <<= 2;
        R(3) = m32(ram, R(0) + R(1));
        R(2) = ~R(3);
        w32(ram, f, R(3));
        R(12) &= R(2);
    }
    R(3) = ~R(9);
    R(2) = ~R(11);
    R(12) &= R(3);
    R(12) &= R(2);
masks_done:
    R(0) = 0x14E0;
    R(8) = SCAN_TABLE;
    w32(ram, R(14) + R(0), R(12));
    R(0) = 0x13D0;
    w32(ram, R(14) + R(0), R(9));
    R(0) -= 8;
    w32(ram, R(14) + R(0), R(11));
    w32(ram, f, R(12));
    w32(ram, f + 8, R(10));
    R(12) = SCAN_FN;
    R(4) = m32(ram, f);
    CALL(0x8C0769C6u, 0x8C0CAD40u);
    for (;;) {
        SET_T(R(0) == 32);
        R(4) = R(0);
        if (R(0) == 32) break;
        R(0) = R(4);
        R(5) = S8(R(8) + R(0));
        R(2) = m32(ram, f + 8);
        R(3) = -R(5);
        R(5) = R(13);
        R(5) = shld(R(5), R(3));
        R(3) = -R(4);
        R(4) = R(13);
        R(4) = shld(R(4), R(3));
        R(4) = ~R(4);
        R(5) |= R(2);
        w32(ram, f + 8, R(5));
        R(3) = m32(ram, f);
        R(4) &= R(3);
        w32(ram, f, R(4));
        R(4) = m32(ram, f);
        CALL(0x8C0769C6u, 0x8C0CAD40u);
    }
    R(0) = 0x14D4;
    R(3) = m32(ram, f + 8);
    w32(ram, R(14) + R(0), R(3));
    w32(ram, f, R(9));
    R(9) = R(10);
    R(4) = m32(ram, f);
    CALL(0x8C0769C6u, 0x8C0CAD74u);
    for (;;) {
        SET_T(R(0) == 32);
        R(4) = R(0);
        if (R(0) == 32) break;
        R(0) = R(4);
        R(5) = S8(R(8) + R(0));
        R(2) = m32(ram, f);
        R(3) = -R(5);
        R(5) = R(13);
        R(5) = shld(R(5), R(3));
        R(3) = -R(4);
        R(4) = R(13);
        R(4) = shld(R(4), R(3));
        R(4) = ~R(4);
        R(4) &= R(2);
        R(9) |= R(5);
        w32(ram, f, R(4));
        R(4) = m32(ram, f);
        CALL(0x8C0769C6u, 0x8C0CAD74u);
    }
    R(0) = 0x13C4;
    w32(ram, R(14) + R(0), R(9));
    w32(ram, f, R(11));
    R(11) = R(10);
    R(4) = m32(ram, f);
    CALL(0x8C0769C6u, 0x8C0CADA2u);
    for (;;) {
        SET_T(R(0) == 32);
        R(4) = R(0);
        if (R(0) == 32) break;
        R(0) = R(4);
        R(5) = S8(R(8) + R(0));
        R(2) = m32(ram, f);
        R(3) = -R(5);
        R(5) = R(13);
        R(5) = shld(R(5), R(3));
        R(3) = -R(4);
        R(4) = R(13);
        R(4) = shld(R(4), R(3));
        R(4) = ~R(4);
        R(4) &= R(2);
        R(11) |= R(5);
        w32(ram, f, R(4));
        R(4) = m32(ram, f);
        CALL(0x8C0769C6u, 0x8C0CADA2u);
    }

    R(0) = 0x13B4;
    w32(ram, R(14) + R(0), R(11));
    R(2) = m32(ram, f + 16);
    R(3) = 0x100;
    F(14) = 0;
    TST(R(3), R(2));
    FMOV(15, 14);
    FMOV(13, 14);                                      /* delay slot */
    if (R(VF3_REG_SR) & 1u) goto store_normal;         /* not in the wall state: FR13 / FR14 / FR15 stay 0 */

    R(0) = m32(ram, f + 28);
    R(1) = 28;
    R(0) = U8(R(0) + R(1));
    R(0) &= 15;
    SET_T(R(0) == 1);
    if (R(0) != 1) goto depth_scan;
    R(3) = R(15);
    R(15) -= 4;
    w32(ram, R(15), R(3));
    R(5) = R(15);
    R(2) = NEAR_FN;
    R(6) = R(15);
    R(7) = R(15);
    R(5) += 8;
    R(6) += 16;
    R(7) += 24;
    R(4) = R(14);
    if (!vf3_guest_call(s, ram, 0x8C06E8A2u, 0x8C0CAE1Au)) return 0;
    R(0) = 0x430;
    R(15) += 4;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 20;
    w32(ram, f + R(0), F(3));
    R(0) = 0x438;
    F(4) = m32(ram, R(14) + R(0));
    R(0) = 4;
    F(2) = m32(ram, f + R(0));
    R(0) = 4;
    F(4) ^= SIGN;
    FSUB(2, 3);
    w32(ram, f + R(0), F(2));
    R(0) = 12;
    F(1) = m32(ram, f + R(0));
    FMUL(2, 2);
    R(0) = 12;
    FSUB(1, 4);
    w32(ram, f + R(0), F(1));
    R(0) = 4;
    FMOV(3, 2);
    FMOV(0, 1);
    FMAC(3, 1);
    w32(ram, f + R(0), F(3));
    R(0) = 0x8C0CAF0Cu;                                /* mova: 2.25f */
    F(4) = 0x40100000u;
    SET_T(GT(4, 3));
    if (R(VF3_REG_SR) & 1u) goto store_normal;

depth_scan:
    R(0) = 0x2258;
    R(5) = 6;
    R(3) = 0x0C119698u;
    R(4) = R(5);
    F(8) = m32(ram, R(14) + R(0));
    R(0) += 4;
    F(7) = m32(ram, R(14) + R(0));
    R(0) += 27;
    R(7) = U8(R(14) + R(0));
    w32(ram, f + 16, R(3));
    R(7) = R(7) & 0xFFu;
depth_step:
    R(3) = R(5);
    R(3) -= R(4);
    w32(ram, f, R(3));
    R(6) = m32(ram, f + 16);
    R(2) = DEPTH_FN;
    R(6) += R(3);
    R(1) = S8(R(6));
    R(0) = 4;                                          /* delay slot */
    CALL(0x8C042C20u, 0x8C0CAE7Au);
    R(3) = 0x185C;
    R(6) = (uint32_t)(int32_t)(int8_t)R(0);
    R(6) <<= 2;
    R(3) += R(14);
    R(6) += R(3);
    R(6) = m32(ram, R(6));
    R(2) = 4;
    TST(R(2), R(6));
    if (R(VF3_REG_SR) & 1u) {
        F(4) = 0;
        FMOV(5, 4);
    } else {
        FMOV(5, 8);
        FMOV(4, 7);
    }
    R(4) -= 1;
    SET_T(R(4) == 0);
    if (R(4) != 0) goto depth_step;

    R(3) = 0x12AC;
    R(4) = 28;
    R(0) = 0x138C;
    R(3) += R(14);
    R(5) = m32(ram, R(14) + R(0));
    w32(ram, f + 8, R(3));
    R(2) = 0x15A8;
    R(2) += R(14);
    w32(ram, f + 16, R(2));
cell:
    R(3) = m32(ram, f + 8);
    R(0) = 4;
    F(6) = m32(ram, R(5) + R(0));
    R(3) += 4;
    w32(ram, f + 8, R(3));
    R(3) -= 4;
    R(2) = m32(ram, f + 16);
    F(10) = m32(ram, R(3));
    R(2) += 4;
    FSUB(6, 10);
    w32(ram, f + 16, R(2));
    R(2) -= 4;
    F(9) = m32(ram, R(2));
    SET_T(GT(6, 9));
    R(5) += 12;                                        /* delay slot */
    if (!(R(VF3_REG_SR) & 1u)) goto cell_next;
    FSUB(9, 6);
    R(0) = 4;
    FMOV(3, 9);
    SET_T(GT(15, 3));
    w32(ram, f + R(0), F(9));                          /* delay slot */
    if (!(R(VF3_REG_SR) & 1u)) goto cell_next;
    R(0) = R(4);
    SET_T(R(0) == 13);
    FMOV(5, 8);
    FMOV(4, 7);
    if (R(0) == 13) goto take_depth;
    R(3) = 13;
    SET_T((int32_t)R(4) > (int32_t)R(3));
    R(6) = 2;
    R(6) &= R(7);
    if ((int32_t)R(4) > (int32_t)R(3)) {
        TST(R(6), R(6));
        if (R(VF3_REG_SR) & 1u) goto cell_next;
        goto take_depth;
    }
    TST(R(6), R(6));
    if (!(R(VF3_REG_SR) & 1u)) goto cell_next;
take_depth:
    R(0) = 4;
    F(15) = m32(ram, f + R(0));
cell_next:
    R(4) -= 1;
    SET_T(R(4) == 0);
    if (R(4) != 0) goto cell;

    R(2) = m32(ram, R(14));
    R(3) = 0x800;
    TST(R(3), R(2));
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = 0x8C0CB038u;                            /* mova: 2.0f */
        F(6) = 0x40000000u;
        FMUL(4, 6);
        FMUL(5, 6);
    }
    FMOV(14, 4);
    FMOV(13, 5);

store_normal:
    R(0) = 0x13A8;
    R(15) += 60;
    w32(ram, R(14) + R(0), F(13));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(15));
    R(0) += 4;
    w32(ram, R(14) + R(0), F(14));
    F(13) = saved_fr[2];
    F(14) = saved_fr[1];
    F(15) = saved_fr[0];
    R(8) = saved[6];
    R(9) = saved[5];
    R(10) = saved[4];
    R(11) = saved[3];
    R(12) = saved[2];
    R(13) = saved[1];
    R(14) = saved[0];
    R(VF3_REG_PR) = pr0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
