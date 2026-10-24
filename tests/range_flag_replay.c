/* range_flag_replay.c - the readable out-of-range flag against the retained
 * generated translation of SH-4 0x8C0CAA9C.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function looks at four floats and sets a bit in a byte when one of them
 * is out of range.  The test seeds the literal pool with the two bounds and
 * the two offsets, and lays the four values and the byte out the way the
 * guest expects.  The scenarios cover the byte's "do not look" bit being
 * clear, everything in range, a value above the upper bound, a value below
 * the lower one and a mixture.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_range_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c0caa9cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the two offsets and the two bounds */
#define POOL_BASE 0x0c0cab10u
#define POOL_LEN  0x20u
#define G_BYTE    (POOL_BASE + 0x0au)   /* the byte's offset */
#define G_VALUE   (POOL_BASE + 0x0cu)   /* the first float's offset */
#define G_LIMIT   (POOL_BASE + 0x10u)   /* the upper bound */
#define G_FLOOR   (POOL_BASE + 0x14u)   /* the lower bound */

/* the record */
#define REC_BASE  0x0c300000u
#define REC_LEN   0x100u

/* the offsets inside the record: the first float's offset has to leave room
 * for the two the guest reads below it (offset - 36) */
#define OFF_BYTE  0x10u
#define OFF_VALUE 0x40u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_REC  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_REC + REC_LEN)

struct scenario {
    const char *name;
    uint8_t byte;            /* the flag byte */
    float v6, v7, v8, v9;     /* the four values */
    float limit, floor;      /* the bounds */
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
    w16(p + OFF_POOL, G_BYTE - POOL_BASE, (uint16_t)OFF_BYTE);
    w16(p + OFF_POOL, G_VALUE - POOL_BASE, (uint16_t)OFF_VALUE);
    w32(p + OFF_POOL, G_LIMIT - POOL_BASE, vf3_f32_bits(sc->limit));
    w32(p + OFF_POOL, G_FLOOR - POOL_BASE, vf3_f32_bits(sc->floor));

    /* the record: the byte and the four values, where the guest looks for
     * them (the first float's offset, +12, -36 and -24 from there) */
    p[OFF_REC + OFF_BYTE] = sc->byte;
    w32(p + OFF_REC, OFF_VALUE, vf3_f32_bits(sc->v6));
    w32(p + OFF_REC, OFF_VALUE + 12u, vf3_f32_bits(sc->v7));
    w32(p + OFF_REC, OFF_VALUE - 36u, vf3_f32_bits(sc->v8));
    w32(p + OFF_REC, OFF_VALUE - 24u, vf3_f32_bits(sc->v9));

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_REC;  r->wins[1].base = REC_BASE;  r->wins[1].len = REC_LEN;
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
    const int ok_port = vf3_range_flag_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "range flag: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_range_flag_entry) {
        fprintf(stderr, "range flag: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the byte's 0x40 bit is clear: the function does nothing */
        { "not asked", 0x00u, 1.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
        /* everything is inside the range */
        { "in range",  0x40u, 1.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
        /* the first value is above the upper bound */
        { "too high",  0x40u, 11.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
        /* the last value is below the lower bound */
        { "too low",   0x40u, 1.0f, 2.0f, 3.0f, -1.0f, 10.0f, 0.0f },
        /* a value on the bound is still in range */
        { "on the bound", 0x40u, 10.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
        /* the byte already carries other bits, and the flag goes on top */
        { "other bits", 0x41u, 11.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
        /* the flag is already on and the values are in range: it goes off */
        { "flag off",   0x50u, 1.0f, 2.0f, 3.0f, 4.0f, 10.0f, 0.0f },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("range_flag: %u differential cases - PASS\n", cases);
    return 0;
}
