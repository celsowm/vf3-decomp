/* table_getter_replay.c - the readable table getter against the retained
 * generated translation of SH-4 0x8C044068.
 *
 * The generated translation is the reference: it is the machine translation
 * the oracle proved against the captured fight states.  The readable port has
 * to leave the same registers, the same RAM and the same return address as
 * that translation, for every answer the getter can give.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The getter hands the caller's three frame words to the table's handler, so
 * the handler is an entry no ported code owns and the test answers it
 * through the dispatcher's "missing" hook.  The answer it gives mixes the
 * three words, so a getter that forwarded them in the wrong order would
 * answer something else and the test would say so.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_table_getter_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define GETTER_ENTRY 0x0c044068u
#define RETURN_PC   0x0c0abcdeu

/* the two entries no ported code owns */
#define HANDLER      0x0c0ff130u   /* the table's handler            */
#define FALLBACK_CAL 0x0c0ff134u   /* the fallback's own callee      */

/* the getter's literal pool */
#define POOL_BASE   0x0c044130u
#define POOL_LEN    0x30u
#define G_INDEX     (POOL_BASE + 0x0au)   /* the slot's offset  0x8C04413A */
#define G_TABLE     (POOL_BASE + 0x10u)   /* the table          0x8C044140 */
#define G_HANDLER   (POOL_BASE + 0x14u)   /* the handler        0x8C044144 */

/* the fallback's literal pool */
#define FBPOOL_BASE 0x0c043d80u
#define FBPOOL_LEN  0x30u
#define FB_OFFSET   (FBPOOL_BASE + 0x02u)  /* the offset        0x8C043D82 */
#define FB_FLAG     (FBPOOL_BASE + 0x10u)  /* the word it sets  0x8C043D90 */
#define FB_CALLEE   (FBPOOL_BASE + 0x14u)  /* the callee        0x8C043D94 */
#define FB_ARRAY_SLOT (FBPOOL_BASE + 0x18u)  /* the array         0x8C043D98 */

#define STACK_BASE  0x0c100000u
#define STACK_LEN   0x10000u
#define DATA_BASE   0x0c300000u
#define DATA_LEN    0x100u

#define SP 0x0c108000u

/* the addresses inside the data window */
#define TABLE_PTR   (DATA_BASE + 0x10u)   /* holds the table's address  */
#define TABLE       (DATA_BASE + 0x20u)   /* the table itself          */
#define SLOT        (TABLE + 4u)         /* the slot the getter asks  */
#define FBWORD      (DATA_BASE + 0x30u)   /* the fallback sets it to 1 */
#define FB_ARRAY_PTR (DATA_BASE + 0x40u)  /* holds the array's address */
#define FB_ARRAY    (DATA_BASE + 0x50u)   /* the array itself          */

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_STACK  0u
#define OFF_POOL   (OFF_STACK + STACK_LEN)
#define OFF_FBPOOL (OFF_POOL + POOL_LEN)
#define OFF_DATA   (OFF_FBPOOL + FBPOOL_LEN)
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

