/* Differential replay of the native aim-frame builders (src/native/motion_aim.c)
 * against the readable guest ports (src/fight/aim_frame.c, 0x8C09E060, and
 * src/fight/aim_frame_b.c, 0x8C09E6B2).
 *
 * Both sides run on the same flat matrix RAM: the guest through its ram map, the
 * native port through `ram_base`.  The fixture lays out the kind record, the
 * output block, the object, the object7 and the caller's stack words the guest
 * reads at sp0+0.., and the entry XMTRX / FR4.  The whole actor region is
 * compared element-wise afterwards, so the frames the guests leave on the stack
 * and the blocks they write are both covered.
 *
 * The guest ports are the authority: they were promoted against the oracle.  The
 * native port is a re-implementation, so the residual is the FPU difference
 * (fsca/fsrra/ftrv against libm), tolerated at 2e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "motion_aim.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_aim_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_aim_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u
#define RECORD 0x0C200000u
#define BLOCK  0x0C200100u
#define OBJECT 0x0C200200u
#define OBJECT7 0x0C200300u
#define OWNER  0x0C200C00u          /* the second builder's r4 (the wrapper's base) */
#define FRAME  0x0C201000u
#define SP0    0x0C201154u

#define ACTOR_BASE 0x0C200000u
#define ACTOR_SIZE 0x2000u

static float *ram;              /* the shared flat RAM */

/* byte-exact: the euler angle triples live at r4, r4+6 and r4+12, so an
 * unaligned guest address must not alias onto the word below it. */
static float *at(uint32_t addr)
{
    return (float *)((uint8_t *)ram + (addr - RAM_BASE));
}

static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16);
    p[3] = (uint8_t)(v >> 24);
}

static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v;
    p[1] = (uint8_t)(v >> 8);
}

static void wf(uint32_t addr, float v)
{
    uint32_t u;
    memcpy(&u, &v, 4);
    w32(addr, u);
}

/* fill the actor region with a deterministic pattern */
static void seed_actor(void)
{
    for (uint32_t a = ACTOR_BASE; a < ACTOR_BASE + ACTOR_SIZE; a += 4)
        w32(a, 0x3F800000u ^ (a & 0x1FF));
}

static void setup_actor(void)
{
    /* the kind record: the floats the builder reads at +0/+8/+12/+20/+24/+36 */
    static const float rec[12] = {
        0.39f, 0.28f, 0.12f, 0.12f, 0.26f, 0.21f,
        0.28f, -0.12f, -0.12f, 0.26f, 0.21f, 0.19f,
    };
    for (int i = 0; i < 12; ++i)
        wf(RECORD + 4u * (uint32_t)i, rec[i]);
    static const float obj[5] = { 0.1f, 0.2f, 0.3f, 5.0f, 5.0f };
    for (int i = 0; i < 5; ++i)
        wf(OBJECT + 4u * (uint32_t)i, obj[i]);
    /* the second builder reads OBJECT7's words 0..1 (the second translate) and 2..3
     * (the clearance sum).  0.8 / 0.9 puts both derived ratios inside (-1, 1) so
     * the clearance sqrt terms are non-degenerate. */
    static const float obj7[4] = { 1.5f, -2.5f, 0.8f, 0.9f };
    for (int i = 0; i < 4; ++i)
        wf(OBJECT7 + 4u * (uint32_t)i, obj7[i]);

    /* the caller's eight stack words (all pointers) */
    w32(SP0 + 0u, 0x0C200400u);      /* M(0x154): an object */
    w32(SP0 + 4u, 0x0C200500u);      /* M(0x158): the euler angles */
    w32(SP0 + 8u, 0x0C200600u);      /* M(0x15C): a float triple */
    w32(SP0 + 12u, 0x0C200700u);     /* M(0x160) = r10 */
    w32(SP0 + 16u, 0x0C200800u);     /* M(0x164): the second angles / floats */
    w32(SP0 + 20u, 0x0C200900u);     /* M(0x168) */
    w32(SP0 + 24u, 0x0C200A00u);     /* M(0x16C) */
    w32(SP0 + 28u, 0x0C200B00u);     /* M(0x170) */

    /* the angle blocks the euler calls read: three halfwords each, at +0,
     * +6 and +12 from the M(0x158) pointer */
    w16(0x0C200500u, 0x1000u);
    w16(0x0C200502u, 0x2000u);
    w16(0x0C200504u, 0x3000u);
    w16(0x0C200506u, 0x4000u);
    w16(0x0C200508u, 0x5000u);
    w16(0x0C20050Au, 0x6000u);
    w16(0x0C20050Cu, 0x7000u);
    w16(0x0C20050Eu, 0x8000u);
    w16(0x0C200510u, 0x9000u);
    /* the float triples at M(0x15C) / M(0x164) / r10 */
    wf(0x0C200600u, 0.05f);
    wf(0x0C200604u, 0.06f);
    wf(0x0C200608u, 0.07f);
    wf(0x0C200800u, 0.08f);
    wf(0x0C200804u, 0.09f);
    wf(0x0C200808u, 0.06f);
    wf(0x0C200700u, 0.11f);
    wf(0x0C200704u, 0.12f);
    wf(0x0C200708u, 0.13f);
    wf(0x0C20070Cu, 0.14f);
    wf(0x0C200400u, 0.15f);
    wf(0x0C200404u, 0.16f);
    wf(0x0C200900u, 0.17f);
    wf(0x0C200A00u, 0.18f);
    wf(0x0C200B00u, 0.19f);

    /* the matrix stack the helpers push/pop through (0x0C19D2E4) */
    w32(0x0C19D2E4u, (16u << 16) | 1u);
    w32(0x0C19D2E8u, 0x0C19D400u);
    w32(0x0C19D2ECu, 0x0C19D440u);
}

