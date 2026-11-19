/* Differential replay of the native HUD sprite-pool port
 * (src/native/glyph_cache.c, 0x8C0C1FBA) against the readable guest port
 * (src/fight/glyph_cache.c, `vf3_glyph_cache_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (its five
 * inlined callees - the retirement self-call, pool_alloc, tex_cell_load,
 * sprite_rect_a/b - go through vf3_guest_call), the native through
 * `ram_base`.  The fixture lays out the layer object, its 120-entry pool, the
 * two cell tables, the screen scale/offset constants, the tint table and the
 * sprite-cell table, seeds the entry registers and the two caller stack words
 * (packed texel offsets, flag bits), and runs the two sides from the same
 * seed.
 *
 * The pool entries (their u16 fields and the float sprite object), the
 * cell-load scratch block, the layer and the saved/stack region are compared
 * byte for byte - the floats are produced by the same toward-zero + FTZ
 * arithmetic on both sides - together with the contract registers (r0 as the
 * result, r8..r14, r15, pr, SR's T bit and fr12..fr15). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "glyph_cache.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_glyph_cache_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x2C0000u

#define LAYER     0x0C203000u
#define POOL      0x0C204000u
#define SP0       0x0C210000u

#define SCRATCH   0x0C1B9620u
#define CELL_RECORDS 0x0C11ABB0u
#define CELL_PAIRS   0x0C11AA60u
#define SCALE_X   0x0C10B7FCu
#define SCALE_Y   0x0C10B800u
#define OFFSET_X  0x0C10B804u
#define OFFSET_Y  0x0C10B808u
#define TINT_TABLE 0x0C10FEB4u
#define SPRITE_CELLS 0x0C2A620Cu

#define POOL_ENTRIES 120u
#define ENTRY_BYTES  68u

#define POOL_LO POOL
#define POOL_HI (POOL + POOL_ENTRIES * ENTRY_BYTES)
#define SCRATCH_LO SCRATCH
#define SCRATCH_HI (SCRATCH + 0x28u)
#define LAYER_LO LAYER
#define LAYER_HI (LAYER + 0x50u)
#define STACK_LO (SP0 - 76u)
#define STACK_HI (SP0 + 16u)

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v)
{ uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static void w16(uint32_t addr, uint16_t v)
{ uint8_t *p = ab(addr); p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

/* seed the whole pool: every entry busy except the one at `free_slot`, so the
 * cursor-take path selects `free_slot`. */
static void seed_pool_busy(uint32_t free_slot)
{
    for (uint32_t i = 0; i < POOL_ENTRIES; ++i)
        w16(POOL + i * ENTRY_BYTES, i == free_slot ? 0u : 0x0005u);
}

/* seed a "previous glyph" at pool slot `slot` with the given col/row/key so
 * the retirement loop (self-call) clears it. */
static void seed_prior(uint32_t slot, uint16_t col8, uint16_t row8, uint16_t key)
{
    uint32_t e = POOL + slot * ENTRY_BYTES;
    w16(e + 0u, 0x0007u);          /* live+flags: busy */
    w16(e + 2u, key);
    w16(e + 6u, col8);
    w16(e + 8u, row8);
}

