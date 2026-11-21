/* segment_delta.h - native port of 0x8C092B4A (segment_delta), operating on
 * the `vf3_native_aim` context.  See segment_delta.c and
 * docs/re/native_segment_delta.md. */
#ifndef VF3_NATIVE_SEGMENT_DELTA_H
#define VF3_NATIVE_SEGMENT_DELTA_H

#include "aim_math.h"

/* Run 0x8C092B4A (segment_delta).  A self-contained FP leaf (call-free, uses
 * a 28-byte frame, saves/restores r14).  r4 = destination record, r5 = second
 * record, r6 = pointer to a scale float, r7 = pointer to a record whose float
 * at +0x14 gates the push.  The caller's stack holds, from sp+0: the two
 * source vectors A / B (words 0 and 1), a third vector (+8) and a flag word
 * (+C).
 *
 *   rec[+0x18 .. +0x20] = A - B
 *   scale = *r6, times 0.65 when flag 0x100 is set
 *   rec[+0x18 .. +0x20] *= scale
 *   unless flag 0x2 is set, or gating[+0x14] is zero (2*float), or r5 is null:
 *       f[0xC .. 0x14] = third * (2 * gating[+0x14])
 *       r5.rec[+0x18 .. +0x20] += f[0xC .. 0x14]
 *
 * See docs/re/native_segment_delta.md. */
void vf3_native_segment_delta(vf3_native_aim *a);

#endif /* VF3_NATIVE_SEGMENT_DELTA_H */
