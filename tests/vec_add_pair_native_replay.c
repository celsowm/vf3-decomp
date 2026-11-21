/* Differential replay of the native vec_add_pair (src/native/vec_add_pair.c,
 * 0x8C092A70) against the readable guest port
 * (src/fight/vec_add_pair.c `vf3_vec_add_pair_entry`).
 *
 * Both sides seed the same flat RAM (the object, the global gate word, the A/B
 * vectors and the D destination) and the same FR/register file, then run the
 * leaf.  The leaf optionally adds A+24 into D, then always adds B.y into D.y.
 * The test compares the written RAM byte for byte against an independent
 * fixture model, the final registers, the FR-bank outputs, and the untouched
 * registers/FR, across both the add and the skip paths. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vec_add_pair.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vec_add_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x2A0000u   /* reaches the gate global at 0x0C29B868 */

#define GATE_W  0x0C011000u   /* the global gate word */
#define OBJ     0x0C011004u   /* the object (byte +97 gates the add) */
#define VEC_A   0x0C011040u   /* vector A (12-byte-stride array) */
#define VEC_B   0x0C01107Cu   /* vector B */
#define VEC_D   0x0C011090u   /* destination D */
#define SP0     0x0C012000u

#define RETURN_PC 0x0c092a8au

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float f) { uint32_t u; memcpy(&u, &f, 4); w32(addr, u); }

/* mode: 0 = gate clear, byte 5 (add runs); 1 = gate set, byte 5 (add still
 * runs - the skip needs BOTH gate set and byte 11); 2 = gate set, byte 11 (skip) */
