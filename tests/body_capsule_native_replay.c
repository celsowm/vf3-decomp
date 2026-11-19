/* Differential replay of the native capsule-fitting driver
 * (src/native/body_capsule.c, 0x8C06F450) against the readable guest port
 * (src/fight/body_capsule.c, `vf3_body_capsule_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (its
 * callees - matrix load/push/pop/concat, word_copy, capsule_chain,
 * chain_frames, negate_copy, matrix_copy - are dispatched by the readable
 * registry), the native through `ram_base` with every callee inlined in plain
 * C.  The fixture lays out the owner, the capsule record (with its node
 * array, end-point/join matrices, counts, link scale, reach and axis length),
 * a matrix stack control block for the guest, and seeds the literal-pool
 * constants.  The two sides run from the same seed.
 *
 * The record's matrix outputs (end points / axes from the `xform`s), the node
 * positions and side vectors, and the negate_copy destination are compared at
 * the native float tolerance (2e-3, non-finite must match exactly); the
 * saved-register stack and the contract registers (r8..r14, r15, pr,
 * fr12..fr15, SR's T bit) are compared bit for bit.
 *
 * SR's T bit differs by path: the non-tail path ends through negate_copy
 * (T clear), the tail path runs no T-setting callee, so it keeps the entry T
 * bit.  The comparison checks equality between the two sides, not a fixed
 * value.
 *
 * The readable is the authority.  The native port is a re-implementation in
 * plain C floats (sqrtf instead of fsrra/fipr), so float quads carry the FPU
 * residual, tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "body_capsule.h"
#include "matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_body_capsule_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define OWNER   0x0C200000u
#define REC     0x0C200200u
#define NODES   0x0C201000u
#define DST     0x0C201C00u
#define MAT_BLK 0x0C202000u
#define M108    0x0C202100u
#define M112    0x0C202200u
#define SP0     0x0C210000u

#define REC_LO   REC
#define REC_HI   (REC + 0x200u)
#define NOD_LO   NODES
#define NOD_HI   (NODES + 0x800u)
#define DST_LO   DST
#define DST_HI   (DST + 0x100u)
#define FRM_LO   (SP0 - 48u)
#define FRM_HI   (SP0 + 32u)

static float *ram;

static void *at(uint32_t addr) { return (uint8_t *)ram + (addr - RAM_BASE); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}
static void seed_mat(uint32_t addr, const float m[16])
{
    for (int i = 0; i < 16; ++i) wf(addr + 4u * (uint32_t)i, m[i]);
}

/* the literals body_capsule reads from its own pool / the ROM image */
static void seed_literals(void)
{
    wf(0x0C06F664u, 0.1f);        /* LIT_TENTH */
    wf(0x0C06F66Cu, 5.0f);        /* LIT_FIVE */
    wf(0x0C06F670u, 8.0f);        /* LIT_EIGHT */
    wf(0x0C06F6D8u, 0.05f);       /* LIT_STEP */
    wf(0x0C06F738u, 0.001f);      /* LIT_EPS */
    wf(0x0C0D3D68u, 1.0f);        /* AXIS_CONST = (1,0,0) */
    wf(0x0C0D3D6Cu, 0.0f);
    wf(0x0C0D3D70u, 0.0f);
    wf(0x0C29BCC4u, 2.0f);        /* SCALE_CELL */
    w32(0x0C19D2E4u, (16u << 16) | 0u);   /* matrix stack ctl: limit 16, count 0 */
    w32(0x0C19D2E8u, 0x0C19D400u);        /* base */
    w32(0x0C19D2ECu, 0x0C19D400u);        /* top */
}

struct spec {
    const char *label;
    uint32_t n;                  /* node count per chain (rec+88) */
    uint32_t m;                  /* chain count (rec+92) */
    uint32_t owner72;            /* owner +72 state word */
    uint32_t o96, o97;           /* owner +96/+97 */
    uint32_t owner62;            /* owner +62 halfword (<2 -> tail path) */
    float link_scale;            /* rec+84 */
    float reach;                 /* rec+100 */
    float axislen;               /* rec+0xA4 */
};

static const float MMAT[16] = {
    0.8f,  0.1f, -0.3f, 0.0f,
    0.2f,  0.9f,  0.1f, 0.0f,
    -0.1f, 0.4f,  0.7f, 0.0f,
    12.0f, -4.0f, 8.0f, 1.0f,
};
static const float MMAT2[16] = {
    0.9f, -0.2f, 0.0f, 0.0f,
    0.2f,  0.7f, 0.1f, 0.0f,
    0.1f, -0.4f, 0.8f, 0.0f,
    -6.0f, 3.0f,  5.0f, 1.0f,
};

