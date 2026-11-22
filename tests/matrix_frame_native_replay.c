/* matrix_frame_native_replay.c - differential replay of the native
 * matrix_frame_a/b/c (0x8C03D260 / 0x8C03D280 / 0x8C03D2B0,
 * src/native/matrix_frame.c, `vf3_native_matrix_frame_a/b/c`) against the
 * readable guest ports (src/fight/matrix_lib.c,
 * `vf3_matrix_frame_a_entry` / `_b` / `_c`).
 *
 * The three matrix_frame leaves are "evaluate a child transform and remember
 * it" sequences built from the matrix-stack helpers - each pushes XMTRX on
 * the matrix stack, multiplies in a parent (and in B's case a second parent
 * first), stores the result as a flat matrix in a fixed slot (0x0C19D4D8 for
 * A/B, 0x0C19D498 for C), and pops the stack back, restoring r15/pr at the
 * end.  They are call-free in the router sense (no indirect jump - every
 * helper is a direct call).
 *
 *   frame_A: push *(node+8);         concat_parent; store 0x0C19D4D8; pop
 *   frame_B: push *(node+8); concat *(parent+8); concat_parent; store
 *            0x0C19D4D8; pop
 *   frame_C: push *(parent+8);       concat_parent; store 0x0C19D498; pop
 *
 * Both sides seed the same flat RAM (the matrix stack control block, the
 * node/parent tops and matrices, the fixture region), the same XMTRX and
 * FR12..FR15, then run.  The final flat-slot matrix, the restored XMTRX,
 * the matrix stack control block, the stack words, r15/pr and the
 * post-frame registers are compared.  The residual is the FPU difference
 * (ftrv against the native column-major multiply) at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "matrix_frame.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authorities */
int vf3_matrix_frame_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_frame_c_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define SP 0x0C20FF00u

#define MATRIX_STACK_CTL 0x0C19D2E4u
#define PARENT_TOP      0x0C19D304u      /* MATRIX_SLOT_PARENT + 8 */
#define NODE_TOP        0x0C19D310u      /* MATRIX_SLOT_NODE + 8 */
#define FLAT_A          0x0C19D4D8u
#define FLAT_C          0x0C19D498u

#define STACK_BASE      0x0C200000u      /* the matrix stack's region */

#define TOL 2.0e-3f

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static void wm(uint32_t addr, const float m[16])
{ for (int i = 0; i < 16; ++i) wf(addr + 4u * (uint32_t)i, m[i]); }

/* seed the matrix stack: control block count=1/limit=8/base=STACK_BASE/
 * top=STACK_BASE+64, one matrix P at STACK_BASE already on it.  The node and
 * parent tops point at matrices planted in the fixture region. */
