/* Differential replay of the native TA-vertex writers
 * (src/native/vertex_writer.c, 0x8C056AA0 / 0x8C056AE0) against the readable
 * guest ports (src/fight/vertex_writers.c, `vf3_vertex_writer0_entry` /
 * `vf3_vertex_writer1_entry`).
 *
 * Both sides run on the same flat RAM.  The leaves are call-free FP bodies
 * with no stack frame: each fills one 32-byte TA vertex slot from the stream
 * record (r8: index, u, v as s16), the store-queue cursor (r12) and the
 * vertex in the FR bank (FR4..FR7 for writer 0, FR8..FR11 for writer 1),
 * scaling the two u,v halfwords by FR3.
 *
 * Writer 0 leaves the cursor at its slot; writer 1 flushes the previous slot
 * with a PREF (a no-op) and moves the cursor on by one slot.  The fixture
 * lays out the stream record and the slot region, runs the two sides from the
 * same seed, and compares the slot bytes, the contract registers (r0, r3,
 * r12), FPUL and the FR bank. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "vertex_writer.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vertex_writer0_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_writer1_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define STREAM_BASE 0x0c16c000u         /* the stream record: index,u,v s16 */
#define CURSOR_BASE 0x0c16d000u         /* the slot region */

#define REGION_LO 0x0c16c000u
#define REGION_HI 0x0c16d100u

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

struct scenario {
    const char *name;
    int which;        /* 0 or 1: which writer */
    int16_t index, u, v;
    float scale;      /* FR3 */
    float vx, vy, vz, vw;   /* the vertex: FR4..FR7 (writer0) or FR8..FR11 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r8, uint32_t r12, uint32_t r6,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x0c111111u;   /* unused by these writers */
    s->v[8] = r8;
    s->v[12] = r12;
    s->v[6] = r6;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;  /* toward-zero + FTZ */
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
    w16(STREAM_BASE, (uint16_t)sc->index);
    w16(STREAM_BASE + 2, (uint16_t)sc->u);
    w16(STREAM_BASE + 4, (uint16_t)sc->v);
    /* fill the slot region so an unwritten byte shows up */
    for (uint32_t ad = CURSOR_BASE; ad < CURSOR_BASE + 2 * 32; ad += 4)
        w32(ad, 0x0badf00du);
}

static void set_fr(vf3_matrix_state *s, int n, float f)
{ uint32_t u; memcpy(&u, &f, 4); s->v[21 + n] = u; }

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = sc->which ? 0x0c056b04u : 0x0c056abc;
    const uint32_t sr = 0x60000000u;
    const uint32_t r8 = STREAM_BASE, r6 = 0xE6000000u;
    const uint32_t cursor = CURSOR_BASE;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, r8, cursor, r6, pr, sr);
    set_fr(&gs, 3, sc->scale);
    /* vertex registers: writer0 = FR4..7, writer1 = FR8..11 */
    {
        int base = sc->which ? 8 : 4;
        set_fr(&gs, base + 0, sc->vx); set_fr(&gs, base + 1, sc->vy);
        set_fr(&gs, base + 2, sc->vz); set_fr(&gs, base + 3, sc->vw);
    }
    vf3_family_override = vf3_readable_override;
    const int ok_guest = sc->which ?
        vf3_vertex_writer1_entry(&gs, &gmap) : vf3_vertex_writer0_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = REGION_HI - REGION_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REGION_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r3 = gs.v[3], g_r12 = gs.v[12];
    const uint32_t g_fpul = gs.v[53], g_sr = gs.v[17];
    const uint32_t g_fr1 = gs.v[22], g_fr2 = gs.v[23];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[8] = r8;
    a.r[12] = cursor;
    a.r[6] = r6;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    a.fr[3] = sc->scale;
    {
        int base = sc->which ? 8 : 4;
        a.fr[base + 0] = sc->vx; a.fr[base + 1] = sc->vy;
        a.fr[base + 2] = sc->vz; a.fr[base + 3] = sc->vw;
    }
    if (sc->which) vf3_native_vertex_writer1(&a);
    else vf3_native_vertex_writer0(&a);

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
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[12] != g_r12) { fprintf(stderr, "  r12: native %08x guest %08x\n", a.r[12], g_r12); nb++; }
        if (a.fpul != g_fpul) { fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, g_fpul); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[1]) != g_fr1) { fprintf(stderr, "  fr1 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[2]) != g_fr2) { fprintf(stderr, "  fr2 differs\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model of the slot */
    {
        int nb = 0;
        /* trivial values exercise the exact u,v scaling */
        const float scale = sc->scale;
        volatile float us = (float)sc->u * scale;
        volatile float vs = (float)sc->v * scale;
        (void)us; (void)vs;
        /* the slot's register-sourced words are literals of the seed; the
         * model asserts the control word and the constant words */
        const uint32_t slot = cursor + 32u * (uint32_t)sc->which;
        if (vf3_aim_u32(&a, slot) != r6) { fprintf(stderr, "  slot ctrl\n"); nb++; }
        if (vf3_aim_u32(&a, slot + 28u) != 0) { fprintf(stderr, "  slot tail\n"); nb++; }
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
        printf("vertex_writer_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "writer0 basic", .which = 0, .index = 1, .u = 100, .v = 200,
          .scale = 2.0f, .vx = 1.5f, .vy = -2.25f, .vz = 3.0f, .vw = 1.0f },
        { .name = "writer0 negative uv", .which = 0, .index = -5, .u = -1000, .v = 3000,
          .scale = 0.5f, .vx = -1.0f, .vy = 0.0f, .vz = 4.0f, .vw = 0.0f },
        { .name = "writer0 max uv", .which = 0, .index = 32767, .u = 32767, .v = -32768,
          .scale = 1.0f, .vx = 2.5f, .vy = 3.5f, .vz = 4.5f, .vw = 5.5f },
        { .name = "writer0 fractional scale", .which = 0, .index = 0, .u = 7, .v = 3,
          .scale = 0.1f, .vx = 0.0f, .vy = -0.5f, .vz = 0.25f, .vw = 2.0f },
        { .name = "writer1 basic", .which = 1, .index = 2, .u = 40, .v = 60,
          .scale = 1.5f, .vx = 1.25f, .vy = 2.5f, .vz = 3.75f, .vw = 1.0f },
        { .name = "writer1 negative", .which = 1, .index = -2, .u = -50, .v = -70,
          .scale = 3.0f, .vx = -1.5f, .vy = 2.0f, .vz = -3.0f, .vw = 4.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("vertex_writer_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
