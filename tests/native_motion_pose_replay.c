/* Replay the native MT->attachment fold (src/native/motion_pose.c).
 *
 * The bind skeletons are authored (they are not captured state), so this
 * test pins only what the evidence pins down:
 *   - the measured parent/group links: rows 2/0 (group 3), 5/4 (group 5),
 *     6/0 (group 6) and 9/8 (group 8), recovered with zero orientation
 *     error by tools/native_attachment_parent_fit.py on the state-47
 *     timeline and reproduced independently for Akira;
 *   - the provisional wrap links: rows 14/0 (group 11) and 17/0 (group 13);
 *   - each link's row actually moves when its own group moves, and a row
 *     outside that row's subtree does not;
 *   - argument validation.
 * It deliberately does not assert the authored bind joints: those are a
 * tunable mannequin, not recovered data. */
#include "motion_pose.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static int ok = 1;

static void check(int condition, const char *name)
{
    if (!condition) {
        fprintf(stderr, "native_motion_pose: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

static int rotation_differs(const float a[16], const float b[16])
{
    for (size_t i = 0; i < 12; ++i)
        if (fabsf(a[i] - b[i]) > 1e-5f)
            return 1;
    return 0;
}

static int matrix_all_finite(const float m[16])
{
    for (size_t i = 0; i < 16; ++i)
        if (!isfinite(m[i]))
            return 0;
    return 1;
}

int main(void)
{
    static float base[VF3_NATIVE_ATTACHMENT_COUNT]
                      [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS];
    static float moved[VF3_NATIVE_ATTACHMENT_COUNT]
                       [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS];
    int16_t zero_fields[VF3_NATIVE_POSE_FIELDS] = { 0 };

    for (size_t rig = 0; rig < 2; ++rig) {
        const vf3_native_motion_rig which =
            rig == 0 ? VF3_NATIVE_MOTION_RIG_AKIRA
                     : VF3_NATIVE_MOTION_RIG_JACKY;
        char rig_name[32];
        snprintf(rig_name, sizeof rig_name, "%s",
                 rig == 0 ? "akira" : "jacky");
        check(vf3_native_motion_pose_fields(zero_fields, which, base) == 0,
              rig_name);
        for (uint32_t row = 0; row < VF3_NATIVE_ATTACHMENT_COUNT; ++row) {
            char name[64];
            snprintf(name, sizeof name, "%s row %u finite at bind",
                     rig_name, row);
            check(matrix_all_finite(base[row]), name);
        }

        /* The measured and provisional links: row <- (parent, group). */
        static const struct { uint8_t row; uint8_t triple; } links[] = {
            { 2, 3 }, { 5, 5 }, { 6, 6 }, { 9, 8 }, { 14, 11 }, { 17, 13 }
        };
        for (size_t link = 0; link < sizeof links / sizeof links[0];
             ++link) {
            int16_t fields[VF3_NATIVE_POSE_FIELDS] = { 0 };
            char name[96];
            /* A quarter turn on the link's first (z) angle only. */
            fields[(size_t)links[link].triple * 3u] = 16384;
            check(vf3_native_motion_pose_fields(fields, which, moved) == 0,
                  "pose with one group turned");
            snprintf(name, sizeof name, "%s row %u moves with group %u",
                     rig_name, links[link].row, links[link].triple);
            check(rotation_differs(moved[links[link].row],
                                   base[links[link].row]),
                  name);
            /* Row 1 (head, group 1, parent row 0) is outside every one of
             * these subtrees, so its rotation must not move. */
            snprintf(name, sizeof name,
                     "%s row 1 still at bind for group %u", rig_name,
                     links[link].triple);
            check(!rotation_differs(moved[1], base[1]), name);
        }
    }

    /* The stream entry point rejects bad arguments. */
    check(vf3_native_motion_pose(NULL, 0, VF3_NATIVE_MOTION_RIG_AKIRA, base)
              == -1,
          "null stream rejected");
    check(vf3_native_motion_pose_fields(NULL, VF3_NATIVE_MOTION_RIG_AKIRA,
                                        base) == -1,
          "null fields rejected");
    check(vf3_native_motion_pose_fields(zero_fields,
                                        (vf3_native_motion_rig)7, base) == -1,
          "unknown rig rejected");
    check(vf3_native_motion_pose_fields(zero_fields,
                                        VF3_NATIVE_MOTION_RIG_AKIRA, NULL) == -1,
          "null matrices rejected");

    if (!ok) return 1;
    puts("native_motion_pose_replay: PASS");
    return 0;
}
