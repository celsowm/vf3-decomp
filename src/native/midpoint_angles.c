/* midpoint_angles.c - SH-4 0x8C09D452: three angle values to three
 * rotations, natively.
 *
 * A plain-C transcription of the readable port src/fight/readable/
 * midpoint_angles.c (`vf3_midpoint_angles_entry`).  It operates on
 * `vf3_native_aim`: the flat RAM, the register file and the XMTRX (a->xm).
 *
 * r4, r5 and r6 are three angle values.  The wrapper saves them as halfwords
 * in a twelve-byte frame (r4 at the frame's first word, r5 at +4, r6 at +8,
 * under the saved pr), then composes three rotations onto the current XMTRX:
 *
 *   rotate_z (a->xm <- a->xm * Rz) with r6's halfword,
 *   rotate_y (a->xm <- a->xm * Ry) with r5's halfword,
 *   and a tail transfer to rotate_x with r4's halfword (the last one runs in
 *   the caller's frame - pr is popped, r15 restored to the entry sp).
 *
 * Each halfword is read back sign-extended (mov.w) and then zero-extended
 * (extu.w in the jsr/jmp delay slot), so the callee sees the low sixteen
 * bits.  r14 is never touched.
 *
 * The three handler pointers are read from the literal pool at run time, as
 * the guest reads them (the test seeds 0x0c09d580/584/588).  The frame bytes
 * are part of the contract: the wrapper writes the halfwords there and the
 * test compares every RAM byte.
 *
 * The register leftovers the guest leaves, reproduced here: r4 = the
 * zero-extended first halfword (tail transfer), r3 = the rotate_x handler
 * pointer, r0 = the sign-extended second halfword (the rotate_y extu path),
 * r15 = the entry sp, r14/pr untouched.
 *
 * See docs/re/native_midpoint_angles.md. */
#include "midpoint_angles.h"

#include <stdint.h>

#define SAVED 4u
#define FRAME 12u

/* the literal pool: the three handler pointers, seeded by the test */
#define POOL_ROTATE_Z 0x0c09d580u
#define POOL_ROTATE_Y 0x0c09d584u
#define POOL_ROTATE_X 0x0c09d588u

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

void vf3_native_midpoint_angles(vf3_native_aim *a, uint32_t sp0)
{
    const uint32_t pr0 = a->pr;
    const uint32_t f = sp0 - SAVED - FRAME;

    /* save pr, reserve the frame, write the three halfwords in order */
    vf3_aim_set_u32(a, sp0 - SAVED, pr0);
    a->r[15] = f;
    vf3_aim_set_u16(a, f, (uint16_t)a->r[4]);
    vf3_aim_set_u16(a, f + 4u, (uint16_t)a->r[5]);
    vf3_aim_set_u16(a, f + 8u, (uint16_t)a->r[6]);

    /* rotate_z with r6's halfword (frame +8), zero-extended */
    vf3_aim_rotate_z_angle(a, (uint16_t)vf3_aim_h16(a, f + 8u));
    a->r[15] = f;

    /* rotate_y with r5's halfword (frame +4); r0 keeps the sign-extended
     * value (the extu only lands in the callee's r4) */
    {
        const uint32_t angy = vf3_aim_h16(a, f + 4u);
        a->r[0] = sext16(angy);
        vf3_aim_rotate_y_angle(a, (uint16_t)angy);
        a->r[15] = f;
    }

    /* the tail transfer to rotate_x with r4's halfword (frame), the handler
     * pointer into r3, pr popped and r15 restored to the entry sp */
    a->r[4] = vf3_aim_h16(a, f) & 0xffffu;
    a->r[15] = f + FRAME;                 /* sp0 - SAVED */
    a->r[3] = vf3_aim_u32(a, POOL_ROTATE_X);
    a->pr = vf3_aim_u32(a, a->r[15]);     /* pop the saved pr */
    a->r[15] = sp0;                       /* + SAVED */
    vf3_aim_rotate_x_angle(a, (uint16_t)a->r[4]);
}
