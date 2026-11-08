/* table_probe_replay.c - the readable indexed table probe (SH-4 0x8C040378)
 * against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are the
 * generated chain (the reference), the readable port called directly, and the
 * readable port reached through the readable override.
 *
 * The body is integer-only.  r4 is an index.  It stores r4 into a transient
 * stack slot at sp-4 (and restores sp at the return, so r15 is net unchanged),
 * reads it back into r2, and returns a status in r0:
 *
 *   * r4 < 0  -> -1, T clear (r1 and r3 keep their entry values);
 *   * r4 >= 8 -> -1, T set (r1 is left as 8, r3 = r4);
 *   * else    -> val = tbl[12 * r4] (stride twelve), r1 = the table base,
 *                r3 = r4: val == 0xffffffff gives -2 with T set, any other
 *                entry gives 0 with T clear.
 *
 * The three windows mirror the captured corpus: the literal pool
 * (0x0c040000) holding the table-base pointer at 0x0c0403bc, the table
 * itself (0x0c19e000, holding 0x0c19e310), and the stack (0x0c31f000, where
 * the transient slot lands).  Every window byte is patterned first so a wrong
 * address shows up as a mismatch rather than a coincidental zero.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_table_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c040378u
#define RETURN_PC 0x0c0409deu

/* the three windows, mirroring the corpus */
#define WIN1_BASE 0x0c040000u
#define WIN1_LEN  0x1000u
#define POOL_SLOT 0x0c0403bcu            /* holds the table's base pointer */
#define WIN2_BASE 0x0c19e000u
#define WIN2_LEN  0x1000u
#define WIN3_BASE 0x0c31f000u
#define WIN3_LEN  0x1000u
#define TBL_BASE  0x0c19e310u            /* the table the pool points at */

