/* Differential replay of the native sprite near-corner helper
 * (src/native/sprite_rect_a.c, 0x8C07B35C) against the readable guest port
 * (src/fight/sprite_uv.c, `vf3_sprite_rect_a_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free, branch-free
 * FP body with no stack.  FR4/FR5 = x/y, FR6/FR7 = w/h, FR8 = z; the four
 * screen constants are read out of fixed data addresses.  Position, z and UV
 * extent are stored at block +4..+20, and the results ride in FR3..FR5 and
 * FR9..FR11.
 *
 * The fixture seeds the block and the FR bank (and the four constant data
 * words), and runs the two sides from the same seed.  The block is compared
 * byte for byte, together with the contract registers and the FR bank, and
 * the stored floats are verified against an independent fixture model. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "sprite_rect_a.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_sprite_rect_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define BLOCK_ADDR 0x0c16c000u
#define BLOCK_LO 0x0c16c000u
#define BLOCK_HI 0x0c16c100u

#define SCALE_X 0x0C10B7FCu
#define SCALE_Y 0x0C10B800u
#define OFFSET_X 0x0C10B804u
#define OFFSET_Y 0x0C10B808u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float f)
{
    uint32_t u; memcpy(&u, &f, 4); w32(addr, u);
}
static uint32_t r32(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

struct scenario {
    const char *name;
    float sx, sy, ox, oy;        /* the four screen constants */
    float x, y, w, h, z;
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr, const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = BLOCK_ADDR;
    s->v[15] = 0x0c04f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;      /* single precision, RM bit 0 (toward zero) */
    s->budget = 4000000u;
    VF3_FR(s, 4) = fbits(sc->x);
    VF3_FR(s, 5) = fbits(sc->y);
    VF3_FR(s, 6) = fbits(sc->w);
    VF3_FR(s, 7) = fbits(sc->h);
    VF3_FR(s, 8) = fbits(sc->z);

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
    for (uint32_t ad = BLOCK_LO; ad < BLOCK_HI; ad += 4) w32(ad, 0x0badf00du);
    wf(SCALE_X, sc->sx);
    wf(SCALE_Y, sc->sy);
    wf(OFFSET_X, sc->ox);
    wf(OFFSET_Y, sc->oy);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c07b37cu;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_sprite_rect_a_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the block */
    const size_t l0 = BLOCK_HI - BLOCK_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(BLOCK_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r2 = gs.v[2], g_r3 = gs.v[3],
                   g_r5 = gs.v[5], g_r6 = gs.v[6];
    const float g_fr3 = vf3_fr_get(&gs, 3), g_fr4 = vf3_fr_get(&gs, 4),
                g_fr5 = vf3_fr_get(&gs, 5), g_fr9 = vf3_fr_get(&gs, 9),
                g_fr10 = vf3_fr_get(&gs, 10), g_fr11 = vf3_fr_get(&gs, 11);

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = BLOCK_ADDR;
    a.r[15] = 0x0c04f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    a.fr[4] = sc->x; a.fr[5] = sc->y; a.fr[6] = sc->w; a.fr[7] = sc->h;
    a.fr[8] = sc->z;
    vf3_native_sprite_rect_a(&a);

    int bad = 0;

    /* RAM block */
    {
        int nb = 0;
        for (uint32_t ad = BLOCK_LO; ad < BLOCK_HI; ad += 4) {
            uint32_t g; memcpy(&g, snap + (ad - BLOCK_LO), 4);
            if (g != r32(ad)) { if (nb < 10) fprintf(stderr, "  block @%08x: got %08x want %08x\n", ad, r32(ad), g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + FR */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        if (fbits(a.fr[3]) != fbits(g_fr3)) { fprintf(stderr, "  fr3 differs\n"); nb++; }
        if (fbits(a.fr[4]) != fbits(g_fr4)) { fprintf(stderr, "  fr4 differs\n"); nb++; }
        if (fbits(a.fr[5]) != fbits(g_fr5)) { fprintf(stderr, "  fr5 differs\n"); nb++; }
        if (fbits(a.fr[9]) != fbits(g_fr9)) { fprintf(stderr, "  fr9 differs\n"); nb++; }
        if (fbits(a.fr[10]) != fbits(g_fr10)) { fprintf(stderr, "  fr10 differs\n"); nb++; }
        if (fbits(a.fr[11]) != fbits(g_fr11)) { fprintf(stderr, "  fr11 differs\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model: x = x*sx+ox, etc. (a rough sanity check;
     * exact rounding is proved by the byte-for-byte comparison above) */
    {
        int nb = 0;
        const float x = sc->x * sc->sx + sc->ox;
        const float y = sc->y * sc->sy + sc->oy;
        const float uw = sc->sx * sc->w;
        const float vh = sc->sy * sc->h;
        const float ep = (float)1e-4 * (1.0f + fabsf(x) + fabsf(y) + fabsf(uw) + fabsf(vh));
        uint32_t bx = r32(BLOCK_ADDR + 4), by = r32(BLOCK_ADDR + 8),
                 buw = r32(BLOCK_ADDR + 16), bvh = r32(BLOCK_ADDR + 20),
                 bz = r32(BLOCK_ADDR + 12);
        float fx, fy, fuw, fvh, fz;
        memcpy(&fx, &bx, 4); memcpy(&fy, &by, 4);
        memcpy(&fuw, &buw, 4); memcpy(&fvh, &bvh, 4); memcpy(&fz, &bz, 4);
        if (fabsf(fx - x) > ep) { fprintf(stderr, "  x %.9g want %.9g\n", fx, x); nb++; }
        if (fabsf(fy - y) > ep) { fprintf(stderr, "  y %.9g want %.9g\n", fy, y); nb++; }
        if (fabsf(fuw - uw) > ep) { fprintf(stderr, "  uw %.9g want %.9g\n", fuw, uw); nb++; }
        if (fabsf(fvh - vh) > ep) { fprintf(stderr, "  vh %.9g want %.9g\n", fvh, vh); nb++; }
        if (fbits(fz) != fbits(sc->z)) { fprintf(stderr, "  z differs\n"); nb++; }
        if (a.r[0] != 20u) { fprintf(stderr, "  r0 %08x want 20\n", a.r[0]); nb++; }
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
        printf("sprite_rect_a_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "origin", .sx = 1.0f, .sy = 1.0f, .ox = 0.0f, .oy = 0.0f,
          .x = 10.0f, .y = 20.0f, .w = 5.0f, .h = 6.0f, .z = 100.0f },
        { .name = "scaled", .sx = 2.0f, .sy = 0.5f, .ox = 1.5f, .oy = -2.25f,
          .x = 10.25f, .y = -3.5f, .w = 2.0f, .h = 4.0f, .z = -8.0f },
        { .name = "negative", .sx = -1.0f, .sy = 3.0f, .ox = 0.5f, .oy = 0.25f,
          .x = -8.0f, .y = 6.0f, .w = 1.5f, .h = 2.5f, .z = 0.25f },
        { .name = "big", .sx = 2.5f, .sy = 4.0f, .ox = 100.0f, .oy = 200.0f,
          .x = 30.0f, .y = 40.0f, .w = 10.0f, .h = 20.0f, .z = 1000.0f },
        { .name = "small", .sx = 0.125f, .sy = 0.25f, .ox = 0.0f, .oy = 0.0f,
          .x = 0.5f, .y = 0.75f, .w = 0.25f, .h = 0.125f, .z = 1.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("sprite_rect_a_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
