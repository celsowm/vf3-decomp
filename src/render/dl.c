/* render/dl.c — display-list assembly layer (M38).
 *
 * Composites the solved asset formats (POL header+float blocks,
 * pol_scan/pol.h; TEX twiddle) into a per-part draw record stream that a
 * KAMUI back-end would emit to the PVR TA FIFO. The PVR submit side
 * itself stays hardware-shaped (render sequences through the KAMUI2
 * pipeline; kamui2 modules attributed in M30).
 *
 * Verification: tests/dl_replay.c parses REAL POL fixtures from
 * extract/gamedata (`_te`-tagged packs) and asserts structural
 * invariants (parts count, triple ranges, table bounds).
 */
#include <stdint.h>

#include "../media/pol.h"

typedef struct VF3_DrawPart_ {
    uint16_t part_id;
    uint16_t flags;
    uint32_t geom_off;      /* into POL payload       */
    uint32_t triples;       /* float3 count           */
    float    bbox_min[3];
    float    bbox_max[3];
} VF3_DrawPart;

typedef struct {
    PolHeader hdr;
    uint32_t  n_parts;
} VF3_DlScene;

typedef struct {
    const uint8_t *data;
    uint32_t       size;
    VF3_DrawPart  *acc;
} BboxCtx;

static void bbox_cb(uint32_t off, uint32_t triples, void *ctx)
{
    BboxCtx *c = (BboxCtx *)ctx;
    VF3_DrawPart *p = c->acc;
    if (p->triples == 0 && p->geom_off == 0)
        p->geom_off = off;
    /* bbox over this block's triples (12 B stride) */
    for (uint32_t i = 0; i < triples; i++) {
        uint32_t at = off + i * 12;
        if (at + 12 > c->size)
            break;
        float v[3];
        for (int k = 0; k < 3; k++) {
            uint32_t u = (uint32_t)c->data[at + k * 4] |
                         ((uint32_t)c->data[at + k * 4 + 1] << 8) |
                         ((uint32_t)c->data[at + k * 4 + 2] << 16) |
                         ((uint32_t)c->data[at + k * 4 + 3] << 24);
            v[k] = *(float *)&u;
        }
        if (p->triples == 0 && i == 0) {
            for (int k = 0; k < 3; k++) {
                p->bbox_min[k] = v[k];
                p->bbox_max[k] = v[k];
            }
        } else {
            for (int k = 0; k < 3; k++) {
                if (v[k] < p->bbox_min[k])
                    p->bbox_min[k] = v[k];
                if (v[k] > p->bbox_max[k])
                    p->bbox_max[k] = v[k];
            }
        }
        p->triples++;
    }
}

/* Parse a POL stream into a scene summary (bounds-checked). */
int vf3_dl_from_pol(const void *data, uint32_t size, VF3_DlScene *out,
                    uint32_t *vtx_triples_total)
{
    if (!data || !out)
        return -1;
    if (pol_header(data, size, &out->hdr) != 0)
        return -2;
    /* parts_lo/hi are two independent counters (M60: GEN_DMY5 lo=11 hi=41);
     * the old lo+(hi<<16) sum (=2686987) is wrong. n_parts = lo (draw parts),
     * hi = secondary (chain/collision rows). Bound both against file size. */
    if (out->hdr.parts_lo == 0 || out->hdr.parts_lo > 256)
        return -3;
    if (out->hdr.table_base != 0x30)
        return -4;
    if (out->hdr.table_base + out->hdr.table_span > size)
        return -5;
    out->n_parts = out->hdr.parts_lo;
    VF3_DrawPart acc = {0};
    BboxCtx cx = {(const uint8_t *)data, size, &acc};
    pol_scan_floats(data, size, 4, bbox_cb, &cx);   /* returns block count */
    if (vtx_triples_total)
        *vtx_triples_total = acc.triples;
    return 0;
}
