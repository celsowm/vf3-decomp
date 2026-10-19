/* boot_sim.c - host-native frames of the boot loader's GD wait: the wait-loop iteration plus the vblank interrupt.
 *
 *   vf3boot <loop.bin> <irqA.bin> <irqB.bin> --loop-entry E --loop-stop S --irqa E --irqb E [options]
 *
 * Starts from the machine state of <loop.bin> pair 0 and, per frame, runs `polls` iterations of the loader's wait loop
 * (each iteration costs `--gd-cycles` cycles of the GD clock) followed by the two vblank handlers, entered with the
 * registers recorded at their entry. After the last frame the RAM is compared with the entry RAM of pair F of <irqA.bin>
 * (the emulator's RAM at the F-th vblank). The IRQ is taken between iterations here; the real one lands inside a BIOS poll,
 * so a few bytes of ordering noise are expected and are reported, not hidden. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "sys/maple_hle.h"
#include "sys/bios_syscall.h"
#include "sys/gdrom_hle.h"

#define GBR_DEFAULT 0x0C16B880u
#define CYCLES_PER_FRAME 3336670u

typedef struct { uint32_t regs[37], xf[16]; uint8_t *ram; } snap;

static int load(const char *path, unsigned pair, snap *s)
{
    if (!vf3_native_load_snapshot(path, pair, s->regs, &s->ram)) { fprintf(stderr, "vf3boot: cannot load pair %u of %s\n", pair, path); return 0; }
    vf3_native_get_xf(s->xf);
    return 1;
}

static int full_loop, run_depth;
static uint32_t next_extra, last_regs[37], last_pc;

static int run(uint8_t *ram, const snap *s, uint32_t entry, uint32_t stop, const char *what)
{
    vf3_native_tick_result r;
    vf3_native_set_xf(s->xf);
    vf3_native_set_stop(stop);
    vf3_native_set_extra_stop(next_extra);
    next_extra = 0;
    ++run_depth;
    vf3_native_tick_run(ram, s->regs, entry, GBR_DEFAULT, &r);
    --run_depth;
    if (!run_depth) {   /* only the outermost run's final registers are the loop's; an interrupt taken inside it is nested */
        memcpy(last_regs, r.regs, sizeof last_regs);
        last_pc = r.pc;
    }
    if (!r.ok || r.unowned_calls) {
        fprintf(stderr, "vf3boot: %s failed at %08x (unowned %u, first %08x)\n", what, r.failed_pc, r.unowned_calls, r.first_unowned);
        return 0;
    }
    if (stop && r.pc != stop && !full_loop) {
        static unsigned shown;
        if (shown++ < 5) fprintf(stderr, "vf3boot: %s ended at %08x, not the loop head %08x\n", what, r.pc, stop);
    }
    return 1;
}

/* --irq-in-poll: the vblank handlers are taken inside the BIOS poll of the last iteration of a frame, as the real interrupt is */
static struct { int armed; uint8_t *ram; const snap *a, *b; uint32_t irqa, irqb; int failed; } irq;

/* --cycle-frames: a free-running clock; every served poll costs per_poll cycles and the vblank pair is taken inside the poll
 * whose cycle count crosses the next frame boundary */
static struct { int on; uint64_t now, next; unsigned taken; int polled; uint32_t per_poll; vf3_gdrom *gd; } clk;

static void poll_irq(void *ctx)
{
    (void)ctx;
    if (clk.on) {
        clk.polled = 1;
        clk.now += clk.per_poll;
        vf3_native_tmu_advance(clk.per_poll);
        if (clk.now < clk.next) return;
        clk.next += CYCLES_PER_FRAME;
        ++clk.taken;
        irq.armed = 1;
    }
    if (!irq.armed) return;
    irq.armed = 0;
    if (!run(irq.ram, irq.a, irq.irqa, 0, "vblank handler A") || !run(irq.ram, irq.b, irq.irqb, 0, "vblank handler B")) irq.failed = 1;
}

