/* matrix_lib.c - the 4x4 matrix helpers the engine keeps XMTRX in (SH-4 0x8C03B620..0x8C03C1FE).
 *
 * Matrices are 16 floats, column-major: M[4*c + r] is row r of column c, so a
 * column is one FV register and `ftrv xmtrx,fvN` is  fvN = XMTRX * fvN.
 * The back bank (XF0..XF15) holds the current transform. The engine keeps a
 * matrix stack whose top pointer lives at *(0x0C19D2E4 + 8).
 *
 *   0x8C03B620  matrix_store    write XMTRX to the matrix at r4 (r4 = 0: the stack top)
 *   0x8C03C0E0  matrix_concat   XMTRX = XMTRX * M(r4), also leaves FR/XF swapped (frchg)
 *   0x8C03C1C0  matrix_premul   XMTRX = M(r4) * XMTRX
 *
 * r4 comes back 64 bytes further (store: at the start of the matrix, r0 too).
 * The routines spill part of the FR bank on the stack; those words are dead but the
 * port writes them too so whole-RAM comparisons stay exact.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define MATRIX_WORDS      16
#define MATRIX_BYTES      64u
#define MATRIX_STACK_PTR  0x0C19D2EC            /* *(0x0C19D2E4 + 8) */

static uint32_t *fr_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_FR0]; }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

static void push_word(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t value)
{
    s->v[15] -= 4;
    vf3_mem_set_u32(ram, s->v[15], value);
}

/* 0x8C03B620 */
int vf3_matrix_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t dest = s->v[4];
    if (dest == 0) dest = vf3_mem_u32(ram, MATRIX_STACK_PTR);
    const uint32_t *xf = xf_bank(s);
    for (int i = 0; i < MATRIX_WORDS; ++i) vf3_mem_set_u32(ram, dest + 4u * i, xf[i]);
    s->v[0] = dest;
    s->v[4] = dest;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C0E0 */
int vf3_matrix_concat_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    uint32_t m[MATRIX_WORDS], out[MATRIX_WORDS];
    const uint32_t fr12 = fr[12];

    push_word(s, ram, fr[15]);
    push_word(s, ram, fr[14]);
    push_word(s, ram, fr[13]);
    s->v[VF3_REG_FPUL] = fr12;

    for (int i = 0; i < MATRIX_WORDS; ++i) m[i] = vf3_mem_u32(ram, s->v[4] + 4u * i);
    s->v[4] += MATRIX_BYTES;
    for (int c = 0; c < 4; ++c)
        if (!vf3_fpu_ftrv(xf_bank(s), &m[4 * c], s->v[VF3_REG_FPSCR], &out[4 * c])) return 0;

    /* frchg: the products become the new XMTRX and the old XMTRX shows in FR0..FR15 */
    for (int i = 0; i < MATRIX_WORDS; ++i) fr[i] = xf_bank(s)[i];
    for (int i = 0; i < MATRIX_WORDS; ++i) xf_bank(s)[i] = out[i];
    s->v[VF3_REG_FPSCR] ^= 0x00200000u;

    /* the caller's FR12..FR15 are put back into the (new) FR bank */
    fr[12] = fr12;
    for (int i = 13; i <= 15; ++i, s->v[15] += 4) fr[i] = vf3_mem_u32(ram, s->v[15]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C1C0 */
int vf3_matrix_premul_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    uint32_t m[MATRIX_WORDS], out[MATRIX_WORDS];
    const uint32_t saved[4] = { fr[12], fr[13], fr[14], fr[15] };

    for (int i = 3; i >= 0; --i) push_word(s, ram, saved[i]);          /* FR15 first */
    for (int i = 0; i < MATRIX_WORDS; ++i) m[i] = vf3_mem_u32(ram, s->v[4] + 4u * i);
    s->v[4] += MATRIX_BYTES;

    /* each old XMTRX column is transformed by the loaded matrix */
    for (int c = 0; c < 4; ++c)
        if (!vf3_fpu_ftrv(m, &xf_bank(s)[4 * c], s->v[VF3_REG_FPSCR], &out[4 * c])) return 0;
    for (int i = 0; i < MATRIX_WORDS; ++i) { fr[i] = m[i]; xf_bank(s)[i] = out[i]; }

    /* FR12..FR15 are reloaded from the stack, then the stack pointer is popped back */
    for (int i = 0; i < 4; ++i) fr[12 + i] = saved[i];
    s->v[15] += 16;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
