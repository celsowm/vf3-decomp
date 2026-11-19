#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for the point clamp (0x8C09F5F8) */
int vf3_point_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define PT    0x0C206000u   /* the three-float point (r4) */
#define SP    0x0C206100u   /* the entry stack pointer (r15) */
#define GATE  0x0C29B864u   /* the global that gates the body */

#define REGION_LO PT
#define REGION_HI (SP + 32u)

/* the wrapper's fr4..fr9 inputs, as the pose-post wrapper establishes them */
static const float FR_IN[6] = { 32768.0f, 16384.0f, -32768.0f,
                                24576.0f, 0.0f,     65536.0f };

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = PT;                     /* r4 */
    s->v[15] = SP;                    /* r15 */
    s->v[16] = 0x0C0ABCDEu;           /* pr */
    s->v[17] = 0x60000000u;           /* sr, T clear */
    s->v[18] = 0x00040001u;           /* fpscr, single precision */
    for (int i = 0; i < 6; ++i) {
        uint32_t bits; memcpy(&bits, &FR_IN[i], 4);
        s->v[25 + i] = bits;          /* FR4..FR9 = v[25..30] */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static void setup_native(vf3_native_aim *a)
{
    memset(a, 0, sizeof *a);
    a->ram = ram; a->ram_base = RAM_BASE; a->f = SP;
    a->r[4] = PT; a->r[15] = SP;
    a->pr = 0x0C0ABCDEu;
    a->sr = 0x60000000u; a->fpscr = 0x00040001u;
    for (int i = 0; i < 6; ++i) a->fr[4 + i] = FR_IN[i];
}

static void seed(float x, float y, float z, uint32_t gate)
{
    for (uint32_t a = REGION_LO; a < REGION_HI; a += 4)
        w32(a, 0xBEEF0000u ^ (a & 0x7FF));
    /* the scratch words under the frame must start as 0xbeef* so a store that
     * leaves them counts as a change */
    wf(PT + 0, x); wf(PT + 4, y); wf(PT + 8, z);
    w32(GATE, gate);
}

static int run_case(const char *label, float x, float y, float z, uint32_t gate)
{
    int bad = 0;
    printf("== %s\n", label);
    fflush(stdout);

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed(x, y, z, gate);
    setup_guest(&gs, &gmap, gwin);
    if (!vf3_point_wrap_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    uint8_t *gblob = (uint8_t *)malloc(REGION_HI - REGION_LO);
    memcpy(gblob, (const uint8_t *)at(REGION_LO), REGION_HI - REGION_LO);

    vf3_native_aim a;
    seed(x, y, z, gate);
    setup_native(&a);
    vf3_native_point_wrap(&a, SP, PT);

    /* strict byte-exact compare: the clamp/fold arithmetic is add/sub and
     * sign-mask on exactly representable floats */
    for (uint32_t a0 = REGION_LO; a0 < REGION_HI; a0 += 4) {
        float g, n;
        memcpy(&g, gblob + (a0 - REGION_LO), 4);
        memcpy(&n, at(a0), 4);
        if (memcmp(&g, &n, 4) != 0) {
            uint32_t ug, un; memcpy(&ug, &g, 4); memcpy(&un, &n, 4);
            if (bad < 10)
                fprintf(stderr, "  ram @%08x: got %08x want %08x\n", a0, un, ug);
            bad++;
        }
    }
    /* r0 = the point plus 12 (or the point itself when gated), r15 = the
     * entry sp; pr untouched */
    if (a.r[0] != gs.v[0] || a.r[15] != gs.v[15]) {
        if (bad < 20)
            fprintf(stderr, "  regs: native r0=%08x r15=%08x | guest r0=%08x r15=%08x\n",
                    a.r[0], a.r[15], gs.v[0], gs.v[15]);
        bad++;
    }
    if (a.pr != gs.v[16]) {
        if (bad < 20) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
        bad++;
    }
    free(gblob);
    printf("  %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    {
        FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
        if (!f) { fprintf(stderr, "image absent\n"); return 2; }
        if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fprintf(stderr, "image short\n"); return 2; }
        fclose(f);
    }

    int bad = 0;
    /* small in-range point: no clamp, no fold, no reflection */
    bad |= run_case("in range", 100.0f, 200.0f, 300.0f, 0);
    /* x above the +655360 clamp */
    bad |= run_case("clamp upper", 800000.0f, 100.0f, 50.0f, 0);
    /* x below the -655360 clamp */
    bad |= run_case("clamp lower", -800000.0f, 100.0f, 50.0f, 0);
    /* x/z large enough to need the fold */
    bad |= run_case("fold x/z", 500000.0f, 100.0f, 200000.0f, 0);
    /* both |x| and |z| above 24576 after the fold, so no check passes and
     * the y-reflection really runs: 30000 folds to itself (it is inside the
     * [-32768,32768] period and above the 24576 threshold) */
    bad |= run_case("reflect y", 30000.0f, 5.0f, 30000.0f, 0);
    /* negative folding direction */
    bad |= run_case("fold negative", -200000.0f, -50.0f, -100000.0f, 0);
    /* the gate blocks the whole body */
    bad |= run_case("gated", 12345.0f, -6789.0f, 1111.0f, 0x0C000000u);
    /* another gate value with only one of the two bits */
    bad |= run_case("gated partial", 12345.0f, -6789.0f, 1111.0f, 0x04000000u);

    free(ram);
    printf("point_wrap_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
