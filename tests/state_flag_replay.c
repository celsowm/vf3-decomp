/* state_flag_replay.c - the readable state flag (SH-4 0x8C0B0FD2) against the
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
 * bit and the word it writes into the state.  Those expectations come from a
 * second implementation in the test, written from the disassembly and not
 * from the port, and it reads the fixture's own bytes - a differential alone
 * is not enough, because a fixture that is not where the guest looks makes
 * both sides read the same wrong bytes and agree on them.
 *
 * The fixture uses the game's own addresses - the pool at 0x0c0b1070..
 * 0x0c0b109c, the state word at 0x0c31f9d0 - but with values the corpus does
 * not use, so a port that hard-coded the capture would fail here.  In
 * particular **every one of the pool's nine entries is varied**: the two
 * bounds of each band, the two flag bits, the gate's mask, the xor constant
 * and the offset of the value's halfword.  The corpus always carries the
 * game's own numbers (5460, 27300, 0x800, 0x1000, 0x00a02000, 0x00008000 and
 * the offset 0x1494), so a port that read them from anywhere else would
 * still replay the corpus.
 *
 * The scenarios cover **every branch of the guest's tree**: the gate, the
 * value between the two bands, above the high band, below the middle band,
 * inside the high band and inside the middle band - and, in both bands, both
 * answers.  The two bands answer the opposite way round, so a port that read
 * one of them the wrong way round would still pass a corpus that only ever
 * reaches one of them.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_state_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0b0fd2u

#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE   0x0c0b1000u   /* the literal pool */
#define POOL_LEN    0x1000u
#define STRUCT_BASE 0x0c200000u   /* the structures the caller hands over */
#define STRUCT_LEN  0x4000u
#define STATE_BASE  0x0c31f000u   /* the state word */
#define STATE_LEN   0x1000u
#define NWIN 3

#define OFF_POOL   0u
#define OFF_STRUCT (OFF_POOL + POOL_LEN)
#define OFF_STATE  (OFF_STRUCT + STRUCT_LEN)
#define SHADOW_LEN (OFF_STATE + STATE_LEN)

/* ---- where things live ---- */
#define VALUE_STRUCT  (STRUCT_BASE + 0x100u)  /* r5: the structure with the value */
#define PARITY_STRUCT (STRUCT_BASE + 0x200u)  /* r4: the structure with the two words */
#define STATE_WORD    (STATE_BASE + 0x9d0u)    /* r7: the state word */

/* ---- the pool's entries ---- */
#define P_TABLE    (POOL_BASE + 0x70u)   /* the offset of the value's halfword */
#define P_LOW      (POOL_BASE + 0x72u)   /* the middle band's upper bound */
#define P_MID      (POOL_BASE + 0x74u)   /* the middle band's lower bound */
#define P_BIT_LOW  (POOL_BASE + 0x76u)   /* the bit the low answer sets */
#define P_HIGH     (POOL_BASE + 0x78u)   /* the high band's lower bound */
#define P_HIGH2    (POOL_BASE + 0x7au)   /* the high band's upper bound */
#define P_BIT_HIGH (POOL_BASE + 0x7cu)   /* the bit the high answer sets */
#define P_MASK     (POOL_BASE + 0x94u)   /* the gate's mask */
#define P_XOR      (POOL_BASE + 0x98u)   /* the xor constant */

/* ---- the guest's constants ---- */
#define WORD_OFFSET 72u                   /* the second parity word's offset */
#define COUNT_FIRST 0xffffffe7u           /* the first shift's count */
#define COUNT_SECOND 0xfffffff6u          /* the second shift's count */

/* the caller's registers that the fixture does not overwrite */
#define CALLER_R0 0x76543210u
#define CALLER_R1 0x76543211u

/* the windows, for the model's own reads */
static const struct {
    uint32_t base;
    uint32_t len;
    uint32_t off;
} windows[NWIN] = {
    { POOL_BASE,   POOL_LEN,   OFF_POOL },
    { STRUCT_BASE, STRUCT_LEN, OFF_STRUCT },
    { STATE_BASE,  STATE_LEN,  OFF_STATE },
};

