/* counter_select_replay.c - the readable four-threshold counter selection
 * (SH-4 0x8C0C10A2) against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are the
 * generated chain (the reference), the readable port called directly, and the
 * readable port reached through the readable override.
 *
 * The body is integer-only.  r4 is a mask.  Two running selection counters
 * (r6 even from 0, r5 odd from 4) choose, for each of four pool masks, the
 * counter to hand out and advance it (tests 1..3 advance, test 4 does not).
 * The handed-out values become @r7 (test 1), two locals (tests 2 and 3) and
 * @r4 (test 4) and are written as halfwords at +0x26 into base, base+0x2c,
 * base+0x58 and base+hw_ce.  r13/r14 are restored, r15 is net flat, r0 = 0x26,
 * r2 = (uint32_t)m3, r3 = base+hw_ce, and SR's T bit is (m4 & r4) == 0.
 *
 * The three windows mirror the captured corpus: the literal pool
 * (0x0c0c1000) holding the five halfword constants at 0x0c0c11ce/d0/d2/d4/d6
 * and the base pointer at 0x0c0c11e0, the target structure (0x0c29f000,
 * where the four halfword writes land), and the stack (0x0c31f000, where the
 * pushed registers and the 16-byte frame land).  Every window byte is
 * patterned first so a wrong address shows up as a mismatch rather than a
 * coincidental zero, and the outcome is checked against the fixture itself.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_counter_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0c10a2u
#define RETURN_PC 0x0c0c114eu

/* the three windows, mirroring the corpus */
#define WIN1_BASE 0x0c0c1000u   /* the literal pool */
#define WIN1_LEN  0x1000u
#define HW_CE_SLOT 0x0c0c11ceu  /* i16 offset to the 4th threshold */
#define M1_SLOT 0x0c0c11d0u
#define M2_SLOT 0x0c0c11d2u
#define M3_SLOT 0x0c0c11d4u
#define M4_SLOT 0x0c0c11d6u
#define BASE_SLOT 0x0c0c11e0u   /* u32 base pointer */
#define WIN2_BASE 0x0c29f000u   /* the target structure */
#define WIN2_LEN  0x1000u
#define WIN3_BASE 0x0c31f000u   /* the stack */
#define WIN3_LEN  0x1000u

