/* pose_post.c - SH-4 0x8C09F432 / 0x8C09F500: the pose postprocessor.
 *
 * 0x8C09F432 is the wrapper.  It is handed the actor (r4) and runs five point
 * clamps (0x8C09F5F8) around two calls of the quantizer (0x8C09F500):
 *
 *   actor+0x1D58  point clamp          the wrapper's own first point
 *   actor+0x1D64  point clamp          the first call's return
 *   actor+0x1DC4  point clamp          the second call's return plus 0x54
 *   actor+0x1DD0  point clamp          the third call's return
 *   actor+0x1DDC  quantizer -> actor+0x233C
 *   actor+0x1DE8  point clamp          the quantizer's return
 *   actor+0x1DF4  quantizer -> actor+0x2342
 *
 * The wrapper returns actor+0x1E00 in r0/r5.  Every point clamp gets the same
 * six floats: fr4 32768.0, fr5 16384.0, fr6 -32768.0, fr7 24576.0, fr8 0.0 and
 * fr9 65536.0; fr4 travels in the call's delay slot.  The wrapper saves
 * r14, fr15, fr14, fr13, fr12 and pr on its stack, with a twelve-byte frame
 * under them, and restores all of it before the return.
 *
 * 0x8C09F500 is the quantizer.  It takes the actor (r4), one three-float
 * vector (r5) and a three-halfword destination (r6).  It truncates the three
 * floats to integers, canonicalises the Euler angle when |x| > 0x5000
 * (x += 0x8000, y = 0x8000 - y, z += 0x8000), and then writes the three
 * quantised halfwords to the destination **only** on the frames the actor's
 * own band words select:
 *
 *   x equals (u16)[actor+0x1FB0] + 1, or
 *   x equals (u16)[actor+0x1A00] - 8,
 *   or x is inside the open band between them ((u16)[actor+0x1A00] - 8 < x <
 *   (u16)[actor+0x1FB0] + 1) - the last one only when the bounds are the right
 *   way round.
 *
 * On top of that, when the actor's kind byte at +0x61 is 3, the z halfword is
 * negated if it lies above 0x7530 in absolute value.  The three quantised
 * values are always written back into the source vector as floats, and the
 * function returns r5+12 in r0/r5 (r2 and r3 are r5+8).
 *
 * The literal pool is read at run time, the way the guest reads it: the
 * offsets, the two destinations, the five floats and the four angle constants
 * are the image's, and this port does not bake them in.  The wrapper is
 * proved against the captured fight states in
 * extract/analysis/native_pose_chain_s29_v1/f_8c09f432.cases, where the
 * actor's window starts at actor+0x1C; every address the two functions read
 * in the actor is at or above that.
 *
 * Details the port has to keep:
 *
 *   * the wrapper's stack holds r14 at E-4, then fr15, fr14, fr13 and fr12,
 *     then pr at E-24 and the frame at E-36..E-24; the FR saves and restores
 *     go through vf3_matrix_store/vf3_matrix_load, so they honour FPSCR.SZ;
 *   * the **`bt/s` delay slots run on both paths**: the quantizer's first
 *     one writes z's low half into the frame before the canonicalisation
 *     branch is resolved, its second one writes the band's high bound minus
 *     eight, its third one bumps the high bound, and its fourth one negates
 *     z into r6 even when z is positive;
 *   * the quantizer stores FPUL three times: the truncated z on entry, the
 *     quantised z'' before the band is checked, and finally z'' (or -z'') as
 *     it leaves |z| > 0x7530.  FPUL is also the value `float FPUL,FRn`
 *     converts, so the last store is the one the source vector sees;
 *   * the **T bit** is part of the contract.  The wrapper inherits the last
 *     quantizer's T; the quantizer's own last test is the band/kind chain and
 *     its arms do not all leave the same value.  The order of the tests below
 *     is therefore the guest's order;
 *   * the two `bt/s` forms have a delay slot and the plain `bt`/`bf` do not,
 *     so the tests that end the band chain do not run the instruction that
 *     follows them.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

/* the wrapper's literal pool */
#define POOL_OFF_FIRST   0x0c09f4e6u /* the first point's offset in the actor */
#define POOL_DEST_FIRST  0x0c09f4e8u /* the first destination, in the actor */
#define POOL_DEST_SECOND 0x0c09f4eau /* the second destination, in the actor */
#define POOL_F_16K       0x0c09f4ecu /* 16384.0, the frame's first float */
#define POOL_F_32K       0x0c09f4f0u /* 32768.0, the clamp's period */
#define POOL_F_M32K      0x0c09f4f4u /* -32768.0 */
#define POOL_F_24K       0x0c09f4f8u /* 24576.0 */
#define POOL_F_64K       0x0c09f4fcu /* 65536.0 */

