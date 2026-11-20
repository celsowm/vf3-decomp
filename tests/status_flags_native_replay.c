/* Differential replay of the native status flags (src/native/status_flags.c,
 * 0x8C0961F4) against the readable guest port (src/fight/status_flags.c,
 * `vf3_status_flags_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed a record (r5) and a
 * mask (r4).  It reads eight fields of the record and puts one bit in the
 * answer for every field that has a bit in common with the mask - the first
 * bit is *assigned* (the answer starts at zero), the rest are or-ed in, and
 * the last field's mask comes out of the literal pool (0x0c09630a), read only
 * when that field hits.  It keeps **no stack frame**.
 *
 * The pool and the record sit at the game's own addresses, spanned by one flat
 * buffer.  The whole region is compared byte for byte, together with the
 * registers (r0..r15), the T bit and the flag word's bytes against an
 * independent model written in the test.  The scenarios cover the empty
 * record, the full one, masks that count only the low bits, mixtures with the
 * field order and the gaps (no field at +16), the high-bit-only mask and the
 * single-field hits that prove the first bit is assigned and each of the eight
 * bits maps to the right field. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "status_flags.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_status_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c096300u
#define RAM_SIZE 0x269e00u       /* pool .. record end */
#define CMP_HI   0x0c300100u

/* the windows */
#define POOL_BASE 0x0c096300u
#define POOL_LEN  0x20u
#define G_LAST_BIT (POOL_BASE + 0x0au)
#define REC_BASE  0x0c300000u
#define REC_LEN   0x100u
#define NWIN 2

#define REC_FIELDS 10u

struct scenario {
    const char *name;
    uint32_t mask;          /* r4 */
    uint32_t word[REC_FIELDS];  /* the record's words: 0,4,8,12,(16),20,24,28,32,(36) */
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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the pool: the mask the last bit takes */
    w16(G_LAST_BIT, 0x0080u);

    /* the record */
    for (unsigned i = 0; i < REC_FIELDS; ++i)
        w32(REC_BASE + i * 4u, sc->word[i]);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x11111111u;
    s->v[5] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
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

/* the model: the eight field offsets, in the guest's order, and their bits */
static const struct { uint32_t off; uint32_t bit; } FIELDS[8] = {
    { 8u, 0x04u }, { 12u, 0x08u }, { 0u, 0x01u }, { 4u, 0x02u },
    { 24u, 0x10u }, { 20u, 0x20u }, { 28u, 0x40u }, { 32u, 0x80u },
};

static uint32_t model_flags(const struct scenario *sc)
{
    uint32_t flags = 0u;
    for (unsigned i = 0; i < 8; ++i) {
        uint32_t f = FIELDS[i].off / 4u;
        if (sc->word[f] & sc->mask)
            flags |= FIELDS[i].bit;
    }
    return flags;
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
    gs.v[4] = sc->mask;
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_status_flags_entry(&gs, &gmap);
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
    a.r[4] = sc->mask;
    a.r[5] = REC_BASE;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_status_flags(&a);
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

    /* the registers + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        /* the T bit the caller sees is the last comparison's: the field at
         * +32 has no bit in common with the mask */
        int expect_t = !(sc->word[32u / 4u] & sc->mask);
        if (((a.sr & 1u) != 0) != expect_t) {
            fprintf(stderr, "  T: native %u want %d\n", a.sr & 1u, expect_t);
            nb++;
        }
        /* the flag word */
        uint32_t want = model_flags(sc);
        if (a.r[0] != want) {
            fprintf(stderr, "  r0 flags: native %08x want %08x\n", a.r[0], want);
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
        { "empty", 0xffffffffu,
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
        { "full", 0xffffffffu,
          { 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0,
            0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0 } },
        { "masked out", 0x0000000fu,
          { 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0,
            0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0 } },
        { "mixed", 0x0000000fu,
          { 0x00000001u, 0x00000100u, 0x00000001u, 0x00000000u, 0,
            0x00000001u, 0x00000000u, 0x00000100u, 0x00000001u, 0 } },
        { "high bit", 0x80000000u,
          { 0, 0, 0, 0, 0, 0, 0, 0, 0x80000000u, 0 } },
        /* single-field hits, one per bit, to prove the mapping */
        { "bit 0x04 at +8", 0x0000fff0u, { 0, 0, 0x10u, 0, 0, 0, 0, 0, 0, 0 } },
        { "bit 0x08 at +12", 0x0000fff0u, { 0, 0, 0, 0x10u, 0, 0, 0, 0, 0, 0 } },
        { "bit 0x01 at +0", 0x0000fff0u, { 0x10u, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
        { "bit 0x02 at +4", 0x0000fff0u, { 0, 0x10u, 0, 0, 0, 0, 0, 0, 0, 0 } },
        { "bit 0x10 at +24", 0x0000fff0u, { 0, 0, 0, 0, 0, 0, 0x10u, 0, 0, 0 } },
        { "bit 0x20 at +20", 0x0000fff0u, { 0, 0, 0, 0, 0, 0x10u, 0, 0, 0, 0 } },
        { "bit 0x40 at +28", 0x0000fff0u, { 0, 0, 0, 0, 0, 0, 0, 0x10u, 0, 0 } },
        { "bit 0x80 at +32 from the pool", 0x0000fff0u,
          { 0, 0, 0, 0, 0, 0, 0, 0, 0x10u, 0 } },
        /* the pool's last bit is only read when the +32 field hits: with the
         * mask not covering it, no 0x80 anywhere */
        { "last field misses", 0x0000001fu,
          { 0x00000001u, 0x00000001u, 0x00000001u, 0x00000001u, 0,
            0x00000001u, 0x00000001u, 0x00000001u, 0x00000080u, 0 } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("status_flags_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
