/* Differential replay of the native terrain_flat (src/native/terrain_flat.c,
 * 0x8C068DE4) against the readable guest port
 * (src/fight/terrain_height.c `vf3_terrain_flat_entry`).
 *
 * Both sides seed the same flat RAM (the 3-float normal block at r4 and the
 * two literal-pool constants) and the same FR/register file, then run the
 * leaf.  The leaf writes the up normal (0,1,0) and returns 0 or -0.5 in fr0
 * depending on whether |x|/|z| exceeds the 6.0 stage edge.  The test matches
 * the written RAM, the FR outputs, the T bit and the untouched registers,
 * across inside and outside cases.
 *
 * The literal pool (0x8C068E5C / 0x8C068E60) is read by the guest at its 0x8C
 * address and by the native at the 0x0C mirror (as the other native ports').
 * The native uses one flat RAM with a base low enough to reach both the block
 * and the pool mirror. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "terrain_flat.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_terrain_flat_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x60000u        /* reaches the pool mirror at 0x0C068E5C */

#define NORM 0x0C012000u
#define SP0  0x0C013000u
#define RETURN_PC 0x0c068e4a

/* the guest reads the pool at its 0x8C addresses (a ROM region), so it needs
 * a second window; the native reads the 0x0C mirror inside its flat RAM */
#define POOL_ROM_BASE 0x8C068E40u
#define LIT_SIX_ROM  0x8C068E5Cu
#define LIT_HALF_ROM 0x8C068E60u
#define LIT_SIX_MIR  0x0C068E5Cu
#define LIT_HALF_MIR 0x0C068E60u

static uint8_t *ram;
static uint8_t *pool;    /* the guest's 0x8C pool window */
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

static void seed_ram(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    memset(pool, 0, 0x40);
    wf(NORM + 0, 0.0f); wf(NORM + 4, 0.0f); wf(NORM + 8, 0.0f);
    float six = 6.0f, half = -0.5f;
    uint32_t s6, sh; memcpy(&s6, &six, 4); memcpy(&sh, &half, 4);
    wp32(LIT_SIX_ROM, s6);  wp32(LIT_HALF_ROM, sh);
    wf(LIT_SIX_MIR, six);   wf(LIT_HALF_MIR, half);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], float x, float z)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = NORM;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f800000u + i * 0x1000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[VF3_REG_FR0 + 4] = vf3_aim_ubits(x); fr_in[4] = vf3_aim_ubits(x);
    s->v[VF3_REG_FR0 + 5] = vf3_aim_ubits(z); fr_in[5] = vf3_aim_ubits(z);
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;
    s->v[18] = 0x00024001u;
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = ram;
    win[1].base = POOL_ROM_BASE; win[1].len = 0x40; win[1].data = pool;
    map->wins = win;
    map->n = 2;
    map->oob = 0;
}

static int compare_one(float x, float z)
{
    seed_ram();
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[2];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in, x, z);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_terrain_flat_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest (%g,%g) failed ok=%d oob=%u\n", x, z, ok_guest, gmap.oob);
        return 1;
    }

    seed_ram();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_terrain_flat(&a);

    int bad = 0;

    /* the written normal: (0,1,0) */
    if (vf3_aim_u32(&a, NORM) != 0x00000000u) fprintf(stderr, "  [%g,%g] nx native %08x\n", x, z, vf3_aim_u32(&a, NORM)), bad++;
    if (vf3_aim_u32(&a, NORM + 4) != 0x3f800000u) fprintf(stderr, "  [%g,%g] ny native %08x\n", x, z, vf3_aim_u32(&a, NORM + 4)), bad++;
    if (vf3_aim_u32(&a, NORM + 8) != 0x00000000u) fprintf(stderr, "  [%g,%g] nz native %08x\n", x, z, vf3_aim_u32(&a, NORM + 8)), bad++;
    /* guest wrote the same */
    if (r32(NORM) != vf3_aim_u32(&a, NORM) || r32(NORM + 4) != vf3_aim_u32(&a, NORM + 4) || r32(NORM + 8) != vf3_aim_u32(&a, NORM + 8))
        fprintf(stderr, "  [%g,%g] normal native/guest disagree\n", x, z), bad++;

    int outside = (fabsf(x) > 6.0f) || (fabsf(z) > 6.0f);

    /* FR outputs: fr0 = the result (-0.5 or 0), fr3 = 1.0, fr4 = the result,
     * fr5 = |z|, fr6 = 6.0, fr7 = 0.  fr4/fr5 on entry had x/z; the leaf
     * fabs's them.  Compare against the guest's FR bank. */
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t g = gs.v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a.fr[i]) != g)
            fprintf(stderr, "  [%g,%g] fr%u: native %08x guest %08x\n", x, z, i, vf3_aim_ubits(a.fr[i]), g), bad++;
    }

    /* T bit */
    if ((a.sr & 1u) != (gs.v[17] & 1u)) fprintf(stderr, "  [%g,%g] T: native %u guest %u\n", x, z, a.sr & 1u, gs.v[17] & 1u), bad++;

    /* untouched registers (r0 is written) */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0) continue;
        if (a.r[i] != in_v[i]) fprintf(stderr, "  [%g,%g] r%u: native %08x entry %08x\n", x, z, i, a.r[i], in_v[i]), bad++;
    }

    /* independent model: the result */
    float want = outside ? -0.5f : 0.0f;
    if (vf3_aim_ubits(a.fr[0]) != vf3_aim_ubits(want))
        fprintf(stderr, "  [%g,%g] fr0 model: native %08x want %08x\n", x, z, vf3_aim_ubits(a.fr[0]), vf3_aim_ubits(want)), bad++;

    printf("  (%g,%g): %s\n", x, z, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    pool = (uint8_t *)calloc(0x40, 1);
    if (!ram || !pool) return 2;
    static const float xs[] = { 0.0f, 3.0f, 6.0f, -6.0f, 7.0f, -9.5f, 6.5f };
    static const float zs[] = { 0.0f, -8.0f, 3.0f, 6.0f, 2.0f, 0.9f, -5.0f };
    int bad = 0;
    for (unsigned i = 0; i < sizeof xs / sizeof xs[0]; ++i)
        bad |= compare_one(xs[i], zs[i]);
    free(ram); free(pool);
    printf("terrain_flat_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
