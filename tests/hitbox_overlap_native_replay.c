/* Differential replay of the native fighter-vs-fighter capsule overlap scan
 * (src/native/hitbox_overlap.c, 0x8C073AAC) against the readable guest port
 * (src/fight/hitbox_overlap.c, `vf3_hitbox_overlap_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map, the
 * native through `ram_base`.  The fixture lays out the result block `out`,
 * the two fighter objects A and B (each with 28 capsule segments, radius
 * arrays and hit words), the shared radius tables and the pause/demo flag,
 * seeds the entry registers and the saved fr/pr words, and runs the two sides
 * from the same seed.  The outputs the routine writes - the min distance at
 * out+48, the pair count at out+52, both fighters' radius arrays and both
 * fighters' hit-word arrays - are compared; the saved-register stack and the
 * contract registers (r8..r14, r15, pr, fr12..fr15, SR's T bit) are compared
 * bit for bit.
 *
 * The hit words and pair count are integer decisions made from float values,
 * so the native port reproduces the guest's round-toward-zero FPU arithmetic
 * (the same vf3_fpu_* helpers) and is expected to match bit for bit. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "hitbox_overlap.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_hitbox_overlap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x2C0000u   /* covers the pause-flag global at 0x0C29BCC0 */

#define OUT   0x0C200000u
#define A     0x0C201000u
#define B     0x0C205000u
#define SP0   0x0C216000u

#define RADIUS_OFF 0x12AC
#define HITWORD_OFF 0x131C
#define SEG_A_OFF 0x138C     /* at +0x138C / +0x1390 the fighter holds POINTERS */
#define SEG_B_OFF 0x1390     /* to its two segment arrays (see below) */
#define COUNT_CAPS 28

/* The +0x138C / +0x1390 slots hold pointers to the actual segment arrays, so
 * the fixture stores the coordinates at these storage addresses and writes the
 * pointers into the fighter slots. */
#define SEGSTOR 0x0C208000u      /* base of the four segment arrays */
#define SEG_A1 SEGSTOR
#define SEG_A2 (SEGSTOR + 0x400u)
#define SEG_B1 (SEGSTOR + 0x800u)
#define SEG_B2 (SEGSTOR + 0xC00u)

/* The shared radius table at 0x0C10D390 holds POINTERS to per-character radius
 * arrays (the do-loop derefs the table entry and walks it by +4).  Two
 * per-character arrays live here, picked by the byte at fighter+97. */
#define CHAR_RAD_A 0x0C209000u
#define CHAR_RAD_B 0x0C20A000u

/* compare ranges: the fighter objects' capsule data + the saved stack.
 * OBJ_REGION starts at OUT so the out block (+48/+52) is inside the copy. */
#define OBJ_REGION_LO OUT
#define OBJ_REGION_HI (B + 0x2000u)
#define FRAME_REGION_LO (SP0 - 48u)
#define FRAME_REGION_HI (SP0 + 32u)

static float *ram;

static float *at(uint32_t addr)
{
    return (float *)((uint8_t *)ram + (addr - RAM_BASE));
}
static uint8_t *ab(uint32_t addr)
{
    return (uint8_t *)ram + (addr - RAM_BASE);
}

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v)
{
    uint32_t u; memcpy(&u, &v, 4); w32(addr, u);
}

/* place `count` capsules on fighter `f`.  The fighter holds pointers to its two
 * segment arrays at f+SEG_A_OFF and f+SEG_B_OFF; the coordinates live at the
 * storage addresses s1 (own ends) and s2 (second ends), `count` vec3s 12 bytes
 * apart.  Radius array at f+RADIUS_OFF. */
static void seed_fighter(uint32_t f, uint32_t s1, uint32_t s2, int count,
                         const float (*seg)[3], const float (*seg2)[3],
                         const float *radii)
{
    w32(f + SEG_A_OFF, s1);
    w32(f + SEG_B_OFF, s2);
    for (int i = 0; i < count; ++i) {
        wf(s1 + 12u * (uint32_t)i + 0u, seg[i][0]);
        wf(s1 + 12u * (uint32_t)i + 4u, seg[i][1]);
        wf(s1 + 12u * (uint32_t)i + 8u, seg[i][2]);
        wf(s2 + 12u * (uint32_t)i + 0u, seg2[i][0]);
        wf(s2 + 12u * (uint32_t)i + 4u, seg2[i][1]);
        wf(s2 + 12u * (uint32_t)i + 8u, seg2[i][2]);
        wf(f + RADIUS_OFF + 4u * (uint32_t)i, radii[i]);
    }
}

