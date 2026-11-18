/* pose_orchestration.c - SH-4 0x8C09EAF2: the pose orchestration, natively.
 *
 * This is the top of the aim/pose family: a plain-C transcription of the
 * readable port src/fight/readable/pose_orchestration.c that chains every
 * native callee (seven_pass, root_orientation, halfword_frame, facing_update,
 * aim_frame, aim_frame_b, aim_midpoints, matrix_basis) and the shared
 * aim_math matrix helpers on one actor, so a fully posed fighter comes out
 * of native code alone.
 *
 * Layout (all constants of the image, confirmed against 1ST_READ.unsc.bin):
 *   frame = sp0 - 228; XMTRX snapshot at +0xA4/+0x64/+0x24,
 *   the kind record r13 = 0x0C10D3C4 + u8(obj+97) * 108,
 *   the kind==12 code pointer r11 = 0x0C10DABC + 8 (kind 12) else
 *   + u8(obj+0x420B) * 4.
 *
 * The persistent guest registers r11(r13 code) / r12(arg) / r13(kind) / r14
 * (obj) and the helper pointers r8/r9/r10 live in a->r[], set at the same
 * points the guest sets them, so the frame-saving callees write and restore
 * the identical saved-register words.  r0..r7 and r15 are locals; macl rides
 * in the stack slot sp0-8 the caller seeded.  See docs/re/native_pose_orchestration.md. */
#include "pose_orchestration.h"
#include "pose_callees.h"
#include "aim_math.h"
#include "matrix.h"

#include <math.h>
#include <string.h>

/* ---- literal-pool 16-bit offsets of the image (verified) ---- */
#define FRAME_OFF   (-228)          /* 0xFF1C */
#define OFF_A4      0xA4u
#define VEC_OFF     0x1EFCu
#define XF_OFF1     0x94u
#define XF_OFF2     0xD4u
#define ACTOR_OFF   0x22E4u
#define F_OFF1      0x1F56u
#define SUM1 0x208Cu
#define SUM2 0x1F08u
#define SUM3 0x2090u
#define SUM4 0x1F0Cu
#define SUM5 0x2094u
#define SUM6 0x1F10u
#define COPY_OFF    0x180u
#define KIND12_OFF  0x420Bu
#define EXIT_OFF    0x13Cu
#define B1 0x2098u
#define B2 0x1F62u
#define B3 0x1F20u
#define B4 0x640u
#define B5 0x200u
#define B6 0xCCu
#define C1 0x20A4u
#define C2 0x1F74u
#define C3 0x1F2Cu
#define C4 0x680u
#define C5 0x300u
#define C6 0xFCu
#define XPT1 0x9Cu
#define XPT2 0x8Cu
#define D1 0x1F8Cu
#define D2 0x138u
#define D3 0x22E8u
#define D4 0x6C0u
#define D5 0x1F38u
#define D6 0x22ECu
#define D7 0xA8u
#define D8 0x20B4u
#define D9 0x480u
#define E1 0x15Cu
#define E2 0x1F44u
#define E3 0x740u
#define E4 0x1F98u
#define E5 0x22EAu
#define E6 0x22F8u
#define E7 0x20C0u
#define E8 0x540u

/* the two tables behind the pools */
#define KIND_TABLE  0x0C10D3C4u
#define KIND_TAB2   0x0C10DABCu

/* the matrix-helper function addresses the guest keeps in r8/r9/r10 (the
 * readable reads them from the literal pool, so they are the 0x0c form) */
#define HELPER_XFORM 0x0C03B450u
#define HELPER_PUSH  0x0C03C4F0u
#define HELPER_POP   0x0C03C4A0u

#define SIGN 0x80000000u

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static uint32_t ld32(vf3_native_aim *a, uint32_t addr) { return vf3_aim_u32(a, addr); }
static float ldf(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void stf(vf3_native_aim *a, uint32_t addr, float v) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(v)); }
static void pushw(vf3_native_aim *a, uint32_t *sp, uint32_t v)
{
    *sp -= 4u;
    vf3_aim_set_u32(a, *sp, v);
}

