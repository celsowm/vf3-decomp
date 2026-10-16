/* chain_readable.c - thin glue entries of the fight engine's matrix helpers.
 *
 *   0x8C03ECB0  build the frame matrix, load the camera basis, then submit    (r4 passes through)
 *   0x8C03CC90  load a 3-vector from r4 into FR4..FR6 and tail-call 0x8C03CC60
 *
 * Both are trampolines: all arithmetic happens in the callees, which run as guest code
 * (or as other readable ports through the same dispatch). Only the frame, the saved
 * words and the argument set-up belong to the entries themselves. */
#include "fight/readable.h"
#include "fight/readable_fp.h"

enum {
    FRAME_A_ENTRY = 0x0C03D260, CAMERA_BASIS_ENTRY = 0x0C03EE40, SUBMIT_ENTRY = 0x0C03EFF0,
    VEC3_TAIL_ENTRY = 0x0C03CC60,
    RET_AFTER_FRAME_A = 0x0C03ECBE, RET_AFTER_BASIS = 0x0C03ECC2
};

int vf3_matrix_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr = s->v[VF3_REG_PR], obj = s->v[4];
    vf3_mem_set_u32(ram, sp0 - 4u, pr);
    vf3_mem_set_u32(ram, sp0 - 8u, obj);
    s->v[15] = sp0 - 8u;
    VF3_FR(s, 4) = 0;                              /* fldi0 fr4, fr5 */
    VF3_FR(s, 5) = 0;
    if (!vf3_guest_call(s, ram, FRAME_A_ENTRY, RET_AFTER_FRAME_A)) return 0;
    if (!vf3_guest_call(s, ram, CAMERA_BASIS_ENTRY, RET_AFTER_BASIS)) return 0;
    s->v[3] = SUBMIT_ENTRY;
    s->v[4] = vf3_mem_u32(ram, sp0 - 8u);
    s->v[15] = sp0;
    s->v[VF3_REG_PR] = pr;
    if (!vf3_guest_call(s, ram, SUBMIT_ENTRY, pr)) return 0;   /* tail jump: returns to our caller */
    return 1;
}

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
