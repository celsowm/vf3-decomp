#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for the pose post-processor (0x8C09F432) */
int vf3_pose_post_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define OBJ    0x0C204000u   /* the actor (r4) */
#define SP     0x0C20FF00u   /* the wrapper's entry sp (r15) */
#define GATE   0x0C29B864u   /* the global that gates every point wrap */

/* the actor's point / destination / band-field offsets (the wrapper's own) */
#define P1  (OBJ + 0x1D58u)
#define P2  (OBJ + 0x1D64u)
#define P3  (OBJ + 0x1DC4u)
#define P4  (OBJ + 0x1DD0u)
#define P5  (OBJ + 0x1DE8u)
#define SRC1 (OBJ + 0x1DDCu)   /* the first quantiser's source */
#define SRC2 (OBJ + 0x1DF4u)   /* the second quantiser's source */
#define DST1 (OBJ + 0x233Cu)   /* the first quantiser's destination */
#define DST2 (OBJ + 0x2342u)   /* the second quantiser's destination */

/* the actor span that carries everything written (points, sources, dests) */
#define ACT_LO (OBJ + 0x1D40u)
#define ACT_HI (OBJ + 0x2360u)
/* the stack span the wrapper + the two callees write below the entry sp */
#define STK_LO (SP - 120u)
#define STK_HI  SP

#define NPOINTS 5u
#define NSRC    2u

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
    s->v[4] = OBJ;                    /* r4: the actor */
    s->v[14] = OBJ;                   /* r14 (saved/restored by the wrapper) */
    s->v[15] = SP;                    /* r15 */
    s->v[16] = 0x0C0ABCDEu;           /* pr */
    s->v[17] = 0x60000000u;           /* sr, T clear */
    s->v[18] = 0x00040001u;           /* fpscr, single precision */
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
    a->r[4] = OBJ; a->r[14] = OBJ; a->r[15] = SP;
    a->pr = 0x0C0ABCDEu;
    a->sr = 0x60000000u; a->fpscr = 0x00040001u;
}

/* The band fields the quantiser reads: hi_field (at +0x1FB0) is the high word
 * (hi = hi_field&0xffff + 1), lo_field (+0x1A00) the low word, mid_field
 * (+0x1FAC) the middle word, band (+0x3E) the current band value and kind
 * (+0x61) the kind byte. */
static void seed(uint16_t hi_field, uint16_t lo_field, uint16_t mid_field,
                 uint16_t band, uint8_t kind,
                 const float pts[NPOINTS][3], const float srcs[NSRC][3],
                 uint32_t gate)
{
    for (uint32_t a = ACT_LO; a < ACT_HI; a += 4)
        w32(a, 0xC0FFEE00u ^ (a & 0x7FF));
    /* clear the wrapper's whole stack span too: the wrapper and its two
     * callees write frame/save words down to sp-80, and a range that is not
     * re-seeded between sides would keep the previous run's residue and make
     * the stack compare pass vacuously. */
    for (uint32_t a = STK_LO; a < STK_HI; a += 4)
        w32(a, 0xDEADC0DEu ^ (a & 0x7FF));
    w32(GATE, gate);

    static const uint32_t poff[NPOINTS] = { 0x1D58u, 0x1D64u, 0x1DC4u,
                                            0x1DD0u, 0x1DE8u };
    static const uint32_t soff[NSRC]  = { 0x1DDCu, 0x1DF4u };
    for (unsigned i = 0; i < NPOINTS; ++i)
        for (int c = 0; c < 3; ++c)
            wf(OBJ + poff[i] + 4u * (uint32_t)c, pts[i][c]);
    for (unsigned i = 0; i < NSRC; ++i)
        for (int c = 0; c < 3; ++c)
            wf(OBJ + soff[i] + 4u * (uint32_t)c, srcs[i][c]);

    /* the destinations start as distinct junk so a write is observable */
    w16(DST1 + 0, 0x1111u); w16(DST1 + 2, 0x2222u); w16(DST1 + 4, 0x3333u);
    w16(DST2 + 0, 0x4444u); w16(DST2 + 2, 0x5555u); w16(DST2 + 4, 0x6666u);

    w16(OBJ + 0x3Eu, band);
    w8(OBJ + 0x61u, kind);
    w16(OBJ + 0x1FB0u, hi_field);
    w16(OBJ + 0x1FACu, mid_field);
    w16(OBJ + 0x1A00u, lo_field);
}

