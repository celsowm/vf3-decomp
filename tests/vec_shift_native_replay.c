/* Differential replay of the native vec-shift (src/native/vec_shift.c,
 * 0x8C0748E0) against the readable guest port (src/fight/vec_shift.c,
 * `vf3_vec_shift_entry`).
 *
 * Both sides seed the same flat RAM (an object with its offset vector, its
 * position vec3 and 28 point-record vec3s) and the same register file, then
 * run the leaf.  The function is call-free and no-stack; it adds the offset
 * vec (x,y,z) to the position and to each of the 28 point vec3s (stride 12),
 * leaving r0 = 8, r5 = r6 = one past the last point and SR's T bit set.  The
 * whole RAM span is compared byte for byte against a snapshot of the guest's
 * writes, together with the output registers (r0, r5, r6), SR's T bit, the
 * untouched ones, and an independent fixture model that adds the offset
 * straight from the addresses. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vec_shift.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>

int vf3_vec_shift_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x120000u

#define OBJ_BASE 0x0c118000u
#define OFFSET       0x13A8u
#define POINTS_PTR   0x138Cu
#define POSITION     0x1488u
#define POINTS_LEN   0x150u
#define POINT_STRIDE 12u
#define NPOINT       28u

#define LOW_END 0x0c118000u
#define HI_END  0x0c11c000u

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

struct scenario {
    const char *name;
};

#define RETURN_PC 0x0c0748e6u
#define POINTS_ADDR 0x0c11a000u   /* where POINTS_PTR points (the 28 vec3s) */

static void seed_all(uint32_t r4_in)
{
    memset(ram, 0x6c, RAM_SIZE);
    uint32_t off = (r4_in & 0xFFFFFu);
    /* offset vector (x,y,z) at obj+OFFSET */
    w32(r4_in + OFFSET + 0u, 0x3f000000u);      /* 0.5 */
    w32(r4_in + OFFSET + 4u, 0xc0400000u);      /* -3.0 */
    w32(r4_in + OFFSET + 8u, 0x40000000u);      /* 2.0 */
    /* the points pointer (points stay at the fixed POINTS_ADDR) */
    w32(r4_in + POINTS_PTR, POINTS_ADDR);
    /* the position vec3 (matters: it gets the offset first) */
    w32(r4_in + POSITION + 0u, 0x3f800000u);
    w32(r4_in + POSITION + 4u, 0x40400000u);
    w32(r4_in + POSITION + 8u, 0xbf800000u);
    /* 28 point vec3s, distinct */
    for (unsigned e = 0; e < NPOINT; ++e) {
        w32(POINTS_ADDR + POINT_STRIDE * e + 0u, 0x3f000000u + e);
        w32(POINTS_ADDR + POINT_STRIDE * e + 4u, 0x40000000u + e);
        w32(POINTS_ADDR + POINT_STRIDE * e + 8u, 0xc0000000u + e);
    }
}

static uint32_t b32(const uint8_t *snap, uint32_t addr)
{
    const uint8_t *p = snap + (addr - LOW_END);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4_in, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4_in;             /* r4 = object */
    s->v[0] = 0x11111111u;       /* clobber */
    s->v[5] = 0x22222222u;
    s->v[6] = 0x33333333u;
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000040u;      /* SR: T clear (the leaf sets it) */
    s->v[18] = 0x00024001u;      /* FPSCR: truncate (RM), FTZ */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc, uint32_t r4_in)
{
    printf("== %s (r4 %08x)\n", sc->name, r4_in);

    seed_all(r4_in);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, r4_in, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vec_shift_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_all(r4_in);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000040u;
    a.fpscr = 0x00024001u;
    uint8_t *before = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(before, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);
    vf3_native_vec_shift(&a);

    int bad = 0;

    /* RAM: native writes vs the guest snapshot, byte for byte */
    {
        int nb = 0;
        for (uint32_t ad = LOW_END; ad < HI_END; ad += 4) {
            uint32_t n = vf3_aim_u32(&a, ad);
            uint32_t g;
            memcpy(&g, gshot + (ad - LOW_END), 4);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", LOW_END, HI_END, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* output registers + T vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 5 || i == 6) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* the fixture model: offset added to the position and every point vec3 */
    {
        int nb = 0;
        uint32_t obj = r4_in;
        const uint32_t off0 = b32(before, obj + OFFSET + 0u);
        const uint32_t off1 = b32(before, obj + OFFSET + 4u);
        const uint32_t off2 = b32(before, obj + OFFSET + 8u);
        float ox, oy, oz;
        memcpy(&ox, &off0, 4); memcpy(&oy, &off1, 4); memcpy(&oz, &off2, 4);

        /* position vec3 */
        {
            struct { uint32_t addr; float o; } pos[3] = {
                { obj + POSITION + 0u, ox }, { obj + POSITION + 4u, oy }, { obj + POSITION + 8u, oz },
            };
            for (unsigned e = 0; e < 3; ++e) {
                uint32_t pb = b32(before, pos[e].addr);
                float pre; memcpy(&pre, &pb, 4);
                const int saved = fegetround();
                fesetround(FE_TOWARDZERO);
                volatile float want = pre + pos[e].o;
                fesetround(saved);
                uint32_t rb = r32(pos[e].addr);
                float got; memcpy(&got, &rb, 4);
                uint32_t wantb; memcpy(&wantb, &want, 4);
                if (memcmp(&want, &got, 4) != 0) { fprintf(stderr, "  pos[%u] @%08x: got %08x want %08x\n", e, pos[e].addr, rb, wantb); nb++; }
            }
        }
        /* each point vec3 */
        for (unsigned e = 0; e < NPOINT; ++e) {
            struct { uint32_t addr; float o; } c[3] = {
                { POINTS_ADDR + POINT_STRIDE * e + 0u, ox },
                { POINTS_ADDR + POINT_STRIDE * e + 4u, oy },
                { POINTS_ADDR + POINT_STRIDE * e + 8u, oz },
            };
            for (unsigned k = 0; k < 3; ++k) {
                uint32_t pb = b32(before, c[k].addr);
                float pre; memcpy(&pre, &pb, 4);
                const int saved = fegetround();
                fesetround(FE_TOWARDZERO);
                volatile float want = pre + c[k].o;
                fesetround(saved);
                uint32_t rb = r32(c[k].addr);
                float got; memcpy(&got, &rb, 4);
                if (memcmp(&want, &got, 4) != 0) { fprintf(stderr, "  pt[%u][%u] @%08x differs\n", e, k, c[k].addr); nb++; }
            }
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    free(before);
    free(gshot);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "base offset 0" },
        { .name = "base offset 8" },
    };
    static const uint32_t r4s[] = { OBJ_BASE, OBJ_BASE + 8u };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i], r4s[i]);

    free(ram);
    printf("vec_shift_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
