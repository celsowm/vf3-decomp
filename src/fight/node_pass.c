/* node_pass.c - 0x8C0A76EC  run the scene pass for one list node.
 *
 *   r4 = node, FR4 = a scale. Frame (8 bytes under r14 and pr): +0 the scale, +4 the node.
 *
 *   The pass starts with 0x8C03C4F0 (r4 = 0). The node's word at +4 is the record: with bit 0 set the routine
 *   leaves at once (the pass is closed by the caller), and a zero record skips straight to the closing step.
 *   Otherwise 0x8C03C1C0 (r4 = 0x0C2A5F60) and 0x8C03E8C0 run; when the scale is under 1.0 the record goes to
 *   0x8C055BA0 (r4 = record, FR4 = scale), and for a scale of 1.0 or more it goes to 0x8C055BE0 when any of its
 *   bits 24..27 are set. The routine ends by tail-jumping to 0x8C03C4A0 with r4 = 1. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 8, FRAME = 8, ONE = 0x3F800000u, SCENE = 0x0C2A5F60u, KIND_BITS = 0x0F000000u };

int vf3_node_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), saved_r14 = R(14), f = sp0 - SAVED - FRAME;
    const uint32_t node = R(4);

    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(15) = f;
    w32(ram, f + 4, node);
    w32(ram, f, F(4));

    R(4) = 0;
    if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C0A76FCu)) return 0;
    R(15) = f;

    R(3) = 1;
    R(14) = m32(ram, m32(ram, f + 4) + 4);
    if (R(14) & 1u) {                                       /* closed by the caller: leave */
        R(14) = saved_r14;
        R(15) = sp0;
        R(VF3_REG_PR) = pr0;
        s->pc = pr0;
        return 1;
    }

    if (R(14) != 0) {
        const uint32_t rec = R(14);
        R(4) = SCENE;
        if (!vf3_guest_call(s, ram, 0x8C03C1C0u, 0x8C0A7712u)) return 0;
        R(15) = f;
        if (!vf3_guest_call(s, ram, 0x8C03E8C0u, 0x8C0A7718u)) return 0;
        R(15) = f;
        R(14) = rec;
        F(2) = m32(ram, f);
        F(3) = ONE;
        if (fl(s, 3) > fl(s, 2)) {
            FMOV(4, 2);
            R(4) = rec;
            if (!vf3_guest_call(s, ram, 0x8C055BA0u, 0x8C0A7738u)) return 0;
            R(15) = f;
        } else if (rec & KIND_BITS) {
            R(4) = rec;
            if (!vf3_guest_call(s, ram, 0x8C055BE0u, 0x8C0A772Cu)) return 0;
            R(15) = f;
        }
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
