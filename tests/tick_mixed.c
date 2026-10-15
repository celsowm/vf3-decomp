/* tick_mixed.c - whole-tick differential: native C versus the oracle.
 *
 * usage: vf3tickmix <entry> <entry-trace.bin> <fxr.bin> <oracle-final.bin> [pair]
 *                   [--no-readable] [--list]
 *
 *   entry-trace   tools/tick_capture.py capture (entry regs + full 16 MiB RAM)
 *   fxr           oracle call-effect record (tools/recomp/tick_oracle.cpp,
 *                 TICK_REC): entry/exit registers and ordered stores of every
 *                 call in the tick, depth <= 12
 *   oracle-final  oracle final registers + RAM (TICK_DUMP)
 *
 * The entry is run through the real dispatcher chain: readable C first,
 * then the generated ported adapters. Whenever control reaches a function
 * nobody ported yet (adapter fails at the entry itself) the recorded effect
 * of that very call is replayed instead, after checking the call arrived
 * with the registers the oracle saw. The tick therefore executes natively
 * as far as the port reaches, and every divergence is pinned to the first
 * call whose inputs differ.
 *
 * Reported:
 *   - first N stub calls whose argument registers differ (native diverged)
 *   - per-readable-call output check against the recorded call (out_regs
 *     contract + stores)
 *   - share of the tick's executed SH-4 steps that ran natively
 *   - final register / RAM diff against the oracle's own end state
 */
#include "fight/readable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_BASE 0x0C000000u
#define RAM_LEN 0x01000000u
#define NREG 54

/* ---------------------------------------------------------------- loading */
typedef struct {
    uint32_t regs[37];
    uint8_t *ram;
} Snap;

static int read_rec(FILE *f, uint64_t *v) { return fread(v, 8, 1, f) == 1; }

static int load_entry(const char *path, unsigned idx, Snap *in)
{
    FILE *f = fopen(path, "rb");
    uint64_t v;
    unsigned pair = 0;
    int stage = 0; /* 0 wait FA30, 1 wait FA50, 2 wait FA32, 3 wait FA60 */
    if (!f) return 0;
    memset(in, 0, sizeof *in);
    while (read_rec(f, &v)) {
        uint32_t m = (uint32_t)(v & 0xFFFFu);
        if ((v >> 16) == 0 || m < 0xFA30) continue;
        if (m == 0xFA30 && stage == 0) {
            if (pair == idx) {
                for (int i = 0; i < 37; ++i) {
                    if (!read_rec(f, &v)) goto fail;
                    in->regs[i] = (uint32_t)v;
                }
                stage = 1;
            } else stage = 2;
        } else if (m == 0xFA50 && stage == 1) {
            uint32_t nwin;
            if (!read_rec(f, &v)) goto fail;
            nwin = (uint32_t)v;
            for (uint32_t w = 0; w < nwin; ++w) {
                uint64_t b, l;
                if (!read_rec(f, &b) || !read_rec(f, &l)) goto fail;
                uint32_t base = (uint32_t)b, len = (uint32_t)l;
                if (base == RAM_BASE && len == RAM_LEN && !in->ram) in->ram = malloc(RAM_LEN);
                for (uint32_t i = 0; i < len / 4; ++i) {
                    if (!read_rec(f, &v)) goto fail;
                    if (in->ram && base == RAM_BASE) {
                        uint32_t x = (uint32_t)v;
                        memcpy(in->ram + i * 4, &x, 4);
                    }
                }
            }
            fclose(f);
            return in->ram != NULL;
        } else if (m == 0xFA32 && stage == 2) {
            ++pair; stage = 0;
        }
    }
fail:
    fclose(f);
    return 0;
}

typedef struct {
    uint32_t entry, seq, depth, steps;
    unsigned kseq; /* ordinal among records with the same (entry, pr): jmp-entered duplicates of an entry never shift it */
    const uint32_t *in, *out;
    uint32_t nw;
    const uint32_t *w; /* nw triples: addr, size, value */
} Fxr;

static Fxr *fxr;
static size_t nfxr;

/* (entry, pr) -> running ordinal; one table for the oracle records, one for the native run */
typedef struct { uint32_t entry, pr; unsigned n; } KeyCnt;
#define KEYTAB (1u << 17)
static KeyCnt okeys[KEYTAB], nkeys[KEYTAB];
static unsigned *kc(KeyCnt *tab, uint32_t entry, uint32_t pr)
{
    uint32_t h = (entry * 2654435761u ^ (pr & 0x1FFFFFFFu) * 40503u) & (KEYTAB - 1);
    pr &= 0x1FFFFFFFu;
    while (tab[h].entry && (tab[h].entry != entry || tab[h].pr != pr)) h = (h + 1) & (KEYTAB - 1);
    if (!tab[h].entry) { tab[h].entry = entry; tab[h].pr = pr; tab[h].n = 0; }
    return &tab[h].n;
}