#define MAXWIN 3u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    uint32_t mask;
    int16_t hw_ce;
    uint16_t m1, m2, m3, m4;
    uint32_t sp0;
    /* expected outcome */
    uint32_t e_r4, e_r5, e_r6, e_r7, e_t2, e_t3, e_T;
};

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static uint16_t r16(const uint8_t *p, uint32_t off)
{
    return (uint16_t)p[off] | ((uint16_t)p[off + 1] << 8);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static unsigned win_len(unsigned w)
{ return w == 0 ? WIN1_LEN : w == 1 ? WIN2_LEN : WIN3_LEN; }

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the pool: base pointer and the five signed halfwords */
    w32(r->shadow[0], BASE_SLOT - WIN1_BASE, WIN2_BASE);
    w16(r->shadow[0], HW_CE_SLOT - WIN1_BASE, (uint16_t)sc->hw_ce);
    w16(r->shadow[0], M1_SLOT  - WIN1_BASE, sc->m1);
    w16(r->shadow[0], M2_SLOT  - WIN1_BASE, sc->m2);
    w16(r->shadow[0], M3_SLOT  - WIN1_BASE, sc->m3);
    w16(r->shadow[0], M4_SLOT  - WIN1_BASE, sc->m4);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->mask;
    s->v[15] = sc->sp0;
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

static void free_run(struct run *r)
{
    for (unsigned w = 0; w < MAXWIN; ++w) free(r->shadow[w]);
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

static int check_struct(const struct run *r, const struct scenario *sc,
                        uint32_t r7, uint32_t t2, uint32_t t3, uint32_t r4out)
{
    const uint8_t *s = r->shadow[1];
    const uint32_t woff = WIN2_BASE;   /* base == WIN2_BASE in the fixture */
    if (r16(s, woff + 0x26u - WIN2_BASE)           != (uint16_t)r7 ||
        r16(s, woff + 0x2cu + 0x26u - WIN2_BASE)   != (uint16_t)t2 ||
        r16(s, woff + 0x58u + 0x26u - WIN2_BASE)   != (uint16_t)t3 ||
        r16(s, woff + (uint32_t)sc->hw_ce + 0x26u - WIN2_BASE) != (uint16_t)r4out) {
        fprintf(stderr, "counter_select: %s: struct halfwords wrong\n", sc->name);
        return 0;
    }
    return 1;
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    unsigned winlen[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN };

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_counter_select_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    int ok = ok_ref == ok_port && ok_ref == ok_hook && handled &&
             same(&ref, &port, "port") && same(&ref, &hook, "hook");
    if (!ok) {
        fprintf(stderr, "counter_select: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        for (unsigned w = 0; w < MAXWIN; ++w) free(ref.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(port.shadow[w]);
        for (unsigned w = 0; w < MAXWIN; ++w) free(hook.shadow[w]);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "counter_select: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* outcome against the fixture itself, independent of the port */
    const int32_t mask = (int32_t)sc->mask;
    uint32_t r6c = 0, r5c = 4;
    uint32_t r7, t2, t3, r4out;
    if ((sc->m1 & mask) == 0) { r7 = r5c; r5c += 1; } else { r7 = r6c; r6c += 1; }
    if ((sc->m2 & mask) == 0) { t2 = r5c; r5c += 1; } else { t2 = r6c; r6c += 1; }
    if ((sc->m3 & mask) == 0) { t3 = r5c; r5c += 1; } else { t3 = r6c; r6c += 1; }
    uint32_t eT;
    if ((sc->m4 & mask) == 0) { r4out = r5c; eT = 1; } else { r4out = r6c; eT = 0; }

    /* the pushed / frame words on the stack */
    uint32_t sp0 = sc->sp0;
    const uint8_t *st = ref.shadow[2];
    if (r32(st, sp0 - 4u - WIN3_BASE)  != 0x7654321eu ||   /* r14 */
        r32(st, sp0 - 8u - WIN3_BASE)  != 0x7654321du ||   /* r13 */
        r32(st, sp0 - 24u - WIN3_BASE) != WIN2_BASE ||     /* base */
        r32(st, sp0 - 20u - WIN3_BASE) != WIN2_BASE + 0x58u ||
        r32(st, sp0 - 16u - WIN3_BASE) != WIN2_BASE + (uint32_t)sc->hw_ce ||
        r32(st, sp0 - 12u - WIN3_BASE) != WIN2_BASE + 0x2cu) {
        fprintf(stderr, "counter_select: %s: stack frame words wrong\n", sc->name);
        return 0;
    }

    const vf3_matrix_state *s = &ref.state;
    if (s->v[4] != r4out || s->v[5] != r5c || s->v[6] != r6c ||
        s->v[7] != r7 || (s->v[17] & 1u) != eT || s->v[0] != 0x26u ||
        s->v[2] != (uint32_t)sc->m3 ||
        s->v[3] != WIN2_BASE + (uint32_t)sc->hw_ce ||
        s->v[15] != sp0 || s->v[13] != 0x7654321du || s->v[14] != 0x7654321eu) {
        fprintf(stderr, "counter_select: %s: registers wrong (r4 %08x r5 %08x "
                "r6 %08x r7 %08x r2 %08x r3 %08x r0 %08x T %u / want r4 %08x "
                "r5 %08x r6 %08x r7 %08x r2 %08x r3 %08x T %u)\n", sc->name,
                s->v[4], s->v[5], s->v[6], s->v[7], s->v[2], s->v[3], s->v[0],
                s->v[17] & 1u, r4out, r5c, r6c, r7, (uint32_t)sc->m3,
                WIN2_BASE + (uint32_t)sc->hw_ce, eT);
        return 0;
    }
    if (!check_struct(&ref, sc, r7, t2, t3, r4out))
        return 0;

    ++cases;
    free_run(&ref); free_run(&port); free_run(&hook);
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_counter_select_entry) {
        fprintf(stderr, "counter_select: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* mask bit0: m1 overlaps (even), m2 clear (odd), m3 overlaps (even),
         * m4 clear (odd).  r4out = r5 after tests = 5, T set. */
        { .name = "mix of overlaps and clears",
          .mask = 0x00000001u, .hw_ce = 0x0374, .sp0 = 0x0c31fa34u,
          .m1 = 0x0001, .m2 = 0x0000, .m3 = 0x0001, .m4 = 0x0000,
          .e_r4 = 5, .e_r5 = 5, .e_r6 = 2, .e_r7 = 0, .e_t2 = 4, .e_t3 = 1, .e_T = 1 },
        /* mask bit1: every mask is 0, so every test takes the odd counter. */
        { .name = "all clears -> all odd",
          .mask = 0x00000002u, .hw_ce = 0x0100, .sp0 = 0x0c31f9c8u,
          .m1 = 0x0000, .m2 = 0x0000, .m3 = 0x0000, .m4 = 0x0000,
          .e_r4 = 7, .e_r5 = 7, .e_r6 = 0, .e_r7 = 4, .e_t2 = 5, .e_t3 = 6, .e_T = 1 },
        /* mask all ones, every mask bit 1 -> every test takes the even counter. */
        { .name = "all overlaps -> all even",
          .mask = 0xffffffffu, .hw_ce = -16, .sp0 = 0x0c31fa40u,
          .m1 = 0x0001, .m2 = 0x0001, .m3 = 0x0001, .m4 = 0x0001,
          .e_r4 = 3, .e_r5 = 4, .e_r6 = 3, .e_r7 = 0, .e_t2 = 1, .e_t3 = 2, .e_T = 0 },
        /* mask bit0, m1 clear, m2 overlaps, m3 clear, m4 overlaps. */
        { .name = "odd, even, odd, even",
          .mask = 0x00000001u, .hw_ce = 0x0200, .sp0 = 0x0c31fa10u,
          .m1 = 0x0000, .m2 = 0x0001, .m3 = 0x0000, .m4 = 0x0001,
          .e_r4 = 5, .e_r5 = 5, .e_r6 = 2, .e_r7 = 4, .e_t2 = 0, .e_t3 = 5, .e_T = 0 },
        /* negative hw_ce (0xFFE0), base + hw_ce lands below base but inside
         * the window; mask bit0, all clear -> all odd. */
        { .name = "negative hw_ce, all odd",
          .mask = 0x00000004u, .hw_ce = 0xFFE0, .sp0 = 0x0c31f9e8u,
          .m1 = 0x0000, .m2 = 0x0000, .m3 = 0x0000, .m4 = 0x0000,
          .e_r4 = 7, .e_r5 = 7, .e_r6 = 0, .e_r7 = 4, .e_t2 = 5, .e_t3 = 6, .e_T = 1 },
        /* mask bit0 & bit1 both set; m1 = 1 overlaps, m2 = 2 overlaps, etc. */
        { .name = "two overlapping bits",
          .mask = 0x00000003u, .hw_ce = 0x0078, .sp0 = 0x0c31fa28u,
          .m1 = 0x0001, .m2 = 0x0002, .m3 = 0x0001, .m4 = 0x0002,
          .e_r4 = 1, .e_r5 = 4, .e_r6 = 3, .e_r7 = 0, .e_t2 = 1, .e_t3 = 2, .e_T = 0 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i) {
        /* the .e_* fields are computed by compare() against the fixture; the
         * table values are documentation, so (void) them. */
        (void)scenarios[i].e_r4; (void)scenarios[i].e_r5; (void)scenarios[i].e_r6;
        (void)scenarios[i].e_r7; (void)scenarios[i].e_t2; (void)scenarios[i].e_t3;
        (void)scenarios[i].e_T;
        if (!compare(&scenarios[i])) return 1;
    }

    printf("counter_select: %u differential cases - PASS\n", cases);
    return 0;
}
