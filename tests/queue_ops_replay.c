/* queue_ops_replay.c - the readable queue family (SH-4 0x8C038570, 0x8C038590
 * and 0x8C0385C0) against the retained generated translation.
 *
 * The three functions - the reset, the push and the pop - call nobody, so the
 * test needs no stub: the two leaves are the *generated* translation and the
 * readable port, and they are compared against each other.
 *
 * The three arms are:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it).
 *
 * All three compare the whole register file, the return PC, the failed PC, the
 * out-of-window counter and every RAM byte.  The test also checks the outcome
 * **against the fixture itself**: the answer in r0, the T bit the guest leaves
 * behind, the queue's counter and the words the two arrays and the struct
 * carry.  Those expectations come from a second implementation in the test,
 * written from the disassembly and not from the port - a differential alone is
 * not enough, because a fixture that is not where the guest looks makes both
 * sides read the same wrong bytes and agree on them.
 *
 * The fixture uses the game's own addresses, taken from the literal pool the
 * oracle recorded: the struct at 0x0c16b880, the first array at 0x0c1a5720 and
 * the second at 0x0c1a57e0.  The two arrays are therefore 48 words apart, so
 * the first array's slot 48 *is* the second array's slot 0 - the queue writes
 * slot 48 when the counter goes from 47 to 48.  The fixture models that one
 * contiguous space, so the alias is exercised rather than hidden.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_queue_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY_RESET 0x0c038570u
#define ENTRY_PUSH  0x0c038590u
#define ENTRY_POP   0x0c0385c0u

#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE   0x0c038000u   /* the literal pool */
#define POOL_LEN    0x1000u
#define STRUCT_BASE 0x0c16b000u   /* the queue's struct */
#define STRUCT_LEN  0x1000u
#define DATA_BASE   0x0c1a5000u   /* the two arrays */
#define DATA_LEN    0x1000u
#define NWIN 3

#define OFF_POOL   0u
#define OFF_STRUCT (OFF_POOL + POOL_LEN)
#define OFF_DATA   (OFF_STRUCT + STRUCT_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

/* ---- where things live ---- */
#define STRUCT_ADDR (STRUCT_BASE + 0x880u)
#define ARRAY1_ADDR (DATA_BASE + 0x720u)
#define ARRAY2_ADDR (DATA_BASE + 0x7e0u)

/* ---- the pool's entries ---- */
#define P_STRUCT (POOL_BASE + 0x5f0u)
#define P_ARRAY1 (POOL_BASE + 0x5f4u)
#define P_ARRAY2 (POOL_BASE + 0x5f8u)

/* ---- the struct's fields ---- */
#define FIELD_COUNT 6u
#define FIELD_A     44u
#define FIELD_A2    48u
#define FIELD_B     56u
#define FIELD_B2    60u

#define QUEUE_LIMIT 48u

/* The two arrays are one contiguous space: the first array's slots 0..48 and
 * then the second array's slots 0..48, the second array starting 48 words
 * after the first - so the first array's slot 48 *is* the second array's
 * slot 0. */
#define ARRAY_STRIDE 48u
#define SPACE_WORDS 97u

