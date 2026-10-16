/* pass_prep.c - 0x8C09DBC0  run one setup pass around a scene helper.
 *
 *   r4 / r5 = the two arguments handed on to 0x8C03B450. The routine resets the pass with 0x8C03C4F0 (r4 = 0)
 *   and 0x8C03C5B0, runs 0x8C03B450 (r4, r5 as passed), and ends by tail-jumping to 0x8C03C4A0 with r4 = 1,
 *   so that routine returns straight to this one's caller.
 *
 *   Frame (72 bytes under pr): +0 / +4 the two arguments. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 4, FRAME = 72 };

int vf3_pass_prep_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t arg0 = R(4), arg1 = R(5);

    w32(ram, sp0 - 4, pr0);
    R(15) = f;
    w32(ram, f, arg0);
    w32(ram, f + 4, arg1);

    R(4) = 0;
    if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C09DBCEu)) return 0;
    R(15) = f;
    if (!vf3_guest_call(s, ram, 0x8C03C5B0u, 0x8C09DBD4u)) return 0;
    R(15) = f;
    R(5) = arg1; R(4) = arg0;
    if (!vf3_guest_call(s, ram, 0x8C03B450u, 0x8C09DBDCu)) return 0;

    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(4) = 1;
    if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
