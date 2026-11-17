/* Differential replay of the four native pose-orchestration callees
 * (src/native/pose_callees.c files) against the readable guest ports:
 *   0x8C09D4B0 halfword_frame   (src/fight/halfword_frame.c)
 *   0x8C09E428 aim_midpoints    (src/fight/readable/aim_midpoints.c)
 *   0x8C09E4C8 matrix_basis     (src/fight/matrix_basis.c)
 *   0x8C09DCDC facing_update    (src/fight/facing_update.c)
 *
 * Both sides run on the same flat matrix RAM: the guest through its ram map,
 * the native port through `ram_base`.  Each fixture lays out the function's
 * argument objects / frames and the entry XMTRX / FR, then both sides run and
 * the whole actor region plus the final XMTRX are compared.
 *
 * The guest ports are the authority (they were promoted against the oracle);
 * the native port is a re-implementation, so the residual is the FPU
 * difference (fsca/fsrra/ftrv against libm), tolerated at 2e-3.  The guest's
 * matrix push/pop writes to the external matrix stack (0x0C19D400), which the
 * native keeps in its own struct, so that region is outside the compared
 * actor region. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_halfword_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_aim_midpoints_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_basis_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_facing_update_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u           /* must reach KIND_CELL 0x0C29BB84 */
#define REGION_BASE 0x0C200000u
#define REGION_SIZE 0x10000u

#define OBJ     0x0C201000u      /* halfword_frame object */
#define ACTOR   0x0C202000u      /* aim_midpoints actor */
#define CPTR    0x0C203000u      /* aim_midpoints caller pointer */
#define RECORD  0x0C204000u      /* matrix_basis record */
#define BLOCK   0x0C205000u      /* matrix_basis block */
#define CHARACTER 0x0C206000u    /* facing_update character */
#define TARGET  0x0C207000u      /* facing_update target point */
#define PARTTBL 0x0C209000u      /* the part table r11 points into */
#define SP      0x0C20FF00u

#define KIND_CELL 0x0C29BB84u    /* absolute, outside the compared region */

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
static void w8(uint32_t addr, uint8_t v) { ((uint8_t *)at(addr))[0] = v; }
static uint32_t w32read(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint32_t membits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static void seed_region(void)
{
    for (uint32_t a = REGION_BASE; a < REGION_BASE + REGION_SIZE; a += 4)
        w32(a, 0x3F800000u ^ (a & 0x7FF));
    /* the matrix stack the guest push/pop go through */
    w32(0x0C19D2E4u, (16u << 16) | 1u);
    w32(0x0C19D2E8u, 0x0C19D400u);
    w32(0x0C19D2ECu, 0x0C19D440u);
}

/* the entry XMTRX most fixtures use: a rotation with a translation */
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
    a.ram = ram; a.ram_base = RAM_BASE; a.f = SP;
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

/* run one case: guest vs native over the same fresh seed.  Compares the
 * caller-visible output ranges (the object / record / character regions and
 * each callee's own frame) plus the final XMTRX.  The sub-callee scratch
 * below the frame is deliberately excluded, as the aimframe test does. */
static uint32_t case_regions[8][2];
static int case_nregions;

static int in_region(uint32_t addr)
{
    for (int i = 0; i < case_nregions; ++i)
        if (addr >= case_regions[i][0] && addr < case_regions[i][1])
            return 1;
    return 0;
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
    for (int i = 0; i < nrange; ++i) {
        case_regions[i][0] = ranges[i][0];
        case_regions[i][1] = ranges[i][1];
    }
    case_nregions = nrange;
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

    setup_nexus:
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
        if (bad)
            fprintf(stderr, "  region: DIFFERS (%d)\n", bad);
        else
            printf("  region: match\n");
    }
    free(gblob);
    return bad ? 1 : 0;
}

/* ---- halfword_frame fixtures ---- */
static void seed_hf(uint16_t a, uint16_t b, uint16_t c, uint16_t arg)
{
    seed_region();
    w16(OBJ + 0, a); w16(OBJ + 2, b); w16(OBJ + 4, c);
    (void)arg;
}
static void seed_hf0(void) { seed_hf(0x1000u, 0x2000u, 0x3000u, 0x1234u); }
static void seed_hf1(void) { seed_hf(0x8000u, 0x9000u, 0x4000u, 0xF000u); }
static void hf_native0(vf3_native_aim *a) { vf3_native_halfword_frame(a, SP, OBJ, 0x1234u); }
static void hf_native1(vf3_native_aim *a) { vf3_native_halfword_frame(a, SP, OBJ, 0xF000u); }
static int hf_guest0(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = OBJ; s->v[5] = 0x1234u; s->v[15] = SP;
    return vf3_halfword_frame_entry(s, r);
}
static int hf_guest1(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = OBJ; s->v[5] = 0xF000u; s->v[15] = SP;
    return vf3_halfword_frame_entry(s, r);
}

