/* move_cap_replay.c - the readable capped move against the retained generated
 * translation of SH-4 0x8C08DD5C.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run three times: once through the generated chain (the
 * reference), once called directly and once through the readable override,
 * which is how the native tick reaches it.
 *
 * The function moves a position by the difference between the old one and the
 * current one, but never by more than the longest movement the literal pool
 * holds.  The test lays the pool and the frame out and walks the movement
 * through the cap: shorter than the cap, longer than it, and exactly zero.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_move_cap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c08dd5cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the epsilon and the longest movement */
#define POOL_BASE 0x0c08ddc8u
#define POOL_LEN  8u
#define EPSILON_OFF 0u
#define MAXSTEP_OFF 4u

/* the epsilon the guest will not measure a difference against: 1e-7 */
#define EPSILON_BITS 0x33d6bf94u
/* the longest movement the function allows: two units */
#define MAXSTEP_BITS 0x40000000u
/* and the same movement, but negative: the factor comes out negative then */
#define MAXSTEP_NEG_BITS 0xc0800000u

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts at the frame's first word, twelve bytes below the
 * guest's stack pointer */
#define STACK_WIN_BASE (STACK_TOP - 12u)
#define STACK_LEN      0x40u

/* the two words the current position lives in */
#define POS_X (STACK_TOP + 0x10u)
#define POS_Y (STACK_TOP + 0x14u)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_STACK (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t old_x;   /* the position at the start of the frame */
    uint32_t old_y;
    uint32_t cur_x;   /* and the position it has now */
    uint32_t cur_y;
    int neg_step;     /* the pool's longest movement is negative */
};

/* the pool's longest movement, as the scenario lays it out */
static uint32_t step_bits(const struct scenario *sc)
{
    return sc->neg_step ? MAXSTEP_NEG_BITS : MAXSTEP_BITS;
}

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[2];
    vf3_ram_map map;
};

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
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

    /* the literal pool */
    w32(p + OFF_POOL, EPSILON_OFF, EPSILON_BITS);
    w32(p + OFF_POOL, MAXSTEP_OFF, step_bits(sc));

    /* the current position */
    w32(p + OFF_STACK, POS_X - STACK_WIN_BASE, sc->cur_x);
    w32(p + OFF_STACK, POS_Y - STACK_WIN_BASE, sc->cur_y);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->old_x;
    s->v[5] = sc->old_y;
    s->v[6] = POS_X;
    s->v[7] = POS_Y;
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_STACK; r->wins[1].base = STACK_WIN_BASE; r->wins[1].len = STACK_LEN;
    r->map.wins = r->wins;
    r->map.n = 2;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

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

/* the movement the fixture expects, worked out from the pool's own values with
 * the same FPU primitives the guest uses */
static void expect_move(const struct scenario *sc, uint32_t *out_x, uint32_t *out_y)
{
    const uint32_t fpscr = 0;
    const int32_t dx = (int32_t)(sc->cur_x - sc->old_x);
    const int32_t dy = (int32_t)(sc->cur_y - sc->old_y);
    const uint32_t fx = vf3_fpu_float((uint32_t)dx, fpscr);
    const uint32_t fy = vf3_fpu_float((uint32_t)dy, fpscr);

    /* the squared length, with the guest's fused multiply-add */
    const uint32_t sq = vf3_fpu_mac(fy, fy, vf3_fpu_binary(fx, fx, fpscr, '*'), fpscr);

    /* the inverse length, unless the difference is too short to measure */
    uint32_t inverse = 0;
    if (!(vf3_bits_f32(EPSILON_BITS) > vf3_bits_f32(sq)))
        vf3_fpu_fsrra(sq, fpscr, &inverse);

    /* the length, and the factor the movement is scaled by */
    const uint32_t len = vf3_fpu_binary(sq, inverse, fpscr, '*');
    uint32_t factor = vf3_fpu_binary(step_bits(sc), len, fpscr, '/');
    factor &= 0x7fffffffu;

    if (vf3_bits_f32(0x3f800000u) > vf3_bits_f32(factor)) {
        const uint32_t sx = vf3_fpu_binary(fx, factor, fpscr, '*');
        const uint32_t sy = vf3_fpu_binary(fy, factor, fpscr, '*');
        *out_x = sc->old_x + (uint32_t)vf3_f_trunc(vf3_bits_f32(sx));
        *out_y = sc->old_y + (uint32_t)vf3_f_trunc(vf3_bits_f32(sy));
    } else {
        /* too short to be capped: the integer difference is kept */
        *out_x = sc->old_x + (uint32_t)dx;
        *out_y = sc->old_y + (uint32_t)dy;
    }
}

