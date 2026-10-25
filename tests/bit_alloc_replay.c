/* bit_alloc_replay.c - the readable bit allocator (SH-4 0x8C038860) against the
 * retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the two leaves are the
 * *generated* translation and the readable port, and they are compared against
 * each other.
 *
 * The three arms are:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it).
 *
 * All three compare the whole register file, the return PC, the failed PC, the
 * out-of-window counter and every RAM byte.  The test also checks the outcome
 * **against the fixture itself**: the eight registers the guest leaves, the T
 * bit and the word it writes.  Those expectations come from a second
 * implementation in the test, written from the disassembly and not from the
 * port, and it reads the fixture's own bytes - a differential alone is not
 * enough, because a fixture that is not where the guest looks makes both sides
 * read the same wrong bytes and agree on them.
 *
 * The fixture uses the game's own addresses - the pool at 0x0c0389c8, the
 * count at 0x0c0ea38c, the table at 0x0c19cc2c, the words at 0x0c2e185c and the
 * stack at 0x0c31fa0c - but every *value* the guest follows is moved around:
 * the pool's two pointers, the count, the table's first entry and the words
 * themselves all sit at scenario-dependent offsets.  The corpus always carries
 * the game's own numbers (the count 33, the table 0x0c19cc2c and the words at
 * 0x0c2e185c), so a port that hard-coded the capture would still replay the
 * corpus - and would fail here.
 *
 * The scenarios cover **every branch of the guest's tree**:
 *
 *   * the first slot's bit 0 is free;
 *   * a bit in the middle of the word is free, with the lower ones taken;
 *   * the word's **top** bit (31) is the free one - the mask reaches its last
 *     step;
 *   * the first slot is exhausted and the second one is free - the guest skips
 *     a slot and the answer moves on by a whole word;
 *   * three slots are exhausted and the fourth is free;
 *   * **every** slot is exhausted and the count is reached: the answer is -1
 *     and nothing is written;
 *   * the count is zero: the answer is -1 before a single word is read.
 *
 * The last two are **not in the corpus**: all 194 specimens either find a free
 * bit or skip to one, so the "no free bit at all" answer is the differential's
 * business.  The corpus is the oracle's business, and it has its own test.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_bit_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c038860u

#define RETURN_PC 0x0cabcdeu

/* ---- the windows: the game's own addresses ---- */
#define POOL_BASE   0x0c038000u   /* the literal pool */
#define POOL_LEN    0x1000u
#define COUNT_BASE  0x0c0ea000u   /* where the count lives */
#define COUNT_LEN   0x1000u
#define TABLE_BASE  0x0c19c000u   /* where the table lives */
#define TABLE_LEN   0x1000u
#define WORDS_BASE  0x0c2e1000u   /* where the words live */
#define WORDS_LEN   0x1000u
#define STACK_BASE  0x0c31f000u   /* the stack */
#define STACK_LEN   0x1000u
#define NWIN 5

#define OFF_POOL   0u
#define OFF_COUNT  (OFF_POOL + POOL_LEN)
#define OFF_TABLE  (OFF_COUNT + COUNT_LEN)
#define OFF_WORDS  (OFF_TABLE + TABLE_LEN)
#define OFF_STACK  (OFF_WORDS + WORDS_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

/* ---- the pool's entries: the game's own addresses ---- */
#define P_COUNT (POOL_BASE + 0x9c8u)   /* where the count's address lives */
#define P_TABLE (POOL_BASE + 0x9ccu)   /* where the table's address lives */

/* ---- the caller's registers that the fixture does not overwrite ---- */
#define CALLER_R0 0x76543210u
#define CALLER_R1 0x76543211u
#define CALLER_R2 0x76543212u
#define CALLER_R4 0x76543214u
#define CALLER_R6 0x76543216u

/* the windows, for the model's own reads */
static const struct {
    uint32_t base;
    uint32_t len;
    uint32_t off;
} windows[NWIN] = {
    { POOL_BASE,  POOL_LEN,  OFF_POOL },
    { COUNT_BASE, COUNT_LEN, OFF_COUNT },
    { TABLE_BASE, TABLE_LEN, OFF_TABLE },
    { WORDS_BASE, WORDS_LEN, OFF_WORDS },
    { STACK_BASE, STACK_LEN, OFF_STACK },
};

