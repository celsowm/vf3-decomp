/* Differential replay of the native clamp pair (src/native/clamp_pair.c,
 * 0x8C08DCB0) against the readable guest port (src/fight/clamp_pair.c,
 * `vf3_clamp_pair_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf limits two numbers (r4 and r5)
 * into three ranges and writes four results to four places - two of them
 * addresses the caller leaves in its own frame (at the entry sp).  It saves
 * r13/r14 at sp-4/-8, so r15 returns to the entry sp.  The low bound is tested
 * first.
 *
 * The literal pool and the caller's frame sit at the game's own addresses,
 * spanned by one flat buffer.  The whole region is compared byte for byte,
 * together with the registers (r0..r15), the T bit and the four limited values
 * (the two register destinations, the two frame destinations, r1/r4, the last
 * bounds in r0/r5) against an independent model written in the test.  The
 * scenarios walk the two numbers through the ranges, including an inverted
 * range whose bounds are the wrong way round. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "clamp_pair.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_clamp_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c08dd48u
#define RAM_SIZE 0x7a2f0u       /* spans the pool .. the stack end (0x0c108038) */
#define CMP_HI   0x0c108038u

/* the windows */
#define POOL_BASE 0x0c08dd48u
#define POOL_LEN  12u
#define STACK_TOP 0x0c108000u
#define STACK_WIN_BASE (STACK_TOP - 8u)
#define STACK_LEN  0x40u
#define NWIN 2

#define X_LO  (POOL_BASE + 0x00u)
#define X_HI  (POOL_BASE + 0x02u)
#define Y1_LO (POOL_BASE + 0x04u)
#define Y1_HI (POOL_BASE + 0x06u)
#define Y2_LO (POOL_BASE + 0x08u)
#define Y2_HI (POOL_BASE + 0x0au)

#define BOUND_X_LO  (-1000)
#define BOUND_X_HI  ( 1000)
#define BOUND_Y1_LO (-2000)
#define BOUND_Y1_HI ( 2000)
#define BOUND_Y2_LO (  -50)
#define BOUND_Y2_HI (   50)

#define FRAME_WORD0 STACK_TOP
#define FRAME_WORD1 (STACK_TOP + 4u)
#define FRAME_DEST0 (STACK_TOP + 0x10u)
#define FRAME_DEST1 (STACK_TOP + 0x14u)
#define DEST_X (STACK_TOP + 0x18u)
#define DEST_Y (STACK_TOP + 0x1cu)

