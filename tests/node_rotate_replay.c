/* node_rotate_replay.c - the readable node rotation against the retained
 * generated translation of SH-4 0x8C09F83C.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function turns seven twelve-byte records around and then moves the
 * root's position.  The test lays the records, the root and the literal pool
 * out the way the guest expects.  The scenarios cover the identity, a quarter
 * turn, a half turn, a general angle and the root's move.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_node_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c09f83cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the offset of the root's second coordinate */
#define POOL_BASE 0x0c09f8d0u
#define POOL_LEN  0x04u
#define G_Y      POOL_BASE

/* the root's first coordinate, and the distance to the third one */
#define ROOT_X   0x58u
#define ROOT_STEP 24u

/* the root's second coordinate's offset, as the pool holds it */
#define Y_OFFSET 0x6cu

/* the object: seven records, then the root's three coordinates */
#define OBJ_BASE 0x0c120000u
#define OBJ_LEN  0x80u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_OBJ  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_OBJ + OBJ_LEN)

struct scenario {
    const char *name;
    float cos;          /* FR4 */
    float sin;          /* FR5 */
    float move;         /* FR6 */
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
    w16(p + OFF_POOL, G_Y - POOL_BASE, (uint16_t)Y_OFFSET);

    /* the seven records: two floats each, eight bytes apart, twelve apart */
    for (unsigned i = 0; i < 7; ++i) {
        const uint32_t at = i * 12u;
        w32(p + OFF_OBJ, at, vf3_f32_bits(1.0f + (float)i));
        w32(p + OFF_OBJ, at + 8u, vf3_f32_bits(10.0f + (float)i));
    }

    /* the root's three coordinates */
    w32(p + OFF_OBJ, ROOT_X, vf3_f32_bits(100.0f));
    w32(p + OFF_OBJ, Y_OFFSET, vf3_f32_bits(200.0f));
    w32(p + OFF_OBJ, Y_OFFSET - ROOT_STEP, vf3_f32_bits(300.0f));

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->v[21 + 4] = vf3_f32_bits(sc->cos);
    s->v[21 + 5] = vf3_f32_bits(sc->sin);
    s->v[21 + 6] = vf3_f32_bits(sc->move);
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_OBJ;  r->wins[1].base = OBJ_BASE;  r->wins[1].len = OBJ_LEN;
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

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_node_rotate_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "node rotate: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "node rotate: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_node_rotate_entry) {
        fprintf(stderr, "node rotate: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the identity: the records do not move */
        { "identity",    1.0f, 0.0f, 0.0f },
        /* a quarter turn: (a, b) becomes (-b, a) */
        { "quarter",     0.0f, 1.0f, 0.0f },
        /* a half turn: (a, b) becomes (-a, -b) */
        { "half",       -1.0f, 0.0f, 0.0f },
        /* a general angle */
        { "angle",       0.5f, 0.8660254f, 0.0f },
        /* and the root's move */
        { "moved",       1.0f, 0.0f, 7.5f },
        /* both */
        { "angle moved", 0.5f, 0.8660254f, -2.25f },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("node_rotate: %u differential cases - PASS\n", cases);
    return 0;
}
