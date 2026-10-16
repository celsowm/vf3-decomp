/* terrain_height.c - the ground-height lookup (0x8C068E0E) and its two helpers.
 *
 *   0x8C068D54  terrain_wrap     r4 = stage type, r5 -> x, r6 -> z (floats): stages of type 2/7 scale
 *                                both by 0.769; type 13 folds both into a 10 unit repeating cell;
 *                                every other type leaves them alone.
 *   0x8C068DE4  terrain_flat     r4 -> a 3-float normal block, fr4/fr5 = x/z: writes the up normal
 *                                (0, 1, 0) and returns 0, or -0.5 when x or z lies beyond +-6 (the
 *                                stage edge)  -> fr0
 *   0x8C068E0E  terrain_height   fr4 = x, fr5 = z -> fr0 = ground height. The stage type is the low
 *                                nibble of the byte at 0x0C29B880. With a height table (the pointer at
 *                                0x0C1B9610) x/z are clamped to +-12, mapped to 5 samples per unit
 *                                (64 + 5v), and the four surrounding samples of the 128-wide float grid
 *                                are blended bilinearly. Without one the flat result is used. Stage
 *                                type 11 then runs a further routine (0x0C087ACE) on the same values.
 *
 * Locals live on the original's 36 byte stack frame: z @4, x @8, blend terms @0/@12/@16, result @20. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

#define R(n) (s->v[(n)])
#define F(n) VF3_FR(s, (n))
#define SET_F(n, x) vf3_fr_set(s, (n), (x))
#define GET_F(n) vf3_fr_get(s, (n))

enum {
    LIT_SCALE = 0x8C068E50, LIT_TENTH = 0x8C068E54, LIT_SIGN = 0x8C068E58, LIT_SIX = 0x8C068E5C,
    LIT_HALF = 0x8C068E60, LIT_NEG12 = 0x8C068FD0, LIT_POS12 = 0x8C068FD4, LIT_FIVE = 0x8C068FD8,
    LIT_64 = 0x8C068FDC,
    TYPE_BYTE = 0x0C29B880, TABLE_PTR = 0x0C1B9610,
    WRAP = 0x8C068D54, FLAT = 0x8C068DE4, RET_WRAP = 0x8C068E38, RET_FLAT = 0x8C068E4A,
    EXTRA = 0x8C087ACE, RET_EXTRA = 0x8C068F82, FRAME_BYTES = 36, SAVED_BYTES = 12,
    NEG_ZERO = 0x80000000u
};

static uint32_t lit(uint32_t a) { return a & 0x0FFFFFFFu; }

/* the "round half away to an even count of cells" step shared by both axes of type 13 */
static void fold_axis(vf3_matrix_state *s, const vf3_ram_map *ram, int cnt_reg, uint32_t addr)
{
    if (R(cnt_reg) == 0) return;
    R(2) = 1;
    if ((R(cnt_reg) & 1u) != 0) {
        R(1) = NEG_ZERO;
        if ((R(cnt_reg) & NEG_ZERO) == 0) R(cnt_reg) += 1; else R(cnt_reg) -= 1;
    }
    R(3) = R(cnt_reg);
    R(cnt_reg) <<= 2;
    R(cnt_reg) += R(3);
    F(2) = vf3_mem_u32(ram, addr);
    R(cnt_reg) <<= 1;
    s->v[VF3_REG_FPUL] = R(cnt_reg);
    SET_F(3, vf3_f_from_int(s, (int32_t)R(cnt_reg)));
    F(4) = F(3);
    SET_F(2, vf3_f_sub(s, GET_F(2), GET_F(4)));
    vf3_mem_set_u32(ram, addr, F(2));
}

