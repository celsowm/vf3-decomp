/* rotation_xmtrx_native_replay.c - differential replay of the native
 * rotation_xmtrx (0x8C03C8B0, src/native/rotation_xmtrx.c,
 * `vf3_native_rotation_xmtrx`) against the readable guest port
 * (src/fight/small_leaves.c, `vf3_rotation_xmtrx_entry`).
 *
 * rotation_xmtrx is a self-contained FP leaf: it takes FR4 (sin) and FR5
 * (cos), builds two FV column vectors {cos, 0, -sin, 0} and {sin, 0, cos, 0},
 * runs each through XMTRX via ftrv (column-major out = XMTRX * v), lands the
 * results in FR0..FR3 / FR4..FR7, and writes them into XMTRX columns 0 and 2
 * (XF0..XF3 / XF8..XF11); columns 1 and 3 are untouched.  FR8..FR15, r15 and
 * SR are untouched.
 *
 * Both sides seed the same flat RAM, the same XMTRX and the same FR bank,
 * then run.  The final XMTRX (columns 0..3), FR0..FR7, the preserved
 * FR8..FR15 and r15/SR are compared.  The residual is the FPU difference
 * (ftrv against the native column-major multiply), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "rotation_xmtrx.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for rotation_xmtrx (0x8C03C8B0) */
int vf3_rotation_xmtrx_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], const float fr[16])
{
    memset(s, 0, sizeof *s);
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
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const float xm[16], const float fr[16])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    return a;
}

static int run_case(const char *label, const float xm[16], const float fr[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, fr);
    const int ok = vf3_rotation_xmtrx_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    float gxm[16], gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }
    const uint32_t gr15 = gs.v[15], gsr = gs.v[17];

    vf3_native_aim a = setup_native(xm, fr);
    const int rc = vf3_native_rotation_xmtrx(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* final XMTRX: columns 0 and 2 are the products, 1 and 3 unchanged */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* FR0..FR7 = the two products; FR8..FR15 preserved */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    /* r15 / SR untouched */
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.sr != gsr) { if (bad < 10) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }

    printf("  rotation_xmtrx: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { printf("rotation_xmtrx_native_replay: skipped (image absent)\n"); free(ram); return 0; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); printf("skipped (image short)\n"); free(ram); return 0; }
        fclose(f);
    }

    /* XMTRX: a rotation+translation, distinct columns 1/3 to check untouched */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    /* a 30-degree rotation: sin = 0.5, cos = 0.866 */
    float fr0[16];
    memcpy(fr0, MX, sizeof MX);             /* placeholder; overwritten below */
    memset(fr0, 0, sizeof fr0);
    fr0[4] = 0.5f;                          /* FR4 = sin */
    fr0[5] = 0.8660254f;                    /* FR5 = cos */
    fr0[12] = 1.0f; fr0[13] = 2.0f; fr0[14] = 3.0f; fr0[15] = 4.0f;  /* FR12..15 sentinels */

    int bad = 0;
    bad |= run_case("base", MX, fr0);
    {
        /* zero sin/cos: both products are zero columns */
        float fz[16]; memcpy(fz, fr0, sizeof fz);
        fz[4] = 0.0f; fz[5] = 0.0f;
        bad |= run_case("zero sincos", MX, fz);
    }
    {
        /* negative sin */
        float fn[16]; memcpy(fn, fr0, sizeof fn);
        fn[4] = -0.5f;
        bad |= run_case("negative sin", MX, fn);
    }
    {
        /* identity XMTRX: out = v itself */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, fr0);
    }
    {
        /* FR8..FR11 sentinels that must survive */
        float fs[16]; memcpy(fs, fr0, sizeof fs);
        fs[8] = -1.0f; fs[9] = -2.0f; fs[10] = -3.0f; fs[11] = -4.0f;
        bad |= run_case("FR8..11 sentinels", MX, fs);
    }

    free(ram);
    printf("rotation_xmtrx_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