static int load_fxr(const char *path)
{
    FILE *f = fopen(path, "rb");
    long n;
    uint32_t *buf;
    size_t words, i = 0, cap = 0;
    if (!f) return 0;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    buf = malloc((size_t)n);
    if (!buf || fread(buf, 1, (size_t)n, f) != (size_t)n) { fclose(f); return 0; }
    fclose(f);
    words = (size_t)n / 4;
    if (words < 1 || buf[0] != 0x31584656u) return 0;
    i = 1;
    while (i + 4 + 2 * NREG + 1 <= words) {
        Fxr r;
        r.entry = buf[i]; r.seq = buf[i + 1]; r.depth = buf[i + 2]; r.steps = buf[i + 3];
        r.in = buf + i + 4; r.out = buf + i + 4 + NREG;
        r.kseq = (*kc(okeys, r.entry, r.in[16]))++;
        r.nw = buf[i + 4 + 2 * NREG];
        r.w = buf + i + 4 + 2 * NREG + 1;
        i += 4 + 2 * NREG + 1 + (size_t)r.nw * 3;
        if (i > words) break;
        if (nfxr == cap) { cap = cap ? cap * 2 : 4096; fxr = realloc(fxr, cap * sizeof *fxr); }
        fxr[nfxr++] = r;
    }
    return 1;
}

/* ------------------------------------------------------------ per-entry state */
typedef struct {
    uint32_t entry;
    unsigned next_seq;          /* ordinal of the next call, as the oracle numbers them */
    unsigned stub_calls, native_calls, readable_calls;
    uint64_t stub_steps;
    unsigned arg_mismatch, out_mismatch;
} EntryStat;

static EntryStat stats[4096]; /* fixed: pointers into it are held across nested calls */
static size_t nstats;

static EntryStat *stat_for(uint32_t entry)
{
    for (size_t i = 0; i < nstats; ++i) if (stats[i].entry == entry) return &stats[i];
    if (nstats == sizeof stats / sizeof stats[0]) { fprintf(stderr, "stat table full\n"); exit(2); }
    memset(&stats[nstats], 0, sizeof stats[nstats]);
    stats[nstats].entry = entry;
    return &stats[nstats++];
}

static const Fxr *find_fxr(uint32_t entry, uint32_t pr, unsigned kseq)
{
    for (size_t i = 0; i < nfxr; ++i)
        if (fxr[i].entry == entry && fxr[i].kseq == kseq && (fxr[i].in[16] & 0x1FFFFFFFu) == (pr & 0x1FFFFFFFu)) return &fxr[i];
    return NULL;
}

/* Every dispatch pushes a frame at enter and pops it at leave. The frame fixes the
 * call's ordinal (the oracle numbers calls in pre-order per entry), so the
 * override / missing hooks and the audit all name the same record. */
typedef struct { uint32_t entry, rec_entry; unsigned seq; uint32_t in[NREG]; int verified_elsewhere; } Frame;
/* A call that tail-jumped (jmp @Rn with pr redirected into a fragment of itself) returns to the
 * dispatcher with pc != pr; the chain then re-dispatches the fragment. The call is only finished
 * when that continuation reaches its real rts, so the audit is carried over. */
static struct { int valid; Frame f; uint32_t pc; } pending;
static Frame frames[512];
static unsigned nframes;
static Frame *frame_top(void) { return nframes ? &frames[nframes - 1] : NULL; }

/* ------------------------------------------------------------- device log
 * The oracle logs every access outside RAM in program order (tick_oracle.cpp, TICK_DEVLOG):
 * 4-word entries {kind, a, b, c}; kind 1 read (addr,size,value), 2 write, 3/4 enter/exit
 * marker of a recorded call (entry,seq). Native reads are answered from the log; a replayed
 * (stubbed) call skips the span between its markers. Any read or write that does not
 * line up with the log is a divergence of the native path from the oracle's. */
static uint32_t *devlog;
static size_t ndev, dcur;
static uint32_t dev_count, dev_desync, dev_wr_value_bad;
static void dev_report(const char *what, uint32_t a, unsigned sz)
{
    if (dev_desync + dev_wr_value_bad <= 8)
        printf("  DEV DESYNC %s %08x/%u at log #%zu: log has kind %u %08x/%u val %08x\n", what, a, sz, dcur,
               dcur < ndev ? devlog[4 * dcur] : 0, dcur < ndev ? devlog[4 * dcur + 1] : 0,
               dcur < ndev ? devlog[4 * dcur + 2] : 0, dcur < ndev ? devlog[4 * dcur + 3] : 0);
}
static void dev_skip_markers(void) { while (dcur < ndev && devlog[4 * dcur] >= 3) ++dcur; }
static uint32_t dev_read(void *c, uint32_t a, unsigned sz)
{
    (void)c;
    ++dev_count;
    if (!devlog) return 0;
    dev_skip_markers();
    if (dcur < ndev && devlog[4 * dcur] == 1 && (devlog[4 * dcur + 1] & 0x1FFFFFFFu) == a && devlog[4 * dcur + 2] == sz)
        return devlog[4 * dcur++ + 3];
    dev_report("read", a, sz);
    ++dev_desync;
    return 0;
}
static unsigned ta_words; /* words the store queues delivered to the TA FIFO */
static int iso_mode; /* TICK_ISO: replay one recorded call alone, printing its device stores */
static void dev_write(void *c, uint32_t a, unsigned sz, uint32_t v)
{
    (void)c;
    ++dev_count;
    if (iso_mode) { printf("  native %08x/%u = %08x\n", a, sz, v); return; }
    if (!devlog) return;
    /* the native map folds addresses to physical; the oracle logged virtual ones (store-queue
     * writes at 0xE0000000.. fold to 0..0x03FFFFFF), hence the mask in the comparison. */
    /* a store-queue burst into the Tile Accelerator (area 4) is delivered by PREF, not by a
     * store, so the oracle's device log has no entry for it */
    if (a >= 0x10000000u && a < 0x14000000u) { ++ta_words; return; }
    dev_skip_markers();
    if (dcur < ndev && devlog[4 * dcur] == 2 && (devlog[4 * dcur + 1] & 0x1FFFFFFFu) == a && devlog[4 * dcur + 2] == sz) {
        if (devlog[4 * dcur + 3] != v) {
            if (dev_wr_value_bad < 24)
                printf("  DEV WRITE-VALUE log #%zu %08x/%u native %08x oracle %08x\n", dcur, devlog[4 * dcur + 1], sz, v, devlog[4 * dcur + 3]);
            ++dev_wr_value_bad;
        }
        ++dcur;
        return;
    }
    dev_report("write", a, sz);
    ++dev_desync;
}
/* a replayed call's device accesses already happened: move past its exit marker */
static void dev_skip_call(uint32_t entry, uint32_t seq)
{
    size_t i = dcur;
    if (!devlog) return;
    while (i < ndev && !(devlog[4 * i] == 3 && devlog[4 * i + 1] == entry && devlog[4 * i + 2] == seq)) ++i;
    while (i < ndev && !(devlog[4 * i] == 4 && devlog[4 * i + 1] == entry && devlog[4 * i + 2] == seq)) ++i;
    if (i >= ndev) { printf("  DEV log: no span for %08x#%u\n", entry, seq); return; }
    dcur = i + 1;
}
static int load_devlog(const char *path)
{
    FILE *f = fopen(path, "rb");
    long n;
    if (!f) return 0;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    devlog = malloc((size_t)n);
    if (!devlog || fread(devlog, 1, (size_t)n, f) != (size_t)n) { fclose(f); return 0; }
    fclose(f);
    ndev = (size_t)n / 16;
    return 1;
}

