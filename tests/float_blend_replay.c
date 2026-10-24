/* float_blend_replay.c - the readable float blend against the retained
 * generated translation of SH-4 0x8C03E810.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function copies four floats out of an array and into a structure of four
 * slots, and then writes a weighted sum over three of the slots back into the
 * first one.  The test lays the literal pool, the array, the structure and the
 * caller's stack out the way the guest expects.  The scenarios cover a plain
 * blend, a blend over negative numbers, a blend with round-toward-zero and the
 * double-precision FPSCR, where the float loads are eight bytes wide.
 *
 * The test also checks the result against the fixture on its own: a
 * differential alone is not enough, because a fixture that is not where the
 * guest looks makes both sides read the same wrong bytes and agree on them.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_float_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c03e810u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the structure and the three weights */
#define POOL_BASE 0x0c03e8a0u
#define POOL_LEN  0x20u
#define G_DEST (POOL_BASE + 0x04u)
#define G_A    (POOL_BASE + 0x08u)
#define G_B    (POOL_BASE + 0x0cu)
#define G_C    (POOL_BASE + 0x10u)

/* the array of four floats */
#define SRC_BASE 0x0c180000u
#define SRC_LEN  0x40u

/* the structure of four slots */
#define DST_BASE 0x0c190000u
#define DST_LEN  0x40u

/* the caller's stack: the function pushes eight bytes below it */
#define STACK_BASE 0x0c107ff0u
#define STACK_LEN  0x20u
#define SP 0x0c108000u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_SRC   (OFF_POOL + POOL_LEN)
#define OFF_DST   (OFF_SRC + SRC_LEN)
#define OFF_STACK (OFF_DST + DST_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t fpscr;         /* the FPSCR the caller leaves */
    float src[4];           /* the array's four floats */
    float w[3];             /* the three weights */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[5];
    vf3_ram_map map;
};

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

/* the step along the array: eight bytes when the FPSCR is double */
static uint32_t step(const struct scenario *sc)
{
    return (sc->fpscr & 0x100000u) ? 8u : 4u;
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w32(p + OFF_POOL, G_DEST - POOL_BASE, DST_BASE);
    w32(p + OFF_POOL, G_A - POOL_BASE, vf3_f32_bits(sc->w[0]));
    w32(p + OFF_POOL, G_B - POOL_BASE, vf3_f32_bits(sc->w[1]));
    w32(p + OFF_POOL, G_C - POOL_BASE, vf3_f32_bits(sc->w[2]));

    /* the array: one float per cell, the cells a step apart */
    for (unsigned i = 0; i < 4; ++i)
        w32(p + OFF_SRC, i * step(sc), vf3_f32_bits(sc->src[i]));

    /* the structure starts with something, so a byte that is not written
     * shows up */
    memset(p + OFF_DST, 0xa5u, DST_LEN);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = SRC_BASE;            /* the array */
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = sc->fpscr;          /* the FPSCR */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;  r->wins[0].base = POOL_BASE;  r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_SRC;   r->wins[1].base = SRC_BASE;   r->wins[1].len = SRC_LEN;
    r->wins[2].data = p + OFF_DST;   r->wins[2].base = DST_BASE;   r->wins[2].len = DST_LEN;
    r->wins[3].data = p + OFF_STACK; r->wins[3].base = STACK_BASE; r->wins[3].len = STACK_LEN;
    r->map.wins = r->wins;
    r->map.n = 4;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

/* The result, read straight off the fixture: the structure's slots three and
 * four have to hold the array's third and fourth float, and in single
 * precision the second slot holds the array's second float and the first slot
 * holds the blend.  This does not consult the generated translation, so it
 * also catches a fixture that is not where the guest looks.
 *
 * The double-precision FPSCR is a special case: the stores are eight bytes
 * wide there, so the slot at +4 and the slot at +8 overlap and the blend's
 * own store - eight bytes at the slot at +0 - reaches over the slot at +4.
 * Only the two slots that survive are checked. */
static int slot_is(const uint8_t *dst, unsigned i, float want)
{
    uint32_t w = vf3_f32_bits(want);
    uint32_t got = (uint32_t)dst[i * 4 + 0]
                 | ((uint32_t)dst[i * 4 + 1] << 8)
                 | ((uint32_t)dst[i * 4 + 2] << 16)
                 | ((uint32_t)dst[i * 4 + 3] << 24);
    return got == w;
}

static int expected(const struct run *r, const struct scenario *sc,
                    const char **why)
{
    const uint8_t *dst = r->shadow + OFF_DST;
    const int wide = (sc->fpscr & 0x100000u) != 0;

    if (!slot_is(dst, 2, sc->src[2])) {
        *why = "the third slot does not hold the array's float";
        return 0;
    }
    if (!slot_is(dst, 3, sc->src[3])) {
        *why = "the fourth slot does not hold the array's float";
        return 0;
    }

    if (!wide) {
        if (!slot_is(dst, 1, sc->src[1])) {
            *why = "the second slot does not hold the array's float";
            return 0;
        }
        /* the first slot holds the blend, which the test computes on its own */
        vf3_matrix_state s;
        memset(&s, 0, sizeof s);
        s.v[18] = sc->fpscr;
        float blend = vf3_f_mul(&s, sc->src[2], sc->w[0]);
        blend = vf3_f_mac(&s, sc->w[1], sc->src[1], blend);
        blend = vf3_f_mac(&s, sc->w[2], sc->src[3], blend);
        if (!slot_is(dst, 0, blend)) {
            *why = "the first slot does not hold the blend";
            return 0;
        }
    }
    return 1;
}

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

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_float_blend_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "float blend: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "float blend: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* and the result is checked against the fixture itself */
    const char *why = "";
    if (!expected(&ref, sc, &why)) {
        fprintf(stderr, "float blend: %s: %s\n", sc->name, why);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_float_blend_entry) {
        fprintf(stderr, "float blend: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        { "plain",     0u,
          { 1.0f, 2.0f, 3.0f, 4.0f },
          { 0.5f, 0.25f, 0.125f } },
        { "negatives", 0u,
          { -1.5f, 2.25f, -3.75f, 4.5f },
          { -0.5f, 0.75f, 2.0f } },
        /* round toward zero: the FPSCR's rounding mode */
        { "truncate",  0x180u,
          { 1.0f / 3.0f, 2.0f / 3.0f, 1.0f, -1.0f / 7.0f },
          { 1.0f / 3.0f, 1.0f / 5.0f, 1.0f / 9.0f } },
        /* the double-precision FPSCR: the loads are eight bytes wide */
        { "double",    0x100000u,
          { 1.0f, 2.0f, 3.0f, 4.0f },
          { 0.5f, 0.25f, 0.125f } },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("float_blend: %u differential cases - PASS\n", cases);
    return 0;
}
