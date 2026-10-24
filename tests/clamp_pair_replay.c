/* clamp_pair_replay.c - the readable clamp pair against the retained generated
 * translation of SH-4 0x8C08DCB0.
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
 * The function limits two numbers into three ranges and writes the four
 * results to four places - two of them addresses the caller leaves in its own
 * frame.  The test lays the literal pool and the caller's frame out and walks
 * the two numbers through the ranges.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_clamp_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c08dcb0u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the six bounds */
#define POOL_BASE 0x0c08dd48u
#define POOL_LEN  12u
#define X_LO  (POOL_BASE + 0x00u)
#define X_HI  (POOL_BASE + 0x02u)
#define Y1_LO (POOL_BASE + 0x04u)
#define Y1_HI (POOL_BASE + 0x06u)
#define Y2_LO (POOL_BASE + 0x08u)
#define Y2_HI (POOL_BASE + 0x0au)

/* the bounds themselves */
#define BOUND_X_LO  (-1000)
#define BOUND_X_HI  ( 1000)
#define BOUND_Y1_LO (-2000)
#define BOUND_Y1_HI ( 2000)
#define BOUND_Y2_LO (  -50)
#define BOUND_Y2_HI (   50)

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts below the two words the callee pushes */
#define STACK_WIN_BASE (STACK_TOP - 8u)
#define STACK_LEN      0x40u

/* the two words the caller leaves in its frame, and where they point */
#define FRAME_WORD0 STACK_TOP
#define FRAME_WORD1 (STACK_TOP + 4u)
#define FRAME_DEST0 (STACK_TOP + 0x10u)
#define FRAME_DEST1 (STACK_TOP + 0x14u)

/* the two register destinations */
#define DEST_X (STACK_TOP + 0x18u)
#define DEST_Y (STACK_TOP + 0x1cu)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_STACK (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t x;      /* the number the caller leaves in r4 */
    uint32_t y;      /* and the one in r5 */
    int flip;        /* the third range's bounds are the wrong way round */
};

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
    w16(p + OFF_POOL, X_LO  - POOL_BASE, (uint16_t)(int16_t)BOUND_X_LO);
    w16(p + OFF_POOL, X_HI  - POOL_BASE, (uint16_t)(int16_t)BOUND_X_HI);
    w16(p + OFF_POOL, Y1_LO - POOL_BASE, (uint16_t)(int16_t)BOUND_Y1_LO);
    w16(p + OFF_POOL, Y1_HI - POOL_BASE, (uint16_t)(int16_t)BOUND_Y1_HI);
    w16(p + OFF_POOL, Y2_LO - POOL_BASE, (uint16_t)(int16_t)(sc->flip ? BOUND_Y2_HI : BOUND_Y2_LO));
    w16(p + OFF_POOL, Y2_HI - POOL_BASE, (uint16_t)(int16_t)(sc->flip ? BOUND_Y2_LO : BOUND_Y2_HI));

    /* the caller's frame: the two destination addresses */
    w32(p + OFF_STACK, FRAME_WORD0 - STACK_WIN_BASE, FRAME_DEST0);
    w32(p + OFF_STACK, FRAME_WORD1 - STACK_WIN_BASE, FRAME_DEST1);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->x;
    s->v[5] = sc->y;
    s->v[6] = DEST_X;
    s->v[7] = DEST_Y;
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

