/* clip_near_triangle.c - 0x8C04A320  project triangles and write them to the store queue, clipping against the near
 * plane.
 *
 *   r4 -> a stream: a point count, then that many triangles (three point records each, the point record layout of
 *   vertex_classify.c: inline at +0 with a 32 byte stride or an offset to out-of-line x, y, z with an 8 byte
 *   stride); after the last triangle a word that is > 0 with bit 7 clear continues the stream with a new count,
 *   anything else ends it.
 *   r5 counts the 64 byte vertex blocks written, r6 is the store-queue write pointer (0xE0.. area, flushed with
 *   pref every 32 bytes), r7 holds a constant word that goes into the last word of the second vertex block (1.0
 *   in the callers) and r12 the near-plane threshold (a float, kept in FR2).
 *
 *   FPSCR.SZ is 1 for the whole body, so every fmov between even registers moves a register pair and every
 *   fmov to or from memory moves two words; the few stretches with SZ = 0 are marked. Per triangle each point
 *   goes through XMTRX as (x, y, z, 1): the point's four results live in FR4..7 / FR8..11 / FR12..15, where
 *   FR4 / FR8 / FR12 end up holding the depth to compare (the transformed w plus zero) and FR7 / FR11 / FR15 the
 *   reciprocal of the transformed x.
 *
 *   The three depths are tested against the threshold, one bit per point (first point is the high bit):
 *     0        every point is in front: the triangle is written as is (a 96 byte block plus a 32 byte trailer).
 *     7        every point is behind the plane: nothing is written.
 *     1        the first point is the only one behind: the 4f2 branch emits the clipped quad pieces.
 *     2..6     the point order is rotated (a braf over the 16 byte permutation stubs) so the same two emitters
 *              serve every case: 4, 6 -> the 4f2 emitter, 3, 5, 6 -> the 48a emitter.
 *   Each emitter writes the cut vertices by interpolating along the edge toward the threshold:
 *   t = (threshold - depth_a) / (depth_b - depth_a), then position += t * delta.
 *
 *   After the stream the 'trailer' pair (words at sp + 20 / 24 / 28 of the caller's frame: a header word, a
 *   second word and a third that is or-ed into the second) is written once, but only if something was emitted
 *   (r11 != 0). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SZ_BIT = 0x00100000u, SQ_REGION_MASK = 0xFC000000u, SQ_REGION = 0xE0000000u, ONE = 0x3F800000u,
       MAX_STEPS = 1000000 };

#define FPUL        (s->v[VF3_REG_FPUL])
#define SZ_ON       ((R(VF3_REG_FPSCR) & SZ_BIT) != 0)
#define FSCHG()     (R(VF3_REG_FPSCR) ^= SZ_BIT)
#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define IS_T        (R(VF3_REG_SR) & 1u)
#define FLDI0(n)    (F(n) = 0)
#define FLDI1(n)    (F(n) = ONE)
#define FLOAT(n)    set_fl(s, (n), (float)(int32_t)FPUL)
#define FLDS(m)     (FPUL = F(m))
#define FSTS(n)     (F(n) = FPUL)
#define PREF(a)     pref_sq(ram, (a))

static void pref_sq(const vf3_ram_map *ram, uint32_t a)
{
    if ((a & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, a);
}

/* fmov FRm,FRn - a register pair when SZ = 1 */
static void fmov_reg(vf3_matrix_state *s, int d, int m)
{
    const uint32_t a = F(m), b = F(m + 1);
    F(d) = a;
    if (SZ_ON) F(d + 1) = b;
}

/* fmov FRm,@-r6 */
static void fst_pre(vf3_matrix_state *s, const vf3_ram_map *ram, int n)
{
    R(6) -= SZ_ON ? 8u : 4u;
    w32(ram, R(6), F(n));
    if (SZ_ON) w32(ram, R(6) + 4, F(n + 1));
}

/* fmov FRm,@(r0,r6) and fmov FRm,@r6 */
static void fst_at(vf3_matrix_state *s, const vf3_ram_map *ram, int n, uint32_t addr)
{
    w32(ram, addr, F(n));
    if (SZ_ON) w32(ram, addr + 4, F(n + 1));
}

