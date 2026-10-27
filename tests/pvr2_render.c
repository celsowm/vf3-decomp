/* tests/pvr2_render.c - rasterise a captured TA command stream.
 *
 * usage: vf3pvr <ta.bin> <pvr2_state.bin> <out.ppm>
 *
 * The TA file holds the 32-byte blocks the hardware received (little-endian
 * words); the state file holds the PVR2's register file and its VRAM, as the
 * reference emulator's instrument wrote them.  The tool decodes the stream
 * with our own decoder, rasterises it with our own rasteriser and writes the
 * framebuffer out as a PPM, so a frame can be looked at (and diffed) without
 * running the whole game.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render/pvr2.h"

static uint32_t *read_words(const char *path, unsigned *count)
{
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open %s\n", path); return NULL; }
    fseek(f, 0, SEEK_END);
    const long bytes = ftell(f);
    fseek(f, 0, SEEK_SET);
    const unsigned n = (unsigned)(bytes / 4);
    uint32_t *words = malloc((size_t)n * 4 ? (size_t)n * 4 : 4);
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

static int write_ppm(const char *path, const vf3_pvr2 *pvr, unsigned w, unsigned h)
{
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write %s\n", path); return -1; }
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    for (unsigned i = 0; i < w * h; ++i) {
        const uint32_t px = vf3_pvr2_pixel(pvr, i % w, i / w);
        const unsigned char rgb[3] = {
            (unsigned char)((px >> 16) & 0xFFu),
            (unsigned char)((px >> 8) & 0xFFu),
            (unsigned char)(px & 0xFFu)
        };
        fwrite(rgb, 1, 3, f);
    }
    fclose(f);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "usage: %s <ta.bin> <pvr2_state.bin> <out.ppm>\n", argv[0]);
        return 2;
    }
    unsigned n = 0;
    uint32_t *words = read_words(argv[1], &n);
    if (!words) return 2;

    vf3_pvr2 pvr;
    vf3_pvr2_init(&pvr);
    if (vf3_pvr2_load_state(&pvr, argv[2]) != 0) {
        fprintf(stderr, "cannot load the PVR2 state %s\n", argv[2]);
        free(words);
        vf3_pvr2_free(&pvr);
        return 2;
    }
    printf("framebuffer %ux%u, stride %u, base %08x, pack %u, clip %u..%u %u..%u\n",
           pvr.fb_width, pvr.fb_height, pvr.fb_stride, pvr.fb_base, pvr.pack_mode,
           pvr.clip_x0, pvr.clip_x1, pvr.clip_y0, pvr.clip_y1);

    vf3_ta_list list;
    const int rc = vf3_ta_decode(words, n, &list);
    if (rc) {
        fprintf(stderr, "the stream did not parse at word %u (block %u)\n",
                list.words, list.blocks);
        vf3_ta_free(&list);
        free(words);
        vf3_pvr2_free(&pvr);
        return 1;
    }
    printf("blocks %u, primitives %u, lists %u, invalid %u, vertices %u\n",
           list.blocks, list.count, list.lists, list.invalid, list.vcount);

    const unsigned pixels = vf3_pvr2_rasterise(&pvr, &list);
    printf("triangles %u, pixels %u, textured %u\n",
           pvr.stats.triangles, pixels, pvr.stats.textured);
    if (write_ppm(argv[3], &pvr, VF3_PVR2_WIDTH, VF3_PVR2_HEIGHT) != 0) {
        vf3_ta_free(&list);
        free(words);
        vf3_pvr2_free(&pvr);
        return 2;
    }
    printf("wrote %s\n", argv[3]);
    vf3_ta_free(&list);
    free(words);
    vf3_pvr2_free(&pvr);
    return 0;
}
