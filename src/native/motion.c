/* Bounded native implementation of the recovered MT frame evaluator.
 * This module consumes ordinary byte slices from extracted assets. It has no
 * guest RAM, address translation, emulator state or instruction dispatcher. */
#include "motion.h"
#include "matrix.h"

#include <math.h>
#include <limits.h>
#include <string.h>

int vf3_native_motion_load(const MtFile *file, uint32_t motion_id,
                           uint16_t cycle, MtMotionView *storage,
                           vf3_native_motion_stream *stream)
{
    int rc;
    if (!storage || !stream)
        return -1;
    memset(storage, 0, sizeof *storage);
    memset(stream, 0, sizeof *stream);
    rc = mt_motion_view(file, motion_id, storage);
    if (rc != 0)
        return rc;
    stream->cycle = cycle;
    stream->ops = storage->ops;
    stream->ops_size = sizeof storage->ops;
    stream->counts = storage->counts;
    stream->counts_size = storage->counts_size;
    stream->times = storage->times;
    stream->times_size = storage->times_size;
    stream->tuples = storage->tuples;
    stream->tuples_size = storage->tuples_size;
    return 0;
}

static uint32_t read_u32le(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int read_float(const uint8_t *data, size_t size, size_t cursor,
                      size_t index, float *out)
{
    uint32_t bits;
    if (!data || !out || cursor > size ||
        index > (SIZE_MAX - cursor) / 4u)
        return 0;
    cursor += index * 4u;
    if (cursor > size || size - cursor < 4u)
        return 0;
    bits = read_u32le(data + cursor);
    memcpy(out, &bits, sizeof bits);
    return 1;
}

static void flip_sign(float *value)
{
    uint32_t bits;
    memcpy(&bits, value, sizeof bits);
    bits ^= 0x80000000u;
    memcpy(value, &bits, sizeof bits);
}

int vf3_native_motion_eval(const vf3_native_motion_stream *stream,
                           int32_t phase, float out[VF3_NATIVE_MOTION_CHANNELS])
{
    float values[VF3_NATIVE_MOTION_CHANNELS];
    size_t count_cursor = 0, time_cursor = 0, tuple_cursor = 0;
    int32_t cycle_time;

    if (!stream || !out || !stream->ops ||
        stream->ops_size < VF3_NATIVE_MOTION_CHANNELS || sizeof(float) != 4u)
        return -1;
    cycle_time = (int32_t)stream->cycle << 8;

    for (size_t channel = 0; channel < VF3_NATIVE_MOTION_CHANNELS; ++channel) {
        const uint8_t op = stream->ops[channel];
        float value;
        if (op == 0) {
            value = 0.0f;
        } else if (op == 1) {
            if (!read_float(stream->tuples, stream->tuples_size,
                            tuple_cursor, 0, &value))
                return -2;
            tuple_cursor += 4u;
        } else {
            uint8_t count;
            int32_t index, previous_time = 0x100, next_time = cycle_time;
            int exact = 0;
            if (!stream->counts || count_cursor >= stream->counts_size)
                return -2;
            count = stream->counts[count_cursor++];
            if (time_cursor > stream->times_size ||
                count > stream->times_size - time_cursor ||
                (count && !stream->times))
                return -2;
            index = count; /* exhausted key scan selects the cycle endpoint */
            for (uint32_t key = 0; key < count; ++key) {
                const int32_t key_time = (int32_t)stream->times[time_cursor + key] << 8;
                if (key_time > phase) {
                    index = (int32_t)key;
                    next_time = key_time;
                    break;
                }
                if (key_time == phase) {
                    index = (int32_t)key;
                    exact = 1;
                    break;
                }
                previous_time = key_time;
            }
            time_cursor += count;

            if (exact) {
                if (op == 2) {
                    if (!read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, (size_t)index + 1u, &value))
                        return -2;
                    tuple_cursor += ((size_t)count + 2u) * 4u;
                } else {
                    if (!read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor,
                                    ((size_t)index + 1u) * 3u, &value))
                        return -2;
                    tuple_cursor += ((size_t)count * 3u + 4u) * 4u;
                }
            } else {
                const int32_t relative_time = phase - previous_time;
                const int32_t span = next_time - previous_time;
                /* A valid native motion phase gives adjacent key times a
                 * nonzero interval. Reject a malformed cycle/phase pair
                 * rather than letting a zero-duration segment produce an
                 * infinity or NaN that would contaminate the whole pose. */
                if (span == 0)
                    return -3;
                const float t = (float)relative_time / (float)span;
                if (op == 2) {
                    float v0, v1;
                    if (!read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, (size_t)index, &v0) ||
                        !read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, (size_t)index + 1u, &v1))
                        return -2;
                    value = v0 + t * (v1 - v0);
                    tuple_cursor += ((size_t)count + 2u) * 4u;
                } else {
                    const size_t base = (size_t)index * 3u;
                    float v0x, y0, z0, v1x;
                    if (!read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, base, &v0x) ||
                        !read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, base + 1u, &y0) ||
                        !read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, base + 2u, &z0) ||
                        !read_float(stream->tuples, stream->tuples_size,
                                    tuple_cursor, base + 3u, &v1x))
                        return -2;
                    value = v0x
                        + (float)relative_time * (t - 1.0f) * (1.0f / 256.0f)
                          * (t * z0 + (t - 1.0f) * y0)
                        + t * (t * (2.0f * t - 3.0f)) * (v0x - v1x);
                    tuple_cursor += ((size_t)count * 3u + 2u) * 4u;
                }
            }
        }
        values[channel] = value;
    }

    for (size_t i = 2; i < 21u; i += 3u)
        flip_sign(&values[i]);
    for (size_t i = 21; i < VF3_NATIVE_MOTION_CHANNELS; i += 3u)
        flip_sign(&values[i]);
    memcpy(out, values, sizeof values);
    return 0;
}

