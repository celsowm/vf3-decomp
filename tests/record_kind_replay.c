/* record_kind_replay.c - the readable record kind against the retained
 * generated translation of SH-4 0x8C078044.
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
 * A fourth arm comes from the other side: `src/fight/g78044.c` is a
 * hand-written port of the *same* function that was proved against the oracle
 * (docs/decomp_status.csv: "oracle-verified (RAM shadow diff)", eight cases
 * over five windows).  It bakes the literal pool's values in, so the fixture
 * here uses the values the real image holds - which is what makes the arm
 * meaningful: the readable port reads the pool at run time, g78044 does not,
 * and the two have to agree.
 *
 * The function steps a record's kind byte and the flag word that goes with
 * it.  The test lays the literal pool, the record, the caller's three frame
 * words and the stack out, and walks the record through every branch.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/g78044.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_record_kind_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c078044u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the five offsets and the gate mask */
#define POOL_BASE  0x0c078158u
#define POOL_LEN   0x20u
#define POOL_KIND   (POOL_BASE + 0x02u)   /* 0x8C07815A */
#define POOL_STATE  (POOL_BASE + 0x04u)   /* 0x8C07815C */
#define POOL_SOURCE (POOL_BASE + 0x06u)   /* 0x8C07815E */
#define POOL_DEST   (POOL_BASE + 0x08u)   /* 0x8C078160 */
#define POOL_EXTRA  (POOL_BASE + 0x0au)   /* 0x8C078162 */
#define POOL_GATE   (POOL_BASE + 0x14u)   /* 0x8C07816C */

/* the values the real image holds in that pool.  The offsets are the ones the
 * guest adds to the record's base; the extra bit and the gate mask are the
 * ones it puts into the flag word and tests the caller's word against. */
#define OFF_KIND   0x1bb0u
#define OFF_STATE  0x1bb2u
#define OFF_SOURCE 0x1b83u
#define OFF_DEST   0x1bb4u
#define EXTRA_BIT  0x0100u
#define GATE_BIT   0x40000000u

/* the record */
#define RECORD_BASE 0x0c200000u
#define RECORD_LEN  0x2000u

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts below the two words the callee pushes */
#define STACK_WIN_BASE (STACK_TOP - 16u)
#define STACK_LEN      0x40u

/* the caller's three frame words: the flag word, the gate word and the mode
 * word.  The callee reads them at its own stack pointer plus 8, 12 and 16,
 * which is where the caller's three pushes land. */
#define FRAME_FLAGS (STACK_TOP + 0x00u)
#define FRAME_GATE  (STACK_TOP + 0x04u)
#define FRAME_MODE  (STACK_TOP + 0x08u)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL   0u
#define OFF_RECORD (OFF_POOL + POOL_LEN)
#define OFF_STACK  (OFF_RECORD + RECORD_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t kind;      /* the record's kind byte */
    uint32_t state;     /* the record's state byte */
    uint32_t source;    /* the record's source byte */
    uint32_t flags;     /* the flag word the caller left */
    uint32_t gate;      /* the caller's gate word */
    uint32_t mode;      /* the caller's mode word */
    uint32_t index;     /* r7 */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[3];
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

    /* the literal pool, with the values the real image holds */
    w16(p + OFF_POOL, POOL_KIND   - POOL_BASE, (uint16_t)OFF_KIND);
    w16(p + OFF_POOL, POOL_STATE  - POOL_BASE, (uint16_t)OFF_STATE);
    w16(p + OFF_POOL, POOL_SOURCE - POOL_BASE, (uint16_t)OFF_SOURCE);
    w16(p + OFF_POOL, POOL_DEST   - POOL_BASE, (uint16_t)OFF_DEST);
    w16(p + OFF_POOL, POOL_EXTRA  - POOL_BASE, (uint16_t)EXTRA_BIT);
    w32(p + OFF_POOL, POOL_GATE   - POOL_BASE, GATE_BIT);

    /* the record: the three bytes that matter, and the two places the copy
     * lands (they start with a value of their own, so a copy is visible) */
    p[OFF_RECORD + OFF_KIND   + sc->index] = (uint8_t)sc->kind;
    p[OFF_RECORD + OFF_STATE  + sc->index] = (uint8_t)sc->state;
    p[OFF_RECORD + OFF_SOURCE] = (uint8_t)sc->source;
    p[OFF_RECORD + OFF_DEST   + sc->index] = 0xeeu;
    p[OFF_RECORD + OFF_SOURCE + 51u] = 0xeeu;

    /* the caller's three frame words */
    w32(p + OFF_STACK, FRAME_FLAGS - STACK_WIN_BASE, sc->flags);
    w32(p + OFF_STACK, FRAME_GATE  - STACK_WIN_BASE, sc->gate);
    w32(p + OFF_STACK, FRAME_MODE  - STACK_WIN_BASE, sc->mode);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x11111111u;              /* r4 - the guest overwrites it */
    s->v[5] = RECORD_BASE;             /* r5 - the record */
    s->v[6] = 0x22222222u;             /* r6 - the guest overwrites it */
    s->v[7] = sc->index;               /* r7 - the index */
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;   r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_RECORD; r->wins[1].base = RECORD_BASE; r->wins[1].len = RECORD_LEN;
    r->wins[2].data = p + OFF_STACK;  r->wins[2].base = STACK_WIN_BASE; r->wins[2].len = STACK_LEN;
    r->map.wins = r->wins;
    r->map.n = 3;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

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

