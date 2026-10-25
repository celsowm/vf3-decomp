/* state_rotate_replay.c - the readable fighter-vector rotator (SH-4 0x8C06DEC6)
 * against the retained generated translation.
 *
 * The port calls the rotation helper (0x8C09553C), which calls two leaves
 * (0x8C03A6E0 and 0x8C03A140).  The tree has readable ports for those two
 * leaves, but they leave a different r4 behind than the code the oracle ran,
 * so this test answers the leaves with a **stub** - in all three arms - and the
 * stub's answers are simple enough for the model below to predict:
 *
 *   the first leaf answers with its argument as a float,
 *   the second one answers with 1.0.
 *
 * The three arms are:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it).
 *
 * All three compare the whole register file (the FP registers and SR
 * included), the return PC, the failed PC, the out-of-window counter and every
 * RAM byte.
 *
 * The stack the fixture hands to the guest is filled with garbage, not zeroes:
 * the guest's private frame sits on it, so a store the port forgets shows up
 * in the result.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_state_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c06dec6u
#define RETURN_PC 0x0c0abcdeu

/* the helper's two leaves */
#define CALLEE_A  0x0c03a6e0u
#define CALLEE_B  0x0c03a140u

/* ---- the windows ---- */
#define POOL_BASE    0x0c06d000u   /* the literal pool */
#define POOL_LEN     0x1000u
#define HPOOL_BASE   0x0c095000u   /* the helper's own pool */
#define HPOOL_LEN    0x1000u
#define DATA_BASE    0x0c210000u   /* the fighter's struct and the global */
#define DATA_LEN     0x10000u
#define STACK_BASE   0x0c100000u
#define STACK_LEN    0x10000u
#define NWIN 5

#define OFF_POOL   0u
#define OFF_HPOOL  (OFF_POOL + POOL_LEN)
#define OFF_DATA   (OFF_HPOOL + HPOOL_LEN)
#define OFF_STACK  (OFF_DATA + DATA_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

/* ---- where things live ---- */
#define OBJECT     (DATA_BASE + 0xb000u)   /* the fighter's struct */
#define GLOBAL_PTR (DATA_BASE + 0xbf00u)   /* the global that points at it */
#define STACK_TOP  0x0c108000u
#define STRUCT_LEN 0x400u

/* The stack below the top is not clean in the real game: the guest's private
 * frame sits on whatever the stack held before, so the fixture fills it with
 * garbage.  A port that forgets one of the guest's own stores into that frame
 * then reads the garbage instead, and the differential sees it. */
#define STACK_GARBAGE 0x41a0a0a0u

/* ---- the pool's entries, and the values the image holds ---- */
#define P_OFF_SRC   (POOL_BASE + 0xfc4u)
#define P_OFF_ROT   (POOL_BASE + 0xfc6u)
#define P_OFF_PAIR  (POOL_BASE + 0xfc8u)
#define P_OBJECT    (POOL_BASE + 0xfccu)
#define P_HELPER    (POOL_BASE + 0xfe0u)
#define C_NEG_ONE   (POOL_BASE + 0xfdcu)    /* -1.0 */
#define C_HALF      (POOL_BASE + 0xfe4u)    /* 0.5 */
#define HP_CALLEE_A (HPOOL_BASE + 0x6f0u)
#define HP_CALLEE_B (HPOOL_BASE + 0x6f4u)

#define V_OFF_SRC   256u
#define V_OFF_ROT   984u
#define V_OFF_PAIR  968u
#define V_HELPER    0x0c09553cu
#define V_NEG_ONE   0xbf800000u
#define V_HALF      0x3f000000u
#define V_ONE       0x3f800000u

/* the struct's fields */
#define OBJ_ANGLE   30u
#define OBJ_A       0x70u
#define OBJ_B       0x78u
#define OBJ_C       0xb8u
#define OBJ_D       0xc0u
#define OBJ_SRC     0x100u

/* the guest's state at the entry */
#define FPSCR 0x00240001u

