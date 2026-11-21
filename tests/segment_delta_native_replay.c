/* Differential replay of the native segment_delta (src/native/segment_delta.c,
 * 0x8C092B4A) against the readable guest port
 * (src/fight/segment_delta.c `vf3_segment_delta_entry`).
 *
 * Both sides seed the same flat RAM (the caller's stack words at sp+0..+C, the
 * source vectors, the destination record, the second record, the scale float,
 * the gating record and the pushed third vector) and the same FR/register
 * file, then run the leaf.  The leaf writes rec[+0x18..+0x20] = (A-B)*scale
 * and (conditionally) pushes a third-vector*scale onto the second record.  The
 * test matches every register/FR/FPUL/T value against the guest plus an
 * independent fixture model across the five branch paths. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "segment_delta.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_segment_delta_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x12000u

#define VEC_A    0x0C012000u
#define VEC_B    0x0C012010u
#define VEC_TH   0x0C012020u   /* third vector */
#define REC2     0x0C012040u   /* second record (r5); +0x18..0x20 pushed */
#define SCALE    0x0C012048u   /* scale float */
#define GATING   0x0C012090u   /* gating record (r7); float at +0x14 */
#define DEST     0x0C012100u   /* destination record (r4) */
#define SP0      0x0C01F000u   /* caller's stack: [0]=A [4]=B [8]=third [C]=flag */
#define RETURN_PC 0x0c092bca

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

/* mode: 0 full push, flag 0; 1 flag 0x100 (scale*0.65); 2 flag 0x2 (skip push);
 * 3 gating[+0x14]=0 (skip push); 4 r5 null (skip push) */
