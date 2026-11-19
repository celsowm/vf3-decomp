/* pose_turns.c - SH-4 0x8C09F500: the pose quantiser, natively.
 *
 * This is the leaf that closes the fight engine's motion channel: after the
 * pose orchestration (0x8C09EAF2) and its callees have run, the final
 * vector is turned into a canonicalised set of halfwords.  A plain-C
 * transcription of the readable port src/fight/pose_post.c
 * (`vf3_pose_turns_entry`).
 *
 *   r4 = actor, r5 = a three-float vector, r6 = a three-halfword
 *   destination.  The three floats are truncated (ftrc, toward zero) and the
 *   Euler x is canonicalised into [-0x5000, 0x5000]:
 *
 *     |x| > 0x5000  ->  x += 0x8000, y = 0x8000 - y, z += 0x8000
 *
 * The band value (i16)[actor+0x3E] selects when the destination is written:
 * on the two edges band == hi (== (i16)[actor+0x1FB0]&0xffff + 1) and
 * band == lo8 (== lo - 8 where lo = (i16)[actor+0x1A00]&0xffff) the three
 * halfwords x''/y''/z'' go to dest[+0/+2/+4].  The kind gate is reached from
 * two places (hi < band < mid, or lo8 < band < lo1 where mid is signed);
 * when the actor byte +0x61 is 3 and |z''| > 0x7530 (the pool halfword at
 * 0x0C09F5F0) the guest negates z''.  The source vector is always written
 * back as the three floats float(x'')/float(y'')/float(z'').
 *
 * The function is a leaf: pr is never pushed, and the epilogue restores
 * r8..r14 and r15 to the entry values.  The 12-byte frame sits 40 bytes
 * under the entry sp and is written three times at +0 (z-trunc, z'', lo8);
 * the final word is lo8.  See docs/re/native_pose_turns.md and
 * docs/re/pose_post.md.
 */
#include "pose_callees.h"

#include <stdint.h>
#include <string.h>

#include "aim_math.h"

#define R(n) (r[(n)])

/* literal-pool constants of the image (verified against 1ST_READ.unsc.bin) */
#define POOL_BAND_HI   0x5000        /* the canonicalisation bound */
#define POOL_BAND_LO   (-0x5000)     /* signed */
#define POOL_ACTOR_HI  0x1FB0u       /* the band's high word in the actor */
#define POOL_ACTOR_MID 0x1FACu       /* the band's middle word */
#define POOL_ACTOR_LO  0x1A00u       /* the band's low word */
#define POOL_NEG_LIMIT 0x7530        /* the kind-3 magnitude limit */
#define POOL_CANON_ADD 0x8000u       /* the canonicalisation addend */

#define ACTOR_FLAGS 0x3eu
#define ACTOR_KIND  0x61u

#define QUANT_FRAME 12u
#define SAVED_BYTES 28u             /* seven 4-byte register saves */

static int32_t sext16(uint32_t v) { return (int32_t)(int16_t)v; }
static float ldf(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_fbits(vf3_aim_u32(a, addr));
}

