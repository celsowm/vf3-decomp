/* xform_vector_native_replay.c - differential replay of the native
 * xform_vector (0x8C03B4B0, src/native/xform_vector.c,
 * `vf3_native_xform_vector`) against the readable guest port
 * (src/fight/matrix_extra.c, `vf3_xform_vector_entry`).
 *
 * xform_vector is a self-contained FP leaf (call-free, no stack frame): it
 * reads the three floats at r4 as a vector, runs it through XMTRX as
 * (x, y, z, 0) via ftrv (column-major out = XMTRX * v; w=0 drops the
 * translation, so this is rotation-only), lands the result in FR4..FR6
 * (FR7 = 0) and writes the three floats out to r5.  r4 advances by 12;
 * r5, FR8..FR15, r15 and SR are untouched.
 *
 * Both sides seed the same flat RAM, the same XMTRX and the same FR bank,
 * then run.  The out words at r5, the vector at r4 (now r4+12), FR4..FR7,
 * the preserved FR8..FR15, r4/r5/r15/SR are compared.  The residual is the
 * FPU difference (ftrv against the native column-major multiply), tolerated
 * at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "xform_vector.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for xform_vector (0x8C03B4B0) */
int vf3_xform_vector_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u
#define VEC_ADDR 0x0C1A6000u
#define OUT_ADDR 0x0C1A6040u

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], const float fr[16], const float vec[3])
{
    memset(s, 0, sizeof *s);
    s->v[4] = VEC_ADDR;
    s->v[5] = OUT_ADDR;
    s->v[15] = 0x0C20FF00u;
    s->v[16] = 0x0C0ABCDEu;                 /* pr */
    s->v[17] = 0x60000000u;                 /* sr, T clear */
    s->v[18] = 0x00040001u;                 /* fpscr, SZ + PR clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;       /* XF0..XF15 = XMTRX */
    }
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &fr[i], 4);
        s->v[VF3_REG_FR0 + i] = bits;       /* FR0..FR15 */
    }
    s->budget = 4000000u;
    memcpy(at(VEC_ADDR), vec, sizeof(float) * 3);
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const float xm[16], const float fr[16], const float vec[3])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[4] = VEC_ADDR;
    a.r[5] = OUT_ADDR;
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    memcpy(at(VEC_ADDR), vec, sizeof(float) * 3);
    return a;
}

static int run_case(const char *label, const float xm[16], const float fr[16], const float vec[3])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, fr, vec);
    const int ok = vf3_xform_vector_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t gr4 = gs.v[4], gr5 = gs.v[5], gr15 = gs.v[15], gsr = gs.v[17];
    float gout[3], gfr[16];
    for (int i = 0; i < 3; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + 4 + i]; memcpy(&gfr[4 + i], &u, 4); }
    { uint32_t u = gs.v[VF3_REG_FR0 + 7]; memcpy(&gfr[7], &u, 4); }
    for (int i = 0; i < 8; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + 8 + i]; memcpy(&gfr[8 + i], &u, 4); }
    memcpy(gout, at(OUT_ADDR), sizeof gout);

    vf3_native_aim a = setup_native(xm, fr, vec);
    /* reset the out region so a native that does not write it (or writes only
     * part of it) is visible against the guest's result */
    {
        const uint32_t sentinel = 0xC9400000u;  /* large negative float, not NaN */
        uint32_t *dst = (uint32_t *)at(OUT_ADDR);
        for (int i = 0; i < 4; ++i) dst[i] = sentinel;
    }
    const int rc = vf3_native_xform_vector(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }
    float nout[3];
    memcpy(nout, at(OUT_ADDR), sizeof nout);

    for (int i = 0; i < 3; ++i) {
        if (fabsf(nout[i] - gout[i]) > TOL && memcmp(&nout[i], &gout[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  out[%d]: native %.7g guest %.7g\n", i, nout[i], gout[i]);
            bad++;
        }
    }
    for (int i = 4; i <= 6; ++i) {
        if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    if (a.fr[7] != gfr[7]) { if (bad < 10) fprintf(stderr, "  fr[7]: native %.7g guest %.7g\n", a.fr[7], gfr[7]); bad++; }
    for (int i = 8; i < 16; ++i) {
        if (memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d] preserved: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[5] != gr5) { if (bad < 10) fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gr5); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.sr != gsr) { if (bad < 10) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }

    printf("  xform_vector: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { printf("xform_vector_native_replay: skipped (image absent)\n"); free(ram); return 0; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); printf("skipped (image short)\n"); free(ram); return 0; }
        fclose(f);
    }

    /* XMTRX: a rotation+translation; the w=0 component must drop it */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    float fr0[16];
    memset(fr0, 0, sizeof fr0);
    fr0[8] = 1.0f; fr0[9] = 2.0f; fr0[10] = 3.0f; fr0[11] = 4.0f;   /* FR8..11 sentinels */
    fr0[12] = 5.0f; fr0[13] = 6.0f; fr0[14] = 7.0f; fr0[15] = 8.0f;  /* FR12..15 sentinels */

    const float v0[3] = { 1.0f, 2.0f, 3.0f };
    const float vzero[3] = { 0.0f, 0.0f, 0.0f };
    const float vneg[3] = { -1.0f, 0.5f, -2.0f };
    const float vx[3] = { 1.0f, 0.0f, 0.0f };

    int bad = 0;
    bad |= run_case("base", MX, fr0, v0);
    bad |= run_case("zero vec", MX, fr0, vzero);
    bad |= run_case("negative vec", MX, fr0, vneg);
    {
        /* identity XMTRX: out = vec itself by the 3x3 part, translation dropped */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, fr0, vx);
    }

    free(ram);
    printf("xform_vector_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