static void seed_nodes(uint32_t n, uint32_t m)
{
    /* node positions spread across all the bodies the chain loop will touch.
     * The coordinates are deliberately irregular (no two edge vectors
     * parallel) so chain_frames' phase-1 crosses stay well conditioned -
     * a symmetric/collinear seed made the two crosses cancel and both sides
     * normalised a zero vector into garbage. */
    for (uint32_t i = 0; i < (3u + m + 1u) * n + 8u; ++i) {
        const uint32_t a = NODES + 24u * i;
        wf(a, 3.0f + 0.71f * (float)i);
        wf(a + 4u, -0.43f + 0.37f * (float)(i % 3u));
        wf(a + 8u, 0.16f + 0.31f * (float)((i + 1u) % 4u));
    }
}

static void seed(const struct spec *sp)
{
    memset((uint8_t *)at(OWNER), 0xAA, 0x10000u);
    /* owner */
    w32(OWNER + 72u, sp->owner72);
    w32(OWNER + 62u, sp->owner62);
    {
        uint8_t *p = (uint8_t *)at(OWNER + 96u);
        p[0] = (uint8_t)sp->o96; p[1] = (uint8_t)sp->o97;
    }
    /* record */
    w32(REC + 0u, 2u);                         /* negate_copy count */
    w32(REC + 4u, NODES);                      /* node array base (= negate src) */
    w32(REC + 8u, DST);                        /* negate dst */
    w32(REC + 12u, MAT_BLK);                   /* matrix-block pointer */
    seed_mat(REC + 16u, MMAT2);                /* the join matrix (overwritten by FINISH) */
    wf(REC + 84u, sp->link_scale);
    w32(REC + 88u, sp->n);
    w32(REC + 92u, sp->m);
    wf(REC + 96u, 2.5f);                       /* capsule_chain link */
    wf(REC + 100u, sp->reach);
    w32(REC + 108u, M108);
    w32(REC + 112u, M112);
    wf(REC + 0xA4u, sp->axislen);
    wf(REC + 0xA8u, sp->axislen);              /* capsule_chain axis length */
    wf(REC + 0xACu, 1.0f);                     /* capsule_chain radius */

    /* matrices */
    seed_mat(MAT_BLK, MMAT);
    seed_mat(M108, MMAT2);
    seed_mat(M112, MMAT);
    seed_nodes(sp->n, sp->m);
    seed_literals();
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t *regs, const float *frseed)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[4] = OWNER; s->v[5] = REC; s->v[15] = SP0;
    s->v[16] = 0x0C0ABCDEu;                    /* pr */
    s->v[17] = 0x60000001u;                    /* sr, T bit SET (cleared on most paths) */
    s->v[18] = 0x00040001u;                    /* fpscr */
    for (int i = 0; i < 4; ++i) {
        uint32_t bits; memcpy(&bits, &frseed[i], 4);
        s->v[21 + 12 + i] = bits;              /* FR12..FR15 */
    }
    s->budget = 4000000u;
    /* XMTRX = identity so the first MATRIX_LOAD overwrites it deterministically */
    s->v[VF3_REG_XF0 + 12] = 0; s->v[VF3_REG_XF0 + 13] = 0; s->v[VF3_REG_XF0 + 14] = 0; s->v[VF3_REG_XF0 + 15] = 0x3F800000u;
    s->v[VF3_REG_XF0] = s->v[VF3_REG_XF0 + 5] = s->v[VF3_REG_XF0 + 10] = 0x3F800000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) { fclose(f); return "image short"; }
    fclose(f);
    return NULL;
}

/* compare one compared region at the native float tolerance (2e-3) */
struct fcmp { int nb; float worst; uint32_t worst_at; };
static struct fcmp cmp_float(const uint8_t *guest, uint32_t goff, uint32_t lo, uint32_t hi,
                             const char *name)
{
    struct fcmp c; memset(&c, 0, sizeof c);
    for (uint32_t ad = lo; ad < hi; ad += 4) {
        uint32_t g, n;
        memcpy(&g, guest + goff + (ad - lo), 4);
        memcpy(&n, at(ad), 4);
        float gf, nf; memcpy(&gf, &g, 4); memcpy(&nf, &n, 4);
        if (!isfinite(gf) || !isfinite(nf)) {
            if (g != n) {
                if (c.nb < 10)
                    fprintf(stderr, "  [%s] @%08x: non-finite want %08x got %08x\n",
                            name, ad, g, n);
                c.nb++;
            }
            continue;
        }
        const float d = fabsf(gf - nf);
        if (d > c.worst) { c.worst = d; c.worst_at = ad; }
        if (d > 2.0e-3f && g != n) {
            if (c.nb < 10)
                fprintf(stderr, "  [%s] @%08x: want %.7g got %.7g (d=%.3g)\n",
                        name, ad, gf, nf, d);
            c.nb++;
        }
    }
    printf("  %-7s: %s (worst %.3g @ %08x)\n", name, c.nb ? "DIFFERS" : "match",
           c.worst, c.worst_at);
    return c;
}

