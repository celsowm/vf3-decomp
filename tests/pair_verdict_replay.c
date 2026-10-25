/* pair_verdict_replay.c - the readable pair verdict against the retained
 * generated translation of SH-4 0x8C074E7C.
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
 * The function compares two structures and writes a word into the first one:
 * zero, or minus one.  The test lays the literal pool and the two structures
 * out and walks the words and the byte through the decision tree.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_pair_verdict_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c074e7cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the three offsets and the five masks */
#define POOL_BASE 0x0c074f50u
#define POOL_LEN  0x24u
#define OFF_BYTE   (POOL_BASE + 0x00u)
#define OFF_FIELD  (POOL_BASE + 0x02u)
#define OFF_RESULT (POOL_BASE + 0x04u)
#define MASK_A     (POOL_BASE + 0x10u)
#define MASK_B     (POOL_BASE + 0x14u)
#define MASK_C     (POOL_BASE + 0x18u)
#define MASK_D     (POOL_BASE + 0x1cu)
#define MASK_E     (POOL_BASE + 0x20u)

/* the guest's stack pointer at the call */
#define STACK_TOP 0x0c108000u

/* the stack window starts below the word the callee pushes */
#define STACK_WIN_BASE (STACK_TOP - 4u)
#define STACK_LEN      0x20u

/* the two structures */
#define DATA_BASE 0x0c110000u
#define DATA_LEN  0x200u
#define STRUCT_A  (DATA_BASE + 0x000u)
#define STRUCT_B  (DATA_BASE + 0x100u)

/* the offset both structures keep their word at */
#define WORD_OFFSET 0x48u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL  0u
#define OFF_STACK (OFF_POOL + POOL_LEN)
#define OFF_DATA  (OFF_STACK + STACK_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

struct scenario {
    const char *name;
    uint32_t word_a;     /* the first structure's word at +0x48 */
    uint32_t word_b;     /* the second structure's word at +0x48 */
    uint8_t  byte;       /* the byte of the second structure */
    uint32_t field;      /* the field of the first structure */
    int32_t  off_byte;   /* the pool's offsets */
    int32_t  off_field;
    int32_t  off_result;
    uint32_t mask_a;     /* the pool's masks */
    uint32_t mask_b;
    uint32_t mask_c;
    uint32_t mask_d;
    uint32_t mask_e;
    uint32_t result;     /* the word the answer goes into, before the call */
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

    /* the literal pool */
    w16(p + OFF_POOL, OFF_BYTE   - POOL_BASE, (uint16_t)(int16_t)sc->off_byte);
    w16(p + OFF_POOL, OFF_FIELD  - POOL_BASE, (uint16_t)(int16_t)sc->off_field);
    w16(p + OFF_POOL, OFF_RESULT - POOL_BASE, (uint16_t)(int16_t)sc->off_result);
    w32(p + OFF_POOL, MASK_A - POOL_BASE, sc->mask_a);
    w32(p + OFF_POOL, MASK_B - POOL_BASE, sc->mask_b);
    w32(p + OFF_POOL, MASK_C - POOL_BASE, sc->mask_c);
    w32(p + OFF_POOL, MASK_D - POOL_BASE, sc->mask_d);
    w32(p + OFF_POOL, MASK_E - POOL_BASE, sc->mask_e);

