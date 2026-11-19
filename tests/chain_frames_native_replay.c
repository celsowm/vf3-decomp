/* Differential replay of the native chain side-vector walk
 * (src/native/chain_frames.c, 0x8C071694) against the readable guest port
 * (src/fight/chain_frames.c, `vf3_chain_frames_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map, the
 * native through `ram_base`.  The fixture lays out a chain object (its node
 * array pointer, node count n and second count m) and a node array of 24-byte
 * nodes whose positions are irregular (so no two edge crosses cancel), seeds
 * the entry registers and the saved-register stack, and runs the two sides
 * from the same seed.  The nodes' +12 side vectors (the routine's only
 * output), the saved-register stack and the contract registers are compared.
 *
 * The readable normalises with the SH-4's approximate fsrra through the
 * round-toward-zero helpers; the native uses plain-C sqrtf, so the +12
 * vectors match within the native float tolerance (like the capsule family).
 * The saved stack, the register contract and SR's T bit (cleared by the last
 * cmp/gt) match bit for bit. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "chain_frames.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_chain_frames_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x2C0000u

#define OBJ    0x0C203000u
#define NODES  0x0C204000u
#define SP0    0x0C216000u

#define NNODES 12u         /* storage; fixtures use <= 6 */

/* compare the nodes' +12 side vectors + the saved stack */
#define NODE_REGION_LO NODES
#define NODE_REGION_HI (NODES + NNODES * 24u)
#define FRAME_REGION_LO (SP0 - 32u)
#define FRAME_REGION_HI (SP0 + 8u)

static float *ram;

static float *at(uint32_t addr)
{
    return (float *)((uint8_t *)ram + (addr - RAM_BASE));
}
static uint8_t *ab(uint32_t addr)
{
    return (uint8_t *)ram + (addr - RAM_BASE);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}

/* seed `nn` nodes (out of the NNODES storage) with well-spread, non-degenerate
 * 3D positions: no three are near-collinear and no two consecutive edge crosses
 * become anti-parallel (an anti-parallel pair makes X1+X2 = 0 and the side
 * vector undefined, so the two implementations legitimately diverge).  A node's
 * +12 is pre-seeded to known junk that the walk must overwrite. */
static const float NODE_POS[NNODES][3] = {
    { 3.2f, 1.1f, 4.9f },
    { 5.7f, 2.3f, 0.8f },
    { 1.4f, 5.9f, 2.2f },
    { 6.8f, 4.1f, 3.3f },
    { 2.9f, 7.4f, 6.1f },
    { 4.4f, 0.7f, 5.5f },
    { 7.6f, 3.8f, 1.7f },
    { 0.9f, 6.4f, 7.2f },
    { 5.1f, 5.3f, 0.6f },
    { 3.7f, 2.8f, 7.9f },
    { 0.2f, 8.1f, 3.4f },
    { 6.3f, 6.9f, 4.6f },
};
static void seed_nodes(int nn)
{
    for (int i = 0; i < (int)NNODES; ++i) {
        uint32_t b = NODES + 24u * (uint32_t)i;
        wf(b + 0u,  NODE_POS[i][0]);
        wf(b + 4u,  NODE_POS[i][1]);
        wf(b + 8u,  NODE_POS[i][2]);
        (void)nn;
        /* +12 garbage the walk overwrites on every reached node */
        wf(b + 12u, (float)(i + 1));
        wf(b + 16u, (float)(20 - i));
        wf(b + 20u, (float)(i * i + 3));
    }
}

