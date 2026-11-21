/* Differential replay of the native clamp-cell leaf (src/native/clamp_cell.c,
 * 0x8C055B28) against the readable guest port (src/fight/misc_wrappers.c,
 * `vf3_clamp_cell_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FP and no stack frame: it sign-extends the halfword at R4+2, clamps
 * it to a cell number (below 9 keeps itself, 9..16 -> 9, 17+ -> 10), stores
 * four times the clamped value at the global 0x0C058FDC, advances R4 by 4 and
 * tail-transfers to pr (untouched).
 *
 * The fixture lays out the cell halfword and the global, and runs the two
 * sides from the same seed.  The cell and global regions are compared byte
 * for byte, together with the contract registers (r0 = 4*clamped, r1 = the
 * global, r4 advanced, SR.T) and the stored global word. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "clamp_cell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_clamp_cell_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define CELL_ADDR 0x0c16c000u         /* the cell: halfword at +2 */
#define GLOB_ADDR 0x0c058fdCu         /* the global */

#define CELL_LO 0x0c16c000u
#define CELL_HI 0x0c16c100u
#define GLOB_LO 0x0c058000u
#define GLOB_HI 0x0c059000u

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

struct scenario {
    const char *name;
    int16_t hw;      /* the halfword at the cell + 2 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4;
    s->v[15] = 0x0c47f000u;
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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w16(CELL_ADDR + 2, (uint16_t)sc->hw);
    w32(GLOB_ADDR, 0x0F0F0F0Fu);
}

/* the clamp results, worked out from the fixture */
static void expect(const struct scenario *sc, uint32_t *r0, uint32_t *t)
{
    int32_t v = (int32_t)(int16_t)sc->hw;
    int32_t res;
    if (v >= 17)      { res = 10; *t = 1; }
    else if (v >= 9)  { res = 9;  *t = 1; }
    else              { res = v;  *t = 0; }
    *r0 = ((uint32_t)(int32_t)res) << 2;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c055b5au;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, CELL_ADDR, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_clamp_cell_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared regions */
    const size_t l0 = CELL_HI - CELL_LO, l1 = GLOB_HI - GLOB_LO;
    uint8_t *snap = (uint8_t *)malloc(l0 + l1);
    memcpy(snap, ab(CELL_LO), l0);
    memcpy(snap + l0, ab(GLOB_LO), l1);

    const uint32_t g_r0 = gs.v[0], g_r1 = gs.v[1], g_r4 = gs.v[4];
    const uint32_t g_r15 = gs.v[15], g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = CELL_ADDR;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_clamp_cell(&a);

    int bad = 0;

    /* RAM regions */
    {
        int nb = 0;
        for (uint32_t ad = CELL_LO; ad < CELL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - CELL_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  cell @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        for (uint32_t ad = GLOB_LO; ad < GLOB_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + l0 + (ad - GLOB_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  glob @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + fixture model */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15 differs\n"); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }

        uint32_t er0, et;
        expect(sc, &er0, &et);
        if (a.r[0] != er0) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], er0); nb++; }
        if ((a.sr & 1u) != et) { fprintf(stderr, "  T %u want %u\n", a.sr & 1u, et); nb++; }
        if (a.r[1] != GLOB_ADDR) { fprintf(stderr, "  r1 %08x want glob\n", a.r[1]); nb++; }
        if (a.r[4] != CELL_ADDR + 4u) { fprintf(stderr, "  r4 %08x want cell+4\n", a.r[4]); nb++; }
        if (vf3_aim_u32(&a, GLOB_ADDR) != er0) {
            fprintf(stderr, "  global word %08x want %08x\n", vf3_aim_u32(&a, GLOB_ADDR), er0); nb++;
        }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
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
        printf("clamp_cell_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "value 5", .hw = 5 },
        { .name = "value 0", .hw = 0 },
        { .name = "value 8", .hw = 8 },
        { .name = "value 9", .hw = 9 },
        { .name = "value 12", .hw = 12 },
        { .name = "value 16", .hw = 16 },
        { .name = "value 17", .hw = 17 },
        { .name = "value 100", .hw = 100 },
        { .name = "value -1", .hw = -1 },
        { .name = "value -32768", .hw = (int16_t)0x8000 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("clamp_cell_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
