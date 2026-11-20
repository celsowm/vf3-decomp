/* Differential replay of the native first-free-bit allocator
 * (src/native/bit_alloc.c, 0x8C038860) against the readable guest port
 * (src/fight/bit_alloc.c, `vf3_bit_alloc_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf calls nobody and uses no FP.
 * It follows the pool's two pointers (the count, the table), walks the table,
 * takes the lowest free bit of the first non-exhausted word and answers with
 * the bit's index in the whole table; a table with no free bit answers -1.
 *
 * The literal pool, the count, the table, the words and the stack are all at
 * the game's own addresses, spanned by one flat buffer.  The whole region is
 * compared byte for byte, together with the output registers (r0..r7), the
 * T bit and the restored callee-saved frame (r8..r11, r13, r14) and r15.
 * The outcome is also checked against an independent model of the guest
 * (written from the disassembly, not from the port), so a fixture that is not
 * where the guest looks cannot make both sides agree on the wrong bytes.
 *
 * The scenarios cover every branch of the guest's tree: the first bit free, a
 * middle bit, the top bit, exhausted-then-free, three exhausted then free,
 * all exhausted (answer -1, nothing written) and a zero count. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "bit_alloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_bit_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c038000u
#define RAM_SIZE 0x2e9000u     /* spans pool .. stack top (0x0c320000) */
#define CMP_HI   0x0c320000u   /* the top of the stack window */

/* ---- the windows: the game's own addresses ---- */
#define POOL_BASE   0x0c038000u
#define POOL_LEN    0x1000u
#define COUNT_BASE  0x0c0ea000u
#define COUNT_LEN   0x1000u
#define TABLE_BASE  0x0c19c000u
#define TABLE_LEN   0x1000u
#define WORDS_BASE  0x0c2e1000u
#define WORDS_LEN   0x1000u
#define STACK_BASE  0x0c31f000u
#define STACK_LEN   0x1000u
#define STACK_TOP   0x0c31fa0cu

#define P_COUNT (POOL_BASE + 0x9c8u)
#define P_TABLE (POOL_BASE + 0x9ccu)

#define CALLER_R0 0x76543210u
#define CALLER_R1 0x76543211u
#define CALLER_R2 0x76543212u
#define CALLER_R3 0x76543213u
#define CALLER_R4 0x76543214u
#define CALLER_R5 0x76543215u
#define CALLER_R6 0x76543216u
#define CALLER_R7 0x76543217u

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

#define MAX_WORDS 8

struct scenario {
    const char *name;
    uint16_t count_at;
    uint32_t count;
    uint16_t table_at;
    uint16_t words_at;
    uint32_t words[MAX_WORDS];
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    memset(ab(POOL_BASE),  0x11, POOL_LEN);
    memset(ab(COUNT_BASE), 0x22, COUNT_LEN);
    memset(ab(TABLE_BASE), 0x33, TABLE_LEN);
    memset(ab(WORDS_BASE), 0x44, WORDS_LEN);
    memset(ab(STACK_BASE), 0x55, STACK_LEN);

    const uint32_t count_addr = COUNT_BASE + sc->count_at;
    const uint32_t table_addr = TABLE_BASE + sc->table_at;
    const uint32_t words_addr = WORDS_BASE + sc->words_at;

    w32(P_COUNT, count_addr);
    w32(P_TABLE, table_addr);
    w32(count_addr, sc->count);
    w32(table_addr, words_addr);
    for (unsigned i = 0; i < MAX_WORDS; ++i)
        w32(words_addr + 4u * i, sc->words[i]);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0cabcdeu;          /* RETURN_PC */
    s->v[17] = 0x60000001u;         /* sr */
    s->v[18] = 0x00024001u;         /* fpscr */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    win[0].base = POOL_BASE;   win[0].len = POOL_LEN;   win[0].data = ab(POOL_BASE);
    win[1].base = COUNT_BASE;  win[1].len = COUNT_LEN;  win[1].data = ab(COUNT_BASE);
    win[2].base = TABLE_BASE;  win[2].len = TABLE_LEN;  win[2].data = ab(TABLE_BASE);
    win[3].base = WORDS_BASE;  win[3].len = WORDS_LEN;  win[3].data = ab(WORDS_BASE);
    win[4].base = STACK_BASE;  win[4].len = STACK_LEN;  win[4].data = ab(STACK_BASE);
    map->wins = win;
    map->n = 5;
    map->oob = 0;
}

/* the independent model of the guest, reading the fixture's own bytes */
struct outcome {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    int t;
};
static struct outcome model(const struct scenario *sc)
{
    struct outcome out;
    const uint32_t count_addr = r32(P_COUNT);
    const uint32_t table_addr = r32(P_TABLE);
    const uint32_t count = r32(count_addr);
    const uint32_t words_addr = r32(table_addr);

