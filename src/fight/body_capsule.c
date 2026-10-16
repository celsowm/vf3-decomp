/* body_capsule.c - 0x8C06F450  fit a fighter's capsule (cylinder with end points) to the current pose and
 * run the node-chain collision (capsule_chain) once per chain.
 *
 *   r4 = owner object, r5 = capsule record (the same record capsule_chain reads).
 *   Record fields: +4 node array, +12 matrix block, +0x54 link scale, +0x58 chain count, +0x5C chain length,
 *   +0x64 node reach (fr14), +0x6C / +0x70 the two matrix blocks of the end points, +0x74 / +0x80 the capsule
 *   axes, +0x8C / +0x98 the end points, +0xA4 axis length, +0xA8/+0xAC come from the setup below.
 *
 *   1. Transform the axis length (+0xA4, as x on a zero vector) and the constant axis vector at 0x0D3D68 into the
 *      two end-point matrices: end point A / axis A with the first matrix block, end point B / axis B with the
 *      second block ([+0x70]).
 *   2. Pick the push-out vector at frame+104 (a fixed offset up, or sideways for some object states) and the
 *      first chain (1 for owner states 8 / 12, else 2).
 *   3. For every chain: every node is moved onto the capsule radius, the displacement is transformed back
 *      into the chain frame and capsule_chain runs on the chain's nodes.
 *   4. Finally the end-point matrices are restored through 0x03C4A0 and the follow-up fixups 0x071694 /
 *      0x072B02 / 0x03B530 run.
 *
 * Frame = 116 bytes below the saved block (14 words + macl); temporaries sit at frame+8 .. +116 as the
 * original lays them out, because the callees' dead stack pushes are part of the verified state. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

#define LIT(a) ((uint32_t)(a) & 0x0FFFFFFFu)   /* literal-pool form of a code address */

enum {
    SAVED_BYTES = 52, FRAME_BYTES = 116,
    WORD_COPY = 0x8C042F08, MATRIX_LOAD = 0x8C03BD80, MATRIX_POP_A = 0x8C03C5B0, MATRIX_PUSH = 0x8C03C4F0,
    SELECT_BONE = 0x8C03C0E0, MATRIX_POP_B = 0x8C03C4A0, CAPSULE_CHAIN = 0x8C070008,
    FIXUP_A = 0x8C071694, FIXUP_B = 0x8C072B02, FINISH = 0x8C03B530,
    AXIS_CONST = 0x0C0D3D68, SCALE_CELL = 0x0C29BCC4,
    LIT_TENTH = 0x8C06F664, LIT_FIVE = 0x8C06F66C, LIT_EIGHT = 0x8C06F670, LIT_STEP = 0x8C06F6D8,
    LIT_EPS = 0x8C06F738,
    ONE_BITS = 0x3F800000
};

/* v = M * (x, y, z, w) with the matrix in XF; stores xyz at dst. Leaves FR4..FR7 = the full result. */
static int xform(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t src, uint32_t dst, int point)
{
    R(4) = src + (point ? 8u : 12u);
    F(4) = m32(ram, src); F(5) = m32(ram, src + 4); F(6) = m32(ram, src + 8);
    F(7) = point ? ONE_BITS : 0;
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(4), R(VF3_REG_FPSCR), &F(4))) return 0;
    R(5) = dst;
    w32(ram, dst + 8, F(6)); w32(ram, dst + 4, F(5)); w32(ram, dst, F(4));
    return 1;
}

int vf3_body_capsule_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };
    const uint32_t saved_macl = R(VF3_REG_MACL);
    const uint32_t owner = R(4), rec = R(5);

