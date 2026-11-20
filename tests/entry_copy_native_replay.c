/* Differential replay of the native entry copy (src/native/entry_copy.c,
 * 0x8C06D7D6) against the readable guest port (src/fight/entry_copy.c,
 * `vf3_entry_copy_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf looks a sixty-four-byte table
 * entry up by the whole index byte (256 entries) and copies some of its fields
 * into the structure the pool points at, twice: once at each of the two signed
 * halfword offsets the pool holds.  It uses the FR bank for the entry's five
 * floats and keeps **no stack frame**.
 *
 * The pool, the index byte, the table, the structure and the pointer cell sit
 * at the game's own addresses, spanned by one flat buffer.  The whole region
 * is compared byte for byte, together with the registers (r0..r15), the FR
 * bank and the copied fields against an independent fixture-based model.  The
 * scenarios walk the index from the first entry to the last and vary the two
 * offsets (both positive, both negative, and the same). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "entry_copy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_entry_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c06d870u
#define RAM_SIZE 0x1327a0u       /* pool .. pointer cell end */
#define CMP_HI   0x0c1a0010u

/* the windows */
#define POOL_BASE 0x0c06d870u
#define POOL_LEN  0x40u
#define G_FIRST  (POOL_BASE + 0x10u)
#define G_SECOND (POOL_BASE + 0x12u)
#define G_STRUCT (POOL_BASE + 0x20u)
#define G_INDEX  (POOL_BASE + 0x2cu)
#define G_TABLE  (POOL_BASE + 0x38u)
#define INDEX_BASE 0x0c140000u
#define INDEX_LEN  0x08u
#define TABLE_BASE 0x0c150000u
#define ENTRY_SIZE 64u
#define ENTRIES 256u
#define TABLE_LEN  (ENTRIES * ENTRY_SIZE)
#define STRUCT_WIN 0x0c180000u
#define STRUCT_LEN 0x400u
#define STRUCT_AT  0x200u
#define PTR_BASE 0x0c1a0000u
#define PTR_LEN  0x10u
#define NWIN 5

#define FR0 21u   /* v[FR0+n] holds the bits of FRn */

struct scenario {
    const char *name;
    uint8_t index;     /* the index byte */
    int16_t first;     /* the first offset in the structure */
    int16_t second;    /* and the second */
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

/* one entry: three bytes and five floats */
static void entry_seed(unsigned j)
{
    const uint32_t at = TABLE_BASE + j * ENTRY_SIZE;
    ab(at + 5)[0] = (uint8_t)(0x80u + (j & 0x3fu));
    ab(at + 6)[0] = (uint8_t)(0x20u + (j & 0x1fu));
    ab(at + 7)[0] = (uint8_t)j;
    w32(at + 16u, fbits((float)(1.0 + (double)j)));
    w32(at + 24u, fbits((float)(2.0 + (double)j)));
    w32(at + 28u, fbits((float)(3.0 + (double)j)));
    w32(at + 32u, fbits((float)(4.0 + (double)j)));
    w32(at + 36u, fbits((float)(5.0 + (double)j)));
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    w16(G_FIRST, (uint16_t)sc->first);
    w16(G_SECOND, (uint16_t)sc->second);
    w32(G_STRUCT, PTR_BASE);
    w32(G_INDEX, INDEX_BASE);
    w32(G_TABLE, TABLE_BASE);

    ab(INDEX_BASE)[0] = sc->index;

    for (unsigned j = 0; j < ENTRIES; ++j)
        entry_seed(j);

    /* the structure starts full of a pattern */
    memset(ab(STRUCT_WIN), 0x5au, STRUCT_LEN);

    w32(PTR_BASE, STRUCT_WIN + STRUCT_AT);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { INDEX_BASE, INDEX_LEN }, { TABLE_BASE, TABLE_LEN },
        { STRUCT_WIN, STRUCT_LEN }, { PTR_BASE, PTR_LEN },
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

/* The fixture-based model: the structure window has to hold the entry's
 * fields where the guest puts them.  `want` is the full window (index 0 is
 * the window's base 0x0c180000); the structure starts at STRUCT_AT inside it,
 * so a structure-relative offset d is want[STRUCT_AT + d].  The two groups can
 * overlap and the order the guest writes in decides what wins, so the
 * expectation is built by applying the writes in that order. */
static int model_ok(const struct scenario *sc, uint32_t *bad_addr)
{
    const uint32_t tbl = TABLE_BASE + (unsigned)sc->index * ENTRY_SIZE;
    const int a = sc->first;
    const int b = sc->second;

    static uint8_t want[STRUCT_LEN];
    memset(want, 0x5au, sizeof want);

    for (unsigned k = 0; k < 3; ++k)
        want[STRUCT_AT + (int)k + a] = r8(tbl + 5u + k);
    memcpy(want + STRUCT_AT + (a - 20), ab(tbl + 28u), 4);
    memcpy(want + STRUCT_AT + (a - 16), ab(tbl + 32u), 4);
    memcpy(want + STRUCT_AT + (a - 4), ab(tbl + 36u), 4);

    for (unsigned k = 0; k < 3; ++k)
        want[STRUCT_AT + (int)k + b] = r8(tbl + 5u + k);
    memcpy(want + STRUCT_AT + (b - 12), ab(tbl + 24u), 4);
    memcpy(want + STRUCT_AT + (b - 16), ab(tbl + 16u), 4);

    for (uint32_t rel = 0; rel < STRUCT_LEN; ++rel) {
        if (r8(STRUCT_WIN + rel) != want[rel]) {
            *bad_addr = STRUCT_WIN + rel;
            return 0;
        }
    }
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
    const int ok_guest = vf3_entry_copy_entry(&gs, &gmap);
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
    /* the guest seeds every FR with the same running pattern; the leaf only
     * writes FR4/5/6/7/8, so the rest must start at that pattern to match */
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t ub = 0x76543225u + i;
        memcpy(&a.fr[i], &ub, 4);
    }
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_entry_copy(&a);
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

    /* the registers + FR bank + model */
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
        uint32_t ba = 0;
        if (!model_ok(sc, &ba)) {
            fprintf(stderr, "  model: wrong byte at %08x\n", ba);
            nb++;
        }
        printf("  regs+fr+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "first",    0x00u,  0x0060, 0x0040 },
        { "middle",   0x03u,  0x0060, 0x0040 },
        { "high",     0xc8u,  0x0060, 0x0040 },
        { "last",     0xffu,  0x0060, 0x0040 },
        { "negative", 0x07u, -0x0020, -0x0010 },
        { "same",     0x09u,  0x0050, 0x0050 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("entry_copy_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
