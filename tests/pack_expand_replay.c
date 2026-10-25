/* pack_expand_replay.c - the readable packed-attribute expansion (SH-4
 * 0x8C09D5AE) against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the two leaves are the
 * *generated* translation and the readable port, and they are compared against
 * each other.
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
 * **against the fixture itself**: the eight registers the guest leaves, the
 * T bit, the record's two bytes, the destination's three words, the sixteen
 * groups and the two words the guest pushes on its stack.  Those expectations
 * come from a second implementation in the test, written from the disassembly
 * and not from the port, and it reads the fixture's own bytes - a differential
 * alone is not enough, because a fixture that is not where the guest looks
 * makes both sides read the same wrong bytes and agree on them.
 *
 * The fixture uses the game's own addresses - the pool at 0x0c09d6ce,
 * 0x0c09d6d0 and 0x0c09d6dc, the record, the table and the stack at the
 * places the oracle recorded - but with values the corpus does not use, so a
 * port that hard-coded the capture would fail here.  In particular the
 * **record's two offsets come out of the pool**, so the scenarios vary them:
 * the corpus always carries 8127 and 7424, and a port that read them from
 * anywhere else would still replay the corpus.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pack_expand_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09d5aeu

#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE   0x0c09d000u   /* the literal pool */
#define POOL_LEN    0x1000u
#define TABLE_BASE  0x0c29b000u   /* the table */
#define TABLE_LEN   0x8000u       /* the table is big: the entry is 12 bytes
                                     * and the corpus names entries as high
                                     * as 2390 */
#define SRC_BASE    0x0c691000u   /* the packed bytes */
#define SRC_LEN     0x1000u
#define DEST_BASE   0x0c226000u   /* the destination block */
#define DEST_LEN    0x1000u
#define REC_BASE    0x0c1f0000u   /* the record: the window reaches below it,
                                     * because the pool's offsets can be
                                     * negative */
#define REC_LEN     0x12000u
#define STACK_BASE  0x0c31f000u   /* the guest's stack */
#define STACK_LEN   0x1000u
#define NWIN 6

#define OFF_POOL   0u
#define OFF_TABLE  (OFF_POOL + POOL_LEN)
#define OFF_SRC    (OFF_TABLE + TABLE_LEN)
#define OFF_DEST   (OFF_SRC + SRC_LEN)
#define OFF_REC    (OFF_DEST + DEST_LEN)
#define OFF_STACK  (OFF_REC + REC_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

/* ---- where things live ---- */
#define TABLE_PTR  (POOL_BASE + 0x800u)   /* holds the table's base */
#define TABLE_ROOT (TABLE_BASE + 0x400u)  /* the table's base */
#define FIRST      (SRC_BASE + 0x500u)    /* the packed bytes */
#define SECOND     (TABLE_BASE + 0x800u)
#define THIRD      (TABLE_BASE + 0x900u)
#define DEST       (DEST_BASE + 0x864u)
#define RECORD     (REC_BASE + 0x9100u)
#define SP         (STACK_BASE + 0x9f8u)

/* ---- the pool's entries ---- */
#define P_TABLE    (POOL_BASE + 0x6dcu)   /* the address of the table's pointer */
#define P_PACKED   (POOL_BASE + 0x6ceu)   /* the record's offset of the byte */
#define P_DEST     (POOL_BASE + 0x6d0u)   /* the record's offset of the dest */

/* ---- the record's fields ---- */
#define FIELD_INDEX 60u

/* ---- the expansion ---- */
#define GROUP_COUNT 16u
#define GROUP_SIZE  4u
#define ENTRY_SIZE  12u

/* the windows, for the model's own reads */
static const struct {
    uint32_t base;
    uint32_t len;
    uint32_t off;
} windows[NWIN] = {
    { POOL_BASE,  POOL_LEN,  OFF_POOL },
    { TABLE_BASE, TABLE_LEN, OFF_TABLE },
    { SRC_BASE,   SRC_LEN,   OFF_SRC },
    { DEST_BASE,  DEST_LEN,  OFF_DEST },
    { REC_BASE,   REC_LEN,   OFF_REC },
    { STACK_BASE, STACK_LEN, OFF_STACK },
};

struct scenario {
    const char *name;
    uint16_t index;        /* the record's halfword at +60: the entry, from one */
    uint16_t packed_off;   /* the pool's offset of the record's packed byte */
    uint16_t dest_off;     /* the pool's offset of the record's destination */
    uint16_t head;         /* the halfword in front of the packed bytes */
    uint8_t  packed_byte;  /* the record's own packed byte */
    uint8_t  bytes[GROUP_COUNT];   /* the sixteen packed bytes */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
};

