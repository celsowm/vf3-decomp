/* Differential replay of the native band probe (src/native/band_probe.c,
 * 0x8C0B0F28) against the readable guest port (src/fight/band_probe.c,
 * `vf3_band_probe_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed a point in r4/r5/r6
 * and a band in the literal pool: it takes the two differences the point makes
 * with its third coordinate, masks them, and asks whether they are inside the
 * band, writing the flags into a word the caller hands over in its own frame.
 *
 * The literal pool and the caller's frame sit at the game's own addresses,
 * spanned by one flat buffer.  The whole region is compared byte for byte,
 * together with the registers, SR's T bit and an independent fixture model
 * that computes the answer, the flag word and the T bit straight from the
 * fixture.  The scenarios cover the inside, outside and gated arm, the mask
 * flipping the sign, the band inverted, and the sixteen-bit cut. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "band_probe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_band_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POOL_BASE 0x0c0b0f60u
#define POOL_LEN  0x140u
#define STACK_TOP 0x0c108000u
#define STACK_WIN_BASE (STACK_TOP - 8u)
#define STACK_LEN      0x40u
#define CMP_HI    (STACK_TOP + 0x40u)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define BAND_LO (POOL_BASE + 0x04u)
#define BAND_HI (POOL_BASE + 0x06u)
#define IN_BIT  (POOL_BASE + 0x08u)
#define MASK    (POOL_BASE + 0x30u)
#define GATE    (POOL_BASE + 0x128u)
#define OUT_A   (POOL_BASE + 0x12cu)
#define OUT_B   (POOL_BASE + 0x130u)

#define FRAME_WORD (STACK_TOP)
#define FLAG_ADDR  (STACK_TOP + 0x10u)

struct scenario {
    const char *name;
    uint32_t x, y, z, r7;
    uint32_t mask;
    int32_t lo, hi;
    uint32_t gate;
    uint32_t flag;
    uint32_t in_bit, out_a, out_b;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint16_t h16(uint32_t addr) { return (uint16_t)(ab(addr)[0] | (ab(addr)[1] << 8)); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t addr, uint16_t v) { ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static int32_t s16(uint32_t v) { return (int32_t)(int16_t)v; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w16(BAND_LO, (uint16_t)(int16_t)sc->lo);
    w16(BAND_HI, (uint16_t)(int16_t)sc->hi);
    w16(IN_BIT,  (uint16_t)(int16_t)sc->in_bit);
    w32(MASK,  sc->mask);
    w32(GATE,  sc->gate);
    w32(OUT_A, sc->out_a);
    w32(OUT_B, sc->out_b);
    w32(FRAME_WORD, FLAG_ADDR);
    w32(FLAG_ADDR, sc->flag);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->x;
    s->v[5] = sc->y;
    s->v[6] = sc->z;
    s->v[7] = sc->r7;
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

/* the fixture's band test: the high bound first, then the low one */
static int band(int32_t v, int32_t hi, int32_t lo)
{
    if (v > hi) return 0;
    return v >= lo;
}

/* what the fixture says the guest has to answer, the word it has to leave
 * behind and the T bit the caller has to see */
