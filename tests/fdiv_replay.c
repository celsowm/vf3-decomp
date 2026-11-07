/* fdiv_replay.c - the readable float division / reciprocal helper
 * (SH-4 0x8C0533A4) against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are
 * the generated chain (the reference), the readable port called directly, and
 * the readable port reached through the readable override.
 *
 * The body is pure bit-twiddling with no FPU instructions: it stores fr0 on
 * the stack, pops it into r0, reads three of its four literal-pool scratch
 * constants, and does a carry-rotate fixed-point software reciprocal.  The
 * answer goes into a two-word cell whose address the caller leaves at sp+16:
 *
 *     cell[0] <- r3   the exponent / status word
 *     cell[1] <- r0   the packed result word
 *
 * and the four caller-saved registers come back from the stack.  The branch
 * it takes is the input's exponent byte (the top byte of 2*r0, masked 0xff):
 *
 *   * 0xff -> infinity or NaN (spread across two cases below);
 *   * 0    -> zero or denormal (three cases);
 *   * else -> the ordinary path (the rest).
 *
 * The fixture uses the game's own addresses - the pool at 0x0c053000, the
 * stack at 0x0c31fa0c, the result cell at 0x0c2a7000 - but every value the
 * guest follows is moved around, and every window is filled with its own
 * pattern first, so a port (or a fixture) that reads the wrong address sees
 * bytes that are not the ones the guest meant.
 *
 * Besides the byte-exact comparison of all three arms, the test checks the
 * outcome against the fixture itself: the two words written to the cell, the
 * T bit the guest leaves and the four caller-saved registers it restores.
 * The expected cell words are the module's own answers for each input, pinned
 * here as literals, and the caller-register check is independent of the port -
 * r0..r3 have to come back as the distinct values that sat at sp+0/+4/+8/+12,
 * so a port that pops them in the wrong order fails even though both arms read
 * the same stack.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_fdiv_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0533a4u

#define RETURN_PC 0x0c0432e4u

/* ---- the windows: the game's own addresses ---- */
#define POOL_BASE   0x0c053000u   /* the literal pool */
#define POOL_LEN    0x1000u
#define STACK_BASE  0x0c31f000u   /* the stack */
#define STACK_LEN   0x1000u
#define RESULT_BASE 0x0c2a7000u   /* the result cell */
#define RESULT_LEN  0x1000u
#define NWIN 3

#define OFF_POOL    0u
#define OFF_STACK   (OFF_POOL + POOL_LEN)
#define OFF_RESULT  (OFF_STACK + STACK_LEN)
#define SHADOW_LEN  (OFF_RESULT + RESULT_LEN)

#define SP (STACK_BASE + 0xa0cu)   /* the entry stack pointer */

/* the offsets of the four scratch constants inside the pool window */
#define P_MASK    0x418u   /* 0x000000ff */
#define P_INF     0x420u   /* 0x000007ff */
#define P_QQNAN   0x424u   /* 0x7ff00000 */
#define P_BIAS    0x428u   /* 0x00000380 */

/* the caller-saved registers, sat at sp+0/+4/+8/+12 */
#define CALLER_R3 0x10201020u
#define CALLER_R2 0x20402040u
#define CALLER_R1 0x30603060u
#define CALLER_R0 0x40804080u

static const struct {
    uint32_t base;
    uint32_t len;
    uint32_t off;
} windows[NWIN] = {
    { POOL_BASE,   POOL_LEN,   OFF_POOL },
    { STACK_BASE,  STACK_LEN,  OFF_STACK },
    { RESULT_BASE, RESULT_LEN, OFF_RESULT },
};

struct scenario {
    const char *name;
    uint32_t fr0;            /* the dividend's bits the caller left in fr0 */
    uint32_t cell_r3;        /* the word the guest writes to cell[0] */
    uint32_t cell_r0;        /* the word the guest writes to cell[1] */
    int t;                   /* the T bit the guest leaves */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
};

