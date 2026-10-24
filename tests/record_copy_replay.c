/* record_copy_replay.c - the readable record repack against the retained
 * generated translation of SH-4 0x8C043A7C.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function copies twenty-four records from the table into the destination
 * array, repacking the fields on the way.  The test lays the literal pool,
 * the table, the source records and the destination out the way the guest
 * expects.  The scenarios cover a plain table, a destination that already
 * holds something, a table of high bytes and a table whose bytes wrap.
 *
 * The test also checks the result against the fixture on its own.  A
 * differential alone is not enough here: the first version of this fixture
 * laid the records one stride too low, so *both* sides read the zero gap
 * between the records and agreed on nothing at all.  The out-of-window
 * counter did not see it either, because the wrong address was still inside
 * a captured window.  The `expected` check below pins the repack to the
 * bytes the fixture wrote, so a fixture that is not where the guest looks
 * fails the test instead of passing it.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_record_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c043a7cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the destination and the table */
#define POOL_BASE 0x0c043b70u
#define POOL_LEN  0x10u
#define G_DEST  (POOL_BASE + 0x04u)
#define G_TABLE (POOL_BASE + 0x08u)

/* the table's cell holds the source's base */
#define TBL_BASE 0x0c170000u
#define TBL_LEN  0x10u

/* the source's records: twenty-four of them, forty-four bytes apart, and the
 * first one sits forty bytes into the window */
#define SRC_BASE 0x0c180000u
#define SRC_LEN  0x460u
#define SRC_STRIDE 0x2cu
#define SRC_OFFSET 0x28u

/* the destination's records: twenty-four of them, twenty-four bytes apart */
#define DST_BASE 0x0c190000u
#define DST_LEN  0x240u
#define DEST_STRIDE 0x18u

/* how many records are copied */
#define RECORDS 24u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_TBL  (OFF_POOL + POOL_LEN)
#define OFF_SRC  (OFF_TBL + TBL_LEN)
#define OFF_DST  (OFF_SRC + SRC_LEN)
#define SHADOW_LEN (OFF_DST + DST_LEN)

struct scenario {
    const char *name;
    uint8_t fill;      /* what the destination starts with */
    uint8_t pattern;   /* the source's bytes are this and their successors */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[4];
    vf3_ram_map map;
};

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

/* the byte the fixture puts at a source record's field */
static uint8_t src_byte(const struct scenario *sc, unsigned i, unsigned b)
{
    return (uint8_t)(sc->pattern + b + i);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w32(p + OFF_POOL, G_DEST - POOL_BASE, DST_BASE);
    w32(p + OFF_POOL, G_TABLE - POOL_BASE, TBL_BASE);

    /* the table's cell: the source's base */
    w32(p + OFF_TBL, 0u, SRC_BASE);

    /* the source's twenty-four records.  The first one is SRC_OFFSET bytes
     * into the window, because that is where the guest reads it from. */
    for (unsigned i = 0; i < RECORDS; ++i) {
        const uint32_t at = SRC_OFFSET + i * SRC_STRIDE;
        for (unsigned b = 0; b < 4; ++b)
            p[OFF_SRC + at + b] = src_byte(sc, i, b);
        for (unsigned b = 8; b < 12; ++b)
            p[OFF_SRC + at + b] = src_byte(sc, i, b);
        w32(p + OFF_SRC, at + 16u, 0x11111111u * (i + 1u));
        w32(p + OFF_SRC, at + 20u, 0x22222222u * (i + 1u));
    }

    /* the destination starts with something, so a byte that is not written
     * shows up */
    memset(p + OFF_DST, sc->fill, DST_LEN);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x0c160000u;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_TBL;  r->wins[1].base = TBL_BASE;  r->wins[1].len = TBL_LEN;
    r->wins[2].data = p + OFF_SRC;  r->wins[2].base = SRC_BASE;  r->wins[2].len = SRC_LEN;
    r->wins[3].data = p + OFF_DST;  r->wins[3].base = DST_BASE;  r->wins[3].len = DST_LEN;
    r->map.wins = r->wins;
    r->map.n = 4;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

/* The repack, read straight off the fixture: the destination's record must
 * hold the source's bytes and words where the guest puts them.  This does not
 * consult the generated translation, so it also catches a fixture that is not
 * where the guest looks. */
static int expected(const struct run *r, const struct scenario *sc,
                    unsigned i, const char **why)
{
    const unsigned soff = SRC_OFFSET + i * SRC_STRIDE;
    const unsigned doff = i * DEST_STRIDE;
    const uint8_t *src = r->shadow + OFF_SRC + soff;
    const uint8_t *dst = r->shadow + OFF_DST + doff;

    for (unsigned b = 0; b < 4; ++b)
        if (dst[b] != src_byte(sc, i, b)) {
            *why = "the first four bytes";
            return 0;
        }
    for (unsigned b = 0; b < 4; ++b)
        if (dst[4 + b] != src_byte(sc, i, 8 + b)) {
            *why = "the bytes eight to eleven";
            return 0;
        }
    for (unsigned b = 0; b < 4; ++b)
        if (dst[8 + b] != src[16 + b]) {
            *why = "the word at sixteen";
            return 0;
        }
    for (unsigned b = 0; b < 4; ++b)
        if (dst[12 + b] != src[20 + b]) {
            *why = "the word at twenty";
            return 0;
        }
    /* the destination's last eight bytes are left alone */
    for (unsigned b = 16; b < DEST_STRIDE; ++b)
        if (dst[b] != sc->fill) {
            *why = "the bytes that are not written";
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
    const int ok_port = vf3_record_copy_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "record copy: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "record copy: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* and the repack is checked against the fixture itself, so a fixture that
     * is not where the guest looks cannot make both sides agree on nothing */
    for (unsigned i = 0; i < RECORDS; ++i) {
        const char *why = "";
        if (!expected(&ref, sc, i, &why)) {
            fprintf(stderr, "record copy: %s record %u: %s are wrong\n",
                    sc->name, i, why);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_record_copy_entry) {
        fprintf(stderr, "record copy: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* a plain table */
        { "plain",      0x00u, 0x10u },
        /* the destination already holds something */
        { "prefilled",  0xaau, 0x20u },
        /* every source byte is high, so the sign extension shows */
        { "high",       0x00u, 0x99u },
        /* the source's bytes wrap past 0xff */
        { "wrap",       0x5au, 0xf0u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("record_copy: %u differential cases - PASS\n", cases);
    return 0;
}
