/* Differential replay of the native scaled_vec_add (src/native/scaled_vec_add.c,
 * 0x8C09302A) against the readable guest port
 * (src/fight/scaled_vec_add.c `vf3_scaled_vec_add_entry`).
 *
 * Both sides seed the same flat RAM (actor, owner, source record, destination
 * vector and the dest pointer at [sp0+0]) and the same FR/register file, then
 * run the leaf.  The leaf does dest += w * owner.vec with the weight scaled by
 * a chain of flag tests; it may be skipped entirely (weight zero / r7 & 0x1000).
 * The test matches the written dest RAM against an independent fixture model
 * and every register/FR/FPUL value against the guest across all the branch
 * paths. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "scaled_vec_add.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scaled_vec_add_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x12000u

#define ACTOR 0x0C012010u
#define OWNER 0x0C012040u   /* flags at +72, vector at +92 */
#define SRC   0x0C0120C0u   /* weight at +16 */
#define SP0   0x0C013000u   /* [sp0+0] = dest pointer */
#define DEST  0x0C014000u
#define RETURN_PC 0x0c0930a1

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

/* independent model multiply: round-toward-zero + FTZ (as the port) */
static float fmodel_mul(float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x * y;
    fesetround(saved);
    return z;
}

/* mode selects the branch path:
 *   0 : weight 0                  -> leave (R(3)=0x0C0930D8)
 *   1 : owner.flag 0x04000000 set -> w *= 1.1
 *   2 : flag clear, actor bit0 set-> w *= 0.75 (apply after bf/s)
 *   3 : flag clear, actor bit0 clr, r7 & 0x1000 set -> leave
 *   4 : flag clear, actor bit0 clr, r7&0x1000 clr, r7&0x100 clr -> w*=0.75
 *   5 : flag clear, actor bit0 clr, r7&0x1000 clr, r7&0x100 set -> w*=0.75*0.45
 */
