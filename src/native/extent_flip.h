/* extent_flip.h - native port of 0x8C0CC3F0 (extent_flip), operating on the
 * `vf3_native_aim` context.  See extent_flip.c and
 * docs/re/native_extent_flip.md. */
#ifndef VF3_NATIVE_EXTENT_FLIP_H
#define VF3_NATIVE_EXTENT_FLIP_H

#include "aim_math.h"

/* Run 0x8C0CC3F0 (extent_flip).  A self-contained FP leaf (call-free, no
 * stack frame).  r4 -> six floats (a0 a1 a2 b0 b1 b2), r5 -> a flag word,
 * fr4 = a limit.  Writes a0 = a0+b0, a1 = a1+b1, a2 = a2+b2 (the sign
 * flipped twice), and unless the flag word's bit 1 is set, floors a1+b1 at
 * fr4 (replacing it and clearing flag bit 0).  See
 * docs/re/native_extent_flip.md. */
void vf3_native_extent_flip(vf3_native_aim *a);

#endif /* VF3_NATIVE_EXTENT_FLIP_H */
