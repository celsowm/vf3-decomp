/* matrix_concat_pair_native_replay.c - differential replay of the native
 * matrix_concat_pair (0x8C03DD00, src/native/matrix_concat_pair.c,
 * `vf3_native_matrix_concat_pair`) against the readable guest port
 * (src/fight/matrix_concat_pair.c, `vf3_matrix_concat_pair_entry`).
 *
 * matrix_concat_pair is a self-contained FP leaf: XMTRX becomes XMTRX * A * B
 * where A is the 16 floats at the pointer held in [0x0C19D308 + 8] and B the
 * 16 floats at 0x0C19D518.  It leaves FR0..FR11 as B, round-trips FR12..FR15
 * through the stack (sp0-16..-4), and answers r4 = B + 32, r5 = B + 64.  The
 * SZ-bit guard (FPSCR & 0x100000) makes both sides return immediately.
 *
 * Both sides seed the same flat RAM (A and B, the FIRST_PTR pointer word, the
 * stack region), the same XMTRX and the same FR12..FR15, then run.  The final
 * XMTRX, FR0..FR11 (= B), FR12..FR15 (preserved), r4/r5, the stack region and
 * r15 are compared.  The residual is the FPU difference (ftrv against the
 * native column-major multiply), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_concat_pair.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for matrix_concat_pair (0x8C03DD00) */
int vf3_matrix_concat_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define FIRST_PTR 0x0C19D308u      /* [FIRST_PTR + 8] holds the A matrix ptr */
#define SECOND    0x0C19D518u      /* the B matrix lives here directly */
#define AMAT      0x0C205000u      /* where we put the A matrix */
#define SP        0x0C20FF00u

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
    memset(at(0x0C200000u), 0, 0x2000);     /* clear the fixture region */

    /* A: a rotation+translation, distinct from B and XMTRX */
    static const float A[16] = {
        0.70710678f, 0.0f, 0.70710678f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.70710678f, 0.0f, 0.70710678f, 0.0f,
        0.5f, -1.0f, 2.0f, 1.0f,
    };
    /* B: a scale about Z, distinct translation */
    static const float B[16] = {
        2.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 3.0f, 0.0f,
        0.25f, 0.75f, -0.5f, 1.0f,
    };
    for (int i = 0; i < 16; ++i) wf(AMAT + 4u * (uint32_t)i, A[i]);
    for (int i = 0; i < 16; ++i) wf(SECOND + 4u * (uint32_t)i, B[i]);
    w32(FIRST_PTR + 8u, AMAT);              /* [0x0C19D308 + 8] -> A */

    /* FR12..FR15 must be preserved; give them distinct sentinels */
    w32(FIRST_PTR + 0u, 0x12345678u);       /* neighbour, not read */
    w32(FIRST_PTR + 4u, 0x9ABCDEF0u);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], const uint32_t fr1215[4])
{
    memset(s, 0, sizeof *s);
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
    const int ok = vf3_matrix_concat_pair_entry(&gs, &gmap);
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
    const uint32_t gr4 = gs.v[4], gr5 = gs.v[5], gr15 = gs.v[15];

    seed();
    vf3_native_aim a = setup_native(xm, fr1215);
    const int rc = vf3_native_matrix_concat_pair(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    /* final XMTRX = XMTRX * A * B */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* FR0..FR11 = B */
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
    /* r4/r5/r15 */
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[5] != gr5) { if (bad < 10) fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gr5); bad++; }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }

    /* the stack region (sp0-16..-4) ends as the saved FR12..15 words */
    for (uint32_t a0 = SP - 16u; a0 < SP; a0 += 4) {
        uint32_t g, n;
        memcpy(&g, gblob + (a0 - 0x0C200000u), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            if (bad < 10) fprintf(stderr, "  stk @%08x: native %08x guest %08x\n", a0, n, g);
            bad++;
        }
    }

    free(gblob);
    printf("  matrix_concat_pair: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { printf("matrix_concat_pair_native_replay: skipped (image absent)\n"); free(ram); return 0; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); printf("skipped (image short)\n"); free(ram); return 0; }
        fclose(f);
    }

    static const float MX[16] = {
        0.8660254f, 0.0f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    uint32_t f0[4] = { 0x3F800000u, 0x40000000u, 0x40400000u, 0x40800000u };

    int bad = 0;
    bad |= run_case("base", MX, f0);
    {
        /* zero XMTRX -> result is just A*B (still a real product) */
        float Z[16]; memset(Z, 0, sizeof Z);
        bad |= run_case("zero XMTRX", Z, f0);
    }
    {
        /* identity XMTRX -> XMTRX*A*B */
        float I[16]; memset(I, 0, sizeof I);
        I[0] = I[5] = I[10] = I[15] = 1.0f;
        bad |= run_case("identity XMTRX", I, f0);
    }
    {
        /* all-ones FR12..15 sentinels, negative */
        uint32_t neg[4] = { 0xBF800000u, 0xC0000000u, 0xC0400000u, 0xC0800000u };
        bad |= run_case("negative FR sentinels", MX, neg);
    }

    /* the SZ-bit guard: both sides return without touching XMTRX */
    {
        static const float A_[16] = { 0 }; /* silence unused */
        (void)A_;
        printf("== SZ guard\n");
        seed();
        vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
        setup_guest(&gs, &gmap, gwin, MX, f0);
        gs.v[18] = 0x00100001u;             /* FPSCR.SZ set */
        if (vf3_matrix_concat_pair_entry(&gs, &gmap) != 0) {
            fprintf(stderr, "  guest SZ guard not taken\n"); bad++;
        }
        vf3_native_aim a = setup_native(MX, f0);
        a.fpscr = 0x00100001u;
        if (vf3_native_matrix_concat_pair(&a) != 0) {
            fprintf(stderr, "  native SZ guard not taken\n"); bad++;
        }
    }

    free(ram);
    printf("matrix_concat_pair_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
