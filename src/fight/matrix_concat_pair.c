/* matrix_concat_pair.c - 0x8C03DD00  concatenate two stored 4x4 matrices onto XMTRX.
 *
 *   no arguments. The first matrix is the 16 floats at the address held in [0x0C19D308 + 8], the second the 16 floats at
 *   0x0C19D518. Both are read as row vectors in order (first row = first four floats). XMTRX ends as
 *   XMTRX * A * B (every row run through ftrv with A, then with B); the shared body (0x8C03DD30) keeps
 *   FR12..FR15 as they were (they travel through the stack) and leaves the second matrix in FR0..FR11.
 *
 *   The original does this with bank swaps (FRCHG): load A into the front bank, swap so it is XMTRX and run the
 *   old XMTRX rows through it, swap back, load B over A, swap and run the result through B. Returns with
 *   r4 = second matrix + 32 and r5 = second matrix + 64. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { FR_BIT = 0x00200000u, SZ_BIT = 0x00100000u, SECOND = 0x0C19D518u, FIRST_PTR = 0x0C19D308u };

static uint32_t *fr_bank(vf3_matrix_state *s) { return &VF3_FR(s, 0); }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

static void frchg(vf3_matrix_state *s)
{
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    for (int i = 0; i < 16; ++i) { const uint32_t t = fr[i]; fr[i] = xf[i]; xf[i] = t; }
    s->v[VF3_REG_FPSCR] ^= FR_BIT;
}

static int rows_through_xmtrx(vf3_matrix_state *s)
{
    uint32_t *fr = fr_bank(s);
    for (int i = 0; i < 16; i += 4)
        if (!vf3_fpu_ftrv(xf_bank(s), fr + i, s->v[VF3_REG_FPSCR], fr + i)) return 0;
    return 1;
}

int vf3_matrix_concat_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15);
    uint32_t *fr = fr_bank(s);

    if (s->v[VF3_REG_FPSCR] & SZ_BIT) return 0;             /* the body's own fschg would turn pair moves off */

    const uint32_t first = m32(ram, FIRST_PTR + 8);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), fr[15 - i]);

    for (int i = 0; i < 16; ++i) fr[i] = m32(ram, first + 4u * (uint32_t)i);
    frchg(s);                                               /* A is XMTRX */
    if (!rows_through_xmtrx(s)) return 0;
    frchg(s);
    for (int i = 0; i < 16; ++i) fr[i] = m32(ram, SECOND + 4u * (uint32_t)i);
    frchg(s);
    if (!rows_through_xmtrx(s)) return 0;
    frchg(s);

    for (int i = 0; i < 4; ++i) fr[12 + i] = m32(ram, sp0 - 16u + 4u * (uint32_t)i);
    R(4) = SECOND + 32;
    R(5) = SECOND + 64;
    s->pc = R(VF3_REG_PR);
    return 1;
}
