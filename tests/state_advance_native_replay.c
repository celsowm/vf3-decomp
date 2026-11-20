/* Differential replay of the native state advance (src/native/state_advance.c,
 * 0x8C06BEA4) against the readable guest port (src/fight/state_advance.c,
 * `vf3_state_advance_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf steps an entry counter (the
 * word at *r4, low four bits) forward and wraps at sixteen, counts a lap down
 * (the word at *r5), and tells a byte of kind flags (the pool at 0x0c06bfbc
 * points at it) what the table says about the current entry.  It keeps a frame:
 * it saves r12/r13/r14 at sp-4/-8/-12 and restores them (r14 in the delay slot
 * of the return), so r15 returns to the entry sp.
 *
 * The literal pool, the table, the flags byte, the two words the guest is
 * handed and the stack sit at the game's own addresses, spanned by one flat
 * buffer.  The whole region is compared byte for byte, together with the
 * registers (r0..r15), the T bit, the stack frame words and the answer
 * (counter, count, flags byte) against an independent model written in the
 * test.  The scenarios are the readable test's, covering both kinds, the table
 * knowing or not, the flags holding bits, the counter at zero (count runs
 * down), the wrap at sixteen, bits above the four, and signed flags/masks. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "state_advance.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_state_advance_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c06bf80u
#define RAM_SIZE 0x9c0c0u       /* spans the pool .. the stack end (0x0c108040) */
#define CMP_HI   0x0c108040u

/* the windows */
#define POOL_BASE 0x0c06bf80u
#define POOL_LEN  0x60u
#define TABLE_BASE 0x0c0d0000u
#define TABLE_LEN  0x20u
#define FLAGS_BASE 0x0c0e0000u
#define FLAGS_LEN  0x10u
#define SLOTS_BASE 0x0c0f0000u
#define SLOTS_LEN  0x10u
#define STACK_TOP  0x0c108000u
#define STACK_WIN_BASE (STACK_TOP - 16u)
#define STACK_LEN  0x40u
#define NWIN 5

#define MASK_A    (POOL_BASE + 0x2cu)
#define MASK_B    (POOL_BASE + 0x2eu)
#define FLAGS_PTR (POOL_BASE + 0x3cu)
#define TABLE_PTR (POOL_BASE + 0x40u)

