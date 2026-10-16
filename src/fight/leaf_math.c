/* leaf_math.c - small leaf routines of the matrix / memory layer.
 *
 *   0x8C03C880  rotation about Y: XMTRX = XMTRX-composed rotation by the angle in r4 (65536 = turn)
 *   0x8C03C940  rotation about Z, same convention
 *   0x8C03B450  transform a point: (r4 -> x, y, z) * XMTRX -> r5 (three floats, w taken as 1)
 *   0x8C043018  memmove(dst = r4, src = r5, count = r6) -> r0 = dst, overlap safe
 *
 * The rotations build the two basis rows of the rotation from sin/cos (fsca), push each row
 * through the current XMTRX and write the four results straight back over the matching XMTRX
 * columns (the double moves with an odd register number target the extended bank). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum { NEGATE = 0x80000000u, SR_T = 1u };

static uint32_t *fr_bank(vf3_matrix_state *s) { return &VF3_FR(s, 0); }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

int vf3_rotate_y_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = s->v[4];
    vf3_fpu_fsca(s->v[VF3_REG_FPUL], fr + 4);          /* fr4 = sin, fr5 = cos */
    const uint32_t sin_a = fr[4], cos_a = fr[5];
    fr[0] = cos_a; fr[1] = 0; fr[2] = sin_a ^ NEGATE; fr[3] = 0;
    fr[6] = cos_a; fr[7] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[5] = 0;                                         /* second row (sin, 0, cos, 0) */
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    xf[0] = fr[0]; xf[1] = fr[1]; xf[2] = fr[2]; xf[3] = fr[3];
    xf[8] = fr[4]; xf[9] = fr[5]; xf[10] = fr[6]; xf[11] = fr[7];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_rotate_z_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = s->v[4];
    vf3_fpu_fsca(s->v[VF3_REG_FPUL], fr + 4);
    const uint32_t sin_a = fr[4], cos_a = fr[5];
    fr[2] = 0; fr[3] = 0; fr[6] = 0;
    fr[0] = cos_a; fr[1] = sin_a;
    fr[4] = sin_a ^ NEGATE;                            /* second row (-sin, cos, 0, 0) */
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[7] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    xf[0] = fr[0]; xf[1] = fr[1]; xf[2] = fr[2]; xf[3] = fr[3];
    xf[4] = fr[4]; xf[5] = fr[5]; xf[6] = fr[6]; xf[7] = fr[7];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_xform_point_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    for (int i = 0; i < 3; ++i) fr[4 + i] = vf3_mem_u32(ram, s->v[4] + 4u * (uint32_t)i);
    s->v[4] += 12;
    vf3_fr_set(s, 7, 1.0f);
    if (!vf3_fpu_ftrv(xf_bank(s), fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, s->v[5] + 4u * (uint32_t)i, fr[4 + i]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_mem_move_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t dst = s->v[4], src = s->v[5], count = s->v[6];
    if (dst != src) {
        if (dst < src) {
            for (uint32_t i = 0; i < count; ++i) vf3_mem_set_u8(ram, dst + i, vf3_mem_u8(ram, src + i));
        } else {
            for (uint32_t i = count; i-- > 0;) vf3_mem_set_u8(ram, dst + i, vf3_mem_u8(ram, src + i));
        }
    }
    s->v[0] = dst;
    s->v[VF3_REG_SR] |= SR_T;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C09D4E6  store XMTRX into the transform object at r4 but keep the object's own translation
 * (floats at +48, +52, +56): they are parked on the stack around the matrix_store call. */
int vf3_store_keep_translation_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    enum { TRANSLATION = 48, MATRIX_STORE = 0x8C03B620, RET_AFTER_STORE = 0x8C09D50E, SAVED = 12 };
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR], saved_r14 = s->v[14], saved_r13 = s->v[13];
    const uint32_t object = s->v[4], frame = sp0 - SAVED - 12u;

    vf3_mem_set_u32(ram, sp0 - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp0 - 8u, saved_r13);
    vf3_mem_set_u32(ram, sp0 - 12u, pr0);
    for (uint32_t i = 0; i < 3; ++i) {
        VF3_FR(s, 3) = vf3_mem_u32(ram, object + TRANSLATION + 4u * i);
        vf3_mem_set_u32(ram, frame + 4u * i, VF3_FR(s, 3));
    }
    s->v[0] = TRANSLATION + 8;
    s->v[14] = object;
    s->v[13] = frame;
    s->v[15] = frame;
    s->v[3] = 0x0C03B620u;                      /* the literal-pool form of the target */
    if (!vf3_guest_call(s, ram, MATRIX_STORE, RET_AFTER_STORE)) return 0;
    for (uint32_t i = 0; i < 3; ++i) {
        VF3_FR(s, 3) = vf3_mem_u32(ram, frame + 4u * i);
        vf3_mem_set_u32(ram, object + TRANSLATION + 4u * i, VF3_FR(s, 3));
    }
    s->v[0] = TRANSLATION + 8;
    s->v[15] = sp0;
    s->v[14] = saved_r14;
    s->v[13] = saved_r13;
    s->v[VF3_REG_PR] = pr0;
    s->pc = pr0;
    return 1;
}

