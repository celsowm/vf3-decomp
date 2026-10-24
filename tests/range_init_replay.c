/* range_init_replay.c - the readable structure init against the retained
 * generated translation of SH-4 0x8C036A58.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function sets up a forty-four byte structure: most of it is zeroed, but
 * four words in the middle carry a range whose shape depends on a word the
 * pool points at.  The test lays the literal pool, the flag word and the
 * structure out the way the guest expects, and walks the flag through the
 * shapes it can have.
 *
 * The structure starts full of a pattern, so a byte that is not written - the
 * ones past the structure's forty-four bytes - shows up.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_range_init_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c036a58u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the pointer to the flag word, and the tail word */
#define POOL_BASE 0x0c036ae0u
#define POOL_LEN  0x40u
#define G_FLAG (POOL_BASE + 0x10u)
#define G_TAIL (POOL_BASE + 0x2cu)

/* the word the pool points at */
#define FLAG_BASE 0x0c140000u
#define FLAG_LEN  0x10u

/* the structure */
#define STRUCT_BASE 0x0c150000u
#define STRUCT_LEN  0x40u

/* the word that lands in the structure's +36 */
#define TAIL_WORD 0x0badf00du

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL   0u
#define OFF_FLAG   (OFF_POOL + POOL_LEN)
#define OFF_STRUCT (OFF_FLAG + FLAG_LEN)
#define SHADOW_LEN (OFF_STRUCT + STRUCT_LEN)

struct scenario {
    const char *name;
    uint32_t flag;    /* the word the pool points at */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[3];
    vf3_ram_map map;
};

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w32(p + OFF_POOL, G_FLAG - POOL_BASE, FLAG_BASE);
    w32(p + OFF_POOL, G_TAIL - POOL_BASE, TAIL_WORD);

    /* the word the pool points at */
    w32(p + OFF_FLAG, 0u, sc->flag);

    /* the structure starts full of a pattern, so the bytes the function does
     * not write are visible */
    memset(p + OFF_STRUCT, 0x7eu, STRUCT_LEN);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = STRUCT_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;   r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_FLAG;   r->wins[1].base = FLAG_BASE;   r->wins[1].len = FLAG_LEN;
    r->wins[2].data = p + OFF_STRUCT; r->wins[2].base = STRUCT_BASE; r->wins[2].len = STRUCT_LEN;
    r->map.wins = r->wins;
    r->map.n = 3;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

static uint32_t word_at(const uint8_t *p, unsigned off)
{
    return (uint32_t)p[off + 0] | ((uint32_t)p[off + 1] << 8)
         | ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void w16(uint8_t *p, unsigned off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

/* The result, read straight off the fixture: the structure has to hold what
 * the function is supposed to put there, and the bytes past the end of it
 * have to keep the pattern they started with.  This does not consult the
 * generated translation, so it also catches a fixture that is not where the
 * guest looks. */
static int expected(const struct run *r, const struct scenario *sc,
                    const char **why)
{
    uint8_t want[STRUCT_LEN];
    const uint8_t *st = r->shadow + OFF_STRUCT;
    const int empty = (sc->flag == 0u);

    /* the pattern the structure started with */
    memset(want, 0x7eu, sizeof want);

    /* the first two words are zero */
    w32(want, 0u, 0u);
    w32(want, 4u, 0u);

    /* and the range's four words */
    w32(want, 8u, empty ? 0u : 0xffffffffu);
    w32(want, 12u, empty ? 0xffffffffu : 0u);
    w32(want, 16u, empty ? 0u : 0xffffffffu);
    w32(want, 20u, empty ? 0u : 0xffffffffu);

    /* the four halfwords are zero */
    for (unsigned off = 24u; off < 36u; off += 2u)
        w16(want, off, 0u);

    /* and the two words at the end */
    w32(want, 36u, TAIL_WORD);
    w32(want, 40u, 0u);

    if (memcmp(st, want, sizeof want)) {
        *why = "the structure";
        return 0;
    }
    return 1;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        for (unsigned i = 0; i < 54; ++i)
            if (a->state.v[i] != b->state.v[i])
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
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

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_range_init_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "range init: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "range init: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* and the result is checked against the fixture itself */
    const char *why = "";
    if (!expected(&ref, sc, &why)) {
        fprintf(stderr, "range init: %s: %s are wrong\n", sc->name, why);
        return 0;
    }
    /* and the T bit: the one of the test the guest branched on */
    const int expect_t = (sc->flag == 0u);
    if (((ref.state.v[17] & 1u) != 0) != expect_t) {
        fprintf(stderr, "range init: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, expect_t);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_range_init_entry) {
        fprintf(stderr, "range init: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the flag is zero: the range's first and third word are zero */
        { "zero",      0x00000000u },
        /* the flag is not: the first, the third and the fourth word are -1 */
        { "set",       0x00000001u },
        /* a negative flag is not zero either */
        { "negative",  0xffffffffu },
        /* a large flag is not zero either */
        { "large",     0x0000ffffu },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("range_init: %u differential cases - PASS\n", cases);
    return 0;
}
