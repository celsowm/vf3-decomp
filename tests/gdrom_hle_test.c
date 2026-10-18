/* gdrom_hle_test.c - exercise sys/gdrom_hle on the real disc image (rom/vf3.gdi, never committed).
 *
 *   vf3gdrom [gdi] [gd_state dump]
 *
 * 1. A full REQ_CMD -> GET_CMD_STAT -> EXEC_SERVER -> scheduler ticks -> GET_CMD_STAT cycle for a 0x4B-sector DMA read
 *    (the request savestate 24 is in the middle of) must report BUSY until the last tick, then COMPLETE once, then idle,
 *    and deliver exactly the sectors the reader returns.
 * 2. Resuming from the dumped command state of a boot savestate (extract/analysis/gd_state/vf3_<N>.txt) must finish
 *    with result[2] = total * 2048 and the remaining sectors landing at the dumped cursor. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sys/gdrom_hle.h"

static int failures;
#define CHECK(c, ...) do { if (!(c)) { ++failures; printf("FAIL %s:%d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

typedef struct { uint8_t *mem; uint32_t base, len; } sink;

static void sink_write(void *ctx, uint32_t addr, const uint8_t *data, uint32_t len)
{
    sink *s = ctx;
    if (addr >= s->base && addr - s->base + len <= s->len) memcpy(s->mem + (addr - s->base), data, len);
}

static int full_cycle(const vf3_gdi *gdi)
{
    const uint32_t fad = 0x81ADB, count = 0x4B, dest = 0x0CBA8000u;
    sink s = { calloc(count, VF3_GD_SECTOR), dest, count * VF3_GD_SECTOR };
    vf3_gdrom gd;
    vf3_gd_init(&gd, gdi, sink_write, &s);
    uint32_t params[4] = { fad, count, dest, 0 }, ext[4];
    const uint32_t id = vf3_gd_req_cmd(&gd, VF3_GDCC_DMAREAD, params);
    CHECK(id == 2, "first request id %u", id);
    CHECK(vf3_gd_req_cmd(&gd, VF3_GDCC_DMAREAD, params) == 0, "second request must be refused while busy");
    CHECK(vf3_gd_get_cmd_stat(&gd, id, ext) == VF3_GDC_BUSY, "status after REQ_CMD");
    vf3_gd_exec_server(&gd);
    vf3_gd_exec_server(&gd);                 /* a second EXEC_SERVER must not re-arm */
    CHECK(gd.st.multi_read_count == count, "armed count %u", gd.st.multi_read_count);
    uint32_t steps = 0, moved = 0, n;
    while ((n = vf3_gd_sched_step(&gd)) != 0) {
        ++steps;
        moved += n;
        CHECK(vf3_gd_get_cmd_stat(&gd, id, ext) == (moved == count ? VF3_GDC_COMPLETE : VF3_GDC_BUSY) ||
              moved == count, "status while moving (%u/%u)", moved, count);
        if (moved == count) break;
        CHECK(ext[2] == moved * VF3_GD_SECTOR, "size word %u after %u sectors", ext[2], moved);
    }
    CHECK(steps == 15 && moved == count, "steps %u moved %u", steps, moved);
    /* the in-loop status query above already reported COMPLETE and cleared it */
    CHECK(vf3_gd_get_cmd_stat(&gd, id, ext) == VF3_GDC_OK, "status after completion was consumed");
    uint8_t ref[VF3_GD_SECTOR];
    int bad = 0;
    for (uint32_t i = 0; i < count; ++i)
        if (vf3_gdi_read_sector(gdi, fad + i, ref) != 0 || memcmp(ref, s.mem + i * VF3_GD_SECTOR, VF3_GD_SECTOR)) ++bad;
    CHECK(bad == 0, "%d sectors differ from the reader", bad);
    printf("full cycle: %u steps, %u sectors, %d differ\n", steps, moved, bad);
    free(s.mem);
    return 0;
}

static int resume_from_dump(const vf3_gdi *gdi, const char *path)
{
    FILE *f = fopen(path, "r");
    if (!f) { printf("no dump %s - skipped\n", path); return 0; }
    vf3_gd_state st;
    memset(&st, 0, sizeof st);
    char name[64];
    unsigned v;
    while (fscanf(f, "%63s %x", name, &v) == 2) {
        if (!strcmp(name, "status")) st.status = (int32_t)v;
        else if (!strcmp(name, "command")) st.command = v;
        else if (!strcmp(name, "params0")) st.params[0] = v;
        else if (!strcmp(name, "params1")) st.params[1] = v;
        else if (!strcmp(name, "params2")) st.params[2] = v;
        else if (!strcmp(name, "result2")) st.result[2] = v;
        else if (!strcmp(name, "multi_read_sector")) st.multi_read_sector = v;
        else if (!strcmp(name, "multi_read_offset")) st.multi_read_offset = v;
        else if (!strcmp(name, "multi_read_count")) st.multi_read_count = v;
        else if (!strcmp(name, "multi_read_total")) st.multi_read_total = v;
    }
    fclose(f);
    if (st.status != VF3_GDC_BUSY || st.command != VF3_GDCC_DMAREAD || !st.multi_read_count) {
        printf("dump %s is not a mid-transfer state - skipped\n", path);
        return 0;
    }
    const uint32_t first_off = st.multi_read_offset, first_sec = st.multi_read_sector, remain = st.multi_read_count;
    sink s = { calloc(remain, VF3_GD_SECTOR), first_off, remain * VF3_GD_SECTOR };
    vf3_gdrom gd;
    vf3_gd_init(&gd, gdi, sink_write, &s);
    gd.st = st;
    uint32_t moved = 0, n;
    while ((n = vf3_gd_sched_step(&gd)) != 0) moved += n;
    CHECK(moved == remain, "moved %u of %u", moved, remain);
    CHECK(gd.st.status == VF3_GDC_COMPLETE, "final status %d", gd.st.status);
    CHECK(gd.st.result[2] == st.multi_read_total * VF3_GD_SECTOR, "final size word %x", gd.st.result[2]);
    uint8_t ref[VF3_GD_SECTOR];
    int bad = 0;
    for (uint32_t i = 0; i < remain; ++i)
        if (vf3_gdi_read_sector(gdi, first_sec + i, ref) != 0 || memcmp(ref, s.mem + i * VF3_GD_SECTOR, VF3_GD_SECTOR)) ++bad;
    CHECK(bad == 0, "%d resumed sectors differ", bad);
    printf("resume %s: %u sectors from fad %x to %08x, final size %x, %d differ\n", path, moved, first_sec, first_off,
           gd.st.result[2], bad);
    free(s.mem);
    return 0;
}

int main(int argc, char **argv)
{
    const char *gdi_path = argc > 1 ? argv[1] : "rom/vf3.gdi";
    vf3_gdi gdi;
    if (vf3_gdi_open(&gdi, gdi_path) != 0) { printf("cannot open %s - skipped\n", gdi_path); return 0; }
    full_cycle(&gdi);
    resume_from_dump(&gdi, argc > 2 ? argv[2] : "extract/analysis/gd_state/vf3_24.txt");
    resume_from_dump(&gdi, "extract/analysis/gd_state/vf3_25.txt");
    printf(failures ? "gdrom_hle: %d FAILURES\n" : "gdrom_hle: all checks passed\n", failures);
    return failures != 0;
}