static const uint8_t *at(const uint8_t *shadow, uint32_t addr, uint32_t size)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= windows[i].base &&
            addr + size <= windows[i].base + windows[i].len)
            return shadow + windows[i].off + (addr - windows[i].base);
    return NULL;
}

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

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    memset(p + OFF_POOL,   0x11, POOL_LEN);
    memset(p + OFF_STACK,  0x55, STACK_LEN);
    memset(p + OFF_RESULT, 0x77, RESULT_LEN);

    /* the pool's four scratch constants, at the game's own offsets */
    w32(p + OFF_POOL, P_MASK,  0x000000ffu);
    w32(p + OFF_POOL, P_INF,   0x000007ffu);
    w32(p + OFF_POOL, P_QQNAN, 0x7ff00000u);
    w32(p + OFF_POOL, P_BIAS,  0x00000380u);

    /* the caller's frame: four saved registers, then the result-cell pointer
     * at sp+16.  The transient fr0 store lands at sp-4. */
    w32(p + OFF_STACK, SP - STACK_BASE + 0u,  CALLER_R3);
    w32(p + OFF_STACK, SP - STACK_BASE + 4u,  CALLER_R2);
    w32(p + OFF_STACK, SP - STACK_BASE + 8u,  CALLER_R1);
    w32(p + OFF_STACK, SP - STACK_BASE + 12u, CALLER_R0);
    w32(p + OFF_STACK, SP - STACK_BASE + 16u, RESULT_BASE);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;             /* sr */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->v[21] = sc->fr0;                 /* fr0: the dividend's bits */
    s->budget = 4000000u;

    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = windows[i].base;
        r->wins[i].len = windows[i].len;
        r->wins[i].data = p + windows[i].off;
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
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
    const int ok_port = vf3_fdiv_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                               &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "fdiv: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "fdiv: %s reads outside the windows "
                "(oob %u/%u/%u)\n", sc->name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        const uint8_t *cell = at(ref.shadow, RESULT_BASE, 8);
        if (!cell || r32(cell, 0) != sc->cell_r3 || r32(cell, 4) != sc->cell_r0) {
            fprintf(stderr, "fdiv: %s: cell is %08x/%08x, expected "
                    "%08x/%08x\n", sc->name,
                    cell ? r32(cell, 0) : 0u, cell ? r32(cell, 4) : 0u,
                    sc->cell_r3, sc->cell_r0);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != sc->t) {
            fprintf(stderr, "fdiv: %s: the T bit is %u, expected %d\n",
                    sc->name, ref.state.v[17] & 1u, sc->t);
            return 0;
        }
        if (ref.state.v[3] != CALLER_R3 || ref.state.v[2] != CALLER_R2 ||
            ref.state.v[1] != CALLER_R1 || ref.state.v[0] != CALLER_R0) {
            fprintf(stderr, "fdiv: %s: the caller's registers are %08x %08x "
                    "%08x %08x, expected %08x %08x %08x %08x\n", sc->name,
                    ref.state.v[0], ref.state.v[1], ref.state.v[2],
                    ref.state.v[3],
                    CALLER_R0, CALLER_R1, CALLER_R2, CALLER_R3);
            return 0;
        }
        /* the stack pointer advances by twenty */
        if (ref.state.v[15] != SP + 20u) {
            fprintf(stderr, "fdiv: %s: the stack pointer is %08x, expected "
                    "%08x\n", sc->name, ref.state.v[15], SP + 20u);
            return 0;
        }
        /* the transient store left fr0's bits at sp-4 */
        const uint8_t *junk = at(ref.shadow, SP - 4u, 4);
        if (!junk || r32(junk, 0) != sc->fr0) {
            fprintf(stderr, "fdiv: %s: the transient slot at sp-4 is %08x, "
                    "expected %08x\n", sc->name, junk ? r32(junk, 0) : 0u,
                    sc->fr0);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_fdiv_entry) {
        fprintf(stderr, "fdiv: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* infinity: exponent 0xff, mantissa zero -> the infinity exponent
         * 0x7ff through the shared pack. */
        { .name = "infinity",
          .fr0 = 0x7f800000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x7ff00000u,
          .t = 0 },
        /* NaN: exponent 0xff, mantissa non-zero -> the quiet-NaN constant,
         * status 1, straight to the tail. */
        { .name = "NaN",
          .fr0 = 0x7fa00000u, .cell_r3 = 0x00000001u, .cell_r0 = 0x7ff00000u,
          .t = 0 },
        /* zero: exponent 0 and mantissa zero -> the shared pack. */
        { .name = "zero",
          .fr0 = 0x00000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x00000000u,
          .t = 0 },
        /* the smallest denormal: mantissa normalised up, exponent counted
         * down into the bias. */
        { .name = "smallest denormal",
          .fr0 = 0x00000001u, .cell_r3 = 0x00000000u, .cell_r0 = 0x36a00000u,
          .t = 0 },
        /* a denormal in the middle of its range. */
        { .name = "denormal 0x0000007f",
          .fr0 = 0x0000007fu, .cell_r3 = 0x00000000u, .cell_r0 = 0x370fc000u,
          .t = 0 },
        /* 1.0: the ordinary path. */
        { .name = "one",
          .fr0 = 0x3f800000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x3ff00000u,
          .t = 0 },
        /* 2.0: the ordinary path, a different exponent byte. */
        { .name = "two",
          .fr0 = 0x40000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x40000000u,
          .t = 0 },
        /* -2.0: the same exponent, the sign bit set (the raw input's bit 31
         * feeds the shll at 0x533d2).  The corpus carries 0xc0000000. */
        { .name = "minus two",
          .fr0 = 0xc0000000u, .cell_r3 = 0x00000000u, .cell_r0 = 0xc0000000u,
          .t = 0 },
        /* a normal with mantissa bits beyond bit 31 of 2*r0, so the pack has
         * something real to rotate. */
        { .name = "0x40a4a000",
          .fr0 = 0x40a4a000u, .cell_r3 = 0x00000000u, .cell_r0 = 0x40149400u,
          .t = 0 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("fdiv: %u differential cases - PASS\n", cases);
    return 0;
}
