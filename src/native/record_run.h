/* record_run.h - native port of 0x8C0C1296 (record_run), operating on the
 * `vf3_native_aim` context.  See record_run.c and
 * docs/re/native_record_run.md. */
#ifndef VF3_NATIVE_RECORD_RUN_H
#define VF3_NATIVE_RECORD_RUN_H

#include "aim_math.h"

/* Run 0x8C0C1296 (record_run): a pure-integer leaf.  r4 -> a record; the
 * word at [r4+12] is the base of 120 consecutive 68-byte records, each of
 * which is zero-filled by a call to mem_fill (0x8C095604, natively ported),
 * and then bit 0 is OR-ed into the halfword at [orig r4 + 34].  The whole
 * register file (r0..r7 come from the last mem_fill and the OR; r8..r15 and
 * pr are restored/untouched), SR's T bit and FPUL/FR/XF are the observable
 * contract.  See docs/re/native_record_run.md. */
void vf3_native_record_run(vf3_native_aim *a);

#endif /* VF3_NATIVE_RECORD_RUN_H */
