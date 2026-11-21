/* Differential replay of the native vec3_sub (src/native/vec3_sub.c,
 * 0x8C03CEE0) against the readable guest port
 * (src/fight/small_leaves.c `vf3_vec3_sub_entry`).
 *
 * Both sides seed the same flat RAM (three 3-float vectors at r4 / r5 / r6)
 * and the same FR/register file, then run the leaf.  The leaf computes
 * r4[0..2] = r5[0..2] - r6[0..2] component-wise and advances r4 / r5 / r6 by
 * 12 bytes.  The test compares the written RAM byte for byte against an
 * independent fixture model, the output registers, the FR-bank outputs the
 * leaf leaves, and the untouched registers/FR. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vec3_sub.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vec3_sub_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x10000u

#define VEC_A 0x0C011000u   /* source 1 */
#define VEC_B 0x0C01100Cu   /* source 2 */
#define VEC_D 0x0C011018u   /* destination */
#define SP0   0x0C012000u

#define RETURN_PC 0x0c03cef8u

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

static void seed(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* three vectors, deliberately not aligned to each other so the leaf's
     * pointer arithmetic (each advances 12 bytes) is visible */
    wf(VEC_A + 0, 1.25f);  wf(VEC_A + 4, -3.5f);  wf(VEC_A + 8, 7.0f);
    wf(VEC_B + 0, 0.5f);   wf(VEC_B + 4, 2.0f);   wf(VEC_B + 8, -1.25f);
    wf(VEC_D + 0, 99.0f);  wf(VEC_D + 4, 99.0f);  wf(VEC_D + 8, 99.0f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = VEC_D;
    s->v[5] = VEC_A;
    s->v[6] = VEC_B;
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

static int compare_one(void)
{
    seed();

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vec3_sub_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    seed();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_vec3_sub(&a);

    int bad = 0;

    /* registers r4 / r5 / r6 advance by 8 */
    if (a.r[4] != VEC_D + 8) fprintf(stderr, "  r4: native %08x want %08x\n", a.r[4], VEC_D + 8), bad++;
    if (a.r[5] != VEC_A + 8) fprintf(stderr, "  r5: native %08x want %08x\n", a.r[5], VEC_A + 8), bad++;
    if (a.r[6] != VEC_B + 8) fprintf(stderr, "  r6: native %08x want %08x\n", a.r[6], VEC_B + 8), bad++;
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4 || i == 5 || i == 6) continue;
        if (a.r[i] != in_v[i]) fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]), bad++;
    }
    /* FR outputs: fr0/fr1/fr2 = differences, fr4/fr5/fr6 = source-2 components */
    int saved = fegetround(); fesetround(FE_TOWARDZERO);
    volatile float dx = 1.25f - 0.5f, dy = -3.5f - 2.0f, dz = 7.0f - (-1.25f);
    fesetround(saved);
    uint32_t wx, wy, wz; memcpy(&wx, &dx, 4); memcpy(&wy, &dy, 4); memcpy(&wz, &dz, 4);
    if (vf3_aim_ubits(a.fr[0]) != wx) fprintf(stderr, "  fr0: native %08x model %08x\n", vf3_aim_ubits(a.fr[0]), wx), bad++;
    if (vf3_aim_ubits(a.fr[1]) != wy) fprintf(stderr, "  fr1: native %08x model %08x\n", vf3_aim_ubits(a.fr[1]), wy), bad++;
    if (vf3_aim_ubits(a.fr[2]) != wz) fprintf(stderr, "  fr2: native %08x model %08x\n", vf3_aim_ubits(a.fr[2]), wz), bad++;
    uint32_t b0 = 0, b1 = 0, b2 = 0; { float x = 0.5f, y = 2.0f, z = -1.25f; memcpy(&b0, &x, 4); memcpy(&b1, &y, 4); memcpy(&b2, &z, 4); }
    if (vf3_aim_ubits(a.fr[4]) != b0) fprintf(stderr, "  fr4: native %08x model %08x\n", vf3_aim_ubits(a.fr[4]), b0), bad++;
    if (vf3_aim_ubits(a.fr[5]) != b1) fprintf(stderr, "  fr5: native %08x model %08x\n", vf3_aim_ubits(a.fr[5]), b1), bad++;
    if (vf3_aim_ubits(a.fr[6]) != b2) fprintf(stderr, "  fr6: native %08x model %08x\n", vf3_aim_ubits(a.fr[6]), b2), bad++;
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 1 || i == 2 || i == 4 || i == 5 || i == 6) continue;
        if (vf3_aim_ubits(a.fr[i]) != fr_in[i]) fprintf(stderr, "  fr%u: native %08x entry %08x\n", i, vf3_aim_ubits(a.fr[i]), fr_in[i]), bad++;
    }

    /* written RAM: r4[0..2] = A - B, byte for byte */
    uint32_t gw[3];
    for (int e = 0; e < 3; ++e) gw[e] = r32(VEC_D + 4u * (unsigned)e);
    uint32_t nw[3] = { vf3_aim_u32(&a, VEC_D), vf3_aim_u32(&a, VEC_D + 4), vf3_aim_u32(&a, VEC_D + 8) };
    uint32_t mw[3] = { wx, wy, wz };
    for (int e = 0; e < 3; ++e) {
        if (gw[e] != mw[e]) fprintf(stderr, "  guest ram[%d]: %08x model %08x\n", e, gw[e], mw[e]), bad++;
        if (nw[e] != mw[e]) fprintf(stderr, "  native ram[%d]: %08x model %08x\n", e, nw[e], mw[e]), bad++;
    }
    /* the "99" bytes the leaf overwrites must not survive (they are all in
     * r4's run, so they are covered above); the sources stay untouched */
    if (r32(VEC_A) != 0x3fa00000u) fprintf(stderr, "  source A clobbered %08x\n", r32(VEC_A)), bad++;
    if (r32(VEC_B) != 0x3f000000u) fprintf(stderr, "  source B clobbered %08x\n", r32(VEC_B)), bad++;

    printf("vec3_sub: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = compare_one();
    free(ram);
    printf("vec3_sub_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