/* ---- XMTRX editing routines (the matrix is the X bank; the originals reach it with FRCHG) ---- */

/* 0x8C03CBD0  XMTRX translation (elements 12..14) = the three floats at r4 */
int vf3_matrix_set_translation_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *xf = xf_bank(s);
    for (int i = 0; i < 3; ++i) xf[12 + i] = vf3_mem_u32(ram, s->v[4] + 4u * (uint32_t)i);
    s->v[4] += 12;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03CC60  XMTRX translation = XMTRX * (FR4, FR5, FR6, 1): move the origin by a local offset */
int vf3_matrix_translate_by_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    vf3_fr_set(s, 7, 1.0f);
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    xf[12] = fr[4]; xf[13] = fr[5]; xf[14] = fr[6]; xf[15] = fr[7];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C970  rotation about Z from a ready sin (FR4) / cos (FR5): the body of 0x8C03C940 */
int vf3_matrix_rotate_sc_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    fr[1] = fr[4];
    fr[4] ^= NEGATE;
    fr[0] = fr[5]; fr[2] = 0; fr[3] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[6] = 0; fr[7] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 8; ++i) xf[i] = fr[i];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03CB70  scale XMTRX's three axis columns by (FR4, FR5, FR6); FR4..FR6 pass through the stack */
int vf3_matrix_scale_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    const uint32_t sp = s->v[15], saved_fr15 = xf[15];
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, sp - 4u * (uint32_t)(i + 1), fr[6 - i]);
    s->v[VF3_REG_FPUL] = saved_fr15;
    for (int axis = 0; axis < 3; ++axis) {
        xf[15] = fr[4 + axis];
        const float scale = vf3_bits_f32(xf[15]);
        for (int i = 0; i < 4; ++i)
            xf[4 * axis + i] = vf3_f32_bits(vf3_f_mul(s, vf3_bits_f32(xf[4 * axis + i]), scale));
    }
    xf[15] = s->v[VF3_REG_FPUL];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C5B0  invert the (rigid) XMTRX in place: transpose the 3x3 rotation and set the
 * translation to -(R^T * t). The dot products run on the pre-swap matrix; FPUL ends up holding
 * the last swapped element. */
int vf3_matrix_invert_rigid_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *xf = xf_bank(s);
    const uint32_t fpscr = s->v[VF3_REG_FPSCR];
    xf[3] = 0; xf[7] = 0;
    xf[11] = vf3_f32_bits(vf3_f_sub(s, vf3_bits_f32(xf[11]), vf3_bits_f32(xf[11])));
    xf[15] = vf3_f32_bits(1.0f);
    if (!vf3_fpu_fipr(xf + 12, xf + 0, fpscr, xf + 3)) return 0;
    if (!vf3_fpu_fipr(xf + 12, xf + 4, fpscr, xf + 7)) return 0;
    if (!vf3_fpu_fipr(xf + 12, xf + 8, fpscr, xf + 11)) return 0;
    const float zero = 0.0f;
    xf[12] = vf3_f32_bits(vf3_f_sub(s, zero, vf3_bits_f32(xf[3])));
    xf[13] = vf3_f32_bits(vf3_f_sub(s, zero, vf3_bits_f32(xf[7])));
    xf[14] = vf3_f32_bits(vf3_f_sub(s, zero, vf3_bits_f32(xf[11])));
    static const int pairs[3][2] = { { 1, 4 }, { 2, 8 }, { 6, 9 } };
    for (int i = 0; i < 3; ++i) {
        s->v[VF3_REG_FPUL] = xf[pairs[i][0]];
        xf[pairs[i][0]] = xf[pairs[i][1]];
        xf[pairs[i][1]] = s->v[VF3_REG_FPUL];
    }
    xf[3] = xf[7] = xf[11] = 0;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C6C0  rotation about X from an fsca angle (r4): columns 1 and 2 of XMTRX */
