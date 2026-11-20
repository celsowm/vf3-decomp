/* Differential replay of the native capped move (src/native/move_cap.c,
 * 0x8C08DD5C) against the readable guest port (src/fight/move_cap.c,
 * `vf3_move_cap_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf moves a position by the
 * difference between the old one and the current one, but never by more than
 * the longest movement the literal pool holds.
 *
 * The literal pool and the frame sit at the game's own addresses, spanned by
 * one flat buffer.  The whole region is compared byte for byte, together with
 * the registers, the FR bank, FPUL and SR's T bit, and the new position
 * against an independent fixture model worked out from the pool's own values
 * with the same FPU primitives the guest uses.
 *
 * The leaf runs under round-to-nearest and no FTZ (the readable test's FPSCR
 * is 0), so the native uses plain C float ops, `fmaf` and `1/sqrtf`. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "move_cap.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_move_cap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POOL_BASE 0x0c08ddc8u
#define POOL_LEN  8u
#define STACK_TOP 0x0c108000u
#define STACK_WIN_BASE (STACK_TOP - 12u)
#define STACK_LEN      0x40u
#define CMP_HI    (STACK_TOP + 0x40u)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define EPSILON_OFF 0u
#define MAXSTEP_OFF 4u

#define POS_X (STACK_TOP + 0x10u)
#define POS_Y (STACK_TOP + 0x14u)

#define EPSILON_BITS 0x33d6bf94u
#define MAXSTEP_BITS 0x40000000u
#define MAXSTEP_NEG_BITS 0xc0800000u

struct scenario {
    const char *name;
    uint32_t old_x, old_y, cur_x, cur_y;
    int neg_step;
};

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
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static uint32_t step_bits(const struct scenario *sc)
{
    return sc->neg_step ? MAXSTEP_NEG_BITS : MAXSTEP_BITS;
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w32(POOL_BASE + EPSILON_OFF, EPSILON_BITS);
    w32(POOL_BASE + MAXSTEP_OFF, step_bits(sc));
    w32(POS_X, sc->cur_x);
    w32(POS_Y, sc->cur_y);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->old_x;
    s->v[5] = sc->old_y;
    s->v[6] = POS_X;
    s->v[7] = POS_Y;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[2] = {
        { POOL_BASE, POOL_LEN }, { STACK_WIN_BASE, STACK_LEN },
    };
    for (unsigned i = 0; i < 2; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = 2;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the movement the fixture expects, worked out from the pool's own values with
 * the same FPU primitives the guest uses */
static void expect_move(const struct scenario *sc, uint32_t *out_x, uint32_t *out_y)
{
    const uint32_t fpscr = 0;
    const int32_t dx = (int32_t)(sc->cur_x - sc->old_x);
    const int32_t dy = (int32_t)(sc->cur_y - sc->old_y);
    const uint32_t fx = vf3_fpu_float((uint32_t)dx, fpscr);
    const uint32_t fy = vf3_fpu_float((uint32_t)dy, fpscr);

    const uint32_t sq = vf3_fpu_mac(fy, fy, vf3_fpu_binary(fx, fx, fpscr, '*'), fpscr);

    uint32_t inverse = 0;
    if (!(vf3_bits_f32(EPSILON_BITS) > vf3_bits_f32(sq)))
        vf3_fpu_fsrra(sq, fpscr, &inverse);

    const uint32_t len = vf3_fpu_binary(sq, inverse, fpscr, '*');
    uint32_t factor = vf3_fpu_binary(step_bits(sc), len, fpscr, '/');
    factor &= 0x7fffffffu;

    if (vf3_bits_f32(0x3f800000u) > vf3_bits_f32(factor)) {
        const uint32_t sx = vf3_fpu_binary(fx, factor, fpscr, '*');
        const uint32_t sy = vf3_fpu_binary(fy, factor, fpscr, '*');
        *out_x = sc->old_x + (uint32_t)vf3_f_trunc(vf3_bits_f32(sx));
        *out_y = sc->old_y + (uint32_t)vf3_f_trunc(vf3_bits_f32(sy));
    } else {
        *out_x = sc->old_x + (uint32_t)dx;
        *out_y = sc->old_y + (uint32_t)dy;
    }
}

static uint32_t factor_check(const struct scenario *sc)
{
    const uint32_t fpscr = 0;
    const int32_t dx = (int32_t)(sc->cur_x - sc->old_x);
    const int32_t dy = (int32_t)(sc->cur_y - sc->old_y);
    const uint32_t fx = vf3_fpu_float((uint32_t)dx, fpscr);
    const uint32_t fy = vf3_fpu_float((uint32_t)dy, fpscr);
    const uint32_t sq = vf3_fpu_mac(fy, fy, vf3_fpu_binary(fx, fx, fpscr, '*'), fpscr);
    uint32_t inverse = 0;
    if (!(vf3_bits_f32(EPSILON_BITS) > vf3_bits_f32(sq)))
        vf3_fpu_fsrra(sq, fpscr, &inverse);
    const uint32_t len = vf3_fpu_binary(sq, inverse, fpscr, '*');
    return vf3_fpu_binary(step_bits(sc), len, fpscr, '/') & 0x7fffffffu;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[2];
    setup_guest(&gs, &gmap, gwin, sc);
    uint32_t in_v[54];
    memcpy(in_v, gs.v, sizeof in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_move_cap_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &in_v[21u + i], 4);
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    a.r[15] = STACK_TOP;
    a.fpul = in_v[53];
    vf3_native_move_cap(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* registers + FR bank + FPUL + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr differs\n"); nb++; }
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t ub;
            memcpy(&ub, &a.fr[i], 4);
            if (ub != gs.v[21u + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        }

        uint32_t want_x, want_y;
        expect_move(sc, &want_x, &want_y);
        if (r32(POS_X) != want_x || r32(POS_Y) != want_y) {
            fprintf(stderr, "  position %08x/%08x, expected %08x/%08x\n",
                    r32(POS_X), r32(POS_Y), want_x, want_y);
            nb++;
        }
        if (a.r[0] != POOL_BASE + MAXSTEP_OFF) {
            fprintf(stderr, "  r0 %08x != %08x\n", a.r[0], POOL_BASE + MAXSTEP_OFF);
            nb++;
        }
        const int expect_t = (vf3_bits_f32(0x3f800000u) > vf3_bits_f32(factor_check(sc)));
        if (((a.sr & 1u) != 0) != expect_t) {
            fprintf(stderr, "  T bit is %u, expected %d\n", a.sr & 1u, expect_t);
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "still", 100u, 200u, 100u, 200u, 0 },
        { "short", 100u, 200u, 101u, 200u, 0 },
        { "short diagonal", 0u, 0u, 3u, 4u, 0 },
        { "long", 0u, 0u, 10u, 0u, 0 },
        { "long diagonal", 0u, 0u, 30u, 40u, 0 },
        { "at the cap", 0u, 0u, 2u, 0u, 0 },
        { "just over the cap", 0u, 0u, 3u, 0u, 0 },
        { "negative", 0u, 0u, (uint32_t)-10, (uint32_t)-5, 0 },
        { "big", 0u, 0u, 1000000u, 1000000u, 0 },
        { "fractional long", 0u, 0u, 7u, 11u, 0 },
        { "inexact dy square", 0u, 0u, 1u, 1234567u, 0 },
        { "fused rounding edge", 0u, 0u, 1u, 4269u, 0 },
        { "negative cap", 0u, 0u, 1u, 0u, 1 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("move_cap_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
