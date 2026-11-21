/* Differential replay of the native negate-run (src/native/negate_run.c,
 * 0x8C09D408) against the readable guest port (src/fight/small_leaves.c,
 * `vf3_negate_run_entry`).
 *
 * Both sides seed the same flat RAM (the floats to negate) and the same
 * register file, then run the leaf.  The function is call-free and no-stack;
 * it sign-flips the floats in place and leaves r4, r5 and SR's T bit.  The
 * whole RAM span is compared byte for byte against a snapshot of the guest's
 * writes, together with the output registers (r4, r5) and T bit, the
 * untouched ones, and an independent fixture model that flips the signs
 * straight from the addresses. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "negate_run.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_negate_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define RUN_BASE 0x0c118000u   /* the floats the run negates */
#define LOW_END  0x0c110000u
#define HI_END   0x0c11c000u

#define SIGN 0x80000000u

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

/* the addresses the body touches: the 7-word run from base+8 stride 12, then
 * the 14-word run restarting 8 below the first run's end */
#define FIRST_COUNT 7u
#define SECOND_COUNT 14u

struct scenario {
    const char *name;
};

#define RETURN_PC 0x0c0432e4u

static void seed_all(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* the two 12-stride grids the body touches, with sign-clear, distinct
     * values; the second grid starts at +84 (8 below the first run's end) */
    for (unsigned e = 0; e < FIRST_COUNT; ++e)
        w32(RUN_BASE + 8u + 12u * e, 0x3f000000u + e);
    for (unsigned e = 0; e < SECOND_COUNT; ++e)
        w32(RUN_BASE + 84u + 12u * e, 0x40000000u + e);
    /* one already-negative, to prove the flip clears it */
    w32(RUN_BASE + 8u + 12u * 5u, 0xbf000005u);
}

static uint32_t b32(const uint8_t *snap, uint32_t addr)
{
    const uint8_t *p = snap + (addr - LOW_END);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4_in, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4_in;             /* r4 */
    s->v[5] = 0x11111111u;       /* r5 / r0: clobbered */
    s->v[0] = 0x22222222u;
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear (the leaf sets it) */
    s->v[18] = 0x00024001u;      /* FPSCR: plain (no SZ/PR), so it accepts */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc, uint32_t r4_in)
{
    printf("== %s (r4 %08x)\n", sc->name, r4_in);

    seed_all();
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, r4_in, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_negate_run_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_all();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    uint8_t *before = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(before, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);
    vf3_native_negate_run(&a);

    int bad = 0;

    /* RAM: native writes vs the guest snapshot, byte for byte */
    {
        int nb = 0;
        for (uint32_t ad = LOW_END; ad < HI_END; ad += 4) {
            uint32_t n = vf3_aim_u32(&a, ad);
            uint32_t g;
            memcpy(&g, gshot + (ad - LOW_END), 4);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", LOW_END, HI_END, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* output registers + T vs the guest */
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4 || i == 5) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* the fixture model: each touched word is the pre-run value, sign-flipped */
    {
        int nb = 0;
        uint32_t addr = r4_in + 8u;
        for (unsigned e = 0; e < FIRST_COUNT; ++e) {
            if (r32(addr) != (b32(before, addr) ^ SIGN)) { fprintf(stderr, "  first[%u] @%08x not flipped\n", e, addr); nb++; }
            addr += 12u;
        }
        addr = r4_in + 84u;
        for (unsigned e = 0; e < SECOND_COUNT; ++e) {
            if (r32(addr) != (b32(before, addr) ^ SIGN)) { fprintf(stderr, "  second[%u] @%08x not flipped\n", e, addr); nb++; }
            addr += 12u;
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    free(before);
    free(gshot);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "base offset 0" },
        { .name = "base offset 12" },
    };
    static const uint32_t r4s[] = { RUN_BASE, RUN_BASE + 12u };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i], r4s[i]);

    free(ram);
    printf("negate_run_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
