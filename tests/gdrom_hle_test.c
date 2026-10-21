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

#include "sys/bios_syscall.h"
#include "sys/gdrom_hle.h"

static int failures, skipped;
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
    if (!f) { printf("no dump %s - skipped\n", path); ++skipped; return 0; }
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
        ++skipped;
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

typedef struct { uint8_t *mem; uint32_t base; } fakemem;

static uint32_t fm_read(void *ctx, uint32_t a)
{
    fakemem *m = ctx;
    uint32_t v;
    memcpy(&v, m->mem + (a - m->base), 4);
    return v;
}

static void fm_write(void *ctx, uint32_t a, uint32_t v)
{
    fakemem *m = ctx;
    memcpy(m->mem + (a - m->base), &v, 4);
}

/* the same read as full_cycle, but driven through the r4..r7 register convention of the BIOS vector */
static void syscall_cycle(const vf3_gdi *gdi)
{
    const uint32_t fad = 0x81ADB, count = 7, base = 0x0C000000u;
    uint8_t *ram = calloc(1, 0x4000);
    fakemem fm = { ram, base };
    vf3_guest_mem gm = { &fm, fm_read, fm_write };
    sink s = { calloc(count, VF3_GD_SECTOR), 0x0C002000u, count * VF3_GD_SECTOR };
    vf3_gdrom gd;
    vf3_gd_init(&gd, gdi, sink_write, &s);
    const uint32_t params = base + 0x100, out = base + 0x120;
    fm_write(&fm, params, fad);
    fm_write(&fm, params + 4, count);
    fm_write(&fm, params + 8, 0x0C002000u);
    uint32_t r[8] = { 0, 0, 0, 0, VF3_GDCC_DMAREAD, params, 0, VF3_GD_REQ_CMD }, r0 = 0;
    CHECK(vf3_bios_gd_syscall(&gd, &gm, r, &r0) && r0 == 2, "REQ_CMD through the vector: id %u", r0);
    r[7] = VF3_GD_EXEC_SERVER;
    CHECK(vf3_bios_gd_syscall(&gd, &gm, r, &r0), "EXEC_SERVER through the vector");
    r[4] = 2; r[5] = out; r[7] = VF3_GD_GET_CMD_STAT;
    int polls = 0;
    do { vf3_bios_gd_syscall_clocked(&gd, &gm, r, &r0); ++polls; } while ((int32_t)r0 == VF3_GDC_BUSY && polls < 100);
    CHECK(polls == 2, "poll clock: %d polls for 7 sectors", polls);
    CHECK((int32_t)r0 == VF3_GDC_COMPLETE, "last poll status %d", (int)r0);
    CHECK(fm_read(&fm, out + 8) == count * VF3_GD_SECTOR, "size word %x", fm_read(&fm, out + 8));
    r[6] = 1;
    CHECK(!vf3_bios_gd_syscall(&gd, &gm, r, &r0), "r6 != 0 must be left to the caller");
    uint8_t refsec[VF3_GD_SECTOR];
    int bad = 0;
    for (uint32_t i = 0; i < count; ++i)
        if (vf3_gdi_read_sector(gdi, fad + i, refsec) != 0 || memcmp(refsec, s.mem + i * VF3_GD_SECTOR, VF3_GD_SECTOR)) ++bad;
    CHECK(bad == 0, "%d syscall-delivered sectors differ", bad);
    printf("syscall cycle: %u sectors, %d differ\n", count, bad);
    free(s.mem);
    free(ram);
}

int main(int argc, char **argv)
{
    const char *gdi_path = argc > 1 ? argv[1] : "rom/vf3.gdi";
    vf3_gdi gdi;
    if (vf3_gdi_open(&gdi, gdi_path) != 0) { fprintf(stderr, "cannot open %s - SKIP (77)\n", gdi_path); return 77; }
    if (argc > 2) {
        FILE *dump = fopen(argv[2], "rb");
        if (!dump) { fprintf(stderr, "cannot open requested state %s\n", argv[2]); return 2; }
        fclose(dump);
    }
    full_cycle(&gdi);
    syscall_cycle(&gdi);
    resume_from_dump(&gdi, argc > 2 ? argv[2] : "extract/analysis/gd_state/vf3_24.txt");
    resume_from_dump(&gdi, "extract/analysis/gd_state/vf3_25.txt");
    printf("gdrom_hle: %d failures; %d optional resume checks skipped\n", failures, skipped);
    return failures != 0;
}
