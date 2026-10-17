/* small_leaves.c - a handful of short leaf routines the fight tick calls from many places.
 *
 *   0x8C03B820  store XF12..XF14 (the shadow bank) at r4 .. r4+8
 *   0x8C03CEE0  r4[0..2] = r5[0..2] - r6[0..2] (vector difference); r4 / r5 / r6 end 8 bytes advanced
 *   0x8C03C8B0  build the rotation XMTRX from (sin, cos) = (fr4, fr5): the two rows go through XMTRX and land in
 *               XF0..XF3 / XF8..XF11
 *   0x8C04B9BE  r0 = (record kind == 1) ? 0 : byte [[r4+4] + 16] & 0x40
 *   0x8C05342C  strlen of the string at r4 (r0 = r5 = length)
 *   0x8C09D408  negate the 7 + 14 floats at r4+8, r4+20, ... (stride 12; the second run restarts 8 below the end)
 *   0x8C09D590  42 floats from r4+0x1D58 truncated to halfwords at r4+0x1F50
 *   0x8C0B1B2E  run the zero-terminated handler list [0x0C10F7A8 + 4 * min(r5, 17)] with r4 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SZ_BIT = 0x00100000u, PR_BIT = 0x00080000u, HANDLER_TABLE = 0x0C10F7A8u, HANDLER_MAX = 17u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define FPUL        (s->v[VF3_REG_FPUL])

static int plain_fpu(const vf3_matrix_state *s)
{
    return vf3_fpu_supported(R(VF3_REG_FPSCR)) && !(R(VF3_REG_FPSCR) & (SZ_BIT | PR_BIT));
}

int vf3_xf_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!plain_fpu(s)) return 0;
    R(4) += 12;
    for (int i = 14; i >= 12; --i) { R(4) -= 4; w32(ram, R(4), s->v[VF3_REG_XF0 + i]); }
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_vec3_sub_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!plain_fpu(s)) return 0;
    F(0) = m32(ram, R(5)); R(5) += 4;
    F(4) = m32(ram, R(6)); R(6) += 4;
    F(1) = m32(ram, R(5)); R(5) += 4;
    F(5) = m32(ram, R(6)); R(6) += 4;
    FSUB(0, 4);
    F(2) = m32(ram, R(5));
    F(6) = m32(ram, R(6));
    FSUB(1, 5);
    w32(ram, R(4), F(0)); R(4) += 4;
    FSUB(2, 6);
    w32(ram, R(4), F(1)); R(4) += 4;
    w32(ram, R(4), F(2));
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_rotation_xmtrx_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    if (!plain_fpu(s)) return 0;
    FMOV(0, 5);
    FMOV(2, 4);
    F(2) ^= SIGN;
    FMOV(6, 0);
    F(1) = 0;
    F(3) = 0;
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(0), R(VF3_REG_FPSCR), &F(0))) return 0;
    F(5) = 0;
    F(7) = 0;
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(4), R(VF3_REG_FPSCR), &F(4))) return 0;
    /* fschg: with SZ = 1 an even -> odd fmov moves a register pair into the shadow bank (XD) */
    s->v[VF3_REG_XF0 + 0] = F(0); s->v[VF3_REG_XF0 + 1] = F(1);
    s->v[VF3_REG_XF0 + 2] = F(2); s->v[VF3_REG_XF0 + 3] = F(3);
    s->v[VF3_REG_XF0 + 8] = F(4); s->v[VF3_REG_XF0 + 9] = F(5);
    s->v[VF3_REG_XF0 + 10] = F(6); s->v[VF3_REG_XF0 + 11] = F(7);
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_record_flag40_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = m32(ram, R(4));
    SET_T(R(0) == 1);
    if (R(0) == 1) {
        R(0) = 0;
    } else {
        R(1) = 16;
        R(0) = m32(ram, R(4) + 4);
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(0) + R(1));
        R(0) &= 0x40u;
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_strlen_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(5) = 0;
    for (;;) {
        R(3) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4));
        R(4) += 1;
        if (R(3) == 0) break;
        R(5) += 1;
    }
    SET_T(1);
    R(0) = R(5);
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_negate_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!plain_fpu(s)) return 0;
    R(5) = 7;
    R(4) += 8;
    do {
        F(3) = m32(ram, R(4));
        R(5) -= 1;
        F(3) ^= SIGN;
        w32(ram, R(4), F(3));
        R(4) += 12;
    } while (R(5) != 0);
    R(5) = 14;
    R(4) -= 8;
    do {
        F(3) = m32(ram, R(4));
        R(5) -= 1;
        F(3) ^= SIGN;
        w32(ram, R(4), F(3));
        R(4) += 12;
    } while (R(5) != 0);
    SET_T(1);
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_float_to_short_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!plain_fpu(s)) return 0;
    R(5) = 0x1F50u + R(4);
    R(6) = 0x1D58u + R(4);
    R(4) = 42;
    do {
        F(4) = m32(ram, R(6)); R(6) += 4;
        R(4) -= 1;
        FPUL = vf3_fpu_ftrc(F(4));
        R(7) = FPUL;
        R(7) = (uint32_t)(int32_t)(int16_t)R(7);
        vf3_mem_set_u16(ram, R(5), (uint16_t)R(7));
        R(5) += 2;
    } while (R(4) != 0);
    SET_T(1);
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_handler_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 20;
    const uint32_t saved[3] = { R(14), R(13), R(12) };
    w32(ram, sp0 - 4, saved[0]);
    w32(ram, sp0 - 8, saved[1]);
    w32(ram, sp0 - 12, saved[2]);
    w32(ram, sp0 - 16, pr0);
    R(15) = f;
    w32(ram, f, R(4));
    R(4) = HANDLER_MAX;
    SET_T(R(5) > R(4));
    R(6) = 0;
    if (R(5) > R(4)) R(5) = R(4);
    R(0) = HANDLER_TABLE;
    R(12) = R(5) << 2;
    R(13) = R(6);
    R(12) = m32(ram, R(0) + R(12));
    for (;;) {
        R(0) = R(13) << 2;
        R(14) = m32(ram, R(0) + R(12));
        SET_T(R(14) == 0);
        if (R(14) == 0) break;
        R(4) = m32(ram, f);
        if (!vf3_guest_call(s, ram, (R(14) & 0x0FFFFFFFu) | 0x8C000000u, 0x8C0B1B5Cu)) return 0;
        R(15) = f;
        R(13) += 1;
    }
    R(15) = sp0;
    R(14) = saved[0];
    R(13) = saved[1];
    R(12) = saved[2];
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