struct scenario {
    const char *name;
    int32_t angle;        /* the struct's halfword at +30 */
    float a, b, c, d;     /* the struct's vectors */
    float x, y;           /* the vector to rotate */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
    uint32_t base[NWIN];
    uint32_t len[NWIN];
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

static void wf32(uint8_t *p, uint32_t off, float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    w32(p, off, b);
}

static float as_float(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the stack: garbage, not zeroes - see STACK_GARBAGE */
    for (uint32_t off = 0; off < STACK_TOP - STACK_BASE; off += 4u)
        w32(p + OFF_STACK, off, STACK_GARBAGE);

    /* the literal pool, with the values the real image holds */
    w16(p + OFF_POOL, P_OFF_SRC  - POOL_BASE, (uint16_t)V_OFF_SRC);
    w16(p + OFF_POOL, P_OFF_ROT  - POOL_BASE, (uint16_t)V_OFF_ROT);
    w16(p + OFF_POOL, P_OFF_PAIR - POOL_BASE, (uint16_t)V_OFF_PAIR);
    w32(p + OFF_POOL, P_OBJECT   - POOL_BASE, GLOBAL_PTR);
    w32(p + OFF_POOL, P_HELPER   - POOL_BASE, V_HELPER);
    w32(p + OFF_POOL, C_NEG_ONE  - POOL_BASE, V_NEG_ONE);
    w32(p + OFF_POOL, C_HALF     - POOL_BASE, V_HALF);

    /* the helper's own pool: the two leaves it calls */
    w32(p + OFF_HPOOL, HP_CALLEE_A - HPOOL_BASE, CALLEE_A);
    w32(p + OFF_HPOOL, HP_CALLEE_B - HPOOL_BASE, CALLEE_B);

    /* the global that points at the struct */
    w32(p + OFF_DATA, GLOBAL_PTR - DATA_BASE, OBJECT);

    /* the struct itself */
    w16(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_ANGLE, (uint16_t)sc->angle);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_A, sc->a);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_B, sc->b);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_C, sc->c);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_D, sc->d);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_SRC, sc->x);
    wf32(p + OFF_DATA, OBJECT - DATA_BASE + OBJ_SRC + 8u, sc->y);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;              /* sr, with the T bit set */
    s->v[18] = FPSCR;
    s->v[21] = 0x40400000u;         /* fr0 - 3.0f */
    s->budget = 1000000u;

    r->base[0] = POOL_BASE;   r->len[0] = POOL_LEN;
    r->base[1] = HPOOL_BASE;  r->len[1] = HPOOL_LEN;
    r->base[2] = DATA_BASE;   r->len[2] = DATA_LEN;
    r->base[3] = STACK_BASE;  r->len[3] = STACK_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : i == 1 ? OFF_HPOOL
                             : i == 2 ? OFF_DATA : OFF_STACK);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

/* ---- the stub the helper's leaves are answered with ---- */
static int stub_leaf(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    (void)ram;
    if (entry == CALLEE_A) {
        /* the first leaf answers with its argument, as a float */
        *handled = 1;
        s->v[53] = s->v[4] & 0xffffu;
        s->v[21] = vf3_fpu_float(s->v[4], s->v[18]);
        s->pc = s->v[16];
        return 1;
    }
    if (entry == CALLEE_B) {
        /* the second one answers with 1.0 */
        *handled = 1;
        s->v[53] = s->v[4] & 0xffffu;
        s->v[21] = V_ONE;
        s->pc = s->v[16];
        return 1;
    }
    *handled = 0;
    return 0;
}

static int hook_stub(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    return stub_leaf(entry, s, ram, handled);
}