/* fmov @r14+,FRn */
static void fld_post14(vf3_matrix_state *s, const vf3_ram_map *ram, int n)
{
    F(n) = m32(ram, R(14));
    if (SZ_ON) F(n + 1) = m32(ram, R(14) + 4);
    R(14) += SZ_ON ? 8u : 4u;
}

/* r14 = the record, r0 = its flag word, r4 on to the next record */
static void begin_point(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(14) = R(4);
    R(0) = m32(ram, R(4));
    R(4) += 32;
}

/* tst #1,r0; pref @r4; an out-of-line record redirects r14 to its coordinates and moves r4 back to +8 */
static void resolve_point(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    SET_T((R(0) & 1u) == 0);
    PREF(R(4));
    if (IS_T) {
        R(14) = m32(ram, R(14) + 4);
        R(4) -= 24;
        R(14) += R(4);
    }
}

/* ftrv xmtrx,fv<n> */
static int transform(vf3_matrix_state *s, int n)
{
    return vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(n), R(VF3_REG_FPSCR), &F(n));
}

/* rotcl r0: r0 = (r0 << 1) | T, T = the bit shifted out */
static void rotcl_r0(vf3_matrix_state *s)
{
    const uint32_t out = R(0) >> 31;
    R(0) = (R(0) << 1) | (R(VF3_REG_SR) & 1u);
    SET_T(out);
}

int vf3_clip_near_triangle_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || SZ_ON) return 0;
    const uint32_t sp = R(15);
    int guard = MAX_STEPS;

    FPUL = R(12);
    R(0) = 1;
    FSTS(2);
    FSCHG();                                            /* SZ = 1 from here */
    FPUL = R(0);
    R(11) = 0;
    R(3) = m32(ram, R(4));
    R(4) += 4;

next_triangle:
    if (--guard < 0) return 0;
    begin_point(s, ram);
    FLDI0(1);
    resolve_point(s, ram);
    fld_post14(s, ram, 4);
    fld_post14(s, ram, 6);
    FLOAT(7);

    begin_point(s, ram);
    if (!transform(s, 4)) return 0;
    resolve_point(s, ram);
    fld_post14(s, ram, 8);
    FADD(1, 7);
    FLDI1(7);
    FDIV(7, 4);
    fld_post14(s, ram, 10);
    FLOAT(11);
    FLDI0(4);
    FADD(4, 1);

    begin_point(s, ram);
    if (!transform(s, 8)) return 0;
    FLDI0(1);
    resolve_point(s, ram);
    FADD(1, 11);
    FLDI1(11);
    FDIV(11, 8);
    fld_post14(s, ram, 12);
    fld_post14(s, ram, 14);
    FLOAT(15);
    FLDI0(8);
    FADD(8, 1);
    if (!transform(s, 12)) return 0;
    FLDI0(1);
    FADD(1, 15);
    FLDI1(15);
    FDIV(15, 12);
    FLDI0(12);
    FADD(12, 1);

    /* one outcode bit per point: depth > threshold */
    R(0) = 0;
    SET_T(GT(2, 4));  rotcl_r0(s);
    SET_T(GT(2, 8));  rotcl_r0(s);
    SET_T(GT(2, 12)); rotcl_r0(s);
    SET_T((R(0) & 7u) == 0);
    if (!IS_T) goto clipped;

    /* all three points in front: the triangle as it is */
    FLDS(11);
    R(0) = 24;
    R(6) += 16;
    FMUL(6, 7);
    FMUL(5, 7);
    R(1) = FPUL;
    fst_pre(s, ram, 6);
    FMUL(14, 15);
    fst_pre(s, ram, 4);
    FMUL(13, 15);
    fst_at(s, ram, 12, R(6) + R(0));
    FMUL(10, 11);
    R(0) = 32;
    FMUL(9, 11);
    fst_at(s, ram, 14, R(6) + R(0));
    R(0) = 0xFFFFFFFFu;
    w32(ram, R(6) + 24, R(1));
    FSCHG();                                            /* SZ = 0 */
    w32(ram, R(6), R(0));
    R(0) = 16;
    fst_at(s, ram, 9, R(6) + R(0));
    R(0) = 20;
    fst_at(s, ram, 10, R(6) + R(0));
    R(5) += 64;
    PREF(R(6));
    R(6) += 32;
    R(11) = 1;
    FSCHG();                                            /* SZ = 1 */
    FPUL = R(11);
    PREF(R(6));
    R(6) += 32;

