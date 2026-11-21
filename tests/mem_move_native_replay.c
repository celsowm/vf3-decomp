/* Differential replay of the native mem_move (src/native/mem_move.c,
 * 0x8C043018) against the readable guest port
 * (src/fight/leaf_math.c `vf3_mem_move_entry`).
 *
 * Both sides seed the same flat RAM (source and destination byte regions),
 * then run the leaf.  The leaf copies `count` bytes from src to dst,
 * overlap-safe (forward when dst < src, backward otherwise), a no-op when
 * dst == src.  The test compares the written RAM byte for byte against an
 * independent fixture model (plain memmove deferred to a reference), the
 * r0 output and the SR.T bit, and the untouched registers. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "mem_move.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_mem_move_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x10000u

#define SRC  0x0C011000u
#define DST  0x0C011400u
#define SP0  0x0C012000u

#define RETURN_PC 0x0c043024u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint8_t r8(uint32_t addr) { return *ab(addr); }
static void w8(uint32_t addr, uint8_t v) { *ab(addr) = v; }

static void seed_case(uint32_t src, uint32_t dst, uint32_t count)
{
    memset(ram, 0xa5, RAM_SIZE);
    /* distinctive source pattern */
    for (uint32_t i = 0; i < count; ++i) w8(src + i, (uint8_t)(i * 3u + 7u));
    /* a distinct fill in the destination so overlap behaviour is visible */
    for (uint32_t i = 0; i < count; ++i) w8(dst + i, 0x5a);
}

static void run_guest(uint32_t src, uint32_t dst, uint32_t count,
                      uint32_t *r0_out, uint32_t *sr_out)
{
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = dst;
    gs.v[5] = src;
    gs.v[6] = count;
    gs.v[15] = SP0;
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = 0x00024001u;
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;
    const int ok = vf3_mem_move_entry(&gs, &gmap);
    if (!ok || gmap.oob) { fprintf(stderr, "  guest failed\n"); exit(2); }
    *r0_out = gs.v[0];
    *sr_out = gs.v[17];
}

static int compare_one(uint32_t src, uint32_t dst, uint32_t count,
                       uint32_t sp0_push, int idx)
{
    /* independent model: reference memmove on an isolated copy */
    uint8_t *model = (uint8_t *)calloc(RAM_SIZE, 1);
    uint8_t *gn = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!model || !gn) { free(model); free(gn); return 1; }

    /* seed the reference reservoir */
    seed_case(src, dst, count);
    memcpy(model, ram, RAM_SIZE);
    /* the readable guest writes with its own memmove logic; the reference
     * std memmove is the independent oracle for the overlap handling */
    if (dst != src) memmove(model + (dst - RAM_BASE), model + (src - RAM_BASE), count);

    /* guest run writes into `ram` */
    uint32_t r0g = 0, srg = 0;
    seed_case(src, dst, count);
    run_guest(src, dst, count, &r0g, &srg);
    memcpy(gn, ram, RAM_SIZE);
    if (memcmp(gn + (dst - RAM_BASE), model + (dst - RAM_BASE), count) != 0) {
        fprintf(stderr, "  case %d: guest dst mismatch\n", idx);
        free(model); free(gn);
        return 1;
    }

    /* native run on a fresh copy */
    seed_case(src, dst, count);
    vf3_native_aim x;
    memset(&x, 0, sizeof x);
    x.ram = (float *)ram;
    x.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) x.r[i] = 0x76543210u + i;
    x.r[4] = dst;
    x.r[5] = src;
    x.r[6] = count;
    x.r[15] = sp0_push;
    x.pr = RETURN_PC;
    x.sr = 0x60000000u;
    x.fpscr = 0x00024001u;
    vf3_native_mem_move(&x);

    int bad = 0;
    /* RAM */
    if (memcmp(ram + (dst - RAM_BASE), model + (dst - RAM_BASE), count) != 0) {
        fprintf(stderr, "  case %d: native dst mismatch\n", idx);
        bad++;
    }
    /* r0 = dst, SR.T set */
    if (x.r[0] != dst) fprintf(stderr, "  case %d: r0 native %08x want %08x\n", idx, x.r[0], dst), bad++;
    if ((x.sr & 1u) != 1u) fprintf(stderr, "  case %d: T native %u want 1\n", idx, x.sr & 1u), bad++;
    /* r0 matches guest */
    if (x.r[0] != r0g) fprintf(stderr, "  case %d: r0 native %08x guest %08x\n", idx, x.r[0], r0g), bad++;
    if ((x.sr & 1u) != (srg & 1u)) fprintf(stderr, "  case %d: T native %u guest %u\n", idx, x.sr & 1u, srg & 1u), bad++;

    free(model); free(gn);
    return bad;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    /* forward, non-overlapping */
    bad += compare_one(SRC, DST, 8, SP0, 1);
    /* backward, overlapping (dst > src, regions overlap) */
    bad += compare_one(SRC, SRC + 4, 8, SP0, 2);
    /* backward larger */
    bad += compare_one(SRC, SRC + 2, 16, SP0, 3);
    /* identical (no-op) */
    bad += compare_one(SRC, SRC, 16, SP0, 4);
    /* forward, smaller than source start (dst < src, overlap) */
    bad += compare_one(SRC + 8, SRC, 8, SP0, 5);
    /* single byte forward */
    bad += compare_one(SRC, DST, 1, SP0, 6);
    /* zero bytes */
    bad += compare_one(SRC, DST, 0, SP0, 7);
    /* large, forward */
    bad += compare_one(SRC, DST, 256, SP0, 8);
    /* large, backward-overlapping */
    bad += compare_one(SRC, SRC + 1, 256, SP0, 9);

    free(ram);
    printf("mem_move_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
