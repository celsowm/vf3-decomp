/* counter_advance_replay.c - the readable frame counters against the retained
 * generated translation of SH-4 0x8C08B338.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function advances three counters in a record and one in a block, but only
 * when the value a global points at has no bit in common with the mask.  The
 * test seeds the literal pool with the mask and the two pointers, and lays the
 * counters out the way the guest expects.  The scenarios cover the gate
 * closing, the gate open, the bit that is carried into the narrow counters,
 * the seven-bit counter wrapping and the block counter wrapping at 127.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_counter_advance_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c08b338u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the mask and the two pointers */
#define POOL_BASE 0x0c08b3e0u
#define POOL_LEN  0x40u
#define G_MASK   (POOL_BASE + 0x0cu)   /* the mask */
#define G_ENABLE (POOL_BASE + 0x10u)   /* the pointer to the gate's value */
#define G_BLOCK  (POOL_BASE + 0x14u)   /* the pointer to the block */

/* the value the gate points at */
#define VAL_BASE 0x0c3a0000u
#define VAL_LEN  0x10u

/* the header the block's global points at: its first word is the block */
#define HDR_BASE 0x0c3c0000u
#define HDR_LEN  0x10u

/* the block that carries the counter */
#define BLK_BASE 0x0c3b0000u
#define BLK_LEN  0x80u
#define BLK_COUNTER 0x54u

/* the record that carries the three counters */
#define REC_BASE 0x0c300000u
#define REC_LEN  0x40u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_VAL  (OFF_POOL + POOL_LEN)
#define OFF_HDR  (OFF_VAL + VAL_LEN)
#define OFF_BLK  (OFF_HDR + HDR_LEN)
#define OFF_REC  (OFF_BLK + BLK_LEN)
#define SHADOW_LEN (OFF_REC + REC_LEN)

struct scenario {
    const char *name;
    uint32_t mask;      /* the mask the gate's value is tested against */
    uint32_t gate;      /* the value the gate points at */
    uint16_t wide;      /* the record's seven-bit counter, at +12 */
    uint16_t narrow;    /* the record's two-bit counter, at +14 */
    uint16_t four;      /* the record's four-bit counter, at +16 */
    uint16_t counter;   /* the block's counter, at +0x54 */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[5];
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
    w32(p + OFF_POOL, G_MASK - POOL_BASE, sc->mask);
    w32(p + OFF_POOL, G_ENABLE - POOL_BASE, VAL_BASE);
    w32(p + OFF_POOL, G_BLOCK - POOL_BASE, HDR_BASE);

    /* the value the gate points at */
    w32(p + OFF_VAL, 0u, sc->gate);

    /* the header's first word is the block */
    w32(p + OFF_HDR, 0u, BLK_BASE);

    /* the block's counter */
    w16(p + OFF_BLK, BLK_COUNTER, sc->counter);

    /* the record's three counters */
    w16(p + OFF_REC, 12u, sc->wide);
    w16(p + OFF_REC, 14u, sc->narrow);
    w16(p + OFF_REC, 16u, sc->four);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_VAL;  r->wins[1].base = VAL_BASE;  r->wins[1].len = VAL_LEN;
    r->wins[2].data = p + OFF_HDR;  r->wins[2].base = HDR_BASE;  r->wins[2].len = HDR_LEN;
    r->wins[3].data = p + OFF_BLK;  r->wins[3].base = BLK_BASE;  r->wins[3].len = BLK_LEN;
    r->wins[4].data = p + OFF_REC;  r->wins[4].base = REC_BASE;  r->wins[4].len = REC_LEN;
    r->map.wins = r->wins;
    r->map.n = 5;
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
    const int ok_port = vf3_counter_advance_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "counter advance: %s differs (ok %d/%d/%d)\n",
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
    if (!reg || reg->fn != vf3_counter_advance_entry) {
        fprintf(stderr, "counter advance: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the gate is shut: the value shares a bit with the mask, so nothing
         * moves at all */
        { "gate shut",   0x00000001u, 0x00000001u, 10u, 1u, 3u, 5u },
        /* the gate is open: the value has no bit in common with the mask */
        { "gate open",   0x00000001u, 0x00000000u, 10u, 1u, 3u, 5u },
        /* a mask of zero lets everything through */
        { "empty mask",  0x00000000u, 0xffffffffu, 10u, 1u, 3u, 5u },
        /* the seven-bit counter was odd: nothing is carried into the narrow
         * counters */
        { "odd wide",    0x00000001u, 0x00000000u, 11u, 1u, 3u, 5u },
        /* the seven-bit counter wraps: it goes back to zero */
        { "wide wraps",  0x00000001u, 0x00000000u, 127u, 1u, 3u, 5u },
        /* the block's counter wraps at 127 */
        { "block wraps", 0x00000001u, 0x00000000u, 10u, 1u, 3u, 126u },
        /* the two narrow counters wrap on their own widths */
        { "narrow wraps", 0x00000001u, 0x00000000u, 10u, 3u, 15u, 5u },
        /* a counter that is already past its width */
        { "over wide",   0x00000001u, 0x00000000u, 300u, 9u, 20u, 5u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("counter_advance: %u differential cases - PASS\n", cases);
    return 0;
}
