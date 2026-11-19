/* capsule_chain.h - native port of the fight engine's capsule node-chain
 * keeper (0x8C070008), in the same spirit as the aim/pose family: plain C on
 * the `vf3_native_aim` context, no guest SH-4 code at run time.
 *
 * See capsule_chain.c and docs/re/native_capsule_chain.md. */
#ifndef VF3_NATIVE_CAPSULE_CHAIN_H
#define VF3_NATIVE_CAPSULE_CHAIN_H

#include "aim_math.h"

/* Run 0x8C070008.  `owner` is r4 (bytes +96/+97 pick which of the first
 * nodes are skipped), `rec` r5 (the capsule record), `array_end` r6 (one
 * past the last 24-byte node), `part` r7 (an int16 part number, passed as
 * its unsigned halfword and sign-extended inside).  The capsule record:
 *   +0x58 node count, +0x60 link length, +0x74/+0x80 the two axes,
 *   +0x8C/+0x98 the two end points, +0xA8 axis length, +0xAC radius.
 * The nodes are walked from both ends of the array towards the middle; each
 * is tested against the capsule by two stages (end-cap / side / beyond) and
 * then pulled back to its neighbour's link length. */
void vf3_native_capsule_chain(vf3_native_aim *a, uint32_t sp0, uint32_t owner,
                              uint32_t rec, uint32_t array_end, uint16_t part);

#endif /* VF3_NATIVE_CAPSULE_CHAIN_H */
