/* node_rotate.h - native port of the fighter's node rotation (0x8C09F83C),
 * operating on the `vf3_native_aim` context.  See node_rotate.c and
 * docs/re/native_node_rotate.md. */
#ifndef VF3_NATIVE_NODE_ROTATE_H
#define VF3_NATIVE_NODE_ROTATE_H

#include "aim_math.h"

/* Run 0x8C09F83C.  Turns seven twelve-byte records around the Y axis by the
 * angle the caller leaves in FR4 (cosine) and FR5 (sine), then moves the
 * root's position by the value the caller leaves in FR6.  r4 = the object.
 * A self-contained FP leaf with no calls.  Runs under round-to-nearest (no
 * FTZ): the FPSCR is 0, so plain C float ops and `fmaf` reproduce it. */
void vf3_native_node_rotate(vf3_native_aim *a);

#endif /* VF3_NATIVE_NODE_ROTATE_H */
