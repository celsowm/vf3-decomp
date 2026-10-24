/* band_probe_replay.c - the readable band probe against the retained generated
 * translation of SH-4 0x8C0B0F28.
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
 * The function takes a point in three registers and a band in the literal
 * pool, asks whether the two differences the point makes with its third
 * coordinate are inside the band, and writes the answer into a word the
 * caller leaves in its own frame.  The test lays the literal pool and the
 * caller's frame out and walks the point through the band.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_band_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c0b0f28u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the band, the inside bit, the mask and the two outside
 * bits.  One window covers all of them. */
#define POOL_BASE 0x0c0b0f60u
#define POOL_LEN  0x140u
#define BAND_LO  (POOL_BASE + 0x04u)
#define BAND_HI  (POOL_BASE + 0x06u)
#define IN_BIT   (POOL_BASE + 0x08u)
#define MASK     (POOL_BASE + 0x30u)
#define GATE     (POOL_BASE + 0x128u)
#define OUT_A    (POOL_BASE + 0x12cu)
#define OUT_B    (POOL_BASE + 0x130u)

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts below the two words the callee pushes */
#define STACK_WIN_BASE (STACK_TOP - 8u)
#define STACK_LEN      0x40u

/* the word the caller hands the guest, and the word the flags go into */
#define FRAME_WORD (STACK_TOP)
#define FLAG_ADDR  (STACK_TOP + 0x10u)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_STACK (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t x;        /* r4 - the first coordinate */
    uint32_t y;        /* r5 - the second coordinate */
    uint32_t z;        /* r6 - the third one */
    uint32_t r7;       /* the seventh register */
    uint32_t mask;     /* the pool's mask on the differences */
    int32_t lo;        /* the band's low bound */
    int32_t hi;        /* the band's high bound */
    uint32_t gate;     /* the pool's word the seventh register is asked about */
    uint32_t flag;     /* the word the flags go into, before the call */
    uint32_t in_bit;   /* the bit for "inside" */
    uint32_t out_a;    /* the first outside bit */
    uint32_t out_b;    /* the second outside bit */
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
    w16(p + OFF_POOL, BAND_LO - POOL_BASE, (uint16_t)(int16_t)sc->lo);
    w16(p + OFF_POOL, BAND_HI - POOL_BASE, (uint16_t)(int16_t)sc->hi);
    w16(p + OFF_POOL, IN_BIT  - POOL_BASE, (uint16_t)(int16_t)sc->in_bit);
    w32(p + OFF_POOL, MASK    - POOL_BASE, sc->mask);
    w32(p + OFF_POOL, GATE    - POOL_BASE, sc->gate);
    w32(p + OFF_POOL, OUT_A   - POOL_BASE, sc->out_a);
    w32(p + OFF_POOL, OUT_B   - POOL_BASE, sc->out_b);

    /* the caller's frame: the word the flags go into, and the word that
     * points at it */
    w32(p + OFF_STACK, FRAME_WORD - STACK_WIN_BASE, FLAG_ADDR);
    w32(p + OFF_STACK, FLAG_ADDR  - STACK_WIN_BASE, sc->flag);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->x;
    s->v[5] = sc->y;
    s->v[6] = sc->z;
    s->v[7] = sc->r7;
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

/* the guest's halfword: sixteen bits, sign extended */
static int32_t s16(uint32_t v)
{
    return (int32_t)(int16_t)v;
}

/* the guest's band test: the high bound first, then the low one */
static int band(int32_t v, int32_t hi, int32_t lo)
{
    if (v > hi) return 0;
    return v >= lo;
}

/* what the fixture says the guest has to answer, the word it has to leave
 * behind and the T bit the caller has to see */
