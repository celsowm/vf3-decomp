/* Native port of 0x8C09E428 (aim_midpoints): the three angle midpoints of
 * the actor's pose-field halfwords and the aim-frame half of the pose
 * orchestration.
 *
 *   r4 (actor) -> the actor, r5 (caller_ptr) -> the caller's pointer.
 *
 * The three midpoints of the actor's pose-field halfwords land in the frame
 * (+8, +12, +4), then midpoint_angles (0x8C09D452, three rotations) runs,
 * then a rotate_z by the pool's quarter turn, a store_keep_translation into
 * the caller's pointer, a matrix_copy from that pointer into actor+0x400,
 * and a matrix_pop (which restores the XMTRX the opening push saved).  The
 * whole computation is scoped: only the stores matter, the XMTRX returns to
 * its entry state.
 *
 * mid(second, first) is the guest's exact halfword arithmetic: zero-extend
 * both, sign-extend the difference, shift it right logically, add it to the
 * second operand and mask to sixteen bits.  See docs/re/aim_midpoints.md. */
#include "pose_callees.h"

#include <stdint.h>

#define SAVED 8u
#define FRAME 16u

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }
static uint32_t u16(vf3_native_aim *a, uint32_t addr) { return vf3_aim_h16(a, addr); }

/* mid(second, first) at actor+off_second / actor+off_first, as the guest
 * computes it */
static uint32_t midpoint(vf3_native_aim *a, uint32_t obj, uint32_t off_second,
                         uint32_t off_first)
{
    const uint32_t second = u16(a, obj + off_second);
    const uint32_t first = u16(a, obj + off_first);
    uint32_t diff = (uint32_t)(int32_t)(int16_t)((int32_t)first -
                                                 (int32_t)second);
    diff >>= 1u;                      /* logical shift, as shlr */
    return (second + diff) & 0xffffu;
}

void vf3_native_aim_midpoints(vf3_native_aim *a, uint32_t sp, uint32_t actor,
                              uint32_t caller_ptr)
{
    /* save r14 and pr, reserve frame */
    vf3_aim_set_u32(a, sp - 4u, a->r[14]);
    vf3_aim_set_u32(a, sp - 8u, a->pr);
    uint32_t f = sp - SAVED - FRAME;
    a->r[15] = f;
    a->r[14] = actor;

    /* matrix_push(0): the rotations run on a pushed XMTRX */
    vf3_aim_push(a, 0);

    /* the saved r5 (the caller's pointer) goes in the frame's first word */
    vf3_aim_set_u32(a, f, caller_ptr);

    /* the three midpoints: 0x1F86/0x1F58/0x1F5A with their partners 48 below */
    vf3_aim_set_u32(a, f + 8u, midpoint(a, actor, 0x1F86u, 0x1F86u - 48u));
    vf3_aim_set_u32(a, f + 12u, midpoint(a, actor, 0x1F88u, 0x1F58u));
    vf3_aim_set_u32(a, f + 4u, midpoint(a, actor, 0x1F8Au, 0x1F5Au));

    /* midpoint_angles with the three midpoint values: rotate_z(+8), rotate_y
     * (+12), rotate_x (+4) */
    vf3_aim_rotate_z_angle(a, (uint16_t)vf3_aim_u32(a, f + 8u));
    vf3_aim_rotate_y_angle(a, (uint16_t)vf3_aim_u32(a, f + 12u));
    vf3_aim_rotate_x_angle(a, (uint16_t)vf3_aim_u32(a, f + 4u));

    /* rotate_z by the pool's quarter turn (0x4000) */
    vf3_aim_rotate_z_angle(a, 0x4000u);

    /* store the computed XMTRX (keeping the caller's own translation) into
     * the caller's pointer */
    vf3_aim_store_keep_translation(a, caller_ptr);

    /* matrix_copy from the caller's pointer into actor + 0x400 */
    vf3_aim_copy(a, actor + 0x400u, caller_ptr);

    /* tail matrix_pop(1): restore r14/pr/r15 and pop the pushed XMTRX */
    vf3_aim_pop(a);
    a->r[14] = vf3_aim_u32(a, sp - 4u);
    a->pr = vf3_aim_u32(a, sp - 8u);
    a->r[15] = sp;
}