#define MAXWIN 3u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    int32_t r4;
    uint32_t tbl[8];                    /* the table words, stride 12, indices 0..7 */
};

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static unsigned win_len(unsigned w) { return w == 0 ? WIN1_LEN : w == 1 ? WIN2_LEN : WIN3_LEN; }

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the pool: the table-base pointer at 0x0c0403bc */
    w32(r->shadow[0], POOL_SLOT - WIN1_BASE, TBL_BASE);
    /* the table: words at indices 0..7 of stride twelve */
    uint8_t *t = r->shadow[1] + (TBL_BASE - WIN2_BASE);
    for (unsigned i = 0; i < 8; ++i)
        w32(t, i * 12u, sc->tbl[i]);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = (uint32_t)sc->r4;
    s->v[15] = 0x0c31f9c4u;             /* points into window 3 */
    s->v[16] = RETURN_PC;               /* pr */
    s->v[17] = 0x60000000u;             /* sr, T clear */
    s->v[18] = 0x00024001u;             /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
    r->wins[2].base = WIN3_BASE; r->wins[2].len = WIN3_LEN; r->wins[2].data = r->shadow[2];
    r->map.wins = r->wins;
    r->map.n = MAXWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    unsigned winlen[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN };
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 37 && shown < 10; ++i)
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
    for (unsigned w = 0; w < MAXWIN; ++w)
        if (memcmp(a->shadow[w], b->shadow[w], winlen[w])) {
            for (unsigned i = 0; i < winlen[w]; ++i)
                if (a->shadow[w][i] != b->shadow[w][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n", what, w, i,
                            a->shadow[w][i], b->shadow[w][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_table_probe_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "table_probe: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "table_probe: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself, independent of the port */
    const int32_t r4i = sc->r4;
    const uint32_t r15 = 0x0c31f9c4u;
    uint8_t *t = ref.shadow[1] + (TBL_BASE - WIN2_BASE);

    /* the transient stack slot at sp-4 holds the entry r4, and r15 is flat */
    if (r32(ref.shadow[2], r15 - 4u - WIN3_BASE) != (uint32_t)r4i) {
        fprintf(stderr, "table_probe: %s: stack slot does not hold r4\n", sc->name);
        return 0;
    }
    if (ref.state.v[15] != r15 || ref.state.v[2] != (uint32_t)r4i) {
        fprintf(stderr, "table_probe: %s: r15 or r2 drifted\n", sc->name);
        return 0;
    }

    if (r4i < 0) {
        /* below range: -1, T clear, r1/r3 preserved */
        if (ref.state.v[0] != 0xffffffffu || (ref.state.v[17] & 1u) != 0u ||
            ref.state.v[1] != 0x76543211u || ref.state.v[3] != 0x76543213u) {
            fprintf(stderr, "table_probe: %s: below range r0 %08x r1 %08x "
                    "r3 %08x T %u\n", sc->name, ref.state.v[0], ref.state.v[1],
                    ref.state.v[3], ref.state.v[17] & 1u);
            return 0;
        }
    } else if (r4i >= 8) {
        /* above range: -1, T set, r1 = 8, r3 = r4 */
        if (ref.state.v[0] != 0xffffffffu || (ref.state.v[17] & 1u) != 1u ||
            ref.state.v[1] != 8u || ref.state.v[3] != (uint32_t)r4i) {
            fprintf(stderr, "table_probe: %s: above range r0 %08x r1 %08x "
                    "r3 %08x T %u\n", sc->name, ref.state.v[0], ref.state.v[1],
                    ref.state.v[3], ref.state.v[17] & 1u);
            return 0;
        }
    } else {
        /* in range: r1 = table base, r3 = r4, answer from tbl[12*r4] */
        unsigned idx = (unsigned)r4i;
        uint32_t val = sc->tbl[idx];
        uint32_t want = (val == 0xffffffffu) ? 0xfffffffeu : 0u;
        unsigned T = (val == 0xffffffffu) ? 1u : 0u;
        (void)t;
        if (ref.state.v[1] != TBL_BASE || ref.state.v[3] != (uint32_t)r4i ||
            ref.state.v[0] != want || (ref.state.v[17] & 1u) != T) {
            fprintf(stderr, "table_probe: %s: in-range r0 %08x r1 %08x r3 %08x "
                    "T %u, want %08x %08x %08x %u\n", sc->name, ref.state.v[0],
                    ref.state.v[1], ref.state.v[3], ref.state.v[17] & 1u,
                    want, TBL_BASE, (uint32_t)r4i, T);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_table_probe_entry) {
        fprintf(stderr, "table_probe: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "index 3, -1 entry",
          .r4 = 3, .tbl = { 0, 0, 0, 0xffffffffu, 0, 0, 0, 0 } },
        { .name = "index 4, -1 entry",
          .r4 = 4, .tbl = { 0, 0, 0, 0, 0xffffffffu, 0, 0, 0 } },
        { .name = "index 5, -1 entry",
          .r4 = 5, .tbl = { 0, 0, 0, 0, 0, 0xffffffffu, 0, 0 } },
        { .name = "index 0, live entry",
          .r4 = 0, .tbl = { 0x7f800001u, 0, 0, 0, 0, 0, 0, 0 } },
        { .name = "index 7, live entry",
          .r4 = 7, .tbl = { 0, 0, 0, 0, 0, 0, 0, 0x1234abcd } },
        { .name = "index 1, live entry",
          .r4 = 1, .tbl = { 0, 0xdeadbeefu, 0, 0, 0, 0, 0, 0 } },
        { .name = "index -3, below range",
          .r4 = -3, .tbl = { 0, 0, 0, 0xffffffffu, 0, 0, 0, 0 } },
        { .name = "index 8, above range",
          .r4 = 8, .tbl = { 0, 0, 0, 0, 0xffffffffu, 0, 0, 0 } },
        { .name = "index -1, below range",
          .r4 = -1, .tbl = { 0, 0, 0, 0, 0, 0xffffffffu, 0, 0 } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("table_probe: %u differential cases - PASS\n", cases);
    return 0;
}
