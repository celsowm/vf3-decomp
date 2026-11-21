/* Differential replay of the native texture-cell loader (src/native/tex_cell_load.c,
 * 0x8C07B4D4) against the readable guest port (src/fight/sprite_uv.c,
 * `vf3_tex_cell_load_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free body (integer
 * field extraction plus a float from-int / fdiv / fmul pipeline; no guest
 * callees).  `r4` = cell id: ids with bit 0x4000 select a six-byte record at
 * 0x0C11ABB0, others the pair table at 0x0C11AA60.  The cell's rectangle
 * (x8 as floats) lands at SCRATCH+0..+12, the reciprocal-scaled UV extents
 * at +0x30/+0x34/+0x38/+0x3C, the id at +0x40.
 *
 * The fixture seeds both tables (and their pair-table entries), and runs the
 * two sides from the same seed.  The scratch block, the recip/U/V words, the
 * contract registers, FR2..FR4, FPUL, pr and SR's T bit are compared. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "tex_cell_load.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_tex_cell_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define CELL_RECORDS 0x0C11ABB0u
#define CELL_PAIRS 0x0C11AA60u
#define SCRATCH 0x0C1B9620u
#define SCRATCH_RECIP_W 0x0C1B9630u
#define SCRATCH_RECIP_H 0x0C1B9634u
#define SCRATCH_U 0x0C1B9638u
#define SCRATCH_V 0x0C1B963Cu
#define SCRATCH_ID 0x0C1B9640u

#define REC_LO 0x0c11aa60u
#define REC_HI 0x0c11b000u
#define SCR_LO 0x0c1b9620u
#define SCR_HI 0x0c1b9650u

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

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

struct scenario {
    const char *name;
    uint32_t id;                 /* the cell id in r4 */
    uint32_t cell_flag;          /* 1 = use the six-byte records table */
    uint16_t rec0;               /* record's u16 id (cell-flag path) */
    uint8_t b2, b3, b4, b5;      /* record's four byte fields */
    uint32_t pair_id;            /* which pair entry the rec id / pair id indexes */
    uint16_t pw, ph;             /* that pair entry's two u16 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr, const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->id;
    s->v[15] = 0x0c04f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;      /* single precision, RM bit 0 (toward zero) */
    s->v[14] = 0x76543220u;
    s->v[13] = 0x7654321fu;
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
    for (uint32_t ad = REC_LO; ad < REC_HI; ad += 4) w32(ad, 0x0badf00du);
    for (uint32_t ad = SCR_LO; ad < SCR_HI; ad += 4) w32(ad, 0x0badf00du);

    const uint32_t pair_index = sc->pair_id;
    w16(CELL_PAIRS + 4u * pair_index, sc->pw);
    w16(CELL_PAIRS + 4u * pair_index + 2u, sc->ph);

    if (sc->cell_flag) {
        const uint32_t idx = sc->id & 0x3FFFu;
        const uint32_t rec = CELL_RECORDS + 6u * idx;
        w16(rec, sc->rec0);
        ab(rec + 2u)[0] = sc->b2;
        ab(rec + 3u)[0] = sc->b3;
        ab(rec + 4u)[0] = sc->b4;
        ab(rec + 5u)[0] = sc->b5;
        /* the record's own id indexes the pair table too */
        w16(CELL_PAIRS + 4u * (sc->rec0 & 0xFFFFu), sc->pw);
        w16(CELL_PAIRS + 4u * (sc->rec0 & 0xFFFFu) + 2u, sc->ph);
    } else {
        /* the pair path's id IS the pair index */
        w16(CELL_PAIRS + 4u * sc->id, sc->pw);
        w16(CELL_PAIRS + 4u * sc->id + 2u, sc->ph);
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c07b54au;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_tex_cell_load_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the scratch + tables */
    const size_t s0 = SCR_HI - SCR_LO, s1 = REC_HI - REC_LO;
    uint8_t *snap = (uint8_t *)malloc(s0 + s1);
    memcpy(snap, ab(SCR_LO), s0);
    memcpy(snap + s0, ab(REC_LO), s1);

    const uint32_t g_regs[7] = { gs.v[0], gs.v[1], gs.v[2], gs.v[3],
                                 gs.v[4], gs.v[5], gs.v[53] };
    const uint32_t g_sr_T = gs.v[17] & 1u;
    const float g_fr2 = vf3_fr_get(&gs, 2), g_fr3 = vf3_fr_get(&gs, 3),
                g_fr4 = vf3_fr_get(&gs, 4);

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->id;
    a.r[15] = 0x0c04f000u;
    a.r[14] = 0x76543220u;
    a.r[13] = 0x7654321fu;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    vf3_native_tex_cell_load(&a);

    int bad = 0;

    /* RAM regions */
    {
        int nb = 0;
        for (uint32_t ad = SCR_LO; ad < SCR_HI; ad += 4) {
            uint32_t g; memcpy(&g, snap + (ad - SCR_LO), 4);
            if (g != r32(ad)) { if (nb < 10) fprintf(stderr, "  scr @%08x: got %08x want %08x\n", ad, r32(ad), g); nb++; }
        }
        for (uint32_t ad = REC_LO; ad < REC_HI; ad += 4) {
            uint32_t g; memcpy(&g, snap + s0 + (ad - REC_LO), 4);
            if (g != r32(ad)) { if (nb < 10) fprintf(stderr, "  table @%08x differs\n", ad); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + FR + FPUL + pr + SR T */
    {
        int nb = 0;
        if (a.r[0] != g_regs[0]) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], g_regs[0]); nb++; }
        if (a.r[1] != g_regs[1]) { fprintf(stderr, "  r1 %08x want %08x\n", a.r[1], g_regs[1]); nb++; }
        if (a.r[2] != g_regs[2]) { fprintf(stderr, "  r2 %08x want %08x\n", a.r[2], g_regs[2]); nb++; }
        if (a.r[3] != g_regs[3]) { fprintf(stderr, "  r3 %08x want %08x\n", a.r[3], g_regs[3]); nb++; }
        if (a.r[4] != g_regs[4]) { fprintf(stderr, "  r4 %08x want %08x\n", a.r[4], g_regs[4]); nb++; }
        if (a.r[5] != g_regs[5]) { fprintf(stderr, "  r5 %08x want %08x\n", a.r[5], g_regs[5]); nb++; }
        if (a.fpul != g_regs[6]) { fprintf(stderr, "  fpul %08x want %08x\n", a.fpul, g_regs[6]); nb++; }
        if ((a.sr & 1u) != g_sr_T) { fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr_T); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        if (fbits(a.fr[2]) != fbits(g_fr2)) { fprintf(stderr, "  fr2 differs\n"); nb++; }
        if (fbits(a.fr[3]) != fbits(g_fr3)) { fprintf(stderr, "  fr3 differs\n"); nb++; }
        if (fbits(a.fr[4]) != fbits(g_fr4)) { fprintf(stderr, "  fr4 differs\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model: scratch +0..+12 are the four fields <<3 as
     * floats; recip_w = 1/(pw<<3), u = (w<<3)*recip_w, etc. (rough sanity
     * check; exact rounding proved by the byte-for-byte comparison above) */
    {
        int nb = 0;
        uint32_t x, y, w, h;
        if (sc->cell_flag) {
            x = sc->b2; y = sc->b3; w = sc->b4; h = sc->b5;
        } else {
            x = y = 0; w = sc->pw; h = sc->ph;
        }
        const float fx = (float)(x << 3), fy = (float)(y << 3);
        const float fw = (float)(w << 3), fh = (float)(h << 3);
        const float ep = (float)1e-3;
        uint32_t r; float f;
        r = r32(SCRATCH + 0); memcpy(&f, &r, 4);
        if (fabsf(f - fx) > ep) { fprintf(stderr, "  scratch x %.9g want %.9g\n", f, fx); nb++; }
        r = r32(SCRATCH + 4); memcpy(&f, &r, 4);
        if (fabsf(f - fy) > ep) { fprintf(stderr, "  scratch y %.9g want %.9g\n", f, fy); nb++; }
        r = r32(SCRATCH + 8); memcpy(&f, &r, 4);
        if (fabsf(f - fw) > ep) { fprintf(stderr, "  scratch w %.9g want %.9g\n", f, fw); nb++; }
        r = r32(SCRATCH + 12); memcpy(&f, &r, 4);
        if (fabsf(f - fh) > ep) { fprintf(stderr, "  scratch h %.9g want %.9g\n", f, fh); nb++; }
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
        printf("tex_cell_load_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "pair id 0",   .id = 3,  .cell_flag = 0, .pair_id = 0,
          .pw = 2, .ph = 4 },
        { .name = "pair id large", .id = 300, .cell_flag = 0, .pair_id = 0,
          .pw = 16, .ph = 32 },
        { .name = "cell flag",   .id = 0x4000u | 5u, .cell_flag = 1,
          .rec0 = 0x0007u, .b2 = 1, .b3 = 2, .b4 = 3, .b5 = 4, .pair_id = 0,
          .pw = 8, .ph = 16 },
        { .name = "cell flag big", .id = 0x4000u | 0x3FFu, .cell_flag = 1,
          .rec0 = 0x0012u, .b2 = 100, .b3 = 200, .b4 = 50, .b5 = 40, .pair_id = 0,
          .pw = 24, .ph = 48 },
        { .name = "cell flag signed id", .id = 0x4000u | 7u, .cell_flag = 1,
          .rec0 = 0x8003u, .b2 = 1, .b3 = 2, .b4 = 3, .b5 = 4, .pair_id = 0,
          .pw = 8, .ph = 16 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("tex_cell_load_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