struct scenario {
    const char *name;
    uint32_t entry;
    int32_t counter;       /* the struct's halfword at +6 */
    uint32_t a, a2;        /* the struct's words at 44 and 48 */
    uint32_t b, b2;        /* the struct's words at 56 and 60 */
    uint32_t space[SPACE_WORDS];  /* the first array, then the second */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
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

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static uint32_t r16(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool: the addresses the guest reads */
    w32(p + OFF_POOL, P_STRUCT - POOL_BASE, STRUCT_ADDR);
    w32(p + OFF_POOL, P_ARRAY1 - POOL_BASE, ARRAY1_ADDR);
    w32(p + OFF_POOL, P_ARRAY2 - POOL_BASE, ARRAY2_ADDR);

    /* the struct.  The window is filled with garbage first: the guest writes
     * the counter as a *halfword*, and a port that writes a word instead
     * clobbers the two bytes behind it - which the fixture has to make
     * visible.  The words at 44 and 48 carry the same value in the game until
     * a pop breaks them apart (the pop writes 44 and leaves 48 alone), so the
     * fixture gives each of the four its own value: a port that reads the
     * duplicate where the guest reads the original is caught. */
    memset(p + OFF_STRUCT, 0xa5, STRUCT_LEN);
    w16(p + OFF_STRUCT, STRUCT_ADDR - STRUCT_BASE + FIELD_COUNT,
        (uint16_t)sc->counter);
    w32(p + OFF_STRUCT, STRUCT_ADDR - STRUCT_BASE + FIELD_A, sc->a);
    w32(p + OFF_STRUCT, STRUCT_ADDR - STRUCT_BASE + FIELD_A2, sc->a2);
    w32(p + OFF_STRUCT, STRUCT_ADDR - STRUCT_BASE + FIELD_B, sc->b);
    w32(p + OFF_STRUCT, STRUCT_ADDR - STRUCT_BASE + FIELD_B2, sc->b2);

    /* the two arrays, as the one contiguous space the guest sees */
    for (unsigned i = 0; i < SPACE_WORDS; ++i)
        w32(p + OFF_DATA, ARRAY1_ADDR - DATA_BASE + 4u * i, sc->space[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;          /* sr: the corpus' own value, T bit set */
    /* The dispatcher refuses to run anything when the FPU is unsupported
     * (FPSCR.RM is 2 or 3, or the precision bit is set), and the corpus
     * carries 0x240001 / 0x40001.  The three functions use no FP
     * instruction, but the gate stands between the caller and the body. */
    s->v[18] = 0x00024001u;          /* fpscr: the corpus' own value */
    s->budget = 1000000u;

    r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].base = STRUCT_BASE; r->wins[1].len = STRUCT_LEN;
    r->wins[2].base = DATA_BASE;   r->wins[2].len = DATA_LEN;
    r->wins[0].data = p + OFF_POOL;
    r->wins[1].data = p + OFF_STRUCT;
    r->wins[2].data = p + OFF_DATA;
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int call_port(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == ENTRY_RESET) return vf3_queue_reset_entry(s, ram);
    if (entry == ENTRY_PUSH) return vf3_queue_push_entry(s, ram);
    return vf3_queue_pop_entry(s, ram);
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
                fprintf(stderr, "  %s: ram %u %02x != %02x\n", what, i,
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

/* ---- the model of the guest ---- *
 *
 * The reset empties the queue and seeds the struct with the arrays' first
 * slots.  The push refuses when the counter has reached the limit, and
 * otherwise writes the struct's two words into the arrays at the counter's new
 * value.  The pop refuses when the counter is not above zero, and otherwise
 * takes the arrays' slots at the counter's value back into the struct and
 * counts down. */
struct outcome {
    uint32_t answer;      /* r0 */
    int t;                /* the T bit the guest leaves */
    int32_t counter;      /* the queue's counter afterwards */
    uint32_t w44, w48;    /* the struct's first pair afterwards */
    uint32_t w56, w60;    /* the struct's second pair afterwards */
    int touched;          /* the array slot the function wrote, or -1 */
    uint32_t slot;        /* what it wrote into the first array */
    uint32_t slot2;       /* what it wrote into the second array */
};

static void model(const struct scenario *sc, struct outcome *out)
{
    /* the counter is a halfword, so the guest sees it sign extended */
    const int32_t count = (int32_t)(int16_t)(uint16_t)sc->counter;

    out->answer = 0u;
    out->t = 1;                       /* the guest starts with the T bit set */
    out->counter = count;
    out->w44 = sc->a;
    out->w48 = sc->a2;
    out->w56 = sc->b;
    out->w60 = sc->b2;
    out->touched = -1;
    out->slot = 0u;
    out->slot2 = 0u;

    if (sc->entry == ENTRY_RESET) {
        out->counter = 0;
        out->w44 = sc->space[0];              /* the first array's slot 0 */
        out->w48 = sc->space[0];
        out->w56 = sc->space[ARRAY_STRIDE];   /* the second array's slot 0 */
        out->w60 = sc->space[ARRAY_STRIDE];
        return;
    }
    if (sc->entry == ENTRY_PUSH) {
        /* cmp/ge r3,r5: T = (counter >= limit) */
        out->t = (count >= (int32_t)QUEUE_LIMIT);
        if (out->t) {
            /* the queue is full: nothing moves and the answer is -1 */
            out->answer = 0xffffffffu;
            return;
        }
        out->counter = count + 1;
        out->touched = (int)out->counter;
        out->slot = sc->a;                    /* the struct's word at 44 */
        out->slot2 = sc->b;                   /* the struct's word at 56 */
        return;
    }
    /* the pop */
    out->t = (count > 0);
    if (!out->t) {
        out->answer = 0xffffffffu;    /* the queue is empty */
        return;
    }
    /* the pop writes the struct's words at 44 and 56 only - the copies at
     * 48 and 60 keep the values they had */
    out->w44 = sc->space[count];
    out->w56 = sc->space[ARRAY_STRIDE + count];
    out->counter = count - 1;
}

static unsigned cases;
static unsigned taken_full;
static unsigned taken_empty;

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(sc->entry, &ref.state, &ref.map);
    const int ok_port = call_port(sc->entry, &port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(sc->entry, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "queue: %s differs (ok %d/%d/%d; ref pc %08x failed %08x "
                "oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "queue: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        struct outcome want;
        model(sc, &want);
        const uint8_t *sp = ref.shadow + OFF_STRUCT + (STRUCT_ADDR - STRUCT_BASE);
        const uint8_t *dp = ref.shadow + OFF_DATA + (ARRAY1_ADDR - DATA_BASE);
        const uint8_t *dp2 = ref.shadow + OFF_DATA + (ARRAY2_ADDR - DATA_BASE);

        if (ref.state.v[0] != want.answer) {
            fprintf(stderr, "queue: %s: the answer is %08x, expected %08x\n",
                    sc->name, ref.state.v[0], want.answer);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != want.t) {
            fprintf(stderr, "queue: %s: the T bit is %u, expected %d\n",
                    sc->name, ref.state.v[17] & 1u, want.t);
            return 0;
        }
        if ((int32_t)(int16_t)r16(sp, FIELD_COUNT) != want.counter) {
            fprintf(stderr, "queue: %s: the counter is %d, expected %d\n",
                    sc->name, (int32_t)(int16_t)r16(sp, FIELD_COUNT), want.counter);
            return 0;
        }
        if (r32(sp, FIELD_A) != want.w44 || r32(sp, FIELD_A2) != want.w48) {
            fprintf(stderr, "queue: %s: the first pair is %08x/%08x, expected "
                    "%08x/%08x\n", sc->name, r32(sp, FIELD_A), r32(sp, FIELD_A2),
                    want.w44, want.w48);
            return 0;
        }
        if (r32(sp, FIELD_B) != want.w56 || r32(sp, FIELD_B2) != want.w60) {
            fprintf(stderr, "queue: %s: the second pair is %08x/%08x, expected "
                    "%08x/%08x\n", sc->name, r32(sp, FIELD_B), r32(sp, FIELD_B2),
                    want.w56, want.w60);
            return 0;
        }
        if (want.touched >= 0) {
            const unsigned k = (unsigned)want.touched;
            if (r32(dp, 4u * k) != want.slot) {
                fprintf(stderr, "queue: %s: the first array's slot %u is %08x, "
                        "expected %08x\n", sc->name, k, r32(dp, 4u * k), want.slot);
                return 0;
            }
            if (r32(dp2, 4u * k) != want.slot2) {
                fprintf(stderr, "queue: %s: the second array's slot %u is %08x, "
                        "expected %08x\n", sc->name, k, r32(dp2, 4u * k), want.slot2);
                return 0;
            }
        }
        if (sc->entry == ENTRY_PUSH && want.t) ++taken_full;
        if (sc->entry == ENTRY_POP && !want.t) ++taken_empty;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the ports have to be registered, or the native tick never reaches them */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY_RESET);
    if (!reg || reg->fn != vf3_queue_reset_entry) {
        fprintf(stderr, "queue: the reset is not registered\n");
        return 1;
    }
    reg = vf3_readable_find(ENTRY_PUSH);
    if (!reg || reg->fn != vf3_queue_push_entry) {
        fprintf(stderr, "queue: the push is not registered\n");
        return 1;
    }
    reg = vf3_readable_find(ENTRY_POP);
    if (!reg || reg->fn != vf3_queue_pop_entry) {
        fprintf(stderr, "queue: the pop is not registered\n");
        return 1;
    }

    /* The slots are numbered from 0 in the space; the first array's slots are
     * 0..48 and the second array's slots are 49..97. */
    static const struct scenario scenarios[] = {
        { .name = "the reset on an empty queue", .entry = ENTRY_RESET,
          .counter = 0, .a = 0x11111111u, .a2 = 0x12121212u,
          .b = 0x22222222u, .b2 = 0x23232323u,
          .space = { [0] = 0xaaaa0001u, [ARRAY_STRIDE] = 0xbbbb0001u } },
        { .name = "the reset on a full queue", .entry = ENTRY_RESET,
          .counter = 48, .a = 0x33333333u, .a2 = 0x34343434u,
          .b = 0x44444444u, .b2 = 0x45454545u,
          .space = { [0] = 0xaaaa0002u, [ARRAY_STRIDE] = 0xbbbb0002u } },
        { .name = "the reset with a negative counter", .entry = ENTRY_RESET,
          .counter = -1, .a = 0x55555555u, .a2 = 0x56565656u,
          .b = 0x66666666u, .b2 = 0x67676767u,
          .space = { [0] = 0xaaaa0003u, [ARRAY_STRIDE] = 0xbbbb0003u } },

        { .name = "the push into an empty queue", .entry = ENTRY_PUSH,
          .counter = 0, .a = 0x11111111u, .a2 = 0x12121212u,
          .b = 0x22222222u, .b2 = 0x23232323u,
          .space = { [0] = 0xaaaa0004u, [ARRAY_STRIDE] = 0xbbbb0004u } },
        { .name = "the push into a half full queue", .entry = ENTRY_PUSH,
          .counter = 5, .a = 0x77777777u, .a2 = 0x78787878u,
          .b = 0x88888888u, .b2 = 0x89898989u,
          .space = { [0] = 0xaaaa0005u, [ARRAY_STRIDE] = 0xbbbb0005u } },
        { .name = "the push into the last free slot", .entry = ENTRY_PUSH,
          .counter = 47, .a = 0x99999999u, .a2 = 0x9a9a9a9au,
          .b = 0xaaaaaaaau, .b2 = 0xababababu,
          .space = { [0] = 0xaaaa0006u, [ARRAY_STRIDE] = 0xbbbb0006u } },
        { .name = "the push into a full queue", .entry = ENTRY_PUSH,
          .counter = 48, .a = 0xbbbbbbbbu, .a2 = 0xbcbcbcbcu,
          .b = 0xccccccccu, .b2 = 0xcdcdcdcdu,
          .space = { [0] = 0xaaaa0007u, [ARRAY_STRIDE] = 0xbbbb0007u } },
        { .name = "the push into a queue with a negative counter",
          .entry = ENTRY_PUSH, .counter = -1,
          .a = 0xdedededeu, .a2 = 0xdfdfdfdfu,
          .b = 0xe0e0e0e0u, .b2 = 0xe1e1e1e1u,
          .space = { [0] = 0xaaaa0014u, [ARRAY_STRIDE] = 0xbbbb0014u } },

        { .name = "the pop out of a queue with one entry", .entry = ENTRY_POP,
          .counter = 1, .a = 0x11111111u, .a2 = 0x12121212u,
          .b = 0x22222222u, .b2 = 0x23232323u,
          .space = { [1] = 0xaaaa0008u, [ARRAY_STRIDE + 1] = 0xbbbb0008u } },
        { .name = "the pop out of a queue with many entries", .entry = ENTRY_POP,
          .counter = 7, .a = 0x33333333u, .a2 = 0x34343434u,
          .b = 0x44444444u, .b2 = 0x45454545u,
          .space = { [7] = 0xaaaa0010u, [ARRAY_STRIDE + 7] = 0xbbbb0010u } },
        { .name = "the pop out of a full queue", .entry = ENTRY_POP,
          .counter = 48, .a = 0x55555555u, .a2 = 0x56565656u,
          .b = 0x66666666u, .b2 = 0x67676767u,
          .space = { [48] = 0xaaaa0011u, [ARRAY_STRIDE + 48] = 0xbbbb0011u } },
        { .name = "the pop out of an empty queue", .entry = ENTRY_POP,
          .counter = 0, .a = 0x77777777u, .a2 = 0x78787878u,
          .b = 0x88888888u, .b2 = 0x89898989u,
          .space = { [0] = 0xaaaa0012u, [ARRAY_STRIDE] = 0xbbbb0012u } },
        { .name = "the pop out of a queue with a negative counter",
          .entry = ENTRY_POP, .counter = -1,
          .a = 0x99999999u, .a2 = 0x9a9a9a9au,
          .b = 0xaaaaaaaau, .b2 = 0xababababu,
          .space = { [0] = 0xaaaa0013u, [ARRAY_STRIDE] = 0xbbbb0013u } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    /* the refusals have to be exercised */
    if (!taken_full || !taken_empty) {
        fprintf(stderr, "queue: the scenarios do not cover both refusals "
                "(%u full, %u empty)\n", taken_full, taken_empty);
        return 1;
    }

    printf("queue_ops: %u differential cases - PASS\n", cases);
    return 0;
}
