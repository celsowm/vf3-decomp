/* Static type data used by the native pose path.
 *
 * Retail 0x8c09eaf2 indexes 0x0c10d3c4 by actor byte +0x61 with a 0x6c-byte
 * stride. The first playable matchup only needs kind 0 (Akira) and kind 7
 * (Jacky). Keep unclassified words indexed by their original byte offset;
 * three float3 records are exposed by name because the orchestration passes
 * pointers to +0x18, +0x24 and +0x3c into its aim-frame builders.
 */
#include "pose_data.h"

#include <stddef.h>
#include <string.h>

enum {
    POSE_VECTOR_FIRST = 0x18,
    POSE_VECTOR_SECOND = 0x24,
    POSE_VECTOR_AIM_B = 0x3C,
};

static const float kind_0[VF3_NATIVE_POSE_KIND_WORDS] = {
    0.25f, 0.065f, 0.015f, 0.0f, 0.0f, 0.125f,
    0.125f, 0.16f, 0.07f, 0.125f, 0.16f, 0.07f,
    0.0f, 0.0f, 0.0f,
    0.205f, 0.181f, 0.35f,
    -0.055f, -0.073f, -0.16f,
    0.205f, 0.181f, 0.35f,
    -0.055f, -0.073f, -0.16f,
};

static const float kind_7[VF3_NATIVE_POSE_KIND_WORDS] = {
    0.27f, 0.075f, 0.01f, 0.025f, 0.0f, 0.18f,
    0.135f, 0.185f, 0.085f, 0.135f, 0.185f, 0.085f,
    0.0f, 0.0f, -0.03f,
    0.195f, 0.18f, 0.345f,
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
