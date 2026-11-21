/* Differential replay of the native triangle winding test
 * (src/native/tri_winding.c, 0x8C068F92) against the readable guest port
 * (src/fight/geom_readable.c, `vf3_tri_winding_entry`).
 *
 * Both sides seed the same FR bank (FR4..FR9 as the three (x,y) points) and
 * register file, then run the leaf.  The leaf is pure-FR: no RAM, no calls,
 * no stack; it returns only r0 (2 positive / 1 degenerate / 4 negative).
 * The test compares r0 against the guest and against an independent fixture
 * model computed straight from the six floats, verifies that SR's T bit is
 * preserved (the readable writes no comparison into it here) and that every
 * register other than r0 is preserved. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "tri_winding.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_tri_winding_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x20000u

#define RETURN_PC 0x0c069048u

struct scenario {
    const char *name;
    uint32_t fr[6];   /* x0 y0 x1 y1 x2 y2 */
};

static uint8_t *ram;

/* fixture model: the same algebra, at native float precision */
static int model_winding(uint32_t fr[6])
{
    float x0, y0, x1, y1, x2, y2;
    memcpy(&x0, &fr[0], 4); memcpy(&y0, &fr[1], 4);
    memcpy(&x1, &fr[2], 4); memcpy(&y1, &fr[3], 4);
    memcpy(&x2, &fr[4], 4); memcpy(&y2, &fr[5], 4);
    float area = (y1 - y0) * (x2 - x1) - (x1 - x0) * (y2 - y1);
    if (area > 0.0f) return 2;
    if (area == 0.0f) return 1;
    return 4;
}

static void seed_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                       const uint32_t fr[6], uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 6; ++i) VF3_FR(s, 4 + i) = fr[i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear, preserved by the leaf */
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
    printf("== %s\n", sc->name);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    seed_guest(&gs, &gmap, gwin, sc->fr, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_tri_winding_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t g_r0 = gs.v[0];

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 6; ++i) a.fr[4 + i] = vf3_aim_fbits(sc->fr[i]);
    vf3_native_tri_winding(&a);

    int bad = 0;

    /* r0 vs guest and vs the fixture model */
    if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); bad++; }
    const uint32_t m = (uint32_t)model_winding(sc->fr);
    if (a.r[0] != m) { fprintf(stderr, "  r0: native %08x model %08x\n", a.r[0], m); bad++; }
    printf("  r0 = %u\n", a.r[0]);

    /* no other register may change; pr/r15 preserved; T preserved */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }
    if (a.pr != RETURN_PC) { fprintf(stderr, "  pr: native %08x want %08x\n", a.pr, RETURN_PC); bad++; }
    if ((a.sr & 1u) != (in_v[17] & 1u)) {
        fprintf(stderr, "  T bit changed: native %u entry %u\n", a.sr & 1u, in_v[17] & 1u); bad++;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "positive (ccw)", .fr = {
            0x3f800000u, 0x00000000u,   /* (1, 0) */
            0x00000000u, 0x3f800000u,   /* (0, 1) */
            0xc0000000u, 0x00000000u,   /* (-2, 0) */
        } },
        { .name = "negative (cw)", .fr = {
            0x00000000u, 0x3f800000u,
            0x3f800000u, 0x00000000u,
            0xc0000000u, 0x00000000u,
        } },
        { .name = "degenerate (collinear)", .fr = {
            0x3f800000u, 0x00000000u,
            0x40000000u, 0x00000000u,
            0xc0000000u, 0x00000000u,
        } },
        { .name = "positive large", .fr = {
            0x43000000u, 0x00000000u,   /* (128, 0) */
            0x00000000u, 0x43000000u,   /* (0, 128) */
            0xc2800000u, 0x00000000u,   /* (-64, 0) */
        } },
        { .name = "NaN yields negative", .fr = {
            0x7fc00000u, 0x3f800000u,
            0x3f800000u, 0x00000000u,
            0xc0000000u, 0x00000000u,
        } },
        { .name = "scaled large", .fr = {
            0x4b000000u, 0x00000000u,   /* (2^23, 0) */
            0x00000000u, 0x4b000000u,
            0xc9800000u, 0x00000000u,
        } },
        { .name = "mutation-sensitive", .fr = {
            0x00000000u, 0x00000000u,   /* (0, 0) */
            0x3f800000u, 0x3f800000u,   /* (1, 1) */
            0xc0400000u, 0xc0400000u,   /* (-3, -3) */
        } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("tri_winding_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
