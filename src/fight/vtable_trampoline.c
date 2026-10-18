/* vtable_trampoline.c - 0x8C035CBA  forward to slot +68 of the object whose pointer lives at 0x0C0EA314.
 *
 *     r14 = [0x0C0EA314]; if (r14 == 0) return;  else  jump to [r14 + 68]   (r14 restored in the jump's delay slot)
 *
 * The jump is a tail jump: the callee returns to this routine's caller. The port ends with pc = the slot's target and
 * pr untouched, exactly where the original stands after the delay slot, so the recorded exit (the target) matches.
 * r1 holds the target, r0 = 68, r3 the pointer's address. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c) (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_vtable_trampoline_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), saved_r14 = R(14);
    w32(ram, sp0 - 4, saved_r14);
    R(3) = 0x0C0EA314u;
    const uint32_t obj = m32(ram, R(3));
    SET_T(obj == 0);
    if (obj == 0) {
        R(15) = sp0;
        s->pc = R(VF3_REG_PR);
        return 1;
    }
    R(0) = 68;
    R(1) = m32(ram, obj + 68);
    R(15) = sp0;
    s->pc = R(1);
    return 1;
}
