/* Native port of the aim-frame builders (0x8C09E060 / 0x8C09E6B2).
 *
 * The guest builders run on XMTRX, the FR bank and the 0x40-byte matrix stack
 * at 0x0C19D2E4.  This port keeps that shape: `vf3_native_aim` carries a flat
 * matrix RAM whose base lets every guest address (the builder's frame, the
 * output block, the kind record, the object and the caller's stack words)
 * resolve to the same words the guest saw, plus XMTRX, a local matrix stack,
 * the FR bank and the register file.
 *
 * The SH-4 FPU primitives are reproduced with sinf/cosf/sqrtf and fmaf; the
 * residual against the guest is last-bit (the guest's fsca table and fsrra
 * against libm), which the replay tolerates.  See docs/re/motion_aim.md. */
#include "motion_aim.h"
#include "matrix.h"

#include <math.h>
#include <string.h>

#define AIM_NEGATE 0x80000000u
#define AIM_LIT_TWO 0x40000000u
#define AIM_LIT_HALF 0x3F000000u
#define AIM_LIT_ONE 0x3F800000u
#define AIM_LIT_MINUS_ONE 0xBF800000u
#define AIM_LIT 0x33D6BF94u
#define AIM_LIT_TENTH 0xBDCCCCCCu

static float aim_fbits(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static uint32_t aim_ubits(float f)
{
    uint32_t u;
    memcpy(&u, &f, 4);
    return u;
}

/* the float word at a guest address.  The builder reads halfwords too (the
 * euler's angle triples sit at r4, r4+6 and r4+12), so the address arithmetic
 * has to be byte-exact: a shift by two would alias every unaligned guest
 * address onto the word below it. */
static float *aim_p(vf3_native_aim *a, uint32_t addr)
{
    return (float *)((uint8_t *)a->ram + (addr - a->ram_base));
}

static uint32_t aim_adr(vf3_native_aim *a, const float *p)
{
    return a->ram_base + (uint32_t)((const uint8_t *)p - (const uint8_t *)a->ram);
}

/* frame access: the frame lives at a->f */
static float MR(vf3_native_aim *a, uint32_t off) { return *aim_p(a, a->f + off); }
static void MW(vf3_native_aim *a, uint32_t off, float v) { *aim_p(a, a->f + off) = v; }
static uint32_t UR(vf3_native_aim *a, uint32_t off) { return aim_ubits(MR(a, off)); }

/* absolute access (a pointer kept in a frame word) */
static float AR(vf3_native_aim *a, uint32_t addr) { return *aim_p(a, addr); }
static void AW(vf3_native_aim *a, uint32_t addr, float v) { *aim_p(a, addr) = v; }

#define R(n)  (a->r[n])
#define F(n)  (a->fr[n])

/* ---- the guest's matrix helpers, natively ---- */

static void aim_push(vf3_native_aim *a, uint32_t src)
{
    if (a->sp >= (int)(sizeof a->stk / sizeof a->stk[0]))
        return;
    memcpy(a->stk[a->sp++], a->xm, sizeof a->xm);
    if (src)
        memcpy(a->xm, aim_p(a, src), sizeof a->xm);
}

static void aim_pop(vf3_native_aim *a)
{
    if (a->sp <= 0)
        return;
    memcpy(a->xm, a->stk[--a->sp], sizeof a->xm);
}

static void aim_identity(vf3_native_aim *a) { vf3_native_matrix_identity(a->xm); }

static void aim_store(vf3_native_aim *a, uint32_t dst)
{
    memcpy(aim_p(a, dst), a->xm, sizeof a->xm);
}

static void aim_load(vf3_native_aim *a, uint32_t src)
{
    memcpy(a->xm, aim_p(a, src), sizeof a->xm);
}

static void aim_copy(vf3_native_aim *a, uint32_t dst, uint32_t src)
{
    memcpy(aim_p(a, dst), aim_p(a, src), 64u);
}

/* 0x8C03CC60: XMTRX translation = XMTRX * (FR4, FR5, FR6, 1) */
static void aim_translate_by(vf3_native_aim *a)
{
    const float x = F(4), y = F(5), z = F(6);
    a->xm[12] = a->xm[0] * x + a->xm[4] * y + a->xm[8] * z + a->xm[12];
    a->xm[13] = a->xm[1] * x + a->xm[5] * y + a->xm[9] * z + a->xm[13];
    a->xm[14] = a->xm[2] * x + a->xm[6] * y + a->xm[10] * z + a->xm[14];
    a->xm[15] = a->xm[3] * x + a->xm[7] * y + a->xm[11] * z + a->xm[15];
}

/* 0x8C03CBD0: XMTRX translation = the three floats at r4 */
static void aim_set_translation(vf3_native_aim *a, uint32_t src)
{
    const float *t = aim_p(a, src);
    a->xm[12] = t[0];
    a->xm[13] = t[1];
    a->xm[14] = t[2];
}

/* 0x8C09D4E6: store XMTRX but keep the object's own translation (+48) */
static void aim_store_keep_translation(vf3_native_aim *a, uint32_t dst)
{
    float *object = aim_p(a, dst);
    float kept[3] = { object[12], object[13], object[14] };
    memcpy(object, a->xm, sizeof a->xm);
    object[12] = kept[0];
    object[13] = kept[1];
    object[14] = kept[2];
}

/* 0x8C03B820: store XMTRX's translation (XF12..XF14) at r4..r4+8 */
static void aim_store_translation(vf3_native_aim *a, uint32_t dst)
{
    float *object = aim_p(a, dst);
    object[0] = a->xm[12];
    object[1] = a->xm[13];
    object[2] = a->xm[14];
}

static void aim_point(vf3_native_aim *a, const float p[3], uint32_t dst)
{
    float out[3];
    vf3_native_matrix_transform_point(a->xm, p, out);
    float *d = aim_p(a, dst);
    d[0] = out[0];
    d[1] = out[1];
    d[2] = out[2];
}

/* 0x8C03B450: (r4 -> x,y,z) * XMTRX -> r5 */
static void aim_xform_point(vf3_native_aim *a, uint32_t src, uint32_t dst)
{
    aim_point(a, aim_p(a, src), dst);
}

/* 0x8C09D52E: the point (FR4, 0, 0) through XMTRX, stored at r4 */
static void aim_xform_axis(vf3_native_aim *a, uint32_t dst)
{
    const float p[3] = { F(4), 0.0f, 0.0f };
    aim_point(a, p, dst);
}

/* 0x8C09D42C: the point (FR4, 0, FR5) through XMTRX, stored at r4 */
static void aim_xform_vec(vf3_native_aim *a, uint32_t dst)
{
    const float p[3] = { F(4), 0.0f, F(5) };
    aim_point(a, p, dst);
}

/* 0x8C09D554: the point (0, FR4, FR5) through XMTRX, stored at r4 */
static void aim_xform_vec2(vf3_native_aim *a, uint32_t dst)
{
    const float p[3] = { 0.0f, F(4), F(5) };
    aim_point(a, p, dst);
}

static void aim_rot_z(float sine, float cosine, float out[16])
{
    vf3_native_matrix_identity(out);
    out[0] = cosine;
    out[1] = sine;
    out[4] = -sine;
    out[5] = cosine;
}

static void aim_rot_y(float sine, float cosine, float out[16])
{
    vf3_native_matrix_identity(out);
    out[0] = cosine;
    out[2] = -sine;
    out[8] = sine;
    out[10] = cosine;
}

static void aim_rot_x(float sine, float cosine, float out[16])
{
    vf3_native_matrix_identity(out);
    out[5] = cosine;
    out[6] = sine;
    out[9] = -sine;
    out[10] = cosine;
}

static const double aim_turn = 3.14159265358979323846 / 32768.0;

static void aim_rotate_z_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_z(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

static void aim_rotate_y_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_y(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

static void aim_rotate_x_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_x(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

/* 0x8C03C970: rotation about Z from a ready sin (FR4) / cos (FR5) */
static void aim_rotate_sc(vf3_native_aim *a)
{
    float rotation[16], product[16];
    aim_rot_z(F(4), F(5), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

/* 0x8C09D480: the three 16-bit angles at r4 (Z, Y, X) applied to XMTRX */
static void aim_rotate_euler(vf3_native_aim *a, uint32_t angles)
{
    const uint8_t *src = (const uint8_t *)aim_p(a, angles);
    uint16_t z, y, x;
    memcpy(&z, src, 2);
    memcpy(&y, src + 2, 2);
    memcpy(&x, src + 4, 2);
    float composed[16];
    if (vf3_native_matrix_apply_euler_keep_translation(a->xm, z, y, x,
                                                       a->xm, composed) != 0)
        return;
    memcpy(a->xm, composed, sizeof composed);
}

/* 0x8C03C5B0: in-place inverse of a rigid XMTRX (R^T, -R^T t) */
static void aim_invert_rigid(const float m[16], float out[16])
{
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            out[4 * c + r] = m[4 * r + c];
    for (int r = 0; r < 3; ++r)
        out[12 + r] = -(m[4 * r] * m[12] + m[4 * r + 1] * m[13] +
                        m[4 * r + 2] * m[14]);
    out[3] = out[7] = out[11] = 0.0f;
    out[15] = 1.0f;
}

/* 0x8C09DC34: pass_prep runs the triple through the inverted XMTRX, then the
 * heading/pitch basis is composed after XMTRX and the two lengths are written
 * to the caller's r5 (frame+8) and r6 (frame+12). */
static int aim_unit_triple(vf3_native_aim *a, uint32_t triple)
{
    float inverted[16], p[3];
    aim_invert_rigid(a->xm, inverted);
    vf3_native_matrix_transform_point(inverted, aim_p(a, triple), p);
    float composed[16];
    float xz_length, inverse_length;
    if (vf3_native_matrix_unit_triple(a->xm, p, composed,
                                      &xz_length, &inverse_length) != 0)
        return -1;
    memcpy(a->xm, composed, sizeof composed);
    const float m = xz_length * xz_length + p[2] * p[2];
    MW(a, 8, m < 1.0e-7f ? 0.0f : sqrtf(m));
    MW(a, 12, inverse_length);
    return 0;
}

/* frame[0x40 + k] += FR0 * frame[src + k], k = 0, 4, ..., 12 (the aim_frame
 * builder's fma_row: the destination is always the 0x40 block) */
static void aim_fma_row(vf3_native_aim *a, uint32_t src)
{
    for (uint32_t k = 0; k < 12; k += 4)
        MW(a, 0x40u + k, fmaf(F(0), MR(a, src + k), MR(a, 0x40u + k)));
}

/* the aim_frame_b builder's fma_row: frame[dst + k] += FR0 * frame[src + k] */
static void aim_fma_row_at(vf3_native_aim *a, uint32_t dst, uint32_t src)
{
    for (uint32_t k = 0; k < 12; k += 4)
        MW(a, dst + k, fmaf(F(0), MR(a, src + k), MR(a, dst + k)));
}

/* the 16-bit halfword at a guest address */
static uint16_t aim_h16(vf3_native_aim *a, uint32_t addr)
{
    uint16_t v;
    memcpy(&v, (const uint8_t *)aim_p(a, addr), 2);
    return v;
}

/* 0x8C09DA1E: the three-angle wrapper the second builder calls.
 *
 *   r4 = the angle record (three halfwords at +0 / +2 / +4), r5 = a base pointer.
 *   The wrapper parks XMTRX's own translation on its frame, rebuilds the rotation
 *   from the identity (Ry(base + 30), Rz(record + 0), Ry(record + 2),
 *   Rx(*(int16 *)(base + 0x22E6) + record + 4)) and puts the parked translation
 *   back, so only the rotation part changes. */
static void aim_three_angles(vf3_native_aim *a, uint32_t angles, uint32_t base)
{
    const uint32_t frame = a->r[15] - 24u;
    float *parked = aim_p(a, frame + 4u);
    const float kept[3] = { a->xm[12], a->xm[13], a->xm[14] };

    /* the guest parks XMTRX's translation with 0x8C03B820 before it rebuilds the
     * rotation, and puts it back with 0x8C03CBD0 afterwards: the round trip
     * through its own frame is part of the mechanism. */
    parked[0] = kept[0];
    parked[1] = kept[1];
    parked[2] = kept[2];

    aim_identity(a);
    aim_rotate_y_angle(a, aim_h16(a, base + 30u));
    aim_rotate_z_angle(a, aim_h16(a, angles));
    aim_rotate_y_angle(a, aim_h16(a, angles + 2u));
    aim_rotate_x_angle(a, (uint16_t)(aim_h16(a, base + 0x22E6u) + aim_h16(a, angles + 4u)));
    a->xm[12] = parked[0];
    a->xm[13] = parked[1];
    a->xm[14] = parked[2];
}

/* ---- 0x8C09E060 ---- */

int vf3_native_aim_frame(vf3_native_aim *a, const float *record_a,
                         float *block_b, const float *object,
                         const float *object7, float fr4)
{
    if (!a || !record_a || !block_b || !object || !object7)
        return -1;
    const uint32_t f = a->f;
    const uint32_t sp0 = f + 340u;
    const uint32_t rec = aim_adr(a, record_a);
    const uint32_t block = aim_adr(a, block_b);
    const uint32_t obj = aim_adr(a, object);
    const uint32_t obj7 = aim_adr(a, object7);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const float saved_f[3] = { F(15), F(14), F(13) };
    for (int i = 0; i < 7; ++i)
        *aim_p(a, sp0 - 4u * (uint32_t)(i + 1)) = aim_fbits(saved_r[i]);
    for (int i = 0; i < 3; ++i)
        *aim_p(a, sp0 - 28u - 4u * (uint32_t)(i + 1)) = saved_f[i];
    *aim_p(a, sp0 - 44u) = aim_fbits(a->pr);
    R(15) = f;

    R(13) = rec;
    R(11) = block;
    MW(a, 0, aim_fbits(obj));
    MW(a, 4, aim_fbits(obj7));
    R(10) = UR(a, 0x160u);
    F(4) = fr4;

    aim_push(a, 0);
    aim_identity(a);
    aim_store(a, f + 0x90u);
    aim_store(a, f + 80u);
    aim_pop(a);

    F(4) = record_a[0];
    F(5) = aim_fbits(aim_ubits(record_a[2]) ^ AIM_NEGATE);
    aim_xform_vec(a, f + 0x11Cu);
    aim_store(a, f + 0xD0u);

    MW(a, 0x100, MR(a, 0x11C));
    MW(a, 0x104, MR(a, 0x120));
    MW(a, 0x108, MR(a, 0x124));

    F(6) = object[1];
    F(15) = 0.0f;
    F(5) = F(15);
    F(4) = object[0];
    aim_translate_by(a);
    aim_rotate_euler(a, UR(a, 0x158u));
    aim_store_keep_translation(a, f + 0xD0u);
    aim_copy(a, block, f + 0xD0u);
    aim_store_keep_translation(a, f + 0x90u);

    MW(a, 0xC0, MR(a, 0x100));
    MW(a, 0xC4, MR(a, 0x104));
    MW(a, 0xC8, MR(a, 0x108));
    aim_store(a, f + 16u);
    aim_push(a, 0);
    aim_load(a, f + 0x90u);

    F(6) = aim_fbits(aim_ubits(record_a[5]) ^ AIM_NEGATE);
    F(5) = F(15);
    F(4) = record_a[3];
    aim_translate_by(a);
    aim_store(a, f + 0xD0u);
    aim_pop(a);

    F(4) = object[2];
    F(0) = F(4);
    aim_fma_row(a, 0x30u);
    aim_load(a, f + 16u);
    aim_rotate_euler(a, UR(a, 0x158u) + 6u);

    for (uint32_t k = 0; k < 12; k += 4) {
        F(2) = AR(a, obj7 + k);
        F(3) = AR(a, UR(a, 0x164u) + k);
        F(2) = F(2) + F(3);
        MW(a, 0x110u + k, F(2));
    }
    if (aim_unit_triple(a, f + 0x110u) != 0)
        return -2;
    aim_store_keep_translation(a, block + 0xC0u);

    F(6) = object[3];
    F(4) = object[4];
    F(5) = MR(a, 8);
    F(7) = F(4) + F(6);
    F(14) = F(15);
    if (F(5) >= F(7)) {
        aim_store_keep_translation(a, f + 80u);
        aim_store_keep_translation(a, UR(a, 0x154u));
    } else {
        F(10) = F(5) * F(5);
        F(9) = F(6) * F(6);
        F(8) = F(4) * F(4);
        F(2) = F(4);
        F(4) = F(4) * F(6);
        F(3) = F(10) - F(9);
        F(7) = aim_fbits(AIM_LIT_TWO);
        F(2) = F(2) * F(5);
        F(4) = F(4) * F(7);
        F(3) = F(3) + F(8);
        F(8) = F(8) + F(9);
        F(2) = F(2) * F(7);
        F(5) = F(3);
        F(8) = F(8) - F(10);
        F(5) = F(5) / F(2);
        F(14) = F(8);
        F(14) = F(14) / F(4);
        F(4) = aim_fbits(AIM_LIT_ONE);
        F(6) = aim_fbits(AIM_LIT_MINUS_ONE);
        if (F(14) > F(4))
            F(14) = F(4);
        else if (F(6) > F(14))
            F(14) = F(6);
        if (F(5) > F(4))
            F(5) = F(4);
        else if (F(6) > F(5))
            F(5) = F(6);
        F(3) = F(5) * F(5);
        F(13) = aim_fbits(AIM_LIT);
        F(4) = F(4) - F(3);
        if (F(13) > F(4))
            F(4) = 0.0f;
        else
            F(4) = sqrtf(F(4));
        aim_rotate_sc(a);
        aim_store_keep_translation(a, f + 80u);

        F(5) = aim_fbits(AIM_LIT_HALF);
        F(6) = F(14) * F(5);
        F(4) = F(6) + F(5);
        if (F(13) > F(4))
            F(3) = 0.0f;
        else {
            F(3) = F(4);
            F(3) = sqrtf(F(3));
        }
        F(4) = F(5) - F(6);
        F(14) = aim_fbits(aim_ubits(F(3)) ^ AIM_NEGATE);
        if (F(13) > F(4))
            F(13) = 0.0f;
        else {
            F(13) = F(4);
            F(13) = sqrtf(F(13));
        }
        F(5) = F(13);
        F(4) = F(14);
        aim_rotate_sc(a);
        aim_store_keep_translation(a, UR(a, 0x154u));
        F(5) = F(13);
        F(4) = F(14);
        aim_rotate_sc(a);
    }

    MW(a, 0, aim_fbits(block + 64u));
    aim_store_keep_translation(a, f + 0xD0u);
    aim_push(a, 0);
    aim_load(a, f + 0xD0u);
    aim_store_translation(a, f + 0x11Cu);
    aim_store(a, UR(a, 0));
    aim_pop(a);
    aim_set_translation(a, f + 0x11Cu);
    aim_store_translation(a, R(10));
    F(4) = AR(a, UR(a, 0x15Cu));
    aim_xform_axis(a, R(10) + 12u);
    aim_store(a, f + 16u);

    F(4) = record_a[6];
    F(0) = F(4);
    aim_fma_row(a, 0x10u);

    AW(a, UR(a, 0x154u) + 48u, F(14));
    MW(a, 0, aim_fbits(block + 0x80u));
    aim_load(a, f + 16u);
    aim_store_translation(a, f + 0x80u);
    aim_push(a, 0);
    aim_load(a, f + 80u);
    aim_store(a, f + 16u);
    aim_store(a, UR(a, 0));
    aim_pop(a);
    aim_load(a, f + 16u);
    aim_store_translation(a, R(10) + 24u);
    F(4) = AR(a, UR(a, 0x15Cu) + 4u);
    aim_xform_axis(a, R(10) + 36u);
    F(4) = record_a[9];
    F(6) = F(15);
    F(5) = F(15);
    aim_translate_by(a);
    aim_rotate_euler(a, UR(a, 0x158u) + 12u);
    aim_store(a, block + 0xC0u);
    F(4) = AR(a, UR(a, 0x15Cu) + 8u);
    aim_xform_axis(a, R(10) + 48u);

    for (int i = 0; i < 7; ++i) R(14 - i) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    return 0;
}

/* ---- 0x8C09E6B2 ---- */

int vf3_native_aim_frame_b(vf3_native_aim *a, const float *record_a,
                           const float *owner, const float *object,
                           const float *object7, float fr4)
{
    if (!a || !record_a || !owner || !object || !object7)
        return -1;
    const uint32_t f = a->f;
    const uint32_t sp0 = f + 348u;             /* SAVED 44 + FRAME 0x130 */
    const uint32_t rec = aim_adr(a, record_a);
    const uint32_t obj6 = aim_adr(a, object);
    const uint32_t obj7 = aim_adr(a, object7);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const float saved_f[3] = { F(15), F(14), F(13) };
    for (int i = 0; i < 7; ++i)
        *aim_p(a, sp0 - 4u * (uint32_t)(i + 1)) = aim_fbits(saved_r[i]);
    for (int i = 0; i < 3; ++i)
        *aim_p(a, sp0 - 28u - 4u * (uint32_t)(i + 1)) = saved_f[i];
    *aim_p(a, sp0 - 44u) = aim_fbits(a->pr);
    R(15) = f;

    R(10) = rec;
    MW(a, 20, aim_fbits(aim_adr(a, owner)));   /* the pointer the caller passed */
    MW(a, 4, aim_fbits(obj6));
    MW(a, 0, aim_fbits(obj7));
    R(11) = UR(a, 0x160u);
    R(12) = UR(a, 0x168u);
    R(14) = UR(a, 0x16Cu);
    MW(a, 16, fr4);

    aim_push(a, 0);
    aim_identity(a);
    aim_store(a, f + 0xF0u);
    aim_store(a, f + 0xB0u);
    aim_store(a, f + 112u);
    aim_pop(a);
    aim_push(a, 0);

    F(6) = aim_fbits(aim_ubits(record_a[2]) ^ AIM_NEGATE);
    F(15) = 0.0f;
    F(5) = F(15);
    F(4) = record_a[0];
    aim_translate_by(a);
    aim_store(a, f + 0xF0u);
    aim_pop(a);
    aim_push(a, 0);

    F(6) = object7[1];
    F(5) = F(15);
    F(4) = object7[0];
    aim_translate_by(a);
    aim_rotate_euler(a, UR(a, 0x164u));

    MW(a, 88, AR(a, UR(a, 0x15Cu)));
    F(4) = MR(a, 16) + AR(a, UR(a, 0x15Cu) + 4u);
    MW(a, 92, F(4));
    MW(a, 96, AR(a, UR(a, 0x15Cu) + 8u));
    if (aim_unit_triple(a, f + 88u) != 0)
        return -2;

    F(6) = object7[2];
    F(4) = object7[3];
    F(7) = F(4) + F(6);
    F(5) = MR(a, 8);
    F(14) = F(15);
    if (F(5) >= F(7)) {
        aim_store_keep_translation(a, f + 0xB0u);
        aim_store_keep_translation(a, R(11));
    } else {
        F(10) = F(5) * F(5);
        F(8) = F(6) * F(6);
        F(7) = F(4) * F(4);
        F(2) = F(4) * F(5);
        F(3) = F(10) - F(8);
        F(9) = aim_fbits(AIM_LIT_TWO);
        F(6) = F(6) * F(4);
        F(4) = aim_fbits(AIM_LIT_ONE);
        F(2) = F(2) * F(9);
        F(3) = F(3) + F(7);
        F(7) = F(7) + F(8);
        F(6) = F(6) * F(9);
        F(5) = F(3) / F(2);
        F(7) = F(7) - F(10);
        F(14) = F(7) / F(6);
        F(6) = aim_fbits(AIM_LIT_MINUS_ONE);
        if (F(5) > F(4))
            F(5) = F(4);
        else if (F(6) > F(5))
            F(5) = F(6);
        if (F(14) > F(4))
            F(14) = F(4);
        else if (F(6) > F(14))
            F(14) = F(6);
        F(3) = F(5) * F(5);
        F(13) = aim_fbits(AIM_LIT);
        F(4) = F(4) - F(3);
        if (F(13) > F(4))
            F(3) = 0.0f;
        else
            F(3) = sqrtf(F(4));
        F(4) = aim_fbits(aim_ubits(F(3)) ^ AIM_NEGATE);
        aim_rotate_sc(a);
        aim_store_keep_translation(a, f + 0xB0u);

        F(4) = aim_fbits(AIM_LIT_HALF);
        F(6) = F(14) * F(4);
        F(5) = F(6) + F(4);
        F(4) = F(4) - F(6);
        /* GT(m, n) is fl(n) > fl(m): the tiny-literal test reads the other way round */
        if (F(13) > F(5))
            F(14) = 0.0f;
        else
            F(14) = sqrtf(F(5));
        if (F(13) > F(4))
            F(13) = 0.0f;
        else
            F(13) = sqrtf(F(4));
        F(5) = F(13);
        F(4) = F(14);
        aim_rotate_sc(a);
        aim_store_keep_translation(a, R(11));
        F(5) = F(13);
        F(4) = F(14);
        aim_rotate_sc(a);
    }

    aim_store_keep_translation(a, f + 0xF0u);
    aim_push(a, 0);
    aim_load(a, f + 0xF0u);
    aim_store_translation(a, f + 100u);
    aim_store(a, UR(a, 4));
    aim_pop(a);
    aim_set_translation(a, f + 100u);
    aim_store_translation(a, R(14));
    aim_store(a, f + 24u);
    R(4) = R(14) + 12;
    F(4) = AR(a, R(12));
    aim_xform_axis(a, R(14) + 12u);

    F(4) = record_a[3];
    F(0) = F(4);
    aim_fma_row_at(a, 72u, 24u);
    {
        const uint32_t r11 = R(11);
        for (uint32_t k = 0; k < 12; k += 4)
            *aim_p(a, r11 + 48u + k) = MR(a, 72u + k);
    }

    R(3) = UR(a, 4) + 64u;
    MW(a, 0, aim_fbits(R(3)));
    MW(a, 0xE0, MR(a, 72));
    MW(a, 0xE4, MR(a, 76));
    MW(a, 0xE8, MR(a, 80));
    aim_load(a, f + 0xB0u);
    aim_store(a, UR(a, 0));

    {
        const uint32_t r14 = R(14);
        for (uint32_t k = 0; k < 12; k += 4)
            *aim_p(a, r14 + 24u + k) = MR(a, 72u + k);
    }
    R(4) = R(14) + 36;
    F(4) = AR(a, R(12) + 4u);
    aim_xform_axis(a, R(14) + 36u);
    R(4) = R(14) + 48;
    F(4) = AR(a, R(12) + 8u);
    aim_xform_axis(a, R(14) + 48u);
    F(4) = record_a[6];
    F(6) = F(15);
    F(5) = F(15);
    aim_translate_by(a);

    R(5) = UR(a, 20);
    R(4) = UR(a, 0x164u) + 6u;
    aim_three_angles(a, UR(a, 0x164u) + 6u, UR(a, 20));
    aim_store(a, f + 112u);
    aim_copy(a, UR(a, 4) + 0x80u, f + 112u);

    MW(a, 92, aim_fbits(AIM_LIT_TENTH));
    F(3) = MR(a, 92);
    F(4) = F(3);
    F(3) = F(3) + F(4);
    MW(a, 96, F(3));
    F(4) = MR(a, 92);
    F(3) = F(4) - F(4);
    MW(a, 88, F(3));
    aim_xform_point(a, f + 88u, UR(a, 0x170u));

    R(4) = R(14) + 60;
    F(4) = AR(a, R(12) + 12u);
    aim_xform_vec2(a, R(14) + 60u);
    MW(a, 100, F(15));
    MW(a, 104, AR(a, R(12) + 16u));
    MW(a, 108, AR(a, R(12) + 20u));
    aim_xform_point(a, f + 100u, R(14) + 72u);
    aim_pop(a);

    for (int i = 0; i < 7; ++i) R(14 - i) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    return 0;
}
