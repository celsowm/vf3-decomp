/* tenpp_fill_replay.c - the readable tenpp leaf structure filler
 * (SH-4 0x8C0C103C) against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are
 * the generated chain (the reference), the readable port called directly, and
 * the readable port reached through the readable override.
 *
 * The body is a straight scan: it fills a node structure at r4 with a fixed
 * pattern (the five bytes +16..+20 set to 0xff, the halfwords +22..+30 and
 * +32..+40 cleared, the words +44..+60 cleared) and clears the auxiliary
 * cell's word at r5+20, then leaves r0 = 0x28 (the last offset), r3 = r4+16,
 * r5 = the widened 0xff (-1) and r6 = 0, and returns through r16.  Nothing
 * else moves, so r4, the stack pointer and SR are part of the contract too.
 *
 * The window mirrors the captured corpus: one 0x2000 window at 0x0c404000
 * holding both the node and the cell.  The scenarios vary the two pointers so
 * a port (or a fixture) that miscalculates an offset reads bytes the guest
 * never wrote, and every window byte is patterned first so wrong addresses
 * show up as mismatches rather than as coincidentally-zero stores.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_tenpp_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0c103cu

#define RETURN_PC 0x0c0432e4u

/* the one window, mirroring the corpus' 0x0c404000 / len 0x2000 */
#define WIN_BASE 0x0c404000u
#define WIN_LEN  0x2000u
#define SHADOW_LEN WIN_LEN

struct scenario {
    const char *name;
    uint32_t r4;   /* the node */
    uint32_t r5;   /* the auxiliary cell */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[1];
    vf3_ram_map map;
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

static uint16_t r16(const uint8_t *p, uint32_t off)
{
    return (uint16_t)((uint16_t)p[off] | ((uint16_t)p[off + 1] << 8));
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);
    /* pattern every byte so a wrong address reads a non-guest value */
    for (unsigned i = 0; i < SHADOW_LEN; i += 4)
        w32(p, i, 0x11111111u + (i & 0xff));

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->r4;
    s->v[5] = sc->r5;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;             /* sr */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->budget = 4000000u;

    r->wins[0].base = WIN_BASE;
    r->wins[0].len = WIN_LEN;
    r->wins[0].data = p;
    r->map.wins = r->wins;
    r->map.n = 1;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static const uint8_t *at(const uint8_t *shadow, uint32_t addr, uint32_t size)
{
    if (addr >= WIN_BASE && addr + size <= WIN_BASE + WIN_LEN)
        return shadow + (addr - WIN_BASE);
    return NULL;
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

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_tenpp_fill_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "tenpp_fill: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "tenpp_fill: %s reads outside the window "
                "(oob %u/%u/%u)\n", sc->name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself, independent of the port */
    const uint32_t r4 = sc->r4, r5 = sc->r5;
    const uint8_t *q;
    /* the output registers */
    if (ref.state.v[0] != 0x28u || ref.state.v[3] != r4 + 0x10u ||
        ref.state.v[5] != 0xffffffffu || ref.state.v[6] != 0u) {
        fprintf(stderr, "tenpp_fill: %s: outputs r0 %08x r3 %08x r5 %08x "
                "r6 %08x, expected %08x %08x %08x 0\n", sc->name,
                ref.state.v[0], ref.state.v[3], ref.state.v[5],
                ref.state.v[6], 0x28u, r4 + 0x10u, 0xffffffffu);
        return 0;
    }
    /* r4, r15, pr unchanged */
    if (ref.state.v[4] != r4 || ref.state.v[15] != 0x76543210u + 15u ||
        ref.state.v[16] != RETURN_PC) {
        fprintf(stderr, "tenpp_fill: %s: r4/r15/pr drifted\n", sc->name);
        return 0;
    }
    /* the node's five 0xff bytes at +16..+20 */
    for (unsigned off = 16; off <= 20; ++off) {
        q = at(ref.shadow, r4 + off, 1);
        if (!q || q[0] != 0xffu) {
            fprintf(stderr, "tenpp_fill: %s: node +%u is %02x, expected ff\n",
                    sc->name, off, q ? q[0] : 0u);
            return 0;
        }
    }
    /* the cleared halfwords +22..+30 and +32..+40 */
    for (unsigned off = 22; off <= 30; off += 2) {
        q = at(ref.shadow, r4 + off, 2);
        if (!q || r16(q, 0) != 0u) {
            fprintf(stderr, "tenpp_fill: %s: node halfword +%u not cleared\n",
                    sc->name, off);
            return 0;
        }
    }
    for (unsigned off = 0x20; off <= 0x28; off += 2) {
        q = at(ref.shadow, r4 + off, 2);
        if (!q || r16(q, 0) != 0u) {
            fprintf(stderr, "tenpp_fill: %s: node halfword +%u not cleared\n",
                    sc->name, off);
            return 0;
        }
    }
    /* the cleared words +44..+60 */
    for (unsigned off = 44; off <= 60; off += 4) {
        q = at(ref.shadow, r4 + off, 4);
        if (!q || r32(q, 0) != 0u) {
            fprintf(stderr, "tenpp_fill: %s: node word +%u not cleared\n",
                    sc->name, off);
            return 0;
        }
    }
    /* the auxiliary cell's word at +20 is cleared */
    q = at(ref.shadow, r5 + 20u, 4);
    if (!q || r32(q, 0) != 0u) {
        fprintf(stderr, "tenpp_fill: %s: cell word +20 not cleared\n",
                sc->name);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_tenpp_fill_entry) {
        fprintf(stderr, "tenpp_fill: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "the corpus' own node",   .r4 = 0x0c404000u, .r5 = 0x0c405000u },
        { .name = "node before cell",       .r4 = 0x0c404020u, .r5 = 0x0c405010u },
        { .name = "node shifted up",        .r4 = 0x0c404080u, .r5 = 0x0c404200u },
        { .name = "cell inside node region",.r4 = 0x0c404100u, .r5 = 0x0c404140u },
        { .name = "large offsets in window",.r4 = 0x0c405f00u, .r5 = 0x0c405e80u },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("tenpp_fill: %u differential cases - PASS\n", cases);
    return 0;
}