/* the quantizer's literal pool */
#define POOL_BAND_HI     0x0c09f5e8u /* 0x5000, the canonicalisation bound */
#define POOL_BAND_LO     0x0c09f5eau /* -0x5000 */
#define POOL_ACTOR_HI    0x0c09f5ecu /* 0x1FB0, the band's high word */
#define POOL_ACTOR_LO    0x0c09f5eeu /* 0x1A00, the band's low word */
#define POOL_NEG_LIMIT   0x0c09f5f0u /* 0x7530, the kind-3 limit */
#define POOL_CANON_ADD   0x0c09f5f4u /* 0x8000, the canonicalisation addend */

/* the stride between the points in the actor */
#define POINT_STRIDE 0x54u

/* the fields of the actor the quantizer reads */
#define ACTOR_FLAGS  0x3eu   /* the halfword the first band test uses */
#define ACTOR_KIND   0x61u

/* the continuations the guest leaves in pr */
#define CONT_POINT_1 0x0c09f470u
#define CONT_POINT_2 0x0c09f482u
#define CONT_POINT_3 0x0c09f496u
#define CONT_POINT_4 0x0c09f4a8u
#define CONT_QUANT_1 0x0c09f4b6u
#define CONT_POINT_5 0x0c09f4c8u
#define CONT_QUANT_2 0x0c09f4d6u

/* the functions the wrapper calls */
#define POINT_WRAP   0x0c09f5f8u
#define QUANTIZE     0x0c09f500u

/* the wrapper's stack, relative to its entry sp */
#define WRAP_SAVE_R14  4u
#define WRAP_SAVE_FR15 8u
#define WRAP_SAVE_FR14 12u
#define WRAP_SAVE_FR13 16u
#define WRAP_SAVE_FR12 20u
#define WRAP_SAVE_PR   24u
#define WRAP_FRAME     12u

/* the quantizer's stack, relative to its entry sp */
#define QUANT_SAVE_R14  4u
#define QUANT_SAVE_R13  8u
#define QUANT_SAVE_R12  12u
#define QUANT_SAVE_R11  16u
#define QUANT_SAVE_R10  20u
#define QUANT_SAVE_R9   24u
#define QUANT_SAVE_R8   28u
#define QUANT_FRAME     12u

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* A pool halfword: the guest reads it and sign extends it. */
static uint32_t pool_half(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)vf3_mem_u16(ram, addr);
}

/* A pool word, as the float the guest loads through the PC-relative address. */
static uint32_t pool_word(const vf3_ram_map *ram, uint32_t addr)
{
    return vf3_mem_u32(ram, addr);
}

/* A stack save of the guest's registers: 4 bytes for r, the FPSCR width for
 * fr.  These mirror the generated translation's vf3_matrix_store uses. */
static uint32_t fr_width(const vf3_matrix_state *s)
{
    return (R(18) & 0x100000u) ? 8u : 4u;
}

