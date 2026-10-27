/* tests/ta_inspect.c - read a captured TA command stream and say what it draws.
 *
 * usage: vf3tainfo <ta.bin> [vram.bin]
 *
 * The TA file holds the 32-byte blocks the hardware received (little-endian
 * words).  The tool decodes them with our own decoder and prints every
 * primitive: its kind, the list it belongs to, its texture control word (the
 * texture's address, its format, whether it is vector-quantised) and its
 * vertices.  With a VRAM dump it also shows what the model would find at the
 * texture's address, which is how a black picture gets explained.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render/ta.h"

static uint32_t *read_words(const char *path, unsigned *count)
{
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open %s\n", path); return NULL; }
    fseek(f, 0, SEEK_END);
    const long bytes = ftell(f);
    fseek(f, 0, SEEK_SET);
    const unsigned n = (unsigned)(bytes / 4);
    uint32_t *words = malloc((size_t)n * 4u ? (size_t)n * 4u : 4u);
    if (!words || (n && fread(words, 4, n, f) != n)) {
        fprintf(stderr, "cannot read %s\n", path);
        free(words);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *count = n;
    return words;
}

static const char *list_name(unsigned t)
{
    switch (t) {
    case VF3_TA_LIST_OPAQUE: return "opaque";
    case VF3_TA_LIST_OPAQUE_MODVOL: return "opaque+modvol";
    case VF3_TA_LIST_TRANSLUCENT: return "translucent";
    case VF3_TA_LIST_TRANSLUCENT_MODVOL: return "translucent+modvol";
    case VF3_TA_LIST_PUNCH_THROUGH: return "punch-through";
    default: return "?";
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <ta.bin> [vram.bin]\n", argv[0]);
        return 2;
    }
    unsigned n = 0;
    uint32_t *words = read_words(argv[1], &n);
    if (!words) return 2;

    uint8_t *vram = NULL;
    unsigned vram_bytes = 0;
    if (argc > 2) {
        FILE *f = fopen(argv[2], "rb");
        if (f) {
            fseek(f, 0, SEEK_END);
            vram_bytes = (unsigned)ftell(f);
            fseek(f, 0, SEEK_SET);
            vram = malloc(vram_bytes ? vram_bytes : 1u);
            if (vram) vram_bytes = (unsigned)fread(vram, 1, vram_bytes, f);
            fclose(f);
        }
    }

    vf3_ta_list list;
    if (vf3_ta_decode(words, n, &list)) {
        fprintf(stderr, "the stream did not parse at word %u (block %u)\n", list.words, list.blocks);
        vf3_ta_free(&list);
        free(words);
        free(vram);
        return 1;
    }
    printf("words %u, blocks %u, lists %u, primitives %u, vertices %u, invalid %u\n",
           n, list.blocks, list.lists, list.count, list.vcount, list.invalid);

    for (unsigned i = 0; i < list.count; ++i) {
        const vf3_ta_prim *p = &list.prims[i];
        const uint32_t tcw = p->param.tcw;
        const uint32_t tsp = p->param.tsp;
        const uint32_t addr = (tcw & 0x1FFFFFu) << 3;
        printf("prim %u: %s%s list %u (%s) pcw %08x tsp %08x tcw %08x"
               " -> tex %08x fmt %u vq %u mip %u %ux%u\n",
               i, p->is_sprite ? "sprite" : "polygon", p->is_modvol ? "/modvol" : "",
               p->list_type, list_name(p->list_type), p->param.pcw, tsp, tcw,
               addr, (tcw >> 27) & 7u, (tcw >> 30) & 1u, (tcw >> 31) & 1u,
               8u << ((tsp >> 3) & 7u), 8u << (tsp & 7u));
        if (vram && addr < vram_bytes) {
            printf("    vram at %08x:", addr);
            for (unsigned k = 0; k < 32 && addr + k < vram_bytes; ++k)
                printf(" %02x", vram[addr + k]);
            printf("\n");
            if ((tcw >> 30) & 1u) {
                const uint32_t data = addr + 2048u;
                unsigned nonzero = 0;
                if (data < vram_bytes)
                    for (unsigned k = 0; k < 4096u && data + k < vram_bytes; ++k)
                        if (vram[data + k]) ++nonzero;
                printf("    vq data at %08x: %u of 4096 bytes nonzero\n", data, nonzero);
            }
        }
        for (unsigned v = 0; v < p->count; ++v) {
            const vf3_ta_vertex *q = &list.verts[p->vstart + v];
            printf("    v%u x %.2f y %.2f z %g u %.4f v %.4f col %08x%s\n", v, q->x, q->y, q->z,
                   q->u, q->v, q->colour, q->end_strip ? " (strip end)" : "");
        }
    }
    vf3_ta_free(&list);
    free(words);
    free(vram);
    return 0;
}
