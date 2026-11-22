/* matrix_translate_by_native_replay.c - differential replay of the native
 * XMTRX translate-by leaf (0x8C03CC60, src/native/matrix_translate_by.c,
 * `vf3_native_matrix_translate_by`) against the readable guest port
 * (src/fight/leaf_math.c, `vf3_matrix_translate_by_entry`).
 *
 * matrix_translate_by is a self-contained FP leaf (call-free, no stack
 * frame): it sets XMTRX's translation column to XMTRX * (FR4, FR5, FR6, 1)
 * via ftrv (column-major out = XMTRX * v, w=1 so the translation
 * contributes) - i.e. it moves the origin by the local offset in FR4..FR6.
 * FR4..FR7 hold the transformed vector on return; FR7 is set to 1.0 first.
 * FR8..FR15, r15 and SR are untouched.
 *
 * Both sides seed the same flat RAM, the same XMTRX and the same FR bank,
 * then run.  The XF12..XF15 translation column, FR4..FR7, the preserved
 * FR8..FR15, r15 and SR are compared.  The residual is the FPU difference
 * (ftrv against the native column-major multiply), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_translate_by.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_translate_by (0x8C03CC60) */
int vf3_matrix_translate_by_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

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
    const int ok = vf3_matrix_translate_by_entry(&gs, &gmap);
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
    const int rc = vf3_native_matrix_translate_by(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* the translation column XF12..XF15 (tolerance) */
    for (int i = 12; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxf[i]) > TOL && memcmp(&a.xm[i], &gxf[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  xf[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxf[i]);
            bad++;
        }
    }
    /* columns 0..11 are untouched by this leaf */
    for (int i = 0; i < 12; ++i) {
        if (memcmp(&a.xm[i], &xm[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  xf[%d] preserved: native %.7g guest %.7g\n", i, a.xm[i], xm[i]);
            bad++;
        }
    }
    /* FR4..FR7 (tolerance), FR0..FR3/FR8..FR15 exact */
    for (int i = 4; i <= 7; ++i) {
        if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (memcmp(&a.fr[i], &fr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d] preserved: native %.7g guest %.7g\n", i, a.fr[i], fr[i]);
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

    printf("  matrix_translate_by: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    int bad = 0;

    /* XMTRX: a rotation+translation; the w=1 component keeps the translation */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    float fr0[16];
    memset(fr0, 0, sizeof fr0);
    fr0[4] = 1.0f; fr0[5] = 2.0f; fr0[6] = 3.0f;       /* local offset */
    fr0[8] = 1.0f; fr0[9] = 2.0f; fr0[10] = 3.0f; fr0[11] = 4.0f;   /* FR8..11 sentinels */
    fr0[12] = 5.0f; fr0[13] = 6.0f; fr0[14] = 7.0f; fr0[15] = 8.0f; /* FR12..15 sentinels */

    float fr1[16]; memcpy(fr1, fr0, sizeof fr0);
    fr1[4] = -1.0f; fr1[5] = 0.5f; fr1[6] = -2.0f;      /* negative offset */

    float frz[16]; memcpy(frz, fr0, sizeof fr0);
    frz[4] = 0.0f; frz[5] = 0.0f; frz[6] = 0.0f;        /* zero offset */

    bad |= run_case("base", MX, fr0);
    bad |= run_case("negative offset", MX, fr1);
    bad |= run_case("zero offset", MX, frz);
    {
        /* identity XMTRX: the whole vector is the offset itself */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, fr0);
    }

    free(ram);
    printf("matrix_translate_by_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
