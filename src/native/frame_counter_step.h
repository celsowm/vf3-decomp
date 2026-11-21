/* frame_counter_step.h - native port of 0x8C0CC334 (frame_counter_step),
 * operating on the `vf3_native_aim` context.  See frame_counter_step.c and
 * docs/re/native_frame_counter_step.md. */
#ifndef VF3_NATIVE_FRAME_COUNTER_STEP_H
#define VF3_NATIVE_FRAME_COUNTER_STEP_H

#include "aim_math.h"

/* Run 0x8C0CC334 (frame_counter_step).  A self-contained FP leaf (call-free).
 * r4 -> object (word counter at +0x1E, word table value at +0x1C, floats at
 * +0x10 / +0x0C / +0x14), r5 -> flag word, r6 / r7 -> two halfword tables,
 * [the caller's sp] -> a third, fr4 / fr5 = speeds.  The counter is
 * decremented; if it goes negative only flag bit 0 is cleared.  Otherwise
 * the counter is stored back, its low five bits index a halfword table and
 * the entry goes to +0x1C; the float at +0x10 is advanced by -0.0018 and
 * floored at -0.006; a non-zero fr4 then also moves the floats at +0x0C and
 * +0x14 by fr4 / fr5 times (31 - counter) * 0.032.  See
 * docs/re/native_frame_counter_step.md. */
void vf3_native_frame_counter_step(vf3_native_aim *a);

#endif /* VF3_NATIVE_FRAME_COUNTER_STEP_H */
