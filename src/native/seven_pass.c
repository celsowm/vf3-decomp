/* seven_pass.c - 0x8C09DA72 (seven_pass): the seven-segment pass for one
 * object.  Native port on the `vf3_native_aim` context, mirroring the readable
 * port src/fight/seven_pass.c and the generated matrix_adapters.c body.
 *
 *   r4 -> object.  The pass builds a vector at frame +0 (zero, or the object's
 *   vector at +0x1D04 when flag 0x20000000 of its first word is set) and a
 *   second one at frame +36 from the object's +16/+20/+24.  Unless the
 *   object's flags (+72) have 0x29000, its mode byte (+97) lowers the second
 *   vector's y by a fixed amount (6 -> 0.0300, 8 -> 0.0600, 11 -> 0.0550,
 *   12 -> 0.0200).
 *
 *   Then push(0), identity, translate_by(the second vector) and rotate_y(the
 *   sign-extended halfword at +30) set up XMTRX, and seven segments run:
 *   0x8C03CEE0 subtracts frame vec0 from each SEG_A (+0x1D04) record into
 *   frame +24, (optionally) zeroes frame +28, and 0x8C03B450 pushes frame +24
 *   through XMTRX into each SEG_B (+0x1EFC) record.  It ends with pop(1), so
 *   XMTRX is restored and the net observable write is the SEG_A/SEG_B record
 *   region plus the call frame on the stack.
 *
 *   Frame (48 bytes under nine saved words): +0 vector, +24 scratch, +28
 *   zeroed float, +36 second vector.
 *
 *   The three matrix sub-ops were reversed out of the generated bodies in
 *   matrix_adapters.c: 0x8C03C4F0(0) = matrix_push, 0x8C03CCB0 = identity,
 *   0x8C03CC90 = load 3 floats + translate_by (tail call via the pool address
 *   0x0C03CCA4 -> 0x8C03CC60; the image confirms it), 0x8C03C880 = rotate_y,
 *   0x8C03CEE0 = 3-vec subtract, 0x8C03B450 = xform point, 0x8C03C4A0(1) =
 *   matrix_pop. */
#include "pose_callees.h"
#include "aim_math.h"

#include <stdint.h>
#include <string.h>

#define SAVED 36u
#define FRAME 48u
#define SEG_A 0x1D04u
#define SEG_B 0x1EFCu
#define VEC   0x1D04u
#define SEGMENTS   7u
#define SEG_STRIDE 12u
#define STAGE_WORD 0x0C29BCCCu

enum {
    FLAGS = 72u, MODE = 97u,
    FLAG_STAGE = 0x20000000u, FLAGS_SKIP = 0x29000u,
};

/* the drop amounts for modes 6, 8, 11, 12 (as the guest's float bits) */
static const uint32_t DROP_BITS[4] = {
    0x3CF5C28Fu, 0x3D75C28Fu, 0x3D6147AEu, 0x3CA3D70Au
};

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

