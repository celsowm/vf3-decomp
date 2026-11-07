/* Shared native implementation of the recovered column-major matrix helpers.
 * Angles use the game's 65536-unit turn convention. */
#include "matrix.h"

#include <math.h>
#include <string.h>

void vf3_native_matrix_identity(float out[16])
{
    if (!out)
        return;
    memset(out, 0, 16u * sizeof *out);
    out[0] = out[5] = out[10] = out[15] = 1.0f;
}

void vf3_native_matrix_multiply(const float left[16], const float right[16],
                                float out[16])
{
    float product[16];
    if (!left || !right || !out)
        return;
    for (size_t column = 0; column < 4u; ++column) {
        for (size_t row = 0; row < 4u; ++row) {
            float sum = 0.0f;
            for (size_t k = 0; k < 4u; ++k)
                sum += left[k * 4u + row] * right[column * 4u + k];
            product[column * 4u + row] = sum;
        }
    }
    memcpy(out, product, sizeof product);
}

void vf3_native_matrix_transform_point(const float matrix[16],
                                       const float point[3], float out[3])
{
    float result[3];
    if (!matrix || !point || !out)
        return;
    for (size_t row = 0; row < 3u; ++row) {
        result[row] = matrix[row] * point[0] + matrix[4u + row] * point[1] +
                      matrix[8u + row] * point[2] + matrix[12u + row];
    }
    memcpy(out, result, sizeof result);
}

void vf3_native_matrix_translate_local(const float matrix[16],
                                       const float offset[3], float out[16])
{
    float translated[16];
    if (!matrix || !offset || !out)
        return;
    memcpy(translated, matrix, sizeof translated);
    for (size_t row = 0; row < 3u; ++row) {
        translated[12u + row] = matrix[12u + row] +
            matrix[row] * offset[0] + matrix[4u + row] * offset[1] +
            matrix[8u + row] * offset[2];
    }
    memcpy(out, translated, sizeof translated);
}

void vf3_native_matrix_scale_axes(const float matrix[16],
                                  float x, float y, float z, float out[16])
{
    float scaled[16];
    const float scale[3] = { x, y, z };
    if (!matrix || !out)
        return;
    memcpy(scaled, matrix, sizeof scaled);
    for (size_t column = 0; column < 3u; ++column)
        for (size_t row = 0; row < 4u; ++row)
            scaled[column * 4u + row] *= scale[column];
    memcpy(out, scaled, sizeof scaled);
}

static void rotation_z_sincos(float sine, float cosine, float out[16])
{
    vf3_native_matrix_identity(out);
    out[0] = cosine; out[1] = sine;
    out[4] = -sine;  out[5] = cosine;
}

static void rotation_y_sincos(float sine, float cosine, float out[16])
{
    vf3_native_matrix_identity(out);
    out[0] = cosine;  out[2] = -sine;
    out[8] = sine;    out[10] = cosine;
}

static void rotation_z(uint16_t angle, float out[16])
{
    const float radians = (float)((double)angle *
                                  (3.14159265358979323846 / 32768.0));
    const float sine = sinf(radians), cosine = cosf(radians);
    rotation_z_sincos(sine, cosine, out);
}

static void rotation_y(uint16_t angle, float out[16])
{
    const float radians = (float)((double)angle *
                                  (3.14159265358979323846 / 32768.0));
    const float sine = sinf(radians), cosine = cosf(radians);
    rotation_y_sincos(sine, cosine, out);
}

static void rotation_x(uint16_t angle, float out[16])
{
    const float radians = (float)((double)angle *
                                  (3.14159265358979323846 / 32768.0));
    const float sine = sinf(radians), cosine = cosf(radians);
    vf3_native_matrix_identity(out);
    out[5] = cosine;  out[6] = sine;
    out[9] = -sine;   out[10] = cosine;
}

