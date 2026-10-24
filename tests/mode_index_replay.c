/* mode_index_replay.c - the readable mode-index switch against the retained
 * generated translation of SH-4 0x8C038990.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function turns a mode flag into an index: four flags are constants and
 * four live in the literal pool, and a flag that is none of them is left
 * alone.  The test lays the pool out and walks the flag through every case
 * and one that is not a case at all.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_mode_index_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c038990u

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the four flags that are not constants */
#define POOL_BASE 0x0c038af0u
#define POOL_LEN  0x10u
#define G_CASE4 (POOL_BASE + 0x02u)
#define G_CASE5 (POOL_BASE + 0x04u)
#define G_CASE6 (POOL_BASE + 0x06u)
#define G_CASE7 (POOL_BASE + 0x08u)

/* the four flags the pool holds.  The last one is negative as a signed
 * halfword, so the sign extension the guest does is visible. */
#define POOL_FLAG4 0x0111u
#define POOL_FLAG5 0x0222u
#define POOL_FLAG6 0x0333u
#define POOL_FLAG7 0x8444u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define SHADOW_LEN (OFF_POOL + POOL_LEN)

struct scenario {
    const char *name;
    uint32_t flag;    /* the flag the caller leaves in r4 */
    uint32_t index;   /* the index the function answers */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[1];
    vf3_ram_map map;
};

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w16(p + OFF_POOL, G_CASE4 - POOL_BASE, (uint16_t)POOL_FLAG4);
    w16(p + OFF_POOL, G_CASE5 - POOL_BASE, (uint16_t)POOL_FLAG5);
    w16(p + OFF_POOL, G_CASE6 - POOL_BASE, (uint16_t)POOL_FLAG6);
    w16(p + OFF_POOL, G_CASE7 - POOL_BASE, (uint16_t)POOL_FLAG7);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->flag;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->map.wins = r->wins;
    r->map.n = 1;
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
    const int ok_port = vf3_mode_index_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "mode index: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "mode index: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    /* the answer, checked against the fixture itself */
    if (ref.state.v[4] != sc->index) {
        fprintf(stderr, "mode index: %s: r4 %08x != %08x\n",
                sc->name, ref.state.v[4], sc->index);
        return 0;
    }
    /* and the T bit: set on a hit, cleared when no flag matched.  A hit is
     * the case where the answer is not the flag that came in. */
    const int expect_t = (sc->index != sc->flag);
    if (((ref.state.v[17] & 1u) != 0) != expect_t) {
        fprintf(stderr, "mode index: %s: the T bit is %u, expected %d\n",
                sc->name, ref.state.v[17] & 1u, expect_t);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_mode_index_entry) {
        fprintf(stderr, "mode index: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the four constant flags */
        { "eight",   8u,   0u },
        { "sixteen", 16u,  1u },
        { "thirty two", 32u, 2u },
        { "sixty four", 64u, 3u },
        /* and the four the pool holds */
        { "pool four",   POOL_FLAG4, 4u },
        { "pool five",   POOL_FLAG5, 5u },
        { "pool six",    POOL_FLAG6, 6u },
        { "pool seven",  (uint32_t)(int32_t)(int16_t)POOL_FLAG7, 7u },
        /* and a flag that is none of them */
        { "unknown", 0x1234u, 0x1234u },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("mode_index: %u differential cases - PASS\n", cases);
    return 0;
}
