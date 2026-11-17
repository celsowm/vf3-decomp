/* Native port of 0x8C09D4B0 (halfword_frame): the frame of three halfwords
 * and the three rotations it feeds.
 *
 *   r4 (obj) -> three halfwords, r5 (arg) a value.  The function saves pr,
 *   reserves a 16-byte frame, writes the argument and the object's three
 *   halfwords into it, then:
 *
 *     rotate_z (0x8C03C940) with the object's first halfword,
 *     rotate_y (0x8C03C880) with the argument plus the object's second,
 *     and a tail transfer to rotate_x (0x8C03C6C0) with the object's third.
 *
 * The third rotation runs in the caller's frame, so this native port returns
 * to the caller with the stack pointer and pr restored, exactly as the guest
 * tail transfer does.  The frame halfwords and saved pr are the guest's
 * stack traffic, written for the differential to compare.  See
 * docs/re/halfword_frame.md. */
#include "pose_callees.h"

#include <stdint.h>

#define FRAME 16u

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

void vf3_native_halfword_frame(vf3_native_aim *a, uint32_t sp, uint32_t obj,
                               uint32_t arg)
{
    /* save pr and reserve the frame */
    vf3_aim_set_u32(a, sp - 4u, a->pr);
    uint32_t f = sp - FRAME - 4u;
    a->r[15] = f;

    /* the frame: the argument, then the object's three halfwords (read back
     * sign-extended, stored as u16, exactly like mov.w -> mov.w) */
    vf3_aim_set_u16(a, f, (uint16_t)arg);
    vf3_aim_set_u16(a, f + 4u, (uint16_t)sext16(vf3_aim_h16(a, obj + 2u)));
    vf3_aim_set_u16(a, f + 8u, (uint16_t)sext16(vf3_aim_h16(a, obj + 0u)));
    vf3_aim_set_u16(a, f + 12u, (uint16_t)sext16(vf3_aim_h16(a, obj + 4u)));

    /* the first handler, rotate_z, gets the object's first halfword */
    vf3_aim_rotate_z_angle(a, vf3_aim_h16(a, f + 8u));

    /* the second, rotate_y, gets the sign-extended argument plus the second
     * halfword (the guest zero-extends the second before adding) */
    {
        const uint32_t r = sext16(vf3_aim_h16(a, f)) +
                           (vf3_aim_h16(a, f + 4u) & 0xffffu);
        vf3_aim_rotate_y_angle(a, (uint16_t)r);
    }

    /* the third, rotate_x, gets the object's third halfword; the guest makes
     * it a tail transfer (pr popped, r15 restored), so we do the same */
    vf3_aim_rotate_x_angle(a, vf3_aim_h16(a, f + 12u));
    a->pr = vf3_aim_u32(a, sp - 4u);             /* pr popped from the stack */
    a->r[15] = sp;                               /* r15 restored */
}