void vf3_native_seven_pass(vf3_native_aim *a, uint32_t sp0, uint32_t obj)
{
    /* capture the caller's saved registers / fr15 / pr before they are
     * overwritten: the guest writes these to the stack as its call frame */
    static const uint8_t pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
    uint32_t saved_r[7];
    for (int i = 0; i < 7; ++i) saved_r[i] = a->r[pushed[i]];
    const uint32_t saved_f15 = vf3_aim_ubits(a->fr[15]);
    const uint32_t pr0 = a->pr;

    for (int i = 0; i < 7; ++i)
        vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    vf3_aim_set_u32(a, sp0 - 32u, saved_f15);
    vf3_aim_set_u32(a, sp0 - 36u, pr0);

    const uint32_t f = sp0 - SAVED - FRAME;
    a->r[15] = f;
    a->r[14] = obj;
    a->r[12] = obj + SEG_A;
    a->r[11] = obj + SEG_B;

    /* the second vector at frame +36, from the object's +16/+20/+24 */
    vf3_aim_set_u32(a, f + 36u, vf3_aim_u32(a, obj + 16u));
    vf3_aim_set_u32(a, f + 40u, vf3_aim_u32(a, obj + 20u));
    vf3_aim_set_u32(a, f + 44u, vf3_aim_u32(a, obj + 24u));

    /* the mode-dependent drop on the second vector's y */
    if (!(vf3_aim_u32(a, obj + FLAGS) & FLAGS_SKIP)) {
        static const int modes[4] = { 6, 8, 11, 12 };
        const uint32_t mode = (uint32_t)vf3_aim_u8(a, obj + MODE);
        for (int i = 0; i < 4; ++i) {
            if (mode != (uint32_t)modes[i]) continue;
            a->fr[3] = vf3_aim_fbits(DROP_BITS[i]);
            a->fr[2] = *vf3_aim_p(a, f + 40u);
            a->fr[2] = a->fr[2] - a->fr[3];      /* FSUB(2,3): fr2 -= fr3 */
            *vf3_aim_p(a, f + 40u) = a->fr[2];
            break;
        }
    }

    /* frame vec0: zero, or the object's VEC when FLAG_STAGE is set */
    a->fr[15] = 0.0f;
    if (vf3_aim_u32(a, obj) & FLAG_STAGE) {
        vf3_aim_set_u32(a, f + 0u, vf3_aim_u32(a, obj + VEC + 0u));
        vf3_aim_set_u32(a, f + 4u, vf3_aim_u32(a, obj + VEC + 4u));
        vf3_aim_set_u32(a, f + 8u, vf3_aim_u32(a, obj + VEC + 8u));
    } else {
        vf3_aim_set_u32(a, f + 0u, 0u);
        vf3_aim_set_u32(a, f + 4u, 0u);
        vf3_aim_set_u32(a, f + 8u, 0u);
    }

    /* 0x8C03C4F0(0): matrix_push(0) -- saves the entry XMTRX */
    a->r[4] = 0u;
    vf3_aim_push(a, 0);
    a->r[15] = f;

    /* 0x8C03CCB0: identity */
    vf3_aim_identity(a);
    a->r[15] = f;

    /* 0x8C03CC90(frame+36): load the three floats into FR4/5/6, translate_by */
    a->r[4] = f + 36u;
    a->fr[4] = *vf3_aim_p(a, f + 36u);
    a->fr[5] = *vf3_aim_p(a, f + 40u);
    a->fr[6] = *vf3_aim_p(a, f + 44u);
    vf3_aim_translate_by(a);
    a->r[15] = f;

    /* 0x8C03C880(sign-extended halfword at +30): rotate_y */
    a->r[4] = sext16(vf3_aim_h16(a, obj + 30u));
    vf3_aim_rotate_y_angle(a, (uint16_t)a->r[4]);
    a->r[15] = f;

    /* the seven segments: CEE0 subtract (SEG_A - vec0) into frame+24,
     * optional zero of frame+28, then xform frame+24 through XMTRX to SEG_B */
    a->r[10] = 0x21000u; a->r[13] = SEGMENTS; a->r[9] = 0x800u; a->r[8] = 0x8000u;
    for (;;) {
        a->r[4] = f + 24u; a->r[6] = f; a->r[5] = a->r[12];
        for (int i = 0; i < 3; ++i)
            *vf3_aim_p(a, f + 24u + 4u * (uint32_t)i) =
                *vf3_aim_p(a, a->r[5] + 4u * (uint32_t)i) -
                *vf3_aim_p(a, f + 4u * (uint32_t)i);
        a->r[15] = f;
        a->r[12] += SEG_STRIDE;

        const uint32_t stage = vf3_aim_u32(a, STAGE_WORD);
        if ((stage & 0x800u) && !(vf3_aim_u32(a, obj) & 0x8000u) &&
            (vf3_aim_u32(a, obj) & 0x40000u) &&
            (vf3_aim_u32(a, obj + FLAGS) & 0x21000u))
            vf3_aim_set_u32(a, f + 28u, vf3_aim_ubits(a->fr[15]));

        a->r[4] = f + 24u; a->r[5] = a->r[11];
        vf3_aim_xform_point(a, f + 24u, a->r[11]);
        a->r[15] = f;

        a->r[13] -= 1;
        a->r[11] += SEG_STRIDE;
        if (a->r[13] == 0u) break;
    }

    /* 0x8C03C4A0(1): matrix_pop(1) -- restores the entry XMTRX */
    a->r[4] = 1u;
    vf3_aim_pop(a);

    /* restore the caller's registers / fr15 / pr / r15 */
    for (int i = 0; i < 7; ++i)
        a->r[pushed[i]] = vf3_aim_u32(a, sp0 - 4u * (uint32_t)(i + 1));
    a->fr[15] = vf3_aim_fbits(vf3_aim_u32(a, sp0 - 32u));
    a->r[15] = sp0;
    a->pr = vf3_aim_u32(a, sp0 - 36u);
}