struct scenario {
    const char *name;
    uint32_t frame[3];      /* the caller's three frame words */
    uint32_t slot;          /* the slot's value: 0 means the fallback runs */
    int expect_fallback;    /* whether the fallback has to run */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[4];
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

static uint32_t r32(const struct run *r, uint32_t addr)
{
    uint32_t off;
    if (addr >= STACK_BASE && addr < STACK_BASE + STACK_LEN) off = OFF_STACK + (addr - STACK_BASE);
    else if (addr >= POOL_BASE && addr < POOL_BASE + POOL_LEN) off = OFF_POOL + (addr - POOL_BASE);
    else if (addr >= FBPOOL_BASE && addr < FBPOOL_BASE + FBPOOL_LEN) off = OFF_FBPOOL + (addr - FBPOOL_BASE);
    else off = OFF_DATA + (addr - DATA_BASE);
    return (uint32_t)r->shadow[off] | ((uint32_t)r->shadow[off + 1] << 8) |
           ((uint32_t)r->shadow[off + 2] << 16) | ((uint32_t)r->shadow[off + 3] << 24);
}

static int missing_hook(uint32_t entry, vf3_matrix_state *s,
                        const vf3_ram_map *ram, int *handled)
{
    if (entry == (HANDLER & 0x1FFFFFFFu)) {
        /* the table's handler: it gets the caller's three frame words on the
         * stack and answers a mix of them, so a getter that forwarded them
         * in the wrong order would answer something else */
        const uint32_t sp = s->v[15];
        uint32_t a[3];
        for (unsigned i = 0; i < 3; ++i) {
            const uint32_t at = sp + i * 4u;
            a[i] = (uint32_t)vf3_matrix_read(ram, at, 4);
        }
        s->v[0] = a[0] ^ (a[1] << 1) ^ (a[2] << 2);
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    if (entry == (FALLBACK_CAL & 0x1FFFFFFFu)) {
        /* the fallback's own callee: it answers -2, which is the answer that
         * sends the fallback down its short path */
        s->v[0] = 0xfffffffeu;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    *handled = 0;
    return 0;
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the getter's pool */
    w16(p + OFF_POOL, G_INDEX - POOL_BASE, 4);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE_PTR);
    w32(p + OFF_POOL, G_HANDLER - POOL_BASE, HANDLER);

    /* the fallback's pool */
    w16(p + OFF_FBPOOL, FB_OFFSET - FBPOOL_BASE, 0);
    w32(p + OFF_FBPOOL, FB_FLAG - FBPOOL_BASE, FBWORD);
    w32(p + OFF_FBPOOL, FB_CALLEE - FBPOOL_BASE, FALLBACK_CAL);
    w32(p + OFF_FBPOOL, FB_ARRAY_SLOT - FBPOOL_BASE, FB_ARRAY_PTR);

    /* the data: the table and the slot the getter asks about */
    w32(p + OFF_DATA, TABLE_PTR - DATA_BASE, TABLE);
    w32(p + OFF_DATA, SLOT - DATA_BASE, sc->slot);
    w32(p + OFF_DATA, FB_ARRAY_PTR - DATA_BASE, FB_ARRAY);

    /* the caller's frame: the three words the getter hands to the handler.
     * They sit at the caller's sp and above it */
    for (unsigned i = 0; i < 3; ++i)
        w32(p + OFF_STACK, (SP - STACK_BASE) + i * 4u, sc->frame[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_STACK;  r->wins[0].base = STACK_BASE;  r->wins[0].len = STACK_LEN;
    r->wins[1].data = p + OFF_POOL;   r->wins[1].base = POOL_BASE;   r->wins[1].len = POOL_LEN;
    r->wins[2].data = p + OFF_FBPOOL; r->wins[2].base = FBPOOL_BASE; r->wins[2].len = FBPOOL_LEN;
    r->wins[3].data = p + OFF_DATA;   r->wins[3].base = DATA_BASE;   r->wins[3].len = DATA_LEN;
    r->map.wins = r->wins;
    r->map.n = 4;
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

    vf3_family_missing = missing_hook;

    const int ok_ref = vf3_matrix_family(GETTER_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_table_getter_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(GETTER_ENTRY, &hook.state, &hook.map, &handled);

    vf3_family_missing = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "table getter: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    /* the answer is the handler's, a mix of the three frame words */
    const uint32_t expect = sc->frame[0] ^ (sc->frame[1] << 1) ^ (sc->frame[2] << 2);
    if (ref.state.v[0] != expect) {
        fprintf(stderr, "table getter: %s answered %08x, expected %08x\n",
                sc->name, ref.state.v[0], expect);
        return 0;
    }

    /* the fallback runs exactly when the slot is taken */
    const uint32_t flag = r32(&ref, FBWORD);
    if ((flag == 1u) != (sc->expect_fallback != 0)) {
        fprintf(stderr, "table getter: %s: the fallback %s\n", sc->name,
                sc->expect_fallback ? "did not run" : "ran");
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(GETTER_ENTRY);
    if (!reg || reg->fn != vf3_table_getter_entry) {
        fprintf(stderr, "table getter: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the slot is taken: the fallback lets the manager know */
        { "taken",  { 0x11111111u, 0x22222222u, 0x33333333u }, 0x5a5a5a5au, 1 },
        /* the slot is clear: the fallback is not asked */
        { "clear",  { 0x11111111u, 0x22222222u, 0x33333333u }, 0u, 0 },
        /* the frame words are in another order: the answer follows them */
        { "order",  { 0xdeadbeefu, 0x00000001u, 0x00010000u }, 0x5a5a5a5au, 1 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("table_getter: %u differential cases - PASS\n", cases);
    return 0;
}
