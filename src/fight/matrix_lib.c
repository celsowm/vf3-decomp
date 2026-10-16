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

/* 0x8C03C4F0  matrix_push: push XMTRX on the matrix stack, optionally load a new one.
 *
 * The stack's control block is at 0x0C19D2E4: word 0 = (limit << 16) | count (two int16),
 * word 8 = stack top. XMTRX is written at the top (FR0 lowest) and the top moves up by one
 * matrix; the count is incremented whether or not it stays below the limit (the limit test
 * only leaves its result in r0). With r4 != 0 the matrix at r4 then becomes XMTRX and r4
 * advances past it. The front FR bank is untouched; SR.T ends as r4 == 0, or as
 * "r4 is 8-byte aligned" (which picks the pair-load path) when a matrix is loaded. */
#define MATRIX_STACK_CTL 0x0C19D2E4u

int vf3_matrix_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t top = vf3_mem_u32(ram, MATRIX_STACK_CTL + 8u);
    const uint32_t ctl = vf3_mem_u32(ram, MATRIX_STACK_CTL);
    const uint32_t *xf = xf_bank(s);
    for (int i = 0; i < MATRIX_WORDS; ++i) vf3_mem_set_u32(ram, top + 4u * i, xf[i]);

    const int32_t count = (int16_t)(ctl & 0xFFFFu), limit = (int16_t)(ctl >> 16);
    s->v[0] = limit > count;
    vf3_mem_set_u32(ram, MATRIX_STACK_CTL + 8u, top + MATRIX_BYTES);
    vf3_matrix_write(ram, MATRIX_STACK_CTL, (uint32_t)(count + 1) & 0xFFFFu, 2);

    int t;
    if (s->v[4] == 0) {
        t = 1;
    } else {
        uint32_t *dst = xf_bank(s);
        for (int i = 0; i < MATRIX_WORDS; ++i) dst[i] = vf3_mem_u32(ram, s->v[4] + 4u * i);
        t = (s->v[4] & 4u) == 0;
        s->v[4] += MATRIX_BYTES;
    }
    s->v[17] = (s->v[17] & ~1u) | (uint32_t)t;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C140  matrix_concat_save: same product as matrix_concat (XMTRX = XMTRX * M(r4), banks
 * end up swapped) but it keeps the caller's FR12..FR15 on the stack as four words and puts
 * them back into the new front bank. */
int vf3_matrix_concat_save_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    uint32_t m[MATRIX_WORDS], out[MATRIX_WORDS];
    const uint32_t saved[4] = { fr[12], fr[13], fr[14], fr[15] };

    for (int i = 3; i >= 0; --i) push_word(s, ram, saved[i]);          /* FR15 first */
    for (int i = 0; i < MATRIX_WORDS; ++i) m[i] = vf3_mem_u32(ram, s->v[4] + 4u * i);
    s->v[4] += MATRIX_BYTES;
    for (int c = 0; c < 4; ++c)
        if (!vf3_fpu_ftrv(xf_bank(s), &m[4 * c], s->v[VF3_REG_FPSCR], &out[4 * c])) return 0;

    for (int i = 0; i < MATRIX_WORDS; ++i) fr[i] = xf_bank(s)[i];
    for (int i = 0; i < MATRIX_WORDS; ++i) xf_bank(s)[i] = out[i];
    s->v[VF3_REG_FPSCR] ^= 0x00200000u;
    for (int i = 0; i < 4; ++i) fr[12 + i] = saved[i];
    s->v[15] += 16;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03C200  matrix_concat_parent: XMTRX = XMTRX * (the matrix just below the stack top). */
int vf3_matrix_concat_parent_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    s->v[4] = vf3_mem_u32(ram, MATRIX_STACK_CTL + 8u) - MATRIX_BYTES;
    return vf3_matrix_concat_save_entry(s, ram);
}

