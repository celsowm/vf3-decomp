/* matrix_rotate_sc_native_replay.c - differential replay of the native
 * XMTRX rotate-sc leaf (0x8C03C970, src/native/matrix_rotate_sc.c,
 * `vf3_native_matrix_rotate_sc`) against the readable guest port
 * (src/fight/leaf_math.c, `vf3_matrix_rotate_sc_entry`).
 *
 * matrix_rotate_sc is a self-contained FP leaf (call-free, no stack frame):
 * it post-multiplies XMTRX by the Z rotation whose sin/cos are in FR4/FR5,
 * building v0 = {cos, sin, 0, 0} and v1 = {-sin, cos, 0, 0}, running each
 * through XMTRX via ftrv (column-major out = XMTRX * v), and writing the two
 * result columns into XMTRX columns 0 and 1 (XF0..XF7).  FR0..FR7 hold the
 * two outputs on return.  FR8..FR15, XF8..XF15, r15 and SR are untouched.
 *
 * Both sides seed the same flat RAM, the same XMTRX and the same FR bank,
 * then run.  The XF0..XF7 result columns, FR0..FR7, the preserved
 * XF8..XF15/FR8..FR15, r15 and SR are compared.  The residual is the FPU
 * difference (ftrv against the native column-major multiply), tolerated at
 * 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_rotate_sc.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_rotate_sc (0x8C03C970) */
int vf3_matrix_rotate_sc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static int run_case(const char *label, const float xm[16], const float fr[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = 0x0C0ABCDEu;                 /* pr */
    gs.v[17] = 0x60000000u;                 /* sr, T clear */
    gs.v[18] = 0x00040001u;                 /* fpscr, SZ + PR clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        gs.v[VF3_REG_XF0 + i] = bits;       /* XMTRX */
    }
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &fr[i], 4);
        gs.v[VF3_REG_FR0 + i] = bits;       /* FR0..FR15 */
    }
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE;
    gwin[0].data = (uint8_t *)ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    const int ok = vf3_matrix_rotate_sc_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t gr15 = gs.v[15], gsr = gs.v[17];
    float gxf[16], gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxf[i], &u, 4); }
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    const int rc = vf3_native_matrix_rotate_sc(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* the result columns XF0..XF7 (tolerance) */
    for (int i = 0; i < 8; ++i) {
        if (fabsf(a.xm[i] - gxf[i]) > TOL && memcmp(&a.xm[i], &gxf[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  xf[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxf[i]);
            bad++;
        }
    }
    /* columns 2,3 (XF8..XF15) are untouched by this leaf */
    for (int i = 8; i < 16; ++i) {
        if (memcmp(&a.xm[i], &xm[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  xf[%d] preserved: native %.7g guest %.7g\n", i, a.xm[i], xm[i]);
            bad++;
        }
    }
    /* FR0..FR7 (tolerance), FR8..FR15 exact */
    for (int i = 0; i < 8; ++i) {
        if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    for (int i = 8; i < 16; ++i) {
        if (memcmp(&a.fr[i], &fr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d] preserved: native %.7g guest %.7g\n", i, a.fr[i], fr[i]);
            bad++;
        }
    }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.sr != gsr) { if (bad < 10) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }

    printf("  matrix_rotate_sc: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    int bad = 0;

    /* XMTRX: a rotation+translation */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    float fr0[16];
    memset(fr0, 0, sizeof fr0);
    fr0[4] = 0.5f; fr0[5] = 0.8660254f;     /* sin = 0.5, cos ~ 0.866 (30 deg) */
    fr0[8] = 1.0f; fr0[9] = 2.0f; fr0[10] = 3.0f; fr0[11] = 4.0f;   /* FR8..11 sentinels */
    fr0[12] = 5.0f; fr0[13] = 6.0f; fr0[14] = 7.0f; fr0[15] = 8.0f; /* FR12..15 sentinels */

    float frneg[16]; memcpy(frneg, fr0, sizeof fr0);
    frneg[4] = -0.5f; frneg[5] = 0.8660254f;  /* negative sin */

    float frzero[16]; memcpy(frzero, fr0, sizeof fr0);
    frzero[4] = 0.0f; frzero[5] = 1.0f;      /* zero angle: identity in the 3x3 */

    bad |= run_case("base", MX, fr0);
    bad |= run_case("negative sin", MX, frneg);
    bad |= run_case("zero angle", MX, frzero);
    {
        /* identity XMTRX: columns become the v0/v1 vectors themselves */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, fr0);
    }

    free(ram);
    printf("matrix_rotate_sc_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
