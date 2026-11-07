/* Native 3D capsule collision core used by the fighter contact path. */
#ifndef VF3_NATIVE_COLLISION_H
#define VF3_NATIVE_COLLISION_H

#include <stddef.h>
#include <stdint.h>

#define VF3_NATIVE_CAPSULE_LIMIT 28u
#define VF3_NATIVE_CAPSULE_KIND_COUNT 13u

typedef struct {
    float first[3];
    float second[3];
    float radius;
    uint8_t enabled;
    uint8_t distance_excluded;
} vf3_native_capsule;

typedef struct {
    /* Bit j is set when A capsule i overlaps B capsule j, and vice versa. */
    uint32_t a_hits[VF3_NATIVE_CAPSULE_LIMIT];
    uint32_t b_hits[VF3_NATIVE_CAPSULE_LIMIT];
    uint32_t overlap_pairs;
    /* Smallest signed surface gap over enabled pairs; negative means overlap. */
    float minimum_surface_gap;
} vf3_native_collision_result;

/* Apply the retail actor's radius profile to 28 already-built segments.
 * `radius_kind` is actor byte +97; `mask_kind` is actor byte +0x1a20.
 * `actor_flags` is actor word +0x1a04, `actor_word76` is actor word +76,
 * and `radius_mode` is actor byte +0x1560. If radius_mode bit 1 is set,
 * existing capsule radii are preserved. Geometry and enabled flags are
 * preserved. The operation is atomic on invalid input. */
int vf3_native_capsule_apply_actor_profile(
    vf3_native_capsule capsules[VF3_NATIVE_CAPSULE_LIMIT],
    uint8_t radius_kind, uint8_t mask_kind,
    uint32_t actor_flags, uint32_t actor_word76, uint8_t radius_mode);

/* Test the finite capsule sets used by VF3's 28-per-fighter contact scan.
 * `distance_excluded` only filters a capsule pair from the minimum-distance
 * accumulator; enabled pairs still produce contact hits. On invalid input,
 * returns -1 and leaves `out` unchanged. */
int vf3_native_capsule_collide(
    const vf3_native_capsule *a, size_t a_count,
    const vf3_native_capsule *b, size_t b_count,
    vf3_native_collision_result *out);

#endif
