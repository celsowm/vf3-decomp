/* Differential replay of the native clip-ring vertex emitter
 * (src/native/vertex_emit.c, 0x8C048C20) against the readable guest port
 * (src/fight/vertex_emit.c, `vf3_vertex_emit_ring_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FPU arithmetic, no stack frame and no device access: it packs the
 * lit/transformed vertex left in registers (FR4..FR7, FR2, FR3, r1, r2) into
 * one 32-byte slot of the 4-slot ring at 0x0C1A5960, chosen by (r11 & 3),
 * and leaves r0 = offset and r10 = the slot's low address.
 *
 * The fixture lays out the ring region and the vertex registers and runs the
 * two sides from the same seed.  The ring region is compared byte for byte,
 * together with the contract registers (r0, r10, pr) and the byte-identical
 * slot words. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "vertex_emit.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vertex_emit_ring_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define RING_BASE 0x0C1A5960u
#define RING_LEN_BYTES (4 * 32u + 0x100u)
#define RING_LO RING_BASE
#define RING_HI (RING_BASE + RING_LEN_BYTES)

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }

void set_fr(vf3_matrix_state *s, int n, float f)
{ uint32_t u; memcpy(&u, &f, 4); s->v[21 + n] = u; }

struct scenario {
    const char *name;
    uint32_t r11;
    float fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t r1, r2;
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

static void seed_all(const struct scenario *sc)
{
    (void)sc;
    memset(ram, 0, RAM_SIZE);
    /* leave the ring words as a pattern so an unwritten byte shows up */
    for (uint32_t ad = RING_LO; ad < RING_HI; ad += 4) {
        uint8_t *p = ab(ad);
        p[0]=0xFF; p[1]=0xEE; p[2]=0xDD; p[3]=0xCC;
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c048c50u;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr);
    gs.v[11] = sc->r11;
    gs.v[1] = sc->r1; gs.v[2] = sc->r2;
    set_fr(&gs, 2, sc->fr2); set_fr(&gs, 3, sc->fr3);
    set_fr(&gs, 4, sc->fr4); set_fr(&gs, 5, sc->fr5);
    set_fr(&gs, 6, sc->fr6); set_fr(&gs, 7, sc->fr7);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vertex_emit_ring_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = RING_HI - RING_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(RING_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r10 = gs.v[10];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[11] = sc->r11;
    a.r[1] = sc->r1; a.r[2] = sc->r2;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    a.fr[2] = sc->fr2; a.fr[3] = sc->fr3;
    a.fr[4] = sc->fr4; a.fr[5] = sc->fr5;
    a.fr[6] = sc->fr6; a.fr[7] = sc->fr7;
    vf3_native_vertex_emit_ring(&a);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RING_LO; ad < RING_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - RING_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  ring @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + fixture model */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[10] != g_r10) { fprintf(stderr, "  r10: native %08x guest %08x\n", a.r[10], g_r10); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }

        /* the model: the chosen slot and its eight words */
        const uint32_t off = (sc->r11 & 3u) * 32u;
        const uint32_t base = RING_BASE + off;
        if (a.r[0] != off) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], off); nb++; }
        if (a.r[10] != base) { fprintf(stderr, "  r10 %08x want %08x\n", a.r[10], base); nb++; }
        if (vf3_aim_u32(&a, base + 0x00) != vf3_aim_ubits(sc->fr4)) { fprintf(stderr, "  w0\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x04) != vf3_aim_ubits(sc->fr5)) { fprintf(stderr, "  w1\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x08) != vf3_aim_ubits(sc->fr6)) { fprintf(stderr, "  w2\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x0C) != vf3_aim_ubits(sc->fr7)) { fprintf(stderr, "  w3\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x10) != sc->r1) { fprintf(stderr, "  w4\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x14) != sc->r2) { fprintf(stderr, "  w5\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x18) != vf3_aim_ubits(sc->fr2)) { fprintf(stderr, "  w6\n"); nb++; }
        if (vf3_aim_u32(&a, base + 0x1C) != vf3_aim_ubits(sc->fr3)) { fprintf(stderr, "  w7\n"); nb++; }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("vertex_emit_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "slot 0", .r11 = 0,
          .fr2 = 0.5f, .fr3 = 1.5f, .fr4 = 1.0f, .fr5 = 2.0f, .fr6 = 3.0f, .fr7 = 4.0f,
          .r1 = 0x11111111u, .r2 = 0x22222222u },
        { .name = "slot 1", .r11 = 1,
          .fr2 = -0.5f, .fr3 = 2.5f, .fr4 = -1.0f, .fr5 = -2.0f, .fr6 = 3.25f, .fr7 = -4.5f,
          .r1 = 0xaaaaaaaau, .r2 = 0xbbbbbbbbu },
        { .name = "slot 2", .r11 = 2,
          .fr2 = 0.0f, .fr3 = 0.0f, .fr4 = 100.5f, .fr5 = -100.5f, .fr6 = 1.0f, .fr7 = 0.0f,
          .r1 = 0u, .r2 = 0xffffffffu },
        { .name = "slot 3", .r11 = 3,
          .fr2 = 1e-30f, .fr3 = 3e30f, .fr4 = 0.25f, .fr5 = 0.5f, .fr6 = 0.75f, .fr7 = 1.0f,
          .r1 = 0x12345678u, .r2 = 0x9abcdef0u },
        { .name = "slot wrap (r11=7 -> 3)", .r11 = 7,
          .fr2 = 1.0f, .fr3 = 2.0f, .fr4 = 3.0f, .fr5 = 4.0f, .fr6 = 5.0f, .fr7 = 6.0f,
          .r1 = 0x0000ffffu, .r2 = 0xffff0000u },
        { .name = "slot 0 large r11", .r11 = 0x40000000,
          .fr2 = 0.1f, .fr3 = 0.2f, .fr4 = 0.3f, .fr5 = 0.4f, .fr6 = 0.5f, .fr7 = 0.6f,
          .r1 = 1u, .r2 = 2u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("vertex_emit_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
