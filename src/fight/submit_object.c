/* submit_object.c - 0x8C055646  cull one object against the near plane and, if it survives, run its submit
 * chain with the fight GBR block and the store-queue pointers swapped in.
 *
 *   r4 -> the object record (+0 flags, +4 / +8 arguments, +12 the command list, +16 / +20 / +24 the centre,
 *   +28 the radius).
 *
 *   Prologue: the three queue pointers at [[0x0C16CA08] + 0 / 8 / 16] are cut to their low 26 bits, tagged
 *   0xE0000000 (the store-queue area) and parked at GBR+72 / +80 / +88 of the fight block (0x0C16B880), which
 *   becomes the GBR for the duration. PR is pointed at the epilogue (0x8C0557E0), so every early return of the
 *   body lands there.
 *
 *   Body: the centre goes through XMTRX; with the depth scale GBR[+40] the radius gives a near/far interval
 *   (fr7 = z - r*s, fr8 = z + r*s...) and the object is dropped if the interval is behind the plane or beyond
 *   the far limit [0x0C16B8A0]. Survivors run the GBR[+20] set-up, the flag-selected header writer
 *   (0x8C057060 or 0x8C057BE0, chosen by bit 5 of the flags and [0x0C0EA54C]), and are tested a second time
 *   against two clip volumes from the table at 0x0C19D558 (two rounds, each two 4-vector dot products). Then
 *   the submit pass: GBR[+16](obj args) unless GBR[+68] > 0, followed by the command-list interpreter - bank r4
 *   walks the 16-bit command list at obj[+12], each entry (low byte x 4) indexing the function table at GBR[+12]
 *   - and finally a tail call to 0x8C03C4A0(1).
 *
 *   Epilogue: the queue pointers are read back from the fight block, their low 26 bits merged with the high bits
 *   they had in the queue state, GBR[+40] (the caller's block) gets 1.0, and the caller's registers return.
 *
 *   Frame: r14..r8, pr, gbr, then fr15..fr12 pushed (52 bytes); a second pr slot below it while the survivors run. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 52, SQ_STATE = 0x0C16CA08u, FIGHT_GBR = 0x0C16B880u, EPILOGUE = 0x8C0557E0u,
       NEAR_LIMIT = 0x0C16B8A0u, SCALE_CELL = 0x0C16B8ACu, CELL_A = 0x0C0EA534u, CELL_B = 0x0C0EA538u,
       VOLUMES = 0x0C19D558u, LOW26 = 0x03FFFFFFu, QUEUE_TAG = 0xE0000000u, ONE = 0x3F800000u,
       SZ = 0x00100000u, PR_MODE = 0x00080000u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

static uint32_t guest(uint32_t a) { return (a & 0x0FFFFFFFu) | 0x8C000000u; }

/* fr0..fr2 = the centre (obj + 16), fr3 = 1, through XMTRX; fr6 = the depth scale bits; r4 left at obj + 28 */
static int transform_centre(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t obj)
{
    F(0) = m32(ram, obj + 16);
    F(1) = m32(ram, obj + 20);
    F(2) = m32(ram, obj + 24);
    F(3) = ONE;
    R(4) = obj + 28;
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(0), R(VF3_REG_FPSCR), &F(0))) return 0;
    R(0) = m32(ram, s->gbr + 40);
    s->v[VF3_REG_FPUL] = R(0);
    F(6) = s->v[VF3_REG_FPUL];
    return 1;
}