/* the limit the fixture expects: the low bound first, like the guest */
static int32_t expect_limit(int32_t v, int32_t lo, int32_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
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
    const int ok_port = vf3_clamp_pair_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "clamp pair: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "clamp pair: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the four results, checked against the fixture itself */
    const int32_t x = (int32_t)sc->x;
    const int32_t y = (int32_t)sc->y;
    const int32_t y2_lo = sc->flip ? BOUND_Y2_HI : BOUND_Y2_LO;
    const int32_t y2_hi = sc->flip ? BOUND_Y2_LO : BOUND_Y2_HI;
    const int32_t x_limited = expect_limit(x, BOUND_X_LO, BOUND_X_HI);
    const int32_t y_first = expect_limit(y, BOUND_Y1_LO, BOUND_Y1_HI);
    const int32_t y_second = expect_limit(y, y2_lo, y2_hi);

    struct {
        const char *what;
        uint32_t addr;
        uint32_t want;
    } checks[] = {
        { "dest x",   DEST_X,     (uint32_t)x_limited },
        { "dest y",   DEST_Y,     (uint32_t)y_first },
        { "frame 0",  FRAME_DEST0, (uint32_t)x_limited },
        { "frame 1",  FRAME_DEST1, (uint32_t)y_second },
    };
    for (unsigned i = 0; i < sizeof checks / sizeof checks[0]; ++i) {
        const uint32_t got = shadow_word(&ref, checks[i].addr);
        if (got != checks[i].want) {
            fprintf(stderr, "clamp pair: %s: %s is %08x, expected %08x\n",
                    sc->name, checks[i].what, got, checks[i].want);
            return 0;
        }
    }

    /* the two limited values the guest still holds */
    if (ref.state.v[1] != (uint32_t)x_limited) {
        fprintf(stderr, "clamp pair: %s: r1 %08x != %08x\n",
                sc->name, ref.state.v[1], (uint32_t)x_limited);
        return 0;
    }
    if (ref.state.v[4] != (uint32_t)y_second) {
        fprintf(stderr, "clamp pair: %s: r4 %08x != %08x\n",
                sc->name, ref.state.v[4], (uint32_t)y_second);
        return 0;
    }
    /* the bounds it read last */
    if (ref.state.v[0] != (uint32_t)y2_hi ||
        ref.state.v[5] != (uint32_t)y2_lo) {
        fprintf(stderr, "clamp pair: %s: the last bounds are %08x/%08x\n",
                sc->name, ref.state.v[0], ref.state.v[5]);
        return 0;
    }
    /* the saved registers are back */
    if (ref.state.v[13] != 0x76543210u + 13u || ref.state.v[14] != 0x76543210u + 14u) {
        fprintf(stderr, "clamp pair: %s: the saved registers are %08x/%08x\n",
                sc->name, ref.state.v[13], ref.state.v[14]);
        return 0;
    }
    /* and the T bit: the last comparison the guest made */
    const int expect_t = (y >= y2_lo) ? (y > y2_hi) : 0;
    if (((ref.state.v[17] & 1u) != 0) != expect_t) {
        fprintf(stderr, "clamp pair: %s: the T bit is %u, expected %d\n",
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
    if (!reg || reg->fn != vf3_clamp_pair_entry) {
        fprintf(stderr, "clamp pair: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* both numbers inside every range */
        { "inside", 0u, 0u, 0 },
        /* the first number below and above its range */
        { "x below", (uint32_t)-5000, 0u, 0 },
        { "x above", 5000u, 0u, 0 },
        { "x at the low bound", (uint32_t)BOUND_X_LO, 0u, 0 },
        { "x at the high bound", (uint32_t)BOUND_X_HI, 0u, 0 },
        /* the second number below and above its first range */
        { "y below the first range", 0u, (uint32_t)-9000, 0 },
        { "y above the first range", 0u, 9000u, 0 },
        /* and below and above its second range */
        { "y below the second range", 0u, (uint32_t)-300, 0 },
        { "y above the second range", 0u, 300u, 0 },
        { "y at a bound", 0u, (uint32_t)BOUND_Y2_HI, 0 },
        { "y at the low bound", 0u, (uint32_t)BOUND_Y2_LO, 0 },
        /* negative numbers inside the ranges */
        { "negative", (uint32_t)-7, (uint32_t)-9, 0 },
        /* and both numbers outside at once */
        { "both outside", 5000u, (uint32_t)-9000, 0 },
        /* and a range whose bounds are the wrong way round: the guest tests
         * the low one first, so a value on it goes to the high one */
        { "inverted range", 0u, (uint32_t)BOUND_Y2_HI, 1 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("clamp_pair: %u differential cases - PASS\n", cases);
    return 0;
}
