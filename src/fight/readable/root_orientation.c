/* root_orientation.c - SH-4 0x8C09D9EA: build the actor's root orientation.
 *
 * r4 -> actor.  The function resets the matrix bank (XMTRX) to the identity
 * and composes three rotations from the actor's own angle fields, then
 * tail-transfers to a fourth:
 *
 *   identity (0x8C03CCB0, pool 0x0C09DAD8)
 *   rotate_y (0x8C03C880, pool 0x0C09DADC) with the actor's yaw halfword
 *     at +30 (+0x1E), sign-extended
 *   rotate_z (0x8C03C940, pool 0x0C09DAE0) with the first pose field,
 *     the halfword at the pool offset 0x0C09DACC (0x1F50), zero-extended
 *   rotate_y (0x8C03C880 again) with the second pose field, at the pool
 *     offset 0x0C09DACE (0x1F52), zero-extended
 *   tail to rotate_x (0x8C03C6C0, pool 0x0C09DAE4) with the third pose
 *     field, at the pool offset 0x0C09DAD0 (0x1F54), zero-extended
 *
 * The yaw is sign-extended (a plain mov.w into r4, no extu in the jsr delay
 * slot); the three pose fields are zero-extended (the extu.w sits in the
 * jsr/jmp delay slot).  The tail transfer pops pr at 0x0C09DA12 and restores
 * r14 in the jmp delay slot, so rotate_x runs in the caller's frame and
 * returns to the caller's caller.
 *
 * The three pose-field offsets are read from the literal pool at run time,
 * as the guest reads them, rather than baked in. */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define POOL_IDENTITY 0x0c09dad8u
#define POOL_ROTATE_Y  0x0c09dadcu
#define POOL_ROTATE_Z  0x0c09dae0u
#define POOL_ROTATE_X  0x0c09dae4u
#define POOL_OFF_Z     0x0c09daccu   /* halfword offset of the first field */
#define POOL_OFF_Y     0x0c09daceu   /* halfword offset of the second field */
#define POOL_OFF_X     0x0c09dad0u   /* halfword offset of the third field */

/* the continuations the guest leaves in pr */
#define CONT_IDENTITY 0x0c09d9f4u
#define CONT_YAW      0x0c09d9fcu
#define CONT_Z        0x0c09da06u
#define CONT_Y        0x0c09da10u

#define YAW_OFFSET 30u

int vf3_root_orientation_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(16), saved_r14 = R(14), obj = R(4);

    /* the guest saves r14 and pr, eight bytes under the entry sp */
    vf3_mem_set_u32(ram, sp0 - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp0 - 8u, pr0);
    R(15) = sp0 - 8u;
    R(14) = obj;

    /* XMTRX = identity */
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_IDENTITY),
                        CONT_IDENTITY)) return 0;
    R(15) = sp0 - 8u;

    /* XMTRX <- XMTRX * Ry(yaw): the yaw halfword, sign-extended */
    R(4) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + YAW_OFFSET);
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Y),
                        CONT_YAW)) return 0;
    R(15) = sp0 - 8u;

    /* XMTRX <- XMTRX * Rz(first field): zero-extended */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, POOL_OFF_Z);
    R(4) = vf3_mem_u16(ram, obj + R(0)) & 0xffffu;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Z),
                        CONT_Z)) return 0;
    R(15) = sp0 - 8u;

    /* XMTRX <- XMTRX * Ry(second field): zero-extended */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, POOL_OFF_Y);
    R(4) = vf3_mem_u16(ram, obj + R(0)) & 0xffffu;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Y),
                        CONT_Y)) return 0;
    R(15) = sp0 - 8u;

    /* the tail transfer: the guest pops pr, loads the third field
     * zero-extended, restores r14 in the jmp delay slot and jumps. */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, POOL_OFF_X);
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(4) = vf3_mem_u16(ram, obj + R(0)) & 0xffffu;
    R(3) = vf3_mem_u32(ram, POOL_ROTATE_X);
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    return vf3_guest_tail_call(s, ram, R(3), R(16));
}
