/* tenpp_fill.h - native port of the tenpp leaf structure filler (0x8C0C103C),
 * operating on the `vf3_native_aim` context.
 *
 * See tenpp_fill.c and docs/re/native_tenpp_fill.md. */
#ifndef VF3_NATIVE_TENPP_FILL_H
#define VF3_NATIVE_TENPP_FILL_H

#include "aim_math.h"

/* Run 0x8C0C103C.  A self-contained 72 B leaf, call-free, no FPU, no stack
 * frame.  r4 is a node structure, r5 an auxiliary cell.  It fills the node
 * with a fixed pattern (five 0xff bytes at +16..+20, cleared halfwords
 * +22..+30 and +32..+40, cleared words +44..+60) and clears the cell word at
 * r5+20.  The scan leaves r0 = 0x28, r3 = r4+16, r5 = -1 (the widened 0xff)
 * and r6 = 0; r4 and the stack pointer and every other register and all of SR
 * are untouched.  The return is a tail jump through r16 (caller's return
 * address).  See docs/re/native_tenpp_fill.md. */
void vf3_native_tenpp_fill(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_TENPP_FILL_H */
