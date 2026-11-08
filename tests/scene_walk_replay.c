/* scene_walk_replay.c - the readable scene list walk (SH-4 0x8C06233E)
 * against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are the
 * generated chain (the reference), the readable port called directly, and the
 * readable port reached through the readable override.
 *
 * The body is call-free and integer-only.  r4 is a key, r5 points at the
 * flag/table write target.
 *
 *   p1      = [0x0c06238c]   a pointer to a threshold
 *   thr     = [p1]
 *   enabled = (r4 >= thr)    signed, SR.T
 *   [r5]    = enabled ? 1 : 0     (16-bit)
 *   byte    = (int8)[r5]          (0 or 1)
 *   node    = [base + 20*byte]    base = [0x0c062384]
 *
 * If node != 0 the body walks the linked list (value at node+12, next at
 * node+8), recording in r6 the first node whose value == r4, then follows
 * next until the list ends.  r0 = r6 on the return, r1 = the last value read,
 * r2 = the enable byte, r3 = 20*byte, r5 = 0 (terminator), SR.T = 1; r4 and
 * r15 are untouched.
 *
 * The four windows mirror the captured corpus: the literal pool at 0x0c062000
 * (the threshold pointer at 0x0c06238c, the table base at 0x0c062384), the
 * pool's table/threshold region at 0x0c0ea000, the node region at 0x0c16d000
 * and the stack/flag region at 0x0c31f000.  Every window byte is patterned
 * first so a wrong address shows as a mismatch rather than a zero.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scene_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c06233eu
#define RETURN_PC 0x0c062004u

/* the four windows, mirroring the corpus */
#define WIN1_BASE 0x0c062000u        /* literal pool */
#define WIN1_LEN  0x1000u
#define POOL_P1    0x0c06238cu       /* holds the threshold pointer */
#define POOL_BASE  0x0c062384u       /* holds the table base */
#define WIN2_BASE 0x0c0ea000u        /* the pool's table/threshold region */
#define WIN2_LEN  0x1000u
#define P1_TARGET 0x0c0eae00u        /* the threshold word *p1 */
#define TBL_BASE  0x0c0eae08u        /* the table [base + 20*byte] */
#define WIN3_BASE 0x0c16d000u        /* nodes */
#define WIN3_LEN  0x1000u
#define WIN4_BASE 0x0c31f000u        /* r5 / r15 */
#define WIN4_LEN  0x1000u

#define MAXWIN 4u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

/* a linked-list node: u32 value at +12, u32 next at +8. */
struct node {
    const char *name;
    uint32_t value;                 /* the key it matches, or 0 */
    uint32_t next;                  /* VA of the next node, or 0 */
};

struct scenario {
    const char *name;
    int32_t r4;                     /* the key */
    uint32_t thr;                   /* *p1 threshold */
    uint32_t node0;                 /* table[0]: first node (base + 0) */
    uint32_t node1;                 /* table[1]: first node (base + 20) */
    struct node nodes[3];           /* laid out at known VAs */
};

/* node VAs inside WIN3 */
#define NODE_A 0x0c16d200u
#define NODE_B 0x0c16d240u
#define NODE_C 0x0c16d280u

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static unsigned win_len(unsigned w)
{
    static const unsigned L[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN, WIN4_LEN };
    return L[w];
}

