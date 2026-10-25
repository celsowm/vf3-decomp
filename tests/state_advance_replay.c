/* state_advance_replay.c - the readable state advance against the retained
 * generated translation of SH-4 0x8C06BEA4.
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
 * The function steps an entry counter forward, counts a lap down, and tells a
 * byte of kind flags what the table says about the current entry.  The test
 * lays the literal pool, the table, the flags byte, the two words the guest
 * is handed and the stack out, and walks the counter through the table.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_state_advance_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c06bea4u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the two masks, the pointer to the flags and the pointer
 * to the table.  One window covers all of them. */
#define POOL_BASE 0x0c06bf80u
#define POOL_LEN  0x60u
#define MASK_A    (POOL_BASE + 0x2cu)
#define MASK_B    (POOL_BASE + 0x2eu)
#define FLAGS_PTR (POOL_BASE + 0x3cu)
#define TABLE_PTR (POOL_BASE + 0x40u)

/* the table the pool points at, the flags byte and the two words the guest is
 * handed */
#define TABLE_BASE 0x0c0d0000u
#define TABLE_LEN  0x20u
#define FLAGS_BASE 0x0c0e0000u
#define FLAGS_LEN  0x10u
#define SLOTS_BASE 0x0c0f0000u
#define SLOTS_LEN  0x10u

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts below the three words the callee pushes */
#define STACK_WIN_BASE (STACK_TOP - 16u)
#define STACK_LEN      0x40u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_TABLE (OFF_POOL + POOL_LEN)
#define OFF_FLAGS (OFF_TABLE + TABLE_LEN)
#define OFF_SLOTS (OFF_FLAGS + FLAGS_LEN)
#define OFF_STACK (OFF_SLOTS + SLOTS_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

struct scenario {
    const char *name;
    uint32_t slot_idx;    /* the word at r4 - the entry counter */
    uint32_t slot_count;  /* the word at r5 - the count */
    uint32_t r6;          /* the kind: zero for the first, anything else the second */
    uint8_t table_at;     /* the position the table has a byte at (0xff: nowhere) */
    uint8_t table_byte;   /* the byte at that position */
    int16_t mask_a;       /* the pool's mask for the first kind */
    int16_t mask_b;       /* the pool's mask for the second kind */
    uint8_t flags;        /* the flags byte before the call */
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
    w16(p + OFF_POOL, MASK_A    - POOL_BASE, (uint16_t)sc->mask_a);
    w16(p + OFF_POOL, MASK_B    - POOL_BASE, (uint16_t)sc->mask_b);
    w32(p + OFF_POOL, FLAGS_PTR - POOL_BASE, FLAGS_BASE);
    w32(p + OFF_POOL, TABLE_PTR - POOL_BASE, TABLE_BASE);

    /* the table: one byte, and zeroes everywhere else */
    if (sc->table_at < 16u)
        p[OFF_TABLE + sc->table_at] = sc->table_byte;

    /* the flags byte */
    p[OFF_FLAGS] = sc->flags;