/* shared radius TABLE at 0x0C10D390 (indexed by the byte at fighter+97) whose
 * entries are POINTERS to 28-float per-character radius arrays; and the
 * capsule-participation table at 0x0C110994 (indexed by +0x1A20).  The
 * rebuild step derefs the table entry and walks it by +4, so the arrays live
 * at CHAR_RAD_A / CHAR_RAD_B. */
static void seed_tables(uint32_t a97, uint32_t b97, int count,
                        const float *radA, const float *radB)
{
    for (int i = 0; i < 256; ++i) {
        wf(CHAR_RAD_A + 4u * (uint32_t)i, 0.5f);   /* default radii */
        wf(CHAR_RAD_B + 4u * (uint32_t)i, 0.5f);
        w32(0x0C10D390u + 4u * (uint32_t)i, CHAR_RAD_A);   /* default: every table row -> A array */
        w32(0x0C110994u + 4u * (uint32_t)i, 0xFFFFFFFFu);
    }
    /* the two characters actually used get their own arrays and pointers */
    for (int i = 0; i < count; ++i) {
        wf(CHAR_RAD_A + 4u * (uint32_t)i, radA[i]);
        wf(CHAR_RAD_B + 4u * (uint32_t)i, radB[i]);
    }
    w32(0x0C10D390u + 4u * a97, CHAR_RAD_A);
    w32(0x0C10D390u + 4u * b97, CHAR_RAD_B);
}