static uint32_t expect(const struct scenario *sc, uint32_t *answer, int *t_bit)
{
    const int32_t dx = (int32_t)(uint32_t)(sc->x - sc->z);
    const int32_t dy = (int32_t)(uint32_t)(sc->y - sc->z);
    const int32_t mx = s16((uint32_t)dx ^ sc->mask);
    const int32_t my = s16((uint32_t)dy ^ sc->mask);
    uint32_t flag = sc->flag;

    if (band(mx, sc->hi, sc->lo) && band(my, sc->hi, sc->lo)) {
        flag |= (uint32_t)s16(sc->in_bit);
        *answer = 1;
        *t_bit = (my >= sc->lo) ? 1 : 0;
        return flag;
    }
    if ((sc->r7 & sc->gate) == 0) {
        *answer = 0;
        *t_bit = 1;                       /* the tst of the gate */
        return flag;
    }
    if (band(s16((uint32_t)dy), sc->hi, sc->lo)) flag |= sc->out_a;
    if (band(my, sc->hi, sc->lo)) flag |= sc->out_b;
    *answer = 1;
    *t_bit = (my > sc->hi) ? 1 : ((my >= sc->lo) ? 1 : 0);
    return flag;
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
    const int ok_guest = vf3_band_probe_entry(&gs, &gmap);
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
    a.r[4] = sc->x;
    a.r[5] = sc->y;
    a.r[6] = sc->z;
    a.r[7] = sc->r7;
    a.r[15] = STACK_TOP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    vf3_native_band_probe(&a);
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

    /* registers + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr differs\n"); nb++; }

        uint32_t answer = 0;
        int t_bit = 0;
        const uint32_t want_flag = expect(sc, &answer, &t_bit);

        if (a.r[0] != answer) {
            fprintf(stderr, "  r0 %08x, expected %08x\n", a.r[0], answer);
            nb++;
        }
        if (r32(FLAG_ADDR) != want_flag) {
            fprintf(stderr, "  flag word %08x, expected %08x\n", r32(FLAG_ADDR), want_flag);
            nb++;
        }
        if (a.r[1] != sc->mask) {
            fprintf(stderr, "  r1 %08x, expected %08x\n", a.r[1], sc->mask);
            nb++;
        }
        if (a.r[4] != (uint32_t)s16((uint32_t)sc->hi) ||
            a.r[5] != (uint32_t)s16((uint32_t)sc->lo)) {
            fprintf(stderr, "  bounds %08x/%08x\n", a.r[4], a.r[5]);
            nb++;
        }
        if (a.r[13] != 0x76543210u + 13u) {
            fprintf(stderr, "  r13 %08x\n", a.r[13]);
            nb++;
        }
        if (a.r[15] != STACK_TOP) {
            fprintf(stderr, "  stack at %08x\n", a.r[15]);
            nb++;
        }
        const uint32_t pushed = (uint32_t)(sc->y - sc->z);
        if (r32(STACK_TOP - 8u) != pushed) {
            fprintf(stderr, "  pushed difference %08x, expected %08x\n",
                    r32(STACK_TOP - 8u), pushed);
            nb++;
        }
        if (((a.sr & 1u) != 0) != t_bit) {
            fprintf(stderr, "  T bit is %u, expected %d\n", a.sr & 1u, t_bit);
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
        { "inside", 50u, (uint32_t)-30, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "on the high bound", 100u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "on the low bound", (uint32_t)-100, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "x above", 500u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "x below", (uint32_t)-500, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "y above", 0u, 500u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "y below", 0u, (uint32_t)-500, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "outside, the gate is open", 500u, 0u, 0u, 0x10u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "outside, other bits in r7", 500u, 0u, 0u, 0x30u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "the mask flips the sign", (uint32_t)-50, (uint32_t)-30, 0u, 0u,
          0x00008000u, -100, 100, 0x10u, 0u, 1u, 2u, 4u },
        { "outside, only the first bit", 500u, (uint32_t)-50, 0u, 0x10u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        { "outside, only the second bit", 500u, 50u, 0u, 0x10u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        { "the mask decides the second difference", 0x8000u, 0x8000u, 0u, 0u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        { "the gate is closed, the mask's bit in r7", 500u, 0u, 0u, 0x80000000u,
          0x80000000u, -100, 100, 0x10u, 0u, 1u, 2u, 4u },
        { "sixteen bits", 0x10050u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "a third number", 150u, 100u, 100u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "the band is inverted", 0u, 0u, 0u, 0u, 0x80000000u, 100, -100,
          0x10u, 0u, 1u, 2u, 4u },
        { "the gate is zero", 500u, 0u, 0u, 0x10u, 0x80000000u, -100, 100,
          0u, 0u, 1u, 2u, 4u },
        { "the flag word is not empty", 50u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0x40u, 1u, 2u, 4u },
        { "the inside bit is negative", 50u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 0xffffu, 2u, 4u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("band_probe_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
