/* Differential replay of the native division helpers
 * (src/native/div_helpers.c, 0x8C042C20 / 0x8C042CD4 / 0x8C042E44 /
 * 0x8C042D7C) against the readable guest ports
 * (src/fight/math_readable.c `vf3_div_s32_entry` etc.).
 *
 * Each helper does r1 / r0.  The test seeds r0/r1 plus the scratch registers
 * r2/r3/r4 and SR (with Q/M/T), runs both the readable guest and the native
 * port, and compares r0/r1, the whole SR (the DIV flags), the dead stack
 * words below r15, and the error word at 0x0C1A5A60.  For non-zero divisors
 * the quotient / remainder is also checked against plain C. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "div_helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_div_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mod_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mod_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u
#define SP0      0x0C011000u

/* error word lives at 0x0C1A5A60 */
#define RAM_ERR  0x0C1A5A60u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32a(const uint8_t *buf, uint32_t addr)
{
    const uint8_t *p = buf + (addr - RAM_BASE);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

typedef int (*ent_fn)(vf3_matrix_state *, const vf3_ram_map *);
typedef void (*nat_fn)(vf3_native_aim *);

static int compare_one(ent_fn guest, nat_fn native, uint32_t r0, uint32_t r1,
                       uint32_t sr, const char *nm, int idx)
{
    /* --- guest on g_ram --- */
    uint8_t *g_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *n_ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!g_ram || !n_ram) { free(g_ram); free(n_ram); return 1; }
    /* distinctive scratch values so the dead stack words are visible */
    for (uint32_t i = 0; i < 16; ++i) w32(SP0 - 4u * (i + 1), 0xA0 + i);

    memcpy(g_ram, ram, RAM_SIZE);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[0] = r0;
    gs.v[1] = r1;
    gs.v[2] = 0x22222222u;
    gs.v[3] = 0x33333333u;
    gs.v[4] = 0x44444444u;
    gs.v[15] = SP0;
    gs.v[16] = 0x0c042c40u;
    gs.v[17] = sr;
    gs.v[18] = 0x00024001u;
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = g_ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;
    const int ok = guest(&gs, &gmap);

    /* --- native on n_ram --- */
    memcpy(n_ram, ram, RAM_SIZE);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)n_ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = 0x76543210u + i;
    x.r[0] = r0;
    x.r[1] = r1;
    x.r[2] = 0x22222222u;
    x.r[3] = 0x33333333u;
    x.r[4] = 0x44444444u;
    x.r[15] = SP0;
    x.pr = 0x0c042c40u;
    x.sr = sr;
    x.fpscr = 0x00024001u;
    native(&x);

    int bad = 0;
    if (!ok || gmap.oob) { fprintf(stderr, "  case %d: guest failed (ok=%d oob=%u)\n", idx, ok, gmap.oob), bad++; }
    /* r0 / r1 */
    if (x.r[0] != gs.v[0]) fprintf(stderr, "  case %d: %s r0 native %08x guest %08x\n", idx, nm, x.r[0], gs.v[0]), bad++;
    if (x.r[1] != gs.v[1]) fprintf(stderr, "  case %d: %s r1 native %08x guest %08x\n", idx, nm, x.r[1], gs.v[1]), bad++;
    /* whole SR (DIV flags) */
    if (x.sr != gs.v[17]) fprintf(stderr, "  case %d: %s SR native %08x guest %08x\n", idx, nm, x.sr, gs.v[17]), bad++;
    /* the dead stack words below r15 (native and guest should match) */
    for (unsigned i = 0; i < 4; ++i) {
        uint32_t a = r32a(n_ram, SP0 - 4u * (i + 1));
        uint32_t b = r32a(g_ram, SP0 - 4u * (i + 1));
        if (a != b) fprintf(stderr, "  case %d: %s stack -%d native %08x guest %08x\n", idx, nm, (i + 1) * 4, a, b), bad++;
    }
    /* the error word */
    if (r32a(n_ram, RAM_ERR) != r32a(g_ram, RAM_ERR))
        fprintf(stderr, "  case %d: %s err native %08x guest %08x\n", idx, nm, r32a(n_ram, RAM_ERR), r32a(g_ram, RAM_ERR)), bad++;
    /* independent C check for non-zero divisor */
    if (r0 != 0) {
        if (native == vf3_native_div_s32) {
            int32_t e = (int32_t)r1 / (int32_t)r0;
            if ((int32_t)x.r[0] != e) fprintf(stderr, "  case %d: %s C div %08x want %08x\n", idx, nm, x.r[0], (uint32_t)e), bad++;
        } else if (native == vf3_native_div_u32) {
            if (x.r[0] != r1 / r0) fprintf(stderr, "  case %d: %s C div %08x want %08x\n", idx, nm, x.r[0], r1 / r0), bad++;
        } else if (native == vf3_native_mod_u32) {
            if (x.r[0] != r1 % r0) fprintf(stderr, "  case %d: %s C mod %08x want %08x\n", idx, nm, x.r[0], r1 % r0), bad++;
        } else if (native == vf3_native_mod_s32) {
            int32_t e = (int32_t)r1 % (int32_t)r0;
            if ((int32_t)x.r[0] != e) fprintf(stderr, "  case %d: %s C mod %08x want %08x\n", idx, nm, x.r[0], (uint32_t)e), bad++;
        }
    }

    free(g_ram); free(n_ram);
    return bad;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    const uint32_t S = 0x60000000u; /* T clear, Q=0 M=0 */

    /* div_s32 */
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 3u, 10u, S, "ds32", 1);
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 3u, 0xFFFFFFF6u, S, "ds32", 2);   /* -10 / 3 */
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 0xFFFFFFFDu, 10u, S, "ds32", 3); /* 10 / -3 */
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 0xFFFFFFFDu, 0xFFFFFFF6u, S, "ds32", 4);
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 0u, 5u, S, "ds32", 5);           /* /0 */
    bad += compare_one(vf3_div_s32_entry, vf3_native_div_s32, 1u, 0x80000000u, S, "ds32", 6);  /* INT_MIN */

    /* div_u32 */
    bad += compare_one(vf3_div_u32_entry, vf3_native_div_u32, 3u, 10u, S, "du32", 11);
    bad += compare_one(vf3_div_u32_entry, vf3_native_div_u32, 0xFFFFFFFDu, 10u, S, "du32", 12);
    bad += compare_one(vf3_div_u32_entry, vf3_native_div_u32, 0u, 5u, S, "du32", 13);
    bad += compare_one(vf3_div_u32_entry, vf3_native_div_u32, 0xFFFFu, 0xFFFFFFFFu, S, "du32", 14);

    /* mod_u32 */
    bad += compare_one(vf3_mod_u32_entry, vf3_native_mod_u32, 3u, 10u, S, "mu32", 21);
    bad += compare_one(vf3_mod_u32_entry, vf3_native_mod_u32, 7u, 100u, S, "mu32", 22);
    bad += compare_one(vf3_mod_u32_entry, vf3_native_mod_u32, 0u, 5u, S, "mu32", 23);
    bad += compare_one(vf3_mod_u32_entry, vf3_native_mod_u32, 5u, 0xFFFFFFFFu, S, "mu32", 24);

    /* mod_s32 */
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 3u, 10u, S, "ms32", 31);
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 3u, 0xFFFFFFF6u, S, "ms32", 32);  /* -10 % 3 */
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 0xFFFFFFFDu, 10u, S, "ms32", 33); /* 10 % -3 */
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 0xFFFFFFFDu, 0xFFFFFFF6u, S, "ms32", 34);
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 0u, 5u, S, "ms32", 35);
    bad += compare_one(vf3_mod_s32_entry, vf3_native_mod_s32, 7u, 0x80000000u, S, "ms32", 36);

    free(ram);
    printf("div_helpers_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
