#ifndef VF3_NATIVE_AIM_STEP_H
#define VF3_NATIVE_AIM_STEP_H

/* Native port of the aim step leaf 0x8C093768 (vf3_native_aim_step). */
#include "aim_math.h"

/* Push a point along the direction between two points.  Runs on
 * `vf3_native_aim`: R(4) -> context (float at +36 is the step length),
 * R(5) -> point A (updated in place), R(6) -> point B, R(7) -> the vec3
 * that receives the unit direction. */
void vf3_native_aim_step(vf3_native_aim *a);

#endif /* VF3_NATIVE_AIM_STEP_H */
