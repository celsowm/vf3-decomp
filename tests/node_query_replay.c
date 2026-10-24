/* node_query_replay.c - the readable node query against the retained
 * generated translation of SH-4 0x8C053CA4.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation, for every answer the query can give.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The query asks two handlers about the node, and both of them are entries
 * no ported code owns, so the test answers them through the dispatcher's
 * "missing" hook.  Each handler answers a pointer that depends on the node
 * it was given, so a getter that looked the wrong node up would read the
 * wrong status and the wrong flags.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_node_query_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define QUERY_ENTRY 0x0c053ca4u

/* the caller's return address, in the 0x8c mirror: the module of the query
 * writes its continuations with the code base it derives from it */
#define RETURN_PC   0x8c0abcdeu

/* the two entries no ported code owns */
#define FIRST_CALLEE  0x0c0ff140u
#define SECOND_CALLEE 0x0c0ff144u

/* the query's literal pool */
#define POOL_BASE  0x0c053d40u
#define POOL_LEN   0x20u
#define G_TABLE    (POOL_BASE + 0x04u)   /* the table of nodes  0x8C053D44 */
#define G_FIRST    (POOL_BASE + 0x08u)   /* the first handler   0x8C053D48 */
#define G_SECOND   (POOL_BASE + 0x0cu)   /* the second handler  0x8C053D4C */

#define STACK_BASE 0x0c100000u
#define STACK_LEN  0x10000u
#define DATA_BASE  0x0c300000u
#define DATA_LEN   0x400u

#define SP 0x0c108000u

/* the addresses inside the data window */
#define TABLE      (DATA_BASE + 0x000u)  /* the table: an entry per index */
#define NODE(i)    (DATA_BASE + 0x100u + (i) * 0x10u)  /* the node of index i */
#define STATUS(i)  (NODE(i) + 0x100u)     /* the status byte */
#define FLAGS(i)   (NODE(i) + 0x200u)     /* the flags word  */

/* where the handlers record the return address they were called with: the
 * continuation the module writes carries the mirror the run came through,
 * and a stub that records it makes that visible */
#define RET_FIRST  (DATA_BASE + 0x380u)
#define RET_SECOND (DATA_BASE + 0x384u)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK 0u
#define OFF_POOL  (OFF_STACK + STACK_LEN)
#define OFF_DATA  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

struct scenario {
    const char *name;
    uint32_t index;         /* the index the query is asked about */
    uint8_t status;         /* the status byte the first handler points at */
    uint32_t flags;         /* the flags the second handler points at */
    uint32_t expect;        /* the answer */
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

static int missing_hook(uint32_t entry, vf3_matrix_state *s,
                        const vf3_ram_map *ram, int *handled)
{
    if (entry == (FIRST_CALLEE & 0x1FFFFFFFu)) {
        /* the first handler: it answers a pointer to the status byte of the
         * node it was given, and records the return address it was called
         * with */
        vf3_matrix_write(ram, RET_FIRST, s->v[16], 4);
        s->v[0] = s->v[4] + 0x100u;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (SECOND_CALLEE & 0x1FFFFFFFu)) {
        /* the second handler: it answers a pointer to the flags of the node
         * it was given, and records the return address too */
        vf3_matrix_write(ram, RET_SECOND, s->v[16], 4);
        s->v[0] = s->v[4] + 0x200u;
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

    /* the query's pool */
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE);
    w32(p + OFF_POOL, G_FIRST - POOL_BASE, FIRST_CALLEE);
    w32(p + OFF_POOL, G_SECOND - POOL_BASE, SECOND_CALLEE);

    /* the table: an entry per index, and the node it points at */
    for (unsigned i = 0; i < 8; ++i)
        w32(p + OFF_DATA, (TABLE - DATA_BASE) + i * 4u, NODE(i));

    /* the status and the flags of the node the query asks about */
    p[OFF_DATA + (STATUS(sc->index) - DATA_BASE)] = sc->status;
    w32(p + OFF_DATA, FLAGS(sc->index) - DATA_BASE, sc->flags);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->index;
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK; r->wins[0].base = STACK_BASE; r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_POOL;  r->wins[1].base = POOL_BASE;  r->wins[1].len = POOL_LEN;
    r->wins[2].data = p + OFF_DATA;  r->wins[2].base = DATA_BASE;  r->wins[2].len = DATA_LEN;
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

    vf3_family_missing = missing_hook;

    const int ok_ref = vf3_matrix_family(QUERY_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_node_query_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(QUERY_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "node query: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    if (ref.state.v[0] != sc->expect) {
        fprintf(stderr, "node query: %s answered %08x, expected %08x\n",
                sc->name, ref.state.v[0], sc->expect);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(QUERY_ENTRY);
    if (!reg || reg->fn != vf3_node_query_entry) {
        fprintf(stderr, "node query: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the status is set and the flags carry the bit: the node is active */
        { "active",  3u, 1u,  0x00000002u, 1u },
        /* the status is set but the flag is missing: not active */
        { "noflag", 3u, 1u,  0x00000000u, 0u },
        /* the flag is there but the status is clear: not active */
        { "clear",  3u, 0u,  0x00000002u, 0u },
        /* the other bits of the flags do not matter */
        { "other",  5u, 0x80u, 0x00000006u, 1u },
        /* another node of the table */
        { "node1",  1u, 1u,  0x00000002u, 1u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("node_query: %u differential cases - PASS\n", cases);
    return 0;
}
