/* Native port of the retail fixed-point pose blend at 0x8C091DE6. */
#ifndef VF3_NATIVE_POSE_BLEND_H
#define VF3_NATIVE_POSE_BLEND_H

#include <stddef.h>
#include <stdint.h>

#define VF3_NATIVE_POSE_BLEND_FIELDS 26u

/* Advance `weight` by `step`, cap it at 1.0, convert the updated weight to
 * Q14 with SH-4 truncation toward zero, and blend two signed-halfword poses.
 * Each result is stored as the low 16 bits of the arithmetic-shifted Q14
 * sum, matching the guest's halfword stores. The two pose inputs may overlap
 * the output because results are staged before they are written.
 * Returns -1 for null pointers and -2 for a non-finite or out-of-range
 * weight. On error, `weight` and `out` are left unchanged. */
int vf3_native_pose_blend_step(float *weight, float step,
                               const int16_t pose_a[VF3_NATIVE_POSE_BLEND_FIELDS],
                               const int16_t pose_b[VF3_NATIVE_POSE_BLEND_FIELDS],
                               int16_t out[VF3_NATIVE_POSE_BLEND_FIELDS]);

#endif
