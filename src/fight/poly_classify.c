/* vf3 poly_classify — per-vertex quad classification (SH-4 0x8C068FF6).
 *
 * The #2 hottest fight function (~1.4M summed trace hits / 120 frames,
 * 288 bytes). It walks a descriptor:
 *
 *   r4 -> { u32 flags; u32 off_rec; ... }
 *   r3 -> u32 base                       (added to every stored offset)
 *   rec = base + *(r4+4)                 (32-bit header)
 *   rec[0]     : bit0 = "stored" gate
 *   rec[1..4]  : offsets from base to four (x,y) points p0..p3
 *   rec[6]     : float weight (0 => classify 0)
 *
 * Five calles to the orientation helper 0x8C068F92 (ported as
 * src/fight/orient2.c) classify the sample point (fr4,fr5) against the
 * quad edges p0->p1, p1->p2, p2->p0, p2->p3, p3->p0. The 1/2/4 bit results
 * are folded into masks; the function returns 1 (flag gate), 0 (weight 0 /
 * gate / balance), 2 or 4:
 *
 *   m = h3 | (h1 & 6) | (h2 & 6)
 *   if (bit2(m) != bit4(m)) return 2;
 *   if (stored != 0)        return 0;
 *   a = h1 | (h2 & 6) | (h4 & 6) | (h5 & 6)
 *   return (bit2(a) != bit4(a)) ? 4 : 0;
 *
 * Semantics were recovered from the sh4.py disassembly and validated against
 * 16 oracle cases captured with flycast VF3_FULL + VF3_RAMWIN
 * (extract/analysis/goldens/f_0c068ff6.*): 16/16 exact r0 match.
 *
 * The address-space map below emulates the SH-4 P1/P2 aliases so the replay
 * test can run against a 16 MB RAM snapshot; in the engine these reads are
 * ordinary pointer dereferences.
 */
#include "fight/poly_classify.h"

#include <string.h>

static const uint8_t *win_find(const vf3_ram_map *ram, uint32_t addr,
                               uint32_t *off)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            *off = canon - w->base;
            return w->data;
        }
    }
    return 0;
}

static uint32_t rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t off;
    const uint8_t *p = win_find(ram, addr, &off);
    uint32_t v = 0;
    if (p)
        memcpy(&v, p + off, 4);
    return v;
}

static float rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static int xor_flag(uint32_t x, uint32_t y)
{
    return (x != 0) != (y != 0);
}

int vf3_poly_classify(uint32_t r4, uint32_t r3, float fr4, float fr5,
                      const vf3_ram_map *ram)
{
    uint32_t flags = rd32(ram, r4);
    uint32_t rec, stored, p0, p1, p2, p3;
    int h1, h2, h3, h4, h5;
    uint32_t m, a;

    if (flags & 1)
        return 1;

    rec = rd32(ram, r4 + 4) + rd32(ram, r3);
    stored = rd32(ram, rec) & 1;

    if (rdflt(ram, rec + 24) == 0.0f)
        return 0;

    p0 = rd32(ram, rec + 4) + rd32(ram, r3);
    p1 = rd32(ram, rec + 8) + rd32(ram, r3);
    p2 = rd32(ram, rec + 12) + rd32(ram, r3);
    p3 = rd32(ram, rec + 16) + rd32(ram, r3);

    h1 = vf3_orient2_bits(fr4, fr5, rdflt(ram, p0), rdflt(ram, p0 + 8),
                          rdflt(ram, p1), rdflt(ram, p1 + 8));
    h2 = vf3_orient2_bits(fr4, fr5, rdflt(ram, p1), rdflt(ram, p1 + 8),
                          rdflt(ram, p2), rdflt(ram, p2 + 8));
    h3 = vf3_orient2_bits(fr4, fr5, rdflt(ram, p2), rdflt(ram, p2 + 8),
                          rdflt(ram, p0), rdflt(ram, p0 + 8));
    h4 = vf3_orient2_bits(fr4, fr5, rdflt(ram, p2), rdflt(ram, p2 + 8),
                          rdflt(ram, p3), rdflt(ram, p3 + 8));
    h5 = vf3_orient2_bits(fr4, fr5, rdflt(ram, p3), rdflt(ram, p3 + 8),
                          rdflt(ram, p0), rdflt(ram, p0 + 8));

    m = (uint32_t)h3 | ((uint32_t)h1 & 6u) | ((uint32_t)h2 & 6u);
    if (xor_flag(m & 2u, m & 4u))
        return 2;
    if (stored != 0)
        return 0;

    a = (uint32_t)h1 | ((uint32_t)h2 & 6u) |
        ((uint32_t)h4 & 6u) | ((uint32_t)h5 & 6u);
    return xor_flag(a & 2u, a & 4u) ? 4 : 0;
}
