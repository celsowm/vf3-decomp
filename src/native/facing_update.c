/* Native port of 0x8C09DCDC (facing_update): turn a character's heading and
 * pitch toward a target point (r5) and refresh its orientation matrix.
 *
 *   r4 -> the character (flags at +0, kind bytes at +4/+0x61, kind halfword
 *   at +0x3C, position at +0x1FC8..0x1FD0, heading at +0x1FD4, pitch at
 *   +0x1FD8, the anchor at +0x1F14..0x1F1C, the blend weight at +0xC0),
 *   r5 -> the target point.
 *
 * Phase 1 parks the anchor and, unless the 0x400 (cleared) or 0x100 flag is
 * set, moves the position at +0x1FC8: when the mask 0x88836020 hits +0x48
 * the offset at +0x2308 is added to its y, otherwise it becomes
 * 0.25 * fmac(3.0, part, position).  Phase 2 blends the offset vector,
 * turns the direction into a heading by the atan table, clamps and adds it,
 * derives the pitch, then rotates_by heading/pitch and commits the matrix to
 * +0x1C0.
 *
 * All matrix helpers come from aim_math; the atan lookup is inlined natively
 * (table 0x0C0EAF60, scale 15000).  See the readable port
 * src/fight/facing_update.c. */
#include "pose_callees.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define KIND_CELL   0x0C29BB84u
#define MASK_FLAGS  0x88836020u
#define FLAG_400    0x400u
#define FLAG_100    0x100u
#define HEADING     0x1FD4u
#define PITCH       0x1FD8u
#define TURN_TABLE  0x0C10DAD0u
#define CONST_A     0x0C09DEC4u
#define CONST_B     0x0C09DEC8u
#define EPSILON     0x0C09DF90u
#define ATAN_TABLE  0x0C0EAF60u
#define SAVED       220u

static uint32_t sext8(uint32_t v)  { return (uint32_t)(int32_t)(int8_t)v; }
static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

static uint32_t clamp_s(uint32_t v, int32_t lo, int32_t hi)
{
    int32_t x = (int32_t)v;
    if (x > hi) x = hi;
    if (x < lo) x = lo;
    return (uint32_t)x;
}

static float rd(vf3_native_aim *a, uint32_t addr) { return ((float *)vf3_aim_p(a, addr))[0]; }

static void wf(vf3_native_aim *a, uint32_t addr, float v)
{
    uint32_t u;
    memcpy(&u, &v, 4);
    vf3_aim_set_u32(a, addr, u);
}

/* 0x8C069624: angle of the vector (x, y) as a 16-bit binary angle, from the
 * table at 0x0C0EAF60 scaled by 15000.  Returns the signed angle. */
static int32_t atan_lookup(vf3_native_aim *a, float x, float y)
{
    if (x == 0.0f && y == 0.0f)
        return 0;
    const float ay = fabsf(y), ax = fabsf(x);
    float scale = (ay > ax) ? (ax / ay) : (ay / ax);
    scale *= 15000.0f;
    int32_t t = (int32_t)scale;
    int32_t a2 = (int16_t)vf3_aim_h16(a, ATAN_TABLE + ((uint32_t)t << 1));
    if (ax > ay)
        a2 = 0x4000 - a2;
    if (y < 0.0f) {
        if (x < 0.0f)
            a2 += (int16_t)0x8000;
        else
            a2 = 0x8000 - a2;
    } else if (x < 0.0f) {
        a2 = -a2;
    }
    return a2;
}

