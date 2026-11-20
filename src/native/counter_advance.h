/* counter_advance.h - native port of the animation frame counters (0x8C08B338),
 * operating on the `vf3_native_aim` context.  See counter_advance.c and
 * docs/re/native_counter_advance.md. */
#ifndef VF3_NATIVE_COUNTER_ADVANCE_H
#define VF3_NATIVE_COUNTER_ADVANCE_H

#include "aim_math.h"

/* Run 0x8C08B338.  Advance the three counters in a record (r4) - seven bits at
 * +12, two at +14, four at +16 - and one in a block (reached through the pool
 * at 0x0c08b3f4, at +0x54, wrapping at 127), but only when the value the
 * global at 0x0c08b3f0 points at has *no* bit in common with the mask at
 * 0x0c08b3ec.  The low bit of the *incremented* wide counter is carried into
 * the narrow counters and into the block's counter, so the wide counter's own
 * wrap (127 to zero) carries nothing.
 *
 * On the gated path the T bit is set and nothing else changes.  Otherwise the
 * leaf leaves r0, r1, r2, r3, r5, r6 and r7 and the three halfword writes.  It
 * calls nobody, uses no FPU and keeps **no stack frame**.  The T bit the caller
 * sees is the block wrap comparison's.  See docs/re/native_counter_advance.md. */
void vf3_native_counter_advance(vf3_native_aim *a);

#endif /* VF3_NATIVE_COUNTER_ADVANCE_H */