static unsigned first_reports;
static const char *regname(int i)
{
    static char b[8];
    if (i < 16) { snprintf(b, sizeof b, "r%d", i); return b; }
    static const char *n[] = { "pr", "sr", "fpscr", "macl", "mach" };
    if (i < 21) return n[i - 16];
    if (i < 37) { snprintf(b, sizeof b, "fr%d", i - 21); return b; }
    if (i < 53) { snprintf(b, sizeof b, "xf%d", i - 37); return b; }
    return "fpul";
}

/* An unported callee: replay the oracle's recorded effect of this very call. */
static const vf3_ram_map *g_ram;
static int missing_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    EntryStat *st = stat_for(entry);
    const Fxr *r = find_fxr(entry, frame_top()->in[16], frame_top()->seq);
    if (!r) {
        printf("  NO RECORD for unported %08x call #%u (pr %08x r4 %08x r5 %08x)\n", entry, frame_top()->seq,
               s->v[16], s->v[4], s->v[5]);
        *handled = 0;
        return 0;
    }
    *handled = 1;
    frame_top()->verified_elsewhere = 1;
    dev_skip_call(entry, r->seq);
    /* the replayed call hides its whole subtree from the native run: advance the
     * ordinals of every entry the oracle called underneath it */
    for (size_t j = (size_t)(r - fxr) + 1; j < nfxr && fxr[j].depth > r->depth; ++j) {
        unsigned *c = kc(nkeys, fxr[j].entry, fxr[j].in[16]);
        if (*c < fxr[j].kseq + 1) *c = fxr[j].kseq + 1;
    }
    /* inputs must match: argument + callee-saved registers and sp */
    int bad = 0;
    for (int i = 4; i <= 15; ++i)
        if (s->v[i] != r->in[i]) {
            if (!bad && first_reports < 12)
                printf("  ARG MISMATCH call %08x#%u: %s native %08x oracle %08x\n",
                       entry, r->seq, regname(i), s->v[i], r->in[i]);
            ++bad;
        }
    if (bad) { st->arg_mismatch++; ++first_reports; }
    for (uint32_t k = 0; k < r->nw; ++k)
        vf3_matrix_write(ram, r->w[3 * k], r->w[3 * k + 2], r->w[3 * k + 1]);
    uint32_t pr = s->v[16];
    memcpy(s->v, r->out, sizeof(uint32_t) * NREG);
    s->pc = pr;
    st->stub_calls++;
    st->stub_steps += r->steps;
    return 1;
}

static unsigned fail_n;
static int fail_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    (void)ram; (void)handled;
    if (fail_n++ < 14)
        printf("  FAIL return: entry %08x pc %08x failed_pc %08x pr %08x fpscr %08x\n", entry, s->pc, s->failed_pc, s->v[16], s->v[18]);
    return 0;
}
static vf3_matrix_state saved_4b0;
static uint32_t ring[64], ringpr[64];
static unsigned ring_n;
/* ------------------------------------------------- readable-call verification */
static int reg_differs(int i, uint32_t a, uint32_t b);

/* Register contract of a readable function, checked against the oracle's records:
 *   out_regs   compared with the recorded exit value (results, and registers the
 *              function promises to leave alone)
 *   clobbered  registers the ORIGINAL changes (in != out in some record) that are not in
 *              out_regs: undefined after the call. Refilled from the oracle's record so the
 *              generated callers see identical residue (TICK_SCRATCH=oracle, default), or
 *              poisoned (TICK_SCRATCH=poison) to prove nothing downstream reads them; a
 *              poisoned run that changes the result names an undeclared output.
 *   all others must come back exactly as they went in.
 * TICK_SCRATCH_ONLY=<entry> poisons one function, TICK_SCRATCH_MASK=<hex> only those
 * registers (bit i = v[i]). */