struct scenario {
    const char *name;
    uint16_t table_off;   /* the pool: the offset of the value's halfword */
    int16_t  low;         /* the pool: the middle band's upper bound */
    int16_t  mid;         /* the pool: the middle band's lower bound */
    uint16_t bit_low;     /* the pool: the bit the low answer sets */
    int16_t  high;        /* the pool: the high band's lower bound */
    int16_t  high2;       /* the pool: the high band's upper bound */
    uint16_t bit_high;    /* the pool: the bit the high answer sets */
    uint32_t mask;        /* the pool: the gate's mask */
    uint32_t xor_const;   /* the pool: the xor constant */
    uint32_t state;       /* the word at r7 */
    uint32_t offset;      /* r6: the offset the value is measured from */
    uint16_t entry;       /* the halfword the value comes from */
    uint32_t word0;       /* the first parity word */
    uint32_t word1;       /* the second parity word */
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

static uint32_t m_u16(const uint8_t *shadow, uint32_t addr)
{
    const uint8_t *p = at(shadow, addr, 2);
    return p ? (uint32_t)p[0] | ((uint32_t)p[1] << 8) : 0u;
}

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
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

    /* the literal pool: every entry the guest reads */
    w16(p + OFF_POOL, P_TABLE - POOL_BASE, sc->table_off);
    w16(p + OFF_POOL, P_LOW - POOL_BASE, (uint16_t)sc->low);
    w16(p + OFF_POOL, P_MID - POOL_BASE, (uint16_t)sc->mid);
    w16(p + OFF_POOL, P_BIT_LOW - POOL_BASE, sc->bit_low);
    w16(p + OFF_POOL, P_HIGH - POOL_BASE, (uint16_t)sc->high);
    w16(p + OFF_POOL, P_HIGH2 - POOL_BASE, (uint16_t)sc->high2);
    w16(p + OFF_POOL, P_BIT_HIGH - POOL_BASE, sc->bit_high);
    w32(p + OFF_POOL, P_MASK - POOL_BASE, sc->mask);
    w32(p + OFF_POOL, P_XOR - POOL_BASE, sc->xor_const);

    /* the structures: the value's halfword and the two parity words.  The
     * structures are filled with garbage first, so a port that reads the
     * wrong word - or the wrong offset - is visible. */
    memset(p + OFF_STRUCT, 0x5c, STRUCT_LEN);
    w16(p + OFF_STRUCT, (VALUE_STRUCT + sc->table_off) - STRUCT_BASE, sc->entry);
    w32(p + OFF_STRUCT, PARITY_STRUCT - STRUCT_BASE, sc->word0);
    w32(p + OFF_STRUCT, PARITY_STRUCT + WORD_OFFSET - STRUCT_BASE, sc->word1);

    /* the state word */
    w32(p + OFF_STATE, STATE_WORD - STATE_BASE, sc->state);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = PARITY_STRUCT;            /* the structure with the two words */
    s->v[5] = VALUE_STRUCT;             /* the structure with the value */
    s->v[6] = sc->offset;               /* the offset the value is measured from */
    s->v[7] = STATE_WORD;               /* the state word */
    s->v[15] = STATE_BASE + 0xff0u;     /* the stack */
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;             /* sr: the corpus' own value, T bit clear */
    /* The dispatcher refuses to run anything when the FPU is unsupported
     * (FPSCR.RM is 2 or 3, or the precision bit is set), and the corpus
     * carries 0x240001 / 0x40001.  The function uses no FP instruction, but
     * the gate stands between the caller and the body. */
    s->v[18] = 0x00024001u;             /* fpscr: the corpus' own value */
    s->budget = 1000000u;

    r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].base = STRUCT_BASE; r->wins[1].len = STRUCT_LEN;
    r->wins[2].base = STATE_BASE;  r->wins[2].len = STATE_LEN;
    r->wins[0].data = p + OFF_POOL;
    r->wins[1].data = p + OFF_STRUCT;
    r->wins[2].data = p + OFF_STATE;
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
 * The guest reads a halfword out of the structure r5 points at, turns it into
 * a signed value, works out one parity bit out of two words, and then sets
 * one of two bits in the word at r7 - or nothing at all.  The model below
 * recomputes all of that from the fixture's own bytes. */