struct scenario {
    const char *name;
    uint32_t x;
    uint32_t y;
    int flip;
};

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
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool */
    w16(X_LO,  (uint16_t)(int16_t)BOUND_X_LO);
    w16(X_HI,  (uint16_t)(int16_t)BOUND_X_HI);
    w16(Y1_LO, (uint16_t)(int16_t)BOUND_Y1_LO);
    w16(Y1_HI, (uint16_t)(int16_t)BOUND_Y1_HI);
    w16(Y2_LO, (uint16_t)(int16_t)(sc->flip ? BOUND_Y2_HI : BOUND_Y2_LO));
    w16(Y2_HI, (uint16_t)(int16_t)(sc->flip ? BOUND_Y2_LO : BOUND_Y2_HI));

    /* the caller's frame: the two destination addresses */
    w32(FRAME_WORD0, FRAME_DEST0);
    w32(FRAME_WORD1, FRAME_DEST1);

    /* the destinations start full of a pattern so the writes are visible */
    memset(ab(DEST_X), 0x7e, 0x10);
    memset(ab(STACK_WIN_BASE), 0x5a, STACK_LEN);
    w32(FRAME_WORD0, FRAME_DEST0);
    w32(FRAME_WORD1, FRAME_DEST1);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0u;                 /* x, reset per scenario below */
    s->v[5] = 0u;                 /* y */
    s->v[6] = DEST_X;
    s->v[7] = DEST_Y;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { STACK_WIN_BASE, STACK_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the limit the fixture expects: the low bound first, like the guest */
static int32_t expect_limit(int32_t v, int32_t lo, int32_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    gs.v[4] = sc->x;
    gs.v[5] = sc->y;
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_clamp_pair_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->x;
    a.r[5] = sc->y;
    a.r[6] = DEST_X;
    a.r[7] = DEST_Y;
    a.r[15] = STACK_TOP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_clamp_pair(&a);
    free(seed_shot);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - RAM_BASE), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* the registers + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 4) continue;      /* checked below (y_second) */
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        /* r15 back on the entry sp, r13/r14 restored */
        if (a.r[15] != STACK_TOP) { fprintf(stderr, "  r15: %08x\n", a.r[15]); nb++; }
        if (a.r[13] != gs.v[13] || a.r[14] != gs.v[14]) {
            fprintf(stderr, "  r13/r14: %08x/%08x\n", a.r[13], a.r[14]); nb++;
        }
        if (((a.sr & 1u) != 0) != ((gs.v[17] & 1u) != 0)) {
            fprintf(stderr, "  sr T: native %u want %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }

        /* the model */
        const int32_t x = (int32_t)sc->x;
        const int32_t y = (int32_t)sc->y;
        const int32_t y2_lo = sc->flip ? BOUND_Y2_HI : BOUND_Y2_LO;
        const int32_t y2_hi = sc->flip ? BOUND_Y2_LO : BOUND_Y2_HI;
        const int32_t x_limited = expect_limit(x, BOUND_X_LO, BOUND_X_HI);
        const int32_t y_first = expect_limit(y, BOUND_Y1_LO, BOUND_Y1_HI);
        const int32_t y_second = expect_limit(y, y2_lo, y2_hi);

        const struct { uint32_t addr; uint32_t want; } chk[] = {
            { DEST_X, (uint32_t)x_limited },
            { DEST_Y, (uint32_t)y_first },
            { FRAME_DEST0, (uint32_t)x_limited },
            { FRAME_DEST1, (uint32_t)y_second },
        };
        for (unsigned i = 0; i < 4; ++i) {
            if (r32(chk[i].addr) != chk[i].want) {
                fprintf(stderr, "  dest %u @%08x: got %08x want %08x\n", i,
                        chk[i].addr, r32(chk[i].addr), chk[i].want);
                nb++;
            }
        }
        if (a.r[1] != (uint32_t)x_limited) { fprintf(stderr, "  r1: %08x\n", a.r[1]); nb++; }
        if (a.r[4] != (uint32_t)y_second) { fprintf(stderr, "  r4: %08x\n", a.r[4]); nb++; }
        if (a.r[0] != (uint32_t)y2_hi || a.r[5] != (uint32_t)y2_lo) {
            fprintf(stderr, "  last bounds r0/r5: %08x/%08x\n", a.r[0], a.r[5]); nb++;
        }
        int expect_t = (y >= y2_lo) ? (y > y2_hi) : 0;
        if (((a.sr & 1u) != 0) != expect_t) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, expect_t);
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "inside", 0u, 0u, 0 },
        { "x below", (uint32_t)-5000, 0u, 0 },
        { "x above", 5000u, 0u, 0 },
        { "x at the low bound", (uint32_t)BOUND_X_LO, 0u, 0 },
        { "x at the high bound", (uint32_t)BOUND_X_HI, 0u, 0 },
        { "y below the first range", 0u, (uint32_t)-9000, 0 },
        { "y above the first range", 0u, 9000u, 0 },
        { "y below the second range", 0u, (uint32_t)-300, 0 },
        { "y above the second range", 0u, 300u, 0 },
        { "y at a bound", 0u, (uint32_t)BOUND_Y2_HI, 0 },
        { "y at the low bound", 0u, (uint32_t)BOUND_Y2_LO, 0 },
        { "negative", (uint32_t)-7, (uint32_t)-9, 0 },
        { "both outside", 5000u, (uint32_t)-9000, 0 },
        { "inverted range", 0u, (uint32_t)BOUND_Y2_HI, 1 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("clamp_pair_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
