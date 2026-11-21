/* Differential replay of the native pool-allocator leaf (src/native/pool_alloc.c,
 * 0x8C07B2BE) against the readable guest port (src/fight/glyph_cache.c,
 * `vf3_pool_alloc_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FP and no stack frame.  The layer (r4) keeps a pool of 120
 * 68-byte entries at *(layer+12) and a rotating cursor (u16 at layer+42); an
 * entry is free when its first halfword is zero.
 *
 * The fixture lays out the layer, the pool and (for the full path) the
 * full-table registers, and runs the two sides from the same seed.  The
 * layer/pool/full regions are compared byte for byte, together with the
 * contract registers and the independent model of which entry is handed out. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "pool_alloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pool_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define LAYER_ADDR 0x0c16c000u
#define LAYER_LO 0x0c16c000u
#define LAYER_HI 0x0c16c100u
#define POOL_ADDR 0x0c16d000u
#define POOL_LO 0x0c16d000u
#define POOL_HI 0x0c16de00u      /* 120 * 68 = 8160 = 0x1FE0 */

#define FULL_TABLE 0x0C29F2F0u
#define FULL_LO 0x0c29f2f0u
#define FULL_HI 0x0c29f380u

#define ENTRY_BYTES 68u
#define LAYER_POOL 12u
#define LAYER_CURSOR 42u

