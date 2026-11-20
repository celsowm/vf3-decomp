/* Differential replay of the native table grower (src/native/table_grow.c,
 * 0x8C044C7C) against the readable guest port (src/fight/table_grow.c,
 * `vf3_table_grow_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf calls nobody, uses no FPU and
 * keeps no stack frame: it adds N entries (r4) to two arrays behind one header
 * that hangs off a global (the global holds the header's address, the header's
 * first word the base).  The literal pool holds the first array's slot, the
 * fill value and the second array's slot as halfwords.
 *
 * The whole region - the pool, the header pointer, the base and the arrays -
 * sits at the game's own addresses, spanned by one flat buffer.  The whole
 * region is compared byte for byte, together with the registers (r0..r7), the
 * T bit and the answer.  The scenarios cover a zero count (the loop does not
 * run), one entry, several entries and a negative count (the loop does not run
 * either, but the second array's count and pointer still move). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "table_grow.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_table_grow_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c044d10u
#define RAM_SIZE 0x4bb3f0u     /* spans the pool .. arr (0x0c500000+0x100) */
#define CMP_HI   0x0c500100u

/* the windows */
#define POOL_BASE  0x0c044d10u
#define POOL_LEN   0x40u
#define PTR_BASE   0x0c400000u
#define PTR_LEN    0x10u
#define BASE       0x0c410000u
#define BASE_LEN   0x40u
#define ARR_BASE   0x0c500000u
#define ARR_LEN    0x100u

#define G_SLOT0  (POOL_BASE + 0x06u)
#define G_FILL   (POOL_BASE + 0x08u)
#define G_SLOT1  (POOL_BASE + 0x0au)
#define G_HEADER (POOL_BASE + 0x34u)

#define SLOT0  0x10u
#define SLOT1  0x20u
#define STRIDE 2u

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
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t count;    /* r4 */
};

static void seed_all(void)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool */
    w16(G_SLOT0, SLOT0);
    w16(G_FILL, 0x1234u);
    w16(G_SLOT1, SLOT1);
    w32(G_HEADER, PTR_BASE);

    /* the word the global points at holds the base */
    w32(PTR_BASE, BASE);

    /* the base: the first array's slot and its stride, then the second
     * array's count and its pointer */
    w32(BASE + SLOT0, ARR_BASE);
    w32(BASE + SLOT0 + 12u, STRIDE);
    w32(BASE + SLOT1, 5u);
    w32(BASE + SLOT1 + 4u, ARR_BASE + 0x80u);

    /* the arrays: garbage so overwrites are visible */
    memset(ab(ARR_BASE), 0x99, ARR_LEN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t count)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = count;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[4] = {
        { POOL_BASE, POOL_LEN }, { PTR_BASE, PTR_LEN }, { BASE, BASE_LEN },
        { ARR_BASE, ARR_LEN },
    };
    for (unsigned i = 0; i < 4; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = 4;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all();
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[4];
    setup_guest(&gs, &gmap, gwin, sc->count);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_table_grow_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
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
    a.r[4] = sc->count;
    a.r[15] = 0x0c108000u;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_table_grow(&a);
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

    /* registers + T bit + answer */
    {
        int nb = 0;
        if (a.r[0] != 0u) { fprintf(stderr, "  r0: native %08x want 0\n", a.r[0]); nb++; }
        /* r4 was shifted left by two for the second-array pointer move */
        uint32_t want_r4 = sc->count << 2;
        if (a.r[4] != want_r4) { fprintf(stderr, "  r4: native %08x want %08x\n", a.r[4], want_r4); nb++; }
        /* the T bit: set on a non-zero count in the loop, else the sign test.
         * For count<=0, the sign test sets T only when count>0, so it is
         * clear; for count>0 the loop leaves T set (r6>=count on the last
         * iteration).  A negative count leaves T clear. */
        int want_t = ((int32_t)sc->count > 0) ? 1 : 0;
        if (((a.sr & 1u) != 0) != want_t) {
            fprintf(stderr, "  sr T: native %u want %d\n", a.sr & 1u, want_t);
            nb++;
        }
        /* guest's own registers */
        if (gs.v[0] != 0u || gs.v[4] != want_r4 ||
            ((gs.v[17] & 1u) != 0) != want_t) {
            fprintf(stderr, "  guest regs diverge\n");
            nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "zero",     0u },
        { "one",      1u },
        { "three",    3u },
        { "eight",    8u },
        { "negative", 0xffffffffu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("table_grow_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
