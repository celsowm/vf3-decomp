/* Differential replay of the native extent_flip (src/native/extent_flip.c,
 * 0x8C0CC3F0) against the readable guest port
 * (src/fight/extent_flip.c `vf3_extent_flip_entry`).
 *
 * Both sides seed the same flat RAM (six floats at r4 / r5-pointed flag word
 * and the fr4 limit), then run the leaf.  The leaf rewrites the three source
 * floats a0 a1 a2 = a0+b0, a1+b1 (floored at fr4 unless flag bit 1 is set),
 * a2+b2, and clears the flag word's bit 0 when a1+b1 is floored.  The test
 * compares the written RAM byte for byte against an independent fixture
 * model, the output registers/FR/T bit, and the untouched registers/FR. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "extent_flip.h"

#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_extent_flip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x10000u

#define REC   0x0C011000u   /* six floats a0 a1 a2 b0 b1 b2 */
#define FLAGS 0x0C011030u   /* flag word */
#define SP0   0x0C012000u

#define RETURN_PC 0x0c0cc408u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float f) { uint32_t u; memcpy(&u, &f, 4); w32(addr, u); }

/* --- independent fixture model (round-toward-zero + FTZ, as the leaf) --- */
static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }
static float tz_add(float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x + y;
    fesetround(saved);
    return z;
}
static float tz_sub(float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x - y;
    fesetround(saved);
    return z;
}

typedef struct {
    float out[3];      /* a0 a1 a2 */
    uint32_t flags;
    uint32_t sr_t;     /* the T bit */
    uint32_t r2, r3;
    int clobbered_23;  /* whether r2/r3 were written (clamp arm) */
} model_t;

static void model_case(float a0, float a1, float a2, float b0, float b1, float b2,
                       uint32_t flags, float fr4, model_t *m)
{
    float x = tz_add(a0, b0);
    float y = tz_add(a1, b1);
    /* z = -(-b2 - a2): the SH-4 flips b2's sign, subtracts a2, flips again */
    float fr3 = bits2f(fbits(b2) ^ 0x80000000u);
    float fr7 = tz_sub(fr3, a2);
    fr7 = bits2f(fbits(fr7) ^ 0x80000000u);

    m->flags = flags;
    m->r2 = m->r3 = 0;
    m->clobbered_23 = 0;
    if (!(flags & 2u)) {
        const int over = (y > fr4);
        m->sr_t = over ? 1u : 0u;
        if (!over) {
            m->flags &= 0xFFFFFFFEu;
            y = fr4;
            m->r2 = m->flags;
            m->r3 = 0xFFFFFFFEu;
            m->clobbered_23 = 1;
        }
    } else {
        m->sr_t = 0;
    }
    m->out[0] = x;
    m->out[1] = y;
    m->out[2] = fr7;
}

static void seed_case(float a0, float a1, float a2, float b0, float b1, float b2,
                      uint32_t flags)
{
    memset(ram, 0x6c, RAM_SIZE);
    wf(REC + 0, a0);  wf(REC + 4, a1);   wf(REC + 8, a2);
    wf(REC + 12, b0); wf(REC + 16, b1);  wf(REC + 20, b2);
    w32(FLAGS, flags);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54], uint32_t fr_in[16])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC;
    s->v[5] = FLAGS;
    s->v[15] = SP0;
    for (unsigned i = 0; i < 16; ++i) { fr_in[i] = 0x3f000000u + i * 0x1000u; s->v[VF3_REG_FR0 + i] = fr_in[i]; }
    s->v[16] = RETURN_PC;   /* pr */
    s->v[17] = 0x60000000u; /* SR: T clear */
    s->v[18] = 0x00024001u; /* FPSCR: truncate (RM), FTZ */
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

