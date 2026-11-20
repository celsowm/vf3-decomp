/* negate_copy.h - native port of the negate-copy (0x8C072B02), operating on
 * the `vf3_native_aim` context.
 *
 * See negate_copy.c and docs/re/native_negate_copy.md. */
#ifndef VF3_NATIVE_NEGATE_COPY_H
#define VF3_NATIVE_NEGATE_COPY_H

#include "aim_math.h"

/* Run 0x8C072B02.  A self-contained leaf (call-free, no FPU, no stack frame).
 * r5 -> { count, src, dst }; every entry reads six floats and writes six: the
 * first three copied as they are, the next three with the sign flipped (a
 * fneg, so a NaN keeps its payload and a zero becomes -0).  Leaves r4 = src
 * (one past the last read), r6 = dst (one past the last write), r7 = count
 * (int32, <= 0) and SR's T bit clear.  See docs/re/native_negate_copy.md. */
void vf3_native_negate_copy(vf3_native_aim *a);

#endif /* VF3_NATIVE_NEGATE_COPY_H */