struct scenario {
    const char *name;
    uint32_t slot_idx;
    uint32_t slot_count;
    uint32_t r6;
    uint8_t table_at;
    uint8_t table_byte;
    int16_t mask_a;
    int16_t mask_b;
    uint8_t flags;
};

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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool */
    w16(MASK_A, (uint16_t)sc->mask_a);
    w16(MASK_B, (uint16_t)sc->mask_b);
    w32(FLAGS_PTR, FLAGS_BASE);
    w32(TABLE_PTR, TABLE_BASE);

    /* the table: one byte, and zeroes everywhere else */
    if (sc->table_at < 16u) ab(TABLE_BASE)[sc->table_at] = sc->table_byte;

    /* the flags byte */
    ab(FLAGS_BASE)[0] = sc->flags;

    /* the two words the guest is handed */
    w32(SLOTS_BASE, sc->slot_idx);
    w32(SLOTS_BASE + 4u, sc->slot_count);

    /* the stack: garbage so the writes are visible */
    memset(ab(STACK_WIN_BASE), 0x5a, STACK_LEN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = SLOTS_BASE;
    s->v[5] = SLOTS_BASE + 4u;
    s->v[6] = 0u;                 /* reset per scenario below */
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { TABLE_BASE, TABLE_LEN },
        { FLAGS_BASE, FLAGS_LEN }, { SLOTS_BASE, SLOTS_LEN },
        { STACK_WIN_BASE, STACK_LEN },
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

/* the independent model of the counter, the count, the flags and the T bit,
 * worked out from the fixture alone */
static void model(const struct scenario *sc, uint32_t *new_idx, uint32_t *new_count,
                  uint8_t *new_flags, int *t_bit)
{
    const uint32_t idx = sc->slot_idx & 15u;

    if (idx == 0) {
        *new_flags = sc->flags;
        if (sc->slot_count == 0) {
            *new_idx = 0; *new_count = 0; *t_bit = 1;
        } else {
            *new_idx = 1; *new_count = sc->slot_count - 1u; *t_bit = 0;
        }
        return;
    }

    const uint8_t v = (sc->table_at == idx) ? sc->table_byte : 0u;
    const int first = (sc->r6 == 0);
    uint32_t flags = (uint32_t)(int32_t)(int8_t)sc->flags;
    flags &= (uint32_t)(int32_t)(first ? sc->mask_a : sc->mask_b);
    if (v != 0) flags |= (first ? 1u : 2u);

    *new_flags = (uint8_t)flags;
    *new_idx = (idx + 1u) & 15u;
    *new_count = sc->slot_count;
    *t_bit = (v == 0) ? 1 : 0;
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
    gs.v[6] = sc->r6;
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_state_advance_entry(&gs, &gmap);
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
    a.r[4] = SLOTS_BASE;
    a.r[5] = SLOTS_BASE + 4u;
    a.r[6] = sc->r6;
    a.r[15] = STACK_TOP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_state_advance(&a);
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

    /* the registers + T bit + answer */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 14 || i == 15) continue;   /* checked below */
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        /* r15 back on the entry sp */
        if (a.r[15] != STACK_TOP) {
            fprintf(stderr, "  r15: native %08x want %08x\n", a.r[15], STACK_TOP);
            nb++;
        }
        /* r14 restored to its caller value */
        if (a.r[14] != gs.v[14]) {
            fprintf(stderr, "  r14: native %08x want %08x\n", a.r[14], gs.v[14]);
            nb++;
        }
        /* the T bit */
        if (((a.sr & 1u) != 0) != ((gs.v[17] & 1u) != 0)) {
            fprintf(stderr, "  sr T: native %u want %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }

        /* the model */
        uint32_t new_idx = 0, new_count = 0;
        uint8_t new_flags = 0;
        int t_bit = 0;
        model(sc, &new_idx, &new_count, &new_flags, &t_bit);
        if (r32(SLOTS_BASE) != new_idx) {
            fprintf(stderr, "  counter: %08x want %08x\n", r32(SLOTS_BASE), new_idx);
            nb++;
        }
        if (r32(SLOTS_BASE + 4u) != new_count) {
            fprintf(stderr, "  count: %08x want %08x\n", r32(SLOTS_BASE + 4u), new_count);
            nb++;
        }
        if (r8(FLAGS_BASE) != new_flags) {
            fprintf(stderr, "  flags: %02x want %02x\n", r8(FLAGS_BASE), new_flags);
            nb++;
        }
        if (((a.sr & 1u) != 0) != t_bit) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, t_bit);
            nb++;
        }
        /* the three words the guest pushed */
        if (r32(STACK_TOP - 12u) != 0x76543210u + 12u ||
            r32(STACK_TOP - 8u) != 0x76543210u + 13u ||
            r32(STACK_TOP - 4u) != 0x76543210u + 14u) {
            fprintf(stderr, "  pushed words %08x/%08x/%08x\n",
                    r32(STACK_TOP - 12u), r32(STACK_TOP - 8u), r32(STACK_TOP - 4u));
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
        { "the first kind", 1u, 5u, 0u, 1u, 1u, (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the second kind", 1u, 5u, 1u, 1u, 1u, (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the sixth register is not one", 1u, 5u, 0x80000000u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the table says nothing", 1u, 5u, 0u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the table says nothing, the second kind", 1u, 5u, 1u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the other kind's bit is there", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 2u },
        { "the other kind's bit is there, the second kind", 1u, 5u, 1u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        { "the kind's bit is taken away", 1u, 5u, 0u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        { "the second kind's mask keeps the first bit", 1u, 5u, 1u, 1u, 2u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        { "the counter is at zero, the count is spent", 0u, 0u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the counter is at zero, the count is left", 0u, 3u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the count is one", 0u, 1u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the count is the biggest", 0u, 0xffffffffu, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the counter wraps", 15u, 5u, 0u, 15u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter wraps and the table knows nothing", 15u, 5u, 0u, 15u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter has bits above the four", 0x21u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter has four bits above the four", 0x1au, 5u, 0u, 10u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter is zero with bits above the four", 0x30u, 3u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the flags byte is negative", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x80u },
        { "the flags byte is all ones", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0x7fff, (int16_t)0x7fff, 0xffu },
        { "the mask is a negative halfword", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0x8000, (int16_t)0x8000, 0xffu },
        { "the mask keeps everything", 1u, 5u, 1u, 1u, 1u,
          (int16_t)0x7fff, (int16_t)0x7fff, 0x03u },
        { "the middle of the table", 7u, 2u, 0u, 7u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("state_advance_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
