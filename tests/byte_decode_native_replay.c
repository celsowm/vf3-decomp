/* Differential replay of the native word decoder (src/native/byte_decode.c,
 * 0x8C04538A) against the readable guest port (src/fight/byte_decode.c,
 * `vf3_byte_decode_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf pops a word off the caller's
 * stack, pushes it on its own stack, copies its four bytes into the object at
 * +8..+11 in the natural order or turned around, then classifies the object's
 * first byte into an answer at its +20.
 *
 * The literal pool, the table's cell, the table, the caller's stack and the
 * object sit at the game's own addresses, spanned by one flat buffer.  The
 * whole region is compared byte for byte, together with the registers, SR's T
 * bit and an independent fixture model that computes the object's bytes, the
 * answer and the T bit straight from the fixture.
 *
 * The scenarios cover the two byte orders, the mark, the limit, a limit that
 * is negative, and an entry that is not the turned-around one. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "byte_decode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_byte_decode_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

/* the lowest guest address read is the table's first word */
#define RAM_BASE 0x0c030000u
#define CMP_HI   0x0c120040u
#define RAM_SIZE (CMP_HI - RAM_BASE)

#define POOL_BASE 0x0c045440u
#define G_MARK  (POOL_BASE + 0x08u)   /* the byte that means "no value" */
#define G_BASE  (POOL_BASE + 0x0au)   /* the table's base: a signed halfword */
#define G_LIMIT (POOL_BASE + 0x0cu)   /* the byte at or above which the word counts */
#define G_TABLE (POOL_BASE + 0x14u)   /* the table */

#define PTR_BASE   0x0c050000u        /* the cell the table's global points at */
#define TBL_FIRST  0x0c030000u        /* the table: first word + the base */

#define STK_BASE    0x0c110000u
#define CALLER_SP   (STK_BASE + 0x80u)  /* the caller's stack: word0, word1 */
#define OWN_SP      (STK_BASE + 0x40u)  /* this function's stack */

#define OBJ_BASE 0x0c120000u
#define OBJ_BYTES  8u
#define OBJ_ANSWER 20u

