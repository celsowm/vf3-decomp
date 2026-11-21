/* Differential replay of the native integer-conversion leaf
 * (src/native/format_int.c, 0x8C04AF04) against the readable guest port
 * (src/fight/format_int.c, `vf3_format_int_entry`).
 *
 * Both sides seed the same flat RAM (the conversion spec, the output buffer,
 * a dirty stack) and the same register file, then run the leaf.  The leaf
 * renders one integer into the engine's printf buffer: it fills the spec's
 * start / zero-pad / space-pad fields and writes the number's characters at
 * the output cursor.
 *
 * After the run the whole register file (r0..r15, pr, sr), the whole output
 * buffer, the whole spec, the digit scratch and the dead stack words are
 * compared byte for byte with the guest.  The digits themselves are also
 * checked against an independent decimal/hex/octal conversion. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "format_int.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_format_int_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define SPEC      0x0C1A6000u   /* r7 -> the conversion spec */
#define OUT       0x0C1A6200u   /* r5 = the output cursor */
#define SP0       0x0C1A6400u   /* r15: the leaf's stack pointer */
#define RETURN_PC 0x0c04afe0u
#define FPSCR     0x00040001u

/* spec fields (offsets inside the spec) */
#define S_FLAGS   0u
#define S_PAD     1u
#define S_WIDTH   4u
#define S_PREC    8u
#define S_START   20u
#define S_ZEROS   32u
#define S_SPACES  40u

#define F_ALT  0x04u
#define F_PLUS 0x08u
#define F_SPACE 0x10u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w8(uint32_t addr, uint8_t v) { ab(addr)[0] = v; }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

struct scenario {
    const char *name;
    int32_t value;         /* r4 */
    int conv;              /* r6 */
    uint8_t flags;         /* spec@0 */
    uint8_t pad;           /* spec@1 */
    uint32_t width;        /* spec@4 */
    uint32_t prec;         /* spec@8 */
    uint32_t r9;           /* fallback base (only for unknown conv) */
    const char *expect;    /* the number characters at OUT..OUT+len (no pads) */
};

static void seed_ram(const struct scenario *sc)
{
    memset(ram, 0x5A, RAM_SIZE);
    w8(SPEC + S_FLAGS, sc->flags);
    w8(SPEC + S_PAD, sc->pad);
    w32(SPEC + S_WIDTH, sc->width);
    w32(SPEC + S_PREC, sc->prec);
    w32(SPEC + S_START, 0x11111111u);
    w32(SPEC + S_ZEROS, 0x22222222u);
    w32(SPEC + S_SPACES, 0x33333333u);
}

