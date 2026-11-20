/* status_flags.h - native port of the record status flags (0x8C0961F4),
 * operating on the `vf3_native_aim` context.  See status_flags.c and
 * docs/re/native_status_flags.md. */
#ifndef VF3_NATIVE_STATUS_FLAGS_H
#define VF3_NATIVE_STATUS_FLAGS_H

#include "aim_math.h"

/* Run 0x8C0961F4.  Handed a record (r5) and a mask (r4), it reads eight fields
 * of the record and puts one bit in the answer for every field that has a bit
 * in common with the mask.  The first bit is assigned (the answer starts at
 * zero), the rest are or-ed in; the last bit's mask comes out of the literal
 * pool (0x0c09630a), read only when that field hits.  It calls nobody, uses no
 * FPU and keeps **no stack frame**.  See docs/re/native_status_flags.md. */
void vf3_native_status_flags(vf3_native_aim *a);

#endif /* VF3_NATIVE_STATUS_FLAGS_H */