/* ---- aim_midpoints fixture ---- */
static void seed_am(void)
{
    seed_region();
    /* the three midpoints read the halfword pairs (second, first):
     *   +8  mid(0x1F86, 0x1F56), +12 mid(0x1F88, 0x1F58), +4 mid(0x1F8A, 0x1F5A)
     * The difference first-second is computed as u16-u16 then re-sign-extended
     * from 16 bits, so a difference with the top bit set (>= 0x8000) is where
     * the (int16_t) reinterpretation of the difference matters.  Give the
     * first pair a wrapping difference (0xFFFF - 0x0010) to reach it; keep the
     * other two ordinary. */
    w16(ACTOR + 0x1F86u, 0x0010u);
    w16(ACTOR + 0x1F56u, 0xFFFFu);
    w16(ACTOR + 0x1F88u, 0x1000u);
    w16(ACTOR + 0x1F58u, 0x2000u);
    /* the +4 pair is the swap boundary: mid(0, 0x8000) differs from
     * mid(0x8000, 0) by half a turn (0xC000 vs 0x4000), so swapping the
     * midpoint operands changes the rotated XMTRX far beyond the 2e-3
     * tolerance. */
    w16(ACTOR + 0x1F8Au, 0u);
    w16(ACTOR + 0x1F5Au, 0x8000u);
}
static void am_native(vf3_native_aim *a) { vf3_native_aim_midpoints(a, SP, ACTOR, CPTR); }
static int am_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = ACTOR; s->v[5] = CPTR; s->v[15] = SP;
    return vf3_aim_midpoints_entry(s, r);
}

/* ---- matrix_basis fixture ---- */
static void seed_mb(void)
{
    seed_region();
    w16(RECORD + 0x1F86u, 0x1111u); w16(RECORD + 0x1F88u, 0x2222u);
    w16(RECORD + 0x1F8Au, 0x3333u);
    w16(RECORD + 0x61u, 0x5A);
    w16(RECORD + 0x22BCu, 0x0A00u);
    w16(RECORD + 0x22BEu, 0x0600u);
}
static void mb_native(vf3_native_aim *a) { vf3_native_matrix_basis(a, SP, RECORD, BLOCK); }
static int mb_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = RECORD; s->v[5] = BLOCK; s->v[15] = SP;
    return vf3_matrix_basis_entry(s, r);
}

/* ---- facing_update fixture ---- */
static void seed_fu(void)
{
    seed_region();
    w32(CHARACTER + 0, 0x00100240u);        /* flags: mask 0x88836020 & +72 overrides */
    w8(CHARACTER + 4, 0);
    w8(CHARACTER + 0x61u, 11);
    w16(CHARACTER + 0x3Cu, 0x0200u);        /* kind halfword (not special) */
    wf(CHARACTER + 0x1F14u, 1.0f); wf(CHARACTER + 0x1F18u, 2.0f); wf(CHARACTER + 0x1F1Cu, 3.0f);
    wf(CHARACTER + 0x1FC8u, 0.0f); wf(CHARACTER + 0x1FCCu, 0.0f); wf(CHARACTER + 0x1FD0u, 0.5f);
    w32(CHARACTER + 0x1FD4u, 0x0500u);      /* heading */
    w32(CHARACTER + 0x1FD8u, 0x0000u);      /* pitch = 0 */
    wf(CHARACTER + 0xC0u, 0.5f);            /* blend weight */
    wf(CHARACTER + 0x1F5Cu, 0x0100u); wf(CHARACTER + 0x1F5Eu, 0x0200u); wf(CHARACTER + 0x1F60u, 0x0300u);
    w32(CHARACTER + 0x2308u, 0.5f);         /* the +0x2308 offset */
    w32(CHARACTER + 72u, 0x00000048u);      /* +72: mask 0x88836020 hits +0x48 */
    for (int i = 0; i < 3; ++i) wf(TARGET + 4u * (uint32_t)i, 1.0f);   /* target in front */
    /* the kind cell and part table */
    w32(KIND_CELL + 20u, PARTTBL);
    wf(PARTTBL + 0x1F0u, 0.5f); wf(PARTTBL + 0x1F4u, -0.5f); wf(PARTTBL + 0x1F8u, 0.25f);
    /* style byte +0x61 (== obj+97) = 11: it selects the turn-table row
     * (TURN_TABLE + 11<<1 = TURN+22 = 0x0000, whose +2 neighbour TURN+24 =
     * 0x0400).  At pitch = 0 the local pitch angle is small (atan_pitch =
     * 0x15b), so -atan_pitch = -0x15b is just inside the ±0x100 pitch clamp;
     * the mutation that reads the +2 neighbour instead adds 0x0400 and pushes
     * r5 to +0x2a5, which clamps to +0x100 - a different result. */
}
static void fu_native(vf3_native_aim *a) { vf3_native_facing_update(a, SP, CHARACTER, TARGET); }
static int fu_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = CHARACTER; s->v[5] = TARGET; s->v[15] = SP;
    return vf3_facing_update_entry(s, r);
}

