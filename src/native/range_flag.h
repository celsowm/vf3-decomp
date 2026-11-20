/* range_flag.h - native port of the out-of-range flag (0x8C0CAA9C),
 * operating on the `vf3_native_aim` context.  See range_flag.c and
 * docs/re/native_range_flag.md. */
#ifndef VF3_NATIVE_RANGE_FLAG_H
#define VF3_NATIVE_RANGE_FLAG_H

#include "aim_math.h"

/* Run 0x8C0CAA9C.  The caller hands over a record (r4) that holds a byte of
 * flags and four floats.  This function sets the byte's 0x10 bit when one of
 * the four floats is outside the range the two bounds describe, and clears it
 * again when they are all inside - but only when the byte's own 0x40 bit says
 * the values have to be looked at.  It calls nobody, uses the FR bank and
 * keeps **no stack frame**.  See docs/re/native_range_flag.md. */
void vf3_native_range_flag(vf3_native_aim *a);

#endif /* VF3_NATIVE_RANGE_FLAG_H */
