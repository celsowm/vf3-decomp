/* Fighter-kind pose constants recovered from the retail data image. */
#ifndef VF3_NATIVE_POSE_DATA_H
#define VF3_NATIVE_POSE_DATA_H

#include <stdint.h>

#define VF3_NATIVE_POSE_KIND_WORDS 27u

/* The first native matchup uses fighter kinds 0 (Akira) and 7 (Jacky).
 * The returned words preserve the 0x6c-byte record's float layout. */
const float *vf3_native_pose_kind_words(uint8_t fighter_kind);

/* Read one of the three float3 bases passed directly from the kind record to
 * the pose orchestration's aim-frame builders. Offsets are byte offsets in
 * the original 0x6c-byte record: 0x18, 0x24, and 0x3c. */
int vf3_native_pose_kind_vector(uint8_t fighter_kind,
                                uint32_t record_byte_offset,
                                float out[3]);

#endif
