/* Differential replay of the native point-in-quad leaf
 * (src/native/quad_node.c, 0x8C068FE4) against the readable guest port
 * (src/fight/geom_readable.c, `vf3_quad_node_entry`).
 *
 * Both sides seed the same flat RAM (the base cell, a node, a record and four
 * vertices), the same FR bank (the query point in FR4/FR5) and the same
 * register file, then run the leaf.  The leaf's only callee (the triangle
 * winding test) is exercised natively through `vf3_native_tri_winding`.
 *
 * After the run the whole register file (r0..r15, pr, sr) and the whole FR
 * bank are compared with the guest, and the node-flag / live-zero paths are
 * checked against their expected answers. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "quad_node.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_quad_node_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define BASE_CELL 0x0C113A0Cu   /* *(u32) here = the record base */
#define NODE      0x0C1A6000u   /* r4 */
#define BASE      0x0C1A8000u   /* the record base */
#define SP0       0x0C1A7000u   /* r15 */
#define RETURN_PC 0x0c068fe4u
#define FPSCR     0x00040001u   /* single-PR, toward-zero + FTZ */

#define V_A 0x20u   /* rec.vtx_off[0]  (+ BASE = vertex) */
#define V_B 0x60u
#define V_C 0xA0u
#define V_D 0xE0u

struct scenario {
    const char *name;
    int node_flag0;          /* node.flags bit0 -> answer 1 */
    int rec_flags0;          /* rec.flags bit0 : one_triangle */
    int live_zero;           /* rec.live == 0 -> answer 0 */
    uint32_t rec_off;        /* node.rec_off */
    float q[2];              /* the query point (FR4, FR5) */
    /* four vertices as (x, z) */
    float v0[2], v1[2], v2[2], v3[2];
    /* expected result (only set for the trivial paths) */
    int expect;              /* -1 = compare only */
};

static void w32(uint8_t *ab, uint32_t w)
{
    ab[0] = (uint8_t)w; ab[1] = (uint8_t)(w >> 8);
    ab[2] = (uint8_t)(w >> 16); ab[3] = (uint8_t)(w >> 24);
}
static void wf32(uint8_t *ab, float f) { w32(ab, vf3_f32_bits(f)); }

static void seed_ram(uint8_t *ram, const struct scenario *sc)
{
    memset(ram, 0x5A, RAM_SIZE);
    uint8_t *b = ram + (BASE - RAM_BASE);
    uint8_t *cell = ram + (BASE_CELL - RAM_BASE);
    w32(cell, BASE);
    uint8_t *nd = ram + (NODE - RAM_BASE);
    w32(nd, sc->node_flag0 ? 1u : 0u);
    w32(nd + 4, sc->rec_off);
    /* the record at BASE + rec_off */
    uint8_t *rec = b + sc->rec_off;
    w32(rec, sc->rec_flags0 ? 1u : 0u);
    w32(rec + 4, V_A); w32(rec + 8, V_B); w32(rec + 12, V_C); w32(rec + 16, V_D);
    wf32(rec + 0x18, sc->live_zero ? 0.0f : 1.0f);
    /* vertices at BASE + vtx_off */
    const float (*vv[4])[2] = { &sc->v0, &sc->v1, &sc->v2, &sc->v3 };
    const uint32_t voff[4] = { V_A, V_B, V_C, V_D };
    for (int i = 0; i < 4; ++i) {
        uint8_t *vx = b + voff[i];
        wf32(vx, (*vv[i])[0]);
        wf32(vx + 8, (*vv[i])[1]);
    }
}

static int compare_one(const struct scenario *sc, int idx)
{
    printf("== %s\n", sc->name);

    uint8_t *g_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *n_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }

    /* ----- guest side ----- */
    seed_ram(g_ram, sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = NODE;
    gs.v[15] = SP0;
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = FPSCR;
    gs.v[25] = vf3_f32_bits(sc->q[0]);       /* FR4 = v[21+4] */
    gs.v[26] = vf3_f32_bits(sc->q[1]);       /* FR5 = v[21+5] */
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = g_ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_quad_node_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  case %d: guest failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
        free(g_ram); free(n_ram); return 1;
    }

    /* ----- native side ----- */
    seed_ram(n_ram, sc);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)n_ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) x.fr[i] = vf3_aim_fbits(0x76543210u + 21u + i);
    x.r[4] = NODE;
    x.r[15] = SP0;
    x.pr = RETURN_PC;
    x.sr = 0x60000000u;
    x.fpscr = FPSCR;
    x.fr[4] = sc->q[0];
    x.fr[5] = sc->q[1];
    vf3_native_quad_node(&x);

    int bad = 0;
    for (unsigned i = 0; i < 16; ++i)
        if (x.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, x.r[i], gs.v[i]); bad++;
        }
    if (x.pr != gs.v[16]) fprintf(stderr, "  pr native %08x guest %08x\n", x.pr, gs.v[16]), bad++;
    if (x.sr != gs.v[17]) fprintf(stderr, "  sr native %08x guest %08x\n", x.sr, gs.v[17]), bad++;
    for (unsigned i = 0; i < 16; ++i)
        if (vf3_aim_ubits(x.fr[i]) != gs.v[21 + i]) {
            fprintf(stderr, "  fr%u native %08x guest %08x\n", i,
                    vf3_aim_ubits(x.fr[i]), gs.v[21 + i]); bad++;
        }

    if (sc->expect >= 0 && (int)gs.v[0] != sc->expect) {
        fprintf(stderr, "  geometry: guest r0=%u expected %d\n", gs.v[0], sc->expect); bad++;
    }

    free(g_ram); free(n_ram);
    printf("  quad_node: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    int bad = 0;
    struct scenario scs[] = {
        { "node flag set", 1, 0, 0, 0x40u, { 0, 0 },
          { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 1 },
        { "live zero", 0, 0, 1, 0x40u, { 0, 0 },
          { 0, 0 }, { 10, 0 }, { 0, 0 }, { 0, 0 }, 0 },
        { "inside tri1 (quad)", 0, 0, 0, 0x40u, { 3, 3 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "inside second tri", 0, 0, 0, 0x40u, { 4, 8 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "outside", 0, 0, 0, 0x40u, { 12, 12 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "one triangle, disagree", 0, 1, 0, 0x40u, { 4, 8 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "edges grind", 0, 0, 0, 0x40u, { -1, 1 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "on diagonal", 0, 0, 0, 0x40u, { 5, 5 },
          { 0, 0 }, { 10, 0 }, { 10, 10 }, { 0, 10 }, -1 },
        { "different rec_off", 0, 0, 0, 0x180u, { 3, 3 },
          { 4, 0 }, { 12, 0 }, { 12, 9 }, { 0, 9 }, -1 },
    };
    for (unsigned i = 0; i < sizeof scs / sizeof scs[0]; ++i)
        bad |= compare_one(&scs[i], (int)i);
    printf("quad_node_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
