/* Finite capsule contact geometry for the native fight runtime.
 *
 * VF3's readable hitbox_overlap routine scans 28 capsule pairs per fighter,
 * after applying character participation masks and radius scaling. This
 * module ports the geometric query behind that scan into ordinary C data.
 * Actor layout, per-character masks and radius-table selection remain in the
 * caller, so the standalone path has no guest memory dependency.
 */
#include "collision.h"

#include <math.h>
#include <string.h>

static float dot3(const float a[3], const float b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

static float clamp01(float value)
{
    if (value < 0.0f) return 0.0f;
    if (value > 1.0f) return 1.0f;
    return value;
}

static int valid_capsule(const vf3_native_capsule *capsule)
{
    if (!capsule || !isfinite(capsule->radius) || capsule->radius < 0.0f)
        return 0;
    for (size_t axis = 0; axis < 3; ++axis)
        if (!isfinite(capsule->first[axis]) ||
            !isfinite(capsule->second[axis]))
            return 0;
    return 1;
}

/* Squared distance between two closed line segments. Handles point capsules
 * and parallel segments without dividing by a zero-length denominator. */
static float segment_distance_squared(const vf3_native_capsule *a,
                                      const vf3_native_capsule *b)
{
    float d1[3], d2[3], r[3];
    for (size_t axis = 0; axis < 3; ++axis) {
        d1[axis] = a->second[axis] - a->first[axis];
        d2[axis] = b->second[axis] - b->first[axis];
        r[axis] = a->first[axis] - b->first[axis];
    }

    const float aa = dot3(d1, d1);
    const float ee = dot3(d2, d2);
    const float ff = dot3(d2, r);
    float s = 0.0f, t = 0.0f;

    if (aa <= 0.0f && ee <= 0.0f) {
        /* Both capsules reduce to spheres. */
    } else if (aa <= 0.0f) {
        t = clamp01(ff / ee);
    } else {
        const float cc = dot3(d1, r);
        if (ee <= 0.0f) {
            s = clamp01(-cc / aa);
        } else {
            const float bb = dot3(d1, d2);
            const float denominator = aa * ee - bb * bb;
            if (denominator > 0.0f)
                s = clamp01((bb * ff - cc * ee) / denominator);
            t = (bb * s + ff) / ee;
            if (t < 0.0f) {
                t = 0.0f;
                s = clamp01(-cc / aa);
            } else if (t > 1.0f) {
                t = 1.0f;
                s = clamp01((bb - cc) / aa);
            }
        }
    }

    float delta[3];
    for (size_t axis = 0; axis < 3; ++axis)
        delta[axis] = r[axis] + s * d1[axis] - t * d2[axis];
    return dot3(delta, delta);
}

int vf3_native_capsule_collide(
    const vf3_native_capsule *a, size_t a_count,
    const vf3_native_capsule *b, size_t b_count,
    vf3_native_collision_result *out)
{
    vf3_native_collision_result result;
    int found_pair = 0;

    if (!out || a_count > VF3_NATIVE_CAPSULE_LIMIT ||
        b_count > VF3_NATIVE_CAPSULE_LIMIT ||
        (a_count && !a) || (b_count && !b))
        return -1;
    for (size_t i = 0; i < a_count; ++i)
        if (!valid_capsule(&a[i])) return -1;
    for (size_t j = 0; j < b_count; ++j)
        if (!valid_capsule(&b[j])) return -1;

    memset(&result, 0, sizeof result);
    result.minimum_surface_gap = 0.0f;
    for (size_t i = 0; i < a_count; ++i) {
        if (!a[i].enabled) continue;
        for (size_t j = 0; j < b_count; ++j) {
            if (!b[j].enabled) continue;
            const float radius = a[i].radius + b[j].radius;
            const float distance_squared = segment_distance_squared(&a[i], &b[j]);
            const float surface_gap = sqrtf(distance_squared) - radius;
            if (!found_pair || surface_gap < result.minimum_surface_gap) {
                result.minimum_surface_gap = surface_gap;
                found_pair = 1;
            }
            if (distance_squared > radius * radius) continue;
            result.a_hits[i] |= (uint32_t)1u << j;
            result.b_hits[j] |= (uint32_t)1u << i;
            ++result.overlap_pairs;
        }
    }

    if (!found_pair)
        result.minimum_surface_gap = 0.0f;
    *out = result;
    return 0;
}
