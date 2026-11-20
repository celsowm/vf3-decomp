/* Differential replay of the native unsigned-32-to-float scale
 * (src/native/float_scale.c, 0x8C039C50 / 0x8C039C70) against the readable
 * guest ports (src/fight/float_scale.c, `vf3_float_scale_a_entry` /
 * `vf3_float_scale_b_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf reads one 32-bit value
 * through a literal-pool pointer, converts it to a float, folds the sign bit
 * back in with the 2^32 addition when it is set, scales by 1.28 read from the
 * pool, and returns the truncated integer in r0 and FPUL.  The two entries
 * differ only in which pool pointer names the value, so they share the
 * scenarios.
 *
 * The pool and the data sit at the game's own addresses, spanned by one flat
 * buffer.  The whole region is compared byte for byte, together with the
 * registers, the FR bank, FPUL and the T bit, and the answer against an
 * independent fixture model.  The values cover the two paths of the sign-bit
 * fold and the truncation. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "float_scale.h"

#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_float_scale_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_float_scale_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY_A 0x0c039c50u
#define ENTRY_B 0x0c039c70u

#define POOL_BASE 0x0c039000u
#define POOL_LEN  0x1000u
#define DATA_BASE 0x0c300000u
#define DATA_LEN  0x1000u
#define CMP_HI    (DATA_BASE + DATA_LEN)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define P_P1_A 0x0c039d4cu
#define P_P1_B 0x0c039d58u
#define P_PLUS 0x0c039d50u
#define P_SCALE 0x0c039d54u

#define VAL_A_OFF 0x100u
#define VAL_B_OFF 0x104u

#define FPSCR 0x00040001u

#define NWIN 2

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
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static float ft0(float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = (op == '*') ? (x * y) : (x + y);
    fesetround(saved);
    return z;
}
static float flz(float f)
{
    uint32_t u = fbits(f);
    if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
    float out;
    memcpy(&out, &u, 4);
    return out;
}

static void seed_all(uint32_t val_a, uint32_t val_b)
{
    memset(ram, 0, RAM_SIZE);

    w32(P_P1_A, DATA_BASE + VAL_A_OFF);
    w32(P_P1_B, DATA_BASE + VAL_B_OFF);
    w32(P_PLUS, 0x4f800000u);   /* 4294967296.0f */
    w32(P_SCALE, 0x3fa3d70au);  /* 1.28f */

    w32(DATA_BASE + VAL_A_OFF, val_a);
    w32(DATA_BASE + VAL_B_OFF, val_b);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x60000000u;
    s->v[18] = FPSCR;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { DATA_BASE, DATA_LEN },
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

/* the fixture-based model, straight from the value through the SH-4 FPU path */
static uint32_t model(uint32_t val, uint32_t *t_out, uint32_t *fr3_out, uint32_t *fr2_out)
{
    const int32_t v = (int32_t)val;
    float f;
    {
        const int saved2 = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float conv = (float)v;
        fesetround(saved2);
        f = conv;
    }
    if (v < 0)
        f = flz(ft0(f, 4294967296.0f, '+'));
    const float scale = 1.28f;
    f = flz(ft0(f, scale, '*'));
    *t_out = (uint32_t)(v >= 0);
    *fr3_out = fbits(f);
    *fr2_out = fbits(scale);
    /* FTRC: the SH-4 saturates at the int32 bounds */
    {
        double d = (double)f;
        if (isnan(d) || d < -2147483648.0) return 0x80000000u;
        if (d >= 2147483648.0) return 0x7fffffffu;
        return (uint32_t)(int32_t)d;
    }
}

static int compare_one(uint32_t entry, uint32_t pool_p1, uint32_t val_addr,
                       uint32_t val, const char *name)
{
    printf("== %s\n", name);

    seed_all(val, val);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    uint32_t in_v[54];
    memcpy(in_v, gs.v, sizeof in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = (entry == ENTRY_A)
        ? vf3_float_scale_a_entry(&gs, &gmap)
        : vf3_float_scale_b_entry(&gs, &gmap);
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
        memcpy(&a.fr[i], &in_v[21u + i], 4);
    a.pr = 0x0c0abcdeu;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    a.r[15] = 0x0c108000u;
    a.fpul = 0x76543210u + 53u;
    vf3_native_float_scale(&a, pool_p1);
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
            if (ub != gs.v[21u + i]) {
                fprintf(stderr, "  fr%u: native %08x want %08x\n", i, ub, gs.v[21u + i]);
                nb++;
            }
        }

        uint32_t t_want = 0, fr3_want = 0, fr2_want = 0;
        const uint32_t want = model(val, &t_want, &fr3_want, &fr2_want);
        if (a.r[0] != want || a.fpul != want) {
            fprintf(stderr, "  r0/fpul %08x/%08x, expected %08x\n", a.r[0], a.fpul, want);
            nb++;
        }
        if ((a.sr & 1u) != (t_want & 1u)) {
            fprintf(stderr, "  T: native %u want %u\n", a.sr & 1u, t_want & 1u);
            nb++;
        }
        if (fbits(a.fr[3]) != fr3_want || fbits(a.fr[2]) != fr2_want) {
            fprintf(stderr, "  fr3/fr2 %08x/%08x, want %08x/%08x\n",
                    fbits(a.fr[3]), fbits(a.fr[2]), fr3_want, fr2_want);
            nb++;
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

    static const struct { const char *name; uint32_t val; } vals[] = {
        { "zero", 0x00000000u },
        { "a small positive", 0x00000005u },
        { "a small negative", 0xfffffffbU },
        { "one", 0x00000001u },
        { "a mid positive", 0x00000f00u },
        { "near int32 max", 0x7fffffffu },
        { "int32 min", 0x80000000u },
        { "near int32 min", 0x80000001u },
        { "a large negative", 0xffff0000u },
        { "one past the sign", 0x80010000u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof vals / sizeof vals[0]; ++i) {
        bad |= compare_one(ENTRY_A, P_P1_A, DATA_BASE + VAL_A_OFF, vals[i].val, vals[i].name);
        bad |= compare_one(ENTRY_B, P_P1_B, DATA_BASE + VAL_B_OFF, vals[i].val, vals[i].name);
    }

    free(ram);
    printf("float_scale_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