static uint32_t shadow_word(const struct run *r, uint32_t addr)
{
    const uint32_t off = OFF_STACK + (addr - STACK_WIN_BASE);
    return (uint32_t)r->shadow[off + 0]
         | ((uint32_t)r->shadow[off + 1] << 8)
         | ((uint32_t)r->shadow[off + 2] << 16)
         | ((uint32_t)r->shadow[off + 3] << 24);
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_move_cap_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "move cap: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "move cap: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the new position, checked against the fixture itself */
    uint32_t want_x, want_y;
    expect_move(sc, &want_x, &want_y);
    const uint32_t got_x = shadow_word(&ref, POS_X);
    const uint32_t got_y = shadow_word(&ref, POS_Y);
    if (got_x != want_x || got_y != want_y) {
        fprintf(stderr, "move cap: %s: the position is %08x/%08x, expected %08x/%08x\n",
                sc->name, got_x, got_y, want_x, want_y);
        return 0;
    }

    /* the pool address the guest leaves behind */
    if (ref.state.v[0] != POOL_BASE + MAXSTEP_OFF) {
        fprintf(stderr, "move cap: %s: r0 %08x != %08x\n",
                sc->name, ref.state.v[0], POOL_BASE + MAXSTEP_OFF);
        return 0;
    }
    /* and the T bit: the last comparison the guest made */
    uint32_t factor_check = 0;
    {
        const uint32_t fpscr = 0;
        const int32_t dx = (int32_t)(sc->cur_x - sc->old_x);
        const int32_t dy = (int32_t)(sc->cur_y - sc->old_y);
        const uint32_t fx = vf3_fpu_float((uint32_t)dx, fpscr);
        const uint32_t fy = vf3_fpu_float((uint32_t)dy, fpscr);
        const uint32_t sq = vf3_fpu_mac(fy, fy, vf3_fpu_binary(fx, fx, fpscr, '*'), fpscr);
        uint32_t inverse = 0;
        if (!(vf3_bits_f32(EPSILON_BITS) > vf3_bits_f32(sq)))
            vf3_fpu_fsrra(sq, fpscr, &inverse);
        const uint32_t len = vf3_fpu_binary(sq, inverse, fpscr, '*');
        factor_check = vf3_fpu_binary(step_bits(sc), len, fpscr, '/') & 0x7fffffffu;
    }
    const int expect_t = (vf3_bits_f32(0x3f800000u) > vf3_bits_f32(factor_check));
    if (((ref.state.v[17] & 1u) != 0) != expect_t) {
        fprintf(stderr, "move cap: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, expect_t);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_move_cap_entry) {
        fprintf(stderr, "move cap: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* no movement at all: the difference is too short to measure */
        { "still", 100u, 200u, 100u, 200u, 0 },
        /* a movement shorter than the cap: the whole difference is kept */
        { "short", 100u, 200u, 101u, 200u, 0 },
        { "short diagonal", 0u, 0u, 3u, 4u, 0 },
        /* a movement longer than the cap: it is scaled down to the cap */
        { "long", 0u, 0u, 10u, 0u, 0 },
        { "long diagonal", 0u, 0u, 30u, 40u, 0 },
        /* and one exactly at the cap */
        { "at the cap", 0u, 0u, 2u, 0u, 0 },
        /* and one just over it */
        { "just over the cap", 0u, 0u, 3u, 0u, 0 },
        /* negative movements */
        { "negative", 0u, 0u, (uint32_t)-10, (uint32_t)-5, 0 },
        /* and one big enough that the squares are not exact in a float */
        { "big", 0u, 0u, 1000000u, 1000000u, 0 },
        /* and one where the pool's longest movement is negative, so the
         * factor is negative too and its absolute value matters */
        { "negative cap", 0u, 0u, 1u, 0u, 1 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("move_cap: %u differential cases - PASS\n", cases);
    return 0;
}
