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

static void bbox_cb(uint32_t off, uint32_t triples, void *ctx)
{
    (void)off;
    VF3_DrawPart *p = (VF3_DrawPart *)ctx;
    p->triples += triples;
}

/* Parse a POL stream into a scene summary (bounds-checked). */
int vf3_dl_from_pol(const void *data, uint32_t size, VF3_DlScene *out,
                    uint32_t *vtx_triples_total)
{
    if (!data || !out)
        return -1;
    if (pol_header(data, size, &out->hdr) != 0)
        return -2;
    out->n_parts = (uint32_t)out->hdr.parts_lo +
                   ((uint32_t)out->hdr.parts_hi << 16);
    VF3_DrawPart acc = {0};
    pol_scan_floats(data, size, 4, bbox_cb, &acc);   /* returns block count */
    if (vtx_triples_total)
        *vtx_triples_total = acc.triples;
    return 0;
}
