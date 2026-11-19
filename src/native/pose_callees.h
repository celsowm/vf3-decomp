/* pose_callees.h - native reimplementations of the four pose-orchestration
 * callees, in the same spirit as motion_aim.c: plain C on the
 * `vf3_native_aim` context (flat matrix RAM + XMTRX + matrix stack + FR bank
 * + register file), reproducing the guest matrix helpers from aim_math.
 *
 *  0x8C09D4B0  halfword_frame   (halfword_frame.c)
 *  0x8C09E428  aim_midpoints    (aim_midpoints.c)
 *  0x8C09E4C8  matrix_basis     (matrix_basis.c)
 *  0x8C09DCDC  facing_update    (facing_update.c)
 *
 * Each takes the guest argument registers (pointers into the flat RAM) and
 * the caller's sp0, runs the matrix arithmetic on XMTRX, and leaves the same
 * stack traffic / RAM writes the guest left. */
#ifndef VF3_NATIVE_POSE_CALLEES_H
#define VF3_NATIVE_POSE_CALLEES_H

#include "aim_math.h"

/* 0x8C09D4B0: obj (r4) holds three halfwords, arg (r5) a value.  Three
 * rotations: rotate_z(obj[0]), rotate_y(arg + obj[1]), rotate_x(obj[2]).
 * The third is a tail transfer, so this function fully returns to the
 * caller.  Frames / saved pr are left at sp (sp0) as the guest left them. */
void vf3_native_halfword_frame(vf3_native_aim *a, uint32_t sp, uint32_t obj,
                               uint32_t arg);

/* 0x8C09E428: three angle midpoints of the actor's pose-field halfwords,
 * then midpoint_angles + rotate_z + store_keep_translation + matrix_copy.
 * actor (r4) and the caller's pointer (r5). */
void vf3_native_aim_midpoints(vf3_native_aim *a, uint32_t sp, uint32_t actor,
                              uint32_t caller_ptr);

/* 0x8C09E4C8: build the camera basis of a record (r4) and publish its axis
 * vectors to the destination block (r5). */
void vf3_native_matrix_basis(vf3_native_aim *a, uint32_t sp, uint32_t record,
                             uint32_t block);

/* 0x8C09DCDC: turn a character's heading and pitch toward a target point
 * (r5) and refresh its orientation matrix.  character is r4. */
void vf3_native_facing_update(vf3_native_aim *a, uint32_t sp, uint32_t character,
                              uint32_t target);

/* 0x8C09DA72: the seven-segment pass for one object (r4).  Builds SEG_B
 * (+0x1EFC) from the object's SEG_A records (+0x1D04) through a push /
 * identity / translate / rotate_y / xform pipeline; net XMTRX is unchanged. */
void vf3_native_seven_pass(vf3_native_aim *a, uint32_t sp0, uint32_t obj);

/* 0x8C09F500: the pose quantiser.  Turns the three-float vector (r5) into
 * canonicalised halfwords at the destination (r6).  Leaf, no pr.  See
 * pose_turns.c. */
void vf3_native_pose_turns(vf3_native_aim *a, uint32_t sp, uint32_t actor,
                           uint32_t vec, uint32_t dest);

/* 0x8C09F5F8: the point clamp.  Clamps a three-float point (r4) into the
 * ring's period, taking fr4..fr9 as inputs; r0 = the point plus 12.  Leaf. */
void vf3_native_point_wrap(vf3_native_aim *a, uint32_t sp, uint32_t pt);

/* 0x8C09F432: the pose post-processor.  Wraps the five points around the two
 * quantiser calls and returns actor+0x1E00 in r0/r5.  See pose_post.c. */
void vf3_native_pose_post(vf3_native_aim *a, uint32_t sp, uint32_t actor);


#endif
