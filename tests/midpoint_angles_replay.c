/* midpoint_angles_replay.c - the readable three-angle wrapper
 * (SH-4 0x8C09D452) against the retained generated translation.
 *
 * The wrapper saves r4/r5/r6 as halfwords in a twelve-byte frame and
 * calls rotate_z with r6's, rotate_y with r5's and then tail-transfers
 * to rotate_x with r4's.  The callees are the readable rotation leaves,
 * so the test needs no stub: the three arms are the generated chain
 * (the reference), the readable port called directly, and the readable
 * port reached through the readable override.
 *
 * Two windows: the literal pool at 0x0c09d000 (the three handler
 * pointers at 0x0c09d580..) and the stack.  XMTRX starts as the
 * identity, so the fixture model is the plain composition
 * Rz(r6) * Ry(r5) * Rx(r4) built in the test from its own sinf/cosf -
 * a differential passes even when the fixture is laid out where the
 * guest never looks, so this guard does not consult the translation.
 * The frame bytes are checked too: the wrapper writes the three
 * halfwords there and they stay in the stack shadow.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_midpoint_angles_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09d452u
#define RETURN_PC 0x0c0abcdeu

#define WIN1_BASE 0x0c09d000u        /* literal pool */
#define WIN1_LEN  0x1000u
#define WIN2_BASE 0x0c100000u        /* the stack */
#define WIN2_LEN  0x10000u
#define STACK_TOP 0x0c108000u

#define MAXWIN 2u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    uint16_t angle[3];              /* r4, r5, r6 */
};

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static unsigned win_len(unsigned w)
{
    static const unsigned L[MAXWIN] = { WIN1_LEN, WIN2_LEN };
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

    /* the literal pool: the three handler pointers, as in the image */
    w32(r->shadow[0], 0x0c09d580u - WIN1_BASE, 0x0c03c940u);
    w32(r->shadow[0], 0x0c09d584u - WIN1_BASE, 0x0c03c880u);
    w32(r->shadow[0], 0x0c09d588u - WIN1_BASE, 0x0c03c6c0u);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->angle[0];
    s->v[5] = sc->angle[1];
    s->v[6] = sc->angle[2];
    s->v[15] = STACK_TOP;          /* r15 */
    s->v[16] = RETURN_PC;          /* pr: the tail-return target */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;
    /* XMTRX starts as the identity so the model is the plain composition */
    for (unsigned i = 0; i < 16; ++i) s->v[37 + i] = 0u;
    s->v[37] = s->v[42] = s->v[47] = s->v[52] = 0x3f800000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
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

static void ident(float out[16])
{
    memset(out, 0, 16u * sizeof *out);
    out[0] = out[5] = out[10] = out[15] = 1.0f;
}

static void rot_y(float sine, float cosine, float out[16])
{
    ident(out);
    out[0] = cosine; out[2] = -sine; out[8] = sine; out[10] = cosine;
}

static void rot_z(float sine, float cosine, float out[16])
{
    ident(out);
    out[0] = cosine; out[1] = sine; out[4] = -sine; out[5] = cosine;
}

static void rot_x(float sine, float cosine, float out[16])
{
    ident(out);
    out[5] = cosine; out[6] = sine; out[9] = -sine; out[10] = cosine;
}

/* column-major multiply, the same convention the fixture model uses for
 * every composition - independent of the port under test */
static void multiply(const float a[16], const float b[16], float out[16])
{
    float tmp[16];
    for (unsigned col = 0; col < 4; ++col)
        for (unsigned row = 0; row < 4; ++row) {
            float sum = 0.0f;
            for (unsigned k = 0; k < 4; ++k)
                sum += a[k * 4u + row] * b[col * 4u + k];
            tmp[col * 4u + row] = sum;
        }
    memcpy(out, tmp, sizeof tmp);
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_midpoint_angles_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "midpoint_angles: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "midpoint_angles: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    /* r4 is the zero-extended first halfword; r0 keeps the sign-extended
     * second one (the extu only lands in the callee's r4) */
    if (ref.state.pc != RETURN_PC || ref.state.v[15] != STACK_TOP ||
        ref.state.v[14] != 0x76543210u + 14u ||
        ref.state.v[3] != 0x0c03c6c0u ||
        ref.state.v[4] != (sc->angle[0] & 0xffffu) ||
        ref.state.v[0] != (uint32_t)(int32_t)(int16_t)sc->angle[1]) {
        fprintf(stderr, "midpoint_angles: %s: pc/sp/r14/r3/r4/r0 wrong\n",
                sc->name);
        return 0;
    }
    /* the frame the guest left on the stack (entry sp - 16): the three
     * halfwords, in r4/r5/r6 order */
    {
        const uint32_t frame = STACK_TOP - 16u;
        const uint8_t *stack = ref.shadow[1];
        for (unsigned i = 0; i < 3; ++i) {
            const uint32_t got = (uint32_t)stack[frame - WIN2_BASE + 4u * i] |
                ((uint32_t)stack[frame - WIN2_BASE + 4u * i + 1] << 8);
            if (got != (sc->angle[i] & 0xffffu)) {
                fprintf(stderr, "midpoint_angles: %s: frame+%u %08x, want %08x\n",
                        sc->name, 4u * i, got, sc->angle[i] & 0xffffu);
                return 0;
            }
        }
    }
    /* XMTRX = Rz(r6) * Ry(r5) * Rx(r4) from the identity */
    {
        float sz, cz, sy, cy, sx, cx, rz[16], ry[16], rx[16], tmp[16], want[16];
        const double pi = 3.14159265358979323846;
        sz = (float)sin((double)sc->angle[2] * (2 * pi / 65536.0));
        cz = (float)cos((double)sc->angle[2] * (2 * pi / 65536.0));
        sy = (float)sin((double)sc->angle[1] * (2 * pi / 65536.0));
        cy = (float)cos((double)sc->angle[1] * (2 * pi / 65536.0));
        sx = (float)sin((double)sc->angle[0] * (2 * pi / 65536.0));
        cx = (float)cos((double)sc->angle[0] * (2 * pi / 65536.0));
        rot_z(sz, cz, rz);
        rot_y(sy, cy, ry);
        rot_x(sx, cx, rx);
        multiply(rz, ry, tmp);
        multiply(tmp, rx, want);
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t bits;
            float as_float;
            memcpy(&bits, &ref.state.v[37 + i], 4);
            memcpy(&as_float, &bits, 4);
            if (fabsf(as_float - want[i]) > 1e-4f) {
                fprintf(stderr, "midpoint_angles: %s: XMTRX[%u] %g, want %g\n",
                        sc->name, i, (double)as_float, (double)want[i]);
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
    if (!reg || reg->fn != vf3_midpoint_angles_entry) {
        fprintf(stderr, "midpoint_angles: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "identity", .angle = { 0, 0, 0 } },
        { .name = "z quarter", .angle = { 0, 0, 16384 } },
        { .name = "y quarter", .angle = { 0, 16384, 0 } },
        { .name = "x quarter", .angle = { 16384, 0, 0 } },
        { .name = "mixed", .angle = { 8192, 16384, 4096 } },
        { .name = "high-bit", .angle = { 40000, 50000, 60000 } },
        { .name = "capture-ish", .angle = { 1234, 4567, 8910 } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("midpoint_angles: %u differential cases - PASS\n", cases);
    return 0;
}