struct outcome {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    int t;                       /* the T bit the guest leaves */
    uint32_t word;               /* the word at r7 afterwards */
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

static void model(const uint8_t *shadow, const struct scenario *sc,
                  struct outcome *out)
{
    const uint32_t mask = m_u32(shadow, P_MASK);
    const uint32_t xor_const = m_u32(shadow, P_XOR);
    const int32_t low = sext16(m_u16(shadow, P_LOW));
    const int32_t mid = sext16(m_u16(shadow, P_MID));
    const int32_t high = sext16(m_u16(shadow, P_HIGH));
    const int32_t high2 = sext16(m_u16(shadow, P_HIGH2));
    const uint32_t bit_low = m_u16(shadow, P_BIT_LOW);
    const uint32_t bit_high = m_u16(shadow, P_BIT_HIGH);
    const uint32_t table = (uint32_t)sext16(m_u16(shadow, P_TABLE));

    const uint32_t state = m_u32(shadow, STATE_WORD);
    const uint32_t word0 = m_u32(shadow, PARITY_STRUCT);
    const uint32_t word1 = m_u32(shadow, PARITY_STRUCT + WORD_OFFSET);

    /* what the caller handed over, before the guest touches anything */
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

    /* ---- the gate ---- */
    out->r2 = state;
    out->r3 = mask;
    out->t = ((state & mask) == 0u);
    if ((state & mask) != 0u) return;         /* the gate is closed */

