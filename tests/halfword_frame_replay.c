/* halfword_frame_replay.c - the readable halfword frame against the
 * retained generated translation of SH-4 0x8C09D4B0.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The first two handlers are entries no ported code owns, so the test
 * answers them through the dispatcher's "missing" hook.  Each of them reads
 * the value it was given and answers a mix of it and the frame, so a port
 * that built the frame in the wrong order would hand the handlers something
 * else.
 *
 * The third one is a tail transfer, and the translation reaches it through
 * the switch of the eighteen matrix operations - so the test uses one of
 * them (matrix_identity, which needs no memory) as the third target.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_halfword_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c09d4b0u

/* the caller's return address */
#define RETURN_PC   0x0c0abcdeu

/* the entries no ported code owns */
#define FIRST_CALLEE  0x0c0ff160u
#define SECOND_CALLEE 0x0c0ff164u

/* the third target: one of the eighteen matrix operations, so the
 * translation's switch can serve it */
#define THIRD_TARGET 0x0c03ccb0u   /* matrix_identity */

/* the function's literal pool */
#define POOL_BASE  0x0c09d580u
#define POOL_LEN   0x10u
#define G_FIRST    (POOL_BASE + 0x00u)
#define G_SECOND   (POOL_BASE + 0x04u)
#define G_THIRD    (POOL_BASE + 0x08u)

#define STACK_BASE 0x0c100000u
#define STACK_LEN  0x10000u
#define DATA_BASE  0x0c300000u
#define DATA_LEN   0x100u

#define SP 0x0c108000u

/* the object: three halfwords */
#define OBJECT (DATA_BASE + 0x000u)

/* where the handlers record the value they were given: the frame is on the
 * caller's stack and the handlers cannot see it, so the value has to be
 * recorded to be compared */
#define GOT_FIRST  (DATA_BASE + 0x040u)
#define GOT_SECOND (DATA_BASE + 0x044u)

/* where the handlers record the return address they were called with: a stub
 * that just answers would hide the continuation, because it returns to pr and
 * the port that ignored the continuation would come back to the same place */
#define GOT_RET1 (DATA_BASE + 0x048u)
#define GOT_RET2 (DATA_BASE + 0x04cu)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK 0u
#define OFF_POOL  (OFF_STACK + STACK_LEN)
#define OFF_DATA  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

struct scenario {
    const char *name;
    uint32_t argument;       /* r5 */
    uint16_t object[3];      /* the object's three halfwords */
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
        /* the first handler: it records the value it was given and the return
         * address it was called with */
        vf3_matrix_write(ram, GOT_FIRST, s->v[4], 4);
        vf3_matrix_write(ram, GOT_RET1, s->v[16], 4);
        s->v[0] = s->v[4];
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (SECOND_CALLEE & 0x1FFFFFFFu)) {
        /* the second handler: the same */
        vf3_matrix_write(ram, GOT_SECOND, s->v[4], 4);
        vf3_matrix_write(ram, GOT_RET2, s->v[16], 4);
        s->v[0] = s->v[4];
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
    w32(p + OFF_POOL, G_FIRST - POOL_BASE, FIRST_CALLEE);
    w32(p + OFF_POOL, G_SECOND - POOL_BASE, SECOND_CALLEE);
    w32(p + OFF_POOL, G_THIRD - POOL_BASE, THIRD_TARGET);

    /* the object: three halfwords */
    for (unsigned i = 0; i < 3; ++i)
        w16(p + OFF_DATA, (OBJECT - DATA_BASE) + i * 2u, sc->object[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJECT;
    s->v[5] = sc->argument;
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

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_halfword_frame_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "halfword frame: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_halfword_frame_entry) {
        fprintf(stderr, "halfword frame: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        { "plain",    0x00000010u, { 0x1111u, 0x2222u, 0x3333u } },
        { "argument", 0x00000020u, { 0x4444u, 0x5555u, 0x6666u } },
        /* a negative argument: the frame keeps it as a halfword */
        { "negative", 0xfffffff0u, { 0x7777u, 0x8888u, 0x9999u } },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("halfword_frame: %u differential cases - PASS\n", cases);
    return 0;
}
