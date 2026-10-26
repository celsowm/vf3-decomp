/* tests/ta_decode.c - decode a captured Tile Accelerator command stream.
 *
 * usage: vf3ta <file.bin> [limit]
 *
 * The file holds the TA words the port captured (one 32-bit word each, little
 * endian).  The tool decodes them with our own TA decoder and prints what the
 * stream holds: the primitives, their lists, their textures and the range the
 * vertices cover.  It is the check that the capture is a well formed display
 * list before the rasteriser is written against it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render/ta.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <ta.bin> [limit]\n", argv[0]);
        return 2;
    }
    FILE *f = fopen(argv[1], "rb");
    if (!f) { fprintf(stderr, "cannot open %s\n", argv[1]); return 2; }
    fseek(f, 0, SEEK_END);
    long bytes = ftell(f);
    fseek(f, 0, SEEK_SET);
    const unsigned n = (unsigned)(bytes / 4);
    uint32_t *words = malloc((size_t)n * 4);
    if (!words || fread(words, 4, n, f) != n) {
        fprintf(stderr, "cannot read %s\n", argv[1]);
        return 2;
    }
    fclose(f);

    vf3_ta_list list;
    const int rc = vf3_ta_decode(words, n, &list);
    printf("words %u, blocks %u, primitives %u, consumed %u words (%s)\n",
           n, list.blocks, list.count, list.words, rc ? "PARSE ERROR" : "ok");
    if (rc) {
        printf("the stream did not parse at word %u (block %u)\n", list.words, list.blocks);
        vf3_ta_free(&list);
        return 1;
    }

    unsigned polys = 0, sprites = 0, textured = 0;
    float minx = 1e30f, maxx = -1e30f, miny = 1e30f, maxy = -1e30f;
    unsigned lists[8] = {0};
    for (unsigned i = 0; i < list.count; ++i) {
        const vf3_ta_prim *p = &list.prims[i];
        if (p->is_sprite) sprites++; else polys++;
        if (vf3_ta_texture(p->param.pcw)) textured++;
        if (p->list_type < 8) lists[p->list_type]++;
        for (unsigned v = 0; v < p->count; ++v) {
            const vf3_ta_vertex *q = &p->verts[v];
            if (q->x < minx) minx = q->x;
            if (q->x > maxx) maxx = q->x;
            if (q->y < miny) miny = q->y;
            if (q->y > maxy) maxy = q->y;
        }
    }
    printf("polygons %u, sprites %u, textured %u\n", polys, sprites, textured);
    printf("lists: opaque %u, opaque+modvol %u, translucent %u, translucent+modvol %u, punch %u\n",
           lists[0], lists[1], lists[2], lists[3], lists[4]);
    printf("vertex range: x %g .. %g, y %g .. %g\n", minx, maxx, miny, maxy);

    const unsigned limit = argc > 2 ? (unsigned)strtoul(argv[2], 0, 0) : 12u;
    for (unsigned i = 0; i < list.count && i < limit; ++i) {
        const vf3_ta_prim *p = &list.prims[i];
        printf("prim %u: %s list %u vtype %u verts %u pcw %08x isp %08x tsp %08x tcw %08x\n",
               i, p->is_sprite ? "sprite" : "polygon", p->list_type, p->param.vertex_type,
               p->count, p->param.pcw, p->param.isp_tsp, p->param.tsp, p->param.tcw);
        for (unsigned v = 0; v < p->count; ++v) {
            const vf3_ta_vertex *q = &p->verts[v];
            printf("   v%u: x %g y %g z %g u %g v %g col %08x\n",
                   v, q->x, q->y, q->z, q->u, q->v, q->colour);
        }
    }
    vf3_ta_free(&list);
    free(words);
    return 0;
}
