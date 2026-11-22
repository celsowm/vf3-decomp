/* poly_header_sq_native_replay.c - differential replay of the native
 * poly_header_sq (0x8C055E00, src/native/poly_header_sq.c,
 * `vf3_native_poly_header_sq`) against the readable guest port
 * (src/fight/poly_header_sq.c, `vf3_poly_header_sq_entry`).
 *
 * The leaf writes one polygon header (two 16-byte halves) into the store-queue
 * slot the GBR block points at, and leaves the next slot in r12.  Its
 * observable, flat-RAM contract is the RAM written at `dst` (the pointer the
 * GBR block holds), the register file (r0..r6, r12) and SR's T bit.  The
 * QACR0/QACR1 device writes are swallowed by a no-op device_write hook on the
 * guest side (they do not live in RAM), and PREF never fires because `dst` is
 * a RAM pointer.
 *
 * Both sides seed the same flat RAM (the mode flag, the tag word, the SQ
 * state, the shading template, the GBR block, the source record and the
 * fixture region), the same GBR and the same entry registers, then run.  The
 * whole RAM region, r0..r6, r12 and SR's T bit are compared byte/bit for
 * bit - there is no FPU, so no tolerance is needed.  pr is untouched by the
 * body. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "poly_header_sq.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority */
int vf3_poly_header_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define SP 0x0C20FF00u

#define MODE_FLAG 0x0C055B80u
#define TAG_WORD  0x0C055B84u
#define SQ_STATE  0x0C16CA08u
#define TEMPLATE  0x0C16B820u

#define GBR       0x0C050000u
#define SRC       0x0C300000u
#define DST       0x0C200000u
#define DST_TAG   0x0C201000u
#define SQ_TARGET 0x0C16CA40u   /* what SQ_STATE points at */

static uint8_t *ram;
static uint8_t *at(uint32_t addr) { return ram + (addr - RAM_BASE); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

/* swallow the QACR0/QACR1 device writes so the guest does not trip OOB */
static void dev_write(void *ctx, uint32_t a, unsigned sz, uint32_t v)
{
    (void)ctx; (void)a; (void)sz; (void)v;
}

static void seed(uint32_t mode, uint32_t w1, uint32_t w2, uint32_t w3, uint32_t w5)
{
    memset(ram, 0, RAM_SIZE);

    w32(MODE_FLAG, mode);            /* 0 => plain, non-zero => tagged */
    w32(TAG_WORD, 0xDEADBEE0u);      /* tag word, used by the tagged form */
    w32(SQ_STATE, SQ_TARGET);        /* the pointer; word +0/+8 feeds only area */
    w32(SQ_TARGET, 0x12000000u);     /* area word +0 */
    w32(SQ_TARGET + 8u, 0x34000000u);/* area word +8 */

    /* the shading template: 8 words */
    w32(TEMPLATE + 0u, 0x11111111u);
    w32(TEMPLATE + 4u, 0x22222222u);
    w32(TEMPLATE + 8u, 0x33333333u);
    w32(TEMPLATE + 12u, 0x44444444u);
    w32(TEMPLATE + 16u, 0x55555555u);
    w32(TEMPLATE + 20u, 0x66666666u);
    w32(TEMPLATE + 24u, 0x77777777u);
    w32(TEMPLATE + 28u, 0x88888888u);

    /* the GBR block: +72 (plain) and +80 (tagged) name distinct destinations
     * so the offset select is observable */
    w32(GBR + 72u, DST);
    w32(GBR + 80u, DST_TAG);

    /* the source record (words +4/+8/+12/+16; +0 unused) */
    w32(SRC + 4u, w1);
    w32(SRC + 8u, w2);
    w32(SRC + 12u, w3);
    w32(SRC + 16u, w5);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = SRC;
    s->v[6] = 0x0CA0B0C0u;            /* r6 seed */
    s->v[15] = SP;
    s->v[16] = 0x0C0ABCDEu;           /* pr */
    s->v[17] = 0x60000000u;           /* sr, T clear */
    s->gbr = GBR;
    s->gbr_known = 1;
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
    map->device_write = dev_write;
}

static vf3_native_aim setup_native(void)
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram; a.ram_base = RAM_BASE;
    a.r[4] = SRC;
    a.r[6] = 0x0CA0B0C0u;
    a.r[15] = SP;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.gbr = GBR;
    return a;
}