#define CALL(target, ret) do { R(15) = frame; if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = frame; } while (0)

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 32u - 4u * (uint32_t)i, saved_f[i]);
    w32(ram, sp0 - 48u, pr0);
    w32(ram, sp0 - 52u, saved_macl);
    R(14) = rec;
    R(11) = owner;
    R(13) = SCALE_CELL;
    R(15) = frame;

    /* copy the constant axis vector (12 bytes) into frame+20 */
    R(3) = LIT(WORD_COPY); R(2) = AXIS_CONST; R(1) = frame + 20; R(0) = 12;
    CALL(WORD_COPY, 0x8C06F47E);
    R(1) = LIT(MATRIX_LOAD); R(9) = 2; R(4) = m32(ram, rec + 12);
    CALL(MATRIX_LOAD, 0x8C06F486);
    R(3) = LIT(MATRIX_POP_A);
    CALL(MATRIX_POP_A, 0x8C06F48C);
    R(2) = LIT(MATRIX_PUSH); R(4) = 0;
    CALL(MATRIX_PUSH, 0x8C06F492);
    R(8) = LIT(SELECT_BONE); R(0) = 108; R(4) = m32(ram, rec + 108);
    CALL(SELECT_BONE, 0x8C06F49A);

    /* end point A and axis A through the first matrix block */
    R(0) = 0xA4;
    R(4) = frame + 8;
    F(3) = m32(ram, rec + 0xA4);
    R(0) = 8;  w32(ram, frame + 8, F(3));
    F(15) = 0;
    R(0) = 12; w32(ram, frame + 12, F(15));
    R(0) = 16; w32(ram, frame + 16, F(15));
    if (!xform(s, ram, frame + 8, rec + 0x8C, 1)) return 0;
    if (!xform(s, ram, frame + 20, rec + 116, 0)) return 0;

    R(3) = LIT(MATRIX_POP_B); R(4) = 1;
    CALL(MATRIX_POP_B, 0x8C06F52A);
    R(0) = 112; R(4) = m32(ram, rec + 112);
    CALL(SELECT_BONE, 0x8C06F530);
    if (!xform(s, ram, frame + 8, rec + 0x98, 1)) return 0;
    if (!xform(s, ram, frame + 20, rec + 0x80, 0)) return 0;

    /* chain parameters */
    R(10) = m32(ram, rec + 88);
    R(3) = m32(ram, rec + 92);
    w32(ram, frame + 4, R(3));
    R(0) = 100; F(14) = m32(ram, rec + 100);
    R(0) = LIT_TENTH; F(3) = m32(ram, LIT_TENTH);
    R(0) = 84; F(13) = m32(ram, rec + 84);
    R(0) = 72;
    R(3) = 0x20000; R(4) = m32(ram, owner + 72);
    set_fl(s, 13, vf3_f_mul(s, fl(s, 13), fl(s, 3)));
    if ((R(4) & 0x21000u) != 0) {
        if ((R(4) & 0x20000u) == 0) R(1) = 0x1000;
        F(3) = m32(ram, R(13)); F(3) ^= SIGN;
        R(0) = 108; w32(ram, frame + 108, F(3));
        R(0) = 112; w32(ram, frame + 112, F(15));
        R(0) = LIT_FIVE; F(4) = m32(ram, LIT_FIVE);
        R(0) = vf3_mem_u8(ram, owner + 96);
        if (R(0) == 21) {
            F(3) = m32(ram, R(13));
            set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 4)));
            F(3) ^= SIGN;
        } else {
            F(3) = m32(ram, R(13));
            set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 4)));
        }
        R(0) = 104; w32(ram, frame + 104, F(3));
    } else {
        if ((R(4) & 0x20000u) == 0) R(1) = 0x1000;
        R(0) = 112; w32(ram, frame + 112, F(15));
        R(0) = 104; w32(ram, frame + 104, F(15));
        R(0) = LIT_EIGHT;
        F(2) = m32(ram, R(13)); F(3) = m32(ram, LIT_EIGHT);
        R(0) = 108;
        set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 3)));
        F(2) ^= SIGN;
        w32(ram, frame + 108, F(2));
    }

    /* first chain / node pointers */
    R(0) = 97;
    R(4) = vf3_mem_u8(ram, owner + 97);
    R(0) = R(4);
    if (R(0) == 8 || R(0) == 12) R(9) = 1;
    R(4) = R(9) - 1u;
    R(VF3_REG_MACL) = R(4) * R(10);
    R(2) = m32(ram, rec + 4);
    R(13) = R(10);
    R(0) = 62;
    R(4) = R(VF3_REG_MACL);
    R(12) = R(4) * 24u;                                    /* node pointer of the first chain */
    R(3) = R(10);
    R(13) = R(13) * 24u;
    R(12) += R(2);
    R(2) = m32(ram, rec + 12);
    w32(ram, frame, R(2));
    R(3) = vf3_mem_u16(ram, owner + 62);
    R(2) = 2;
    R(13) += R(12);                                        /* end of that chain's nodes */
    if (R(3) < 2) {
        R(3) = 0x0C06F96A;
        goto tail;
    }

    R(3) = LIT(MATRIX_PUSH); R(4) = 0;
    CALL(MATRIX_PUSH, 0x8C06F638);
    R(3) = LIT(MATRIX_LOAD); R(4) = m32(ram, frame);
    CALL(MATRIX_LOAD, 0x8C06F63E);
    R(2) = LIT(MATRIX_POP_A);
    CALL(MATRIX_POP_A, 0x8C06F644);
    R(0) = 72; R(3) = 0x21000; R(2) = m32(ram, owner + 72);
    if ((R(3) & R(2)) == 0) {
        if (!xform(s, ram, frame + 104, frame + 104, 0)) return 0;
    } else {
        R(1) = 0x0C06F6A0;
    }
    R(4) = rec + 16;
    CALL(SELECT_BONE, 0x8C06F6A6);
    R(3) = 0x0C06F94A;
    R(8) = R(9);
    F(12) = ONE_BITS;

    for (;;) {
        R(2) = m32(ram, frame + 4);
        if ((int32_t)R(8) >= (int32_t)R(2)) break;
        R(3) = 0x0C06F6AE;

        R(0) = LIT_STEP; F(3) = m32(ram, LIT_STEP);
        set_fl(s, 13, vf3_f_add(s, fl(s, 13), fl(s, 3)));
        R(9) = 0;
        if (fgt(s, 13, 12)) F(13) = F(12);

        if ((int32_t)R(10) > 0) {
            for (;;) {
                R(4) = frame + 56;
                v3_sub(s, ram, frame + 56, R(13), R(12));
                R(4) = frame + 56;
                if (!v3_length(s, ram, frame + 56)) return 0;
                R(0) = LIT_EPS; F(3) = m32(ram, LIT_EPS);
                if (fl(s, 3) > fl(s, 0)) {                      /* degenerate: use (reach, 0, 0) */
                    R(0) = 56; w32(ram, frame + 56, F(14));
                    R(0) = 60; w32(ram, frame + 60, F(15));
                    R(0) = 64; R(3) = 0x0C06F75C; w32(ram, frame + 64, F(15));
                } else {
                    F(4) = F(14);
                    if (!v3_normalize(s, ram, frame + 56, frame + 56)) return 0;
                }
                v3_add(s, ram, R(13), frame + 56, R(12), 0);
                if (!xform(s, ram, R(13), frame + 80, 1)) return 0;
                v3_sub(s, ram, frame + 92, frame + 80, R(13));
                F(4) = F(13);
                v3_scale(s, ram, frame + 92, frame + 92);
                if (!v3_length(s, ram, frame + 92)) return 0;
                v3_add(s, ram, frame + 68, frame + 92, frame + 104, 0);

                /* copy frame+56 -> frame+44 */
                R(0) = 56; F(3) = m32(ram, frame + 56);
                R(5) = frame; R(0) = 44; R(4) = frame + 44;
                w32(ram, frame + 44, F(3));
                R(0) = 60; F(3) = m32(ram, frame + 60);
                R(0) = 48; R(5) = frame + 68;
                w32(ram, frame + 48, F(3));
                R(0) = 64; F(3) = m32(ram, frame + 64);
                R(0) = 52;
                w32(ram, frame + 52, F(3));

                if (!v3_dot(s, ram, frame + 44, frame + 68)) return 0;
                R(4) = frame + 32;
                R(5) = frame + 44;
                if (!v3_normalize(s, ram, frame + 32, frame + 44)) return 0;

                /* frame+68 -= frame+32, in place */
                F(0) = m32(ram, frame + 68); F(3) = m32(ram, frame + 32);
                F(1) = m32(ram, frame + 72); F(4) = m32(ram, frame + 36);
                F(2) = m32(ram, frame + 76); F(5) = m32(ram, frame + 40);
                set_fl(s, 0, vf3_f_sub(s, fl(s, 0), fl(s, 3)));
                set_fl(s, 2, vf3_f_sub(s, fl(s, 2), fl(s, 5)));
                set_fl(s, 1, vf3_f_sub(s, fl(s, 1), fl(s, 4)));
                w32(ram, frame + 76, F(2)); w32(ram, frame + 72, F(1)); w32(ram, frame + 68, F(0));
                R(4) = frame + 68; R(5) = frame + 44;

                v3_add(s, ram, frame + 44, frame + 56, frame + 68, 0);
                F(4) = F(14);
                if (!v3_normalize(s, ram, frame + 44, frame + 44)) return 0;
                v3_add(s, ram, frame + 80, R(12), frame + 44, 0);
                v3_add(s, ram, R(13), R(12), frame + 44, 0);

                R(9) += 1;
                R(13) += 24;
                R(12) += 24;
                if ((int32_t)R(9) >= (int32_t)R(10)) break;
                R(2) = 0x0C06F6C6;
            }
        } else {
            R(2) = 0x0C06F93C;
        }

        R(3) = LIT(CAPSULE_CHAIN);
        R(5) = R(14); R(7) = R(8); R(6) = R(13); R(4) = R(11);
        CALL(CAPSULE_CHAIN, 0x8C06F948);
        R(8) += 1;
    }

    R(2) = LIT(MATRIX_POP_B); R(4) = 1;
    CALL(MATRIX_POP_B, 0x8C06F95C);
    R(3) = LIT(FIXUP_A); R(4) = R(14);
    CALL(FIXUP_A, 0x8C06F962);
    R(2) = LIT(FIXUP_B); R(5) = R(14); R(4) = R(11);
    CALL(FIXUP_B, 0x8C06F96A);

tail:
    R(3) = LIT(FINISH); R(4) = R(14) + 16; R(5) = m32(ram, frame);
    CALL(FINISH, 0x8C06F974);

    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = saved_f[0]; F(14) = saved_f[1]; F(13) = saved_f[2]; F(12) = saved_f[3];
    R(VF3_REG_MACL) = saved_macl;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
#undef CALL
}
