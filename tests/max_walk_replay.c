/* max_walk_replay.c - the readable four-list gated max walk (SH-4 0x8C061910)
 * against the retained generated translation.
 *
 * The function is a self-contained leaf (call-free, integer-only), so the test
 * needs no stub: the three arms are the generated chain (the reference), the
 * readable port called directly, and the readable port reached through the
 * readable override.
 *
 * The body reads the fight structure's address from the pool at 0x0c061a0c and
 * searches four linked lists over [node+16] (value), stepping a node by its
 * [+8] word (next); lists B and D only let a node compete while (node.gate &
 * 4) == 0.  The two maxima start at 0 and go to [r4] and [r5]: r7 from list A
 * (st+8) then list B (st); r14 from list C (st+0x1c) then list D (list at
 * st+0x14).  r12/r13/r14 are restored, r15 net flat, and the body leaves
 * r0 = 0, r1 = the last gated value read, r2 = the last gate/next read, r6 = 0,
 * and SR.T = 1.
 *
 * The five windows mirror the captured corpus: the literal pool (0x0c061000,
 * holding the struct pointer at 0x0c061a0c), the fight structure (0x0c0ea000),
 * the stack (0x0c31f000, where the pushed registers and the scratch slot
 * land), the output words (0x0c40d000, r4/r5 targets) and the node region
 * (0x0c40f000).  Every window byte is patterned first so a wrong address shows
 * up as a mismatch rather than a coincidental zero, and the outcome is checked
 * against the fixture itself.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_max_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c061910u
#define RETURN_PC 0x0c061994u

/* the five windows, mirroring the corpus */
#define WIN0_BASE 0x0c061000u   /* the literal pool */
#define WIN0_LEN  0x1000u
#define ST_SLOT   0x0c061a0cu   /* u32 struct pointer in the pool */
#define WIN1_BASE 0x0c0ea000u   /* the fight structure */
#define WIN1_LEN  0x1000u
#define ST        0x0c0eae08u   /* the structure (window 1 +0xe08) */
#define WIN2_BASE 0x0c31f000u   /* the stack */
#define WIN2_LEN  0x1000u
#define WIN3_BASE 0x0c40d000u   /* the output words */
#define WIN3_LEN  0x1000u
#define OUT0      0x0c40d000u   /* r4 target */
#define OUT1      0x0c40d004u   /* r5 target */
#define WIN4_BASE 0x0c40f000u   /* the node region */
#define WIN4_LEN  0x1000u

#define MAXWIN 5u

/* fixe dnode addresses inside WIN4 */
#define NB0 0x0c40f000u
#define NB1 0x0c40f020u
#define NA0 0x0c40f040u
#define NA1 0x0c40f060u
#define ND0 0x0c40f080u
#define ND1 0x0c40f0a0u
#define NC0 0x0c40f0c0u
#define NC1 0x0c40f0e0u

struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct list {
    int count;                 /* 0, 1 or 2 nodes */
    uint16_t gate[2];
    uint32_t val[2];
};

