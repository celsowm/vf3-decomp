#ifndef VF3_NATIVE_MOTION_STATE_CHECK_H
#define VF3_NATIVE_MOTION_STATE_CHECK_H

/* Native port of the motion state field checker 0x8C0355CA
 * (vf3_native_motion_state_check). */
#include "aim_math.h"

/* Check a motion state field and conditionally tail-transfer.
 *
 *   R(4) -> the state record (may be 0), R(5) -> the destination pointer.
 *
 * If R(4) == 0, answers r0 = 0.  Otherwise reads the sign-extended halfword
 * at R(4)+0x48: if it is zero, answers r0 = 0 (r3 = 0x48 had been set but is
 * overwritten to 0 first).  Otherwise reads the word at R(4)+12 and stores it
 * through *R(5), answering r0 = 1.  Every path is a tail transfer to pr
 * (r16), so pr is left untouched and the C port simply returns.
 */
void vf3_native_motion_state_check(vf3_native_aim *a);

#endif /* VF3_NATIVE_MOTION_STATE_CHECK_H */
