/* Differential replay of the native extent-list leaf
 * (src/native/extent_list.c, 0x8C0CC432) against the readable guest port
 * (src/fight/extent_list.c, `vf3_extent_list_entry`).
 *
 * Both sides seed the same flat RAM (an object with its 32-byte extent
 * records and the three halfword tables), the same FR bank and the same
 * register file, then run the leaf.  The leaf's two callees - frame_counter_step
 * (0x8C0CC334) and extent_flip (0x8C0CC3F0) - are exercised natively through
 * `vf3_native_frame_counter_step` / `vf3_native_extent_flip`; on the guest side
 * they run as readable ports through `vf3_readable_override`.
 *
 * After the run the whole register file (r0..r15, pr, sr) and the whole FR
 * bank are compared with the guest, and the object / record / table RAM region
 * is compared byte for byte. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "extent_list.h"
#include "frame_counter_step.h"
#include "extent_flip.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_extent_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define OBJ  0x0C1A6000u   /* r4 */
#define SP0  0x0C1A8000u   /* r15 */
#define REC0 (OBJ + 0x200u)   /* object + 0x200, records are 32 bytes */
#define TAB_A 0x0C1A6400u
#define TAB_B 0x0C1A6500u
#define TAB_C 0x0C1A6600u
#define RETURN_PC 0x0c0cc432u
#define FPSCR     0x00040001u   /* single-PR, toward-zero + FTZ */

/* obj has count records; each record is 32 bytes.  Fields the callees read:
 *   +0x1A  halfword flags (bit 0 = live, bits 1/2 pick the table)
 *   +0x1E  halfword counter (frame_counter_step)
 *   +0x1C  word table value (written by frame_counter_step)
 *   +0x10  float (advanced by frame_counter_step)
 *   +0x0C  float (moved when fr4 != 0)
 *   +0x14  float (moved when fr4 != 0)
 *   +0x00..+0x14  the six floats of extent_flip (a0 a1 a2 b0 b1 b2) */
struct scenario {
    const char *name;
    unsigned count;
    /* per-record: flags (halfword at +0x1A), counter (halfword at +0x1E),
       and the six extent_flip floats a0 a1 a2 b0 b1 b2 */
    struct {
        uint16_t flags;
        uint16_t counter;
        float a[6];
    } rec[4];
    /* object's FR-source floats */
    float f_10, f_38, f_3c;
};

static void w32(uint8_t *ab, uint32_t w)
{
    ab[0] = (uint8_t)w; ab[1] = (uint8_t)(w >> 8);
    ab[2] = (uint8_t)(w >> 16); ab[3] = (uint8_t)(w >> 24);
}
static void wf32(uint8_t *ab, float f) { w32(ab, vf3_f32_bits(f)); }

static void seed_ram(uint8_t *ram, const struct scenario *sc)
{
    memset(ram, 0x5A, RAM_SIZE);
    uint8_t *obj = ram + (OBJ - RAM_BASE);
    wf32(obj + 0x10, sc->f_10);
    wf32(obj + 0x38, sc->f_38);
    wf32(obj + 0x3C, sc->f_3c);
    w32(obj + 0x34, sc->count);
    w32(obj + 0x1C, TAB_A);
    w32(obj + 0x24, TAB_B);
    w32(obj + 0x28, TAB_C);
    for (unsigned i = 0; i < sc->count; ++i) {
        uint8_t *r = ram + (REC0 + 32u * i - RAM_BASE);
        const uint16_t lo = sc->rec[i].flags, hi = sc->rec[i].counter;
        r[0x1A] = (uint8_t)lo; r[0x1B] = (uint8_t)(lo >> 8);
        r[0x1E] = (uint8_t)hi; r[0x1F] = (uint8_t)(hi >> 8);
        for (int k = 0; k < 6; ++k) wf32(r + 4u * (uint32_t)k, sc->rec[i].a[k]);
    }
    /* the three halfword tables */
    for (unsigned t = 0; t < 3; ++t) {
        uint8_t *tb = ram + ((t == 0 ? TAB_A : t == 1 ? TAB_B : TAB_C) - RAM_BASE);
        for (int k = 0; k < 64; ++k) {   /* 32 halfwords */
            uint16_t v = (uint16_t)(0x100 + 32u * t + 2u * (unsigned)k);
            tb[2 * k] = (uint8_t)v; tb[2 * k + 1] = (uint8_t)(v >> 8);
        }
    }
    /* the stack frame region a known pattern (it is overwritten, but the dead
       words the callees leave must be comparable) */
    for (int k = 0; k < 64; ++k) w32(ram + (SP0 - 64u - RAM_BASE) + 4u * (uint32_t)k, 0x11111111u + (uint32_t)k);
}