    /* the two structures */
    w32(p + OFF_DATA, STRUCT_A + WORD_OFFSET - DATA_BASE, sc->word_a);
    w32(p + OFF_DATA, STRUCT_B + WORD_OFFSET - DATA_BASE, sc->word_b);
    p[OFF_DATA + (STRUCT_B + (uint32_t)sc->off_byte - DATA_BASE)] = sc->byte;
    w32(p + OFF_DATA, STRUCT_A + (uint32_t)sc->off_field  - DATA_BASE, sc->field);
    w32(p + OFF_DATA, STRUCT_A + (uint32_t)sc->off_result - DATA_BASE, sc->result);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = STRUCT_A;
    s->v[5] = STRUCT_B;
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;  r->wins[0].base = POOL_BASE;  r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_STACK; r->wins[1].base = STACK_WIN_BASE; r->wins[1].len = STACK_LEN;
    r->wins[2].data = p + OFF_DATA;  r->wins[2].base = DATA_BASE;  r->wins[2].len = DATA_LEN;
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
        for (unsigned i = 0; i < 54; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                if (++shown == 8u) break;
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

/* the guest's block at 0x8C074EB4: the field has to be empty, and the mask
 * has to be clear of it */
static int field_block(const struct scenario *sc, uint32_t r7, int *t)
{
    *t = (sc->field == 0u);
    if (sc->field != 0u) return 0;
    *t = (r7 == 0u);
    return r7 == 0u;
}

/* the guest's block at 0x8C074ECC */
static uint32_t deep_block(const struct scenario *sc, uint32_t r1, uint32_t r6, int *t)
{
    *t = (r1 == 0u);
    if (r1 != 0u) return 0xffffffffu;
    *t = ((r6 & sc->mask_e) == 0u);
    return ((r6 & sc->mask_e) != 0u) ? 0xffffffffu : 0u;
}

/* what the fixture says the guest has to write, and the T bit it leaves */
static void expect(const struct scenario *sc, uint32_t *written, int *t_bit)
{
    const uint32_t r6 = sc->word_a;
    const uint32_t r7 = sc->word_b;
    const uint32_t r5 = sc->byte & 0xffu;
    uint32_t r13 = 0u;
    int t = 0;

    /* the first gate: the word has to share a bit with the first mask */
    t = ((sc->mask_a & r7) == 0u);
    if (!t) {
        /* the second gate: it must not share a bit with the second one */
        t = ((sc->mask_b & r7) == 0u);
        if (t) {
            const uint32_t c = sc->mask_c & r6;
            const uint32_t d = sc->mask_d & r6;
            t = (c == 0u);
            if (c == 0u) {
                /* the first arm */
                if (field_block(sc, c, &t)) {
                    t = (r5 == 2u);
                    if (r5 == 2u) {
                        r13 = deep_block(sc, d, r6, &t);
                    } else {
                        t = (r5 == 5u);
                        if (r5 == 5u) r13 = deep_block(sc, d, r6, &t);
                    }
                }
            } else {
                /* the second arm */
                int minus_one = 0;
                t = (d == 0u);
                if (d == 0u) {
                    t = (r5 == 4u);
                    if (r5 != 4u) {
                        t = (r5 == 5u);
                        if (r5 != 5u) minus_one = 1;
                    }
                }
                if (minus_one) r13 = 0xffffffffu;
                else (void)field_block(sc, c, &t);
            }
        }
    }
    *written = r13;
    *t_bit = t;
}

static uint32_t shadow_word(const struct run *r, uint32_t addr)
{
    const uint32_t off = OFF_DATA + (addr - DATA_BASE);
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
    const int ok_port = vf3_pair_verdict_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "pair verdict: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "pair verdict: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the answer, checked against the fixture itself */
    uint32_t written = 0;
    int t_bit = 0;
    expect(sc, &written, &t_bit);

    const uint32_t result_addr = STRUCT_A + (uint32_t)sc->off_result;
    if (shadow_word(&ref, result_addr) != written) {
        fprintf(stderr, "pair verdict: %s: the word is %08x, expected %08x\n",
                sc->name, shadow_word(&ref, result_addr), written);
        return 0;
    }
    /* the offset it wrote it to is the one it read */
    if (ref.state.v[0] != (uint32_t)(int32_t)(int16_t)sc->off_result) {
        fprintf(stderr, "pair verdict: %s: r0 %08x, expected %08x\n",
                sc->name, ref.state.v[0], (uint32_t)(int32_t)(int16_t)sc->off_result);
        return 0;
    }
    /* the saved register is back and the stack is where it was */
    if (ref.state.v[13] != 0x76543210u + 13u) {
        fprintf(stderr, "pair verdict: %s: r13 %08x\n", sc->name, ref.state.v[13]);
        return 0;
    }
    if (ref.state.v[15] != STACK_TOP) {
        fprintf(stderr, "pair verdict: %s: the stack is at %08x\n",
                sc->name, ref.state.v[15]);
        return 0;
    }
    /* and the T bit the caller sees */
    if (((ref.state.v[17] & 1u) != 0) != t_bit) {
        fprintf(stderr, "pair verdict: %s: the T bit is %u, expected %d\n",
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
    if (!reg || reg->fn != vf3_pair_verdict_entry) {
        fprintf(stderr, "pair verdict: the port is not registered\n");
        return 1;
    }

    /* the defaults: the word of the second structure has a bit in the first
     * mask and none in the second one.  The third mask is 0x04 and the fourth
     * one is 0x08, so the first structure's word decides the arm it takes:
     * 0x04 and 0x0c land in the second arm, 0x00, 0x08 and 0x10 in the
     * first. */
    static const struct scenario scenarios[] = {
        /* the gate fails: the word shares no bit with the first mask */
        { "the first gate fails", 0x00000004u, 0x00000010u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the gate fails the other way: the word shares a bit with the second
         * mask */
        { "the second gate fails", 0x00000004u, 0x00000003u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the first arm: the first structure's word has no bit in the third
         * mask.  The field of the first structure has to be *empty* for the
         * tree to go on. */
        { "the first arm, the byte is 2", 0x00000010u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 5", 0x00000010u, 0x00000001u, 5u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 3", 0x00000010u, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the byte is 4: the guest's test of the byte 5 is the last one it
         * makes, so the T bit says the byte is not 5 */
        { "the first arm, the byte is 4", 0x00000010u, 0x00000001u, 4u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the field of the first structure is not empty: the tree stops */
        { "the first arm, the field is there", 0x00000010u, 0x00000001u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the fourth mask is not clear: the deep test answers minus one
         * without looking at the last mask */
        { "the first arm, the fourth mask is not clear", 0x00000008u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the last mask is clear of the first structure's word */
        { "the first arm, the last mask is clear", 0x00000000u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the second arm: the first structure's word has a bit in the third
         * mask */
        { "the second arm, the byte is 3", 0x00000004u, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 4", 0x00000004u, 0x00000001u, 4u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 5", 0x00000004u, 0x00000001u, 5u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 2", 0x00000004u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the second arm with the field not empty: the T bit is the one of
         * the field's test */
        { "the second arm, the field is there", 0x00000004u, 0x00000001u, 4u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the fourth mask is not clear", 0x0000000cu, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the byte is read signed and then masked to eight bits: the value
         * the tree compares is the unsigned one */
        { "the byte is two hundred", 0x00000010u, 0x00000001u, 200u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the byte is two hundred and fifty five", 0x00000010u, 0x00000001u, 255u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        /* the offsets are halfwords, so they can be negative */
        { "a negative offset", 0x00000010u, 0x00000001u, 2u, 0u,
          (int32_t)-16, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u,
          0x00000008u, 0x00000010u, 0u },
        /* the word the answer goes into already has bits in it */
        { "the result word is not empty", 0x00000010u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0x40u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("pair_verdict: %u differential cases - PASS\n", cases);
    return 0;
}
