/* Differential replay of the native matrix push leaf
 * (src/native/matrix_push.c, 0x8C03C4F0) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_push_entry`).
 *
 * Both sides seed the same flat RAM (the matrix-stack control block at
 * 0x0C19D2E4), the same XMTRX and an r4, then run the leaf.  The function
 * is call-free, no-stack and FPU-free.  After the run the whole XMTRX
 * (guest v[37..52] vs native a->xm[16]), r0, r4, SR.T, the control block
 * words and the whole low RAM region are compared byte-for-byte. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_push.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u

#define STK_CTL   0x0C19D2E4u
#define LOAD_SRC  0x0C1A0000u
#define LOW_END   0x0C19D000u   /* covers the control block + the pushed matrix */
#define HI_END    0x0C1B0000u

#define RETURN_PC 0x0c03c4e0u /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u

struct scenario {
    const char *name;
    uint32_t r4;
    uint32_t top;
    uint32_t ctl;
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
    w32(STK_CTL + 8, sc->top);
    /* a distinct load-source matrix at LOAD_SRC */
    for (uint32_t i = 0; i < 16; ++i)
        w32(LOAD_SRC + 4u * i, 0x3FC00000u + 0x11111111u * i);
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
    printf("== %s (r4 %08x top %08x ctl %08x)\n", sc->name, sc->r4, sc->top, sc->ctl);

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
    const int ok_guest = vf3_matrix_push_entry(&gs, &gmap);
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

    vf3_native_matrix_push(&a);

    int bad = 0;

    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    if (a.r[0] != gs.v[0]) {
        fprintf(stderr, "  r0 native %08x guest %08x\n", a.r[0], gs.v[0]); bad++;
    }
    if (a.r[4] != gs.v[4]) {
        fprintf(stderr, "  r4 native %08x guest %08x\n", a.r[4], gs.v[4]); bad++;
    }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  SR.T native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    /* every other general register unchanged */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 4) continue;
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }

    /* independent fixture model: the pushed matrix is always the OLD xm[0]
       (the load, if any, happens after the push) */
    {
        const uint32_t want = sc->xm_seed + 0x9E3779B9u * 1u;
        if (r32(sc->top) != want) {
            fprintf(stderr, "  pushed[0] got %08x want %08x\n", r32(sc->top), want); bad++;
        }
    }

    free(gshot);
    printf("  matrix_push: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "push only, room",    0u,          0x0C1AB000u, 0x00100000u, 0x40000000u },
        { "push past limit",    0u,          0x0C1AB000u, 0x00020002u, 0x5A5A5A5Au },
        { "push + load matrix", LOAD_SRC,    0x0C1AB000u, 0x00100000u, 0x40000000u },
        { "load with odd align",LOAD_SRC + 4,0x0C1AB000u, 0x00090005u, 0xCAFEBABEu },
        { "max count wrap",     0u,          0x0C1AA000u, 0x00007FFFu, 0x12345678u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("matrix_push_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
