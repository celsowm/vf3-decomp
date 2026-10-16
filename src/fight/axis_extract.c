/* axis_extract.c - 0x8C03EE40  derive the camera/body axes from a direction table through XMTRX.
 *
 *   no arguments: reads the three-by-four float table at 0x0C0EA624 and writes the result to the
 *   vector block at 0x0C1A58A0 (the body continues at 0x8C03EE90 with r4 = block, r5 = table):
 *
 *       block[+16..+24] = (t0, t1, t2) * M^T              (a transformed copy of the first row)
 *       block[+0..+8]   = normalise((t0, t1, t3) * M^T)   (the unit axis)
 *
 * M^T is the 3x3 part of XMTRX transposed. The original gets it by swapping the matrix's
 * off-diagonal pairs (1,4) (2,8) (6,9) through FPUL in the other FP bank (FRCHG) and swaps them
 * back at the end, so XMTRX is unchanged on exit; here the transposed copy is built directly. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum { BLOCK = 0x0C1A58A0u, TABLE = 0x0C0EA624u, ROW_COPY = 16, FR_BIT = 0x00200000u };

static uint32_t *fr_bank(vf3_matrix_state *s) { return &VF3_FR(s, 0); }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

/* FRCHG: the two register banks trade places */
static void frchg(vf3_matrix_state *s)
{
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    for (int i = 0; i < 16; ++i) { const uint32_t t = fr[i]; fr[i] = xf[i]; xf[i] = t; }
    s->v[VF3_REG_FPSCR] ^= FR_BIT;
}

/* FLDS FRa,FPUL / FMOV FRb,FRa / FSTS FPUL,FRb in the current FR bank */
static void swap_through_fpul(vf3_matrix_state *s, int a, int b)
{
    uint32_t *fr = fr_bank(s);
    s->v[VF3_REG_FPUL] = fr[a];
    fr[a] = fr[b];
    fr[b] = s->v[VF3_REG_FPUL];
}

int vf3_axis_extract_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    static const int pairs[3][2] = { { 1, 4 }, { 2, 8 }, { 6, 9 } };

    s->v[4] = BLOCK;
    s->v[5] = TABLE;
    fr[3] = 0;                                      /* w of the first row */
    frchg(s);
    for (int i = 0; i < 3; ++i) swap_through_fpul(s, pairs[i][0], pairs[i][1]);
    frchg(s);                                       /* XMTRX is now M^T (3x3 part) */

    for (int i = 0; i < 3; ++i) fr[i] = vf3_mem_u32(ram, TABLE + 4u * (uint32_t)i);
    fr[6] = vf3_mem_u32(ram, TABLE + 12u);
    fr[4] = vf3_mem_u32(ram, TABLE);
    fr[7] = 0;
    if (!vf3_fpu_ftrv(xf_bank(s), fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[5] = vf3_mem_u32(ram, TABLE + 4u);
    s->v[0] = ROW_COPY;
    if (!vf3_fpu_ftrv(xf_bank(s), fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, BLOCK + ROW_COPY + 4u * (uint32_t)i, fr[i]);

    frchg(s); swap_through_fpul(s, 1, 4); frchg(s);  /* put the pairs back, one per bank visit */
    fr[7] = 0;
    if (!vf3_fpu_fipr(fr + 4, fr + 4, s->v[VF3_REG_FPSCR], fr + 7)) return 0;
    frchg(s); swap_through_fpul(s, 2, 8); frchg(s);
    if (!vf3_fpu_fsrra(fr[7], s->v[VF3_REG_FPSCR], fr + 7)) return 0;
    frchg(s); swap_through_fpul(s, 6, 9); frchg(s);

    for (int i = 0; i < 3; ++i) vf3_fr_set(s, 4 + i, vf3_f_mul(s, vf3_fr_get(s, 4 + i), vf3_fr_get(s, 7)));
    s->v[0] = 8;
    s->v[5] = TABLE + 8u;
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, BLOCK + 4u * (uint32_t)i, fr[4 + i]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