int vf3_native_matrix_euler_z_y_x(uint16_t z, uint16_t y, uint16_t x,
                                 float out[16])
{
    float rz[16], ry[16], rx[16], zy[16], result[16];
    if (!out)
        return -1;
    rotation_z(z, rz);
    rotation_y(y, ry);
    rotation_x(x, rx);
    vf3_native_matrix_multiply(rz, ry, zy);
    vf3_native_matrix_multiply(zy, rx, result);
    memcpy(out, result, sizeof result);
    return 0;
}

int vf3_native_matrix_apply_euler_keep_translation(
    const float base[16], uint16_t z, uint16_t y, uint16_t x,
    const float translation_source[16], float out[16])
{
    float rotation[16], composed[16];
    if (!base || !translation_source || !out)
        return -1;
    if (vf3_native_matrix_euler_z_y_x(z, y, x, rotation) != 0)
        return -1;
    vf3_native_matrix_multiply(base, rotation, composed);
    composed[12] = translation_source[12];
    composed[13] = translation_source[13];
    composed[14] = translation_source[14];
    memcpy(out, composed, sizeof composed);
    return 0;
}

int vf3_native_matrix_pose_angles(const float translation_source[16],
                                  int16_t owner_y, int16_t owner_x,
                                  const uint16_t input_angles[3],
                                  float out[16])
{
    float current[16], rotation[16], next[16];
    uint16_t final_x;
    if (!translation_source || !input_angles || !out)
        return -1;
    final_x = (uint16_t)((uint16_t)owner_x + input_angles[2]);

    vf3_native_matrix_identity(current);
    rotation_y((uint16_t)owner_y, rotation);
    vf3_native_matrix_multiply(current, rotation, next);
    memcpy(current, next, sizeof current);
    rotation_z(input_angles[0], rotation);
    vf3_native_matrix_multiply(current, rotation, next);
    memcpy(current, next, sizeof current);
    rotation_y(input_angles[1], rotation);
    vf3_native_matrix_multiply(current, rotation, next);
    memcpy(current, next, sizeof current);
    rotation_x(final_x, rotation);
    vf3_native_matrix_multiply(current, rotation, next);

    next[12] = translation_source[12];
    next[13] = translation_source[13];
    next[14] = translation_source[14];
    memcpy(out, next, sizeof next);
    return 0;
}

int vf3_native_matrix_unit_triple(const float base[16], const float triple[3],
                                  float out[16], float *xz_length,
                                  float *inverse_length)
{
    const float threshold = 1.0e-7f;
    float heading[16], pitch[16], headed[16], result[16];
    const float a = triple ? triple[0] : 0.0f;
    const float b = triple ? triple[1] : 0.0f;
    const float c = triple ? triple[2] : 0.0f;
    const float xy_squared = b * b + a * a;
    const float length_squared = xy_squared + c * c;
    const float inverse_xy = xy_squared < threshold
        ? 0.0f : 1.0f / sqrtf(xy_squared);
    const float inverse_total = length_squared < threshold
        ? 0.0f : 1.0f / sqrtf(length_squared);
    const float horizontal_length = xy_squared < threshold
        ? 0.0f : sqrtf(xy_squared);
    const float heading_sine = inverse_xy * b;
    const float heading_cosine = inverse_xy * a;
    const float pitch_sine = -(inverse_total * c);
    const float pitch_cosine = horizontal_length * inverse_total;

    if (!base || !triple || !out || !xz_length || !inverse_length ||
        !isfinite(a) || !isfinite(b) || !isfinite(c) ||
        !isfinite(xy_squared) || !isfinite(length_squared))
        return -1;

    rotation_z_sincos(heading_sine, heading_cosine, heading);
    rotation_y_sincos(pitch_sine, pitch_cosine, pitch);
    vf3_native_matrix_multiply(base, heading, headed);
    vf3_native_matrix_multiply(headed, pitch, result);
    memcpy(out, result, sizeof result);
    *xz_length = horizontal_length;
    *inverse_length = inverse_total;
    return 0;
}
