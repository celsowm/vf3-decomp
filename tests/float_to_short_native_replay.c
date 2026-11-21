/* Differential replay of the native float-to-short (src/native/float_to_short.c,
 * 0x8C09D590) against the readable guest port (src/fight/small_leaves.c,
 * `vf3_float_to_short_entry`).
 *
 * Both sides seed the same flat RAM (the object's 42 source floats and the
 * destination run) and the same register file, then run the leaf.  The
 * function is call-free and no-stack; it truncates each source float toward
 * zero, narrows it to int16 and stores it as a halfword in the destination
 * run.  The whole RAM span is compared byte for byte against a snapshot of
 * the guest's writes, together with the output registers (r4, r5, r6, r7),
 * FPUL and SR's T bit, the untouched ones, and an independent fixture model
 * that computes the expected halfwords straight from the source floats. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "float_to_short.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_float_to_short_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define OBJ_BASE 0x0c118000u
#define SRC_OFF  0x1D58u
#define DST_OFF  0x1F50u
#define N        42u

#define LOW_END 0x0c118000u
#define HI_END  0x0c11c000u

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
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)(p[0] | ((uint16_t)p[1] << 8));
}

struct scenario {
    const char *name;
};

#define RETURN_PC 0x0c045ae4u

static void seed_all(uint32_t r4_in)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* the 42 source floats: a spread that exercises truncation, negatives,
     * values that overflow int16, a NaN and a huge value */
    static const uint32_t src[N] = {
        0x3f800000u, 0x3f400000u, 0xc1700000u, 0x3f133333u,
        0xc9280000u, 0x461c4000u, 0x3f99999au, 0xc0000000u,
        0x44814000u, 0x3f000000u, 0xc6fa0000u, 0x3f733333u,
        0x40200000u, 0xc0400000u, 0x3f2b851fu, 0x41900000u,
        0xc3a00000u, 0x3fa00000u, 0x3e99999au, 0x45bb8000u,
        0xc1120000u, 0x3f4ccccdu, 0x7fc00000u, 0xc2600000u,
        0x3dcccccdu, 0x3f0ccccdu, 0xc3f00000u, 0x3eb33333u,
        0x41f00000u, 0xc1a00000u, 0x3f19999au, 0x44610000u,
        0xc6c80000u, 0x3f666666u, 0x3f933333u, 0xc1200000u,
        0x42900000u, 0x3e4ccccdu, 0xc6a00000u, 0x3f2a3d71u,
        0x41800000u, 0x4788c000u,
    };
    for (unsigned e = 0; e < N; ++e)
        w32(r4_in + SRC_OFF + 4u * e, src[e]);
}

static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4_in, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4_in;             /* r4 */
    s->v[5] = 0x11111111u;       /* clobbered */
    s->v[6] = 0x22222222u;
    s->v[7] = 0x33333333u;
    s->v[0] = 0x44444444u;
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear (the leaf sets it) */
    s->v[18] = 0x00024001u;      /* FPSCR: plain (no SZ/PR) */
    s->v[53] = 0;                /* FPUL */
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

    seed_all(r4_in);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, r4_in, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_float_to_short_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);
    uint32_t g_fpul = gs.v[53];

    seed_all(r4_in);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    a.fpul = 0;
    vf3_native_float_to_short(&a);

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

    /* output registers + FPUL + T vs the guest */
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if (a.r[7] != gs.v[7]) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gs.v[7]); bad++; }
    if (a.fpul != g_fpul) { fprintf(stderr, "  FPUL: native %08x guest %08x\n", a.fpul, g_fpul); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4 || i == 5 || i == 6 || i == 7) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* the fixture model: each halfword is trunc(src float), narrowed to int16 */
    {
        int nb = 0;
        for (unsigned e = 0; e < N; ++e) {
            float f = vf3_aim_fbits(r32(r4_in + SRC_OFF + 4u * e));
            uint16_t want = (uint16_t)(int16_t)(int32_t)ftrc(f);
            uint16_t got = r16(r4_in + DST_OFF + 2u * e);
            if (got != want) { fprintf(stderr, "  dst[%u] @%08x: got %04x want %04x\n", e, r4_in + DST_OFF + 2u * e, got, want); nb++; }
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    free(gshot);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "base offset 0" },
        { .name = "base offset 8" },
    };
    static const uint32_t r4s[] = { OBJ_BASE, OBJ_BASE + 8u };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i], r4s[i]);

    free(ram);
    printf("float_to_short_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
