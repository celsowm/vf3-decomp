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
#include "aim_math.h"
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


/* frame access: the frame lives at a->f */
static float MR(vf3_native_aim *a, uint32_t off) { return *vf3_aim_p(a, a->f + off); }
static void MW(vf3_native_aim *a, uint32_t off, float v) { *vf3_aim_p(a, a->f + off) = v; }
static uint32_t UR(vf3_native_aim *a, uint32_t off) { return vf3_aim_ubits(MR(a, off)); }

/* absolute access (a pointer kept in a frame word) */
static float AR(vf3_native_aim *a, uint32_t addr) { return *vf3_aim_p(a, addr); }
static void AW(vf3_native_aim *a, uint32_t addr, float v) { *vf3_aim_p(a, addr) = v; }

#define R(n)  (a->r[n])
#define F(n)  (a->fr[n])

/* ---- 0x8C09E060 ---- */


int vf3_native_aim_frame(vf3_native_aim *a, const float *record_a,
                         float *block_b, const float *object,
                         const float *object7, float fr4)
{
    if (!a || !record_a || !block_b || !object || !object7)
        return -1;
    const uint32_t f = a->f;
    const uint32_t sp0 = f + 340u;
    const uint32_t rec = vf3_aim_adr(a, record_a);
    const uint32_t block = vf3_aim_adr(a, block_b);
    const uint32_t obj = vf3_aim_adr(a, object);
    const uint32_t obj7 = vf3_aim_adr(a, object7);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const float saved_f[3] = { F(15), F(14), F(13) };
    for (int i = 0; i < 7; ++i)
        *vf3_aim_p(a, sp0 - 4u * (uint32_t)(i + 1)) = vf3_aim_fbits(saved_r[i]);
    for (int i = 0; i < 3; ++i)
        *vf3_aim_p(a, sp0 - 28u - 4u * (uint32_t)(i + 1)) = saved_f[i];
    *vf3_aim_p(a, sp0 - 44u) = vf3_aim_fbits(a->pr);
    R(15) = f;

    R(13) = rec;
    R(11) = block;
    MW(a, 0, vf3_aim_fbits(obj));
    MW(a, 4, vf3_aim_fbits(obj7));
    R(10) = UR(a, 0x160u);
    F(4) = fr4;

    vf3_aim_push(a, 0);
    vf3_aim_identity(a);
    vf3_aim_store(a, f + 0x90u);
    vf3_aim_store(a, f + 80u);
    vf3_aim_pop(a);

    F(4) = record_a[0];
    F(5) = vf3_aim_fbits(vf3_aim_ubits(record_a[2]) ^ AIM_NEGATE);
    vf3_aim_xform_vec(a, f + 0x11Cu);
    vf3_aim_store(a, f + 0xD0u);

    MW(a, 0x100, MR(a, 0x11C));
    MW(a, 0x104, MR(a, 0x120));
    MW(a, 0x108, MR(a, 0x124));

    F(6) = object[1];
    F(15) = 0.0f;
    F(5) = F(15);
    F(4) = object[0];
    vf3_aim_translate_by(a);
    vf3_aim_rotate_euler(a, UR(a, 0x158u));
    vf3_aim_store_keep_translation(a, f + 0xD0u);
    vf3_aim_copy(a, block, f + 0xD0u);
    vf3_aim_store_keep_translation(a, f + 0x90u);

    MW(a, 0xC0, MR(a, 0x100));
    MW(a, 0xC4, MR(a, 0x104));
    MW(a, 0xC8, MR(a, 0x108));
    vf3_aim_store(a, f + 16u);
    vf3_aim_push(a, 0);
    vf3_aim_load(a, f + 0x90u);

    F(6) = vf3_aim_fbits(vf3_aim_ubits(record_a[5]) ^ AIM_NEGATE);
    F(5) = F(15);
    F(4) = record_a[3];
    vf3_aim_translate_by(a);
    vf3_aim_store(a, f + 0xD0u);
    vf3_aim_pop(a);

    F(4) = object[2];
    F(0) = F(4);
    vf3_aim_fma_row(a, 0x30u);
    vf3_aim_load(a, f + 16u);
    vf3_aim_rotate_euler(a, UR(a, 0x158u) + 6u);

    for (uint32_t k = 0; k < 12; k += 4) {
        F(2) = AR(a, obj7 + k);
        F(3) = AR(a, UR(a, 0x164u) + k);
        F(2) = F(2) + F(3);
        MW(a, 0x110u + k, F(2));
    }
    if (vf3_aim_unit_triple(a, f + 0x110u) != 0)
        return -2;
    vf3_aim_store_keep_translation(a, block + 0xC0u);

    F(6) = object[3];
    F(4) = object[4];
    F(5) = MR(a, 8);
    F(7) = F(4) + F(6);
    F(14) = F(15);
    if (F(5) >= F(7)) {
        vf3_aim_store_keep_translation(a, f + 80u);
        vf3_aim_store_keep_translation(a, UR(a, 0x154u));
    } else {
        F(10) = F(5) * F(5);
        F(9) = F(6) * F(6);
        F(8) = F(4) * F(4);
        F(2) = F(4);
        F(4) = F(4) * F(6);
        F(3) = F(10) - F(9);
        F(7) = vf3_aim_fbits(AIM_LIT_TWO);
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
        F(4) = vf3_aim_fbits(AIM_LIT_ONE);
        F(6) = vf3_aim_fbits(AIM_LIT_MINUS_ONE);
        if (F(14) > F(4))
            F(14) = F(4);
        else if (F(6) > F(14))
            F(14) = F(6);
        if (F(5) > F(4))
            F(5) = F(4);
        else if (F(6) > F(5))
            F(5) = F(6);
        F(3) = F(5) * F(5);
        F(13) = vf3_aim_fbits(AIM_LIT);
        F(4) = F(4) - F(3);
        if (F(13) > F(4))
            F(4) = 0.0f;
        else
            F(4) = sqrtf(F(4));
        vf3_aim_rotate_sc(a);
        vf3_aim_store_keep_translation(a, f + 80u);

        F(5) = vf3_aim_fbits(AIM_LIT_HALF);
        F(6) = F(14) * F(5);
        F(4) = F(6) + F(5);
        if (F(13) > F(4))
            F(3) = 0.0f;
        else {
            F(3) = F(4);
            F(3) = sqrtf(F(3));
        }
        F(4) = F(5) - F(6);
        F(14) = vf3_aim_fbits(vf3_aim_ubits(F(3)) ^ AIM_NEGATE);
        if (F(13) > F(4))
            F(13) = 0.0f;
        else {
            F(13) = F(4);
            F(13) = sqrtf(F(13));
        }
        F(5) = F(13);
        F(4) = F(14);
        vf3_aim_rotate_sc(a);
        vf3_aim_store_keep_translation(a, UR(a, 0x154u));
        F(5) = F(13);
        F(4) = F(14);
        vf3_aim_rotate_sc(a);
    }

    MW(a, 0, vf3_aim_fbits(block + 64u));
    vf3_aim_store_keep_translation(a, f + 0xD0u);
    vf3_aim_push(a, 0);
    vf3_aim_load(a, f + 0xD0u);
    vf3_aim_store_translation(a, f + 0x11Cu);
    vf3_aim_store(a, UR(a, 0));
    vf3_aim_pop(a);
    vf3_aim_set_translation(a, f + 0x11Cu);
    vf3_aim_store_translation(a, R(10));
    F(4) = AR(a, UR(a, 0x15Cu));
    vf3_aim_xform_axis(a, R(10) + 12u);
    vf3_aim_store(a, f + 16u);

    F(4) = record_a[6];
    F(0) = F(4);
    vf3_aim_fma_row(a, 0x10u);

    AW(a, UR(a, 0x154u) + 48u, F(14));
    MW(a, 0, vf3_aim_fbits(block + 0x80u));
    vf3_aim_load(a, f + 16u);
    vf3_aim_store_translation(a, f + 0x80u);
    vf3_aim_push(a, 0);
    vf3_aim_load(a, f + 80u);
    vf3_aim_store(a, f + 16u);
    vf3_aim_store(a, UR(a, 0));
    vf3_aim_pop(a);
    vf3_aim_load(a, f + 16u);
    vf3_aim_store_translation(a, R(10) + 24u);
    F(4) = AR(a, UR(a, 0x15Cu) + 4u);
    vf3_aim_xform_axis(a, R(10) + 36u);
    F(4) = record_a[9];
    F(6) = F(15);
    F(5) = F(15);
    vf3_aim_translate_by(a);
    vf3_aim_rotate_euler(a, UR(a, 0x158u) + 12u);
    vf3_aim_store(a, block + 0xC0u);
    F(4) = AR(a, UR(a, 0x15Cu) + 8u);
    vf3_aim_xform_axis(a, R(10) + 48u);

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
    const uint32_t rec = vf3_aim_adr(a, record_a);
    const uint32_t obj6 = vf3_aim_adr(a, object);
    const uint32_t obj7 = vf3_aim_adr(a, object7);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const float saved_f[3] = { F(15), F(14), F(13) };
    for (int i = 0; i < 7; ++i)
        *vf3_aim_p(a, sp0 - 4u * (uint32_t)(i + 1)) = vf3_aim_fbits(saved_r[i]);
    for (int i = 0; i < 3; ++i)
        *vf3_aim_p(a, sp0 - 28u - 4u * (uint32_t)(i + 1)) = saved_f[i];
    *vf3_aim_p(a, sp0 - 44u) = vf3_aim_fbits(a->pr);
    R(15) = f;

    R(10) = rec;
    MW(a, 20, vf3_aim_fbits(vf3_aim_adr(a, owner)));   /* the pointer the caller passed */
    MW(a, 4, vf3_aim_fbits(obj6));
    MW(a, 0, vf3_aim_fbits(obj7));
    R(11) = UR(a, 0x160u);
    R(12) = UR(a, 0x168u);
    R(14) = UR(a, 0x16Cu);
    MW(a, 16, fr4);

    vf3_aim_push(a, 0);
    vf3_aim_identity(a);
    vf3_aim_store(a, f + 0xF0u);
    vf3_aim_store(a, f + 0xB0u);
    vf3_aim_store(a, f + 112u);
    vf3_aim_pop(a);
    vf3_aim_push(a, 0);

    F(6) = vf3_aim_fbits(vf3_aim_ubits(record_a[2]) ^ AIM_NEGATE);
    F(15) = 0.0f;
    F(5) = F(15);
    F(4) = record_a[0];
    vf3_aim_translate_by(a);
    vf3_aim_store(a, f + 0xF0u);
    vf3_aim_pop(a);
    vf3_aim_push(a, 0);

    F(6) = object7[1];
    F(5) = F(15);
    F(4) = object7[0];
    vf3_aim_translate_by(a);
    vf3_aim_rotate_euler(a, UR(a, 0x164u));

    MW(a, 88, AR(a, UR(a, 0x15Cu)));
    F(4) = MR(a, 16) + AR(a, UR(a, 0x15Cu) + 4u);
    MW(a, 92, F(4));
    MW(a, 96, AR(a, UR(a, 0x15Cu) + 8u));
    if (vf3_aim_unit_triple(a, f + 88u) != 0)
        return -2;

    F(6) = object7[2];
    F(4) = object7[3];
    F(7) = F(4) + F(6);
    F(5) = MR(a, 8);
    F(14) = F(15);
    if (F(5) >= F(7)) {
        vf3_aim_store_keep_translation(a, f + 0xB0u);
        vf3_aim_store_keep_translation(a, R(11));
    } else {
        F(10) = F(5) * F(5);
        F(8) = F(6) * F(6);
        F(7) = F(4) * F(4);
        F(2) = F(4) * F(5);
        F(3) = F(10) - F(8);
        F(9) = vf3_aim_fbits(AIM_LIT_TWO);
        F(6) = F(6) * F(4);
        F(4) = vf3_aim_fbits(AIM_LIT_ONE);
        F(2) = F(2) * F(9);
        F(3) = F(3) + F(7);
        F(7) = F(7) + F(8);
        F(6) = F(6) * F(9);
        F(5) = F(3) / F(2);
        F(7) = F(7) - F(10);
        F(14) = F(7) / F(6);
        F(6) = vf3_aim_fbits(AIM_LIT_MINUS_ONE);
        if (F(5) > F(4))
            F(5) = F(4);
        else if (F(6) > F(5))
            F(5) = F(6);
        if (F(14) > F(4))
            F(14) = F(4);
        else if (F(6) > F(14))
            F(14) = F(6);
        F(3) = F(5) * F(5);
        F(13) = vf3_aim_fbits(AIM_LIT);
        F(4) = F(4) - F(3);
        if (F(13) > F(4))
            F(3) = 0.0f;
        else
            F(3) = sqrtf(F(4));
        F(4) = vf3_aim_fbits(vf3_aim_ubits(F(3)) ^ AIM_NEGATE);
        vf3_aim_rotate_sc(a);
        vf3_aim_store_keep_translation(a, f + 0xB0u);

        F(4) = vf3_aim_fbits(AIM_LIT_HALF);
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
        vf3_aim_rotate_sc(a);
        vf3_aim_store_keep_translation(a, R(11));
        F(5) = F(13);
        F(4) = F(14);
        vf3_aim_rotate_sc(a);
    }

    vf3_aim_store_keep_translation(a, f + 0xF0u);
    vf3_aim_push(a, 0);
    vf3_aim_load(a, f + 0xF0u);
    vf3_aim_store_translation(a, f + 100u);
    vf3_aim_store(a, UR(a, 4));
    vf3_aim_pop(a);
    vf3_aim_set_translation(a, f + 100u);
    vf3_aim_store_translation(a, R(14));
    vf3_aim_store(a, f + 24u);
    R(4) = R(14) + 12;
    F(4) = AR(a, R(12));
    vf3_aim_xform_axis(a, R(14) + 12u);

    F(4) = record_a[3];
    F(0) = F(4);
    vf3_aim_fma_row_at(a, 72u, 24u);
    {
        const uint32_t r11 = R(11);
        for (uint32_t k = 0; k < 12; k += 4)
            *vf3_aim_p(a, r11 + 48u + k) = MR(a, 72u + k);
    }

    R(3) = UR(a, 4) + 64u;
    MW(a, 0, vf3_aim_fbits(R(3)));
    MW(a, 0xE0, MR(a, 72));
    MW(a, 0xE4, MR(a, 76));
    MW(a, 0xE8, MR(a, 80));
    vf3_aim_load(a, f + 0xB0u);
    vf3_aim_store(a, UR(a, 0));

    {
        const uint32_t r14 = R(14);
        for (uint32_t k = 0; k < 12; k += 4)
            *vf3_aim_p(a, r14 + 24u + k) = MR(a, 72u + k);
    }
    R(4) = R(14) + 36;
    F(4) = AR(a, R(12) + 4u);
    vf3_aim_xform_axis(a, R(14) + 36u);
    R(4) = R(14) + 48;
    F(4) = AR(a, R(12) + 8u);
    vf3_aim_xform_axis(a, R(14) + 48u);
    F(4) = record_a[6];
    F(6) = F(15);
    F(5) = F(15);
    vf3_aim_translate_by(a);

    R(5) = UR(a, 20);
    R(4) = UR(a, 0x164u) + 6u;
    vf3_aim_three_angles(a, UR(a, 0x164u) + 6u, UR(a, 20));
    vf3_aim_store(a, f + 112u);
    vf3_aim_copy(a, UR(a, 4) + 0x80u, f + 112u);

    MW(a, 92, vf3_aim_fbits(AIM_LIT_TENTH));
    F(3) = MR(a, 92);
    F(4) = F(3);
    F(3) = F(3) + F(4);
    MW(a, 96, F(3));
    F(4) = MR(a, 92);
    F(3) = F(4) - F(4);
    MW(a, 88, F(3));
    vf3_aim_xform_point(a, f + 88u, UR(a, 0x170u));

    R(4) = R(14) + 60;
    F(4) = AR(a, R(12) + 12u);
    vf3_aim_xform_vec2(a, R(14) + 60u);
    MW(a, 100, F(15));
    MW(a, 104, AR(a, R(12) + 16u));
    MW(a, 108, AR(a, R(12) + 20u));
    vf3_aim_xform_point(a, f + 100u, R(14) + 72u);
    vf3_aim_pop(a);

    for (int i = 0; i < 7; ++i) R(14 - i) = saved_r[i];
    for (int i = 0; i < 3; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    return 0;
}
