/* Differential replay of the native record_run leaf
 * (src/native/record_run.c, 0x8C0C1296) against the readable guest port
 * (src/fight/misc_wrappers.c, `vf3_record_run_entry`).
 *
 * Both sides seed the same flat RAM (a record whose [r4+12] is the base of
 * 120 consecutive 68-byte records, some pre-set, plus a distinctive halfword
 * at [r4+34]) and the same register file, then run the leaf.  The leaf's sole
 * callee (mem_fill, 0x8C095604) is exercised natively through
 * `vf3_native_mem_fill`; on the guest side it runs as a readable port through
 * `vf3_readable_override` (the `CALL` in the readable body dispatches to it).
 *
 * After the run the whole register file (r0..r15, pr, sr), the FR bank and
 * FPUL are compared with the guest, and the record region + stack frame RAM
 * is compared byte for byte.  An independent fixture model checks that every
 * record is zeroed and that bit 0 of the [r4+34] halfword is set. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "record_run.h"
#include "mem_fill.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define OBJ  0x0C1A6000u   /* r4 */
#define REC0 0x0C1A4000u   /* the base of the 120 records, read from [r4+12] */
#define SP0  0x0C1A8000u   /* r15 */

#define N_REC  120u
#define REC_B  68u
#define REC_END (REC0 + N_REC * REC_B)

#define RETURN_PC 0x0c0c1296u
#define FPSCR     0x00040001u

static void w32(uint8_t *ab, uint32_t w)
{
    ab[0] = (uint8_t)w; ab[1] = (uint8_t)(w >> 8);
    ab[2] = (uint8_t)(w >> 16); ab[3] = (uint8_t)(w >> 24);
}

/* fill the 120-record region: every byte (over a per-case pattern) is set so
 * the zero-fill is observable, and the [r4+34] halfword is given a distinct
 * value. */
static void seed_ram(uint8_t *ram, uint32_t pat, uint16_t hw34)
{
    memset(ram, 0x5A, RAM_SIZE);
    for (uint32_t i = 0; i < N_REC * REC_B; ++i)
        ram[(REC0 - RAM_BASE) + i] = (uint8_t)(pat + i);
    /* [r4+12] -> the record base */
    w32(ram + (OBJ - RAM_BASE) + 12u, REC0);
    /* [r4+34] halfword, big enough to be distinct from the fill */
    uint8_t *p = ram + (OBJ - RAM_BASE) + 34u;
    p[0] = (uint8_t)hw34; p[1] = (uint8_t)(hw34 >> 8);
    /* the stack frame a known pattern (overwritten, but the dead words the
       callee leaves must be comparable) */
    for (int k = 0; k < 64; ++k) w32(ram + (SP0 - 64u - RAM_BASE) + 4u * (uint32_t)k, 0x11111111u + (uint32_t)k);
}

static int compare_one(const char *name, uint32_t pat, uint16_t hw34, int idx)
{
    printf("== %s (pat %08x hw34 %04x)\n", name, pat, hw34);

    uint8_t *g_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *n_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }

    /* ----- guest side ----- */
    seed_ram(g_ram, pat, hw34);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = OBJ;
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
    const int ok = vf3_record_run_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  case %d: guest failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
        free(g_ram); free(n_ram); return 1;
    }

    /* ----- native side ----- */
    seed_ram(n_ram, pat, hw34);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)n_ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i) x.fr[i] = vf3_aim_fbits(0x76543210u + 21u + i);
    x.r[4] = OBJ;
    x.r[15] = SP0;
    x.pr = RETURN_PC;
    x.sr = 0x60000000u;
    x.fpscr = FPSCR;
    vf3_native_record_run(&x);

    int bad = 0;
    for (unsigned i = 0; i < 16; ++i)
        if (x.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, x.r[i], gs.v[i]); bad++;
        }
    if (x.pr != gs.v[16]) fprintf(stderr, "  pr native %08x guest %08x\n", x.pr, gs.v[16]), bad++;
    if (x.sr != gs.v[17]) fprintf(stderr, "  sr native %08x guest %08x\n", x.sr, gs.v[17]), bad++;
    for (unsigned i = 0; i < 16; ++i)
        if (vf3_aim_ubits(x.fr[i]) != gs.v[21 + i]) {
            fprintf(stderr, "  fr%u native %08x guest %08x\n", i,
                    vf3_aim_ubits(x.fr[i]), gs.v[21 + i]); bad++;
        }
    if (x.fpul != gs.v[53]) fprintf(stderr, "  fpul native %08x guest %08x\n", x.fpul, gs.v[53]), bad++;

    /* RAM compare: the record region, the object, and the stack frame */
    const unsigned ram_lo = (REC0 - 64u) - RAM_BASE;
    const unsigned ram_hi = (REC_END + 64u) - RAM_BASE;
    for (unsigned a = ram_lo; a < ram_hi; ++a)
        if (n_ram[a] != g_ram[a]) {
            fprintf(stderr, "  mem @+0x%04x native %02x guest %02x\n", a, n_ram[a], g_ram[a]); bad++;
            break;
        }
    for (unsigned a = (SP0 - 64u) - RAM_BASE; a < (SP0 + 64u) - RAM_BASE; ++a)
        if (n_ram[a] != g_ram[a]) {
            fprintf(stderr, "  frame @+0x%04x native %02x guest %02x\n", a, n_ram[a], g_ram[a]); bad++;
            break;
        }

    /* independent fixture model: every record zeroed, bit 0 of [r4+34] set */
    for (uint32_t i = 0; i < N_REC * REC_B; ++i)
        if (n_ram[(REC0 - RAM_BASE) + i] != 0) {
            fprintf(stderr, "  model record not zeroed @+0x%04x\n", i); bad++;
            break;
        }
    const uint32_t want34 = (uint32_t)hw34 | 1u;
    const uint8_t *q = n_ram + (OBJ - RAM_BASE) + 34u;
    if ((q[0] | ((uint16_t)q[1] << 8)) != want34) {
        fprintf(stderr, "  model hw34 native %04x want %04x\n",
                (unsigned)(q[0] | ((uint16_t)q[1] << 8)), (unsigned)want34); bad++;
    }

    free(g_ram); free(n_ram);
    printf("  record_run: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    int bad = 0;
    static const struct { const char *name; uint32_t pat; uint16_t hw34; } cases[] = {
        { "hw34 even, plain fill", 0x10101010u, 0x0040u },
        { "hw34 bit0 set already", 0x22222222u, 0x0001u },
        { "hw34 high, odd fill",   0x33333333u, 0xFEDCu },
        { "hw34 zero, counting fill", 0x01020304u, 0x0000u },
        { "hw34 default, fill 0xff",  0xFFFFFFFFu, 0x0080u },
    };
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; ++i)
        bad |= compare_one(cases[i].name, cases[i].pat, cases[i].hw34, (int)i);
    printf("record_run_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
