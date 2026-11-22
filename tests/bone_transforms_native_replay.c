/* bone_transforms_native_replay.c - differential replay of the native
 * bone_transforms (0x8C03E8C0, src/native/bone_transforms.c,
 * `vf3_native_bone_transforms`) against the readable guest port
 * (src/fight/matrix_extra.c, `vf3_bone_transforms_entry`).
 *
 * bone_transforms sequences five callees that the readable registry already
 * serves (matrix_push 0x8C03C4F0, matrix_invert_scaled 0x8C03B5C0,
 * xform_vector 0x8C03B4B0, xform_point 0x8C03B450, matrix_pop 0x8C03C4A0):
 *
 *   1. push XMTRX (r4 = 0),
 *   2. invert XMTRX in place,
 *   3. per "used" entry (sign-extended u16 tag at the record start) of the
 *      sixteen-record TABLE (0x0C19D5B0, stride 0xB0):
 *        - xform_vector: entry+VEC_IN(104) -> entry+VEC_OUT(128),
 *        - xform_point:  entry+POINT_IN(92) -> entry+POINT_OUT(116),
 *   4. matrix_pop (r4 = 1) as the tail call - restores the pushed XMTRX.
 *
 * Both sides run on the same flat RAM (TABLE + records + matrix stack) and
 * the same seed XMTRX: the guest through its ram map and the readable chain,
 * the native through `ram_base` with the callees inlined.
 *
 * Compared: every used entry's xform_vector and xform_point outputs (at the
 * native float tolerance 2e-3; non-finite must be bit-exact), the final
 * XMTRX (bit-exact after the push/pop), and r14. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "bone_transforms.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_bone_transforms_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x400000u

#define TABLE       0x0C19D5B0u
#define ENTRY_BYTES 0xB0u
#define ENTRIES     16
#define VEC_IN      104u
#define VEC_OUT     128u
#define POINT_IN    92u
#define POINT_OUT   116u
#define STK_CTL     0x0C19D2E4u
#define STK_BASE    0x0C1A0000u
#define SP0         0x0C210000u

static uint8_t *ram;
static uint8_t *at(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static float rf(uint32_t addr) { float v; memcpy(&v, at(addr), 4); return v; }

static void seed_matrix_stack(const float xm[16], int pre_pushed)
{
    /* control block: {count:int16, limit:int16, base:u32, top:u32} at 0x0C19D2E4 */
    w32(STK_CTL + 0u, (uint32_t)((16 << 16) | (pre_pushed ? 1 : 0)));
    w32(STK_CTL + 4u, STK_BASE);
    w32(STK_CTL + 8u, STK_BASE + (pre_pushed ? 64u : 0u));
    /* if a matrix is already pushed, plant the seed XMTRX at the top slot */
    if (pre_pushed)
        for (int i = 0; i < 16; ++i) wf(STK_BASE + 4u * (uint32_t)i, xm[i]);
}

static void seed(const uint16_t *used_tags, const int n_used,
                 const float xm[16], int pre_pushed)
{
    memset(at(TABLE), 0, ENTRIES * ENTRY_BYTES);
    for (uint32_t e = 0; e < ENTRIES; ++e) {
        const uint32_t base = TABLE + e * ENTRY_BYTES;
        const uint16_t tag = (e < (uint32_t)n_used) ? used_tags[e] : 0u;
        /* tag used as both sign-extended u16 and record content */
        w32(base, (uint32_t)tag);
        /* a distinct point/vector pair for each used record */
        wf(base + POINT_IN + 0u, (float)e + 1.0f);
        wf(base + POINT_IN + 4u, (float)e * 2.0f - 1.0f);
        wf(base + POINT_IN + 8u, 0.5f + 0.1f * (float)e);
        wf(base + VEC_IN + 0u, 3.0f - (float)e * 0.25f);
        wf(base + VEC_IN + 4u, 1.0f + (float)e * 0.5f);
        wf(base + VEC_IN + 8u, -2.0f + (float)e * 0.125f);
        /* outputs start dirty so a missed write is visible */
        wf(base + POINT_OUT + 0u, -99.0f); wf(base + POINT_OUT + 4u, -99.0f); wf(base + POINT_OUT + 8u, -99.0f);
        wf(base + VEC_OUT + 0u, -99.0f);   wf(base + VEC_OUT + 4u, -99.0f);   wf(base + VEC_OUT + 8u, -99.0f);
    }
    seed_matrix_stack(xm, pre_pushed);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], int pre_pushed)
{
    memset(s, 0, sizeof *s);
    s->v[15] = SP0;
    s->v[VF3_REG_PR] = 0x0C0ABCDEu;
    s->v[17] = 0x60000000u;                 /* sr */
    s->v[18] = 0x00040001u;                 /* fpscr */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;       /* XMTRX */
    }
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = ram;
    map->wins = win; map->n = 1; map->oob = 0;
    (void)pre_pushed;
}

