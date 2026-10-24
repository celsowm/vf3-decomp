/* table_grow_replay.c - the readable table grower against the retained
 * generated translation of SH-4 0x8C044C7C.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function adds N entries to two arrays behind one header.  The test lays
 * the header out the way the guest expects - the first array's slot and its
 * stride twelve bytes further on, the second array's count and its pointer -
 * and seeds the literal pool with the three offsets the guest reads.
 *
 * The scenarios cover a count of zero (the loop does not run), one entry,
 * several entries and a negative count (the loop does not run either, but
 * the second array's count and pointer still move).
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_table_grow_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c044c7cu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the three offsets and the global */
#define POOL_BASE  0x0c044d10u
#define POOL_LEN   0x40u
#define G_SLOT0    (POOL_BASE + 0x06u)   /* the first array's slot */
#define G_FILL     (POOL_BASE + 0x08u)   /* the fill value */
#define G_SLOT1    (POOL_BASE + 0x0au)   /* the second array's slot */
#define G_HEADER   (POOL_BASE + 0x34u)   /* the header's address */

/* the header and the first array.  The global holds the address of a word
 * that holds the base, and the slots are measured from the base */
#define PTR_BASE   0x0c400000u
#define PTR_LEN    0x10u
#define BASE       0x0c410000u
#define BASE_LEN   0x40u
#define ARR_BASE   0x0c500000u
#define ARR_LEN    0x100u

/* the base's layout, given the pool's offsets */
#define SLOT0      0x10u
#define SLOT1      0x20u
#define STRIDE     2u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_PTR  (OFF_POOL + POOL_LEN)
#define OFF_BASE (OFF_PTR + PTR_LEN)
#define OFF_ARR  (OFF_BASE + BASE_LEN)
#define SHADOW_LEN (OFF_ARR + ARR_LEN)

struct scenario {
    const char *name;
    uint32_t count;        /* r4 */
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

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w16(p + OFF_POOL, G_SLOT0 - POOL_BASE, (uint16_t)SLOT0);
    w16(p + OFF_POOL, G_FILL - POOL_BASE, 0x1234u);
    w16(p + OFF_POOL, G_SLOT1 - POOL_BASE, (uint16_t)SLOT1);
    w32(p + OFF_POOL, G_HEADER - POOL_BASE, PTR_BASE);

    /* the word the global points at holds the base */
    w32(p + OFF_PTR, 0, BASE);

    /* the base: the first array's slot and its stride, then the second
     * array's count and its pointer */
    w32(p + OFF_BASE, SLOT0, ARR_BASE);
    w32(p + OFF_BASE, SLOT0 + 12u, STRIDE);
    w32(p + OFF_BASE, SLOT1, 5u);
    w32(p + OFF_BASE, SLOT1 + 4u, ARR_BASE + 0x80u);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->count;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_PTR;  r->wins[1].base = PTR_BASE;  r->wins[1].len = PTR_LEN;
    r->wins[2].data = p + OFF_BASE; r->wins[2].base = BASE;      r->wins[2].len = BASE_LEN;
    r->wins[3].data = p + OFF_ARR;  r->wins[3].base = ARR_BASE;  r->wins[3].len = ARR_LEN;
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

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_table_grow_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "table grow: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_table_grow_entry) {
        fprintf(stderr, "table grow: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        { "zero",     0u },
        { "one",      1u },
        { "three",    3u },
        { "eight",    8u },
        { "negative", 0xffffffffu },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("table_grow: %u differential cases - PASS\n", cases);
    return 0;
}
