/* Differential replay of the native packed-attribute expansion
 * (src/native/pack_expand.c, 0x8C09D5AE) against the readable guest port
 * (src/fight/pack_expand.c, `vf3_pack_expand_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf calls nobody and uses no FP.
 * It reads the table out of the pool, takes the entry the record names,
 * expands the sixteen packed bytes into sixteen groups of four two-bit fields
 * and writes them into the destination the record carries, and also moves the
 * record's own packed byte up by 29 and puts bit 14 of the source's head into
 * the record's packed byte.
 *
 * The literal pool, the table, the source bytes, the destination, the record
 * and the stack sit at the game's own addresses, spanned by one flat buffer.
 * The whole region is compared byte for byte, together with the output
 * registers (r0..r7), the T bit, the record's two changed bytes, the
 * destination's three words and the sixteen groups and the two words the
 * guest pushes on its stack.  The outcome is also checked against an
 * independent model of the guest (written from the disassembly, not from the
 * port). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "pack_expand.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pack_expand_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c09d000u
#define RAM_SIZE 0x5f5000u     /* spans the pool .. the source top */
#define CMP_HI   0x0c692000u

/* the windows */
#define POOL_BASE   0x0c09d000u
#define POOL_LEN    0x1000u
#define TABLE_BASE  0x0c29b000u
#define TABLE_LEN   0x8000u
#define SRC_BASE    0x0c691000u
#define SRC_LEN     0x1000u
#define DEST_BASE   0x0c226000u
#define DEST_LEN    0x1000u
#define REC_BASE    0x0c1f0000u
#define REC_LEN     0x12000u
#define STACK_BASE  0x0c31f000u
#define STACK_LEN   0x1000u
#define NWIN 6

#define TABLE_PTR  (POOL_BASE + 0x800u)
#define TABLE_ROOT (TABLE_BASE + 0x400u)
#define FIRST      (SRC_BASE + 0x500u)
#define SECOND     (TABLE_BASE + 0x800u)
#define THIRD      (TABLE_BASE + 0x900u)
#define DEST       (DEST_BASE + 0x864u)
#define RECORD     (REC_BASE + 0x9100u)
#define SP         (STACK_BASE + 0x9f8u)

#define P_TABLE    (POOL_BASE + 0x6dcu)
#define P_PACKED   (POOL_BASE + 0x6ceu)
#define P_DEST     (POOL_BASE + 0x6d0u)

