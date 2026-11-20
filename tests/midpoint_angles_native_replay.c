/* Differential replay of the native three-angle wrapper
 * (src/native/midpoint_angles.c, 0x8C09D452) against the readable guest port
 * (src/fight/readable/midpoint_angles.c, `vf3_midpoint_angles_entry`).
 *
 * Both sides run on the same flat RAM.  The wrapper saves r4/r5/r6 as
 * halfwords in a twelve-byte frame and composes three rotations onto XMTRX:
 * rotate_z with r6's, rotate_y with r5's, and a tail rotate_x with r4's.  The
 * callees are the readable rotation leaves / the native a->xm helpers, so no
 * stub is needed.
 *
 * The whole RAM region (pool + stack, covering the frame bytes the wrapper
 * writes) is compared byte for byte, together with the contract integer
 * registers (r0, r3, r4, r14, r15, pr, SR's T bit).  XMTRX is compared with
 * the same 1e-4 tolerance as the readable test's model (the native helper
 * uses sinf/cosf, the guest uses the game's own rotation tables, so they are
 * not bit-identical).  The frame bytes are also checked against the fixture
 * directly. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "midpoint_angles.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_midpoint_angles_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c09d000u
#define RAM_SIZE 0x80000u

#define POOL_BASE 0x0c09d000u
#define POOL_LEN  0x1000u
#define STACK_BASE 0x0c100000u
#define STACK_LEN 0x10000u
#define STACK_TOP 0x0c108000u
#define CMP_HI    0x0c110000u

#define RETURN_PC 0x0c0abcdeu

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
    uint16_t angle[3];              /* r4, r5, r6 */
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    for (uint32_t ad = POOL_BASE;   ad < POOL_BASE + POOL_LEN;   ad += 4) w32(ad, 0x22222222u);
    for (uint32_t ad = STACK_BASE;  ad < STACK_BASE + STACK_LEN; ad += 4) w32(ad, 0x33333333u);

    /* the literal pool: the three handler pointers, as in the image */
    w32(0x0c09d580u, 0x0c03c940u);
    w32(0x0c09d584u, 0x0c03c880u);
    w32(0x0c09d588u, 0x0c03c6c0u);
}

static void xmtrx_identity(vf3_matrix_state *s)
{
    for (unsigned i = 0; i < 16; ++i) s->v[37 + i] = 0u;
    s->v[37] = s->v[42] = s->v[47] = s->v[52] = 0x3f800000u;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->angle[0];
    s->v[5] = sc->angle[1];
    s->v[6] = sc->angle[2];
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;           /* pr */
    s->v[17] = 0x60000000u;         /* sr, T clear */
    s->v[18] = 0x00040001u;         /* fpscr */
    s->budget = 4000000u;
    xmtrx_identity(s);

    memset(map, 0, sizeof *map);
    win[0].base = POOL_BASE;  win[0].len = POOL_LEN;  win[0].data = ab(POOL_BASE);
    win[1].base = STACK_BASE; win[1].len = STACK_LEN; win[1].data = ab(STACK_BASE);
    map->wins = win;
    map->n = 2;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    /* ---- guest side ---- */
    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[2];
    setup_guest(&gs, &gmap, gwin, sc);
    const int ok_guest = vf3_midpoint_angles_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the guest's RAM over the whole region before re-seed */
    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->angle[0];
    a.r[5] = sc->angle[1];
    a.r[6] = sc->angle[2];
    a.r[15] = STACK_TOP;
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    /* XMTRX = identity */
    vf3_aim_identity(&a);
    vf3_native_midpoint_angles(&a, STACK_TOP);

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

    /* contract integer registers */
    {
        int nb = 0;
        if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); nb++; }
        if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); nb++; }
        if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); nb++; }
        if (a.r[14] != gs.v[14]) { fprintf(stderr, "  r14: native %08x guest %08x\n", a.r[14], gs.v[14]); nb++; }
        if (a.r[15] != gs.v[15]) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]); nb++; }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]); nb++; }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* XMTRX, with the readable test's tolerance (sinf/cosf vs game tables) */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t bits = gs.v[37 + i];
            float gf; memcpy(&gf, &bits, 4);
            if (fabsf(a.xm[i] - gf) > 1e-4f) {
                fprintf(stderr, "  xm[%u]: native %g guest %g\n", i, (double)a.xm[i], (double)gf);
                if (++nb > 6) break;
            }
        }
        printf("  xm: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the frame bytes against the fixture */
    {
        int nb = 0;
        const uint32_t frame = STACK_TOP - 16u;
        for (unsigned i = 0; i < 3; ++i) {
            const uint16_t got = (uint16_t)(r32(frame + 4u * i) & 0xffffu);
            if (got != (sc->angle[i] & 0xffffu)) {
                fprintf(stderr, "  frame+%u: %04x want %04x\n", 4u * i, got, sc->angle[i]);
                nb++;
            }
        }
        printf("  frame: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "identity", .angle = { 0, 0, 0 } },
        { .name = "z quarter", .angle = { 0, 0, 16384 } },
        { .name = "y quarter", .angle = { 0, 16384, 0 } },
        { .name = "x quarter", .angle = { 16384, 0, 0 } },
        { .name = "mixed", .angle = { 8192, 16384, 4096 } },
        { .name = "high-bit", .angle = { 40000, 50000, 60000 } },
        { .name = "capture-ish", .angle = { 1234, 4567, 8910 } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("midpoint_angles_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
