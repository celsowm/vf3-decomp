/* gate_dispatch.c - 0x8C08B5DA  run a state check, then hand the current slot byte to a follow-up routine.
 *
 * r4 = value forwarded as the third argument (r6). Bails out (returning whatever the checks left in r0) when bit 0x800
 * of the word behind the pointer at 0x0C29BBA4 is set, or when 0x8C08B40C reports non-zero. Otherwise it fetches the
 * record pointer at 0x0C29BBC8 and its signed byte at +16; the byte is compared against 255 (a sign-extended load, so
 * the compare can only be true for a byte that reads back positive 255, i.e. never), and 0x8C08B4DE is asked about it.
 * The routine then tail-jumps to 0x8C08B430 with r4 = record, r5 = 16, r6 = the saved r4, r7 = 0x8C08B4DE's result,
 * after restoring r14 / pr, so the callee returns straight to this routine's caller. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))

int vf3_gate_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 12;
    const uint32_t saved_r14 = R(14), arg = R(4);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(15) = f;
    w32(ram, f, arg);
    R(2) = 0x0C29BBA4u;
    R(1) = 0x0800u;
    R(3) = m32(ram, R(2));
    R(0) = m32(ram, R(3));
    SET_T((R(1) & R(0)) == 0);
    if (!(R(VF3_REG_SR) & 1u)) goto leave;

    R(VF3_REG_PR) = 0x8C08B5F2u;
    CALL(0x0C08B40Cu, 0x8C08B5F2u);
    SET_T(R(0) == 0);
    if (!(R(VF3_REG_SR) & 1u)) goto leave;

    R(2) = 0x0C29BBC8u;
    R(0) = 16;
    R(3) = 0x00FFu;
    R(14) = m32(ram, R(2));
    R(4) = S8(R(14) + R(0));
    SET_T(R(3) == R(4));
    if (R(VF3_REG_SR) & 1u) goto leave;
    R(4) = S8(R(14) + R(0));                           /* delay slot of the bsr */
    R(VF3_REG_PR) = 0x8C08B608u;
    CALL(0x0C08B4DEu, 0x8C08B608u);

    R(6) = m32(ram, f);
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(4) = R(14);
    R(7) = R(0);
    R(5) = 16;
    R(14) = saved_r14;
    if (!vf3_guest_call(s, ram, 0x0C08B430u, pr0)) return 0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;

leave:
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(14) = saved_r14;
    s->pc = pr0;
    return 1;
}
