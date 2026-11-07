/* pose_post_replay.c - the pose postprocessor (SH-4 0x8C09F432) and its
 * quantiser (0x8C09F500) against the retained generated translation.
 *
 * The wrapper runs five point clamps (0x8C09F5F8) around two quantiser calls.
 * The clamps and the quantiser are the **generated** bodies in both arms of the
 * comparison: the wrapper hands every call to vf3_guest_call, which dispatches
 * through the same chain the reference uses, so this test pins the wrapper's
 * own sequencing (which point each call gets, which destination each quantiser
 * writes, where the stack frame and the saved registers end up).
 *
 * The quantiser is a leaf, so its test compares its body on its own.
 *
 * Three arms, as in the other readable-port tests:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it; only the entry under test is served, so the
 *      nested calls still run the generated bodies).
 *
 * All three compare the whole register file (the FP registers and SR
 * included), the return PC, the failed PC, the out-of-window counter and every
 * RAM byte.
 *
 * On top of the differential, each case is checked against a model of the
 * quantiser written from the **fixture**: the three halfwords it writes into
 * the destination, the three floats it writes back into the source vector, and
 * the answer it leaves in r0/r2/r3/r5.  A differential passes even when the
 * fixture is wrong; this guard does not consult the translation.
 *
 * The stack is filled with garbage, not zeroes: the guest's private frames sit
 * on it, so a store the port forgets shows up in the result.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pose_post_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_pose_turns_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POST     0x0c09f432u
#define TURNS    0x0c09f500u
#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE    0x0c09f000u
#define POOL_LEN     0x1000u
#define ACTOR_BASE   0x0c200000u
#define ACTOR_LEN    0x4000u
#define GLOBAL_BASE  0x0c29b000u
#define GLOBAL_LEN   0x1000u
#define STACK_BASE   0x0c100000u
#define STACK_LEN    0x10000u
#define NWIN 4

#define OFF_POOL   0u
#define OFF_ACTOR  (OFF_POOL + POOL_LEN)
#define OFF_GLOBAL (OFF_ACTOR + ACTOR_LEN)
#define OFF_STACK  (OFF_GLOBAL + GLOBAL_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

#define STACK_TOP 0x0c108000u
#define STACK_GARBAGE 0x41a0a0a0u
#define GLOBAL_PTR 0x0c29b864u
#define GLOBAL_GATE 0x0c000000u

/* ---- the literal pool, with the values the real image holds ---- */
#define P_OFF_FIRST   (POOL_BASE + 0x4e6u)
#define P_DEST_FIRST  (POOL_BASE + 0x4e8u)
#define P_DEST_SECOND (POOL_BASE + 0x4eau)
#define P_F_16K       (POOL_BASE + 0x4ecu)
#define P_F_32K       (POOL_BASE + 0x4f0u)
#define P_F_M32K      (POOL_BASE + 0x4f4u)
#define P_F_24K       (POOL_BASE + 0x4f8u)
#define P_F_64K       (POOL_BASE + 0x4fcu)
#define P_BAND_HI     (POOL_BASE + 0x5e8u)
#define P_BAND_LO     (POOL_BASE + 0x5eau)
#define P_ACTOR_HI    (POOL_BASE + 0x5ecu)
#define P_ACTOR_LO    (POOL_BASE + 0x5eeu)
#define P_NEG_LIMIT   (POOL_BASE + 0x5f0u)
#define P_CANON_ADD   (POOL_BASE + 0x5f4u)
#define P_POINT_GLOB  (POOL_BASE + 0x6c0u)
#define P_POINT_MASK  (POOL_BASE + 0x6c4u)
#define P_POINT_UP    (POOL_BASE + 0x6c8u)
#define P_POINT_DOWN  (POOL_BASE + 0x6ccu)

/* the wrapper's offsets in the actor */
#define POINT_1     0x1d58u
#define POINT_2     0x1d64u
#define POINT_3     0x1dc4u
#define POINT_4     0x1dd0u
#define POINT_5     0x1de8u
#define DEST_1      0x233cu
#define DEST_2      0x2342u
/* the quantiser's sources in each of the wrapper's two paths: with the point
 * clamp's gate open every clamp answers its argument plus twelve, so the
 * quantiser reads 0x1DDC and 0x1DF4; with the gate closed the clamps answer
 * their argument unchanged, so it reads 0x1DAC and 0x1DB8. */
