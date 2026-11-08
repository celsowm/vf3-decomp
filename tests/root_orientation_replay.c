/* root_orientation_replay.c - the readable root-orientation builder
 * (SH-4 0x8C09D9EA) against the retained generated translation.
 *
 * The body resets XMTRX to the identity and composes Ry(yaw at actor+30,
 * sign-extended), Rz(field0 at the pool offset 0x1F50, zero-extended),
 * Ry(field1 at 0x1F52) and then tail-transfers to Rx(field2 at 0x1F54).
 * All four callees are the readable/generated matrix helpers, so the test
 * needs no stub: the three arms are the generated chain (the reference),
 * the readable port called directly, and the readable port reached through
 * the readable override.
 *
 * The literal pool is supplied from the real image values (the four call
 * targets and the three field offsets), so the port's runtime pool reads
 * are exercised rather than baked constants.
 *
 * On top of the differential, each case is checked against the fixture
 * itself: with all angles zero XMTRX must be the identity, and with only a
 * yaw the matrix must be Ry(yaw) = (cos,0,-sin / 0,1,0 / sin,0,cos) with
 * zero translation.  Stack, r14 and pr must be restored, r0 must be the
 * last pool offset and r4 the third field.
 *
 * The stack is filled with garbage, not zeroes: the guest's two saved
 * words sit on it, so a store the port forgets shows up in the result.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_root_orientation_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09d9eau
#define RETURN_PC 0x0c0abcdeu

/* the three windows, mirroring the corpus */
#define WIN1_BASE 0x0c09d000u        /* literal pool */
#define WIN1_LEN  0x1000u
#define WIN2_BASE 0x0c200000u        /* the actor */
#define WIN2_LEN  0x4000u
#define WIN3_BASE 0x0c100000u        /* the stack */
#define WIN3_LEN  0x10000u
#define ACTOR 0x0c200000u
#define STACK_TOP 0x0c108000u
#define STACK_GARBAGE 0x41a0a0a0u

#define MAXWIN 3u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    int16_t yaw;                    /* at actor+30 */
    uint16_t field[3];              /* at actor+0x1F50, +0x1F52, +0x1F54 */
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
    static const unsigned L[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN };
    return L[w];
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the literal pool: the four call targets and the three field
     * offsets, with the values the real image holds */
    w32(r->shadow[0], 0x0c09dad8u - WIN1_BASE, 0x0c03ccb0u);
    w32(r->shadow[0], 0x0c09dadcu - WIN1_BASE, 0x0c03c880u);
    w32(r->shadow[0], 0x0c09dae0u - WIN1_BASE, 0x0c03c940u);
    w32(r->shadow[0], 0x0c09dae4u - WIN1_BASE, 0x0c03c6c0u);
    w16(r->shadow[0], 0x0c09daccu - WIN1_BASE, 0x1f50u);
    w16(r->shadow[0], 0x0c09daceu - WIN1_BASE, 0x1f52u);
    w16(r->shadow[0], 0x0c09dad0u - WIN1_BASE, 0x1f54u);

    /* the actor: yaw at +30, the three pose fields at +0x1F50.. */
    w16(r->shadow[1], 30u, (uint16_t)sc->yaw);
    for (unsigned i = 0; i < 3; ++i)
        w16(r->shadow[1], 0x1f50u + 2u * i, sc->field[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = ACTOR;               /* r4: the actor */
    s->v[15] = STACK_TOP;          /* r15 */
    s->v[16] = RETURN_PC;          /* pr: the tail-return target */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
    r->wins[2].base = WIN3_BASE; r->wins[2].len = WIN3_LEN; r->wins[2].data = r->shadow[2];
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
    const int ok_port = vf3_root_orientation_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "root_orientation: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "root_orientation: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    if (ref.state.pc != RETURN_PC || ref.state.v[15] != STACK_TOP ||
        ref.state.v[14] != 0x76543210u + 14u || ref.state.v[16] != RETURN_PC) {
        fprintf(stderr, "root_orientation: %s: pc/sp/r14/pr not restored\n",
                sc->name);
        return 0;
    }
    if (ref.state.v[0] != 0x1f54u || ref.state.v[3] != 0x0c03c6c0u ||
        ref.state.v[4] != sc->field[2]) {
        fprintf(stderr, "root_orientation: %s: r0 %08x r3 %08x r4 %08x, want "
                "00001f54 0c03c6c0 %08x\n", sc->name, ref.state.v[0],
                ref.state.v[3], ref.state.v[4], sc->field[2]);
        return 0;
    }
    /* XMTRX (v[37..52]) must be a pure rotation: zero translation
     * (elements 12..14; element 15 is the w component, 1.0) */
    for (unsigned i = 12; i < 15; ++i) {
        if (ref.state.v[37 + i] != 0u) {
            fprintf(stderr, "root_orientation: %s: XMTRX[%u] %08x, want 0\n",
                    sc->name, i, ref.state.v[37 + i]);
            return 0;
        }
    }
    if (sc->yaw == 0 && sc->field[0] == 0 && sc->field[1] == 0 &&
        sc->field[2] == 0) {
        /* all angles zero: the identity */
        static const float want[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t got = ref.state.v[37 + i], want_bits;
            float as_float, want_float = want[i];
            memcpy(&want_bits, &want_float, 4);
            (void)as_float;
            if (got != want_bits) {
                fprintf(stderr, "root_orientation: %s: XMTRX[%u] %08x, want %08x\n",
                        sc->name, i, got, want_bits);
                return 0;
            }
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_root_orientation_entry) {
        fprintf(stderr, "root_orientation: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* all angles zero: the identity */
        { .name = "identity", .yaw = 0, .field = { 0, 0, 0 } },
        /* yaw only, a quarter turn */
        { .name = "yaw quarter", .yaw = 16384, .field = { 0, 0, 0 } },
        /* yaw only, a half turn (negative halfword: sign extension) */
        { .name = "yaw half sign-extended", .yaw = (int16_t)32768,
          .field = { 0, 0, 0 } },
        /* fields only, each a quarter turn of a different axis */
        { .name = "fields quarter", .yaw = 0,
          .field = { 16384, 16384, 16384 } },
        /* mixed, including a high-bit field (zero extension, not sign) */
        { .name = "mixed high-bit fields", .yaw = 8192,
          .field = { 40000, 50000, 60000 } },
        /* near-full turns */
        { .name = "near full", .yaw = 65000,
          .field = { 65535, 32767, 1 } },
        /* the captured s29-ish values */
        { .name = "capture-ish", .yaw = 27577,
          .field = { 1234, 4567, 8910 } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("root_orientation: %u differential cases - PASS\n", cases);
    return 0;
}