void vf3_native_pose_turns(vf3_native_aim *a, uint32_t sp, uint32_t actor,
                           uint32_t vec, uint32_t dest)
{
    uint32_t r[16];
    for (int i = 0; i < 16; ++i) r[i] = a->r[i];
    R(4) = actor; R(5) = vec; R(6) = dest; R(15) = sp;

    const uint32_t f = sp - SAVED_BYTES - QUANT_FRAME;   /* the frame base */

    /* ---- prologue: save r14..r8 ---- */
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(14));
    R(3) = R(5);                          /* the vector base */
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(13));
    R(3) += 4u;                           /* the frame's y pointer */
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(12));
    R(12) = R(5);
    R(2) = R(12); R(2) += 8u;             /* the frame's z pointer */
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(11));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(10));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(9));
    R(15) -= 4u; vf3_aim_set_u32(a, R(15), R(8));
    /* R(15) is now f (== sp - 40) */

    R(15) -= QUANT_FRAME;
    vf3_aim_set_u32(a, f + 8u, R(3));     /* frame +8: the y pointer */
    vf3_aim_set_u32(a, f + 4u, R(2));     /* frame +4: the z pointer */

    /* ---- the three floats, truncated ---- */
    const int32_t x_tr = (int32_t)ldf(a, vec);
    const int32_t y_tr = (int32_t)ldf(a, vec + 4u);
    const int32_t z_tr = (int32_t)ldf(a, vec + 8u);

    R(7) = (uint32_t)x_tr; R(7) &= 0xffffu; R(7) = (uint32_t)sext16(R(7));
    R(13) = (uint32_t)y_tr;
    R(1) = (uint32_t)z_tr;
    vf3_aim_set_u32(a, f, R(1));          /* frame +0 = z-trunc */

    /* ---- the Euler canonicalisation: |x| > 0x5000 ---- */
    R(14) = POOL_CANON_ADD;
    int canonicalise = ((int32_t)R(7) > POOL_BAND_HI);
    R(11) = R(1) & 0xffffu;               /* the delay slot */
    if (!canonicalise)
        canonicalise = !((int32_t)R(7) >= POOL_BAND_LO);
    if (canonicalise) {
        R(13) = (uint32_t)((int32_t)R(14) - (int32_t)R(13));  /* y = 0x8000 - y */
        R(11) = R(11) + R(14);            /* z += 0x8000 */
        R(7)  = R(7)  + R(14);            /* x += 0x8000 */
    }

    /* ---- quantised: the three halfwords ---- */
    R(7)  &= 0xffffu;
    R(9)  = (uint32_t)sext16(R(7));       /* x'' */
    R(11) &= 0xffffu;
    R(14) = (uint32_t)sext16(R(11));      /* z'' */
    vf3_aim_set_u32(a, f, R(11));         /* frame +0 = z'' (low 16) */

    /* ---- the band fields ---- */
    R(7) = vf3_aim_h16(a, actor + ACTOR_FLAGS);  R(7) &= 0xffffu;   /* band value */
    R(10) = vf3_aim_h16(a, actor + POOL_ACTOR_HI); R(10) &= 0xffffu; R(10) += 1u; /* hi */
    R(8) = (uint32_t)sext16(vf3_aim_h16(a, actor + POOL_ACTOR_MID)); R(8) += 1u;   /* mid */
    R(11) = vf3_aim_h16(a, actor + POOL_ACTOR_LO); R(11) &= 0xffffu;              /* lo */
    const uint32_t lo8 = R(11) - 8u;
    R(3) = lo8;
    vf3_aim_set_u32(a, f, R(3));          /* frame +0 = lo8 (the final word) */
    R(11) += 1u;                          /* lo1 (the delay slot) */

    /* ---- the band's two edges ---- */
    if (R(7) == R(10) || R(7) == R(3)) {  /* band == hi or band == lo8 */
        vf3_aim_set_u16(a, dest, (uint16_t)R(9));     /* x'' */
        vf3_aim_set_u16(a, dest + 2u, (uint16_t)R(13)); /* y'' (full width) */
        vf3_aim_set_u16(a, dest + 4u, (uint16_t)R(14)); /* z'' */
    }

    /* ---- the band's inside / the kind-3 negation ---- */
    {
        int to_gate;
        if ((int32_t)R(7) > (int32_t)R(10)) {              /* band > hi */
            to_gate = !((int32_t)R(7) >= (int32_t)R(8));   /* and band < mid */
        } else {                                           /* band <= hi: inside */
            to_gate = ((int32_t)R(7) > (int32_t)R(3))      /* band > lo8 */
                      && !((int32_t)R(7) >= (int32_t)R(11)); /* and band < lo1 */
        }
        if (to_gate) {
            const uint32_t kind = vf3_aim_u8(a, actor + ACTOR_KIND);
            if (kind == 3u) {
                const uint32_t neg = 0u - R(14);           /* -z'' */
                int32_t cand = (int32_t)((int32_t)R(14) >= 0 ? R(14) : neg);
                if (cand > (int32_t)POOL_NEG_LIMIT)
                    R(14) = neg;                           /* z'' = -z'' */
            }
        }
    }

    /* ---- the source vector goes back as floats (int -> float, exact) ---- */
    {
        const float fx = (float)(int32_t)R(9);    /* float(x'') */
        const float fy = (float)(int32_t)R(13);   /* float(y'', full width) */
        const float fz = (float)(int32_t)R(14);   /* float(z'') */
        vf3_aim_set_u32(a, vec, vf3_aim_ubits(fx));
        vf3_aim_set_u32(a, vec + 4u, vf3_aim_ubits(fy));
        vf3_aim_set_u32(a, vec + 8u, vf3_aim_ubits(fz));
    }

    /* ---- the epilogue: r8..r13, then r14 in the rts's delay slot ---- */
    for (int i = 8; i <= 13; ++i) {
        R(i) = vf3_aim_u32(a, f + 12u + 4u * (uint32_t)(i - 8));
    }
    R(14) = vf3_aim_u32(a, f + 36u);
    R(15) = sp;                           /* the leaf restores the stack exactly */

    for (int i = 8; i <= 14; ++i) a->r[i] = r[i];
    a->r[15] = R(15);
    /* pr is never touched, as in the leaf */
}
