/* matrix_concat_save_native_replay.c - differential replay of the native
 * matrix_concat_save (0x8C03C140, src/native/matrix_concat_save.c,
 * `vf3_native_matrix_concat_save`) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_concat_save_entry`).
 *
 * matrix_concat_save is the sibling of matrix_concat (0x8C03C0E0), a member
 * of the same column-major family: XMTRX becomes XMTRX * M(r4), where M is
 * the 16 floats at r4 (each M column is the ftrv input).  The guest's
 * bank-swap emulation (frchg) puts the OLD XMTRX into fr[0..11] and toggles
 * FPSCR.FR.  The caller's FR12..FR15 are protected: all four saved words are
 * pushed (a 16-byte stack round trip) and put straight back into the new FR
 * bank from the saved registers -- so FPUL is untouched (unlike matrix_concat,
 * which parks fr12 in FPUL).  r4 advances by 64.
 *
 * Both sides seed the same flat RAM (M, the stack region), the same XMTRX and
 * the same FR12..FR15, then run.  The final XMTRX, fr[0..11] (old XMTRX),
 * fr[12..15] (preserved), FPUL (untouched), FPSCR.FR, the stack words, r4 and
 * r15 are compared.  The residual is the FPU difference (ftrv against the
 * native column-major multiply), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_concat_save.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_concat_save (0x8C03C140) */
int vf3_matrix_concat_save_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
/* and its parent (0x8C03C200): XMTRX = XMTRX * the matrix just below the
 * matrix stack top (*(0x0C19D2E4 + 8) - 64) */
int vf3_matrix_concat_parent_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

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

    /* M: a distinct rotation+translation */
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
    const uint32_t gfpul_in = gs.v[VF3_REG_FPUL] = 0xCAFEBABEu;  /* must survive */
    const int ok = vf3_matrix_concat_save_entry(&gs, &gmap);
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
    const uint32_t gfpul = gs.v[VF3_REG_FPUL], gfpscr = gs.v[VF3_REG_FPSCR];
    const uint32_t gr4 = gs.v[4], gr15 = gs.v[15];

    seed();
    vf3_native_aim a = setup_native(xm, fr1215);
    a.fpul = gfpul_in;
    /* clear the stack region so an unwritten slot reads as zero */
    memset(at(SP - 32u), 0, 32);
    const int rc = vf3_native_matrix_concat_save(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* final XMTRX = XMTRX * M */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* fr[0..11] = the OLD XMTRX */
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
    /* FPUL untouched, FPSCR.FR toggled */
    if (a.fpul != gfpul) { if (bad < 10) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); bad++; }
    if ((a.fpscr & 0x00200000u) != (gfpscr & 0x00200000u)) {
        if (bad < 10) fprintf(stderr, "  fpscr FR: native %08x guest %08x\n", a.fpscr, gfpscr);
        bad++;
    }
    /* r4/r15 */
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }

    /* the stack region (sp0-16..-4) holds FR15, FR14, FR13, FR12 (pushed:
     * saved[3]=FR15 at sp0-4 .. saved[0]=FR12 at sp0-16, so sp0-16+4*j holds
     * fr1215[j]) */
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
    printf("  matrix_concat_save: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

/* Parent (0x8C03C200): r4 is derived as the matrix stack top (*(0x0C19D2EC))
 * minus 64, then matrix_concat_save runs.  The M matrix is planted at
 * 0x0C200000 and the stack top is pointed just past it (so r4 = 0x0C200000). */
#define STACK_TOP_ADDR 0x0C19D2ECu

static int run_case_parent(const char *label, const float xm[16], const uint32_t fr1215[4])
{
    printf("== %s (parent)\n", label);
    fflush(stdout);
    int bad = 0;

    seed();
    w32(STACK_TOP_ADDR, MATRIX + 64u);   /* top - 64 = MATRIX */
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, fr1215);
    const int ok = vf3_matrix_concat_parent_entry(&gs, &gmap);
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
    const uint32_t gfpscr = gs.v[VF3_REG_FPSCR];
    const uint32_t gr4 = gs.v[4], gr15 = gs.v[15];

    seed();
    w32(STACK_TOP_ADDR, MATRIX + 64u);
    vf3_native_aim a = setup_native(xm, fr1215);
    memset(at(SP - 32u), 0, 32);
    const int rc = vf3_native_matrix_concat_parent(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* the derived r4 is MATRIX + 64, so the product uses M at 0x0C200000 */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    for (int i = 0; i < 12; ++i) {
        if (fabsf(a.fr[i] - gfr0[i]) > TOL && memcmp(&a.fr[i], &gfr0[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr0[i]);
            bad++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (memcmp(&a.fr[12 + i], &gfr1215[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %x guest %x\n", 12 + i,
                                  (unsigned)vf3_aim_ubits(a.fr[12 + i]), (unsigned)gfr1215[i]);
            bad++;
        }
    }
    if ((a.fpscr & 0x00200000u) != (gfpscr & 0x00200000u)) {
        if (bad < 10) fprintf(stderr, "  fpscr FR: native %08x guest %08x\n", a.fpscr, gfpscr);
        bad++;
    }
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }

    free(gblob);
    printf("  matrix_concat_parent: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { printf("matrix_concat_save_native_replay: skipped (image absent)\n"); free(ram); return 0; }
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
        /* zero XMTRX -> result is zero (old XMTRX in fr is zero) */
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

    /* parent derivation: the matrix below the stack top */
    bad |= run_case_parent("base", MX, f0);

    free(ram);
    printf("matrix_concat_save_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
