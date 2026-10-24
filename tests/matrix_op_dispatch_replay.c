/* matrix_op_dispatch_replay.c - the readable matrix-op dispatcher against the
 * retained generated translation of SH-4 0x8C035CE8.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation, for every node the dispatcher can meet: no node at all, a
 * node that names one of the matrix operations, and a node that names a
 * pointer no module owns.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The operation the node names is run by the chain in both runs, so the
 * operation's own effect (the FP registers, the matrix it writes) is part of
 * the comparison and not a free variable.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_matrix_op_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define DISPATCH_ENTRY 0x0c035ce8u
#define RETURN_PC      0x0c0abcdeu

/* the operations a node may name */
#define OP_IDENTITY 0x0c03ccb0u   /* matrix_identity */
#define OP_LOAD     0x0c03bd80u   /* matrix_load     */
#define OP_XFORM    0x0c03b450u   /* xform_point     */
#define OP_UNKNOWN  0x0c0ff0f0u   /* no module owns this one */

#define STACK_BASE   0x0c100000u
#define STACK_LEN    0x10000u
#define GLOBALS_BASE 0x0c035d60u
#define GLOBALS_LEN  0x10u
#define NODEPTR_BASE 0x0c300000u
#define NODEPTR_LEN  0x10u
#define NODE_BASE    0x0c310000u
#define NODE_LEN     0x100u
#define MATRIX_BASE  0x0c320000u
#define MATRIX_LEN   0x100u

/* the node's word with the operation's entry */
#define NODE_OP 0x50u

#define SP 0x0c108000u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK   0u
#define OFF_GLOBALS (OFF_STACK + STACK_LEN)
#define OFF_NODEPTR (OFF_GLOBALS + GLOBALS_LEN)
#define OFF_NODE    (OFF_NODEPTR + NODEPTR_LEN)
#define OFF_MATRIX  (OFF_NODE + NODE_LEN)
#define SHADOW_LEN  (OFF_MATRIX + MATRIX_LEN)

struct scenario {
    const char *name;
    uint32_t node;      /* the node behind the global, 0 for none */
    uint32_t op;        /* the operation the node names */
    int expect_ok;      /* whether the dispatch has to succeed */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[5];
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

    /* the global points at the node pointer */
    w32(p + OFF_GLOBALS, 0, NODEPTR_BASE);
    /* the node pointer */
    w32(p + OFF_NODEPTR, 0, sc->node);
    if (sc->node)
        w32(p + OFF_NODE, NODE_OP, sc->op);
    /* the matrix the operation works on: a rotation about z, so the
     * transform has no infinity and raises no FP exception */
    static const uint32_t m[16] = {
        0x3f800000u, 0x00000000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x3f800000u, 0x00000000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x3f800000u, 0x00000000u,
        0x00000000u, 0x00000000u, 0x00000000u, 0x3f800000u,
    };
    for (unsigned i = 0; i < 16; ++i)
        w32(p + OFF_MATRIX, i * 4u, m[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = MATRIX_BASE;          /* the matrix the operation works on */
    s->v[5] = MATRIX_BASE + 0x40u;  /* where the transform writes its point */
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;                   /* the FPSCR: the dispatcher refuses a bad one */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK;   r->wins[0].base = STACK_BASE;   r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_GLOBALS; r->wins[1].base = GLOBALS_BASE; r->wins[1].len = GLOBALS_LEN;
    r->wins[2].data = p + OFF_NODEPTR; r->wins[2].base = NODEPTR_BASE; r->wins[2].len = NODEPTR_LEN;
    r->wins[3].data = p + OFF_NODE;    r->wins[3].base = NODE_BASE;    r->wins[3].len = NODE_LEN;
    r->wins[4].data = p + OFF_MATRIX;  r->wins[4].base = MATRIX_BASE;  r->wins[4].len = MATRIX_LEN;
    r->map.wins = r->wins;
    r->map.n = 5;
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

    const int ok_ref = vf3_matrix_family(DISPATCH_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_matrix_op_dispatch_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(DISPATCH_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "matrix op dispatch: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    if (ok_ref != sc->expect_ok) {
        fprintf(stderr, "matrix op dispatch: %s returned %d, expected %d\n",
                sc->name, ok_ref, sc->expect_ok);
        return 0;
    }
    /* the dispatcher answers 0 for a node that is not there */
    if (!sc->node && ref.state.v[0] != 0u) {
        fprintf(stderr, "matrix op dispatch: %s answered r0 %08x\n",
                sc->name, ref.state.v[0]);
        return 0;
    }
    /* and the T flag says the node was missing */
    if (!sc->node && !(ref.state.v[17] & 1u)) {
        fprintf(stderr, "matrix op dispatch: %s did not set the T flag\n", sc->name);
        return 0;
    }
    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(DISPATCH_ENTRY);
    if (!reg || reg->fn != vf3_matrix_op_dispatch_entry) {
        fprintf(stderr, "matrix op dispatch: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* no node: there is no operation to run */
        { "no node",   0,          0,          1 },
        /* the node names the identity */
        { "identity",  NODE_BASE,  OP_IDENTITY, 1 },
        /* the node names the load of a matrix */
        { "load",      NODE_BASE,  OP_LOAD,     1 },
        /* the node names a transform of a point */
        { "xform",     NODE_BASE,  OP_XFORM,    1 },
        /* the node names a pointer no module owns: the jump fails */
        { "unknown",   NODE_BASE,  OP_UNKNOWN,  0 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("matrix_op_dispatch: %u differential cases - PASS\n", cases);
    return 0;
}
