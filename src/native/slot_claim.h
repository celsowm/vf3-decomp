/* slot_claim.h - native port of the slot-claim scan (0x8C062490), operating
 * on the `vf3_native_aim` context.
 *
 * See slot_claim.c and docs/re/native_slot_claim.md. */
#ifndef VF3_NATIVE_SLOT_CLAIM_H
#define VF3_NATIVE_SLOT_CLAIM_H

#include "aim_math.h"

/* Run 0x8C062490.  A call-free, integer-only, no-stack leaf (it tail-returns
 * through r16 and never touches r15).  It reads two parameters from the pool
 * - base = [0x0c062590], count = (int16)[0x0c06258a] - and scans `count`
 * 0x18-byte slots whose 16-bit tag at the slot start is read and masked to 16
 * bits, marking the first slot whose low bit is clear by writing 1 (u16) to
 * it and answering with its address in r0; with no free slot inside `count`
 * it answers r0 = 0.  The loop is a do-while (no pre-loop guard), so the
 * first slot is always tested even when count <= 0.  See
 * docs/re/native_slot_claim.md. */
void vf3_native_slot_claim(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_SLOT_CLAIM_H */
