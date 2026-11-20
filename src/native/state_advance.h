/* state_advance.h - native port of the state advance (0x8C06BEA4), operating on
 * the `vf3_native_aim` context.  See state_advance.c and
 * docs/re/native_state_advance.md. */
#ifndef VF3_NATIVE_STATE_ADVANCE_H
#define VF3_NATIVE_STATE_ADVANCE_H

#include "aim_math.h"

/* Run 0x8C06BEA4.  The guest is handed two words - the entry counter at *r4 and
 * the count at *r5 - and a kind in r6.  The counter steps forward by one and
 * wraps at sixteen (only the low four bits are used); when it is at zero the
 * guest counts down instead - the counter restarts at one and the count goes
 * down by one, or with the count at zero both stay at zero.  A byte of kind
 * flags (the pointer to it is in the pool at 0x0c06bfbc) is told about the
 * entry: a table in the pool (0x0c06bfc0) says what kind the entry is, the
 * flags are masked with the mask of the kind in question (0x0c06bfac / a e)
 * and that kind's bit is set only when the table says something.  On the
 * counting path the flags are left alone.
 *
 * The leaf saves r12/r13/r14 on the stack at sp-4/-8/-12 and restores them
 * (r14 in the delay slot of the return), so r15 returns to the entry sp.  The
 * counter and count are written back through r4/r5.  See
 * docs/re/native_state_advance.md. */
void vf3_native_state_advance(vf3_native_aim *a);

#endif /* VF3_NATIVE_STATE_ADVANCE_H */