static int compare_one(const struct scenario *sc, int idx)
{
    printf("== %s\n", sc->name);

    uint8_t *g_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *n_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }

    /* ----- guest side ----- */
    seed_ram(g_ram, sc);
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
    gs.v[25] = vf3_f32_bits(sc->f_10);   /* FR4 = v[21+4] : obj+0x10, from the entry read */
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = g_ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_extent_list_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  case %d: guest failed (ok=%d oob=%u)\n", idx, ok, gmap.oob);
        free(g_ram); free(n_ram); return 1;
    }

    /* ----- native side ----- */
    seed_ram(n_ram, sc);
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
    x.fr[4] = sc->f_10;
    vf3_native_extent_list(&x);

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

    /* RAM compare: the object, the records, the tables and the stack frame */
    const unsigned ram_start = OBJ - RAM_BASE;
    const unsigned ram_end = (TAB_C + 128u) - RAM_BASE;
    for (unsigned a = ram_start; a < ram_end; ++a)
        if (n_ram[a] != g_ram[a]) {
            fprintf(stderr, "  mem @+0x%04x native %02x guest %02x\n", a, n_ram[a], g_ram[a]); bad++;
            break;
        }
    for (unsigned a = (SP0 - 64u) - RAM_BASE; a < (SP0 + 64u) - RAM_BASE; ++a)
        if (n_ram[a] != g_ram[a]) {
            fprintf(stderr, "  frame @+0x%04x native %02x guest %02x\n", a, n_ram[a], g_ram[a]); bad++;
            break;
        }

    free(g_ram); free(n_ram);
    printf("  extent_list: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    int bad = 0;
    struct scenario scs[] = {
        { "two live, table via bits", 2,
          { { 1, 10, { 1,2,3, 4,5,6 } }, { 3, 20, { 7,8,9, 10,11,12 } } },
          0.5f, 2.0f, 3.0f },
        { "one live + one dead", 2,
          { { 0, 5, { 0,0,0, 0,0,0 } }, { 1, 30, { 1,1,1, 2,2,2 } } },
          1.0f, 0.5f, 0.25f },
        { "bit2 picks stack table", 2,
          { { 5, 12, { 1,2,3, 4,5,6 } }, { 1, 8, { 9,8,7, 6,5,4 } } },
          0.0f, 1.0f, 1.0f },
        { "negative counter clears live", 1,
          { { 1, 0xFFFF, { 1,2,3, 4,5,6 } } },
          2.0f, 3.0f, 4.0f },
        { "three records", 3,
          { { 1, 4, { 1,2,3, 4,5,6 } }, { 1, 16, { 2,3,4, 5,6,7 } }, { 1, 22, { 3,4,5, 6,7,8 } } },
          1.0f, 1.0f, 1.0f },
        { "empty", 0, { { 0,0,{0,0,0,0,0,0} } }, 1.0f, 2.0f, 3.0f },
        { "bit1 skip-floor in extent_flip", 1,
          { { 3, 7, { 1,2,3, 4,5,6 } } },
          0.0f, 1.0f, 1.0f },
        { "fr4 zero (fr4 speed path off)", 1,
          { { 1, 6, { 1,2,3, 4,5,6 } } },
          0.0f, 0.0f, 0.0f },
    };
    for (unsigned i = 0; i < sizeof scs / sizeof scs[0]; ++i)
        bad |= compare_one(&scs[i], (int)i);
    printf("extent_list_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
