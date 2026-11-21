/* Differential replay of the native store-queue vertex emitter
 * (src/native/vertex_emit_sq.c, 0x8C048BE0) against the readable guest port
 * (src/fight/vertex_emit.c, `vf3_vertex_emit_sq_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free FP body with
 * no stack frame and no device access (the SQ PREF is a no-op without SQ
 * modeling): it perspective-scales the vertex's y',z' (FR5, FR6) by 1/x'
 * (FR7), packs the vertex into the 32-byte slot at r6, and overwrites the
 * control word with the slot address for an in-strip vertex or
 * (slot + 0x14) >> 1 for the last one.
 *
 * The fixture lays out the slot region and the vertex registers and runs the
 * two sides from the same seed.  The region is compared byte for byte,
 * together with the contract registers (r2, r3, r5, r6, SR.T, pr), the FR
 * bank and the byte-identical slot words. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "vertex_emit_sq.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vertex_emit_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define SLOT_BASE 0x0C1A5960u
#define SLOT_LEN_BYTES (2 * 32u + 0x40u)
#define REGION_LO SLOT_BASE
#define REGION_HI (SLOT_BASE + SLOT_LEN_BYTES)

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }

static void set_fr(vf3_matrix_state *s, int n, float f)
{ uint32_t u; memcpy(&u, &f, 4); s->v[21 + n] = u; }

struct scenario {
    const char *name;
    uint32_t r3;       /* vertices left */
    uint32_t r1, r2;   /* the record's trailing words */
    float fr2, fr3, fr4, fr5, fr6, fr7;
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r5, uint32_t r6, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[5] = r5;
    s->v[6] = r6;
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
    /* leave the slot region as a pattern so an unwritten byte shows up */
    for (uint32_t ad = REGION_LO; ad < REGION_HI; ad += 4) {
        uint8_t *p = ab(ad);
        p[0]=0xFF; p[1]=0xEE; p[2]=0xDD; p[3]=0xCC;
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c048c04u;
    const uint32_t sr = 0x60000000u;
    const uint32_t r5 = 0x0c111000u, r6 = SLOT_BASE;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, r5, r6, pr, sr);
    gs.v[3] = sc->r3;
    gs.v[1] = sc->r1; gs.v[2] = sc->r2;
    set_fr(&gs, 2, sc->fr2); set_fr(&gs, 3, sc->fr3);
    set_fr(&gs, 4, sc->fr4); set_fr(&gs, 5, sc->fr5);
    set_fr(&gs, 6, sc->fr6); set_fr(&gs, 7, sc->fr7);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_vertex_emit_sq_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = REGION_HI - REGION_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REGION_LO), l0);

    const uint32_t g_r2 = gs.v[2], g_r3 = gs.v[3], g_r5 = gs.v[5], g_r6 = gs.v[6];
    const uint32_t g_sr = gs.v[17];
    const uint32_t g_fr5 = gs.v[26], g_fr6 = gs.v[27];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[3] = sc->r3;
    a.r[5] = r5;
    a.r[6] = r6;
    a.r[1] = sc->r1; a.r[2] = sc->r2;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    a.fr[2] = sc->fr2; a.fr[3] = sc->fr3;
    a.fr[4] = sc->fr4; a.fr[5] = sc->fr5;
    a.fr[6] = sc->fr6; a.fr[7] = sc->fr7;
    vf3_native_vertex_emit_sq(&a);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = REGION_LO; ad < REGION_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  slot @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + FR */
    {
        int nb = 0;
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[5]) != g_fr5) { fprintf(stderr, "  fr5 differs\n"); nb++; }
        if (vf3_aim_ubits(a.fr[6]) != g_fr6) { fprintf(stderr, "  fr6 differs\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs+fr: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent fixture model */
    {
        int nb = 0;
        /* the control word: slot address or tail */
        const uint32_t tail = (uint32_t)((int32_t)(r6 + 0x14) >> 1);
        const int last = (sc->r3 - 1u) == 0;
        const uint32_t want_ctrl = last ? tail : r6;
        if (vf3_aim_u32(&a, r6) != want_ctrl) { fprintf(stderr, "  ctrl %08x want %08x\n", vf3_aim_u32(&a, r6), want_ctrl); nb++; }
        if (a.r[2] != tail) { fprintf(stderr, "  r2 %08x want %08x\n", a.r[2], tail); nb++; }
        if ((a.sr & 1u) != (unsigned)last) { fprintf(stderr, "  T %u want %u\n", a.sr & 1u, last); nb++; }
        if (a.r[3] != sc->r3 - 1u) { fprintf(stderr, "  r3 %08x want %08x\n", a.r[3], sc->r3 - 1u); nb++; }
        if (a.r[5] != r5 + 32u) { fprintf(stderr, "  r5 %08x want %08x\n", a.r[5], r5 + 32u); nb++; }
        if (a.r[6] != r6 + 32u) { fprintf(stderr, "  r6 %08x want %08x\n", a.r[6], r6 + 32u); nb++; }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
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
        printf("vertex_emit_sq_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "in-strip r3=4", .r3 = 4, .r1 = 0x11111111u, .r2 = 0x22222222u,
          .fr2 = 0.5f, .fr3 = 1.5f, .fr4 = 1.0f, .fr5 = 2.0f, .fr6 = 3.0f, .fr7 = 0.5f },
        { .name = "last r3=1", .r3 = 1, .r1 = 0xaaaaaaaa, .r2 = 0xbbbbbbbb,
          .fr2 = -0.5f, .fr3 = 2.5f, .fr4 = -1.0f, .fr5 = -2.0f, .fr6 = 3.25f, .fr7 = 2.0f },
        { .name = "r3=2", .r3 = 2, .r1 = 0u, .r2 = 0xffffffffu,
          .fr2 = 0.0f, .fr3 = 0.25f, .fr4 = 100.5f, .fr5 = -100.5f, .fr6 = 1.0f, .fr7 = 1.0f },
        { .name = "fractional scale", .r3 = 3, .r1 = 0x12345678u, .r2 = 0x9abcdef0u,
          .fr2 = 1e-30f, .fr3 = 3e30f, .fr4 = 0.25f, .fr5 = 0.5f, .fr6 = 0.75f, .fr7 = 0.1f },
        { .name = "zero scale", .r3 = 7, .r1 = 1u, .r2 = 2u,
          .fr2 = 1.0f, .fr3 = 2.0f, .fr4 = 3.0f, .fr5 = 4.0f, .fr6 = 5.0f, .fr7 = 0.0f },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("vertex_emit_sq_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
