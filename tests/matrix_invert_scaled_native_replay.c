/* matrix_invert_scaled_native_replay.c - differential replay of the native
 * matrix_invert_scaled (0x8C03B5C0, src/native/matrix_invert_scaled.c,
 * `vf3_native_matrix_invert_scaled`) against the readable guest port
 * (src/fight/matrix_extra.c, `vf3_matrix_invert_scaled_entry`).
 *
 * matrix_invert_scaled is a self-contained FP leaf (call-free, no stack
 * frame): it inverts a rotation + scale + translation XMTRX in place.  With
 * t = the translation and c0/c1/c2 the three axis columns:
 *
 *   1. tc_i = t . c_i (four-element FIPR dots)
 *   2. t = (tc0, tc1, tc2); the axis columns' w elements become 0
 *   3. l_i = |c_i|^2, and t is negated
 *   4. inv_i = 1/sqrt(l_i)
 *   5. normalise the axes and the translation components by inv_i
 *   6. transpose the 3x3 block (FPUL swaps)
 *   7. clear the w elements again
 *
 * Both sides seed the same XMTRX (as XF0..XF15 for the guest, as a->xm for
 * the native), then run.  The final XMTRX, the FPUL side effect and the
 * preserved registers are compared.  The residual is the FPU difference (the
 * fsrra 1/sqrt against sqrtf), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_invert_scaled.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_invert_scaled (0x8C03B5C0) */
int vf3_matrix_invert_scaled_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define TOL 2.0e-3f

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16])
{
    memset(s, 0, sizeof *s);
    s->v[15] = 0x0C20FF00u;
    s->v[16] = 0x0C0ABCDEu;                 /* pr */
    s->v[17] = 0x60000000u;                 /* sr */
    s->v[18] = 0x00040001u;                 /* fpscr */
    s->v[19] = 0x12345678u;                 /* macl */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;       /* XF0..XF15 = XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = 0x0C010000u; win[0].len = 0x400000u;
    win[0].data = (uint8_t *)calloc(1, 0x400000u);
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const float xm[16])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    memcpy(a.xm, xm, sizeof a.xm);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    return a;
}

static int run_case(const char *label, const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm);
    const int ok = vf3_matrix_invert_scaled_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    const uint32_t gfpul = gs.v[VF3_REG_FPUL];
    float gf; memcpy(&gf, &gfpul, 4);

    vf3_native_aim a = setup_native(xm);
    const int rc = vf3_native_matrix_invert_scaled(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    {
        float nf; uint32_t nbits = a.fpul; memcpy(&nf, &nbits, 4);
        if (fabsf(nf - gf) > TOL && a.fpul != gfpul) {
            if (bad < 10) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul);
            bad++;
        }
    }

    printf("  matrix_invert_scaled: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    free(gwin[0].data);
    return bad ? 1 : 0;
}

int main(void)
{
    /* distinct axis lengths + a translation, so the normalisation and the
     * dot-derived translation are exercised */
    static const float M1[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,        /* col0 */
        0.2f, 0.9f, -0.3f, 0.1f,            /* col1 */
        -0.5f, 0.0f, 0.8660254f, 0.0f,      /* col2 */
        1.5f, 2.5f, -0.5f, 1.0f,            /* t */
    };
    /* a pure rotation, scale 2 on the axes, small translation */
    static const float M2[16] = {
        1.0f, 0.0f,  0.0f, 0.0f,
        0.0f, 2.0f,  0.0f, 0.0f,
        0.0f, 0.0f, -1.0f, 0.0f,
        3.0f, 4.0f,  5.0f, 1.0f,
    };
    /* identity with zero translation */
    static const float MI[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    /* non-orthonormal, scaled axes with non-zero w elements, so the length,
     * normalise and inverse-mutation paths are observably exercised */
    static const float M3[16] = {
        2.0f, 0.5f, 0.0f, 0.3f,          /* col0: |c0|^2 = 4.25, w = 0.3 */
        0.0f, 1.5f, 0.2f, 0.0f,          /* col1: |c1|^2 = 2.29 */
        0.1f, 0.0f, 2.0f, 0.4f,          /* col2: |c2|^2 = 4.01, w = 0.4 */
        1.0f, 2.0f, 3.0f, 1.0f,          /* t */
    };

    int bad = 0;
    bad |= run_case("general", M1);
    bad |= run_case("scale+translation", M2);
    bad |= run_case("identity", MI);
    bad |= run_case("scaled-nonortho", M3);

    printf("matrix_invert_scaled_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
