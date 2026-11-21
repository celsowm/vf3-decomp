/* Differential replay of the native colour unpack (src/native/color_unpack.c,
 * 0x8C0562E0) against the readable guest port (src/fight/color_unpack.c,
 * `vf3_color_unpack_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free FP body with
 * no stack frame and no guest callees (the only register it touches beyond
 * the FR/FPUL bank is GBR, from the seed): it reads four halfwords off the
 * record (r4), scales the fixed 3-float vector (0x0C19D5C8) by the factor
 * (0x0C056508), packs the first two halfwords into GBR+0x60, and converts
 * each halfword's two bytes to floats and scales them, storing six floats at
 * 0x0C16B82C and downwards (three, then back up).
 *
 * The fixture seeds the record, the scale vector, the factor, the GBR target
 * and the output region, runs the two sides from the same seed, and compares
 * the touched RAM byte for byte plus the contract registers (r4, r1) and the
 * FR/FPUL bank. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "color_unpack.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_color_unpack_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define FACTOR_ADDR 0x0C056508u
#define SCALE_ADDR  0x0C19D5C8u
#define OUT_ADDR    0x0C16B82Cu
#define RECORD_ADDR 0x0C16B000u
#define GBR_VALUE   0x0C16B900u
#define GBR_WRITE   (GBR_VALUE + 96u)   /* the single GBR write target */

/* the compared RAM region: OUT..OUT+16 and GBR_WRITE..+4 */
#define REGION_LO 0x0C16B800u
#define REGION_HI 0x0C16BA00u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }

static void w32(uint32_t addr, uint32_t v)
{ uint8_t *p = ab(addr); p[0]=((uint8_t)v);p[1]=((uint8_t)(v>>8));p[2]=((uint8_t)(v>>16));p[3]=((uint8_t)(v>>24)); }
static void w16(uint32_t addr, uint16_t v)
{ uint8_t *p = ab(addr); p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); }

struct scenario {
    const char *name;
    int16_t hw0, hw1, hw2, hw3;   /* the record halfwords */
    float s0, s1, s2;             /* the scale vector */
    float factor;
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4, uint32_t gbr, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;
    s->budget = 4000000u;
    s->gbr = gbr;
    s->gbr_known = 1;

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
    (void)sc;
    memset(ram, 0, RAM_SIZE);
    w16(RECORD_ADDR + 4, (uint16_t)sc->hw0);
    w16(RECORD_ADDR + 6, (uint16_t)sc->hw1);
    w16(RECORD_ADDR + 8, (uint16_t)sc->hw2);
    w16(RECORD_ADDR + 10, (uint16_t)sc->hw3);
    { uint32_t u; memcpy(&u, &sc->s0, 4); w32(SCALE_ADDR, u); }
    { uint32_t u; memcpy(&u, &sc->s1, 4); w32(SCALE_ADDR + 4, u); }
    { uint32_t u; memcpy(&u, &sc->s2, 4); w32(SCALE_ADDR + 8, u); }
    { uint32_t u; memcpy(&u, &sc->factor, 4); w32(FACTOR_ADDR, u); }
    /* leave the compared region as a pattern so an unwritten byte shows up */
    for (uint32_t ad = REGION_LO; ad < REGION_HI; ad += 4) w32(ad, 0xCDCDCDCDu);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c056330u;
    const uint32_t sr = 0x60000000u;
    const uint32_t r4 = RECORD_ADDR, gbr = GBR_VALUE;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, r4, gbr, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_color_unpack_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = REGION_HI - REGION_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REGION_LO), l0);

    const uint32_t g_r4 = gs.v[4], g_r1 = gs.v[1];
    const uint32_t g_fr0 = gs.v[21], g_fr1 = gs.v[22], g_fr2 = gs.v[23];
    const uint32_t g_fr4 = gs.v[25], g_fr5 = gs.v[26], g_fr6 = gs.v[27], g_fr7 = gs.v[28];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = r4;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    a.gbr = gbr;
    vf3_native_color_unpack(&a);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = REGION_LO; ad < REGION_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 12) fprintf(stderr, "  @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + FR */
    {
        int nb = 0;
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (vf3_aim_ubits(a.fr[0]) != g_fr0) { fprintf(stderr, "  fr0 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[1]) != g_fr1) { fprintf(stderr, "  fr1 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[2]) != g_fr2) { fprintf(stderr, "  fr2 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[4]) != g_fr4) { fprintf(stderr, "  fr4 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[5]) != g_fr5) { fprintf(stderr, "  fr5 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[6]) != g_fr6) { fprintf(stderr, "  fr6 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[7]) != g_fr7) { fprintf(stderr, "  fr7 differs\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model */
    {
        int nb = 0;
        /* the packed GBR write */
        const uint32_t packed = ((uint32_t)(uint16_t)sc->hw1 << 16) | ((uint32_t)(uint16_t)sc->hw0 & 0xFFFFu);
        if (vf3_aim_u32(&a, GBR_WRITE) != packed) { fprintf(stderr, "  gbr packed %08x want %08x\n", vf3_aim_u32(&a, GBR_WRITE), packed); nb++; }
        /* r4 advanced by 12 (skip 4 + four halfwords) */
        if (a.r[4] != r4 + 12u) { fprintf(stderr, "  r4 %08x want %08x\n", a.r[4], r4 + 12u); nb++; }
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
        printf("color_unpack_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "basic", .hw0 = 0x0102, .hw1 = 0x0304, .hw2 = 0x0506, .hw3 = 0x0708,
          .s0 = 1.0f, .s1 = 2.0f, .s2 = 0.5f, .factor = 1.0f },
        { .name = "negative bytes", .hw0 = (int16_t)0x80FF, .hw1 = (int16_t)0xFF80,
          .hw2 = 0x7F00, .hw3 = 0xF0F0,
          .s0 = 1.5f, .s1 = -2.0f, .s2 = 0.25f, .factor = 2.0f },
        { .name = "scale factor", .hw0 = 0x1020, .hw1 = 0x3040, .hw2 = 0x5060, .hw3 = 0x7080,
          .s0 = 3.0f, .s1 = 0.1f, .s2 = 10.0f, .factor = 0.5f },
        { .name = "mixed sign", .hw0 = (int16_t)0x8001, .hw1 = (int16_t)0x7FFF,
          .hw2 = (int16_t)0xFFFF, .hw3 = (int16_t)0x8000,
          .s0 = 4.0f, .s1 = 0.125f, .s2 = 8.0f, .factor = 1.5f },
        { .name = "zero", .hw0 = 0, .hw1 = 0, .hw2 = 0, .hw3 = 0,
          .s0 = 100.0f, .s1 = 100.0f, .s2 = 100.0f, .factor = 100.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("color_unpack_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