static int run_case(const struct spec *sp)
{
    printf("== %s (n=%u m=%u o72=%08x o62=%u o96=%u o97=%u)\n",
           sp->label, sp->n, sp->m, sp->owner72, sp->owner62, sp->o96, sp->o97);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x11110000u + (uint32_t)i * 0x1111u;
    const float frseed[4] = { 3.5f, 4.5f, 5.5f, 6.5f };   /* fr12..fr15 */

    /* ---- guest side ---- */
    seed(sp);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, frseed);
    const int ok_guest = vf3_body_capsule_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    size_t guest_sz = (size_t)(REC_HI - REC_LO) + (NOD_HI - NOD_LO) +
                      (DST_HI - DST_LO) + (FRM_HI - FRM_LO);
    uint8_t *guest = (uint8_t *)malloc(guest_sz);
    memcpy(guest, at(REC_LO), REC_HI - REC_LO);
    memcpy(guest + (REC_HI - REC_LO), at(NOD_LO), NOD_HI - NOD_LO);
    memcpy(guest + (REC_HI - REC_LO) + (NOD_HI - NOD_LO), at(DST_LO), DST_HI - DST_LO);
    memcpy(guest + (REC_HI - REC_LO) + (NOD_HI - NOD_LO) + (DST_HI - DST_LO),
           at(FRM_LO), FRM_HI - FRM_LO);

    /* ---- native side ---- */
    seed(sp);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.r[4] = OWNER; a.r[5] = REC; a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000001u; a.fpscr = 0x00040001u;
    a.fr[12] = frseed[0]; a.fr[13] = frseed[1];
    a.fr[14] = frseed[2]; a.fr[15] = frseed[3];
    vf3_native_matrix_identity(a.xm);
    vf3_native_body_capsule(&a, SP0, OWNER, REC);

    int bad = 0;
    size_t rec_off = 0, nod_off = REC_HI - REC_LO, dst_off = (REC_HI - REC_LO) + (NOD_HI - NOD_LO);

    struct fcmp r = cmp_float(guest, rec_off, REC_LO, REC_HI, "record");
    struct fcmp nd = cmp_float(guest, nod_off, NOD_LO, NOD_HI, "nodes");
    struct fcmp dd = cmp_float(guest, dst_off, DST_LO, DST_HI, "dst");
    bad |= r.nb | nd.nb | dd.nb;

    /* ---- frame + saved registers: exact ---- */
    {
        int nb = 0;
        for (uint32_t ad = FRM_LO; ad < FRM_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + dst_off + (DST_HI - DST_LO) + (ad - FRM_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10)
                    fprintf(stderr, "  frame @%08x: want %08x got %08x\n", ad, g, n);
                nb++;
            }
        }
        printf("  frame  : %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* ---- contract registers ---- */
    {
        int nb = 0;
        for (int i = 8; i <= 14; ++i)
            if (a.r[i] != gs.v[i]) {
                if (nb < 30) fprintf(stderr, "  r%d: native %08x guest %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.r[15] != gs.v[15]) { if (nb < 30) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]); nb++; }
        if (a.pr != gs.v[16]) { if (nb < 30) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]); nb++; }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) { fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1, gs.v[17] & 1); nb++; }
        for (int i = 12; i <= 15; ++i) {
            uint32_t gb, n2;
            memcpy(&gb, &a.fr[i], 4);
            memcpy(&n2, &gs.v[21 + i], 4);
            if (gb != n2) { if (nb < 30) fprintf(stderr, "  fr%d: native %08x guest %08x\n", i, gb, n2); nb++; }
        }
        printf("  regs   : %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(guest);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("body_capsule_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct spec all[] = {
        { "else path (o72=0)",    3, 4u, 0x00000u,  0u,  0u, 5u, 2.0f, 1.5f, 6.0f },
        { "if path o72=0x1000",   3, 4u, 0x01000u,  0u,  0u, 5u, 2.0f, 1.0f, 6.0f },
        { "if path o72=0x20000",  3, 3u, 0x20000u,  0u,  0u, 5u, 2.0f, 1.0f, 6.0f },
        { "if path o96==21",      3, 3u, 0x20000u, 21u,  0u, 5u, 2.0f, 1.0f, 6.0f },
        { "capsule skip o96==8",  3, 3u, 0x00000u,  8u,  0u, 5u, 2.0f, 1.0f, 6.0f },
        { "capsule skip o97==4",  4, 4u, 0x00000u,  0u,  4u, 5u, 2.0f, 1.0f, 6.0f },
        { "first chain o97==8",   3, 4u, 0x00000u,  0u,  8u, 5u, 2.0f, 1.0f, 6.0f },
        { "tail (o62<2)",         3, 4u, 0x00000u,  0u,  0u, 1u, 2.0f, 1.0f, 6.0f },
        { "single chain m=2",     2, 2u, 0x00000u,  0u,  0u, 5u, 2.0f, 0.8f, 5.0f },
    };

    int bad = 0;
    for (size_t i = 0; i < sizeof all / sizeof all[0]; ++i)
        bad |= run_case(&all[i]);

    free(ram);
    printf("body_capsule_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
