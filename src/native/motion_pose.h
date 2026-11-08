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

#endif
