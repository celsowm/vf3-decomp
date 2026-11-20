/* Differential replay of the native float table (src/native/float_table.c,
 * 0x8C06D792) against the readable guest port (src/fight/float_table.c,
 * `vf3_float_table_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf looks a sixty-four-byte table
 * entry up by the low **four** bits of the index byte and unpacks it into two
 * structures: the entry's two halfwords (+12/+14, swapped) go into the first
 * structure at +34 and +32, and the entry's three floats (+16/+20/+24) go
 * into the second structure at the signed halfword offset the pool holds, at
 * eight bytes below it and at four below that.  It uses the FR bank and keeps
 * **no stack frame**.
 *
 * The pool, the index byte, the table, the two structures and the pointer cell
 * sit at the game's own addresses, spanned by one flat buffer.  The whole
 * region is compared byte for byte, together with the registers (r0..r15), the
 * FR bank and the unpacked values against an independent fixture-based model.
 * The scenarios walk the index (including the four-bit mask and the unsigned
 * byte) and vary the pool offset (positive, negative and large). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "float_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_float_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c06d870u
#define RAM_SIZE 0x1127a0u       /* pool .. pointer cell end */
#define CMP_HI   0x0c180010u

/* the windows */
#define POOL_BASE 0x0c06d870u
#define POOL_LEN  0x40u
#define G_OFFSET (POOL_BASE + 0x0eu)
#define G_STRUCT (POOL_BASE + 0x20u)
#define G_INDEX  (POOL_BASE + 0x2cu)
#define G_DEST   (POOL_BASE + 0x34u)
#define G_TABLE  (POOL_BASE + 0x38u)
#define INDEX_BASE 0x0c140000u
#define INDEX_LEN  0x08u
#define TABLE_BASE 0x0c150000u
#define BLOCKS 16u
#define BLOCK_SIZE 64u
#define TABLE_LEN  (BLOCKS * BLOCK_SIZE)
#define DEST_BASE 0x0c160000u
#define DEST_LEN  0x40u
#define STRUCT_BASE 0x0c170000u
#define STRUCT_LEN  0x100u
#define STRUCT_AT   0x20u
#define PTR_BASE 0x0c180000u
#define PTR_LEN  0x10u
#define NWIN 6

/* where the entry's two halfwords land in the first structure */
#define HALFWORD_A 32u
#define HALFWORD_B 34u

#define FR0 21u   /* v[FR0+n] holds the bits of FRn */

struct scenario {
    const char *name;
    uint8_t index;      /* the index byte */
    int16_t offset;     /* the pool's offset for the three floats */
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

/* one entry: two halfwords and three floats */
static void block_seed(unsigned j)
{
    const uint32_t at = TABLE_BASE + j * BLOCK_SIZE;
    w16(at + 12u, (uint16_t)(0x1000 + j));
    w16(at + 14u, (uint16_t)(0x2000 + j));
    w32(at + 16u, fbits((float)(1.0 + (double)j)));
    w32(at + 20u, fbits((float)(2.0 + (double)j)));
    w32(at + 24u, fbits((float)(3.0 + (double)j)));
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    w16(G_OFFSET, (uint16_t)sc->offset);
    w32(G_STRUCT, PTR_BASE);
    w32(G_INDEX, INDEX_BASE);
    w32(G_DEST, DEST_BASE);
    w32(G_TABLE, TABLE_BASE);

    ab(INDEX_BASE)[0] = sc->index;

    for (unsigned j = 0; j < BLOCKS; ++j)
        block_seed(j);

    memset(ab(DEST_BASE), 0x5au, DEST_LEN);
    memset(ab(STRUCT_BASE), 0x3cu, STRUCT_LEN);
    w32(PTR_BASE, STRUCT_BASE + STRUCT_AT);
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
        { DEST_BASE, DEST_LEN }, { STRUCT_BASE, STRUCT_LEN }, { PTR_BASE, PTR_LEN },
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

/* The fixture-based model: the first structure's +32/+34 hold the entry's
 * swapped halfwords, and the second structure's bytes around the offset hold
 * the three floats.  `w1` is the first structure window; `w2` the second
 * (index 0 is the window base, the structure starts at STRUCT_AT). */
static int model_ok(const struct scenario *sc, uint32_t *bad_addr)
{
    const uint32_t tbl = TABLE_BASE + (unsigned)(sc->index & 0x0fu) * BLOCK_SIZE;
    const int off = sc->offset;
    const uint32_t s2 = STRUCT_BASE + STRUCT_AT;

    /* the two halfwords, swapped, into the first structure:
     * structure+32 <- entry+12, structure+34 <- entry+14 */
    if (r8(DEST_BASE + HALFWORD_A + 0u) != r8(tbl + 12u) ||
        r8(DEST_BASE + HALFWORD_A + 1u) != r8(tbl + 13u)) { *bad_addr = DEST_BASE + 32u; return 0; }
    if (r8(DEST_BASE + HALFWORD_B + 0u) != r8(tbl + 14u) ||
        r8(DEST_BASE + HALFWORD_B + 1u) != r8(tbl + 15u)) { *bad_addr = DEST_BASE + 34u; return 0; }

    /* the three floats into the second structure */
    if (r32(s2 + (uint32_t)(off)) != r32(tbl + 16u)) { *bad_addr = s2 + off; return 0; }
    if (r32(s2 + (uint32_t)(off - 8)) != r32(tbl + 20u)) { *bad_addr = s2 + off - 8; return 0; }
    if (r32(s2 + (uint32_t)(off - 4)) != r32(tbl + 24u)) { *bad_addr = s2 + off - 4; return 0; }
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
    const int ok_guest = vf3_float_table_entry(&gs, &gmap);
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
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_float_table(&a);
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
        { "first",    0x00u,  0x0020 },
        { "last",     0x0fu,  0x0020 },
        { "masked",   0xf3u,  0x0020 },
        { "unsigned", 0x93u,  0x0020 },
        { "negative", 0x05u, -0x0010 },
        { "large",    0x07u,  0x0060 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("float_table_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
