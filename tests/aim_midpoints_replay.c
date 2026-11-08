/* aim_midpoints_replay.c - the readable aim-midpoints builder
 * (SH-4 0x8C09E428) against the retained generated translation.
 *
 * The body computes three halfword midpoints of the actor's pose fields
 * with the guest's exact logical-shift arithmetic, calls 0x8C09D452 with
 * the three values, a quarter-turn rotate_z, store_keep_translation and
 * matrix_copy, then tail-transfers to matrix_pop with count 1.  All but
 * the 09D452 wrapper are the readable/generated matrix helpers, so the
 * test needs no stub: the three arms are the generated chain (the
 * reference), the readable port called directly, and the readable port
 * reached through the readable override.
 *
 * Four windows: the literal pool at 0x0c09d000 (the 09D452 handler
 * pointers at 0x0c09d580.., the call targets and the field offsets at
 * 0x0c09e4aa..), the actor at 0x0c200000, the stack, and the matrix-stack
 * control block at 0x0c19d2e4 (count 1 / limit 16, so the push and the
 * tail pop both have somewhere to go).  The saved r5 pointer the body
 * frames is actor+0x200; the matrix copy source is actor+0x400.
 *
 * On top of the differential, each case is checked against a midpoint
 * model written from the fixture (zero-extend both operands, sign-extend
 * the difference from sixteen bits, shift it right logically, add it to
 * the second operand, mask to sixteen bits) and read back out of the
 * frame the guest left on the stack: frame+8, +12 and +4.  A
 * differential passes even when the fixture is laid out where the guest
 * never looks; this guard does not consult the translation.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_aim_midpoints_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09e428u
#define RETURN_PC 0x0c0abcdeu

#define WIN1_BASE 0x0c09d000u        /* literal pool */
#define WIN1_LEN  0x2000u
#define WIN2_BASE 0x0c200000u        /* the actor */
#define WIN2_LEN  0x4000u
#define WIN3_BASE 0x0c100000u        /* the stack */
#define WIN3_LEN  0x10000u
#define WIN4_BASE 0x0c19d000u        /* the matrix stack */
#define WIN4_LEN  0x2000u
#define ACTOR 0x0c200000u
#define STACK_TOP 0x0c108000u
#define STACK_GARBAGE 0x41a0a0a0u
#define STACK_CTL 0x0c19d2e4u
#define STACK_BASE 0x0c19d400u
#define R5_PTR (ACTOR + 0x200u)

#define MAXWIN 4u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    /* pose-field halfwords: the pairs at 0x1F56/0x1F58/0x1F5A (first
     * operands) and 0x1F86/0x1F88/0x1F8A (second operands) */
    uint16_t first[3];
    uint16_t second[3];
};

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

