/* Differential replay of the native node rotation (src/native/node_rotate.c,
 * 0x8C09F83C) against the readable guest port (src/fight/node_rotate.c,
 * `vf3_node_rotate_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf turns seven twelve-byte
 * records around the Y axis by the angle the caller leaves in FR4 (cosine) and
 * FR5 (sine), then moves the root's position by the value the caller leaves in
 * FR6.
 *
 * The literal pool and the object (seven records + the root's coordinates)
 * sit at the game's own addresses, spanned by one flat buffer.  The whole
 * region is compared byte for byte, together with the registers, the FR bank,
 * SR's T bit and an independent fixture model that computes the record
 * rotation and the root's move straight from the fixture.
 *
 * The leaf runs under round-to-nearest and no FTZ (the FPSCR is 0), so the
 * native uses plain C float ops and `fmaf`. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "node_rotate.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_node_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POOL_BASE 0x0c09f8d0u
#define POOL_LEN  4u
#define OBJ_BASE  0x0c120000u
#define OBJ_LEN   0x80u
#define CMP_HI    (OBJ_BASE + OBJ_LEN)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define G_Y      POOL_BASE
#define Y_OFFSET 0x6cu
#define ROOT_X   0x58u
#define ROOT_STEP 24u

#define NODES     7u
#define NODE_STRIDE 12u

struct scenario {
    const char *name;
    float cos;          /* FR4 */
    float sin;          /* FR5 */
    float move;         /* FR6 */
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t addr, uint16_t v) { ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w16(G_Y, (uint16_t)Y_OFFSET);
    for (unsigned i = 0; i < NODES; ++i) {
        const uint32_t at = i * NODE_STRIDE;
        w32(OBJ_BASE + at, fbits(1.0f + (float)i));
        w32(OBJ_BASE + at + 8u, fbits(10.0f + (float)i));
    }
    w32(OBJ_BASE + ROOT_X, fbits(100.0f));
    w32(OBJ_BASE + Y_OFFSET, fbits(200.0f));
    w32(OBJ_BASE + Y_OFFSET - ROOT_STEP, fbits(300.0f));
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->v[21 + 4] = fbits(sc->cos);
    s->v[21 + 5] = fbits(sc->sin);
    s->v[21 + 6] = fbits(sc->move);
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[2] = {
        { POOL_BASE, POOL_LEN }, { OBJ_BASE, OBJ_LEN },
    };
    for (unsigned i = 0; i < 2; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = 2;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the fixture model: the readable's record rotation - the stored first float
 * is `sin * first - cos * second` and the stored second is
 * `sin * second + first * cos` under the caller's FR4=cos, FR5=sin - plus the
 * root's three coordinates each moved by FR6. */
static void expect_fixture(const struct scenario *sc, float out[7][2],
                           float root[3])
{
    for (unsigned i = 0; i < NODES; ++i) {
        const float first = 1.0f + (float)i;
        const float second = 10.0f + (float)i;
        out[i][0] = sc->sin * first - sc->cos * second;
        out[i][1] = sc->sin * second + first * sc->cos;
    }
    root[0] = 100.0f + sc->move;
    root[1] = 200.0f + sc->move;
    root[2] = 300.0f + sc->move;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[2];
    setup_guest(&gs, &gmap, gwin, sc);
    uint32_t in_v[54];
    memcpy(in_v, gs.v, sizeof in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_node_rotate_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &in_v[21u + i], 4);
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    a.fpul = in_v[53];
    vf3_native_node_rotate(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* registers + FR bank + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr differs\n"); nb++; }
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t ub;
            memcpy(&ub, &a.fr[i], 4);
            if (ub != gs.v[21u + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        }

        float out[7][2], root[3];
        expect_fixture(sc, out, root);
        for (unsigned i = 0; i < NODES; ++i) {
            if (r32(OBJ_BASE + i * NODE_STRIDE) != fbits(out[i][0])) {
                fprintf(stderr, "  record %u first %08x, expected %08x\n",
                        i, r32(OBJ_BASE + i * NODE_STRIDE), fbits(out[i][0]));
                nb++;
            }
            if (r32(OBJ_BASE + i * NODE_STRIDE + 8u) != fbits(out[i][1])) {
                fprintf(stderr, "  record %u second %08x, expected %08x\n",
                        i, r32(OBJ_BASE + i * NODE_STRIDE + 8u), fbits(out[i][1]));
                nb++;
            }
        }
        if (r32(OBJ_BASE + ROOT_X) != fbits(root[0])) {
            fprintf(stderr, "  root x %08x, expected %08x\n",
                    r32(OBJ_BASE + ROOT_X), fbits(root[0]));
            nb++;
        }
        if (r32(OBJ_BASE + Y_OFFSET) != fbits(root[1])) {
            fprintf(stderr, "  root y %08x, expected %08x\n",
                    r32(OBJ_BASE + Y_OFFSET), fbits(root[1]));
            nb++;
        }
        if (r32(OBJ_BASE + Y_OFFSET - ROOT_STEP) != fbits(root[2])) {
            fprintf(stderr, "  root z %08x, expected %08x\n",
                    r32(OBJ_BASE + Y_OFFSET - ROOT_STEP), fbits(root[2]));
            nb++;
        }
        if (a.r[6] != 0)           { fprintf(stderr, "  r6 %08x\n", a.r[6]); nb++; }
        if (a.r[0] != (uint32_t)(Y_OFFSET - ROOT_STEP)) {
            fprintf(stderr, "  r0 %08x\n", a.r[0]); nb++;
        }
        if (a.r[5] != OBJ_BASE + NODES * NODE_STRIDE) {
            fprintf(stderr, "  r5 %08x\n", a.r[5]); nb++;
        }
        if ((a.sr & 1u) != 1) { fprintf(stderr, "  T bit is %u, expected 1\n", a.sr & 1u); nb++; }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "identity",    1.0f, 0.0f, 0.0f },
        { "quarter",     0.0f, 1.0f, 0.0f },
        { "half",       -1.0f, 0.0f, 0.0f },
        { "angle",       0.5f, 0.8660254f, 0.0f },
        { "moved",       1.0f, 0.0f, 7.5f },
        { "angle moved", 0.5f, 0.8660254f, -2.25f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("node_rotate_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
