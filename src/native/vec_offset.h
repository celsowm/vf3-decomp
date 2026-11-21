/* vec_offset.h - native ports of the offset-adders (0x8C074702 vec_offset,
 * 0x8C074854 vec_offset3), operating on the `vf3_native_aim` context.
 *
 * See vec_offset.c and docs/re/native_vec_offset.md. */
#ifndef VF3_NATIVE_VEC_OFFSET_H
#define VF3_NATIVE_VEC_OFFSET_H

#include "aim_math.h"

/* Run 0x8C074702 (vec_offset).  A self-contained FP leaf (call-free, no stack
 * frame).  r4 = record.  The offset is the two floats at +0x13A8 (x) and
 * +0x13B0 (z); the record's own position at +0x1488 / +0x1490 gets it added,
 * then every point of the list that begins at the pointer stored at +0x138C
 * (0x150 bytes of 12-byte points) gets the same offset on x (+0) and z (+8).
 * Leaves r0 = 8 (a non-empty list), r5 = one past the list, r6 = the same,
 * and SR's T bit set.  See docs/re/native_vec_offset.md. */
void vf3_native_vec_offset(vf3_native_aim *a);

/* Run 0x8C074854 (vec_offset3).  A self-contained FP leaf (call-free, no
 * stack frame).  r4 = record.  The offset is the three floats at
 * +0x1488 .. +0x1490; the record's own vector at +0x10 .. +0x18 gets it added,
 * then the 25 points of 64 bytes each starting at +0x180 get it added at
 * +0x30 / +0x34 / +0x38.  Leaves r0 = 56 (the list's z slot), r5 = one past
 * the list, r6 = the same (the list end), and SR's T bit set.  See
 * docs/re/native_vec_offset.md. */
void vf3_native_vec_offset3(vf3_native_aim *a);

#endif /* VF3_NATIVE_VEC_OFFSET_H */
