/* Differential replay of the native atan-table (src/native/atan_table.c,
 * 0x8C069624) against the readable guest port (src/fight/atan_table.c,
 * `vf3_atan_table_entry`).
 *
 * Both sides seed the same flat RAM (the atan halfword table at 0x0C0EAF60)
 * and the same FR/register file, then run the leaf.  The leaf is call-free
 * and no-stack; it folds the |min|/|max| ratio into a table index, looks up
 * the slope angle and folds back the octant by the signs of x and y.  The
 * test compares r0/r4, FPUL, SR's T bit, the FR-bank outputs the leaf writes
 * (fr2, fr3, fr6, fr7, fr8) against the guest, and an independent fixture
 * model that computes the angle straight from the ratio and octant. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "atan_table.h"

#include <fenv.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_atan_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define TABLE      0x0C0EAF60u
#define SCALE_BITS 0x466A6000u
#define QUARTER    0x4000
#define HALF       0x8000
#define SIGN       0x80000000u

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define RETURN_PC 0x0c069636u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static float fbits_to_f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

struct scenario {
    const char *name;
    uint32_t x, y;   /* FR4, FR5 */
};

/* build the atan slope table: index i (scaled ratio) -> int16 angle */
static void build_table(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* the table row i holds the angle of slope (i / scale) in turns*0x4000
     * (the angle of the ray whose |y|/|x| = i/scale); we fill from the real
     * atan so the octant fold has true angles to work with. */
    const float scale = fbits_to_f(SCALE_BITS);
    const int n = 0x10000;
    for (int i = 0; i < n; ++i) {
        float slope = (float)i / scale;
        float ang = atanf(slope);                 /* in radians 0..pi/4 */
        float turns = ang / (2.0f * 3.14159265358979f);   /* 0..0.125 */
        int16_t v = (int16_t)(turns * 65536.0f);  /* 0..0x2000 */
        uint8_t *p = ab(TABLE + 2u * i);
        p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    }
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    VF3_FR(s, 4) = sc->x;
    VF3_FR(s, 5) = sc->y;
    for (unsigned i = 0; i < 16; ++i) fr_in[i] = s->v[VF3_REG_FR0 + i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x6000002du;      /* SR: T seeded (leaf does not touch it) */
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

static int compare_one(const struct scenario *sc)
{
    printf("== %s (x %08x y %08x)\n", sc->name, sc->x, sc->y);

    build_table();
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, sc, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_atan_table_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t g_fpul = gs.v[53];

    /* the native runs on the same RAM/regs */
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x6000002du;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_atan_table(&a);

    int bad = 0;

    /* output + FPUL + T vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.fpul != g_fpul) { fprintf(stderr, "  FPUL: native %08x guest %08x\n", a.fpul, g_fpul); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 4) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }
    /* FR-bank outputs the leaf writes (fr2, fr3, fr6, fr7, fr8) */
    {
        const unsigned w[] = { 2, 3, 6, 7, 8 };
        for (unsigned e = 0; e < sizeof w / sizeof w[0]; ++e) {
            unsigned i = w[e];
            uint32_t g = gs.v[VF3_REG_FR0 + i];
            if (vf3_aim_ubits(a.fr[i]) != g) {
                fprintf(stderr, "  fr%u: native %08x guest %08x\n", i, vf3_aim_ubits(a.fr[i]), g); bad++;
            }
        }
    }
    /* untouched FR: fr4/fr5 keep the args, the rest stay */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 2 || i == 3 || i == 6 || i == 7 || i == 8) continue;
        if (vf3_aim_ubits(a.fr[i]) != fr_in[i]) {
            fprintf(stderr, "  fr%u(untouched): native %08x entry %08x\n", i, vf3_aim_ubits(a.fr[i]), fr_in[i]); bad++;
        }
    }

    /* the fixture model: compute the angle straight from the ratio/octant */
    {
        float x = fbits_to_f(sc->x), y = fbits_to_f(sc->y);
        if (x == 0.0f && y == 0.0f) {
            if (a.r[0] != 0) { fprintf(stderr, "  model: native r0 %08x want 0\n", a.r[0]); bad++; }
            printf("  model: %s\n", a.r[0] == 0 ? "match" : "DIFFERS");
        } else {
        int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        float ax = fabsf(x), ay = fabsf(y);
        float ratio = ay > ax ? ax / ay : ay / ax;
        float scale = fbits_to_f(SCALE_BITS);
        float v = ratio * scale;
        int32_t t = v >= 2147483648.0f ? INT32_MAX : v <= -2147483648.0f ? INT32_MIN : (int32_t)v;
        fesetround(saved);
        int16_t ang = (int16_t)r16(TABLE + ((uint32_t)t << 1));
        if (ax > ay) ang = QUARTER - ang;
        if (y < 0) {
            if (x < 0) ang += (int16_t)HALF;
            else       ang = HALF - ang;
        } else if (x < 0) {
            ang = -ang;
        }
        uint32_t want = (uint32_t)ang;
        if (a.r[4] != want) { fprintf(stderr, "  model angle: native %04x model %04x\n", a.r[4] & 0xffffu, want & 0xffffu); bad++; }
        printf("  model: %s\n", want == a.r[4] ? "match" : "DIFFERS");
        }
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "zero vector",  .x = 0x00000000u, .y = 0x00000000u },
        { .name = "x-axis",       .x = 0x3f800000u, .y = 0x00000000u },   /* (1,0) = 0 */
        { .name = "y-axis",       .x = 0x00000000u, .y = 0x3f800000u },   /* (0,1) = 0x2000 */
        { .name = "diag",         .x = 0x3f800000u, .y = 0x3f800000u },   /* (1,1) = 0x1000 */
        { .name = "diag neg y",   .x = 0x3f800000u, .y = 0xbf800000u },   /* (1,-1) = 0x3000 */
        { .name = "diag neg x",   .x = 0xbf800000u, .y = 0x3f800000u },   /* (-1,1) = 0x7000 */
        { .name = "diag negboth", .x = 0xbf800000u, .y = 0xbf800000u },   /* (-1,-1) = 0x5000 */
        { .name = "steep",        .x = 0x3f000000u, .y = 0x40000000u },   /* (0.5,2) */
        { .name = "shallow",      .x = 0x40000000u, .y = 0x3f000000u },   /* (2,0.5) */
        { .name = "neg steep",    .x = 0x3f000000u, .y = 0xc0000000u },
        { .name = "neg shallow",  .x = 0xbf000000u, .y = 0x3f000000u },
        { .name = "quarterx",     .x = 0x3e800000u, .y = 0x3f000000u },   /* (0.25,0.5) */
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("atan_table_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
