/* Differential replay of the native word decoder (src/native/byte_decode.c,
 * 0x8C04538A) against the readable guest port (src/fight/byte_decode.c,
 * `vf3_byte_decode_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf calls nobody, uses no FPU and
 * keeps no callee-saved frame: it pops a word off the caller's stack (r5),
 * pushes it on its own stack (r15), copies its four bytes into the object (r4)
 * at +8..+11 (natural order or turned around, per a table), and classifies the
 * object's first byte into an answer at +20 (the mark -> -1, at or above the
 * limit -> the caller's next word, else zero).
 *
 * The literal pool, the cell, the table, the caller's stack, this function's
 * stack and the object sit at the game's own addresses, spanned by one flat
 * buffer.  The whole region is compared byte for byte, together with the
 * registers (r0..r7), the T bit, r15 (back on the entry sp) and the answer.
 * The scenarios cover the two byte orders, the mark, the limit, a negative
 * limit, and an entry that is not the turned-around one. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "byte_decode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_byte_decode_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c030000u
#define RAM_SIZE 0x0f0100u     /* spans the table .. the object (0x0c120040) */
#define CMP_HI   0x0c120040u

/* the windows */
#define POOL_BASE  0x0c045440u
#define POOL_LEN   0x20u
#define PTR_BASE   0x0c050000u
#define PTR_LEN    0x10u
#define TBL_BASE   0x0c030000u
#define TBL_LEN    0x40u
#define STK_BASE   0x0c110000u
#define STK_LEN    0x100u
#define OBJ_BASE   0x0c120000u
#define OBJ_LEN    0x40u
#define NWIN 5

#define G_MARK  (POOL_BASE + 0x08u)
#define G_BASE  (POOL_BASE + 0x0au)
#define G_LIMIT (POOL_BASE + 0x0cu)
#define G_TABLE (POOL_BASE + 0x14u)

#define PTR_FIRST PTR_BASE
#define TBL_ENTRY (TBL_BASE + 0x10u)
#define TBL_BASE_OFF 0x0010u

#define CALLER_SP (STK_BASE + 0x80u)
#define OWN_SP    (STK_BASE + 0x40u)

#define OBJ_BYTES  8u
#define OBJ_ANSWER 20u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint8_t r8(uint32_t addr) { return ab(addr)[0]; }
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

struct scenario {
    const char *name;
    uint32_t entry;
    uint32_t word0;
    uint32_t word1;
    uint16_t mark;
    uint16_t limit;
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool */
    w16(G_MARK, sc->mark);
    w16(G_LIMIT, sc->limit);
    w32(G_TABLE, PTR_BASE);
    w16(G_BASE, (uint16_t)TBL_BASE_OFF);

    /* the cell the table's global points at */
    w32(PTR_FIRST, TBL_BASE);

    /* the table's entry */
    w32(TBL_ENTRY, sc->entry);

    /* the object and the stack: fill first so the writes are visible */
    memset(ab(OBJ_BASE), 0xa5, OBJ_LEN);
    memset(ab(STK_BASE), 0x5a, STK_LEN);
    /* then the caller's words, on top of the stack fill */
    w32(CALLER_SP, sc->word0);
    w32(CALLER_SP + 4u, sc->word1);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[5] = CALLER_SP;
    s->v[15] = OWN_SP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { PTR_BASE, PTR_LEN }, { TBL_BASE, TBL_LEN },
        { STK_BASE, STK_LEN }, { OBJ_BASE, OBJ_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
}

/* the independent model of the answer, reading the fixture's bytes */
struct outcome { uint32_t answer; };
static struct outcome model(const struct scenario *sc)
{
    /* the four bytes of the pushed word, in memory (little-endian) order */
    uint8_t raw[4];
    raw[0] = (uint8_t)(sc->word0);
    raw[1] = (uint8_t)(sc->word0 >> 8);
    raw[2] = (uint8_t)(sc->word0 >> 16);
    raw[3] = (uint8_t)(sc->word0 >> 24);
    /* natural order writes +8..+11 = raw[0..3]; turned writes them reversed */
    uint8_t first;
    if (sc->entry == 1u) first = raw[3];
    else first = raw[0];
    struct outcome out;
    uint16_t mark = sc->mark & 0xffu;
    int16_t limit = (int16_t)sc->limit;
    if ((int32_t)first == (int32_t)mark) out.answer = 0xffffffffu;
    else if ((int32_t)first >= (int32_t)limit) out.answer = sc->word1;
    else out.answer = 0u;
    return out;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    seed_all(sc);            /* setup_guest does not seed RAM; re-seed */
    const int ok_guest = vf3_byte_decode_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = OBJ_BASE;
    a.r[5] = CALLER_SP;
    a.r[15] = OWN_SP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_byte_decode(&a, OWN_SP);

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

    /* the model: the answer; and r15 back on the entry sp */
    {
        int nb = 0;
        struct outcome want = model(sc);
        if (r32(OBJ_BASE + OBJ_ANSWER) != want.answer) {
            fprintf(stderr, "  answer: %08x want %08x\n",
                    r32(OBJ_BASE + OBJ_ANSWER), want.answer);
            nb++;
        }
        if (a.r[15] != OWN_SP) {
            fprintf(stderr, "  r15: native %08x want %08x\n", a.r[15], OWN_SP);
            nb++;
        }
        /* the object's bytes: the pushed word's four bytes, natural or turned */
        uint8_t raw[4];
        raw[0] = (uint8_t)(sc->word0);
        raw[1] = (uint8_t)(sc->word0 >> 8);
        raw[2] = (uint8_t)(sc->word0 >> 16);
        raw[3] = (uint8_t)(sc->word0 >> 24);
        uint8_t b[4];
        if (sc->entry == 1u) {
            b[0] = raw[3]; b[1] = raw[2]; b[2] = raw[1]; b[3] = raw[0];
        } else {
            b[0] = raw[0]; b[1] = raw[1]; b[2] = raw[2]; b[3] = raw[3];
        }
        for (unsigned i = 0; i < 4; ++i) {
            if (r8(OBJ_BASE + OBJ_BYTES + i) != b[i]) {
                fprintf(stderr, "  obj byte %u: %02x want %02x\n", i,
                        r8(OBJ_BASE + OBJ_BYTES + i), b[i]);
                nb++;
            }
        }
        /* the guest's own answer */
        if (gs.v[4] != OBJ_BASE || gs.v[15] != OWN_SP) {
            fprintf(stderr, "  guest r4/r15 diverge\n");
            nb++;
        }
        printf("  outcome: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "natural zero",  0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "natural word",  0u, 0x11223044u, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "just below",    0u, 0x1122303fu, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "natural mark",  0u, 0x000000eeu, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "turned word",   1u, 0x44112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "turned mark",   1u, 0xee112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "turned zero",   1u, 0x11112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        { "limit 255",     0u, 0x112230ffu, 0xcafebabeu, 0x00eeu, 0x00ffu },
        { "negative limit", 0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x8000u },
        { "other entry",   2u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("byte_decode_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