/* ---- the model's own reads of the fixture ---- */
static const uint8_t *at(const uint8_t *shadow, uint32_t addr, uint32_t size)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= windows[i].base && addr + size <= windows[i].base + windows[i].len)
            return shadow + windows[i].off + (addr - windows[i].base);
    return NULL;
}

static uint32_t m_u32(const uint8_t *shadow, uint32_t addr)
{
    const uint8_t *p = at(shadow, addr, 4);
    return p ? (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                 ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24) : 0u;
}

static uint32_t m_u16(const uint8_t *shadow, uint32_t addr)
{
    const uint8_t *p = at(shadow, addr, 2);
    return p ? (uint32_t)p[0] | ((uint32_t)p[1] << 8) : 0u;
}

static uint32_t m_u8(const uint8_t *shadow, uint32_t addr)
{
    const uint8_t *p = at(shadow, addr, 1);
    return p ? p[0] : 0u;
}

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

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool: the addresses the guest reads */
    w32(p + OFF_POOL, P_TABLE - POOL_BASE, TABLE_PTR);
    w16(p + OFF_POOL, P_PACKED - POOL_BASE, sc->packed_off);
    w16(p + OFF_POOL, P_DEST - POOL_BASE, sc->dest_off);
    w32(p + OFF_POOL, TABLE_PTR - POOL_BASE, TABLE_ROOT);

    /* the table's entry: three offsets from the table's base */
    {
        const uint32_t entry = TABLE_ROOT + ENTRY_SIZE * (sc->index - 1u);
        w32(p + OFF_TABLE, entry - TABLE_BASE, FIRST - TABLE_ROOT);
        w32(p + OFF_TABLE, entry + 4u - TABLE_BASE, SECOND - TABLE_ROOT);
        w32(p + OFF_TABLE, entry + 8u - TABLE_BASE, THIRD - TABLE_ROOT);
    }

    /* the source: the head halfword and the sixteen packed bytes */
    w16(p + OFF_SRC, FIRST - SRC_BASE, sc->head);
    for (unsigned i = 0; i < GROUP_COUNT; ++i)
        p[OFF_SRC + FIRST - SRC_BASE + 2u + i] = sc->bytes[i];

    /* the record: its index, its packed byte and the garbage around them.
     * The window is filled with garbage first, so a port that writes the
     * wrong byte, or the wrong width, is visible.  The pool's offsets are
     * sign extended halfwords, so they can be negative - and then the
     * record's fields sit *below* it. */
    memset(p + OFF_REC, 0xa5, REC_LEN);
    w16(p + OFF_REC, RECORD - REC_BASE + FIELD_INDEX, sc->index);
    {
        const ptrdiff_t at_packed = (ptrdiff_t)OFF_REC +
            (ptrdiff_t)(RECORD - REC_BASE) + (int32_t)(int16_t)sc->packed_off;
        const ptrdiff_t at_dest = (ptrdiff_t)OFF_REC +
            (ptrdiff_t)(RECORD - REC_BASE) + (int32_t)(int16_t)sc->dest_off;
        p[at_packed] = sc->packed_byte;
        w32(p + at_dest, 0, DEST);
    }

    /* the stack: garbage, so the two words the guest pushes are visible. */
    memset(p + OFF_STACK, 0x5a, STACK_LEN);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = RECORD;               /* the record */
    s->v[15] = SP;                  /* the stack */
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;         /* sr: the corpus' own value, T bit set */
    /* The dispatcher refuses to run anything when the FPU is unsupported
     * (FPSCR.RM is 2 or 3, or the precision bit is set), and the corpus
     * carries 0x240001 / 0x40001.  The function uses no FP instruction, but
     * the gate stands between the caller and the body. */
    s->v[18] = 0x00024001u;         /* fpscr: the corpus' own value */
    s->budget = 1000000u;

    r->wins[0].base = POOL_BASE;   r->wins[0].len = POOL_LEN;
    r->wins[1].base = TABLE_BASE;  r->wins[1].len = TABLE_LEN;
    r->wins[2].base = SRC_BASE;    r->wins[2].len = SRC_LEN;
    r->wins[3].base = DEST_BASE;   r->wins[3].len = DEST_LEN;
    r->wins[4].base = REC_BASE;    r->wins[4].len = REC_LEN;
    r->wins[5].base = STACK_BASE;  r->wins[5].len = STACK_LEN;
    r->wins[0].data = p + OFF_POOL;
    r->wins[1].data = p + OFF_TABLE;
    r->wins[2].data = p + OFF_SRC;
    r->wins[3].data = p + OFF_DEST;
    r->wins[4].data = p + OFF_REC;
    r->wins[5].data = p + OFF_STACK;
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
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
 * The function reads the table out of the pool, takes the entry the record
 * names, expands the sixteen packed bytes into sixteen groups of four two-bit
 * fields and writes them into the destination the record carries.  It also
 * moves the record's own packed byte up by 29 and puts bit 14 of the source's
 * head into the record's packed byte. */
