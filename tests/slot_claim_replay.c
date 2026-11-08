/* slot_claim_replay.c - the readable slot-claim scan (SH-4 0x8C062490)
 * against the retained generated translation.
 *
 * The function calls nobody, so the test needs no stub: the three arms are the
 * generated chain (the reference), the readable port called directly, and the
 * readable port reached through the readable override.
 *
 * The body is call-free and integer-only.  It reads two parameters from the
 * literal pool:
 *
 *   base  = [0x0c062590]     a pointer to the first slot
 *   count = (int16)[0x0c06258a]   the number of slots (signed)
 *
 * then scans `count` slots at stride 0x18, reading each slot's 16-bit tag at
 * the slot start; the first slot whose low bit is clear is marked by writing 1
 * (u16) to it and its address is returned in r0.  If none of the slots is free
 * within `count`, r0 = 0 is returned.  The loop is a do-while, so the first
 * slot is always tested even when count <= 0.
 *
 * Left registers: r0 = the found slot's address (or 0), r3 = the last tag read,
 * r4/r6 = the found slot (or one past the run), r5 = 1, r7 = the scan index,
 * SR.T = 1 on both arms.  r1, r2, r8..r14, r15 and r16 are untouched.
 *
 * The two windows mirror the captured corpus: the literal pool at 0x0c062000
 * (the count at 0x0c06258a, the base pointer at 0x0c062590) and the slot array
 * at 0x0c16c000 (base points into it).  Every window byte is patterned first so
 * a wrong address shows as a mismatch rather than a zero.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_slot_claim_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c062490u
#define RETURN_PC 0x0c062004u

/* the two windows, mirroring the corpus */
#define WIN1_BASE 0x0c062000u        /* literal pool */
#define WIN1_LEN  0x1000u
#define POOL_BASE 0x0c062590u        /* holds the slot array base pointer */
#define POOL_CNT  0x0c06258au        /* holds the signed 16-bit count */
#define WIN2_BASE 0x0c16c000u        /* the slot array */
#define WIN2_LEN  0x2000u
#define SLOT_BASE 0x0c16cf6cu        /* the array base, mirrors the corpus */

#define MAXWIN 2u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    int32_t count;                  /* the signed slot count */
    uint16_t tags[8];               /* the 16-bit tags, slots 0..7 */
};

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static unsigned win_len(unsigned w)
{
    static const unsigned L[MAXWIN] = { WIN1_LEN, WIN2_LEN };
    return L[w];
}

