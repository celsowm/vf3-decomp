/* strip_vertex_lit.c - 0x8C048F60  transform a lit vertex strip and write it to the store queue.
 *
 *   r4 -> the strip: a vertex count word (r9), then records of 32 bytes: bit 0 of a record's first word set =
 *   the vertex data is inline, otherwise word 1 is an offset (from record + 8) to it. A vertex is (x, y, z, w)
 *   in FR4..7, a texture pair in FR0 / FR1 and two attribute words (r1 / r2). r6 is the store-queue write
 *   pointer (vertices are written backwards, so r6 is moved up before and down while writing), r5 advances 32
 *   per vertex, r8 selects the specular power ladder (4 .. 40, 0 = no specular), FV12 is the light vector,
 *   FV8 the second vector (the half vector), FR15 the ambient term the caller left.
 *
 *   FPSCR.SZ is 1 for the whole body (set on entry, cleared in the rts delay slot), so every FRn load or
 *   store moves a pair.
 *
 *   Per vertex: FR4..7 through XMTRX (w forced to 1), FR7 = 1 / x', FR3 = FV12 . FV0 (diffuse), FR11 = FV0 . FV8
 *   (a cosine) and FR2 = ambient (+ the diffuse term when it is positive). With r8 and a positive cosine FR11
 *   is squared, doubled and reduced by 1; when that is still above 0 it is squared again, added to FR3 and the
 *   ladder (a braf into 4 byte slots at 0x8C04903C + r8) multiplies FR3 / FR11 the number of times its slot
 *   encodes. The vertex goes out as FR2/FR3, r2, r1, FR6 * FR7 / FR7, FR4 / FR5 * FR7; three vertices are read
 *   per pass (r3 counts them) and r6 itself is written over the last one's first word and prefetched. After the
 *   third a -1 word closes the group and the vertex count in r9 counts down. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SZ_BIT = 0x00100000u, PR_BIT = 0x00080000u, SQ_REGION_MASK = 0xFC000000u, SQ_REGION = 0xE0000000u,
       ONE = 0x3F800000u, MAX_STEPS = 1000000, LADDER_MIN = 4, LADDER_MAX = 40 };

#define FPUL        (s->v[VF3_REG_FPUL])
#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define IS_T        (R(VF3_REG_SR) & 1u)
#define PREF(a)     pref_sq(ram, (a))

static void pref_sq(const vf3_ram_map *ram, uint32_t a)
{
    if ((a & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, a);
}

/* fmov @r14+,FRn (a pair, SZ = 1 throughout) */
static void fld_post14(vf3_matrix_state *s, const vf3_ram_map *ram, int n)
{
    F(n) = m32(ram, R(14));
    F(n + 1) = m32(ram, R(14) + 4);
    R(14) += 8;
}

/* fmov FRn,@-r6 (a pair) */
static void fst_pre6(vf3_matrix_state *s, const vf3_ram_map *ram, int n)
{
    R(6) -= 8;
    w32(ram, R(6), F(n));
    w32(ram, R(6) + 4, F(n + 1));
}

static void push6(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t v)
{
    R(6) -= 4;
    w32(ram, R(6), v);
}

/* The ladder slot r8 selects: the multiplies its chain of branches runs before it rejoins at 0x8C048FF4. */
static void ladder(vf3_matrix_state *s, uint32_t slot)
{
    switch (slot) {
    case 4:  break;
    case 8:  FMUL(3, 3); break;
    case 12: FMUL(11, 11); FMUL(3, 11); break;
    case 16: FMUL(3, 3); FMUL(3, 3); break;
    case 20: FMUL(11, 11); FMUL(11, 11); FMUL(3, 11); break;
    case 24: FMUL(11, 11); FMUL(3, 11); FMUL(3, 11); break;
    case 28: FMUL(11, 11); FMUL(3, 11); FMUL(11, 11); FMUL(3, 11); break;
    case 32: FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); break;
    case 36: FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); break;
    default: FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); FMUL(3, 3); break;   /* 40 */
    }
}

int vf3_strip_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & (SZ_BIT | PR_BIT))) return 0;
    if (R(8) != 0 && (R(8) < LADDER_MIN || R(8) > LADDER_MAX || (R(8) & 3u))) return 0;
    int steps = MAX_STEPS;

    R(3) = 3;
    R(9) = m32(ram, R(4));
    R(4) += 4;
    R(6) -= 32;
    R(0) = m32(ram, R(4));
    R(VF3_REG_FPSCR) ^= SZ_BIT;
    SET_T((R(0) & 1u) == 0);
    R(14) = R(4);
    R(4) += 32;                                         /* bf/s delay slot */
    if (IS_T) {                                         /* out-of-line record */
        R(14) = m32(ram, R(14) + 4);
        R(4) -= 24;
        R(14) += R(4);
    }

