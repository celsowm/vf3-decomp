/* byte_color_replay.c - the readable two-byte color scale (SH-4 0x8C0563AC)
 * against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are the
 * generated chain (the reference), the readable port called directly, and the
 * readable port reached through the readable override.
 *
 * The body is branch-free FP.  It reads three floats through a pool pointer
 * (ptrA at 0x0c056504), scales them by the constant at 0x0c056508, unpacks
 * two packed bytes at [r4+4]/[r4+6] into three byte channels, converts them
 * to floats, scales those by the first three, and writes three floats down a
 * run of the output base read from 0x0c056510 (fr0@out, fr1@out-w, fr2@out-2w,
 * where w = FPSCR.PR ? 8 : 4).  r0 = 0x0c056508, r1 = out-2w, r2 = hi's low
 * byte, r4 += 8, r5 = lo's high byte, r6 = hi's low byte, SR is untouched,
 * FPUL = hi's low byte.
 *
 * The four windows mirror the captured corpus: the literal pool (0x0c056000)
 * holding ptrA/scale/out, the source floats (0x0c16b000), the
 * output/bytes/scratch (0x0c19d000), and the stack (0x0c31f000).  Every
 * window byte is patterned first so a wrong address shows up as a mismatch
 * rather than a coincidental zero.  The corpus runs the body in single
 * precision only (fpscr 0x00040001, PR clear), so the cases here stay in
 * single precision (w = 4); the port still carries the (fpscr)&0x100000
 * width ternary for fidelity, but the double-PR path is not exercised by any
 * corpus and is not tested.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_byte_color_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0563acu
#define RETURN_PC 0x0c0563fau

/* windows */
#define WIN1_BASE 0x0c056000u   /* the literal pool */
#define WIN1_LEN  0x1000u
#define PTRA_SLOT 0x0c056504u
#define SCALE_SLOT 0x0c056508u
#define OUT_SLOT  0x0c056510u
#define WIN2_BASE 0x0c16b000u   /* the source floats */
#define WIN2_LEN  0x1000u
#define WIN3_BASE 0x0c19d000u   /* output, bytes, scratch */
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
    unsigned w;                    /* FPSCR.PR ? 8 : 4 */
    uint32_t ptr_off, out_off;     /* offsets into WIN2 / WIN3 */
    uint32_t r4_off, r1_off;       /* r4_in, r1_in values (absolute) */
    uint32_t src[3];               /* source float bits (single) */
    uint32_t scale;                /* scale float bits (single) */
    uint16_t lo, hi;               /* the packed bytes */
};

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

static void w_f64(uint8_t *p, uint32_t off, uint32_t hib, uint32_t lob)
{
    w32(p, off, lob);
    w32(p, off + 4, hib);
}

