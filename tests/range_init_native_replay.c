/* Differential replay of the native structure init (src/native/range_init.c,
 * 0x8C036A58) against the readable guest port (src/fight/range_init.c,
 * `vf3_range_init_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf sets up a forty-four byte
 * structure at r4: mostly zeroed, but four words in the middle (at +8/+12/+16/
 * +20) carry a range whose shape depends on the first word of whatever the pool
 * (0x0c036af0) points at - `0, -1, 0, 0` when that word is zero, `-1, 0, -1,
 * -1` when it is not.  The word at the structure's +36 comes from the pool
 * (0x0c036b0c).  The leaf keeps **no stack frame**.
 *
 * The literal pool, the flag word and the structure sit at the game's own
 * addresses, spanned by one flat buffer.  The whole region is compared byte for
 * byte, together with the registers (r0..r15), the T bit and the structure
 * against an independent model written in the test (the structure started full
 * of a pattern, so a byte the leaf does not write shows up).  The scenarios
 * walk the flag through zero and non-zero shapes. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "range_init.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_range_init_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c036ae0u
#define RAM_SIZE 0x119560u      /* spans the pool .. the structure end (0x0c150040) */
#define CMP_HI   0x0c150040u

/* the windows */
#define POOL_BASE 0x0c036ae0u
#define POOL_LEN  0x40u
#define FLAG_BASE 0x0c140000u
#define FLAG_LEN  0x10u
#define STRUCT_BASE 0x0c150000u
#define STRUCT_LEN  0x40u
#define NWIN 3

#define G_FLAG (POOL_BASE + 0x10u)
#define G_TAIL (POOL_BASE + 0x2cu)
#define TAIL_WORD 0x0badf00du

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

struct scenario {
    const char *name;
    uint32_t flag;
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool */
    w32(G_FLAG, FLAG_BASE);
    w32(G_TAIL, TAIL_WORD);

    /* the word the pool points at */
    w32(FLAG_BASE, sc->flag);

    /* the structure starts full of a pattern, so the bytes the leaf does not
     * write are visible */
    memset(ab(STRUCT_BASE), 0x7e, STRUCT_LEN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = STRUCT_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { FLAG_BASE, FLAG_LEN }, { STRUCT_BASE, STRUCT_LEN },
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

/* the structure the fixture says the leaf has to leave behind, read straight
 * off the fixture (the structure started full of 0x7e, so the bytes past the
 * end keep the pattern) */
static int model_ok(const struct scenario *sc, uint32_t *bad_word, uint32_t *bad_addr)
{
    const int empty = (sc->flag == 0u);

    /* the first two words are zero */
    for (unsigned off = 0u; off < 8u; off += 4u) {
        if (r32(STRUCT_BASE + off) != 0u) { *bad_word = r32(STRUCT_BASE + off); *bad_addr = STRUCT_BASE + off; return 0; }
    }
    /* the range's four words */
    {
        static const uint32_t Z[4] = { 0u, 0xffffffffu, 0u, 0u };
        static const uint32_t NZ[4] = { 0xffffffffu, 0u, 0xffffffffu, 0xffffffffu };
        const uint32_t *want = empty ? Z : NZ;
        for (unsigned i = 0; i < 4; ++i) {
            uint32_t off = 8u + 4u * i;
            if (r32(STRUCT_BASE + off) != want[i]) { *bad_word = r32(STRUCT_BASE + off); *bad_addr = STRUCT_BASE + off; return 0; }
        }
    }
    /* the four halfwords are zero */
    for (unsigned off = 24u; off < 36u; off += 2u) {
        if (r16(STRUCT_BASE + off) != 0u) { *bad_word = r16(STRUCT_BASE + off); *bad_addr = STRUCT_BASE + off; return 0; }
    }
    /* and the two words at the end */
    if (r32(STRUCT_BASE + 36u) != TAIL_WORD) { *bad_word = r32(STRUCT_BASE + 36u); *bad_addr = STRUCT_BASE + 36u; return 0; }
    if (r32(STRUCT_BASE + 40u) != 0u) { *bad_word = r32(STRUCT_BASE + 40u); *bad_addr = STRUCT_BASE + 40u; return 0; }
    return 1;
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
    const int ok_guest = vf3_range_init_entry(&gs, &gmap);
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
    a.r[4] = STRUCT_BASE;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_range_init(&a);
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

    /* the registers + T bit + the model */
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
        /* the T bit is the one of the branch the guest took */
        int expect_t = (sc->flag == 0u);
        if (((a.sr & 1u) != 0) != expect_t) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, expect_t);
            nb++;
        }
        uint32_t bw = 0, ba = 0;
        if (!model_ok(sc, &bw, &ba)) {
            fprintf(stderr, "  model: word %08x at %08x wrong\n", bw, ba);
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
        { "zero",     0x00000000u },
        { "set",      0x00000001u },
        { "negative", 0xffffffffu },
        { "large",    0x0000ffffu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("range_init_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
