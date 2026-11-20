/* Differential replay of the native record kind (src/native/record_kind.c,
 * 0x8C078044) against the readable guest port (src/fight/record_kind.c,
 * `vf3_record_kind_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed a record (r5), an
 * index into it (r7) and the three frame words the caller left in its frame
 * (entry sp+0/+4/+8).  It steps the record's kind/state bytes and copies a
 * source byte, gated by the caller's words.  It keeps a frame (saves
 * r13/r14 at sp-4/-8).
 *
 * The pool, the record and the caller's stack sit at the game's own addresses,
 * spanned by one flat buffer.  The whole region is compared byte for byte,
 * together with the registers (r0..r15, with r15 back on the entry sp and
 * r13/r14 restored), the T bit and the flag word, the record's bytes and the
 * copies against an independent model written in the test.  The scenarios walk
 * the whole branch tree: the record with and without a kind, the gate open and
 * closed, the three tests holding or not, the state-six extra bit, the merged
 * value fifteen, the kind one, and the kind counting down. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "record_kind.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_kind_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c078158u
#define RAM_SIZE 0x189ea8u       /* pool .. record end */
#define CMP_HI   0x0c202000u

/* the windows */
#define POOL_BASE 0x0c078158u
#define POOL_LEN  0x20u
#define G_KIND   (POOL_BASE + 0x02u)
#define G_STATE  (POOL_BASE + 0x04u)
#define G_SOURCE (POOL_BASE + 0x06u)
#define G_DEST   (POOL_BASE + 0x08u)
#define G_EXTRA  (POOL_BASE + 0x0au)
#define G_GATE   (POOL_BASE + 0x14u)

#define OFF_KIND   0x1bb0u
#define OFF_STATE  0x1bb2u
#define OFF_SOURCE 0x1b83u
#define OFF_DEST   0x1bb4u
#define EXTRA_BIT  0x0100u
#define GATE_BIT   0x40000000u

#define RECORD_BASE 0x0c200000u
#define RECORD_LEN  0x2000u

#define STACK_TOP 0x0c108000u
#define STACK_WIN_BASE (STACK_TOP - 16u)
#define STACK_LEN      0x40u
#define FRAME_FLAGS (STACK_TOP + 0x00u)
#define FRAME_GATE  (STACK_TOP + 0x04u)
#define FRAME_MODE  (STACK_TOP + 0x08u)
#define NWIN 3

struct scenario {
    const char *name;
    uint32_t kind;
    uint32_t state;
    uint32_t source;
    uint32_t flags;
    uint32_t gate;
    uint32_t mode;
    uint32_t index;
};

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
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool, with the values the real image holds */
    w16(G_KIND,   (uint16_t)OFF_KIND);
    w16(G_STATE,  (uint16_t)OFF_STATE);
    w16(G_SOURCE, (uint16_t)OFF_SOURCE);
    w16(G_DEST,   (uint16_t)OFF_DEST);
    w16(G_EXTRA,  (uint16_t)EXTRA_BIT);
    w32(G_GATE,   GATE_BIT);

    /* the record: the three bytes that matter, and the two places the copy
     * lands (they start with a value of their own, so a copy is visible) */
    ab(RECORD_BASE + OFF_KIND   + sc->index)[0] = (uint8_t)sc->kind;
    ab(RECORD_BASE + OFF_STATE  + sc->index)[0] = (uint8_t)sc->state;
    ab(RECORD_BASE + OFF_SOURCE)[0] = (uint8_t)sc->source;
    ab(RECORD_BASE + OFF_DEST   + sc->index)[0] = 0xeeu;
    ab(RECORD_BASE + OFF_SOURCE + 51u)[0] = 0xeeu;

    /* the caller's three frame words */
    w32(FRAME_FLAGS, sc->flags);
    w32(FRAME_GATE, sc->gate);
    w32(FRAME_MODE, sc->mode);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = 0x11111111u;
    s->v[6] = 0x22222222u;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN }, { RECORD_BASE, RECORD_LEN }, { STACK_WIN_BASE, STACK_LEN },
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

/* the model: what the fixture says the leaf has to leave behind */
struct result {
    uint32_t flags;
    uint32_t kind;
    uint32_t state;
    uint32_t dest;
    uint32_t second;
    int copied;
    int t_bit;
};

