#ifndef VF3_NATIVE_MOTION_POSE_H
#define VF3_NATIVE_MOTION_POSE_H

#include <stdint.h>

#include "motion.h"
#include "fighter_view.h"

/* Which bind skeleton to pose.  The two characters' POL meshes have different
 * proportions, so their joint heights differ; the attachment selector rows
 * (and therefore the matrix indices) are the same for both. */
typedef enum {
    VF3_NATIVE_MOTION_RIG_AKIRA = 0,
    VF3_NATIVE_MOTION_RIG_JACKY = 1,
} vf3_native_motion_rig;

/* Fold one evaluated MT motion at a Q8 phase into the 18 native attachment
 * matrices that vf3_native_akira_draw() / vf3_native_jacky_draw() consume.
 * Row 0 stays the actor origin (the pelvis centre).  The field->row mapping
 * and the bind mannequins are a documented, tunable inference (see
 * motion_pose.c): the 42 pose fields group as 14 (z,y,x) turn triples that
 * drive the live attachment rows in selector order, composed through the
 * character's authored bind skeleton so the parts stay connected.
 *
 * Returns 0 on success, -1 for bad args, -2 if the motion cannot be
 * evaluated at this phase, and -3 if a matrix build fails.  On error the
 * matrices array is left in an indeterminate but non-dereferenced state. */
int vf3_native_motion_pose(
    const vf3_native_motion_stream *stream,
    int32_t phase,
    vf3_native_motion_rig rig,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS]);

/* Same fold from an already-evaluated pose-field block (the 42 halfwords the
 * guest keeps at actor+0x1F50).  All-zero fields give the bind pose; this is
 * the entry point the preview's --zero-fields check uses and the shape a
 * future pose blend feeds. */
int vf3_native_motion_pose_fields(
    const int16_t fields[VF3_NATIVE_POSE_FIELDS],
    vf3_native_motion_rig rig,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS]);

/* The external actor state the recovered row-0 chain reads.  The pose fields
 * themselves come from the evaluated motion; these are the actor words the
 * guest reads around them (see docs/re/motion_row0.md). */
typedef struct {
    uint16_t yaw;            /* actor +0x1E, sign-extended by the caller */
    float position[3];       /* actor +0x10, the seven-pass origin */
    uint8_t mode;            /* actor +97 */
    uint32_t flags;          /* actor +72 (word0) */
    uint32_t pose_flags;     /* actor +0x48 */
    uint32_t global_flags;   /* 0x0C29BCCC */
    int16_t arg;             /* actor +0x22E4 */
    float offset[3];         /* actor +0x208C/+0x2090/+0x2094 */
} vf3_native_motion_actor;

/* Recovered native row 0 of the pose orchestration (0x8C09EAF2): the root
 * orientation from pose fields 0..2 and the actor yaw, the seven-pass
 * translation, the halfword frame from fields 3..5 and the actor +0x22E4
 * argument, and the unit_triple heading/pitch from the summed actor triple.
 * `channels[0..20]` feed the seven-point transform.  Returns 0 on success,
 * -1 for bad arguments, -2 for a non-finite actor transform, -3 when the
 * seven points cannot be built, -4 when the row-0 basis is rejected. */
int vf3_native_motion_row0(const int16_t fields[VF3_NATIVE_POSE_FIELDS],
                           const vf3_native_motion_actor *actor,
                           const float channels[21], float out[16]);

/* The full 18-row fold with the recovered row 0 substituted for the authored
 * bind row.  The remaining rows keep the documented authored rig.  Returns
 * the same codes as vf3_native_motion_pose, plus -4 when actor is null or
 * the row-0 build fails. */
int vf3_native_motion_pose_actor(
    const vf3_native_motion_stream *stream, int32_t phase,
    vf3_native_motion_rig rig, const vf3_native_motion_actor *actor,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS]);

#endif