load_x:                                                 /* 8C048F78 */
    if (--steps < 0) return 0;
    fld_post14(s, ram, 4);
load_z:                                                 /* 8C048F7A */
    fld_post14(s, ram, 6);
    F(2) = 0;
tail_w:                                                 /* 8C048F7E */
    FADD(2, 7);
    F(7) = ONE;
    R(6) += 64;
    F(3) = 0;
    R(5) += 32;
    fld_post14(s, ram, 0);
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(4), R(VF3_REG_FPSCR), &F(4))) return 0;
    F(11) = 0;
    R(1) = m32(ram, R(14));
    R(14) += 4;
    R(3) -= 1;
    SET_T(R(3) == 0);
    R(2) = m32(ram, R(14));
    R(14) += 4;
    R(0) = m32(ram, R(4));                              /* bt/s delay slot */
    if (IS_T) {                                         /* the third vertex of the group */
        if (!vf3_fpu_fipr(&F(12), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
        F(7) = ONE;
        FDIV(7, 4);
        goto next_inline;
    }
    if (!vf3_fpu_fipr(&F(12), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    R(14) = m32(ram, R(4) + 4);
    SET_T((R(0) & 1u) == 0);
    F(7) = ONE;
    FDIV(7, 4);                                         /* bf/s delay slot */
    if (!IS_T) goto next_inline;
    R(4) += 8;                                          /* the next record is out of line */
    PREF(R(4));
    {
        const int lit = GT(11, 3);
        R(14) += R(4);
        FPUL = F(15);
        if (!vf3_fpu_fipr(&F(0), &F(8), R(VF3_REG_FPSCR), &F(11))) return 0;
        PREF(R(14));
        F(2) = FPUL;
        if (lit) FADD(2, 3);
    }
    goto shade;

next_inline:                                            /* 8C048FC2 */
    R(14) = R(4);
    R(4) += 32;
    {
        const int lit = GT(11, 3);
        PREF(R(4));
        if (!vf3_fpu_fipr(&F(0), &F(8), R(VF3_REG_FPSCR), &F(11))) return 0;
        FPUL = F(15);
        F(2) = FPUL;
        if (lit) FADD(2, 3);
    }

shade:                                                  /* 8C048FD4 */
    F(3) = 0;
    if (R(8) != 0) {
        const int positive = GT(3, 11);
        F(0) = ONE;
        FMUL(11, 11);
        if (positive) {
            FADD(11, 11);
            const int above_one = GT(0, 11);
            FSUB(11, 0);
            if (above_one) {
                FMUL(11, 11);
                FADD(3, 11);
                ladder(s, R(8));
            }
            R(0) = R(8) + 72;                           /* braf offset (the slot's address minus 0x8C048FF4) */
        }
    }

emit:                                                   /* 8C048FF4 */
    fst_pre6(s, ram, 2);
    FMUL(6, 7);
    push6(s, ram, R(2));
    FMUL(5, 7);
    push6(s, ram, R(1));
    SET_T(R(3) == 0);
    fst_pre6(s, ram, 6);
    fst_pre6(s, ram, 4);                                /* bt/s delay slot */
    if (!IS_T) {
        w32(ram, R(6), R(6));
        PREF(R(6));
        fld_post14(s, ram, 4);                          /* bf/s delay slot */
        if (--steps < 0) return 0;
        goto load_z;
    }

    R(1) = 0xFFFFFFFFu;                                 /* 8C049010 */
    w32(ram, R(6), R(1));
    R(9) -= 1;
    SET_T(R(9) == 0);
    PREF(R(6));
    if (IS_T) {
        R(4) -= 32;
        R(6) += 32;
        R(VF3_REG_FPSCR) ^= SZ_BIT;                     /* rts delay slot */
        s->pc = R(VF3_REG_PR);
        return 1;
    }
    R(0) = m32(ram, R(14));
    R(3) = 3;
    fld_post14(s, ram, 4);
    SET_T((R(0) & 1u) == 0);
    fld_post14(s, ram, 6);
    FSUB(2, 2);                                         /* bf/s delay slot */
    if (!IS_T) goto tail_w;
    FPUL = F(5);
    R(4) -= 24;
    R(14) = FPUL;
    R(14) += R(4);
    goto load_x;
}