static void seed(void)
{
    memset(at(STACK_BASE), 0, SP - STACK_BASE);   /* clear the fixture region */

    static const float P[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    static const float NODE[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        0.75f, -2.0f, 1.25f, 1.0f,
    };
    static const float PARENT[16] = {
        0.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        2.0f, 3.0f, -0.5f, 1.0f,
    };
    wm(STACK_BASE, P);                 /* the matrix on the stack */
    wm(STACK_BASE + 64u, NODE);        /* the matrix the node top points at */
    wm(STACK_BASE + 128u, PARENT);     /* the matrix the parent top points at */

    w32(MATRIX_STACK_CTL, (uint32_t)((8 << 16) | 1));   /* count=1, limit=8 */
    w32(MATRIX_STACK_CTL + 4u, STACK_BASE);             /* base */
    w32(MATRIX_STACK_CTL + 8u, STACK_BASE + 64u);       /* top */
    w32(NODE_TOP,   STACK_BASE + 64u);                  /* push_from -> node matrix */
    w32(PARENT_TOP, STACK_BASE + 128u);                 /* parent -> parent matrix */
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16])
{
    memset(s, 0, sizeof *s);
    s->v[15] = SP;
    s->v[16] = 0x0C0ABCDEu;                 /* pr */
    s->v[17] = 0x60000000u;                 /* sr, T clear */
    s->v[18] = 0x00040001u;                 /* fpscr, SZ clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;       /* XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static vf3_native_aim setup_native(const float xm[16])
{
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    memcpy(a.xm, xm, sizeof a.xm);
    a.r[15] = SP;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    return a;
}

typedef int (*guest_fn)(vf3_matrix_state *, const vf3_ram_map *);
typedef void (*native_fn)(vf3_native_aim *);

static int run_case(const char *label, guest_fn gf, native_fn nf,
                    uint32_t flat_slot, const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    seed();
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm);
    const int ok = gf(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    /* the flat slots (0x0C19D498/0x0C19D4D8), the matrix-stack control
     * block (0x0C19D2E4), the node/parent slots and the fixture region all
     * sit below the stack; blob_lo must reach them. */
    uint32_t blob_lo = 0x0C19D000u;
    uint32_t blob_hi = SP;
    uint8_t *gblob = (uint8_t *)malloc(blob_hi - blob_lo);
    memcpy(gblob, (const uint8_t *)at(blob_lo), blob_hi - blob_lo);
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    const uint32_t gfpul = gs.v[VF3_REG_FPUL], gfpscr = gs.v[VF3_REG_FPSCR];
    const uint32_t gr0 = gs.v[0], gr4 = gs.v[4], gr6 = gs.v[6], gr7 = gs.v[7];
    const uint32_t gr15 = gs.v[15];
    const uint32_t gctl = r32(MATRIX_STACK_CTL), gtop = r32(MATRIX_STACK_CTL + 8u);

    seed();
    vf3_native_aim a = setup_native(xm);
    nf(&a);

    /* the flat slot matrix */
    for (int i = 0; i < 16; ++i) {
        uint32_t n, g;
        memcpy(&n, at(flat_slot + 4u * (uint32_t)i), 4);
        memcpy(&g, gblob + (flat_slot - blob_lo) + 4u * (uint32_t)i, 4);
        float nf_ = vf3_aim_fbits(n), gf_ = vf3_aim_fbits(g);
        if (fabsf(nf_ - gf_) > TOL && memcmp(&nf_, &gf_, 4) != 0) {
            if (bad < 20) fprintf(stderr, "  flat[%d]: native %.7g guest %.7g\n", i, nf_, gf_);
            bad++;
        }
    }
    /* restored XMTRX (after the final pop) */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* the fixture region, byte for byte (matrix stack + flat slot + stack).
     * The flat slot (flat_slot..+64) is compared with float tolerance above;
     * its low ulps differ between the native plain-float multiply and the
     * guest ftrv, so it is excluded from the byte-exact pass. */
    for (uint32_t o = 0; o < blob_hi - blob_lo; ++o) {
        uint32_t a0 = blob_lo + o;
        if (a0 >= flat_slot && a0 < flat_slot + 64u) continue;
        uint8_t n, g;
        memcpy(&n, (uint8_t *)at(blob_lo + o), 1);
        memcpy(&g, gblob + o, 1);
        if (n != g) {
            if (bad < 24) fprintf(stderr, "  ram @%08x: native %02x guest %02x\n",
                                  blob_lo + o, n, g);
            bad++;
        }
    }
    /* registers: r15/pr restored to entry; the frame leaves r15 = sp */
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }
    if (a.pr != 0x0C0ABCDEu) { if (bad < 10) fprintf(stderr, "  pr: native %08x\n", a.pr); bad++; }
    if (a.fpul != gfpul) { if (bad < 10) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); bad++; }
    if ((a.fpscr & 0x00200000u) != (gfpscr & 0x00200000u)) {
        if (bad < 10) fprintf(stderr, "  fpscr FR: native %08x guest %08x\n", a.fpscr, gfpscr);
        bad++;
    }
    if (a.r[0] != gr0) { if (bad < 10) fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); bad++; }
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[6] != gr6) { if (bad < 10) fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gr6); bad++; }
    if (a.r[7] != gr7) { if (bad < 10) fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gr7); bad++; }
    if (r32(MATRIX_STACK_CTL) != gctl || r32(MATRIX_STACK_CTL + 8u) != gtop) {
        if (bad < 10) fprintf(stderr, "  stack ctl/top changed\n");
        bad++;
    }

    free(gblob);
    printf("  matrix_frame: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    static const float ID[16] = {
        1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1,
    };

    int bad = 0;
    bad |= run_case("frame_a", vf3_matrix_frame_a_entry, vf3_native_matrix_frame_a, FLAT_A, MX);
    bad |= run_case("frame_b", vf3_matrix_frame_b_entry, vf3_native_matrix_frame_b, FLAT_A, MX);
    bad |= run_case("frame_c", vf3_matrix_frame_c_entry, vf3_native_matrix_frame_c, FLAT_C, MX);
    bad |= run_case("frame_a-ident", vf3_matrix_frame_a_entry, vf3_native_matrix_frame_a, FLAT_A, ID);

    free(ram);
    printf("matrix_frame_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
