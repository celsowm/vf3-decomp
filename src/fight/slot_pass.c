/* slot_pass.c - 0x8C0A756C  run the scene pass for one entry of the slot table.
 *
 *   r4 = slot index. Indices from 0x10A4 up are ignored. The slot is the pointer at 0x0C2A1C3C + 4 * index;
 *   zero or -1 means the slot is empty and the routine leaves at once (r0 holds what it looked at).
 *
 *   Otherwise the pass runs: 0x8C03C4F0 (r4 = 0), 0x8C03C1C0 (r4 = 0x0C2A5F60), then 0x8C03FFD0 with the
 *   slot's record when bit 0 of the record's second word is set, and the routine ends by tail-jumping to
 *   0x8C03C4A0 with r4 = 1, so that routine returns straight to this one's caller. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { LIMIT = 0x10A4, SLOTS = 0x0C2A1C3Cu, SCENE = 0x0C2A5F60u, EMPTY = 0xFFFFFFFFu };

int vf3_slot_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), saved_r14 = R(14);
    const int32_t index = (int32_t)R(4);

    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(15) = sp0 - 8;
    R(3) = LIMIT;

    if (index < LIMIT) {
        R(0) = SLOTS;
        R(14) = (uint32_t)index << 2;
        R(14) = m32(ram, SLOTS + R(14));
        if (R(14) != 0) {
            R(0) = R(14);
            if (R(14) != EMPTY) {
                const uint32_t rec = R(14);
                R(4) = 0;
                if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C0A758Eu)) return 0;
                R(15) = sp0 - 8;
                R(4) = SCENE;
                if (!vf3_guest_call(s, ram, 0x8C03C1C0u, 0x8C0A7596u)) return 0;
                R(15) = sp0 - 8;
                R(14) = rec;
                R(0) = m32(ram, rec + 4);
                if (R(0) & 1u) {
                    R(4) = rec;
                    if (!vf3_guest_call(s, ram, 0x8C03FFD0u, 0x8C0A75A2u)) return 0;
                    R(15) = sp0 - 8;
                }
                R(14) = saved_r14;
                R(15) = sp0;
                R(VF3_REG_PR) = pr0;
                R(4) = 1;
                if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
                R(15) = sp0;
                R(VF3_REG_PR) = pr0;
                s->pc = pr0;
                return 1;
            }
        }
    }

    R(14) = saved_r14;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