static int scratch_poison;
static uint32_t scratch_only;
/* Captured hardware (flycast) RAM at the end of the tick, optional (TICK_HW_RAM). Where the
 * recompiled oracle and hardware disagree (its denormal handling) a readable store that
 * matches hardware is accepted and only counted. */
static const uint8_t *hw_ram;
static unsigned oracle_quirk_stores;
static int store_matches_hw(const vf3_ram_map *ram, uint32_t a, unsigned sz)
{
    if (!hw_ram || a < RAM_BASE || a + sz > RAM_BASE + RAM_LEN) return 0;
    uint32_t native = vf3_matrix_read(ram, a, sz), hw = 0;
    for (unsigned i = 0; i < sz; ++i) hw |= (uint32_t)hw_ram[a - RAM_BASE + i] << (8 * i);
    return native == hw;
}
static uint64_t scratch_mask = ~0ull;
/* With fewer than MIN_OBSERVED recorded calls (the top-level scheduler is called once and
 * the capture leaves r0-r3 undefined there) nothing is known about what is preserved:
 * the preservation check is skipped and the caller-saved set (r0-r7, macl/mach, fr0-fr15,
 * fpul) is what gets refilled. */
#define MIN_OBSERVED 4
static uint64_t clobber_mask(uint32_t entry, int *known)
{
    static struct { uint32_t entry; uint64_t mask; int known; } cache[64];
    static unsigned n;
    uint64_t m = 0;
    unsigned seen = 0;
    for (unsigned i = 0; i < n; ++i)
        if (cache[i].entry == entry) { *known = cache[i].known; return cache[i].mask; }
    for (size_t k = 0; k < nfxr; ++k)
        if (fxr[k].entry == entry) {
            ++seen;
            for (int i = 0; i < NREG; ++i)
                if (reg_differs(i, fxr[k].in[i], fxr[k].out[i])) m |= 1ull << i;
        }
    *known = seen >= MIN_OBSERVED;
    if (!*known) {
        m = 0;
        for (int i = 0; i < NREG; ++i)
            if (i < 8 || (i >= 19 && i < 37) || i == 53) m |= 1ull << i;
    }
    if (n < 64) { cache[n].entry = entry; cache[n].mask = m; cache[n].known = *known; ++n; }
    return m;
}
static void settle_scratch(const vf3_readable_entry *e, vf3_matrix_state *s, const Fxr *r)
{
    int known;
    const int poison = scratch_poison && (!scratch_only || scratch_only == (e->entry & 0x1FFFFFFFu));
    const uint64_t clobbered = clobber_mask(e->entry & 0x1FFFFFFFu, &known) & ~e->out_regs;
    for (int i = 0; i < NREG; ++i) {
        if (!((clobbered >> i) & 1u)) continue;
        if (poison && ((scratch_mask >> i) & 1u)) s->v[i] = 0xDEAD0000u | (uint32_t)i;
        else if (r) s->v[i] = r->out[i];
    }
}

static int override_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    const vf3_readable_entry *e = vf3_readable_find(entry);
    EntryStat *st;
    const Fxr *r;
    uint32_t in_regs[NREG];
    int ok;
    if (!e) {
        if ((entry & 0x1FFFFFFFu) == 0x0c03b4b0u) memcpy(&saved_4b0, s, sizeof saved_4b0);
        ring[ring_n++ & 63] = (entry & 0x1FFFFFFFu) | 0;
        ringpr[(ring_n - 1) & 63] = s->v[16];
        *handled = 0;
        return 0;
    }
    *handled = 1;
    st = stat_for(entry & 0x1FFFFFFFu);
    r = find_fxr(entry & 0x1FFFFFFFu, frame_top()->in[16], frame_top()->seq);
    frame_top()->verified_elsewhere = 1;
    memcpy(in_regs, s->v, sizeof in_regs);
    ok = e->fn(s, ram);
    st->readable_calls++;
    if (ok) {
        /* registers outside the contract that the original never changes must be untouched */
        int known;
        const uint64_t untouched = ~(clobber_mask(entry & 0x1FFFFFFFu, &known) | e->out_regs);
        int moved = 0;
        for (int i = 0; known && i < NREG; ++i)
            if (((untouched >> i) & 1u) && reg_differs(i, s->v[i], in_regs[i])) {
                if (!moved && first_reports < 12)
                    printf("  PRESERVE MISMATCH %s: %s changed %08x -> %08x\n", e->name, regname(i), in_regs[i], s->v[i]);
                ++moved;
            }
        if (moved) { st->out_mismatch++; ++first_reports; }
        settle_scratch(e, s, r);
    }
    if (r && ok) {
        int bad = 0;
        for (int i = 0; i < NREG; ++i)
            if ((e->out_regs >> i) & 1u)
                if (reg_differs(i, s->v[i], r->out[i])) {
                    if (!bad && first_reports < 12)
                        printf("  OUT MISMATCH %s#%u: %s native %08x oracle %08x (in r0 %08x r4 %08x r8 %08x r12 %08x; out r0 %08x)\n",
                               e->name, r->seq, regname(i), s->v[i], r->out[i],
                               r->in[0], r->in[4], r->in[8], r->in[12], r->out[0]);
                    ++bad;
                }
        /* stores: every recorded final byte must be present in RAM */
        for (uint32_t k = 0; k < r->nw; ++k) {
            uint32_t a = r->w[3 * k], sz = r->w[3 * k + 1], v = r->w[3 * k + 2];
            /* a later recorded store may overwrite this one; compare only the last writer */
            int last = 1;
            for (uint32_t j = k + 1; j < r->nw && last; ++j) {
                uint32_t a2 = r->w[3 * j], s2 = r->w[3 * j + 1];
                if (a2 < a + sz && a < a2 + s2) last = 0;
            }
            if (!last || a < RAM_BASE || a >= RAM_BASE + RAM_LEN) continue;
            if (sz == 4 && vf3_matrix_read(ram, a, sz) == (v | 0x80000000u) && (v & 0xFF000000u) == 0x0C000000u) continue;
            if (vf3_matrix_read(ram, a, sz) != v && store_matches_hw(ram, a, sz)) { ++oracle_quirk_stores; continue; }
            if (vf3_matrix_read(ram, a, sz) != v) {
                if (!bad && first_reports < 12)
                    printf("  STORE MISMATCH %s#%u: %08x/%u native %08x oracle %08x\n",
                           e->name, r->seq, a, sz, vf3_matrix_read(ram, a, sz), v);
                ++bad;
            }
        }
        if (bad) { st->out_mismatch++; ++first_reports; }
    }
    (void)in_regs;
    return ok;
}

