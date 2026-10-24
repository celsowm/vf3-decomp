/* byte_decode_replay.c - the readable word decoder against the retained
 * generated translation of SH-4 0x8C04538A.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function pops a word off the caller's stack, copies its four bytes into
 * the object - in the natural order or turned around, depending on a table -
 * and then classifies the object's first byte into an answer at the object's
 * +20.  The test lays the caller's stack, the literal pool, the table and the
 * object out the way the guest expects.  The scenarios cover the two byte
 * orders, the mark, the limit, and a limit that is negative.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_byte_decode_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c04538au

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the mark, the limit, the table's base and the table */
#define POOL_BASE 0x0c045440u
#define POOL_LEN  0x20u
#define G_MARK  (POOL_BASE + 0x08u)   /* the byte that means "no value" */
#define G_BASE  (POOL_BASE + 0x0au)   /* the table's base */
#define G_LIMIT (POOL_BASE + 0x0cu)   /* the byte at or above which the word counts */
#define G_TABLE (POOL_BASE + 0x14u)   /* the table */

/* the table: the global points at a cell that holds the table's first word,
 * and the pool's base is a signed halfword added to it */
#define PTR_BASE 0x0c050000u
#define PTR_LEN  0x10u
#define TBL_FIRST 0x0c030000u

/* the table itself: the entry sits at the first word plus the base */
#define TBL_BASE 0x0c030000u
#define TBL_LEN  0x40u
#define TBL_ENTRY 0x10u
#define TBL_BASE_OFF 0x0010u   /* the pool's base: a signed halfword */

/* the stack: the caller's words sit above the frame this function builds */
#define STK_BASE 0x0c110000u
#define STK_LEN  0x100u
#define CALLER_SP (STK_BASE + 0x80u)  /* the caller's stack: word0, word1 */
#define OWN_SP    (STK_BASE + 0x40u)  /* this function's stack */

/* the object */
#define OBJ_BASE 0x0c120000u
#define OBJ_LEN  0x40u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_PTR  (OFF_POOL + POOL_LEN)
#define OFF_TBL  (OFF_PTR + PTR_LEN)
#define OFF_STK  (OFF_TBL + TBL_LEN)
#define OFF_OBJ  (OFF_STK + STK_LEN)
#define SHADOW_LEN (OFF_OBJ + OBJ_LEN)

struct scenario {
    const char *name;
    uint32_t entry;    /* the table's entry: 1 asks for the bytes turned around */
    uint32_t word0;    /* the word on the caller's stack */
    uint32_t word1;    /* the word behind it */
    uint16_t mark;     /* the byte that means "no value" */
    uint16_t limit;    /* the byte at or above which the word counts */
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
    w16(p + OFF_POOL, G_MARK - POOL_BASE, sc->mark);
    w16(p + OFF_POOL, G_LIMIT - POOL_BASE, sc->limit);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, PTR_BASE);
    /* the table's base: the entry sits at the table's first word plus this */
    w16(p + OFF_POOL, G_BASE - POOL_BASE, (uint16_t)TBL_BASE_OFF);

    /* the cell the table's global points at */
    w32(p + OFF_PTR, 0u, TBL_FIRST);

    /* the table's entry */
    w32(p + OFF_TBL, TBL_ENTRY, sc->entry);

    /* the caller's stack */
    w32(p + OFF_STK, CALLER_SP - STK_BASE, sc->word0);
    w32(p + OFF_STK, CALLER_SP - STK_BASE + 4u, sc->word1);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[5] = CALLER_SP;
    s->v[15] = OWN_SP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_PTR;  r->wins[1].base = PTR_BASE;  r->wins[1].len = PTR_LEN;
    r->wins[2].data = p + OFF_TBL;  r->wins[2].base = TBL_BASE;  r->wins[2].len = TBL_LEN;
    r->wins[3].data = p + OFF_STK;  r->wins[3].base = STK_BASE;  r->wins[3].len = STK_LEN;
    r->wins[4].data = p + OFF_OBJ;  r->wins[4].base = OBJ_BASE;  r->wins[4].len = OBJ_LEN;
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
    const int ok_port = vf3_byte_decode_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "byte decode: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "byte decode: %s reads outside the windows (oob %u/%u/%u)\n",
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
    if (!reg || reg->fn != vf3_byte_decode_entry) {
        fprintf(stderr, "byte decode: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the natural order, the byte below the limit: no answer */
        { "natural zero",  0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* the natural order, the byte at the limit: the caller's word */
        { "natural word",  0u, 0x11223044u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* one below the limit: no answer */
        { "just below",    0u, 0x1122303fu, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* the natural order, the first byte is the mark: no value */
        { "natural mark",  0u, 0x000000eeu, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the first byte is now the last one */
        { "turned word",   1u, 0x44112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the first byte is the mark */
        { "turned mark",   1u, 0xee112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* turned around, the byte below the limit: no answer */
        { "turned zero",   1u, 0x11112233u, 0xcafebabeu, 0x00eeu, 0x0040u },
        /* a limit of 255: only the byte 255 is at or above it */
        { "limit 255",     0u, 0x112230ffu, 0xcafebabeu, 0x00eeu, 0x00ffu },
        /* a negative limit: every byte is at or above it */
        { "negative limit", 0u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x8000u },
        /* an entry that is not 1 asks for the natural order */
        { "other entry",   2u, 0x11223011u, 0xcafebabeu, 0x00eeu, 0x0040u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("byte_decode: %u differential cases - PASS\n", cases);
    return 0;
}
