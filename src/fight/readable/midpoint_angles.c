/* midpoint_angles.c - SH-4 0x8C09D452: three angle values to three
 * rotations.
 *
 * r4, r5 and r6 are three angle values. The wrapper saves them as
 * halfwords in a twelve-byte frame (r4 at the frame's first word, r5 at
 * +4, r6 at +8, under the saved pr), then:
 *
 *   rotate_z (0x8C03C940, pool 0x0C09D580) with r6's halfword,
 *   rotate_y (0x8C03C880, pool 0x0C09D584) with r5's halfword,
 *   and a **tail transfer** to rotate_x (0x8C03C6C0, pool 0x0C09D588)
 *   with r4's halfword.
 *
 * Each halfword is read back sign-extended (mov.w) and then zero-extended
 * (extu.w in the jsr/jmp delay slot), so the callee sees the low sixteen
 * bits. The tail transfer pops pr in the jmp delay slot, so rotate_x
 * runs in the caller's frame. r14 is never touched.
 *
 * The three handler pointers are read from the literal pool at run time,
 * as the guest reads them. The frame bytes are part of the contract: the
 * wrapper writes the halfwords there and the test compares every RAM
 * byte, so a port that skipped the frame would still be caught.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define POOL_ROTATE_Z 0x0c09d580u
#define POOL_ROTATE_Y 0x0c09d584u
#define POOL_ROTATE_X 0x0c09d588u

/* the continuations the guest leaves in pr */
#define CONT_Z 0x0c09d46au
#define CONT_Y 0x0c09d474u

#define SAVED 4u
#define FRAME 12u

int vf3_midpoint_angles_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(16), f = sp0 - SAVED - FRAME;

    /* the guest saves pr and reserves the frame, halfwords in r4/r5/r6
     * order */
    vf3_mem_set_u32(ram, sp0 - 4u, pr0);
    R(15) = f;
    vf3_mem_set_u16(ram, f, (uint16_t)R(4));
    vf3_mem_set_u16(ram, f + 4u, (uint16_t)R(5));
    vf3_mem_set_u16(ram, f + 8u, (uint16_t)R(6));

    /* rotate_z with r6's halfword, read back and zero-extended */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, f + 8u);
    R(4) = R(0) & 0xffffu;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Z), CONT_Z))
        return 0;
    R(15) = f;

    /* rotate_y with r5's halfword */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, f + 4u);
    R(4) = R(0) & 0xffffu;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Y), CONT_Y))
        return 0;
    R(15) = f;

    /* the tail transfer: r4's halfword, pr popped, r15 restored */
    R(4) = vf3_mem_u16(ram, f) & 0xffffu;
    R(15) += FRAME;
    R(3) = vf3_mem_u32(ram, POOL_ROTATE_X);
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += SAVED;
    return vf3_guest_tail_call(s, ram, R(3), R(16));
}
