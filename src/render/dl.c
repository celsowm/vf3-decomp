/* POL asset inspection summary. This does not yet decode POL object chains or
 * assemble meshes; pol_scan_floats is retained as a geometry reconnaissance
 * helper while the native renderer is being built. */
#include <stdint.h>
#include <string.h>

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
    uint32_t  n_slots;
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
            memcpy(&v[k], &u, sizeof v[k]);
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

/* Parse valid POL slot/texture tables and report candidate float blocks. */
int vf3_dl_from_pol(const void *data, uint32_t size, VF3_DlScene *out,
                    uint32_t *vtx_triples_total)
{
    uint32_t slot_count = 0, texture_count = 0;
    if (!data || !out)
        return -1;
    if (pol_header(data, size, &out->hdr) != 0)
        return -2;
    if (out->hdr.slot_count == 0 || out->hdr.slot_count > 256)
        return -3;
    if (pol_slots(data, size, NULL, 0, &slot_count) != -2 ||
        pol_textures(data, size, NULL, 0, &texture_count) != -2 ||
        slot_count != out->hdr.slot_count ||
        texture_count != out->hdr.texture_count)
        return -4;
    out->n_slots = slot_count;
    VF3_DrawPart acc = {0};
    BboxCtx cx = {(const uint8_t *)data, size, &acc};
    pol_scan_floats(data, size, 4, bbox_cb, &cx);   /* returns block count */
    if (vtx_triples_total)
        *vtx_triples_total = acc.triples;
    return 0;
}