next_stream_word:                                       /* 8C04A3F2 */
    R(3) -= 1;
    SET_T(R(3) == 0);
    R(0) = m32(ram, R(4));
    if (!IS_T) goto next_triangle;
    SET_T((int32_t)R(0) > 0);
    if (IS_T) {
        SET_T((R(0) & 128u) == 0);
        R(4) += 4;
        R(3) = m32(ram, R(4));                          /* delay slot of the bf/s: runs on both paths */
        R(4) += 4;
        if (!IS_T) goto next_triangle;
        R(4) -= 8;
    }
    SET_T(R(11) == 0);
    FSCHG();                                            /* SZ = 0 */
    if (IS_T) {
        R(6) -= 32;
        R(5) -= 32;
        goto done;
    }
    PREF(R(6));
    R(6) += 32;
    R(0) = m32(ram, sp + 20);
    R(5) += 64;
    R(1) = m32(ram, sp + 24);
    R(2) = m32(ram, sp + 28);
    PREF(R(6));
    R(6) -= 96;
    w32(ram, R(6), R(0));
    R(0) |= 64;
    w32(ram, R(6) + 4, R(1));
    R(2) |= R(1);
    PREF(R(6));
    R(6) += 32;
    w32(ram, R(6), R(0));
    w32(ram, R(6) + 4, R(2));
    PREF(R(6));
    R(6) += 96;
    goto done;

clipped: {                                              /* 8C04A438 */
        const uint32_t outcode = R(0);
        SET_T(outcode == 7);
        R(0) -= 2;
        if (IS_T) goto next_stream_word;                /* all behind */
        R(0) <<= 2;
        SET_T((int32_t)R(0) == -4);
        R(0) <<= 2;
        if (IS_T) goto emit_one_behind;                 /* outcode 1 */
        fmov_reg(s, 2, 6);                              /* delay slot of the braf */
        switch (outcode) {                              /* the permutation stubs at 8C04A44A.. */
        case 2:
            fmov_reg(s, 0, 4); fmov_reg(s, 6, 14); fmov_reg(s, 4, 12); fmov_reg(s, 14, 10);
            fmov_reg(s, 12, 8); fmov_reg(s, 10, 2); fmov_reg(s, 8, 0);
            goto emit_one_behind;
        case 3:
            fmov_reg(s, 0, 4); fmov_reg(s, 6, 10); fmov_reg(s, 4, 8); fmov_reg(s, 10, 14);
            fmov_reg(s, 8, 12); fmov_reg(s, 14, 2); fmov_reg(s, 12, 0);
            goto emit_two_behind;
        case 4:
            fmov_reg(s, 0, 4); fmov_reg(s, 6, 10); fmov_reg(s, 4, 8); fmov_reg(s, 10, 14);
            fmov_reg(s, 8, 12); fmov_reg(s, 14, 2); fmov_reg(s, 12, 0);
            goto emit_one_behind;
        case 5:
            fmov_reg(s, 0, 4); fmov_reg(s, 6, 14); fmov_reg(s, 4, 12); fmov_reg(s, 14, 10);
            fmov_reg(s, 12, 8); fmov_reg(s, 10, 2); fmov_reg(s, 8, 0);
            goto emit_two_behind;
        case 6:
            goto emit_two_behind;
        default:
            return 0;
        }
    }

