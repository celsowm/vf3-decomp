/* chain_frames.h - native port of the fight engine's chain side-vector walk
 * (0x8C071694), in the same spirit as the capsule_chain / body_capsule family:
 * plain C on the `vf3_native_aim` context, no guest SH-4 code at run time.
 *
 * See chain_frames.c and docs/re/native_chain_frames.md. */
#ifndef VF3_NATIVE_CHAIN_FRAMES_H
#define VF3_NATIVE_CHAIN_FRAMES_H

#include "aim_math.h"

/* Run 0x8C071694.  `obj` is r4, a chain object: +4 the node array, +88 the node
 * count n, +92 the second count m.  Nodes are 24 bytes: a vec3 position at +0
 * and the vec3 this routine writes at +12.  It gives every node an orthonormal
 * side vector by an eight-phase walk over the closed strip (two edge crosses
 * per node, each normalised, summed and normalised into the node).  No guest
 * FPU runs: the crosses and normalisations are plain-C sqrtf, so the +12
 * vectors match the readable within tolerance; the saved-register stack and
 * the contract registers (r8..r14, fr12..fr15, pr, SR's T bit cleared) match
 * bit for bit. */
void vf3_native_chain_frames(vf3_native_aim *a, uint32_t sp0, uint32_t obj);

#endif /* VF3_NATIVE_CHAIN_FRAMES_H */
