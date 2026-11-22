/* edge_probe_native_replay.c - differential replay of the native edge_probe
 * (0x8C06E31C, src/native/edge_probe.c, `vf3_native_edge_probe`) against the
 * readable guest port (src/fight/edge_probe.c, `vf3_edge_probe_entry`).
 *
 * edge_probe casts four quarter-turn rays from a fighter's probe origin
 * against the stage outline and writes, per direction, a hit distance (a
 * float at one object offset) and an edge direction (a halfword at another;
 * the two offsets come from the halfword table at 0x0C119688).  A miss
 * writes 0.0 and 0.
 *
 * Both sides seed the same object (the signed-word angle at +0x1394 and the
 * probe origin floats at +0x430/+0x438), the same outline (the vertex list
 * reached through [[0x0C29BBA4] + 0x3C4]), the same offset table and the
 * same saved FR12..FR15 / r8..r14, then run.  Compared: the four distance
 * floats written to the object (at the float tolerance 2e-3, because the
 * fsca/fsrra are reproduced with sinf/cosf/sqrtf and are last-bit off), the
 * four direction halfwords (bit-exact - both sides go through the same
 * atan_table), the restored r8..r14 and FR12..FR15 (bit-exact, through the
 * stack), r15 and pr.
 */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "edge_probe.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_edge_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u
#define TOL      2.0e-3f

#define OBJ     0x0C200000u
#define SP0     0x0C210000u   /* frame f = sp0 - 84 */
#define CELL    0x0C29BBA4u   /* -> the outline block */
#define BLOCK   0x0C2A0000u
#define VERT    0x0C2A0400u   /* the vertex list, reached at block + 0x3C4 */
#define TABLE   0x0C119688u   /* the halfword table of result offsets */

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint16_t)(p[0] | (p[1] << 8));
}
static float rf(uint32_t addr) { float f; uint32_t u = r32(addr); memcpy(&f, &u, 4); return f; }

/* outline block: x0,y0,x1,y1 (four corners, closed).  Block+0x3C4 -> VERT,
 * VERT = [count][x0 y0][x1 y1][x2 y2][x3 y3]. */