int vf3_pose_post_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t w = fr_width(s);

    /* ---- the prologue: r14, fr15, fr14, fr13, fr12, pr, then the frame ---- */
    R(15) -= 4u;
    w32(ram, R(15), R(14));
    R(0) = POOL_F_16K;
    R(15) -= w;
    vf3_matrix_store(s, ram, 15, R(15));
    R(14) = R(4);
    R(15) -= w;
    vf3_matrix_store(s, ram, 14, R(15));
    R(15) -= w;
    vf3_matrix_store(s, ram, 13, R(15));
    R(15) -= w;
    vf3_matrix_store(s, ram, 12, R(15));
    R(15) -= 4u;
    w32(ram, R(15), R(16));

    /* ---- the frame's two floats, then the six the clamp reads ---- */
    vf3_matrix_load(s, ram, 3, R(0));              /* fr3 = 16384.0 */
    R(0) = POOL_F_32K;
    R(4) = pool_half(ram, POOL_OFF_FIRST);
    R(15) -= WRAP_FRAME;
    vf3_matrix_store(s, ram, 3, R(15));            /* the frame's +0 */
    R(4) += R(14);                                 /* actor + 0x1D58 */
    vf3_matrix_load(s, ram, 15, R(0));             /* fr15 = 32768.0 */
    R(0) = POOL_F_M32K;
    vf3_matrix_load(s, ram, 3, R(0));              /* fr3 = -32768.0 */
    R(0) = 4u;
    vf3_matrix_store(s, ram, 3, R(15) + R(0));     /* the frame's +4 */
    R(0) = POOL_F_24K;
    vf3_matrix_load(s, ram, 12, R(0));             /* fr12 = 24576.0 */
    R(0) = POOL_F_64K;
    vf3_matrix_load(s, ram, 14, R(0));             /* fr14 = 65536.0 */
    vf3_matrix_load(s, ram, 5, R(15));             /* fr5 = 16384.0 */
    F(13) = 0u;
    vf3_matrix_move(s, 7, 12);
    vf3_matrix_move(s, 6, 3);
    vf3_matrix_move(s, 9, 14);
    vf3_matrix_move(s, 8, 13);

    /* ---- the first point ---- */
    vf3_matrix_move(s, 4, 15);                     /* the call's delay slot */
    if (!vf3_guest_call(s, ram, POINT_WRAP, CONT_POINT_1)) return 0;

    /* ---- the second point: the first call's return ---- */
    R(4) = R(0);
    R(0) = 4u;
    vf3_matrix_load(s, ram, 6, R(15) + R(0));
    vf3_matrix_load(s, ram, 5, R(15));
    vf3_matrix_move(s, 9, 14);
    vf3_matrix_move(s, 8, 13);
    vf3_matrix_move(s, 7, 12);
    vf3_matrix_move(s, 4, 15);
    if (!vf3_guest_call(s, ram, POINT_WRAP, CONT_POINT_2)) return 0;

    /* ---- the third point: the second call's return plus 0x54 ---- */
    R(4) = R(0);
    R(0) = 4u;
    vf3_matrix_load(s, ram, 6, R(15) + R(0));
    R(4) += POINT_STRIDE;
    vf3_matrix_load(s, ram, 5, R(15));
    vf3_matrix_move(s, 7, 12);
    vf3_matrix_move(s, 9, 14);
    vf3_matrix_move(s, 8, 13);
    vf3_matrix_move(s, 4, 15);
    if (!vf3_guest_call(s, ram, POINT_WRAP, CONT_POINT_3)) return 0;

    /* ---- the fourth point: the third call's return ---- */
    R(4) = R(0);
    R(0) = 4u;
    vf3_matrix_load(s, ram, 6, R(15) + R(0));
    vf3_matrix_load(s, ram, 5, R(15));
    vf3_matrix_move(s, 9, 14);
    vf3_matrix_move(s, 8, 13);
    vf3_matrix_move(s, 7, 12);
    vf3_matrix_move(s, 4, 15);
    if (!vf3_guest_call(s, ram, POINT_WRAP, CONT_POINT_4)) return 0;

    /* ---- the first quantizer: source = the fourth return, dest = +0x233C ---- */
    R(2) = pool_half(ram, POOL_DEST_FIRST);
    R(5) = R(0);
    R(2) += R(14);
    R(6) = R(2);
    w32(ram, R(15) + 8u, R(2));
    R(4) = R(14);                                  /* the call's delay slot */
    if (!vf3_guest_call(s, ram, QUANTIZE, CONT_QUANT_1)) return 0;

    /* ---- the fifth point: the quantizer's return ---- */
    R(4) = R(0);
    R(0) = 4u;
    vf3_matrix_load(s, ram, 6, R(15) + R(0));
    vf3_matrix_load(s, ram, 5, R(15));
    vf3_matrix_move(s, 9, 14);
    vf3_matrix_move(s, 8, 13);
    vf3_matrix_move(s, 7, 12);
    vf3_matrix_move(s, 4, 15);
    if (!vf3_guest_call(s, ram, POINT_WRAP, CONT_POINT_5)) return 0;

    /* ---- the second quantizer: source = the fifth return, dest = +0x2342 ---- */
    R(2) = pool_half(ram, POOL_DEST_SECOND);
    R(5) = R(0);
    R(2) += R(14);
    R(6) = R(2);
    w32(ram, R(15) + 8u, R(2));
    R(4) = R(14);                                  /* the call's delay slot */
    if (!vf3_guest_call(s, ram, QUANTIZE, CONT_QUANT_2)) return 0;

    /* ---- the epilogue: the frame, pr, then the four floats and r14 ---- */
    R(15) += WRAP_FRAME;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    vf3_matrix_load(s, ram, 12, R(15)); R(15) += w;
    vf3_matrix_load(s, ram, 13, R(15)); R(15) += w;
    vf3_matrix_load(s, ram, 14, R(15)); R(15) += w;
    vf3_matrix_load(s, ram, 15, R(15)); R(15) += w;
    s->pc = R(16);
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    return ram->oob == 0;
}

