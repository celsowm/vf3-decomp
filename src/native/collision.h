/* Native 3D capsule collision core used by the fighter contact path. */
#ifndef VF3_NATIVE_COLLISION_H
#define VF3_NATIVE_COLLISION_H

#include <stddef.h>
#include <stdint.h>

#define VF3_NATIVE_CAPSULE_LIMIT 28u

typedef struct {
    float first[3];
    float second[3];
    float radius;
    uint8_t enabled;
} vf3_native_capsule;

typedef struct {
    /* Bit j is set when A capsule i overlaps B capsule j, and vice versa. */
    uint32_t a_hits[VF3_NATIVE_CAPSULE_LIMIT];
    uint32_t b_hits[VF3_NATIVE_CAPSULE_LIMIT];
    uint32_t overlap_pairs;
    /* Smallest signed surface gap over enabled pairs; negative means overlap. */
    float minimum_surface_gap;
} vf3_native_collision_result;

/* Test the finite capsule sets used by VF3's 28-per-fighter contact scan.
 * The caller supplies the already-selected capsules and their radii; this
 * routine does not infer actor records, character masks, or radius tables.
 * On invalid input, returns -1 and leaves `out` unchanged. */
int vf3_native_capsule_collide(
    const vf3_native_capsule *a, size_t a_count,
    const vf3_native_capsule *b, size_t b_count,
    vf3_native_collision_result *out);

#endif
