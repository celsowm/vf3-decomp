/* Differential replay of the native matrix store/load leaves
 * (src/native/matrix_io.c, 0x8C03B620 matrix_store / 0x8C03BD80 matrix_load)
 * against the readable guest ports (src/fight/matrix_lib.c,
 * `vf3_matrix_store_entry` / `vf3_matrix_load_entry`).
 *
 * Both sides seed the same flat RAM (the matrix source area, the stack-top
 * pointer and the targets) and the same XMTRX (the guest XF bank
 * v[37..52]); the native carries it as a->xm[16].  Each leaf is call-free,
 * no-FPU-beyond-the-bank and no-stack.  For matrix_store the RAM at the
 * destination and r0/r4 are compared against the guest; for matrix_load the
 * resulting XMTRX (native xm vs guest XF bank) and r4 are compared.  Every
 * other register is checked equal to its entry value. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "matrix_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define MATRIX_SRC  0x0C1A0000u   /* the 16-word source/destination matrix */
#define DST_OBJ     0x0C1B0000u   /* an explicit store target */
#define STK_PTR_ADDR 0x0C19D2ECu  /* *(0x0C19D2E4 + 8), the stack top */
#define STK_PTR_VAL 0x0C1B0200u   /* what the stack-top pointer holds */
#define LOW_END  0x0C190000u
#define HI_END   0x0C1C0000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

/* seed the matrix words at MATRIX_SRC (distinct, so word-order bugs show) */
static void seed_matrix(void)
{
    for (uint32_t i = 0; i < 16; ++i)
        w32(MATRIX_SRC + 4u * i, 0x3F800000u + 0x11111111u * i);
}

struct scenario {
    int is_store;          /* 1 = matrix_store, 0 = matrix_load */
    const char *name;
    uint32_t arg4;         /* r4 */
    uint32_t expect;       /* expected output register (r0/r4 for store, r4 for load) */
};

#define RETURN_PC 0x0c03b600u /*(irrelevant; leaf pops pr)*/

static void seed_scene_ram(void)
{
    memset(ram, 0x39, RAM_SIZE);
    seed_matrix();
    w32(STK_PTR_ADDR, STK_PTR_VAL);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a)
{
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t w = r32(MATRIX_SRC + 4u * i);
        if (s) s->v[37 + i] = w;
        if (a) a->xm[i] = vf3_aim_fbits(w);
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (r4=%08x expect %08x)\n", sc->name, sc->arg4,
           (unsigned)sc->expect);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = sc->arg4;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    gs.v[16] = RETURN_PC;          /* pr */
    gs.v[17] = 0x60000000u;        /* sr */
    gs.v[18] = 0x00024001u;        /* fpscr */
    gs.budget = 4000000u;

    seed_scene_ram();
    seed_xf(&gs, NULL);

    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;

    vf3_family_override = vf3_readable_override;
    const int ok_guest = sc->is_store ? vf3_matrix_store_entry(&gs, &gmap)
                                      : vf3_matrix_load_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    /* re-seed for the native side */
    seed_scene_ram();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    seed_xf(NULL, &a);

    if (sc->is_store) vf3_native_matrix_store(&a);
    else              vf3_native_matrix_load(&a);

    int bad = 0;

    if (sc->is_store) {
        /* r0 and r4 both = the final dest */
        if (a.r[0] != sc->expect) { fprintf(stderr, "  r0 native %08x want %08x\n", a.r[0], sc->expect); bad++; }
        if (a.r[4] != gs.v[4])    { fprintf(stderr, "  r4 native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
        /* the written RAM at the dest matches the guest */
        if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
            fprintf(stderr, "  store RAM region differs from guest\n"); bad++;
        }
        /* every other register untouched */
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 0 || i == 4) continue;
            if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
        }
        /* XMTRX untouched by a store */
        for (uint32_t i = 0; i < 16; ++i) {
            const uint32_t gw = gs.v[37 + i];
            if (vf3_aim_ubits(a.xm[i]) != gw) {
                fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                        vf3_aim_ubits(a.xm[i]), gw); bad++;
            }
        }
    } else {
        /* r4 = src + 64 */
        if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4 native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
        /* XMTRX loaded = the guest's XF bank */
        for (uint32_t i = 0; i < 16; ++i) {
            const uint32_t gw = gs.v[37 + i];
            if (vf3_aim_ubits(a.xm[i]) != gw) {
                fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                        vf3_aim_ubits(a.xm[i]), gw); bad++;
            }
        }
        /* every other register untouched */
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 4) continue;
            if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
        }
        /* a store must not have changed RAM */
        if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
            fprintf(stderr, "  load RAM region differs from guest\n"); bad++;
        }
    }

    free(gshot);
    printf("  matrix_io: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { 1, "store to explicit dest",  DST_OBJ,     DST_OBJ },
        { 1, "store via stack top",     0u,          STK_PTR_VAL },
        { 0, "load from explicit src",  MATRIX_SRC,  MATRIX_SRC + 64u },
        { 0, "load via stack top",      0u,          STK_PTR_VAL + 64u },
        { 1, "store to the source addr",MATRIX_SRC,  MATRIX_SRC },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("matrix_io_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