/* compare a 3-float region; tolerate 2e-3, non-finite must be bit-exact */
static int cmp_vec(const uint8_t *guest, uint32_t g_off, uint32_t n_addr, const char *name)
{
    int nb = 0;
    for (int i = 0; i < 3; ++i) {
        float gf, nf;
        memcpy(&gf, guest + g_off + 4u * (uint32_t)i, 4);
        nf = rf(n_addr + 4u * (uint32_t)i);
        uint32_t gb, nb_ = 0; memcpy(&gb, &gf, 4); memcpy(&nb_, &nf, 4);
        if ((!isfinite(gf) || !isfinite(nf)) ? (gb != nb_)
                                             : (fabsf(gf - nf) > 2.0e-3f && gb != nb_)) {
            if (nb < 8) fprintf(stderr, "  [%s][%d] want %.7g got %.7g\n", name, i, gf, nf);
            nb++;
        }
    }
    printf("  %-5s: %s\n", name, nb ? "DIFFERS" : "match");
    return nb;
}

static int run_case(const char *label, const uint16_t *used_tags, int n_used,
                    const float xm[16], int pre_pushed)
{
    printf("== %s (n_used=%d pre=%d)\n", label, n_used, pre_pushed);
    fflush(stdout);

    /* guest */
    seed(used_tags, n_used, xm, pre_pushed);
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, pre_pushed);
    if (!vf3_bone_transforms_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    /* capture the outputs of every used entry */
    size_t gsz = 0;
    for (uint32_t e = 0; e < ENTRIES; ++e)
        if (e < (uint32_t)n_used) gsz += 24u;    /* POINT_OUT + VEC_OUT triples */
    uint8_t *gvec = (uint8_t *)malloc(gsz ? gsz : 4u);
    size_t off = 0;
    for (uint32_t e = 0; e < ENTRIES; ++e) {
        if (e >= (uint32_t)n_used) continue;
        const uint32_t base = TABLE + e * ENTRY_BYTES;
        memcpy(gvec + off, at(base + POINT_OUT), 12u); off += 12u;
        memcpy(gvec + off, at(base + VEC_OUT), 12u);   off += 12u;
    }
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    const uint32_t gr14 = gs.v[14];

    /* native */
    seed(used_tags, n_used, xm, pre_pushed);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram; a.ram_base = RAM_BASE;
    a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    memcpy(a.xm, xm, sizeof a.xm);
    vf3_native_bone_transforms(&a);

    int bad = 0;
    /* outputs */
    off = 0;
    for (uint32_t e = 0; e < ENTRIES; ++e) {
        if (e >= (uint32_t)n_used) continue;
        const uint32_t base = TABLE + e * ENTRY_BYTES;
        char nm[16];
        snprintf(nm, sizeof nm, "p%u", e); bad |= cmp_vec(gvec, (uint32_t)off, base + POINT_OUT, nm); off += 12u;
        snprintf(nm, sizeof nm, "v%u", e); bad |= cmp_vec(gvec, (uint32_t)off, base + VEC_OUT, nm);   off += 12u;
    }
    /* final XMTRX (restored by the pop) - bit-exact */
    {
        int nb = 0;
        for (int i = 0; i < 16; ++i) {
            uint32_t ga, na; memcpy(&ga, &gxm[i], 4); memcpy(&na, &a.xm[i], 4);
            if (ga != na) { if (nb < 16) fprintf(stderr, "  xm[%d]: native %08x guest %08x\n", i, na, ga); nb++; }
        }
        printf("  xmtrx  : %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    if (a.r[14] != gr14) { fprintf(stderr, "  r14 native %08x guest %08x\n", a.r[14], gr14); bad++; }

    free(gvec);
    printf("  bone_transforms: %s\n", bad ? "FAIL" : "match");
    return bad;
}

int main(void)
{
    static const float M1[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, -2.0f, 0.5f, 1.0f,
    };
    static const unsigned short used_all[16] = {
        1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16,
    };
    static const unsigned short used_none[16] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };
    static const unsigned short used_some[16] = {
        1,0,3,0, 5,0,7,0, 0,0,0,0, 0,0,0,0,
    };

    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    bad |= run_case("all used", used_all, 16, M1, 0);
    bad |= run_case("none used", used_none, 0, M1, 0);
    bad |= run_case("some used", used_some, 8, M1, 0);
    bad |= run_case("pre-pushed stack", used_all, 16, M1, 1);
    free(ram);
    printf("bone_transforms_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
