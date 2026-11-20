/* counter_select.h - native port of the four-threshold counter selection
 * (0x8C0C10A2), operating on the `vf3_native_aim` context.
 *
 * See counter_select.c and docs/re/native_counter_select.md. */
#ifndef VF3_NATIVE_COUNTER_SELECT_H
#define VF3_NATIVE_COUNTER_SELECT_H

#include "aim_math.h"

/* Run 0x8C0C10A2.  A self-contained 124 B leaf, call-free and integer-only
 * (no FP).  r4 is a mask.  The body keeps two running selection counters - r6
 * (even, starts 0) and r5 (odd, starts 4) - and for each of four threshold
 * masks decides which counter to hand out and advances it:
 *
 *   if (mN & r4in) == 0  -> hand out the odd counter, then r5 += 1;
 *   else                 -> hand out the even counter, then r6 += 1.
 *
 * Tests 1..3 advance the counter they hand out; test 4 does NOT advance (it
 * only reads).  It reads base / hw_ce / m1..m4 from the literal pool
 * (0x0c0c11e0, 0x0c0c11ce, 0x0c0c11d0/d2/d4/d6), pushes r14/r13, allocates a
 * 16-byte frame at SP0-24 and writes four 16-bit thresholds at +0x26 into
 * base, base+0x2c, base+0x58 and base+hw_ce.  See
 * docs/re/native_counter_select.md. */
void vf3_native_counter_select(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_COUNTER_SELECT_H */
