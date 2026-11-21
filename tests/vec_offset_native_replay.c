/* Differential replay of the native offset-adders (src/native/vec_offset.c,
 * 0x8C074702 vec_offset / 0x8C074854 vec_offset3) against the readable guest
 * ports (src/fight/vec_offset.c `vf3_vec_offset_entry` and
 * src/fight/vec_offset3.c `vf3_vec_offset3_entry`).
 *
 * Both sides seed the same flat RAM (the record at r4 with its offsets,
 * position/vector fields and the pointed-to list) and the same FR/register
 * file, then run the leaf.  The leaves are call-free FP loops; each adds a
 * stored offset to the record's own position/vector and to every point of a
 * list.  The test compares the RAM the leaf writes (the record's fields and
 * the whole list, byte for byte), the output registers (r0, r5, r6), SR's T
 * bit, the FR-bank outputs the leaf writes (fr2..fr6), an independent fixture
 * model that recomputes every point, and the untouched registers/FR. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vec_offset.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vec_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_offset3_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define REC_A      0x0C112000u   /* vec_offset record */
#define REC_B      0x0C113000u   /* vec_offset3 record */
#define LIST_A     0x0C114000u   /* vec_offset 12-byte list */
#define LIST_B     0x0C116000u   /* vec_offset3 64-byte list */
#define SP0        0x0C11B000u

#define RETURN_PC_A 0x0c074718u
#define RETURN_PC_B 0x0c074870u

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
static float f2(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

static void seed_vec_offset(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* offset (x,z) at +0x13A8 / +0x13B0 */
    wf(REC_A + 0x13A8u, 2.5f);
    wf(REC_A + 0x13B0u, -1.25f);
    /* own position (x,z) at +0x1488 / +0x1490 */
    wf(REC_A + 0x1488u, 10.0f);
    wf(REC_A + 0x1490u, 20.0f);
    /* list pointer at +0x138C, 0x150 bytes of 12-byte points */
    w32(REC_A + 0x138Cu, LIST_A);
    for (int i = 0; i < 28; ++i) {
        wf(LIST_A + 12u * i + 0u, (float)(100 + i));
        wf(LIST_A + 12u * i + 8u, (float)(-i));
    }
}

static void seed_vec_offset3(void)
{
    memset(ram, 0x6c, RAM_SIZE);
    /* offset (x,y,z) at +0x1488 / +0x148C / +0x1490 */
    wf(REC_B + 0x1488u, 1.0f);
    wf(REC_B + 0x148Cu, 2.0f);
    wf(REC_B + 0x1490u, 3.0f);
    /* own vector at +0x10 .. +0x18 */
    wf(REC_B + 0x10u, 5.0f);
    wf(REC_B + 0x14u, 6.0f);
    wf(REC_B + 0x18u, 7.0f);
    /* the 25 points of 64 bytes each at +0x180, fields +0x30/+0x34/+0x38 */
    for (int i = 0; i < 25; ++i) {
        wf(REC_B + 0x180u + 64u * i + 0x30u, (float)(i));
        wf(REC_B + 0x180u + 64u * i + 0x34u, (float)(i * 2));
        wf(REC_B + 0x180u + 64u * i + 0x38u, (float)(i * 3));
    }
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        int three, uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = three ? REC_B : REC_A;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) fr_in[i] = s->v[VF3_REG_FR0 + i];
    s->v[16] = three ? RETURN_PC_B : RETURN_PC_A;   /* pr */
    s->v[17] = 0x60000000u;    /* SR: T clear (the leaves set it) */
    s->v[18] = 0x00024001u;    /* FPSCR: truncate (RM), FTZ */
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

static void check_regs(int three, const vf3_native_aim *a, const vf3_matrix_state *gs,
                       const uint32_t *in_v, int *bad)
{
    /* output registers the leaf leaves: r0, r5, r6 */
    if (a->r[0] != gs->v[0]) fprintf(stderr, "  r0: native %08x guest %08x\n", a->r[0], gs->v[0]), (*bad)++;
    if (a->r[5] != gs->v[5]) fprintf(stderr, "  r5: native %08x guest %08x\n", a->r[5], gs->v[5]), (*bad)++;
    if (a->r[6] != gs->v[6]) fprintf(stderr, "  r6: native %08x guest %08x\n", a->r[6], gs->v[6]), (*bad)++;
    if (a->r[4] != in_v[4]) fprintf(stderr, "  r4: native %08x entry %08x\n", a->r[4], in_v[4]), (*bad)++;
    if ((a->sr & 1u) != (gs->v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a->sr & 1u, gs->v[17] & 1u); (*bad)++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 4 || i == 5 || i == 6) continue;
        if (a->r[i] != in_v[i]) fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a->r[i], in_v[i]), (*bad)++;
    }
    /* FR-bank outputs the leaves write: fr2..fr6 for both */
    for (unsigned i = 2; i <= 6; ++i) {
        uint32_t g = gs->v[VF3_REG_FR0 + i];
        if (vf3_aim_ubits(a->fr[i]) != g) {
            fprintf(stderr, "  fr%u: native %08x guest %08x\n", i, vf3_aim_ubits(a->fr[i]), g); (*bad)++;
        }
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i >= 2 && i <= 6) continue;
        if (vf3_aim_ubits(a->fr[i]) != in_v[VF3_REG_FR0 + i]) {
            fprintf(stderr, "  fr%u(untouched): native %08x entry %08x\n", i, vf3_aim_ubits(a->fr[i]), in_v[VF3_REG_FR0 + i]); (*bad)++;
        }
    }
}

