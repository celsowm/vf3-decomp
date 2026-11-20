/* Differential replay of the native float division / reciprocal helper
 * (src/native/fdiv.c, 0x8C0533A4) against the readable guest port
 * (src/fight/readable/fdiv.c, `vf3_fdiv_entry`).
 *
 * Both sides run on the same flat RAM.  The body is a call-free, FPU-free
 * software reciprocal: it stores fr0 through a transient stack slot (width
 * follows FPSCR), pops it into r0, reads its literal-pool scratch constants,
 * does a carry-rotate fixed-point reciprocal, writes a two-word answer to the
 * caller's cell at sp+16, restores the four caller-saved registers from
 * sp+0/+4/+8/+12 and leaves r15 at sp+20.  SR's T bit is part of the contract.
 *
 * The whole RAM region is compared byte for byte, together with the contract
 * integer registers (r0..r3 restored to the caller's saved values, r15 = the
 * advanced sp), SR's T bit, and the outcome against the fixture itself (the
 * two cell words, the caller registers, the sp advance and the transient
 * fr0 slot at sp-4). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fdiv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_fdiv_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x320000u

#define POOL_BASE   0x0c053000u
#define STACK_BASE  0x0c31f000u
#define RESULT_BASE 0x0c2a7000u
#define CMP_HI      0x0c320000u

#define SP (STACK_BASE + 0xa0cu)   /* the entry stack pointer */

#define P_MASK    0x418u   /* 0x000000ff */
#define P_INF     0x420u   /* 0x000007ff */
#define P_QQNAN   0x424u   /* 0x7ff00000 */
#define P_BIAS    0x428u   /* 0x00000380 */

#define CALLER_R3 0x10201020u
#define CALLER_R2 0x20402040u
#define CALLER_R1 0x30603060u
#define CALLER_R0 0x40804080u

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

struct scenario {
    const char *name;
    uint32_t fr0;            /* the dividend's bits the caller left in fr0 */
    uint32_t cell_r3;        /* the word the guest writes to cell[0] */
    uint32_t cell_r0;        /* the word the guest writes to cell[1] */
    int t;                   /* the T bit the guest leaves */
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    /* pattern each window distinctly */
    for (uint32_t ad = POOL_BASE;   ad < POOL_BASE + 0x1000u;   ad += 4) w32(ad, 0x11111111u);
    for (uint32_t ad = STACK_BASE;  ad < STACK_BASE + 0x1000u;  ad += 4) w32(ad, 0x55555555u);
    for (uint32_t ad = RESULT_BASE; ad < RESULT_BASE + 0x1000u; ad += 4) w32(ad, 0x77777777u);

    /* the pool's four scratch constants */
    w32(POOL_BASE + P_MASK,  0x000000ffu);
    w32(POOL_BASE + P_INF,   0x000007ffu);
    w32(POOL_BASE + P_QQNAN, 0x7ff00000u);
    w32(POOL_BASE + P_BIAS,  0x00000380u);

    /* the caller's frame: four saved registers, then the result-cell pointer
     * at sp+16.  The transient fr0 store lands at sp-w. */
    w32(SP + 0u,  CALLER_R3);
    w32(SP + 4u,  CALLER_R2);
    w32(SP + 8u,  CALLER_R1);
    w32(SP + 12u, CALLER_R0);
    w32(SP + 16u, RESULT_BASE);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = SP;
    s->v[16] = 0x0c0432e4u;             /* pr */
    s->v[17] = 0x60000001u;             /* sr, T set */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->v[21] = sc->fr0;                 /* fr0: the dividend's bits */
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    /* ---- guest side ---- */
    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc);
    const int ok_guest = vf3_fdiv_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2], gr3 = gs.v[3];
    const uint32_t gr15 = gs.v[15], g_sr = gs.v[17];

    /* snapshot the guest's RAM over the compared region before re-seed */
    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - POOL_BASE);
    memcpy(gshot, ram + (POOL_BASE - RAM_BASE), CMP_HI - POOL_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(0x76543225u + i);
    a.r[15] = SP;
    a.pr = 0x0c0432e4u;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    a.fr[0] = vf3_aim_fbits(sc->fr0);
    vf3_native_fdiv(&a, SP);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    {
        int nb = 0;
        for (uint32_t ad = POOL_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - POOL_BASE), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", POOL_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* contract integer registers (restored caller regs + sp) */
    {
        int nb = 0;
        if (a.r[0] != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); nb++; }
        if (a.r[1] != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gr1); nb++; }
        if (a.r[2] != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], gr2); nb++; }
        if (a.r[3] != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gr3); nb++; }
        if (a.r[15] != gr15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the outcome against the fixture itself */
    {
        int nb = 0;
        if (r32(RESULT_BASE) != sc->cell_r3 || r32(RESULT_BASE + 4u) != sc->cell_r0) {
            fprintf(stderr, "  cell: %08x/%08x expected %08x/%08x\n",
                    r32(RESULT_BASE), r32(RESULT_BASE + 4u), sc->cell_r3, sc->cell_r0);
            nb++;
        }
        if (a.r[0] != CALLER_R0 || a.r[1] != CALLER_R1 ||
            a.r[2] != CALLER_R2 || a.r[3] != CALLER_R3) {
            fprintf(stderr, "  caller regs: native %08x %08x %08x %08x\n",
                    a.r[0], a.r[1], a.r[2], a.r[3]);
            nb++;
        }
        if (a.r[15] != SP + 20u) {
            fprintf(stderr, "  r15: native %08x expected %08x\n", a.r[15], SP + 20u);
            nb++;
        }
        if ((a.sr & 1u) != (unsigned)sc->t) {
            fprintf(stderr, "  T bit: native %u expected %d\n", a.sr & 1u, sc->t);
            nb++;
        }
        /* the transient store left fr0's bits at sp-w (single precision: sp-4) */
        if (r32(SP - 4u) != sc->fr0) {
            fprintf(stderr, "  transient slot at sp-4: %08x expected %08x\n",
                    r32(SP - 4u), sc->fr0);
            nb++;
        }
        printf("  outcome: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "infinity",
          .fr0 = 0x7f800000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x7ff00000u, .t = 0 },
        { .name = "NaN",
          .fr0 = 0x7fa00000u, .cell_r3 = 0x00000001u, .cell_r0 = 0x7ff00000u, .t = 0 },
        { .name = "zero",
          .fr0 = 0x00000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x00000000u, .t = 0 },
        { .name = "smallest denormal",
          .fr0 = 0x00000001u, .cell_r3 = 0x00000000u, .cell_r0 = 0x36a00000u, .t = 0 },
        { .name = "denormal 0x0000007f",
          .fr0 = 0x0000007fu, .cell_r3 = 0x00000000u, .cell_r0 = 0x370fc000u, .t = 0 },
        { .name = "one",
          .fr0 = 0x3f800000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x3ff00000u, .t = 0 },
        { .name = "two",
          .fr0 = 0x40000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x40000000u, .t = 0 },
        { .name = "minus two",
          .fr0 = 0xc0000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0xc0000000u, .t = 0 },
        { .name = "0x40a4a000",
          .fr0 = 0x40a4a000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x40149400u, .t = 0 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("fdiv_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