static void expect(const struct scenario *sc, struct result *out)
{
    const uint32_t nibble = sc->flags & 15u;
    uint32_t flags = sc->flags;

    out->kind = sc->kind;
    out->state = sc->state;
    out->dest = 0xeeu;
    out->second = 0xeeu;
    out->copied = 0;

    if (sc->kind == 0) {
        if (nibble != 0 && nibble != 15u) {
            out->kind = 1u;
            out->state = nibble;
            flags &= 0xfffffff0u;
        }
        out->copied = 1;
        out->dest = sc->source;
        out->second = sc->source;
        out->t_bit = (nibble == 0 || nibble == 15u) ? 1 : 0;
        out->flags = flags;
        return;
    }

    const uint32_t state = sc->state;
    if ((sc->gate & GATE_BIT) == 0) {
        if (state == 4u && (sc->mode & 4u) == 0 && nibble == 1u) {
            out->copied = 1;
            out->dest = sc->source;
            out->second = sc->source;
            out->kind = 0u;
            flags |= nibble;
            out->t_bit = 1;
            out->flags = flags;
            return;
        }
    }

    if (state == 6u && (sc->mode & 15u) == 2u)
        flags |= EXTRA_BIT;
    const uint32_t merged = nibble | state;
    if (merged == 15u) {
        out->kind = 0u;
        flags |= merged;
        out->t_bit = 1;
        out->flags = flags;
        return;
    }
    if (sc->kind == 1u) {
        out->kind = 0u;
        flags |= merged;
        out->t_bit = 1;
        out->flags = flags;
        return;
    }
    out->kind = sc->kind - 1u;
    out->state = merged;
    flags &= 0xfffffff0u;
    out->t_bit = 0;
    out->flags = flags;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    gs.v[5] = RECORD_BASE;
    gs.v[7] = sc->index;
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_record_kind_entry(&gs, &gmap);
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
    a.r[4] = 0x11111111u;
    a.r[5] = RECORD_BASE;
    a.r[6] = 0x22222222u;
    a.r[7] = sc->index;
    a.r[13] = 0x76543210u + 13u;
    a.r[14] = 0x76543210u + 14u;
    a.r[15] = STACK_TOP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_record_kind(&a);
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

    /* the registers + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        if (a.r[15] != STACK_TOP) { fprintf(stderr, "  r15: %08x\n", a.r[15]); nb++; }
        if (a.r[13] != 0x76543210u + 13u || a.r[14] != 0x76543210u + 14u) {
            fprintf(stderr, "  r13/r14: %08x/%08x\n", a.r[13], a.r[14]); nb++;
        }
        if (((a.sr & 1u) != 0) != ((gs.v[17] & 1u) != 0)) {
            fprintf(stderr, "  sr T: native %u want %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }

        /* the model */
        struct result want;
        expect(sc, &want);
        struct { uint32_t addr; uint32_t want; const char *n; } chk[] = {
            { RECORD_BASE + OFF_KIND + sc->index, want.kind, "kind" },
            { RECORD_BASE + OFF_STATE + sc->index, want.state, "state" },
            { RECORD_BASE + OFF_DEST + sc->index, want.dest, "dest" },
            { RECORD_BASE + OFF_SOURCE + 51u, want.second, "second" },
        };
        for (unsigned i = 0; i < 4; ++i) {
            if ((uint32_t)r8(chk[i].addr) != chk[i].want) {
                fprintf(stderr, "  %s @%08x: got %02x want %02x\n", chk[i].n,
                        chk[i].addr, r8(chk[i].addr), chk[i].want);
                nb++;
            }
        }
        if (a.r[0] != want.flags) {
            fprintf(stderr, "  flag word: native %08x want %08x\n", a.r[0], want.flags);
            nb++;
        }
        if (((a.sr & 1u) != 0) != want.t_bit) {
            fprintf(stderr, "  model T: native %u want %d\n", a.sr & 1u, want.t_bit);
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

    static const struct scenario scenarios[] = {
        { "no kind, no bits", 0u, 0x11u, 0x22u, 0x00000000u, 0u, 0u, 1u },
        { "no kind, all four bits", 0u, 0x11u, 0x22u, 0x0000000fu, 0u, 0u, 1u },
        { "no kind, one bit", 0u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "no kind, two bits", 0u, 0x11u, 0x22u, 0x00000012u, 0u, 0u, 1u },
        { "no kind, the top bit", 0u, 0x11u, 0x22u, 0x00000008u, 0u, 0u, 1u },
        { "no kind, the bits and more", 0u, 0x11u, 0x22u, 0x12345678u, 0u, 0u, 1u },
        { "no kind, the index is zero", 0u, 0x11u, 0x22u, 0x00000003u, 0u, 0u, 0u },
        { "no kind, a high source byte", 0u, 0x11u, 0xe5u, 0x00000003u, 0u, 0u, 1u },
        { "a kind, the gate is open", 2u, 0x11u, 0x22u, 0x00000001u, GATE_BIT, 0u, 1u },
        { "a kind, the gate is closed", 2u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is four", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is four, the mode has the bit", 2u, 4u, 0x22u, 0x00000001u, 0u, 4u, 1u },
        { "a kind, the state is four, the mode has the bit and more", 2u, 4u, 0x22u, 0x00000001u, 0u, 6u, 1u },
        { "a kind, the state is four, the bits are not one", 2u, 4u, 0x22u, 0x00000002u, 0u, 0u, 1u },
        { "a kind, the three tests hold", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the three tests would hold, the gate is open", 2u, 4u, 0x22u, 0x00000001u, GATE_BIT, 0u, 1u },
        { "a kind, the three tests hold, the index is zero", 2u, 4u, 0x22u, 0x00000001u, 0u, 0u, 0u },
        { "a kind, the three tests hold, a high source byte", 2u, 4u, 0xe5u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is six", 2u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the state is six, the mode is not two", 2u, 6u, 0x22u, 0x00000001u, 0u, 3u, 1u },
        { "a kind, the state is six, the mode is two", 2u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the state is six, the mode is two, the gate is open", 2u, 6u, 0x22u, 0x00000001u, GATE_BIT, 2u, 1u },
        { "a kind, the merged value is fifteen", 2u, 14u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind is one", 1u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind counts down", 3u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind counts down, the state is six", 3u, 6u, 0x22u, 0x00000001u, 0u, 2u, 1u },
        { "a kind, the kind counts down, a big kind", 0x11u, 0x11u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the kind is one, a big state", 1u, 0x84u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the state is a big byte", 3u, 200u, 0x22u, 0x00000001u, 0u, 0u, 1u },
        { "a kind, the flags have other bits", 3u, 0x11u, 0x22u, 0xabcdef01u, 0u, 0u, 1u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("record_kind_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
