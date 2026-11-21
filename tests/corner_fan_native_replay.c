/* Differential replay of the native corner-fan (src/native/corner_fan.c,
 * 0x8C03FB10) against the readable guest port (src/fight/geom_readable.c,
 * `vf3_corner_fan_entry`).
 *
 * Both sides seed the same flat RAM (the object at r4, the corner table at
 * 0x0C0EA670, the output arrays at r5/r6, and the sp-4 dead-push slot) and
 * the same register/FR file, then run the leaf.  The leaf is call-free and
 * no-stack; it fans the object's +4/+8 base floats across the four corner
 * offsets.  The test compares the output arrays, the sp-4 dead push, the
 * output registers (r1, r3, r5, r6, r7), FPUL and SR's T bit, the FR-bank
 * outputs the leaf writes (fr0..fr11), and an independent fixture model that
 * recomputes each output from the defining equation. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "corner_fan.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_corner_fan_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define CORNER_TABLE 0x0C0EA670u
#define OBJ_BASE     0x0C118000u
#define OUT_A        0x0C11A000u
#define OUT_B        0x0C11A010u
#define SP0          0x0C11B000u

#define RETURN_PC 0x0c03fb22u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float f) { uint32_t u; memcpy(&u, &f, 4); w32(addr, u); }
static float fbits_to_f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

struct scenario {
    const char *name;
    uint32_t flags;
    uint32_t fr[4];   /* a b c d */
};

static const float CORNERS[8] = {
    0.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f
};

static void seed_all(const struct scenario *sc, float *base45)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* the four corner (u,v) pairs */
    for (int i = 0; i < 8; ++i) wf(CORNER_TABLE + 4u * i, CORNERS[i]);
    /* object: flags at +0x2C, base floats at +4 and +8 */
    w32(OBJ_BASE + 0x2Cu, sc->flags);
    wf(OBJ_BASE + 4u, base45[0]);
    wf(OBJ_BASE + 8u, base45[1]);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[5] = OUT_A;
    s->v[6] = OUT_B;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 4; ++i) VF3_FR(s, 4 + i) = sc->fr[i];
    for (unsigned i = 0; i < 16; ++i) fr_in[i] = s->v[VF3_REG_FR0 + i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear (the leaf sets it) */
    s->v[18] = 0x00024001u;      /* FPSCR: truncate (RM), FTZ */
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

static int compare_one(const struct scenario *sc, float *base45)
{
    printf("== %s (flags %u)\n", sc->name, sc->flags & 0xFu);

    seed_all(sc, base45);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, sc, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_corner_fan_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    seed_all(sc, base45);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_corner_fan(&a);

    int bad = 0;

    /* the output arrays + the dead sp-4 push (RAM) -- byte for byte */
    {
        const uint32_t addrs[] = { OUT_A, OUT_B, OUT_A + 4u, OUT_B + 4u,
                                    OUT_A + 8u, OUT_B + 8u, OUT_A + 12u, OUT_B + 12u,
                                    SP0 - 4u };
        for (unsigned e = 0; e < sizeof addrs / sizeof addrs[0]; ++e) {
            uint32_t n = vf3_aim_u32(&a, addrs[e]);
            uint32_t g = r32(addrs[e]);
            if (n != g) { fprintf(stderr, "  ram @%08x: native %08x guest %08x\n", addrs[e], n, g); bad++; }
        }
        printf("  ram(outputs+push): %s\n", bad ? "DIFFERS" : "match");
    }

    /* registers + FPUL + T vs the guest */
    if (a.r[1] != gs.v[1]) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gs.v[1]); bad++; }
    if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if (a.r[7] != gs.v[7]) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gs.v[7]); bad++; }
    if (a.fpul != gs.v[53]) { fprintf(stderr, "  FPUL: native %08x guest %08x\n", a.fpul, gs.v[53]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 1 || i == 3 || i == 5 || i == 6 || i == 7) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }
    /* FR-bank outputs the leaf writes (fr0..fr11) match the guest; the rest
     * (fr12..fr15) are untouched */
    for (unsigned i = 0; i <= 11; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g) {
            fprintf(stderr, "  fr%u: native %08x guest %08x\n", i, vf3_aim_ubits(a.fr[i]), g); bad++;
        }
    }
    for (unsigned i = 12; i < 16; ++i) {
        if (vf3_aim_ubits(a.fr[i]) != fr_in[i]) {
            fprintf(stderr, "  fr%u(untouched): native %08x entry %08x\n", i, vf3_aim_ubits(a.fr[i]), fr_in[i]); bad++;
        }
    }

    /* the fixture model: recompute the four outputs from the defining
     * equation with the same toward-zero + fused-mac rounding */
    {
        const float a_ = fbits_to_f(sc->fr[0]), b = fbits_to_f(sc->fr[1]),
                    c = fbits_to_f(sc->fr[2]), d = fbits_to_f(sc->fr[3]);
        const int col = (int)(sc->flags & 3u), row = (int)((sc->flags >> 2) & 3u);
        const float base_u = (float)col, base_v = (float)row;
        int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        const float bc = b * c, ac = a_ * c, bd = b * d, ad = a_ * d;
        int nb = 0;
        for (int i = 0; i < 4; ++i) {
            float u = CORNERS[2 * i], v = CORNERS[2 * i + 1];
            float du = u - base_u, dv = v - base_v;
            float out5 = base45[0], out6 = base45[1];
            if (du != 0.0f) {
                out5 = fmaf(du, ad, out5);      /* out5 += du*(a*d) */
                out6 = fmaf(ac, -du, out6);     /* out6 -= (a*c)*du */
            }
            if (dv != 0.0f) {
                out5 = fmaf(dv, bc, out5);      /* out5 += dv*(b*c) */
                out6 = fmaf(dv, bd, out6);      /* out6 += dv*(b*d) */
            }
            uint32_t g5 = vf3_aim_u32(&a, OUT_A + 4u * i);
            uint32_t g6 = vf3_aim_u32(&a, OUT_B + 4u * i);
            uint32_t w5, w6; memcpy(&w5, &out5, 4); memcpy(&w6, &out6, 4);
            if (g5 != w5) { fprintf(stderr, "  model out5[%d]: native %08x model %08x\n", i, g5, w5); nb++; }
            if (g6 != w6) { fprintf(stderr, "  model out6[%d]: native %08x model %08x\n", i, g6, w6); nb++; }
        }
        fesetround(saved);
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "corner 00",       .flags = 0x0000u, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "corner 01",       .flags = 0x0001u, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "corner 10",       .flags = 0x0002u, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "corner 11",       .flags = 0x0003u, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "row 11",          .flags = 0x000Cu, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "neg a",           .flags = 0x0001u, .fr = { 0xbf800000u, 0x3f000000u, 0x3f000000u, 0x3f800000u } },
        { .name = "neg d",           .flags = 0x0002u, .fr = { 0x3f800000u, 0x3f000000u, 0x3f000000u, 0xbf800000u } },
        { .name = "all-neg",         .flags = 0x0003u, .fr = { 0xbf800000u, 0xbf800000u, 0xbf800000u, 0xbf800000u } },
    };
    static float base45s[][2] = {
        { 3.0f, -2.0f },
        { -1.5f, 0.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i], base45s[i % 2]);

    free(ram);
    printf("corner_fan_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
