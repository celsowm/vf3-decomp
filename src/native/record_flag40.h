/* record_flag40.h - native port of the record flag-40 probe (0x8C04B9BE),
 * operating on the `vf3_native_aim` context.
 *
 * See record_flag40.c and docs/re/native_record_flag40.md. */
#ifndef VF3_NATIVE_RECORD_FLAG40_H
#define VF3_NATIVE_RECORD_FLAG40_H

#include "aim_math.h"

/* Run 0x8C04B9BE.  A self-contained leaf (call-free, no FPU, no stack
 * frame).  r4 = a record; reads its first word (the record kind).  If the
 * kind is 1, r0 = 0; else r0 = (byte [[r4+4] + 16] & 0x40) - the byte is
 * read sign-extended, then masked.  r1 is set to 16 on the else path only.
 * SR's T bit is (kind == 1).  r2..r15, the stack pointer and pr are
 * untouched.  See docs/re/native_record_flag40.md. */
void vf3_native_record_flag40(vf3_native_aim *a);

#endif /* VF3_NATIVE_RECORD_FLAG40_H */
