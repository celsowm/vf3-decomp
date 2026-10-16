/* chain_readable.c - thin glue entry of the fight engine's matrix helpers.
 *
 *   0x8C03CC90  load a 3-vector from r4 into FR4..FR6 and tail-call 0x8C03CC60
 *
 * A trampoline: the transform happens in the callee, which runs as guest code. Only the
 * dead r14 push and the argument set-up belong to the entry itself.
 * (0x8C03ECB0, the frame/camera/submit trampoline, was tried too but is left generated:
 * its outputs include leftovers of nested real code that the poison audit cannot pin
 * to a declared register set.) */
#include "fight/readable.h"
#include "fight/readable_fp.h"

enum { VEC3_TAIL_ENTRY = 0x0C03CC60 };

int vf3_vec3_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr = s->v[VF3_REG_PR], vec = s->v[4];
    vf3_mem_set_u32(ram, sp0 - 4u, s->v[14]);       /* dead r14 push */
    VF3_FR(s, 6) = vf3_mem_u32(ram, vec + 8u);
    VF3_FR(s, 4) = vf3_mem_u32(ram, vec);
    VF3_FR(s, 5) = vf3_mem_u32(ram, vec + 4u);
    s->v[0] = 4;
    s->v[3] = VEC3_TAIL_ENTRY;
    if (!vf3_guest_call(s, ram, VEC3_TAIL_ENTRY, pr)) return 0;
    return 1;
}
