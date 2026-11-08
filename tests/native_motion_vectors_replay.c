/* Replay the native seven-point transform (src/native/motion_vectors.c)
 * against hand-computed cases from 0x8C09DA72:
 *   - yaw rotation (0 and a quarter turn),
 *   - the mode Y drops (6/8/11/12) and their gate on actor +0x48 & 0x29000,
 *   - the 0x20000000 origin subtraction,
 *   - the Y-suppression mask helper (all four tests, each one failing),
 *   - argument validation.
 * Expected values are computed here from the disassembly, not by calling
 * the implementation under test. */
#include "motion_vectors.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static int ok = 1;

static void check_vec(const char *name, const float got[3],
                      const float want[3])
{
    for (size_t i = 0; i < 3; ++i) {
        if (fabsf(got[i] - want[i]) > 1e-5f) {
            fprintf(stderr, "native_motion_vectors: %s axis %zu: got %g want %g\n",
                    name, i, (double)got[i], (double)want[i]);
            ok = 0;
            return;
        }
    }
    printf("  %s: pass\n", name);
}

static void check(int condition, const char *name)
{
    if (!condition) {
        fprintf(stderr, "native_motion_vectors: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

int main(void)
{
    float transform[16];
    float points[VF3_NATIVE_MOTION_POINT_COUNT][VF3_NATIVE_MOTION_POINT_FLOATS];
    /* Channel triples: p0=(1,2,3) p1=(4,5,6) rest zero. */
    float channels[21] = { 1, 2, 3, 4, 5, 6 };
    const float position[3] = { 10.0f, 20.0f, 30.0f };

    /* Yaw 0: identity rotation; mode 11 drops Y by 0.055 when the
     * +0x48 gate (0x29000) is clear. */
    check(vf3_native_motion_actor_transform(0, position, 11, 0,
                                            transform) == 0,
          "actor_transform yaw0 mode11");
    check(vf3_native_motion_points(channels, 0, 0, transform, points) == 0,
          "points yaw0");
    {
        const float want[3] = { 11.0f, 21.945f, 33.0f };
        check_vec("point0 = position + p0 - drop", points[0], want);
        const float want1[3] = { 14.0f, 24.945f, 36.0f };
        check_vec("point1 = position + p1 - drop", points[1], want1);
    }

    /* Same, but the gate word carries 0x29000: no drop. */
    check(vf3_native_motion_actor_transform(0, position, 11, 0x29000u,
                                            transform) == 0,
          "actor_transform gated");
    check(vf3_native_motion_points(channels, 0, 0, transform, points) == 0,
          "points gated");
    {
        const float want[3] = { 11.0f, 22.0f, 33.0f };
        check_vec("point0 no drop when gated", points[0], want);
    }

    /* Every mode drop, from the pool floats at 0x0C09DBF0..FC. */
    {
        static const struct { uint8_t mode; float drop; } drops[] = {
            { 6, 0.0300f }, { 8, 0.0600f }, { 11, 0.0550f }, { 12, 0.0200f }
        };
        for (size_t i = 0; i < sizeof drops / sizeof drops[0]; ++i) {
            char name[64];
            snprintf(name, sizeof name, "mode %u drop", drops[i].mode);
            check(vf3_native_motion_actor_transform(0, position, drops[i].mode,
                                                    0, transform) == 0, name);
            if (fabsf(transform[13] - (20.0f - drops[i].drop)) > 1e-6f) {
                fprintf(stderr,
                        "native_motion_vectors: mode %u: ty=%g want %g\n",
                        drops[i].mode, (double)transform[13],
                        (double)(20.0f - drops[i].drop));
                ok = 0;
            }
        }
        /* An unlisted mode drops nothing. */
        check(vf3_native_motion_actor_transform(0, position, 7, 0,
                                                transform) == 0,
              "mode 7 no drop");
        check(fabsf(transform[13] - 20.0f) <= 1e-6f, "mode 7 ty unchanged");
    }

    /* Quarter turn yaw (16384 = 90 degrees): (x,y,z) -> (z, y, -x). */
    check(vf3_native_motion_actor_transform(16384, position, 0, 0x29000u,
                                            transform) == 0,
          "actor_transform quarter turn");
    check(vf3_native_motion_points(channels, 0, 0, transform, points) == 0,
          "points quarter turn");
    {
        const float want[3] = { 13.0f, 22.0f, 29.0f };
        check_vec("point0 rotated 90deg", points[0], want);
    }

    /* Origin subtraction: every triple has p0 (1,2,3) removed. */
    check(vf3_native_motion_actor_transform(0, position, 0, 0x29000u,
                                            transform) == 0,
          "actor_transform origin");
    check(vf3_native_motion_points(channels, 1, 0, transform, points) == 0,
          "points origin");
    {
        const float want[3] = { 10.0f, 20.0f, 30.0f };
        check_vec("point0 is the origin itself", points[0], want);
        const float want1[3] = { 13.0f, 23.0f, 33.0f };
        check_vec("point1 minus point0", points[1], want1);
    }

    /* Y-suppression mask: the four guest tests, each one failing alone. */
    check(vf3_native_motion_zero_y_mask(0x00040000u, 0x00021000u, 0x800u)
              == 0x7fu,
          "zero_y all tests hold");
    check(vf3_native_motion_zero_y_mask(0x00040000u, 0x00021000u, 0u) == 0,
          "zero_y global clear");
    check(vf3_native_motion_zero_y_mask(0x00048000u, 0x00021000u, 0x800u) == 0,
          "zero_y actor 0x8000 set (bf arm)");
    check(vf3_native_motion_zero_y_mask(0u, 0x00021000u, 0x800u) == 0,
          "zero_y actor 0x40000 clear");
    check(vf3_native_motion_zero_y_mask(0x00040000u, 0u, 0x800u) == 0,
          "zero_y pose clear");

    /* And the mask the helper returns actually zeroes Y. */
    check(vf3_native_motion_actor_transform(0, position, 0, 0x29000u,
                                            transform) == 0,
          "actor_transform zero_y fixture");
    check(vf3_native_motion_points(channels, 0, 0x7fu, transform, points) == 0,
          "points zero_y");
    {
        const float want[3] = { 11.0f, 20.0f, 33.0f };
        check_vec("point0 Y zeroed, X/Z kept", points[0], want);
    }

    /* Argument validation. */
    check(vf3_native_motion_actor_transform(0, NULL, 0, 0, transform) == -1,
          "null position rejected");
    check(vf3_native_motion_actor_transform(0, position, 0, 0, NULL) == -1,
          "null transform rejected");
    {
        const float bad_position[3] = { 0.0f, NAN, 0.0f };
        check(vf3_native_motion_actor_transform(0, bad_position, 0, 0,
                                                transform) == -2,
              "non-finite position rejected");
    }
    check(vf3_native_motion_points(NULL, 0, 0, transform, points) == -1,
          "null channels rejected");
    check(vf3_native_motion_points(channels, 0, 0, NULL, points) == -1,
          "null matrix rejected");
    {
        float bad_channels[21];
        memcpy(bad_channels, channels, sizeof bad_channels);
        bad_channels[7] = INFINITY;
        check(vf3_native_motion_points(bad_channels, 0, 0, transform,
                                       points) == -2,
              "non-finite channel rejected");
    }

    if (!ok) return 1;
    puts("native_motion_vectors_replay: PASS");
    return 0;
}
