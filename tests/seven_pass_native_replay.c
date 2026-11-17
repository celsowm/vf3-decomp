/* Differential replay of the native seven_pass port (src/native/seven_pass.c,
 * 0x8C09DA72) against the readable guest port (src/fight/seven_pass.c).
 *
 * Both sides run on the same flat matrix RAM: the guest through its ram map,
 * the native port through `ram_base`.  The fixture lays out the object (its
 * word0, second vector at +16/+20/+24, the yaw halfword at +30, flags at +72,
 * the mode byte at +97, and the seven SEG_A records at +0x1D04 / SEG_B at
 * +0x1EFC) and the stage word at 0x0C29BCCC, then both sides run and the whole
 * object/SEG region plus the final XMTRX and the call frame are compared.
 *
 * The guest is the authority (it was promoted against the oracle); the native
 * port is a re-implementation, so the residual is the FPU difference
 * (fsca/fsrra/libm), tolerated at 2e-3.</think>

<｜DSML｜tool_calls>
<｜DSML｜invoke name="write">
<｜DSML｜parameter name="content" string="true">/* Differential replay of the native seven_pass port (src/native/seven_pass.c,
 * 0x8C09DA72) against the readable guest port (src/fight/seven_pass.c).
 *
 * Both sides run on the same flat matrix RAM: the guest through its ram map,
 * the native port through `ram_base`.  The fixture lays out the object (its
 * word0, the second vector at +16/+20/+24, the yaw halfword at +30, the flags
 * at +72, the mode byte at +97, and the seven SEG_A records at +0x1D04 with
 * their SEG_B outputs at +0x1EFC) and the stage word at 0x0C29BCCC, then both
 * sides run and the whole object/SEG region plus the final XMTRX and the call
 * frame are compared.
 *
 * The guest is the authority (it was promoted against the oracle); the native
 * port is a re-implementation, so the residual is the FPU difference
 * (fsca/fsrra/libm), tolerated at 2e-3.  seven_pass ends with pop(1), so the
 * final XMTRX should equal the entry XMTRX on both sides. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"
#include "pose_callees.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_seven_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u           /* must reach STAGE_WORD 0x0C29BCCC */
#define REGION_BASE 0x0C200000u
#define REGION_END  0x0C20D000u

#define OBJ     0x0C204000u          /* the seven_pass object */
#define SEG_A   0x1D04u
#define SEG_B   0x1EFCu
#define SP      0x0C20FF00u

#define STAGE_WORD 0x0C29BCCCu       /* absolute, read-only input */

static float *ram;

