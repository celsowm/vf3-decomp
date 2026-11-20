/* Differential replay of the native state flag (src/native/state_flag.c,
 * 0x8C0B0FD2) against the readable guest port (src/fight/state_flag.c,
 * `vf3_state_flag_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed the state word
 * (r7), the structure with the value (r5), the offset the value is measured
 * from (r6) and the structure with the two parity words (r4).  It sets one of
 * two bits in the state word - or nothing - depending on the band the signed
 * value falls into and one parity bit.  It keeps **no stack frame**, reads the
 * literal pool and uses the guest's `shad`.
 *
 * The pool, the two structures and the state word sit at the game's own
 * addresses, spanned by one flat buffer.  The whole region is compared byte
 * for byte, together with the registers (r0..r15) and the T bit, and the
 * outcome (the registers the guest leaves, the T bit and the state word
 * afterwards) against an independent model written in the test.  The scenarios
 * cover the gate, the value between the bands, above the high band, below the
 * middle band, inside both bands with both parity answers - and the corpus'
 * own case. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "state_flag.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_state_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c0b1000u
#define RAM_SIZE 0x26f000u       /* pool .. state end */
#define CMP_HI   0x0c320000u

/* the windows */
#define POOL_BASE   0x0c0b1000u
#define POOL_LEN    0x1000u
#define STRUCT_BASE 0x0c200000u
#define STRUCT_LEN  0x4000u
#define STATE_BASE  0x0c31f000u
#define STATE_LEN   0x1000u
#define NWIN 3

#define VALUE_STRUCT  (STRUCT_BASE + 0x100u)  /* r5: the structure with the value */
#define PARITY_STRUCT (STRUCT_BASE + 0x200u)  /* r4: the structure with the two words */
#define STATE_WORD    (STATE_BASE + 0x9d0u)    /* r7: the state word */

#define P_TABLE    (POOL_BASE + 0x70u)
#define P_LOW      (POOL_BASE + 0x72u)
#define P_MID      (POOL_BASE + 0x74u)
#define P_BIT_LOW  (POOL_BASE + 0x76u)
#define P_HIGH     (POOL_BASE + 0x78u)
#define P_HIGH2    (POOL_BASE + 0x7au)
#define P_BIT_HIGH (POOL_BASE + 0x7cu)
#define P_MASK     (POOL_BASE + 0x94u)
#define P_XOR      (POOL_BASE + 0x98u)

#define WORD_OFFSET 72u
#define COUNT_FIRST 0xffffffe7u
#define COUNT_SECOND 0xfffffff6u

#define CALLER_R0 0x76543210u
#define CALLER_R1 0x76543211u

struct scenario {
    const char *name;
    uint16_t table_off;
    int16_t  low;
    int16_t  mid;
    uint16_t bit_low;
    int16_t  high;
    int16_t  high2;
    uint16_t bit_high;
    uint32_t mask;
    uint32_t xor_const;
    uint32_t state;        /* the word at r7 */
    uint32_t offset;       /* r6 */
    uint16_t entry;        /* the halfword the value comes from */
    uint32_t word0;        /* the first parity word */
    uint32_t word1;        /* the second parity word */
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

    w16(P_TABLE, sc->table_off);
    w16(P_LOW, (uint16_t)sc->low);
    w16(P_MID, (uint16_t)sc->mid);
    w16(P_BIT_LOW, sc->bit_low);
    w16(P_HIGH, (uint16_t)sc->high);
    w16(P_HIGH2, (uint16_t)sc->high2);
    w16(P_BIT_HIGH, sc->bit_high);
    w32(P_MASK, sc->mask);
    w32(P_XOR, sc->xor_const);

    memset(ab(STRUCT_BASE), 0x5c, STRUCT_LEN);
    w16(VALUE_STRUCT + (uint32_t)sc->table_off, sc->entry);
    w32(PARITY_STRUCT, sc->word0);
    w32(PARITY_STRUCT + WORD_OFFSET, sc->word1);