    /* the two words the guest is handed */
    w32(p + OFF_SLOTS, 0u, sc->slot_idx);
    w32(p + OFF_SLOTS, 4u, sc->slot_count);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = SLOTS_BASE;
    s->v[5] = SLOTS_BASE + 4u;
    s->v[6] = sc->r6;
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;  r->wins[0].base = POOL_BASE;  r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_TABLE; r->wins[1].base = TABLE_BASE; r->wins[1].len = TABLE_LEN;
    r->wins[2].data = p + OFF_FLAGS; r->wins[2].base = FLAGS_BASE; r->wins[2].len = FLAGS_LEN;
    r->wins[3].data = p + OFF_SLOTS; r->wins[3].base = SLOTS_BASE; r->wins[3].len = SLOTS_LEN;
    r->wins[4].data = p + OFF_STACK; r->wins[4].base = STACK_WIN_BASE; r->wins[4].len = STACK_LEN;
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

/* the guest's halfword: sixteen bits, sign extended */
static int32_t s16(uint16_t v)
{
    return (int32_t)(int16_t)v;
}

/* What the fixture says the guest has to leave behind: the counter, the
 * count, the flags byte and the T bit the caller has to see.  This is worked
 * out from the fixture alone - the generated translation is not consulted. */
static void expect(const struct scenario *sc, uint32_t *new_idx, uint32_t *new_count,
                   uint8_t *new_flags, int *t_bit)
{
    const uint32_t idx = sc->slot_idx & 15u;

    if (idx == 0) {
        /* the count runs down and the counter waits for the next lap; the
         * flags are left alone */
        *new_flags = sc->flags;
        if (sc->slot_count == 0) {
            *new_idx = 0;
            *new_count = 0;
            *t_bit = 1;
        } else {
            *new_idx = 1;
            *new_count = sc->slot_count - 1u;
            *t_bit = 0;
        }
        return;
    }

    /* the table says what kind the entry is */
    const uint8_t v = (sc->table_at == idx) ? sc->table_byte : 0u;
    const int first = (sc->r6 == 0);
    uint32_t flags = (uint32_t)(int32_t)(int8_t)sc->flags;
    flags &= (uint32_t)(first ? s16(sc->mask_a) : s16(sc->mask_b));
    if (v != 0) flags |= (first ? 1u : 2u);

    *new_flags = (uint8_t)flags;
    *new_idx = (idx + 1u) & 15u;
    *new_count = sc->slot_count;
    *t_bit = (v == 0) ? 1 : 0;
}

static uint32_t shadow_word(const struct run *r, uint32_t addr)
{
    uint32_t off;
    if (addr >= SLOTS_BASE && addr < SLOTS_BASE + SLOTS_LEN)
        off = OFF_SLOTS + (addr - SLOTS_BASE);
    else
        off = OFF_STACK + (addr - STACK_WIN_BASE);
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
    const int ok_port = vf3_state_advance_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "state advance: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "state advance: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the counter, the count, the flags and the T bit, checked against the
     * fixture itself */
    uint32_t new_idx = 0, new_count = 0;
    uint8_t new_flags = 0;
    int t_bit = 0;
    expect(sc, &new_idx, &new_count, &new_flags, &t_bit);

    if (shadow_word(&ref, SLOTS_BASE) != new_idx) {
        fprintf(stderr, "state advance: %s: the counter is %08x, expected %08x\n",
                sc->name, shadow_word(&ref, SLOTS_BASE), new_idx);
        return 0;
    }
    if (shadow_word(&ref, SLOTS_BASE + 4u) != new_count) {
        fprintf(stderr, "state advance: %s: the count is %08x, expected %08x\n",
                sc->name, shadow_word(&ref, SLOTS_BASE + 4u), new_count);
        return 0;
    }
    if (ref.shadow[OFF_FLAGS] != new_flags) {
        fprintf(stderr, "state advance: %s: the flags byte is %02x, expected %02x\n",
                sc->name, ref.shadow[OFF_FLAGS], new_flags);
        return 0;
    }
    if (((ref.state.v[17] & 1u) != 0) != t_bit) {
        fprintf(stderr, "state advance: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, t_bit);
        return 0;
    }

    /* the saved registers are back and the stack is where it was */
    if (ref.state.v[12] != 0x76543210u + 12u ||
        ref.state.v[13] != 0x76543210u + 13u ||
        ref.state.v[14] != 0x76543210u + 14u) {
        fprintf(stderr, "state advance: %s: the saved registers are %08x/%08x/%08x\n",
                sc->name, ref.state.v[12], ref.state.v[13], ref.state.v[14]);
        return 0;
    }
    if (ref.state.v[15] != STACK_TOP) {
        fprintf(stderr, "state advance: %s: the stack is at %08x\n",
                sc->name, ref.state.v[15]);
        return 0;
    }
    /* the three words the guest pushed */
    if (shadow_word(&ref, STACK_TOP - 12u) != 0x76543210u + 12u ||
        shadow_word(&ref, STACK_TOP - 8u) != 0x76543210u + 13u ||
        shadow_word(&ref, STACK_TOP - 4u) != 0x76543210u + 14u) {
        fprintf(stderr, "state advance: %s: the pushed words are %08x/%08x/%08x\n",
                sc->name, shadow_word(&ref, STACK_TOP - 12u),
                shadow_word(&ref, STACK_TOP - 8u), shadow_word(&ref, STACK_TOP - 4u));
        return 0;
    }
    /* and the return address */
    if (ref.state.pc != RETURN_PC) {
        fprintf(stderr, "state advance: %s: the return address is %08x\n",
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
    if (!reg || reg->fn != vf3_state_advance_entry) {
        fprintf(stderr, "state advance: the port is not registered\n");
        return 1;
    }

    /* the defaults: a mask that keeps the other kind's bit, and a table that
     * knows the first entry */
    static const struct scenario scenarios[] = {
        /* the two kinds, the table knowing the entry */
        { "the first kind", 1u, 5u, 0u, 1u, 1u, (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the second kind", 1u, 5u, 1u, 1u, 1u, (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        /* the sixth register only has to be zero or not */
        { "the sixth register is not one", 1u, 5u, 0x80000000u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        /* the table knows nothing about the entry */
        { "the table says nothing", 1u, 5u, 0u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the table says nothing, the second kind", 1u, 5u, 1u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        /* the flags already hold the other kind's bit: the mask keeps it */
        { "the other kind's bit is there", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 2u },
        { "the other kind's bit is there, the second kind", 1u, 5u, 1u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        /* the flags already hold this kind's bit and the table says nothing:
         * the mask takes the bit away again */
        { "the kind's bit is taken away", 1u, 5u, 0u, 1u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        /* the second kind's mask keeps the first kind's bit, and the table
         * byte would not */
        { "the second kind's mask keeps the first bit", 1u, 5u, 1u, 1u, 2u,
          (int16_t)0xfffe, (int16_t)0xfffd, 1u },
        /* the counter is at zero: the count runs down */
        { "the counter is at zero, the count is spent", 0u, 0u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the counter is at zero, the count is left", 0u, 3u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the count is one", 0u, 1u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        { "the count is the biggest", 0u, 0xffffffffu, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        /* the counter wraps at sixteen */
        { "the counter wraps", 15u, 5u, 0u, 15u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter wraps and the table knows nothing", 15u, 5u, 0u, 15u, 0u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        /* the word holds more than the four bits the counter uses */
        { "the counter has bits above the four", 0x21u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter has four bits above the four", 0x1au, 5u, 0u, 10u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
        { "the counter is zero with bits above the four", 0x30u, 3u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x5au },
        /* the flags byte is read signed */
        { "the flags byte is negative", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0x80u },
        { "the flags byte is all ones", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0x7fff, (int16_t)0x7fff, 0xffu },
        /* the mask is read signed too */
        { "the mask is a negative halfword", 1u, 5u, 0u, 1u, 1u,
          (int16_t)0x8000, (int16_t)0x8000, 0xffu },
        { "the mask keeps everything", 1u, 5u, 1u, 1u, 1u,
          (int16_t)0x7fff, (int16_t)0x7fff, 0x03u },
        /* the middle of the table */
        { "the middle of the table", 7u, 2u, 0u, 7u, 1u,
          (int16_t)0xfffe, (int16_t)0xfffd, 0u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("state_advance: %u differential cases - PASS\n", cases);
    return 0;
}
