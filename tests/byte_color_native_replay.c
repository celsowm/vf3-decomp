/* Differential replay of the native two-byte color scale
 * (src/native/byte_color.c, 0x8C0563AC) against the readable guest port
 * (src/fight/readable/byte_color.c, `vf3_byte_color_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, branch-free FP leaf, so it needs no stub, but its float outputs
 * ride the FR bank and depend on the round-toward-zero FPU, so the native side
 * uses the same fmul/flz wrappers the port uses and the fixture supplies the
 * pool (ptrA/scale/out at 0x0c056504/508/510), the source floats, the packed
 * bytes and the scratch.  The whole RAM region is compared byte for byte,
 * together with the FR bank, the contract integer registers (r0, r1, r2, r4,
 * r5, r6), the FPUL and SR's T bit (untouched, clear). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "byte_color.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_byte_color_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define PTRA_SLOT 0x0c056504u
#define SCALE_SLOT 0x0c056508u
#define OUT_SLOT  0x0c056510u
#define SRC_BASE  0x0c16b000u
#define OUT_BASE  0x0c19d000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16(uint16_t *unused, uint32_t addr)
{
    (void)unused;
    const uint8_t *p = ab(addr);
    return (uint16_t)(p[0] | ((uint16_t)p[1] << 8));
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t ptr_off, out_off;   /* offsets into SRC_BASE / OUT_BASE */
    uint32_t r4_off, r1_off;     /* r4_in, r1_in values (absolute) */
    uint32_t src[3];
    uint32_t scale;
    uint16_t lo, hi;
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    for (uint32_t ad = RAM_BASE; ad < RAM_BASE + RAM_SIZE; ad += 4)
        w32(ad, 0x22222222u + (ad & 0xff));

    const uint32_t ptrA = SRC_BASE + sc->ptr_off;
    const uint32_t out = OUT_BASE + sc->out_off;
    w32(PTRA_SLOT, ptrA);
    w32(SCALE_SLOT, sc->scale);
    w32(OUT_SLOT, out);
    for (unsigned i = 0; i < 3; ++i)
        w32(ptrA + i * 4u, sc->src[i]);
    const uint32_t r4 = sc->r4_off;
    w16(r4 + 4u, sc->lo);
    w16(r4 + 6u, sc->hi);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[1] = sc->r1_off;
    s->v[4] = sc->r4_off;
    s->v[15] = OUT_BASE + 0x900;
    s->v[16] = 0x0c0563fau;             /* pr */
    s->v[17] = 0x60000000u;             /* sr, T clear */
    s->v[18] = 0x00040001u;             /* fpscr: single precision, RM bit 0 */
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    /* ---- guest side ---- */
    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_byte_color_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2];
    const uint32_t gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6];
    const uint32_t gfpul = gs.v[53], g_sr = gs.v[17];
    /* guest FR bank (single precision) */
    float gfr[3];
    gfr[0] = vf3_fr_get(&gs, 0);
    gfr[1] = vf3_fr_get(&gs, 1);
    gfr[2] = vf3_fr_get(&gs, 2);

    /* snapshot the guest's RAM over the compared region before the native
     * side re-seeds it */
    const uint32_t cmp_lo = 0x0c056000u, cmp_hi = 0x0c1a0000u;
    uint8_t *gshot = (uint8_t *)malloc(cmp_hi - cmp_lo);
    memcpy(gshot, ram + (cmp_lo - RAM_BASE), cmp_hi - cmp_lo);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) a.fr[i] = vf3_aim_fbits(0x76543225u + i);
    a.r[1] = sc->r1_off;
    a.r[4] = sc->r4_off;
    a.pr = 0x0c0563fau;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    vf3_native_byte_color(&a, OUT_BASE + 0x900);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run, over pool + src + out */
    {
        int nb = 0;
        for (uint32_t ad = cmp_lo; ad < cmp_hi; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - cmp_lo), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", cmp_lo, cmp_hi, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* the network-independent FR outputs vs the guest's bank */
    {
        int nb = 0;
        if (a.fr[0] != gfr[0]) { fprintf(stderr, "  fr0: native %08x guest %08x\n",
            vf3_aim_ubits(a.fr[0]), vf3_aim_ubits(gfr[0])); nb++; }
        if (a.fr[1] != gfr[1]) { fprintf(stderr, "  fr1: native %08x guest %08x\n",
            vf3_aim_ubits(a.fr[1]), vf3_aim_ubits(gfr[1])); nb++; }
        if (a.fr[2] != gfr[2]) { fprintf(stderr, "  fr2: native %08x guest %08x\n",
            vf3_aim_ubits(a.fr[2]), vf3_aim_ubits(gfr[2])); nb++; }
        printf("  fr0/1/2: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract integer registers + FPUL + T bit */
    {
        int nb = 0;
        if (a.r[0] != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); nb++; }
        if (a.r[1] != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gr1); nb++; }
        if (a.r[2] != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], gr2); nb++; }
        if (a.r[4] != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); nb++; }
        if (a.r[5] != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gr5); nb++; }
        if (a.r[6] != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gr6); nb++; }
        if (a.fpul != gfpul) { fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the byte-channel outcome against the fixture */
    {
        const uint32_t c_r2 = sc->lo & 0xffu;
        const uint32_t c_r5 = (sc->lo >> 8u) & 0xffu;
        const uint32_t c_r6 = sc->hi & 0xffu;
        const uint32_t out = OUT_BASE + sc->out_off;
        int nb = 0;
        if (a.r[2] != c_r2 || a.r[5] != c_r5 || a.r[6] != c_r6 ||
            a.fpul != c_r6 || a.r[0] != 0x0c056508u ||
            a.r[1] != out - 8u || a.r[4] != sc->r4_off + 8u) {
            fprintf(stderr, "  byte registers/answers wrong\n"); nb++;
        }
        printf("  outcome: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("byte_color_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "single, all channels",
          .ptr_off = 0x800, .out_off = 0x810, .r4_off = 0x0c19d830u, .r1_off = 0x0c19d840u,
          .src = { 0x3f800000u, 0x40000000u, 0x40800000u }, .scale = 0x3b808080u,
          .lo = 0x0d34u, .hi = 0x00cdu },
        { .name = "single, zero bytes",
          .ptr_off = 0x900, .out_off = 0x820, .r4_off = 0x0c19d900u, .r1_off = 0x0c19d910u,
          .src = { 0x3f800000u, 0x3f800000u, 0x3f800000u }, .scale = 0x3b808080u,
          .lo = 0x0000u, .hi = 0x0000u },
        { .name = "single, max bytes",
          .ptr_off = 0xa00, .out_off = 0x830, .r4_off = 0x0c19da00u, .r1_off = 0x0c19da10u,
          .src = { 0x41200000u, 0x40a00000u, 0x40400000u }, .scale = 0x3b808080u,
          .lo = 0xffffu, .hi = 0xffffu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("byte_color_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