void vf3_native_pose_orchestration(vf3_native_aim *a, uint32_t sp0,
                                   uint32_t obj, uint32_t arg)
{
    const uint32_t f = /* frame */ ((sp0 - 4u) - 4u) + (uint32_t)(int32_t)FRAME_OFF;

    /* prologue: save pr and macl, open the 228-byte frame */
    vf3_aim_set_u32(a, sp0 - 4u, a->pr);
    const uint32_t macl = ld32(a, sp0 - 8u);   /* the caller's saved macl */
    vf3_aim_set_u32(a, sp0 - 8u, macl);
    uint32_t sp = f;
    R(12) = arg;
    R(14) = obj;
    R(15) = f;

    /* XMTRX = identity, then snapshot at f+0xA4 / +0x64 / +0x24 */
    vf3_aim_identity(a);
    vf3_aim_store(a, f + OFF_A4);
    vf3_aim_store(a, f + 0x64u);
    vf3_aim_store(a, f + 0x24u);

    /* the kind record: r13 = table + u8(obj+97) * 108 */
    R(13) = KIND_TABLE + (uint32_t)vf3_aim_u8(a, obj + 97u) * 108u;

    /* seven_pass */
    R(4) = obj; R(15) = f;
    vf3_native_seven_pass(a, f, obj);

    /* root_orientation: Ry(yaw) Rz(f0) Ry(f1) Rx(f2) into XMTRX */
    {
        const uint16_t fields[3] = {
            vf3_aim_h16(a, obj + 0x1F50u),
            vf3_aim_h16(a, obj + 0x1F52u),
            vf3_aim_h16(a, obj + 0x1F54u),
        };
        float root[16];
        vf3_native_root_orientation(vf3_aim_h16(a, obj + 30u), fields, root);
        memcpy(a->xm, root, sizeof root);
    }
    R(15) = f;

    /* matrix_set_translation with the pose-vectors base */
    vf3_aim_set_translation(a, obj + VEC_OFF);

    /* three store_translation copies of the XF translation into the frame */
    vf3_aim_store_translation(a, f + XF_OFF1);
    vf3_aim_store_translation(a, f + XF_OFF2);
    vf3_aim_store_translation(a, f + 0x54u);

    /* matrix_push(0) */
    R(9) = HELPER_PUSH;
    R(15) = f;
    vf3_aim_push(a, 0);

    /* halfword_frame: obj = actor+0x1F56, arg = h16(actor+0x22E4) sign-extended */
    R(15) = f;
    vf3_native_halfword_frame(a, f, obj + F_OFF1,
        (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, obj + ACTOR_OFF));

    /* three float sums into the frame at +24/+28/+32, then unit_triple on it */
    F(3) = ldf(a, obj + SUM1); F(2) = ldf(a, obj + SUM2);
    F(2) = F(2) + F(3); stf(a, f + 24u, F(2));
    F(3) = ldf(a, obj + SUM3); F(2) = ldf(a, obj + SUM4);
    F(2) = F(2) + F(3); stf(a, f + 28u, F(2));
    F(3) = ldf(a, obj + SUM5); F(2) = ldf(a, obj + SUM6);
    F(2) = F(2) + F(3); stf(a, f + 32u, F(2));

    /* 0x8C09DC34 (unit_triple) with r5 -> f+4, r6 -> f+8: XMTRX = composed,
     * f+4 = full length (or 0 below 1e-7), f+8 = 1/|abc| */
    {
        float inverted[16], p[3], composed[16], xz_length, inverse_length;
        uint32_t ok = 0;
        vf3_aim_invert_rigid(a->xm, inverted);
        vf3_native_matrix_transform_point(inverted, vf3_aim_p(a, f + 24u), p);
        if (vf3_native_matrix_unit_triple(a->xm, p, composed,
                                          &xz_length, &inverse_length) == 0)
            ok = 1;
        if (ok) {
            memcpy(a->xm, composed, sizeof composed);
            const float m = xz_length * xz_length + p[2] * p[2];
            stf(a, f + 4u, m < 1.0e-7f ? 0.0f : sqrtf(m));
            stf(a, f + 8u, inverse_length);
        }
    }
    R(15) = f;

    /* store_keep_translation(f+0xA4), then matrix_copy(obj+0x180, f+0xA4) */
    vf3_aim_store_keep_translation(a, f + OFF_A4);
    R(15) = f;
    vf3_aim_copy(a, obj + COPY_OFF, f + OFF_A4);

    /* the kind record floats into the frame, two xform_point calls */
    R(8) = HELPER_XFORM;
    R(15) = f;
    stf(a, f + 12u, ldf(a, R(13) + 0u));
    stf(a, f + 16u, ldf(a, R(13) + 8u));
    stf(a, f + 20u, ldf(a, R(13) + 4u));
    vf3_aim_xform_point(a, f + 12u, R(12) + 12u);
    F(3) = ldf(a, R(13) + 4u);
    F(3) = vf3_aim_fbits(vf3_aim_ubits(F(3)) ^ SIGN);
    stf(a, f + 20u, F(3));
    vf3_aim_xform_point(a, f + 12u, R(12));

    /* matrix_push(0); the kind==12 code-pointer branch; facing_update */
    R(15) = f;
    vf3_aim_push(a, 0);
    {
        const uint32_t tab2 = KIND_TAB2;
        const uint32_t kind = (uint32_t)vf3_aim_u8(a, obj + 97u);
        if (kind == 12u)
            R(11) = ld32(a, tab2 + 8u);
        else
            R(11) = ld32(a, tab2 + ((uint32_t)vf3_aim_u8(a, obj + KIND12_OFF)) * 4u);
    }
    R(15) = f;
    vf3_native_facing_update(a, f, obj, R(11));

    /* kind floats +12/+16/+20; xform_point to r12+24 */
    R(15) = f;
    stf(a, f + 12u, ldf(a, R(13) + 12u));
    stf(a, f + 16u, ldf(a, R(13) + 16u));
    stf(a, f + 20u, ldf(a, R(13) + 20u));
    vf3_aim_xform_point(a, f + 12u, R(12) + 24u);

    /* matrix_pop(1); matrix_push(0) */
    R(10) = HELPER_POP;
    R(15) = f;
    vf3_aim_pop(a);
    vf3_aim_push(a, 0);

    /* ---- aim_frame #1: output block at actor+0x200 ---- */
    pushw(a, &sp, obj + B1);          /* w0 */
    pushw(a, &sp, R(12) + 36u);       /* w1 */
    pushw(a, &sp, R(13) + 24u);       /* w2 */
    pushw(a, &sp, obj + B2);          /* w3 */
    pushw(a, &sp, obj + B4);          /* w4 */
    {
        a->f = sp - 340u;
        R(15) = sp;
        vf3_native_aim_frame(a, vf3_aim_p(a, obj + B6),
                             vf3_aim_p(a, obj + B5),
                             vf3_aim_p(a, R(11) + 4u),
                             vf3_aim_p(a, obj + B3), a->fr[4]);
    }
    R(15) = sp;
    vf3_aim_pop(a);

    /* ---- aim_frame #2: output block at actor+0x300 ---- */
    pushw(a, &sp, obj + C1);          /* w0 */
    pushw(a, &sp, R(12) + 96u);       /* w1 */
    pushw(a, &sp, R(13) + 36u);       /* w2 */
    pushw(a, &sp, obj + C2);          /* w3 */
    pushw(a, &sp, obj + C4);          /* w4 */
    {
        a->f = sp - 340u;
        R(15) = sp;
        vf3_native_aim_frame(a, vf3_aim_p(a, obj + C6),
                             vf3_aim_p(a, obj + C5),
                             vf3_aim_p(a, R(11) + 24u),
                             vf3_aim_p(a, obj + C3), a->fr[4]);
    }
    R(15) = sp;
    vf3_aim_pop(a);

    /* kind floats +48/+56 into the frame at +52/+56/+60.  The guest's R(15)
     * is still f-40 here (the five pushed aim_frame#2 arg words persist),
     * so R(15)+52/+56/+60 land at f+12/f+16/f+20.  xform_point src f+12. */
    R(15) = sp;                     /* f-40 */
    stf(a, sp + 52u, ldf(a, R(13) + 48u));
    stf(a, sp + 56u, ldf(a, R(13) + 52u));
    stf(a, sp + 60u, ldf(a, R(13) + 56u));
    vf3_aim_xform_point(a, sp + 52u, R(12) + XPT1);

    /* aim_midpoints and matrix_basis, still at sp = f-40 */
    R(15) = sp;
    vf3_native_aim_midpoints(a, sp, obj, sp + XPT2);
    R(15) = sp;
    vf3_native_matrix_basis(a, sp, obj, sp + 76u);

    /* matrix_push(0); aim_frame_b #1 (object at actor+0x480) */
    R(15) = f;
    vf3_aim_push(a, 0);
    {
        const uint32_t h = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, obj + D3);
        vf3_aim_set_u32(a, f, obj + D1);                 /* frame f+0 = obj+0x1F8C */
        vf3_aim_set_u16(a, obj + D3 - 2u, (uint16_t)h);  /* obj+0x22E6 */
    }
    /* By the time w3 is read, three push_words have run, so R(15) has moved
     * f-40 -> f-52 and mem[R15+52] = mem[f+0] - the obj+D1 pointer the guest
     * just parked at frame+0, not a kind float. */
    pushw(a, &sp, obj + D6);          /* w0  */
    pushw(a, &sp, R(12) + D7);        /* w1  */
    pushw(a, &sp, R(13) + 60u);       /* w2  */
    pushw(a, &sp, ld32(a, f));        /* w3 = mem[R15+52] = mem[f+0] = obj+D1 */
    pushw(a, &sp, obj + D4);          /* w4  */
    pushw(a, &sp, obj + D5);          /* w5  */
    F(4) = ldf(a, obj + D8);          /* fr4 = f(obj+0x20B4) */
    {
        a->f = sp - 348u;
        R(15) = sp;
        vf3_native_aim_frame_b(a, vf3_aim_p(a, obj + D2), vf3_aim_p(a, obj),
                               vf3_aim_p(a, obj + D9), vf3_aim_p(a, R(11) + 44u),
                               a->fr[4]);
    }
    R(15) = sp;
    vf3_aim_pop(a);
    vf3_aim_push(a, 0);

    /* aim_frame_b #2 (object at actor+0x540) */
    {
        const uint32_t h = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, obj + E5);
        vf3_aim_set_u32(a, f, obj + E2);                 /* frame f+0 = obj+0x1F44 */
        vf3_aim_set_u16(a, obj + E5 - 4u, (uint16_t)h);  /* obj+0x22E6 */
    }
    pushw(a, &sp, obj + E6);          /* w0  */
    pushw(a, &sp, R(12) + C6);        /* w1  */
    pushw(a, &sp, R(13) + 84u);       /* w2  */
    pushw(a, &sp, obj + E4);          /* w3  */
    pushw(a, &sp, obj + E3);          /* w4  */
    /* By the time w5 is read, five push_words have run, so R(15) has moved
     * f-64 -> f-84 and mem[R15+84] = mem[f+0] - the obj+E2 pointer just parked
     * at frame+0 (over the aim_b#1 D1), not a kind float. */
    pushw(a, &sp, ld32(a, f));        /* w5 = mem[R15+84] = mem[f+0] = obj+E2 */
    F(4) = ldf(a, obj + E7);          /* fr4 = f(obj+0x20C0) */
    {
        a->f = sp - 348u;
        R(15) = sp;
        vf3_native_aim_frame_b(a, vf3_aim_p(a, obj + E1), vf3_aim_p(a, obj),
                               vf3_aim_p(a, obj + E8), vf3_aim_p(a, R(11) + 60u),
                               a->fr[4]);
    }
    R(15) = sp;
    vf3_aim_pop(a);

    /* ---- the epilogue: add 0x13C, pop macl, pr, r8..r13 and finally r14 ---- */
    sp += EXIT_OFF;                   /* = sp0 - 8 */
    {
        const uint32_t macl_r = ld32(a, sp);
        (void)macl_r;
        sp += 4u;
        a->pr = ld32(a, sp);
        sp += 4u;
        for (int r = 8; r <= 13; ++r) {
            a->r[r] = ld32(a, sp);
            sp += 4u;
        }
        a->r[14] = ld32(a, sp);
        sp += 4u;
    }
    a->r[15] = sp;                    /* sp0 + 28 */
    (void)macl;
}
