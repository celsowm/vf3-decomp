/* Differential replay of the native out-of-range flag (src/native/range_flag.c,
 * 0x8C0CAA9C) against the readable guest port (src/fight/range_flag.c,
 * `vf3_range_flag_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed a record (r4) that
 * holds a byte of flags and four floats.  It sets the byte's 0x10 bit when one
 * of the four floats is outside the range the two bounds describe, and clears
 * it again when they are all inside - but only when the byte's own 0x40 bit
 * says the values have to be looked at.  It uses the FR bank and keeps **no
 * stack frame**.
 *
 * The pool and the record sit at the game's own addresses, spanned by one flat
 * buffer.  The whole region is compared byte for byte, together with the
 * registers (r0..r15), the FR bank and the T bit, and the flag byte's value
 * against an independent model.  The scenarios cover the byte's "do not look"
 * bit being clear, everything in range, a value above the upper bound, a value
 * below the lower one and a mixture. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "range_flag.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_range_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c0cab10u
#define RAM_SIZE 0x2364f0u       /* pool .. record end */
#define CMP_HI   0x0c301000u

/* the windows */
#define POOL_BASE 0x0c0cab10u
#define POOL_LEN  0x20u
#define G_BYTE   (POOL_BASE + 0x0au)
#define G_VALUE  (POOL_BASE + 0x0cu)
#define G_LIMIT  (POOL_BASE + 0x10u)
#define G_FLOOR  (POOL_BASE + 0x14u)
#define REC_BASE 0x0c300000u
#define REC_LEN  0x100u
#define NWIN 2

#define OFF_BYTE  0x10u
#define OFF_VALUE 0x40u

#define FR0 21u   /* v[FR0+n] holds the bits of FRn */

struct scenario {
    const char *name;
    uint8_t byte;
    float v6, v7, v8, v9;
    float limit, floor;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint8_t  r8(uint32_t addr) { return ab(addr)[0]; }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    w16(G_BYTE, (uint16_t)OFF_BYTE);
    w16(G_VALUE, (uint16_t)OFF_VALUE);
    w32(G_LIMIT, fbits(sc->limit));
    w32(G_FLOOR, fbits(sc->floor));

    ab(REC_BASE + OFF_BYTE)[0] = sc->byte;
    /* the guest reads the four floats at OFF_VALUE, +12, -24 and -12
     * (the portable offset arithmetic: 6@off, 7@off+12, 8@off+12-36,
     * 9@off+12-36+12) */
    w32(REC_BASE + OFF_VALUE, fbits(sc->v6));
    w32(REC_BASE + OFF_VALUE + 12u, fbits(sc->v7));
    w32(REC_BASE + OFF_VALUE - 24u, fbits(sc->v8));
    w32(REC_BASE + OFF_VALUE - 12u, fbits(sc->v9));
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { REC_BASE, REC_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* The fixture-based model: is any of the four values out of range? */
static int is_out(const struct scenario *sc)
{
    const float *v[4] = { &sc->v6, &sc->v7, &sc->v8, &sc->v9 };
    for (unsigned i = 0; i < 4; ++i)
        if (*v[i] > sc->limit || *v[i] < sc->floor)
            return 1;
    return 0;
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
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_range_flag_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t ub = 0x76543225u + i;
        memcpy(&a.fr[i], &ub, 4);
    }
    a.r[4] = REC_BASE;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_range_flag(&a);
    free(seed_shot);

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

    /* the registers + FR bank + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        for (unsigned i = 0; i < 16; ++i) {
            if (fbits(a.fr[i]) != gs.v[FR0 + i]) {
                fprintf(stderr, "  fr%u: native %08x want %08x\n", i, fbits(a.fr[i]),
                        gs.v[FR0 + i]);
                nb++;
            }
        }
        int expect_out = 0;
        int want_t;
        if (sc->byte & 0x40u) {
            expect_out = is_out(sc);
            /* T bit = the last comparison's: set when out went on (or the
             * final comparison is true), clear when everything is inside */
            want_t = expect_out;
        } else {
            /* the gate is closed: the gate comparison is the last one and it
             * set T to 1 */
            want_t = 1;
        }
        if (((a.sr & 1u) != 0) != (want_t != 0)) {
            fprintf(stderr, "  %s: T: native %u want %d\n", sc->name, a.sr & 1u,
                    want_t);
            nb++;
        }
        /* the flag byte */
        uint8_t want_byte = sc->byte;
        if (sc->byte & 0x40u) {
            if (expect_out) want_byte |= 0x10u;
            else want_byte &= (uint8_t)~0x10u;
        }
        if (r8(REC_BASE + OFF_BYTE) != want_byte) {
            fprintf(stderr, "  byte: native %02x want %02x\n",
                    r8(REC_BASE + OFF_BYTE), want_byte);
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "do not look", 0x00u, 5, 6, 7, 8, 10, 0 },
        { "in range",    0x40u, 5, 6, 7, 8, 10, 0 },
        { "above",       0x40u, 5, 11, 7, 8, 10, 0 },
        { "below",       0x40u, 5, 6, -1, 8, 10, 0 },
        { "last high",   0x40u, 5, 6, 7, 11, 10, 0 },
        { "mixed",       0x40u, 11, -1, 12, 6, 10, 0 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("range_flag_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
