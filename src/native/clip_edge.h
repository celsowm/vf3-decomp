/* clip_edge.h - native port of the clip-edge helper 0x8C048CC0 on the
 * `vf3_native_aim` context.
 *
 * See clip_edge.c and docs/re/native_clip_edge.md. */
#ifndef VF3_NATIVE_CLIP_EDGE_H
#define VF3_NATIVE_CLIP_EDGE_H

#include "motion_aim.h"

/* Run 0x8C048CC0 (clip_edge).  A self-contained, call-free FP leaf: it pushes
 * the point where the strip edge ring[r0&3] -> ring[r11&3] crosses the plane
 * w' = r12, interpolating every attribute with a fused multiply-add
 * (lerp(a0,a1,t) = a0 + t*(a1-a0)), scaling y' and z' by the float whose bits
 * are in r7, and writes the 32-byte store-queue vertex block at r6.
 * See clip_edge.c for the full contract.  Returns 1 on success, 0 on a
 * rejected FPSCR (unsupported or SZ already on, which the guest would not
 * enter from). */
int vf3_native_clip_edge(vf3_native_aim *a);

#endif /* VF3_NATIVE_CLIP_EDGE_H */
