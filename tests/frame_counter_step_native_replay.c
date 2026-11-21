/* Differential replay of the native frame_counter_step
 * (src/native/frame_counter_step.c, 0x8C0CC334) against the readable guest
 * port (src/fight/frame_counter_step.c `vf3_frame_counter_step_entry`).
 *
 * Both sides seed the same flat RAM (an object with a counter at +0x1E, a
 * table value at +0x1C, floats at +0x0C/+0x10/+0x14, a flag word, three
 * halfword tables), then run the leaf.  The test compares the written RAM
 * byte for byte, the output registers (r0/r1/r3/r5), the T bit, FPUL, the
 * four FR outputs (fr0/fr6/fr7/fr8 plus the fr2/fr3 scratch) and the r13
 * round trip against the guest. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "frame_counter_step.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_frame_counter_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x10000u

#define OBJ    0x0C011000u
#define FLAGS  0x0C011100u
#define SP0    0x0C012000u
#define TBL_A  0x0C013000u   /* r6 */
#define TBL_B  0x0C013040u   /* r7 */
#define TBL_C  0x0C013080u   /* [sp] }*/

#define RETURN_PC 0x0c0cc490u

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
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
/* reads that work on an arbitrary buffer (a copy of `ram`) */
static uint32_t r32_at(const uint8_t *buf, uint32_t addr)
{
    const uint8_t *p = buf + (addr - RAM_BASE);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16_at(const uint8_t *buf, uint32_t addr)
{
    const uint8_t *p = buf + (addr - RAM_BASE);
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static void seed_case(uint16_t counter, uint16_t tblval, uint32_t flags,
                      float f0c, float f10, float f14,
                      uint16_t t1_idx_low, uint32_t tblsel)
{
    memset(ram, 0x6c, RAM_SIZE);
    w16(OBJ + 0x1E, counter);
    w16(OBJ + 0x1C, tblval);
    wf(OBJ + 0x0C, f0c);
    wf(OBJ + 0x10, f10);
    wf(OBJ + 0x14, f14);
    w32(FLAGS, flags);
    /* three tables: each indexed by (counter&31)<<1; [sp] holds a pointer to
     * the third (the guest dereferences the word at sp) */
    for (unsigned i = 0; i < 32; ++i) {
        w16(TBL_A + (i << 1), (uint16_t)(0x100 + i));
        w16(TBL_B + (i << 1), (uint16_t)(0x200 + i));
        w16(TBL_C + (i << 1), (uint16_t)(0x300 + i));
    }
    w32(SP0, TBL_C);
    (void)t1_idx_low; (void)tblsel;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16], uint32_t flags,
                        float fr4, float fr5, uint8_t *body)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ;
    s->v[5] = FLAGS;
    s->v[6] = TBL_A;
    s->v[7] = TBL_B;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f000000u + i * 0x1000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[VF3_REG_FR0 + 4] = (uint32_t)0; /* replaced below */
    uint32_t f4; memcpy(&f4, &fr4, 4); s->v[VF3_REG_FR0 + 4] = f4;
    uint32_t f5; memcpy(&f5, &fr5, 4); s->v[VF3_REG_FR0 + 5] = f5;
    s->v[16] = RETURN_PC;   /* pr */
    s->v[17] = 0x60000000u; /* SR: T clear */
    s->v[18] = 0x00024001u; /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = body;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(uint16_t counter, uint16_t tblval, uint32_t flags,
                       float f0c, float f10, float f14, float fr4, float fr5,
                       int idx)
{
    /* seed the canonical RAM */
    seed_case(counter, tblval, flags, f0c, f10, f14, 0, 0);
    int bad = 0;

    /* --- guest (readable oracle) on g_ram --- */
    uint8_t *g_ram = (uint8_t *)malloc(RAM_SIZE);
    uint8_t *n_ram = (uint8_t *)malloc(RAM_SIZE);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }
    memcpy(g_ram, ram, RAM_SIZE);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, in_v, fr_in, flags, fr4, fr5, g_ram);
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_frame_counter_step_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  case %d: guest run failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
        bad++;
        free(g_ram); free(n_ram);
        return bad;
    }

    /* --- native on n_ram --- */
    memcpy(n_ram, ram, RAM_SIZE);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)n_ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = in_v[i];
    x.r[4] = OBJ; x.r[5] = FLAGS; x.r[6] = TBL_A; x.r[7] = TBL_B; x.r[15] = SP0;
    x.pr = RETURN_PC;
    x.sr = 0x60000000u;
    x.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) x.fr[i] = vf3_aim_fbits(fr_in[i]);
    x.fr[4] = fr4; x.fr[5] = fr5;
    vf3_native_frame_counter_step(&x);

    /* --- compare --- */
    /* registers */
    if (x.r[0] != gs.v[0]) fprintf(stderr, "  case %d: r0 native %08x guest %08x\n", idx, x.r[0], gs.v[0]), bad++;
    if ((x.r[1] & 31u) != (gs.v[1] & 31u)) fprintf(stderr, "  case %d: r1 native %08x guest %08x\n", idx, x.r[1], gs.v[1]), bad++;
    if (x.r[2] != gs.v[2]) fprintf(stderr, "  case %d: r2 native %08x guest %08x\n", idx, x.r[2], gs.v[2]), bad++;
    if (x.r[3] != gs.v[3]) fprintf(stderr, "  case %d: r3 native %08x guest %08x\n", idx, x.r[3], gs.v[3]), bad++;
    if (x.r[5] != gs.v[5]) fprintf(stderr, "  case %d: r5 native %08x guest %08x\n", idx, x.r[5], gs.v[5]), bad++;
    if (x.r[13] != gs.v[13]) fprintf(stderr, "  case %d: r13 native %08x guest %08x\n", idx, x.r[13], gs.v[13]), bad++;
    if ((x.sr & 1u) != (gs.v[17] & 1u)) fprintf(stderr, "  case %d: T native %u guest %u\n", idx, x.sr & 1u, gs.v[17] & 1u), bad++;
    if (x.fpul != gs.v[VF3_REG_FPUL]) fprintf(stderr, "  case %d: fpul native %08x guest %08x\n", idx, x.fpul, gs.v[VF3_REG_FPUL]), bad++;

    /* FR outputs */
    for (unsigned i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(x.fr[i]) != gs.v[VF3_REG_FR0 + i])
            fprintf(stderr, "  case %d: fr%u native %08x guest %08x\n", idx, i, vf3_aim_ubits(x.fr[i]), gs.v[VF3_REG_FR0 + i]), bad++;
    }

    /* RAM: counter +0x1E, table val +0x1C, floats +0x0C/+0x10/+0x14, flags */
    uint32_t aw[5], bw[5];
    unsigned aoff[] = { 0x1C, 0x1E, 0x0C, 0x10, 0x14 };
    for (unsigned i = 0; i < 5; ++i) {
        if (aoff[i] == 0x1C || aoff[i] == 0x1E) {
            aw[i] = r16_at(n_ram, OBJ + aoff[i]);
            bw[i] = r16_at(g_ram, OBJ + aoff[i]);
        } else {
            aw[i] = r32_at(n_ram, OBJ + aoff[i]);
            bw[i] = r32_at(g_ram, OBJ + aoff[i]);
        }
        if (aw[i] != bw[i]) fprintf(stderr, "  case %d: ram +%02x native %08x guest %08x\n", idx, aoff[i], aw[i], bw[i]), bad++;
    }
    if (r32_at(n_ram, FLAGS) != r32_at(g_ram, FLAGS)) fprintf(stderr, "  case %d: flags native %08x guest %08x\n", idx, r32_at(n_ram, FLAGS), r32_at(g_ram, FLAGS)), bad++;

    free(g_ram); free(n_ram);
    return bad;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    /* 1: normal, fr4=1 non-zero -> the float move runs */
    seed_case(4, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(4, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 1);
    /* 2: normal, flags bit1 (table = r6) */
    seed_case(4, 0x1234, 0x00000002, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(4, 0x1234, 0x00000002, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 2);
    /* 3: normal, flags bit2 (table = [sp]) */
    seed_case(4, 0x1234, 0x00000004, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(4, 0x1234, 0x00000004, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 3);
    /* 4: fr4 = 0 (still) -> the float move is skipped */
    seed_case(4, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(4, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0.0f, 2.0f, 4);
    /* 5: counter 0 -> -1 -> negative path */
    seed_case(0, 0x1234, 0x00000001, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(0, 0x1234, 0x00000001, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 5);
    /* 6: large counter 31 */
    seed_case(31, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(31, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 6);
    /* 7: counter 63 -> wraps to (63&31)=31 */
    seed_case(63, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(63, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 7);
    /* 8: negative float at +0x10, floor at -0.006 */
    seed_case(4, 0x1234, 0x00000000, 1.5f, -10.0f, -1.5f, 0, 0);
    bad += compare_one(4, 0x1234, 0x00000000, 1.5f, -10.0f, -1.5f, 1.0f, 2.0f, 8);
    /* 9: counter with bits above 5 set (still uses low 5) */
    seed_case(33, 0x1234, 0x00000002, 0.5f, 0.5f, 0.5f, 0, 0);
    bad += compare_one(33, 0x1234, 0x00000002, 0.5f, 0.5f, 0.5f, 1.0f, 2.0f, 9);
    /* 10: entry counter 1 -> decremented to exactly 0 (normal path) */
    seed_case(1, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 0, 0);
    bad += compare_one(1, 0x1234, 0x00000000, 1.5f, 2.5f, -1.5f, 1.0f, 2.0f, 10);

    free(ram);
    printf("frame_counter_step_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
