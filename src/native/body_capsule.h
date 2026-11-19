/* body_capsule.h - native port of the fight engine's capsule-fitting driver
 * (0x8C06F450), in the same spirit as the aim/pose and capsule_chain family:
 * plain C on the `vf3_native_aim` context, no guest SH-4 code at run time.
 *
 * Drives the same eleven callees the readable port does, all inlined as
 * plain-C helpers: the matrix stack load/push/pop/invert/concat (native
 * aim_math + matrix helpers), the WORD_COPY axis constant, the two end-point
 * matrix `xform`s (with a w=0 direction transform, which no existing native
 * helper produces), the node-chain repositioning loop, CAPSULE_CHAIN (the
 * already-native vf3_native_capsule_chain), and the two follow-up fixups
 * FIXUP_A (chain_frames strip walk) and FIXUP_B (negate_copy).
 *
 * See body_capsule.c and docs/re/native_body_capsule.md. */
#ifndef VF3_NATIVE_BODY_CAPSULE_H
#define VF3_NATIVE_BODY_CAPSULE_H

#include "aim_math.h"

/* Run 0x8C06F450.  `owner` is r4 (the object whose +72 state word, +62
 * halfword and +96/+97 skip bytes drive the chain selection), `rec` r5 (the
 * capsule record: +4 node array base, +12 matrix-block pointer (also the
 * FINISH source), +16 the join matrix (overwritten by FINISH), +0x54 link
 * scale, +0x58 chain node count n, +0x5C second count m, +0x64 node reach,
 * +0x84 is read as a scale input, +0xA4 axis length, +108/+112 the two
 * end-point matrix pointers).  `sp0` is the entry stack pointer. */
void vf3_native_body_capsule(vf3_native_aim *a, uint32_t sp0, uint32_t owner,
                             uint32_t rec);

#endif /* VF3_NATIVE_BODY_CAPSULE_H */
