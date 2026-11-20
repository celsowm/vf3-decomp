/* pair_verdict.h - native port of the two-structure verdict (0x8C074E7C),
 * operating on the `vf3_native_aim` context.  See pair_verdict.c and
 * docs/re/native_pair_verdict.md. */
#ifndef VF3_NATIVE_PAIR_VERDICT_H
#define VF3_NATIVE_PAIR_VERDICT_H

#include "aim_math.h"

/* Run 0x8C074E7C.  The caller hands over two structures (r4 and r5).  The
 * function writes a word into the first structure: zero, or minus one,
 * following the guest's own decision tree (so the T bit it leaves is the one
 * of the last test it made).  It calls nobody, uses no FPU, and keeps a
 * frame in which it saves r13.  See docs/re/native_pair_verdict.md. */
void vf3_native_pair_verdict(vf3_native_aim *a);

#endif /* VF3_NATIVE_PAIR_VERDICT_H */