static void seed_env_defaults(void)
{
    /* layer: pool ptr, tint index 0, cursor 0 */
    w32(LAYER + 12u, POOL);
    w16(LAYER + 38u, 0u);
    w16(LAYER + 42u, 0u);
    /* screen constants */
    wf(SCALE_X, 2.0f);   wf(SCALE_Y, 3.0f);
    wf(OFFSET_X, 10.0f); wf(OFFSET_Y, 20.0f);
    /* tint table -> layer tint 0 */
    wf(TINT_TABLE + 0u, 0.5f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t *regs, uint32_t pr, uint32_t sr,
                        const float *frseed)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[15] = SP0;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;                 /* fpscr: round-toward-zero, PR single */
    for (int i = 0; i < 4; ++i) {
        uint32_t bits; memcpy(&bits, &frseed[i], 4);
        s->v[21 + 12 + i] = bits;           /* FR12..FR15 */
    }
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

/* compare one exact 32-bit-aligned region */
struct fixture {
    const char *label;
    uint32_t key;          /* r5 */
    uint32_t packed_cell;  /* r7 */
    uint32_t offsets;      /* [sp0] */
    uint32_t flags;        /* [sp0+4] */
    uint32_t cursor_word;  /* r4 */
    int      have_prior;   /* seed a match to retire */
    int      full_pool;    /* make every entry busy -> pool_alloc returns 0 */
    uint32_t spare_key;    /* the cell-pair id (<= 0x3FFF) used when key is a record id */
};

static int run_case(const struct fixture *fx)
{
    printf("== %s\n", fx->label);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x11110000u + (uint32_t)i * 0x1111u;
    regs[4] = fx->cursor_word;              /* r4 = cursor word */
    regs[5] = fx->key;                      /* r5 = key */
    regs[6] = LAYER;                        /* r6 = layer */
    regs[7] = fx->packed_cell;              /* r7 = packed cell */
    regs[15] = SP0;
    const uint32_t pr = 0x0C0CDE2Fu;
    const uint32_t sr = 0x60000001u;        /* T set */
    const float frseed[4] = { 13.0f, 14.0f, 15.0f, 16.0f };

    const uint16_t col8 = (uint16_t)((fx->cursor_word >> 1) & 63u);
    const uint16_t row8 = (uint16_t)((fx->cursor_word >> 7) & 63u);
    const int is_retire = (fx->key & 0x8000u) != 0;
    const uint16_t plain_key = (uint16_t)(fx->key & 0xFFFFu);

    /* ---- guest side ---- */
    memset(ram, 0, RAM_SIZE);
    seed_env_defaults();
    if (fx->full_pool) {
        for (uint32_t i = 0; i < POOL_ENTRIES; ++i)
            w16(POOL + i * ENTRY_BYTES, 0x0005u);
    } else {
        seed_pool_busy(0u);                 /* pool[0] free -> entry = POOL */
        if (fx->have_prior)
            seed_prior(5u, col8, row8, plain_key);
    }
    /* cell tables */
    {
        const uint32_t pid = fx->spare_key & 0x3FFFu;
        w16(CELL_PAIRS + 4u * pid + 0u, 16u);   /* pw = 16 -> 128 texels */
        w16(CELL_PAIRS + 4u * pid + 2u, 8u);    /* ph = 8  -> 64  texels */
        w16(SPRITE_CELLS + 2u * pid, 0x1234u);
        if (fx->key & 0x4000u) {
            const uint32_t rec = CELL_RECORDS + 6u * (fx->key & 0x3FFFu);
            w16(rec + 0u, (uint16_t)pid);       /* first */
            ab(rec + 2u)[0] = 2u;               /* x */
            ab(rec + 3u)[0] = 3u;               /* y */
            ab(rec + 4u)[0] = 4u;               /* w */
            ab(rec + 5u)[0] = 5u;               /* h */
        } else {
            w16(CELL_PAIRS + 4u * (fx->key & 0xFFFFu) + 0u, 16u);
            w16(CELL_PAIRS + 4u * (fx->key & 0xFFFFu) + 2u, 8u);
            w16(SPRITE_CELLS + 2u * (fx->key & 0xFFFFu), 0x1234u);
        }
    }
    /* the two caller stack words */
    w32(SP0 + 0u, fx->offsets);
    w32(SP0 + 4u, fx->flags);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, pr, sr, frseed);
    vf3_family_override = vf3_readable_override;   /* route the 5 callees to the readable ports */
    const int ok_guest = vf3_glyph_cache_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *guest = (uint8_t *)malloc((POOL_HI - POOL_LO) + (SCRATCH_HI - SCRATCH_LO) +
                                       (LAYER_HI - LAYER_LO) + (STACK_HI - STACK_LO));
    size_t off = 0;
    memcpy(guest + off, ab(POOL_LO), POOL_HI - POOL_LO); off += POOL_HI - POOL_LO;
    memcpy(guest + off, ab(SCRATCH_LO), SCRATCH_HI - SCRATCH_LO); off += SCRATCH_HI - SCRATCH_LO;
    memcpy(guest + off, ab(LAYER_LO), LAYER_HI - LAYER_LO); off += LAYER_HI - LAYER_LO;
    memcpy(guest + off, ab(STACK_LO), STACK_HI - STACK_LO);

    /* ---- native side ---- */
    memset(ram, 0, RAM_SIZE);
    seed_env_defaults();
    if (fx->full_pool) {
        for (uint32_t i = 0; i < POOL_ENTRIES; ++i)
            w16(POOL + i * ENTRY_BYTES, 0x0005u);
    } else {
        seed_pool_busy(0u);
        if (fx->have_prior)
            seed_prior(5u, col8, row8, plain_key);
    }
    {
        const uint32_t pid = fx->spare_key & 0x3FFFu;
        w16(CELL_PAIRS + 4u * pid + 0u, 16u);
        w16(CELL_PAIRS + 4u * pid + 2u, 8u);
        w16(SPRITE_CELLS + 2u * pid, 0x1234u);
        if (fx->key & 0x4000u) {
            const uint32_t rec = CELL_RECORDS + 6u * (fx->key & 0x3FFFu);
            w16(rec + 0u, (uint16_t)pid);
            ab(rec + 2u)[0] = 2u; ab(rec + 3u)[0] = 3u;
            ab(rec + 4u)[0] = 4u; ab(rec + 5u)[0] = 5u;
        } else {
            w16(CELL_PAIRS + 4u * (fx->key & 0xFFFFu) + 0u, 16u);
            w16(CELL_PAIRS + 4u * (fx->key & 0xFFFFu) + 2u, 8u);
            w16(SPRITE_CELLS + 2u * (fx->key & 0xFFFFu), 0x1234u);
        }
    }
    w32(SP0 + 0u, fx->offsets);
    w32(SP0 + 4u, fx->flags);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    for (int i = 0; i < 4; ++i) a.fr[12 + i] = frseed[i];
    vf3_native_glyph_cache(&a, SP0);

    int bad = 0;

    /* ---- range 1: pool ---- */
    {
        int nb = 0;
        for (uint32_t ad = POOL_LO; ad < POOL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (ad - POOL_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  pool @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  pool: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    /* ---- range 2: scratch ---- */
    {
        int nb = 0;
        size_t base = POOL_HI - POOL_LO;
        for (uint32_t ad = SCRATCH_LO; ad < SCRATCH_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + base + (ad - SCRATCH_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  scratch @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  scratch: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    /* ---- range 3: layer ---- */
    {
        int nb = 0;
        size_t base = (POOL_HI - POOL_LO) + (SCRATCH_HI - SCRATCH_LO);
        for (uint32_t ad = LAYER_LO; ad < LAYER_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + base + (ad - LAYER_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  layer @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  layer: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    /* ---- range 4: stack ---- */
    {
        int nb = 0;
        size_t base = (POOL_HI - POOL_LO) + (SCRATCH_HI - SCRATCH_LO) + (LAYER_HI - LAYER_LO);
        for (uint32_t ad = STACK_LO; ad < STACK_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + base + (ad - STACK_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 20) fprintf(stderr, "  stack @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  stack: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* ---- contract registers ---- */
    {
        int nb = 0;
        if (a.r[0] != gs.v[0]) {
            fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); nb++;
        }
        for (int i = 8; i <= 14; ++i)
            if (a.r[i] != gs.v[i]) {
                if (nb < 30) fprintf(stderr, "  r%d: native %08x guest %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.r[15] != gs.v[15]) {
            fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]); nb++;
        }
        if (a.pr != gs.v[16]) {
            fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]); nb++;
        }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); nb++;
        }
        for (int i = 12; i <= 15; ++i) {
            uint32_t gb, nb2;
            memcpy(&gb, &a.fr[i], 4);
            memcpy(&nb2, &gs.v[21 + i], 4);
            if (gb != nb2) {
                if (nb < 30) fprintf(stderr, "  fr%d: native %08x guest %08x\n", i, gb, nb2);
                nb++;
            }
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(guest);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("glyph_cache_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct fixture all[] = {
        /* retire mode: key 0x8001 clears the prior glyph at cell, r0 = 0 */
        { "retire path", 0x8001u, 0u, 0u, 0u, 0x00000206u, 1, 0, 0x0042u },
        /* normal pair-id allocate, packed cell set, no texel offsets */
        { "allocate pair-id", 0x0042u, 0x00320010u, 0u, 0u, 0x00000206u, 1, 0, 0x0042u },
        /* record-id key with texel offsets and flag bits (lit + blend) */
        { "allocate record offsets", 0x4005u, 0x00000000u, 0x01020304u, 9u, 0x00000206u, 1, 0, 0x0007u },
        /* flag bit combos */
        { "allocate flags", 0x0042u, 0x00320010u, 0u, 0x2Fu, 0x00000206u, 0, 0, 0x0042u },
        /* pool full -> pool_alloc returns 0 */
        { "full pool", 0x0042u, 0x00320010u, 0u, 0u, 0x00000206u, 0, 1, 0x0042u },
    };

    int bad = 0;
    for (size_t i = 0; i < sizeof all / sizeof all[0]; ++i)
        bad |= run_case(&all[i]);

    free(ram);
    printf("glyph_cache_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
