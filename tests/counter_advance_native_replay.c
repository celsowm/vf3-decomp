/* Differential replay of the native frame counters (src/native/counter_advance.c,
 * 0x8C08B338) against the readable guest port (src/fight/counter_advance.c,
 * `vf3_counter_advance_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf advances three counters in a
 * record (r4) - seven bits at +12, two at +14, four at +16 - and one in a block
 * (reached through the pool at 0x0c08b3f4, at +0x54, wrapping at 127), but only
 * when the value the pool slot at 0x0c08b3f0 points at has *no* bit in common
 * with the mask at 0x0c08b3ec.  It keeps **no stack frame**.
 *
 * The pool, the gate's value, the header, the block and the record sit at the
 * game's own addresses, spanned by one flat buffer (~3.36 MB).  The whole
 * region is compared byte for byte, together with the registers (r0..r15), the
 * T bit and the three record counters plus the block counter against an
 * independent model written in the test.  The scenarios walk the gate shut and
 * open, the empty mask, the odd wide counter, the wide wrap, the block wrap,
 * the narrow wraps and over-width counters. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "counter_advance.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_counter_advance_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

/* the flat buffer: from the pool to the end of the header window */
#define RAM_BASE 0x0c08b3e0u
#define RAM_SIZE 0x334c30u
#define CMP_HI   0x0c3c0010u

/* the windows */
#define POOL_BASE 0x0c08b3e0u
#define POOL_LEN  0x40u
#define G_MASK   (POOL_BASE + 0x0cu)
#define G_ENABLE (POOL_BASE + 0x10u)
#define G_BLOCK  (POOL_BASE + 0x14u)
#define VAL_BASE 0x0c3a0000u
#define VAL_LEN  0x10u
#define HDR_BASE 0x0c3c0000u
#define HDR_LEN  0x10u
#define BLK_BASE 0x0c3b0000u
#define BLK_LEN  0x80u
#define BLK_COUNTER 0x54u
#define REC_BASE 0x0c300000u
#define REC_LEN  0x40u
#define NWIN 5

struct scenario {
    const char *name;
    uint32_t mask;
    uint32_t gate;
    uint16_t wide;
    uint16_t narrow;
    uint16_t four;
    uint16_t counter;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool: the mask and the two pointers */
    w32(G_MASK, sc->mask);
    w32(G_ENABLE, VAL_BASE);
    w32(G_BLOCK, HDR_BASE);

    /* the value the gate points at */
    w32(VAL_BASE, sc->gate);

    /* the header's first word is the block */
    w32(HDR_BASE, BLK_BASE);

    /* the block's counter */
    w16(BLK_BASE + BLK_COUNTER, sc->counter);

    /* the record's three counters */
    w16(REC_BASE + 12u, sc->wide);
    w16(REC_BASE + 14u, sc->narrow);
    w16(REC_BASE + 16u, sc->four);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { VAL_BASE, VAL_LEN }, { HDR_BASE, HDR_LEN },
        { BLK_BASE, BLK_LEN }, { REC_BASE, REC_LEN },
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

/* the model: what the fixture says the leaf has to leave behind */
static void model_apply(const struct scenario *sc, uint16_t *out_wide,
                        uint16_t *out_narrow, uint16_t *out_four,
                        uint16_t *out_counter, int *out_t)
{
    if ((sc->mask & sc->gate) != 0) {
        /* the gate is shut: nothing moves, the T bit is clear */
        *out_wide = sc->wide;
        *out_narrow = sc->narrow;
        *out_four = sc->four;
        *out_counter = sc->counter;
        *out_t = 0;
        return;
    }
    /* the carry: the low bit of the incremented wide counter */
    const uint32_t carry = 1u & (uint32_t)(sc->wide + 1u);
    *out_wide = (uint16_t)((sc->wide + 1u) & 0x7fu);
    *out_narrow = (uint16_t)((sc->narrow + carry) & 0x03u);
    *out_four = (uint16_t)((sc->four + carry) & 0x0fu);
    /* the block counter: sign extend, add the carry, wrap at 127 when the
     * signed halfword is at or above it */
    const int32_t bc = (int32_t)(int16_t)sc->counter;
    int32_t nb = bc + (int32_t)carry;
    const int wraps = ((int32_t)(int16_t)nb) >= 127;
    if (wraps) nb = 0;
    *out_counter = (uint16_t)nb;
    *out_t = wraps;
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
    const int ok_guest = vf3_counter_advance_entry(&gs, &gmap);
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
    a.r[4] = REC_BASE;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_counter_advance(&a);
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

    /* the registers + T bit + the counters + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        if (((a.sr & 1u) != 0) != ((gs.v[17] & 1u) != 0)) {
            fprintf(stderr, "  sr T: native %u want %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }
        /* the counters against the model */
        uint16_t mw, mn, mf, mc;
        int mt;
        model_apply(sc, &mw, &mn, &mf, &mc, &mt);
        struct { uint32_t addr; uint16_t want; const char *n; } chk[] = {
            { REC_BASE + 12u, mw, "wide" },
            { REC_BASE + 14u, mn, "narrow" },
            { REC_BASE + 16u, mf, "four" },
            { BLK_BASE + BLK_COUNTER, mc, "block" },
        };
        for (unsigned i = 0; i < 4; ++i) {
            if (r16(chk[i].addr) != chk[i].want) {
                fprintf(stderr, "  %s counter @%08x: got %04x want %04x\n", chk[i].n,
                        chk[i].addr, r16(chk[i].addr), chk[i].want);
                nb++;
            }
        }
        if (((a.sr & 1u) != 0) != mt) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, mt);
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
        { "gate shut",   0x00000001u, 0x00000001u, 10u, 1u, 3u, 5u },
        { "gate open",   0x00000001u, 0x00000000u, 10u, 1u, 3u, 5u },
        { "empty mask",  0x00000000u, 0xffffffffu, 10u, 1u, 3u, 5u },
        { "odd wide",    0x00000001u, 0x00000000u, 11u, 1u, 3u, 5u },
        { "wide wraps",  0x00000001u, 0x00000000u, 127u, 1u, 3u, 5u },
        { "block wraps", 0x00000001u, 0x00000000u, 10u, 1u, 3u, 126u },
        { "narrow wraps", 0x00000001u, 0x00000000u, 10u, 3u, 15u, 5u },
        { "over wide",   0x00000001u, 0x00000000u, 300u, 9u, 20u, 5u },
        { "wide bit 6",  0x00000001u, 0x00000000u, 64u, 1u, 3u, 5u },
        { "block past 127", 0x00000001u, 0x00000000u, 10u, 1u, 3u, 200u },
        { "block at 32767 with carry", 0x00000001u, 0x00000000u, 10u, 1u, 3u, 32767u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("counter_advance_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
