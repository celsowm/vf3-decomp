/* Differential replay of the native aim step leaf (src/native/aim_step.c,
 * 0x8C093768) against the readable guest port (src/fight/aim_step.c,
 * `vf3_aim_step_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf pushes a point A along the
 * direction between A and B: with d = A - B, it stores the unit direction to
 * *r7 and writes A = d * (inverse length * step) + B back to A.
 *
 * The literal pool and the frame sit at the game's own addresses, spanned by
 * one flat buffer.  The whole region is compared byte for byte, together with
 * the registers, the FR bank and SR's T bit, and the stored A / unit direction
 * against an independent fixture model worked out with the same FPU primitives
 * the guest uses.
 *
 * The leaf runs under round-to-nearest and no FTZ (FPSCR 0, like the sibling
 * move_cap leaf), so the native uses plain C float ops and `1/sqrtf`. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "aim_step.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_aim_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define LIT_BITS 0x33d6bf94u

#define RAM_BASE 0x0c104000u
#define RAM_SIZE 0x4000u
#define STACK_TOP 0x0c108000u

#define A_ADDR 0x0c104000u
#define B_ADDR 0x0c104010u
#define OUT_ADDR 0x0c104020u
#define CTX_ADDR 0x0c104100u

struct scenario {
    const char *name;
    /* A, B, step length bits */
    uint32_t ax, ay, az, bx, by, bz, step;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t fb(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bf(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w32(A_ADDR, sc->ax); w32(A_ADDR + 4, sc->ay); w32(A_ADDR + 8, sc->az);
    w32(B_ADDR, sc->bx); w32(B_ADDR + 4, sc->by); w32(B_ADDR + 8, sc->bz);
    w32(CTX_ADDR + 36, sc->step);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        int flags)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = CTX_ADDR;
    s->v[5] = A_ADDR;
    s->v[6] = B_ADDR;
    s->v[7] = OUT_ADDR;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;                     /* FPSCR: RN, no FTZ */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ab(RAM_BASE);
    map->wins = win;
    map->n = 1;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the expected results, worked out from the fixture with the guest's FPU
 * primitives (fpscr 0) */
static void expect(const struct scenario *sc,
                   uint32_t *out_ax, uint32_t *out_ay, uint32_t *out_az,
                   uint32_t *out_ux, uint32_t *out_uy, uint32_t *out_uz)
{
    const uint32_t fpscr = 0;
    const float ax = bf(sc->ax), ay = bf(sc->ay), az = bf(sc->az);
    const float bx = bf(sc->bx), by = bf(sc->by), bz = bf(sc->bz);
    const float step = bf(sc->step);

    const float dx = ax - bx;
    const float dy = ay - by;
    const float dz = az - bz;

    /* fipr: the inner product accumulated in double, flushed to float */
    volatile double d0 = (double)dx * (double)dx;
    d0 += (double)dy * (double)dy;
    d0 += (double)dz * (double)dz;
    const float sq = (float)d0;

    float inv = 0.0f;
    if (sq != 0.0f) {
        const float eps = bf(LIT_BITS);
        if (!(eps > sq)) inv = 1.0f / sqrtf(sq);
    }

    const float scaled = inv * step;
    *out_ax = fb(dx * scaled + bx);
    *out_ay = fb(dy * scaled + by);
    *out_az = fb(dz * scaled + bz);
    *out_ux = fb(dx * inv);
    *out_uy = fb(dy * inv);
    *out_uz = fb(dz * inv);
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
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, 0);
    uint32_t in_v[54];
    memcpy(in_v, gs.v, sizeof in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_aim_step_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &in_v[21u + i], 4);
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    a.r[15] = STACK_TOP;
    a.fpul = in_v[53];
    vf3_native_aim_step(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < RAM_BASE + RAM_SIZE; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, RAM_BASE + RAM_SIZE, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* registers + FR bank + T bit + model */
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

        uint32_t eax, eay, eaz, eux, euy, euz;
        expect(sc, &eax, &eay, &eaz, &eux, &euy, &euz);
        if (r32(A_ADDR) != eax || r32(A_ADDR + 4) != eay || r32(A_ADDR + 8) != eaz) {
            fprintf(stderr, "  A native %08x/%08x/%08x expected %08x/%08x/%08x\n",
                    r32(A_ADDR), r32(A_ADDR + 4), r32(A_ADDR + 8), eax, eay, eaz);
            nb++;
        }
        if (r32(OUT_ADDR) != eux || r32(OUT_ADDR + 4) != euy || r32(OUT_ADDR + 8) != euz) {
            fprintf(stderr, "  unit native %08x/%08x/%08x expected %08x/%08x/%08x\n",
                    r32(OUT_ADDR), r32(OUT_ADDR + 4), r32(OUT_ADDR + 8), eux, euy, euz);
            nb++;
        }
        if (a.r[4] != A_ADDR) { fprintf(stderr, "  r4 %08x != A\n", a.r[4]); nb++; }
        if (a.r[5] != B_ADDR + 12u) { fprintf(stderr, "  r5 %08x != B+12\n", a.r[5]); nb++; }

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
        { "zero d", 2u, 3u, 4u, 2u, 3u, 4u, 0x3f800000u },
        { "below eps", 0u, 0u, 0u, 0u, 0u, 1u, 0x40000000u },
        { "x axis", 0u, 0u, 0u, 0u, 0u, 0u, 0x40400000u },
        { "diagonal fwd", 0u, 0u, 0u, 0x40400000u, 0x40800000u, 0x3f800000u, 0x40a00000u },
        { "diagonal back", 0x40400000u, 0x40800000u, 0x3f800000u, 0u, 0u, 0u, 0x40200000u },
        { "neg step", 0x3f800000u, 0x40000000u, 0x40400000u, 0x3fc00000u, 0x40200000u, 0x40600000u, 0xc0000000u },
        { "neg coords", 0xc0400000u, 0xc0800000u, 0xc0a00000u, 0x3f800000u, 0x40000000u, 0x40400000u, 0x40800000u },
        { "big", 0x447a0000u, 0x44fa0000u, 0x453b8000u, 0x3f800000u, 0x40000000u, 0x40400000u, 0x40e00000u },
        { "short step", 0x3f800000u, 0x40000000u, 0x40400000u, 0x3fc00000u, 0x40200000u, 0x40600000u, 0x358637bdu },
        { "inexact", 0x3f800000u, 0x40000000u, 0x40400000u, 0x3f333333u, 0x3fa66666u, 0x3dcccccdu, 0x38d1b717u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("aim_step_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