void vf3_native_facing_update(vf3_native_aim *a, uint32_t sp, uint32_t obj,
                              uint32_t target)
{
    const uint32_t saved_r[6] = { a->r[14], a->r[13], a->r[12], a->r[11], a->r[10], a->fr[15] };
    const float saved_f15 = a->fr[15];
    const uint32_t f = sp - SAVED;
    uint32_t r13 = a->r[13];            /* the guest's r13, conditionally set */
    uint32_t r12;
    int special;
    uint32_t r11;

    vf3_aim_set_u32(a, sp - 4u, saved_r[0]);
    vf3_aim_set_u32(a, sp - 8u, saved_r[1]);
    vf3_aim_set_u32(a, sp - 12u, saved_r[2]);
    vf3_aim_set_u32(a, sp - 16u, saved_r[3]);
    vf3_aim_set_u32(a, sp - 20u, saved_r[4]);
    vf3_aim_set_u32(a, sp - 24u, saved_f15);
    vf3_aim_set_u32(a, sp - 28u, a->pr);
    a->r[15] = f;
    vf3_aim_set_u32(a, f, target);

    /* the kind cell */
    {
        uint32_t k = sext8(vf3_aim_u8(a, obj + 4u)) != 0 ? 16u : 20u;
        r11 = vf3_aim_u32(a, KIND_CELL + k);
    }

    /* reset the pass: push(0), identity, store, pop(1) */
    vf3_aim_push(a, 0);
    vf3_aim_identity(a);
    vf3_aim_store(a, f + 68u);
    vf3_aim_pop(a);

    /* phase 1: the mixed position */
    {
        uint32_t p84 = f + 0x84u;
        wf(a, p84, rd(a, obj + 0x1F14u));
        wf(a, p84 + 4u, rd(a, obj + 0x1F18u));
        wf(a, p84 + 8u, rd(a, obj + 0x1F1Cu));
        r12 = vf3_aim_u32(a, obj) & FLAG_400;
        if (r12 != 0) {
            vf3_aim_set_u32(a, obj, vf3_aim_u32(a, obj) & 0xFFFFFBFFu);
        } else if ((vf3_aim_u32(a, obj) & FLAG_100) == 0) {
            r13 = MASK_FLAGS & vf3_aim_u32(a, obj + 72u);
            if (r13 != 0) {
                const float v = rd(a, p84 + 4u) + rd(a, obj + 0x2308u);
                wf(a, p84 + 4u, v);
            } else {
                wf(a, f + 0x9Cu, rd(a, r11 + 0x1F0u));
                wf(a, f + 0xA0u, rd(a, r11 + 0x1F4u));
                wf(a, f + 0xA4u, rd(a, r11 + 0x1F8u));
                wf(a, f + 0x90u, rd(a, obj + 0x1FC8u));
                wf(a, f + 0x94u, rd(a, obj + 0x1FCCu));
                wf(a, f + 0x98u, rd(a, obj + 0x1FD0u));
                const float cb = rd(a, CONST_A);
                const float cx = rd(a, CONST_B);
                for (uint32_t i = 0; i < 12; i += 4) {
                    const float part = rd(a, f + 0x9Cu + i);
                    const float pos = rd(a, f + 0x90u + i);
                    wf(a, p84 + i, fmaf(cx, pos, part) * cb);
                }
            }
        }
        wf(a, obj + 0x1FC8u, rd(a, p84));
        wf(a, obj + 0x1FCCu, rd(a, p84 + 4u));
        wf(a, obj + 0x1FD0u, rd(a, p84 + 8u));
    }
    special = 0;                         /* set below, after the kind test */

    /* phase 2: the offset vector and the direction */
    a->fr[15] = rd(a, obj + 0xC0u);
    vf3_aim_store(a, f + 4u);            /* XMTRX at f+4..f+68 */
    {
        const float w = a->fr[15];
        a->fr[0] = w;
        for (int k = 0; k < 12; k += 4) {   /* f+116.. += w * f+52.. (fma) */
            const float old = rd(a, f + 52u + (uint32_t)k);
            const float axis = rd(a, f + 4u + (uint32_t)k);
            wf(a, f + 116u + (uint32_t)k, fmaf(w, axis, old));
        }
    }
    a->fr[6] = 0.0f;
    a->fr[4] = rd(a, target);
    a->fr[5] = 0.0f;
    vf3_aim_translate_by(a);
    vf3_aim_rotate_euler(a, obj + 0x1F5Cu);

    wf(a, f + 0xB4u, rd(a, obj + 0x1FC8u));
    wf(a, f + 0xB8u, rd(a, obj + 0x1FCCu));
    wf(a, f + 0xBCu, rd(a, obj + 0x1FD0u));
    /* pass_prep: push(0), invert_rigid, xform_point(f+0xB4 -> f+0xA8), pop */
    {
        float inv[16];
        vf3_aim_push(a, 0);
        vf3_aim_invert_rigid(a->xm, inv);
        memcpy(a->xm, inv, sizeof inv);
        vf3_aim_xform_point(a, f + 0xB4u, f + 0xA8u);
        vf3_aim_pop(a);
    }

    /* the heading delta */
    {
        const uint16_t kind = vf3_aim_h16(a, obj + 60u);
        special = (kind == 0x886u || kind == 0x88Du) ? 1 : 0;
        uint32_t r4 = sext16((uint32_t)atan_lookup(a, rd(a, f + 0xACu),
                                                  rd(a, f + 0xA8u)));
        if (!special) {
            if (r13 != 0) {
                if (vf3_aim_h16(a, obj + 60u) == 72 &&
                    ((int32_t)r4 < 0 || (int32_t)r4 > 0x8000))
                    r4 = 0x4000;
            }
            r4 = sext16(r4 + 0xC000u);
            {
                uint32_t lim = vf3_aim_u8(a, obj + 97u) == 12 ? 0x2800u : 0x3800u;
                if ((int32_t)r4 > (int32_t)lim) r4 = lim;
                uint32_t nlim = 0u - lim;
                if (!((int32_t)r4 >= (int32_t)nlim)) r4 = nlim;
            }
            r4 -= 0xC000u;
        }
        r4 = sext16(r4 - vf3_aim_u32(a, obj + HEADING));
        if (r12 == 0 && r13 == 0)
            r4 = clamp_s(r4, -0x300, 0x300);
        r4 += vf3_aim_u32(a, obj + HEADING);
        vf3_aim_set_u32(a, obj + HEADING, r4);
    }

    /* the pitch delta */
    {
        const float dxz = rd(a, f + 0xA8u);
        const float dyz = rd(a, f + 0xACu);
        float len2 = fmaf(dxz, dxz, dyz * dyz);
        if (rd(a, EPSILON) > len2)
            len2 = 0.0f;
        else
            len2 = sqrtf(len2);
        uint32_t r4 = sext16((uint32_t)atan_lookup(a, rd(a, f + 0xB0u), len2));
        uint32_t r5 = 0u - r4;
        if (r12 == 0 && r13 == 0) {
            uint32_t idx = sext8(vf3_aim_u8(a, obj + 97u)) & 0xffu;
            r5 += sext16(vf3_aim_h16(a, TURN_TABLE + (idx << 1))) & 0xffffu;
        }
        r4 = vf3_aim_u32(a, obj + PITCH);
        r5 -= r4;
        if (r12 == 0 && r13 == 0)
            r5 = clamp_s(r5, -0x100, 0x100);
        r4 += r5;
        if (!special) {
            uint32_t lim = vf3_aim_u8(a, obj + 97u) == 12 ? 0x800u : 0x1000u;
            if ((int32_t)r4 > (int32_t)lim) r4 = lim;
            if (!((int32_t)r4 >= (int32_t)(int16_t)0xE000u)) r4 = (uint32_t)(int16_t)0xE000u;
        }
        vf3_aim_set_u32(a, obj + PITCH, r4);
    }

    /* commit the matrix */
    vf3_aim_rotate_z_angle(a, (uint16_t)vf3_aim_u32(a, obj + HEADING));
    vf3_aim_rotate_y_angle(a, (uint16_t)vf3_aim_u32(a, obj + PITCH));
    vf3_aim_store_keep_translation(a, f + 68u);
    vf3_aim_copy(a, obj + 0x1C0u, f + 68u);

    a->r[15] = sp;
    /* the saved registers and pr are restored, as the guest does */
}







