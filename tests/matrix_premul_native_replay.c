/* matrix_premul_native_replay.c - differential replay of the native
 * matrix_premul (0x8C03C1C0, src/native/matrix_premul.c,
 * `vf3_native_matrix_premul`) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_premul_entry`).
 *
 * matrix_premul is a self-contained FP leaf: XMTRX becomes M(r4) * XMTRX,
 * where M is the 16 floats at r4 (each old XMTRX column is run through
 * ftrv(m, ...)).  FR0..FR11 end as the first twelve floats of M; FR12..FR15
 * travel through the stack (sp0-16..-4, in the order FR15, FR14, FR13, FR12)
 * and come back untouched.  r4 advances by 64; r15 and SR are untouched.
 *
 * Both sides seed the same flat RAM (M, the stack region), the same XMTRX
 * and the same FR12..FR15, then run.  The final XMTRX, FR0..FR11 (= first
 * 12 floats of M), FR12..FR15 (preserved), the stack region, r4 and r15 are
 * compared.  The residual is the FPU difference (ftrv against the native
 * column-major multiply), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_premul.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_premul (0x8C03C1C0) */
int vf3_matrix_premul_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define MATRIX 0x0C200000u      /* the matrix M at r4 */
#define SP     0x0C20FF00u

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }

static void seed(void)
{
    memset(at(0x0C200000u), 0, 0x1000);     /* clear the fixture region */

    /* M: a rotation+translation, distinct from XMTRX */
    static const float M[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        0.75f, -2.0f, 1.25f, 1.0f,
    };
    for (int i = 0; i < 16; ++i) wf(MATRIX + 4u * (uint32_t)i, M[i]);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], const uint32_t fr1215[4])
{
    memset(s, 0, sizeof *s);
    s->v[4] = MATRIX;
    s->v[15] = SP;
    s->v[16] = 0x0C0ABCDEu;                 /* pr */
    s->v[17] = 0x60000000u;                 /* sr, T clear */
    s->v[18] = 0x00040001u;                 /* fpscr, SZ clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;       /* XF0..XF15 = XMTRX */
    }
    for (int i = 0; i < 4; ++i)
        s->v[VF3_REG_FR0 + 12 + i] = fr1215[i];
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const float xm[16], const uint32_t fr1215[4])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    a.r[4] = MATRIX;
    a.r[15] = SP;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    for (int i = 0; i < 4; ++i) {
        uint32_t bits = fr1215[i];
        memcpy(&a.fr[12 + i], &bits, 4);
    }
    return a;
}

static int run_case(const char *label, const float xm[16], const uint32_t fr1215[4])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    seed();
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, fr1215);
    const int ok = vf3_matrix_premul_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    uint8_t *gblob = (uint8_t *)malloc(SP - 0x0C200000u);
    memcpy(gblob, (const uint8_t *)at(0x0C200000u), SP - 0x0C200000u);
    float gxm[16], gfr0[12], gfr1215[4];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    for (int i = 0; i < 12; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr0[i], &u, 4); }
    for (int i = 0; i < 4; ++i)  { uint32_t u = gs.v[VF3_REG_FR0 + 12 + i]; memcpy(&gfr1215[i], &u, 4); }
    const uint32_t gr4 = gs.v[4], gr15 = gs.v[15];

    seed();
    vf3_native_aim a = setup_native(xm, fr1215);
    /* clear the stack region so an unwritten slot reads as zero (a port that
     * fails to write a pushed word leaves a visible gap) */
    memset(at(SP - 32u), 0, 32);
    const int rc = vf3_native_matrix_premul(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* final XMTRX = M * XMTRX */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* FR0..FR11 = first twelve floats of M */
    for (int i = 0; i < 12; ++i) {
        if (fabsf(a.fr[i] - gfr0[i]) > TOL && memcmp(&a.fr[i], &gfr0[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr0[i]);
            bad++;
        }
    }
    /* FR12..FR15 preserved */
    for (int i = 0; i < 4; ++i) {
        if (memcmp(&a.fr[12 + i], &gfr1215[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %x guest %x\n", 12 + i,
                                  (unsigned)vf3_aim_ubits(a.fr[12 + i]), (unsigned)gfr1215[i]);
            bad++;
        }
    }
    /* r4/r15 */
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }

    /* the stack region (sp0-16..-4) ends as the pushed saved words: push_word
     * wrote FR15 at sp0-4, FR14 at sp0-8, FR13 at sp0-12, FR12 at sp0-16, so
     * saved[j] (j = 0..3 = FR12..FR15) sits at sp0-16 + 4*j.  Compare the
     * native stack bytes against the guest's, and against the saved words. */
    for (int j = 0; j < 4; ++j) {
        uint32_t a0 = SP - 16u + 4u * (uint32_t)j;
        uint32_t g, n;
        memcpy(&g, gblob + (a0 - 0x0C200000u), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            if (bad < 10) fprintf(stderr, "  stk @%08x: native %08x guest %08x\n", a0, n, g);
            bad++;
        } else if (memcmp(&n, &fr1215[j], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  stk @%08x value %08x != saved fr[%d] %08x\n",
                                  a0, n, 12 + j, fr1215[j]);
            bad++;
        }
    }

    free(gblob);
    printf("  matrix_premul: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { printf("matrix_premul_native_replay: skipped (image absent)\n"); free(ram); return 0; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); printf("skipped (image short)\n"); free(ram); return 0; }
        fclose(f);
    }

    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    uint32_t f0[4] = { 0x3F800000u, 0x40000000u, 0x40400000u, 0x40800000u };

    int bad = 0;
    bad |= run_case("base", MX, f0);
    {
        /* zero XMTRX -> result is all zero (M * 0) */
        float Z[16]; memset(Z, 0, sizeof Z);
        bad |= run_case("zero XMTRX", Z, f0);
    }
    {
        /* identity XMTRX -> result is M itself */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, f0);
    }
    {
        /* all-ones FR12..15 sentinels, negative */
        uint32_t neg[4] = { 0xBF800000u, 0xC0000000u, 0xC0400000u, 0xC0800000u };
        bad |= run_case("negative FR sentinels", MX, neg);
    }

    free(ram);
    printf("matrix_premul_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
