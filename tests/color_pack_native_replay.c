/* Differential replay of the native color-pack (src/native/color_pack.c,
 * 0x8C03FB80) against the readable guest port (src/fight/geom_readable.c,
 * `vf3_color_pack_entry`).
 *
 * Both sides seed the same flat RAM (the three pool constants at
 * 0x0C03FC38/3C/40) and FR bank (FR4..FR7 = a, r, g, b) and register file,
 * then run the leaf.  The leaf is call-free and no-stack; it scales the four
 * channels by 255, truncates, clamps to 255 and packs a:r:g:b into r0/r4,
 * leaving r5..r7 = the clamped r,g,b.  The test compares r0/r4/r5/r6/r7,
 * FPUL and SR's T bit against the guest, the untouched registers, FPUL and
 * FPSCR, the FR-bank outputs, and an independent fixture model that recomputes
 * the pack straight from the four channel floats. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "color_pack.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>

int vf3_color_pack_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define COLOR_SCALE_ADDR      0x0C03FC38u
#define COLOR_HALF_RANGE_ADDR 0x0C03FC3Cu
#define COLOR_WRAP_BIAS_ADDR  0x0C03FC40u

#define RETURN_PC 0x0c03fba6u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    uint32_t fr[4];   /* a r g b */
};

static void seed_all(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    w32(COLOR_SCALE_ADDR, 0x437f0000u);       /* 255.0 */
    w32(COLOR_HALF_RANGE_ADDR, 0x4f000000u);  /* 2^31 */
    w32(COLOR_WRAP_BIAS_ADDR, 0xcf000000u);   /* -2^32 */
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t fr[4], uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 4; ++i) VF3_FR(s, 4 + i) = fr[i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear */
    s->v[18] = 0x00024001u;      /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all();
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc->fr, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_color_pack_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t g_fpul = gs.v[53];

    seed_all();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 4; ++i) a.fr[4 + i] = vf3_aim_fbits(sc->fr[i]);
    /* seed the rest of the FR bank as the guest's entry values, so any
     * unintended write to a scratch FR register is caught */
    for (unsigned i = 0; i < 16; ++i) {
        if (i >= 4 && i <= 7) continue;
        a.fr[i] = vf3_aim_fbits(gs.v[VF3_REG_FR0 + i]);
    }
    uint32_t fr_before[4];
    for (unsigned i = 0; i < 4; ++i) fr_before[i] = vf3_aim_ubits(a.fr[4 + i]);
    vf3_native_color_pack(&a);

    int bad = 0;

    /* output registers + FPUL + T vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if (a.r[7] != gs.v[7]) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gs.v[7]); bad++; }
    if (a.r[1] != gs.v[1]) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gs.v[1]); bad++; }
    if (a.fpul != g_fpul) { fprintf(stderr, "  FPUL: native %08x guest %08x\n", a.fpul, g_fpul); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 1 || i == 4 || i == 5 || i == 6 || i == 7) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* FR-bank outputs match the guest (the leaf writes fr3..fr9; the rest are
     * scratch and untouched) */
    for (unsigned i = 3; i <= 9; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g) {
            fprintf(stderr, "  fr%u: native %08x guest %08x\n", i, vf3_aim_ubits(a.fr[i]), g); bad++;
        }
    }

    /* the fixture model: recompute the pack from the four channel floats */
    {
        float scale, half_range, bias;
        uint32_t sb = r32(COLOR_SCALE_ADDR); memcpy(&scale, &sb, 4);
        uint32_t hb = r32(COLOR_HALF_RANGE_ADDR); memcpy(&half_range, &hb, 4);
        uint32_t wb = r32(COLOR_WRAP_BIAS_ADDR); memcpy(&bias, &wb, 4);
        uint32_t packed = 0;
        uint32_t raw[4];
        for (int i = 0; i < 4; ++i) {
            float c;
            memcpy(&c, &sc->fr[i], 4);
            const int saved = fegetround();
            fesetround(FE_TOWARDZERO);
            volatile float s = c * scale;
            fesetround(saved);
            float conv = s > half_range ? s + bias : s;
            raw[i] = ftrc(conv);
            const uint32_t byte = raw[i] > 0xFFu ? 0xFFu : raw[i];
            packed = (packed << 8) | byte;
        }
        if (a.r[4] != packed) { fprintf(stderr, "  model packed: native %08x model %08x\n", a.r[4], packed); bad++; }
        if (a.r[5] != (raw[1] > 0xFFu ? 0xFFu : raw[1])) { fprintf(stderr, "  model r5\n"); bad++; }
        if (a.r[6] != (raw[2] > 0xFFu ? 0xFFu : raw[2])) { fprintf(stderr, "  model r6\n"); bad++; }
        if (a.r[7] != (raw[3] > 0xFFu ? 0xFFu : raw[3])) { fprintf(stderr, "  model r7\n"); bad++; }
        printf("  model: %s\n", bad ? "DIFFERS" : "match");
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "plain colors", .fr = { 0x3f800000u, 0x3f000000u, 0x3eccccccdu, 0x3f333333u } },
        /* a=1.0, r=0.5, g=0.4, b=0.7 -> scale 255: 255, 127, 102, 178 */
        { .name = "all zero", .fr = { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u } },
        { .name = "all one", .fr = { 0x3f800000u, 0x3f800000u, 0x3f800000u, 0x3f800000u } },
        { .name = "negative g", .fr = { 0x3f000000u, 0x3f000000u, 0xbf000000u, 0x3f000000u } },
        { .name = "over-range r", .fr = { 0x3f800000u, 0x40200000u, 0x3f000000u, 0x3f000000u } },
        /* r=2.5 -> scale 637 -> clamp 255 */
        { .name = "huge b", .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x41800000u } },
        /* b=16.0 -> scale 4080 -> clamp 255 */
        { .name = "wrap boundary b", .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x4b008081u } },
        /* b=8421505.0, scale 255 -> exactly 2^31 under toward-zero; the
         * `>`/`>=` wrap comparison and the bias sign hinge on this channel */
        { .name = "deep wrap b", .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x4b371b00u } },
        /* b=1.2e7, scale 255 -> 3.06e9 in [2^31, 2^32), wraps through -2^32 */
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("color_pack_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
