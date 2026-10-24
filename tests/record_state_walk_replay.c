/* record_state_walk_replay.c - the readable record walk against the retained
 * generated translation of SH-4 0x8C03550C.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port
 * has to leave the same registers, the same RAM and the same return address
 * as that translation in every branch of the walk: the empty record, the
 * finished walk, the two value codes, the unknown code, the step limit and
 * the node callback.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The callback is a call into an entry no ported code owns, so the test
 * answers it through the dispatcher's "missing" hook.  It advances the walk
 * cursor and may set the record's code, which is what makes the callback
 * observable: without it the walk would spin on the same cursor.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_record_state_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_record_state_get_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define WALK_ENTRY     0x0c03550cu
#define GETTER_ENTRY   0x0c035a20u
#define CALLBACK_ENTRY 0x0c0ff0f0u
#define RETURN_PC      0x0c0abcdeu

#define STACK_BASE   0x0c100000u
#define STACK_LEN    0x10000u
#define NODE_BASE    0x0c200000u
#define NODE_LEN     0x100u
#define VTABLE_BASE  0x0c210000u
#define VTABLE_LEN   0x40u
#define CURSOR_BASE  0x0c220000u
#define CURSOR_LEN   0x40u
#define GLOBALS_BASE 0x0c0355e0u
#define GLOBALS_LEN  0x20u

#define G_LIMIT    (GLOBALS_BASE + 4u)
#define G_CURSOR   (GLOBALS_BASE + 8u)
#define G_CALLBACK (GLOBALS_BASE + 12u)

#define NODE_VTABLE 0u
#define NODE_CURSOR 24u
#define NODE_FLAG   0x48u
#define NODE_CODE   0x4cu
#define NODE_VALUE  0x4eu
#define VTABLE_KIND 36u

#define SP 0x0c108000u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK   0u
#define OFF_NODE    (OFF_STACK + STACK_LEN)
#define OFF_VTABLE  (OFF_NODE + NODE_LEN)
#define OFF_CURSOR  (OFF_VTABLE + VTABLE_LEN)
#define OFF_GLOBALS (OFF_CURSOR + CURSOR_LEN)
#define SHADOW_LEN  (OFF_GLOBALS + GLOBALS_LEN)

/* what the fake node callback does */
static uint32_t cb_step;          /* how far it advances the walk cursor */
static uint32_t cb_code_first;    /* the code it writes on the first call */
static uint32_t cb_code_then;     /* the code it writes on the later calls */
static uint32_t cb_node_cursor;   /* the node word at +24 it writes */
static int cb_set_code;           /* whether it writes the code at all */
static int cb_set_node_cursor;    /* whether it moves the node */
static unsigned cb_calls;         /* how often it ran */

static int missing_hook(uint32_t entry, vf3_matrix_state *s,
                        const vf3_ram_map *ram, int *handled)
{
    if (entry != CALLBACK_ENTRY) { *handled = 0; return 0; }
    ++cb_calls;
    const uint32_t cur = vf3_matrix_read(ram, CURSOR_BASE, 4);
    vf3_matrix_write(ram, CURSOR_BASE, cur + cb_step, 4);
    if (cb_set_code)
        vf3_matrix_write(ram, NODE_BASE + NODE_CODE,
                         cb_calls == 1 ? cb_code_first : cb_code_then, 2);
    if (cb_set_node_cursor)
        vf3_matrix_write(ram, NODE_BASE + NODE_CURSOR, cb_node_cursor, 4);
    s->v[0] = 0;
    s->pc = s->v[16];
    *handled = 1;
    return 1;
}

struct scenario {
    const char *name;
    uint32_t kind;        /* the vtable's slot 9 */
    uint32_t flag;        /* the record's flag halfword */
    uint32_t code;        /* the record's code halfword */
    uint32_t value;       /* the record's value halfword */
    uint32_t limit;       /* the step limit */
    uint32_t cursor;      /* the cursor position */
    uint32_t node_cursor; /* the record's word at +24 */
    uint32_t cb_step;     /* the callback's cursor step */
    uint32_t cb_code_first;
    uint32_t cb_code_then;
    uint32_t cb_node_cursor;
    int cb_set_code;
    int cb_set_node_cursor;
    int cb_expected;      /* how often the callback has to run */
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

static void w16(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the record */
    w32(p + OFF_NODE, NODE_VTABLE, VTABLE_BASE);
    w32(p + OFF_NODE, NODE_CURSOR, sc->node_cursor);
    w16(p + OFF_NODE, NODE_FLAG, sc->flag);
    w16(p + OFF_NODE, NODE_CODE, sc->code);
    w16(p + OFF_NODE, NODE_VALUE, sc->value);
    /* the vtable */
    w32(p + OFF_VTABLE, VTABLE_KIND, sc->kind);
    /* the cursor */
    w32(p + OFF_CURSOR, 0, sc->cursor);
    /* the globals */
    w16(p + OFF_GLOBALS, 4, sc->limit);
    w32(p + OFF_GLOBALS, 8, CURSOR_BASE);
    w32(p + OFF_GLOBALS, 12, CALLBACK_ENTRY);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = NODE_BASE;
    s->v[5] = 0x11112222u;
    s->v[6] = 0x33334444u;
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;                /* the FPSCR: the dispatcher refuses a bad one */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK;   r->wins[0].base = STACK_BASE;   r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_NODE;    r->wins[1].base = NODE_BASE;    r->wins[1].len = NODE_LEN;
    r->wins[2].data = p + OFF_VTABLE;  r->wins[2].base = VTABLE_BASE;  r->wins[2].len = VTABLE_LEN;
    r->wins[3].data = p + OFF_CURSOR;  r->wins[3].base = CURSOR_BASE;  r->wins[3].len = CURSOR_LEN;
    r->wins[4].data = p + OFF_GLOBALS; r->wins[4].base = GLOBALS_BASE; r->wins[4].len = GLOBALS_LEN;
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
                fprintf(stderr, "  %s: r%u %08x != %08x\n", what, i,
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

    cb_step = sc->cb_step;
    cb_code_first = sc->cb_code_first;
    cb_code_then = sc->cb_code_then;
    cb_node_cursor = sc->cb_node_cursor;
    cb_set_code = sc->cb_set_code;
    cb_set_node_cursor = sc->cb_set_node_cursor;

    vf3_family_missing = missing_hook;

    cb_calls = 0;
    const int ok_ref = vf3_matrix_family(WALK_ENTRY, &ref.state, &ref.map);
    const unsigned calls_ref = cb_calls;

    cb_calls = 0;
    const int ok_port = vf3_record_state_walk_entry(&port.state, &port.map);
    const unsigned calls_port = cb_calls;

    int handled = 0;
    cb_calls = 0;
    const int ok_hook = vf3_readable_override(WALK_ENTRY, &hook.state, &hook.map, &handled);
    const unsigned calls_hook = cb_calls;

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        calls_ref != calls_port || calls_ref != calls_hook ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record walk: %s differs (ok %d/%d/%d calls %u/%u/%u)\n",
                sc->name, ok_ref, ok_port, ok_hook, calls_ref, calls_port, calls_hook);
        return 0;
    }
    if (calls_ref != (unsigned)sc->cb_expected) {
        fprintf(stderr, "record walk: %s called the callback %u times, expected %d\n",
                sc->name, calls_ref, sc->cb_expected);
        return 0;
    }
    ++cases;
    return 1;
}