int vf3_rotate_x_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = s->v[4];
    vf3_fpu_fsca(s->v[VF3_REG_FPUL], fr + 4);
    const uint32_t sin_a = fr[4], cos_a = fr[5];
    fr[0] = 0; fr[3] = 0; fr[7] = 0;
    fr[1] = cos_a; fr[2] = sin_a;
    fr[5] = sin_a ^ NEGATE;                            /* second row (0, -sin, cos, 0) */
    fr[6] = cos_a;
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[4] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 8; ++i) xf[4 + i] = fr[i];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C09D52E  transform the point (FR4, 0, 0) by XMTRX and store it at r4 */
int vf3_xform_axis_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    enum { XFORM_POINT = 0x8C03B450, RET_AFTER_XFORM = 0x8C09D54C };
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR], dest = s->v[4], frame = sp0 - 20u;

    vf3_mem_set_u32(ram, sp0 - 4u, pr0);
    vf3_mem_set_u32(ram, frame, dest);
    vf3_mem_set_u32(ram, frame + 4u, VF3_FR(s, 4));
    VF3_FR(s, 4) = 0;
    vf3_mem_set_u32(ram, frame + 8u, 0);
    vf3_mem_set_u32(ram, frame + 12u, 0);
    s->v[0] = 12;
    s->v[3] = 0x0C03B450u;
    s->v[4] = frame + 4u;
    s->v[5] = dest;
    s->v[15] = frame;
    if (!vf3_guest_call(s, ram, XFORM_POINT, RET_AFTER_XFORM)) return 0;
    s->v[15] = sp0;
    s->v[VF3_REG_PR] = pr0;
    s->pc = pr0;
    return 1;
}

/* 0x8C09D480  apply the three 16-bit Euler angles at r4 (Z, Y, then X) to XMTRX */
int vf3_rotate_euler_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    enum { ROTATE_Z = 0x8C03C940, ROTATE_Y = 0x8C03C880, ROTATE_X = 0x8C03C6C0,
           RET_AFTER_Z = 0x8C09D49A, RET_AFTER_Y = 0x8C09D4A4 };
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR], angles = s->v[4], frame = sp0 - 16u;
    const uint32_t z = vf3_mem_u16(ram, angles), y = vf3_mem_u16(ram, angles + 2u),
                   x = vf3_mem_u16(ram, angles + 4u);

    vf3_mem_set_u32(ram, sp0 - 4u, pr0);
    vf3_mem_set_u16(ram, frame + 8u, (uint16_t)z);
    vf3_mem_set_u16(ram, frame + 4u, (uint16_t)y);
    vf3_mem_set_u16(ram, frame, (uint16_t)x);
    s->v[15] = frame;

    s->v[0] = (uint32_t)(int32_t)(int16_t)z;
    s->v[3] = 0x0C03C940u;
    s->v[4] = z;
    if (!vf3_guest_call(s, ram, ROTATE_Z, RET_AFTER_Z)) return 0;
    s->v[0] = (uint32_t)(int32_t)(int16_t)y;
    s->v[3] = 0x0C03C880u;
    s->v[4] = y;
    s->v[15] = frame;
    if (!vf3_guest_call(s, ram, ROTATE_Y, RET_AFTER_Y)) return 0;

    s->v[4] = x;
    s->v[15] = sp0;
    s->v[3] = 0x0C03C6C0u;
    s->v[VF3_REG_PR] = pr0;                            /* the original tail-jumps with PR restored */
    return vf3_guest_call(s, ram, ROTATE_X, pr0);
}
