/* negate_run.h - native port of the negate-run (0x8C09D408), operating on the
 * `vf3_native_aim` context.
 *
 * See negate_run.c and docs/re/native_negate_run.md. */
#ifndef VF3_NATIVE_NEGATE_RUN_H
#define VF3_NATIVE_NEGATE_RUN_H

#include "aim_math.h"

/* Run 0x8C09D408.  A self-contained leaf (call-free, no stack frame).  It
 * negates 7 + 14 floats at r4+8, r4+20, ... (stride 12); the second run
 * restarts 8 below the first run's end.  Each negation is a sign-bit flip
 * (fneg), so the body is pure integer in native form.  Leaves r4 one past
 * the last written float, r5 = 0 and SR's T bit set.  r0..r3, r6..r15 and pr
 * are untouched.  See docs/re/native_negate_run.md. */
void vf3_native_negate_run(vf3_native_aim *a);

#endif /* VF3_NATIVE_NEGATE_RUN_H */