static void put_node(struct run *r, uint32_t va, const struct node *n)
{
    if (va == 0) return;
    uint8_t *p = r->shadow[2] + (va - WIN3_BASE);
    w32(p, 8, n->next);
    w32(p, 12, n->value);
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the literal pool */
    w32(r->shadow[0], POOL_P1 - WIN1_BASE, P1_TARGET);
    w32(r->shadow[0], POOL_BASE - WIN1_BASE, TBL_BASE);
    /* the threshold */
    w32(r->shadow[1], P1_TARGET - WIN2_BASE, sc->thr);
    /* the table: entries at base + 0 and base + 20 */
    w32(r->shadow[1], TBL_BASE - WIN2_BASE + 0u, sc->node0);
    w32(r->shadow[1], TBL_BASE - WIN2_BASE + 20u, sc->node1);
    /* the nodes */
    const struct node *n = sc->nodes;
    put_node(r, NODE_A, &n[0]);
    put_node(r, NODE_B, &n[1]);
    put_node(r, NODE_C, &n[2]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = (uint32_t)sc->r4;
    s->v[5] = 0x0c31f8e4u;           /* the flag/table write target, in win 4 */
    s->v[15] = 0x0c31f8e4u;          /* r15 == r5 in the captured corpus */
    s->v[16] = RETURN_PC;            /* pr: the tail-return target */
    s->v[17] = 0x60000000u;          /* sr, T clear */
    s->v[18] = 0x00024001u;          /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
    r->wins[2].base = WIN3_BASE; r->wins[2].len = WIN3_LEN; r->wins[2].data = r->shadow[2];
    r->wins[3].base = WIN4_BASE; r->wins[3].len = WIN4_LEN; r->wins[3].data = r->shadow[3];
    r->map.wins = r->wins;
    r->map.n = MAXWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 37 && shown < 12; ++i)
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
    for (unsigned w = 0; w < MAXWIN; ++w)
        if (memcmp(a->shadow[w], b->shadow[w], win_len(w))) {
            for (unsigned i = 0; i < win_len(w); ++i)
                if (a->shadow[w][i] != b->shadow[w][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n",
                            what, w, i, a->shadow[w][i], b->shadow[w][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_scene_walk_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "scene_walk: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "scene_walk: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    const uint32_t enabled = ((int32_t)sc->r4 >= (int32_t)sc->thr) ? 1u : 0u;
    uint8_t *flag = ref.shadow[3] + (0x0c31f8e4u - WIN4_BASE);
    /* the written flag is a 16-bit store; mask off the patterned high bytes */
    if ((r32(flag, 0) & 0xffffu) != enabled) {
        fprintf(stderr, "scene_walk: %s: flag %08x, want %u\n", sc->name,
                r32(flag, 0), enabled);
        return 0;
    }
    if (ref.state.v[2] != enabled || ref.state.v[3] != 20u * enabled) {
        fprintf(stderr, "scene_walk: %s: r2 %08x r3 %08x, want %u %u\n",
                sc->name, ref.state.v[2], ref.state.v[3], enabled, 20u * enabled);
        return 0;
    }
    /* expected found node: walk table[enabled] */
    uint32_t want = 0, r1 = ref.state.v[1];
    uint32_t cur = enabled ? sc->node1 : sc->node0;
    unsigned matched = 0;
    while (cur != 0 && !matched) {
        const struct node *nn = NULL;
        if (cur == NODE_A) nn = &sc->nodes[0];
        else if (cur == NODE_B) nn = &sc->nodes[1];
        else if (cur == NODE_C) nn = &sc->nodes[2];
        if (!nn) { fprintf(stderr, "scene_walk: %s: unknown node %08x\n",
                           sc->name, cur); return 0; }
        const uint32_t value = nn->value ? nn->value : (uint32_t)sc->r4;
        if (nn->value != 0 && nn->value == (uint32_t)sc->r4) {
            want = cur;
            r1 = nn->value;
            matched = 1;
        } else {
            r1 = value;
            cur = nn->next;
        }
    }
    if (ref.state.v[6] != want || ref.state.v[0] != want) {
        fprintf(stderr, "scene_walk: %s: r6 %08x r0 %08x, want %08x\n",
                sc->name, ref.state.v[6], ref.state.v[0], want);
        return 0;
    }
    if (ref.state.v[5] != 0u || (ref.state.v[17] & 1u) != 1u) {
        fprintf(stderr, "scene_walk: %s: r5 %08x T %u\n", sc->name,
                ref.state.v[5], ref.state.v[17] & 1u);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_scene_walk_entry) {
        fprintf(stderr, "scene_walk: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* enable=1, found at the first node (node A matches). */
        { .name = "enable1 first match",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { "A", 0x5f0080, 0 }, { 0, 0, 0 }, { 0, 0, 0 } } },
        /* enable=1, match at the second node (A mismatches, B matches). */
        { .name = "enable1 second match",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { "A", 0x11111111, NODE_B }, { "B", 0x5f0080, 0 }, { 0, 0, 0 } } },
        /* enable=1, not found: one mismatching node with a null next. */
        { .name = "enable1 not found",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = 0, .node1 = NODE_A,
          .nodes = { { "A", 0x11111111, 0 }, { 0, 0, 0 }, { 0, 0, 0 } } },
        /* enable=1, empty table (node1 == 0): early return, r6 = 0. */
        { .name = "enable1 empty table",
          .r4 = 0x5f0080, .thr = 0x400000, .node0 = 0, .node1 = 0,
          .nodes = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } } },
        /* enable=0 (r4 < thr), found at table[0]'s node. */
        { .name = "enable0 first match",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = NODE_C,
          .nodes = { { "A", 0x100, 0 }, { "B", 0x5f0080, 0 }, { "C", 0x5f0080, 0 } } },
        /* enable=0, multi-node walk where the match is the third node. */
        { .name = "enable0 third match",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = 0,
          .nodes = { { "A", 0x1, NODE_B }, { "B", 0x2, NODE_C }, { "C", 0x100, 0 } } },
        /* enable=0, not found. */
        { .name = "enable0 not found",
          .r4 = 0x100, .thr = 0x400000,
          .node0 = NODE_A, .node1 = 0,
          .nodes = { { "A", 0x1, NODE_B }, { "B", 0x2, 0 }, { 0, 0, 0 } } },
        /* boundary: r4 == thr gives enable = 1. */
        { .name = "r4 == thr enable1",
          .r4 = 0x400000, .thr = 0x400000,
          .node0 = NODE_A, .node1 = NODE_B,
          .nodes = { { "A", 0x400000, 0 }, { "B", 0x5f0080, 0 }, { 0, 0, 0 } } },
        /* enable=1, match at the first node which is also in node0 (distinct
         * table entries, so the walk must use table[1], not table[0]). */
        { .name = "enable1 uses table1",
          .r4 = 0x5f0080, .thr = 0x400000,
          .node0 = NODE_C, .node1 = NODE_A,
          .nodes = { { "A", 0x5f0080, 0 }, { "B", 0x1111, 0 }, { "C", 0x5f0080, 0 } } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("scene_walk: %u differential cases - PASS\n", cases);
    return 0;
}
