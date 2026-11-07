/* Native, bounded view of the recovered VF3 MT channel evaluator. */
#ifndef VF3_NATIVE_MOTION_H
#define VF3_NATIVE_MOTION_H

#include <stddef.h>
#include <stdint.h>

#include "mt.h"

#define VF3_NATIVE_MOTION_CHANNELS 63u
#define VF3_NATIVE_POSE_FIELDS 42u

typedef struct {
    uint16_t cycle;
    const uint8_t *ops;
    size_t ops_size;
    const uint8_t *counts;
    size_t counts_size;
    const uint8_t *times;
    size_t times_size;
    const uint8_t *tuples;
    size_t tuples_size;
} vf3_native_motion_stream;

/* Resolve a one-based MT motion ID from an extracted asset and bind its
 * borrowed streams for the native evaluator. `storage` owns the expanded
 * opcode bytes and must remain alive while `stream` is used. `cycle` comes
 * from the native fighter state; it is not inferred from the MT descriptor. */
int vf3_native_motion_load(const MtFile *file, uint32_t motion_id,
                           uint16_t cycle, MtMotionView *storage,
                           vf3_native_motion_stream *stream);

/* Evaluate one 63-channel frame into caller-owned storage. The four streams
 * are borrowed slices, so a caller can point them into the offline VFA pack.
 * Returns -1 for invalid arguments, -2 for a truncated stream, and -3 when
 * the requested phase creates a zero-duration keyframe interval. On error,
 * `out` is left unchanged. */
int vf3_native_motion_eval(const vf3_native_motion_stream *stream,
                           int32_t phase, float out[VF3_NATIVE_MOTION_CHANNELS]);

/* Evaluate the 63-channel block and pack the 42-float suffix the guest reads
 * at actor+0x1D58 (channel 21) into the 42 halfword fields written at
 * actor+0x1F50. `channels` and `pose_fields` are both left unchanged on error.
 * The packed fields are not yet assigned to joints or POL parts. */
int vf3_native_motion_eval_pose_fields(
    const vf3_native_motion_stream *stream, int32_t phase,
    float channels[VF3_NATIVE_MOTION_CHANNELS],
    uint16_t pose_fields[VF3_NATIVE_POSE_FIELDS]);

/* Convert a 42-float span to the halfword fields stored by 0x8C09D590. The
 * span is the evaluator suffix beginning at channel 21; a runtime caller can
 * pass channels + 21 or use vf3_native_motion_eval_pose_fields(). The output
 * contains the stored 16-bit patterns, so callers can interpret them as
 * signed values where the actor format requires it. Returns -1 for invalid
 * pointers and -2 if a value is non-finite or outside the SH-4 FTRC signed-
 * 32-bit input range. On error, `out` is left unchanged. */
int vf3_native_motion_pack_pose_fields(
    const float source[VF3_NATIVE_POSE_FIELDS],
    uint16_t out[VF3_NATIVE_POSE_FIELDS]);

/* Build the readable engine's Z-then-Y-then-X Euler rotation from three
 * unsigned 16-bit turns (65536 units per revolution). The result is a
 * column-major 4x4 rotation matrix with zero translation. This is a math
 * primitive only; it does not assign the 42 pose fields to joints or parts. */
int vf3_native_motion_euler_matrix(uint16_t z, uint16_t y, uint16_t x,
                                   float out[16]);

#endif