/* ---- facing_update, phase-1 y-override path (r13 != 0) ---- */
static void seed_fu2(void)
{
    seed_region();
    /* 0x240: FLAG_400 (0x400) clear and FLAG_100 (0x100) clear, so the
     * mixed-position branch runs; the +72 word 0x20 hits the mask
     * (0x88836020 & 0x20 = 0x20), so r13 != 0 and the y-override path adds
     * the +0x2308 offset to p84.y. */
    w32(CHARACTER + 0, 0x00000240u);
    w8(CHARACTER + 4, 0);
    w8(CHARACTER + 0x61u, 3);
    w16(CHARACTER + 0x3Cu, 0x0200u);        /* kind halfword (not special) */
    wf(CHARACTER + 0x1F14u, 1.0f); wf(CHARACTER + 0x1F18u, 2.0f); wf(CHARACTER + 0x1F1Cu, 3.0f);
    wf(CHARACTER + 0x1FC8u, 10.0f); wf(CHARACTER + 0x1FCCu, 11.0f); wf(CHARACTER + 0x1FD0u, -1000.0f);
    w32(CHARACTER + 0x1FD4u, 0x0500u);      /* heading */
    w32(CHARACTER + 0x1FD8u, 0x0200u);      /* pitch */
    wf(CHARACTER + 0xC0u, 0.5f);            /* blend weight */
    wf(CHARACTER + 0x1F5Cu, 0x0100u); wf(CHARACTER + 0x1F5Eu, 0x0200u); wf(CHARACTER + 0x1F60u, 0x0300u);
    wf(CHARACTER + 0x2308u, 7.0f);         /* the +0x2308 offset (y-override) */
    wf(CHARACTER + 0x2304u, 3.0f);         /* the +0x2304 neighbour (must NOT be used) */
    w32(CHARACTER + 72u, 0x00000020u);      /* +72: mask 0x88836020 hits 0x20 -> r13 != 0 */
    for (int i = 0; i < 3; ++i) wf(TARGET + 4u * (uint32_t)i, 1.0f);
    w32(KIND_CELL + 20u, PARTTBL);
    wf(PARTTBL + 0x1F0u, 0.5f); wf(PARTTBL + 0x1F4u, -0.5f); wf(PARTTBL + 0x1F8u, 0.25f);
}
static void fu2_native(vf3_native_aim *a) { vf3_native_facing_update(a, SP, CHARACTER, TARGET); }
static int fu2_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = CHARACTER; s->v[5] = TARGET; s->v[15] = SP;
    return vf3_facing_update_entry(s, r);
}