#define SRC_OPEN_1  0x1ddcu
#define SRC_OPEN_2  0x1df4u
#define SRC_SHUT_1  0x1dacu
#define SRC_SHUT_2  0x1db8u

#define ACTOR_FLAGS 0x3eu
#define ACTOR_KIND  0x61u
#define ACTOR_BAND_HI 0x1fb0u
#define ACTOR_BAND_MID 0x1facu
#define ACTOR_BAND_LO 0x1a00u

#define FPSCR 0x00040001u

struct scenario {
    const char *name;
    float x, y, z;
    uint16_t flags;      /* the actor's halfword at +0x3e, the band's value */
    uint16_t band_hi;    /* the actor's halfword at +0x1FB0 */
    uint16_t band_mid;   /* the actor's halfword at +0x1FAC */
    uint16_t band_lo;    /* the actor's halfword at +0x1A00 */
    uint8_t kind;        /* the actor's byte at +0x61 */
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

static uint32_t fbits(float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    return b;
}

static float as_float(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

/* the image's pool, word for word */
static void pool(uint8_t *p)
{
    w16(p, P_OFF_FIRST   - POOL_BASE, 0x1d58u);
    w16(p, P_DEST_FIRST  - POOL_BASE, 0x233cu);
    w16(p, P_DEST_SECOND - POOL_BASE, 0x2342u);
    w32(p, P_F_16K       - POOL_BASE, 0x46800000u);
    w32(p, P_F_32K       - POOL_BASE, 0x47000000u);
    w32(p, P_F_M32K      - POOL_BASE, 0xc7000000u);
    w32(p, P_F_24K       - POOL_BASE, 0x46c00000u);
    w32(p, P_F_64K       - POOL_BASE, 0x47800000u);
    w16(p, P_BAND_HI     - POOL_BASE, 0x5000u);
    w16(p, P_BAND_LO     - POOL_BASE, 0xb000u);
    w16(p, P_ACTOR_HI    - POOL_BASE, 0x1fb0u);
    w16(p, P_ACTOR_LO    - POOL_BASE, 0x1a00u);
    w16(p, P_NEG_LIMIT   - POOL_BASE, 0x7530u);
    w32(p, P_CANON_ADD   - POOL_BASE, 0x00008000u);
    w32(p, P_POINT_GLOB  - POOL_BASE, GLOBAL_PTR);
    w32(p, P_POINT_MASK  - POOL_BASE, GLOBAL_GATE);
    w32(p, P_POINT_UP    - POOL_BASE, 0x49200000u);   /* +655360.0 */
    w32(p, P_POINT_DOWN  - POOL_BASE, 0xc9200000u);   /* -655360.0 */
}

static void setup(struct run *r, const struct scenario *sc, int gate_open,
                  float x1, float y1, float z1, float x2, float y2, float z2,
                  uint32_t src1, uint32_t src2)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    for (uint32_t off = 0; off < STACK_LEN; off += 4u)
        w32(p + OFF_STACK, off, STACK_GARBAGE);

    pool(p + OFF_POOL);

    /* the point clamp's global: with a bit of 0x0C000000 set it is a no-op,
     * otherwise it runs its body. */
    w32(p + OFF_GLOBAL, GLOBAL_PTR - GLOBAL_BASE,
        gate_open ? 0u : GLOBAL_GATE);

    /* the actor's band words and kind */
    w16(p + OFF_ACTOR, ACTOR_FLAGS, sc->flags);
    w16(p + OFF_ACTOR, ACTOR_BAND_HI, sc->band_hi);
    w16(p + OFF_ACTOR, ACTOR_BAND_MID, sc->band_mid);
    w16(p + OFF_ACTOR, ACTOR_BAND_LO, sc->band_lo);
    p[OFF_ACTOR + ACTOR_KIND] = sc->kind;

    /* the five points: values a clamp stores back unchanged (|x| > 24576
     * makes its first test the one that fires) */
    {
        static const uint32_t pts[5] = { POINT_1, POINT_2, POINT_3, POINT_4, POINT_5 };
        for (unsigned i = 0; i < 5; ++i) {
            wf32(p + OFF_ACTOR, pts[i] + 0u, 30000.0f);
            wf32(p + OFF_ACTOR, pts[i] + 4u, 1000.0f);
            wf32(p + OFF_ACTOR, pts[i] + 8u, 30000.0f);
        }
    }

    /* the quantiser sources (in the closed-gate path these are two of the
     * points, which the closed clamp never reads) */
    wf32(p + OFF_ACTOR, src1 + 0u, x1);
    wf32(p + OFF_ACTOR, src1 + 4u, y1);
    wf32(p + OFF_ACTOR, src1 + 8u, z1);
    wf32(p + OFF_ACTOR, src2 + 0u, x2);
    wf32(p + OFF_ACTOR, src2 + 4u, y2);
    wf32(p + OFF_ACTOR, src2 + 8u, z2);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = ACTOR_BASE;           /* the actor */
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;         /* sr, T clear */
    s->v[18] = FPSCR;
    s->budget = 1000000u;

    r->base[0] = POOL_BASE;   r->len[0] = POOL_LEN;
    r->base[1] = ACTOR_BASE;  r->len[1] = ACTOR_LEN;
    r->base[2] = GLOBAL_BASE; r->len[2] = GLOBAL_LEN;
    r->base[3] = STACK_BASE;  r->len[3] = STACK_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : i == 1 ? OFF_ACTOR
                             : i == 2 ? OFF_GLOBAL : OFF_STACK);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

/* ---- the model of the quantiser, from the fixture's fields ---- */

struct quant {
    int wrote;
    uint16_t dest[3];
    uint32_t src[3];
    uint32_t r0, r2;
};

static void expect_quant(const struct scenario *sc, float x, float y, float z,
                         struct quant *q)
{
    const int32_t x0 = (int32_t)vf3_fpu_ftrc(fbits(x));
    const int32_t y0 = (int32_t)vf3_fpu_ftrc(fbits(y));
    const int32_t z0 = (int32_t)vf3_fpu_ftrc(fbits(z));
    int32_t x16 = (int16_t)((uint32_t)x0 & 0xffffu);
    int32_t yv = y0;
    uint32_t z16 = (uint32_t)z0 & 0xffffu;