static void seed(int mode)
{
    memset(ram, 0x6c, RAM_SIZE);
    wf(VEC_A + 0, 5.0f);  wf(VEC_A + 4, 1.0f);  wf(VEC_A + 8, -2.0f);
    wf(VEC_B + 0, 1.0f);  wf(VEC_B + 4, 3.0f);  wf(VEC_B + 8, 4.0f);
    wf(VEC_TH + 0, 0.5f); wf(VEC_TH + 4, -1.0f); wf(VEC_TH + 8, 2.0f);
    wf(SCALE, 0.8f);
    wf(GATING + 0x14, (mode == 3) ? 0.0f : 1.5f);
    /* second record's [+0x18..+0x20], which the push adds into */
    wf(REC2 + 0x18, 100.0f); wf(REC2 + 0x1C, 200.0f); wf(REC2 + 0x20, 300.0f);
    /* caller stack */
    w32(SP0 + 0, VEC_A);
    w32(SP0 + 4, VEC_B);
    w32(SP0 + 8, VEC_TH);
    w32(SP0 + 0xC, (mode == 1) ? 0x100u : (mode == 2) ? 0x2u : 0x0u);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], int mode)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = DEST;
    s->v[5] = (mode == 4) ? 0u : REC2;
    s->v[6] = SCALE;
    s->v[7] = GATING;
    s->v[14] = 0x77777777u;   /* r14 gets saved/restored */
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x40400000u + i * 0x4000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;
    s->v[18] = 0x00024001u;
    s->v[VF3_REG_FPUL] = 0x34567890u;
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
    const int ok_guest = vf3_segment_delta_entry(&gs, &gmap);
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
    a.fpul = 0x34567890u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    vf3_native_segment_delta(&a);

    int bad = 0;

    /* registers vs guest */
    for (unsigned i = 0; i < 16; ++i)
        if (a.r[i] != gs.v[i])
            fprintf(stderr, "  [%d] r%u: native %08x guest %08x\n", mode, i, a.r[i], gs.v[i]), bad++;
    /* FR vs guest */
    for (unsigned i = 0; i < 16; ++i)
        if (vf3_aim_ubits(a.fr[i]) != gs.v[VF3_REG_FR0 + i])
            fprintf(stderr, "  [%d] fr%u: native %08x guest %08x\n", mode, i, vf3_aim_ubits(a.fr[i]), gs.v[VF3_REG_FR0 + i]), bad++;
    /* T + fpul */
    if ((a.sr & 1u) != (gs.v[17] & 1u))
        fprintf(stderr, "  [%d] T: native %u guest %u\n", mode, a.sr & 1u, gs.v[17] & 1u), bad++;
    if (a.fpul != 0x34567890u) fprintf(stderr, "  [%d] fpul changed\n", mode), bad++;

    /* dest record RAM + second record RAM vs guest */
    for (int e = 0; e < 3; ++e) {
        uint32_t addr = DEST + 0x18 + 4u * (unsigned)e;
        if (vf3_aim_u32(&a, addr) != r32(addr))
            fprintf(stderr, "  [%d] dest[%d] native %08x guest %08x\n", mode, e, vf3_aim_u32(&a, addr), r32(addr)), bad++;
    }
    for (int e = 0; e < 3; ++e) {
        uint32_t addr = REC2 + 0x18 + 4u * (unsigned)e;
        if (vf3_aim_u32(&a, addr) != r32(addr))
            fprintf(stderr, "  [%d] rec2[%d] native %08x guest %08x\n", mode, e, vf3_aim_u32(&a, addr), r32(addr)), bad++;
    }

    /* independent model */
    {
        const int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float ax = 5.0f, ay = 1.0f, az = -2.0f;
        volatile float bx = 1.0f, by = 3.0f, bz = 4.0f;
        volatile float dx = ax - bx, dy = ay - by, dz = az - bz;
        float scale = 0.8f;
        if (mode == 1) {
            volatile float t0 = scale * 0.65f; scale = t0;
        }
        volatile float mx = dx * scale, my = dy * scale, mz = dz * scale;
        uint32_t wx, wy, wz;
        memcpy(&wx, &mx, 4); memcpy(&wy, &my, 4); memcpy(&wz, &mz, 4);
        if (vf3_aim_u32(&a, DEST + 0x18) != wx) fprintf(stderr, "  [%d] dest.x model %08x want %08x\n", mode, vf3_aim_u32(&a, DEST + 0x18), wx), bad++;
        if (vf3_aim_u32(&a, DEST + 0x1C) != wy) fprintf(stderr, "  [%d] dest.y model %08x want %08x\n", mode, vf3_aim_u32(&a, DEST + 0x1C), wy), bad++;
        if (vf3_aim_u32(&a, DEST + 0x20) != wz) fprintf(stderr, "  [%d] dest.z model %08x want %08x\n", mode, vf3_aim_u32(&a, DEST + 0x20), wz), bad++;

        int push = (mode != 2 && mode != 3 && mode != 4);
        if (push) {
            volatile float g = 1.5f;
            volatile float g2 = g + g;
            volatile float px = 0.5f * g2, py = -1.0f * g2, pz = 2.0f * g2;
            volatile float r2x = 100.0f + px, r2y = 200.0f + py, r2z = 300.0f + pz;
            memcpy(&wx, &r2x, 4); memcpy(&wy, &r2y, 4); memcpy(&wz, &r2z, 4);
            if (vf3_aim_u32(&a, REC2 + 0x18) != wx) fprintf(stderr, "  [%d] rec2.x model %08x want %08x\n", mode, vf3_aim_u32(&a, REC2 + 0x18), wx), bad++;
            if (vf3_aim_u32(&a, REC2 + 0x1C) != wy) fprintf(stderr, "  [%d] rec2.y model %08x want %08x\n", mode, vf3_aim_u32(&a, REC2 + 0x1C), wy), bad++;
            if (vf3_aim_u32(&a, REC2 + 0x20) != wz) fprintf(stderr, "  [%d] rec2.z model %08x want %08x\n", mode, vf3_aim_u32(&a, REC2 + 0x20), wz), bad++;
        } else {
            uint32_t a100 = 0x42c80000u, a200 = 0x43480000u, a300 = 0x43960000u;
            if (vf3_aim_u32(&a, REC2 + 0x18) != a100) fprintf(stderr, "  [%d] rec2 unchanged\n", mode), bad++;
        }
        fesetround(saved);
    }

    printf("  [mode %d] %s\n", mode, bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    for (int m = 0; m < 5; ++m) bad |= compare_one(m);
    free(ram);
    printf("segment_delta_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
