/* uncached_call_replay.c - the readable uncached-mirror call (SH-4 0x8C011984)
 * against the retained generated translation.
 *
 * The function computes an entry point - a base plus an offset - forces it
 * into the 0xac mirror and calls it.  The callee is therefore not known at
 * compile time, so the test answers it with a **stub**: the stub leaves the
 * answer the scenario picked in r0 and comes back to the caller's return
 * address.
 *
 * Three arms:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it).
 *
 * All three compare the whole register file (the FP registers and SR
 * included), the exit PC, the failed PC, the out-of-window counter and every
 * RAM byte.
 *
 * The stack the fixture hands to the guest is filled with garbage, not
 * zeroes: the guest's private frame sits on it, so a store the port forgets
 * shows up in the result.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_uncached_call_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c011984u
#define RETURN_PC 0x0c0abcdeu

/* the literal pool the mirror mask lives in */
#define POOL_BASE   0x0c011000u
#define POOL_LEN    0x1000u
#define MIRROR_MASK (POOL_BASE + 0xa78u)

/* the stack */
#define STACK_BASE 0x0c100000u
#define STACK_LEN  0x10000u
#define STACK_TOP  0x0c108000u

#define NWIN 2
#define OFF_POOL  0u
#define OFF_STACK (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

/* the mirror the guest forces the entry point into */
#define UNCACHED 0xa0000000u

/* the stack below the top is not clean in the real game: the guest's private
 * frame sits on whatever the stack held before, so the fixture fills it with
 * garbage.  A port that forgets one of the guest's own stores into that frame
 * then reads the garbage instead, and the differential sees it. */
#define STACK_GARBAGE 0x41a0a0a0u

struct scenario {
    const char *name;
    uint32_t base;       /* r3: the base of the entry point */
    uint32_t offset;     /* r0: the offset added to it */
    uint32_t answer;     /* the r0 the callee leaves behind */
    uint32_t alias;      /* the mirror the run came through (0: none) */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
    uint32_t base[NWIN];
    uint32_t len[NWIN];
};

/* the scenario the stubs answer with */
static const struct scenario *current_scenario;

/* what the stub saw: the continuation it was handed, and the alias the
 * caller left behind.  Both are part of the contract - the continuation
 * carries the mirror the run came through, and the callee is told which
 * mirror it was jumped to. */
static uint32_t stub_return;
static uint32_t seen_alias;
static uint32_t seen_alias_pc;

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

/* the entry point the port computes, and the address the stub answers */
static uint32_t callee_of(const struct scenario *sc)
{
    return (sc->base + sc->offset) | UNCACHED;
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the stack: garbage, not zeroes - see STACK_GARBAGE */
    for (uint32_t off = 0; off < STACK_TOP - STACK_BASE; off += 4u)
        w32(p + OFF_STACK, off, STACK_GARBAGE);

    /* the literal pool: the mirror mask the guest reads */
    w32(p + OFF_POOL, MIRROR_MASK - POOL_BASE, UNCACHED);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;              /* sr, with the T bit set */
    s->v[18] = 0x00240001u;         /* fpscr */
    s->v[0] = sc->offset;
    s->v[3] = sc->base;
    s->budget = 1000000u;

    r->base[0] = POOL_BASE;   r->len[0] = POOL_LEN;
    r->base[1] = STACK_BASE;  r->len[1] = STACK_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : OFF_STACK);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

/* ---- the stub the callee is answered with ---- */
static int stub_callee(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                        int *handled, const struct scenario *sc)
{
    (void)ram;
    if (entry != (callee_of(sc) & 0x1fffffffu)) return 0;
    *handled = 1;
    stub_return = s->v[16];
    seen_alias = vf3_matrix_call_alias;
    seen_alias_pc = vf3_matrix_call_alias_pc;
    s->v[0] = sc->answer;
    s->pc = s->v[16];
    return 1;
}

static int hook_stub(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    return stub_callee(entry, s, ram, handled, current_scenario);
}

