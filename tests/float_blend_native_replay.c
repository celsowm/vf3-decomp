/* Differential replay of the native four-float blend leaf
 * (src/native/float_blend.c, 0x8C03E810) against the readable guest port
 * (src/fight/float_blend.c, `vf3_float_blend_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free FP body: it
 * copies four floats out of an array (r4) into a structure of four slots,
 * then writes a weighted sum over three of the slots back into the first one
 * (a multiply plus two fused multiply-adds).  The structure's address and the
 * three weights live in the literal pool; the two slot addresses the blend
 * reads back are pushed onto an 8-byte frame below sp.
 *
 * The fixture lays out the pool, the array, the structure and the caller's
 * stack and runs the two sides from the same seed.  The four windows, the
 * contract registers and the FR bank are compared byte for byte, and the
 * slots are verified against an independent fixture model (the first three
 * slots are exact copies of the array; slot 0 is the blend computed in the
 * test).  The scenarios are single precision, the FPSCR the captured fight
 * exercises. */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "float_blend.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_float_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C000000u
#define RAM_SIZE 0x200000u

/* the literal pool */
#define POOL_BASE 0x0c03e8a0u
#define POOL_LEN  0x20u
#define G_DEST (POOL_BASE + 0x04u)
#define G_A    (POOL_BASE + 0x08u)
#define G_B    (POOL_BASE + 0x0cu)
#define G_C    (POOL_BASE + 0x10u)

/* the array / structure / stack */
#define SRC_BASE 0x0c180000u
#define SRC_LEN  0x40u
#define DST_BASE 0x0c190000u
#define DST_LEN  0x40u
#define STACK_BASE 0x0c107ff0u
#define STACK_LEN  0x20u
#define SP 0x0c108000u

#define OFF_POOL  (POOL_BASE - RAM_BASE)
#define OFF_SRC   (SRC_BASE - RAM_BASE)
#define OFF_DST   (DST_BASE - RAM_BASE)
#define OFF_STACK (STACK_BASE - RAM_BASE)

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t r32(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

struct scenario {
    const char *name;
    float src[4];   /* the array's four floats */
    float w[3];     /* the three weights */
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    /* the literal pool */
    w32(G_DEST, DST_BASE);
    w32(G_A, fbits(sc->w[0]));
    w32(G_B, fbits(sc->w[1]));
    w32(G_C, fbits(sc->w[2]));
    /* the array: one float per cell, four bytes apart */
    for (unsigned i = 0; i < 4; ++i) w32(SRC_BASE + 4u * i, fbits(sc->src[i]));
    /* the structure starts full so an unwritten byte shows up */
    for (uint32_t ad = DST_BASE; ad < DST_BASE + DST_LEN; ad += 4) w32(ad, 0x0badf00du);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = SRC_BASE;
    s->v[15] = SP;
    s->v[16] = 0x0c0abcdeu;          /* pr */
    s->v[17] = 0x301u;
    s->v[18] = 0x00040001u;          /* single precision, RM bit 0 (toward zero) */
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    static vf3_ram_win win[4];
    win[0].data = ram + OFF_POOL;  win[0].base = POOL_BASE;  win[0].len = POOL_LEN;
    win[1].data = ram + OFF_SRC;   win[1].base = SRC_BASE;   win[1].len = SRC_LEN;
    win[2].data = ram + OFF_DST;   win[2].base = DST_BASE;   win[2].len = DST_LEN;
    win[3].data = ram + OFF_STACK; win[3].base = STACK_BASE; win[3].len = STACK_LEN;
    map->wins = win;
    map->n = 4;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    setup_guest(&gs, &gmap);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_float_blend_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *snap = (uint8_t *)malloc(RAM_SIZE);
    memcpy(snap, ram, RAM_SIZE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = SRC_BASE;
    a.r[15] = SP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0x00040001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(0x76543210u + 21u + i);
    vf3_native_float_blend(&a);

    int bad = 0;

    /* RAM: compare dst + stack against the guest's snapshot */
    {
        int nb = 0;
        for (uint32_t ad = DST_BASE; ad < DST_BASE + DST_LEN; ad += 4) {
            uint32_t g; memcpy(&g, snap + (ad - RAM_BASE), 4);
            if (g != r32(ad)) { if (nb < 10) fprintf(stderr, "  dst @%08x: got %08x want %08x\n", ad, r32(ad), g); nb++; }
        }
        for (uint32_t ad = STACK_BASE; ad < STACK_BASE + STACK_LEN; ad += 4) {
            uint32_t g; memcpy(&g, snap + (ad - RAM_BASE), 4);
            if (g != r32(ad)) { if (nb < 14) fprintf(stderr, "  stk @%08x: got %08x want %08x\n", ad, r32(ad), g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* registers + FR */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) { fprintf(stderr, "  r%u: native %08x guest %08x\n", i, a.r[i], gs.v[i]); nb++; }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr\n"); nb++; }
        if (a.sr != gs.v[17]) { fprintf(stderr, "  sr\n"); nb++; }
        for (unsigned i = 0; i < 16; ++i)
            if (fbits(a.fr[i]) != gs.v[21 + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model */
    {
        int nb = 0;
        /* slots 1..3 are exact copies of the array's floats 1..3 */
        if (r32(DST_BASE + 4u) != fbits(sc->src[1])) { fprintf(stderr, "  slot1\n"); nb++; }
        if (r32(DST_BASE + 8u) != fbits(sc->src[2])) { fprintf(stderr, "  slot2\n"); nb++; }
        if (r32(DST_BASE + 12u) != fbits(sc->src[3])) { fprintf(stderr, "  slot3\n"); nb++; }
        /* slot 0 is the blend, computed here under toward-zero with a fused fma */
        int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float blend = sc->src[2] * sc->w[0];
        blend = fmaf(sc->w[1], sc->src[1], blend);
        blend = fmaf(sc->w[2], sc->src[3], blend);
        fesetround(saved);
        if (r32(DST_BASE) != fbits(blend)) {
            fprintf(stderr, "  slot0 blend: stored %08x model %08x (%g vs %g)\n",
                    r32(DST_BASE), fbits(blend), vf3_bits_f32(r32(DST_BASE)), blend);
            nb++;
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("float_blend_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "basic",
          { 1.0f, 2.0f, 3.0f, 4.0f },
          { 0.5f, 0.25f, 0.125f } },
        { .name = "negatives",
          { -1.5f, 2.25f, -3.75f, 4.5f },
          { -0.5f, 0.75f, 2.0f } },
        { .name = "subnormal",
          { 1.5e-40f, 2.0f, 3.0f, 4.0f },
          { 0.5f, 0.25f, 0.5f } },
        { .name = "tiny",
          { 1.0f / 3.0f, 2.0f / 3.0f, 1.0f, -1.0f / 7.0f },
          { 1.0f / 3.0f, 1.0f / 5.0f, 1.0f / 9.0f } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("float_blend_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
