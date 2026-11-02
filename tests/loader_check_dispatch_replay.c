/* loader_check_dispatch_replay.c - the readable loader check-and-dispatch
 * (SH-4 0x8C034A20) against the retained generated translation.
 *
 * The function increments a counter, checks a field in a loader state
 * structure, and either returns (if the field is 1) or tail-transfers
 * to the loader dispatch routine (0x8C035238).
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

int vf3_loader_check_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c034a20u
#define DISPATCH  0x0c035238u
#define CONTINUE  0x0c034a36u

/* literal pool addresses */
#define OBJ_PTR_ADDR  0x0c0ea2ecu
#define COUNTER_ADDR  0x0c0ea2f8u

/* the loader state object */
#define OBJ_BASE      0x0c0ea000u
#define OBJ_LEN       0x1000u

/* the stack */
#define STACK_BASE    0x0c100000u
#define STACK_LEN     0x10000u
#define STACK_TOP     (STACK_BASE + STACK_LEN)

#define NWIN 3
#define OFF_POOL      0u
#define OFF_OBJ       (OFF_POOL + 0x1000u)
#define OFF_STACK     (OFF_OBJ + OBJ_LEN)
#define SHADOW_LEN    (OFF_STACK + STACK_LEN)

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    uint32_t init_counter;
    uint32_t field36;
    int expect_return;
};

