/* pose_orchestration.h - native port of the pose orchestration driver
 * (SH-4 0x8C09EAF2).
 *
 * This is the top of the aim/pose family: chain 0x8C09E060 (aim_frame),
 * 0x8C09E6B2 (aim_frame_b), 0x8C09DA72 (seven_pass), 0x8C09D4B0
 * (halfword_frame), 0x8C09E428 (aim_midpoints), 0x8C09E4C8
 * (matrix_basis), 0x8C09DCDC (facing_update) and the recovered matrix
 * helpers of aim_math on one actor, so a fully posed fighter (the blocks
 * at actor+0x200/+0x300/+0x480/+0x540, the SEG records, the orientation
 * matrix and the final XMTRX) comes out of plain C.
 *
 * See docs/re/native_pose_orchestration.md and the readable authority
 * src/fight/readable/pose_orchestration.c. */
#ifndef VF3_NATIVE_POSE_ORCHESTRATION_H
#define VF3_NATIVE_POSE_ORCHESTRATION_H

#include "motion_aim.h"

/* Run 0x8C09EAF2.  `sp0` is the entry stack pointer (r15), `obj` the
 * actor (r14), `arg` the caller's argument (r5).  The actor, the kind
 * record table, the kind==12 code table, the matrix stack control block
 * and the literal pool must be present in the flat matrix RAM.  On return
 * the posed outputs live in the actor region and a->xm is the final
 * matrix; a->r[8..15] and a->pr are restored to the caller's saved values
 * as the epilogue leaves them (macl is recovered from the stack slot at
 * sp0-8 inside the driver). */
void vf3_native_pose_orchestration(vf3_native_aim *a, uint32_t sp0,
                                   uint32_t obj, uint32_t arg);

#endif
