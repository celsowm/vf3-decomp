/* record_match_replay.c - the readable record predicate against the retained
 * generated translation of SH-4 0x8C03772A.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation, for every answer the predicate can give.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The two helpers the predicate calls are entries no ported code owns, so
 * the test answers them through the dispatcher's "missing" hook: the first
 * one hands out a record, the second one fills the header on the stack and
 * answers a status.  What they answer is what makes every check in the
 * chain observable - without them the predicate would always fail the same
 * way.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_record_match_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define MATCH_ENTRY   0x0c03772au
#define RETURN_PC     0x0c0abcdeu

/* the two helpers, in the literal pool */
#define HELPER_A 0x0c0ff100u
#define HELPER_B 0x0c0ff104u

#define POOL_BASE   0x0c037780u
#define POOL_LEN    0x40u
#define G_EXPECTED  (POOL_BASE + 0x0eu)   /* the global halfword at 0x8C03778E */
#define G_FIRST     (POOL_BASE + 0x1cu)   /* the first helper  at 0x8C03779C */
#define G_SECOND    (POOL_BASE + 0x20u)   /* the second helper at 0x8C0377A0 */

#define STACK_BASE 0x0c100000u
#define STACK_LEN  0x10000u
#define RECORD_BASE 0x0c300000u
#define RECORD_LEN  0x100u

#define SP 0x0c108000u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK  0u
#define OFF_POOL   (OFF_STACK + STACK_LEN)
#define OFF_RECORD (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_RECORD + RECORD_LEN)

struct scenario {
    const char *name;
    uint32_t status;      /* the second helper's answer */
    uint32_t kind;        /* the record's first word */
    uint32_t hdr_first;   /* the header's words */
    uint32_t hdr_second;
    uint32_t hdr_third;
    uint8_t  flag_a;      /* the header's two flag bytes */
    uint8_t  flag_b;
    int expect;           /* the answer the predicate has to give */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[3];
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
static uint32_t hb_status;
static uint32_t hb_kind;
static uint32_t hb_first;
static uint32_t hb_second;
static uint32_t hb_third;
static uint8_t  hb_flag_a;
static uint8_t  hb_flag_b;

static int missing_hook(uint32_t entry, vf3_matrix_state *s,
                        const vf3_ram_map *ram, int *handled)
{
    if (entry == (HELPER_A & 0x1FFFFFFFu)) {
        /* the first helper hands out the record */
        s->v[0] = RECORD_BASE;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (HELPER_B & 0x1FFFFFFFu)) {
        /* the second helper fills the header and answers the status */
        const uint32_t header = s->v[4];
        vf3_matrix_write(ram, header + 0, hb_first, 2);
        vf3_matrix_write(ram, header + 2, hb_second, 2);
        vf3_matrix_write(ram, header + 4, hb_third, 2);
        vf3_matrix_write(ram, header + 6, hb_flag_a, 1);
        vf3_matrix_write(ram, header + 7, hb_flag_b, 1);
        s->v[0] = hb_status;
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

    /* the literal pool: the two helpers and the global halfword */
    w32(p + OFF_POOL, G_FIRST - POOL_BASE, HELPER_A);
    w32(p + OFF_POOL, G_SECOND - POOL_BASE, HELPER_B);
    w16(p + OFF_POOL, G_EXPECTED - POOL_BASE, 0x1234u);
    /* the record the first helper hands out */
    w32(p + OFF_RECORD, 0, sc->kind);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x0c310000u;        /* the object the first helper gets */
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK;  r->wins[0].base = STACK_BASE;  r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_POOL;   r->wins[1].base = POOL_BASE;   r->wins[1].len = POOL_LEN;
    r->wins[2].data = p + OFF_RECORD; r->wins[2].base = RECORD_BASE; r->wins[2].len = RECORD_LEN;
    r->map.wins = r->wins;
    r->map.n = 3;
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

    hb_status = sc->status;
    hb_kind = sc->kind;
    hb_first = sc->hdr_first;
    hb_second = sc->hdr_second;
    hb_third = sc->hdr_third;
    hb_flag_a = sc->flag_a;
    hb_flag_b = sc->flag_b;

    vf3_family_missing = missing_hook;

    const int ok_ref = vf3_matrix_family(MATCH_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_record_match_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(MATCH_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record match: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    if ((int)ref.state.v[0] != sc->expect) {
        fprintf(stderr, "record match: %s answered %u, expected %d\n",
                sc->name, ref.state.v[0], sc->expect);
        return 0;
    }
    /* the T flag says whether the chain of checks held */
    if (((ref.state.v[17] & 1u) != 0) != (sc->expect != 0)) {
        fprintf(stderr, "record match: %s left the T flag at %08x\n",
                sc->name, ref.state.v[17]);
        return 0;
    }
    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(MATCH_ENTRY);
    if (!reg || reg->fn != vf3_record_match_entry) {
        fprintf(stderr, "record match: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* everything the engine expects: the answer is 1 */
        { "match",     0,     14, 1, 0x1234, 1, 0, 0, 1 },
        /* the status is negative */
        { "status",    0xffffffffu, 14, 1, 0x1234, 1, 0, 0, 0 },
        /* the record is another kind */
        { "kind",      0,     13, 1, 0x1234, 1, 0, 0, 0 },
        /* the header's first word is another one */
        { "first",     0,     14, 2, 0x1234, 1, 0, 0, 0 },
        /* the header's second word is not the global */
        { "second",    0,     14, 1, 0x4321, 1, 0, 0, 0 },
        /* the header's third word is another one */
        { "third",     0,     14, 1, 0x1234, 2, 0, 0, 0 },
        /* the header's first flag byte is set */
        { "flag a",    0,     14, 1, 0x1234, 1, 1, 0, 0 },
        /* the header's second flag byte is set */
        { "flag b",    0,     14, 1, 0x1234, 1, 0, 1, 0 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("record_match: %u differential cases - PASS\n", cases);
    return 0;
}