struct outcome {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    int t;                       /* the T bit the guest leaves */
    uint8_t rec_byte;            /* the record's packed byte afterwards */
    uint8_t rec_byte_up;         /* the record's byte 29 further up */
    uint32_t dest0, dest4, dest8;
    uint8_t groups[GROUP_COUNT * GROUP_SIZE];
    uint32_t stack_low, stack_high;   /* the two words the guest pushed */
};

static void model(const uint8_t *shadow, struct outcome *out)
{
    /* the pool: the table's address, and the record's two offsets */
    const uint32_t base = m_u32(shadow, m_u32(shadow, P_TABLE));
    const uint32_t index = m_u16(shadow, RECORD + FIELD_INDEX) - 1u;
    const uint32_t entry = base + ENTRY_SIZE * index;
    const uint32_t first = base + m_u32(shadow, entry);
    const uint32_t second = base + m_u32(shadow, entry + 4u);
    const uint32_t third = base + m_u32(shadow, entry + 8u);
    const int32_t packed_at = (int32_t)(int16_t)m_u16(shadow, P_PACKED);
    const int32_t dest_at = (int32_t)(int16_t)m_u16(shadow, P_DEST);
    const uint32_t head = m_u16(shadow, first);
    const uint32_t dest = m_u32(shadow, RECORD + (uint32_t)dest_at);

    out->r0 = 0u;
    out->r1 = GROUP_COUNT;
    out->r2 = first + 2u + GROUP_COUNT;
    out->r3 = dest + 12u + GROUP_COUNT * GROUP_SIZE - GROUP_SIZE;
    out->r4 = dest;
    out->r5 = GROUP_COUNT * GROUP_SIZE;
    out->r6 = 0u;
    out->r7 = GROUP_COUNT;
    out->t = 1;                       /* the counter reached 16 */

    out->rec_byte = (uint8_t)((head >> 12) & 4u);
    out->rec_byte_up = (uint8_t)m_u8(shadow, RECORD + (uint32_t)packed_at);

    out->dest0 = first + 17u;
    out->dest4 = second;
    out->dest8 = third;

    for (unsigned k = 0; k < GROUP_COUNT; ++k) {
        const uint32_t v = m_u8(shadow, first + 2u + k);
        out->groups[k * GROUP_SIZE + 0] = (uint8_t)((v >> 6) & 3u);
        out->groups[k * GROUP_SIZE + 1] = (uint8_t)((v >> 4) & 3u);
        out->groups[k * GROUP_SIZE + 2] = (uint8_t)((v >> 2) & 3u);
        out->groups[k * GROUP_SIZE + 3] = (uint8_t)(v & 3u);
    }
    out->r0 = out->groups[GROUP_COUNT * GROUP_SIZE - 1];
    out->r6 = (uint8_t)m_u8(shadow, first + 2u + GROUP_COUNT - 1u);

    out->stack_low = second;
    out->stack_high = third;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    /* the shadow is large (the record's window reaches below the record), so
     * the three runs live in static storage rather than on the stack */
    static struct run ref, port, hook;
    struct outcome want;

    setup(&ref, sc);
    /* the expectation, computed from the fixture before the port touches it */
    model(ref.shadow, &want);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_pack_expand_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "pack_expand: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "pack_expand: %s reads outside the windows "
                "(oob %u/%u/%u)\n", sc->name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        const uint8_t *rec = ref.shadow + OFF_REC + (RECORD - REC_BASE);
        const uint8_t *dst = ref.shadow + OFF_DEST + (DEST - DEST_BASE);
        const uint8_t *stk = ref.shadow + OFF_STACK + (SP - STACK_BASE);
        const uint32_t packed_off = (uint32_t)(int32_t)(int16_t)
            m_u16(ref.shadow, P_PACKED);
        const int32_t packed_at = (int32_t)(int16_t)packed_off;

        if (ref.state.v[0] != want.r0 || ref.state.v[1] != want.r1 ||
            ref.state.v[2] != want.r2 || ref.state.v[3] != want.r3 ||
            ref.state.v[4] != want.r4 || ref.state.v[5] != want.r5 ||
            ref.state.v[6] != want.r6 || ref.state.v[7] != want.r7) {
            fprintf(stderr, "pack_expand: %s: the registers are %08x %08x %08x "
                    "%08x %08x %08x %08x %08x, expected %08x %08x %08x %08x "
                    "%08x %08x %08x %08x\n", sc->name,
                    ref.state.v[0], ref.state.v[1], ref.state.v[2], ref.state.v[3],
                    ref.state.v[4], ref.state.v[5], ref.state.v[6], ref.state.v[7],
                    want.r0, want.r1, want.r2, want.r3,
                    want.r4, want.r5, want.r6, want.r7);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != want.t) {
            fprintf(stderr, "pack_expand: %s: the T bit is %u, expected %d\n",
                    sc->name, ref.state.v[17] & 1u, want.t);
            return 0;
        }
        if (ref.state.v[15] != SP) {
            fprintf(stderr, "pack_expand: %s: the stack pointer is %08x, "
                    "expected %08x\n", sc->name, ref.state.v[15], SP);
            return 0;
        }
        if (rec[packed_at] != want.rec_byte) {
            fprintf(stderr, "pack_expand: %s: the record's byte is %02x, "
                    "expected %02x\n", sc->name, rec[packed_at],
                    want.rec_byte);
            return 0;
        }
        if (rec[packed_at + 29] != want.rec_byte_up) {
            fprintf(stderr, "pack_expand: %s: the record's byte 29 up is %02x, "
                    "expected %02x\n", sc->name, rec[packed_at + 29],
                    want.rec_byte_up);
            return 0;
        }
        if (r32(dst, 0) != want.dest0 || r32(dst, 4) != want.dest4 ||
            r32(dst, 8) != want.dest8) {
            fprintf(stderr, "pack_expand: %s: the destination's words are "
                    "%08x %08x %08x, expected %08x %08x %08x\n", sc->name,
                    r32(dst, 0), r32(dst, 4), r32(dst, 8),
                    want.dest0, want.dest4, want.dest8);
            return 0;
        }
        for (unsigned i = 0; i < GROUP_COUNT * GROUP_SIZE; ++i)
            if (dst[12 + i] != want.groups[i]) {
                fprintf(stderr, "pack_expand: %s: the group byte %u is %02x, "
                        "expected %02x\n", sc->name, i, dst[12 + i],
                        want.groups[i]);
                return 0;
            }
        /* the guest pushes the two words *below* the stack pointer */
        if (r32(stk - 8, 0) != want.stack_low || r32(stk - 4, 0) != want.stack_high) {
            fprintf(stderr, "pack_expand: %s: the stack holds %08x %08x, "
                    "expected %08x %08x\n", sc->name, r32(stk - 8, 0),
                    r32(stk - 4, 0), want.stack_low, want.stack_high);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_pack_expand_entry) {
        fprintf(stderr, "pack_expand: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "the first entry, the corpus' offsets",
          .index = 1, .packed_off = 8127, .dest_off = 7424,
          .head = 0x003cu, .packed_byte = 0x00u,
          .bytes = { 0x31u, 0xd7u, 0x5du, 0x75u, 0x55u, 0x40u, 0x10u, 0x53u,
                     0x13u, 0x00u, 0xc4u, 0xc0u, 0x11u, 0x41u, 0x14u, 0x10u } },

        { .name = "a middle entry, other offsets",
          .index = 4, .packed_off = 0x1f00u, .dest_off = 0x1c00u,
          .head = 0x4000u, .packed_byte = 0xa7u,
          .bytes = { 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u,
                     0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u } },

        { .name = "a high entry, a head with bit 14 set",
          .index = 1050, .packed_off = 8127, .dest_off = 7424,
          .head = 0x5000u, .packed_byte = 0x5au,
          .bytes = { 0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u,
                     0x08u, 0x09u, 0x0au, 0x0bu, 0x0cu, 0x0du, 0x0eu, 0x0fu } },

        { .name = "the last entry, every field set",
          .index = 2400, .packed_off = 0x0f00u, .dest_off = 0x1000u,
          .head = 0x7fffu, .packed_byte = 0xffu,
          .bytes = { 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
                     0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu } },

        { .name = "a head with only bit 14 set",
          .index = 7, .packed_off = 0x2000u, .dest_off = 0x1800u,
          .head = 0x4000u, .packed_byte = 0x01u,
          .bytes = { 0x01u, 0x02u, 0x04u, 0x08u, 0x10u, 0x20u, 0x40u, 0x80u,
                     0x03u, 0x0cu, 0x30u, 0xc0u, 0x00u, 0x00u, 0x00u, 0x00u } },

        /* the pool's offsets are sign extended halfwords: these two are
         * negative, and the record's fields then sit *below* it */
        { .name = "negative offsets out of the pool",
          .index = 2, .packed_off = 0x8000u, .dest_off = 0x9000u,
          .head = 0x4004u, .packed_byte = 0x3cu,
          .bytes = { 0x81u, 0x42u, 0x24u, 0x18u, 0x81u, 0x42u, 0x24u, 0x18u,
                     0x81u, 0x42u, 0x24u, 0x18u, 0x81u, 0x42u, 0x24u, 0x18u } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("pack_expand: %u differential cases - PASS\n", cases);
    return 0;
}