    /* ---- the value ----
     * The halfword is read signed and then truncated to sixteen bits again,
     * r6 is subtracted from it and the pool's xor constant flips the sign
     * bit; what is left is a signed number. */
    {
        const uint32_t entry = m_u16(shadow, VALUE_STRUCT + table) & 0xffffu;
        uint32_t v = entry;
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

    /* ---- the parity bit ----
     * The two words are shifted right - 25 and 10 bits - and exclusive-ored;
     * only the low bit of the result is kept. */
    {
        const uint32_t parity = (asr(word0, 25u) ^ asr(word1, 10u)) & 1u;
        out->r5 = parity;
        out->r4 = asr(word1, 10u);
    }
    out->r2 = COUNT_SECOND;
    out->r3 = (uint32_t)low;

    /* ---- the bands ---- */
    {
        const int32_t value = (int32_t)out->r6;
        const uint32_t parity = out->r5 & 1u;

        if (value > low) {
            /* the high band, or nothing at all */
            out->r0 = (uint32_t)high;
            out->r3 = (uint32_t)low;
            out->t = (value >= high);
            if (value < high) return;          /* below the band */

            out->r3 = (uint32_t)high2;
            out->t = (value > high2);
            if (value > high2) return;          /* above the band */

            /* inside the high band: a clear parity bit sets the high bit */
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

        /* below the low bound: the middle band, or the high band */
        out->r2 = (uint32_t)mid;
        out->t = (value >= mid);
        if (value < mid) {
            /* below the middle bound: the high band again, and the value is
             * below its lower bound as well */
            out->r0 = (uint32_t)high;
            out->r3 = (uint32_t)low;
            out->t = (value >= high);
            return;
        }

        /* the middle band: a clear parity bit sets the low bit - the other
         * way round than in the high band */
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

static unsigned cases;

static int compare(const struct scenario *sc)
{
    /* the shadow is large, so the three runs live in static storage */
    static struct run ref, port, hook;
    struct outcome want;

    setup(&ref, sc);
    /* the expectation, computed from the fixture before the port touches it */
    model(ref.shadow, sc, &want);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_state_flag_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "state_flag: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "state_flag: %s reads outside the windows "
                "(oob %u/%u/%u)\n", sc->name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        const uint8_t *st = ref.shadow + OFF_STATE + (STATE_WORD - STATE_BASE);
        if (ref.state.v[0] != want.r0 || ref.state.v[1] != want.r1 ||
            ref.state.v[2] != want.r2 || ref.state.v[3] != want.r3 ||
            ref.state.v[4] != want.r4 || ref.state.v[5] != want.r5 ||
            ref.state.v[6] != want.r6 || ref.state.v[7] != want.r7) {
            fprintf(stderr, "state_flag: %s: the registers are %08x %08x %08x "
                    "%08x %08x %08x %08x %08x, expected %08x %08x %08x %08x "
                    "%08x %08x %08x %08x\n", sc->name,
                    ref.state.v[0], ref.state.v[1], ref.state.v[2], ref.state.v[3],
                    ref.state.v[4], ref.state.v[5], ref.state.v[6], ref.state.v[7],
                    want.r0, want.r1, want.r2, want.r3,
                    want.r4, want.r5, want.r6, want.r7);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != want.t) {
            fprintf(stderr, "state_flag: %s: the T bit is %u, expected %d\n",
                    sc->name, ref.state.v[17] & 1u, want.t);
            return 0;
        }
        if (r32(st, 0) != want.word) {
            fprintf(stderr, "state_flag: %s: the state word is %08x, expected "
                    "%08x\n", sc->name, r32(st, 0), want.word);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_state_flag_entry) {
        fprintf(stderr, "state_flag: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* The gate is closed: the word carries the mask's bits and nothing
         * happens at all - the word is not even written back. */
        { .name = "the gate is closed",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00a02000u, .offset = 0x0000ab19u, .entry = 0x4288u,
          .word0 = 0x01400001u, .word1 = 0xa6000000u },

        /* The value is between the two bands (-1): nothing happens. */
        { .name = "the value is between the bands",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x7fffu,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        /* The value is above the high band (27301): nothing happens. */
        { .name = "the value is above the high band",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0xeaa5u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        /* The value is below the middle band (-32768): the guest walks into
         * the high band, and there it is below the lower bound as well. */
        { .name = "the value is below the middle band",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x00000000u, .entry = 0x0000u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        /* Inside the high band (5468), the parity bit clear: the high bit.
         * The state word is not empty here, so a port that reads the word
         * from the wrong place shows up. */
        { .name = "the high band, the parity bit clear",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x955cu,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        /* Inside the high band, the parity bit set: the low bit. */
        { .name = "the high band, the parity bit set",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x955cu,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        /* Inside the middle band (-10000), the parity bit clear: the low
         * bit - the other way round than in the high band. */
        { .name = "the middle band, the parity bit clear",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x58e0u,
          .word0 = 0x00000000u, .word1 = 0x00000000u },

        /* Inside the middle band, the parity bit set: the high bit. */
        { .name = "the middle band, the parity bit set",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000040u, .offset = 0x00000000u, .entry = 0x58e0u,
          .word0 = 0x02000000u, .word1 = 0x00000000u },

        /* The corpus' own case: the value is 5991, inside the high band,
         * and the parity bit is clear - the corpus' own answer is the high
         * bit 0x1000. */
        { .name = "the corpus' own case",
          .table_off = 0x1494u, .low = -5460, .mid = -27300,
          .bit_low = 0x0800u, .high = 5460, .high2 = 27300,
          .bit_high = 0x1000u, .mask = 0x00a02000u, .xor_const = 0x00008000u,
          .state = 0x00000000u, .offset = 0x0000ab19u, .entry = 0x4288u,
          .word0 = 0x01400001u, .word1 = 0xa6000000u },

        /* The pool's own numbers, all of them different: another offset for
         * the value's halfword, other bounds, other bits, another mask and
         * another xor constant. */
        { .name = "the pool's numbers, all of them different",
          .table_off = 0x0800u, .low = -3000, .mid = -12000,
          .bit_low = 0x0004u, .high = 3000, .high2 = 12000,
          .bit_high = 0x0020u, .mask = 0x0000000fu, .xor_const = 0x00000001u,
          .state = 0x00000000u, .offset = 0x00000010u, .entry = 0x3041u,
          .word0 = 0x80000001u, .word1 = 0x00000003u },

        /* The four boundaries of the bands.  The corpus never reaches any of
         * them, and the guest's own comparisons decide them: the middle band
         * keeps its lower bound and its upper bound, and so does the high
         * band. */
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

    unsigned failures = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) ++failures;

    if (failures) {
        fprintf(stderr, "state_flag: %u of %u scenarios failed\n", failures,
                (unsigned)(sizeof scenarios / sizeof scenarios[0]));
        return 1;
    }
    printf("state_flag: %u differential cases - PASS\n", cases);
    return 0;
}