int vf3_native_motion_eval_pose_fields(
    const vf3_native_motion_stream *stream, int32_t phase,
    float channels[VF3_NATIVE_MOTION_CHANNELS],
    uint16_t pose_fields[VF3_NATIVE_POSE_FIELDS])
{
    float evaluated[VF3_NATIVE_MOTION_CHANNELS];
    uint16_t packed[VF3_NATIVE_POSE_FIELDS];

    if (!channels || !pose_fields)
        return -1;
    if (vf3_native_motion_eval(stream, phase, evaluated) != 0)
        return -2;
    /* 0x1D58 - 0x1D04 = 0x54 bytes = 21 floats. The guest's 42-value
     * FTRC loop therefore packs channels 21 through 62 in order. */
    if (vf3_native_motion_pack_pose_fields(
            evaluated + (VF3_NATIVE_MOTION_CHANNELS - VF3_NATIVE_POSE_FIELDS),
            packed) != 0)
        return -2;
    memcpy(channels, evaluated, sizeof evaluated);
    memcpy(pose_fields, packed, sizeof packed);
    return 0;
}

int vf3_native_motion_pack_pose_fields(
    const float source[VF3_NATIVE_POSE_FIELDS],
    uint16_t out[VF3_NATIVE_POSE_FIELDS])
{
    uint16_t fields[VF3_NATIVE_POSE_FIELDS];
    const double lower = (double)INT32_MIN;
    const double upper = (double)INT32_MAX + 1.0;

    if (!source || !out)
        return -1;
    for (size_t i = 0; i < VF3_NATIVE_POSE_FIELDS; ++i) {
        const float value = source[i];
        const double wide = (double)value;
        int32_t truncated;
        if (!isfinite(value) || wide < lower || wide >= upper)
            return -2;
        /* SH-4 FTRC truncates toward zero. Conversion to unsigned then keeps
         * the low halfword exactly as the guest's signed-halfword store does. */
        truncated = (int32_t)trunc((double)value);
        fields[i] = (uint16_t)(uint32_t)truncated;
    }
    memcpy(out, fields, sizeof fields);
    return 0;
}

int vf3_native_motion_euler_matrix(uint16_t z, uint16_t y, uint16_t x,
                                   float out[16])
{
    return vf3_native_matrix_euler_z_y_x(z, y, x, out);
}