static unsigned hook_slice, irq_cap = 400, asic_busy, peek_last;
static uint32_t rd32(const uint8_t *ram, uint32_t a) { uint32_t v; memcpy(&v, ram + (a & 0x0FFFFFFFu) - 0x0C000000u, 4); return v; }
static uint32_t slice_hook(void)
{
    /* the guest has run a time slice: the drive and the frame clock move, the vblank pair is taken in place */
    clk.now += hook_slice;
    vf3_native_tmu_advance(hook_slice);
    if (clk.gd) vf3_bios_gd_advance_cycles(clk.gd, hook_slice);
    while (clk.now >= clk.next) {
        clk.next += CYCLES_PER_FRAME;
        ++clk.taken;
        if (!run(irq.ram, irq.a, irq.irqa, 0, "vblank handler A") || !run(irq.ram, irq.b, irq.irqb, 0, "vblank handler B")) { irq.failed = 1; return 0; }
    }
    int dma_done = 0;
    for (unsigned n = vf3_native_take_dma2(); n; --n) {
        dma_done = 1;   /* a DMA transfer ended: the ASIC handler clears the channel and starts the next queued one */
        vf3_native_raise_asic(0x80000u);   /* Ch2-DMA end: the handler clears the channel and starts the next queued transfer */
    }
    /* PVR/TA events: the lists a DMA fed end (the game says which it expects in 0x0C16CDE8), a started render ends */
    if (dma_done) {
        const uint32_t want = rd32(irq.ram, 0x0C16CDE8u) & ~rd32(irq.ram, 0x0C16CDECu);   /* lists not yet ended */
        static const uint32_t bits[5] = { 0x80u, 0x100u, 0x200u, 0x400u, 0x200000u };
        for (unsigned i = 0; i < 5; ++i) if (want & (1u << i)) vf3_native_raise_asic(bits[i]);
    }
    {   /* Maple: the list is answered at once (a stand-in pad on port A) and the DMA-end event follows */
        uint32_t list = 0;
        static const vf3_maple_pad pad = { 0xFFFFu, 0, 0, 0x80, 0x80, 0x80, 0x80 };
        for (unsigned n = vf3_native_take_maple(&list); n; --n) {
            vf3_maple_dma(irq.ram, VF3_NATIVE_RAM_BASE, VF3_NATIVE_RAM_LEN, list, &pad);
            vf3_native_raise_asic(0x1000u);
        }
    }
    for (unsigned n = vf3_native_take_render(); n; --n) vf3_native_raise_asic(0x4u);
    if (vf3_native_asic_pending() && !asic_busy) {   /* the ASIC interrupt handler dispatches them */
        asic_busy = 1;
        snap d = *irq.a;
        d.regs[16] = 0xDEAD0000u;
        if (!run(irq.ram, &d, 0x0C06423Au, 0, "asic handler")) { irq.failed = 1; return 0; }
        asic_busy = 0;
    }
    if (getenv("BS_PEEK") && clk.taken % 40 == 0 && clk.taken != peek_last) {
        peek_last = clk.taken;
        static const uint32_t a[] = { 0x0C16CDCCu, 0x0C16CDD0u, 0x0C16CC90u, 0x0C16CC94u, 0x0C16CDE8u, 0x0C16CDECu, 0x0C16CDF0u, 0x0C16CDF4u, 0x0C16CDF8u, 0x0C16CD30u, 0x0C16CCACu, 0x0C16CCB0u, 0x0C1981C8u, 0x0C1981D0u };
        fprintf(stderr, "peek vb %u:", clk.taken);
        for (unsigned i = 0; i < sizeof a / sizeof *a; ++i) fprintf(stderr, " %08x", rd32(irq.ram, a[i]));
        fputc(10, stderr);
        if (getenv("BS_CMP")) {   /* distance to a later captured state: bytes of RAM that differ */
            static snap cmp; static int have;
            if (!have) { have = load(getenv("BS_CMP"), 0, &cmp) ? 1 : -1; }
            if (have > 0) {
                unsigned long diff = 0;
                for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) diff += irq.ram[i] != cmp.ram[i];
                fprintf(stderr, "cmp vb %u: %lu bytes differ%c", clk.taken, diff, 10);
                if (getenv("BS_CMPV")) {   /* the 4 KB blocks that differ most */
                    static unsigned blk[VF3_NATIVE_RAM_LEN >> 12];
                    memset(blk, 0, sizeof blk);
                    for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) blk[i >> 12] += irq.ram[i] != cmp.ram[i];
                    for (unsigned n = 0; n < 400; ++n) {
                        unsigned best = 0;
                        for (unsigned j = 1; j < (VF3_NATIVE_RAM_LEN >> 12); ++j) if (blk[j] > blk[best]) best = j;
                        if (!blk[best]) break;
                        fprintf(stderr, "  block %08x: %u%c", VF3_NATIVE_RAM_BASE + (best << 12), blk[best], 10);
                        blk[best] = 0;
                    }
                }
            }
        }
    }
    return clk.taken < irq_cap ? hook_slice : 0;
}