static int hook_readable(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                         int *handled)
{
    if (stub_leaf(entry, s, ram, handled)) return 1;
    if (*handled) return 1;
    return vf3_readable_override(entry, s, ram, handled);
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

/* ---- the model of the guest ---- *
 *
 * The helper rotates the two floats in the frame the guest hands it.  The guest
 * hands it -1.0 and 0.0, so after the call the frame holds
 *
 *   frame[0] = cos * (-1.0) - sin * 0.0 = -cos
 *   frame[4] = sin * (-1.0) + cos * 0.0 = -sin
 *
 * where the stub's first leaf answers with sin = float(the angle) and its
 * second one with cos = 1.0.
 */
#define FBIN(a, b, op) vf3_fpu_binary((a), (b), FPSCR, (op))
#define FMAC(a, b, c)  vf3_fpu_mac((a), (b), (c), FPSCR)

static uint32_t bits_of(float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    return b;
}

static void expect(const struct scenario *sc, uint8_t *out)
{
    const uint32_t sin = vf3_fpu_float((uint32_t)(int32_t)(int16_t)sc->angle, FPSCR);
    const uint32_t cos = V_ONE;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7, fr8, fr10, fr11, fr14, fr15;
    uint32_t frame0, frame4, rot_x, rot_y;

    /* what the helper leaves in the frame */
    fr6 = 0u;                                   /* the frame's second float */
    fr5 = V_NEG_ONE;                            /* the frame's first float */
    fr7 = FBIN(cos, fr6, '*');                  /* cos * 0.0 */
    fr4 = FBIN(cos, fr5, '*');                  /* cos * -1.0 */
    fr7 = FMAC(fr5, sin, fr7);                  /* -1.0 * sin + 0.0 */
    fr15 = FBIN(sin, fr6, '*');                 /* sin * 0.0 */
    frame4 = fr7;                               /* the frame's second float */
    frame0 = FBIN(fr4, fr15, '-');              /* cos * -1.0 - sin * 0.0 */

    /* the vector the guest turns */
    fr15 = bits_of(sc->x);
    fr14 = bits_of(sc->y);
    fr2 = frame0;
    fr3 = frame4;
    fr14 = FBIN(fr14, fr2, '+');
    fr15 = FBIN(fr15, fr3, '+');
    rot_x = fr15;                              /* the guest stores it now */
    rot_y = fr14;

    /* the four vectors the normalised pair comes from */
    fr4 = bits_of(sc->a);
    fr5 = bits_of(sc->b);
    fr8 = bits_of(sc->c);
    fr6 = bits_of(sc->d);
    fr7 = fr14;                                  /* fr7 = fr14 */
    fr11 = fr4;                                  /* fr11 = fr4 */
    fr11 = FBIN(fr11, fr15, '-');
    fr7 = FBIN(fr7, fr4, '*');
    fr10 = fr14;                                 /* fr10 = fr14 */
    fr15 = FBIN(fr15, fr5, '*');
    fr10 = FBIN(fr10, fr5, '-');
    fr3 = fr7;                                   /* fr3 = fr7 */
    fr7 = fr15;                                  /* fr7 = fr15 */
    fr7 = FBIN(fr7, fr3, '-');
    fr3 = fr4;                                   /* fr3 = fr4 */
    fr3 = FBIN(fr3, fr8, '+');
    frame4 = fr3;
    fr2 = fr5;                                   /* fr2 = fr5 */
    fr2 = FBIN(fr2, fr6, '+');
    frame0 = fr2;
    fr1 = frame4;
    fr1 = FBIN(fr1, V_HALF, '*');
    frame4 = fr1;
    fr3 = frame0;
    fr3 = FBIN(fr3, V_HALF, '*');
    frame0 = fr3;

    fr0 = fr10;                                  /* fr0 = fr10 */
    fr7 = FMAC(fr0, fr1, fr7);
    fr0 = fr11;                                  /* fr0 = fr11 */
    fr2 = fr7;                                   /* fr2 = fr7 */
    fr2 = FMAC(fr0, fr3, fr2);
    fr3 = 0u;
    fr7 = fr2;                                   /* fr7 = fr2 */

    /* what the guest leaves in the struct */
    memset(out, 0, STRUCT_LEN);
    w16(out, OBJ_ANGLE, (uint16_t)sc->angle);
    wf32(out, OBJ_A, sc->a);
    wf32(out, OBJ_B, sc->b);
    wf32(out, OBJ_C, sc->c);
    wf32(out, OBJ_D, sc->d);
    wf32(out, OBJ_SRC, sc->x);
    wf32(out, OBJ_SRC + 8u, sc->y);
    w32(out, V_OFF_ROT, rot_x);
    w32(out, V_OFF_ROT + 4u, rot_y);
    if (as_float(fr7) > as_float(fr3)) {
        w32(out, V_OFF_PAIR, fr8);
        w32(out, V_OFF_PAIR + 4u, fr6);
        w32(out, V_OFF_PAIR + 8u, fr4);
        w32(out, V_OFF_PAIR + 12u, fr5);
    } else {
        w32(out, V_OFF_PAIR, fr4);
        w32(out, V_OFF_PAIR + 4u, fr5);
        w32(out, V_OFF_PAIR + 8u, fr8);
        w32(out, V_OFF_PAIR + 12u, fr6);
    }
}

static unsigned cases;
static unsigned taken_positive;

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    vf3_family_override = hook_stub;
    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_state_rotate_entry(&port.state, &port.map);
    int handled = 0;
    vf3_family_override = hook_readable;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map, &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "state rotate: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "state rotate: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        uint8_t want[STRUCT_LEN];
        expect(sc, want);
        for (unsigned i = 0; i < STRUCT_LEN; ++i) {
            const uint8_t got = ref.wins[2].data[(OBJECT - DATA_BASE) + i];
            if (got != want[i]) {
                fprintf(stderr, "state rotate: %s: the struct's byte %u is %02x, "
                        "expected %02x\n", sc->name, i, got, want[i]);
                return 0;
            }
        }
        /* the sign the guest leaves behind */
        {
            const uint32_t sr = ref.state.v[17];
            const float f = as_float(ref.state.v[21 + 7]);
            const int positive = f > 0.0f;
            if (((sr & 1u) != 0u) != positive) {
                fprintf(stderr, "state rotate: %s: the T bit is %u, the value is %g\n",
                        sc->name, sr & 1u, (double)f);
                return 0;
            }
            if (positive) ++taken_positive;
        }
        /* the saved registers are back and the stack is where it was */
        if (ref.state.v[14] != 0x76543210u + 14u ||
            ref.state.v[15] != STACK_TOP ||
            ref.state.v[16] != RETURN_PC) {
            fprintf(stderr, "state rotate: %s: the saved registers are %08x/%08x/%08x\n",
                    sc->name, ref.state.v[14], ref.state.v[15], ref.state.v[16]);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_state_rotate_entry) {
        fprintf(stderr, "state rotate: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "the plain case", .angle = 0,
          .a = 1.0f, .b = 2.0f, .c = 3.0f, .d = 4.0f, .x = 5.0f, .y = 6.0f },
        { .name = "the angle is one", .angle = 1,
          .a = 1.0f, .b = 2.0f, .c = 3.0f, .d = 4.0f, .x = 5.0f, .y = 6.0f },
        { .name = "the angle is negative", .angle = -1,
          .a = 1.0f, .b = 2.0f, .c = 3.0f, .d = 4.0f, .x = 5.0f, .y = 6.0f },
        { .name = "the angle is big", .angle = 30000,
          .a = 1.0f, .b = 2.0f, .c = 3.0f, .d = 4.0f, .x = 5.0f, .y = 6.0f },
        { .name = "the angle is very negative", .angle = -30000,
          .a = 1.0f, .b = 2.0f, .c = 3.0f, .d = 4.0f, .x = 5.0f, .y = 6.0f },
        { .name = "the pair comes out positive", .angle = 0,
          .a = 3.0f, .b = 1.0f, .c = 1.0f, .d = 1.0f, .x = 0.0f, .y = 0.0f },
        { .name = "the pair comes out positive, twice", .angle = 7,
          .a = 3.0f, .b = 1.0f, .c = 1.0f, .d = 1.0f, .x = 0.5f, .y = 0.5f },
        { .name = "the vectors are negative", .angle = 2,
          .a = -1.0f, .b = -2.0f, .c = -3.0f, .d = -4.0f, .x = -5.0f, .y = -6.0f },
        { .name = "the vectors are tiny", .angle = 3,
          .a = 0.25f, .b = 0.5f, .c = 0.75f, .d = 1.5f, .x = 0.125f, .y = 2.5f },
        { .name = "the vectors are big", .angle = 4,
          .a = 100.0f, .b = 200.0f, .c = 300.0f, .d = 400.0f,
          .x = 500.0f, .y = 600.0f },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    /* both orders of the four floats have to be exercised */
    if (!taken_positive || taken_positive == cases) {
        fprintf(stderr, "state rotate: the scenarios do not cover both orders "
                "(%u of %u positive)\n", taken_positive, cases);
        return 1;
    }

    printf("state_rotate: %u differential cases - PASS\n", cases);
    return 0;
}