    out.r0 = CALLER_R0; out.r1 = CALLER_R1; out.r2 = CALLER_R2;
    out.r3 = CALLER_R3; out.r4 = CALLER_R4; out.r5 = CALLER_R5;
    out.r6 = CALLER_R6; out.r7 = CALLER_R7; out.t = 0;
    out.r7 = 0u;

    uint32_t index = 0, bit_base = 0u;
    for (;;) {
        out.r3 = count;
        if ((int32_t)index >= (int32_t)count) {
            out.r0 = 0xffffffffu;
            out.r5 = bit_base;
            out.t = 1;
            break;
        }
        const uint32_t word = r32(words_addr + 4u * index);
        out.r1 = word;
        if (word == 0xffffffffu) {
            ++index; bit_base += 32u;
            continue;
        }
        uint32_t mask = 1u, bit = 0u;
        while (word & mask) { mask <<= 1; ++bit; }
        out.r4 = mask; out.r6 = bit; out.r5 = bit_base;
        out.r0 = bit_base + bit; out.r2 = word | mask; out.t = 1;
        break;
    }
    (void)sc;
    return out;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    struct outcome want = model(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[5];
    setup_guest(&gs, &gmap, gwin);
    seed_all(sc);            /* setup_guest does not seed RAM; re-seed */
    const int ok_guest = vf3_bit_alloc_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the guest's RAM before the native re-seeds */
    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[15] = STACK_TOP;
    a.pr = 0x0cabcdeu;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_bit_alloc(&a, STACK_TOP);

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

    /* output registers + frame restore + T bit */
    {
        int nb = 0;
        static const unsigned out_regs[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        uint32_t want_regs[8] = { want.r0, want.r1, want.r2, want.r3,
                                  want.r4, want.r5, want.r6, want.r7 };
        for (unsigned i = 0; i < 8; ++i)
            if (a.r[out_regs[i]] != want_regs[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", out_regs[i],
                        a.r[out_regs[i]], want_regs[i]);
                nb++;
            }
        if ((a.sr & 1u) != (unsigned)want.t) {
            fprintf(stderr, "  sr T: native %u want %d\n", a.sr & 1u, want.t); nb++;
        }
        /* guest's own registers should equal the model too */
        if (gs.v[0] != want.r0 || gs.v[1] != want.r1 || gs.v[2] != want.r2 ||
            gs.v[3] != want.r3 || gs.v[4] != want.r4 || gs.v[5] != want.r5 ||
            gs.v[6] != want.r6 || gs.v[7] != want.r7 || (gs.v[17] & 1u) != (unsigned)want.t) {
            fprintf(stderr, "  guest regs diverge from model\n"); nb++;
        }
        /* the callee-saved frame (r8..r11, r13, r14) must come back; r15
         * must land back on the entry stack pointer */
        for (unsigned r = 8; r <= 14; ++r) {
            uint32_t want_r = 0x76543210u + r;
            if (a.r[r] != want_r) {
                fprintf(stderr, "  r%u restored: native %08x want %08x\n", r, a.r[r], want_r);
                nb++;
            }
        }
        if (a.r[15] != STACK_TOP) {
            fprintf(stderr, "  r15 restored: native %08x want %08x\n", a.r[15], STACK_TOP);
            nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "the first bit is free", .count_at = 0x38cu, .count = 4u,
          .table_at = 0xc2cu, .words_at = 0x85cu,
          .words = { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u } },
        { .name = "a bit in the middle is free", .count_at = 0x10cu, .count = 3u,
          .table_at = 0x200u, .words_at = 0x100u,
          .words = { 0x00000007u, 0x00000000u, 0x00000000u } },
        { .name = "the top bit is free", .count_at = 0x800u, .count = 2u,
          .table_at = 0x400u, .words_at = 0x300u,
          .words = { 0x7fffffffu, 0x00000000u } },
        { .name = "the first word is exhausted", .count_at = 0x24u, .count = 4u,
          .table_at = 0x600u, .words_at = 0x500u,
          .words = { 0xffffffffu, 0x00000000u, 0x00000000u, 0x00000000u } },
        { .name = "three words are exhausted", .count_at = 0x300u, .count = 5u,
          .table_at = 0x800u, .words_at = 0x600u,
          .words = { 0xffffffffu, 0xffffffffu, 0xffffffffu, 0x00000001u, 0x00000000u } },
        { .name = "every word is exhausted", .count_at = 0x400u, .count = 3u,
          .table_at = 0xa00u, .words_at = 0x700u,
          .words = { 0xffffffffu, 0xffffffffu, 0xffffffffu } },
        { .name = "the count is zero", .count_at = 0x500u, .count = 0u,
          .table_at = 0xc2cu, .words_at = 0x900u,
          .words = { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u } },
        { .name = "one word, its top bit free", .count_at = 0x600u, .count = 1u,
          .table_at = 0x200u, .words_at = 0x85cu,
          .words = { 0x7fffffffu, 0x00000000u, 0x00000000u, 0x00000000u } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("bit_alloc_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