int vf3_submit_object_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!s->gbr_known) return 0;
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & (SZ | PR_MODE))) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f0 = sp0 - SAVED, old_gbr = s->gbr, obj = R(4);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
    uint32_t f = f0;

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 32, pr0);
    w32(ram, sp0 - 36, old_gbr);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 36 - 4u * (uint32_t)(i + 1), saved_f[i]);
    R(15) = f;

    const uint32_t queue = m32(ram, SQ_STATE);
    R(1) = queue;
    R(7) = QUEUE_TAG;
    R(2) = LOW26;
    R(12) = (m32(ram, queue + 0) & LOW26) | QUEUE_TAG;
    R(11) = (m32(ram, queue + 16) & LOW26) | QUEUE_TAG;
    R(0) = (m32(ram, queue + 8) & LOW26) | QUEUE_TAG;
    R(3) = EPILOGUE + 0u;
    s->gbr = FIGHT_GBR;
    R(VF3_REG_PR) = EPILOGUE;
    w32(ram, FIGHT_GBR + 80, R(0));
    w32(ram, FIGHT_GBR + 88, R(11));
    w32(ram, FIGHT_GBR + 72, R(12));
    R(13) = obj;

    /* ---- body: depth cull ---- */
    R(3) = NEAR_LIMIT;
    if (!transform_centre(s, ram, obj)) goto fail;
    F(4) = m32(ram, R(4));
    F(5) = m32(ram, NEAR_LIMIT);
    F(2) ^= SIGN;
    FMUL(4, 6);
    FMOV(7, 2); FMOV(8, 2);
    FADD(7, 4);
    F(9) = 0;
    FSUB(8, 4);
    R(3) = 0x0C03C4F0u;
    SET_T(GT(7, 9));
    if (R(VF3_REG_SR) & 1u) goto epilogue;
    SET_T(GT(5, 8));
    if (R(VF3_REG_SR) & 1u) goto epilogue;

    /* ---- survivors ---- */
    w32(ram, f0 - 4, R(VF3_REG_PR) & 0x0FFFFFFFu);     /* the mova-built pointer lives in the cached mirror */
    f = f0 - 4;
    R(15) = f;
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C0556E0u);
    R(0) = m32(ram, s->gbr + 20);
    CALL(guest(R(0)), 0x8C0556E6u);

    R(0) = m32(ram, obj);
    R(1) = 32;
    SET_T((R(0) & 32) == 0);
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = m32(ram, 0x0C0EA54Cu);
        SET_T(R(0) == 0);
        R(0) = R(0) ? 0x0C057BE0u : 0x0C057060u;
        R(4) = m32(ram, obj + 4);
        R(6) = m32(ram, obj + 8);
        CALL(guest(R(0)), 0x8C05570Cu);
    }

    if (!transform_centre(s, ram, obj)) goto fail;
    R(0) = VOLUMES;
    R(3) = 2;
    F(15) = m32(ram, R(4));                             /* the scaled radius is formed once; the loop re-enters after it */
    R(4) += 4;
    FMUL(15, 6);
    for (;;) {
        R(VF3_REG_FPSCR) ^= SZ;
        for (uint32_t i = 0; i < 8; ++i) F(4 + i) = m32(ram, R(0) + 4 * i);
        R(0) += 32;
        if (!vf3_fpu_fipr(&F(0), &F(4), R(VF3_REG_FPSCR), &F(7))) goto fail;
        if (!vf3_fpu_fipr(&F(0), &F(8), R(VF3_REG_FPSCR), &F(11))) goto fail;
        SET_T(GT(7, 15));
        R(VF3_REG_FPSCR) ^= SZ;
        if (!(R(VF3_REG_SR) & 1u)) goto tail;
        SET_T(GT(11, 15));
        if (!(R(VF3_REG_SR) & 1u)) goto tail;
        --R(3);
        SET_T(R(3) == 0);
        if (R(VF3_REG_SR) & 1u) break;
    }

    R(0) = 0x8C0557B8u + 8u;
    R(3) = 0x0C03DD00u;
    F(4) = m32(ram, CELL_A);
    F(5) = m32(ram, CELL_B);
    R(1) = CELL_B;
    CALL(0x8C03DD00u, 0x8C055754u);

    R(1) = SCALE_CELL;
    R(3) = m32(ram, s->gbr + 68);
    R(0) = m32(ram, s->gbr + 16);
    R(4) = m32(ram, obj + 4);
    R(6) = m32(ram, obj + 8);
    R(7) = obj;
    SET_T((int32_t)R(3) > 0);
    if (!(R(VF3_REG_SR) & 1u)) {
        R(5) = m32(ram, R(1));
        CALL(guest(R(0)), 0x8C05576Au);
    }

    {
        const uint32_t list = m32(ram, obj + 12);
        F(3) = 0x3B800000u;
        R(10) = m32(ram, 0x0C16B8A4u);
        R(3) = SCALE_CELL;
        R(1) = 0xF0000000u;
        R(14) = m32(ram, s->gbr + 12);
        R(4) = list;
        R(2) = 0;
        s->bank[3] = 0;
        R(13) = m32(ram, R(3));
        s->bank[4] = 0xF0000000u;
        s->bank_known = 1;
        for (;;) {
            const uint32_t word = vf3_mem_u16(ram, R(4));
            SET_T(!(word & 0x8000u));                   /* cmp/pz on the sign-extended halfword */
            R(0) = (word & 0xFFu) << 2;                 /* extu.b + the delay-slot shll2 run on both paths */
            if (word & 0x8000u) break;
            R(3) = m32(ram, R(0) + R(14));
            CALL(guest(R(3)), 0x8C055798u);
        }
    }

tail:
    R(3) = 0x0C03C4A0u;
    R(VF3_REG_PR) = m32(ram, f);                        /* lds.l @r15+,pr */
    f += 4;
    R(15) = f;
    R(4) = 1;
    CALL(0x8C03C4A0u, EPILOGUE);
    R(15) = f0;

epilogue:
    {
        const uint32_t keep = LOW26, high = ~keep;
        const uint32_t gbr_block = FIGHT_GBR;
        const uint32_t q = m32(ram, SQ_STATE);
        R(5) = keep;
        R(1) = q;
        R(6) = m32(ram, gbr_block + 72);
        R(9) = m32(ram, gbr_block + 88);
        R(0) = m32(ram, gbr_block + 80);
        R(2) = high;
        R(7) = ONE;
        R(3) = m32(ram, q + 0);
        R(4) = m32(ram, q + 8);
        R(8) = m32(ram, q + 16);
        s->gbr = old_gbr;
        R(3) &= high; R(4) &= high; R(8) &= high;
        R(6) &= keep; R(0) &= keep; R(9) &= keep;
        R(6) |= R(3); w32(ram, q + 0, R(6));
        R(0) |= R(4); w32(ram, q + 8, R(0));
        R(9) |= R(8); w32(ram, q + 16, R(9));
        R(0) = R(7);
        w32(ram, old_gbr + 40, R(0));
    }
    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    for (int i = 0; i < 4; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;

fail:
    s->gbr = old_gbr;
    return 0;
}
