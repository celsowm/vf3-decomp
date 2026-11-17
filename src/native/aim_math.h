/* aim_math.h - the shared native matrix-stack helpers of the aim/pose
 * orchestration family.
 *
 * The guest pose processes run on XMTRX (the current transform), the FR bank
 * and the 0x40-byte matrix stack whose control block lives at 0x0C19D2E4.
 * `vf3_native_aim` carries a flat matrix RAM (every guest address resolves
 * through `ram_base`), XMTRX, a local matrix stack, the FR bank and the
 * register file, so the arithmetic (fsca/fsrra/ftrv/fmac) is reproduced with
 * sinf/cosf/sqrtf and a float multiply-add.
 *
 * These were formerly the statics of src/native/motion_aim.c; they are
 * promoted here so the whole aim/pose family shares one set.  The family:
 *   0x8C09E060 aim_frame          (motion_aim.c)
 *   0x8C09E6B2 aim_frame_b        (motion_aim.c)
 *   0x8C09D4B0 halfword_frame     (halfword_frame.c)
 *   0x8C09E428 aim_midpoints      (aim_midpoints.c)
 *   0x8C09E4C8 matrix_basis       (matrix_basis.c)
 *   0x8C09DCDC facing_update      (facing_update.c)
 * and the callees they pull in (midpoint_angles, atan, pass_prep).
 */
#ifndef VF3_NATIVE_AIM_MATH_H
#define VF3_NATIVE_AIM_MATH_H

#include "motion_aim.h"

void vf3_aim_identity(vf3_native_aim *a);
void vf3_aim_store(vf3_native_aim *a, uint32_t dst);
void vf3_aim_load(vf3_native_aim *a, uint32_t src);
void vf3_aim_copy(vf3_native_aim *a, uint32_t dst, uint32_t src);
void vf3_aim_push(vf3_native_aim *a, uint32_t src);
void vf3_aim_pop(vf3_native_aim *a);
void vf3_aim_translate_by(vf3_native_aim *a);
void vf3_aim_set_translation(vf3_native_aim *a, uint32_t src);
void vf3_aim_store_keep_translation(vf3_native_aim *a, uint32_t dst);
void vf3_aim_store_translation(vf3_native_aim *a, uint32_t dst);
void vf3_aim_xform_point(vf3_native_aim *a, uint32_t src, uint32_t dst);
void vf3_aim_xform_axis(vf3_native_aim *a, uint32_t dst);
void vf3_aim_xform_vec(vf3_native_aim *a, uint32_t dst);
void vf3_aim_xform_vec2(vf3_native_aim *a, uint32_t dst);
void vf3_aim_rotate_z_angle(vf3_native_aim *a, uint16_t angle);
void vf3_aim_rotate_y_angle(vf3_native_aim *a, uint16_t angle);
void vf3_aim_rotate_x_angle(vf3_native_aim *a, uint16_t angle);
void vf3_aim_rotate_sc(vf3_native_aim *a);
void vf3_aim_rotate_euler(vf3_native_aim *a, uint32_t angles);
void vf3_aim_invert_rigid(const float m[16], float out[16]);
int  vf3_aim_unit_triple(vf3_native_aim *a, uint32_t triple);
void vf3_aim_fma_row(vf3_native_aim *a, uint32_t src);
void vf3_aim_fma_row_at(vf3_native_aim *a, uint32_t dst, uint32_t src);
void vf3_aim_three_angles(vf3_native_aim *a, uint32_t angles, uint32_t base);

/* the 16-bit halfword / 32-bit word at a guest address, byte-exact */
uint16_t vf3_aim_h16(vf3_native_aim *a, uint32_t addr);
float   *vf3_aim_p(vf3_native_aim *a, uint32_t addr);
uint32_t vf3_aim_adr(vf3_native_aim *a, const float *p);
float    vf3_aim_fbits(uint32_t u);
uint32_t vf3_aim_ubits(float f);

/* byte / halfword / word writers for the pose callee frames (ram access) */
uint8_t  vf3_aim_u8(vf3_native_aim *a, uint32_t addr);
void     vf3_aim_set_u16(vf3_native_aim *a, uint32_t addr, uint16_t v);
void     vf3_aim_set_u32(vf3_native_aim *a, uint32_t addr, uint32_t v);
uint32_t vf3_aim_u32(vf3_native_aim *a, uint32_t addr);

#endif
