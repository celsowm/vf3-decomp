#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for the pose quantiser (0x8C09F500) */
int vf3_pose_turns_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define ACTOR  0x0C204000u   /* the actor (r4): band fields reach +0x1FB0 */
#define VEC    0x0C206000u   /* the three-float vector (r5) */
#define DEST   0x0C206100u   /* the three-halfword destination (r6) */
#define SP     0x0C206200u   /* the entry stack pointer (r15) */

/* the compare range: the actor through the destination and the stack */
#define REGION_LO ACTOR
#define REGION_HI (SP + 32u)

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
static void w8(uint32_t addr, uint8_t v) { ((uint8_t *)at(addr))[0] = v; }
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = ACTOR; s->v[5] = VEC; s->v[6] = DEST;
    for (int i = 8; i <= 14; ++i) s->v[i] = 0x0100u + (uint32_t)(i * 4u); /* saved */
    s->v[15] = SP;
    s->v[16] = 0x0C0ABCDEu;        /* pr */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr, single precision */
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static void setup_native(vf3_native_aim *a)
{
    memset(a, 0, sizeof *a);
    a->ram = ram; a->ram_base = RAM_BASE; a->f = SP;
    a->r[4] = ACTOR; a->r[5] = VEC; a->r[6] = DEST;
    for (int i = 8; i <= 14; ++i) a->r[i] = 0x0100u + (uint32_t)(i * 4u);
    a->r[15] = SP;
    a->pr = 0x0C0ABCDEu;
    a->sr = 0x60000000u; a->fpscr = 0x00040001u;
    a->r[0] = 0; a->r[1] = 0; a->r[2] = 0; a->r[3] = 0; a->r[7] = 0;
}

/* seed the actor's band fields, the source vector and the destination */
static void seed(float x, float y, float z,
                 int16_t band, int16_t hi, int16_t mid, int16_t lo, uint8_t kind)
{
    for (uint32_t a = REGION_LO; a < REGION_HI; a += 4)
        w32(a, 0xBEEF0000u ^ (a & 0x7FF));
    w16(ACTOR + 0x3Eu, (uint16_t)band);
    w8(ACTOR + 0x61u, kind);
    w16(ACTOR + 0x1FB0u, (uint16_t)hi);
    w16(ACTOR + 0x1FACu, (uint16_t)mid);
    w16(ACTOR + 0x1A00u, (uint16_t)lo);
    wf(VEC + 0, x); wf(VEC + 4, y); wf(VEC + 8, z);
    w16(DEST, 0); w16(DEST + 2, 0); w16(DEST + 4, 0);
}

