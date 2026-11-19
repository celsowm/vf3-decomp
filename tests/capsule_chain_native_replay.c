/* Differential replay of the native capsule node-chain keeper
 * (src/native/capsule_chain.c, 0x8C070008) against the readable guest port
 * (src/fight/capsule_chain.c, `vf3_capsule_chain_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map, the
 * native through `ram_base`.  The fixture lays out the owner, the capsule
 * record and an array of 24-byte nodes (a vec3 at the node start), seeds the
 * entry registers and the saved fr/pr words, and runs the two sides from the
 * same seed.  The node positions (a float quad every 24 bytes) are compared
 * at the native float tolerance; the frame/saved-register stack and the
 * contract registers (r8..r14, r15, pr, fr12..fr15, SR's T bit) are compared
 * bit for bit.
 *
 * The readable is the authority (it was promoted against the oracle).  The
 * native port is a re-implementation in plain C floats, so node positions
 * carry the FPU residual (fsrra/fipr against sqrtf), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "capsule_chain.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_capsule_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define OWNER 0x0C200000u
#define REC   0x0C200100u
#define NODES 0x0C201000u
#define SP0   0x0C202000u

/* the compare range: the node array and the frame + saved registers */
#define NODE_REGION_LO NODES
#define FRAME_REGION_LO (SP0 - 48u)
#define FRAME_REGION_HI (SP0 + 32u)

static float *ram;

static float *at(uint32_t addr)
{
    return (float *)((uint8_t *)ram + (addr - RAM_BASE));
}

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}

/* the link / axis / end / length / radius words of the capsule record */
static void seed_record(uint32_t count)
{
    w32(REC + 88u, count);            /* node count (+0x58) */
    wf(REC + 96u, 2.5f);              /* link length (+0x60) */
    wf(REC + 116u, 1.0f);             /* axis_a (+0x74) = (1,0,0) */
    wf(REC + 120u, 0.0f);
    wf(REC + 124u, 0.0f);
    wf(REC + 128u, 0.0f);             /* axis_b (+0x80) = (0,1,0) */
    wf(REC + 132u, 1.0f);
    wf(REC + 136u, 0.0f);
    wf(REC + 140u, 0.0f);             /* end_a (+0x8C) = origin */
    wf(REC + 144u, 0.0f);
    wf(REC + 148u, 0.0f);
    wf(REC + 152u, 0.0f);             /* end_b (+0x98) = origin */
    wf(REC + 156u, 0.0f);
    wf(REC + 160u, 0.0f);
    wf(REC + 168u, 8.0f);             /* axis length (+0xA8) */
    wf(REC + 172u, 1.0f);             /* radius (+0xAC) */
}

static void seed_nodes(uint32_t count, const float(*nodes)[3])
{
    for (uint32_t i = 0; i < count; ++i) {
        const uint32_t n = NODES + 24u * i;
        wf(n, nodes[i][0]); wf(n + 4u, nodes[i][1]); wf(n + 8u, nodes[i][2]);
    }
}

/* owner byte storage: write the two u8 values at +96 and +97 (little-endian) */
static void seed_owner(uint32_t b96, uint32_t b97)
{
    uint8_t *p = (uint8_t *)at(OWNER + 96u);
    p[0] = (uint8_t)b96;
    p[1] = (uint8_t)b97;
}

