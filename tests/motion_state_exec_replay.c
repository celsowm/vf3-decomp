/* motion_state_exec_replay.c - the readable motion state exec (SH-4 0x8C0357BC)
 * against the retained generated translation.
 *
 * The function is a state machine:
 *   1. Saves r14 and r16 to the stack
 *   2. Loads state values from the guest memory at r4
 *   3. Performs comparisons and conditional branches
 *   4. Makes an indirect call through the router
 *   5. Writes results back to the state structure
 *
 * Three arms:
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override.
 *
 * All three compare the whole register file, the exit PC, the failed PC,
 * the out-of-window counter and every RAM byte.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_motion_state_exec_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c0357bcu
#define RETURN_PC 0x0c0abcdeu

/* the state structure */
#define STATE_BASE  0x0c100000u
#define STATE_LEN   0x1000u

/* the stack */
#define STACK_BASE  0x0c200000u
#define STACK_LEN   0x10000u
#define STACK_TOP   0x0c208000u

#define NWIN 2
#define OFF_STATE 0u
#define OFF_STACK (OFF_STATE + STATE_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t state_ptr;
    int expect_tail_call;
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
    uint32_t base[NWIN];
    uint32_t len[NWIN];
};

static const struct scenario *current_scenario;

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void build_fixture(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof(*r));

    r->base[0] = STATE_BASE;
    r->len[0] = STATE_LEN;
    r->wins[0].base = r->base[0];
    r->wins[0].len = r->len[0];
    r->wins[0].data = r->shadow + OFF_STATE;

    r->base[1] = STACK_BASE;
    r->len[1] = STACK_LEN;
    r->wins[1].base = r->base[1];
    r->wins[1].len = r->len[1];
    r->wins[1].data = r->shadow + OFF_STACK;

    r->map.nwin = NWIN;
    r->map.wins = r->wins;

    r->state.v[4] = sc->state_ptr;
    if (sc->state_ptr != 0)
        w32(r->shadow, OFF_STATE + (sc->state_ptr - STATE_BASE),
            STATE_BASE + 0x100u);
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.v[18] = 0x00040001u;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    vf3_matrix_call_alias = 0;
    vf3_matrix_call_alias_pc = 0xffffffffu;
}

static int run_generated(struct run *r)
{
    r->state.v[4] = current_scenario->state_ptr;
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    r->map.oob = 0;
    return vf3_matrix_family(ENTRY, &r->state, &r->map);
}

static int run_readable_direct(struct run *r)
{
    r->state.v[4] = current_scenario->state_ptr;
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    r->map.oob = 0;
    return vf3_motion_state_exec_entry(&r->state, &r->map);
}

static int run_readable_hook(struct run *r)
{
    r->state.v[4] = current_scenario->state_ptr;
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    r->map.oob = 0;
    int handled = 0;
    return vf3_readable_override(ENTRY, &r->state, &r->map, &handled);
}

static int cmp_state(const vf3_matrix_state *a, const vf3_matrix_state *b,
                     const char *label)
{
    for (int i = 0; i < 64; ++i) {
        if (a->v[i] != b->v[i]) {
            fprintf(stderr, "motion_state_exec: %s: r[%d] differ: %08x vs %08x\n",
                    label, i, a->v[i], b->v[i]);
            return 0;
        }
    }
    if (a->pc != b->pc) {
        fprintf(stderr, "motion_state_exec: %s: pc differ: %08x vs %08x\n",
                label, a->pc, b->pc);
        return 0;
    }
    if (a->failed_pc != b->failed_pc) {
        fprintf(stderr, "motion_state_exec: %s: failed_pc differ: %08x vs %08x\n",
                label, a->failed_pc, b->failed_pc);
        return 0;
    }
    return 1;
}

static int cmp_ram(const vf3_ram_map *a, const vf3_ram_map *b,
                   const char *label)
{
    if (a->oob != b->oob) {
        fprintf(stderr, "motion_state_exec: %s: oob differ: %u vs %u\n",
                label, a->oob, b->oob);
        return 0;
    }
    for (unsigned i = 0; i < a->nwin; ++i) {
        if (a->wins[i].base != b->wins[i].base ||
            a->wins[i].len != b->wins[i].len) {
            fprintf(stderr, "motion_state_exec: %s: window %u layout differ\n",
                    label, i);
            return 0;
        }
        for (unsigned j = 0; j < a->wins[i].len; ++j) {
            if (a->wins[i].data[j] != b->wins[i].data[j]) {
                fprintf(stderr, "motion_state_exec: %s: ram[%08x] differ: %02x vs %02x\n",
                        label, a->wins[i].base + j,
                        a->wins[i].data[j], b->wins[i].data[j]);
                return 0;
            }
        }
    }
    return 1;
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;

    current_scenario = sc;
    build_fixture(&ref, sc);
    build_fixture(&port, sc);
    build_fixture(&hook, sc);

    if (!run_generated(&ref)) {
        fprintf(stderr, "motion_state_exec: %s: generated failed\n", sc->name);
        return 0;
    }
    if (!run_readable_direct(&port)) {
        fprintf(stderr, "motion_state_exec: %s: readable direct failed\n", sc->name);
        return 0;
    }
    if (!run_readable_hook(&hook)) {
        fprintf(stderr, "motion_state_exec: %s: readable hook failed\n", sc->name);
        return 0;
    }

    if (!cmp_state(&ref.state, &port.state, sc->name)) return 0;
    if (!cmp_state(&ref.state, &hook.state, sc->name)) return 0;
    if (!cmp_ram(&ref.map, &port.map, sc->name)) return 0;
    if (!cmp_ram(&ref.map, &hook.map, sc->name)) return 0;

    if (ref.state.v[15] != STACK_TOP || ref.state.v[16] != RETURN_PC) {
        fprintf(stderr, "motion_state_exec: %s: sp/pr mismatch\n", sc->name);
        return 0;
    }
    if (ref.state.v[14] != sc->state_ptr) {
        fprintf(stderr, "motion_state_exec: %s: r14 not restored\n", sc->name);
        return 0;
    }

    static unsigned cases = 0;
    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_motion_state_exec_entry) {
        fprintf(stderr, "motion_state_exec: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "null state pointer", .state_ptr = 0, .expect_tail_call = 0 },
        { .name = "valid state pointer", .state_ptr = STATE_BASE, .expect_tail_call = 0 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("motion_state_exec: %u differential cases - PASS\n", cases);
    return 0;
}
