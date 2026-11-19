/* Differential replay of the native four-list gated max walk
 * (src/native/max_walk.c, 0x8C061910) against the readable guest port
 * (src/fight/readable/max_walk.c, `vf3_max_walk_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is
 * a self-contained integer-only leaf, so it needs no stub and no FPU
 * wrappers.  The fixture lays out the literal pool (with the fight
 * structure's address at 0x0c061a0c), the fight structure and its four list
 * heads, the node region, the stack and the two output words, seeds the
 * entry registers and runs the two sides from the same seed.
 *
 * The pool, the structure (heads), the node region and the stack are
 * compared byte for byte, together with the two output words and the
 * contract registers (r0 = 0, r6 = 0, r7 = the first max, r12/r13/r14
 * restored, r15 flat, r1/r2 leftovers and SR's T bit). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "max_walk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_max_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define POOL_BASE 0x0c061000u   /* the literal pool, holding st */
#define ST_SLOT   0x0c061a0cu
#define ST_BASE   0x0c0ea000u   /* the fight structure window */
#define ST        0x0c0eae08u
#define STACK_BASE 0x0c31f000u  /* the stack window */
#define OUT0      0x0c40d000u   /* r4 target */
#define OUT1      0x0c40d004u   /* r5 target */
#define NODE_BASE 0x0c40f000u   /* the node region */

#define NB0 0x0c40f000u
#define NB1 0x0c40f020u
#define NA0 0x0c40f040u
#define NA1 0x0c40f060u
#define ND0 0x0c40f080u
#define ND1 0x0c40f0a0u
#define NC0 0x0c40f0c0u
#define NC1 0x0c40f0e0u

/* the flat RAM ranges to compare byte for byte */
#define POOL_LO POOL_BASE
#define POOL_HI (POOL_BASE + 0x1000u)
#define ST_LO   ST_BASE
#define ST_HI   (ST_BASE + 0x1000u)
#define NODE_LO NODE_BASE
#define NODE_HI (NODE_BASE + 0x1000u)
#define STACK_LO STACK_BASE
#define STACK_HI (STACK_BASE + 0x1000u)
#define OUT_LO  OUT0
#define OUT_HI  (OUT0 + 0x40u)

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

struct list { int count; uint16_t gate[2]; uint32_t val[2]; };
struct scenario {
    const char *name;
    uint32_t sp0;
    struct list A, B, C, D;   /* A@st+8, B@st, C@st+0x1c, D@st+0x14 */
};

/* lay one list out: node0 at base, node1 at base+0x20. */
static void place(const struct list *l, uint32_t base)
{
    if (l->count == 0) return;
    w16(base + 0, l->gate[0]);
    w32(base + 8, l->count == 2 ? base + 0x20u : 0u);
    w32(base + 16, l->val[0]);
    if (l->count == 2) {
        w16(base + 0x20 + 0, l->gate[1]);
        w32(base + 0x20 + 8, 0u);
        w32(base + 0x20 + 16, l->val[1]);
    }
}

static const uint32_t ENTRY = 0x0c061910u;
static const uint32_t RETURN_PC = 0x0c061994u;

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t *regs, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[15] = regs[15];
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;             /* fpscr: the chain's FPU gate */
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

/* seed the whole RAM space (the pool, structure, nodes, stack, outputs). */
static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    /* the pool: the fight structure's address */
    w32(ST_SLOT, ST);
    /* the structure: four heads (empty list -> head 0) */
    w32(ST + 0x08u, sc->A.count ? NA0 : 0u);
    w32(ST + 0x00u, sc->B.count ? NB0 : 0u);
    w32(ST + 0x1cu, sc->C.count ? NC0 : 0u);
    w32(ST + 0x14u, sc->D.count ? ND0 : 0u);
    /* the nodes */
    place(&sc->A, NA0);
    place(&sc->B, NB0);
    place(&sc->C, NC0);
    place(&sc->D, ND0);
}

