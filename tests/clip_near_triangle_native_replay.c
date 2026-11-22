/* clip_near_triangle_native_replay.c - differential replay of the native
 * near-plane triangle clipper (0x8C04A320, src/native/clip_near_triangle.c,
 * `vf3_native_clip_near_triangle`) against the readable guest port
 * (src/fight/clip_near_triangle.c, `vf3_clip_near_triangle_entry`).
 *
 * clip_near_triangle walks a stream of triangle point-records, projects each
 * point through XMTRX, clips the strip against the near-plane threshold (r12,
 * kept in FR2) and writes 32-byte store-queue vertex blocks at r6, counting
 * 64-byte blocks in r5.  Both sides seed the same flat RAM (the stream, the
 * output slot region, the trailer words at sp+20/24/28 and XMTRX guest
 * XF v[37..52], native a->xm[16]) and the same registers.
 *
 * The outcode per triangle (one bit per point, set when the transformed depth
 * exceeds the threshold) is steered with the point's z through an XMTRX whose
 * w row is the identity on z (`w' = z`), so a z above/threshold puts the point
 * in one class and a z below in the other.  Eight triangles cover outcode 0
 * (all-front write), outcode 7 (all-behind, nothing written) and outcodes
 * 1..6 (the two emitters through every point-order rotation).  The emitted
 * slots, the register contract (r0..r6, r11, r14) and XMTRX (unchanged) are
 * compared bit-exact - the leaf's FP chains are plain ftrv/fdiv/fmul/fmac
 * under FE_TOWARDZERO (FPSCR 0x00040001), so a faithful port is bit-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "clip_near_triangle.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for clip_near_triangle (0x8C04A320) */
int vf3_clip_near_triangle_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define STREAM    0x0C1A0000u   /* the triangle stream */
#define SLOT0     0x0C200000u   /* the output slot region */
#define SP        0x0C20F000u   /* r15; trailer words at sp+20/24/28 */

#define THR_BITS  0x41200000u   /* 10.0f, the near-plane threshold (r12) */
#define ONE_BITS  0x3F800000u   /* r7, the constant in the second block */

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

/* one 32-byte inline point record: bit0 set (flag), x,y,z as the three floats
 * from its first word on (x's low bit carries the flag), next record 32 on. */
static void write_vrec(uint32_t base, float x, float y, float z)
{
    uint32_t ux; memcpy(&ux, &x, 4);
    ux |= 1u;                       /* bit0 = the inline flag */
    wu(base + 0u, ux);              /* x (flag bit set) */
    wf(base + 4u, y);
    wf(base + 8u, z);
    wf(base + 12u, 1.0f);           /* the 4th coord, FLOAT forces 1 anyway */
    wu(base + 16u, 0u);
    wu(base + 20u, 0u);
    wu(base + 24u, 0u);
    wu(base + 28u, 0u);
}

/* a triangle is three inline records (32-byte stride); steer the outcode with
 * each point's z and the threshold 10.0 (z > 10 sets the point's outcode bit). */
static void write_tri(uint32_t base, float za, float zb, float zc)
{
    write_vrec(base + 0u,  1.0f, 2.0f, za);
    write_vrec(base + 32u, 3.0f, 4.0f, zb);
    write_vrec(base + 64u, 5.0f, 6.0f, zc);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}

/* column-major, so result[i] = sum_k xm[4k+i]*src[k].
 * w' = xm[3]*x + xm[7]*y + xm[11]*z + xm[15]*w  -> set xm[11]=1 so the depth
 * (transformed w) equals z; the threshold 10 gates z>10 vs z<10 and steers the
 * outcode.  x'=x, y'=y, z'=z so the emitted positions are clean. */
static const float XM[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,     /* x' = x            (xm[0])  */
    0.0f, 1.0f, 0.0f, 0.0f,     /* y' = y            (xm[5])  */
    0.0f, 0.0f, 1.0f, 1.0f,     /* z' = z (xm[10]); w'= z (xm[11]) */
    0.0f, 0.0f, 0.0f, 0.0f,     /* w input contributes nothing */
};

static void seed_trailer(void)
{
    /* caller frame trailer words */
    wu(SP + 20u, 0x10000000u);
    wu(SP + 24u, 0x20000000u);
    wu(SP + 28u, 0x40000000u);
}

