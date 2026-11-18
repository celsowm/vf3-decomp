#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"
#include "pose_orchestration.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for the pose orchestration driver (0x8C09EAF2) */
int vf3_pose_orchestration_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

/* The actor + work region.  The actor's fields reach obj+0x420C, the pose
 * blocks at +0x200/+0x300/+0x480/+0x540, the arg struct (r12) at 0x0C20A000
 * and the code block (r11) at 0x0C209000 all live inside this span. */
#define REGION_BASE 0x0C200000u
#define REGION_END  0x0C20F000u

#define OBJ       0x0C204000u   /* the actor (r14) */
#define ARG       0x0C20A000u   /* the caller's arg struct (r12 / r5) */
#define CODEBLK   0x0C209000u   /* the code block the kind-12 entry points at (r11) */
#define CODEBLK2  0x0C20B000u   /* the code block the selector entries point at (r11) */
#define SP        0x0C20FF00u   /* the entry stack pointer (r15) */

/* image-region tables the driver reads at run time (overridden by the seed) */
#define KIND_REC  0x0C10D3C4u   /* + kind * 108 is the kind record (r13) */
#define KIND_TAB2 0x0C10DABCu   /* the code table behind the pool */
#define STACK_CTL 0x0C19D2E4u   /* the matrix-stack control block (guest only) */
#define STAGE_WORD 0x0C29BCCCu

#define MACL 0x0DEADBEEFu

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
static void w8(uint32_t addr, uint8_t v) { ((uint8_t *)at(addr))[0] = v; }
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}
static uint32_t membits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

/* the matrix-stack control block the guest's push/pop helpers go through.  The
 * native callees carry the matrix stack in the `a` context (a->stk), so this
 * RAM block is seeded for the guest but never compared. */
static void seed_stack_ctl(void)
{
    w32(STACK_CTL, (16u << 16) | 1u);
    w32(STACK_CTL + 4u, 0x0C19D400u);
    w32(STACK_CTL + 8u, 0x0C19D440u);
    w32(STAGE_WORD, 0);
}

/* the entry XMTRX: a rotation with a translation (as the other native tests) */
static const float MX[16] = {
    0.8660254f, 0.0f, -0.5f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, 0.0f, 0.8660254f, 0.0f,
    1.5f, 2.5f, -0.5f, 1.0f,
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t regs[16], const float xm[16])
{
    memset(s, 0, sizeof *s);
    for (int i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[16] = 0x0C0ABCDEu;        /* pr */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr, single precision */
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
    a.ram = ram; a.ram_base = RAM_BASE; a.f = SP;
    memcpy(a.xm, xm, sizeof a.xm);
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    return a;
}

static int run_case(const char *label,
                    int (*guest)(vf3_matrix_state *, const vf3_ram_map *),
                    void (*nativ)(vf3_native_aim *),
                    void (*seed)(void),
                    const uint32_t (*ranges)[2], int nrange,
                    const uint32_t regs[16], const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed();
    setup_guest(&gs, &gmap, gwin, regs, xm);
    const int ok = guest(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    uint32_t span_lo = 0xFFFFFFFFu, span_hi = 0;
    for (int i = 0; i < nrange; ++i) {
        if (ranges[i][0] < span_lo) span_lo = ranges[i][0];
        if (ranges[i][1] > span_hi) span_hi = ranges[i][1];
    }
    uint8_t *gblob = (uint8_t *)malloc(span_hi - span_lo);
    memcpy(gblob, (const uint8_t *)at(span_lo), span_hi - span_lo);
    const float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u; memcpy(&u, &gs.v[37 + i], 4); memcpy(&gxm[i], &u, 4); }

    {
        seed();
        vf3_native_aim a = setup_native(regs, xm);
        nativ(&a);
        /* compare only the declared caller-visible ranges */
        for (int r = 0; r < nrange; ++r)
        for (uint32_t a0 = ranges[r][0]; a0 < ranges[r][1]; a0 += 4) {
            float g, n;
            memcpy(&g, gblob + (a0 - span_lo), 4);
            memcpy(&n, at(a0), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0) {
                    if (bad < 10)
                        fprintf(stderr, "  ram @%08x: got %08x want %08x (non-finite)\n",
                                a0, membits(n), membits(g));
                    bad++;
                }
                continue;
            }
            if (fabsf(g - n) > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
                if (bad < 10)
                    fprintf(stderr, "  ram @%08x: got %.7g want %.7g\n",
                            a0, n, g);
                bad++;
            }
        }
        /* compare the final XMTRX */
        for (int i = 0; i < 16; ++i) {
            if (fabsf(a.xm[i] - gxm[i]) > 2.0e-3f) {
                if (bad < 20)
                    fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
                bad++;
            }
        }
        /* compare the restored caller registers: the epilogue recovers r8..r14,
         * pr and r15 (and macl) from the stack above the frame, so a shift in
         * the exit offset moves every one of them.  The saved-reg words are
         * caller-pushed, so compare them as raw words. */
        if (a.r[15] != gs.v[15]) {
            if (bad < 30)
                fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]);
            bad++;
        }
        if (a.pr != gs.v[16]) {
            if (bad < 30)
                fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
            bad++;
        }
        for (int i = 8; i <= 14; ++i) {
            if (a.r[i] != gs.v[i]) {
                if (bad < 30)
                    fprintf(stderr, "  r%d: native %08x guest %08x\n",
                            i, a.r[i], gs.v[i]);
                bad++;
            }
        }
        printf("  region: %s\n", bad ? "DIFFERS" : "match");
    }
    free(gblob);
    return bad ? 1 : 0;
}

