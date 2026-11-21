/* Differential replay of the native vec_lerp21 (src/native/vec_lerp21.c,
 * 0x8C09F354) against the readable guest port
 * (src/fight/vec_lerp21.c `vf3_vec_lerp21_entry`).
 *
 * Both sides seed the same flat RAM (a destination array of 21 3-float vectors
 * and a source array) and the same FR/register file, then run the leaf.  The
 * leaf blends each dst vector toward src by t (fr4): dst = src + t*(dst - src)
 * with the engine's round-toward-zero + FTZ FPSCR (fused mac, one rounding).
 *
 * The test matches the written dst RAM against an independent fixture model and
 * every register/FR/SR-T value against the guest, plus the sp-4 z-pointer park
 * slot the loop leaves behind. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vec_lerp21.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vec_lerp21_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x12000u

#define DST  0x0C012000u   /* 21 * 12 = 252 bytes */
#define SRC  0x0C013000u
#define SP0  0x0C014000u   /* the loop parks its z pointer at sp-4 */
#define RETURN_PC 0x0c09f3d2

#define VECTORS 21u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float f) { uint32_t u; memcpy(&u, &f, 4); w32(addr, u); }
static float rf(uint32_t addr) { uint32_t u = r32(addr); float f; memcpy(&f, &u, 4); return f; }

/* independent model: dst = src + t*(dst - src), one fused rounding toward zero */
static float fmodel_mac(float t, float diff, float src)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(t, diff, src);
    fesetround(saved);
    return z;
}
static float fmodel_sub(float a, float b)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = a - b;
    fesetround(saved);
    return z;
}

static void seed(float t)
{
    memset(ram, 0x6c, RAM_SIZE);
    for (unsigned i = 0; i < VECTORS; ++i) {
        wf(SRC + 12 * i + 0, (float)(10 + 3 * i));
        wf(SRC + 12 * i + 4, (float)(-5 - 2 * i));
        wf(SRC + 12 * i + 8, (float)(0.5f * (float)i));
        wf(DST + 12 * i + 0, (float)(i) * 1.0f);
        wf(DST + 12 * i + 4, (float)(100 + i));
        wf(DST + 12 * i + 8, (float)(-0.25f * (float)i));
    }
    (void)t;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], float t)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = DST;
    s->v[5] = SRC;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f000000u + i * 0x4000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    uint32_t tb; memcpy(&tb, &t, 4); s->v[VF3_REG_FR0 + 4] = tb; fr_in[4] = tb;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;
    s->v[18] = 0x00024001u;
    s->v[VF3_REG_FPUL] = 0x12345678u;
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(float t)
{
    seed(t);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in, t);
    memcpy(in_v, gs.v, 54 * sizeof(uint32_t));
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vec_lerp21_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  [t=%g] guest failed ok=%d oob=%u\n", (double)t, ok_guest, gmap.oob);
        return 1;
    }

    seed(t);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    a.fpul = 0x12345678u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    /* snapshot the original dst (the native writes it in place) for the model */
    float odx[VECTORS], ody[VECTORS], odz[VECTORS];
    for (unsigned i = 0; i < VECTORS; ++i) {
        odx[i] = rf(DST + 12 * i);
        ody[i] = rf(DST + 12 * i + 4);
        odz[i] = rf(DST + 12 * i + 8);
    }
    vf3_native_vec_lerp21(&a);

    int bad = 0;

    for (unsigned i = 0; i < 16; ++i)
        if (a.r[i] != gs.v[i])
            fprintf(stderr, "  [t=%g] r%u: native %08x guest %08x\n", (double)t, i, a.r[i], gs.v[i]), bad++;

    for (unsigned i = 0; i < 16; ++i)
        if (vf3_aim_ubits(a.fr[i]) != gs.v[VF3_REG_FR0 + i])
            fprintf(stderr, "  [t=%g] fr%u: native %08x guest %08x\n", (double)t, i, vf3_aim_ubits(a.fr[i]), gs.v[VF3_REG_FR0 + i]), bad++;

    if ((a.sr & 1u) != (gs.v[17] & 1u))
        fprintf(stderr, "  [t=%g] T: native %u guest %u\n", (double)t, a.sr & 1u, gs.v[17] & 1u), bad++;

    if (a.fpul != 0x12345678u) fprintf(stderr, "  [t=%g] fpul changed to %08x\n", (double)t, a.fpul), bad++;

    /* dst RAM: native vs guest, byte for byte */
    for (unsigned i = 0; i < VECTORS; ++i)
        for (unsigned e = 0; e < 3; ++e)
            if (vf3_aim_u32(&a, DST + 12 * i + 4 * e) != r32(DST + 12 * i + 4 * e))
                fprintf(stderr, "  [t=%g] dst[%u][%u]: native %08x guest %08x\n", (double)t, i, e,
                        vf3_aim_u32(&a, DST + 12 * i + 4 * e), r32(DST + 12 * i + 4 * e)), bad++;

    /* source array untouched */
    for (unsigned i = 0; i < VECTORS; ++i)
        for (unsigned e = 0; e < 3; ++e)
            if (vf3_aim_u32(&a, SRC + 12 * i + 4 * e) != r32(SRC + 12 * i + 4 * e))
                fprintf(stderr, "  [t=%g] src[%u][%u] changed\n", (double)t, i, e), bad++;

    /* sp-4 z-pointer park slot: holds the last *loop* vector's z address */
    uint32_t want_park = DST + 12u * 17u + 8u;
    if (vf3_aim_u32(&a, SP0 - 4u) != want_park)
        fprintf(stderr, "  [t=%g] park: native %08x want %08x\n", (double)t, vf3_aim_u32(&a, SP0 - 4u), want_park), bad++;

    /* independent fixture model of the whole dst array */
    for (unsigned i = 0; i < VECTORS; ++i) {
        float sx = rf(SRC + 12 * i), sy = rf(SRC + 12 * i + 4), sz = rf(SRC + 12 * i + 8);
        float mx = fmodel_mac(t, fmodel_sub(odx[i], sx), sx);
        float my = fmodel_mac(t, fmodel_sub(ody[i], sy), sy);
        float mz = fmodel_mac(t, fmodel_sub(odz[i], sz), sz);
        uint32_t bux, buy, buz; memcpy(&bux, &mx, 4); memcpy(&buy, &my, 4); memcpy(&buz, &mz, 4);
        if (vf3_aim_u32(&a, DST + 12 * i + 0) != bux)
            fprintf(stderr, "  [t=%g] model x[%u]: %08x want %08x\n", (double)t, i, vf3_aim_u32(&a, DST + 12 * i), bux), bad++;
        if (vf3_aim_u32(&a, DST + 12 * i + 4) != buy)
            fprintf(stderr, "  [t=%g] model y[%u]: %08x want %08x\n", (double)t, i, vf3_aim_u32(&a, DST + 12 * i + 4), buy), bad++;
        if (vf3_aim_u32(&a, DST + 12 * i + 8) != buz)
            fprintf(stderr, "  [t=%g] model z[%u]: %08x want %08x\n", (double)t, i, vf3_aim_u32(&a, DST + 12 * i + 8), buz), bad++;
    }

    printf("  [t=%g] %s\n", (double)t, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const float ts[] = { 0.0f, 1.0f, 0.5f, 0.1f, -0.25f, 2.5f };
    int bad = 0;
    for (unsigned k = 0; k < sizeof ts / sizeof ts[0]; ++k) bad |= compare_one(ts[k]);
    free(ram);
    printf("vec_lerp21_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
