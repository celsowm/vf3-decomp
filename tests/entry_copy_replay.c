/* entry_copy_replay.c - the readable entry copy against the retained
 * generated translation of SH-4 0x8C06D7D6.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function looks a table entry up by the whole index byte and copies some
 * of its fields into a structure, twice: once at each of the two offsets the
 * pool holds.  The test lays the literal pool, the index byte, the table, the
 * structure and the pointer cell out the way the guest expects.
 *
 * The table has 256 entries of sixty-four bytes, so the scenarios walk the
 * index from the first entry to the last.
 *
 * The test also checks the result against the fixture on its own: a
 * differential alone is not enough, because a fixture that is not where the
 * guest looks makes both sides read the same wrong bytes and agree on them.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_entry_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c06d7d6u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool */
#define POOL_BASE 0x0c06d870u
#define POOL_LEN  0x40u
#define G_FIRST  (POOL_BASE + 0x10u)
#define G_SECOND (POOL_BASE + 0x12u)
#define G_STRUCT (POOL_BASE + 0x20u)
#define G_INDEX  (POOL_BASE + 0x2cu)
#define G_TABLE  (POOL_BASE + 0x38u)

/* the index byte */
#define INDEX_BASE 0x0c140000u
#define INDEX_LEN  0x08u

/* the table: 256 entries of sixty-four bytes */
#define TABLE_BASE 0x0c150000u
#define ENTRY_SIZE 64u
#define ENTRIES 256u
#define TABLE_LEN  (ENTRIES * ENTRY_SIZE)

/* the structure: the window starts before it, so a negative offset lands
 * inside the window */
#define STRUCT_WIN 0x0c180000u
#define STRUCT_LEN 0x400u
#define STRUCT_AT  0x200u

/* the cell that holds the structure's address */
#define PTR_BASE 0x0c1a0000u
#define PTR_LEN  0x10u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL   0u
#define OFF_INDEX  (OFF_POOL + POOL_LEN)
#define OFF_TABLE  (OFF_INDEX + INDEX_LEN)
#define OFF_STRUCT (OFF_TABLE + TABLE_LEN)
#define OFF_PTR    (OFF_STRUCT + STRUCT_LEN)
#define SHADOW_LEN (OFF_PTR + PTR_LEN)

struct scenario {
    const char *name;
    uint8_t index;     /* the index byte */
    int16_t first;     /* the first offset in the structure */
    int16_t second;    /* and the second */
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

/* one entry: three bytes and five floats */
static void entry(uint8_t *p, unsigned j)
{
    const uint32_t at = j * ENTRY_SIZE;
    p[at + 5] = (uint8_t)(0x80u + (j & 0x3fu));   /* negative as a signed byte */
    p[at + 6] = (uint8_t)(0x20u + (j & 0x1fu));
    p[at + 7] = (uint8_t)j;
    w32(p + at, 16u, vf3_f32_bits((float)(1.0 + (double)j)));
    w32(p + at, 24u, vf3_f32_bits((float)(2.0 + (double)j)));
    w32(p + at, 28u, vf3_f32_bits((float)(3.0 + (double)j)));
    w32(p + at, 32u, vf3_f32_bits((float)(4.0 + (double)j)));
    w32(p + at, 36u, vf3_f32_bits((float)(5.0 + (double)j)));
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w16(p + OFF_POOL, G_FIRST - POOL_BASE, (uint16_t)sc->first);
    w16(p + OFF_POOL, G_SECOND - POOL_BASE, (uint16_t)sc->second);
    w32(p + OFF_POOL, G_STRUCT - POOL_BASE, PTR_BASE);
    w32(p + OFF_POOL, G_INDEX - POOL_BASE, INDEX_BASE);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE_BASE);

    /* the index byte */
    p[OFF_INDEX] = sc->index;

    /* the table */
    for (unsigned j = 0; j < ENTRIES; ++j)
        entry(p + OFF_TABLE, j);

    /* the structure starts full of a pattern */
    memset(p + OFF_STRUCT, 0x5au, STRUCT_LEN);

    /* the cell that holds the structure's address */
    w32(p + OFF_PTR, 0u, STRUCT_WIN + STRUCT_AT);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL;   r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_INDEX;  r->wins[1].base = INDEX_BASE;  r->wins[1].len = INDEX_LEN;
    r->wins[2].data = p + OFF_TABLE;  r->wins[2].base = TABLE_BASE;  r->wins[2].len = TABLE_LEN;
    r->wins[3].data = p + OFF_STRUCT; r->wins[3].base = STRUCT_WIN; r->wins[3].len = STRUCT_LEN;
    r->wins[4].data = p + OFF_PTR;    r->wins[4].base = PTR_BASE;    r->wins[4].len = PTR_LEN;
    r->map.wins = r->wins;
    r->map.n = 5;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

/* The result, read straight off the fixture: the structure has to hold the
 * entry's fields where the guest puts them.  This does not consult the
 * generated translation, so it also catches a fixture that is not where the
 * guest looks.
 *
 * The two groups can overlap - the offsets are the guest's to choose - and
 * the order the guest writes them in decides what wins, so the expectation
 * is built by applying the writes in that order. */
static int expected(const struct run *r, const struct scenario *sc,
                    const char **why)
{
    uint8_t want[STRUCT_LEN];
    const uint8_t *tbl = r->shadow + OFF_TABLE + (unsigned)sc->index * ENTRY_SIZE;
    const uint8_t *st = r->shadow + OFF_STRUCT + STRUCT_AT;
    const int a = sc->first;
    const int b = sc->second;

    /* the pattern the structure started with */
    memset(want, 0x5au, sizeof want);

    /* the first group: the three bytes and three of the floats */
    for (unsigned k = 0; k < 3; ++k)
        want[a + (int)k] = tbl[5 + k];
    memcpy(want + a - 20, tbl + 28, 4);
    memcpy(want + a - 16, tbl + 32, 4);
    memcpy(want + a - 4, tbl + 36, 4);

    /* and the second group: the same three bytes and the other two floats */
    for (unsigned k = 0; k < 3; ++k)
        want[b + (int)k] = tbl[5 + k];
    memcpy(want + b - 12, tbl + 24, 4);
    memcpy(want + b - 16, tbl + 16, 4);

    if (memcmp(st, want, STRUCT_LEN - STRUCT_AT)) {
        *why = "the structure";
        return 0;
    }
    return 1;
}

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
    const int ok_port = vf3_entry_copy_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "entry copy: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "entry copy: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* and the result is checked against the fixture itself */
    const char *why = "";
    if (!expected(&ref, sc, &why)) {
        fprintf(stderr, "entry copy: %s: %s are wrong\n", sc->name, why);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_entry_copy_entry) {
        fprintf(stderr, "entry copy: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the first entry */
        { "first",    0x00u,  0x0060, 0x0040 },
        /* an entry in the middle */
        { "middle",   0x03u,  0x0060, 0x0040 },
        /* a high index: the whole byte is the index */
        { "high",     0xc8u,  0x0060, 0x0040 },
        /* the last entry */
        { "last",     0xffu,  0x0060, 0x0040 },
        /* both offsets below the structure */
        { "negative", 0x07u, -0x0020, -0x0010 },
        /* the two offsets the same */
        { "same",     0x09u,  0x0050, 0x0050 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("entry_copy: %u differential cases - PASS\n", cases);
    return 0;
}
