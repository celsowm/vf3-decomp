/* Differential replay of the native sprite far-corner UV helper
 * (src/native/sprite_rect_b.c, 0x8C07B398) against the readable guest port
 * (src/fight/sprite_uv.c, `vf3_sprite_rect_b_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free, branch-free
 * FP body with no stack.  FR4/FR5 are the near corner, FR6/FR7 its extent,
 * FR8/FR9 the UV scales; four floats (corner + bias) * scale are stored at
 * block +24..+36, and the results ride in FR1..FR5.
 *
 * The fixture seeds the block and the FR bank, and runs the two sides from
 * the same seed.  The block region is compared byte for byte, together with
 * the contract registers (r0) and the FR bank, and the stored floats are
 * verified against an independent fixture model. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "sprite_rect_b.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_sprite_rect_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define BLOCK_ADDR 0x0c16c000u
#define BLOCK_LO 0x0c16c000u
#define BLOCK_HI 0x0c16c100u

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

/* ---- round-toward-zero FP model note: exact rounding is in the native port;
   ---- this fixture model is a rough sanity check only ---- */

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

struct scenario {
    const char *name;
    float x, y, w, h, su, sv;
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr, const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = BLOCK_ADDR;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;      /* single precision, RM bit 0 (toward zero) */
    s->budget = 4000000u;
    VF3_FR(s, 4) = fbits(sc->x);
    VF3_FR(s, 5) = fbits(sc->y);
    VF3_FR(s, 6) = fbits(sc->w);
    VF3_FR(s, 7) = fbits(sc->h);
    VF3_FR(s, 8) = fbits(sc->su);
    VF3_FR(s, 9) = fbits(sc->sv);

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
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c07b3b8u;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_sprite_rect_b_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the block */
    const size_t l0 = BLOCK_HI - BLOCK_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(BLOCK_LO), l0);

    const uint32_t g_r0 = gs.v[0];
    const float g_fr1 = vf3_fr_get(&gs, 1), g_fr2 = vf3_fr_get(&gs, 2),
                g_fr3 = vf3_fr_get(&gs, 3), g_fr4 = vf3_fr_get(&gs, 4),
                g_fr5 = vf3_fr_get(&gs, 5);

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = BLOCK_ADDR;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    a.fr[4] = sc->x; a.fr[5] = sc->y; a.fr[6] = sc->w; a.fr[7] = sc->h;
    a.fr[8] = sc->su; a.fr[9] = sc->sv;
    vf3_native_sprite_rect_b(&a);

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
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        if (fbits(a.fr[1]) != fbits(g_fr1)) { fprintf(stderr, "  fr1 differs\n"); nb++; }
        if (fbits(a.fr[2]) != fbits(g_fr2)) { fprintf(stderr, "  fr2 differs\n"); nb++; }
        if (fbits(a.fr[3]) != fbits(g_fr3)) { fprintf(stderr, "  fr3 differs\n"); nb++; }
        if (fbits(a.fr[4]) != fbits(g_fr4)) { fprintf(stderr, "  fr4 differs\n"); nb++; }
        if (fbits(a.fr[5]) != fbits(g_fr5)) { fprintf(stderr, "  fr5 differs\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model: the four stored floats must (roughly) equal
     * (corner + bias) * scale; the exact rounding is proved by the byte-for-byte
     * native-vs-guest comparison above, so this is only a sanity check */
    {
        int nb = 0;
        const uint32_t BIA = 0x3A8461F9u, BIB = 0x33D6BF94u,
                       BIC = 0x80000000u, BID = 0xBED70A3Du;
        float ba, bb, bc, bd;
        memcpy(&ba, &BIA, 4); memcpy(&bb, &BIB, 4);
        memcpy(&bc, &BIC, 4); memcpy(&bd, &BID, 4);
        const float u0 = (sc->x + ba) * sc->su, v0 = (sc->y + bb) * sc->sv;
        const float u1 = (sc->x + sc->w + bc) * sc->su, v1 = (sc->y + sc->h + bd) * sc->sv;
        const float ep = (float)1e-4 * (1.0f + fabsf(u0) + fabsf(v0) + fabsf(u1) + fabsf(v1));
        uint32_t ru0 = r32(BLOCK_ADDR + 24), ru1 = r32(BLOCK_ADDR + 32),
                 rv0 = r32(BLOCK_ADDR + 28), rv1 = r32(BLOCK_ADDR + 36);
        float fu0, fu1, fv0, fv1;
        memcpy(&fu0, &ru0, 4); memcpy(&fu1, &ru1, 4);
        memcpy(&fv0, &rv0, 4); memcpy(&fv1, &rv1, 4);
        if (fabsf(fu0 - u0) > ep) { fprintf(stderr, "  u0 %.9g want %.9g\n", fu0, u0); nb++; }
        if (fabsf(fv0 - v0) > ep) { fprintf(stderr, "  v0 %.9g want %.9g\n", fv0, v0); nb++; }
        if (fabsf(fu1 - u1) > ep) { fprintf(stderr, "  u1 %.9g want %.9g\n", fu1, u1); nb++; }
        if (fabsf(fv1 - v1) > ep) { fprintf(stderr, "  v1 %.9g want %.9g\n", fv1, v1); nb++; }
        if (a.r[0] != 36u) { fprintf(stderr, "  r0 %08x want 36\n", a.r[0]); nb++; }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

static uint32_t rbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("sprite_rect_b_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "origin", .x = 0.0f, .y = 0.0f, .w = 1.0f, .h = 1.0f, .su = 1.0f, .sv = 1.0f },
        { .name = "scaled", .x = 10.25f, .y = -3.5f, .w = 2.0f, .h = 4.0f, .su = 0.5f, .sv = 0.25f },
        { .name = "negative", .x = -8.0f, .y = 6.0f, .w = 1.5f, .h = 2.5f, .su = -1.0f, .sv = 3.0f },
        { .name = "big", .x = 100.0f, .y = 200.0f, .w = 30.0f, .h = 40.0f, .su = 2.5f, .sv = 4.0f },
        { .name = "small", .x = 0.125f, .y = 0.25f, .w = 0.5f, .h = 0.75f, .su = 8.0f, .sv = 16.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("sprite_rect_b_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
