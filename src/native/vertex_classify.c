/* vertex_classify.c - SH-4 0x8C048EC0 (vertex_classify), natively.
 *
 * A plain-C transcription of the readable port src/fight/vertex_classify.c
 * (`vf3_vertex_classify_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained FP leaf (call-free - the only guest FPU primitive is ftrv,
 * reproduced as the column-major transform).  The caller leaves r4 pointing at
 * three consecutive strip point records, r12 = the clip value (compared as an
 * unsigned bit pattern, which orders non-negative floats) and r9 = the outcode
 * accumulator.
 *
 * A point record starts with a flag word.  With bit 0 set the record is
 * inline: x, y, z are the three floats from its first word on and the next
 * record is 32 bytes on.  With bit 0 clear the second word is an offset (from
 * record + 8) to out-of-line x, y, z and the next record follows after 8
 * bytes.  Each point goes through XMTRX as (x, y, z, 1); the transformed w of
 * the three points is then compared against r12, one rotcl into r9 per point
 * (second, third, then first - the last bit shifted out ends up in T).
 *
 * On return r4 and r1 are the original record pointer and r0 holds the
 * first point's transformed w (FPUL the same).  The three transformed vectors
 * stay in FR0-FR3 (second point) and FR4-FR7 (first point).  XMTRX, FR8..FR15,
 * r15, SR (other than the T bit from the last rotcl) and every other register
 * are untouched.
 *
 * See docs/re/native_vertex_classify.md. */
#include "vertex_classify.h"

#include "aim_math.h"

#include <stdint.h>

static const uint32_t ONE = 0x3F800000u;

/* load one point's x, y, z into fr[0..2] (w = 1 in fr[3]); returns the next
 * record's address */
static uint32_t load_point(vf3_native_aim *a, uint32_t record, float *fr)
{
    const uint32_t flags = vf3_aim_u32(a, record);
    fr[3] = vf3_aim_fbits(ONE);
    if (flags & 1u) {
        fr[0] = vf3_aim_fbits(flags);
        fr[1] = vf3_aim_fbits(vf3_aim_u32(a, record + 4));
        fr[2] = vf3_aim_fbits(vf3_aim_u32(a, record + 8));
        return record + 32u;
    }
    const uint32_t xyz = record + 8u + vf3_aim_u32(a, record + 4u);
    for (uint32_t i = 0; i < 3; ++i)
        fr[i] = vf3_aim_fbits(vf3_aim_u32(a, xyz + 4u * i));
    return record + 8u;
}

/* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX) */
static void ftrv(vf3_native_aim *a, float *v)
{
    float out[4];
    for (int r = 0; r < 4; ++r) {
        float s = 0.0f;
        for (int k = 0; k < 4; ++k) s += a->xm[4 * k + r] * v[k];
        out[r] = s;
    }
    for (int r = 0; r < 4; ++r) v[r] = out[r];
}

int vf3_native_vertex_classify(vf3_native_aim *a)
{
    const uint32_t first = a->r[4];

    /* the caller's point order: second, third, then the first (which
     * overwrites the second's FR4..FR7) */
    uint32_t next = load_point(a, first, a->fr + 4);
    ftrv(a, a->fr + 4);
    const uint32_t w_first = vf3_aim_ubits(a->fr[7]);   /* second point's w */

    next = load_point(a, next, a->fr + 0);
    ftrv(a, a->fr + 0);                                  /* third point */

    (void)load_point(a, next, a->fr + 4);
    ftrv(a, a->fr + 4);                                  /* first point */

    const uint32_t clip = a->r[12];
    /* rotcl: r9 = (r9 << 1) | t; the bit shifted out becomes T */
    {
        const uint32_t out0 = a->r[9] >> 31;
        a->r[9] = (a->r[9] << 1) | (uint32_t)(clip > w_first);
        a->sr = (a->sr & ~1u) | (out0 & 1u);
    }
    {
        const uint32_t out1 = a->r[9] >> 31;
        a->r[9] = (a->r[9] << 1) | (uint32_t)(clip > vf3_aim_ubits(a->fr[3]));
        a->sr = (a->sr & ~1u) | (out1 & 1u);
    }
    a->fpul = vf3_aim_ubits(a->fr[7]);
    a->r[0] = vf3_aim_ubits(a->fr[7]);
    {
        const uint32_t out2 = a->r[9] >> 31;
        a->r[9] = (a->r[9] << 1) | (uint32_t)(clip > vf3_aim_ubits(a->fr[7]));
        a->sr = (a->sr & ~1u) | (out2 & 1u);
    }

    a->r[1] = first;
    a->r[4] = first;
    return 1;
}
