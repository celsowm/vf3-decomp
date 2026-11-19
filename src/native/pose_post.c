/* pose_post.c - SH-4 0x8C09F432: the pose post-processor wrapper, natively.
 *
 * Plain-C transcription of the readable port src/fight/pose_post.c
 * (`vf3_pose_post_entry`).  The wrapper takes the actor (r4) and runs five
 * point clamps (0x8C09F5F8, native point_wrap.c) around two calls of the
 * quantiser (0x8C09F500, native pose_turns.c):
 *
 *   actor+0x1D58 -> wrap -> +12 = actor+0x1D64 -> wrap -> +0x54 + 12
 *     = actor+0x1DC4 -> wrap -> +12 = actor+0x1DD0 -> wrap -> +12
 *     = actor+0x1DDC                    (the first quantiser's source)
 *     -> quant(actor+0x233C) -> r0 = +12 = actor+0x1DE8 -> wrap -> +12
 *     = actor+0x1DF4                    (the second quantiser's source)
 *     -> quant(actor+0x2342) -> r0 = r5 = actor+0x1E00.
 *
 * The wrapper returns actor+0x1E00 in r0/r5.  Every point clamp gets the
 * same six floats - fr4 32768, fr5 16384, fr6 -32768, fr7 24576, fr8 0,
 * fr9 65536 - restored before each call.  The wrapper saves r14, fr15,
 * fr14, fr13, fr12 and pr on its stack (E-4 .. E-24) with a twelve-byte
 * frame under them (E-36..E-24), and restores all of it before the return.
 *
 * The quantiser's return contract (r0=r5=source+12, r2=r3=source+8) is not
 * set by the native pose_turns (it restores every register it uses and never
 * writes r0/r2/r3/r5), so this wrapper tracks each continuation address
 * itself - every callee hands control back at its input point/source plus 12
 * - and sets the per-call r2/r3 and the final r0/r5 (=actor+0x1E00).
 *
 * All the arithmetic is add/sub on exactly representable pointer/float
 * values, so plain C reproduces the guest.  See docs/re/native_pose_post.md,
 * docs/re/native_point_wrap.md and docs/re/pose_post.md. */
#include "pose_callees.h"

#include <stdint.h>

#include "aim_math.h"

#define R(n) (r[(n)])

/* the actor offsets / destinations, from the wrapper's literal pool */
#define OFF_FIRST    0x1D58u   /* the first point's offset in the actor */
#define DEST_FIRST   0x233Cu   /* the first quantiser's destination */
#define DEST_SECOND  0x2342u   /* the second quantiser's destination */
#define POINT_STRIDE 0x54u     /* the third point's extra step */

/* the wrapper's stack, relative to its entry sp (WRAP_FRAME under the saves) */
#define WRAP_FRAME 12u

static float ldf(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_fbits(vf3_aim_u32(a, addr));
}

void vf3_native_pose_post(vf3_native_aim *a, uint32_t sp, uint32_t actor)
{
    uint32_t r[16];
    for (int i = 0; i < 16; ++i) r[i] = a->r[i];
    R(15) = sp;
    const uint32_t f = sp - 36u;   /* the frame base (E-36) */

    /* ---- the prologue: r14, fr15, fr14, fr13, fr12, pr ---- */
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(14));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), vf3_aim_ubits(a->fr[15]));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), vf3_aim_ubits(a->fr[14]));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), vf3_aim_ubits(a->fr[13]));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), vf3_aim_ubits(a->fr[12]));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), (uint32_t)a->pr);

    /* ---- the frame's two floats, then the six the clamp reads ---- */
    a->fr[3]  = 16384.0f;
    a->fr[15] = 32768.0f;
    vf3_aim_set_u32(a, f, vf3_aim_ubits(a->fr[3]));      /* frame+0 = 16384 */
    a->fr[3]  = -32768.0f;
    vf3_aim_set_u32(a, f + 4u, vf3_aim_ubits(a->fr[3])); /* frame+4 = -32768 */
    a->fr[12] = 24576.0f;
    a->fr[14] = 65536.0f;
    a->fr[5]  = ldf(a, f);                               /* fr5 = frame+0 */
    a->fr[13] = 0.0f;
    a->fr[7]  = a->fr[12];                               /* 24576 */
    a->fr[6]  = a->fr[3];                                /* -32768 */
    a->fr[9]  = a->fr[14];                               /* 65536 */
    a->fr[8]  = a->fr[13];                               /* 0 */

    /* the six floats every point clamp reads, restored before each call */
#define SETWRAP() do { \
        a->fr[4] = 32768.0f; a->fr[5] = 16384.0f; a->fr[6] = -32768.0f; \
        a->fr[7] = 24576.0f; a->fr[8] = 0.0f;     a->fr[9] = 65536.0f; \
    } while (0)

    uint32_t src;

    /* ---- the first point ---- */
    SETWRAP();
    a->fr[4] = a->fr[15];                    /* the call's delay slot */
    vf3_native_point_wrap(a, f, actor + OFF_FIRST);
    src = a->r[0];      /* r0 = point+12, or the point itself when gated */

    /* ---- the second point: the first call's return ---- */
    SETWRAP();
    vf3_native_point_wrap(a, f, src);
    src = a->r[0];

    /* ---- the third point: the second call's return plus 0x54 ---- */
    SETWRAP();
    vf3_native_point_wrap(a, f, src + POINT_STRIDE);
    src = a->r[0];

    /* ---- the fourth point: the third call's return ---- */
    SETWRAP();
    vf3_native_point_wrap(a, f, src);
    src = a->r[0];

    /* ---- the first quantiser: source = the fourth return, dest = +0x233C ---- */
    vf3_aim_set_u32(a, f + 8u, actor + DEST_FIRST);          /* frame+8 = dest */
    vf3_native_pose_turns(a, f, actor, src, actor + DEST_FIRST);
    R(0) = src + 12u; R(2) = src + 8u; R(3) = src + 8u; R(5) = src + 12u;
    src = src + 12u;

    /* ---- the fifth point: the quantiser's return ---- */
    SETWRAP();
    vf3_native_point_wrap(a, f, src);
    src = a->r[0];

    /* ---- the second quantiser: source = the fifth return, dest = +0x2342 ---- */
    vf3_aim_set_u32(a, f + 8u, actor + DEST_SECOND);         /* frame+8 = dest */
    vf3_native_pose_turns(a, f, actor, src, actor + DEST_SECOND);
    R(0) = src + 12u; R(2) = src + 8u; R(3) = src + 8u; R(5) = src + 12u;
    src = src + 12u;

    /* ---- the epilogue: the frame, pr, then the four floats and r14 ---- */
    R(15) = f + WRAP_FRAME;                          /* E-24 */
    a->pr = vf3_aim_u32(a, R(15)); R(15) += 4u;
    a->fr[12] = ldf(a, R(15)); R(15) += 4u;
    a->fr[13] = ldf(a, R(15)); R(15) += 4u;
    a->fr[14] = ldf(a, R(15)); R(15) += 4u;
    a->fr[15] = ldf(a, R(15)); R(15) += 4u;
    R(14) = vf3_aim_u32(a, R(15)); R(15) += 4u;

    R(0) = src;                                      /* actor + 0x1E00 */
    R(5) = src;
    R(15) = sp;

    for (int i = 0; i < 16; ++i) a->r[i] = r[i];
    a->r[15] = R(15);
    /* a->pr and a->fr[12..15] were restored above; the final r0/r5 = actor+0x1E00 */
}
