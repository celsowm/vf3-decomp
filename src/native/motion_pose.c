/* Native MT-derived pose experiment for the VF3 port game.
 *
 * The two ends this module connects are both validated:
 *
 *   1.  vf3_native_motion_eval_pose_fields() (src/native/motion.c) evaluates
 *       one motion from an extracted MT*.BIN asset at a Q8 phase and returns
 *       the 42 halfword pose fields the guest writes at actor+0x1F50.
 *   2.  vf3_native_akira_draw() / vf3_native_jacky_draw() (src/native/
 *       akira_parts.c, jacky_parts.c) render the fighter's 18 POL attachment
 *       rows, each driven by a column-major 4x4 matrix (row 0 defines the
 *       actor origin whose translation the draw subtracts as root).
 *
 * The attachment producer is still incomplete. A multi-track comparison of
 * captured row-relative rotations proves four group/parent relationships:
 * rows 2/0, 5/4, 6/0 and 9/8 follow pose groups 3, 5, 6 and 8 respectively in
 * Z-Y-X order. The other row/group assignments and most bind transforms are
 * still inferred; the preview remains diagnostic rather than a verified
 * fighter pose.
 *
 * What the guest does pin down:
 *   * 0x8C09D9EA (the root orientation, ported readable as
 *     src/fight/readable/root_orientation.c) reads actor+0x1F50, +0x1F52
 *     and +0x1F54 - the first three pose fields - as angles, composing
 *     Ry(yaw at +0x1E), Rz(field0), Ry(field1) and Rx(field2) post-multiply
 *     into XMTRX.  vf3_native_root_orientation() in src/native/matrix.c
 *     mirrors that chain and matches the guest's FSCA sine table to
 *     9e-8 on a mixed-angle case (tests/native_matrix_replay.c).  It is a
 *     verified primitive, but it is NOT row 0's final matrix: the captured
 *     row-0 matrices do not match this intermediate, which the aim-frame
 *     producer in 0x8C09EAF2 transforms further - so the rig below still
 *     uses its authored bind rotation for row 0 until that producer is
 *     ported;
 *   * the evaluator flips the sign of every third output channel of the
 *     whole 63-channel block, so the 42 fields group as 14 turn triples and
 *     the third component is the angle the FSCA path consumes;
 *   * the repo's recovered turn helpers use 16-bit turns, 65536 units to a
 *     revolution (vf3_native_matrix_euler_z_y_x).
 *
 * What remains inferred here:
 *   * the other pose-group-to-row links and the complete attachment hierarchy;
 *   * the bind skeletons below - standing mannequins built from each
 *     character's own POL mesh bounds, not from captured state.  Every part
 *     is authored around its joint in its own local frame; the table says
 *     where the joint sits at rest, which way the part's local axes point,
 *     which row is its parent where not measured, and how far its mesh has to slide to meet the
 *     joint.  Akira and Jacky have different proportions (Akira's neck is at
 *     1.121, Jacky's at 1.189; Akira's hip is at 0.829, Jacky's at 0.78),
 *     so each character carries its own table.
 *
 * Composition, per row:
 *
 *     world[i] = world[parent] * bind_local[i] * anim[i]
 *     draw[i]  = world[i] * T(shift[i])
 *
 * with bind_local = inverse(bind_world[parent]) * bind_world[i] and anim the
 * row's Euler triple.  At all-zero fields every anim is the identity and the
 * figure stands in the bind pose.  The draw shift is applied after the pose
 * because it is a modelling gap in the POL mesh (Akira's forearm begins 0.049
 * local units past its elbow, the shin 0.023 past its knee), not part of the
 * joint hierarchy.  Row 0 carries no shift, so matrices[0][12..14] stays the
 * pelvis origin the renderer subtracts as root.
 *
 * Geometry sources (POL units).  Akira: ROB_AKI/ROB_WO2 slot 50 torso, MKAO
 * slot 3 head, slots 51/54 shoulder markers, 52/55 upper arms, 53/56
 * forearms, 57/58 hip markers, 59/61 thighs, 60/62 shins+feet, 35/36 waist
 * wraps.  Jacky: ROB_WO2 slots 50-62 and MKAO_WO2 slot 3, same roles.
 * Change the tables (and only the tables) to tune the mannequins.
 */