static void seed_stream_all(void)
{
    uint32_t p = STREAM;
    wu(STREAM, (uint32_t)8); p += 4;         /* triangle count */
    /* eight triangles, outcode 0,1,2,3,4,5,6,7 via (za,zb,zc) each < or > 10 */
    write_tri(p,  5.0f, 6.0f, 7.0f); p += 96;  /* all <10  -> outcode 0 */
    write_tri(p,  1.0f, 2.0f, 20.0f); p += 96; /* outcode 1 */
    write_tri(p,  1.0f, 20.0f, 2.0f); p += 96; /* outcode 2 */
    write_tri(p,  1.0f, 20.0f, 20.0f); p += 96;/* outcode 3 */
    write_tri(p,  20.0f, 1.0f, 2.0f); p += 96; /* outcode 4 */
    write_tri(p,  20.0f, 1.0f, 20.0f); p += 96;/* outcode 5 */
    write_tri(p,  20.0f, 20.0f, 1.0f); p += 96;/* outcode 6 */
    write_tri(p,  20.0f, 20.0f, 20.0f); p += 96;/* all >10 -> outcode 7 */
    wu(p, 0u);                                  /* stream terminator */
    seed_trailer();
}

/* A single all-front triangle: the all-front path's r11 write is the LAST
 * emitter latch, so r11 at exit (and the trailer write it gates at line 272)
 * are decided by that path alone.  This is what makes a mutation of the
 * all-front `R(11) = 1` observable. */
static void seed_stream_single_front(void)
{
    write_tri(STREAM + 4u, 5.0f, 6.0f, 7.0f);   /* outcode 0 */
    wu(STREAM + 100u, 0u);                       /* stream terminator */
    wu(STREAM, (uint32_t)1);                     /* triangle count */
    seed_trailer();
}

static int run_case(const char *label, void (*seed)(void))
{
    const uint32_t slot0 = SLOT0;
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    seed();
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[4] = STREAM;
    gs.v[5] = 0;
    gs.v[6] = slot0;
    gs.v[7] = ONE_BITS;
    gs.v[12] = THR_BITS;
    gs.v[14] = 0;
    gs.v[15] = SP;
    gs.v[17] = 0x60000000u;
    gs.v[18] = 0x00040001u;
    gs.v[19] = 0x12345678u;         /* fpul */
    seed_xf(&gs, NULL, XM);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_clip_near_triangle_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2], gr3 = gs.v[3],
                  gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6], gr11 = gs.v[11],
                  gr14 = gs.v[14];

    /* snapshot the guest's emitted region before the native run clobbers RAM */
    const uint32_t lo = slot0 - 0x40u;
    const uint32_t nwords = 0x440u / 4u;
    uint32_t *gslots = (uint32_t *)calloc(nwords, sizeof(uint32_t));
    for (uint32_t i = 0; i < nwords; ++i) gslots[i] = ru(lo + 4u * i);

    /* ---- native ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    seed();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[4] = STREAM;
    a.r[5] = 0;
    a.r[6] = slot0;
    a.r[7] = ONE_BITS;
    a.r[12] = THR_BITS;
    a.r[14] = 0;
    a.r[15] = SP;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    seed_xf(NULL, &a, XM);
    const int nok = vf3_native_clip_near_triangle(&a);

    if (!nok) {
        fprintf(stderr, "  native rejected the body\n");
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr1 = a.r[1], nr2 = a.r[2], nr3 = a.r[3],
                  nr4 = a.r[4], nr5 = a.r[5], nr6 = a.r[6], nr11 = a.r[11],
                  nr14 = a.r[14];

    /* XMTRX unchanged and equal */
    for (int i = 0; i < 16; ++i)
        if (a.xm[i] != XM[i] && memcmp(&a.xm[i], &XM[i], 4) != 0) bad++;

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr1 != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", nr1, gr1); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr3 != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", nr3, gr3); bad++; }
    if (nr4 != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", nr4, gr4); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr11 != gr11) { fprintf(stderr, "  r11: native %08x guest %08x\n", nr11, gr11); bad++; }
    if (nr14 != gr14) { fprintf(stderr, "  r14: native %08x guest %08x\n", nr14, gr14); bad++; }

    /* emitted slots: compare the whole region bit-exact (guest snapshot vs RAM) */
    for (uint32_t i = 0; i < nwords; ++i) {
        uint32_t nv = ru(lo + 4u * i), gv = gslots[i];
        if (nv != gv) {
            if (bad < 24)
                fprintf(stderr, "  slot[%u] (addr %08x): native %08x guest %08x\n",
                        (unsigned)i, (unsigned)(lo + 4u * i), nv, gv);
            bad++;
        }
    }

    free(gslots);

    printf("  clip_near_triangle: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    bad |= run_case("all-outcodes", seed_stream_all);
    bad |= run_case("single-all-front", seed_stream_single_front);
    free(ram);
    printf("clip_near_triangle_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
