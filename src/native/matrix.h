/* Column-major affine math shared by the native motion and renderer paths. */
#ifndef VF3_NATIVE_MATRIX_H
#define VF3_NATIVE_MATRIX_H

#include <stdint.h>

void vf3_native_matrix_identity(float out[16]);
void vf3_native_matrix_multiply(const float left[16], const float right[16],
                                float out[16]);
void vf3_native_matrix_transform_point(const float matrix[16],
                                       const float point[3], float out[3]);
void vf3_native_matrix_translate_local(const float matrix[16],
                                       const float offset[3], float out[16]);
void vf3_native_matrix_scale_axes(const float matrix[16],
                                  float x, float y, float z, float out[16]);

/* Apply 16-bit-turn rotations in the recovered Z-then-Y-then-X order. */
int vf3_native_matrix_euler_z_y_x(uint16_t z, uint16_t y, uint16_t x,
                                 float out[16]);

/* Apply the recovered Z-Y-X turns to `base`, then keep the translation from
 * `translation_source`. This ports the D480 + D4E6 helper pair used by the
 * aim-frame builders. The fourth matrix row/column follows the composed
 * basis; only translation elements 12..14 are preserved. */
int vf3_native_matrix_apply_euler_keep_translation(
    const float base[16], uint16_t z, uint16_t y, uint16_t x,
    const float translation_source[16], float out[16]);

/* Native port of 0x8C09DA1E. Compose the owner Y turn, the three input turns
 * (Z, Y, then X), and preserve the input matrix's translation. The final X
 * turn adds the owner's second turn to input_angles[2], modulo 65536. */
int vf3_native_matrix_pose_angles(const float translation_source[16],
                                  int16_t owner_y, int16_t owner_x,
                                  const uint16_t input_angles[3],
                                  float out[16]);

/* Native port of 0x8C09DC34. Build the heading/pitch basis from the input
 * triple, then compose it after `base`. `xz_length` receives sqrt(x*x+y*y);
 * `inverse_length` receives 1/sqrt(x*x+y*y+z*z). Values below the game's
 * 1e-7 threshold produce zero reciprocals/lengths. */
int vf3_native_matrix_unit_triple(const float base[16], const float triple[3],
                                  float out[16], float *xz_length,
                                  float *inverse_length);

#endif