/* ---------------------------------------------------------- native audit */
static unsigned stack_reports, audited, audit_bad, audit_norec, audit_reports;
static void check_stores(const Fxr *r, const vf3_ram_map *ram, const char *what, int *bad)
{
    for (uint32_t k = 0; k < r->nw; ++k) {
        uint32_t a = r->w[3 * k], sz = r->w[3 * k + 1], v = r->w[3 * k + 2];
        int last = 1;
        for (uint32_t j = k + 1; j < r->nw && last; ++j) {
            uint32_t a2 = r->w[3 * j], s2 = r->w[3 * j + 1];
            if (a2 < a + sz && a < a2 + s2) last = 0;
        }
        if (!last || a < RAM_BASE || a >= RAM_BASE + RAM_LEN) continue;
        /* the recompiled oracle keeps code addresses in the 0x0C form, hardware (and the port) in 0x8C */
        if (sz == 4 && vf3_matrix_read(ram, a, sz) == (v | 0x80000000u) && (v & 0xFF000000u) == 0x0C000000u) continue;
        if (vf3_matrix_read(ram, a, sz) != v) {
            if (!*bad && audit_reports < 24)
                printf("  AUDIT STORE %s#%u: %08x/%u native %08x oracle %08x\n", what, r->seq, a, sz,
                       vf3_matrix_read(ram, a, sz), v);
            ++*bad;
        }
    }
}

static void print_stacks(uint32_t entry, const Frame *f, const Fxr *r)
{
    printf("    native stack:");
    for (unsigned k = 0; k < nframes; ++k) printf(" %08x#%u", frames[k].entry, frames[k].seq);
    printf(" <- %08x#%u\n    oracle stack:", entry, f->seq);
    {
        uint32_t want = r->depth;
        size_t chain[16];
        unsigned nc = 0;
        for (size_t j = (size_t)(r - fxr); j-- > 0 && want > 0;)
            if (fxr[j].depth == want - 1) { chain[nc++] = j; --want; }
        while (nc) { --nc; printf(" %08x#%u", fxr[chain[nc]].entry, fxr[chain[nc]].seq); }
    }
    printf(" <- %08x#%u\n", entry, r->seq);
}
static int reg_differs(int i, uint32_t a, uint32_t b)
{
    if (i == 16) { a &= 0x1FFFFFFFu; b &= 0x1FFFFFFFu; } /* pr: P1 and P0 aliases of the same code */
    /* sr.T: the oracle's recorded exit snapshot is taken at the rts, before its delay slot
     * (often a cmp that sets T), so T is not comparable there; the whole-tick RAM is. */
    if (i == 17) { a &= ~1u; b &= ~1u; }
    return a != b;
}

static uint32_t trace_under; /* TICK_TRACE_UNDER=<entry>: print every dispatch below that entry */
static void enter_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{
    Frame *f;
    (void)ram; (void)ok;
    if (nframes == sizeof frames / sizeof frames[0]) { fprintf(stderr, "frame stack full\n"); exit(2); }
    f = &frames[nframes++];
    f->entry = entry;
    f->rec_entry = entry;
    f->verified_elsewhere = 0;
    memcpy(f->in, s->v, sizeof f->in);
    if (pending.valid && (pending.pc & 0x1FFFFFFFu) == (entry & 0x1FFFFFFFu)) {
        /* continuation of a tail-jumped call: keep its identity, inputs and ordinal */
        f->rec_entry = pending.f.rec_entry;
        f->seq = pending.f.seq;
        memcpy(f->in, pending.f.in, sizeof f->in);
        pending.valid = 0;
        return;
    }
    if (trace_under) {
        for (unsigned k = 0; k + 1 < nframes; ++k)
            if (frames[k].entry == trace_under) {
                printf("  [under %08x] %*s%08x pr %08x r4 %08x r5 %08x sp %08x\n", trace_under, (int)(nframes - k - 2) * 2, "",
                       entry, s->v[16], s->v[4], s->v[5], s->v[15]);
                break;
            }
    }
    /* The generated chain forwards an entry from one adapter file to the next by
     * re-entering the dispatcher with the identical register file: that is the
     * same call, not a new one. */
    if (nframes > 1 && frames[nframes - 2].entry == entry &&
        memcmp(frames[nframes - 2].in, f->in, sizeof f->in) == 0) {
        f->seq = frames[nframes - 2].seq;
        f->verified_elsewhere = 1;
        return;
    }
    /* A dispatch that leaves pr untouched is not a jsr/bsr: the chain is continuing the same
     * guest function at a seed address inside it (fall-through into a fragment, jmp @Rn tail
     * jump). The oracle sees one call there, so the fragment gets no ordinal of its own. */
    if (nframes > 1 && frames[nframes - 2].in[16] == f->in[16]) {
        f->seq = ~0u;
        f->verified_elsewhere = 1;
        return;
    }
    f->seq = (*kc(nkeys, entry, s->v[16]))++;
}