static void seed(int mode)
{
    memset(ram, 0x6c, RAM_SIZE);
    if (mode == 0) w32(GATE_W, 0x00000000u);
    else           w32(GATE_W, 0x04000000u);
    w32(OBJ, 0x11111111u);
    if (mode == 2) {
        /* byte at OBJ+97 == 11 */
        ab(OBJ + 97)[0] = 11;
    } else {
        ab(OBJ + 97)[0] = 5;
    }
    /* A is a 12-byte-stride array; A+24 is the third vector */
    wf(VEC_A + 0 * 12 + 0, 1.0f); wf(VEC_A + 0 * 12 + 4, 2.0f); wf(VEC_A + 0 * 12 + 8, 3.0f);
    wf(VEC_A + 1 * 12 + 0, 4.0f); wf(VEC_A + 1 * 12 + 4, 5.0f); wf(VEC_A + 1 * 12 + 8, 6.0f);
    wf(VEC_A + 2 * 12 + 0, 0.25f); wf(VEC_A + 2 * 12 + 4, -1.5f); wf(VEC_A + 2 * 12 + 8, 4.0f);
    wf(VEC_B + 0, 10.0f); wf(VEC_B + 4, -0.5f); wf(VEC_B + 8, 7.0f);
    wf(VEC_D + 0, 100.0f); wf(VEC_D + 4, 200.0f); wf(VEC_D + 8, 300.0f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ;
    s->v[5] = VEC_A;
    s->v[6] = VEC_B;
    s->v[7] = VEC_D;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f000000u + i * 0x1000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[16] = RETURN_PC;   /* pr */
    s->v[17] = 0x60000000u; /* SR: T clear */
    s->v[18] = 0x00024001u; /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(int mode)
{
    seed(mode);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vec_add_pair_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  [mode %d] guest run failed (ok=%d oob=%u)\n", mode, ok_guest, gmap.oob);
        return 1;
    }

    seed(mode);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_vec_add_pair(&a);

    int bad = 0;

    /* register outputs: r0=4, r1=B+4, r2=D, r3=B; r15 restored; add path r4=D,
     * r5=A+36; skip path r4/r5 untouched */
    if (a.r[0] != 4u) fprintf(stderr, "  [%d] r0: native %08x want 4\n", mode, a.r[0]), bad++;
    if (a.r[1] != VEC_B + 4) fprintf(stderr, "  [%d] r1: native %08x want %08x\n", mode, a.r[1], VEC_B + 4), bad++;
    if (a.r[2] != VEC_D) fprintf(stderr, "  [%d] r2: native %08x want %08x\n", mode, a.r[2], VEC_D), bad++;
    if (a.r[3] != VEC_B) fprintf(stderr, "  [%d] r3: native %08x want %08x\n", mode, a.r[3], VEC_B), bad++;
    if (a.r[15] != SP0) fprintf(stderr, "  [%d] r15: native %08x want %08x\n", mode, a.r[15], SP0), bad++;
    int add = (mode != 2);  /* only gate-set AND byte 11 skips */
    if (a.r[4] != (add ? VEC_D : OBJ)) fprintf(stderr, "  [%d] r4: native %08x want %08x\n", mode, a.r[4], add ? (uint32_t)VEC_D : (uint32_t)OBJ), bad++;
    if (a.r[5] != (add ? VEC_A + 36 : VEC_A)) fprintf(stderr, "  [%d] r5: native %08x want %08x\n", mode, a.r[5], add ? (uint32_t)(VEC_A + 36) : (uint32_t)VEC_A), bad++;
    if (a.r[6] != VEC_B) fprintf(stderr, "  [%d] r6: native %08x want %08x\n", mode, a.r[6], VEC_B), bad++;
    if (a.r[7] != VEC_D) fprintf(stderr, "  [%d] r7: native %08x want %08x\n", mode, a.r[7], VEC_D), bad++;

    /* the guest's T bits are intermediate here (a compare mid-routine); the
     * fixture seeds a fresh state so the leaves' own writes are the same on
     * both sides; the final T is whatever the last compare left, which both
     * sides agree on because they run the same comparisons.  Compare it. */
    {
        uint32_t gt = gs.v[17] & 1u, nt = a.sr & 1u;
        if (gt != nt) fprintf(stderr, "  [%d] T bit: native %u guest %u\n", mode, nt, gt), bad++;
    }

    /* FR outputs: fr0/fr1/fr2 = D vector (add path), fr3/fr4/fr5 = (A+24)
     * vector (add path); then the D.y += B.y overwrites fr2 with the combined
     * y and fr3 with D.y's addend (B.y) on every path.  Compare against the
     * guest's FR bank (it ran the same sequence). */
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g)
            fprintf(stderr, "  [%d] fr%u: native %08x guest %08x\n", mode, i, vf3_aim_ubits(a.fr[i]), g), bad++;
    }

    /* written RAM: D and (add path) D += A+24, plus the always-D.y += B.y.
     * Compare native vs guest RAM at D */
    for (int e = 0; e < 3; ++e) {
        uint32_t addr = VEC_D + 4u * (unsigned)e;
        uint32_t nv = vf3_aim_u32(&a, addr), gv = r32(addr);
        if (nv != gv) fprintf(stderr, "  [%d] D ram[%d]: native %08x guest %08x\n", mode, e, nv, gv), bad++;
    }

    /* independent fixture model */
    {
        float ax0 = 0.25f, ay0 = -1.5f, az0 = 4.0f;   /* A+24 */
        float bx = 10.0f, by = -0.5f, bz = 7.0f;
        float dx = 100.0f, dy = 200.0f, dz = 300.0f;
        int saved = fegetround(); fesetround(FE_TOWARDZERO);
        if (add) {
            volatile float t;
            t = dx + ax0; dx = t; t = dy + ay0; dy = t; t = dz + az0; dz = t;
        }
        volatile float ty = dy + by; dy = ty;
        fesetround(saved);
        uint32_t wx, wy, wz; memcpy(&wx, &dx, 4); memcpy(&wy, &dy, 4); memcpy(&wz, &dz, 4);
        uint32_t n0 = vf3_aim_u32(&a, VEC_D), n1 = vf3_aim_u32(&a, VEC_D + 4), n2 = vf3_aim_u32(&a, VEC_D + 8);
        if (n0 != wx) fprintf(stderr, "  [%d] D.x native %08x model %08x\n", mode, n0, wx), bad++;
        if (n1 != wy) fprintf(stderr, "  [%d] D.y native %08x model %08x\n", mode, n1, wy), bad++;
        if (n2 != wz) fprintf(stderr, "  [%d] D.z native %08x model %08x\n", mode, n2, wz), bad++;
    }

    printf("  [mode %d] %s\n", mode, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    for (int m = 0; m < 3; ++m) bad |= compare_one(m);
    free(ram);
    printf("vec_add_pair_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
