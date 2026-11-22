/* Differential replay of the native pass_prep (src/native/pass_prep.c,
 * 0x8C09DBC0) against the readable guest port (src/fight/pass_prep.c,
 * `vf3_pass_prep_entry`).
 *
 * pass_prep is a format_int-pattern sequencer: it pushes the current XMTRX,
 * inverts it rigidly, transforms the point at r4 through the inverse into r5,
 * and pops the stack back - a full round trip whose only lasting RAM effect,
 * beyond the transformed point, is the matrix-stack control block (the native
 * push/pop carry it in the flat RAM, so it is comparable too).
 *
 * Both sides seed the same flat RAM (the source/dest points, the frame, the
 * matrix-stack control block at 0x0C19D2E4) and the same XMTRX, then run.
 * The caller-visible output ranges (the two points, the frame, and the
 * control block) plus the final XMTRX are compared.  The residual is the FPU
 * difference (fsca/fsrra/ftrv against libm), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "pass_prep.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pass_prep_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define SRC     0x0C205000u      /* arg0: the source point (three floats) */
#define DST     0x0C206000u      /* arg1: the destination (three floats) */
#define SP      0x0C20FF00u

#define STK_CTL 0x0C19D2E4u      /* the matrix-stack control block */

static float *ram;

static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}
static float w32read_f(uint32_t addr)
{
    uint8_t *p = (uint8_t *)at(addr);
    uint32_t u = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                 ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    float f; memcpy(&f, &u, 4); return f;
}
static uint32_t membits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

/* seed the matrix stack control block exactly the way the pose family does */
static void seed_stack(void)
{
    w32(STK_CTL + 0u, (16u << 16) | 1u);   /* {limit, count} = {16, 1} */
    w32(STK_CTL + 4u, 0x0C19D400u);        /* base */
    w32(STK_CTL + 8u, 0x0C19D440u);        /* top */
}

static void seed(const float s[3])
{
    memset(at(0x0C200000u), 0, 0x4000);   /* clear the fixture region */
    seed_stack();
    wf(SRC + 0u, s[0]); wf(SRC + 4u, s[1]); wf(SRC + 8u, s[2]);
    wf(DST + 0u, 0.0f); wf(DST + 4u, 0.0f); wf(DST + 8u, 0.0f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t regs[16], const float xm[16])
{
    memset(s, 0, sizeof *s);
    for (int i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[16] = 0x0C0ABCDEu;        /* pr */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[37 + i] = bits;       /* XF0..XF15 = XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const uint32_t regs[16], const float xm[16])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    return a;
}

static const char *load_image(void)
{
    static const char path[] = "extract/exe/1ST_READ.unsc.bin";
    FILE *f = fopen(path, "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); return "image short"; }
    fclose(f);
    return NULL;
}

static int run_case(const char *label, const uint32_t regs[16], const float xm[16],
                    const float s[3])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed(s);
    setup_guest(&gs, &gmap, gwin, regs, xm);
    const int ok = vf3_pass_prep_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }

    /* snapshot the caller-visible output words before the native runs */
    float *gsaved = (float *)malloc(RAM_SIZE);
    if (!gsaved) return 2;
    memcpy(gsaved, ram, RAM_SIZE);
    uint32_t gsr = gs.v[17];
    uint32_t gr15 = gs.v[15], gpr = gs.v[16];
    const float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u; memcpy(&u, &gs.v[37 + i], 4); memcpy(&gxm[i], &u, 4); }

    seed(s);
    vf3_native_aim a = setup_native(regs, xm);
    vf3_native_pass_prep(&a);

    /* compare the destination point (the observable transform result) */
    for (int k = 0; k < 3; ++k) {
        float g, n;
        memcpy(&g, (uint8_t *)gsaved + (DST - RAM_BASE) + 4u * (uint32_t)k, 4);
        memcpy(&n, at(DST + 4u * (uint32_t)k), 4);
        if (fabsf(g - n) > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
            if (bad < 10)
                fprintf(stderr, "  dst[%d]: native %.7g guest %.7g\n", k, n, g);
            bad++;
        }
    }

    /* the matrix-stack control block and the pushed matrix round trip */
    for (uint32_t a0 = STK_CTL; a0 < STK_CTL + 0x80; a0 += 4) {
        uint32_t g, n;
        memcpy(&g, (uint8_t *)gsaved + (a0 - RAM_BASE), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            if (bad < 10)
                fprintf(stderr, "  stk @%08x: native %08x guest %08x\n",
                        a0, n, g);
            bad++;
        }
    }

    /* the frame (the arguments the guest parked under sp0) */
    for (uint32_t a0 = SP - 80u; a0 < SP + 16u; a0 += 4) {
        uint32_t g, n;
        memcpy(&g, (uint8_t *)gsaved + (a0 - RAM_BASE), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            if (bad < 10)
                fprintf(stderr, "  frame @%08x: native %08x guest %08x\n",
                        a0, n, g);
            bad++;
        }
    }

    free(gsaved);

    /* the final XMTRX (must be restored to the entry value) */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > 2.0e-3f) {
            if (bad < 20)
                fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }

    /* the return contract: r15, pr restored */
    if (a.r[15] != gr15) {
        if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15);
        bad++;
    }
    if (a.pr != gpr) {
        if (bad < 10) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gpr);
        bad++;
    }
    /* SR's T bit must be preserved by the caller-visible contract */
    if ((a.sr & 1u) != (gsr & 1u)) {
        if (bad < 10) fprintf(stderr, "  sr.T: native %u guest %u\n", a.sr & 1u, gsr & 1u);
        bad++;
    }

    printf("  pass_prep: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    const char *err = load_image();
    if (err) { printf("pass_prep_native_replay: skipped (%s)\n", err); free(ram); return 0; }

    uint32_t regs[16] = { 0 };
    regs[4] = SRC;
    regs[5] = DST;
    regs[15] = SP;

    static const float MX[16] = {
        0.8660254f, 0.0f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };

    int bad = 0;
    { const float s[3] = { 1.0f, 2.0f, -3.0f }; bad |= run_case("c0", regs, MX, s); }
    { const float s[3] = { -4.0f, 0.5f, 8.25f }; bad |= run_case("c1", regs, MX, s); }
    { const float s[3] = { 0.0f, 0.0f, 0.0f }; bad |= run_case("c2 origin", regs, MX, s); }
    { const float s[3] = { 100.0f, -50.0f, 25.0f }; bad |= run_case("c3", regs, MX, s); }

    free(ram);
    printf("pass_prep_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