static void seed(const float origin[2], int16_t angle, const float sq[8])
{
    memset(at(OBJ), 0, 0x10000);        /* object region */
    memset(at(SP0 - 112u), 0, 320);     /* frame + save region */

    /* object: probe origin + the signed-word angle at +0x1394 */
    wf(OBJ + 0x430u, origin[0]);
    wf(OBJ + 0x438u, origin[1]);
    uint16_t a = (uint16_t)(int16_t)angle;
    w32(OBJ + 0x1394u, a | (0u << 16)); /* low word is the signed angle */

    /* the outline cell -> block -> vertex list */
    w32(CELL, BLOCK);
    w32(BLOCK + 0x3C4u, VERT);
    w32(VERT, 4);                       /* count: four edges */
    for (int i = 0; i < 4; ++i) {
        wf(VERT + 4u + 8u * (uint32_t)i, sq[2 * i]);
        wf(VERT + 8u + 8u * (uint32_t)i, sq[2 * i + 1]);
    }

    /* the offset table: four (dist_offset, dir_offset) halfword pairs */
    {
        uint16_t tab[8] = {
            (uint16_t)0x500, (uint16_t)0x600,
            (uint16_t)0x510, (uint16_t)0x610,
            (uint16_t)0x520, (uint16_t)0x620,
            (uint16_t)0x530, (uint16_t)0x630,
        };
        for (int i = 0; i < 8; ++i) {
            uint8_t *p0 = (uint8_t *)at(TABLE + 2u * (uint32_t)i);
            p0[0] = (uint8_t)tab[i]; p0[1] = (uint8_t)(tab[i] >> 8);
        }
    }
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = OBJ;
    s->v[15] = SP0;
    s->v[16] = 0x0C0ABCDEu;             /* pr */
    s->v[17] = 0x60000000u;             /* sr */
    s->v[18] = 0x00040001u;             /* fpscr */
    s->v[VF3_REG_FR0 + 12] = 0x3F400000u;   /* fr12 = 0.75 */
    s->v[VF3_REG_FR0 + 13] = 0x40400000u;   /* fr13 = 3.0 */
    s->v[VF3_REG_FR0 + 14] = 0x40800000u;   /* fr14 = 4.0 */
    s->v[VF3_REG_FR0 + 15] = 0x40A00000u;   /* fr15 = 5.0 */
    for (int i = 8; i <= 14; ++i) s->v[i] = 0x1000u * (uint32_t)i;   /* r8..r14 */
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static int run_case(const char *label, const float origin[2], int16_t angle,
                    const float sq[8])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    seed(origin, angle, sq);
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_edge_probe_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    /* the guest's four result pairs */
    float gdist[4]; uint16_t gdir[4];
    {
        uint16_t tab[8];
        for (int i = 0; i < 8; ++i) tab[i] = r16(TABLE + 2u * (uint32_t)i);
        for (int i = 0; i < 4; ++i) {
            gdist[i] = rf(OBJ + tab[2 * i]);
            gdir[i] = r16(OBJ + tab[2 * i + 1]);
        }
    }
    const uint32_t gr15 = gs.v[15], gpr = gs.v[16];
    uint32_t gr8_14[7];
    for (int i = 0; i < 7; ++i) gr8_14[i] = gs.v[8 + i];
    uint32_t gfr[4];
    for (int i = 0; i < 4; ++i) gfr[i] = gs.v[VF3_REG_FR0 + 12 + i];

    seed(origin, angle, sq);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    a.r[4] = OBJ;
    a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fr[12] = 0.75f; a.fr[13] = 3.0f; a.fr[14] = 4.0f; a.fr[15] = 5.0f;
    for (int i = 8; i <= 14; ++i) a.r[i] = 0x1000u * (uint32_t)i;
    vf3_native_edge_probe(&a);

    /* the native's four result pairs, read from the same table */
    float ndist[4]; uint16_t ndir[4];
    {
        uint16_t tab[8];
        for (int i = 0; i < 8; ++i) tab[i] = r16(TABLE + 2u * (uint32_t)i);
        for (int i = 0; i < 4; ++i) {
            ndist[i] = rf(OBJ + tab[2 * i]);
            ndir[i] = r16(OBJ + tab[2 * i + 1]);
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (fabsf(ndist[i] - gdist[i]) > TOL && memcmp(&ndist[i], &gdist[i], 4) != 0) {
            if (bad < 12) fprintf(stderr, "  dist[%d]: native %.6g guest %.6g\n", i, ndist[i], gdist[i]);
            bad++;
        }
        if (ndir[i] != gdir[i]) {
            if (bad < 12) fprintf(stderr, "  dir[%d]: native %04x guest %04x\n", i, ndir[i], gdir[i]);
            bad++;
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (a.r[8 + i] != gr8_14[i]) { if (bad < 12) fprintf(stderr, "  r%d: native %08x guest %08x\n", 8 + i, a.r[8 + i], gr8_14[i]); bad++; }
    }
    for (int i = 0; i < 4; ++i) {
        if (vf3_aim_ubits(a.fr[12 + i]) != gfr[i]) { if (bad < 12) fprintf(stderr, "  fr%d: native %08x guest %08x\n", 12 + i, (unsigned)vf3_aim_ubits(a.fr[12 + i]), (unsigned)gfr[i]); bad++; }
    }
    if (a.r[15] != gr15) { if (bad < 4) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.pr != gpr) { if (bad < 4) fprintf(stderr, "  pr:  native %08x guest %08x\n", a.pr, gpr); bad++; }
    if (a.sr & 1u) { if (bad < 4) fprintf(stderr, "  sr T bit: native not cleared\n"); bad++; }

    printf("  edge_probe: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    int bad = 0;
    /* square outline, origin near the centre: every ray must hit an edge */
    {
        const float sq[8] = { -50, -50, 50, -50, 50, 50, -50, 50 };
        const float origin[2] = { 0.0f, 0.0f };
        bad |= run_case("centre +x", origin, 0, sq);
    }
    {
        const float sq[8] = { -40, -60, 40, -60, 40, 60, -40, 60 };
        const float origin[2] = { 10.0f, 5.0f };
        bad |= run_case("off-centre 90", origin, 0x2000, sq);
    }
    {
        const float sq[8] = { -30, -30, 30, -30, 30, 30, -30, 30 };
        const float origin[2] = { -8.0f, 12.0f };
        bad |= run_case("off-centre 180", origin, 0x4000, sq);
    }
    {
        const float sq[8] = { -60, -40, 60, -40, 60, 40, -60, 40 };
        const float origin[2] = { 20.0f, -15.0f };
        bad |= run_case("off-centre 270", origin, 0x6000, sq);
    }

    free(ram);
    printf("edge_probe_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
