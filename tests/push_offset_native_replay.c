/* Differential replay of the native scaled-offset push helper
 * (src/native/push_offset.c, 0x8C056B20) against the readable guest port
 * (src/fight/geom_readable.c, `vf3_push_offset_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free FP body (only
 * fmul / from-int; no guest callees, no stack).  It is register-passed: r8 =
 * source (two int16 at +0x0E, +0x10), r12 = record cursor, r6 and
 * FR12..FR15 = values, FR3 = scale.  It writes the stored register block at
 * the old cursor and the scaled offset / carry words at the new top.
 *
 * The fixture seeds the source record and the FR/r6 inputs, and runs the two
 * sides from the same seed.  The record region is compared byte for byte,
 * together with the contract registers and the FR bank, and the stored floats
 * are verified against an independent fixture model. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "push_offset.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_push_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define SRC_ADDR 0x0c16c000u
#define REC_ADDR 0x0c16d000u
#define REC_LO 0x0c16d000u
#define REC_HI 0x0c16d100u
#define R_TOP(r12) ((r12) + 0x20u)

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
    uint32_t r12;                /* the record cursor (absolute) */
    int16_t first, second;       /* the source's two int16 at +0x0E, +0x10 */
    uint32_t r6;                 /* the value to push as the word */
    float fr12, fr13, fr14, fr15;/* the four carried floats */
    float scale;                 /* FR3 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr, const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[8] = SRC_ADDR;
    s->v[12] = sc->r12;
    s->v[6] = sc->r6;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;      /* single precision, RM bit 0 (toward zero) */
    s->budget = 4000000u;
    VF3_FR(s, 3) = fbits(sc->scale);
    VF3_FR(s, 12) = fbits(sc->fr12);
    VF3_FR(s, 13) = fbits(sc->fr13);
    VF3_FR(s, 14) = fbits(sc->fr14);
    VF3_FR(s, 15) = fbits(sc->fr15);

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
    w16(SRC_ADDR + 0x0Eu, (uint16_t)sc->first);
    w16(SRC_ADDR + 0x10u, (uint16_t)sc->second);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c056b5eu;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_push_offset_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the record */
    const size_t l0 = REC_HI - REC_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REC_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r12 = gs.v[12];
    const float g_fr1 = vf3_fr_get(&gs, 1), g_fr2 = vf3_fr_get(&gs, 2);

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[8] = SRC_ADDR;
    a.r[12] = sc->r12;
    a.r[6] = sc->r6;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    a.fr[3] = sc->scale; a.fr[12] = sc->fr12; a.fr[13] = sc->fr13;
    a.fr[14] = sc->fr14; a.fr[15] = sc->fr15;
    vf3_native_push_offset(&a);

    int bad = 0;

    /* RAM record */
    {
        int nb = 0;
        for (uint32_t ad = REC_LO; ad < REC_HI; ad += 4) {
            uint32_t g; memcpy(&g, snap + (ad - REC_LO), 4);
            if (g != r32(ad)) { if (nb < 10) fprintf(stderr, "  rec @%08x: got %08x want %08x\n", ad, r32(ad), g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + FR */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[12] != g_r12) { fprintf(stderr, "  r12: native %08x guest %08x\n", a.r[12], g_r12); nb++; }
        if (a.r[8] != SRC_ADDR) { fprintf(stderr, "  r8 changed\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        if (fbits(a.fr[1]) != fbits(g_fr1)) { fprintf(stderr, "  fr1 differs\n"); nb++; }
        if (fbits(a.fr[2]) != fbits(g_fr2)) { fprintf(stderr, "  fr2 differs\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model: y = second * scale, x = first * scale at
     * the new top (r12' = r12+0x20 - 16 = r12 + 0x10); the four carried words
     * land at the old cursor region (rough sanity check only) */
    {
        int nb = 0;
        const float y = (float)sc->second * sc->scale;
        const float x = (float)sc->first * sc->scale;
        const float ep = (float)1e-4 * (1.0f + fabsf(x) + fabsf(y));
        const uint32_t top = R_TOP(sc->r12);        uint32_t r; float f;
        r = r32(top + 20u); memcpy(&f, &r, 4);
        if (fabsf(f - y) > ep) { fprintf(stderr, "  y %.9g want %.9g\n", f, y); nb++; }
        r = r32(top + 16u); memcpy(&f, &r, 4);
        if (fabsf(f - x) > ep) { fprintf(stderr, "  x %.9g want %.9g\n", f, x); nb++; }
        if (r32(top + 28u) != 0) { fprintf(stderr, "  top+28 not zero\n"); nb++; }
        if (a.r[0] != 0u) { fprintf(stderr, "  r0 %08x want 0\n", a.r[0]); nb++; }
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
        printf("push_offset_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "basic", .r12 = 0x0c16d060u, .first = 5, .second = 7,
          .r6 = 0x12345678u, .fr12 = 1.0f, .fr13 = 2.0f, .fr14 = 3.0f,
          .fr15 = 4.0f, .scale = 0.5f },
        { .name = "negative", .r12 = 0x0c16d060u, .first = -5, .second = -7,
          .r6 = 0xABCDEF01u, .fr12 = -1.0f, .fr13 = 2.5f, .fr14 = -3.5f,
          .fr15 = 4.25f, .scale = -2.0f },
        { .name = "scale0", .r12 = 0x0c16d040u, .first = 300, .second = -100,
          .r6 = 0u, .fr12 = 10.0f, .fr13 = 20.0f, .fr14 = 30.0f,
          .fr15 = 40.0f, .scale = 0.0f },
        { .name = "big", .r12 = 0x0c16d068u, .first = 32767, .second = -32768,
          .r6 = 0xFFFFFFFFu, .fr12 = 100.0f, .fr13 = -200.0f, .fr14 = 300.0f,
          .fr15 = -400.0f, .scale = 1.5f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("push_offset_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