emit_two_behind:                                        /* 8C04A48A */
    FPUL = R(12);
    R(6) += 40;
    fmov_reg(s, 2, 14);
    FMUL(14, 15);
    fmov_reg(s, 0, 12);
    FMUL(13, 15);
    FSTS(0);
    FSUB(0, 12);
    FSUB(4, 12);
    fst_pre(s, ram, 14);
    FSUB(6, 2);
    fst_pre(s, ram, 12);
    FSUB(5, 1);
    fmov_reg(s, 14, 0);
    FDIV(0, 4);
    FSUB(8, 12);
    fmov_reg(s, 12, 2);
    FSUB(10, 2);
    FSUB(9, 1);
    FMAC(2, 6);
    FMAC(1, 5);
    FPUL = R(7);
    FDIV(14, 8);
    FSTS(3);
    FMUL(2, 3);
    R(6) -= 8;
    FMUL(1, 3);
    R(0) = 0xFFFFFFFFu;
    fst_pre(s, ram, 2);
    fst_pre(s, ram, 0);
    FSCHG();                                            /* SZ = 0 */
    fmov_reg(s, 0, 14);
    FMAC(12, 10);
    w32(ram, R(6), R(0));
    FMAC(15, 9);
    R(6) += 28;
    fst_pre(s, ram, 3);
    FMUL(12, 3);
    FMUL(15, 3);
    fst_pre(s, ram, 12);
    fst_pre(s, ram, 15);
    PREF(R(6));
    FSCHG();                                            /* SZ = 1 */
    R(6) += 16;
    FPUL = R(12);
    R(11) = 1;
    FSTS(2);
    R(5) += 64;
    FPUL = R(11);
    PREF(R(6));
    R(6) += 32;
    goto next_stream_word;

emit_one_behind:                                        /* 8C04A4F2 */
    FPUL = R(12);
    R(6) += 40;
    fmov_reg(s, 2, 6);
    FMUL(6, 7);
    fmov_reg(s, 0, 4);
    FMUL(5, 7);
    FSTS(0);
    FSUB(0, 4);
    FLDS(12);
    FSTS(15);
    FSUB(15, 4);
    FLDS(14);
    fst_pre(s, ram, 6);
    fst_pre(s, ram, 4);
    FDIV(0, 15);
    fmov_reg(s, 6, 10);
    FMUL(6, 7);
    fmov_reg(s, 4, 8);
    FMUL(5, 7);
    R(6) -= 8;
    fst_pre(s, ram, 6);
    R(0) = 0xFFFFFFFFu;
    fst_pre(s, ram, 4);
    FSCHG();                                            /* SZ = 0 */
    w32(ram, R(6), R(0));
    FSTS(6);
    FSUB(6, 2);
    FLDS(13);
    R(0) = 4;
    FSTS(5);
    FSUB(5, 1);
    R(6) += 16;
    FMAC(2, 6);
    FPUL = R(7);
    FMAC(1, 5);
    FSTS(0);
    FMUL(2, 0);
    w32(ram, R(6) + 8, R(7));
    FMUL(1, 0);
    fst_at(s, ram, 2, R(6) + R(0));
    fst_at(s, ram, 1, R(6));
    R(6) -= 16;
    PREF(R(6));
    FSCHG();                                            /* SZ = 1 */
    R(6) += 32;
    R(5) += 64;
    PREF(R(6));
    R(6) += 32;
    FPUL = R(12);
    R(6) += 40;
    fmov_reg(s, 2, 10);
    FMUL(10, 11);
    fmov_reg(s, 0, 8);
    FMUL(9, 11);
    FSTS(0);
    FSUB(0, 8);
    FLDS(12);
    FSTS(15);
    FSUB(15, 8);
    fst_pre(s, ram, 10);
    fst_pre(s, ram, 8);
    FDIV(0, 15);
    FSCHG();                                            /* SZ = 0 */
    w32(ram, R(6), R(7));
    FSUB(14, 2);
    R(0) = 4;
    FSUB(13, 1);
    R(6) -= 20;
    FMAC(2, 14);
    FPUL = R(7);
    FMAC(1, 13);
    FSTS(0);
    FMUL(2, 0);
    w32(ram, R(6) + 8, R(7));
    FMUL(1, 0);
    fst_at(s, ram, 2, R(6) + R(0));
    fst_at(s, ram, 1, R(6));
    R(6) -= 4;
    PREF(R(6));
    FSCHG();                                            /* SZ = 1 */
    R(6) += 32;
    FPUL = R(12);
    R(11) = 1;
    FSTS(2);
    R(5) += 64;
    FPUL = R(11);
    PREF(R(6));
    R(6) += 32;
    goto next_stream_word;

done:
    s->pc = R(VF3_REG_PR);
    return 1;
}