static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
static void w8(uint32_t addr, uint8_t v) { ((uint8_t *)at(addr))[0] = v; }
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}
static uint32_t w32read(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint32_t membits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static void seed_region(void)
{
    for (uint32_t a = REGION_BASE; a < REGION_END; a += 4)
        w32(a, 0x3F800000u ^ (a & 0x7FF));
    /* the matrix stack the guest push/pop go through */
    w32(0x0C19D2E4u, (16u << 16) | 1u);
    w32(0x0C19D2E8u, 0x0C19D400u);
    w32(0x0C19D2ECu, 0x0C19D440u);
    w32(STAGE_WORD, 0);               /* default: no zero-y */
}

/* the entry XMTRX: a rotation with a translation */
static const float MX[16] = {
    0.8660254f, 0.0f, -0.5f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, 0.0f, 0.8660254f, 0.0f,
    1.5f, 2.5f, -0.5f, 1.0f,
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t regs[16], const float xm[16])
{
    memset(s, 0, sizeof *s);
    for (int i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[16] = 0x0C0ABCDEu;        /* pr */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[37 + i] = bits;       /* XF0..XF15 = XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const uint32_t regs[16], const float xm[16])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE; a.f = SP;
    memcpy(a.xm, xm, sizeof a.xm);
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    return a;
}

static int run_case(const char *label,
                    int (*guest)(vf3_matrix_state *, const vf3_ram_map *),
                    void (*nativ)(vf3_native_aim *),
                    void (*seed)(void),
                    const uint32_t (*ranges)[2], int nrange,
                    const uint32_t regs[16], const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    seed();
    setup_guest(&gs, &gmap, gwin, regs, xm);
    const int ok = guest(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    uint32_t span_lo = 0xFFFFFFFFu, span_hi = 0;
    for (int i = 0; i < nrange; ++i) {
        if (ranges[i][0] < span_lo) span_lo = ranges[i][0];
        if (ranges[i][1] > span_hi) span_hi = ranges[i][1];
    }
    uint8_t *gblob = (uint8_t *)malloc(span_hi - span_lo);
    memcpy(gblob, (const uint8_t *)at(span_lo), span_hi - span_lo);
    const float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u; memcpy(&u, &gs.v[37 + i], 4); memcpy(&gxm[i], &u, 4); }

    {
        seed();
        vf3_native_aim a = setup_native(regs, xm);
        nativ(&a);
        for (int r = 0; r < nrange; ++r)
        for (uint32_t a0 = ranges[r][0]; a0 < ranges[r][1]; a0 += 4) {
            float g, n;
            memcpy(&g, gblob + (a0 - span_lo), 4);
            memcpy(&n, at(a0), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0) {
                    if (bad < 10)
                        fprintf(stderr, "  ram @%08x: got %08x want %08x (non-finite)\n",
                                a0, membits(n), membits(g));
                    bad++;
                }
                continue;
            }
            if (fabsf(g - n) > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
                if (bad < 10)
                    fprintf(stderr, "  ram @%08x: got %.7g want %.7g\n",
                            a0, n, g);
                bad++;
            }
        }
        for (int i = 0; i < 16; ++i) {
            if (fabsf(a.xm[i] - gxm[i]) > 2.0e-3f) {
                if (bad < 20)
                    fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
                bad++;
            }
        }
        printf("  region: %s\n", bad ? "DIFFERS" : "match");
    }
    free(gblob);
    return bad ? 1 : 0;
}

/* ---- fixtures ----
 * Each seeds the object at OBJ: word0 (obj+0), second vector (+16/+20/+24),
 * yaw halfword (+30), flags (+72), mode byte (+97), then seven SEG_A records
 * (+0x1D04, 12 apart) that feed the subtraction, with SEG_B (+0x1EFC) the
 * output.  stage_word and the flags decide the drop and the zero-y paths. */

static void seed_segs(void)
{
    /* seven SEG_A records, 12 bytes apart */
    for (int i = 0; i < 7; ++i) {
        wf(OBJ + SEG_A + 12u * (uint32_t)i + 0u, (float)(i * 3 + 1));
        wf(OBJ + SEG_A + 12u * (uint32_t)i + 4u, (float)(i * 5 + 2));
        wf(OBJ + SEG_A + 12u * (uint32_t)i + 8u, (float)(i * 7 + 3));
    }
}

static void seed_a(void)   /* mode 6 drop, vec0 zero, zero-y off */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x00000000u);            /* word0: no FLAG_STAGE */
    wf(OBJ + 16u, 1.0f); wf(OBJ + 20u, 5.0f); wf(OBJ + 24u, -2.0f);
    w16(OBJ + 30u, 0x0400u);              /* yaw */
    w32(OBJ + 72u, 0x00002000u);          /* +72: not 0x29000, not 0x21000 */
    w8(OBJ + 97u, 6);
}
static void seed_b(void)   /* mode 8 drop, vec0 = VEC, zero-y off */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x20000000u);            /* FLAG_STAGE only (no 0x40000) */
    w32(OBJ + SEG_A + 0u, 0x40400000u);   /* VEC at +0x1D04 = 3.0 */
    w32(OBJ + SEG_A + 4u, 0xC0400000u);   /* = -3.0 */
    w32(OBJ + SEG_A + 8u, 0x40A00000u);   /* = 5.0 */
    wf(OBJ + 16u, 0.5f); wf(OBJ + 20u, 1.0f); wf(OBJ + 24u, 1.5f);
    w16(OBJ + 30u, 0x0200u);
    w32(OBJ + 72u, 0x00002000u);          /* +72: no 0x29000 -> drop fires */
    w8(OBJ + 97u, 8);
}
static void seed_c(void)   /* mode 11, FLAGS_SKIP set -> no drop */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x00000000u);
    wf(OBJ + 16u, 1.0f); wf(OBJ + 20u, 1.0f); wf(OBJ + 24u, 1.0f);
    w16(OBJ + 30u, 0x8000u);              /* yaw half-turn */
    w32(OBJ + 72u, 0x00029000u);          /* +72: FLAGS_SKIP set -> no drop */
    w8(OBJ + 97u, 11);
}
static void seed_d(void)   /* mode 12 drop, vec0 = VEC, zero-y off */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x20000000u);            /* FLAG_STAGE only */
    w32(OBJ + SEG_A + 0u, 0x40000000u);   /* VEC = 2.0 */
    w32(OBJ + SEG_A + 4u, 0x40000000u);
    w32(OBJ + SEG_A + 8u, 0x40000000u);
    wf(OBJ + 16u, -1.0f); wf(OBJ + 20u, -1.0f); wf(OBJ + 24u, -1.0f);
    w16(OBJ + 30u, 0x0A00u);
    w32(OBJ + 72u, 0x00002000u);          /* +72: no 0x29000 -> drop fires */
    w8(OBJ + 97u, 12);
    w32(STAGE_WORD, 0);                   /* zero-y gate off */
}
static void seed_e(void)   /* mode 5 (not in the table) -> no drop */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x00000000u);
    wf(OBJ + 16u, 2.0f); wf(OBJ + 20u, 2.0f); wf(OBJ + 24u, 2.0f);
    w16(OBJ + 30u, 0x0100u);
    w32(OBJ + 72u, 0x00000000u);          /* no flags at all */
    w8(OBJ + 97u, 5);
}
static void seed_f(void)   /* flags 0x1000: drop applies, zero-y ON via 0x1000 */
{
    seed_region(); seed_segs();
    w32(OBJ + 0, 0x20040000u);            /* FLAG_STAGE | 0x40000, no 0x8000 */
    wf(OBJ + 16u, 1.0f); wf(OBJ + 20u, 1.0f); wf(OBJ + 24u, 1.0f);
    w16(OBJ + 30u, 0x0300u);
    w32(OBJ + 72u, 0x00001000u);          /* +72: 0x1000 -> zero-y (0x21000 mask) */
    w8(OBJ + 97u, 6);
    w32(STAGE_WORD, 0x800u);              /* zero-y gate on */
}

