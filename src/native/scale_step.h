/* scale_step.h - native port of the motion-VM scale step (0x8C0CB8AC),
 * operating on the `vf3_native_aim` context.  See scale_step.c and
 * docs/re/native_scale_step.md. */
#ifndef VF3_NATIVE_SCALE_STEP_H
#define VF3_NATIVE_SCALE_STEP_H

#include "aim_math.h"

/* Run 0x8C0CB8AC.  When the VM's mode byte (masked to four bits) is 1, this
 * function takes the step count, makes it a positive number, parks it in
 * FPUL, and writes `constant_two * count + constant_one` into the caller's
 * structure at +16 and into the structure the VM names.  It calls nobody,
 * uses the FR bank and keeps no stack frame.  See docs/re/native_scale_step.md. */
void vf3_native_scale_step(vf3_native_aim *a);

#endif /* VF3_NATIVE_SCALE_STEP_H */
