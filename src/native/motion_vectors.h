/* Native reconstruction of the seven point outputs written by 0x8C09DA72. */
#ifndef VF3_NATIVE_MOTION_VECTORS_H
#define VF3_NATIVE_MOTION_VECTORS_H

#include <stdint.h>

enum {
    VF3_NATIVE_MOTION_POINT_COUNT = 7,
    VF3_NATIVE_MOTION_POINT_FLOATS = 3
};

/* Build the affine transform prepared by 0x8C09DA72 from the actor yaw at
 * +0x1E, position at +0x10, mode byte at +97 and flags at +72. */
int vf3_native_motion_actor_transform(
    uint16_t actor_yaw,
    const float actor_position[3],
    uint8_t actor_mode,
    uint32_t actor_pose_flags,
    float world_from_actor[16]);

/* The per-point Y-suppression the 0x8C09DA72 loop applies at 0x0C09DB70..
 * 0x0C09DB92. Four tests, all of which must hold before the loop stores its
 * zeroed Y (fr15) at sp+28 for a point:
 *   *global at 0x0C29BCCC & 0x800   (bt/s skips when the bit is clear)
 *   actor word0 & 0x8000 == 0       (bf skips when the bit is set: bf
 *                                    branches when T is clear, and tst
 *                                    leaves T clear exactly when set)
 *   actor word0 & 0x40000           (bt skips when clear)
 *   actor +0x48   & 0x21000         (bt skips when clear)
 * The tests do not depend on the point index, so the mask is either every
 * point (0x7F) or none (0). No captured timeline exercises this arm (the
 * global bit is clear in every retained sample), so its value rests on the
 * disassembly, not on a capture. */
uint8_t vf3_native_motion_zero_y_mask(
    uint32_t actor_flags_word0,
    uint32_t actor_pose_flags_at_0x48,
    uint32_t global_pose_flags_at_0x0c29bccc);

/* Convert the first seven MT vec3 channels into the seven points consumed by
 * the attachment builder. `use_first_channel_as_origin` mirrors the actor's
 * 0x20000000 flag: when set, channel[0..2] is subtracted from every triple.
 * `zero_y_mask` carries the conditional per-loop Y suppression selected by
 * the retail global/action flags (see vf3_native_motion_zero_y_mask). `world_from_actor` is the caller transform
 * after 0x8C09DA72 retains its translation and rebuilds rotation from the
 * actor yaw at +0x1E. The result is written only after all inputs validate. */
int vf3_native_motion_points(
    const float channels[21],
    int use_first_channel_as_origin,
    uint8_t zero_y_mask,
    const float world_from_actor[16],
    float out[VF3_NATIVE_MOTION_POINT_COUNT][VF3_NATIVE_MOTION_POINT_FLOATS]);

#endif
