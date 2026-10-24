/* float_table_replay.c - the readable table unpack against the retained
 * generated translation of SH-4 0x8C06D792.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function looks a table entry up by the low four bits of an index byte
 * and unpacks it into two structures.  The test lays the literal pool, the
 * index byte, the table, the two structures and the pointer cell out the way
 * the guest expects.
 *
 * The table is laid out the way the guest reads it: every sixteen-byte block
 * holds three floats and then two halfwords, and an entry's floats are the
 * *next* block's floats.  The scenarios cover the first and the last entry, an
 * index that the four-bit mask cuts down, and a negative offset for the three
 * floats.
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

int vf3_float_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c06d792u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool */
#define POOL_BASE 0x0c06d870u
#define POOL_LEN  0x40u
#define G_OFFSET (POOL_BASE + 0x0eu)
#define G_STRUCT (POOL_BASE + 0x20u)
#define G_INDEX  (POOL_BASE + 0x2cu)
#define G_DEST   (POOL_BASE + 0x34u)
#define G_TABLE  (POOL_BASE + 0x38u)

/* the index byte */
#define INDEX_BASE 0x0c140000u
#define INDEX_LEN  0x08u

/* the table: sixteen entries of sixty-four bytes */
#define TABLE_BASE 0x0c150000u
#define BLOCKS 16u
#define BLOCK_SIZE 64u
#define TABLE_LEN  (BLOCKS * BLOCK_SIZE)

/* the first structure: the two halfwords land at its +32 and +34 */
#define DEST_BASE 0x0c160000u
#define DEST_LEN  0x40u

/* the second structure: the three floats land around the pool's offset.
 * The window starts before the structure, so a negative offset still lands
 * inside it. */
#define STRUCT_BASE 0x0c170000u
#define STRUCT_LEN  0x100u
#define STRUCT_AT   0x20u

/* the cell that holds the second structure's address */
#define PTR_BASE 0x0c180000u
#define PTR_LEN  0x10u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL   0u
#define OFF_INDEX  (OFF_POOL + POOL_LEN)
#define OFF_TABLE  (OFF_INDEX + INDEX_LEN)
#define OFF_DEST   (OFF_TABLE + TABLE_LEN)
#define OFF_STRUCT (OFF_DEST + DEST_LEN)
#define OFF_PTR    (OFF_STRUCT + STRUCT_LEN)
#define SHADOW_LEN (OFF_PTR + PTR_LEN)

struct scenario {
    const char *name;
    uint8_t index;      /* the index byte */
    int16_t offset;     /* the pool's offset for the three floats */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[6];
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

/* the three floats and the two halfwords of one entry */
static void block(uint8_t *p, uint32_t j)
{
    const uint32_t at = j * BLOCK_SIZE;
    w16(p + at, 12u, (uint16_t)(0x1000 + j));
    w16(p + at, 14u, (uint16_t)(0x2000 + j));
    w32(p + at, 16u, vf3_f32_bits((float)(1.0 + (double)j)));
    w32(p + at, 20u, vf3_f32_bits((float)(2.0 + (double)j)));
    w32(p + at, 24u, vf3_f32_bits((float)(3.0 + (double)j)));
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w16(p + OFF_POOL, G_OFFSET - POOL_BASE, (uint16_t)sc->offset);
    w32(p + OFF_POOL, G_STRUCT - POOL_BASE, PTR_BASE);
    w32(p + OFF_POOL, G_INDEX - POOL_BASE, INDEX_BASE);
    w32(p + OFF_POOL, G_DEST - POOL_BASE, DEST_BASE);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TABLE_BASE);

    /* the index byte */
    p[OFF_INDEX] = sc->index;

    /* the table: sixteen entries */
    for (unsigned j = 0; j < BLOCKS; ++j)
        block(p + OFF_TABLE, j);

    /* the first structure starts with something */
    memset(p + OFF_DEST, 0x5au, DEST_LEN);

    /* the second structure starts with something */
    memset(p + OFF_STRUCT, 0x3cu, STRUCT_LEN);

    /* the cell that holds the second structure's address */
    w32(p + OFF_PTR, 0u, STRUCT_BASE + STRUCT_AT);

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
    r->wins[3].data = p + OFF_DEST;   r->wins[3].base = DEST_BASE;   r->wins[3].len = DEST_LEN;
    r->wins[4].data = p + OFF_STRUCT; r->wins[4].base = STRUCT_BASE; r->wins[4].len = STRUCT_LEN;
    r->wins[5].data = p + OFF_PTR;    r->wins[5].base = PTR_BASE;    r->wins[5].len = PTR_LEN;
    r->map.wins = r->wins;
    r->map.n = 6;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

/* The result, read straight off the fixture: the first structure's two
 * halfwords and the second structure's three floats have to be the ones the
 * entry holds.  This does not consult the generated translation, so it also
 * catches a fixture that is not where the guest looks. */
static int expected(const struct run *r, const struct scenario *sc,
                    const char **why)
{
    const unsigned i = sc->index & 15u;
    const uint8_t *tbl = r->shadow + OFF_TABLE;
    const uint8_t *dst = r->shadow + OFF_DEST;
    const uint8_t *st = r->shadow + OFF_STRUCT + STRUCT_AT;
    const int32_t off = sc->offset;
    const uint32_t entry = i * BLOCK_SIZE;

    /* the entry's halfwords, and they are swapped on the way */
    if (dst[32] != tbl[entry + 12] || dst[33] != tbl[entry + 13]) {
        *why = "the first structure's first halfword";
        return 0;
    }
    if (dst[34] != tbl[entry + 14] || dst[35] != tbl[entry + 15]) {
        *why = "the first structure's second halfword";
        return 0;
    }

    /* the entry's three floats */
    for (unsigned k = 0; k < 3; ++k) {
        const uint32_t want = (uint32_t)tbl[entry + 16 + k * 4u]
                            | ((uint32_t)tbl[entry + 16 + k * 4u + 1] << 8)
                            | ((uint32_t)tbl[entry + 16 + k * 4u + 2] << 16)
                            | ((uint32_t)tbl[entry + 16 + k * 4u + 3] << 24);
        const int32_t at = off - (k == 0 ? 0 : (k == 1 ? 8 : 4));
        uint32_t got = (uint32_t)st[at + 0] | ((uint32_t)st[at + 1] << 8)
                     | ((uint32_t)st[at + 2] << 16) | ((uint32_t)st[at + 3] << 24);
        if (got != want) {
            *why = "the second structure's float";
            return 0;
        }
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
    const int ok_port = vf3_float_table_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "float table: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "float table: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* and the result is checked against the fixture itself */
    const char *why = "";
    if (!expected(&ref, sc, &why)) {
        fprintf(stderr, "float table: %s: %s is wrong\n", sc->name, why);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_float_table_entry) {
        fprintf(stderr, "float table: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the first entry */
        { "first",    0x00u,  0x0020 },
        /* the last entry: its floats sit past the end of the table */
        { "last",     0x0fu,  0x0020 },
        /* the four-bit mask cuts the index down to three */
        { "masked",   0xf3u,  0x0020 },
        /* and the byte is read as unsigned, so 0x93 is the entry nine */
        { "unsigned", 0x93u,  0x0020 },
        /* a negative offset for the three floats */
        { "negative", 0x05u, -0x0010 },
        /* a large offset, near the end of the structure */
        { "large",    0x07u,  0x0060 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("float_table: %u differential cases - PASS\n", cases);
    return 0;
}