static void leave_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{
    Frame *f = &frames[--nframes];
    const Fxr *r;
    int bad = 0;
    if (trace_under) {
        for (unsigned k = 0; k < nframes; ++k)
            if (frames[k].entry == trace_under) {
                printf("  [under %08x] %*s%08x -> ok %d pc %08x failed_pc %08x r0 %08x\n", trace_under, (int)(nframes - k - 1) * 2, "",
                       entry, ok, s->pc, s->failed_pc, s->v[0]);
                break;
            }
    }
    if (f->verified_elsewhere || !ok) return;
    if ((s->pc & 0x1FFFFFFFu) != (f->in[16] & 0x1FFFFFFFu)) {
        pending.valid = 1; pending.f = *f; pending.pc = s->pc;
        return;
    }
    entry = f->rec_entry;
    r = find_fxr(entry, f->in[16], f->seq);
    if (!r) {
        if (++audit_norec <= 6 && audit_reports < 24) { printf("  AUDIT no oracle record for %08x#%u\n", entry, f->seq); ++audit_reports; }
        return;
    }
    ++audited;
    for (int i = 4; i < NREG && audit_reports < 24; ++i) {
        /* r0-r3 are call-clobbered scratch: the readable scheduler does not
         * reproduce the residue the guest loop leaves there. sr is skipped. */
        if (i == 17) continue;
        if (reg_differs(i, f->in[i], r->in[i])) {
            printf("  AUDIT IN %08x#%u depth %u rec %zu: %s native %08x oracle %08x (pr native %08x oracle %08x)\n",
                   entry, r->seq, r->depth, (size_t)(r - fxr), regname(i), f->in[i], r->in[i], f->in[16], r->in[16]);
            if (stack_reports++ < 4) print_stacks(entry, f, r);
            ++bad;
            break;
        }
    }
    if (bad) { ++audit_bad; ++audit_reports; return; }
    for (int i = 0; i < NREG; ++i) {
        if (i == 17) continue; /* sr: T bit is the only observable part and is covered by the r/ram diff */
        /* a scratch register the callee left untouched on both sides only carries the
         * caller's residue, which the readable scheduler does not reproduce */
        if (i < 4 && s->v[i] == f->in[i] && r->out[i] == r->in[i]) continue;
        if (reg_differs(i, s->v[i], r->out[i])) {
            if (!bad && stack_reports++ < 4) print_stacks(entry, f, r);
            if (!bad && audit_reports < 24)
                printf("  AUDIT OUT %08x#%u depth %u: %s native %08x oracle %08x (in r4 %08x)\n", entry, r->seq, r->depth,
                       regname(i), s->v[i], r->out[i], f->in[4]);
            ++bad;
        }
    }
    {
        char nm[16];
        snprintf(nm, sizeof nm, "%08x", entry);
        check_stores(r, ram, nm, &bad);
    }
    if (bad) { ++audit_bad; ++audit_reports; }
}

/* Call targets = every entry the oracle saw a jsr/bsr land on. */
static int is_call_entry(uint32_t entry)
{
    static uint32_t *set;
    static size_t cap;
    if (!set) {
        cap = 1u << 16;
        set = calloc(cap, sizeof *set);
        for (size_t i = 0; i < nfxr; ++i) {
            size_t h = (fxr[i].entry * 2654435761u) & (cap - 1);
            while (set[h] && set[h] != fxr[i].entry) h = (h + 1) & (cap - 1);
            set[h] = fxr[i].entry;
        }
    }
    for (size_t h = (entry * 2654435761u) & (cap - 1); set[h]; h = (h + 1) & (cap - 1))
        if (set[h] == entry) return 1;
    return 0;
}

/* The combined override hook: readable C verifies itself against the record. */