struct scenario {
    const char *name;
    uint32_t sp0;
    struct list A, B, C, D;    /* A@st+8, B@st, C@st+0x1c, D@st+0x14 */
};

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static uint16_t r16(const uint8_t *p, uint32_t off)
{
    return (uint16_t)p[off] | ((uint16_t)p[off + 1] << 8);
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
{ return w == 0 ? WIN0_LEN : w == 1 ? WIN1_LEN : w == 2 ? WIN2_LEN :
         w == 3 ? WIN3_LEN : WIN4_LEN; }

/* lay one list out: node0 at base, node1 at base+0x20. */
static void place(uint8_t *shw4, const struct list *l, uint32_t base)
{
    const uint32_t b = base - WIN4_BASE;
    if (l->count == 0) {
        /* head field is written by the caller; nothing to place */
        return;
    }
    w16(shw4, b + 0, l->gate[0]);
    w32(shw4, b + 8, l->count == 2 ? base + 0x20u : 0u);
    w32(shw4, b + 16, l->val[0]);
    if (l->count == 2) {
        w16(shw4, b + 0x20 + 0, l->gate[1]);
        w32(shw4, b + 0x20 + 8, 0u);
        w32(shw4, b + 0x20 + 16, l->val[1]);
    }
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }
    uint8_t *w0 = r->shadow[0], *w1 = r->shadow[1], *w4 = r->shadow[4];

    /* the pool: the fight structure's address. */
    w32(w0, ST_SLOT - WIN0_BASE, ST);

    /* the structure: the four heads (empty list -> head field 0). */
    w32(w1, ST + 0x08u - WIN1_BASE, sc->A.count ? NA0 : 0u);
    w32(w1, ST + 0x00u - WIN1_BASE, sc->B.count ? NB0 : 0u);
    w32(w1, ST + 0x1cu - WIN1_BASE, sc->C.count ? NC0 : 0u);
    w32(w1, ST + 0x14u - WIN1_BASE, sc->D.count ? ND0 : 0u);

    /* the nodes. */
    place(w4, &sc->A, NA0);
    place(w4, &sc->B, NB0);
    place(w4, &sc->C, NC0);
    place(w4, &sc->D, ND0);

    /* register file */
    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OUT0;                   /* r4: the first output word */
    s->v[5] = OUT1;                   /* r5: the second output word */
    s->v[15] = sc->sp0;
    s->v[16] = RETURN_PC;             /* pr */
    s->v[17] = 0x60000000u;           /* sr, T clear */
    s->v[18] = 0x00024001u;           /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;

    r->wins[0].base = WIN0_BASE; r->wins[0].len = WIN0_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN1_BASE; r->wins[1].len = WIN1_LEN; r->wins[1].data = r->shadow[1];
    r->wins[2].base = WIN2_BASE; r->wins[2].len = WIN2_LEN; r->wins[2].data = r->shadow[2];
    r->wins[3].base = WIN3_BASE; r->wins[3].len = WIN3_LEN; r->wins[3].data = r->shadow[3];
    r->wins[4].base = WIN4_BASE; r->wins[4].len = WIN4_LEN; r->wins[4].data = r->shadow[4];
    r->map.wins = r->wins;
    r->map.n = MAXWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static void free_run(struct run *r)
{
    for (unsigned w = 0; w < MAXWIN; ++w) free(r->shadow[w]);
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    unsigned winlen[MAXWIN] = { WIN0_LEN, WIN1_LEN, WIN2_LEN, WIN3_LEN, WIN4_LEN };
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 37 && shown < 10; ++i)
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
        if (memcmp(a->shadow[w], b->shadow[w], winlen[w])) {
            for (unsigned i = 0; i < winlen[w]; ++i)
                if (a->shadow[w][i] != b->shadow[w][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n", what, w, i,
                            a->shadow[w][i], b->shadow[w][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned cases;

/* independent walk over the fixture: list ungated (A/C) or gated (B/D). */
static uint32_t walk_max(const uint8_t *shw4, uint32_t head, int gated)
{
    uint32_t m = 0;
    uint32_t node = head;
    while (node) {
        const uint32_t off = node - WIN4_BASE;
        if (gated) {
            if ((r16(shw4, off + 0) & 4u) == 0) {
                uint32_t v = r32(shw4, off + 16);
                if ((int32_t)v > (int32_t)m) m = v;
            }
        } else {
            uint32_t v = r32(shw4, off + 16);
            if ((int32_t)v > (int32_t)m) m = v;
        }
        node = r32(shw4, off + 8);
    }
    return m;
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    unsigned winlen[MAXWIN] = { WIN0_LEN, WIN1_LEN, WIN2_LEN, WIN3_LEN, WIN4_LEN };

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_max_walk_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    int ok = ok_ref == ok_port && ok_ref == ok_hook && handled &&
             same(&ref, &port, "port") && same(&ref, &hook, "hook");
    if (!ok) {
        fprintf(stderr, "max_walk: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "max_walk: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }

    /* outcome against the fixture itself: two maxima over the four lists */
    const uint8_t *shw1 = ref.shadow[1];
    const uint8_t *shw3 = ref.shadow[3];
    const uint8_t *shw4 = ref.shadow[4];
    uint32_t e_r7 = walk_max(shw4, sc->A.count ? NA0 : 0, 0);
    uint32_t b = walk_max(shw4, sc->B.count ? NB0 : 0, 1);
    if ((int32_t)b > (int32_t)e_r7) e_r7 = b;
    uint32_t e_r14 = walk_max(shw4, sc->C.count ? NC0 : 0, 0);
    uint32_t d = walk_max(shw4, sc->D.count ? ND0 : 0, 1);
    if ((int32_t)d > (int32_t)e_r14) e_r14 = d;

    if (r32(shw1, ST + 0x08u - WIN1_BASE) != (sc->A.count ? NA0 : 0u) ||
        r32(shw1, ST + 0x00u - WIN1_BASE) != (sc->B.count ? NB0 : 0u) ||
        r32(shw1, ST + 0x1cu - WIN1_BASE) != (sc->C.count ? NC0 : 0u) ||
        r32(shw1, ST + 0x14u - WIN1_BASE) != (sc->D.count ? ND0 : 0u)) {
        fprintf(stderr, "max_walk: %s: a head field was clobbered\n", sc->name);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }
    if (r32(shw3, OUT0 - WIN3_BASE) != e_r7 ||
        r32(shw3, OUT1 - WIN3_BASE) != e_r14) {
        fprintf(stderr, "max_walk: %s: [r4]/[r5] wrong (%08x/%08x want %08x/%08x)\n",
                sc->name, r32(shw3, OUT0 - WIN3_BASE),
                r32(shw3, OUT1 - WIN3_BASE), e_r7, e_r14);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }

    /* the pushed/scratch words on the stack */
    uint32_t sp0 = sc->sp0;
    const uint8_t *stk = ref.shadow[2];
    if (r32(stk, sp0 - 4u - WIN2_BASE)  != 0x7654321eu ||
        r32(stk, sp0 - 8u - WIN2_BASE)  != 0x7654321du ||
        r32(stk, sp0 - 12u - WIN2_BASE) != 0x7654321cu ||
        r32(stk, sp0 - 16u - WIN2_BASE) != ST + 0x14u) {
        fprintf(stderr, "max_walk: %s: stack/scratch words wrong\n", sc->name);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }

    const vf3_matrix_state *s = &ref.state;
    if (s->v[0] != 0u || s->v[7] != e_r7 || s->v[6] != 0u ||
        (s->v[17] & 1u) != 1u || s->v[15] != sp0 ||
        s->v[12] != 0x7654321cu || s->v[13] != 0x7654321du ||
        s->v[14] != 0x7654321eu) {
        fprintf(stderr, "max_walk: %s: registers wrong (r0 %08x r7 %08x r6 %08x "
                "r12 %08x r13 %08x r14 %08x r15 %08x T %u)\n", sc->name,
                s->v[0], s->v[7], s->v[6], s->v[12], s->v[13], s->v[14],
                s->v[15], s->v[17] & 1u);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }

    ++cases;
    free_run(&ref); free_run(&port); free_run(&hook);
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_max_walk_entry) {
        fprintf(stderr, "max_walk: the port is not registered\n");
        return 1;
    }

    /* A value in node0, larger in the gated B list that a gate lets through;
     * C and D likewise for r14.  This mirrors the captured corpus case 0. */
    struct scenario s1 = {
        .name = "four populated lists",
        .sp0 = 0x0c31f9ccu,
        .A = { .count = 2, .gate = {0,0}, .val = {0x0, 0x1} },
        .B = { .count = 2, .gate = {0,4}, .val = {0x0, 0x2} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x0, 0x2} },
        .D = { .count = 2, .gate = {0,4}, .val = {0x0, 0x3} },
    };
    /* the gated B/D lists hide their high value (gate bit set), so r7/r14
     * come from A and C. */
    struct scenario s2 = {
        .name = "gates hide the high values",
        .sp0 = 0x0c31fa20u,
        .A = { .count = 2, .gate = {0,0}, .val = {0x1, 0x2} },
        .B = { .count = 2, .gate = {0,4}, .val = {0x0, 0x64} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x3, 0x4} },
        .D = { .count = 2, .gate = {0,4}, .val = {0x0, 0x65} },
    };
    /* a negative value wins the signed max; gates clear so B/D count too. */
    struct scenario s3 = {
        .name = "negative values and open gates",
        .sp0 = 0x0c31f9e0u,
        .A = { .count = 1, .gate = {0,0}, .val = {0xfffffffe} },
        .B = { .count = 1, .gate = {0,0}, .val = {0x5} },
        .C = { .count = 1, .gate = {0,0}, .val = {0xfffffffd} },
        .D = { .count = 1, .gate = {0,0}, .val = {0x6} },
    };
    /* all lists empty: both maxima stay 0. */
    struct scenario s4 = {
        .name = "all lists empty",
        .sp0 = 0x0c31f9f0u,
        .A = { .count = 0 }, .B = { .count = 0 },
        .C = { .count = 0 }, .D = { .count = 0 },
    };
    /* only the gated lists populated, their gates open. */
    struct scenario s5 = {
        .name = "only gated lists populated",
        .sp0 = 0x0c31fa08u,
        .A = { .count = 0 }, .B = { .count = 1, .gate = {0,0}, .val = {0x7} },
        .C = { .count = 0 }, .D = { .count = 1, .gate = {0,0}, .val = {0x8} },
    };
    /* A empty but C carries the second max. */
    struct scenario s6 = {
        .name = "A empty, longer C",
        .sp0 = 0x0c31fac0u,
        .A = { .count = 0 },
        .B = { .count = 1, .gate = {0,0}, .val = {0x1} },
        .C = { .count = 2, .gate = {0,0}, .val = {0x2, 0x9} },
        .D = { .count = 1, .gate = {0,4}, .val = {0x0, 0x20} },
    };

    struct scenario *scenarios[] = { &s1, &s2, &s3, &s4, &s5, &s6 };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(scenarios[i])) return 1;

    printf("max_walk: %u differential cases - PASS\n", cases);
    return 0;
}
