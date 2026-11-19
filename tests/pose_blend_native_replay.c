/* pose_blend_native_replay.c - native pose blend (0x8C091DE6) proved against
 * the readable authority.
 *
 * The native leaf `vf3_native_pose_blend_step` is a bare-C port in the native
 * library (`src/native/pose_blend.c`) that had no proof of its own.  Its
 * readable authority is `vf3_pose_blend_entry` (src/fight/pose_blend.c,
 * registered at 0x0c091de6).  This test seeds a blender object exactly as the
 * readable entry reads it - weight at +0x9C, step at +0xA0, pose A at +0
 * (26 signed halfwords), pose B at +52, output at +104 - runs the readable
 * entry, then runs the native leaf on the SAME object and compares every byte
 * of the object region byte-exact, plus the updated weight.
 *
 * The math is fixed-point and the differential is therefore byte-exact, not
 * tolerance-based: the updated weight (sum + clamp to 1.0) is truncated to
 * Q14 toward zero, then each output halfword is the low 16 bits of the
 * arithmetic-shifted Q14 sum `(A*(0x4000-w) + B*w) >> 14`.  The native's
 * `arithmetic_shift_q14` adds 0x3FFF to the two's-complement magnitude before
 * shifting, which is exactly floor-equivalent to the readable's `>> 14` on a
 * signed int32 for both positive and negative sums (the half-multiple rounds
 * the magnitude up, matching the arithmetic shift's toward-negative-infinity
 * behaviour).  The `volatile` floats force the single-precision add/mul
 * rounding the guest's FPU does, matching the readable's FADD/FMUL.
 *
 * The native leaf returns 0 on the success path; the readable entry has no
 * error returns (the game never feeds it nulls or non-finite weights), so the
 * differential drives the success path only, and the leaf's defensive -1/-2
 * arms are exercised by direct calls below (not by a differential). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "pose_blend.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for the pose blend (0x8C091DE6) */
int vf3_pose_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define OBJ  0x0C205000u   /* the blender object (r4) */
#define SP   0x0C205200u   /* the entry stack pointer (r15) */

#define WEIGHT_OFF 0x9Cu
#define STEP_OFF   0xA0u
#define POSE_B     52u
#define POSE_OUT   104u
#define COUNT      26u

