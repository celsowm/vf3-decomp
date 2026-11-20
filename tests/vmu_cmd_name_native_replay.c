/* Differential replay of the native save-operation name selector
 * (src/native/vmu_cmd_name.c, 0x8C0374B0) against the readable guest port
 * (src/fight/readable/vmu_cmd_name.c, `vf3_vmu_cmd_name_entry`).
 *
 * Both sides run on the same flat RAM.  The body is a self-contained leaf: no
 * calls, no FPU, no stack.  It reads the command id in r4, matches it against
 * the seven known ids, reads the matching pool word's string address and
 * answers in r0; an unknown id takes the fallback.  The T bit it leaves is
 * the last compare's (set on a match, clear on the fallback).
 *
 * The whole pool window is compared byte for byte, together with r0 (the
 * answer) and SR's T bit.  The outcome is also checked against an independent
 * model of the guest (the same key/pool mapping), so a fixture that is not
 * where the guest looks cannot make both sides agree on the wrong bytes. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "vmu_cmd_name.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vmu_cmd_name_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c037000u
#define RAM_SIZE 0x1000u

#define POOL_BASE 0x0c037000u
#define POOL_LEN  0x1000u
#define POOL_HI   (POOL_BASE + POOL_LEN)

/* the pool words, one per command id, at the game's own offsets */
#define P_OFF_0  0x54cu   /* "NOP"              */
#define P_OFF_1  0x550u   /* "CONNECTED"        */
#define P_OFF_2  0x554u   /* "DISCONNECTED"     */
#define P_OFF_3  0x558u   /* "FORMAT DISK"      */
#define P_OFF_7  0x55cu   /* "DELETE FILE"      */
#define P_OFF_B  0x560u   /* "LOAD FILE"        */
#define P_OFF_C  0x564u   /* "SAVE FILE"        */
#define P_OFF_DF 0x568u   /* "UNKNOWN OPERATION" */

#define STR_NOP     0x0c0ccd14u
#define STR_CONN    0x0c0ccd1cu
#define STR_DISC    0x0c0ccd28u
#define STR_FORMAT  0x0c0ccd38u
#define STR_DELETE  0x0c0ccd44u
#define STR_LOAD    0x0c0ccd50u
#define STR_SAVE    0x0c0ccd5cu
#define STR_UNKNOWN 0x0c0ccd68u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

static void seed_all(void)
{
    memset(ram, 0x11, RAM_SIZE);
    w32(POOL_BASE + P_OFF_0,  STR_NOP);
    w32(POOL_BASE + P_OFF_1,  STR_CONN);
    w32(POOL_BASE + P_OFF_2,  STR_DISC);
    w32(POOL_BASE + P_OFF_3,  STR_FORMAT);
    w32(POOL_BASE + P_OFF_7,  STR_DELETE);
    w32(POOL_BASE + P_OFF_B,  STR_LOAD);
    w32(POOL_BASE + P_OFF_C,  STR_SAVE);
    w32(POOL_BASE + P_OFF_DF, STR_UNKNOWN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t cmd)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = cmd;
    s->v[16] = 0x0cabcdeu;              /* pr */
    s->v[17] = 0x60000001u;             /* sr */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    win[0].base = POOL_BASE;
    win[0].len = POOL_LEN;
    win[0].data = ab(POOL_BASE);
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

/* the independent model of the guest */
static uint32_t model(uint32_t cmd, int *t)
{
    static const uint32_t keys[7] = { 0u, 1u, 2u, 3u, 7u, 0xbu, 0xcu };
    static const uint32_t offs[7] = { P_OFF_0, P_OFF_1, P_OFF_2, P_OFF_3,
                                      P_OFF_7, P_OFF_B, P_OFF_C };
    uint32_t off = P_OFF_DF;            /* the fallback */
    *t = 0;
    for (unsigned i = 0; i < 7; ++i) {
        *t = (cmd == keys[i]);
        if (*t) { off = offs[i]; break; }
    }
    return r32(POOL_BASE + off);
}

static int compare_one(const char *name, uint32_t cmd)
{
    printf("== %s (cmd %u)\n", name, cmd);

    int want_t;
    seed_all();
    const uint32_t want_r0 = model(cmd, &want_t);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, cmd);
    const int ok_guest = vf3_vmu_cmd_name_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], g_sr = gs.v[17];

    /* snapshot the guest's RAM over the pool before the native re-seeds */
    uint8_t *gshot = (uint8_t *)malloc(POOL_LEN);
    memcpy(gshot, ab(POOL_BASE), POOL_LEN);

    /* ---- native side ---- */
    seed_all();
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = cmd;
    a.pr = 0x0cabcdeu;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_vmu_cmd_name(&a, 0x0c47f000u);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    {
        int nb = 0;
        for (uint32_t ad = POOL_BASE; ad < POOL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - POOL_BASE), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", POOL_BASE, POOL_HI, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* r0 + T bit */
    {
        int nb = 0;
        if (a.r[0] != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the outcome against the independent model */
    {
        int nb = 0;
        if (a.r[0] != want_r0) {
            fprintf(stderr, "  r0: native %08x expected %08x\n", a.r[0], want_r0); nb++;
        }
        if ((a.sr & 1u) != (unsigned)want_t) {
            fprintf(stderr, "  T: native %u expected %d\n", a.sr & 1u, want_t); nb++;
        }
        printf("  outcome: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    int bad = 0;
    bad |= compare_one("NOP", 0u);
    bad |= compare_one("CONNECTED", 1u);
    bad |= compare_one("DISCONNECTED", 2u);
    bad |= compare_one("FORMAT DISK", 3u);
    bad |= compare_one("DELETE FILE", 7u);
    bad |= compare_one("LOAD FILE", 0xbu);
    bad |= compare_one("SAVE FILE", 0xcu);
    bad |= compare_one("five", 5u);
    bad |= compare_one("all bits", 0xffffffffu);
    bad |= compare_one("large id", 0x1000u);

    free(ram);
    printf("vmu_cmd_name_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
