/* Differential replay of the native record repack (src/native/record_copy.c,
 * 0x8C043A7C) against the readable guest port (src/fight/record_copy.c,
 * `vf3_record_copy_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf copies twenty-four records
 * from the table (pool 0x0c043b78) into the destination array (pool
 * 0x0c043b74).  The source's records are 0x2c apart with the first at +0x28 of
 * the table's cell; the destination's are 0x18 apart.  Per record the source's
 * bytes 0..3 and 8..11 and its words 16 and 20 become the destination's bytes
 * 0..3 and 4..7 and its words 8 and 12.  It keeps **no stack frame**.
 *
 * The pool, the table, the destination and the source sit at the game's own
 * addresses, spanned by one flat buffer.  The whole region is compared byte
 * for byte, together with the registers (r0..r15), the T bit and the copied
 * records against an independent model written in the test.  The destination
 * starts full of a pattern, so a byte the leaf does not write (the last eight
 * of each record) shows up. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "record_copy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c043b70u
#define RAM_SIZE 0x36c8d8u       /* pool .. source end */
#define CMP_HI   0x0c3b0448u

/* the windows */
#define POOL_BASE 0x0c043b70u
#define POOL_LEN  0x20u
#define G_DEST  (POOL_BASE + 0x04u)
#define G_TABLE (POOL_BASE + 0x08u)
#define DEST_BASE 0x0c300000u
#define DEST_LEN  0x240u
#define TABLE_BASE 0x0c3a0000u
#define TABLE_LEN  0x10u
#define SRC_BASE  0x0c3b0000u
#define SRC_LEN   0x460u
#define NWIN 4

#define RECORDS 24u
#define SRC_STRIDE 0x2cu
#define DEST_STRIDE 0x18u
#define SRC_OFFSET 0x28u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint8_t  r8(uint32_t addr) { return ab(addr)[0]; }
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
    memset(ram, 0, RAM_SIZE);

    /* the literal pool: the two pointers */
    w32(G_DEST, DEST_BASE);
    w32(G_TABLE, TABLE_BASE);

    /* the table's cell is the source */
    w32(TABLE_BASE, SRC_BASE);

    /* the source's records: every byte carries its offset within the record
     * (so word16 != word20 and byte8 != byte9), and every record differs, so
     * the repack is visible */
    for (unsigned i = 0; i < RECORDS; ++i) {
        uint32_t base = SRC_BASE + SRC_OFFSET + i * SRC_STRIDE;
        for (unsigned b = 0; b < 0x30; ++b)
            ab(base + b)[0] = (uint8_t)(0xa0 + i + b);
    }

    /* the destination starts full of a pattern, so the bytes the leaf does not
     * write show up */
    memset(ab(DEST_BASE), 0x7e, DEST_LEN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { DEST_BASE, DEST_LEN }, { TABLE_BASE, TABLE_LEN },
        { SRC_BASE, SRC_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the model: what the fixture says the destination has to look like */
static int model_ok(uint32_t *bad_addr)
{
    for (unsigned i = 0; i < RECORDS; ++i) {
        uint32_t d = DEST_BASE + i * DEST_STRIDE;
        uint32_t s = SRC_BASE + SRC_OFFSET + i * SRC_STRIDE;
        /* bytes 0..3 <- source bytes 0..3 */
        for (unsigned b = 0; b < 4; ++b)
            if (r8(d + b) != r8(s + b)) { *bad_addr = d + b; return 0; }
        /* bytes 4..7 <- source bytes 8..11 */
        for (unsigned b = 0; b < 4; ++b)
            if (r8(d + 4 + b) != r8(s + 8 + b)) { *bad_addr = d + 4 + b; return 0; }
        /* words 8 and 12 <- source words 16 and 20 */
        if (r32(d + 8u) != r32(s + 16u)) { *bad_addr = d + 8u; return 0; }
        if (r32(d + 12u) != r32(s + 20u)) { *bad_addr = d + 12u; return 0; }
        /* the destination's last eight bytes are left alone */
        for (unsigned b = 16; b < DEST_STRIDE; ++b)
            if (r8(d + b) != 0x7eu) { *bad_addr = d + b; return 0; }
    }
    return 1;
}

static int compare_one(void)
{
    seed_all();
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_record_copy_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[15] = 0x0c108000u;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_record_copy(&a);
    free(seed_shot);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - RAM_BASE), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* the registers + T bit + the model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        if (((a.sr & 1u) != 0) != ((gs.v[17] & 1u) != 0)) {
            fprintf(stderr, "  sr T: native %u want %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }
        /* after 24 records the T bit of the exit compare is set */
        int expect_t = 1;
        if (((a.sr & 1u) != 0) != expect_t) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, expect_t);
            nb++;
        }
        uint32_t ba = 0;
        if (!model_ok(&ba)) {
            fprintf(stderr, "  model: wrong byte at %08x\n", ba);
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    int bad = compare_one();
    free(ram);
    printf("record_copy_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
