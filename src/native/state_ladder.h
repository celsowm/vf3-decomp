/* state_ladder.h - native port of the fight-state ladder (0x8C08B89C),
 * operating on the `vf3_native_aim` context.  See state_ladder.c and
 * docs/re/native_state_ladder.md. */
#ifndef VF3_NATIVE_STATE_LADDER_H
#define VF3_NATIVE_STATE_LADDER_H

#include "motion_aim.h"

/* Run 0x8C08B89C.  The second half of the counter updater: the caller hands
 * it a task struct (r4) and a frame (r5), and it folds six flag bits into the
 * frame's word at F+0 and steps the task's counters.  A self-contained
 * integer leaf with a single float copying through FR3; runs under
 * single-precision, round-to-nearest, no FTZ (FPSCR 0). */
void vf3_native_state_ladder(vf3_native_aim *a);

#endif /* VF3_NATIVE_STATE_LADDER_H */
