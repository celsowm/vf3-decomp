/* Differential replay of the native terrain_wrap (src/native/terrain_wrap.c,
 * 0x8C068D54) against the readable guest port
 * (src/fight/terrain_height.c `vf3_terrain_wrap_entry`).
 *
 * Both sides seed the same flat RAM (x at r5, z at r6, and the literal-pool
 * constants) and the same FR/register file, then run the leaf.  The leaf
 * scales x/z by 0.769 for stage types 2/7, folds both into a 10-unit
 * repeating cell for type 13, and leaves them alone otherwise.  The test
 * matches the written x/z RAM, the FR outputs, FPUL, the registers and the T
 * bit across all three stage families. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "terrain_wrap.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_terrain_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x60000u         /* reaches the pool mirror at 0x0C068E50 */

#define X   0x0C012000u
#define Z   0x0C012004u
#define SP0 0x0C013000u
#define RETURN_PC 0x0c068d8e

#define POOL_ROM_BASE 0x8C068E40u
#define LIT_SCALE_ROM 0x8C068E50u
#define LIT_TENTH_ROM 0x8C068E54u
#define LIT_SCALE_MIR 0x0C068E50u
#define LIT_TENTH_MIR 0x0C068E54u

static uint8_t *ram;
static uint8_t *pool;
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
static void wp32(uint32_t addr, uint32_t v) { uint8_t *p = pool + (addr - POOL_ROM_BASE); p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24); }

/* type: 2/7 scale; 13 fold; otherwise leave alone */
static void seed(uint32_t type, float x, float z)
{
    memset(ram, 0x6c, RAM_SIZE);
    memset(pool, 0, 0x40);
    wf(X, x); wf(Z, z);
    float scale = 0.769f, tenth = 0.1f;
    uint32_t sc, te; memcpy(&sc, &scale, 4); memcpy(&te, &tenth, 4);
    wp32(LIT_SCALE_ROM, sc); wp32(LIT_TENTH_ROM, te);
    wf(LIT_SCALE_MIR, scale); wf(LIT_TENTH_MIR, tenth);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], uint32_t type,
                        uint32_t fpul_in, uint32_t sr_in)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = type;
    s->v[5] = X;
    s->v[6] = Z;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f000000u + i * 0x1000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[16] = RETURN_PC;
    s->v[17] = sr_in;
    s->v[18] = 0x00024001u;
    s->v[VF3_REG_FPUL] = fpul_in;
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = ram;
    win[1].base = POOL_ROM_BASE; win[1].len = 0x40; win[1].data = pool;
    map->wins = win;
    map->n = 2;
    map->oob = 0;
}