#define REGION_LO (OBJ)
#define REGION_HI (OBJ + 0xA4u)   /* through weight (+0x9C) and step (+0xA0) */

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static void w16(uint32_t addr, int16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    const uint16_t u = (uint16_t)v;
    p[0] = (uint8_t)u; p[1] = (uint8_t)(u >> 8);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = OBJ;                    /* r4 */
    s->v[15] = SP;                    /* r15 */
    s->v[16] = 0x0C0ABCDEu;           /* pr */
    s->v[17] = 0x60000000u;           /* sr, T clear */
    s->v[18] = 0x00040001u;           /* fpscr, single precision */
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static void seed(float weight, float step,
                 const int16_t A[COUNT], const int16_t B[COUNT])
{
    for (uint32_t a = REGION_LO; a < REGION_HI; a += 4)
        w32(a, 0x11AA0000u ^ (a & 0x7FF));
    for (int i = 0; i < COUNT; ++i) {
        w16(OBJ + 2u * (uint32_t)i, A[i]);
        w16(OBJ + POSE_B + 2u * (uint32_t)i, B[i]);
    }
    wf(OBJ + WEIGHT_OFF, weight);
    wf(OBJ + STEP_OFF, step);
}

static int run_case(const char *label, float weight, float step,
                    const int16_t A[COUNT], const int16_t B[COUNT])
{
    int bad = 0;
    printf("== %s\n", label);
    fflush(stdout);

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed(weight, step, A, B);
    setup_guest(&gs, &gmap, gwin);
    if (!vf3_pose_blend_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    uint8_t *gblob = (uint8_t *)malloc(REGION_HI - REGION_LO);
    memcpy(gblob, (const uint8_t *)at(REGION_LO), REGION_HI - REGION_LO);

    seed(weight, step, A, B);
    /* point the native leaf at the SAME RAM object the readable entry used, so
     * its `out` and `weight` land at +104 / +0x9C and the byte compare reads
     * the native's real output */
    float *wptr = (float *)at(OBJ + WEIGHT_OFF);
    const int16_t *pa = (const int16_t *)at(OBJ);
    const int16_t *pb = (const int16_t *)at(OBJ + POSE_B);
    int16_t *pout = (int16_t *)at(OBJ + POSE_OUT);
    const int rc = vf3_native_pose_blend_step(wptr, step, pa, pb, pout);
    if (rc != 0) {
        fprintf(stderr, "  native rc=%d (expect 0)\n", rc);
        return 1;
    }

    /* byte-exact: the native writes `out` at +104 and `weight` at +0x9C, the
     * same two places the readable entry writes.  compare the object region. */
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

    /* A ascending positives, B descending negatives.  weight 0 + step 0.25:
     * a quarter blend, outputs half-way-ish between (via Q14, truncated). */
    {
        int16_t A[COUNT], B[COUNT];
        for (int i = 0; i < COUNT; ++i) { A[i] = (int16_t)(20 * i); B[i] = (int16_t)(-20 * i); }
        bad |= run_case("quarter blend, spanning signs", 0.0f, 0.25f, A, B);
    }

    /* full blend: step pushes weight from 0 above 1.0, so it clamps to 1.0 and
     * the output is exactly B (w = 16384, a = 0). */
    {
        int16_t A[COUNT], B[COUNT];
        for (int i = 0; i < COUNT; ++i) { A[i] = (int16_t)(1000 + 7 * i); B[i] = (int16_t)(-3000 + 9 * i); }
        bad |= run_case("clamp to full blend (out = B)", 0.9f, 0.5f, A, B);
    }

    /* zero blend: w = 0, a = 0x4000, output is exactly A (A*0x4000 >> 14). */
    {
        int16_t A[COUNT], B[COUNT];
        for (int i = 0; i < COUNT; ++i) { A[i] = (int16_t)(-1000 - 9 * i); B[i] = (int16_t)(4000 - 3 * i); }
        bad |= run_case("zero blend (out = A)", 0.0f, 0.0f, A, B);
    }

    /* an exact half-multiple of a negative sum: exercises the native's
     * +0x3FFF magnitude rounding against the readable's >> 14 on negatives */
    {
        int16_t A[COUNT], B[COUNT];
        for (int i = 0; i < COUNT; ++i) { A[i] = (int16_t)(-32768 + i); B[i] = (int16_t)(32767 - 2 * i); }
        bad |= run_case("negative sums / half-multiples", 0.5f, 0.25f, A, B);
    }

    /* mid blend with a weight near 1.0 but not clamped (0.9 + 0.05 = 0.95) */
    {
        int16_t A[COUNT], B[COUNT];
        for (int i = 0; i < COUNT; ++i) { A[i] = (int16_t)(7777 - 13 * i); B[i] = (int16_t)(-12345 + 17 * i); }
        bad |= run_case("mid blend, weight 0.95", 0.9f, 0.05f, A, B);
    }

    /* the defensive arms are not differential-able (the readable has no error
     * path), so they are checked directly: nulls -> -1, NaN/Inf -> -2 */
    {
        int16_t A[COUNT] = {0}, B[COUNT] = {0}, out[COUNT];
        float w = 0.5f;
        if (vf3_native_pose_blend_step(NULL, 0.1f, A, B, out) != -1) bad++;
        if (vf3_native_pose_blend_step(&w, 0.1f, NULL, B, out) != -1) bad++;
        if (vf3_native_pose_blend_step(&w, 0.1f, A, B, NULL) != -1) bad++;
        w = 0.5f;
        if (vf3_native_pose_blend_step(&w, 0.1f, A, NULL, out) != -1) bad++;
        w = NAN;
        if (vf3_native_pose_blend_step(&w, 0.1f, A, B, out) != -2) bad++;
        w = 0.5f;
        if (vf3_native_pose_blend_step(&w, INFINITY, A, B, out) != -2) bad++;
        w = 1.0f;
        if (vf3_native_pose_blend_step(&w, 0.1f, A, B, out) != 0) bad++; /* 1.1 -> clamped 1.0 */
        if (bad)
            fprintf(stderr, "  defensive-arm checks failed\n");
    }

    free(ram);
    printf("pose_blend_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