/* independent walk over the fixture: list ungated (A/C) or gated (B/D). */
static uint32_t walk_max(uint32_t head, int gated)
{
    uint32_t m = 0;
    uint32_t node = head;
    while (node) {
        if (gated) {
            uint16_t g;
            g = (uint16_t)(ab(node)[0] | (ab(node)[1] << 8));
            if ((g & 4u) == 0) {
                uint32_t v = (uint32_t)ab(node)[16] | ((uint32_t)ab(node)[17] << 8) |
                             ((uint32_t)ab(node)[18] << 16) | ((uint32_t)ab(node)[19] << 24);
                if ((int32_t)v > (int32_t)m) m = v;
            }
        } else {
            uint32_t v = (uint32_t)ab(node)[16] | ((uint32_t)ab(node)[17] << 8) |
                         ((uint32_t)ab(node)[18] << 16) | ((uint32_t)ab(node)[19] << 24);
            if ((int32_t)v > (int32_t)m) m = v;
        }
        node = (uint32_t)ab(node)[8] | ((uint32_t)ab(node)[9] << 8) |
               ((uint32_t)ab(node)[10] << 16) | ((uint32_t)ab(node)[11] << 24);
    }
    return m;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x76543210u + (uint32_t)i;
    regs[4] = OUT0;
    regs[5] = OUT1;
    regs[15] = sc->sp0;
    const uint32_t pr = RETURN_PC;
    const uint32_t sr = 0x60000000u;    /* T clear */

    /* ---- guest side ---- */
    seed_all(sc);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_max_walk_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared regions (native runs on the same buffer later) */
    size_t lens[5] = { POOL_HI - POOL_LO, ST_HI - ST_LO, NODE_HI - NODE_LO,
                       STACK_HI - STACK_LO, OUT_HI - OUT_LO };
    uint8_t *snap = (uint8_t *)malloc(lens[0] + lens[1] + lens[2] + lens[3] + lens[4]);
    size_t off = 0;
    memcpy(snap + off, ab(POOL_LO), lens[0]); off += lens[0];
    memcpy(snap + off, ab(ST_LO), lens[1]); off += lens[1];
    memcpy(snap + off, ab(NODE_LO), lens[2]); off += lens[2];
    memcpy(snap + off, ab(STACK_LO), lens[3]); off += lens[3];
    memcpy(snap + off, ab(OUT_LO), lens[4]);

    /* the guest's register leftovers (r1/r2 are set where a list runs) */
    const uint32_t g_r1 = gs.v[1], g_r2 = gs.v[2], g_r7 = gs.v[7];
    const uint32_t g_r12 = gs.v[12], g_r13 = gs.v[13], g_r14 = gs.v[14];
    const uint32_t g_r15 = gs.v[15], g_r0 = gs.v[0], g_r6 = gs.v[6];
    const uint32_t g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_max_walk(&a, sc->sp0);

    int bad = 0;

    /* RAM ranges */
    off = 0;
    const uint32_t bases[5] = { POOL_LO, ST_LO, NODE_LO, STACK_LO, OUT_LO };
    const char *names[5] = { "pool", "struct", "nodes", "stack", "outputs" };
    for (int w = 0; w < 5; ++w) {
        int nb = 0;
        for (uint32_t ad = bases[w]; ad < bases[w] + lens[w]; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + off + (ad - bases[w]), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  %s @%08x: got %08x want %08x\n",
                                     names[w], ad, n, g);
                nb++;
            }
        }
        printf("  %s: %s\n", names[w], nb ? "DIFFERS" : "match");
        bad |= nb;
        off += lens[w];
    }

    /* contract registers */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if (a.r[7] != g_r7) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], g_r7); nb++; }
        if (a.r[12] != g_r12 || a.r[13] != g_r13 || a.r[14] != g_r14) {
            fprintf(stderr, "  r12/13/14: native %08x/%08x/%08x guest %08x/%08x/%08x\n",
                    a.r[12], a.r[13], a.r[14], g_r12, g_r13, g_r14); nb++;
        }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture itself: two maxima over the four lists */
    {
        uint32_t e_r7 = walk_max(sc->A.count ? NA0 : 0, 0);
        uint32_t b = walk_max(sc->B.count ? NB0 : 0, 1);
        if ((int32_t)b > (int32_t)e_r7) e_r7 = b;
        uint32_t e_r14 = walk_max(sc->C.count ? NC0 : 0, 0);
        uint32_t d = walk_max(sc->D.count ? ND0 : 0, 1);
        if ((int32_t)d > (int32_t)e_r14) e_r14 = d;
        uint32_t got0, got1;
        memcpy(&got0, ab(OUT0), 4);
        memcpy(&got1, ab(OUT1), 4);
        if (got0 != e_r7 || got1 != e_r14) {
            fprintf(stderr, "  [r4]/[r5]: %08x/%08x want %08x/%08x\n",
                    got0, got1, e_r7, e_r14); bad++;
        }
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
        printf("max_walk_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    struct scenario s1 = {
        .name = "four populated lists",
        .sp0 = 0x0c31f9ccu,
        .A = { .count = 2, .gate = {0,0}, .val = {0x0, 0x1} },
        .B = { .count = 2, .gate = {0,4}, .val = {0x0, 0x2} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x0, 0x2} },
        .D = { .count = 2, .gate = {0,4}, .val = {0x0, 0x3} },
    };
    struct scenario s2 = {
        .name = "gates hide the high values",
        .sp0 = 0x0c31fa20u,
        .A = { .count = 2, .gate = {0,0}, .val = {0x1, 0x2} },
        .B = { .count = 2, .gate = {0,4}, .val = {0x0, 0x64} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x3, 0x4} },
        .D = { .count = 2, .gate = {0,4}, .val = {0x0, 0x65} },
    };
    struct scenario s3 = {
        .name = "negative values and open gates",
        .sp0 = 0x0c31f9e0u,
        .A = { .count = 1, .gate = {0,0}, .val = {0xfffffffe} },
        .B = { .count = 1, .gate = {0,0}, .val = {0x5} },
        .C = { .count = 1, .gate = {0,0}, .val = {0xfffffffd} },
        .D = { .count = 1, .gate = {0,0}, .val = {0x6} },
    };
    struct scenario s4 = {
        .name = "all lists empty",
        .sp0 = 0x0c31f9f0u,
        .A = { .count = 0 }, .B = { .count = 0 },
        .C = { .count = 0 }, .D = { .count = 0 },
    };
    struct scenario s5 = {
        .name = "only gated lists populated",
        .sp0 = 0x0c31fa08u,
        .A = { .count = 0 }, .B = { .count = 1, .gate = {0,0}, .val = {0x7} },
        .C = { .count = 0 }, .D = { .count = 1, .gate = {0,0}, .val = {0x8} },
    };
    struct scenario s6 = {
        .name = "A empty, longer C",
        .sp0 = 0x0c31fac0u,
        .A = { .count = 0 },
        .B = { .count = 1, .gate = {0,0}, .val = {0x1} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x2, 0x9} },
        .D = { .count = 1, .gate = {0,4}, .val = {0x0, 0x20} },
    };

    struct scenario *scenarios[] = { &s1, &s2, &s3, &s4, &s5, &s6 };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(scenarios[i]);

    free(ram);
    printf("max_walk_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