/* ---- facing_update, special-kind path (kind 0x886) ---- */
static void seed_fu3(void)
{
    seed_region();
    /* same shape as seed_fu2 (r13 != 0 through +72 = 0x20, so the outer
     * heading/pitch clamps are skipped) but the kind halfword is the special
     * 0x886, so the `if (!special)` heading/pitch limits MUST be skipped.  A
     * mutation that stops recognising 0x886 takes the non-special branch and
     * clamps, which changes the committed matrix. */
    w32(CHARACTER + 0, 0x00000240u);
    w8(CHARACTER + 4, 0);
    w8(CHARACTER + 0x61u, 3);
    w16(CHARACTER + 0x3Cu, 0x0886u);        /* kind halfword (SPECIAL) */
    wf(CHARACTER + 0x1F14u, -1000.0f); wf(CHARACTER + 0x1F18u, -7.0f); wf(CHARACTER + 0x1F1Cu, 0.0f);
    wf(CHARACTER + 0x1FC8u, 10.0f); wf(CHARACTER + 0x1FCCu, 11.0f); wf(CHARACTER + 0x1FD0u, -1000.0f);
    w32(CHARACTER + 0x1FD4u, 0x0100u);      /* heading (small, inside clamp) */
    w32(CHARACTER + 0x1FD8u, 0x0100u);      /* pitch */
    wf(CHARACTER + 0xC0u, 0.5f);            /* blend weight */
    wf(CHARACTER + 0x1F5Cu, 0x0100u); wf(CHARACTER + 0x1F5Eu, 0x0200u); wf(CHARACTER + 0x1F60u, 0x0300u);
    wf(CHARACTER + 0x2308u, 7.0f);
    wf(CHARACTER + 0x2304u, 3.0f);
    w32(CHARACTER + 72u, 0x00000020u);      /* +72: mask hits -> r13 != 0 */
    /* With r13 != 0 the mixed position becomes (anchor.x, anchor.y + 0x2308,
     * anchor.z) = (-1000, 0, 0), transformed into the local frame (only
     * target[0] feeds the XMTRX translation; fr5/fr6 = 0), so the local-frame
     * heading is near -0x8000 (atan = -0x7fe2).  A mutation that stops
     * recognising 0x886 takes the non-special branch, whose heading clamp
     * (lim = 0x3800) then bites on SExt16(atan + 0xC000) ~ +0x401e (above
     * 0x3800 => clamped), changing the committed heading. */
    wf(TARGET + 0u, 0.0f); wf(TARGET + 4u, 0.0f); wf(TARGET + 8u, 0.0f);
    w32(KIND_CELL + 20u, PARTTBL);
    wf(PARTTBL + 0x1F0u, 0.5f); wf(PARTTBL + 0x1F4u, -0.5f); wf(PARTTBL + 0x1F8u, 0.25f);
}
static void fu3_native(vf3_native_aim *a) { vf3_native_facing_update(a, SP, CHARACTER, TARGET); }
static int fu3_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{
    s->v[4] = CHARACTER; s->v[5] = TARGET; s->v[15] = SP;
    return vf3_facing_update_entry(s, r);
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    const char *err = load_image();
    if (err) { printf("native_pose_callees_replay: skipped (%s)\n", err); free(ram); return 0; }

    uint32_t regs[16] = { 0 };

    int bad = 0;

    /* Range 1 = all the object / record / character output regions (all below
     * 0x0C20D000); Range 2 = the callee's own frame f..sp.  The sub-callee
     * scratch below each frame is deliberately left out of the comparison. */
    static const uint32_t lo[2][2] = {
        { REGION_BASE, 0x0C20D000u },
    };
    static const uint32_t hf_r[2][2] = { { REGION_BASE, 0x0C20D000u },
                                         { SP - 20u, SP + 16u } };
    static const uint32_t am_r[2][2] = { { REGION_BASE, 0x0C20D000u },
                                         { SP - 24u, SP + 16u } };
    static const uint32_t mb_r[2][2] = { { REGION_BASE, 0x0C20D000u },
                                         { SP - 112u, SP + 16u } };
    static const uint32_t fu_r[2][2] = { { REGION_BASE, 0x0C20D000u },
                                         { SP - 220u, SP + 16u } };

    bad |= run_case("halfword_frame (0x8C09D4B0) c0", hf_guest0, hf_native0,
                    seed_hf0, hf_r, 2, regs, MX);
    bad |= run_case("halfword_frame (0x8C09D4B0) c1", hf_guest1, hf_native1,
                    seed_hf1, hf_r, 2, regs, MX);

    bad |= run_case("aim_midpoints (0x8C09E428)", am_guest, am_native,
                    seed_am, am_r, 2, regs, MX);

    bad |= run_case("matrix_basis (0x8C09E4C8)", mb_guest, mb_native,
                    seed_mb, mb_r, 2, regs, MX);

    bad |= run_case("facing_update (0x8C09DCDC)", fu_guest, fu_native,
                    seed_fu, fu_r, 2, regs, MX);
    bad |= run_case("facing_update (0x8C09DCDC) y-override", fu2_guest, fu2_native,
                    seed_fu2, fu_r, 2, regs, MX);
    bad |= run_case("facing_update (0x8C09DCDC) special-kind", fu3_guest, fu3_native,
                    seed_fu3, fu_r, 2, regs, MX);

    (void)lo;

    free(ram);
    printf("native_pose_callees_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}