#define MAX_WORDS 8

struct scenario {
    const char *name;
    uint16_t count_at;      /* where the count sits, in the count window */
    uint32_t count;         /* the number of words the table has */
    uint16_t table_at;      /* where the table sits, in the table window */
    uint16_t words_at;      /* where the words sit, in the words window */
    uint32_t words[MAX_WORDS];
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
};

/* ---- the model's own reads of the fixture ---- */
static const uint8_t *at(const uint8_t *shadow, uint32_t addr, uint32_t size)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= windows[i].base && addr + size <= windows[i].base + windows[i].len)
            return shadow + windows[i].off + (addr - windows[i].base);
    return NULL;
}

static uint32_t m_u32(const uint8_t *shadow, uint32_t addr)
{
    const uint8_t *p = at(shadow, addr, 4);
    return p ? (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                 ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24) : 0u;
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* Every window is filled with its own pattern first, so a port that reads
     * the wrong address sees bytes that are not the ones the guest meant. */
    memset(p + OFF_POOL,  0x11, POOL_LEN);
    memset(p + OFF_COUNT, 0x22, COUNT_LEN);
    memset(p + OFF_TABLE, 0x33, TABLE_LEN);
    memset(p + OFF_WORDS, 0x44, WORDS_LEN);
    memset(p + OFF_STACK, 0x55, STACK_LEN);

    const uint32_t count_addr = COUNT_BASE + sc->count_at;
    const uint32_t table_addr = TABLE_BASE + sc->table_at;
    const uint32_t words_addr = WORDS_BASE + sc->words_at;

    /* the pool: the two addresses the guest follows */
    w32(p + OFF_POOL, P_COUNT - POOL_BASE, count_addr);
    w32(p + OFF_POOL, P_TABLE - POOL_BASE, table_addr);

    /* the count */
    w32(p + OFF_COUNT, sc->count_at, sc->count);

    /* the table: its first entry points at the words */
    w32(p + OFF_TABLE, sc->table_at, words_addr);

    /* the words */
    for (unsigned i = 0; i < MAX_WORDS; ++i)
        w32(p + OFF_WORDS, sc->words_at + 4u * i, sc->words[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = STACK_BASE + 0xa0cu;     /* the stack, the corpus' own */
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;             /* sr: the corpus' own value */
    /* The dispatcher refuses to run anything when the FPU is unsupported
     * (FPSCR.RM is 2 or 3, or the precision bit is set), and the corpus
     * carries 0x240001 / 0x40001.  The function uses no FP instruction, but
     * the gate stands between the caller and the body. */
    s->v[18] = 0x00024001u;             /* fpscr: the corpus' own value */
    s->budget = 1000000u;

    r->wins[0].base = POOL_BASE;  r->wins[0].len = POOL_LEN;
    r->wins[1].base = COUNT_BASE; r->wins[1].len = COUNT_LEN;
    r->wins[2].base = TABLE_BASE; r->wins[2].len = TABLE_LEN;
    r->wins[3].base = WORDS_BASE; r->wins[3].len = WORDS_LEN;
    r->wins[4].base = STACK_BASE; r->wins[4].len = STACK_LEN;
    r->wins[0].data = p + OFF_POOL;
    r->wins[1].data = p + OFF_COUNT;
    r->wins[2].data = p + OFF_TABLE;
    r->wins[3].data = p + OFF_WORDS;
    r->wins[4].data = p + OFF_STACK;
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 54 && shown < 8; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                ++shown;
            }
        return 0;
    }
    if (a->state.pc != b->state.pc || a->state.failed_pc != b->state.failed_pc) {
        fprintf(stderr, "  %s: pc %08x/%08x failed %08x/%08x\n", what,
                a->state.pc, b->state.pc, a->state.failed_pc, b->state.failed_pc);
        return 0;
    }
    if (a->map.oob != b->map.oob) {
        fprintf(stderr, "  %s: oob %u/%u\n", what, a->map.oob, b->map.oob);
        return 0;
    }
    if (memcmp(a->shadow, b->shadow, SHADOW_LEN)) {
        for (unsigned i = 0; i < SHADOW_LEN; ++i)
            if (a->shadow[i] != b->shadow[i]) {
                fprintf(stderr, "  %s: ram %u %02x != %02x\n", what, i,
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

/* ---- the model of the guest ----
 *
 * The guest walks the table's words.  A word of 0xffffffff is an exhausted
 * slot and the guest moves on to the next one; any other word has a free bit
 * - the lowest one - and the guest takes it and answers with the bit's number
 * in the whole table: the word's index times 32, plus the bit's number inside
 * the word.  A table with no free bit answers -1 and writes nothing.
 *
 * The registers the guest leaves are part of the answer: the word it stopped
 * at (r1), the count (r3), the mask it used (r4), the word's base (r5) and
 * the bit's number (r6). */
struct outcome {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    int t;                       /* the T bit the guest leaves */
};

static void model(const uint8_t *shadow, struct outcome *out)
{
    const uint32_t count_addr = m_u32(shadow, P_COUNT);
    const uint32_t table_addr = m_u32(shadow, P_TABLE);
    const uint32_t count = m_u32(shadow, count_addr);
    const uint32_t words_addr = m_u32(shadow, table_addr);

    /* what the caller handed over, before the guest touches anything */
    out->r0 = CALLER_R0;
    out->r1 = CALLER_R1;
    out->r2 = CALLER_R2;
    out->r3 = 0x76543213u;
    out->r4 = CALLER_R4;
    out->r5 = 0x76543215u;
    out->r6 = CALLER_R6;
    out->r7 = 0x76543217u;
    out->t = 0;

    /* the guest zeroes r7 and counts from there */
    out->r7 = 0u;

    uint32_t index = 0;          /* the guest's r10 */
    uint32_t bit_base = 0u;      /* the guest's r5: the bit offset */

    for (;;) {
        /* the loop's condition: the index against the count */
        out->r3 = count;
        if ((int32_t)index >= (int32_t)count) {
            /* the table is exhausted: the answer is -1, nothing is written */
            out->r0 = 0xffffffffu;
            out->r5 = bit_base;
            out->t = 1;
            break;
        }

        /* the word at this index */
        const uint32_t word = m_u32(shadow, words_addr + 4u * index);
        out->r1 = word;
        if (word == 0xffffffffu) {
            /* an exhausted slot: the next word */
            ++index;
            bit_base += 32u;
            continue;
        }

        /* the bit scan: the lowest clear bit of the word */
        uint32_t mask = 1u;
        uint32_t bit = 0u;
        while (word & mask) {
            mask <<= 1;
            ++bit;
        }
        out->r4 = mask;
        out->r6 = bit;
        out->r5 = bit_base;
        out->r0 = bit_base + bit;
        out->r2 = word | mask;
        out->t = 1;
        break;
    }
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    /* the shadow is large, so the three runs live in static storage */
    static struct run ref, port, hook;
    struct outcome want;

    setup(&ref, sc);
    /* the expectation, computed from the fixture before the port touches it */
    model(ref.shadow, &want);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_bit_alloc_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                               &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "bit_alloc: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "bit_alloc: %s reads outside the windows "
                "(oob %u/%u/%u)\n", sc->name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        const uint32_t words_addr = m_u32(ref.shadow, m_u32(ref.shadow, P_TABLE));
        const uint32_t count = m_u32(ref.shadow, m_u32(ref.shadow, P_COUNT));
        if (ref.state.v[0] != want.r0 || ref.state.v[1] != want.r1 ||
            ref.state.v[2] != want.r2 || ref.state.v[3] != want.r3 ||
            ref.state.v[4] != want.r4 || ref.state.v[5] != want.r5 ||
            ref.state.v[6] != want.r6 || ref.state.v[7] != want.r7) {
            fprintf(stderr, "bit_alloc: %s: the registers are %08x %08x %08x "
                    "%08x %08x %08x %08x %08x, expected %08x %08x %08x %08x "
                    "%08x %08x %08x %08x\n", sc->name,
                    ref.state.v[0], ref.state.v[1], ref.state.v[2], ref.state.v[3],
                    ref.state.v[4], ref.state.v[5], ref.state.v[6], ref.state.v[7],
                    want.r0, want.r1, want.r2, want.r3,
                    want.r4, want.r5, want.r6, want.r7);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != want.t) {
            fprintf(stderr, "bit_alloc: %s: the T bit is %u, expected %d\n",
                    sc->name, ref.state.v[17] & 1u, want.t);
            return 0;
        }
        /* the word the guest wrote: the one it took the bit in, and only that
         * one - the table's other words are untouched */
        if (want.r0 != 0xffffffffu) {
            const uint32_t index = want.r0 / 32u;
            const uint8_t *p = at(ref.shadow, words_addr + 4u * index, 4);
            if (!p || r32(p, 0) != want.r2) {
                fprintf(stderr, "bit_alloc: %s: the word %u is %08x, expected "
                        "%08x\n", sc->name, index, p ? r32(p, 0) : 0u, want.r2);
                return 0;
            }
        } else {
            /* nothing is written when there is no free bit */
            for (unsigned i = 0; i < count; ++i) {
                const uint8_t *p = at(ref.shadow, words_addr + 4u * i, 4);
                if (!p || r32(p, 0) != sc->words[i]) {
                    fprintf(stderr, "bit_alloc: %s: the word %u changed even "
                            "though there is no free bit\n", sc->name, i);
                    return 0;
                }
            }
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_bit_alloc_entry) {
        fprintf(stderr, "bit_alloc: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* The first word's bit 0 is free: the answer is 0. */
        { .name = "the first bit is free",
          .count_at = 0x38cu, .count = 4u, .table_at = 0xc2cu,
          .words_at = 0x85cu,
          .words = { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u } },

        /* A bit in the middle is free, with the lower ones taken: the answer
         * is 3, and the mask is 8. */
        { .name = "a bit in the middle is free",
          .count_at = 0x10cu, .count = 3u, .table_at = 0x200u,
          .words_at = 0x100u,
          .words = { 0x00000007u, 0x00000000u, 0x00000000u } },

        /* The word's top bit is the free one: the mask reaches its last
         * step, 0x80000000, and the answer is 31. */
        { .name = "the top bit is free",
          .count_at = 0x800u, .count = 2u, .table_at = 0x400u,
          .words_at = 0x300u,
          .words = { 0x7fffffffu, 0x00000000u } },

        /* The first word is exhausted: the guest skips it and takes the
         * second word's bit 0.  The answer is a whole word further on, and
         * r1 holds the exhausted word. */
        { .name = "the first word is exhausted",
          .count_at = 0x24u, .count = 4u, .table_at = 0x600u,
          .words_at = 0x500u,
          .words = { 0xffffffffu, 0x00000000u, 0x00000000u, 0x00000000u } },

        /* Three exhausted words, then a free one: the answer is 96 + 1. */
        { .name = "three words are exhausted",
          .count_at = 0x300u, .count = 5u, .table_at = 0x800u,
          .words_at = 0x600u,
          .words = { 0xffffffffu, 0xffffffffu, 0xffffffffu,
                     0x00000001u, 0x00000000u } },

        /* Every word is exhausted and the count is reached: the answer is -1
         * and nothing is written. */
        { .name = "every word is exhausted",
          .count_at = 0x400u, .count = 3u, .table_at = 0xa00u,
          .words_at = 0x700u,
          .words = { 0xffffffffu, 0xffffffffu, 0xffffffffu } },

        /* The count is zero: the answer is -1 before a single word is read,
         * and r1 keeps the caller's value. */
        { .name = "the count is zero",
          .count_at = 0x500u, .count = 0u, .table_at = 0xc2cu,
          .words_at = 0x900u,
          .words = { 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u } },

        /* The count is one and that word is free at its top bit: the answer
         * is 31 and the mask is 0x80000000. */
        { .name = "one word, its top bit free",
          .count_at = 0x600u, .count = 1u, .table_at = 0x200u,
          .words_at = 0x85cu,
          .words = { 0x7fffffffu, 0x00000000u, 0x00000000u, 0x00000000u } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("bit_alloc: %u differential cases - PASS\n", cases);
    return 0;
}