static void sp_native(vf3_native_aim *a) { vf3_native_seven_pass(a, SP, OBJ); }
static int sp_guest(vf3_matrix_state *s, const vf3_ram_map *r)
{ s->v[4] = OBJ; s->v[15] = SP; return vf3_seven_pass_entry(s, r); }

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    uint32_t regs[16] = { 0 };

    /* Range 1 = the object / SEG_A / SEG_B region (all below 0x0C20D000);
     * Range 2 = the call frame f..sp (f = sp - 84).  Sub-callee scratch below
     * the frame is left out. */
    static const uint32_t sp_r[2][2] = {
        { REGION_BASE, REGION_END },
        { SP - 84u, SP + 16u },
    };

    int bad = 0;
    bad |= run_case("seven_pass c0 (mode 6 drop, vec0 zero)", sp_guest, sp_native,
                    seed_a, sp_r, 2, regs, MX);
    bad |= run_case("seven_pass c1 (mode 8 drop, vec0 VEC)", sp_guest, sp_native,
                    seed_b, sp_r, 2, regs, MX);
    bad |= run_case("seven_pass c2 (mode 11, FLAGS_SKIP -> no drop)", sp_guest, sp_native,
                    seed_c, sp_r, 2, regs, MX);
    bad |= run_case("seven_pass c3 (mode 12 drop, vec0 VEC)", sp_guest, sp_native,
                    seed_d, sp_r, 2, regs, MX);
    bad |= run_case("seven_pass c4 (mode 5 -> no drop)", sp_guest, sp_native,
                    seed_e, sp_r, 2, regs, MX);
    bad |= run_case("seven_pass c5 (mode 6, zero-y via 0x1000)", sp_guest, sp_native,
                    seed_f, sp_r, 2, regs, MX);

    free(ram);
    printf("seven_pass_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