static void check_ram_bytes(int three, const vf3_native_aim *a, int *bad)
{
    if (!three) {
        static const uint32_t addrs[] = {
            REC_A + 0x1488u, REC_A + 0x1490u
        };
        for (unsigned e = 0; e < sizeof addrs / sizeof addrs[0]; ++e) {
            if (vf3_aim_u32(a, addrs[e]) != r32(addrs[e])) {
                fprintf(stderr, "  ram rec @%08x: native %08x readback %08x\n", addrs[e], vf3_aim_u32(a, addrs[e]), r32(addrs[e])); (*bad)++;
            }
        }
        /* the whole 12-byte x 28 list */
        for (int i = 0; i < 28; ++i) {
            uint32_t addr = LIST_A + 12u * i;
            for (int o = 0; o < 12; o += 4) {
                if (vf3_aim_u32(a, addr + o) != r32(addr + o)) {
                    fprintf(stderr, "  list @%08x: native %08x readback %08x\n", addr + o, vf3_aim_u32(a, addr + o), r32(addr + o)); (*bad)++;
                }
            }
        }
    } else {
        static const uint32_t addrs[] = { REC_B + 0x10u, REC_B + 0x14u, REC_B + 0x18u };
        for (unsigned e = 0; e < sizeof addrs / sizeof addrs[0]; ++e) {
            if (vf3_aim_u32(a, addrs[e]) != r32(addrs[e])) {
                fprintf(stderr, "  ram rec @%08x: native %08x readback %08x\n", addrs[e], vf3_aim_u32(a, addrs[e]), r32(addrs[e])); (*bad)++;
            }
        }
        for (int i = 0; i < 25; ++i) {
            uint32_t base = REC_B + 0x180u + 64u * i;
            for (int o = 0x30; o <= 0x38; o += 4) {
                if (vf3_aim_u32(a, base + o) != r32(base + o)) {
                    fprintf(stderr, "  list @%08x: native %08x readback %08x\n", base + o, vf3_aim_u32(a, base + o), r32(base + o)); (*bad)++;
                }
            }
        }
    }
}

