/* max_walk.h - native port of the four-list gated max walk (0x8C061910),
 * operating on the `vf3_native_aim` context.
 *
 * See max_walk.c and docs/re/native_max_walk.md. */
#ifndef VF3_NATIVE_MAX_WALK_H
#define VF3_NATIVE_MAX_WALK_H

#include "aim_math.h"

/* Run 0x8C061910.  r4 = the first output word's address, r5 = the second.
 * The fight structure's address is read from the literal pool at 0x0c061a0c.
 * Four linked lists are searched over [node + 16] (the value), stepping a
 * node by its [+8] word (next); lists B and D only let a node compete while
 * (node.gate & 4) == 0.  [r4] = r7 = max of (A at st+8, ungated) then
 * (B at st, gated); [r5] = r14 = max of (C at st+0x1c, ungated) then
 * (D at st+0x14, gated).  Both maxima start at 0.  The entry r12/r13/r14 are
 * restored, r15 is net flat, and the body leaves r0 = 0, r1 = the last gated
 * value read, r2 = the last gate/next read, r6 = 0 and SR's T bit set. */
void vf3_native_max_walk(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_MAX_WALK_H */
