/* misc_wrappers.c - short routines of the fight tick that mostly just sequence calls.
 *
 *   0x8C0C1296  run 0x8C095604(record, 0, 68) over 120 consecutive 68-byte records at [r4 + 12], then set bit 0 of
 *               the halfword at r4 + 34
 *   0x8C055B28  clamp the halfword at r4 + 2 to 0..9 (17 and above give 10), store 4 * that at 0x0C058FDC, r4 += 4
 *   0x8C08B5AC  0x8C08B40C(r4); on 0 and a byte at +16 (r4 as the record) run 0x8C08B4DE(byte) and tail-jump to
 *               0x8C08B430(r4, 12, 0, result)
 *   0x8C0C1208  a 0x3F14 byte frame: 0x8C043064(frame + 4, [frame + 0x3F1C]) then 0x8C0C1754(0x0C29F2F0, [frame],
 *               frame + 4, 1)
 *
 * The call-sequencing ones declare the full caller-saved register file as output: what they leave behind is what
 * the nested callees left. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { RECORDS = 120, RECORD_BYTES = 68, CLAMP_CELL = 0x0C058FDCu, FRAME_BYTES = 0x3F14u, FRAME_ARG = 0x3F1Cu };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

int vf3_record_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 24;
    const uint32_t saved[4] = { R(14), R(13), R(12), R(11) };
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    w32(ram, sp0 - 20, pr0);
    R(15) = f;
    w32(ram, f, R(4));
    R(14) = m32(ram, R(4) + 12);
    R(13) = 0;
    R(12) = RECORDS;
    R(11) = 0x0C095604u;
    do {
        R(5) = 0;
        R(6) = RECORD_BYTES;
        R(4) = R(14);
        CALL(0x8C095604u, 0x8C0C12B6u);
        R(13) += 1;
        SET_T(R(13) >= R(12));
        R(14) += RECORD_BYTES;
    } while (R(13) < R(12));
    R(3) = m32(ram, f);
    R(0) = 34;
    R(1) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(3) + R(0));
    R(2) = 1;
    R(1) |= R(2);
    vf3_mem_set_u16(ram, R(3) + R(0), (uint16_t)R(1));
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3];
    s->pc = pr0;
    return 1;
}

int vf3_clamp_cell_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 2);
    R(1) = 17;
    SET_T((int32_t)R(0) >= (int32_t)R(1));
    if ((int32_t)R(0) >= (int32_t)R(1)) {
        R(0) = 10;
    } else {
        R(1) = 9;
        SET_T((int32_t)R(0) >= (int32_t)R(1));
        if ((int32_t)R(0) >= (int32_t)R(1)) R(0) = R(1);
    }
    R(0) <<= 2;
    R(1) = CLAMP_CELL;
    w32(ram, R(1), R(0));
    R(4) += 4;
    s->pc = R(VF3_REG_PR);
    return 1;
}

int vf3_record_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8, saved_r14 = R(14);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(15) = f;
    R(14) = R(4);
    CALL(0x8C08B40Cu, 0x8C08B5B4u);
    SET_T(R(0) == 0);
    if (R(0) == 0) {
        R(0) = 16;
        R(3) = 0xFFu;
        R(4) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(14) + R(0));
        SET_T(R(3) == R(4));
        if (R(3) != R(4)) {
            R(4) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(14) + R(0));
            CALL(0x8C08B4DEu, 0x8C08B5C6u);
            R(VF3_REG_PR) = (pr0 & 0x0FFFFFFFu) | 0x8C000000u;
            R(4) = R(14);
            R(5) = 12;
            R(7) = R(0);
            R(6) = 0;
            R(14) = saved_r14;
            R(15) = sp0;
            if (!vf3_guest_tail_call(s, ram, 0x8C08B430u, (pr0 & 0x0FFFFFFFu) | 0x8C000000u)) return 0;
            R(15) = sp0;
            s->pc = pr0;
            return 1;
        }
    }
    R(VF3_REG_PR) = pr0;
    R(14) = saved_r14;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}

int vf3_frame_call_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8 - FRAME_BYTES, saved_r14 = R(14);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(6) = 3;
    R(15) = f;
    w32(ram, f, R(4));
    R(14) = f;
    R(0) = FRAME_ARG + f + 4;
    SET_T((R(0) & R(6)) == 0);
    R(14) += 4;
    if ((R(0) & R(6)) == 0) {
        R(6) = FRAME_ARG + f + 4;
    } else {
        R(6) = FRAME_ARG + f + 8;
    }
    R(0) = FRAME_ARG;
    R(3) = 0x0C043064u;
    R(5) = m32(ram, f + R(0));
    R(4) = R(14);
    CALL(0x8C043064u, 0x8C0C123Au);
    R(4) = 0x0C29F2F0u;
    R(6) = R(14);
    R(7) = 1;
    R(5) = m32(ram, f);
    CALL(0x8C0C1754u, 0x8C0C1244u);
    R(1) = FRAME_BYTES;
    R(15) = sp0 - 8;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(14) = saved_r14;
    s->pc = pr0;
    return 1;
}
