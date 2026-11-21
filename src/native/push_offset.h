#ifndef VF3_NATIVE_PUSH_OFFSET_H
#define VF3_NATIVE_PUSH_OFFSET_H

/* Native port of the scaled-offset push helper 0x8C056B20
 * (vf3_native_push_offset). */
#include "aim_math.h"

/* Push one scaled 2D offset onto a descending record.
 *
 *   r8 = source (two int16 at +0x0E, +0x10), r12 = record cursor (+0x30),
 *   r6 and FR12..FR15 = values, FR3 = scale.
 *
 * Writes [r12+30]..[r12+18] and [r12'+14]..[r12'+28] with r12' = r12+0x20 on
 * return; r0 = 0.  Tail-transfer to pr (untouched). */
void vf3_native_push_offset(vf3_native_aim *a);

#endif /* VF3_NATIVE_PUSH_OFFSET_H */