int main(int argc, char **argv)
{
    const char *gdi_path = NULL, *gd_state = NULL;
    uint32_t loop_entry = 0, loop_stop = 0, irqa = 0, irqb = 0, per_poll = 2688, per_step = 1000000;
    int in_poll = 0, go_on = 0;
    unsigned slice_steps = 20000;   /* guest steps per time slice: the budget hook moves the clocks and takes the vblank pair in place */
    uint64_t gd_phase = 0;
    unsigned cycle_frames = 0;
    int maple_inflight = 0;   /* the savestate was taken with a Maple DMA running (mpdrv state SENT): its end event is due */
    int free_run = 0;   /* the capture is a plain game state, not a loader wait: run its code from --loop-entry for the vblank cap */
    unsigned frames = 1, first_polls = 0, per_frame = 0, polls_per_frame = 0;
    if (argc < 4) { fprintf(stderr, "usage: vf3boot loop.bin irqA.bin irqB.bin --loop-entry E --loop-stop S --irqa E --irqb E [--frames N] [--first-polls P] [--gdi f --gd-state f]\n"); return 2; }
    for (int i = 4; i + 1 < argc; i += 2) {
        const char *k = argv[i], *v = argv[i + 1];
        if (!strcmp(k, "--loop-entry")) loop_entry = (uint32_t)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--loop-stop")) loop_stop = (uint32_t)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--irqa")) irqa = (uint32_t)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--irqb")) irqb = (uint32_t)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--frames")) frames = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--polls-per-frame")) polls_per_frame = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--first-polls")) first_polls = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--cycle-frames")) cycle_frames = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--gd-phase")) gd_phase = (uint64_t)strtoull(v, NULL, 0);
        else if (!strcmp(k, "--full-loop")) full_loop = (int)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--slice")) slice_steps = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--vblank-cap")) irq_cap = (unsigned)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--maple-inflight")) maple_inflight = (int)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--aica-word")) { unsigned ao, av; if (sscanf(v, "%x:%x", &ao, &av) == 2) vf3_native_aica_poke(ao, av); }
        else if (!strcmp(k, "--free")) free_run = (int)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--continue")) go_on = (int)strtoul(v, NULL, 0);
        else if (!strcmp(k, "--irq-in-poll")) { in_poll = (int)strtoul(v, NULL, 0); }
        else if (!strcmp(k, "--gdi")) gdi_path = v;
        else if (!strcmp(k, "--gd-state")) gd_state = v;
        else { fprintf(stderr, "vf3boot: unknown option %s\n", k); return 2; }
    }
    per_frame = polls_per_frame ? polls_per_frame : CYCLES_PER_FRAME / per_poll;
    const int use_tmu = cycle_frames && getenv("VF3_TMU");   /* opt-in: the frame clock the render/title waits sample */
    if (use_tmu) vf3_native_enable_tmu();

    snap loop, a, b, ref;
    if (!load(argv[1], 0, &loop) || !load(argv[2], 0, &a) || !load(argv[3], 0, &b)) return 2;
    if (use_tmu) vf3_native_tmu_set(rd32(loop.ram, 0x0C1981C8u));   /* start the frame clock where the savestate left it */
    free(a.ram); free(b.ram);                       /* only their entry registers are used */
    if (!load(argv[2], getenv("BS_REF") ? (unsigned)atoi(getenv("BS_REF")) : frames, &ref)) return 2;

    vf3_gdi gdi;
    vf3_gdrom gd;
    if (gdi_path) {
        if (vf3_gdi_open(&gdi, gdi_path) != 0) { fprintf(stderr, "vf3boot: cannot open %s\n", gdi_path); return 2; }
        vf3_gd_init(&gd, &gdi, NULL, NULL);
        if (gd_state) {
            FILE *f = fopen(gd_state, "r");
            unsigned w[16];
            int n = 0;
            while (f && n < 16 && fscanf(f, "%x", &w[n]) == 1) ++n;
            if (f) fclose(f);
            if (n != 16) { fprintf(stderr, "vf3boot: bad GD state %s\n", gd_state); return 2; }
            vf3_gd_state *st = &gd.st;
            st->last_request_id = w[0]; st->next_request_id = w[1]; st->status = (int32_t)w[2]; st->command = w[3];
            for (int i = 0; i < 4; ++i) { st->params[i] = w[4 + i]; st->result[i] = w[8 + i]; }
            st->cur_sector = w[12]; st->multi_read_sector = w[13]; st->multi_read_offset = w[14]; st->multi_read_count = w[15];
            st->multi_read_total = w[15];
        }
        vf3_native_attach_gdrom(&gd);
        vf3_bios_gd_set_cycle_clock(per_poll, per_step);
        if (gd_phase) vf3_bios_gd_advance_cycles(&gd, gd_phase);   /* the drive is part-way through a step when the capture begins */
    }

    if (cycle_frames) {
        clk.on = 1; clk.per_poll = per_poll; clk.next = CYCLES_PER_FRAME - (uint64_t)(first_polls ? first_polls : 0) * per_poll * 0; clk.gd = gdi_path ? &gd : NULL;
        if (first_polls) clk.next = (uint64_t)first_polls * per_poll;
        irq.ram = loop.ram; irq.a = &a; irq.b = &b; irq.irqa = irqa; irq.irqb = irqb;
        vf3_native_set_poll_hook(poll_irq, NULL);
        unsigned iters = 0;
        snap cur = loop;   /* the register file of the wait function, carried from one iteration to the next */
        uint32_t ret = 0, resume = loop_entry, head = loop_stop;
        int finished = 0;
        if (getenv("BS_POKE")) {   /* BS_POKE=addr:value (hex): an experiment, write one RAM word before the run starts */
            unsigned pa = 0, pv = 0;
            if (sscanf(getenv("BS_POKE"), "%x:%x", &pa, &pv) == 2) {
                const uint32_t off = (uint32_t)pa & 0x00FFFFFFu;
                memcpy(loop.ram + off, &pv, 4);
                fprintf(stderr, "poked %08x = %08x%c", pa, pv, 10);
            }
        }
        if (getenv("BS_FIND")) {   /* BS_FIND=word: every RAM address holding that 32-bit word, with the three words before and after */
            const uint32_t want = (uint32_t)strtoul(getenv("BS_FIND"), NULL, 0);
            for (uint32_t a = VF3_NATIVE_RAM_BASE; a < VF3_NATIVE_RAM_BASE + VF3_NATIVE_RAM_LEN - 16; a += 4)
                if (rd32(loop.ram, a) == want) {
                    fprintf(stderr, "find %08x:", a);
                    for (int k = -3; k <= 3; ++k) fprintf(stderr, " %08x", rd32(loop.ram, a + 4 * (uint32_t)k));
                    fputc(10, stderr);
                }
        }
        if (getenv("BS_WORDS")) {   /* BS_WORDS=addr: 24 RAM words from addr at the start, and the entry registers */
            const uint32_t w0 = (uint32_t)strtoul(getenv("BS_WORDS"), NULL, 0);
            for (unsigned i = 0; i < 24; ++i) fprintf(stderr, "%08x: %08x%c", w0 + 4 * i, rd32(loop.ram, w0 + 4 * i), 10);
            for (unsigned i = 0; i < 20; ++i) fprintf(stderr, "r%u=%08x%c", i, cur.regs[i], i % 4 == 3 ? 10 : 32);
        }
        if (maple_inflight) vf3_native_raise_asic(0x1000u);
        if (free_run) { finished = 1; ret = loop_entry; memcpy(last_regs, cur.regs, sizeof last_regs); }
        while (!free_run && clk.taken < cycle_frames && iters < 300000) {
            if (full_loop && iters == 1) {   /* past the first poll an iteration is the whole loop body: poll, decide, time out or return */
                const uint32_t sp = cur.regs[15] & 0x00FFFFFFu;
                memcpy(&ret, loop.ram + sp, 4);   /* the pr the function pushed on entry */
                resume = loop_stop; head = 0x0C035524u;
            }
            if (full_loop && iters >= 1) next_extra = ret;
            if (!run(loop.ram, &cur, resume, head, "wait loop") || irq.failed) { fprintf(stderr, "vf3boot: stopped after %u iterations, %u frames\n", iters, clk.taken); return 1; }
            ++iters;
            if (full_loop) {
                memcpy(cur.regs, last_regs, sizeof cur.regs);
                if (iters > 1 && (last_pc & 0x1FFFFFFFu) == (ret & 0x1FFFFFFFu)) { finished = 1; break; }
                resume = head;
            }
            if (!clk.polled) {   /* an iteration that never reached the BIOS still takes time: the drive and the frame clock move */
                if (gdi_path) vf3_bios_gd_advance_cycles(&gd, per_poll);
                poll_irq(NULL);
            }
            clk.polled = 0;
        }
        if (finished) printf("the wait function returned %d to %08x after %u iterations\n", (int)last_regs[0], (unsigned)ret, iters);
        if (finished && go_on) {   /* the caller of the wait function: game code, run as far as the port reaches */
            snap after = cur;
            memcpy(after.regs, last_regs, sizeof after.regs);
            after.regs[16] = 0xDEAD0000u;
            vf3_native_tick_result r;
            vf3_native_set_xf(cur.xf);
            vf3_native_set_stop(0);
            vf3_native_set_extra_stop(0);
            uint32_t at = ret;
            unsigned slices = 0;
            for (unsigned hop = 0; hop < (unsigned)go_on; ++hop) {
                /* A hop is a time slice of guest steps. It ends where a returning function hands control back to a frame the port has
                 * not entered (resume there with a fresh pr), or where the slice ran out (resume in place, pr kept). Slice time moves
                 * the drive and the frame clock; the vblank pair is taken between slices. */
                if (free_run && hop && ((at & 0x1FFFFFFFu) < 0x0C010000u || (at & 0x1FFFFFFFu) >= 0x0C130000u)) {   /* the task stack ran out: its bottom frame holds a marker or data, not a return address into the image */
                    printf("  task left the code at %08x (outside the image 0C010000-0C130000): the task function returned%c", (unsigned)at, 10);
                    memset(&r, 0, sizeof r); r.ok = 1; r.pc = at;
                    break;
                }
                vf3_native_set_xf(cur.xf);
                vf3_native_set_stop(0);
                vf3_native_set_extra_stop(0);
                vf3_native_set_budget(slice_steps);
                hook_slice = slice_steps;
                vf3_native_set_budget_hook(slice_hook);
                vf3_native_tick_run(loop.ram, after.regs, at, GBR_DEFAULT, &r);
                vf3_native_set_budget(0);
                const int sliced = !r.ok && !r.unowned_calls && !r.oob && r.failed_pc != 0 && r.steps_budget_used >= slice_steps;
                if (!sliced || hop % 50 == 0)
                    printf("  hop %u: %08x -> pc %08x ok %d unowned %u failed %08x steps %u vblanks %u oob %u fpscr %08x\n", hop, (unsigned)at, (unsigned)r.pc, r.ok, r.unowned_calls, (unsigned)r.failed_pc, r.steps_budget_used, clk.taken, r.oob, (unsigned)r.regs[18]);
                clk.now += r.steps_budget_used;
                if (gdi_path) vf3_bios_gd_advance_cycles(&gd, r.steps_budget_used);
                while (clk.now >= clk.next) {
                    clk.next += CYCLES_PER_FRAME;
                    ++clk.taken;
                    if (!run(loop.ram, &a, irqa, 0, "vblank handler A") || !run(loop.ram, &b, irqb, 0, "vblank handler B")) { r.ok = 0; r.oob = 1; break; }
                }
                if (sliced) {
                    ++slices;
                    at = r.failed_pc;
                    memcpy(after.regs, r.regs, 37 * sizeof after.regs[0]);
                    continue;
                }
                /* A callee that returns into a frame this hop never entered (its pr came off the stack) ends with ok 0, no failed pc
                 * and nothing unowned: that is a hand-back, so resume at the return address like the ok-1 hops do. */
                const int handed_back = !r.ok && !r.failed_pc && !r.oob && !r.unowned_calls && r.pc != at;
                if ((!r.ok && !handed_back) || r.unowned_calls || r.pc == at || r.pc == 0xDEAD0000u || (free_run && r.pc == 1)) break;   /* pc 1: a task function returning to its exit marker */
                at = r.pc;
                memcpy(after.regs, r.regs, 37 * sizeof after.regs[0]);
                after.regs[16] = 0xDEAD0000u;
            }
            printf("%u time slices of %u steps\n", slices, slice_steps);
            printf("after the wait: ok %d, pc %08x, failed %08x, unowned %u (first %08x), %u BIOS calls, %u vblanks\n", r.ok, (unsigned)r.pc, (unsigned)r.failed_pc, r.unowned_calls, (unsigned)r.first_unowned, r.bios_calls, clk.taken);
        }
        printf("ran %u wait-loop iterations over %u vblanks (%llu cycles)\n", iters, clk.taken, (unsigned long long)clk.now);
        if (gdi_path) printf("GD model: status %d, %u sectors left, cur %08x\n", (int)gd.st.status, (unsigned)gd.st.multi_read_count, (unsigned)gd.st.cur_sector);
        return 0;
    }
    uint8_t *ram = loop.ram;
    irq.ram = ram; irq.a = &a; irq.b = &b; irq.irqa = irqa; irq.irqb = irqb;
    if (in_poll) vf3_native_set_poll_hook(poll_irq, NULL);
    for (unsigned f = 0; f < frames; ++f) {
        const unsigned polls = f == 0 && first_polls ? first_polls : per_frame;
        for (unsigned p = 0; p < polls; ++p) {
            irq.armed = in_poll == 1 && p + 1 == polls;
            if (!run(ram, &loop, loop_entry, loop_stop, "wait loop") || irq.failed) return 1;
        }
        if (in_poll) continue;
        /* the rest of the frame is interrupt work: it moves the drive too */
        if (gdi_path && (uint64_t)polls * per_poll < CYCLES_PER_FRAME && f > 0) vf3_bios_gd_advance_cycles(&gd, CYCLES_PER_FRAME - (uint64_t)polls * per_poll);
        if (!run(ram, &a, irqa, 0, "vblank handler A") || !run(ram, &b, irqb, 0, "vblank handler B")) return 1;
    }
    /* the reference is the RAM at the entry of the next vblank handler, i.e. before it ran */
    if (getenv("BS_DUMP")) { FILE *d = fopen(getenv("BS_DUMP"), "wb"); if (d) { fwrite(ref.ram + 0x800000u, 1, 0x400000, d); fclose(d); } }
    unsigned bytes = 0, shown = 0;
    for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) {
        if (ram[i] == ref.ram[i]) continue;
        if (shown < 200 && (i >= 0x100000u || getenv("BS_ALL")) && i < 0x800000u) { printf("  ram %08x: native %02x, emulator %02x\n", VF3_NATIVE_RAM_BASE + i, ram[i], ref.ram[i]); ++shown; }
        ++bytes;
    }
    {
        static unsigned blocks[VF3_NATIVE_RAM_LEN >> 12];
        for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) if (ram[i] != ref.ram[i]) ++blocks[i >> 12];
        unsigned listed = 0;
        for (uint32_t k = 0; k < (VF3_NATIVE_RAM_LEN >> 12) && listed < 24; ++k)
            if (blocks[k]) { printf("  4K block %08x: %u bytes\n", VF3_NATIVE_RAM_BASE + (k << 12), blocks[k]); ++listed; }
    }
    printf("after %u frame(s): %u bytes differ from the emulator's RAM at vblank %u\n", frames, bytes, frames);
    if (gdi_path) printf("GD model: status %d, %u sectors left\n", (int)gd.st.status, (unsigned)gd.st.multi_read_count);
    return bytes != 0;
}
