/* Static type data used by the native pose path.
 *
 * Retail 0x8c09eaf2 indexes 0x0c10d3c4 by actor byte +0x61 with a 0x6c-byte
 * stride. Each record holds 27 floats (108 bytes exactly, no padding). The
 * first playable matchup only needs kind 0 (Akira) and kind 7 (Jacky).
 * Unclassified words are kept indexed by their original byte offset; three
 * float3 records are exposed by name because the orchestration passes
 * pointers to +0x18, +0x24 and +0x3c into its aim-frame builders.
 *
 * The field categorization below (POSE_VECTOR_FIRST / SECOND / AIM_B at
 * indices 6-8, 9-11 and 15-17) is an unverified interpretation of how the
 * three exposed float3 vectors map to the record. The float values themselves
 * are taken verbatim from the retail data image at 0x0c10d3c4 and verified
 * against docs/re/pose_record_fields.md.
 *
 * NOTE: docs/re/pose_record_fields.md records raw field offsets without
 *   semantic names; the per-index semantics there are unverified guesses.
 */
#include "pose_data.h"

#include <stddef.h>
#include <string.h>

enum {
    POSE_VECTOR_FIRST = 0x18,
    POSE_VECTOR_SECOND = 0x24,
    POSE_VECTOR_AIM_B = 0x3C,
};

/* Kind 0 (Akira) pose record fields (27 floats = 108 bytes)
 *
 * Values verified against the retail data image at 0x0c10d3c4 (kind 0,
 * actor byte +0x61 = 0). Field categorization is unverified interpretation;
 * see docs/re/pose_record_fields.md for raw field offsets.
 */
static const float kind_0[VF3_NATIVE_POSE_KIND_WORDS] = {
    /* Initial/scale parameters (0-5) */
    0.25f, 0.065f, 0.015f, 0.0f, 0.0f, 0.125f,
    /* POSE_VECTOR_FIRST (6-8): Primary translation/offset parameters */
    0.125f, 0.16f, 0.07f,
    /* POSE_VECTOR_SECOND (9-11): Secondary position/rotation parameters */
    0.125f, 0.16f, 0.07f,
    /* Neutral values (12-14) */
    0.0f, 0.0f, 0.0f,
    /* POSE_VECTOR_AIM_B (15-17): Aim-specific parameters */
    0.205f, 0.181f, 0.35f,
    /* Y-suppression/offset parameters (18-26) */
    -0.055f, -0.073f, -0.16f,
    0.205f, 0.181f, 0.35f,
    -0.055f, -0.073f, -0.16f,
};

/* Kind 7 (Jacky) pose record fields (27 floats = 108 bytes)
 *
 * Values verified against the retail data image at 0x0c10d3c4 + 0x6c =
 * 0x0c10d6b8 (kind 7, actor byte +0x61 = 7). Field categorization is
 * unverified interpretation; see docs/re/pose_record_fields.md for raw field
 * offsets.
 */
static const float kind_7[VF3_NATIVE_POSE_KIND_WORDS] = {
    /* Initial/scale parameters (0-5) */
    0.27f, 0.075f, 0.01f, 0.025f, 0.0f, 0.18f,
    /* POSE_VECTOR_FIRST (6-8): Primary translation/offset parameters */
    0.135f, 0.185f, 0.085f,
    /* POSE_VECTOR_SECOND (9-11): Secondary position/rotation parameters */
    0.135f, 0.185f, 0.085f,
    /* Neutral values (12-14) */
    0.0f, 0.0f, -0.03f,
    /* POSE_VECTOR_AIM_B (15-17): Aim-specific parameters */
    0.195f, 0.18f, 0.345f,
    /* Y-suppression/offset parameters (18-26) */
    -0.052f, -0.085f, -0.19f,
    0.195f, 0.18f, 0.345f,
    -0.052f, -0.085f, -0.19f,
};

const float *vf3_native_pose_kind_words(uint8_t fighter_kind)
{
    switch (fighter_kind) {
    case 0:
        return kind_0;
    case 7:
        return kind_7;
    default:
        return NULL;
    }
}

int vf3_native_pose_kind_vector(uint8_t fighter_kind,
                                uint32_t record_byte_offset,
                                float out[3])
{
    const float *words = vf3_native_pose_kind_words(fighter_kind);
    size_t first_word;

    if (!out)
        return -1;
    if (!words)
        return -2;
    switch (record_byte_offset) {
    case POSE_VECTOR_FIRST:
    case POSE_VECTOR_SECOND:
    case POSE_VECTOR_AIM_B:
        first_word = record_byte_offset / sizeof(float);
        break;
    default:
        return -3;
    }
    memcpy(out, words + first_word, 3u * sizeof *out);
    return 0;
}