/* 0x8C03C4A0  matrix_pop: drop r4 matrices (at least one, never below an empty stack) and load
 * the new top into XMTRX. The control block is {int16 count, int16 limit, u32 base, u32 top}.
 * The top pointer is only rewritten while the new count is below the limit. Leaves
 * r0 = (count >= r4), r6 = new count, r7 = address past the loaded matrix. */
int vf3_matrix_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const int32_t drop = (int32_t)s->v[4] > 0 ? (int32_t)s->v[4] : 1;
    const uint32_t ctl = vf3_mem_u32(ram, MATRIX_STACK_CTL);
    const int32_t count = (int16_t)(ctl & 0xFFFFu), limit = (int16_t)(ctl >> 16);
    const uint32_t base = vf3_mem_u32(ram, MATRIX_STACK_CTL + 4u);

    const int enough = count >= drop;
    const int32_t new_count = enough ? count - drop : 0;
    uint32_t addr = base + ((uint32_t)new_count << 6);
    vf3_matrix_write(ram, MATRIX_STACK_CTL, (uint32_t)new_count & 0xFFFFu, 2);
    if (new_count < limit) vf3_mem_set_u32(ram, MATRIX_STACK_CTL + 8u, addr);

    uint32_t *xf = xf_bank(s);
    for (int i = 0; i < MATRIX_WORDS; ++i) xf[i] = vf3_mem_u32(ram, addr + 4u * i);

    s->v[0] = (uint32_t)enough;
    s->v[2] = (uint32_t)limit;
    s->v[3] = MATRIX_STACK_CTL;
    s->v[4] = (uint32_t)new_count << 6;
    s->v[6] = (uint32_t)new_count;
    s->v[7] = addr + MATRIX_BYTES;
    s->v[17] = (s->v[17] & ~1u) | (uint32_t)(new_count >= limit);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C03D260 / 0x8C03D280 / 0x8C03D2B0  matrix_frame_*: "evaluate a child transform and
 * remember it" sequences built from the stack helpers above. Each pushes the current XMTRX,
 * multiplies in the parent (and in B's case the matrix at *(0x0C19D2FC+8) first), stores the
 * result as a flat matrix in one of the fixed slots and pops the stack back (tail call). */
#define MATRIX_SLOT_NODE    0x0C19D308u   /* control block whose top is pushed first (A, B) */
#define MATRIX_SLOT_PARENT  0x0C19D2FCu   /* control block of the parent chain (B, C) */
#define MATRIX_FLAT_A       0x0C19D4D8u
#define MATRIX_FLAT_C       0x0C19D498u

static int frame_chain(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t push_from,
                       int concat_parent_matrix, uint32_t flat_slot)
{
    const uint32_t sp = s->v[15], pr = s->v[VF3_REG_PR];
    vf3_mem_set_u32(ram, sp - 4u, pr);
    s->v[15] = sp - 4u;

    s->v[4] = vf3_mem_u32(ram, push_from + 8u);
    if (!vf3_matrix_push_entry(s, ram)) return 0;
    if (concat_parent_matrix) {
        s->v[4] = vf3_mem_u32(ram, MATRIX_SLOT_PARENT + 8u);
        if (!vf3_matrix_concat_entry(s, ram)) return 0;
    }
    if (!vf3_matrix_concat_parent_entry(s, ram)) return 0;
    s->v[4] = flat_slot;
    if (!vf3_matrix_store_entry(s, ram)) return 0;
    s->v[4] = 1;
    if (!vf3_matrix_pop_entry(s, ram)) return 0;

    s->v[15] = sp;
    s->v[VF3_REG_PR] = pr;
    s->pc = pr;
    return 1;
}

int vf3_matrix_frame_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{ return frame_chain(s, ram, MATRIX_SLOT_NODE, 0, MATRIX_FLAT_A); }

int vf3_matrix_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{ return frame_chain(s, ram, MATRIX_SLOT_NODE, 1, MATRIX_FLAT_A); }

int vf3_matrix_frame_c_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{ return frame_chain(s, ram, MATRIX_SLOT_PARENT, 0, MATRIX_FLAT_C); }