static uint32_t mid_model(uint16_t second, uint16_t first)
{
    uint32_t diff = (uint32_t)(int32_t)(int16_t)((int32_t)first -
                                                (int32_t)second);
    diff >>= 1;
    return (second + diff) & 0xffffu;
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the literal pool: 09D452's handler pointers, this body's targets
     * and field offsets, with the values the real image holds */
    w32(r->shadow[0], 0x0c09d580u - WIN1_BASE, 0x0c03c940u);
    w32(r->shadow[0], 0x0c09d584u - WIN1_BASE, 0x0c03c880u);
    w32(r->shadow[0], 0x0c09d588u - WIN1_BASE, 0x0c03c6c0u);
    w32(r->shadow[0], 0x0c09d58cu - WIN1_BASE, 0x0c03b620u);
    w32(r->shadow[0], 0x0c09e4b4u - WIN1_BASE, 0x0c03c4f0u);
    w32(r->shadow[0], 0x0c09e4b8u - WIN1_BASE, 0x0c09d452u);
    w32(r->shadow[0], 0x0c09e4bcu - WIN1_BASE, 0x0c03c940u);
    w32(r->shadow[0], 0x0c09e4c0u - WIN1_BASE, 0x0c03b530u);
    w32(r->shadow[0], 0x0c09e4c4u - WIN1_BASE, 0x0c03c4a0u);
    w16(r->shadow[0], 0x0c09e4aau - WIN1_BASE, 0x1f86u);
    w16(r->shadow[0], 0x0c09e4acu - WIN1_BASE, 0x1f58u);
    w16(r->shadow[0], 0x0c09e4aeu - WIN1_BASE, 0x1f5au);
    w16(r->shadow[0], 0x0c09e4b0u - WIN1_BASE, 0x4000u);
    w16(r->shadow[0], 0x0c09e4b2u - WIN1_BASE, 0x0400u);

    /* the actor: the six halfwords the midpoints read */
    for (unsigned i = 0; i < 3; ++i) {
        w16(r->shadow[1], 0x1f56u + 2u * i, sc->first[i]);
        w16(r->shadow[1], 0x1f86u + 2u * i, sc->second[i]);
    }

    /* the matrix stack: count 1, limit 16, top one matrix up */
    w32(r->shadow[3], STACK_CTL - WIN4_BASE, (16u << 16) | 1u);
    w32(r->shadow[3], STACK_CTL - WIN4_BASE + 4u, STACK_BASE);
    w32(r->shadow[3], STACK_CTL - WIN4_BASE + 8u, STACK_BASE + 64u);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = ACTOR;               /* r4: the actor */
    s->v[5] = R5_PTR;              /* r5: the saved pointer */
    s->v[15] = STACK_TOP;          /* r15 */
    s->v[16] = RETURN_PC;          /* pr: the tail-return target */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr: the chain's FPU gate */
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
        for (unsigned i = 0; i < 54 && shown < 12; ++i)
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
    const int ok_port = vf3_aim_midpoints_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "aim_midpoints: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "aim_midpoints: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself: the frame the guest left on
     * the stack (entry sp - 24) holds the three midpoints at +8, +12, +4 */
    const uint32_t frame = STACK_TOP - 24u;
    const uint8_t *stack = ref.shadow[2];
    static const unsigned slot_off[3] = { 8u, 12u, 4u };
    for (unsigned i = 0; i < 3; ++i) {
        const uint32_t want = mid_model(sc->second[i], sc->first[i]);
        const uint32_t got = r32(stack, frame - WIN3_BASE + slot_off[i]);
        if (got != want) {
            fprintf(stderr, "aim_midpoints: %s: frame+%u %08x, want %08x\n",
                    sc->name, slot_off[i], got, want);
            return 0;
        }
    }
    /* the saved r5 pointer in frame+0, and the push/pop round trip on the
     * matrix stack (count back to 1, top back to base+64, r4 = 1 << 6) */
    if (r32(stack, frame - WIN3_BASE) != R5_PTR ||
        ref.state.pc != RETURN_PC || ref.state.v[15] != STACK_TOP ||
        ref.state.v[14] != 0x76543210u + 14u ||
        ref.state.v[4] != 64u || ref.state.v[6] != 1u ||
        ref.state.v[7] != STACK_BASE + 128u) {
        fprintf(stderr, "aim_midpoints: %s: frame/r4/r6/r7/sp/r14/pc wrong\n",
                sc->name);
        return 0;
    }
    if ((r32(ref.shadow[3], STACK_CTL - WIN4_BASE) & 0xffffu) != 1u ||
        r32(ref.shadow[3], STACK_CTL - WIN4_BASE + 8u) != STACK_BASE + 64u) {
        fprintf(stderr, "aim_midpoints: %s: matrix stack not restored\n",
                sc->name);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_aim_midpoints_entry) {
        fprintf(stderr, "aim_midpoints: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* equal operands: the difference is zero */
        { .name = "equal",
          .first = { 1000, 2000, 3000 }, .second = { 1000, 2000, 3000 } },
        /* positive differences: the plain average */
        { .name = "positive",
          .first = { 2000, 4000, 6000 }, .second = { 1000, 2000, 3000 } },
        /* negative differences: the logical shift of the sign-extended
         * value, not the signed average */
        { .name = "negative",
          .first = { 1000, 2000, 3000 }, .second = { 2000, 4000, 6000 } },
        /* high-bit operands: the difference wraps through sixteen bits */
        { .name = "high-bit",
          .first = { 65000, 60000, 0 }, .second = { 100, 200, 65535 } },
        /* odd differences: the shifted-out bit is the last T */
        { .name = "odd",
          .first = { 1001, 2003, 3001 }, .second = { 1000, 2000, 3000 } },
        /* full range */
        { .name = "extremes",
          .first = { 0, 65535, 32768 }, .second = { 65535, 0, 32767 } },
        /* capture-ish values around the s29 pose fields */
        { .name = "capture-ish",
          .first = { 1234, 4567, 8910 }, .second = { 4321, 7654, 1987 } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("aim_midpoints: %u differential cases - PASS\n", cases);
    return 0;
}
