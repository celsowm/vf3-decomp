/* Differential replay of the native matrix copy leaf
 * (src/native/matrix_copy.c, 0x8C03B530) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_copy_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX / FR3, then run the
 * leaf.  The function is call-free and no-stack (the r14 "push" only writes
 * [sp-4] without moving sp).  Four arms are covered: both-null, null dst
 * (load), null src (store) and a full copy.  After the run the whole XMTRX
 * (guest v[37..52] vs native a->xm[16]), FR3 (guest v[24] vs a->fr[3]) and
 * every general register are compared against the guest, and the full low
 * RAM region (the source, the destination, the dead push) byte-for-byte. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "matrix_copy.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define MATRIX_SRC  0x0C1A0000u
#define DST_OBJ     0x0C1B0000u
#define STK_PTR_ADDR 0x0C19D2ECu
#define STK_PTR_VAL 0x0C1B0200u
#define SP0         0x0C190000u   /* r15; the dead push lands at sp-4 */
#define LOW_END  0x0C18E000u   /* must cover SP0-4 = 0x0C18FFFC (the dead push) */
#define HI_END   0x0C1C0000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    uint32_t dst;   /* r4 */
    uint32_t src;   /* r5 */
};

#define RETURN_PC 0x0c03b520u /*(irrelevant; leaf pops pr)*/

static void seed_scene(void)
{
    memset(ram, 0x3a, RAM_SIZE);
    for (uint32_t i = 0; i < 16; ++i)
        w32(MATRIX_SRC + 4u * i, 0x3F800000u + 0x11111111u * i);
    w32(STK_PTR_ADDR, STK_PTR_VAL);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, uint32_t sxm)
{
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t w = sxm + 0x9E3779B9u * (i + 1u);
        if (s) s->v[37 + i] = w;
        if (a) a->xm[i] = vf3_aim_fbits(w);
    }
    const uint32_t fr3 = 0x40490FDBu;   /* distinct FR3 */
    if (s) s->v[24] = fr3;
    if (a) a->fr[3] = vf3_aim_fbits(fr3);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (dst %08x src %08x)\n", sc->name, sc->dst, sc->src);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[15] = SP0;
    gs.v[4] = sc->dst;
    gs.v[5] = sc->src;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = 0x00024001u;
    gs.budget = 4000000u;

    seed_scene();
    seed_xf(&gs, NULL, 0x40000000u);

    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;

    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_matrix_copy_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_scene();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    seed_xf(NULL, &a, 0x40000000u);

    vf3_native_matrix_copy(&a);

    int bad = 0;

    /* XMTRX vs guest XF bank */
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    /* FR3 vs guest */
    if (vf3_aim_ubits(a.fr[3]) != gs.v[24]) {
        fprintf(stderr, "  fr3 native %08x guest %08x\n",
                vf3_aim_ubits(a.fr[3]), gs.v[24]); bad++;
    }
    /* every general register vs guest */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    /* RAM region (source, dest, dead push) byte-for-byte */
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }
    /* the independent fixture model for the copy arm */
    if (sc->dst == 0 && sc->src == 0) {
        /* both-null: nothing moves but no check needed beyond the above */
    }

    free(gshot);
    printf("  matrix_copy: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "both null",               0u,          0u },
        { "null dst (load)",         0u,          MATRIX_SRC },
        { "null src (store)",        DST_OBJ,     0u },
        { "full copy",               DST_OBJ,     MATRIX_SRC },
        { "copy dst==src area",      MATRIX_SRC,  DST_OBJ },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("matrix_copy_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
