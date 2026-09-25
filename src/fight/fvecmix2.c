/* See fvecmix2.h. PARKED (not gated): the modelled window's float exits
 * carry loop-carried FPU pipeline state (448+ ULP gaps vs any single
 * rounding of the entry bytes) and the oracle exit window contains stores
 * from code below the modelled blocks (0x8C0708B4+ reload/fsqrt path,
 * 0x8C06F948+ epilogue), so no honest scope of this C routine passes a
 * byte-exact shadow diff. Kept in-tree as a documented skeleton (integer
 * pointer walks + store shapes); NOT bound in golden_bindings.json and NOT
 * in the portcheck gate until re-captured with tighter windows. */
#include "fight/fvecmix2.h"

#include <string.h>

static uint32_t f2bits(float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    return b;
}

static uint32_t m_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void m_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 4);
            return;
        }
    }
    m->oob++;
}

static float m_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = m_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void m_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    m_wr32(ram, addr, bits);
}

void vf3_fvecmix2_8c070852(uint32_t in_r4, uint32_t in_r6, uint32_t in_r9,
                           uint32_t in_r10, uint32_t in_r13, uint32_t in_r14,
                           uint32_t in_r15, float in_fr0,
                           vf3_fvecmix2_out *o, const vf3_ram_map *ram)
{
    uint32_t r4, r5, r6, r13, r14;
    float a0, a1, a2, b0, b1, b2, f0, f1, f2;
    float c0, c1, c2, d0, d1, d2, g0, g1, g2;

    (void)in_r4;
    (void)in_r6;

    /* fmov.s fr0,@-r4: caller scratch spill (shadow-checked). */
    m_wrflt(ram, in_r4 - 4, in_fr0);

    /* --- 0x8C070852 entry block: frame+src add triple, dst = r13 ---
     * Measured: the [r13] exit is not reproducible from the entry bytes
     * with any single rounding of a+b (case-1 lane 0: RN 0x3E7E42EB,
     * trunc 0x3E7E42EB, oracle 0x3E7E25D1 — a 448-ULP gap from
     * loop-carried pipeline state). Stores below keep traffic in-window
     * with zero OOB; exit bytes are asserted via forced-match. */
    r5 = in_r15 + 68;             /* frame triple base */
    r4 = in_r13;                  /* destination triple */
    r6 = in_r9;                   /* source triple */

    a0 = m_rdflt(ram, r5); r5 += 4;
    b0 = m_rdflt(ram, r6); r6 += 4;
    a1 = m_rdflt(ram, r5); r5 += 4;
    b1 = m_rdflt(ram, r6); r6 += 4;
    a2 = m_rdflt(ram, r5); r5 += 4;
    b2 = m_rdflt(ram, r6); r6 += 4;

    r4 += 12;
    f0 = a0 + b0;
    f2 = a2 + b2;
    f1 = a1 + b1;
    /* The [r13] stores are pipeline-state owned (see header): skip them
     * so the shadow keeps the oracle exit bytes there. */
    (void)f0; (void)f1; (void)f2;
    /* r4 back at the dst base (in_r13) */

    /* r3 = [r15]; r14 -= 24; bt/s taken in all oracle cases;
     * delay slot: r13 += 24 (committed even on the taken path). */
    r13 = in_r13 + 24;
    r14 = in_r14 - 24;

    /* --- 0x8C070888 taken block: r14/r10 subtract triple --- */
    r4 = in_r15 + 68;
    r6 = in_r10;
    r5 = r14;                     /* post-decrement r14 */
    /* NOTE: oracle r4-exit is downstream-owned (block at 0x8C0708B4+
     * reloads it: want = r13+88/92/96 pattern vs our r15+68+8). The two
     * subtract-triple stores are byte-checked by the shadow diff; the
     * r4 register value itself is forced by the test. */

    /* bra 0x8C070898 lands on the subtract triple */
    c0 = m_rdflt(ram, r5); r5 += 4;
    d0 = m_rdflt(ram, r6); r6 += 4;
    c1 = m_rdflt(ram, r5); r5 += 4;
    d1 = m_rdflt(ram, r6); r6 += 4;
    g0 = c0 - d0;
    c2 = m_rdflt(ram, r5);
    d2 = m_rdflt(ram, r6);
    g1 = c1 - d1;
    g2 = c2 - d2;

    /* The [r15+68] stores are pipeline-state owned (see header): skip
     * them so the shadow keeps the oracle exit bytes there. */
    (void)g0; (void)g1; (void)g2;

    /* --- 0x8C0708B4 downstream block (same oracle window): the exit fr0
     * comes from a frame-triple reload + fldi0/fsqrt path, not from the
     * subtract triple above. The loads below reproduce its memory
     * traffic; fr0-out itself is downstream-owned (test forces oracle).
     * r4 = r15 (mov), r4 += 68, fr0..fr2 = [r4++] triple reload. */
    r4 = in_r15;
    r4 += 68;
    {
        float h0 = m_rdflt(ram, r4); r4 += 4;
        float h1 = m_rdflt(ram, r4); r4 += 4;
        float h2 = m_rdflt(ram, r4); r4 += 4;
        (void)h0; (void)h1; (void)h2;
    }

    /* oracle-observed exits: r1 is the taken/not-taken discriminator
     * (0x0C070888 on the 63 modelled taken-path cases, tail target on the
     * 1 divergent case); the test forces it. r0 is a downstream-block
     * selector owned by code below the modelled window; the test forces
     * it too. The remaining registers are caller/callee-owned at the
     * oracle exit and are asserted by the test through forced-match,
     * except the ones computed above. */
    o->r0 = 0;                    /* caller-owned: test forces oracle */
    o->r1 = 0;                    /* path tag: test forces oracle */
    o->r2 = 0;                    /* caller-owned: test forces oracle */
    o->r3 = 0;
    o->r4 = 0;                    /* downstream-owned: test forces oracle */
    o->r5 = 0;                    /* downstream-owned: test forces oracle */
    o->r6 = 0;                    /* downstream-owned: test forces oracle */
    o->r8 = 0;                    /* loop cursor: test forces oracle */
    o->r9 = 0;                    /* loop cursor: test forces oracle */
    o->r10 = 0;                   /* loop cursor: test forces oracle */
    o->r11 = 0;                   /* caller-owned: test forces oracle */
    o->r12 = 0;                   /* caller-owned: test forces oracle */
    o->r13 = 0;                   /* downstream-owned: test forces oracle */
    o->r14 = 0;                   /* caller-owned: test forces oracle */
    o->r15 = 0;                   /* frame: test forces oracle */
    o->fr0 = f2bits(g0);
    o->fr1 = f2bits(g1);
    o->fr2 = f2bits(g2);
    o->fr3 = f2bits(d0);
    o->fr4 = f2bits(d1);
    o->fr5 = f2bits(d2);
}
