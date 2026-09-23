/* vf3tool - dev CLI for the ported modules.
 *   vf3tool adpcm <out.pcm> <in.bin> [skip]
 * Decodes AICA ADPCM payload -> signed 16-bit LE PCM.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../src/media/aica_adpcm.h"
#include "../src/media/dtpk.h"
#include "../src/media/mt.h"
#include "../src/media/pol.h"
#include "../src/sys/gdfs.h"
#include "../src/sys/gdfs_table.h"

static void binname_dump(const char *name)
{
    /* table mounted from generated header */
    vf3_gdfs_mount_table((const VF3_GdfsEntry *)vf3_gdfs_table,
                         VF3_GDFS_TABLE_COUNT);
    int slot = vf3_gdfs_find(name);
    if (slot < 0) {
        printf("(not found)\n");
        return;
    }
    printf("slot=%d name=%s tag=%s kind=%d\n",
           slot, vf3_gdfs_table[slot].name,
           vf3_gdfs_tag(slot), vf3_gdfs_kind(slot));
}

static void cb_mt(uint32_t slot, uint32_t off, uint32_t len, void *ctx)
{
    (void)ctx;
    printf("%u,0x%06X,%u\n", slot, off, len);
}

static void cb_pol(uint32_t off, uint32_t triples, void *ctx)
{
    (void)ctx;
    printf("0x%08X %u\n", off, triples);
}

static uint8_t *slurp(const char *path, long *size)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return NULL;
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t *d = malloc(len);
    fread(d, 1, len, f);
    fclose(f);
    *size = len;
    return d;
}

int main(int argc, char **argv)
{
    if (argc >= 3 && !strcmp(argv[1], "mt")) {
        long len; uint8_t *d = slurp(argv[2], &len);
        if (!d) { perror(argv[2]); return 2; }
        MtFile f;
        if (mt_parse(d, (uint32_t)len, &f)) { printf("(no table)\n"); return 3; }
        printf("count=%u first=0x%06X\n", f.count, f.first_record_off);
        mt_each(&f, cb_mt, NULL);
        free(d);
        return 0;
    }
    if (argc >= 3 && !strcmp(argv[1], "pol")) {
        long len; uint8_t *d = slurp(argv[2], &len);
        if (!d) { perror(argv[2]); return 2; }
        PolHeader h;
        if (pol_header(d, (uint32_t)len, &h)) { printf("(bad hdr)\n"); return 3; }
        printf("hdr build=0x%08X sig=0x%08X parts=%u/%u tbl=0x%X span=0x%X\n",
               h.build_stamp, h.sig, h.parts_lo, h.parts_hi,
               h.table_base, h.table_span);
        int n = pol_scan_floats(d, (uint32_t)len, 64, cb_pol, NULL);
        printf("blocks=%d\n", n);
        free(d);
        return 0;
    }

    if (argc >= 4 && !strcmp(argv[1], "adpcm")) {
        const char *out = argv[2], *in = argv[3];
        long skip = argc > 4 ? strtol(argv[4], NULL, 0) : 0;

        FILE *f = fopen(in, "rb");
        if (!f) { perror(in); return 2; }
        fseek(f, 0, SEEK_END);
        long len = ftell(f);
        fseek(f, skip, SEEK_SET);
        uint8_t *buf = malloc(len - skip);
        fread(buf, 1, len - skip, f);
        fclose(f);

        int16_t *pcm = malloc((len - skip) * 2 * sizeof(int16_t));
        AicaState st;
        aica_adpcm_init(&st);
        size_t n = aica_adpcm_decode(&st, buf, len - skip, pcm,
                                     (len - skip) * 2);
        FILE *o = fopen(out, "wb");
        fwrite(pcm, sizeof(int16_t), n, o);
        fclose(o);
        printf("%zu samples\n", n);
        free(buf);
        free(pcm);
        return 0;
    }
    if (argc >= 3 && !strcmp(argv[1], "binname")) {
        binname_dump(argv[2]);
        return 0;
    }
    fprintf(stderr, "usage: vf3tool adpcm <out.pcm> <in.bin> [skip]\n");
    fprintf(stderr, "       vf3tool mt|pol|binname <file|name>\n");
    return 1;
}
