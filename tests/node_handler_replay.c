/* node_handler_replay.c - the readable node handler against the retained
 * generated translation of SH-4 0x8C0AB870.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The handler is an entry no ported code owns, so the test answers it
 * through the dispatcher's "missing" hook.  The handler reads the frame it
 * was given and answers a mix of its words, so a port that built the frame
 * in the wrong order would answer something else and the test would say so.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_node_handler_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define HANDLER_ENTRY 0x0c0ab870u

/* the caller's return address */
#define RETURN_PC   0x0c0abcdeu

/* the entry no ported code owns */
#define HANDLER 0x0c0ff150u

/* the function's literal pool */
#define POOL_BASE  0x0c0ab990u
#define POOL_LEN   0x20u
#define G_OFFSET   (POOL_BASE + 0x00u)   /* the object's float offset */
#define G_TABLE    (POOL_BASE + 0x10u)   /* the table of handlers      */

#define STACK_BASE 0x0c100000u
#define STACK_LEN  0x10000u
#define DATA_BASE  0x0c300000u
#define DATA_LEN   0x200u

#define SP 0x0c108000u

/* the addresses inside the data window */
#define OBJECT   (DATA_BASE + 0x000u)   /* the object: r4 */
#define NODE     (DATA_BASE + 0x080u)   /* the node: r6 */
#define TABLE    (DATA_BASE + 0x100u)   /* the table of handlers */

/* the object's float sits at the object plus the pool's offset */
#define FLOAT_OFFSET 0x40u
#define FLOAT_AT (OBJECT + FLOAT_OFFSET)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK 0u
#define OFF_POOL  (OFF_STACK + STACK_LEN)
#define OFF_DATA  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

struct scenario {
    const char *name;
    uint32_t object_word;   /* the object's first word */
    uint32_t node_word;     /* the node's first word */
    uint32_t node_index;    /* the node's second word: the handler's index */
    uint32_t object_float;  /* the float that belongs to the object */
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
    if (entry == (HANDLER & 0x1FFFFFFFu)) {
        /* the handler: r5 points at the frame's arguments - the object's
         * first word, the node's two words and the float.  The answer mixes
         * them, so a frame in the wrong order answers something else. */
        const uint32_t frame = s->v[5];
        uint32_t mix = 0u;
        for (unsigned i = 0; i < 4; ++i)
            mix ^= vf3_matrix_read(ram, frame + i * 4u, 4) << i;
        s->v[0] = mix;
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

    /* the function's pool */
    w16(p + OFF_POOL, G_OFFSET - POOL_BASE, (uint16_t)FLOAT_OFFSET);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE);

    /* the object, the node and the handler table */
    w32(p + OFF_DATA, OBJECT - DATA_BASE, sc->object_word);
    w32(p + OFF_DATA, FLOAT_AT - DATA_BASE, sc->object_float);
    w32(p + OFF_DATA, NODE - DATA_BASE, sc->node_word);
    w32(p + OFF_DATA, (NODE + 4u) - DATA_BASE, sc->node_index);
    w32(p + OFF_DATA, (TABLE + sc->node_index * 4u) - DATA_BASE, HANDLER);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJECT;
    s->v[6] = NODE;
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

    const int ok_ref = vf3_matrix_family(HANDLER_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_node_handler_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(HANDLER_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "node handler: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    /* the answer is the handler's: a mix of the frame's words */
    const uint32_t expect = sc->object_word ^ (sc->node_word << 1) ^
                            (sc->node_index << 2) ^ (sc->object_float << 3);
    if (ref.state.v[0] != expect) {
        fprintf(stderr, "node handler: %s answered %08x, expected %08x\n",
                sc->name, ref.state.v[0], expect);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(HANDLER_ENTRY);
    if (!reg || reg->fn != vf3_node_handler_entry) {
        fprintf(stderr, "node handler: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        { "plain",  0x11111111u, 0x22222222u, 0u, 0x3f800000u },
        { "index",  0x11111111u, 0x22222222u, 3u, 0x3f800000u },
        { "float",  0x11111111u, 0x22222222u, 0u, 0x40000000u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("node_handler: %u differential cases - PASS\n", cases);
    return 0;
}
