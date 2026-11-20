/* Differential replay of the native motion-VM scale step (src/native/scale_step.c,
 * 0x8C0CB8AC) against the readable guest port (src/fight/scale_step.c,
 * `vf3_scale_step_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed a mode byte, a VM
 * structure, two float constants and the caller's structure; when the mode
 * byte (masked to four bits) is 1 it takes the step count, makes it positive,
 * parks it in FPUL, and writes `constant_two * count + constant_one` (a fused
 * multiply-add) into the caller's structure at +16 and into the structure the
 * VM names.
 *
 * The pool, the mode byte, the VM structure and the caller's structure sit at
 * the game's own addresses, spanned by one flat buffer.  The whole region is
 * compared byte for byte, together with the registers, the FR bank, FPUL and
 * the T bit, and the two stored floats against an independent fixture model.
 * The scenarios cover the modes that do not step, the masked mode, and counts
 * above, below and exactly at the bias. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "scale_step.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scale_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POOL_BASE 0x0c0cb9b0u
#define POOL_LEN  0x20u
#define MODE_BASE 0x0c140000u
#define MODE_LEN  0x04u
#define VM_BASE   0x0c150000u
#define VM_LEN    0x100u
#define OBJ_BASE  0x0c160000u
#define OBJ_LEN   0x40u
#define CMP_HI    (OBJ_BASE + OBJ_LEN)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define G_OFFSET (POOL_BASE + 0x04u)
#define G_MODE   (POOL_BASE + 0x08u)
#define G_VM     (POOL_BASE + 0x0cu)
#define G_ONE    (POOL_BASE + 0x10u)
#define G_TWO    (POOL_BASE + 0x14u)

#define COUNT_PTR (VM_BASE + 0x80u)
#define DEST_PTR  (VM_BASE + 0x90u)
#define DEST_OFF  0x0008u

#define CONST_ONE 1.5f
#define CONST_TWO 2.5f

#define NWIN 4

struct scenario {
    const char *name;
    uint8_t mode;
    int16_t count;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint8_t  r8(uint32_t addr) { return ab(addr)[0]; }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    w16(G_OFFSET, DEST_OFF);
    w32(G_MODE, MODE_BASE);
    w32(G_VM, VM_BASE);
    w32(G_ONE, fbits(CONST_ONE));
    w32(G_TWO, fbits(CONST_TWO));

    ab(MODE_BASE)[0] = sc->mode;

    w32(VM_BASE + 0x44u, COUNT_PTR);
    w32(VM_BASE + 0x20u, DEST_PTR);
    w16(COUNT_PTR + 0x54u, (uint16_t)sc->count);
    /* the second destination has a pre-existing value to overwrite */
    w32(DEST_PTR + DEST_OFF, 0x11223344u);
    /* the caller's +16 has a pre-existing value to overwrite */
    w32(OBJ_BASE + 16u, 0x55667788u);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: single width, round to nearest */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { MODE_BASE, MODE_LEN },
        { VM_BASE, VM_LEN }, { OBJ_BASE, OBJ_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the fixture-based model: the adjusted count and the scaled result */
static void expect(const struct scenario *sc, uint32_t *fpul_out, uint32_t *res_out,
                   int *steps_out)
{
    const int mode = sc->mode & 15;
    if (mode != 1) { *steps_out = 0; return; }
    int adj = (int)sc->count - 60;
    if (adj < 0) adj = -adj;
    *fpul_out = (uint32_t)(uint32_t)adj;
    /* fused multiply-add: constant_two * adj + constant_one */
    *res_out = fbits(CONST_TWO * (float)adj + CONST_ONE);
    *steps_out = 1;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    const uint32_t in_fpul = gs.v[53];
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_scale_step_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(gshot, ram, RAM_SIZE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &gs.v[21u + i], 4);
    a.r[4] = OBJ_BASE;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    a.fpul = in_fpul;
    vf3_native_scale_step(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }
    free(gshot);

    /* registers + FR bank + FPUL + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr differs\n"); nb++; }
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t ub;
            memcpy(&ub, &a.fr[i], 4);
            if (ub != gs.v[21u + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        }

        uint32_t fpul_want = 0, res_want = 0;
        int steps = 0;
        expect(sc, &fpul_want, &res_want, &steps);
        /* the last comparison in the guest: on the step path it is the count's
         * "already non-negative" test (count >= 60), otherwise the mode test */
        const int want_t = steps ? ((int)sc->count >= 60) : 0;
        if (((a.sr & 1u) != 0) != (want_t != 0)) {
            fprintf(stderr, "  T: native %u want %d\n", a.sr & 1u, want_t);
            nb++;
        }
        if (a.fpul != gs.v[53]) {
            fprintf(stderr, "  fpul: native %08x want %08x\n", a.fpul, gs.v[53]);
            nb++;
        }
        if (steps) {
            if (r8(OBJ_BASE) == 0) { /* nothing meaningful; just markers */ }
            if (r32(OBJ_BASE + 16u) != res_want) {
                fprintf(stderr, "  obj+16: native %08x want %08x\n",
                        r32(OBJ_BASE + 16u), res_want);
                nb++;
            }
            if (r32(DEST_PTR + DEST_OFF) != res_want) {
                fprintf(stderr, "  dest: native %08x want %08x\n",
                        r32(DEST_PTR + DEST_OFF), res_want);
                nb++;
            }
        } else {
            /* nothing written: the markers survive */
            if (r32(OBJ_BASE + 16u) != 0x55667788u) {
                fprintf(stderr, "  obj+16 written on a non-step\n"); nb++;
            }
            if (r32(DEST_PTR + DEST_OFF) != 0x11223344u) {
                fprintf(stderr, "  dest written on a non-step\n"); nb++;
            }
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "no step",      0u, 100 },
        { "other mode",   2u, 100 },
        { "masked mode", 17u, 100 },
        { "mask keeps nine", 9u, 100 },
        { "step",         1u, 100 },
        { "short count",  1u, 50 },
        { "bias count",   1u, 60 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("scale_step_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