/* ---- fixture ----
 * Seeds the actor (OBJ), the code block (CODEBLK), the kind record at
 * KIND_REC+kind*108, the tab2 code table, the arg struct and the stack, then
 * runs the driver on both sides and compares the actor/work region, the
 * driver's frame+stack and the final XMTRX. */

static void seed_region(void)
{
    for (uint32_t a = REGION_BASE; a < REGION_END; a += 4)
        w32(a, 0x3F800000u ^ (a & 0x7FF));
}

static void seed_common(uint8_t kind, uint8_t sel)
{
    seed_region();
    seed_stack_ctl();

    /* the actor control fields the driver reads */
    w8(OBJ + 97u, kind);                 /* the kind index */
    w8(OBJ + 0x420Bu, sel);              /* the code-block selector */
    w16(OBJ + 30u, 0x0600u);             /* yaw (root_orientation) */
    w16(OBJ + 0x1F50u, 0x1000u);         /* root fields[0] Rz */
    w16(OBJ + 0x1F52u, 0x2000u);         /* root fields[1] Ry */
    w16(OBJ + 0x1F54u, 0x3000u);         /* root fields[2] Rx */
    w16(OBJ + 0x22E4u, 0x1234u);         /* halfword_frame arg */
    wf(OBJ + 0x1EFCu, 1.0f); wf(OBJ + 0x1F00u, 2.0f); wf(OBJ + 0x1F04u, 3.0f); /* set_translation src */
    wf(OBJ + 0x208Cu, 1.5f); wf(OBJ + 0x1F08u, -0.5f);   /* sum #1 */
    wf(OBJ + 0x2090u, 2.5f); wf(OBJ + 0x1F0Cu, 0.5f);    /* sum #2 */
    wf(OBJ + 0x2094u, 3.5f); wf(OBJ + 0x1F10u, -1.0f);   /* sum #3 */
    wf(OBJ + 0x20B4u, 1.25f);            /* aim_b#1 fr4 */
    wf(OBJ + 0x20C0u, -0.75f);           /* aim_b#2 fr4 */
    w16(OBJ + 0x22E8u, 0x0A00u);         /* aim_b#1 D3 -> re-stored to +0x22E6 */
    w16(OBJ + 0x22EAu, 0x0B00u);         /* aim_b#2 E5 -> re-stored to +0x22E6 */
    /* the face fields the aim builders read (actor records at +0xCC etc.) */
    wf(OBJ + 0xCCu + 0, 0.1f); wf(OBJ + 0xCCu + 8, 4.0f);
    wf(OBJ + 0xCCu + 16, 0.2f); wf(OBJ + 0xCCu + 24, 5.0f);
    wf(OBJ + 0xFCu + 0, 0.3f); wf(OBJ + 0xFCu + 8, 6.0f);
    wf(OBJ + 0xFCu + 16, 0.4f); wf(OBJ + 0xFCu + 24, 7.0f);
    wf(OBJ + 0x138u + 0, 0.5f); wf(OBJ + 0x138u + 8, 8.0f);
    wf(OBJ + 0x138u + 16, 0.6f); wf(OBJ + 0x138u + 24, 9.0f);
    wf(OBJ + 0x15Cu + 0, 0.7f); wf(OBJ + 0x15Cu + 8, 10.0f);
    wf(OBJ + 0x15Cu + 16, 0.8f); wf(OBJ + 0x15Cu + 24, 11.0f);

    /* the code block (r11): the facing target at +0, the aim builders' object
     * and object7 data at +4/+24/+44/+60 */
    wf(CODEBLK + 0, 1.0f); wf(CODEBLK + 4, 2.0f); wf(CODEBLK + 8, -3.0f);
    wf(CODEBLK + 12, 0.9f); wf(CODEBLK + 16, 1.1f); wf(CODEBLK + 20, 1.2f);
    wf(CODEBLK + 24, 2.0f); wf(CODEBLK + 28, -2.0f); wf(CODEBLK + 32, 0.5f);
    wf(CODEBLK + 36, 3.0f); wf(CODEBLK + 40, -3.0f); wf(CODEBLK + 44, 0.25f);
    wf(CODEBLK + 48, 4.0f); wf(CODEBLK + 52, -4.0f); wf(CODEBLK + 56, 0.125f);
    wf(CODEBLK + 60, 5.0f); wf(CODEBLK + 64, -5.0f); wf(CODEBLK + 68, 0.0625f);
    /* the second code block: deliberately different values so the kind-12
     * branch (which reads tab2+8) is distinguishable from the selector path */
    wf(CODEBLK2 + 0, 9.0f); wf(CODEBLK2 + 4, 8.0f); wf(CODEBLK2 + 8, -7.0f);
    wf(CODEBLK2 + 12, 7.0f); wf(CODEBLK2 + 16, 6.0f); wf(CODEBLK2 + 20, 5.0f);
    wf(CODEBLK2 + 24, 4.0f); wf(CODEBLK2 + 28, -4.0f); wf(CODEBLK2 + 32, 0.75f);
    wf(CODEBLK2 + 36, 3.0f); wf(CODEBLK2 + 40, -3.0f); wf(CODEBLK2 + 44, 0.875f);
    wf(CODEBLK2 + 48, 2.0f); wf(CODEBLK2 + 52, -2.0f); wf(CODEBLK2 + 56, 0.9375f);
    wf(CODEBLK2 + 60, 1.0f); wf(CODEBLK2 + 64, -1.0f); wf(CODEBLK2 + 68, 0.96875f);

    /* the tab2 code table: the kind-12 entry (at +8) points at CODEBLK, every
     * other selector points at CODEBLK2, so the kind==12 branch is observable */
    for (int i = 0; i < 16; ++i) {
        const uint32_t off = 4u * (uint32_t)i;
        w32(KIND_TAB2 + off, CODEBLK2);
    }
    w32(KIND_TAB2 + 8u, CODEBLK);

    /* the kind record at KIND_REC + kind*108: the kind floats the driver and
     * the aim builders read at +0/+4/+8/+12/+16/+20/+24 and +36/+48/+52/+56
     * and +60/+84 */
    {
        const uint32_t kr = KIND_REC + 108u * (uint32_t)kind;
        const float kf[13] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f,
                               0.8f, 0.9f, 1.0f, 1.1f, 1.2f, 1.3f };
        for (int i = 0; i < 7; ++i) wf(kr + 4u * (uint32_t)i, kf[i]);
        wf(kr + 36u, kf[7]); wf(kr + 48u, kf[8]); wf(kr + 52u, kf[9]);
        wf(kr + 56u, kf[10]); wf(kr + 60u, kf[11]); wf(kr + 84u, kf[12]);
    }

    /* the arg struct (r12): the driver writes xform results into it at +0,
     * +12, +24 and +0x9C, and reads +36/+96/+0xA8/+0xFC as pushes */
    wf(ARG + 0, 0.0f); wf(ARG + 12, 0.0f); wf(ARG + 24, 0.0f);
    wf(ARG + 0x9Cu, 0.0f);
    wf(ARG + 36, 100.0f); wf(ARG + 96, 200.0f);
    wf(ARG + 0xA8u, 300.0f); wf(ARG + 0xFCu, 400.0f);

    /* macl rides in the stack slot sp0-8 */
    w32(SP - 8u, MACL);
}