static void seed(size_t count, const float(*nodes)[3], uint32_t part,
                 uint32_t b96, uint32_t b97)
{
    memset((uint8_t *)at(OWNER), 0xAA, 0x2000u);
    seed_record((uint32_t)count);
    seed_nodes((uint32_t)count, nodes);
    seed_owner(b96, b97);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t count, uint32_t part, const uint32_t *regs,
                        uint32_t pr, const float *frseed)
{
    const uint32_t array_end = NODES + 24u * count;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[4] = OWNER; s->v[5] = REC; s->v[6] = array_end; s->v[7] = part;
    s->v[15] = SP0;
    s->v[16] = pr;
    s->v[17] = 0x60000001u;          /* sr, T bit SET (cleared on exit) */
    s->v[18] = 0x00040001u;          /* fpscr: the chain's FPU gate */
    for (int i = 0; i < 4; ++i) {
        uint32_t bits; memcpy(&bits, &frseed[i], 4);
        s->v[21 + 12 + i] = bits;    /* FR12..FR15 */
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
    uint32_t count;
    uint32_t part;
    uint32_t o96;                    /* owner byte +96 */
    uint32_t o97;                    /* owner byte +97 */
    const float(*nodes)[3];
};

static int run_case(const struct fixture *fx)
{
    const uint32_t array_end = NODES + 24u * fx->count;
    printf("== %s (count=%u part=%u o96=%u o97=%u)\n",
           fx->label, fx->count, fx->part, fx->o96, fx->o97);

    /* entry registers: r8..r14 seeded so their restore is observable */
    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x11110000u + (uint32_t)i * 0x1111u;
    const float frseed[4] = { 3.0f, 4.0f, 5.0f, 6.0f };   /* fr12..fr15 */
    const uint32_t pr = 0x0C0ABCDEu;

    /* ---- guest side ---- */
    seed(fx->count, fx->nodes, fx->part, fx->o96, fx->o97);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, fx->count, fx->part, regs, pr, frseed);
    const int ok_guest = vf3_capsule_chain_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    /* snapshot the node region + frame/saved stack */
    /* (re-read from gs after the run: gmap points at `ram`) */
    uint8_t *guest = (uint8_t *)malloc((array_end - NODES) + (FRAME_REGION_HI - FRAME_REGION_LO));
    memcpy(guest, at(NODES), array_end - NODES);
    memcpy(guest + (array_end - NODES), at(FRAME_REGION_LO), FRAME_REGION_HI - FRAME_REGION_LO);

    /* ---- native side ---- */
    seed(fx->count, fx->nodes, fx->part, fx->o96, fx->o97);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram;
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.r[4] = OWNER; a.r[5] = REC; a.r[6] = array_end; a.r[7] = fx->part;
    a.r[15] = SP0;
    a.pr = pr;
    a.sr = 0x60000001u;
    a.fpscr = 0x00040001u;
    a.fr[12] = frseed[0]; a.fr[13] = frseed[1];
    a.fr[14] = frseed[2]; a.fr[15] = frseed[3];
    vf3_native_capsule_chain(&a, SP0, OWNER, REC, array_end, (uint16_t)fx->part);

    int bad = 0;

    /* ---- node positions: float tolerance ---- */
    {
        float worst = 0.0f; uint32_t worst_at = 0; int nb = 0;
        for (uint32_t ad = NODES; ad < array_end; ad += 4) {
            /* only the vec3 words of each node carry positions that both write */
            float g, n;
            memcpy(&g, guest + (ad - NODES), 4);
            memcpy(&n, at(ad), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0) {
                    if (nb < 10)
                        fprintf(stderr, "  node @%08x: got %08x want %08x (non-finite)\n",
                                ad, vf3_aim_ubits(n), vf3_aim_ubits(g));
                    nb++;
                }
                continue;
            }
            const float d = fabsf(g - n);
            if (d > worst) { worst = d; worst_at = ad; }
            if (d > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
                if (nb < 12)
                    fprintf(stderr, "  node @%08x: got %.7g want %.7g (d=%.3g)\n",
                            ad, n, g, d);
                nb++;
            }
        }
        printf("  nodes: %s (worst %.3g at %08x)\n", nb ? "DIFFERS" : "match", worst, worst_at);
        bad |= nb;
    }

    /* ---- frame + saved registers: exact ---- */
    {
        int nb = 0;
        for (uint32_t ad = FRAME_REGION_LO; ad < FRAME_REGION_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (array_end - NODES) + (ad - FRAME_REGION_LO), 4);
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
                if (nb < 30)
                    fprintf(stderr, "  r%d: native %08x guest %08x\n", i, a.r[i], gs.v[i]);
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
        if ((a.sr & 1u) != 0u) { fprintf(stderr, "  sr T bit not cleared\n"); nb++; }
        if ((gs.v[17] & 1u) != 0u) { fprintf(stderr, "  guest sr T bit not cleared\n"); nb++; }
        for (int i = 12; i <= 15; ++i) {
            uint32_t gb, nb2;
            memcpy(&gb, &a.fr[i], 4);
            memcpy(&nb2, &gs.v[21 + i], 4);
            if (gb != nb2) {
                if (nb < 30)
                    fprintf(stderr, "  fr%d: native %08x guest %08x\n", i, gb, nb2);
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
        printf("capsule_chain_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    /* node seeds: a spread across the side / behind / beyond arms */
    static const float nodes_even[4][3] = {
        {  3.0f,  0.5f,  0.5f },   /* stage A side */
        { -0.5f,  0.2f,  0.2f },   /* behind the end cap */
        { 20.0f,  0.5f,  0.5f },   /* beyond the axis length */
        {  1.5f, -0.3f,  0.4f },   /* side */
    };
    static const float nodes_odd[3][3] = {
        {  2.0f,  0.4f,  0.3f },
        { -0.6f,  0.1f,  0.2f },
        { 12.0f,  0.6f, -0.3f },
    };
    static const float nodes_skip[4][3] = {
        {  1.0f,  0.3f,  0.2f },
        {  2.0f, -0.2f,  0.3f },
        {  3.0f,  0.4f, -0.2f },
        {  4.0f,  0.1f,  0.3f },
    };

    static const struct fixture all[] = {
        { "even two walkers", 4, 4u, 0u, 0u, nodes_even },
        { "odd one chain",    3, 4u, 0u, 0u, nodes_odd },
        { "skip_first (o97==4, part<=4)", 4, 3u, 0u, 4u, nodes_skip },
        { "skip_first (o96==8, part<=3)", 4, 2u, 8u, 0u, nodes_skip },
        { "single node",      1, 4u, 0u, 0u, (const float(*)[3])&nodes_odd[0] },
    };

    int bad = 0;
    for (size_t i = 0; i < sizeof all / sizeof all[0]; ++i)
        bad |= run_case(&all[i]);

    free(ram);
    printf("capsule_chain_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
