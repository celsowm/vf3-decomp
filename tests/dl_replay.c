/* tests/dl_replay.c — M38: run the DL assembler on the real POL fixture. */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "../src/media/pol.h"

typedef struct VF3_DrawPart_ {
    uint16_t part_id;
    uint16_t flags;
    uint32_t geom_off;
    uint32_t triples;
    float    bbox_min[3];
    float    bbox_max[3];
} VF3_DrawPart;
typedef struct { PolHeader hdr; uint32_t n_parts; } VF3_DlScene;

int vf3_dl_from_pol(const void *data, uint32_t size, VF3_DlScene *out,
                    uint32_t *vtx_triples_total);

static int fails = 0;
#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

int main(void)
{
    const char *path = "extract/gamedata/GEN_DMY5.BIN";
    FILE *f = fopen(path, "rb");
    if (!f) { printf("dl_replay: SKIP (no fixture)\n"); return 0; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t *buf = malloc(sz);
    fread(buf, 1, sz, f);
    fclose(f);

    VF3_DlScene sc;
    uint32_t triples = 0;
    int rc = vf3_dl_from_pol(buf, (uint32_t)sz, &sc, &triples);
    CHK(rc == 0);
    CHK(sc.hdr.hdr_marker == 0x200);
    CHK(sc.n_parts > 0);
    CHK(sc.hdr.table_base == 0x30);
    CHK(triples > 0);
    printf("  GEN_DMY5: parts=%u triples=%u geom=%u span=%u\n",
           sc.n_parts, triples, sc.hdr.geom_size, sc.hdr.table_span);

    CHK(vf3_dl_from_pol(buf, 8, &sc, &triples) != 0);   /* truncated */
    CHK(vf3_dl_from_pol(NULL, sz, &sc, &triples) != 0);

    printf("dl_replay: %s\n", fails ? "FAIL" : "PASS");
    free(buf);
    return fails ? 1 : 0;
}