    if (x16 > 0x5000 || x16 < -0x5000) {
        yv = 0x8000 - y0;
        z16 += 0x8000u;
        x16 += 0x8000;
    }
    const int32_t xq = (int16_t)((uint32_t)x16 & 0xffffu);
    int32_t zq = (int16_t)(z16 & 0xffffu);

    /* the band's value is the actor's own halfword at +0x3e, not x */
    const int32_t bandv = (int32_t)(uint16_t)sc->flags;
    const int32_t hi  = (int32_t)(uint16_t)sc->band_hi + 1;
    /* the middle bound is *not* masked by the guest: it is read with mov.w and
     * compared signed, so a halfword with its top bit set stays negative. */
    const int32_t mid = (int32_t)(int16_t)sc->band_mid + 1;
    const int32_t lo  = (int32_t)(uint16_t)sc->band_lo;
    const int32_t lo8 = lo - 8;
    const int32_t lo1 = lo + 1;

    q->wrote = (bandv == hi) || (bandv == lo8);
    q->dest[0] = (uint16_t)xq;
    q->dest[1] = (uint16_t)yv;
    q->dest[2] = (uint16_t)zq;

    /* the gate is reached from two places, and the second one is only tested
     * when the first one does not take it: between the high bound and the
     * middle bound (bandv > hi && bandv < mid), or - for a band value that is
     * at or below the high bound, or at or above the middle one - inside the
     * far band (lo8 < bandv < lo1). */
    int kind_gate;
    if ((int32_t)bandv > (int32_t)hi && (int32_t)bandv < (int32_t)mid)
        kind_gate = 1;
    else
        kind_gate = ((int32_t)bandv > (int32_t)lo8) &&
                    ((int32_t)bandv < (int32_t)lo1);
    if (kind_gate && sc->kind == 3u) {
        const int32_t mag = zq < 0 ? -zq : zq;
        if (mag > 0x7530) zq = -zq;
    }