int vf3_pose_turns_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t w = 4u;          /* the quantizer pushes r registers only */

    /* ---- the prologue: r14, r13, r12, r11, r10, r9, r8, then the frame ---- */
    R(15) -= w;
    w32(ram, R(15), R(14));
    R(3) = R(5);
    R(15) -= w;
    w32(ram, R(15), R(13));
    R(3) += 4u;                     /* the frame's first pointer: the vector's y */
    R(15) -= w;
    w32(ram, R(15), R(12));
    R(12) = R(5);
    R(2) = R(12);
    R(2) += 8u;                     /* the vector's z */
    R(15) -= w;
    w32(ram, R(15), R(11));
    R(15) -= w;
    w32(ram, R(15), R(10));
    R(15) -= w;
    w32(ram, R(15), R(9));
    R(15) -= w;
    w32(ram, R(15), R(8));

    /* ---- the three floats, truncated ---- */
    vf3_matrix_load(s, ram, 6, R(12));             /* fr6 = x */
    R(15) -= QUANT_FRAME;
    w32(ram, R(15) + 8u, R(3));                    /* the frame's +8: the y pointer */
    R(53) = vf3_fpu_ftrc(F(6));                    /* x, truncated */
    vf3_matrix_load(s, ram, 4, R(3));              /* fr4 = y */
    w32(ram, R(15) + 4u, R(2));                    /* the frame's +4: the z pointer */
    vf3_matrix_load(s, ram, 5, R(2));              /* fr5 = z */
    R(7) = R(53);
    R(53) = vf3_fpu_ftrc(F(4));                    /* y, truncated */
    R(7) &= 0xffffu;
    R(13) = R(53);
    R(53) = vf3_fpu_ftrc(F(5));                    /* z, truncated */
    R(7) = (uint32_t)(int32_t)(int16_t)R(7);
    R(1) = R(53);
    w32(ram, R(15), R(1));                         /* the frame's +0: z, truncated */

    /* ---- the Euler canonicalisation: |x| > 0x5000 ---- */
    R(3) = pool_half(ram, POOL_BAND_HI);
    R(14) = pool_word(ram, POOL_CANON_ADD);        /* 0x8000 */
    set_t(s, (int32_t)R(7) > (int32_t)R(3));
    R(11) = R(1) & 0xffffu;                        /* the delay slot */
    if (R(17) & 1u) goto canonicalise;
    R(0) = pool_half(ram, POOL_BAND_LO);
    set_t(s, (int32_t)R(7) >= (int32_t)R(0));
    if (R(17) & 1u) goto quantised;

canonicalise:
    R(3) = R(14);
    R(3) -= R(13);
    R(13) = R(3);                                  /* y = 0x8000 - y */
    R(11) += R(14);                                /* z += 0x8000 */
    R(7) += R(14);                                 /* x += 0x8000 */

