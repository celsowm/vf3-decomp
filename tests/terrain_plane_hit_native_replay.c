/* Differential replay of the native terrain plane-height solver
 * (src/native/terrain_plane_hit.c, 0x8C0692A6) against the readable guest
 * port (src/fight/terrain_plane_hit.c, `vf3_terrain_plane_hit_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free FP body with
 * no device/FMTRX access: it reads a triangle's three vertex positions (P,
 * Q, R; the Q/R selection depends on r7), crosses the edge vectors, solves
 * the plane through them for the height at (FR4 = x, FR5 = z), writes the
 * height to r5's float and the stored normal (shape+20/24/28) to r6, and
 * returns (shape+0 << 1 & 0x1FFFC) | (shape+0 & 3) in r0.  It pushes r14 and
 * FR14 below sp0 and restores them.
 *
 * The fixture lays out the base table, the shape record, the four vertex
 * positions (P, A, B, C), the height/normal outputs and the stack frame, runs
 * the two sides from the same seed, and compares the touched RAM byte for
 * byte plus the contract registers (r0, r1, r4, r14, r15, pr) and the FR
 * bank. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "terrain_plane_hit.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_terrain_plane_hit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define BASE_STOR 0x0C113A0Cu   /* holds `base` */
#define BASE      0x0C100000u   /* the shape base for the vertex offsets */
#define SHAPE     0x0C16D000u   /* the shape record */
#define TRI_REC   0x0C16C000u   /* r4 -> triangle record */
#define OUT_H     0x0C16E000u   /* r5 -> height */
#define OUT_N     0x0C16E100u   /* r6 -> normal */
#define SP0       0x0C16E800u

/* regions covered: shape, triangle record, vertices, outputs, frame */
#define REGION_LO 0x0C100000u
#define REGION_HI 0x0C16ED00u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }

static void w32(uint32_t addr, uint32_t v)
{ uint8_t *p = ab(addr); p[0]=((uint8_t)v);p[1]=((uint8_t)(v>>8));p[2]=((uint8_t)(v>>16));p[3]=((uint8_t)(v>>24)); }
static void wf(uint32_t addr, float f) { uint32_t u; memcpy(&u, &f, 4); w32(addr, u); }

struct scenario {
    const char *name;
    int r7;                 /* whether the second vertex triple is selected */
    float x, z;             /* FR4, FR5 */
    float P[3], A[3], B[3], C[3];   /* the four candidate vertices */
    float n0, n1, n2;       /* the stored normal at shape+20/24/28 */
    uint32_t word;          /* shape+0 (the return word) */
    uint32_t offA, offB, offC;  /* shape+8/+12/+16 offsets from base */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4, uint32_t r5, uint32_t r6, uint32_t r7,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4; s->v[5] = r5; s->v[6] = r6; s->v[7] = r7;
    s->v[15] = SP0;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;
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
    w32(BASE_STOR, BASE);
    /* triangle record: +4 = offset of shape from base */
    w32(TRI_REC + 4, SHAPE - BASE);
    /* shape record */
    w32(SHAPE, sc->word);
    w32(SHAPE + 4, 0u);                     /* P offset */
    w32(SHAPE + 8, sc->offA);
    w32(SHAPE + 12, sc->offB);
    w32(SHAPE + 16, sc->offC);
    wf(SHAPE + 20, sc->n0); wf(SHAPE + 24, sc->n1); wf(SHAPE + 28, sc->n2);
    /* vertices */
    wf(BASE + 0x000, sc->P[0]); wf(BASE + 0x004, sc->P[1]); wf(BASE + 0x008, sc->P[2]);
    wf(BASE + 0x1000, sc->A[0]); wf(BASE + 0x1004, sc->A[1]); wf(BASE + 0x1008, sc->A[2]);
    wf(BASE + 0x2000, sc->B[0]); wf(BASE + 0x2004, sc->B[1]); wf(BASE + 0x2008, sc->B[2]);
    wf(BASE + 0x3000, sc->C[0]); wf(BASE + 0x3004, sc->C[1]); wf(BASE + 0x3008, sc->C[2]);
}