static int compare_one(uint32_t type, float x, float z)
{
    seed(type, x, z);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[2];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in, type, 0x12345678u, 0x60000000u);
    memcpy(in_v, gs.v, 54 * sizeof(uint32_t));
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_terrain_wrap_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  [type %u %g,%g] guest failed ok=%d oob=%u\n", type, x, z, ok_guest, gmap.oob);
        return 1;
    }

    seed(type, x, z);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    a.fpul = 0x12345678u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_terrain_wrap(&a);

    int bad = 0;

    /* written x/z */
    for (int e = 0; e < 2; ++e) {
        uint32_t addr = X + 4u * (unsigned)e;
        uint32_t nv = vf3_aim_u32(&a, addr), gv = r32(addr);
        if (nv != gv) fprintf(stderr, "  [%u %g,%g] ramp[%d]: native %08x guest %08x\n", type, x, z, e, nv, gv), bad++;
    }

    /* FR outputs against the guest's FR bank */
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g)
            fprintf(stderr, "  [%u %g,%g] fr%u: native %08x guest %08x\n", type, x, z, i, vf3_aim_ubits(a.fr[i]), g), bad++;
    }

    /* FPUL */
    if (a.fpul != gs.v[VF3_REG_FPUL])
        fprintf(stderr, "  [%u %g,%g] fpul: native %08x guest %08x\n", type, x, z, a.fpul, gs.v[VF3_REG_FPUL]), bad++;

    /* T bit */
    if ((a.sr & 1u) != (gs.v[17] & 1u))
        fprintf(stderr, "  [%u %g,%g] T: native %u guest %u\n", type, x, z, a.sr & 1u, gs.v[17] & 1u), bad++;

    /* registers 0..15 (compare to guest, which is the better oracle here since
     * fold_axis clobbers some registers) */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i])
            fprintf(stderr, "  [%u %g,%g] r%u: native %08x guest %08x\n", type, x, z, i, a.r[i], gs.v[i]), bad++;
    }

    /* independent model */
    if (type == 2 || type == 7) {
        int saved = fegetround(); fesetround(FE_TOWARDZERO);
        volatile float mx = x * 0.769f, mz = z * 0.769f;
        fesetround(saved);
        uint32_t wx, wz; memcpy(&wx, &mx, 4); memcpy(&wz, &mz, 4);
        if (vf3_aim_u32(&a, X) != wx) fprintf(stderr, "  [%u] x model: native %08x want %08x\n", type, vf3_aim_u32(&a, X), wx), bad++;
        if (vf3_aim_u32(&a, Z) != wz) fprintf(stderr, "  [%u] z model: native %08x want %08x\n", type, vf3_aim_u32(&a, Z), wz), bad++;
    } else if (type == 13) {
        /* fold: n = trunc(v * 0.1) toward zero; round half-away to even; v -= n*10 */
        int saved = fegetround(); fesetround(FE_TOWARDZERO);
        volatile float tx = x * 0.1f, tz = z * 0.1f;
        fesetround(saved);
        int32_t nx = (int32_t)tx, nz = (int32_t)tz;
        if (nx & 1) nx = (nx >= 0) ? nx + 1 : nx - 1;
        if (nz & 1) nz = (nz >= 0) ? nz + 1 : nz - 1;
        fesetround(FE_TOWARDZERO);
        volatile float rmx = x - (float)(nx * 10), rmz = z - (float)(nz * 10);
        fesetround(saved);
        uint32_t wx, wz; memcpy(&wx, &rmx, 4); memcpy(&wz, &rmz, 4);
        if (vf3_aim_u32(&a, X) != wx) fprintf(stderr, "  [13] x model: native %08x want %08x\n", vf3_aim_u32(&a, X), wx), bad++;
        if (vf3_aim_u32(&a, Z) != wz) fprintf(stderr, "  [13] z model: native %08x want %08x\n", vf3_aim_u32(&a, Z), wz), bad++;
    } else {
        uint32_t wx, wz; memcpy(&wx, &x, 4); memcpy(&wz, &z, 4);
        if (vf3_aim_u32(&a, X) != wx) fprintf(stderr, "  [%u] x unchanged: native %08x want %08x\n", type, vf3_aim_u32(&a, X), wx), bad++;
        if (vf3_aim_u32(&a, Z) != wz) fprintf(stderr, "  [%u] z unchanged: native %08x want %08x\n", type, vf3_aim_u32(&a, Z), wz), bad++;
    }

    printf("  [type %u (%g,%g)] %s\n", type, x, z, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    pool = (uint8_t *)calloc(0x40, 1);
    if (!ram || !pool) return 2;
    /* [type, x, z]: scale (type 2/7), fold (type 13), leave (type 1/other).
     * For type 13, include values inside/outside units and near the fold
     * boundaries, plus a small value that truncates to zero (count 0). */
    struct { uint32_t t; float x, z; } cases[] = {
        { 2, 1.0f, 2.0f },
        { 7, -3.5f, 4.25f },
        { 2, 0.0f, 0.0f },
        { 13, 12.3f, -8.7f },
        { 13, -3.2f, 7.9f },
        { 13, 0.6f, -0.4f },
        { 13, 5.0f, 5.0f },
        { 13, 20.0f, -15.0f },
        { 1, 3.0f, 4.0f },
        { 0, -1.0f, -2.0f },
    };
    int bad = 0;
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; ++i)
        bad |= compare_one(cases[i].t, cases[i].x, cases[i].z);
    free(ram); free(pool);
    printf("terrain_wrap_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