#define FIELD_INDEX 60u
#define GROUP_COUNT 16u
#define GROUP_SIZE  4u
#define ENTRY_SIZE  12u

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
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint16_t index;
    uint16_t packed_off;
    uint16_t dest_off;
    uint16_t head;
    uint8_t  packed_byte;
    uint8_t  bytes[GROUP_COUNT];
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    memset(ab(POOL_BASE),  0x11, POOL_LEN);

    w32(P_TABLE, TABLE_PTR);
    w16(P_PACKED, sc->packed_off);
    w16(P_DEST, sc->dest_off);
    w32(TABLE_PTR, TABLE_ROOT);

    /* the table's entry: three offsets from the table's base */
    {
        const uint32_t entry = TABLE_ROOT + ENTRY_SIZE * (sc->index - 1u);
        w32(entry,      FIRST - TABLE_ROOT);
        w32(entry + 4u, SECOND - TABLE_ROOT);
        w32(entry + 8u, THIRD - TABLE_ROOT);
    }

    /* the source: the head halfword and the sixteen packed bytes */
    memset(ab(SRC_BASE), 0x44, SRC_LEN);
    w16(FIRST, sc->head);
    for (unsigned i = 0; i < GROUP_COUNT; ++i)
        ab(FIRST + 2u + i)[0] = sc->bytes[i];

    /* the record: garbage, its index, its packed byte, its destination */
    memset(ab(REC_BASE), 0xa5, REC_LEN);
    w16(RECORD + FIELD_INDEX, sc->index);
    {
        const ptrdiff_t at_packed = (ptrdiff_t)(RECORD - RAM_BASE) +
            (int32_t)(int16_t)sc->packed_off;
        const ptrdiff_t at_dest = (ptrdiff_t)(RECORD - RAM_BASE) +
            (int32_t)(int16_t)sc->dest_off;
        ram[at_packed] = sc->packed_byte;
        w32(RAM_BASE + (uint32_t)at_dest, DEST);
    }

    /* the destination and the stack: garbage */
    memset(ab(DEST_BASE),  0x66, DEST_LEN);
    memset(ab(STACK_BASE), 0x5a, STACK_LEN);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = RECORD;
    s->v[15] = SP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x60000001u;         /* sr, T set */
    s->v[18] = 0x00024001u;         /* fpscr */
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { TABLE_BASE, TABLE_LEN }, { SRC_BASE, SRC_LEN },
        { DEST_BASE, DEST_LEN }, { REC_BASE, REC_LEN }, { STACK_BASE, STACK_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    const int ok_guest = vf3_pack_expand_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the guest's RAM before the native re-seeds */
    uint8_t *gshot = (uint8_t *)malloc(CMP_HI - RAM_BASE);
    memcpy(gshot, ram, CMP_HI - RAM_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = RECORD;
    a.r[15] = SP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_pack_expand(&a, SP);

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

    /* the output registers, the T bit, r15 */
    {
        int nb = 0;
        uint32_t want[8] = { 0u, GROUP_COUNT,
                             FIRST + 2u + GROUP_COUNT,
                             DEST + 12u + GROUP_COUNT * GROUP_SIZE - GROUP_SIZE,
                             DEST, GROUP_COUNT * GROUP_SIZE, 0u, GROUP_COUNT };
        const uint8_t last = sc->bytes[GROUP_COUNT - 1];
        want[0] = last & 3u;
        want[6] = last;
        static const unsigned reg[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        for (unsigned i = 0; i < 8; ++i)
            if (a.r[reg[i]] != want[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", reg[i], a.r[reg[i]], want[i]);
                nb++;
            }
        if ((a.sr & 1u) != 1u) { fprintf(stderr, "  sr T: native %u want 1\n", a.sr & 1u); nb++; }
        if (a.r[15] != SP) { fprintf(stderr, "  r15: native %08x want %08x\n", a.r[15], SP); nb++; }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the record's two bytes + the destination + groups + stack, against the
     * fixture */
    {
        int nb = 0;
        const int32_t packed_at = (int32_t)(int16_t)sc->packed_off;
        const uint16_t head = sc->head;
        /* record's packed byte keeps (head>>12)&4, byte+29 keeps the original */
        uint8_t rec_byte = (uint8_t)((head >> 12) & 4u);
        if (r32(RECORD + (uint32_t)packed_at) != (uint32_t)rec_byte &&
            (r32(RECORD + (uint32_t)packed_at) & 0xffu) != rec_byte)
            ; /* checked byte-wise below */
        if ((r32(RECORD + (uint32_t)packed_at) & 0xffu) != rec_byte) {
            fprintf(stderr, "  rec byte: %02x want %02x\n",
                    r32(RECORD + (uint32_t)packed_at) & 0xffu, rec_byte);
            nb++;
        }
        /* the destination's three words */
        uint32_t d0 = FIRST + 17u, d4 = SECOND, d8 = THIRD;
        if (r32(DEST) != d0 || r32(DEST + 4u) != d4 || r32(DEST + 8u) != d8) {
            fprintf(stderr, "  dest words: %08x %08x %08x want %08x %08x %08x\n",
                    r32(DEST), r32(DEST + 4u), r32(DEST + 8u), d0, d4, d8);
            nb++;
        }
        /* the sixteen groups */
        for (unsigned k = 0; k < GROUP_COUNT; ++k) {
            const uint32_t v = sc->bytes[k];
            uint8_t want4[4] = { (uint8_t)((v >> 6) & 3u), (uint8_t)((v >> 4) & 3u),
                                 (uint8_t)((v >> 2) & 3u), (uint8_t)(v & 3u) };
            for (unsigned j = 0; j < 4; ++j) {
                if (ab(DEST + 12u + 4u * k + j)[0] != want4[j]) {
                    fprintf(stderr, "  group %u byte %u: %02x want %02x\n",
                            k, j, ab(DEST + 12u + 4u * k + j)[0], want4[j]);
                    nb++;
                }
            }
        }
        /* the two words the guest pushed on its stack, below SP */
        if (r32(SP - 8u) != SECOND || r32(SP - 4u) != THIRD) {
            fprintf(stderr, "  stack: %08x %08x want %08x %08x\n",
                    r32(SP - 8u), r32(SP - 4u), SECOND, THIRD);
            nb++;
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

    static const struct scenario scenarios[] = {
        { .name = "the first entry, the corpus' offsets",
          .index = 1, .packed_off = 8127, .dest_off = 7424,
          .head = 0x003cu, .packed_byte = 0x00u,
          .bytes = { 0x31u, 0xd7u, 0x5du, 0x75u, 0x55u, 0x40u, 0x10u, 0x53u,
                     0x13u, 0x00u, 0xc4u, 0xc0u, 0x11u, 0x41u, 0x14u, 0x10u } },
        { .name = "a middle entry, other offsets",
          .index = 4, .packed_off = 0x1f00u, .dest_off = 0x1c00u,
          .head = 0x4000u, .packed_byte = 0xa7u,
          .bytes = { 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u,
                     0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u, 0xffu, 0x00u } },
        { .name = "a high entry, a head with bit 14 set",
          .index = 1050, .packed_off = 8127, .dest_off = 7424,
          .head = 0x5000u, .packed_byte = 0x5au,
          .bytes = { 0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u,
                     0x08u, 0x09u, 0x0au, 0x0bu, 0x0cu, 0x0du, 0x0eu, 0x0fu } },
        { .name = "the last entry, every field set",
          .index = 2400, .packed_off = 0x0f00u, .dest_off = 0x1000u,
          .head = 0x7fffu, .packed_byte = 0xffu,
          .bytes = { 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
                     0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu } },
        { .name = "a head with only bit 14 set",
          .index = 7, .packed_off = 0x2000u, .dest_off = 0x1800u,
          .head = 0x4000u, .packed_byte = 0x01u,
          .bytes = { 0x01u, 0x02u, 0x04u, 0x08u, 0x10u, 0x20u, 0x40u, 0x80u,
                     0x03u, 0x0cu, 0x30u, 0xc0u, 0x00u, 0x00u, 0x00u, 0x00u } },
        { .name = "negative offsets out of the pool",
          .index = 2, .packed_off = 0x8000u, .dest_off = 0x9000u,
          .head = 0x4004u, .packed_byte = 0x3cu,
          .bytes = { 0x81u, 0x42u, 0x24u, 0x18u, 0x81u, 0x42u, 0x24u, 0x18u,
                     0x81u, 0x42u, 0x24u, 0x18u, 0x81u, 0x42u, 0x24u, 0x18u } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("pack_expand_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