    w32(STATE_WORD, sc->state);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = PARITY_STRUCT;
    s->v[5] = VALUE_STRUCT;
    s->v[6] = sc->offset;
    s->v[7] = STATE_WORD;
    s->v[15] = STATE_BASE + 0xff0u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x60000000u;             /* sr, T bit clear */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { STRUCT_BASE, STRUCT_LEN }, { STATE_BASE, STATE_LEN },
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

/* the fixture-based model of the guest's outcome: the registers it leaves, the
 * T bit and the state word afterwards.  Written from the disassembly, reading
 * the fixture's own bytes. */
struct outcome {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    int t;
    uint32_t word;
};

static int32_t sext16(uint32_t value)
{
    return (int32_t)(int16_t)(uint16_t)value;
}

static uint32_t asr(uint32_t value, unsigned bits)
{
    if (bits == 0u) return value;
    if (value & 0x80000000u) return (value >> bits) | ~(0xffffffffu >> bits);
    return value >> bits;
}

static void model(const struct scenario *sc, struct outcome *out)
{
    const uint32_t mask = r32(P_MASK);
    const uint32_t xor_const = r32(P_XOR);
    const int32_t low = sext16(r8(P_LOW) | ((uint32_t)r8(P_LOW + 1) << 8));
    const int32_t mid = sext16(r8(P_MID) | ((uint32_t)r8(P_MID + 1) << 8));
    const int32_t high = sext16(r8(P_HIGH) | ((uint32_t)r8(P_HIGH + 1) << 8));
    const int32_t high2 = sext16(r8(P_HIGH2) | ((uint32_t)r8(P_HIGH2 + 1) << 8));
    const uint32_t bit_low = r8(P_BIT_LOW) | ((uint32_t)r8(P_BIT_LOW + 1) << 8);
    const uint32_t bit_high = r8(P_BIT_HIGH) | ((uint32_t)r8(P_BIT_HIGH + 1) << 8);
    const uint32_t table = (uint32_t)sext16(r8(P_TABLE) | ((uint32_t)r8(P_TABLE + 1) << 8));

    const uint32_t state = r32(STATE_WORD);
    const uint32_t word0 = r32(PARITY_STRUCT);
    const uint32_t word1 = r32(PARITY_STRUCT + WORD_OFFSET);

    out->r0 = CALLER_R0;
    out->r1 = CALLER_R1;
    out->r2 = 0x76543212u;
    out->r3 = 0x76543213u;
    out->r4 = PARITY_STRUCT;
    out->r5 = VALUE_STRUCT;
    out->r6 = sc->offset;
    out->r7 = STATE_WORD;
    out->word = state;
    out->t = 0;

    /* the gate */
    out->r2 = state;
    out->r3 = mask;
    out->t = ((state & mask) == 0u);
    if ((state & mask) != 0u) return;

    /* the value */
    {
        const uint32_t entry = r8(VALUE_STRUCT + table) |
                               ((uint32_t)r8(VALUE_STRUCT + table + 1) << 8);
        uint32_t v = entry & 0xffffu;
        v -= sc->offset;
        v ^= xor_const;
        out->r5 = v;
        out->r6 = (uint32_t)sext16(v);
    }
    out->r0 = table;
    out->r2 = COUNT_FIRST;
    out->r1 = 1u;
    out->r3 = xor_const;
    out->r0 = WORD_OFFSET;

    /* the parity bit */
    {
        const uint32_t parity = (asr(word0, 25u) ^ asr(word1, 10u)) & 1u;
        out->r5 = parity;
        out->r4 = asr(word1, 10u);
    }
    out->r2 = COUNT_SECOND;
    out->r3 = (uint32_t)low;

    /* the bands */
    {
        const int32_t value = (int32_t)out->r6;
        const uint32_t parity = out->r5 & 1u;

        if (value > low) {
            out->r0 = (uint32_t)high;
            out->r3 = (uint32_t)low;
            out->t = (value >= high);
            if (value < high) return;

            out->r3 = (uint32_t)high2;
            out->t = (value > high2);
            if (value > high2) return;

            out->t = (parity == 0u);
            if (parity == 0u) {
                out->r2 = state | bit_high;
                out->r3 = bit_high;
                out->word = state | bit_high;
            } else {
                out->r1 = state | bit_low;
                out->r3 = bit_low;
                out->word = state | bit_low;
            }
            return;
        }

        out->r2 = (uint32_t)mid;
        out->t = (value >= mid);
        if (value < mid) {
            out->r0 = (uint32_t)high;
            out->r3 = (uint32_t)low;
            out->t = (value >= high);
            return;
        }

        out->r0 = WORD_OFFSET;
        out->t = (parity == 0u);
        if (parity == 0u) {
            out->r1 = state | bit_low;
            out->r3 = bit_low;
            out->word = state | bit_low;
        } else {
            out->r2 = state | bit_high;
            out->r3 = bit_high;
            out->word = state | bit_high;
        }
    }
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
    setup_guest(&gs, &gmap, gwin, sc);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_state_flag_entry(&gs, &gmap);
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
    a.r[4] = PARITY_STRUCT;
    a.r[5] = VALUE_STRUCT;
    a.r[6] = sc->offset;
    a.r[7] = STATE_WORD;
    a.r[15] = STATE_BASE + 0xff0u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_state_flag(&a);
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
        struct outcome want;
        model(sc, &want);
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        if (a.r[0] != want.r0 || a.r[1] != want.r1 || a.r[2] != want.r2 ||
            a.r[3] != want.r3 || a.r[4] != want.r4 || a.r[5] != want.r5 ||
            a.r[6] != want.r6 || a.r[7] != want.r7) {
            fprintf(stderr, "  outcome regs: got %08x %08x %08x %08x %08x %08x "
                    "%08x %08x want %08x %08x %08x %08x %08x %08x %08x %08x\n",
                    a.r[0], a.r[1], a.r[2], a.r[3], a.r[4], a.r[5], a.r[6], a.r[7],
                    want.r0, want.r1, want.r2, want.r3, want.r4, want.r5,
                    want.r6, want.r7);
            nb++;
        }
        if (((a.sr & 1u) != 0) != (want.t != 0)) {
            fprintf(stderr, "  T: native %u want %d\n", a.sr & 1u, want.t);
            nb++;
        }
        if (r32(STATE_WORD) != want.word) {
            fprintf(stderr, "  state word: native %08x want %08x\n", r32(STATE_WORD),
                    want.word);
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
        { .name = "the gate is closed",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00a02000u, .offset = 0x0000ab19u, .entry = 0x4288u,
          .word0 = 0x01400001u, .word1 = 0xa6000000u },

        { .name = "the value is between the bands",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x7fffu,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the value is above the high band",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0xeaa5u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the value is below the middle band",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x0000u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the high band, the parity bit clear",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x955cu,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the high band, the parity bit set",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x955cu,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        { .name = "the middle band, the parity bit clear",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x58e0u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the middle band, the parity bit set",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x58e0u,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        { .name = "the corpus' own case",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x0000ab19u, .entry = 0x4288u,
          .word0 = 0x01400001u, .word1 = 0xa6000000u },

        { .name = "the pool's numbers, all of them different",
          .table_off = 0x0800u, .low = -3000, .mid = -12000,
          .bit_low = 0x0004u, .high = 3000, .high2 = 12000,
          .bit_high = 0x0020u, .mask = 0x0000000fu, .xor_const = 0x00000001u,
          .state = 0x00000000u, .offset = 0x00000010u, .entry = 0x3041u,
          .word0 = 0x80000001u, .word1 = 0x00000003u },

        { .name = "the value is the middle band's upper bound",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x6aacu,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        { .name = "the value is the middle band's lower bound",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x155cu,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        { .name = "the value is the high band's lower bound",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x9554u,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        { .name = "the value is the high band's upper bound",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0xeaa4u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("state_flag_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
