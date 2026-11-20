/* clamp_pair.h - native port of the clamp pair (0x8C08DCB0), operating on the
 * `vf3_native_aim` context.  See clamp_pair.c and docs/re/native_clamp_pair.md. */
#ifndef VF3_NATIVE_CLAMP_PAIR_H
#define VF3_NATIVE_CLAMP_PAIR_H

#include "aim_math.h"

/* Run 0x8C08DCB0.  Limit two numbers (r4 and r5) into three ranges and write
 * four results: the first number into the range [pool 0x0c08dd48, a] into r6
 * and *(entry sp+0)'s pointer, the second into [0x0c08dd4c, ...] into r7, and
 * the second again into [0x0c08dd50, ...] into *(entry sp+4)'s pointer.  The
 * two latter destination *addresses* sit in the caller's frame (entry sp+0 and
 * sp+4); the leaf reads them after its own two-word push.
 *
 * The low bound is tested first, so a value below the low bound is never
 * tested against the high one.  The T bit the caller sees is the one of the
 * last comparison.  The leaf saves r13/r14 at sp-4/-8, so r15 returns to the
 * entry sp.  It calls nobody and uses no FPU.  See
 * docs/re/native_clamp_pair.md. */
void vf3_native_clamp_pair(vf3_native_aim *a);

#endif /* VF3_NATIVE_CLAMP_PAIR_H */
