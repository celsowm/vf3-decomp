/* quad_strip.h - native port of the quad-strip emitter 0x8C048600
 * on the `vf3_native_aim` context.
 *
 * See quad_strip.c and docs/re/native_quad_strip.md. */
#ifndef VF3_NATIVE_QUAD_STRIP_H
#define VF3_NATIVE_QUAD_STRIP_H

#include "motion_aim.h"

/* Run 0x8C048600 (quad_strip).  A self-contained FP leaf (the guest lighting
 * and projection are inlined in its body): it walks a list of groups of four
 * vertices, transforms and lights the first and projects the rest, and writes
 * 32-byte store-queue slots at r6.  See quad_strip.c for the contract.
 * Returns 1 on success, 0 on a rejected FPSCR / malformed input (which the
 * guest would not terminate on). */
int vf3_native_quad_strip(vf3_native_aim *a);

#endif /* VF3_NATIVE_QUAD_STRIP_H */