struct scenario {
    const char *name;
    uint32_t entry;    /* the table's entry: 1 asks for the bytes turned around */
    uint32_t word0;    /* the word on the caller's stack */
    uint32_t word1;    /* the word behind it */
    uint16_t mark;     /* the byte that means "no value" */
    uint16_t limit;    /* the byte at or above which the word counts */
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w16(G_MARK, sc->mark);
    w16(G_LIMIT, sc->limit);
    w32(G_TABLE, PTR_BASE);
    w16(G_BASE, 0x0010u);               /* the table's base: the entry sits at the
                                         * first word plus this (a signed halfword) */
    w32(PTR_BASE, TBL_FIRST);           /* the cell the table's global points at */
    w32(TBL_FIRST + 0x10u, sc->entry);  /* the table's entry */
    w32(CALLER_SP, sc->word0);
    w32(CALLER_SP + 4u, sc->word1);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[5] = CALLER_SP;
    s->v[15] = OWN_SP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[5] = {
        { POOL_BASE, 0x20u }, { PTR_BASE, 0x10u }, { TBL_FIRST, 0x40u },
        { STK_BASE, 0x100u }, { OBJ_BASE, 0x40u },
    };
    for (unsigned i = 0; i < 5; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = 5;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the fixture's model: the object's byte at +8, the answer at +20 (with the
 * pushed word stored little-endian, the pushed byte 0 is the low byte) and the
 * T bit the caller sees */
static uint8_t model_first(const struct scenario *sc)
{
    const uint8_t lo = (uint8_t)(sc->word0 & 0xffu);
    const uint8_t hi = (uint8_t)(sc->word0 >> 24);
    return (sc->entry == 1u) ? hi : lo;
}

static void expect(const struct scenario *sc, uint32_t *answer, int *t_bit)
{
    const uint8_t first = model_first(sc);
    const uint8_t mark = (uint8_t)(sc->mark & 0xffu);
    if (first == mark) {
        *answer = 0xffffffffu;
        *t_bit = 1;
        return;
    }
    const int32_t lim = (int32_t)(int16_t)sc->limit;
    *t_bit = ((int32_t)first >= lim) ? 1 : 0;
    *answer = ((int32_t)first >= lim) ? sc->word1 : 0u;
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
    vf3_ram_win gwin[5];
    setup_guest(&gs, &gmap, gwin, sc);
    uint32_t in_v[54];
    memcpy(in_v, gs.v, sizeof in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_byte_decode_entry(&gs, &gmap);
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
    a.r[15] = OWN_SP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    vf3_native_byte_decode(&a);
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
        expect(sc, &answer, &t_bit);

        if (r32(OBJ_BASE + OBJ_ANSWER) != answer) {
            fprintf(stderr, "  answer %08x, expected %08x\n",
                    r32(OBJ_BASE + OBJ_ANSWER), answer);
            nb++;
        }
        /* the object's four bytes +8..+11, little-endian stored */
        {
            uint8_t first = model_first(sc);
            if (ab(OBJ_BASE + OBJ_BYTES)[0] != first) {
                fprintf(stderr, "  byte0 %02x, expected %02x\n",
                        ab(OBJ_BASE + OBJ_BYTES)[0], first);
                nb++;
            }
            const uint8_t lo = (uint8_t)(sc->word0 & 0xffu);
            const uint8_t hi = (uint8_t)(sc->word0 >> 24);
            const uint8_t b1 = (sc->entry == 1u) ? (uint8_t)(sc->word0 >> 16)
                                                 : (uint8_t)(sc->word0 >> 8);
            const uint8_t b2 = (sc->entry == 1u) ? (uint8_t)(sc->word0 >> 8)
                                                 : (uint8_t)(sc->word0 >> 16);
            const uint8_t b3 = (sc->entry == 1u) ? lo : hi;
            if (ab(OBJ_BASE + OBJ_BYTES)[3] != b3 ||
                ab(OBJ_BASE + OBJ_BYTES)[1] != b1 ||
                ab(OBJ_BASE + OBJ_BYTES)[2] != b2) {
                fprintf(stderr, "  bytes %02x%02x%02x%02x, expected %02x%02x%02x%02x\n",
                        ab(OBJ_BASE + OBJ_BYTES)[0], ab(OBJ_BASE + OBJ_BYTES)[1],
                        ab(OBJ_BASE + OBJ_BYTES)[2], ab(OBJ_BASE + OBJ_BYTES)[3],
                        first, b1, b2, b3);
                nb++;
            }
        }
        if (r32(OWN_SP - 4u) != sc->word0) {
            fprintf(stderr, "  pushed word %08x, expected %08x\n",
                    r32(OWN_SP - 4u), sc->word0);
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
        /* the natural order, the byte below the limit: no answer */
        { "natural zero",  0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* the natural order, the byte at the limit: the caller's word */
        { "natural word",  0u, 0x11223044u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* one below the limit: no answer */
        { "just below",    0u, 0x1122303fu, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* the first byte exactly at the limit: the caller's word */
        { "exactly at the limit", 0u, 0x11223040u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* the natural order, the first byte is the mark: no value */
        { "natural mark",  0u, 0x000000eeu, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the first byte is now the last one */
        { "turned word",   1u, 0x44112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the first byte is the mark */
        { "turned mark",   1u, 0xee112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the byte below the limit: no answer */
        { "turned zero",   1u, 0x11112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* a limit of 255: only the byte 255 is at or above it */
        { "limit 255",     0u, 0x112230ffu, 0xcafebabeu, 0x00eeu, 0x00ffu },
        /* a negative limit: every byte is at or above it */
        { "negative limit", 0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x8000u },
        /* an entry that is not 1 asks for the natural order */
        { "other entry",   2u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("byte_decode_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