static void seed(int mode)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* actor: mode 2/3/4/5 need bit0 of s16[16] clear for the 0.45/0x1000 tests */
    w32(ACTOR, 0x11111111u);
    ab(ACTOR + 16)[0] = (mode == 2) ? 0x01 : 0x00;   /* s16[16] bit0 */
    ab(ACTOR + 17)[0] = 0x00;
    /* owner flags at +72 (this gates the 1.1 scale) */
    w32(OWNER + 72, (mode == 1) ? 0x04000000u : 0x00000000u);
    /* the source vector the leaf reads is at r4(=actor)+92 (via the frame) */
    wf(ACTOR + 92 + 0, 2.0f); wf(ACTOR + 92 + 4, -1.5f); wf(ACTOR + 92 + 8, 0.75f);
    /* source record weight at +16 */
    wf(SRC + 16, (mode == 0) ? 0.0f : 1.25f);
    /* dest */
    wf(DEST + 0, 10.0f); wf(DEST + 4, 20.0f); wf(DEST + 8, 30.0f);
    /* dest pointer at [sp0+0] */
    w32(SP0, DEST);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], int mode)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = ACTOR;
    s->v[5] = OWNER;
    s->v[6] = SRC;
    s->v[7] = 0x00000000u;
    if (mode == 5) s->v[7] = 0x00000100u;
    if (mode == 3 || mode == 4) ; /* 0x1000 clear for 4/5, set for 3 */
    if (mode == 3) s->v[7] = 0x00001000u;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x40400000u + i * 0x4000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;
    s->v[18] = 0x00024001u;
    s->v[VF3_REG_FPUL] = 0x12345678u;
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = ram;
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
    setup_guest(&gs, &gmap, gwin, in_v, fr_in, mode);
    memcpy(in_v, gs.v, 54 * sizeof(uint32_t));
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_scaled_vec_add_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  [mode %d] guest failed ok=%d oob=%u\n", mode, ok_guest, gmap.oob);
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
    a.fpul = 0x12345678u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_scaled_vec_add(&a);

    int bad = 0;

    /* registers 0..15 vs guest */
    for (unsigned i = 0; i < 16; ++i)
        if (a.r[i] != gs.v[i])
            fprintf(stderr, "  [%d] r%u: native %08x guest %08x\n", mode, i, a.r[i], gs.v[i]), bad++;

    /* FR bank vs guest (fr15 restored to entry both sides) */
    for (unsigned i = 0; i < 16; ++i)
        if (vf3_aim_ubits(a.fr[i]) != gs.v[VF3_REG_FR0 + i])
            fprintf(stderr, "  [%d] fr%u: native %08x guest %08x\n", mode, i, vf3_aim_ubits(a.fr[i]), gs.v[VF3_REG_FR0 + i]), bad++;

    /* T bit */
    if ((a.sr & 1u) != (gs.v[17] & 1u))
        fprintf(stderr, "  [%d] T: native %u guest %u\n", mode, a.sr & 1u, gs.v[17] & 1u), bad++;

    /* FPUL untouched */
    if (a.fpul != 0x12345678u) fprintf(stderr, "  [%d] fpul changed to %08x\n", mode, a.fpul), bad++;

    /* dest RAM: native vs guest */
    for (int e = 0; e < 3; ++e) {
        uint32_t addr = DEST + 4u * (unsigned)e;
        if (vf3_aim_u32(&a, addr) != r32(addr))
            fprintf(stderr, "  [%d] dest[%d]: native %08x guest %08x\n", mode, e, vf3_aim_u32(&a, addr), r32(addr)), bad++;
    }

    /* independent model: dest += w * owner.vec */
    int applies = (mode != 0 && mode != 3);
    if (applies) {
        float w = 1.25f, sx = 2.0f, sy = -1.5f, sz = 0.75f;
        /* the guest's literals are exact bits, not C's round-to-nearest
         * constants (1.1f = 0x3F8CCCCD, but the guest uses 0x3F8CCCCC) */
        if (mode == 1) w = fmodel_mul(w, vf3_aim_fbits(0x3F8CCCCCu));
        else {
            w = fmodel_mul(w, vf3_aim_fbits(0x3F400000u));
            if (mode == 5) w = fmodel_mul(w, vf3_aim_fbits(0x3EE66666u));
        }
        volatile float tx = fmodel_mul(sx, w);
        volatile float ty = fmodel_mul(sy, w);
        volatile float tz = fmodel_mul(sz, w);
        const int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float dx = 10.0f, dy = 20.0f, dz = 30.0f;
        volatile float rx = dx + tx, ry = dy + ty, rz = dz + tz;
        fesetround(saved);
        uint32_t wx, wy, wz; memcpy(&wx, &rx, 4); memcpy(&wy, &ry, 4); memcpy(&wz, &rz, 4);
        if (vf3_aim_u32(&a, DEST) != wx) fprintf(stderr, "  [%d] dest.x model: %08x want %08x\n", mode, vf3_aim_u32(&a, DEST), wx), bad++;
        if (vf3_aim_u32(&a, DEST + 4) != wy) fprintf(stderr, "  [%d] dest.y model: %08x want %08x\n", mode, vf3_aim_u32(&a, DEST + 4), wy), bad++;
        if (vf3_aim_u32(&a, DEST + 8) != wz) fprintf(stderr, "  [%d] dest.z model: %08x want %08x\n", mode, vf3_aim_u32(&a, DEST + 8), wz), bad++;
    } else {
        uint32_t wx = 0x41200000u, wy = 0x41a00000u, wz = 0x41f00000u; /* 10,20,30 */
        if (vf3_aim_u32(&a, DEST) != wx) fprintf(stderr, "  [%d] dest unchanged: %08x\n", mode, vf3_aim_u32(&a, DEST)), bad++;
        if (vf3_aim_u32(&a, DEST + 4) != wy) fprintf(stderr, "  [%d] dest unchanged: %08x\n", mode, vf3_aim_u32(&a, DEST + 4)), bad++;
        if (vf3_aim_u32(&a, DEST + 8) != wz) fprintf(stderr, "  [%d] dest unchanged: %08x\n", mode, vf3_aim_u32(&a, DEST + 8)), bad++;
    }

    printf("  [mode %d] %s\n", mode, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    for (int m = 0; m < 6; ++m) bad |= compare_one(m);
    free(ram);
    printf("scaled_vec_add_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