static int compare(const struct scenario *sc)
{
    uint8_t ref_shadow[SHADOW_LEN];
    uint8_t port_shadow[SHADOW_LEN];
    uint8_t hook_shadow[SHADOW_LEN];

    vf3_matrix_state ref_state = {0}, port_state = {0}, hook_state = {0};
    vf3_ram_win ref_wins[NWIN], port_wins[NWIN], hook_wins[NWIN];
    vf3_ram_map ref_map = {0}, port_map = {0}, hook_map = {0};
    uint32_t ref_base[NWIN] = {0}, ref_len[NWIN] = {0};
    uint32_t port_base[NWIN] = {0}, port_len[NWIN] = {0};
    uint32_t hook_base[NWIN] = {0}, hook_len[NWIN] = {0};

    ref_map.wins = ref_wins; ref_map.n = NWIN; ref_map.oob = 0; ref_map.device_read = NULL; ref_map.device_write = NULL; ref_map.device_context = NULL;
    port_map.wins = port_wins; port_map.n = NWIN; port_map.oob = 0; port_map.device_read = NULL; port_map.device_write = NULL; port_map.device_context = NULL;
    hook_map.wins = hook_wins; hook_map.n = NWIN; hook_map.oob = 0; hook_map.device_read = NULL; hook_map.device_write = NULL; hook_map.device_context = NULL;

    memset(ref_shadow, 0, SHADOW_LEN);
    memset(port_shadow, 0, SHADOW_LEN);
    memset(hook_shadow, 0, SHADOW_LEN);

    ref_wins[0].base = OBJ_PTR_ADDR & ~0xfffu;
    ref_wins[0].len = 0x1000u;
    ref_wins[0].data = ref_shadow + OFF_POOL;
    port_wins[0] = ref_wins[0];
    port_wins[0].data = port_shadow + OFF_POOL;
    hook_wins[0] = ref_wins[0];
    hook_wins[0].data = hook_shadow + OFF_POOL;

    ref_wins[1].base = OBJ_BASE & ~0xfffu;
    ref_wins[1].len = OBJ_LEN;
    ref_wins[1].data = ref_shadow + OFF_OBJ;
    port_wins[1] = ref_wins[1];
    port_wins[1].data = port_shadow + OFF_OBJ;
    hook_wins[1] = ref_wins[1];
    hook_wins[1].data = hook_shadow + OFF_OBJ;

    ref_wins[2].base = STACK_BASE & ~0xfffu;
    ref_wins[2].len = STACK_LEN;
    ref_wins[2].data = ref_shadow + OFF_STACK;
    port_wins[2] = ref_wins[2];
    port_wins[2].data = port_shadow + OFF_STACK;
    hook_wins[2] = ref_wins[2];
    hook_wins[2].data = hook_shadow + OFF_STACK;

    w32(ref_shadow + OFF_POOL, OBJ_PTR_ADDR - ref_wins[0].base, OBJ_BASE);
    w32(ref_shadow + OFF_POOL, COUNTER_ADDR - ref_wins[0].base, COUNTER_ADDR);
    w32(port_shadow + OFF_POOL, OBJ_PTR_ADDR - ref_wins[0].base, OBJ_BASE);
    w32(port_shadow + OFF_POOL, COUNTER_ADDR - ref_wins[0].base, COUNTER_ADDR);
    w32(hook_shadow + OFF_POOL, OBJ_PTR_ADDR - ref_wins[0].base, OBJ_BASE);
    w32(hook_shadow + OFF_POOL, COUNTER_ADDR - ref_wins[0].base, COUNTER_ADDR);

    w32(ref_shadow + OFF_OBJ, 0, sc->init_counter);
    w32(ref_shadow + OFF_OBJ, 36, sc->field36);
    w32(port_shadow + OFF_OBJ, 0, sc->init_counter);
    w32(port_shadow + OFF_OBJ, 36, sc->field36);
    w32(hook_shadow + OFF_OBJ, 0, sc->init_counter);
    w32(hook_shadow + OFF_OBJ, 36, sc->field36);

    for (uint32_t i = 0; i < STACK_LEN; i += 4) {
        w32(ref_shadow + OFF_STACK, i, 0x41a0a0a0u + i);
        w32(port_shadow + OFF_STACK, i, 0x41a0a0a0u + i);
        w32(hook_shadow + OFF_STACK, i, 0x41a0a0a0u + i);
    }

    ref_state.pc = ENTRY;
    ref_state.v[15] = STACK_TOP;
    ref_state.v[16] = 0x0c0abcdeu;
    port_state = ref_state;
    hook_state = ref_state;

    vf3_matrix_family(ENTRY, &ref_state, &ref_map);
    vf3_loader_check_dispatch_entry(&port_state, &port_map);
    vf3_family_override = vf3_readable_override;
    vf3_matrix_family(ENTRY, &hook_state, &hook_map);
    vf3_family_override = NULL;

    for (int r = 0; r < 54; ++r) {
        if (ref_state.v[r] != port_state.v[r]) {
            fprintf(stderr, "%s: reg r%d ref=%08x port=%08x\n",
                    sc->name, r, ref_state.v[r], port_state.v[r]);
            return 0;
        }
        if (ref_state.v[r] != hook_state.v[r]) {
            fprintf(stderr, "%s: reg r%d ref=%08x hook=%08x\n",
                    sc->name, r, ref_state.v[r], hook_state.v[r]);
            return 0;
        }
    }

    const char *sregs[] = {"pc", "failed_pc", "gbr"};
    uint32_t *ref_s[] = {&ref_state.pc, &ref_state.failed_pc, &ref_state.gbr};
    uint32_t *port_s[] = {&port_state.pc, &port_state.failed_pc, &port_state.gbr};
    uint32_t *hook_s[] = {&hook_state.pc, &hook_state.failed_pc, &hook_state.gbr};
    for (int i = 0; i < 3; ++i) {
        if (*ref_s[i] != *port_s[i]) {
            fprintf(stderr, "%s: %s ref=%08x port=%08x\n",
                    sc->name, sregs[i], *ref_s[i], *port_s[i]);
            return 0;
        }
        if (*ref_s[i] != *hook_s[i]) {
            fprintf(stderr, "%s: %s ref=%08x hook=%08x\n",
                    sc->name, sregs[i], *ref_s[i], *hook_s[i]);
            return 0;
        }
    }

    if (ref_map.oob != port_map.oob || ref_map.oob != hook_map.oob) {
        fprintf(stderr, "%s: oob ref=%u port=%u hook=%u\n",
                sc->name, ref_map.oob, port_map.oob, hook_map.oob);
        return 0;
    }

    if (memcmp(ref_wins[0].data, port_wins[0].data, ref_wins[0].len) != 0 ||
        memcmp(ref_wins[1].data, port_wins[1].data, ref_wins[1].len) != 0 ||
        memcmp(ref_wins[2].data, port_wins[2].data, ref_wins[2].len) != 0 ||
        memcmp(ref_wins[0].data, hook_wins[0].data, ref_wins[0].len) != 0 ||
        memcmp(ref_wins[1].data, hook_wins[1].data, ref_wins[1].len) != 0 ||
        memcmp(ref_wins[2].data, hook_wins[2].data, ref_wins[2].len) != 0) {
        fprintf(stderr, "%s: RAM mismatch\n", sc->name);
        return 0;
    }

    if (sc->expect_return) {
        if ((ref_state.pc & 0x1fffffffu) != (CONTINUE & 0x1fffffffu)) {
            fprintf(stderr, "%s: expected return to CONTINUE, got pc=%08x\n",
                    sc->name, ref_state.pc);
            return 0;
        }
    } else {
        if ((ref_state.pc & 0x1fffffffu) != (DISPATCH & 0x1fffffffu)) {
            fprintf(stderr, "%s: expected tail transfer to DISPATCH, got pc=%08x\n",
                    sc->name, ref_state.pc);
            return 0;
        }
        if (!ref_state.lost_pc) {
            fprintf(stderr, "%s: lost_pc not set on tail transfer\n", sc->name);
            return 0;
        }
    }

    printf("%s: PASS\n", sc->name);
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_loader_check_dispatch_entry) {
        fprintf(stderr, "loader_check_dispatch: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "field36 == 1, returns",
          .init_counter = 0, .field36 = 1, .expect_return = 1 },
        { .name = "field36 == 0, tail transfers",
          .init_counter = 0, .field36 = 0, .expect_return = 0 },
        { .name = "field36 == 2, tail transfers",
          .init_counter = 5, .field36 = 2, .expect_return = 0 },
        { .name = "field36 == 0xFFFFFFFF, tail transfers",
          .init_counter = 10, .field36 = 0xFFFFFFFFu, .expect_return = 0 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("loader_check_dispatch: %u differential cases - PASS\n",
           (unsigned)(sizeof scenarios / sizeof scenarios[0]));
    return 0;
}
