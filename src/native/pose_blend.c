/* Source-level C for the retail 26-field pose blend at 0x8C091DE6. */
#include "pose_blend.h"

#include <fenv.h>
#include <math.h>
#include <string.h>

enum { Q14_ONE = 0x4000, Q14_SHIFT = 14 };

static int32_t arithmetic_shift_q14(uint32_t value)
{
    if (value & UINT32_C(0x80000000)) {
        const uint32_t magnitude = (~value) + 1u;
        const uint32_t shifted_magnitude =
            (magnitude + ((UINT32_C(1) << Q14_SHIFT) - 1u)) >> Q14_SHIFT;
        return -(int32_t)shifted_magnitude;
    }
    return (int32_t)(value >> Q14_SHIFT);
}

int vf3_native_pose_blend_step(float *weight, float step,
                               const int16_t pose_a[VF3_NATIVE_POSE_BLEND_FIELDS],
                               const int16_t pose_b[VF3_NATIVE_POSE_BLEND_FIELDS],
                               int16_t out[VF3_NATIVE_POSE_BLEND_FIELDS])
{
    int16_t blended[VF3_NATIVE_POSE_BLEND_FIELDS];
    volatile float updated_weight;
    volatile float scaled_weight;
    int32_t b_weight;
    uint32_t a_weight;

    if (!weight || !pose_a || !pose_b || !out)
        return -1;
    if (!isfinite(*weight) || !isfinite(step))
        return -2;

    /* Reproduce the guest FPU's rounding of the weight add and the 16384.0
     * scale.  The readable authority (vf3_pose_blend_entry) folds both
     * through vf3_fpu_binary with the captured FPSCR 0x00040001, whose RM
     * bit 0 selects FE_TOWARDZERO (and whose FTZ flag flushes denormals).
     * Plain C round-to-nearest lands a half-ulp sum one ulp higher - e.g.
     * 0.9f + 0.05f gives 0x3F733333 instead of the reference 0x3F733332 -
     * so the add and scale have to round toward zero to match. */
    {
        const int saved_round = fegetround();
        fesetround(FE_TOWARDZERO);
        updated_weight = *weight + step;
        if (updated_weight > 1.0f)
            updated_weight = 1.0f;
        scaled_weight = updated_weight * 16384.0f;
        fesetround(saved_round);
    }
    if (!isfinite(updated_weight))
        return -2;
    if (!isfinite(scaled_weight) || scaled_weight < -2147483648.0f ||
        scaled_weight >= 2147483648.0f)
        return -2;

    b_weight = (int32_t)scaled_weight; /* C conversion truncates toward zero. */
    a_weight = (uint32_t)Q14_ONE - (uint32_t)b_weight;
    for (size_t i = 0; i < VF3_NATIVE_POSE_BLEND_FIELDS; ++i) {
        const uint32_t sum = (uint32_t)(int32_t)pose_a[i] * a_weight +
                             (uint32_t)(int32_t)pose_b[i] * (uint32_t)b_weight;
        const int32_t value = arithmetic_shift_q14(sum);
        const uint16_t low = (uint16_t)(uint32_t)value;
        memcpy(&blended[i], &low, sizeof low);
    }

    *weight = updated_weight;
    memcpy(out, blended, sizeof blended);
    return 0;
}