int main(int argc, char **argv)
{
    if (argc < 5) {
        fprintf(stderr, "usage: vf3tickmix entry entry-trace fxr oracle-final [pair] [--no-readable]\n");
        return 2;
    }
    uint32_t entry = (uint32_t)strtoul(argv[1], NULL, 0);
    unsigned idx = 0;
    int use_readable = 1;
    for (int i = 5; i < argc; ++i) {
        if (!strcmp(argv[i], "--no-readable")) use_readable = 0;
        else idx = (unsigned)strtoul(argv[i], NULL, 0);
    }
    Snap in;
    if (!load_entry(argv[2], idx, &in)) { fprintf(stderr, "entry pair %u not found\n", idx); return 2; }
    if (!load_fxr(argv[3])) { fprintf(stderr, "bad fxr\n"); return 2; }
    if (getenv("TICK_DEVLOG") && !load_devlog(getenv("TICK_DEVLOG"))) { fprintf(stderr, "bad devlog\n"); return 2; }
    if (getenv("TICK_HW_RAM")) {
        FILE *hf = fopen(getenv("TICK_HW_RAM"), "rb");
        uint8_t *hw = malloc(RAM_LEN);
        if (!hf || fread(hw, 1, RAM_LEN, hf) != RAM_LEN) { fprintf(stderr, "bad TICK_HW_RAM\n"); return 2; }
        fclose(hf);
        hw_ram = hw;
    }
    FILE *of = fopen(argv[4], "rb");
    uint32_t oracle_regs[NREG];
    uint8_t *oracle_ram = malloc(RAM_LEN);
    if (!of || fread(oracle_regs, 4, NREG, of) != NREG || fread(oracle_ram, 1, RAM_LEN, of) != RAM_LEN) {
        fprintf(stderr, "bad oracle-final\n");
        return 2;
    }
    fclose(of);

    vf3_ram_win win = { in.ram, RAM_BASE, RAM_LEN };
    vf3_ram_map ram = { &win, 1, 0, dev_read, dev_write, NULL };
    g_ram = &ram;
    vf3_matrix_state st;
    memset(&st, 0, sizeof st);
    st.budget = 1000000000u;
    memcpy(st.v, in.regs, sizeof in.regs);
    st.v[16] = 0xDEAD0000u; /* same return sentinel the oracle ran with */
    /* The capture format carries no GBR. The fight engine keeps it on its
     * global-state block (0x0C16B880 for the vf3_7 state: located by the
     * @(12/16/20,gbr) stores of 0x0C055D5E..66 in the oracle's final RAM);
     * the adapters refuse @(disp,gbr) accesses until gbr_known is set. */
    st.gbr = getenv("TICK_GBR") ? (uint32_t)strtoul(getenv("TICK_GBR"), NULL, 0) : 0x0C16B880u;
    st.gbr_known = 1;
    /* ldc Rm,Rn_BANK is used as scratch storage by the fight code (0x0C055782..);
     * the banked file is written before it is read, so zeroed is a valid start. */
    st.bank_known = 1;
    vf3_family_override = use_readable ? override_hook : NULL;
    vf3_family_missing = missing_hook;
    vf3_family_fail = fail_hook;
    if (getenv("TICK_TRACE_UNDER")) trace_under = (uint32_t)strtoul(getenv("TICK_TRACE_UNDER"), NULL, 0);
    vf3_family_complete_calls = getenv("TICK_NOCOMPLETE") ? 0 : 1;
    scratch_poison = getenv("TICK_SCRATCH") && !strcmp(getenv("TICK_SCRATCH"), "poison");
    if (getenv("TICK_SCRATCH_MASK")) scratch_mask = strtoull(getenv("TICK_SCRATCH_MASK"), NULL, 16);
    if (getenv("TICK_SCRATCH_ONLY")) scratch_only = (uint32_t)strtoul(getenv("TICK_SCRATCH_ONLY"), NULL, 0) & 0x1FFFFFFFu;
    vf3_sq_model = 1;
    vf3_family_call_entry = is_call_entry;
    vf3_family_enter = enter_hook;
    vf3_family_leave = leave_hook;

    if (getenv("TICK_ISO")) {
        /* TICK_ISO=<entry>,<ordinal>: run one recorded call from its own entry registers on the
         * tick-entry RAM and list its device stores next to the oracle's. */
        uint32_t ie = 0; unsigned iq = 0;
        sscanf(getenv("TICK_ISO"), "%x,%u", &ie, &iq);
        const Fxr *r = NULL;
        for (size_t i = 0; i < nfxr; ++i) if (fxr[i].entry == ie && fxr[i].seq == iq) { r = &fxr[i]; break; }
        if (!r) { fprintf(stderr, "no record\n"); return 2; }
        memcpy(st.v, r->in, sizeof st.v);
        if (getenv("TICK_ISO_SNAP")) { /* whole-RAM image at that call's entry (oracle TICK_SNAP) */
            FILE *sf = fopen(getenv("TICK_ISO_SNAP"), "rb");
            if (!sf || fread(st.v, 4, NREG, sf) != NREG || fread(in.ram, 1, RAM_LEN, sf) != RAM_LEN) { fprintf(stderr, "bad snap\n"); return 2; }
            fclose(sf);
        }
        st.gbr = getenv("TICK_GBR") ? (uint32_t)strtoul(getenv("TICK_GBR"), NULL, 0) : 0x0C16B880u;
        vf3_family_override = NULL; vf3_family_missing = NULL; vf3_family_fail = NULL;
        vf3_family_enter = NULL; vf3_family_leave = NULL;
        iso_mode = 1;
        int iok = vf3_matrix_family(ie, &st, &ram);
        printf("iso run: %s pc %08x\n", iok ? "ok" : "FAILED", st.pc);
        size_t i = 0;
        while (i < ndev && !(devlog[4 * i] == 3 && devlog[4 * i + 1] == ie && devlog[4 * i + 2] == iq)) ++i;
        for (++i; i < ndev && devlog[4 * i] != 4; ++i)
            if (devlog[4 * i] == 2) printf("  oracle %08x/%u = %08x\n", devlog[4 * i + 1] & 0x1FFFFFFFu, devlog[4 * i + 2], devlog[4 * i + 3]);
        return 0;
    }
    int ok = vf3_matrix_family(entry, &st, &ram);
    printf("device log: %zu/%zu consumed, %u desync, %u write-value, %u TA burst words\n", dcur, ndev, dev_desync, dev_wr_value_bad, ta_words);
    printf("run: %s  pc %08x failed_pc %08x fpscr %08x budget used %u oob %u dev %u\n",
           ok ? "completed" : "FAILED", st.pc, st.failed_pc, st.v[18],
           1000000000u - st.budget, ram.oob, dev_count);

    printf("native audit: %u calls verified against the oracle, %u diverged, %u without record\n", audited, audit_bad, audit_norec);
    if (!ok) {
        uint32_t v4[4], res[4];
        extern int vf3_fpu_ftrv(const uint32_t matrix[16], const uint32_t vector[4], uint32_t fpscr, uint32_t result[4]);
        for (int i = 0; i < 3; ++i) v4[i] = vf3_matrix_read(&ram, saved_4b0.v[4] + 4 * i, 4);
        v4[3] = 0;
        printf("  saved r4 %08x r5 %08x fpscr %08x sr %08x; ftrv direct -> %d\n", saved_4b0.v[4], saved_4b0.v[5],
               saved_4b0.v[18], saved_4b0.v[17], vf3_fpu_ftrv(saved_4b0.v + 37, v4, saved_4b0.v[18], res));
    }
    if (!ok) {
        printf("  last dispatched calls (entry<-pr):");
        for (unsigned i = ring_n > 12 ? ring_n - 12 : 0; i < ring_n; ++i)
            printf(" %08x<-%08x", ring[i & 63], ringpr[i & 63]);
        printf("\n");
    }
    /* native-share accounting from the oracle's own stats */
    uint64_t total_steps = 0, stub_steps = 0;
    for (size_t i = 0; i < nfxr; ++i)
        if (fxr[i].depth == 0) total_steps += fxr[i].steps;
    unsigned stubs = 0, natives = 0, readables = 0, mism = 0, omism = 0;
    for (size_t i = 0; i < nstats; ++i) {
        stubs += stats[i].stub_calls;
        readables += stats[i].readable_calls;
        stub_steps += stats[i].stub_steps;
        mism += stats[i].arg_mismatch;
        omism += stats[i].out_mismatch;
    }
    (void)natives;
    printf("stub calls %u (top-level only counted once per entered stub), readable calls %u\n", stubs, readables);
    printf("arg mismatches %u  readable output mismatches %u  (oracle-quirk stores accepted: %u)\n",
           mism, omism, oracle_quirk_stores);
    if (total_steps) {
        /* stub steps count nested stubs inside native code once each; steps inside a stub's own subtree
           that were also separately stubbed cannot double count because the stub replaces its subtree */
        printf("oracle steps under top-level calls: %llu, replayed by stubs: %llu (%.1f%%), native: %.1f%%\n",
               (unsigned long long)total_steps, (unsigned long long)stub_steps,
               100.0 * (double)stub_steps / (double)total_steps,
               100.0 - 100.0 * (double)stub_steps / (double)total_steps);
    }

    /* the stubbed entries, heaviest first */
    for (int pass = 0; pass < 12; ++pass) {
        size_t best = (size_t)-1;
        uint64_t bs = 0;
        for (size_t i = 0; i < nstats; ++i)
            if (stats[i].stub_steps > bs) { bs = stats[i].stub_steps; best = i; }
        if (best == (size_t)-1) break;
        printf("  stub %08x calls %5u steps %9llu\n", stats[best].entry, stats[best].stub_calls,
               (unsigned long long)stats[best].stub_steps);
        stats[best].stub_steps = 0;
    }

    /* final comparison against the oracle */
    int regdiff = 0;
    for (int i = 0; i < 37; ++i)
        if (st.v[i] != oracle_regs[i] && i != 17) { /* sr: T bit is flag noise */
            if (++regdiff <= 8) printf("  reg %-5s native %08x oracle %08x\n", regname(i), st.v[i], oracle_regs[i]);
        }
    printf("reg diffs: %d\n", regdiff);
    if (getenv("TICK_NATIVE_DUMP")) { /* same layout as the oracle dump: NREG regs + RAM */
        FILE *nf = fopen(getenv("TICK_NATIVE_DUMP"), "wb");
        if (nf) { fwrite(st.v, 4, NREG, nf); fwrite(in.ram, 1, RAM_LEN, nf); fclose(nf); }
    }
    unsigned runs = 0, total = 0;
    uint32_t s0 = 0, last = 0;
    int open = 0;
    for (uint32_t i = 0; i <= RAM_LEN; ++i) {
        int d = i < RAM_LEN && in.ram[i] != oracle_ram[i];
        if (d) {
            ++total;
            if (!open) { s0 = i; open = 1; }
            else if (i - last > 16) {
                if (runs < 30) printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last);
                ++runs; s0 = i;
            }
            last = i;
        }
    }
    if (open) { if (runs < 30) printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last); ++runs; }
    printf("ram diff bytes: %u in %u runs\n", total, runs);
    return ok && !regdiff && !total ? 0 : 1;
}