int vf3_terrain_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t type = R(4);
    R(0) = type;
    if (type == 2 || type == 7) {
        R(0) = lit(LIT_SCALE);
        F(3) = vf3_mem_u32(ram, R(5));
        F(4) = vf3_mem_u32(ram, LIT_SCALE);
        SET_F(3, vf3_f_mul(s, GET_F(3), GET_F(4)));
        vf3_mem_set_u32(ram, R(5), F(3));
        F(2) = vf3_mem_u32(ram, R(6));
        SET_F(2, vf3_f_mul(s, GET_F(2), GET_F(4)));
        vf3_mem_set_u32(ram, R(6), F(2));
    } else if (type == 13) {
        R(0) = lit(LIT_TENTH);
        F(4) = vf3_mem_u32(ram, R(5));
        F(5) = vf3_mem_u32(ram, LIT_TENTH);
        SET_F(4, vf3_f_mul(s, GET_F(5), GET_F(4)));
        F(3) = F(5);
        F(5) = vf3_mem_u32(ram, R(6));
        SET_F(5, vf3_f_mul(s, GET_F(3), GET_F(5)));
        s->v[VF3_REG_FPUL] = (uint32_t)vf3_f_trunc(GET_F(4));
        R(4) = s->v[VF3_REG_FPUL];
        s->v[VF3_REG_FPUL] = (uint32_t)vf3_f_trunc(GET_F(5));
        R(7) = s->v[VF3_REG_FPUL];
        const uint32_t px = R(5), pz = R(6);
        fold_axis(s, ram, 4, px);
        fold_axis(s, ram, 7, pz);
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_terrain_flat_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    F(6) = vf3_mem_u32(ram, LIT_SIX);
    R(0) = lit(LIT_SIX);
    F(4) &= ~NEG_ZERO;                                     /* fabs */
    F(5) &= ~NEG_ZERO;
    F(7) = 0;
    int far_off = GET_F(4) > GET_F(6);
    if (!far_off) far_off = GET_F(5) > GET_F(6);
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (uint32_t)far_off;
    if (far_off) { R(0) = lit(LIT_HALF); F(4) = vf3_mem_u32(ram, LIT_HALF); }
    else F(4) = F(7);
    R(0) = 8;
    vf3_mem_set_u32(ram, R(4) + 8, F(7));
    R(0) = 4;
    vf3_mem_set_u32(ram, R(4), F(7));
    SET_F(3, 1.0f);
    vf3_mem_set_u32(ram, R(4) + 4, F(3));
    F(0) = F(4);
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_terrain_height_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved_r14 = R(14), saved_r13 = R(13);
    const uint32_t X = frame + 8, Z = frame + 4, T0 = frame, T12 = frame + 12, T16 = frame + 16,
                   RES = frame + 20;

    vf3_mem_set_u32(ram, sp0 - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp0 - 8u, saved_r13);
    vf3_mem_set_u32(ram, sp0 - 12u, pr0);
    R(15) = frame;
    vf3_mem_set_u32(ram, X, F(4));
    vf3_mem_set_u32(ram, Z, F(5));
    R(5) = X; R(3) = TYPE_BYTE; R(6) = Z; R(2) = TABLE_PTR;
    R(0) = vf3_mem_u8(ram, TYPE_BYTE);
    R(14) = vf3_mem_u32(ram, TABLE_PTR);
    R(13) = 15u & R(0);
    R(0) = (uint32_t)(int32_t)R(0) & 0xFF;
    R(4) = R(13);
    if (!vf3_guest_call(s, ram, WRAP, RET_WRAP)) return 0;
    R(15) = frame;
    const uint32_t table = R(14);

    if (R(14) == 0) {
        F(5) = vf3_mem_u32(ram, Z);
        R(4) = frame + 24;
        F(4) = vf3_mem_u32(ram, X);
        R(0) = 8;
        if (!vf3_guest_call(s, ram, FLAT, RET_FLAT)) return 0;
        R(15) = frame;
        R(0) = 20;
        vf3_mem_set_u32(ram, RES, F(0));
    } else {
        F(4) = vf3_mem_u32(ram, LIT_NEG12);
        R(0) = 8;
        F(3) = vf3_mem_u32(ram, X);
        if (!(GET_F(3) > GET_F(4))) { vf3_mem_set_u32(ram, X, F(4)); }
        F(3) = vf3_mem_u32(ram, Z);
        if (!(GET_F(3) > GET_F(4))) { vf3_mem_set_u32(ram, Z, F(4)); }
        F(4) = vf3_mem_u32(ram, LIT_POS12);
        F(3) = vf3_mem_u32(ram, X);
        if (!(GET_F(4) > GET_F(3))) { vf3_mem_set_u32(ram, X, F(4)); }
        F(3) = vf3_mem_u32(ram, Z);
        if (!(GET_F(4) > GET_F(3))) { vf3_mem_set_u32(ram, Z, F(4)); }

        F(5) = vf3_mem_u32(ram, LIT_FIVE);
        F(4) = vf3_mem_u32(ram, LIT_64);
        F(2) = vf3_mem_u32(ram, X);
        F(3) = F(4);
        R(3) = 7;
        F(0) = F(5);
        SET_F(3, vf3_f_mac(s, GET_F(0), GET_F(2), GET_F(3)));      /* 64 + 5x */
        R(1) = 127;
        s->v[VF3_REG_FPUL] = (uint32_t)vf3_f_trunc(GET_F(3));
        vf3_mem_set_u32(ram, T0, F(3));
        F(2) = vf3_mem_u32(ram, Z);
        R(2) = 0x3F80;
        SET_F(4, vf3_f_mac(s, GET_F(0), GET_F(2), GET_F(4)));      /* 64 + 5z */
        R(4) = s->v[VF3_REG_FPUL];                                   /* cell x */
        F(6) = F(4);
        s->v[VF3_REG_FPUL] = (uint32_t)vf3_f_trunc(GET_F(6));
        F(4) = vf3_mem_u32(ram, T0);
        R(5) = s->v[VF3_REG_FPUL];                                   /* cell z */
        s->v[VF3_REG_FPUL] = R(4);
        R(4) &= R(1);
        SET_F(3, vf3_f_from_int(s, (int32_t)s->v[VF3_REG_FPUL]));
        s->v[VF3_REG_FPUL] = R(5);
        R(5) <<= R(3) & 31u;
        R(5) &= R(2);
        SET_F(2, vf3_f_from_int(s, (int32_t)s->v[VF3_REG_FPUL]));
        R(4) |= R(5);                                                /* grid index */
        SET_F(4, vf3_f_sub(s, GET_F(4), GET_F(3)));                  /* fx */
        F(5) = F(2);
        R(0) = R(4);
        F(5) = F(6);
        F(3) = F(2);
        R(0) <<= 2;
        SET_F(5, vf3_f_sub(s, GET_F(5), GET_F(3)));                  /* fz */
        F(3) = vf3_mem_u32(ram, table + R(0));                       /* h00 */
        R(0) = 16;
        SET_F(6, 1.0f);
        F(8) = F(6);
        F(7) = F(6);
        SET_F(7, vf3_f_sub(s, GET_F(7), GET_F(4)));                  /* 1 - fx */
        vf3_mem_set_u32(ram, T16, F(3));
        R(0) = R(4) + 1;
        SET_F(8, vf3_f_sub(s, GET_F(8), GET_F(5)));                  /* 1 - fz */
        R(0) <<= 2;
        F(2) = vf3_mem_u32(ram, table + R(0));                       /* h10 */
        R(0) = 12;
        vf3_mem_set_u32(ram, T12, F(2));
        R(0) = 0x80;
        R(0) += R(4);
        R(0) <<= 2;
        F(1) = vf3_mem_u32(ram, table + R(0));                       /* h01 */
        vf3_mem_set_u32(ram, T0, F(1));
        R(0) = 0x81;
        R(0) += R(4);
        R(0) <<= 2;
        F(6) = vf3_mem_u32(ram, table + R(0));                       /* h11 */
        R(0) = 16;
        F(3) = vf3_mem_u32(ram, T16);
        R(0) = 16;
        SET_F(3, vf3_f_mul(s, GET_F(3), GET_F(7)));
        vf3_mem_set_u32(ram, T16, F(3));
        R(0) = 12;
        F(2) = vf3_mem_u32(ram, T12);
        R(0) = 12;
        SET_F(6, vf3_f_mul(s, GET_F(6), GET_F(4)));
        SET_F(2, vf3_f_mul(s, GET_F(2), GET_F(4)));
        vf3_mem_set_u32(ram, T12, F(2));
        R(0) = 16;
        F(1) = vf3_mem_u32(ram, T0);
        SET_F(1, vf3_f_mul(s, GET_F(1), GET_F(7)));
        vf3_mem_set_u32(ram, T0, F(1));
        F(3) = vf3_mem_u32(ram, T16);
        R(0) = 16;
        SET_F(3, vf3_f_mul(s, GET_F(3), GET_F(8)));
        vf3_mem_set_u32(ram, T16, F(3));
        R(0) = 12;
        F(2) = vf3_mem_u32(ram, T12);
        R(0) = 12;
        SET_F(2, vf3_f_mul(s, GET_F(2), GET_F(8)));
        vf3_mem_set_u32(ram, T12, F(2));
        R(0) = 20;
        F(1) = vf3_mem_u32(ram, T0);
        F(0) = F(5);
        SET_F(2, vf3_f_mac(s, GET_F(0), GET_F(6), GET_F(2)));
        SET_F(3, vf3_f_mac(s, GET_F(0), GET_F(1), GET_F(3)));
        vf3_mem_set_u32(ram, T0, F(3));
        F(4) = F(2);
        SET_F(3, vf3_f_add(s, GET_F(3), GET_F(4)));
        vf3_mem_set_u32(ram, RES, F(3));

        R(0) = R(13);
        R(VF3_REG_SR) &= ~1u;
        if (R(13) == 11) {
            R(VF3_REG_SR) |= 1u;
            const uint32_t sp = frame - 8u;
            vf3_mem_set_u32(ram, frame - 4u, frame);
            vf3_mem_set_u32(ram, frame - 8u, frame + 12u);
            R(2) = lit(EXTRA);
            R(3) = frame + 12u;
            R(15) = sp;
            R(4) = frame + 8u;
            R(5) = frame + 20u;
            R(6) = frame + 4u;
            R(7) = frame + 16u;
            if (!vf3_guest_call(s, ram, EXTRA, RET_EXTRA)) return 0;
            R(15) = frame;
        }
        R(0) = 20;
    }

    F(0) = vf3_mem_u32(ram, RES);
    R(15) = sp0;
    R(14) = saved_r14;
    R(13) = saved_r13;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