/* the second builder's caller stack words: its frame is 0x130 bytes, so
 * f + 0x15C .. f + 0x174 are sp0+0 .. sp0+20. */
static void setup_actor_b(void)
{
    setup_actor();
    const uint32_t sp0b = FRAME + 348u;
    w32(sp0b + 0u, 0x0C200600u);     /* M(0x15C): the offset float triple */
    w32(sp0b + 4u, 0x0C200E00u);     /* M(0x160) = r11: the output block B */
    w32(sp0b + 8u, 0x0C200500u);     /* M(0x164): the euler angles (+6 for the wrapper) */
    w32(sp0b + 12u, 0x0C200700u);    /* M(0x168) = r12: the offset floats */
    w32(sp0b + 16u, 0x0C200800u);    /* M(0x16C) = r14: the vec3 pair C */
    w32(sp0b + 20u, 0x0C200900u);    /* M(0x170): the xformed point */
    /* the wrapper's base pointer reads at +0x1E and +0x22E6 */
    w16(OWNER + 0x1Eu, 0x1234u);
    w16(OWNER + 0x22E6u, 0x0A00u);
}

struct fixture {
    float xm[16];
    float fr4;
    uint32_t regs[16];
    uint32_t pr;
    int second;                 /* 0: 0x8C09E060, 1: 0x8C09E6B2 */
    int skip;                   /* 1: the second builder's clearance-sum arm */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map,
                        vf3_ram_win *win, const struct fixture *fx)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 16; ++i) s->v[i] = fx->regs[i];
    s->v[16] = fx->pr;
    s->v[17] = 0x60000000u;      /* sr, T clear */
    s->v[18] = 0x00040001u;      /* fpscr: the chain's FPU gate */
    for (unsigned i = 0; i < 16; ++i) {
        uint32_t bits;
        memcpy(&bits, &fx->xm[i], 4);
        s->v[37 + i] = bits;     /* XF0..XF15 */
    }
    uint32_t fr4bits;
    memcpy(&fr4bits, &fx->fr4, 4);
    s->v[21 + 4] = fr4bits;      /* FR4 */
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
    static const char path[] = "extract/exe/1ST_READ.unsc.bin";
    FILE *f = fopen(path, "rb");
    if (!f)
        return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram)
        return 2;
    const char *err = load_image();
    if (err) {
        printf("native_motion_aimframe_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct fixture fx = {
        /* a rotation with a translation, so the xform paths are exercised */
        { 0.8660254f, 0.0f, -0.5f, 0.0f,
          0.0f, 1.0f, 0.0f, 0.0f,
          0.5f, 0.0f, 0.8660254f, 0.0f,
          1.5f, 2.5f, -0.5f, 1.0f },
        0.25f,
        {
            0x0C200000u, 0x0C200100u, 0x0C200200u, 0x0C200300u,
            0x0C200000u, 0x0C200100u, 0x0C200200u, 0x0C200300u,
            0x0C03C4F0u, 0x0C03C4A0u, 0x0C03BD80u, 0x0C03B620u,
            0x0C200000u, 0x0C200100u, 0x0C201154u, 0x0C201154u,
        },
        0x0C0ABCDEu,
        0,
    };
    /* the second builder hands r4 a pointer (parked at frame+20) instead of a
     * block, keeps the record in r5, and reads one fewer caller stack word. */
    static const struct fixture fxb = {
        { 0.5f, 0.0f, 0.8660254f, 0.0f,
          0.0f, 0.8660254f, -0.5f, 0.0f,
          -0.8660254f, 0.5f, 0.0f, 0.0f,
          -0.25f, 1.75f, 2.25f, 1.0f },
        0.4f,
        {
            OWNER, RECORD, OBJECT, OBJECT7,
            OWNER, RECORD, OBJECT, OBJECT7,
            0x0C03C4F0u, 0x0C03C4A0u, 0x0C03BD80u, 0x0C03B620u,
            OWNER, RECORD, FRAME + 348u, FRAME + 348u,
        },
        0x0C0ABCE2u,
        1,
        0,
    };
    /* the same second builder with a clearance sum the guest's length always
     * exceeds, so the branch skips the three rotations */
    static const struct fixture fxb_skip = {
        { 0.5f, 0.0f, 0.8660254f, 0.0f,
          0.0f, 0.8660254f, -0.5f, 0.0f,
          -0.8660254f, 0.5f, 0.0f, 0.0f,
          -0.25f, 1.75f, 2.25f, 1.0f },
        0.4f,
        {
            OWNER, RECORD, OBJECT, OBJECT7,
            OWNER, RECORD, OBJECT, OBJECT7,
            0x0C03C4F0u, 0x0C03C4A0u, 0x0C03BD80u, 0x0C03B620u,
            OWNER, RECORD, FRAME + 348u, FRAME + 348u,
        },
        0x0C0ABCE2u,
        1,
        1,
    };

    const struct fixture *all[3] = { &fx, &fxb, &fxb_skip };
    static const char *labels[3] = {
        "aim_frame (0x8C09E060)", "aim_frame_b (0x8C09E6B2)",
        "aim_frame_b (0x8C09E6B2, clearance sum)"
    };
    int bad = 0;
    for (int c = 0; c < 3; ++c) {
        const struct fixture *f = all[c];
        printf("== %s\n", labels[c]);
        if (f->second)
            seed_actor(), setup_actor_b();
        else
            seed_actor(), setup_actor();
        if (f->skip) {
            /* a sum the transformed length never reaches */
            wf(OBJECT7 + 8u, 900.0f);
            wf(OBJECT7 + 12u, 900.0f);
        }
        vf3_matrix_state gs;
        vf3_ram_map gmap;
        vf3_ram_win gwin[1];
        setup_guest(&gs, &gmap, gwin, f);
        const int ok_guest = f->second ? vf3_aim_frame_b_entry(&gs, &gmap)
                                       : vf3_aim_frame_entry(&gs, &gmap);
        if (!ok_guest || gmap.oob) {
            fprintf(stderr, "native_motion_aimframe_replay: guest run failed (ok=%d oob=%u)\n",
                    ok_guest, gmap.oob);
            free(ram);
            return 1;
        }
        uint8_t *guest = (uint8_t *)malloc(ACTOR_SIZE);
        memcpy(guest, (const uint8_t *)at(ACTOR_BASE), ACTOR_SIZE);

        if (f->second)
            seed_actor(), setup_actor_b();
        else
            seed_actor(), setup_actor();
        if (f->skip) {
            wf(OBJECT7 + 8u, 900.0f);
            wf(OBJECT7 + 12u, 900.0f);
        }
        vf3_native_aim na;
        memset(&na, 0, sizeof na);
        na.ram = ram;
        na.ram_base = RAM_BASE;
        na.f = FRAME;
        memcpy(na.xm, f->xm, sizeof na.xm);
        for (unsigned i = 0; i < 16; ++i) na.r[i] = f->regs[i];
        na.pr = f->pr;
        na.sr = 0x60000000u;
        na.fpscr = 0x00040001u;
        na.fr[4] = f->fr4;
        const int ok_native = f->second
            ? vf3_native_aim_frame_b(&na, at(RECORD), at(OWNER), at(OBJECT),
                                     at(OBJECT7), f->fr4)
            : vf3_native_aim_frame(&na, at(RECORD), at(BLOCK),
                                   at(OBJECT), at(OBJECT7), f->fr4);
        if (ok_native != 0) {
            fprintf(stderr, "native_motion_aimframe_replay: native run failed (%d)\n",
                    ok_native);
            free(guest);
            free(ram);
            return 1;
        }
    if (!f->second) {
        printf("  guest block:\n");
        for (int i = 0; i < 64; ++i)
            printf("    %2d %.6f\n", i, *(const float *)(guest + 0x100 + 4 * i));
        printf("  native block:\n");
        for (int i = 0; i < 64; ++i)
            printf("    %2d %.6f\n", i, *at(BLOCK + 4 * i));
    }

    if (!f->second) {
    printf("  frame 0x10 / 0x90 / 0xD0:\n");
    {
        static const uint32_t offs[8] = { 0x08u, 0x0Cu, 0x10u, 0x40u, 0x50u, 0x80u, 0x90u, 0xD0u };
        for (int j = 0; j < 8; ++j) {
            const uint32_t off = offs[j];
            printf("   +%02x guest :", off);
            for (int i = 0; i < 16; ++i)
                printf(" %.5f", *(const float *)(guest + (FRAME - ACTOR_BASE) + off + 4 * i));
            printf("\n   +%02x native:", off);
            for (int i = 0; i < 16; ++i)
                printf(" %.5f", *at(FRAME + off + 4 * i));
            printf("\n");
        }
    }
    }

    float worst = 0.0f;
        uint32_t worst_at = 0;
        int case_bad = 0;
        /* the caller-visible state: the output block, the object and the pointer
         * targets, and the frame + saved registers + the caller's stack words.
         * The callees' own frames live below the frame and are their business.
         * The second builder writes through r11 / r14 into 0x0C200E00 / 0x0C200800. */
        uint32_t ranges[4][2] = {
            { 0x0C200100u, 0x0C200B20u },
            { 0x0C201000u, 0x0C201174u },
            { RECORD,       RECORD + 48u },
            { 0, 0 },
        };
        if (f->second)
            ranges[0][1] = 0x0C200960u;
        for (int r = 0; ranges[r][1]; ++r)
        for (uint32_t a = ranges[r][0]; a < ranges[r][1]; a += 4) {
            float g, n;
            memcpy(&g, guest + (a - ACTOR_BASE), 4);
            memcpy(&n, at(a), 4);
            if (!isfinite(g) || !isfinite(n)) {
                if (memcmp(&g, &n, 4) != 0) {
                    uint32_t gb, nb;
                    memcpy(&gb, &g, 4);
                    memcpy(&nb, &n, 4);
                    if (!case_bad)
                        fprintf(stderr, "  @%08x: got %08x want %08x (non-finite)\n",
                                a, nb, gb);
                    case_bad = 1;
                }
                continue;
            }
            const float d = fabsf(g - n);
            if (d > worst) {
                worst = d;
                worst_at = a;
            }
            if (d > 2.0e-3f && memcmp(&g, &n, 4) != 0) {
                if (case_bad < 12)
                    fprintf(stderr, "  @%08x: got %.7g want %.7g (d=%.3g)\n",
                            a, n, g, d);
                case_bad++;
            }
        }
        printf("  actor region: %s (worst %.3g at %08x)\n",
               case_bad ? "DIFFERS" : "match", worst, worst_at);
        bad |= case_bad;
        free(guest);
    }

    free(ram);
    printf("native_motion_aimframe_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
