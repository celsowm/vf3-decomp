/* matrix_rotate_z_native_replay.c - differential replay of the native
 * XMTRX rotate-Z leaf (0x8C03C940, src/native/matrix_rotate_z.c,
 * `vf3_native_matrix_rotate_z`) against the readable guest port
 * (src/fight/leaf_math.c, `vf3_rotate_z_entry`).
 *
 * matrix_rotate_z is a self-contained FP leaf (call-free, no stack frame): it
 * takes the Z-rotation angle in r4 (65536 = one turn), derives sin/cos from it
 * (the fsca step, FPUL = r4), builds v0 = {cos, sin, 0, 0} and
 * v1 = {-sin, cos, 0, 0}, runs each through XMTRX via ftrv (column-major
 * out = XMTRX * v), and writes the two result columns into XMTRX columns 0 and
 * 1 (XF0..XF7).  FR0..FR7 hold the two outputs on return.  FR8..FR15,
 * XF8..XF15, r15 and SR are untouched.
 *
 * Both sides seed the same angle (r4), the same XMTRX and the same FR bank,
 * then run.  The XF0..XF7 result columns, FR0..FR7, FPUL (must be the angle),
 * the preserved XF8..XF15/FR8..FR15, r15 and SR are compared.  The residual is
 * the FPU difference (fsca-vs-sinf/cosf plus the ftrv accumulate), tolerated
 * at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_rotate_z.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_rotate_z (0x8C03C940) */
int vf3_rotate_z_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static int run_case(const char *label, uint32_t angle, const float xm[16],
                    const float fr[16], uint32_t fpul_seed)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[4] = angle;
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = 0x0C0ABCDEu;                 /* pr */
    gs.v[17] = 0x60000000u;                 /* sr, T clear */
    gs.v[18] = 0x00040001u;                 /* fpscr, SZ + PR clear */
    gs.v[VF3_REG_FPUL] = fpul_seed;         /* FPUL must become the angle */
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
    const int ok = vf3_rotate_z_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t gr15 = gs.v[15], gsr = gs.v[17], gfpul = gs.v[VF3_REG_FPUL];
    float gxf[16], gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxf[i], &u, 4); }
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    a.r[4] = angle;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    a.fpul = fpul_seed;
    const int rc = vf3_native_matrix_rotate_z(&a);
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
    if (a.fpul != gfpul) { if (bad < 10) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.sr != gsr) { if (bad < 10) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }

    printf("  matrix_rotate_z: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
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
    fr0[8] = 1.0f; fr0[9] = 2.0f; fr0[10] = 3.0f; fr0[11] = 4.0f;   /* FR8..11 sentinels */
    fr0[12] = 5.0f; fr0[13] = 6.0f; fr0[14] = 7.0f; fr0[15] = 8.0f; /* FR12..15 sentinels */

    /* 65536 = one turn.  30 deg = 65536/12; 90 deg = 65536/4. */
    const uint32_t A30 = 65536u / 12u;      /* sin = 0.5 */
    const uint32_t A90 = 16384u;            /* sin = 1, cos = 0 */
    const uint32_t A210 = 3u * 65536u / 12u;/* sin = -0.5 (negative quadrant) */

    bad |= run_case("base 30 deg", A30, MX, fr0, 0x12345678u);
    bad |= run_case("90 deg", A90, MX, fr0, 0x0u);
    bad |= run_case("negative quadrant 210 deg", A210, MX, fr0, 0xDEADBEEFu);
    {
        /* identity XMTRX: columns become the v0/v1 vectors themselves */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", A90, I, fr0, 0x0u);
    }

    free(ram);
    printf("matrix_rotate_z_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