#define POOL_ENTRIES 120u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
static uint32_t r32(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static int16_t r16(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (int16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

struct scenario {
    const char *name;
    uint16_t cursor;         /* the layer's cursor */
    uint16_t free_at;        /* the first entry index that is free (or 0xFFFF = none) */
    uint16_t nfree;          /* how many of the leading entries are free (1 = just the one) */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = LAYER_ADDR;
    s->v[15] = 0x0c04f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

/* make every pool entry "taken" except the `nfree` entries starting at
 * `free_at` (and the cursor's own entry when it is free) */
static void seed_pool(const struct scenario *sc)
{
    /* everything taken first */
    for (uint32_t i = 0; i < POOL_ENTRIES; ++i)
        w16(POOL_ADDR + i * ENTRY_BYTES, 0x1234u);
    if (sc->free_at != 0xFFFFu)
        for (uint16_t i = 0; i < sc->nfree; ++i)
            w16(POOL_ADDR + (sc->free_at + i) * ENTRY_BYTES, 0u);
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w32(LAYER_ADDR + LAYER_POOL, POOL_ADDR);
    w16(LAYER_ADDR + LAYER_CURSOR, sc->cursor);
    seed_pool(sc);
}

/* the independent model: which entry does the guest hand out? */
static void expect(const struct scenario *sc, uint32_t *r0, uint16_t *cursor_next,
                   int *full)
{
    const uint32_t cursor = sc->cursor;
    uint32_t entry = POOL_ADDR + cursor * ENTRY_BYTES;
    if (r16(entry) == 0) {
        *full = 0;
        uint16_t next = (uint16_t)(cursor + 1);
        if (next >= 120) next = 0;
        *cursor_next = next;
        *r0 = entry;
        return;
    }
    /* scan from base */
    entry = POOL_ADDR;
    for (uint32_t i = 0; i < POOL_ENTRIES; ++i) {
        if (r16(entry) == 0) { *full = 0; *cursor_next = sc->cursor; *r0 = entry; return; }
        entry += ENTRY_BYTES;
    }
    *full = 1;
    *cursor_next = sc->cursor;
    *r0 = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c07b2f2u;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_pool_alloc_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared regions */
    const size_t l0 = LAYER_HI - LAYER_LO, l1 = POOL_HI - POOL_LO, l2 = FULL_HI - FULL_LO;
    uint8_t *snap = (uint8_t *)malloc(l0 + l1 + l2);
    memcpy(snap, ab(LAYER_LO), l0);
    memcpy(snap + l0, ab(POOL_LO), l1);
    memcpy(snap + l0 + l1, ab(FULL_LO), l2);

    const unsigned g_v[8] = { gs.v[0], gs.v[1], gs.v[2], gs.v[3],
                              gs.v[5], gs.v[6], gs.v[7], gs.v[17] };
#define GV(i) g_v[i]

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = LAYER_ADDR;
    a.r[15] = 0x0c04f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_pool_alloc(&a);

    int bad = 0;

    /* RAM regions */
    {
        int nb = 0;
        for (uint32_t ad = LAYER_LO; ad < LAYER_HI; ad += 4) {
            uint32_t g = 0; memcpy(&g, snap + (ad - LAYER_LO), 4);
            if (g != vf3_aim_u32(&a, ad)) { if (nb < 10) fprintf(stderr, "  layer @%08x differs\n", ad); nb++; }
        }
        for (uint32_t ad = POOL_LO; ad < POOL_HI; ad += 4) {
            uint32_t g = 0; memcpy(&g, snap + l0 + (ad - POOL_LO), 4);
            if (g != vf3_aim_u32(&a, ad)) { if (nb < 10) fprintf(stderr, "  pool @%08x differs\n", ad); nb++; }
        }
        for (uint32_t ad = FULL_LO; ad < FULL_HI; ad += 4) {
            uint32_t g = 0; memcpy(&g, snap + l0 + l1 + (ad - FULL_LO), 4);
            if (g != vf3_aim_u32(&a, ad)) { if (nb < 10) fprintf(stderr, "  full @%08x differs\n", ad); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers */
    {
        int nb = 0;
        if (a.r[0] != GV(0)) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], GV(0)); nb++; }
        if (a.r[1] != GV(1)) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], GV(1)); nb++; }
        if (a.r[2] != GV(2)) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], GV(2)); nb++; }
        if (a.r[3] != GV(3)) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], GV(3)); nb++; }
        if (a.r[5] != GV(4)) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], GV(4)); nb++; }
        if (a.r[6] != GV(5)) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], GV(5)); nb++; }
        if (a.r[7] != GV(6)) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], GV(6)); nb++; }
        if ((a.sr & 1u) != (GV(7) & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent model */
    {
        int nb = 0;
        uint32_t er0 = 0; uint16_t ecn = 0; int efull = 0;
        expect(sc, &er0, &ecn, &efull);
        if (a.r[0] != er0) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], er0); nb++; }
        if (r16(LAYER_ADDR + LAYER_CURSOR) != (int16_t)ecn) {
            fprintf(stderr, "  cursor %d want %d\n", r16(LAYER_ADDR + LAYER_CURSOR), (int16_t)ecn); nb++;
        }
        if (efull) {
            /* full path: r0 = 0 and the full-table registers */
            if (a.r[2] != FULL_TABLE + 44u) { fprintf(stderr, "  full r2 %08x\n", a.r[2]); nb++; }
            if (a.r[5] != FULL_TABLE + 0x84u) { fprintf(stderr, "  full r5 %08x\n", a.r[5]); nb++; }
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("pool_alloc_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static struct scenario scenarios[] = {
        { .name = "cursor free",        .cursor = 0,   .free_at = 0u,    .nfree = 1 },
        { .name = "cursor free mid",    .cursor = 7,   .free_at = 7u,    .nfree = 1 },
        { .name = "cursor wraps",       .cursor = 119, .free_at = 119u,  .nfree = 1 },
        { .name = "cursor taken scan",  .cursor = 7,   .free_at = 12u,   .nfree = 1 },
        { .name = "cursor taken run",   .cursor = 7,   .free_at = 12u,   .nfree = 3 },
        { .name = "taken full",         .cursor = 7,   .free_at = 0xFFFFu, .nfree = 0 },
        { .name = "scan from base",     .cursor = 7,   .free_at = 0u,    .nfree = 1 },
        { .name = "scan near end",      .cursor = 40,  .free_at = 119u,  .nfree = 1 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("pool_alloc_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
