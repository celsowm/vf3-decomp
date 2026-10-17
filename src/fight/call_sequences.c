/* call_sequences.c - two thin call sequencers.
 *
 *   0x8C043064 (a, b, c)  0x8C04A6C8(1, 0, a, b) with c passed as the fifth argument on the stack
 *   0x8C0A7750 (slot)     0x8C03C4F0(0), 0x8C03CCB0(), 0x8C0A7662(slot), then a tail jump to 0x8C03C4A0(1)
 *
 * Both declare the full caller-saved register file as output: what they leave behind is what the nested callees
 * left, and the callees are run for real through the guest-call dispatcher. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

int vf3_call_with_stack_arg_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 16;
    const uint32_t a = R(4), b = R(5), c = R(6);
    w32(ram, sp0 - 4, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    w32(ram, f, a);
    w32(ram, f + 4, b);
    w32(ram, f + 8, c);
    w32(ram, f - 4, c);
    R(3) = 0x0C04A6C8u;
    R(5) = 0;
    R(7) = b;
    R(6) = a;
    R(4) = 1;
    R(15) = f - 4;
    if (!vf3_guest_call(s, ram, 0x8C04A6C8u, 0x8C04307Eu)) return 0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}

int vf3_scene_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8;
    w32(ram, sp0 - 4, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(15) = f;
    w32(ram, f, R(4));
    R(3) = 0x0C03C4F0u;
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C0A775Cu);
    R(2) = 0x0C03CCB0u;
    CALL(0x8C03CCB0u, 0x8C0A7762u);
    R(4) = m32(ram, f);
    CALL(0x8C0A7662u, 0x8C0A7766u);
    R(2) = 0x0C03C4A0u;
    R(15) = sp0;
    R(4) = 1;
    if (!vf3_guest_tail_call(s, ram, 0x8C03C4A0u, (pr0 & 0x0FFFFFFFu) | 0x8C000000u)) return 0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
