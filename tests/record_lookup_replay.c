/* record_lookup_replay.c - the readable record lookup against the retained
 * generated translation of SH-4 0x8C037788.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation, for every answer the lookup can give.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The lookup asks the record predicate and the table's getter, and both of
 * them are entries no ported code owns, so the test answers them through the
 * dispatcher's "missing" hook: the predicate's two helpers and the getter.
 * What they answer is what makes the three answers of the lookup observable.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_record_lookup_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define LOOKUP_ENTRY 0x0c037788u
#define RETURN_PC   0x0c0abcdeu

/* the three helpers, all of them in the literal pool */
#define HELPER_A 0x0c0ff100u   /* the predicate's first helper  */
#define HELPER_B 0x0c0ff104u   /* the predicate's second helper */
#define GETTER   0x0c0ff108u   /* the table's getter            */

#define POOL_BASE   0x0c037780u
#define POOL_LEN    0x40u
#define G_EXPECTED  (POOL_BASE + 0x0eu)   /* the global halfword at 0x8C03778E */
#define G_GETTER    (POOL_BASE + 0x18u)   /* the getter      at 0x8C037798 */
#define G_FIRST     (POOL_BASE + 0x1cu)   /* the first helper at 0x8C03779C */
#define G_SECOND    (POOL_BASE + 0x20u)   /* the second helper at 0x8C0377A0 */
#define G_TABLE     (POOL_BASE + 0x24u)   /* the table       at 0x8C0377A4 */

#define STACK_BASE  0x0c100000u
#define STACK_LEN   0x10000u
#define TABLE_BASE  0x0c300000u
#define TABLE_LEN   0x100u
#define RECORD_BASE 0x0c310000u
#define RECORD_LEN  0x100u

#define SP 0x0c108000u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK  0u
#define OFF_POOL   (OFF_STACK + STACK_LEN)
#define OFF_TABLE  (OFF_POOL + POOL_LEN)
#define OFF_RECORD (OFF_TABLE + TABLE_LEN)
#define SHADOW_LEN (OFF_RECORD + RECORD_LEN)

struct scenario {
    const char *name;
    uint32_t kind;        /* the record's first word */
    int predicate_fits;   /* whether the header the helper writes fits */
    uint32_t answer;      /* what the getter answers */
    int expect_found;     /* whether the lookup has to find the record */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[4];
    vf3_ram_map map;
};

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

/* what the helpers answer in this run */
static uint32_t hb_kind;
static int hb_fits;
static uint32_t hb_answer;

static int missing_hook(uint32_t entry, vf3_matrix_state *s,
                        const vf3_ram_map *ram, int *handled)
{
    if (entry == (HELPER_A & 0x1FFFFFFFu)) {
        /* the predicate's first helper hands out the record */
        s->v[0] = RECORD_BASE;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (HELPER_B & 0x1FFFFFFFu)) {
        /* the predicate's second helper fills the header and answers the
         * status */
        const uint32_t header = s->v[4];
        vf3_matrix_write(ram, header + 0, hb_fits ? 1u : 2u, 2);
        vf3_matrix_write(ram, header + 2, 0x1234u, 2);
        vf3_matrix_write(ram, header + 4, 1u, 2);
        vf3_matrix_write(ram, header + 6, 0u, 1);
        vf3_matrix_write(ram, header + 7, 0u, 1);
        s->v[0] = hb_fits ? 0u : 0xffffffffu;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (GETTER & 0x1FFFFFFFu)) {
        /* the table's getter answers the record */
        s->v[0] = hb_answer;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    *handled = 0;
    return 0;
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool: the three helpers and the table */
    w32(p + OFF_POOL, G_GETTER - POOL_BASE, GETTER);
    w32(p + OFF_POOL, G_FIRST - POOL_BASE, HELPER_A);
    w32(p + OFF_POOL, G_SECOND - POOL_BASE, HELPER_B);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE_BASE);
    w16(p + OFF_POOL, G_EXPECTED - POOL_BASE, 0x1234u);
    /* the record the first helper hands out */
    w32(p + OFF_RECORD, 0, sc->kind);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK;  r->wins[0].base = STACK_BASE;  r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_POOL;   r->wins[1].base = POOL_BASE;   r->wins[1].len = POOL_LEN;
    r->wins[2].data = p + OFF_TABLE;  r->wins[2].base = TABLE_BASE;  r->wins[2].len = TABLE_LEN;
    r->wins[3].data = p + OFF_RECORD; r->wins[3].base = RECORD_BASE; r->wins[3].len = RECORD_LEN;
    r->map.wins = r->wins;
    r->map.n = 4;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

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

    hb_kind = sc->kind;
    hb_fits = sc->predicate_fits;
    hb_answer = sc->answer;

    vf3_family_missing = missing_hook;

    const int ok_ref = vf3_matrix_family(LOOKUP_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_record_lookup_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(LOOKUP_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record lookup: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* the lookup answers 0 when it found the record and -1 when it did not */
    const uint32_t expect = sc->expect_found ? 0u : 0xffffffffu;
    if (ref.state.v[0] != expect) {
        fprintf(stderr, "record lookup: %s answered %08x, expected %08x\n",
                sc->name, ref.state.v[0], expect);
        return 0;
    }
    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(LOOKUP_ENTRY);
    if (!reg || reg->fn != vf3_record_lookup_entry) {
        fprintf(stderr, "record lookup: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the predicate says the record does not fit: -1 */
        { "not found", 14, 0, RECORD_BASE, 0 },
        /* the record fits and the getter answers it: 0 */
        { "found",     14, 1, RECORD_BASE, 1 },
        /* the getter has nothing either: its answer is the answer */
        { "negative",  14, 1, 0xffffffffu, 0 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("record_lookup: %u differential cases - PASS\n", cases);
    return 0;
}