static int compare_one(float a0, float a1, float a2, float b0, float b1, float b2,
                       uint32_t flags, float fr4, int idx)
{
    /* fixture model (independent) */
    model_t m;
    model_case(a0, a1, a2, b0, b1, b2, flags, fr4, &m);

    int bad = 0;

    /* --- guest (readable oracle) --- */
    uint32_t gw_flags0 = flags;
    {
        seed_case(a0, a1, a2, b0, b1, b2, flags);
        vf3_matrix_state gs;
        vf3_ram_map gmap;
        vf3_ram_win gwin[1];
        uint32_t in_v[54], fr_in[16];
        setup_guest(&gs, &gmap, gwin, in_v, fr_in);
        gs.v[VF3_REG_FR0 + 4] = (uint32_t)fbits(fr4);
        vf3_family_override = vf3_readable_override;
        const int ok = vf3_extent_flip_entry(&gs, &gmap);
        vf3_family_override = NULL;
        if (!ok || gmap.oob) {
            fprintf(stderr, "  case %d: guest run failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
            return 1;
        }
        gw_flags0 = r32(FLAGS);

        /* guest output floats vs model */
        uint32_t go[3], mo[3];
        for (int e = 0; e < 3; ++e) { go[e] = r32(REC + 4u * (unsigned)e); memcpy(&mo[e], &m.out[e], 4); }
        for (int e = 0; e < 3; ++e)
            if (go[e] != mo[e]) fprintf(stderr, "  case %d: guest rec[%d] %08x model %08x\n", idx, e, go[e], mo[e]), bad++;
        if (gw_flags0 != m.flags) fprintf(stderr, "  case %d: guest flags %08x model %08x\n", idx, gw_flags0, m.flags), bad++;
    }

    /* --- native --- */
    uint32_t nw_flags0 = flags;
    {
        seed_case(a0, a1, a2, b0, b1, b2, flags);
        vf3_matrix_state gs;
        vf3_ram_map gmap;
        vf3_ram_win gwin[1];
        uint32_t in_v[54], fr_in[16];
        setup_guest(&gs, &gmap, gwin, in_v, fr_in);
        gs.v[VF3_REG_FR0 + 4] = (uint32_t)fbits(fr4);
        memcpy(in_v, gs.v, 54 * sizeof(uint32_t));

        /* build the native context from the captured entry state */
        vf3_native_aim x;
        memset(&x, 0, sizeof x);
        x.ram = (float *)ram;
        x.ram_base = RAM_BASE;
        for (unsigned i = 0; i < 16; ++i) x.r[i] = in_v[i];
        x.pr = RETURN_PC;
        x.sr = 0x60000000u;
        x.fpscr = 0x00024001u;
        for (unsigned i = 0; i < 16; ++i) x.fr[i] = (i == 4) ? fr4 : vf3_aim_fbits(fr_in[i]);
        vf3_native_extent_flip(&x);
        nw_flags0 = vf3_aim_u32(&x, FLAGS);

        /* native output floats vs model */
        uint32_t no[3], mo[3];
        for (int e = 0; e < 3; ++e) { no[e] = vf3_aim_u32(&x, REC + 4u * (unsigned)e); memcpy(&mo[e], &m.out[e], 4); }
        for (int e = 0; e < 3; ++e)
            if (no[e] != mo[e]) fprintf(stderr, "  case %d: native rec[%d] %08x model %08x\n", idx, e, no[e], mo[e]), bad++;
        if (nw_flags0 != m.flags) fprintf(stderr, "  case %d: native flags %08x model %08x\n", idx, nw_flags0, m.flags), bad++;

        /* registers: r0 = 8, r2/r3 only on the clamp arm, T bit */
        if (x.r[0] != 8u) fprintf(stderr, "  case %d: r0 %08x want 8\n", idx, x.r[0]), bad++;
        if (m.clobbered_23) {
            if (x.r[2] != m.r2) fprintf(stderr, "  case %d: r2 %08x want %08x\n", idx, x.r[2], m.r2), bad++;
            if (x.r[3] != m.r3) fprintf(stderr, "  case %d: r3 %08x want %08x\n", idx, x.r[3], m.r3), bad++;
        } else {
            if (x.r[2] != in_v[2]) fprintf(stderr, "  case %d: r2 clobbered %08x entry %08x\n", idx, x.r[2], in_v[2]), bad++;
            if (x.r[3] != in_v[3]) fprintf(stderr, "  case %d: r3 clobbered %08x entry %08x\n", idx, x.r[3], in_v[3]), bad++;
        }
        if ((x.sr & 1u) != m.sr_t) fprintf(stderr, "  case %d: T %u want %u\n", idx, x.sr & 1u, m.sr_t), bad++;
        /* r4 / r5 preserved */
        if (x.r[4] != REC) fprintf(stderr, "  case %d: r4 %08x\n", idx, x.r[4]), bad++;
        if (x.r[5] != FLAGS) fprintf(stderr, "  case %d: r5 %08x\n", idx, x.r[5]), bad++;
        /* untouched r1, r6..r15 preserved */
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 0 || i == 2 || i == 3 || i == 4 || i == 5) continue;
            if (x.r[i] != in_v[i]) fprintf(stderr, "  case %d: r%u clobbered %08x entry %08x\n", idx, i, x.r[i], in_v[i]), bad++;
        }

        /* FR outputs: fr2=a2, fr3=-b2, fr5=a1 result, fr6=x, fr7=z; others
         * preserved (fr4 = the limit) */
        uint32_t mf2, mf3, mf5, mf6, mf7;
        float nb2 = bits2f(fbits(b2) ^ 0x80000000u);
        memcpy(&mf2, &a2, 4);  memcpy(&mf3, &nb2, 4);
        memcpy(&mf5, &m.out[1], 4); memcpy(&mf6, &m.out[0], 4); memcpy(&mf7, &m.out[2], 4);
        if (vf3_aim_ubits(x.fr[2]) != mf2) fprintf(stderr, "  case %d: fr2 %08x want %08x\n", idx, vf3_aim_ubits(x.fr[2]), mf2), bad++;
        if (vf3_aim_ubits(x.fr[3]) != mf3) fprintf(stderr, "  case %d: fr3 %08x want %08x\n", idx, vf3_aim_ubits(x.fr[3]), mf3), bad++;
        if (vf3_aim_ubits(x.fr[5]) != mf5) fprintf(stderr, "  case %d: fr5 %08x want %08x\n", idx, vf3_aim_ubits(x.fr[5]), mf5), bad++;
        if (vf3_aim_ubits(x.fr[6]) != mf6) fprintf(stderr, "  case %d: fr6 %08x want %08x\n", idx, vf3_aim_ubits(x.fr[6]), mf6), bad++;
        if (vf3_aim_ubits(x.fr[7]) != mf7) fprintf(stderr, "  case %d: fr7 %08x want %08x\n", idx, vf3_aim_ubits(x.fr[7]), mf7), bad++;
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7) continue;
            if (vf3_aim_ubits(x.fr[i]) != fr_in[i]) fprintf(stderr, "  case %d: fr%u clobbered %08x entry %08x\n", idx, i, vf3_aim_ubits(x.fr[i]), fr_in[i]), bad++;
        }
    }

    return bad;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    /* 1) flag bit 1 set (keep as-is): no clamp, T clear */
    bad += compare_one(1.5f, -2.5f, 3.0f, 4.0f, 5.0f, -1.0f, 0x00000002u, 0.0f, 1);
    /* 2) flag bit 1 clear, a1+b1 above fr4: kept, T set */
    bad += compare_one(1.5f, -2.5f, 3.0f, 4.0f, 5.0f, -1.0f, 0x00000000u, -5.0f, 2);
    /* 3) flag bit 1 clear, a1+b1 at/below fr4: floored, flag bit0 cleared,
     * T clear, r2/r3 written (flag bit 0 set so the mask is observable) */
    bad += compare_one(1.5f, -2.5f, 3.0f, 4.0f, 5.0f, -1.0f, 0x00000001u, 20.0f, 3);
    /* 4) exact boundary: a1+b1 == fr4 -> floored (not above) */
    bad += compare_one(1.0f, 2.0f, -3.0f, 4.0f, 5.0f, 6.0f, 0x00000000u, 7.0f, 4);
    /* 5) single-precision rounding visibility on the adds */
    bad += compare_one(0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0x00000002u, 0.0f, 5);
    /* 6) negative a1+b1 below fr4 (fr4 positive big) */
    bad += compare_one(-10.0f, -20.0f, -30.0f, 1.0f, 2.0f, 3.0f, 0x00000000u, 0.0f, 6);

    free(ram);
    printf("extent_flip_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