static void seed_k3(void)  { seed_common(3, 3); }        /* sel 3 -> tab2+12 = CODEBLK2 */
static void seed_k12(void) { seed_common(12, 0); }   /* the kind==12 code branch */
static void seed_k21(void) { seed_common(21, 5); }
static void seed_k0(void)  { seed_common(0, 1); }

static void pose_native(vf3_native_aim *a)
{ vf3_native_pose_orchestration(a, SP, OBJ, ARG); }
static int pose_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[15] = SP; s->v[14] = OBJ; s->v[5] = ARG;
    s->v[19] = MACL;               /* macl */
    return vf3_pose_orchestration_entry(s, r);
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    /* load the image so the callee-side literal pools and the tables resolve */
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { fprintf(stderr, "image absent\n"); return 2; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
            fprintf(stderr, "image short\n"); return 2;
        }
        fclose(f);
    }

    uint32_t regs[16] = { 0 };

    /* Range 1 = the actor / work region; Range 2 = the driver frame + stack.
     * The sub-callee scratch below the deepest pushed words (sp - 324) is left
     * out, as the aimframe test does. */
    static const uint32_t sp_r[2][2] = {
        { REGION_BASE, REGION_END },
        { SP - 324u, SP + 32u },
    };

    int bad = 0;
    bad |= run_case("pose kind 3", pose_guest, pose_native, seed_k3, sp_r, 2, regs, MX);
    bad |= run_case("pose kind 12 (code branch)", pose_guest, pose_native, seed_k12, sp_r, 2, regs, MX);
    bad |= run_case("pose kind 21", pose_guest, pose_native, seed_k21, sp_r, 2, regs, MX);
    bad |= run_case("pose kind 0", pose_guest, pose_native, seed_k0, sp_r, 2, regs, MX);

    free(ram);
    printf("pose_orchestration_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