static int run_case(const char *label, uint16_t hi_field, uint16_t lo_field,
                    uint16_t mid_field, uint16_t band, uint8_t kind,
                    const float pts[NPOINTS][3], const float srcs[NSRC][3],
                    uint32_t gate)
{
    int bad = 0;
    printf("== %s\n", label);
    fflush(stdout);

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed(hi_field, lo_field, mid_field, band, kind, pts, srcs, gate);
    setup_guest(&gs, &gmap, gwin);
    if (!vf3_pose_post_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    /* snapshot the actor span and the stack span after the guest ran */
    uint8_t *ablob = (uint8_t *)malloc(ACT_HI - ACT_LO);
    memcpy(ablob, (const uint8_t *)at(ACT_LO), ACT_HI - ACT_LO);
    uint8_t *sblob = (uint8_t *)malloc(STK_HI - STK_LO);
    memcpy(sblob, (const uint8_t *)at(STK_LO), STK_HI - STK_LO);

    {
        vf3_native_aim a;
        seed(hi_field, lo_field, mid_field, band, kind, pts, srcs, gate);
        setup_native(&a);
        vf3_native_pose_post(&a, SP, OBJ);

        /* byte-exact actor compare: every write (wrapped points, quantised
         * source vectors, destination halfwords) is an exact small int */
        for (uint32_t a0 = ACT_LO; a0 < ACT_HI; a0 += 4) {
            float g, n;
            memcpy(&g, ablob + (a0 - ACT_LO), 4);
            memcpy(&n, at(a0), 4);
            if (memcmp(&g, &n, 4) != 0) {
                uint32_t ug, un; memcpy(&ug, &g, 4); memcpy(&un, &n, 4);
                if (bad < 10)
                    fprintf(stderr, "  ram @%08x: got %08x want %08x\n", a0, un, ug);
                bad++;
            }
        }
        /* the wrapper's own stack + the callees' scratch */
        for (uint32_t a0 = STK_LO; a0 < STK_HI; a0 += 4) {
            if (memcmp(sblob + (a0 - STK_LO), at(a0), 4) != 0) {
                uint32_t un; memcpy(&un, at(a0), 4);
                if (bad < 20)
                    fprintf(stderr, "  stk @%08x: got %08x\n", a0, un);
                bad++;
            }
        }

        /* the wrapper's contract: r0/r5 carry the last quantiser's return
         * (actor+0x1E00 when the wrap chain is ungated), r14 = the entry
         * value, r15 = the entry sp, pr untouched.  Compare r0/r5 to the
         * readable authority's own r0/r5. */
        if (a.r[0] != gs.v[0] || a.r[5] != gs.v[5]) {
            if (bad < 30)
                fprintf(stderr, "  r0/r5: native %08x/%08x guest %08x/%08x\n",
                        a.r[0], a.r[5], gs.v[0], gs.v[5]);
            bad++;
        }
        if (a.r[14] != gs.v[14] || a.r[15] != gs.v[15]) {
            if (bad < 30)
                fprintf(stderr, "  r14/r15: native %08x/%08x guest %08x/%08x\n",
                        a.r[14], a.r[15], gs.v[14], gs.v[15]);
            bad++;
        }
        if (a.pr != gs.v[16]) {
            if (bad < 30) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
            bad++;
        }
    }
    free(ablob); free(sblob);
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

    /* case 1: band == hi writes both destinations; the five points run the
     * whole wrap gamut (in-range, fold, reflect, clamp, fold negative) */
    {
        const float pts[NPOINTS][3] = {
            { 100.0f, 200.0f, 300.0f },          /* in range */
            { 500000.0f, 50.0f, 100.0f },        /* fold x */
            { 30000.0f, 5.0f, 30000.0f },        /* reflect y */
            { 700000.0f, 10.0f, 20.0f },         /* clamp upper */
            { -200000.0f, -50.0f, -100000.0f },  /* fold negative */
        };
        const float srcs[NSRC][3] = { { 1000.0f, 2000.0f, 3000.0f },
                                      { 4000.0f, 5000.0f, 6000.0f } };
        bad |= run_case("edge write (band==hi)", 5, 0, 0xFFFFu, 6, 0, pts, srcs, 0);
    }

    /* case 2: a band far outside the band chain leaves both destinations junk */
    {
        const float pts[NPOINTS][3] = {
            { 11.0f, 12.0f, 13.0f }, { 21.0f, 22.0f, 23.0f },
            { 31.0f, 32.0f, 33.0f }, { 41.0f, 42.0f, 43.0f },
            { 51.0f, 52.0f, 53.0f },
        };
        const float srcs[NSRC][3] = { { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f } };
        bad |= run_case("band skip", 5, 0, 0xFFFFu, 200, 0, pts, srcs, 0);
    }

    /* case 3: band inside the open band with kind 3 and a large z'' -> the
     * second quantiser negates z'' (> 0x7530) into its destination */
    {
        const float pts[NPOINTS][3] = {
            { 100.0f, 200.0f, 300.0f }, { 100.0f, 200.0f, 300.0f },
            { 100.0f, 200.0f, 300.0f }, { 100.0f, 200.0f, 300.0f },
            { 100.0f, 200.0f, 300.0f },
        };
        const float srcs[NSRC][3] = { { 100.0f, 200.0f, 300.0f },
                                      { 500.0f, 600.0f, 32000.0f } };
        /* lo=0 -> lo8=-8, lo1=1; band=0 is inside (0 > -8 and 0 < 1) */
        bad |= run_case("kind 3 negate", 5, 0, 0xFFFFu, 0, 3, pts, srcs, 0);
    }

    /* case 4: the gate freezes every point wrap (they become no-ops) but the
     * two quantiser calls still run on the unwrapped source vectors */
    {
        const float pts[NPOINTS][3] = {
            { 500000.0f, 50.0f, 100.0f }, { 30000.0f, 5.0f, 30000.0f },
            { 700000.0f, 10.0f, 20.0f }, { -200000.0f, -50.0f, -100000.0f },
            { 500000.0f, 50.0f, 100.0f },
        };
        const float srcs[NSRC][3] = { { 1000.0f, 2000.0f, 3000.0f },
                                      { 4000.0f, 5000.0f, 6000.0f } };
        bad |= run_case("gated wraps, quantisers still run", 5, 0, 0xFFFFu, 6, 0,
                        pts, srcs, 0x0C000000u);
    }

    free(ram);
    printf("pose_post_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
