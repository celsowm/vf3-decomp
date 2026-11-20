/* midpoint_angles.h - native port of the three-angle wrapper (0x8C09D452),
 * operating on the `vf3_native_aim` context.
 *
 * See midpoint_angles.c and docs/re/native_midpoint_angles.md. */
#ifndef VF3_NATIVE_MIDPOINT_ANGLES_H
#define VF3_NATIVE_MIDPOINT_ANGLES_H

#include "aim_math.h"

/* Run 0x8C09D452.  r4, r5, r6 are three angle values.  The wrapper saves them
 * as halfwords in a twelve-byte frame (r4 at f, r5 at +4, r6 at +8, under the
 * saved pr), then composes three rotations onto the current XMTRX (a->xm):
 * rotate_z with r6's halfword, rotate_y with r5's, and rotate_x with r4's
 * (the tail transfer, which pops pr and runs in the caller's frame).  The
 * frame bytes (part of the contract) stay on the stack.  r14 is never
 * touched; r15 ends at the entry sp.  See
 * docs/re/native_midpoint_angles.md. */
void vf3_native_midpoint_angles(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_MIDPOINT_ANGLES_H */
