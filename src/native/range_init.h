/* range_init.h - native port of the structure init (0x8C036A58), operating on
 * the `vf3_native_aim` context.  See range_init.c and
 * docs/re/native_range_init.md. */
#ifndef VF3_NATIVE_RANGE_INIT_H
#define VF3_NATIVE_RANGE_INIT_H

#include "aim_math.h"

/* Run 0x8C036A58.  Set up the forty-four byte structure at r4: mostly zeroed,
 * but four words in the middle (at +8/+12/+16/+20) carry a range whose shape
 * depends on the first word of whatever the pool at 0x0c036af0 points at -
 * `0, -1, 0, 0` when that word is zero, `-1, 0, -1, -1` when it is not.  The
 * word that lands at the structure's +36 comes from the pool at 0x0c036b0c.
 *
 * This leaf calls nobody, uses no FPU and keeps **no stack** at all; its whole
 * effect is the writes plus the register file (r0..r6).  The T bit is set on
 * the zero path and clear on the non-zero path.  See
 * docs/re/native_range_init.md. */
void vf3_native_range_init(vf3_native_aim *a);

#endif /* VF3_NATIVE_RANGE_INIT_H */