/* place the chain object; `nn` must be <= NNODES.  m is the second count. */
static void seed_obj(uint32_t a97, int n, int m)
{
    (void)a97;
    w32(OBJ + 4u, NODES);
    w32(OBJ + 88u, (uint32_t)n);
    w32(OBJ + 92u, (uint32_t)m);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t *regs, uint32_t pr, const float *frseed,
                        uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[4] = OBJ;
    s->v[15] = SP0;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;                 /* fpscr: round-toward-zero, PR single */
    for (int i = 0; i < 4; ++i) {
        uint32_t bits; memcpy(&bits, &frseed[i], 4);
        s->v[21 + 12 + i] = bits;           /* FR12..FR15 */
    }
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
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

struct fixture {
    const char *label;
    int n, m;
};

static int run_case(const struct fixture *fx)
{
    printf("== %s (n=%d m=%d)\n", fx->label, fx->n, fx->m);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x22220000u + (uint32_t)i * 0x2222u;
    const float frseed[4] = { 7.0f, 8.0f, 9.0f, 10.0f };   /* fr12..fr15 */
    const uint32_t pr = 0x0C0BCDE2u;
    const uint32_t sr = 0x60000001u;                        /* T set; cleared by the routine */

    /* ---- guest side ---- */
    memset((uint8_t *)at(OBJ), 0xAA, 0x3000u);
    seed_nodes(fx->n);
    seed_obj(0, fx->n, fx->m);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, pr, frseed, sr);
    const int ok_guest = vf3_chain_frames_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *guest = (uint8_t *)malloc((NODE_REGION_HI - NODE_REGION_LO) +
                                       (FRAME_REGION_HI - FRAME_REGION_LO));
    memcpy(guest, at(NODE_REGION_LO), NODE_REGION_HI - NODE_REGION_LO);
    memcpy(guest + (NODE_REGION_HI - NODE_REGION_LO), at(FRAME_REGION_LO),
           FRAME_REGION_HI - FRAME_REGION_LO);

    /* ---- native side ---- */
    memset((uint8_t *)at(OBJ), 0xAA, 0x3000u);
    seed_nodes(fx->n);
    seed_obj(0, fx->n, fx->m);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram;
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.r[4] = OBJ;
    a.r[15] = SP0;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    a.fr[12] = frseed[0]; a.fr[13] = frseed[1];
    a.fr[14] = frseed[2]; a.fr[15] = frseed[3];
    vf3_native_chain_frames(&a, SP0, OBJ);

    int bad = 0;

    /* ---- node +12 side vectors: float tolerance ---- */
    {
        int nb = 0;
        for (uint32_t ad = NODE_REGION_LO + 12u; ad < NODE_REGION_HI; ad += 4) {
            float g, n;
            memcpy(&g, guest + (ad - NODE_REGION_LO), 4);
            memcpy(&n, at(ad), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0 && nb < 10)
                    fprintf(stderr, "  node+12 @%08x: got %08x want %08x\n",
                            ad, vf3_aim_ubits(n), vf3_aim_ubits(g));
                if (memcmp(&g, &n, 4) != 0) nb++;
                continue;
            }
            if (fabsf(g - n) > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
                if (nb < 10)
                    fprintf(stderr, "  node+12 @%08x: got %.7g want %.7g\n", ad, n, g);
                nb++;
            }
        }
        printf("  nodes: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* ---- saved stack: exact ---- */
    {
        int nb = 0;
        for (uint32_t ad = FRAME_REGION_LO; ad < FRAME_REGION_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (NODE_REGION_HI - NODE_REGION_LO) + (ad - FRAME_REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10)
                    fprintf(stderr, "  frame @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  frame: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* ---- contract registers ---- */
    {
        int nb = 0;
        for (int i = 8; i <= 14; ++i)
            if (a.r[i] != gs.v[i]) {
                if (nb < 30) fprintf(stderr, "  r%d: native %08x guest %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.r[15] != gs.v[15]) {
            if (nb < 30) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]);
            nb++;
        }
        if (a.pr != gs.v[16]) {
            if (nb < 30) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
            nb++;
        }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) {
            fprintf(stderr, "  sr T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }
        for (int i = 12; i <= 15; ++i) {
            uint32_t gb, nb2;
            memcpy(&gb, &a.fr[i], 4);
            memcpy(&nb2, &gs.v[21 + i], 4);
            if (gb != nb2) {
                if (nb < 30) fprintf(stderr, "  fr%d: native %08x guest %08x\n", i, gb, nb2);
                nb++;
            }
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(guest);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("chain_frames_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    /* n and m pick which of the eight phases run:
     *   n>=3,m>=3 -> all eight;
     *   n>=3,m=1  -> phases 1,2,6,7,8 (the 3/4/5 shared run needs m>=3);
     *   n=2,m=2   -> just the joins and the last node. */
    static const struct fixture all[] = {
        { "full eight phases",  6, 5 },
        { "no shared run",      4, 1 },
        { "joins and last",     2, 2 },
    };

    int bad = 0;
    for (size_t i = 0; i < sizeof all / sizeof all[0]; ++i)
        bad |= run_case(&all[i]);

    free(ram);
    printf("chain_frames_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