    q->src[0] = vf3_fpu_float((uint32_t)xq, FPSCR);
    q->src[1] = vf3_fpu_float((uint32_t)yv, FPSCR);
    q->src[2] = vf3_fpu_float((uint32_t)zq, FPSCR);
    q->r0 = 12u;
    q->r2 = 8u;
}

/* ---- the arms ---- */

static uint32_t served_entry;

static int hook_only(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    if ((entry & 0x1fffffffu) != served_entry) { *handled = 0; return 0; }
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
                fprintf(stderr, "  %s: ram %u (addr %08x) %02x != %02x\n", what, i,
                        i < OFF_ACTOR ? POOL_BASE + i
                        : i < OFF_GLOBAL ? ACTOR_BASE + (i - OFF_ACTOR)
                        : i < OFF_STACK ? GLOBAL_BASE + (i - OFF_GLOBAL)
                        : STACK_BASE + (i - OFF_STACK),
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

static void read_halfs(const struct run *r, uint32_t off, uint16_t out[3])
{
    const uint8_t *p = r->wins[1].data + (off - ACTOR_BASE);
    out[0] = (uint16_t)(p[0] | (p[1] << 8));
    out[1] = (uint16_t)(p[2] | (p[3] << 8));
    out[2] = (uint16_t)(p[4] | (p[5] << 8));
}

static uint32_t read_word(const struct run *r, uint32_t off)
{
    const uint8_t *p = r->wins[1].data + (off - ACTOR_BASE);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static unsigned cases;

/* ---- the quantiser on its own ---- */

#define TURNS_SRC  0x2800u
#define TURNS_DEST 0x3000u
/* the second triple only has to stay clear of the first: the quantiser reads
 * one source vector, and a fixture that lays both triples on the same address
 * lets the second (all zeros) overwrite the first - which is exactly what the
 * first run of this test did. */
#define TURNS_SRC2 (TURNS_SRC + 0x40u)

static int compare_turns(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc, 1, sc->x, sc->y, sc->z, 0, 0, 0,
          TURNS_SRC, TURNS_SRC2);
    setup(&port, sc, 1, sc->x, sc->y, sc->z, 0, 0, 0,
          TURNS_SRC, TURNS_SRC2);
    setup(&hook, sc, 1, sc->x, sc->y, sc->z, 0, 0, 0,
          TURNS_SRC, TURNS_SRC2);
    ref.state.v[5] = ACTOR_BASE + TURNS_SRC;
    port.state.v[5] = ACTOR_BASE + TURNS_SRC;
    hook.state.v[5] = ACTOR_BASE + TURNS_SRC;
    ref.state.v[6] = ACTOR_BASE + TURNS_DEST;
    port.state.v[6] = ACTOR_BASE + TURNS_DEST;
    hook.state.v[6] = ACTOR_BASE + TURNS_DEST;
    /* the destination starts as garbage, so a forgotten store shows up */
    for (unsigned i = 0; i < 6; ++i)
        ref.shadow[OFF_ACTOR + TURNS_DEST + i] = 0xaa;
    memcpy(port.shadow, ref.shadow, SHADOW_LEN);
    memcpy(hook.shadow, ref.shadow, SHADOW_LEN);

    vf3_matrix_call_alias = 0u;
    vf3_matrix_call_alias_pc = 0xffffffffu;
    vf3_family_override = NULL;
    const int ok_ref = vf3_matrix_family(TURNS, &ref.state, &ref.map);
    const int ok_port = vf3_pose_turns_entry(&port.state, &port.map);
    served_entry = TURNS;
    vf3_family_override = hook_only;
    int handled = 0;
    const int ok_hook = vf3_readable_override(TURNS, &hook.state, &hook.map, &handled);
    vf3_family_override = NULL;

    if (!handled || ok_ref != ok_port || ok_ref != ok_hook ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "pose turns: %s differs (ok %d/%d/%d handled %d)\n",
                sc->name, ok_ref, ok_port, ok_hook, handled);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "pose turns: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        struct quant want;
        expect_quant(sc, sc->x, sc->y, sc->z, &want);
        uint16_t got[3];
        read_halfs(&ref, ACTOR_BASE + TURNS_DEST, got);
        for (unsigned i = 0; i < 3; ++i) {
            const uint16_t w = want.wrote ? want.dest[i] : 0xaaaa;
            if (got[i] != w) {
                fprintf(stderr, "pose turns: %s: the destination's halfword %u is "
                        "%04x, expected %04x\n", sc->name, i, got[i], w);
                return 0;
            }
        }
        for (unsigned i = 0; i < 3; ++i) {
            const uint32_t gotw = read_word(&ref, ACTOR_BASE + TURNS_SRC + 4u * i);
            if (gotw != want.src[i]) {
                fprintf(stderr, "pose turns: %s: the source's float %u is %08x, "
                        "expected %08x (src %08x r5 %08x r0 %08x)\n", sc->name, i,
                        gotw, want.src[i], ACTOR_BASE + TURNS_SRC,
                        ref.state.v[5], ref.state.v[0]);
                return 0;
            }
        }
        if (ref.state.v[0] != ACTOR_BASE + TURNS_SRC + want.r0 ||
            ref.state.v[5] != ACTOR_BASE + TURNS_SRC + want.r0 ||
            ref.state.v[2] != ACTOR_BASE + TURNS_SRC + want.r2 ||
            ref.state.v[3] != ACTOR_BASE + TURNS_SRC + want.r2) {
            fprintf(stderr, "pose turns: %s: the answers are %08x/%08x/%08x/%08x\n",
                    sc->name, ref.state.v[0], ref.state.v[2], ref.state.v[3],
                    ref.state.v[5]);
            return 0;
        }
        /* the saved registers and the stack are back */
        for (unsigned i = 8; i <= 14; ++i)
            if (ref.state.v[i] != 0x76543210u + i) {
                fprintf(stderr, "pose turns: %s: r%u is %08x\n", sc->name, i,
                        ref.state.v[i]);
                return 0;
            }
        if (ref.state.v[15] != STACK_TOP || ref.state.v[16] != RETURN_PC) {
            fprintf(stderr, "pose turns: %s: sp/pr are %08x/%08x\n", sc->name,
                    ref.state.v[15], ref.state.v[16]);
            return 0;
        }
    }

    ++cases;
    return 1;
}

/* ---- the wrapper ---- */

struct wrap_case {
    const char *name;
    int gate_open;
    struct scenario band;
    float x1, y1, z1;
    float x2, y2, z2;
};

static int compare_post(const struct wrap_case *wc)
{
    const uint32_t src1 = ACTOR_BASE + (wc->gate_open ? SRC_OPEN_1 : SRC_SHUT_1);
    const uint32_t src2 = ACTOR_BASE + (wc->gate_open ? SRC_OPEN_2 : SRC_SHUT_2);
    struct run ref, port, hook;
    setup(&ref, &wc->band, wc->gate_open,
          wc->x1, wc->y1, wc->z1, wc->x2, wc->y2, wc->z2,
          wc->gate_open ? SRC_OPEN_1 : SRC_SHUT_1,
          wc->gate_open ? SRC_OPEN_2 : SRC_SHUT_2);
    setup(&port, &wc->band, wc->gate_open,
          wc->x1, wc->y1, wc->z1, wc->x2, wc->y2, wc->z2,
          wc->gate_open ? SRC_OPEN_1 : SRC_SHUT_1,
          wc->gate_open ? SRC_OPEN_2 : SRC_SHUT_2);
    setup(&hook, &wc->band, wc->gate_open,
          wc->x1, wc->y1, wc->z1, wc->x2, wc->y2, wc->z2,
          wc->gate_open ? SRC_OPEN_1 : SRC_SHUT_1,
          wc->gate_open ? SRC_OPEN_2 : SRC_SHUT_2);

    for (unsigned i = 0; i < 6; ++i) {
        ref.shadow[OFF_ACTOR + DEST_1 + i] = 0xaa;
        ref.shadow[OFF_ACTOR + DEST_2 + i] = 0xaa;
    }
    memcpy(port.shadow, ref.shadow, SHADOW_LEN);
    memcpy(hook.shadow, ref.shadow, SHADOW_LEN);

    vf3_matrix_call_alias = 0u;
    vf3_matrix_call_alias_pc = 0xffffffffu;
    vf3_family_override = NULL;
    const int ok_ref = vf3_matrix_family(POST, &ref.state, &ref.map);
    const int ok_port = vf3_pose_post_entry(&port.state, &port.map);
    served_entry = POST;
    vf3_family_override = hook_only;
    int handled = 0;
    const int ok_hook = vf3_readable_override(POST, &hook.state, &hook.map, &handled);
    vf3_family_override = NULL;

    if (!handled || ok_ref != ok_port || ok_ref != ok_hook ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "pose post: %s differs (ok %d/%d/%d handled %d)\n",
                wc->name, ok_ref, ok_port, ok_hook, handled);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "pose post: %s reads outside the windows (oob %u/%u/%u)\n",
                wc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        struct quant q1, q2;
        expect_quant(&wc->band, wc->x1, wc->y1, wc->z1, &q1);
        expect_quant(&wc->band, wc->x2, wc->y2, wc->z2, &q2);
        static const uint32_t dests[2] = { DEST_1, DEST_2 };
        const struct quant *want[2] = { &q1, &q2 };
        for (unsigned k = 0; k < 2; ++k) {
            uint16_t got[3];
            read_halfs(&ref, ACTOR_BASE + dests[k], got);
            for (unsigned i = 0; i < 3; ++i) {
                const uint16_t w = want[k]->wrote ? want[k]->dest[i] : 0xaaaa;
                if (got[i] != w) {
                    fprintf(stderr, "pose post: %s: destination %u's halfword %u "
                            "is %04x, expected %04x\n", wc->name, k, i, got[i], w);
                    return 0;
                }
            }
        }
        const uint32_t srcs[2] = { src1, src2 };
        for (unsigned k = 0; k < 2; ++k) {
            for (unsigned i = 0; i < 3; ++i) {
                const uint32_t gotw = read_word(&ref, srcs[k] + 4u * i);
                if (gotw != want[k]->src[i]) {
                    fprintf(stderr, "pose post: %s: source %u's float %u is %08x, "
                            "expected %08x\n", wc->name, k, i, gotw, want[k]->src[i]);
                    return 0;
                }
            }
        }
        if (ref.state.v[0] != src2 + 12u || ref.state.v[5] != src2 + 12u ||
            ref.state.v[2] != src2 + 8u || ref.state.v[3] != src2 + 8u) {
            fprintf(stderr, "pose post: %s: the answers are %08x/%08x/%08x/%08x\n",
                    wc->name, ref.state.v[0], ref.state.v[2], ref.state.v[3],
                    ref.state.v[5]);
            return 0;
        }
        /* the wrapper's saved registers and its stack are back */
        if (ref.state.v[14] != 0x76543210u + 14u ||
            ref.state.v[15] != STACK_TOP || ref.state.v[16] != RETURN_PC) {
            fprintf(stderr, "pose post: %s: r14/sp/pr are %08x/%08x/%08x\n",
                    wc->name, ref.state.v[14], ref.state.v[15], ref.state.v[16]);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the two ports must be registered, or the native tick never reaches them */
    const vf3_readable_entry *post = vf3_readable_find(POST);
    const vf3_readable_entry *turns = vf3_readable_find(TURNS);
    if (!post || post->fn != vf3_pose_post_entry ||
        !turns || turns->fn != vf3_pose_turns_entry) {
        fprintf(stderr, "pose post: the ports are not registered\n");
        return 1;
    }

    /* the quantiser's scenarios: both canonicalisation arms, both band edges,
     * the open band, and the kind-3 negation either way */
    static const struct scenario turn_cases[] = {
        /* name, x, y, z, flags, band_hi, band_mid, band_lo, kind */
        { "the plain case",           1.5f,  2.5f,  3.5f,  0, 5, 7, 20, 0 },
        { "the canonicalisation high", 24577.0f, 100.0f, 200.0f, 0, 5, 7, 20, 0 },
        { "the canonicalisation low", -24577.0f, 100.0f, 200.0f, 0, 5, 7, 20, 0 },
        { "at the canonicalisation bound", 20480.0f, 1.0f, 2.0f, 0, 5, 7, 20, 0 },
        { "at the canonicalisation's low bound", -20480.0f, 1.0f, 2.0f, 0, 5, 7, 20, 0 },
        { "just above the bound",     20481.0f, 1.0f, 2.0f, 0, 5, 7, 20, 0 },
        { "just below the bound",    -20481.0f, 1.0f, 2.0f, 0, 5, 7, 20, 0 },
        { "the band's high edge",     1.0f,  2.0f,  3.0f,  6, 5, 7, 20, 0 },
        { "the band's low edge",      1.0f,  2.0f,  3.0f,  12, 5, 7, 20, 0 },
        { "the open band, low side",  1.0f,  2.0f,  3.0f,  7, 5, 7, 20, 0 },
        { "the open band, high side", 1.0f,  2.0f,  3.0f,  11, 5, 7, 20, 0 },
        { "outside the band",         1.0f,  2.0f,  3.0f,  40, 5, 7, 20, 0 },
        { "the kind-3 gate is shut",  1.0f,  2.0f,  30001.0f, 40, 5, 7, 20, 0 },
        { "kind 3 above the limit",   1.0f,  2.0f,  30001.0f, 40, 5, 7, 20, 3 },
        { "kind 3 below the limit",   1.0f,  2.0f, -30001.0f, 40, 5, 7, 20, 3 },
        { "kind 3 inside the limit",  1.0f,  2.0f,  30000.0f, 40, 5, 7, 20, 3 },
        { "kind 3, z is small",       1.0f,  2.0f,  3.0f,  40, 5, 7, 20, 3 },
        { "the edges coincide",       1.0f,  2.0f,  3.0f,  6, 5, 7, 14, 0 },
        { "the band's lo1 edge",      1.0f,  2.0f,  0.5f,  21, 5, 7, 20, 0 },
        { "the band's lo1 edge, kind 3", 1.0f, 2.0f, 0.5f, 21, 5, 7, 20, 3 },
        { "the kind gate above the limit", 1.0f, 2.0f, 32000.0f, 13, 5, 7, 20, 3 },
        { "the kind gate below the limit", 1.0f, 2.0f, -32000.0f, 13, 5, 7, 20, 3 },
        { "the kind gate, z inside the limit", 1.0f, 2.0f, 30000.0f, 13, 5, 7, 20, 3 },
        { "the kind gate, another kind", 1.0f, 2.0f, 32000.0f, 13, 5, 7, 20, 4 },
        { "the kind gate between hi and mid", 1.0f, 2.0f, 32000.0f, 7, 5, 7, 20, 3 },
        { "a negative x",             -1.5f, 2.5f,  3.5f,  0, 5, 7, 20, 0 },
        { "the wrapped high bound",   1.0f,  2.0f,  32000.0f, 7, 65530, 7, 20, 3 },
        { "the wrapped middle bound", 1.0f,  2.0f,  32000.0f, 7, 5, 65530, 20, 3 },
        { "the wrapped low bound",    1.0f,  2.0f,  32000.0f, 65525, 5, 7, 65530, 3 },
        { "the high edge, kind 3",    1.0f,  2.0f,  32000.0f, 6, 5, 7, 20, 3 },
        /* the destination write and the kind gate are not exclusive: the high
         * edge falls into the inside path, whose second test reaches the gate
         * when lo8 < hi < lo1; the low edge reaches it through the middle
         * path when hi < lo8 < mid.  Both pairs matter because the destination
         * keeps the un-negated z'' while the source gets the negated one. */
        { "the high edge inside the kind band", 1.0f, 2.0f, 32000.0f, 6, 5, 10, 10, 3 },
        { "the low edge inside the kind band",  1.0f, 2.0f, 32000.0f, 12, 5, 15, 20, 3 },
        { "at the middle bound",      1.0f,  2.0f,  32000.0f, 8, 5, 7, 20, 3 },
        { "the lo8 edge, kind 3",     1.0f,  2.0f,  32000.0f, 12, 5, 7, 20, 3 },
        { "just below the lo1 edge",  1.0f,  2.0f,  32000.0f, 20, 5, 7, 20, 3 },
        { "the band wraps",           1.0f,  2.0f,  3.0f,  65530, 0, 7, 3, 0 },
        { "negative y",               1.0f, -2.0f, -3.0f,  6, 5, 7, 20, 0 },
        { "big y",                    1.0f,  70000.0f, 3.0f, 6, 5, 7, 20, 0 },
        { "negative big y",           1.0f, -70000.0f, 3.0f, 6, 5, 7, 20, 0 },
        { "fractional values",        1.9f, -2.9f, 2.1f,  6, 5, 7, 20, 3 },
    };
    for (unsigned i = 0; i < sizeof turn_cases / sizeof turn_cases[0]; ++i)
        if (!compare_turns(&turn_cases[i])) return 1;

    /* the wrapper's scenarios: both paths of the point clamp, both quantiser
     * destinations, the kind gate and the bands */
    static const struct wrap_case post_cases[] = {
        { "the clamp's gate is open, the band is quiet", 1,
          { "w1", 1.5f, 2.5f, 3.5f, 0, 5, 7, 20, 0 },
          10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f },
        { "the clamp's gate is shut, the band is quiet", 0,
          { "w2", 1.5f, 2.5f, 3.5f, 0, 5, 7, 20, 0 },
          10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f },
        { "both destinations are written", 1,
          { "w3", 1.0f, 2.0f, 3.0f, 6, 5, 7, 20, 0 },
          1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f },
        { "both destinations are written, gate shut", 0,
          { "w4", 1.0f, 2.0f, 3.0f, 6, 5, 7, 20, 0 },
          1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f },
        { "the vectors are canonicalised", 1,
          { "w5", 1.0f, 2.0f, 3.0f, 12, 5, 7, 20, 0 },
          24577.0f, 100.0f, 200.0f, -24577.0f, -100.0f, -200.0f },
        { "kind 3 negates both z values", 1,
          { "w6", 1.0f, 2.0f, 3.0f, 40, 5, 7, 20, 3 },
          1.0f, 2.0f, 30001.0f, 4.0f, 5.0f, -30001.0f },
        { "kind 3 leaves the small z alone", 0,
          { "w7", 1.0f, 2.0f, 3.0f, 40, 5, 7, 20, 3 },
          1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f },
        { "the band's high edge", 1,
          { "w8", 1.0f, 2.0f, 3.0f, 6, 5, 7, 20, 0 },
          -1.5f, 2.5f, -3.5f, 4.5f, -5.5f, 6.5f },
        { "the open band sends both to the kind gate", 0,
          { "w9", 1.0f, 2.0f, 3.0f, 11, 5, 7, 20, 3 },
          1.0f, 2.0f, 30001.0f, 4.0f, 5.0f, -30001.0f },
        { "big values", 1,
          { "w10", 1.0f, 2.0f, 3.0f, 40, 5, 7, 20, 0 },
          70000.0f, -70000.0f, 70000.0f, -70000.0f, 70000.0f, -70000.0f },
        { "the kind gate negates through both legs", 1,
          { "w11", 1.0f, 2.0f, 3.0f, 13, 5, 7, 20, 3 },
          1.0f, 2.0f, 32000.0f, 4.0f, 5.0f, -32000.0f },
        { "the lo1 edge leaves both alone", 0,
          { "w12", 1.0f, 2.0f, 3.0f, 21, 5, 7, 20, 3 },
          1.0f, 2.0f, 32000.0f, 4.0f, 5.0f, -32000.0f },
        { "the canonicalisation's low bound", 1,
          { "w13", 1.0f, 2.0f, 3.0f, 6, 5, 7, 20, 0 },
          -20480.0f, 100.0f, 200.0f, -20481.0f, -100.0f, -200.0f },
        { "negative values through the wrapper", 1,
          { "w14", 1.0f, 2.0f, 3.0f, 0, 5, 7, 20, 0 },
          -1.5f, -2.5f, -3.5f, 4.5f, 5.5f, 6.5f },
        { "the destinations are written inside the kind band", 1,
          { "w15", 1.0f, 2.0f, 3.0f, 6, 5, 10, 10, 3 },
          1.0f, 2.0f, 32000.0f, 4.0f, 5.0f, -32000.0f },
    };
    for (unsigned i = 0; i < sizeof post_cases / sizeof post_cases[0]; ++i)
        if (!compare_post(&post_cases[i])) return 1;

    printf("pose_post: %u differential cases - PASS\n", cases);
    return 0;
}
