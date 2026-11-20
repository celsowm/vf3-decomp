/* state_flag.h - native port of the fight engine's state flag (0x8C0B0FD2),
 * operating on the `vf3_native_aim` context.  See state_flag.c and
 * docs/re/native_state_flag.md. */
#ifndef VF3_NATIVE_STATE_FLAG_H
#define VF3_NATIVE_STATE_FLAG_H

#include "aim_math.h"

/* Run 0x8C0B0FD2.  The caller hands the state word (r7), the structure with
 * the value (r5), the offset the value is measured from (r6) and the
 * structure with the two parity words (r4).  The word at r7 carries one of
 * two bits - or nothing - depending on the band the signed value falls into
 * and one parity bit.  It calls nobody, uses no FPU (but reads the pool and
 * the T bit) and keeps **no stack frame**.  See docs/re/native_state_flag.md. */
void vf3_native_state_flag(vf3_native_aim *a);

#endif /* VF3_NATIVE_STATE_FLAG_H */
