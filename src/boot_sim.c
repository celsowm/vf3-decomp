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

static int run(uint8_t *ram, const snap *s, uint32_t entry, uint32_t stop, const char *what)
{
    vf3_native_tick_result r;
    vf3_native_set_xf(s->xf);
    vf3_native_set_stop(stop);
    vf3_native_tick_run(ram, s->regs, entry, GBR_DEFAULT, &r);
    if (!r.ok || r.unowned_calls) {
        fprintf(stderr, "vf3boot: %s failed at %08x (unowned %u, first %08x)\n", what, r.failed_pc, r.unowned_calls, r.first_unowned);
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    const char *gdi_path = NULL, *gd_state = NULL;
    uint32_t loop_entry = 0, loop_stop = 0, irqa = 0, irqb = 0, per_poll = 2688, per_step = 1000000;
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
        else if (!strcmp(k, "--gdi")) gdi_path = v;
        else if (!strcmp(k, "--gd-state")) gd_state = v;
        else { fprintf(stderr, "vf3boot: unknown option %s\n", k); return 2; }
    }
    per_frame = polls_per_frame ? polls_per_frame : CYCLES_PER_FRAME / per_poll;

    snap loop, a, b, ref;
    if (!load(argv[1], 0, &loop) || !load(argv[2], 0, &a) || !load(argv[3], 0, &b)) return 2;
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
    }

    uint8_t *ram = loop.ram;
    for (unsigned f = 0; f < frames; ++f) {
        const unsigned polls = f == 0 && first_polls ? first_polls : per_frame;
        for (unsigned p = 0; p < polls; ++p)
            if (!run(ram, &loop, loop_entry, loop_stop, "wait loop")) return 1;
        /* the rest of the frame is interrupt work: it moves the drive too */
        if (gdi_path && (uint64_t)polls * per_poll < CYCLES_PER_FRAME && f > 0) vf3_bios_gd_advance_cycles(&gd, CYCLES_PER_FRAME - (uint64_t)polls * per_poll);
        if (!run(ram, &a, irqa, 0, "vblank handler A") || !run(ram, &b, irqb, 0, "vblank handler B")) return 1;
    }
    /* the reference is the RAM at the entry of the next vblank handler, i.e. before it ran */
    if (getenv("BS_DUMP")) { FILE *d = fopen(getenv("BS_DUMP"), "wb"); if (d) { fwrite(ref.ram + 0x800000u, 1, 0x400000, d); fclose(d); } }
    unsigned bytes = 0, shown = 0;
    for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) {
        if (ram[i] == ref.ram[i]) continue;
        if (shown < 24) { printf("  ram %08x: native %02x, emulator %02x\n", VF3_NATIVE_RAM_BASE + i, ram[i], ref.ram[i]); ++shown; }
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
