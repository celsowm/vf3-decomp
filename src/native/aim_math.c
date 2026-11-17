/* aim_math.c - shared native matrix-stack helpers of the aim/pose family.
 * See aim_math.h.  These are the promoted statics of motion_aim.c, so the
 * arithmetic and byte-exact address handling are unchanged from the proven
 * aim-frame ports. */
#include "aim_math.h"
#include "matrix.h"

#include <math.h>
#include <string.h>

#define AIM_NEGATE 0x80000000u
#define AIM_LIT    0x33D6BF94u

float vf3_aim_fbits(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

uint32_t vf3_aim_ubits(float f)
{
    uint32_t u;
    memcpy(&u, &f, 4);
    return u;
}

float *vf3_aim_p(vf3_native_aim *a, uint32_t addr)
{
    return (float *)((uint8_t *)a->ram + (addr - a->ram_base));
}

uint32_t vf3_aim_adr(vf3_native_aim *a, const float *p)
{
    return a->ram_base + (uint32_t)((const uint8_t *)p - (const uint8_t *)a->ram);
}

/* frame access: the frame lives at a->f */
static float MR(vf3_native_aim *a, uint32_t off) { return *vf3_aim_p(a, a->f + off); }
static void MW(vf3_native_aim *a, uint32_t off, float v) { *vf3_aim_p(a, a->f + off) = v; }
static uint32_t UR(vf3_native_aim *a, uint32_t off) { return vf3_aim_ubits(MR(a, off)); }

/* absolute access (a pointer kept in a frame word) */
static float AR(vf3_native_aim *a, uint32_t addr) { return *vf3_aim_p(a, addr); }

#define R(n)  (a->r[n])
#define F(n)  (a->fr[n])

void vf3_aim_push(vf3_native_aim *a, uint32_t src)
{
    if (a->sp >= (int)(sizeof a->stk / sizeof a->stk[0]))
        return;
    memcpy(a->stk[a->sp++], a->xm, sizeof a->xm);
    if (src)
        memcpy(a->xm, vf3_aim_p(a, src), sizeof a->xm);
}

void vf3_aim_pop(vf3_native_aim *a)
{
    if (a->sp <= 0)
        return;
    memcpy(a->xm, a->stk[--a->sp], sizeof a->xm);
}

void vf3_aim_identity(vf3_native_aim *a) { vf3_native_matrix_identity(a->xm); }

void vf3_aim_store(vf3_native_aim *a, uint32_t dst)
{
    memcpy(vf3_aim_p(a, dst), a->xm, sizeof a->xm);
}

void vf3_aim_load(vf3_native_aim *a, uint32_t src)
{
    memcpy(a->xm, vf3_aim_p(a, src), sizeof a->xm);
}

void vf3_aim_copy(vf3_native_aim *a, uint32_t dst, uint32_t src)
{
    memcpy(vf3_aim_p(a, dst), vf3_aim_p(a, src), 64u);
}

/* 0x8C03CC60: XMTRX translation = XMTRX * (FR4, FR5, FR6, 1) */
void vf3_aim_translate_by(vf3_native_aim *a)
{
    const float x = F(4), y = F(5), z = F(6);
    a->xm[12] = a->xm[0] * x + a->xm[4] * y + a->xm[8] * z + a->xm[12];
    a->xm[13] = a->xm[1] * x + a->xm[5] * y + a->xm[9] * z + a->xm[13];
    a->xm[14] = a->xm[2] * x + a->xm[6] * y + a->xm[10] * z + a->xm[14];
    a->xm[15] = a->xm[3] * x + a->xm[7] * y + a->xm[11] * z + a->xm[15];
}

/* 0x8C03CBD0: XMTRX translation = the three floats at r4 */
void vf3_aim_set_translation(vf3_native_aim *a, uint32_t src)
{
    const float *t = vf3_aim_p(a, src);
    a->xm[12] = t[0];
    a->xm[13] = t[1];
    a->xm[14] = t[2];
}

/* 0x8C09D4E6: store XMTRX but keep the object's own translation (+48) */
void vf3_aim_store_keep_translation(vf3_native_aim *a, uint32_t dst)
{
    float *object = vf3_aim_p(a, dst);
    float kept[3] = { object[12], object[13], object[14] };
    memcpy(object, a->xm, sizeof a->xm);
    object[12] = kept[0];
    object[13] = kept[1];
    object[14] = kept[2];
}

/* 0x8C03B820: store XMTRX's translation (XF12..XF14) at r4..r4+8 */
void vf3_aim_store_translation(vf3_native_aim *a, uint32_t dst)
{
    float *object = vf3_aim_p(a, dst);
    object[0] = a->xm[12];
    object[1] = a->xm[13];
    object[2] = a->xm[14];
}

static void aim_point(vf3_native_aim *a, const float p[3], uint32_t dst)
{
    float out[3];
    vf3_native_matrix_transform_point(a->xm, p, out);
    float *d = vf3_aim_p(a, dst);
    d[0] = out[0];
    d[1] = out[1];
    d[2] = out[2];
}

/* 0x8C03B450: (r4 -> x,y,z) * XMTRX -> r5 */
void vf3_aim_xform_point(vf3_native_aim *a, uint32_t src, uint32_t dst)
{
    aim_point(a, vf3_aim_p(a, src), dst);
}

/* 0x8C09D52E: the point (FR4, 0, 0) through XMTRX, stored at r4 */
void vf3_aim_xform_axis(vf3_native_aim *a, uint32_t dst)
{
    const float p[3] = { F(4), 0.0f, 0.0f };
    aim_point(a, p, dst);
}

/* 0x8C09D42C: the point (FR4, 0, FR5) through XMTRX, stored at r4 */
void vf3_aim_xform_vec(vf3_native_aim *a, uint32_t dst)
{
    const float p[3] = { F(4), 0.0f, F(5) };
    aim_point(a, p, dst);
}

/* 0x8C09D554: the point (0, FR4, FR5) through XMTRX, stored at r4 */
void vf3_aim_xform_vec2(vf3_native_aim *a, uint32_t dst)
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

void vf3_aim_rotate_z_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_z(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

void vf3_aim_rotate_y_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_y(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

void vf3_aim_rotate_x_angle(vf3_native_aim *a, uint16_t angle)
{
    const float radians = (float)((double)angle * aim_turn);
    float rotation[16], product[16];
    aim_rot_x(sinf(radians), cosf(radians), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

/* 0x8C03C970: rotation about Z from a ready sin (FR4) / cos (FR5) */
void vf3_aim_rotate_sc(vf3_native_aim *a)
{
    float rotation[16], product[16];
    aim_rot_z(F(4), F(5), rotation);
    vf3_native_matrix_multiply(a->xm, rotation, product);
    memcpy(a->xm, product, sizeof product);
}

/* 0x8C09D480: the three 16-bit angles at r4 (Z, Y, X) applied to XMTRX */
void vf3_aim_rotate_euler(vf3_native_aim *a, uint32_t angles)
{
    const uint8_t *src = (const uint8_t *)vf3_aim_p(a, angles);
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
void vf3_aim_invert_rigid(const float m[16], float out[16])
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
int vf3_aim_unit_triple(vf3_native_aim *a, uint32_t triple)
{
    float inverted[16], p[3];
    vf3_aim_invert_rigid(a->xm, inverted);
    vf3_native_matrix_transform_point(inverted, vf3_aim_p(a, triple), p);
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
void vf3_aim_fma_row(vf3_native_aim *a, uint32_t src)
{
    for (uint32_t k = 0; k < 12; k += 4)
        MW(a, 0x40u + k, fmaf(F(0), MR(a, src + k), MR(a, 0x40u + k)));
}

/* the aim_frame_b builder's fma_row: frame[dst + k] += FR0 * frame[src + k] */
void vf3_aim_fma_row_at(vf3_native_aim *a, uint32_t dst, uint32_t src)
{
    for (uint32_t k = 0; k < 12; k += 4)
        MW(a, dst + k, fmaf(F(0), MR(a, src + k), MR(a, dst + k)));
}

uint16_t vf3_aim_h16(vf3_native_aim *a, uint32_t addr)
{
    uint16_t v;
    memcpy(&v, (const uint8_t *)vf3_aim_p(a, addr), 2);
    return v;
}

uint8_t vf3_aim_u8(vf3_native_aim *a, uint32_t addr)
{
    return *(const uint8_t *)vf3_aim_p(a, addr);
}

void vf3_aim_set_u16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)vf3_aim_p(a, addr);
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
}

void vf3_aim_set_u32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)vf3_aim_p(a, addr);
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16);
    p[3] = (uint8_t)(v >> 24);
}

uint32_t vf3_aim_u32(vf3_native_aim *a, uint32_t addr)
{
    uint32_t v;
    memcpy(&v, vf3_aim_p(a, addr), 4);
    return v;
}

/* 0x8C09DA1E: the three-angle wrapper the second builder calls. */
void vf3_aim_three_angles(vf3_native_aim *a, uint32_t angles, uint32_t base)
{
    const uint32_t frame = a->r[15] - 24u;
    float *parked = vf3_aim_p(a, frame + 4u);
    const float kept[3] = { a->xm[12], a->xm[13], a->xm[14] };

    parked[0] = kept[0];
    parked[1] = kept[1];
    parked[2] = kept[2];

    vf3_aim_identity(a);
    vf3_aim_rotate_y_angle(a, vf3_aim_h16(a, base + 30u));
    vf3_aim_rotate_z_angle(a, vf3_aim_h16(a, angles));
    vf3_aim_rotate_y_angle(a, vf3_aim_h16(a, angles + 2u));
    vf3_aim_rotate_x_angle(a, (uint16_t)(vf3_aim_h16(a, base + 0x22E6u) +
                                         vf3_aim_h16(a, angles + 4u)));
    a->xm[12] = parked[0];
    a->xm[13] = parked[1];
    a->xm[14] = parked[2];
}