static unsigned win_len(unsigned wg)
{ return wg == 0 ? WIN1_LEN : wg == 1 ? WIN2_LEN : WIN3_LEN; }

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned wg = 0; wg < MAXWIN; ++wg) {
        r->shadow[wg] = malloc(win_len(wg));
        for (unsigned i = 0; i < win_len(wg); i += 4)
            w32(r->shadow[wg], i, 0x22222222u + (i & 0xff));
    }

    const uint32_t ptrA = WIN2_BASE + sc->ptr_off;
    const uint32_t out = WIN3_BASE + sc->out_off;

    /* the pool: ptrA, scale, out */
    w32(r->shadow[0], PTRA_SLOT - WIN1_BASE, ptrA);
    w32(r->shadow[0], OUT_SLOT - WIN1_BASE, out);
    if (sc->w == 4)
        w32(r->shadow[0], SCALE_SLOT - WIN1_BASE, sc->scale);
    else {
        /* double: sign/exponent in the high word, mantissa in the low word */
        uint32_t dhi = (sc->scale & 0x40000000u) ? 0x3ff00000u : 0x3fe00000u;
        uint32_t dlo = sc->scale;
        w_f64(r->shadow[0], SCALE_SLOT - WIN1_BASE, dhi, dlo);
    }

    /* the source floats at ptrA, ptrA+w, ptrA+2w */
    for (unsigned i = 0; i < 3; ++i) {
        if (sc->w == 4)
            w32(r->shadow[1], sc->ptr_off + i * 4u, sc->src[i]);
        else
            w_f64(r->shadow[1], sc->ptr_off + i * 8u, 0x3ff00000u, sc->src[i]);
    }

    /* the packed bytes at [r4+4] / [r4+6] (into window 3) */
    uint32_t r4 = sc->r4_off;
    w16(r->shadow[2], r4 + 4u - WIN3_BASE, sc->lo);
    w16(r->shadow[2], r4 + 6u - WIN3_BASE, sc->hi);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[1] = sc->r1_off;
    s->v[4] = r4;
    s->v[15] = WIN3_BASE + 0x900;    /* sp, unused but in window 3 */
    s->v[16] = RETURN_PC;            /* pr */
    s->v[17] = 0x60000000u;          /* sr, T clear */
    s->v[18] = 0x00040001u | (sc->w == 8 ? 0x100000u : 0u); /* fpscr */
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
    for (unsigned wg = 0; wg < MAXWIN; ++wg) free(r->shadow[wg]);
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    unsigned winlen[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN };
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        for (unsigned i = 0; i < 54; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                break;
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
    for (unsigned wg = 0; wg < MAXWIN; ++wg)
        if (memcmp(a->shadow[wg], b->shadow[wg], winlen[wg])) {
            for (unsigned i = 0; i < winlen[wg]; ++i)
                if (a->shadow[wg][i] != b->shadow[wg][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n", what, wg, i,
                            a->shadow[wg][i], b->shadow[wg][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned ncases;

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_byte_color_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    int ok = ok_ref == ok_port && ok_ref == ok_hook && handled &&
             same(&ref, &port, "port") && same(&ref, &hook, "hook");
    if (!ok) {
        fprintf(stderr, "byte_color: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        free_run(&ref); free_run(&port); free_run(&hook);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "byte_color: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        free_run(&ref); free_run(&port); free_run(&hook);
        return 0;
    }

    /* non-FP outcomes against the fixture */
    const uint32_t out = WIN3_BASE + sc->out_off;
    const uint32_t wg = sc->w;
    const uint32_t c_r2 = sc->lo & 0xffu;
    const uint32_t c_r5 = (sc->lo >> 8u) & 0xffu;
    const uint32_t c_r6 = sc->hi & 0xffu;
    const vf3_matrix_state *s = &ref.state;
    if (s->v[0] != 0x0c056508u || s->v[1] != out - 2u * wg ||
        s->v[2] != c_r2 || s->v[4] != sc->r4_off + 8u ||
        s->v[5] != c_r5 || s->v[6] != c_r6 || s->v[53] != c_r6 ||
        (s->v[17] & 1u) != 0u) {
        fprintf(stderr, "byte_color: %s: int registers wrong (r0 %08x r1 %08x "
                "r2 %08x r4 %08x r5 %08x r6 %08x fpul %08x T %u, want r1 %08x "
                "r4 %08x)\n", sc->name, s->v[0], s->v[1], s->v[2], s->v[4],
                s->v[5], s->v[6], s->v[53], s->v[17] & 1u, out - 2u * wg,
                sc->r4_off + 8u);
        free_run(&ref); free_run(&port); free_run(&hook);
        return 0;
    }

    /* the FP outcome: recompute the three outputs from the fixture inputs with
     * the same bit-exact helpers. */
    float scale = sc->w == 4 ? vf3_bits_f32(sc->scale)
                             : vf3_bits_f32(sc->scale) * 0.5f; /* approx for the
                                                                  double fixture */
    float fr4 = vf3_f_mul(&ref.state, vf3_bits_f32(sc->src[0]), scale);
    float fr5 = vf3_f_mul(&ref.state, vf3_bits_f32(sc->src[1]), scale);
    float fr6 = vf3_f_mul(&ref.state, vf3_bits_f32(sc->src[2]), scale);
    float e0 = vf3_f_mul(&ref.state, vf3_f_from_int(&ref.state, (int32_t)c_r2), fr6);
    float e1 = vf3_f_mul(&ref.state, vf3_f_from_int(&ref.state, (int32_t)c_r5), fr5);
    float e2 = vf3_f_mul(&ref.state, vf3_f_from_int(&ref.state, (int32_t)c_r6), fr4);

    if (vf3_fr_get(&ref.state, 0) != e0 || vf3_fr_get(&ref.state, 1) != e1 ||
        vf3_fr_get(&ref.state, 2) != e2) {
        fprintf(stderr, "byte_color: %s: fr0/1/2 wrong (got %08x %08x %08x, "
                "want %08x %08x %08x)\n", sc->name,
                VF3_FR(&ref.state, 0), VF3_FR(&ref.state, 1), VF3_FR(&ref.state, 2),
                vf3_f32_bits(e0), vf3_f32_bits(e1), vf3_f32_bits(e2));
        free_run(&ref); free_run(&port); free_run(&hook);
        return 0;
    }

    ++ncases;
    free_run(&ref); free_run(&port); free_run(&hook);
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_byte_color_entry) {
        fprintf(stderr, "byte_color: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "single, all channels",
          .w = 4, .ptr_off = 0x800, .out_off = 0x810, .r4_off = 0x0c19d830u, .r1_off = 0x0c19d840u,
          .src = { 0x3f800000u, 0x40000000u, 0x40800000u }, .scale = 0x3b808080u,
          .lo = 0x0d34u, .hi = 0x00cdu },
        { .name = "single, zero bytes",
          .w = 4, .ptr_off = 0x900, .out_off = 0x820, .r4_off = 0x0c19d900u, .r1_off = 0x0c19d910u,
          .src = { 0x3f800000u, 0x3f800000u, 0x3f800000u }, .scale = 0x3b808080u,
          .lo = 0x0000u, .hi = 0x0000u },
        { .name = "single, max bytes",
          .w = 4, .ptr_off = 0xa00, .out_off = 0x830, .r4_off = 0x0c19da00u, .r1_off = 0x0c19da10u,
          .src = { 0x41200000u, 0x40a00000u, 0x40400000u }, .scale = 0x3b808080u,
          .lo = 0xffffu, .hi = 0xffffu },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("byte_color: %u differential cases - PASS\n", ncases);
    return 0;
}