quantised:
    R(7) &= 0xffffu;
    R(0) = ACTOR_FLAGS;
    R(9) = (uint32_t)(int32_t)(int16_t)R(7);       /* x'' */
    R(11) &= 0xffffu;
    R(14) = (uint32_t)(int32_t)(int16_t)R(11);     /* z'' */
    w32(ram, R(15), R(11));                        /* the frame's +0: z'' */
    R(7) = pool_half(ram, R(4) + R(0));            /* actor's halfword at +0x3e */
    R(0) = pool_half(ram, POOL_ACTOR_HI);
    R(7) &= 0xffffu;
    R(10) = pool_half(ram, R(4) + R(0));           /* (i16)[actor+0x1FB0] */
    R(0) += 0xfffffffcu;                           /* 0x1FAC */
    R(8) = pool_half(ram, R(4) + R(0));            /* (i16)[actor+0x1FAC] */
    R(0) = pool_half(ram, POOL_ACTOR_LO);
    R(10) &= 0xffffu;
    R(10) += 1u;                                   /* the band's high bound */
    R(11) = pool_half(ram, R(4) + R(0));           /* (i16)[actor+0x1A00] */
    set_t(s, R(7) == R(10));
    R(8) += 1u;
    R(11) &= 0xffffu;
    R(3) = R(11);
    R(3) -= 8u;                                    /* the band's low bound */
    w32(ram, R(15), R(3));
    R(11) += 1u;                                   /* the delay slot */

    /* ---- the band's two edges ---- */
    if (R(17) & 1u) goto write_quantised;
    set_t(s, R(7) == R(3));
    if (!(R(17) & 1u)) goto after_band;
write_quantised:
    R(0) = R(13);
    vf3_mem_set_u16(ram, R(6), (uint16_t)R(9));
    vf3_mem_set_u16(ram, R(6) + 2u, (uint16_t)R(0));
    R(0) = R(14);
    vf3_mem_set_u16(ram, R(6) + 4u, (uint16_t)R(0));

    /* ---- the band's inside ---- */
after_band:
    set_t(s, (int32_t)R(7) > (int32_t)R(10));
    if (!(R(17) & 1u)) goto inside_band;
    set_t(s, (int32_t)R(7) >= (int32_t)R(8));
    if (!(R(17) & 1u)) goto kind_gate;
inside_band:
    R(3) = vf3_mem_u32(ram, R(15));
    set_t(s, (int32_t)R(7) > (int32_t)R(3));
    if (!(R(17) & 1u)) goto done;
    set_t(s, (int32_t)R(7) >= (int32_t)R(11));
    if (R(17) & 1u) goto done;

    /* ---- the kind-3 negation ---- */
kind_gate:
    R(0) = ACTOR_KIND;
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + R(0));
    R(0) &= 0xffu;
    set_t(s, R(0) == 3u);
    if (!(R(17) & 1u)) goto done;
    R(4) = R(14);
    set_t(s, (int32_t)R(4) >= 0);
    R(6) = 0u - R(14);                             /* the delay slot */
    if (R(17) & 1u) goto negate_limit;
    R(4) = R(6);
negate_limit:
    R(3) = pool_half(ram, POOL_NEG_LIMIT);
    set_t(s, (int32_t)R(4) > (int32_t)R(3));
    if (!(R(17) & 1u)) goto done;
    R(14) = R(6);

    /* ---- the quantised values go back into the source vector ---- */
done:
    R(53) = R(9);
    R(5) += 12u;
    R(0) = R(5);
    F(3) = vf3_fpu_float(R(53), R(18));
    vf3_matrix_store(s, ram, 3, R(12));
    R(53) = R(13);
    R(3) = vf3_mem_u32(ram, R(15) + 8u);
    F(3) = vf3_fpu_float(R(53), R(18));
    vf3_matrix_store(s, ram, 3, R(3));
    R(3) = vf3_mem_u32(ram, R(15) + 4u);
    R(15) += QUANT_FRAME;
    R(53) = R(14);
    F(3) = vf3_fpu_float(R(53), R(18));
    vf3_matrix_store(s, ram, 3, R(3));

    /* ---- the epilogue: r8..r13, then r14 in the rts's delay slot ---- */
    R(8) = vf3_mem_u32(ram, R(15)); R(15) += w;
    R(9) = vf3_mem_u32(ram, R(15)); R(15) += w;
    R(10) = vf3_mem_u32(ram, R(15)); R(15) += w;
    R(11) = vf3_mem_u32(ram, R(15)); R(15) += w;
    R(12) = vf3_mem_u32(ram, R(15)); R(15) += w;
    R(13) = vf3_mem_u32(ram, R(15)); R(15) += w;
    s->pc = R(16);
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += w;
    return ram->oob == 0;
}
