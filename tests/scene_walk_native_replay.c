/* Differential replay of the native scene list walk (src/native/scene_walk.c,
 * 0x8C06233E) against the readable guest port (src/fight/readable/scene_walk.c,
 * `vf3_scene_walk_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, integer-only leaf (it tail-returns through r16 and never touches
 * r15), so it needs no stub and no FPU wrappers.  The fixture lays out the
 * literal pool (the threshold pointer at 0x0c06238c, the table base at
 * 0x0c062384), the threshold/table region, the node region and the flag/
 * stack region, seeds r4/r5 and runs the two sides from the same seed.
 *
 * The pool, the threshold/table region, the node region and the flag region
 * are compared byte for byte, together with the contract registers (r0 == r6,
 * r1, r2, r3, r5 = 0, SR's T bit; r4 and r15 untouched). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "scene_walk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scene_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x320000u

#define POOL_P1    0x0c06238cu
#define POOL_BASE  0x0c062384u
#define P1_TARGET  0x0c0eae00u
#define TBL_BASE   0x0c0eae08u
#define FLAG       0x0c31f8e4u

#define NODE_A 0x0c16d200u
#define NODE_B 0x0c16d240u
#define NODE_C 0x0c16d280u

/* ranges to compare byte for byte */
#define POOL_LO 0x0c062000u
#define POOL_HI 0x0c063000u
#define TBL_LO  0x0c0ea000u
#define TBL_HI  0x0c0eb000u
#define NODE_LO 0x0c16d000u
#define NODE_HI 0x0c16e000u
#define FLAG_LO 0x0c31f000u
#define FLAG_HI 0x0c320000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct node { uint32_t value; uint32_t next; };
struct scenario {
    const char *name;
    int32_t r4;
    uint32_t thr;
    uint32_t node0;   /* table[0]: first node (base + 0)   */
    uint32_t node1;   /* table[1]: first node (base + 20)  */
    struct node nodes[3];
};

static void put_node(uint32_t va, const struct node *n)
{
    if (va == 0) return;
    w32(va + 8, n->next);
    w32(va + 12, n->value);
}

static const uint32_t ENTRY = 0x0c06233eu;

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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    /* the literal pool */
    w32(POOL_P1, P1_TARGET);
    w32(POOL_BASE, TBL_BASE);
    /* the threshold */
    w32(P1_TARGET, sc->thr);
    /* the table: entries at base + 0 and base + 20 */
    w32(TBL_BASE + 0u, sc->node0);
    w32(TBL_BASE + 20u, sc->node1);
    /* the nodes */
    const struct node *n = sc->nodes;
    put_node(NODE_A, &n[0]);
    put_node(NODE_B, &n[1]);
    put_node(NODE_C, &n[2]);
    /* pattern the flag word so a wrong-width (byte) enable store is visible:
     * the halfword store leaves the two high bytes patterned, an 8-bit store
     * does not */
    w32(FLAG, 0x22222222u);
    w32(FLAG + 4, 0x33333333u);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x76543210u + (uint32_t)i;
    regs[4] = (uint32_t)sc->r4;
    regs[5] = FLAG;
    regs[15] = FLAG;                    /* r15 == r5 in the captured corpus */
    const uint32_t pr = 0x0c062004u;
    const uint32_t sr = 0x60000000u;    /* T clear */

    /* ---- guest side ---- */
    seed_all(sc);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_scene_walk_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot compared regions */
    size_t lens[4] = { POOL_HI - POOL_LO, TBL_HI - TBL_LO,
                       NODE_HI - NODE_LO, FLAG_HI - FLAG_LO };
    uint8_t *snap = (uint8_t *)malloc(lens[0] + lens[1] + lens[2] + lens[3]);
    size_t off = 0;
    memcpy(snap + off, ab(POOL_LO), lens[0]); off += lens[0];
    memcpy(snap + off, ab(TBL_LO), lens[1]); off += lens[1];
    memcpy(snap + off, ab(NODE_LO), lens[2]); off += lens[2];
    memcpy(snap + off, ab(FLAG_LO), lens[3]);

    /* guest contract registers */
    const uint32_t g_r0 = gs.v[0], g_r1 = gs.v[1], g_r2 = gs.v[2];
    const uint32_t g_r3 = gs.v[3], g_r5 = gs.v[5], g_r6 = gs.v[6];
    const uint32_t g_r4 = gs.v[4], g_r15 = gs.v[15], g_sr = gs.v[17];

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
    vf3_native_scene_walk(&a, FLAG);

    int bad = 0;

    /* RAM ranges */
    off = 0;
    const uint32_t bases[4] = { POOL_LO, TBL_LO, NODE_LO, FLAG_LO };
    const char *names[4] = { "pool", "table", "nodes", "flag/stack" };
    for (int w = 0; w < 4; ++w) {
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

    /* contract registers: r0 == r6, r1/r2/r3/r5, T, and r4/r15 untouched */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture itself: written flag, table stride, found node */
    {
        const uint32_t enabled = ((int32_t)sc->r4 >= (int32_t)sc->thr) ? 1u : 0u;
        uint32_t wflag;
        memcpy(&wflag, ab(FLAG), 4);
        if ((wflag & 0xffffu) != enabled ||
            a.r[2] != enabled || a.r[3] != 20u * enabled) {
            fprintf(stderr, "  flag/r2/r3 wrong (%08x %08x %08x, want %u %u)\n",
                    wflag, a.r[2], a.r[3], enabled, 20u * enabled);
            bad++;
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
        printf("scene_walk_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "enable1 first match",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { 0x5f0080, 0 }, { 0, 0 }, { 0, 0 } } },
        { .name = "enable1 second match",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { 0x11111111, NODE_B }, { 0x5f0080, 0 }, { 0, 0 } } },
        { .name = "enable1 not found",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { 0x11111111, 0 }, { 0, 0 }, { 0, 0 } } },
        { .name = "enable1 empty table",
          .r4 = 0x5f0080, .thr = 0x400000, .node0 = 0, .node1 = 0,
          .nodes = { { 0, 0 }, { 0, 0 }, { 0, 0 } } },
        { .name = "enable0 first match",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = NODE_C,
          .nodes = { { 0x100, 0 }, { 0x5f0080, 0 }, { 0x5f0080, 0 } } },
        { .name = "enable0 third match",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = 0,
          .nodes = { { 0x1, NODE_B }, { 0x2, NODE_C }, { 0x100, 0 } } },
        { .name = "enable0 not found",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = 0,
          .nodes = { { 0x1, NODE_B }, { 0x2, 0 }, { 0, 0 } } },
        { .name = "r4 == thr enable1",
          .r4 = 0x400000, .thr = 0x400000,
          .node0 = NODE_A, .node1 = NODE_B,
          .nodes = { { 0x400000, 0 }, { 0x5f0080, 0 }, { 0, 0 } } },
        { .name = "enable1 uses table1",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = NODE_C, .node1 = NODE_A,
          .nodes = { { 0x5f0080, 0 }, { 0x1111, 0 }, { 0x5f0080, 0 } } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("scene_walk_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