/* the state getter on its own: a null record, a record without a flag and a
 * record that carries a code */
static int compare_getter(const char *name, uint32_t record, uint32_t flag,
                          uint32_t code, int has_flag)
{
    struct run ref, port, hook;
    struct scenario sc;
    memset(&sc, 0, sizeof sc);
    sc.flag = flag;
    sc.code = code;
    sc.cursor = 0x100;
    setup(&ref, &sc);
    setup(&port, &sc);
    setup(&hook, &sc);
    for (unsigned k = 0; k < 3; ++k) {
        struct run *r = k == 0 ? &ref : (k == 1 ? &port : &hook);
        r->state.v[4] = record;
        if (has_flag) {
            w16(r->shadow + OFF_NODE, NODE_FLAG, flag);
            w16(r->shadow + OFF_NODE, NODE_CODE, code);
        }
    }

    vf3_family_missing = missing_hook;

    cb_calls = 0;
    const int ok_ref = vf3_matrix_family(GETTER_ENTRY, &ref.state, &ref.map);
    cb_calls = 0;
    const int ok_port = vf3_record_state_get_entry(&port.state, &port.map);
    int handled = 0;
    cb_calls = 0;
    const int ok_hook = vf3_readable_override(GETTER_ENTRY, &hook.state, &hook.map, &handled);
    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record getter: %s differs (ok %d/%d/%d)\n",
                name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(WALK_ENTRY);
    if (!reg || reg->fn != vf3_record_state_walk_entry) {
        fprintf(stderr, "record walk: the port is not registered\n");
        return 1;
    }
    const vf3_readable_entry *reg_get = vf3_readable_find(GETTER_ENTRY);
    if (!reg_get || reg_get->fn != vf3_record_state_get_entry) {
        fprintf(stderr, "record walk: the getter is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the record is empty: -32 */
        { "empty",      1, 1, 0, 0, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        /* the walk is finished: 0 */
        { "done",       1, 1, 1, 0, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        /* the node holds a value */
        { "value5",     1, 1, 5, 0x1234, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        { "value6",     1, 1, 6, 0xfff0, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        /* a code the walk does not know: -25 */
        { "unknown",    1, 1, 7, 0, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        /* the flag is clear, so the getter answers -10: -25 */
        { "noflag",     1, 0, 5, 0x1234, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 1 },
        /* kind 2 asks for no callback at all */
        { "nocallback", 2, 1, 5, 0x4321, 64, 0x100, 0x40, 0, 0, 0, 0, 0, 0, 0 },
        /* the callback's step is already past the limit: -21 */
        { "stepover",   1, 1, 2, 0, 4, 0x100, 0x40, 8, 0, 0, 0, 0, 0, 1 },
        /* the callback advances the cursor until the step runs past the limit */
        { "walk",       1, 1, 2, 0, 4, 0x100, 0x40, 1, 0, 0, 0, 0, 0, 5 },
        /* the callback gives the record a value: the walk returns it */
        { "walkvalue",  1, 1, 2, 0x4321, 64, 0x100, 0x40, 1, 5, 5, 0, 1, 0, 1 },
        /* the callback moves the node, so the previous position follows the
         * cursor and the step restarts */
        { "movenode",   1, 1, 2, 0x4321, 64, 0x100, 0x40, 1, 2, 5, 0x50, 1, 1, 2 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    if (!compare_getter("null record", 0, 0, 0, 0)) return 1;
    if (!compare_getter("no flag", NODE_BASE, 0, 5, 0)) return 1;
    if (!compare_getter("code 5", NODE_BASE, 1, 5, 1)) return 1;
    if (!compare_getter("code -3", NODE_BASE, 1, 0xfffd, 1)) return 1;
    if (!compare_getter("code 0", NODE_BASE, 1, 0, 1)) return 1;
    printf("record_state_walk: %u differential cases - PASS\n", cases);
    return 0;
}