static int compare_one(const struct scenario *sc, int idx)
{
    printf("== %s\n", sc->name);

    uint8_t *g_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *n_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }

    /* ----- guest side ----- */
    memcpy(g_ram, ram, RAM_SIZE);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = (uint32_t)sc->value;
    gs.v[5] = OUT;
    gs.v[6] = (uint32_t)(uint8_t)sc->conv;
    gs.v[7] = SPEC;
    gs.v[9] = sc->r9;   /* the unknown-conversion base */
    gs.v[15] = SP0;
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = FPSCR;
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = g_ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_format_int_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  case %d: guest failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
        free(g_ram); free(n_ram); return 1;
    }

    /* ----- native side ----- */
    memcpy(n_ram, ram, RAM_SIZE);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)n_ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = 0x76543210u + i;
    x.r[4] = (uint32_t)sc->value;
    x.r[5] = OUT;
    x.r[6] = (uint32_t)(uint8_t)sc->conv;
    x.r[7] = SPEC;
    x.r[9] = sc->r9;
    x.r[15] = SP0;
    x.pr = RETURN_PC;
    x.sr = 0x60000000u;
    x.fpscr = FPSCR;
    vf3_native_format_int(&x);

    int bad = 0;

    /* every general register, pr and sr */
    for (unsigned i = 0; i < 16; ++i)
        if (x.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, x.r[i], gs.v[i]); bad++;
        }
    if (x.pr != gs.v[16]) fprintf(stderr, "  pr native %08x guest %08x\n", x.pr, gs.v[16]), bad++;
    if (x.sr != gs.v[17]) fprintf(stderr, "  sr native %08x guest %08x\n", x.sr, gs.v[17]), bad++;

    /* the whole output buffer (OUT..OUT+48) */
    for (uint32_t i = 0; i < 48; ++i)
        if (n_ram[(OUT - RAM_BASE) + i] != g_ram[(OUT - RAM_BASE) + i]) {
            fprintf(stderr, "  out[%u] native %02x guest %02x\n", i,
                    n_ram[(OUT - RAM_BASE) + i], g_ram[(OUT - RAM_BASE) + i]); bad++;
        }

    /* the whole spec (SPEC..SPEC+44) */
    for (uint32_t i = 0; i < 44; ++i)
        if (n_ram[(SPEC - RAM_BASE) + i] != g_ram[(SPEC - RAM_BASE) + i]) {
            fprintf(stderr, "  spec[%u] native %02x guest %02x\n", i,
                    n_ram[(SPEC - RAM_BASE) + i], g_ram[(SPEC - RAM_BASE) + i]); bad++;
        }

    /* the digit scratch + dead stack words: frame-16 .. SP0+4 */
    const uint32_t lo = SP0 - 48u - 16u, hi = SP0 + 4u;
    for (uint32_t a = lo; a < hi; ++a)
        if (n_ram[(a - RAM_BASE)] != g_ram[(a - RAM_BASE)]) {
            fprintf(stderr, "  stack %08x native %02x guest %02x\n", a,
                    n_ram[(a - RAM_BASE)], g_ram[(a - RAM_BASE)]); bad++;
        }

    /* independent decimal/hex/octal check of the digits at OUT */
    if (sc->expect) {
        size_t len = strlen(sc->expect);
        if (memcmp(n_ram + (OUT - RAM_BASE), sc->expect, len) != 0) {
            fprintf(stderr, "  model out[%.*s] != expect [%s]\n", (int)len,
                    (char *)(n_ram + (OUT - RAM_BASE)), sc->expect); bad++;
        }
    }

    free(g_ram); free(n_ram);
    printf("  format_int: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    struct scenario scs[] = {
        { "positive decimal",      12345, 'd', 0, ' ', 0, 0, 0, "12345" },
        { "negative decimal",     -12345, 'd', 0, ' ', 0, 0, 0, "-12345" },
        { "zero no precision",          0, 'd', 0, ' ', 0, 0, 0, "" },
        { "zero with precision",        0, 'd', 0, '0', 0, 1, 0, "0" },
        { "unsigned max",    0x7FFFFFFFu, 'u', 0, ' ', 0, 0, 0, "2147483647" },
        { "decimal plus",        12345, 'd', F_PLUS, ' ', 0, 0, 0, "+12345" },
        { "decimal space",       12345, 'd', F_SPACE, ' ', 0, 0, 0, " 12345" },
        { "hex alt",               255, 'x', F_ALT, ' ', 0, 0, 0, "0xff" },
        { "hex X alt",             255, 'X', F_ALT, ' ', 0, 0, 0, "0XFF" },
        { "octal alt",              15, 'o', F_ALT, ' ', 0, 0, 0, "017" },
        { "zero pad with precision", 7, 'd', 0, '0', 0, 3, 0, "7" },
        { "width space pad",       42, 'd', 0, ' ', 6, 0, 0, "42" },
        { "unknown conv",          99, 'q', 0, ' ', 0, 0, 10, "99" },
        { "negative zero pad",    -42, 'd', 0, '0', 0, 5, 0, "-42" },
        { "negative space pad",   -42, 'd', 0, ' ', 6, 0, 0, "-42" },
        { "prec less than digits", 1024, 'd', 0, ' ', 0, 2, 0, "1024" },
    };
    for (unsigned i = 0; i < sizeof scs / sizeof scs[0]; ++i) {
        seed_ram(&scs[i]);
        bad |= compare_one(&scs[i], (int)i);
    }
    free(ram);
    printf("format_int_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