#include "motion_pose.h"

#include "matrix.h"
#include "motion_vectors.h"

#include <string.h>

typedef enum {
    REST_IDENTITY = 0,
    REST_TORSO,       /* local x -> world y, y -> z, z -> x (cyclic) */
    REST_HEAD,        /* local z -> world y, x -> -z (face to camera)  */
    REST_MIRROR_Y,    /* left limbs: local x -> -x, z -> -z (Ry 180)   */
    REST_LEG,         /* local x -> world -y, y -> x, z -> z (Rz -90)  */
    REST_WRAP_RIGHT,  /* local x -> z, z -> -x (Ry -90)                */
    REST_WRAP_LEFT,   /* local x -> -z, z -> x (Ry +90)                */
} motion_rest;

typedef struct {
    int8_t parent;      /* row index, -1 for the renderer root, -2 empty */
    int8_t triple;      /* 0..13 pose triple, -1 static                  */
    uint8_t rest;       /* motion_rest                                   */
    float joint[3];     /* bind joint in scene space (y up)              */
    float shift[3];     /* draw-only geometry shift, part-local          */
} motion_bone;

/* Akira: neck 1.121 (torso top), hip 0.829 (torso bottom), knee 0.437. */
static const motion_bone MOTION_BONES_AKIRA[VF3_NATIVE_ATTACHMENT_COUNT] = {
    /* row 0: torso / actor root; its origin is the pelvis centre */
    { -1,  0, REST_TORSO,       { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 1: head - MKAO slot 3 */
    {  0,  1, REST_HEAD,        { 0.0f,    1.121f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 2: measured row-0 offset (.28, 0, .12) in torso-local axes. */
    {  0,  3, REST_IDENTITY,    { 0.12f,   1.00f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 3: right upper arm - ROB slot 52 */
    {  2,  3, REST_IDENTITY,    { 0.19f,   1.07f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 4: right forearm + hand - ROB slot 53, starts 0.049 past elbow */
    {  3,  4, REST_IDENTITY,    { 0.40f,   1.07f,  0.0f }, { -0.049f, 0.0f, 0.0f } },
    /* row 5 is a real pivot: captured parent-local bind offset is +0.25 X. */
    {  4,  5, REST_IDENTITY,    { 0.65f,   1.07f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 6: measured mirrored row-0 offset; captured bind rotation is identity. */
    {  0,  6, REST_IDENTITY,    { -0.12f,  1.00f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 7: left upper arm - ROB slot 55 */
    {  6,  6, REST_MIRROR_Y,    { -0.19f,  1.07f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 8: left forearm + hand - ROB slot 56, starts 0.049 past elbow */
    {  7,  7, REST_MIRROR_Y,    { -0.40f,  1.07f,  0.0f }, { -0.049f, 0.0f, 0.0f } },
    /* row 9 is mirrored with row 8; captured parent-local bind offset is +0.25 X. */
    {  8,  8, REST_IDENTITY,    { -0.65f,  1.07f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 10: right hip pivot - ROB slot 57 marker */
    {  0,  8, REST_IDENTITY,    { 0.10f,   0.829f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 11: left hip pivot / pelvis shell - ROB slot 58 */
    {  0,  9, REST_IDENTITY,    { -0.10f,  0.829f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 12: right thigh - ROB slot 59 */
    { 10, 10, REST_LEG,         { 0.10f,   0.829f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 13: right shin + foot - ROB slot 60, starts 0.023 past knee */
    { 12, 11, REST_LEG,         { 0.10f,   0.437f, 0.0f }, { -0.023f, 0.0f, 0.0f } },
    /* row 14: wrap tracks group 11 as a root-relative attachment. */
    {  0, 11, REST_WRAP_RIGHT,  { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 15: left thigh - ROB slot 61 */
    { 11, 12, REST_LEG,         { -0.10f,  0.829f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    /* row 16: left shin + foot - ROB slot 62, starts 0.023 past knee */
    { 15, 13, REST_LEG,         { -0.10f,  0.437f, 0.0f }, { -0.023f, 0.0f, 0.0f } },
    /* row 17: wrap tracks group 13 as a root-relative attachment. */
    {  0, 13, REST_WRAP_LEFT,   { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
};

/* Jacky: neck 1.189 (torso top), hip 0.78, knee 0.448.  His thigh mesh
 * begins 0.067 past the hip and his shin 0.051 past the knee, so the joints
 * sit lower than Akira's to keep the same silhouette connected. */
static const motion_bone MOTION_BONES_JACKY[VF3_NATIVE_ATTACHMENT_COUNT] = {
    { -1,  0, REST_TORSO,       { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  0,  1, REST_HEAD,        { 0.0f,    1.189f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  0,  3, REST_IDENTITY,    { 0.13f,   1.02f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  2,  3, REST_IDENTITY,    { 0.19f,   1.10f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  3,  4, REST_IDENTITY,    { 0.39f,   1.10f,  0.0f }, { -0.049f, 0.0f, 0.0f } },
    {  4,  5, REST_IDENTITY,    { 0.66f,   1.10f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  0,  6, REST_IDENTITY,    { -0.13f,  1.02f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  6,  6, REST_MIRROR_Y,    { -0.19f,  1.10f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  7,  7, REST_MIRROR_Y,    { -0.39f,  1.10f,  0.0f }, { -0.049f, 0.0f, 0.0f } },
    {  8,  8, REST_IDENTITY,    { -0.66f,  1.10f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  0,  8, REST_IDENTITY,    { 0.10f,   0.78f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    {  0,  9, REST_IDENTITY,    { -0.10f,  0.78f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 10, 10, REST_LEG,         { 0.10f,   0.78f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 12, 11, REST_LEG,         { 0.10f,   0.448f, 0.0f }, { -0.023f, 0.0f, 0.0f } },
    {  0, 11, REST_WRAP_RIGHT,  { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 11, 12, REST_LEG,         { -0.10f,  0.78f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 15, 13, REST_LEG,         { -0.10f,  0.448f, 0.0f }, { -0.023f, 0.0f, 0.0f } },
    {  0, 13, REST_WRAP_LEFT,   { 0.0f,    0.72f,  0.0f }, { 0.0f, 0.0f, 0.0f } },
};

/* Build one rest orientation (the part-local -> scene rotation at bind). */
static void build_rest(uint8_t rest, float out[16])
{
    vf3_native_matrix_identity(out);
    switch (rest) {
    case REST_TORSO:
        /* columns: x->(0,1,0), y->(0,0,1), z->(1,0,0) */
        out[0] = 0.0f; out[1] = 1.0f; out[2] = 0.0f;
        out[4] = 0.0f; out[5] = 0.0f; out[6] = 1.0f;
        out[8] = 1.0f; out[9] = 0.0f; out[10] = 0.0f;
        break;
    case REST_HEAD:
        /* Face local +x toward the camera (-z), local +z up.
         * columns: x->(0,0,-1), y->(-1,0,0), z->(0,1,0) */
        out[0] = 0.0f; out[1] = 0.0f; out[2] = -1.0f;
        out[4] = -1.0f; out[5] = 0.0f; out[6] = 0.0f;
        out[8] = 0.0f; out[9] = 1.0f; out[10] = 0.0f;
        break;
    case REST_MIRROR_Y:
        /* Ry(180): x->(-1,0,0), z->(0,0,-1) */
        out[0] = -1.0f; out[10] = -1.0f;
        break;
    case REST_LEG:
        /* Rz(-90): x->(0,-1,0), y->(1,0,0) */
        out[0] = 0.0f; out[1] = -1.0f;
        out[4] = 1.0f; out[5] = 0.0f;
        break;
    case REST_WRAP_RIGHT:
        /* Ry(-90): x->(0,0,1), z->(-1,0,0) */
        out[0] = 0.0f; out[2] = 1.0f;
        out[8] = -1.0f; out[10] = 0.0f;
        break;
    case REST_WRAP_LEFT:
        /* Ry(+90): x->(0,0,-1), z->(1,0,0) */
        out[0] = 0.0f; out[2] = -1.0f;
        out[8] = 1.0f; out[10] = 0.0f;
        break;
    default:
        break;
    }
}

/* Inverse of a rigid transform: R^T and -R^T t (column-major). */
static void matrix_invert_rigid(const float matrix[16], float out[16])
{
    float inverse[16];
    vf3_native_matrix_identity(inverse);
    inverse[0] = matrix[0];
    inverse[1] = matrix[4];
    inverse[2] = matrix[8];
    inverse[4] = matrix[1];
    inverse[5] = matrix[5];
    inverse[6] = matrix[9];
    inverse[8] = matrix[2];
    inverse[9] = matrix[6];
    inverse[10] = matrix[10];
    for (size_t row = 0; row < 3u; ++row)
        inverse[12u + row] = -(matrix[row * 4u + 0u] * matrix[12] +
                               matrix[row * 4u + 1u] * matrix[13] +
                               matrix[row * 4u + 2u] * matrix[14]);
    memcpy(out, inverse, sizeof inverse);
}

static void turns_for_row(const motion_bone *bone,
                          const int16_t pose_fields[VF3_NATIVE_POSE_FIELDS],
                          float anim[16])
{
    if (bone->triple < 0) {
        vf3_native_matrix_identity(anim);
        return;
    }
    const size_t field = (size_t)bone->triple * 3u;
    vf3_native_matrix_euler_z_y_x((uint16_t)pose_fields[field + 0],
                                  (uint16_t)pose_fields[field + 1],
                                  (uint16_t)pose_fields[field + 2], anim);
}

int vf3_native_motion_pose(
    const vf3_native_motion_stream *stream,
    int32_t phase,
    vf3_native_motion_rig rig,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT][VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS])
{
    float channels[VF3_NATIVE_MOTION_CHANNELS];
    uint16_t pose_fields[VF3_NATIVE_POSE_FIELDS];
    int16_t signed_fields[VF3_NATIVE_POSE_FIELDS];
    if (!stream || !matrices)
        return -1;
    if (vf3_native_motion_eval_pose_fields(stream, phase, channels,
                                           pose_fields) != 0)
        return -2;
    for (size_t i = 0; i < VF3_NATIVE_POSE_FIELDS; ++i)
        signed_fields[i] = (int16_t)pose_fields[i];
    return vf3_native_motion_pose_fields(signed_fields, rig, matrices);
}

int vf3_native_motion_pose_fields(
    const int16_t pose_fields[VF3_NATIVE_POSE_FIELDS],
    vf3_native_motion_rig rig,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT][VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS])
{
    const motion_bone *bones;
    float bind_world[VF3_NATIVE_ATTACHMENT_COUNT][16];
    float bind_local[VF3_NATIVE_ATTACHMENT_COUNT][16];
    float world[VF3_NATIVE_ATTACHMENT_COUNT][16];
    if (!pose_fields || !matrices)
        return -1;
    if (rig == VF3_NATIVE_MOTION_RIG_AKIRA)
        bones = MOTION_BONES_AKIRA;
    else if (rig == VF3_NATIVE_MOTION_RIG_JACKY)
        bones = MOTION_BONES_JACKY;
    else
        return -1;

    /* The bind pose is constant for the whole call; derive each row's local
     * transform once so the per-frame path only multiplies. */
    for (uint32_t row = 0; row < VF3_NATIVE_ATTACHMENT_COUNT; ++row) {
        const motion_bone *bone = &bones[row];
        build_rest(bone->rest, bind_world[row]);
        bind_world[row][12] = bone->joint[0];
        bind_world[row][13] = bone->joint[1];
        bind_world[row][14] = bone->joint[2];
        if (bone->parent >= 0) {
            float inverse_parent[16];
            matrix_invert_rigid(bind_world[bone->parent], inverse_parent);
            vf3_native_matrix_multiply(inverse_parent, bind_world[row],
                                       bind_local[row]);
        } else {
            memcpy(bind_local[row], bind_world[row], sizeof bind_local[row]);
        }
    }

    for (uint32_t row = 0; row < VF3_NATIVE_ATTACHMENT_COUNT; ++row) {
        const motion_bone *bone = &bones[row];
        float anim[16], posed[16];
        if (bone->parent == -2) {
            vf3_native_matrix_identity(world[row]);
            vf3_native_matrix_identity(matrices[row]);
            continue;
        }
        turns_for_row(bone, pose_fields, anim);
        vf3_native_matrix_multiply(bind_local[row], anim, posed);
        if (bone->parent >= 0)
            vf3_native_matrix_multiply(world[bone->parent], posed, world[row]);
        else
            memcpy(world[row], posed, sizeof world[row]);
        vf3_native_matrix_translate_local(world[row], bone->shift,
                                          matrices[row]);
    }
    return 0;
}

/* ---- the recovered row 0 (0x8C09EAF2) ----
 *
 * The guest builds the actor's root row as:
 *   R_root = Ry(yaw) * Rz(f0) * Ry(f1) * Rx(f2)      (root_orientation)
 *   t      = seven_pass point 0                      (matrix_set_translation)
 *   R_half = R_root * Rz(hw0) * Ry(arg + hw1) * Rx(hw2)
 *   d      = R_half^T * (point1 + offset - t)        (pass_prep's inverse)
 *   R_row0 = R_half * Rz(heading(d)) * Ry(pitch(d))  (unit_triple)
 * with f0..f2 the first pose triple (zero-extended), hw0..hw2 the second
 * (zero-extended), arg the actor halfword at +0x22E4 (sign-extended), and
 * offset the three floats at +0x208C/+0x2090/+0x2094.  The row's translation
 * is t: the frame's +0xA4 object carries it because the xf_store to frame+0xD4
 * lands on the object's translation field (+0xA4 + 48). */

static const float motion_row0_identity[16] = {
    1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
};

static int motion_row0_from_points(
    const int16_t fields[VF3_NATIVE_POSE_FIELDS],
    const vf3_native_motion_actor *actor,
    const float points[VF3_NATIVE_MOTION_POINT_COUNT]
                       [VF3_NATIVE_MOTION_POINT_FLOATS],
    float out[16])
{
    float root[16], half[16], hw[16];
    const uint16_t angles[3] = { (uint16_t)fields[0], (uint16_t)fields[1],
                                 (uint16_t)fields[2] };
    const float *t = points[0];
    const float src[3] = { points[1][0] + actor->offset[0],
                           points[1][1] + actor->offset[1],
                           points[1][2] + actor->offset[2] };
    const float diff[3] = { src[0] - t[0], src[1] - t[1], src[2] - t[2] };
    float d[3], xz_length, inverse_length;

    if (vf3_native_matrix_pose_angles(motion_row0_identity, (int16_t)actor->yaw,
                                      0, angles, root) != 0)
        return -4;
    root[12] = t[0];
    root[13] = t[1];
    root[14] = t[2];

    if (vf3_native_matrix_euler_z_y_x(
            (uint16_t)fields[3],
            (uint16_t)((uint32_t)actor->arg + (uint32_t)(uint16_t)fields[4]),
            (uint16_t)fields[5], hw) != 0)
        return -4;
    vf3_native_matrix_multiply(root, hw, half);

    for (size_t i = 0; i < 3; ++i)
        d[i] = half[i * 4u + 0u] * diff[0] + half[i * 4u + 1u] * diff[1] +
               half[i * 4u + 2u] * diff[2];

    if (vf3_native_matrix_unit_triple(half, d, out, &xz_length,
                                      &inverse_length) != 0)
        return -4;
    return 0;
}

int vf3_native_motion_row0(const int16_t fields[VF3_NATIVE_POSE_FIELDS],
                           const vf3_native_motion_actor *actor,
                           const float channels[21], float out[16])
{
    float world[16];
    float points[VF3_NATIVE_MOTION_POINT_COUNT]
                [VF3_NATIVE_MOTION_POINT_FLOATS];
    if (!fields || !actor || !channels || !out)
        return -1;
    if (vf3_native_motion_actor_transform(actor->yaw, actor->position,
                                          actor->mode, actor->flags,
                                          world) != 0)
        return -2;
    {
        const uint8_t zero_y = vf3_native_motion_zero_y_mask(
            actor->flags, actor->pose_flags, actor->global_flags);
        const int use_origin = (actor->flags & 0x20000000u) != 0;
        if (vf3_native_motion_points(channels, use_origin, zero_y, world,
                                    points) != 0)
            return -3;
    }
    return motion_row0_from_points(fields, actor, points, out);
}

/* ---- the aim-record table (0x8C09EAF2's kind != 12 branch) ----
 *
 * The orchestration reads the actor byte at +0x420B and indexes the u32 table
 * at 0x0C10DABC (r11 = *(u32 *)(table + byte * 4)); the aim_frame builders then
 * read their endpoints and ratios from the record r11 points at.  The table
 * and its five records are 1ST_READ constants, so they are carried here as
 * data.  The twelve floats are the record's leading span: two three-float
 * endpoints and the two ratio triples that follow. */

static const float motion_aim_records[5][12] = {
    { 0.389999986f, 0.279999971f, 0.119999997f, 0.119999997f, 0.25999999f, 0.209999993f,
      0.279999971f, -0.119999997f, -0.119999997f, 0.25999999f, 0.209999993f, 0.189999998f },
    { 0.309999973f, 0.25f, 0.0899999961f, 0.0799999982f, 0.229999989f, 0.229999989f,
      0.25f, -0.0899999961f, -0.0799999982f, 0.229999989f, 0.229999989f, 0.189999998f },
    { 0.50999999f, 0.409999996f, 0.179999992f, 0.169999987f, 0.299999982f, 0.309999973f,
      0.409999996f, -0.179999992f, -0.169999987f, 0.299999982f, 0.309999973f, 0.189999998f },
    { 0.299999982f, 0.229999989f, 0.0799999982f, 0.0699999928f, 0.219999999f, 0.219999999f,
      0.229999989f, -0.0799999982f, -0.0699999928f, 0.219999999f, 0.219999999f, 0.189999998f },
    { 0.299999982f, 0.239999995f, 0.109999999f, 0.099999994f, 0.219999999f, 0.219999999f,
      0.239999995f, -0.109999999f, -0.099999994f, 0.219999999f, 0.219999999f, 0.189999998f },
};

int vf3_native_motion_aim_record(uint8_t kind, float out[12])
{
    if (kind >= 5u || !out)
        return -1;
    for (int i = 0; i < 12; ++i)
        out[i] = motion_aim_records[kind][i];
    return 0;
}

int vf3_native_motion_pose_actor(
    const vf3_native_motion_stream *stream, int32_t phase,
    vf3_native_motion_rig rig, const vf3_native_motion_actor *actor,
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS])
{
    float channels[VF3_NATIVE_MOTION_CHANNELS];
    uint16_t pose_fields[VF3_NATIVE_POSE_FIELDS];
    int16_t signed_fields[VF3_NATIVE_POSE_FIELDS];
    if (!stream || !actor || !matrices)
        return -1;
    if (vf3_native_motion_eval_pose_fields(stream, phase, channels,
                                           pose_fields) != 0)
        return -2;
    for (size_t i = 0; i < VF3_NATIVE_POSE_FIELDS; ++i)
        signed_fields[i] = (int16_t)pose_fields[i];
    if (vf3_native_motion_pose_fields(signed_fields, rig, matrices) != 0)
        return -3;
    if (vf3_native_motion_row0(signed_fields, actor, channels,
                              matrices[0]) != 0)
        return -4;
    return 0;
}