/* The oracle-verified hand-written port only reports the registers it can
 * vouch for; the rest are the caller's own, untouched. */
static int same_as_g78044(const struct run *ref, const struct run *got,
                           const vf3_g78044_out *o, const char *what)
{
    static const int regs[] = { 0, 3, 4, 6, 7, 15, 17 };
    const uint32_t values[7] = { o->r0, o->r3, o->r4, o->r6, o->r7, o->r15, o->sr };
    for (unsigned i = 0; i < 7; ++i)
        if (ref->state.v[regs[i]] != values[i]) {
            fprintf(stderr, "  %s: v%d %08x != %08x\n", what, regs[i],
                    ref->state.v[regs[i]], values[i]);
            return 0;
        }
    if (ref->map.oob != got->map.oob) {
        fprintf(stderr, "  %s: oob %u/%u\n", what, ref->map.oob, got->map.oob);
        return 0;
    }
    if (memcmp(ref->shadow, got->shadow, SHADOW_LEN)) {
        for (unsigned i = 0; i < SHADOW_LEN; ++i)
            if (ref->shadow[i] != got->shadow[i]) {
                fprintf(stderr, "  %s: ram %u %02x != %02x\n", what, i,
                        ref->shadow[i], got->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

/* What the fixture says the guest has to leave behind: the flag word, the
 * record's three bytes, whether the byte was copied and the T bit the caller
 * has to see.  This is worked out from the fixture alone - the generated
 * translation is not consulted. */
struct result {
    uint32_t flags;
    uint32_t kind;
    uint32_t state;
    uint32_t dest;
    uint32_t second;
    int copied;
    int t_bit;
};

static void expect(const struct scenario *sc, struct result *out)
{
    const uint32_t nibble = sc->flags & 15u;
    uint32_t flags = sc->flags;

    out->kind = sc->kind;
    out->state = sc->state;
    out->dest = 0xeeu;                 /* the value the copy would leave */
    out->second = 0xeeu;
    out->copied = 0;

    if (sc->kind == 0) {
        /* the record has no kind yet: the flag word's low four bits decide */
        if (nibble != 0 && nibble != 15u) {
            out->kind = 1u;
            out->state = nibble;
            flags &= 0xfffffff0u;
        }
        out->copied = 1;
        out->dest = sc->source;
        out->second = sc->source;
        out->t_bit = (nibble == 0 || nibble == 15u) ? 1 : 0;
        out->flags = flags;
        return;
    }

    /* the record has a kind */
    const uint32_t state = sc->state;
    if ((sc->gate & GATE_BIT) == 0) {
        /* the gate is closed: three tests have to hold - the state byte is
         * four, the mode word's bit two is clear, and the flag word's low
         * four bits are one */
        if (state == 4u && (sc->mode & 4u) == 0 && nibble == 1u) {
            out->copied = 1;
            out->dest = sc->source;
            out->second = sc->source;
            out->kind = 0u;
            flags |= nibble;
            out->t_bit = 1;
            out->flags = flags;
            return;
        }
    }

    /* the second block: the state byte joins the flag word */
    if (state == 6u && (sc->mode & 15u) == 2u)
        flags |= EXTRA_BIT;
    const uint32_t merged = nibble | state;
    if (merged == 15u) {
        out->kind = 0u;
        flags |= merged;
        out->t_bit = 1;
        out->flags = flags;
        return;
    }
    if (sc->kind == 1u) {
        out->kind = 0u;
        flags |= merged;
        out->t_bit = 1;
        out->flags = flags;
        return;
    }
    /* the kind counts down */
    out->kind = sc->kind - 1u;
    out->state = merged;
    flags &= 0xfffffff0u;
    out->t_bit = 0;
    out->flags = flags;
}

static uint8_t record_byte(const struct run *r, uint32_t off)
{
    return r->shadow[OFF_RECORD + off];
}

static uint32_t stack_word(const struct run *r, uint32_t addr)
{
    const uint32_t off = OFF_STACK + (addr - STACK_WIN_BASE);
    return (uint32_t)r->shadow[off + 0]
         | ((uint32_t)r->shadow[off + 1] << 8)
         | ((uint32_t)r->shadow[off + 2] << 16)
         | ((uint32_t)r->shadow[off + 3] << 24);
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook, gap;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);
    setup(&gap, sc);

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_record_kind_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record kind: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "record kind: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the fourth arm: the oracle-verified hand-written port of the same
     * function, which bakes the literal pool's values in */
    vf3_g78044_out o;
    memset(&o, 0, sizeof o);
    vf3_g78044_8c078044(gap.state.v[4], gap.state.v[5], gap.state.v[6],
                        gap.state.v[7], gap.state.v[13], gap.state.v[14],
                        gap.state.v[15], gap.state.v[17], &o, &gap.map);
    if (!same_as_g78044(&ref, &gap, &o, "gap unit")) {
        fprintf(stderr, "record kind: %s differs from the gap unit\n", sc->name);
        return 0;
    }

    /* the flag word, the record and the T bit, checked against the fixture */
    struct result want;
    expect(sc, &want);

    if (ref.state.v[0] != want.flags) {
        fprintf(stderr, "record kind: %s: the flag word is %08x, expected %08x\n",
                sc->name, ref.state.v[0], want.flags);
        return 0;
    }
    if (record_byte(&ref, OFF_KIND + sc->index) != (uint8_t)want.kind) {
        fprintf(stderr, "record kind: %s: the kind byte is %02x, expected %02x\n",
                sc->name, record_byte(&ref, OFF_KIND + sc->index), want.kind);
        return 0;
    }
    if (record_byte(&ref, OFF_STATE + sc->index) != (uint8_t)want.state) {
        fprintf(stderr, "record kind: %s: the state byte is %02x, expected %02x\n",
                sc->name, record_byte(&ref, OFF_STATE + sc->index), want.state);
        return 0;
    }
    if (record_byte(&ref, OFF_DEST + sc->index) != (uint8_t)want.dest) {
        fprintf(stderr, "record kind: %s: the first copy is %02x, expected %02x\n",
                sc->name, record_byte(&ref, OFF_DEST + sc->index), want.dest);
        return 0;
    }
    if (record_byte(&ref, OFF_SOURCE + 51u) != (uint8_t)want.second) {
        fprintf(stderr, "record kind: %s: the second copy is %02x, expected %02x\n",
                sc->name, record_byte(&ref, OFF_SOURCE + 51u), want.second);
        return 0;
    }
    if (((ref.state.v[17] & 1u) != 0) != want.t_bit) {
        fprintf(stderr, "record kind: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, want.t_bit);
        return 0;
    }

    /* the saved registers are back and the stack is where it was */
    if (ref.state.v[13] != 0x76543210u + 13u ||
        ref.state.v[14] != 0x76543210u + 14u) {
        fprintf(stderr, "record kind: %s: the saved registers are %08x/%08x\n",
                sc->name, ref.state.v[13], ref.state.v[14]);
        return 0;
    }
    if (ref.state.v[15] != STACK_TOP) {
        fprintf(stderr, "record kind: %s: the stack is at %08x\n", sc->name, ref.state.v[15]);
        return 0;
    }
    /* the two words the guest pushed */
    if (stack_word(&ref, STACK_TOP - 8u) != 0x76543210u + 13u ||
        stack_word(&ref, STACK_TOP - 4u) != 0x76543210u + 14u) {
        fprintf(stderr, "record kind: %s: the pushed words are %08x/%08x\n",
                sc->name, stack_word(&ref, STACK_TOP - 8u), stack_word(&ref, STACK_TOP - 4u));
        return 0;
    }
    /* and the return address */
    if (ref.state.pc != RETURN_PC) {
        fprintf(stderr, "record kind: %s: the return address is %08x\n",
                sc->name, ref.state.pc);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_record_kind_entry) {
        fprintf(stderr, "record kind: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* the record has no kind yet */
        { "no kind, no bits", 0u, 0x11u, 0x22u, 0x00000000u, 0u, 0u, 1u },
        { "no kind, all four bits", 0u, 0x11u, 0x22u, 0x0000000fu, 0u, 0u, 1u },
        { "no kind, one bit", 0u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "no kind, two bits", 0u, 0x11u, 0x22u, 0x00000012u, 0u, 0u, 1u },
        { "no kind, the top bit", 0u, 0x11u, 0x22u, 0x00000008u, 0u, 0u, 1u },
        { "no kind, the bits and more", 0u, 0x11u, 0x22u, 0x12345678u, 0u, 0u, 1u },
        { "no kind, the index is zero", 0u, 0x11u, 0x22u, 0x00000003u, 0u, 0u, 0u },
        { "no kind, a high source byte", 0u, 0x11u, 0xe5u, 0x00000003u, 0u, 0u, 1u },
        /* the record has a kind */
        { "a kind, the gate is open", 2u, 0x11u, 0x22u, 0x00000001u, GATE_BIT, 0u, 1u },
        { "a kind, the gate is closed", 2u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is four", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is four, the mode has the bit", 2u, 4u, 0x22u, 0x00000001u, 0u, 4u, 1u },
        { "a kind, the state is four, the mode has the bit and more", 2u, 4u, 0x22u, 0x00000001u, 0u, 6u, 1u },
        { "a kind, the state is four, the bits are not one", 2u, 4u, 0x22u, 0x00000002u, 0u, 0u, 1u },
        { "a kind, the three tests hold", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the three tests would hold, the gate is open", 2u, 4u, 0x22u, 0x00000001u, GATE_BIT, 0u, 1u },
        { "a kind, the three tests hold, the index is zero", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 0u },
        { "a kind, the three tests hold, a high source byte", 2u, 4u, 0xe5u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is six", 2u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the state is six, the mode is not two", 2u, 6u, 0x22u, 0x00000001u, 0u, 3u, 1u },
        { "a kind, the state is six, the mode is two", 2u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the state is six, the mode is two, the gate is open", 2u, 6u, 0x22u, 0x00000001u, GATE_BIT, 2u, 1u },
        { "a kind, the merged value is fifteen", 2u, 14u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind is one", 1u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind counts down", 3u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind counts down, the state is six", 3u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the kind counts down, a big kind", 0x11u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind is one, a big state", 1u, 0x84u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is a big byte", 3u, 200u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the flags have other bits", 3u, 0x11u, 0x22u, 0xabcdef01u, 0u, 0u, 1u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("record_kind: %u differential cases - PASS\n", cases);
    return 0;
}