static int compare_one(int three)
{
    printf("== %s\n", three ? "vec_offset3" : "vec_offset");
    if (three) seed_vec_offset3(); else seed_vec_offset();

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54], fr_in[16];
    setup_guest(&gs, &gmap, gwin, three, in_v, fr_in);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = three ? vf3_vec_offset3_entry(&gs, &gmap) : vf3_vec_offset_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* the native runs on the same RAM/regs */
    if (three) seed_vec_offset3(); else seed_vec_offset();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = three ? RETURN_PC_B : RETURN_PC_A;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(fr_in[i]);
    if (three) vf3_native_vec_offset3(&a);
    else       vf3_native_vec_offset(&a);

    int bad = 0;
    check_regs(three, &a, &gs, in_v, &bad);
    check_ram_bytes(three, &a, &bad);

    /* independent fixture model: recompute every point by adding the offset.
     * The model derives the expectation from the *seed* values (the RAM has
     * already been modified in place by the leaf), so it uses the same
     * deterministic constants the seed wrote, plus a guaranteed-distinct
     * offset, and compares against the native's written RAM. */
    if (three) {
        const float ox = 1.0f, oy = 2.0f, oz3 = 3.0f;
        uint32_t wex, wey, wez;
        { float p = 5.0f + ox, q = 6.0f + oy, r = 7.0f + oz3; memcpy(&wex, &p, 4); memcpy(&wey, &q, 4); memcpy(&wez, &r, 4); }
        if (vf3_aim_u32(&a, REC_B + 0x10u) != wex || vf3_aim_u32(&a, REC_B + 0x14u) != wey || vf3_aim_u32(&a, REC_B + 0x18u) != wez) {
            fprintf(stderr, "  model own vec: native %08x/%08x/%08x model %08x/%08x/%08x\n",
                vf3_aim_u32(&a, REC_B + 0x10u), vf3_aim_u32(&a, REC_B + 0x14u), vf3_aim_u32(&a, REC_B + 0x18u),
                wex, wey, wez); bad++;
        }
        int nb = 0;
        for (int i = 0; i < 25; ++i) {
            uint32_t base = REC_B + 0x180u + 64u * i;
            float x = (float)i, y = (float)(2 * i), z = (float)(3 * i);
            float wx = x + ox, wy = y + oy, wz = z + oz3;
            uint32_t a1, b1, c1; memcpy(&a1, &wx, 4); memcpy(&b1, &wy, 4); memcpy(&c1, &wz, 4);
            if (vf3_aim_u32(&a, base + 0x30u) != a1) fprintf(stderr, "  model[%d].x: native %08x model %08x\n", i, vf3_aim_u32(&a, base + 0x30u), a1), nb++;
            if (vf3_aim_u32(&a, base + 0x34u) != b1) fprintf(stderr, "  model[%d].y: native %08x model %08x\n", i, vf3_aim_u32(&a, base + 0x34u), b1), nb++;
            if (vf3_aim_u32(&a, base + 0x38u) != c1) fprintf(stderr, "  model[%d].z: native %08x model %08x\n", i, vf3_aim_u32(&a, base + 0x38u), c1), nb++;
        }
        printf("  model: %s%s\n", nb ? "DIFFERS " : "match ", (wex==vf3_aim_u32(&a,REC_B+0x10u) && wey==vf3_aim_u32(&a,REC_B+0x14u) && wez==vf3_aim_u32(&a,REC_B+0x18u)) ? "own-ok" : "own-DIFFERS");
        bad |= nb != 0;
        if (wex!=vf3_aim_u32(&a,REC_B+0x10u) || wey!=vf3_aim_u32(&a,REC_B+0x14u) || wez!=vf3_aim_u32(&a,REC_B+0x18u)) bad++;
    } else {
        const float ox = 2.5f, oz = -1.25f;
        uint32_t wex, wez; { float p = 10.0f + ox, q = 20.0f + oz; memcpy(&wex, &p, 4); memcpy(&wez, &q, 4); }
        if (vf3_aim_u32(&a, REC_A + 0x1488u) != wex || vf3_aim_u32(&a, REC_A + 0x1490u) != wez) {
            fprintf(stderr, "  model own: native %08x/%08x model %08x/%08x\n",
                vf3_aim_u32(&a, REC_A + 0x1488u), vf3_aim_u32(&a, REC_A + 0x1490u), wex, wez); bad++;
        }
        int nb = 0;
        for (int i = 0; i < 28; ++i) {
            uint32_t base = LIST_A + 12u * i;
            float x = (float)(100 + i), z = (float)(-i);
            float wx = x + ox, wz = z + oz;
            uint32_t a1, b1; memcpy(&a1, &wx, 4); memcpy(&b1, &wz, 4);
            if (vf3_aim_u32(&a, base) != a1) fprintf(stderr, "  model[%d].x: native %08x model %08x\n", i, vf3_aim_u32(&a, base), a1), nb++;
            if (vf3_aim_u32(&a, base + 8u) != b1) fprintf(stderr, "  model[%d].z: native %08x model %08x\n", i, vf3_aim_u32(&a, base + 8u), b1), nb++;
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb != 0;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    int bad = 0;
    bad |= compare_one(0);
    bad |= compare_one(1);

    free(ram);
    printf("vec_offset_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