static void set_fr(vf3_matrix_state *s, int n, float f)
{ uint32_t u; memcpy(&u, &f, 4); s->v[21 + n] = u; }

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c0692bcu;
    const uint32_t sr = 0x60000000u;
    const int r7 = sc->r7;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, TRI_REC, OUT_H, OUT_N, (uint32_t)r7, pr, sr);
    set_fr(&gs, 4, sc->x); set_fr(&gs, 5, sc->z);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_terrain_plane_hit_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = REGION_HI - REGION_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REGION_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r1 = gs.v[1], g_r4 = gs.v[4];
    const uint32_t g_r14 = gs.v[14], g_r15 = gs.v[15];
    uint32_t g_fr[16];
    for (int i = 0; i < 16; ++i) g_fr[i] = gs.v[21 + i];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(0x76543210u + 21u + i);
    a.r[4] = TRI_REC; a.r[5] = OUT_H; a.r[6] = OUT_N; a.r[7] = (uint32_t)r7;
    a.r[15] = SP0;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    a.fr[4] = sc->x; a.fr[5] = sc->z;
    vf3_native_terrain_plane_hit(&a);

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
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[14] != g_r14) { fprintf(stderr, "  r14: native %08x guest %08x\n", a.r[14], g_r14); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        for (int i = 0; i < 16; ++i) {
            uint32_t n = vf3_aim_ubits(a.fr[i]);
            if (n != g_fr[i]) { fprintf(stderr, "  fr%d differs: %08x want %08x\n", i, n, g_fr[i]); nb++; }
        }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model of the return value */
    {
        int nb = 0;
        const uint32_t word = sc->word;
        const uint32_t want = ((word << 1) & 0x1FFFCu) | (word & 3u);
        if (a.r[0] != want) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], want); nb++; }
        if (a.r[1] != (word & 3u)) { fprintf(stderr, "  r1 %08x want %08x\n", a.r[1], word & 3u); nb++; }
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
        printf("terrain_plane_hit_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "first triple", .r7 = 0, .x = 0.0f, .z = 0.0f,
          .P = {1,0,2}, .A = {1,0,0}, .B = {1,1,0}, .C = {0,1,1},
          .n0 = 0, .n1 = 0, .n2 = 1, .word = 0x5,
          .offA = 0x1000, .offB = 0x2000, .offC = 0x3000 },
        { .name = "second triple", .r7 = 4, .x = 0.5f, .z = 0.5f,
          .P = {2,0,5}, .A = {1,0,1}, .B = {2,0,1}, .C = {2,1,2},
          .n0 = 0, .n1 = 1, .n2 = 0, .word = 0x1FFF0,
          .offA = 0x1000, .offB = 0x2000, .offC = 0x3000 },
        { .name = "second triple B", .r7 = 4, .x = -1.25f, .z = 2.75f,
          .P = {1,1,4}, .A = {0,0,0}, .B = {2,1,1}, .C = {1,2,1},
          .n0 = -1, .n1 = 0, .n2 = 0, .word = 0x7FFFFFFF,
          .offA = 0x1000, .offB = 0x2000, .offC = 0x3000 },
        { .name = "first triple B", .r7 = 0, .x = 3.0f, .z = -2.0f,
          .P = {0,1,3}, .A = {2,1,1}, .B = {1,1,3}, .C = {2,1,0},
          .n0 = 0.5f, .n1 = -0.5f, .n2 = 0, .word = 0x80000004,
          .offA = 0x1000, .offB = 0x2000, .offC = 0x3000 },
        { .name = "degenerate dodge", .r7 = 0, .x = 0.0f, .z = 0.0f,
          .P = {1,0,2}, .A = {1,1,0}, .B = {1,1,0}, .C = {2,0,-1},
          .n0 = 0, .n1 = 0, .n2 = 0, .word = 0,  /* <- degenerate triangle; fine */
          .offA = 0x1000, .offB = 0x2000, .offC = 0x3000 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("terrain_plane_hit_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