/* the VA of slot i */
static uint32_t slot_va(unsigned i)
{
    return SLOT_BASE + 0x18u * i;
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        for (unsigned i = 0; i < win_len(w); i += 4)
            w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the literal pool */
    w32(r->shadow[0], POOL_BASE - WIN1_BASE, SLOT_BASE);
    /* the count is a signed 16-bit halfword at POOL_CNT */
    w16(r->shadow[0], POOL_CNT - WIN1_BASE, (uint16_t)(int16_t)sc->count);

    /* the slots: each 0x18 stride, a 16-bit tag at the slot start; clear the
     * low nibble of the pattern high bytes so any overwrite is visible. */
    for (unsigned i = 0; i < 8; ++i) {
        uint8_t *p = r->shadow[1] + (slot_va(i) - WIN2_BASE);
        w16(p, 0, (uint16_t)sc->tags[i]);
        p[2] = (uint8_t)(0xA0u + i);   /* guard bytes beyond the tag */
    }

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c47f000u;          /* r15, untouched */
    s->v[16] = RETURN_PC;            /* pr: the tail-return target */
    s->v[17] = 0x60000000u;          /* sr, T clear */
    s->v[18] = 0x00024001u;          /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
    r->map.wins = r->wins;
    r->map.n = MAXWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 37 && shown < 12; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                ++shown;
            }
        return 0;
    }
    if (a->state.pc != b->state.pc || a->state.failed_pc != b->state.failed_pc) {
        fprintf(stderr, "  %s: pc %08x/%08x failed %08x/%08x\n", what,
                a->state.pc, b->state.pc, a->state.failed_pc, b->state.failed_pc);
        return 0;
    }
    if (a->map.oob != b->map.oob) {
        fprintf(stderr, "  %s: oob %u/%u\n", what, a->map.oob, b->map.oob);
        return 0;
    }
    for (unsigned w = 0; w < MAXWIN; ++w)
        if (memcmp(a->shadow[w], b->shadow[w], win_len(w))) {
            for (unsigned i = 0; i < win_len(w); ++i)
                if (a->shadow[w][i] != b->shadow[w][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n",
                            what, w, i, a->shadow[w][i], b->shadow[w][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_slot_claim_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "slot_claim: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "slot_claim: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself.  Find the first slot whose low
     * bit is clear, but honour the do-while: the first slot is always tested,
     * and the scan stops once r7 reaches count. */
    uint32_t want_addr = 0;
    unsigned want_idx = 0;
    /* the scan tests iterations while r7 < count, having tested slot 0 first */
    unsigned iters = 0;
    for (;;) {
        const unsigned i = iters;
        if ((sc->tags[i] & 0x01u) == 0u) {      /* free: the mark arm */
            want_addr = slot_va(i);
            want_idx = i;
            break;
        }
        /* occupied: advance; exit when r7 (i+1) >= count */
        if ((int32_t)(iters + 1) >= sc->count)
            break;
        ++iters;
        if (iters >= 8) break;      /* safety: fixture never scans past 8 */
    }
    if (ref.state.v[0] != want_addr) {
        fprintf(stderr, "slot_claim: %s: r0 %08x, want %08x\n", sc->name,
                ref.state.v[0], want_addr);
        return 0;
    }
    if (want_addr != 0) {
        /* found: r4 and r6 are the slot address, r7 is the scan index */
        if (ref.state.v[4] != want_addr || ref.state.v[6] != want_addr ||
            ref.state.v[7] != want_idx) {
            fprintf(stderr, "slot_claim: %s: r4 %08x r6 %08x r7 %u, want %08x "
                    "%08x %u\n", sc->name, ref.state.v[4], ref.state.v[6],
                    ref.state.v[7], want_addr, want_addr, want_idx);
            return 0;
        }
        /* the slot was marked with 1 */
        uint8_t *p = ref.shadow[1] + (slot_va(want_idx) - WIN2_BASE);
        if ((r32(p, 0) & 0xffffu) != 1u) {
            fprintf(stderr, "slot_claim: %s: slot %u not marked (%08x)\n",
                    sc->name, want_idx, r32(p, 0));
            return 0;
        }
    } else {
        /* not found: r7 is the number of slots scanned, r4/r6 one past the
         * run.  The scan always tests slot 0, so at least one slot went by. */
        unsigned scanned = 0;
        for (unsigned i = 0; i < 8; ++i) {
            if ((sc->tags[i] & 0x01u)) {
                if ((int32_t)(i + 1) >= sc->count) { scanned = i + 1; break; }
            }
        }
        if (scanned == 0) scanned = 1;
        if (ref.state.v[7] != scanned ||
            ref.state.v[4] != SLOT_BASE + 0x18u * scanned ||
            ref.state.v[6] != SLOT_BASE + 0x18u * scanned) {
            fprintf(stderr, "slot_claim: %s: exit r7 %u r4 %08x r6 %08x, want "
                    "%u %08x %08x\n", sc->name, ref.state.v[7], ref.state.v[4],
                    ref.state.v[6], scanned, SLOT_BASE + 0x18u * scanned,
                    SLOT_BASE + 0x18u * scanned);
            return 0;
        }
    }
    if (ref.state.v[5] != 1u || (ref.state.v[17] & 1u) != 1u) {
        fprintf(stderr, "slot_claim: %s: r5 %08x T %u\n", sc->name,
                ref.state.v[5], ref.state.v[17] & 1u);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_slot_claim_entry) {
        fprintf(stderr, "slot_claim: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* count 0 still tests slot 0 (do-while); a clear bit answers. */
        { .name = "count0 first slot free",
          .count = 0, .tags = { 0x00, 0x01, 0x01, 0x01, 0, 0, 0, 0 } },
        /* the first slot is free at slot 0. */
        { .name = "first slot free",
          .count = 4, .tags = { 0x03, 0x05, 0x07, 0x0b, 0, 0, 0, 0 } },
        /* slot 0 occupied, slot 1 free. */
        { .name = "second slot free",
          .count = 4, .tags = { 0x01, 0x02, 0x05, 0x07, 0, 0, 0, 0 } },
        /* the first three slots occupied, the fourth free. */
        { .name = "fourth slot free",
          .count = 6, .tags = { 0x01, 0x03, 0x05, 0x00, 0x07, 0x09, 0, 0 } },
        /* a tag with a clear low bit but a non-zero high byte still match. */
        { .name = "high nibble set free",
          .count = 2, .tags = { 0x01, 0x0100, 0, 0, 0, 0, 0, 0 } },
        /* all slots occupied within count: the not-found exit, r0 = 0. */
        { .name = "all occupied",
          .count = 4, .tags = { 0x01, 0x03, 0x05, 0x07, 0x00, 0, 0, 0 } },
        /* negative count: slot 0 is still tested (do-while), so an occupied
         * slot 0 exits immediately. */
        { .name = "negative count occupied first",
          .count = -2, .tags = { 0x01, 0x00, 0, 0, 0, 0, 0, 0 } },
        /* count 1 with slot 0 occupied: exactly one slot is scanned. */
        { .name = "count1 occupied",
          .count = 1, .tags = { 0x01, 0x00, 0, 0, 0, 0, 0, 0 } },
        /* the scan honours count: the third slot is free but count is 2, so the
         * scan stops after slot 1 (both occupied), not reaching the free one. */
        { .name = "count stops before free",
          .count = 2, .tags = { 0x01, 0x03, 0x00, 0, 0, 0, 0, 0 } },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("slot_claim: %u differential cases - PASS\n", cases);
    return 0;
}
