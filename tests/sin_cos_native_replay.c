/* Differential replay of the native 16-bit-angle sine/cosine
 * (src/native/sin_cos.c, 0x8C03A6E0 / 0x8C03A140) against the readable guest
 * ports (src/fight/geom_readable.c, `vf3_sin_u16_entry` / `vf3_cos_u16_entry`).
 *
 * Both sides seed the same FR/register file and run the leaf.  The leaves are
 * call-free and read nothing from RAM.  The test compares FR0 (the sine or
 * cosine), r4 for the cosine (the folded angle) and the untouched registers,
 * and an independent fixture model computed with the same toward-zero +
 * fused-mac rounding. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "sin_cos.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_cos_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define RETURN_PC_SIN 0x0c03a6f2u
#define RETURN_PC_COS 0x0c03a152u

static uint8_t *ram;

static float fbits_to_f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

struct scenario {
    const char *name;
    uint32_t angle;   /* r4, low 16 bits used */
};

/* an independent model of sin using the same formula.  The toward-zero + FTZ
 * wrappers replicate the SH-4 rounding; using the raw C expressions lets the
 * compiler contract `h - quadrant*half_pi` into a single fused op, which
 * rounds once where the guest rounds twice, so the model calls the wrappers
 * the way the port does. */
static float mod_flz(float f)
{
    return f;   /* the test runs under FTZ, but the operand values are normal */
}
static float mod_op(float x, float y, char op)
{
    int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return mod_flz(z);
}
static float mod_fmul(float x, float y) { return mod_op(x, y, '*'); }
static float mod_fadd(float x, float y) { return mod_op(x, y, '+'); }
static float mod_fsub(float x, float y) { return mod_op(x, y, '-'); }
static float mod_fdiv(float x, float y) { return mod_op(x, y, '/'); }
static float mod_fmac(float x, float y, float acc)
{
    int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return mod_flz(z);
}
static uint32_t model_sin(float anglef)
{
    const float two = fbits_to_f(0x40000000u), two_pi = fbits_to_f(0x40c90fdau),
                turn = fbits_to_f(0x47800000u), half_pi = fbits_to_f(0x3fc90fdau),
                half = fbits_to_f(0x3f000000u);
    float theta = mod_fdiv(mod_fmul(anglef, two_pi), turn);
    float h = mod_fdiv(theta, two);
    float hh = mod_fadd(mod_fdiv(h, half_pi), half);
    int32_t quadrant = (hh >= 2147483648.0f) ? INT32_MAX
                     : (hh <= -2147483648.0f) ? INT32_MIN : (int32_t)hh;
    float y = mod_fsub(h, mod_fmul((float)quadrant, half_pi));
    float y_sq = mod_fmul(y, y);
    float frac = 0.0f;
    for (int k = 11; k >= 3; k -= 2) frac = mod_fdiv(y_sq, mod_fsub((float)k, frac));
    float t = mod_fdiv(y, mod_fsub(1.0f, frac));
    float denom = mod_fmac(t, t, 1.0f);
    float sine = mod_fdiv(mod_fmul(t, two), denom);
    float res = (quadrant & 1) ? -sine : sine;
    uint32_t u; memcpy(&u, &res, 4); return u;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, int is_cos,
                        uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->angle;
    s->v[15] = 0x0C11B000u;
    for (unsigned i = 0; i < 16; ++i) fr_in[i] = s->v[VF3_REG_FR0 + i];
    s->v[16] = is_cos ? RETURN_PC_COS : RETURN_PC_SIN;   /* pr */
    s->v[17] = 0x60000000u;      /* SR */
    s->v[18] = 0x00024001u;      /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc, int is_cos)
{
    printf("== %s %s (angle %04x)\n", sc->name, is_cos ? "cos" : "sin", sc->angle & 0xffffu);

    memset(ram, 0x6c, RAM_SIZE);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, sc, is_cos, in_v, fr_in);

    vf3_family_override = vf3_readable_override;
    const int ok_guest = is_cos ? vf3_cos_u16_entry(&gs, &gmap) : vf3_sin_u16_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t g_fr0 = gs.v[VF3_REG_FR0];
    const uint32_t g_r4 = gs.v[4];

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = is_cos ? RETURN_PC_COS : RETURN_PC_SIN;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    if (is_cos) vf3_native_cos_u16(&a);
    else        vf3_native_sin_u16(&a);

    int bad = 0;
    if (vf3_aim_ubits(a.fr[0]) != g_fr0) {
        fprintf(stderr, "  FR0: native %08x guest %08x\n", vf3_aim_ubits(a.fr[0]), g_fr0); bad++;
    }
    if (is_cos) {
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); bad++; }
    } else {
        if (a.r[4] != in_v[4]) { fprintf(stderr, "  r4(sin,unchanged): native %08x entry %08x\n", a.r[4], in_v[4]); bad++; }
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }
    for (unsigned i = 1; i < 16; ++i) {
        if (vf3_aim_ubits(a.fr[i]) != fr_in[i]) {
            fprintf(stderr, "  fr%u(untouched): native %08x entry %08x\n", i, vf3_aim_ubits(a.fr[i]), fr_in[i]); bad++;
        }
    }

    /* the fixture model */
    {
        uint32_t angU = sc->angle & 0xFFFFu;
        if (is_cos) {
            if (angU > 0x8000u) angU = 0x10000u - angU;   /* fold into first half turn */
            angU = 0x4000u - angU;                         /* masked &0xFFFF by sin's read */
        }
        float anglef = (float)(angU & 0xFFFFu);
        uint32_t want = model_sin(anglef);
        if (vf3_aim_ubits(a.fr[0]) != want) {
            fprintf(stderr, "  model: native %08x model %08x\n", vf3_aim_ubits(a.fr[0]), want); bad++;
            printf("  model: DIFFERS\n");
        } else {
            printf("  model: match\n");
        }
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "zero",     .angle = 0x0000u },
        { .name = "quadrant", .angle = 0x4000u },
        { .name = "half",     .angle = 0x8000u },
        { .name = "threeq",   .angle = 0xC000u },
        { .name = "small",    .angle = 0x0A00u },
        { .name = "large",    .angle = 0xF000u },
        { .name = "odd",      .angle = 0x2D80u },
        { .name = "odd2",     .angle = 0xAA5Au },
        { .name = "one",      .angle = 0x0001u },
        { .name = "full-1",   .angle = 0xFFFFu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i) {
        bad |= compare_one(&scenarios[i], 0);
        bad |= compare_one(&scenarios[i], 1);
    }

    free(ram);
    printf("sin_cos_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
