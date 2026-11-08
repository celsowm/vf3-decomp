/* The first 21 MT channels feed 0x8C09DA72's seven point transform loop. */
#include "motion_vectors.h"

#include "matrix.h"

#include <math.h>
#include <string.h>

int vf3_native_motion_actor_transform(
    uint16_t actor_yaw,
    const float actor_position[3],
    uint8_t actor_mode,
    uint32_t actor_pose_flags,
    float world_from_actor[16])
{
    static const struct {
        uint8_t mode;
        float drop;
    } mode_drops[] = {
        { 6, 0.0300f },
        { 8, 0.0600f },
        { 11, 0.0550f },
        { 12, 0.0200f },
    };
    float transform[16];
    float drop = 0.0f;

    if (!actor_position || !world_from_actor)
        return -1;
    for (size_t axis = 0; axis < 3; ++axis)
        if (!isfinite(actor_position[axis]))
            return -2;

    if (!(actor_pose_flags & 0x00029000u)) {
        for (size_t i = 0; i < sizeof mode_drops / sizeof mode_drops[0]; ++i) {
            if (mode_drops[i].mode == actor_mode) {
                drop = mode_drops[i].drop;
                break;
            }
        }
    }

    const float radians = (float)((double)actor_yaw *
                                  (6.28318530717958647692 / 65536.0));
    const float sine = sinf(radians);
    const float cosine = cosf(radians);
    vf3_native_matrix_identity(transform);
    transform[0] = cosine;
    transform[2] = -sine;
    transform[8] = sine;
    transform[10] = cosine;
    transform[12] = actor_position[0];
    transform[13] = actor_position[1] - drop;
    transform[14] = actor_position[2];
    memcpy(world_from_actor, transform, sizeof transform);
    return 0;
}

uint8_t vf3_native_motion_zero_y_mask(
    uint32_t actor_flags_word0,
    uint32_t actor_pose_flags_at_0x48,
    uint32_t global_pose_flags_at_0x0c29bccc)
{
    /* 0x0C09DB70..0x0C09DB92: bt/s, bf, bt, bt against the pools at
     * 0x0C09DBEC (0x800), 0x0C09DC14 (0x8000), 0x0C09DC24 (0x40000) and
     * 0x0C09DC18 (0x21000). The bf is the odd one out: it is the only
     * test that must see its bit clear. */
    if ((global_pose_flags_at_0x0c29bccc & 0x00000800u) == 0)
        return 0;
    if ((actor_flags_word0 & 0x00008000u) != 0)
        return 0;
    if ((actor_flags_word0 & 0x00040000u) == 0)
        return 0;
    if ((actor_pose_flags_at_0x48 & 0x00021000u) == 0)
        return 0;
    return (uint8_t)((1u << VF3_NATIVE_MOTION_POINT_COUNT) - 1u);
}

int vf3_native_motion_points(
    const float channels[21],
    int use_first_channel_as_origin,
    uint8_t zero_y_mask,
    const float world_from_actor[16],
    float out[VF3_NATIVE_MOTION_POINT_COUNT][VF3_NATIVE_MOTION_POINT_FLOATS])
{
    float points[VF3_NATIVE_MOTION_POINT_COUNT][VF3_NATIVE_MOTION_POINT_FLOATS];

    if (!channels || !world_from_actor || !out)
        return -1;
    for (size_t i = 0; i < 21; ++i)
        if (!isfinite(channels[i]))
            return -2;
    for (size_t i = 0; i < 16; ++i)
        if (!isfinite(world_from_actor[i]))
            return -2;

    for (size_t point = 0; point < VF3_NATIVE_MOTION_POINT_COUNT; ++point) {
        float local[3];
        for (size_t axis = 0; axis < 3; ++axis) {
            const float origin = use_first_channel_as_origin
                ? channels[axis] : 0.0f;
            local[axis] = channels[point * 3 + axis] - origin;
        }
        if (zero_y_mask & (uint8_t)(1u << point))
            local[1] = 0.0f;
        vf3_native_matrix_transform_point(world_from_actor, local,
                                          points[point]);
    }
    memcpy(out, points, sizeof points);
    return 0;
}