static void seed(uint32_t pause_flags, int count,
                 const float (*segA)[3], const float (*seg2A)[3], const float *radA,
                 const float (*segB)[3], const float (*seg2B)[3], const float *radB,
                 uint32_t a97, uint32_t b97)
{
    memset((uint8_t *)at(OUT), 0xAA, 0x3000u);
    w32(0x0C29BCC0u, pause_flags);
    seed_fighter(A, SEG_A1, SEG_A2, count, segA, seg2A, radA);
    seed_fighter(B, SEG_B1, SEG_B2, count, segB, seg2B, radB);
    seed_tables(a97, b97, count, radA, radB);
    ab(A + 97)[0] = (uint8_t)a97;        /* the per-character radius table index */
    ab(B + 97)[0] = (uint8_t)b97;
    w32(A + 76, 0); w32(B + 76, 0);      /* the 0x20 step-3 switch clear (step 3 runs) */
    w32(A + 0x1A04, 0); w32(B + 0x1A04, 0);
    w32(A + 0x1560, 0); w32(B + 0x1560, 0);   /* +0x1560 bit1 clear: rebuild radii */
    w32(A + 0x1A20, 0); w32(B + 0x1A20, 0);   /* participation table index (uses entry 0) */
    wf(A, 0.0f); wf(B, 0.0f);             /* the 0x00800000 flag at fighter +0 is clear */
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const uint32_t *regs, uint32_t pr, const float *frseed,
                        uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = regs[i];
    s->v[4] = OUT; s->v[5] = A; s->v[6] = B;
    s->v[15] = SP0;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00040001u;              /* fpscr: round-toward-zero, PR single */
    for (int i = 0; i < 4; ++i) {
        uint32_t bits; memcpy(&bits, &frseed[i], 4);
        s->v[21 + 12 + i] = bits;        /* FR12..FR15 */
    }
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = (uint8_t *)ram;
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

struct fixture {
    const char *label;
    uint32_t pause_flags;
    int count;
    const float (*segA)[3];
    const float (*seg2A)[3];
    const float *radA;
    const float (*segB)[3];
    const float (*seg2B)[3];
    const float *radB;
};

/* A single capsule landing directly on one of B's produces one hit. */
static const float segA_hit[1][3] = { { 0.0f, 0.0f, 0.0f } };
static const float seg2A_hit[1][3] = { { 2.0f, 0.0f, 0.0f } };
static const float radA_hit[1] = { 1.0f };
static const float segB_hit[1][3] = { { 0.5f, 0.0f, 0.0f } };
static const float seg2B_hit[1][3] = { { 0.5f, 3.0f, 0.0f } };
static const float radB_hit[1] = { 1.0f };

/* A clear miss: both segments far apart, inflated boxes don't overlap. */
static const float segA_miss[1][3] = { { 0.0f, 0.0f, 0.0f } };
static const float seg2A_miss[1][3] = { { 2.0f, 0.0f, 0.0f } };
static const float radA_miss[1] = { 0.3f };
static const float segB_miss[1][3] = { { 100.0f, 100.0f, 100.0f } };
static const float seg2B_miss[1][3] = { { 101.0f, 100.0f, 100.0f } };
static const float radB_miss[1] = { 0.3f };

/* Two of A's capsules hit two of B's (a longer segment layout). */
static const float segA2[2][3] = { { 0.0f, 0.0f, 0.0f }, { -3.0f, 1.0f, 0.0f } };
static const float seg2A2[2][3] = { { 2.0f, 0.0f, 0.0f }, { -1.0f, 1.0f, 0.0f } };
static const float radA2[2] = { 0.7f, 0.7f };
static const float segB2[2][3] = { { 0.8f, 0.2f, 0.2f }, { -2.2f, 1.0f, 0.1f } };
static const float seg2B2[2][3] = { { 0.8f, 3.0f, 0.2f }, { -2.2f, 3.2f, 0.1f } };
static const float radB2[2] = { 0.7f, 0.7f };

/* Pause/demo flag set: the routine must leave everything untouched. */
static const float segA_p[1][3] = { { 0.0f, 0.0f, 0.0f } };
static const float seg2A_p[1][3] = { { 2.0f, 0.0f, 0.0f } };
static const float radA_p[1] = { 1.0f };
static const float segB_p[1][3] = { { 0.5f, 0.0f, 0.0f } };
static const float seg2B_p[1][3] = { { 0.5f, 3.0f, 0.0f } };
static const float radB_p[1] = { 1.0f };

static int run_case(const struct fixture *fx)
{
    printf("== %s\n", fx->label);

    uint32_t regs[16];
    for (int i = 0; i < 16; ++i) regs[i] = 0x22220000u + (uint32_t)i * 0x2222u;
    const float frseed[4] = { 7.0f, 8.0f, 9.0f, 10.0f };   /* fr12..fr15 */
    const uint32_t pr = 0x0C0BCDE2u;
    const uint32_t sr = 0x60000001u;                        /* T set; cleared on the pause arm */

    /* ---- guest side ---- */
    seed(fx->pause_flags, fx->count, fx->segA, fx->seg2A, fx->radA,
         fx->segB, fx->seg2B, fx->radB, 3u, 5u);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, regs, pr, frseed, sr);
    const int ok_guest = vf3_hitbox_overlap_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *guest = (uint8_t *)malloc((OBJ_REGION_HI - OBJ_REGION_LO) +
                                       (FRAME_REGION_HI - FRAME_REGION_LO));
    memcpy(guest, at(OBJ_REGION_LO), OBJ_REGION_HI - OBJ_REGION_LO);
    memcpy(guest + (OBJ_REGION_HI - OBJ_REGION_LO), at(FRAME_REGION_LO),
           FRAME_REGION_HI - FRAME_REGION_LO);

    /* ---- native side ---- */
    seed(fx->pause_flags, fx->count, fx->segA, fx->seg2A, fx->radA,
         fx->segB, fx->seg2B, fx->radB, 3u, 5u);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram;                       /* flat RAM is little-endian float words */
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = regs[i];
    a.r[4] = OUT; a.r[5] = A; a.r[6] = B;
    a.r[15] = SP0;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00040001u;
    a.fr[12] = frseed[0]; a.fr[13] = frseed[1];
    a.fr[14] = frseed[2]; a.fr[15] = frseed[3];
    vf3_native_hitbox_overlap(&a, SP0, OUT, A, B);

    int bad = 0;

    /* ---- object region: min distance, pair count, radius arrays, hit words ---- */
    {
        int nb = 0;
        /* floats (radius arrays) at float tolerance, non-finite exact */
        for (uint32_t ad = A + RADIUS_OFF; ad < A + RADIUS_OFF + 4u * COUNT_CAPS; ad += 4) {
            float g, n;
            memcpy(&g, guest + (ad - OBJ_REGION_LO), 4);
            memcpy(&n, at(ad), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0 && nb < 10)
                    fprintf(stderr, "  radius(A) @%08x: got %08x want %08x\n",
                            ad, vf3_aim_ubits(n), vf3_aim_ubits(g));
                if (memcmp(&g, &n, 4) != 0) nb++;
                continue;
            }
            if (fabsf(g - n) > 1.0e-6f && memcmp(&g, &n, 4) != 0) {
                if (nb < 10)
                    fprintf(stderr, "  radius(A) @%08x: got %.7g want %.7g\n", ad, n, g);
                nb++;
            }
        }
        for (uint32_t ad = B + RADIUS_OFF; ad < B + RADIUS_OFF + 4u * COUNT_CAPS; ad += 4) {
            float g, n;
            memcpy(&g, guest + (ad - OBJ_REGION_LO), 4);
            memcpy(&n, at(ad), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0 && nb < 10)
                    fprintf(stderr, "  radius(B) @%08x: got %08x want %08x\n",
                            ad, vf3_aim_ubits(n), vf3_aim_ubits(g));
                if (memcmp(&g, &n, 4) != 0) nb++;
                continue;
            }
            if (fabsf(g - n) > 1.0e-6f && memcmp(&g, &n, 4) != 0) {
                if (nb < 10)
                    fprintf(stderr, "  radius(B) @%08x: got %.7g want %.7g\n", ad, n, g);
                nb++;
            }
        }
        /* hit words: exact bit masks */
        for (uint32_t ad = A + HITWORD_OFF; ad < A + HITWORD_OFF + 4u * COUNT_CAPS; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (ad - OBJ_REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 12)
                    fprintf(stderr, "  hitword(A) @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        for (uint32_t ad = B + HITWORD_OFF; ad < B + HITWORD_OFF + 4u * COUNT_CAPS; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (ad - OBJ_REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 12)
                    fprintf(stderr, "  hitword(B) @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        /* out block: min distance float + pair count byte */
        {
            float g, n;
            memcpy(&g, guest + (OUT + 48 - OBJ_REGION_LO), 4);
            n = vf3_aim_fbits(vf3_aim_u32(&a, OUT + 48));
            if (memcmp(&g, &n, 4) != 0 && fabsf(g - n) > 1.0e-6f) {
                fprintf(stderr, "  out+48: got %.7g want %.7g\n", n, g);
                nb++;
            }
            uint8_t gc = guest[(OUT + 52 - OBJ_REGION_LO)];
            uint8_t nc = vf3_aim_u8(&a, OUT + 52);
            if (gc != nc) { fprintf(stderr, "  out+52: got %u want %u\n", nc, gc); nb++; }
        }
        printf("  objects: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* ---- saved stack + caller frame: exact ---- */
    {
        int nb = 0;
        for (uint32_t ad = FRAME_REGION_LO; ad < FRAME_REGION_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, guest + (OBJ_REGION_HI - OBJ_REGION_LO) + (ad - FRAME_REGION_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10)
                    fprintf(stderr, "  frame @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  frame: %s\n", nb ? "DIFFERS" : "match");
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
        if (a.r[15] != gs.v[15]) {
            if (nb < 30) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gs.v[15]);
            nb++;
        }
        if (a.pr != gs.v[16]) {
            if (nb < 30) fprintf(stderr, "  pr: native %08x guest %08x\n", a.pr, gs.v[16]);
            nb++;
        }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) {
            fprintf(stderr, "  sr T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }
        for (int i = 12; i <= 15; ++i) {
            uint32_t gb, nb2;
            memcpy(&gb, &a.fr[i], 4);
            memcpy(&nb2, &gs.v[21 + i], 4);
            if (gb != nb2) {
                if (nb < 30) fprintf(stderr, "  fr%d: native %08x guest %08x\n", i, gb, nb2);
                nb++;
            }
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
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
        printf("hitbox_overlap_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct fixture all[] = {
        { "single direct hit", 0, 1, segA_hit, seg2A_hit, radA_hit, segB_hit, seg2B_hit, radB_hit },
        { "clear miss",        0, 1, segA_miss, seg2A_miss, radA_miss, segB_miss, seg2B_miss, radB_miss },
        { "two pairs overlap", 0, 2, segA2, seg2A2, radA2, segB2, seg2B2, radB2 },
        { "pause/demo flag",   0x00080001u, 1, segA_p, seg2A_p, radA_p, segB_p, seg2B_p, radB_p },
    };

    int bad = 0;
    for (size_t i = 0; i < sizeof all / sizeof all[0]; ++i)
        bad |= run_case(&all[i]);

    free(ram);
    printf("hitbox_overlap_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
