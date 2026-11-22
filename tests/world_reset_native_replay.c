/* world_reset_native_replay.c - differential replay of the native world_reset
 * (0x8C03E980, src/native/world_reset.c, `vf3_native_world_reset`) against the
 * readable guest port (src/fight/matrix_extra.c, `vf3_world_reset_entry`).
 *
 * world_reset sequences only matrix-layer callees that the readable registry
 * already serves (matrix_transpose 0x8C03CC30, xform_vector 0x8C03B4B0):
 *
 *   1. transpose XMTRX,
 *   2. transform the vector at 0x0C19D5B0 + 0x68 (rotation-only, w = 0) into
 *      +0x80,
 *   3. transform the vector at 0x0C0EA600 into 0x0C058FE0,
 *   4. transpose XMTRX back (the tail call).
 *
 * The net XMTRX is the identity of the two transposes (the transforms run in
 * the transposed frame, exactly as the guest does).  Both sides run on the
 * same flat RAM and the same seed XMTRX: the guest through its ram map and
 * the readable chain, the native through `ram_base` with the callees inlined.
 *
 * Compared: the two destination 3-vectors (at the native float tolerance
 * 2e-3) and the final XMTRX (bit-exact, since the double transpose is pure
 * permutation).  Non-finite values must match exactly. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "world_reset.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_world_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TABLE   0x0C19D5B0u
#define VEC_IN  104u
#define DST1    0x80u
#define SRC2    0x0C0EA600u
#define DST2    0x0C058FE0u
#define SP0     0x0C210000u

static float *ram;
static void *at(uint32_t addr) { return (uint8_t *)ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static float rf(uint32_t addr) { float v; memcpy(&v, at(addr), 4); return v; }

static void seed(void)
{
    memset((uint8_t *)at(TABLE), 0, 0x100u);
    memset((uint8_t *)at(SRC2), 0, 0x40u);
    memset((uint8_t *)at(DST2), 0, 0x40u);
    /* source vectors are distinctly seeded */
    wf(TABLE + VEC_IN + 0u, 1.5f); wf(TABLE + VEC_IN + 4u, -2.5f); wf(TABLE + VEC_IN + 8u, 0.75f);
    wf(SRC2 + 0u, 3.0f); wf(SRC2 + 4u, -1.0f); wf(SRC2 + 8u, 2.0f);
    /* destinations start dirty so a missed write is visible */
    wf(TABLE + DST1 + 0u, -99.0f); wf(TABLE + DST1 + 4u, -99.0f); wf(TABLE + DST1 + 8u, -99.0f);
    wf(DST2 + 0u, -99.0f); wf(DST2 + 4u, -99.0f); wf(DST2 + 8u, -99.0f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16])
{
    memset(s, 0, sizeof *s);
    s->v[15] = SP0;
    s->v[VF3_REG_PR] = 0x0C0ABCDEu;
    s->v[17] = 0x60000000u;            /* sr */
    s->v[18] = 0x00040001u;            /* fpscr */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;  /* XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

/* compare a 3-float region; tolerate 2e-3, non-finite must be bit-exact */
static int cmp_vec(const uint8_t *guest, uint32_t g_off, uint32_t n_addr,
                   const char *name)
{
    int nb = 0;
    for (int i = 0; i < 3; ++i) {
        float gf, nf;
        memcpy(&gf, guest + g_off + 4u * (uint32_t)i, 4);
        nf = rf(n_addr + 4u * (uint32_t)i);
        uint32_t gb, nb_ = 0; memcpy(&gb, &gf, 4); memcpy(&nb_, &nf, 4);
        if ((!isfinite(gf) || !isfinite(nf)) ? (gb != nb_)
                                             : (fabsf(gf - nf) > 2.0e-3f && gb != nb_)) {
            if (nb < 8) fprintf(stderr, "  [%s][%d] want %.7g got %.7g\n", name, i, gf, nf);
            nb++;
        }
    }
    printf("  %-5s: %s\n", name, nb ? "DIFFERS" : "match");
    return nb;
}

static int run_case(const char *label, const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);

    /* guest: run on the seeded RAM, capture the regions + final XMTRX */
    seed();
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm);
    if (!vf3_world_reset_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    uint8_t *gvec = (uint8_t *)malloc(24u);
    memcpy(gvec, at(TABLE + DST1), 12u);
    memcpy(gvec + 12u, at(DST2), 12u);
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }

    /* native: re-seed so both sides see the same initial RAM/XMTRX */
    seed();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    memcpy(a.xm, xm, sizeof a.xm);
    vf3_native_world_reset(&a);

    int bad = 0;
    bad |= cmp_vec(gvec, 0u,  TABLE + DST1, "dst1");
    bad |= cmp_vec(gvec, 12u, DST2,         "dst2");

    int xb = 0;
    for (int i = 0; i < 16; ++i) {
        uint32_t ga, na; memcpy(&ga, &gxm[i], 4); memcpy(&na, &a.xm[i], 4);
        if (ga != na) { if (xb < 16) fprintf(stderr, "  xm[%d]: native %08x guest %08x\n", i, na, ga); xb++; }
    }
    printf("  xmtrx  : %s\n", xb ? "DIFFERS" : "match");
    bad |= xb;

    free(gvec);
    printf("  world_reset: %s\n", bad ? "FAIL" : "match");
    return bad;
}

int main(void)
{
    static const float M1[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, -2.0f, 0.5f, 1.0f,
    };
    static const float MI[16] = {
        1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1,
    };
    static const float M2[16] = {
        0.8f, 0.1f, -0.3f, 0.0f,
        0.2f, 0.9f,  0.1f, 0.0f,
        -0.1f, 0.4f, 0.7f, 0.0f,
        12.0f, -4.0f, 8.0f, 1.0f,
    };

    ram = (float *)calloc(1, RAM_SIZE);
    if (!ram) return 2;
    int bad = 0;
    bad |= run_case("general", M1);
    bad |= run_case("identity", MI);
    bad |= run_case("skew", M2);
    free(ram);
    printf("world_reset_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
