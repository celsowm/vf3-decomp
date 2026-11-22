/* quad_strip_native_replay.c - differential replay of the native quad_strip
 * (0x8C048600, src/native/quad_strip.c, `vf3_native_quad_strip`) against the
 * readable guest port (src/fight/quad_strip.c, `vf3_quad_strip_entry`).
 *
 * quad_strip walks a list of groups of four inline vertex records and emits
 * 32-byte store-queue slots at r6.  Both sides seed the same flat RAM (the
 * group list, the output slot region, and the globals the lighting reads)
 * and the same XMTRX (guest XF v[37..52], native a->xm[16]), FV12/FV8 lights
 * (guest FR v[29..36], native a->fr[8..15]) and registers.  The emitted
 * slots, the register contract (r0/r1/r2/r4/r5/r6/r9/r14), w1/w2 and XMTRX
 * (unchanged) are compared.  The FP residual comes from ftrv/fipr/div against
 * the native wrappers at the 3e-3 tolerance, as in project_verts. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "quad_strip.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for quad_strip (0x8C048600) */
int vf3_quad_strip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define TOL 3.0e-3f

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define GROUPS    0x0C1A0000u   /* the group list */
#define SLOTS     0x0C200000u   /* the output slot region */
#define SELECTOR_ADDR 0x0C16CA40u   /* not used; kept for name shape */

static uint8_t *ram;

