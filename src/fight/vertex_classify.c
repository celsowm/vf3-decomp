/* vertex_classify.c - 0x8C048EC0  transform three strip points and record which lie behind the clip plane.
 *
 *   r4 -> three consecutive point records, r12 = the clip value (compared as an unsigned bit pattern, which
 *   orders non-negative floats), r9 = the outcode accumulator.
 *
 * A point record starts with a flag word. With bit 0 set the record is inline: x, y, z are the three floats
 * from its first word on, and the next record is 32 bytes on. With bit 0 clear the second word is an offset
 * (from record + 8) to out-of-line x, y, z and the next record follows after 8 bytes. Each point goes through
 * XMTRX as (x, y, z, 1); the transformed w of the three points is then compared against r12, one rotcl into
 * r9 per point (first point first), so the three low bits of r9 hold the outcodes (the last bit shifted out
 * ends up in T).
 *
 * On return r4 is the original record pointer and r0 holds the third point's transformed w. The three
 * transformed vectors stay in FR0-FR3 (second point), FR4-FR7 (third point); the first point's is gone. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum { SR_T = 1u, INLINE_FLAG = 1u, INLINE_STRIDE = 32, OUTLINE_STRIDE = 8, ONE = 0x3F800000u };

/* load one point's x, y, z into fr[0..2] (w = 1 in fr[3]); returns the next record's address */
static uint32_t load_point(const vf3_ram_map *ram, uint32_t record, uint32_t *fr)
{
    const uint32_t flags = vf3_mem_u32(ram, record);
    fr[3] = ONE;
    if (flags & INLINE_FLAG) {
        fr[0] = flags;
        fr[1] = vf3_mem_u32(ram, record + 4);
        fr[2] = vf3_mem_u32(ram, record + 8);
        return record + INLINE_STRIDE;
    }
    const uint32_t xyz = record + OUTLINE_STRIDE + vf3_mem_u32(ram, record + 4);
    for (uint32_t i = 0; i < 3; ++i) fr[i] = vf3_mem_u32(ram, xyz + 4 * i);
    return record + OUTLINE_STRIDE;
}

/* r9 = (r9 << 1) | T, T = the bit shifted out */
static void rotcl_r9(vf3_matrix_state *s, int t)
{
    const uint32_t out = s->v[9] >> 31;
    s->v[9] = (s->v[9] << 1) | (uint32_t)t;
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~SR_T) | out;
}

int vf3_vertex_classify_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = &VF3_FR(s, 0);
    const uint32_t *xf = &s->v[VF3_REG_XF0];
    const uint32_t fpscr = s->v[VF3_REG_FPSCR];
    const uint32_t first = s->v[4];

    uint32_t next = load_point(ram, first, fr + 4);
    if (!vf3_fpu_ftrv(xf, fr + 4, fpscr, fr + 4)) return 0;
    const uint32_t w_first = fr[7];

    next = load_point(ram, next, fr + 0);
    if (!vf3_fpu_ftrv(xf, fr + 0, fpscr, fr + 0)) return 0;

    (void)load_point(ram, next, fr + 4);
    if (!vf3_fpu_ftrv(xf, fr + 4, fpscr, fr + 4)) return 0;

    const uint32_t clip = s->v[12];
    rotcl_r9(s, clip > w_first);
    rotcl_r9(s, clip > fr[3]);
    s->v[VF3_REG_FPUL] = fr[7];
    s->v[0] = fr[7];
    rotcl_r9(s, clip > fr[7]);

    s->v[1] = first;
    s->v[4] = first;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
