/* status_flags_replay.c - the readable status flags against the retained
 * generated translation of SH-4 0x8C0961F4.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function reads eight fields of a record and puts one bit in the answer
 * for every field that has a bit in common with the mask.  The scenarios
 * cover the empty record, the full one, a mask that only counts the low bits
 * (so the fields' high bits do not count) and a mixture - and the last bit
 * comes out of the literal pool, which the test seeds.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_status_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c0961f4u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the record and the pool */
#define REC_BASE  0x0c300000u
#define REC_LEN   0x100u
#define POOL_BASE 0x0c096300u
#define POOL_LEN  0x20u

/* the last bit's mask: the pool slot the guest reads */
#define G_LAST_BIT (POOL_BASE + 0x0au)

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_REC  (OFF_POOL + POOL_LEN)
#define SHADOW_LEN (OFF_REC + REC_LEN)

struct scenario {
    const char *name;
    uint32_t mask;          /* r4 */
    uint32_t word[10];      /* the record's words: 0, 4, 8, 12, (16), 20, 24, 28, 32, (36) */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[2];
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

    /* the pool: the mask the last bit takes */
    w16(p + OFF_POOL, G_LAST_BIT - POOL_BASE, 0x0080u);

    /* the record */
    for (unsigned i = 0; i < 10; ++i)
        w32(p + OFF_REC, i * 4u, sc->word[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->mask;
    s->v[5] = REC_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_REC;  r->wins[1].base = REC_BASE;  r->wins[1].len = REC_LEN;
    r->map.wins = r->wins;
    r->map.n = 2;
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
    const int ok_port = vf3_status_flags_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "status flags: %s differs (ok %d/%d/%d)\n",
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
    if (!reg || reg->fn != vf3_status_flags_entry) {
        fprintf(stderr, "status flags: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* nothing is set: no bit goes in */
        { "empty", 0xffffffffu,
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
        /* everything is set: every bit goes in, the last one from the pool */
        { "full", 0xffffffffu,
          { 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0,
            0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0 } },
        /* the mask counts the low bits only, so the fields do not count */
        { "masked out", 0x0000000fu,
          { 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0,
            0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0x0000ff00u, 0 } },
        /* a mixture: the low bit counts, the next one does not */
        { "mixed", 0x0000000fu,
          { 0x00000001u, 0x00000100u, 0x00000001u, 0x00000000u, 0,
            0x00000001u, 0x00000000u, 0x00000100u, 0x00000001u, 0 } },
        /* one field only, in the high bit */
        { "high bit", 0x80000000u,
          { 0, 0, 0, 0, 0, 0, 0, 0, 0x80000000u, 0 } },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("status_flags: %u differential cases - PASS\n", cases);
    return 0;
}