typedef int (*guest_fn)(vf3_matrix_state *, const vf3_ram_map *);
typedef int (*native_fn)(vf3_native_aim *);

static int run_case(const char *label, uint32_t mode,
                    uint32_t w1, uint32_t w2, uint32_t w3, uint32_t w5)
{
    printf("== %s (mode=%u w1=%08x)\n", label, mode, w1);
    fflush(stdout);
    int bad = 0;

    seed(mode, w1, w2, w3, w5);
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin);
    const int ok = vf3_poly_header_sq_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    uint8_t *gblob = (uint8_t *)malloc(RAM_SIZE);
    memcpy(gblob, ram, RAM_SIZE);
    const uint32_t gsr = gs.v[VF3_REG_SR];
    const uint32_t g0 = gs.v[0], g1 = gs.v[1], g2 = gs.v[2], g3 = gs.v[3];
    const uint32_t g4 = gs.v[4], g5 = gs.v[5], g6 = gs.v[6], g12 = gs.v[12];

    seed(mode, w1, w2, w3, w5);
    vf3_native_aim a = setup_native();
    const int nok = vf3_native_poly_header_sq(&a);
    if (!nok) { fprintf(stderr, "  native returned %d\n", nok); free(gblob); return 1; }

    /* whole RAM region, byte for byte */
    for (uint32_t o = 0; o < RAM_SIZE; ++o) {
        uint8_t n, g;
        memcpy(&n, ram + o, 1);
        memcpy(&g, gblob + o, 1);
        if (n != g) {
            if (bad < 24) fprintf(stderr, "  ram @%08x: native %02x guest %02x\n",
                                  RAM_BASE + o, n, g);
            bad++;
        }
    }
    /* registers */
    if (a.r[0] != g0) { if (bad < 10) fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g0); bad++; }
    if (a.r[1] != g1) { if (bad < 10) fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g1); bad++; }
    if (a.r[2] != g2) { if (bad < 10) fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g2); bad++; }
    if (a.r[3] != g3) { if (bad < 10) fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g3); bad++; }
    if (a.r[4] != g4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g4); bad++; }
    if (a.r[5] != g5) { if (bad < 10) fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g5); bad++; }
    if (a.r[6] != g6) { if (bad < 10) fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g6); bad++; }
    if (a.r[12] != g12) { if (bad < 10) fprintf(stderr, "  r12: native %08x guest %08x\n", a.r[12], g12); bad++; }
    printf("  r0=%08x r1=%08x r2=%08x r3=%08x r12=%08x\n", a.r[0], a.r[1], a.r[2], a.r[3], a.r[12]);
    if ((a.sr & 1u) != (gsr & 1u)) { if (bad < 10) fprintf(stderr, "  SR.T: native %u guest %u\n", a.sr & 1, gsr & 1); bad++; }
    if (a.pr != 0x0C0ABCDEu) { if (bad < 10) fprintf(stderr, "  pr changed: %08x\n", a.pr); bad++; }

    free(gblob);
    printf("  poly_header_sq: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    int bad = 0;
    /* plain, single half (w1 bit 5 clear): header is first half + template
     * first half at +16, dst stays. */
    bad |= run_case("plain-single",  0u, 0x00000001u, 0xA1A2A3A4u, 0xB1B2B3B4u, 0xC1C2C3C4u);
    /* plain, double half (w1 bit 5 set): dst advances 32 and holds both
     * template halves. */
    bad |= run_case("plain-double",  0u, 0x00000021u, 0xA1A2A3A4u, 0xB1B2B3B4u, 0xC1C2C3C4u);
    /* tagged, single half */
    bad |= run_case("tagged-single", 1u, 0x00000001u, 0xA1A2A3A4u, 0xB1B2B3B4u, 0xC1C2C3C4u);
    /* tagged, double half */
    bad |= run_case("tagged-double", 1u, 0x00000021u, 0xA1A2A3A4u, 0xB1B2B3B4u, 0xC1C2C3C4u);
    /* plain, single, bit 25 already set (tagged paths leave it) */
    bad |= run_case("plain-single-bit25", 0u, 0x02000001u, 1u, 2u, 3u);

    free(ram);
    printf("poly_header_sq_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