static uint32_t expect(const struct scenario *sc, uint32_t *answer, int *t_bit)
{
    const int32_t dx = (int32_t)(uint32_t)(sc->x - sc->z);
    const int32_t dy = (int32_t)(uint32_t)(sc->y - sc->z);
    const int32_t mx = s16((uint32_t)dx ^ sc->mask);
    const int32_t my = s16((uint32_t)dy ^ sc->mask);
    uint32_t flag = sc->flag;

    if (band(mx, sc->hi, sc->lo) && band(my, sc->hi, sc->lo)) {
        flag |= (uint32_t)s16(sc->in_bit);
        *answer = 1;
        *t_bit = (my >= sc->lo) ? 1 : 0;
        return flag;
    }
    if ((sc->r7 & sc->gate) == 0) {
        *answer = 0;
        *t_bit = 1;                       /* the tst of the gate */
        return flag;
    }
    if (band(s16((uint32_t)dy), sc->hi, sc->lo)) flag |= sc->out_a;
    if (band(my, sc->hi, sc->lo)) flag |= sc->out_b;
    *answer = 1;
    *t_bit = (my > sc->hi) ? 1 : ((my >= sc->lo) ? 1 : 0);
    return flag;
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
    const int ok_port = vf3_band_probe_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "band probe: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "band probe: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the answer, the word it was handed and the T bit, checked against the
     * fixture itself */
    uint32_t answer = 0;
    int t_bit = 0;
    const uint32_t want_flag = expect(sc, &answer, &t_bit);

    if (ref.state.v[0] != answer) {
        fprintf(stderr, "band probe: %s: r0 %08x, expected %08x\n",
                sc->name, ref.state.v[0], answer);
        return 0;
    }
    if (shadow_word(&ref, FLAG_ADDR) != want_flag) {
        fprintf(stderr, "band probe: %s: the flag word is %08x, expected %08x\n",
                sc->name, shadow_word(&ref, FLAG_ADDR), want_flag);
        return 0;
    }
    /* the pool it read: the mask and the two bounds */
    if (ref.state.v[1] != sc->mask) {
        fprintf(stderr, "band probe: %s: r1 %08x, expected %08x\n",
                sc->name, ref.state.v[1], sc->mask);
        return 0;
    }
    if (ref.state.v[4] != (uint32_t)s16((uint32_t)sc->hi) ||
        ref.state.v[5] != (uint32_t)s16((uint32_t)sc->lo)) {
        fprintf(stderr, "band probe: %s: the bounds are %08x/%08x\n",
                sc->name, ref.state.v[4], ref.state.v[5]);
        return 0;
    }
    /* the saved register is back and the stack is where it was */
    if (ref.state.v[13] != 0x76543210u + 13u) {
        fprintf(stderr, "band probe: %s: r13 %08x\n", sc->name, ref.state.v[13]);
        return 0;
    }
    if (ref.state.v[15] != STACK_TOP) {
        fprintf(stderr, "band probe: %s: the stack is at %08x\n",
                sc->name, ref.state.v[15]);
        return 0;
    }
    /* the difference the guest kept on the stack */
    const uint32_t pushed = (uint32_t)(sc->y - sc->z);
    if (shadow_word(&ref, STACK_TOP - 8u) != pushed) {
        fprintf(stderr, "band probe: %s: the pushed difference is %08x, expected %08x\n",
                sc->name, shadow_word(&ref, STACK_TOP - 8u), pushed);
        return 0;
    }
    /* and the T bit the caller sees */
    if (((ref.state.v[17] & 1u) != 0) != t_bit) {
        fprintf(stderr, "band probe: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, t_bit);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_band_probe_entry) {
        fprintf(stderr, "band probe: the port is not registered\n");
        return 1;
    }

    /* the defaults: a band of a hundred either way, a mask that leaves the
     * low half alone and a gate of one bit */
    static const struct scenario scenarios[] = {
        /* inside the band */
        { "inside", 50u, (uint32_t)-30, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* on the two bounds */
        { "on the high bound", 100u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "on the low bound", (uint32_t)-100, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* outside the band, in each of the four ways */
        { "x above", 500u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "x below", (uint32_t)-500, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "y above", 0u, 500u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        { "y below", 0u, (uint32_t)-500, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* outside, and the gate is open: the guest sets both outside bits */
        { "outside, the gate is open", 500u, 0u, 0u, 0x10u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* outside, the gate is open and the seventh register has other bits */
        { "outside, other bits in r7", 500u, 0u, 0u, 0x30u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* the mask flips the sign of the differences: the band is then the
         * other way round, and the inside case is the negative one */
        { "the mask flips the sign", (uint32_t)-50, (uint32_t)-30, 0u, 0u,
          0x00008000u, -100, 100, 0x10u, 0u, 1u, 2u, 4u },
        /* and with a band that is not symmetric, one of the two outside bits
         * is set and the other is not */
        { "outside, only the first bit", 500u, (uint32_t)-50, 0u, 0x10u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        { "outside, only the second bit", 500u, 50u, 0u, 0x10u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        /* the mask decides the second difference: masked, it is inside the
         * band, and without the mask it is not */
        { "the mask decides the second difference", 0x8000u, 0x8000u, 0u, 0u,
          0x00008000u, -100, 20, 0x10u, 0u, 1u, 2u, 4u },
        /* the seventh register holds a bit of the mask and none of the gate:
         * the gate is closed and the T bit is set */
        { "the gate is closed, the mask's bit in r7", 500u, 0u, 0u, 0x80000000u,
          0x80000000u, -100, 100, 0x10u, 0u, 1u, 2u, 4u },
        /* the difference is cut to sixteen bits */
        { "sixteen bits", 0x10050u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* the third number is not zero */
        { "a third number", 150u, 100u, 100u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 1u, 2u, 4u },
        /* the band is the wrong way round */
        { "the band is inverted", 0u, 0u, 0u, 0u, 0x80000000u, 100, -100,
          0x10u, 0u, 1u, 2u, 4u },
        /* the gate word is zero, so the guest always answers zero outside */
        { "the gate is zero", 500u, 0u, 0u, 0x10u, 0x80000000u, -100, 100,
          0u, 0u, 1u, 2u, 4u },
        /* the word the flags go into already has bits in it */
        { "the flag word is not empty", 50u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0x40u, 1u, 2u, 4u },
        /* the inside bit is a negative halfword */
        { "the inside bit is negative", 50u, 0u, 0u, 0u, 0x80000000u, -100, 100,
          0x10u, 0u, 0xffffu, 2u, 4u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("band_probe: %u differential cases - PASS\n", cases);
    return 0;
}
