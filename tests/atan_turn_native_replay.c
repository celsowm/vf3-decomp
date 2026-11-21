/* Differential replay of the native atan-turn (src/native/atan_turn.c,
 * 0x8C039FD0) against the readable guest port (src/fight/atan_turn.c,
 * `vf3_atan_turn_entry`).
 *
 * Both sides seed the same FR bank (FR4 = x) and register file, then run the
 * leaf.  The leaf is call-free and no-stack; it folds the argument into
 * [-1,1], evaluates atan as a 13-term continued fraction, scales to 16-bit
 * turns and applies the quadrant fold.  The test compares r0/r3/r4/r5, FPUL,
 * SR's T bit, the FR-bank outputs the leaf writes (fr1..fr8) against the
 * guest, and an independent fixture model that computes the angle from the
 * input straight from the defining equation. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "atan_turn.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_atan_turn_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RETURN_PC 0x0c039fe2u

#define TWO_PI_BITS  0x40C90FDAu
#define SCALE_BITS   0x47800000u
#define HALF_BITS    0x3F000000u

struct scenario {
    const char *name;
    uint32_t x;   /* FR4 */
};

static void setup_guest(vf3_matrix_state *s, uint32_t x_in, uint32_t in_v[54],
                        uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    VF3_FR(s, 4) = x_in;
    for (unsigned i = 0; i < 16; ++i) fr_in[i] = s->v[VF3_REG_FR0 + i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* SR: T clear */
    s->v[18] = 0x00024001u;      /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));
}

static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}
static float fbits_to_f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* Independent fixture model: reproduce the continued fraction with the same
 * toward-zero rounding. */
static uint32_t model_pack(uint32_t x_bits)
{
    const float x = fbits_to_f(x_bits);
    const float one = 1.0f;
    int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    float u = x;
    if (fabsf(x) > one) u = one / x;
    float t = 0.0f;
    for (int32_t n = 13;;) {
        int32_t cur = n; n -= 1;
        float fn = (float)cur;
        float den = (float)(cur << 1);
        float sq = fn * fn;
        den = den + t;
        float num = sq * u;
        den = den + one;
        num = num * u;
        t = num / den;
        if (n < 1) break;
    }
    t = t + one;
    float atan = u / t;
    float two_pi = fbits_to_f(TWO_PI_BITS), scale = fbits_to_f(SCALE_BITS), half = fbits_to_f(HALF_BITS);
    float v = atan + two_pi;
    v = v * scale;
    v = v / two_pi;
    v = v + half;
    fesetround(saved);
    return ftrc(v) & 0xFFFFu;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (x %08x)\n", sc->name, sc->x);

    vf3_matrix_state gs;
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, sc->x, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_atan_turn_entry(&gs, NULL);
    vf3_family_override = NULL;
    if (!ok_guest) { fprintf(stderr, "  guest run failed\n"); return 1; }
    const uint32_t g_fpul = gs.v[53];

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_atan_turn(&a);

    int bad = 0;

    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); bad++; }
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.fpul != g_fpul) { fprintf(stderr, "  FPUL: native %08x guest %08x\n", a.fpul, g_fpul); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 3 || i == 4 || i == 5) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }
    /* FR-bank outputs the leaf writes (fr1..fr8) match the guest */
    for (unsigned i = 1; i <= 8; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g) {
            fprintf(stderr, "  fr%u: native %08x guest %08x\n", i, vf3_aim_ubits(a.fr[i]), g); bad++;
        }
    }
    /* untouched FR registers keep their entry value */
    for (unsigned i = 0; i < 16; ++i) {
        if (i >= 1 && i <= 8) continue;
        if (vf3_aim_ubits(a.fr[i]) != fr_in[i]) {
            fprintf(stderr, "  fr%u(untouched): native %08x entry %08x\n", i, vf3_aim_ubits(a.fr[i]), fr_in[i]); bad++;
        }
    }

    /* the fixture model: the angle must equal the model's 16-bit value */
    {
        uint32_t want = model_pack(sc->x);
        if (a.r[4] != want) {
            fprintf(stderr, "  model angle: native %04x model %04x\n", a.r[4], want); bad++;
        }
        printf("  model: %s\n", want == a.r[4] ? "match" : "DIFFERS");
    }

    return bad ? 1 : 0;
}

int main(void)
{
    static const struct scenario scenarios[] = {
        { .name = "x=0.0",      .x = 0x00000000u },
        { .name = "x=0.5",      .x = 0x3f000000u },
        { .name = "x=1.0",      .x = 0x3f800000u },
        { .name = "x=-0.5",     .x = 0xbf000000u },
        { .name = "x=-1.0",     .x = 0xbf800000u },
        { .name = "x=2.0",      .x = 0x40000000u },
        { .name = "x=-2.0",     .x = 0xc0000000u },
        { .name = "x=0.25",     .x = 0x3e800000u },
        { .name = "x=0.75",     .x = 0x3f400000u },
        { .name = "x=1.25",     .x = 0x3fa00000u },
        { .name = "x=100.0",    .x = 0x42c80000u },
        { .name = "x=-100.0",   .x = 0xc2c80000u },
        { .name = "x=0.1",      .x = 0x3dcccccdu },
        { .name = "x=-0.9",     .x = 0xbf666666u },
        { .name = "x=0.9999",   .x = 0x3f7ff972u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    printf("atan_turn_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
