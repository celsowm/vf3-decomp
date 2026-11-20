/* count_leading.h - native port of the leading-zero count (0x8C0769C6),
 * operating on the `vf3_native_aim` context.
 *
 * See count_leading.c and docs/re/native_count_leading.md. */
#ifndef VF3_NATIVE_COUNT_LEADING_H
#define VF3_NATIVE_COUNT_LEADING_H

#include "aim_math.h"

/* Run 0x8C0769C6.  A self-contained leaf (call-free, no FPU, no stack frame,
 * no RAM).  r4 = the word; returns r0 = the number of high bits clear before
 * the first set one (32 for zero).  A probe bit starts at bit 31 and walks
 * down; r6 counts the bits passed, r5 is the probe left over, r3 a copy of
 * r4.  r4 and the stack pointer and every other register are untouched.  The
 * return pops pr (the caller's return address).  See
 * docs/re/native_count_leading.md. */
void vf3_native_count_leading(vf3_native_aim *a);

#endif /* VF3_NATIVE_COUNT_LEADING_H */