static int run_case(const char *label, float x, float y, float z,
                    int16_t band, int16_t hi, int16_t mid, int16_t lo, uint8_t kind)
{
    int bad = 0;
    printf("== %s\n", label);
    fflush(stdout);

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed(x, y, z, band, hi, mid, lo, kind);
    setup_guest(&gs, &gmap, gwin);
    if (!vf3_pose_turns_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }

    uint8_t *gblob = (uint8_t *)malloc(REGION_HI - REGION_LO);
    memcpy(gblob, (const uint8_t *)at(REGION_LO), REGION_HI - REGION_LO);

    vf3_native_aim a;
    seed(x, y, z, band, hi, mid, lo, kind);
    setup_native(&a);
    vf3_native_pose_turns(&a, SP, ACTOR, VEC, DEST);

    /* compare the region word by word.  The quantiser does pure integer
     * arithmetic and exact int->float casts (no rounding), so every written
     * word must match the guest bit for bit.  An exact compare is required:
     * the frame/dest words hold small integers that as float bits are
     * denormals, and a float-tolerance compare would treat any two denormals
     * as "close" and hide a real difference. */
    for (uint32_t a0 = REGION_LO; a0 < REGION_HI; a0 += 4) {
        float g, n;
        memcpy(&g, gblob + (a0 - REGION_LO), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            uint32_t ug, un; memcpy(&ug, &g, 4); memcpy(&un, &n, 4);
            if (bad < 10)
                fprintf(stderr, "  ram @%08x: got %08x want %08x\n", a0, un, ug);
            bad++;
        }
    }

    /* compare the caller-visible registers: r8..r14 (restored from the stack),
     * r15 (the leaf restores the entry sp) and pr (never touched) */
    if (a.r[15] != gs.v[15]) {
        if (bad < 30) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]);
        bad++;
    }
    if (a.pr != gs.v[16]) {
        if (bad < 30) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
        bad++;
    }
    for (int i = 8; i <= 14; ++i) {
        if (a.r[i] != gs.v[i]) {
            if (bad < 30)
                fprintf(stderr, "  r%d: native %08x guest %08x\n", i, a.r[i], gs.v[i]);
            bad++;
        }
    }
    free(gblob);
    printf("  %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { fprintf(stderr, "image absent\n"); return 2; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fprintf(stderr, "image short\n"); return 2; }
        fclose(f);
    }

    int bad = 0;

    /* band == hi (hi word + 1), canonicalise positive x above the bound */
    bad |= run_case("hi edge, canon +x", 20500.0f, 1000.0f, -900.0f,
                    1000, 999, 2000, 900, 0);
    /* band == lo8 (lo - 8), canonicalise negative x below the bound */
    bad |= run_case("lo8 edge, canon -x", -21000.0f, -500.0f, 700.0f,
                    892, 3000, 4000, 900, 0);
    /* kind gate (hi < band < mid), kind 3, z'' = +32000 with a magnitude
     * over the 0x7530 limit: negate z'' */
    bad |= run_case("kind gate negate +z", 1200.0f, 300.0f, 32000.0f,
                    1500, 1000, 2000, 200, 3);
    /* kind gate, kind 3, z'' = -32000 (magnitude over the limit) -> negated */
    bad |= run_case("kind gate negate -z", -1200.0f, 300.0f, -32000.0f,
                    1500, 1000, 2000, 200, 3);
    /* kind gate but kind != 3 -> no negation */
    bad |= run_case("kind gate, kind 0", 1200.0f, 300.0f, 32000.0f,
                    1500, 1000, 2000, 200, 0);
    /* kind gate but |z''| small -> no negation */
    bad |= run_case("kind gate, small z", 1200.0f, 300.0f, 4000.0f,
                    1500, 1000, 2000, 200, 3);
    /* inside low band (lo8 < band < lo1), kind 3, z'' = -32000 -> negate */
    bad |= run_case("inside low band negate", -500.0f, -200.0f, -32000.0f,
                    895, 1000, 2000, 900, 3);
    /* band within range, x inside the band: no canonicalisation, no write */
    bad |= run_case("in range, no canon", 3000.0f, 2000.0f, 1000.0f,
                    1500, 1000, 2000, 200, 2);
    /* band >= mid with band > hi: the inside path, kind gate skipped */
    bad |= run_case("above mid", 3000.0f, 2000.0f, 1000.0f,
                    3000, 1000, 2000, 200, 3);
    /* band <= lo8: the done path, no write */
    bad |= run_case("below lo8", 3000.0f, 2000.0f, 1000.0f,
                    100, 1000, 2000, 900, 3);
    /* fractional vector values exercise the ftrc truncation */
    bad |= run_case("fractional", 12.7f, -3.2f, 0.5f,
                    1000, 1000, 2000, 900, 0);
    /* large float near the int32 boundary, canonicalised */
    bad |= run_case("large values", 4000000.0f, -3000000.0f, 2000000.0f,
                    1000, 1000, 2000, 900, 0);
    /* negative canonicalisation with z at the wrapped width */
    bad |= run_case("neg canon wrap z", -33000.0f, 100.0f, -2000.0f,
                    892, 3000, 4000, 900, 0);

    free(ram);
    printf("pose_turns_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
