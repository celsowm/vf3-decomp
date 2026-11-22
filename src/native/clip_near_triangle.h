/* clip_near_triangle.h - native port of the near-plane triangle clipper
 * 0x8C04A320 on the `vf3_native_aim` context.
 *
 * See clip_near_triangle.c and docs/re/native_clip_near_triangle.md. */
#ifndef VF3_NATIVE_CLIP_NEAR_TRIANGLE_H
#define VF3_NATIVE_CLIP_NEAR_TRIANGLE_H

#include "motion_aim.h"

/* Run 0x8C04A320 (clip_near_triangle).  A self-contained FP leaf (the guest's
 * XMTRX transform and clipping are inlined in its body): it walks a stream of
 * triangles, projects each point through XMTRX, clips the strip against the
 * near-plane threshold and writes 32-byte store-queue vertex blocks at r6,
 * counting 64-byte blocks in r5.  See clip_near_triangle.c for the contract.
 * Returns 1 on success, 0 on a rejected FPSCR (unsupported / SZ already on,
 * which the guest would not enter from) or a malformed input. */
int vf3_native_clip_near_triangle(vf3_native_aim *a);

#endif /* VF3_NATIVE_CLIP_NEAR_TRIANGLE_H */