static uint8_t *ab(uint32_t a) { return ram + (a - RAM_BASE); }
static void wu(uint32_t a, uint32_t v)
{
    uint8_t *p = ab(a);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t ru(uint32_t a)
{
    const uint8_t *p = ab(a);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void wf(uint32_t a, float v) { uint32_t u; memcpy(&u, &v, 4); wu(a, u); }
static float rf(uint32_t a) { return vf3_aim_fbits(ru(a)); }

/* an inline vertex record: pos xyz, normal xyz, w1, w2 (32 bytes) */
typedef struct {
    float pos[3];
    float nrm[3];
    uint32_t w1, w2;
} vrec;

static void write_vrec(uint32_t base, const vrec *v)
{
    for (int k = 0; k < 3; ++k) wf(base + 4u * (uint32_t)k, v->pos[k]);
    for (int k = 0; k < 3; ++k) wf(base + 12u + 4u * (uint32_t)k, v->nrm[k]);
    wu(base + 24u, v->w1);
    wu(base + 28u, v->w2);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}
static void seed_lights(vf3_matrix_state *s, vf3_native_aim *a,
                        const float diffuse[3], float ambient,
                        const float spec[3])
{
    /* FV12 = diffuse + ambient in lane 15; FV8 = specular */
    if (s) {
        s->v[VF3_REG_FR0 + 12] = vf3_aim_ubits(diffuse[0]);
        s->v[VF3_REG_FR0 + 13] = vf3_aim_ubits(diffuse[1]);
        s->v[VF3_REG_FR0 + 14] = vf3_aim_ubits(diffuse[2]);
        s->v[VF3_REG_FR0 + 15] = vf3_aim_ubits(ambient);
        s->v[VF3_REG_FR0 + 8] = vf3_aim_ubits(spec[0]);
        s->v[VF3_REG_FR0 + 9] = vf3_aim_ubits(spec[1]);
        s->v[VF3_REG_FR0 + 10] = vf3_aim_ubits(spec[2]);
        s->v[VF3_REG_FR0 + 11] = 0;
    }
    if (a) {
        a->fr[12] = diffuse[0]; a->fr[13] = diffuse[1]; a->fr[14] = diffuse[2]; a->fr[15] = ambient;
        a->fr[8] = spec[0]; a->fr[9] = spec[1]; a->fr[10] = spec[2]; a->fr[11] = 0.0f;
    }
}

/* two groups of four, laid at GROUPS; first group at GROUPS+4, second at
 * GROUPS+4+136.  r4 list points at GROUPS (units read at GROUPS-8). */
static void seed_groups(uint32_t total_bytes, const vrec **verts, int ngroups)
{
    wu(GROUPS - 8u, total_bytes);
    wu(GROUPS - 4u, 0);
    wu(GROUPS, (uint32_t)ngroups);
    for (int g = 0; g < ngroups; ++g) {
        uint32_t base = GROUPS + 4u + 136u * (uint32_t)g;
        for (int v = 0; v < 4; ++v) write_vrec(base + 32u * (uint32_t)v, &verts[g][v]);
        wu(base + 4u * 32u, 0);          /* group flags */
        wu(base + 4u * 32u + 4u, 1);     /* group count */
    }
}

static int run_case(const char *label, int selector,
                    const vrec verts0[4], int ngroups,
                    const float diffuse[3], float ambient, const float spec[3],
                    const float xm[16])
{
    printf("== %s (sel=%d ngroups=%d)\n", label, selector, ngroups);
    fflush(stdout);
    int bad = 0;
    const uint32_t slot0 = SLOTS + 0x1000u;   /* leave room for slot-8 writes */
    const uint32_t total = 136u * (uint32_t)ngroups;
    const vrec *all[2] = { verts0, verts0 };

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    seed_groups(total, all, ngroups);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = 0x0C0ABCDEu;
    gs.v[17] = 0x60000000u;
    gs.v[18] = 0x00040001u;
    gs.v[19] = 0x12345678u;
    gs.v[4] = GROUPS;
    gs.v[5] = 0;
    gs.v[6] = slot0;
    gs.v[8] = (uint32_t)selector;
    gs.v[9] = 0xDEADBEEFu;   /* the body zeroes r9 on exit */
    seed_xf(&gs, NULL, xm);
    seed_lights(&gs, NULL, diffuse, ambient, spec);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_quad_strip_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2],
                  gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6],
                  gr9 = gs.v[9], gr14 = gs.v[14];
    /* snapshot the emitted slot region: a group writes up to 4 slots, and
     * the colour pair sits 8 bytes below slot0 - cover the whole group span
     * even for a triangle (whose r6 does not advance), so slots 1..3 and the
     * EOS marker are compared */
    const uint32_t span_bytes = (uint32_t)ngroups * 4u * 32u + 8u;
    const uint32_t region = span_bytes / 4u;
    uint32_t *gslots_bits = (uint32_t *)calloc(region, sizeof(uint32_t));
    for (uint32_t i = 0; i < region; ++i)
        gslots_bits[i] = ru(slot0 - 8u + 4u * i);

    /* ---- native ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    seed_groups(total, all, ngroups);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    a.r[4] = GROUPS;
    a.r[5] = 0;
    a.r[6] = slot0;
    a.r[8] = (uint32_t)selector;
    a.r[9] = 0xDEADBEEFu;
    seed_xf(NULL, &a, xm);
    seed_lights(NULL, &a, diffuse, ambient, spec);
    const int nok = vf3_native_quad_strip(&a);

    if (!nok) {
        fprintf(stderr, "  native rejected the body\n");
        free(gslots_bits);
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr1 = a.r[1], nr2 = a.r[2],
                  nr4 = a.r[4], nr5 = a.r[5], nr6 = a.r[6],
                  nr9 = a.r[9], nr14 = a.r[14];
    const uint32_t n_slot_end = nr6;

    /* XMTRX unchanged and equal */
    for (int i = 0; i < 16; ++i)
        if (a.xm[i] != xm[i] && memcmp(&a.xm[i], &xm[i], 4) != 0) bad++;

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr1 != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", nr1, gr1); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr4 != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", nr4, gr4); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr9 != gr9) { fprintf(stderr, "  r9: native %08x guest %08x\n", nr9, gr9); bad++; }
    if (nr14 != gr14) { fprintf(stderr, "  r14: native %08x guest %08x\n", nr14, gr14); bad++; }

    /* slots: compare the whole region bit-exact.  This leaf has no sqrt/fsrra
     * (only ftrv/fipr/fdiv/mul/add chains), so a faithful port is bit-exact:
     * a tolerance filter would let control words slide (addresses-as-floats
     * differ by a tiny relative float amount, and the 0xFFFFFFFF EOS marker
     * is NaN, so `fabsf > TOL` never fires for them). */
    for (uint32_t i = 0; i < region; ++i) {
        uint32_t nv = ru(slot0 - 8u + 4u * i), gv = gslots_bits[i];
        if (nv != gv) {
            if (bad < 24)
                fprintf(stderr, "  slot[%u] (addr %08x): native %08x guest %08x\n",
                        (unsigned)i, (unsigned)(slot0 - 8u + 4u * i), nv, gv);
            bad++;
        }
    }

    free(gslots_bits);
    printf("  quad_strip: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    const float diffuse[3] = { 0.0f, 0.0f, 1.0f };
    const float spec[3] = { 1.0f, 0.0f, 0.0f };

    static const float M1[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.2f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    static const float MI[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    /* a quad: first three face forward so vertex 3 is kept */
    const vrec QUAD[4] = {
        { { 1.0f, 2.0f, 3.0f },  { 0.57735f, 0.57735f, 0.57735f }, 0x11111111u, 0x22222222u },
        { { -1.0f, 2.0f, 1.0f }, { 0.0f, -1.0f, 0.0f },             0x33333333u, 0x44444444u },
        { { -1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f },             0x55555555u, 0x66666666u },
        { { 1.0f, 1.0f, 1.0f },  { 1.0f, 0.0f, 0.0f },              0x77777777u, 0x88888888u },
    };

    /* a triangle: the first three wind the "wrong" way (their screen-space
     * cross product is negative) so vertex 3 is dropped and the EOS path runs */
    const vrec TRI[4] = {
        { { 1.0f, 0.0f, 0.0f },      { 0.0f, 1.0f, 0.0f }, 0x11111111u, 0x22222222u },
        { { 1.0f, 1.0f, 0.83333f },  { 0.0f, 1.0f, 0.0f }, 0x33333333u, 0x44444444u },
        { { 1.0f, 2.0f, 0.0f },      { 0.0f, 1.0f, 0.0f }, 0x55555555u, 0x66666666u },
        { { 1.0f, 1.0f, 0.0f },      { 0.0f, 1.0f, 0.0f }, 0x77777777u, 0x88888888u },
    };

    /* a quad whose vertex-0 normal's first component is a *denormal*: the
     * via_adder (0.0 + n0) flushes it to zero under FTZ, so dropping the
     * via_adder changes the lit vertex's intensity */
    const vrec QDEN[4] = {
        { { 1.0f, 2.0f, 3.0f },  { 1e-40f, 0.0f, 1.0f },   0x11111111u, 0x22222222u },
        { { -1.0f, 2.0f, 1.0f }, { 0.0f, -1.0f, 0.0f },     0x33333333u, 0x44444444u },
        { { -1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f },     0x55555555u, 0x66666666u },
        { { 1.0f, 1.0f, 1.0f },  { 1.0f, 0.0f, 0.0f },      0x77777777u, 0x88888888u },
    };

    int bad = 0;
    bad |= run_case("quad-one", 16, QUAD, 1, diffuse, 0.25f, spec, M1);
    bad |= run_case("quad-two-groups", 4, QUAD, 2, diffuse, 0.25f, spec, MI);
    bad |= run_case("tri-one", 16, TRI, 1, diffuse, 0.25f, spec, M1);
    bad |= run_case("tri-no-spec", -1, TRI, 1, diffuse, 0.25f, spec, M1);
    bad |= run_case("tri-ident", 8, TRI, 1, diffuse, 0.0f, spec, MI);
    bad |= run_case("quad-denormal-n0", 16, QDEN, 1, diffuse, 0.25f, spec, M1);

    free(ram);
    printf("quad_strip_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
