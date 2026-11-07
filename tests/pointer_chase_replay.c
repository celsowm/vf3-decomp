/* pointer_chase_replay.c - the readable pointer chase (SH-4 0x8C035264)
 * against the retained generated translation.
 *
 * The function reads a pointer from a fixed literal pool address (0x0c03548c),
 * dereferences it, and reads a field at offset 40.
 *
 * Two arms:
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

int vf3_pointer_chase_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c035264u
#define RETURN_PC 0x0c0abcdeu

/* the literal pool the pointer lives in */
#define POOL_BASE   0x0c035000u
#define POOL_LEN    0x1000u
#define POOL_PTR    (POOL_BASE + 0x48cu)
#define ZERO_BASE   0x00000000u
#define ZERO_LEN    0x1000u

/* the object the pointer points to */
#define OBJ_BASE    0x0c100000u
#define OBJ_LEN     0x1000u

/* the stack */
#define STACK_BASE  0x0c200000u
#define STACK_LEN   0x10000u
#define STACK_TOP   0x0c208000u

#define NWIN 4
#define OFF_ZERO  0u
#define OFF_POOL  (OFF_ZERO + ZERO_LEN)
#define OFF_OBJ   (OFF_POOL + POOL_LEN)
#define OFF_STACK (OFF_OBJ + OBJ_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t pool_value;
    uint32_t obj_field_40;
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

    r->base[0] = ZERO_BASE;
    r->len[0] = ZERO_LEN;
    r->wins[0].base = r->base[0];
    r->wins[0].len = r->len[0];
    r->wins[0].data = r->shadow + OFF_ZERO;

    r->base[1] = POOL_BASE;
    r->len[1] = POOL_LEN;
    r->wins[1].base = r->base[1];
    r->wins[1].len = r->len[1];
    r->wins[1].data = r->shadow + OFF_POOL;

    r->base[2] = OBJ_BASE;
    r->len[2] = OBJ_LEN;
    r->wins[2].base = r->base[2];
    r->wins[2].len = r->len[2];
    r->wins[2].data = r->shadow + OFF_OBJ;

    r->base[3] = STACK_BASE;
    r->len[3] = STACK_LEN;
    r->wins[3].base = r->base[3];
    r->wins[3].len = r->len[3];
    r->wins[3].data = r->shadow + OFF_STACK;

    r->map.nwin = NWIN;
    r->map.wins = r->wins;

    w32(r->shadow, OFF_POOL + (POOL_PTR - POOL_BASE), sc->pool_value);
    {
        const uint32_t target = sc->pool_value & 0x1fffffffu;
        if (target >= OBJ_BASE && target <= OBJ_BASE + OBJ_LEN - 44u)
            w32(r->shadow, OFF_OBJ + (target - OBJ_BASE) + 40u,
                sc->obj_field_40);
    }

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
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    r->map.oob = 0;
    return vf3_matrix_family(ENTRY, &r->state, &r->map);
}

static int run_readable_direct(struct run *r)
{
    r->state.v[15] = STACK_TOP;
    r->state.v[16] = RETURN_PC;
    r->state.pc = ENTRY;
    r->state.budget = 1000;
    r->map.oob = 0;
    return vf3_pointer_chase_entry(&r->state, &r->map);
}

static int run_readable_hook(struct run *r)
{
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
            fprintf(stderr, "pointer_chase: %s: r[%d] differ: %08x vs %08x\n",
                    label, i, a->v[i], b->v[i]);
            return 0;
        }
    }
    if (a->pc != b->pc) {
        fprintf(stderr, "pointer_chase: %s: pc differ: %08x vs %08x\n",
                label, a->pc, b->pc);
        return 0;
    }
    if (a->failed_pc != b->failed_pc) {
        fprintf(stderr, "pointer_chase: %s: failed_pc differ: %08x vs %08x\n",
                label, a->failed_pc, b->failed_pc);
        return 0;
    }
    return 1;
}

static int cmp_ram(const vf3_ram_map *a, const vf3_ram_map *b,
                   const char *label)
{
    if (a->oob != b->oob) {
        fprintf(stderr, "pointer_chase: %s: oob differ: %u vs %u\n",
                label, a->oob, b->oob);
        return 0;
    }
    for (unsigned i = 0; i < a->nwin; ++i) {
        if (a->wins[i].base != b->wins[i].base ||
            a->wins[i].len != b->wins[i].len) {
            fprintf(stderr, "pointer_chase: %s: window %u layout differ\n",
                    label, i);
            return 0;
        }
        for (unsigned j = 0; j < a->wins[i].len; ++j) {
            if (a->wins[i].data[j] != b->wins[i].data[j]) {
                fprintf(stderr, "pointer_chase: %s: ram[%08x] differ: %02x vs %02x\n",
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
        fprintf(stderr, "pointer_chase: %s: generated failed\n", sc->name);
        return 0;
    }
    if (!run_readable_direct(&port)) {
        fprintf(stderr, "pointer_chase: %s: readable direct failed\n", sc->name);
        return 0;
    }
    if (!run_readable_hook(&hook)) {
        fprintf(stderr, "pointer_chase: %s: readable hook failed\n", sc->name);
        return 0;
    }

    if (!cmp_state(&ref.state, &port.state, sc->name)) return 0;
    if (!cmp_state(&ref.state, &hook.state, sc->name)) return 0;
    if (!cmp_ram(&ref.map, &port.map, sc->name)) return 0;
    if (!cmp_ram(&ref.map, &hook.map, sc->name)) return 0;

    if (ref.state.v[0] != sc->obj_field_40) {
        fprintf(stderr, "pointer_chase: %s: the answer is %08x, expected %08x\n",
                sc->name, ref.state.v[0], sc->obj_field_40);
        return 0;
    }
    if (ref.state.v[3] != sc->pool_value) {
        fprintf(stderr, "pointer_chase: %s: r3 is %08x, expected %08x\n",
                sc->name, ref.state.v[3], sc->pool_value);
        return 0;
    }
    if (ref.state.v[15] != STACK_TOP || ref.state.v[16] != RETURN_PC) {
        fprintf(stderr, "pointer_chase: %s: sp %08x pr %08x\n",
                sc->name, ref.state.v[15], ref.state.v[16]);
        return 0;
    }

    static unsigned cases = 0;
    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_pointer_chase_entry) {
        fprintf(stderr, "pointer_chase: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "null pointer, zero field", .pool_value = 0u, .obj_field_40 = 0u },
        { .name = "valid pointer, zero field", .pool_value = OBJ_BASE, .obj_field_40 = 0u },
        { .name = "valid pointer, non-zero field", .pool_value = OBJ_BASE, .obj_field_40 = 0x12345678u },
        { .name = "valid pointer, field 1", .pool_value = OBJ_BASE, .obj_field_40 = 1u },
        { .name = "pointer to middle of object", .pool_value = OBJ_BASE + 0x100u, .obj_field_40 = 0xdeadbeefu },
        { .name = "pointer with high bit", .pool_value = 0x8c100000u, .obj_field_40 = 0xfeedfaceu },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("pointer_chase: %u differential cases - PASS\n", cases);
    return 0;
}
