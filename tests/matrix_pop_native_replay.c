/* Differential replay of the native matrix stack pop leaf
 * (src/native/matrix_pop.c, 0x8C03C4A0) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_pop_entry`).
 *
 * Both sides seed the same flat RAM (the matrix-stack control block at
 * 0x0C19D2E4 plus matrices on the stack) and the same r4, then run the leaf.
 * The function is call-free, no-stack and FPU-free.  After the run the whole
 * XMTRX (guest v[37..52] vs native a->xm[16]), r0/r2/r3/r4/r6/r7, SR.T, the
 * control block words and the whole low RAM region are compared byte-for-byte. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_pop.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u

#define STK_CTL   0x0C19D2E4u
#define BASE0     0x0C1A8000u   /* the control block's base */
#define LOW_END   0x0C19D000u
#define HI_END    0x0C1B0000u

#define RETURN_PC 0x0c03c490u /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u

struct scenario {
    const char *name;
    uint32_t r4;
    uint32_t ctl;    /* (limit<<16)|count */
    uint32_t base;
    uint32_t xm_seed;
};

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

static void seed_scene(const struct scenario *sc)
{
    memset(ram, 0x3a, RAM_SIZE);
    w32(STK_CTL, sc->ctl);
    w32(STK_CTL + 4, sc->base);
    /* pre-populate the stack matrices at base, base+64, base+128 ... */
    for (uint32_t m = 0; m < 4; ++m)
        for (uint32_t i = 0; i < 16; ++i)
            w32(sc->base + m * 64u + 4u * i, 0x3FC00000u + 0x11111111u * (m + 1u) + i);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, uint32_t sxm)
{
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t w = sxm + 0x9E3779B9u * (i + 1u);
        if (s) s->v[37 + i] = w;
        if (a) a->xm[i] = vf3_aim_fbits(w);
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (r4 %u ctl %08x base %08x)\n", sc->name, sc->r4, sc->ctl, sc->base);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[15] = 0x0C19D200u;
    gs.v[4] = sc->r4;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = FPSCR;
    gs.budget = 4000000u;

    seed_scene(sc);
    seed_xf(&gs, NULL, sc->xm_seed);

    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;

    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_matrix_pop_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_scene(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    seed_xf(NULL, &a, sc->xm_seed);

    vf3_native_matrix_pop(&a);

    int bad = 0;

    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    const uint32_t want_r[] = { 0u, 1u, 2u, 3u, 4u, 6u, 7u };
    for (unsigned k = 0; k < 7; ++k) {
        const unsigned i = want_r[k];
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  SR.T native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    /* every other general register unchanged */
    for (unsigned i = 0; i < 16; ++i) {
        int changed = 0;
        for (unsigned k = 0; k < 7; ++k) if (want_r[k] == i) changed = 1;
        if (changed) continue;
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }

    free(gshot);
    printf("  matrix_pop: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "pop one from three",     1u, 0x00040003u, BASE0,     0x40000000u },
        { "pop two from three",     2u, 0x00040003u, BASE0,     0x5A5A5A5Au },
        { "pop below empty (r4)",   5u, 0x00040002u, BASE0,     0xCAFEBABEu },
        { "pop empty (count 0)",    1u, 0x00040000u, BASE0,     0x12345678u },
        { "r4 <= 0 drops one",      0u, 0x00020002u, BASE0,     0xDEADBEEFu },
        { "r4 negative drops one",  (uint32_t)-1, 0x00020003u, BASE0, 0x9ABCDEF0u },
        { "pop exact count",        3u, 0x00040003u, BASE0,     0x13579BDFu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("matrix_pop_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