static int hook_readable(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                         int *handled)
{
    if (stub_callee(entry, s, ram, handled, current_scenario)) return 1;
    if (*handled) return 1;
    return vf3_readable_override(entry, s, ram, handled);
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

static unsigned cases;

/* The arm starts with a clean slate: a stub that is never reached must not
 * leave the previous arm's observation behind. */
static void arm_begin(uint32_t alias)
{
    stub_return = 0xdeadbeefu;
    seen_alias = 0xdeadbeefu;
    seen_alias_pc = 0xdeadbeefu;
    vf3_matrix_call_alias = 0u;
    vf3_matrix_call_alias_pc = 0xffffffffu;
    if (alias) {
        vf3_matrix_call_alias = alias;
        vf3_matrix_call_alias_pc = ENTRY & 0x1fffffffu;
    }
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    current_scenario = sc;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    /* the mirror the run came through, when the caller left one */
    const uint32_t alias = sc->alias;

    arm_begin(alias);
    vf3_family_override = hook_stub;
    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const uint32_t ret_ref = stub_return;
    const uint32_t alias_ref = seen_alias, alias_pc_ref = seen_alias_pc;

    arm_begin(alias);
    const int ok_port = vf3_uncached_call_entry(&port.state, &port.map);
    const uint32_t ret_port = stub_return;
    const uint32_t alias_port = seen_alias, alias_pc_port = seen_alias_pc;

    int handled = 0;
    arm_begin(alias);
    vf3_family_override = hook_readable;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map, &handled);
    const uint32_t ret_hook = stub_return;
    const uint32_t alias_hook = seen_alias, alias_pc_hook = seen_alias_pc;
    vf3_family_override = NULL;

    /* the continuation the callee was handed carries the mirror the run came
     * through, and the callee is told which mirror it was jumped to */
    if (ret_ref != ret_port || ret_ref != ret_hook) {
        fprintf(stderr, "uncached call: %s: the continuation %08x/%08x/%08x\n",
                sc->name, ret_ref, ret_port, ret_hook);
        return 0;
    }
    if (alias_ref != alias_port || alias_ref != alias_hook ||
        alias_pc_ref != alias_pc_port || alias_pc_ref != alias_pc_hook) {
        fprintf(stderr, "uncached call: %s: the alias %08x/%08x/%08x pc %08x/%08x/%08x\n",
                sc->name, alias_ref, alias_port, alias_hook,
                alias_pc_ref, alias_pc_port, alias_pc_hook);
        return 0;
    }

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "uncached call: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "uncached call: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the answer itself: one when the callee left a non-zero r0 */
    {
        const uint32_t want = sc->answer ? 1u : 0u;
        if (ref.state.v[0] != want) {
            fprintf(stderr, "uncached call: %s: the answer is %u, expected %u\n",
                    sc->name, ref.state.v[0], want);
            return 0;
        }
        /* the T bit ends up set when the answer is zero */
        const uint32_t t = ref.state.v[17] & 1u;
        if (t != (want ? 0u : 1u)) {
            fprintf(stderr, "uncached call: %s: the T bit is %u\n", sc->name, t);
            return 0;
        }
        /* the base plus the offset, and the mirror mask */
        if (ref.state.v[3] != sc->base + sc->offset) {
            fprintf(stderr, "uncached call: %s: r3 is %08x, expected %08x\n",
                    sc->name, ref.state.v[3], sc->base + sc->offset);
            return 0;
        }
        if (ref.state.v[2] != UNCACHED) {
            fprintf(stderr, "uncached call: %s: r2 is %08x, expected %08x\n",
                    sc->name, ref.state.v[2], UNCACHED);
            return 0;
        }
        /* the stack is where it was, and the pr is the caller's */
        if (ref.state.v[15] != STACK_TOP || ref.state.v[16] != RETURN_PC) {
            fprintf(stderr, "uncached call: %s: sp %08x pr %08x\n",
                    sc->name, ref.state.v[15], ref.state.v[16]);
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
    if (!reg || reg->fn != vf3_uncached_call_entry) {
        fprintf(stderr, "uncached call: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "the callee answers zero", .base = 0x0c012000u, .offset = 0u,
          .answer = 0u },
        { .name = "the callee answers one", .base = 0x0c012000u, .offset = 0u,
          .answer = 1u },
        { .name = "the callee answers a word", .base = 0x0c012000u, .offset = 0u,
          .answer = 0x12345678u },
        { .name = "the entry point has an offset", .base = 0x0c012000u,
          .offset = 0x10u, .answer = 0u },
        { .name = "the entry point has an offset and an answer",
          .base = 0x0c012000u, .offset = 0x10u, .answer = 7u },
        { .name = "the base is already in the mirror", .base = 0x8c012000u,
          .offset = 0u, .answer = 3u },
        { .name = "the run came through the uncached mirror",
          .base = 0x0c012000u, .offset = 0u, .answer = 5u, .alias = 0xac000000u },
        { .name = "the run came through the cached mirror",
          .base = 0x0c012000u, .offset = 0u, .answer = 5u, .alias = 0x8c000000u },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    /* the two answers have to be exercised */
    {
        unsigned zero = 0, nonzero = 0;
        for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i) {
            if (scenarios[i].answer) ++nonzero; else ++zero;
        }
        if (!zero || !nonzero) {
            fprintf(stderr, "uncached call: the scenarios do not cover both answers\n");
            return 1;
        }
    }

    printf("uncached_call: %u differential cases - PASS\n", cases);
    return 0;
}
