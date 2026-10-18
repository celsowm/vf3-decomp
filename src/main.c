/* VF3tb source port: host-native fight tick (clean-room reconstruction).
 *
 *   vf3 <tick-capture.bin> [--pair N] [--gbr ADDR] [--expect RAM [--hw RAM]] [--ta-out FILE] [--ticks N]
 *
 * Loads the machine state a fight scheduler tick started from (a tools/tick_capture.py recording
 * made from the retail game) and runs that tick on C code only: the readable ports where they
 * exist, the generated adapters elsewhere. A call into code that nobody owns fails the tick.
 * What the tick produced is the final RAM image and the display-list words it streamed to the
 * Tile Accelerator; --expect compares the RAM with a reference image (a raw 16 MiB RAM dump, or
 * the reference oracle's dump with its register header; --hw is the RAM the real machine
 * ended with, to tell the reference's own flush-to-zero slips from real differences) and
 * --ta-out writes the TA words.
 *
 * Everything here is written from our own reverse-engineering notes; no Sega/NEC library
 * code is used. The game itself (main loop, scene changes) is not reconstructed yet:
 * docs/re/plan_native_slice.md has the plan.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "sys/gdrom_hle.h"
#include "sys/hal.h"

#define DEFAULT_GBR 0x0C16B880u         /* the fight tasks' global-state block, see tick_mixed.c */
#define ORACLE_HEADER_BYTES (54u * 4u)
#define MAX_REPORTED_RUNS 12u

/* A raw 16 MiB RAM image, or the reference oracle's dump (registers first). malloc'd. */
static uint8_t *load_ram_image(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "vf3: cannot open %s\n", path); return NULL; }
    fseek(f, 0, SEEK_END);
    const long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    const long skip = size == (long)(VF3_NATIVE_RAM_LEN + ORACLE_HEADER_BYTES) ? (long)ORACLE_HEADER_BYTES : 0;
    if (size - skip != (long)VF3_NATIVE_RAM_LEN) {
        fprintf(stderr, "vf3: %s is neither a RAM image nor an oracle dump\n", path);
        fclose(f);
        return NULL;
    }
    uint8_t *image = malloc(VF3_NATIVE_RAM_LEN);
    fseek(f, skip, SEEK_SET);
    if (image && fread(image, 1, VF3_NATIVE_RAM_LEN, f) != VF3_NATIVE_RAM_LEN) { free(image); image = NULL; }
    fclose(f);
    return image;
}

/* Bytes where `ram` differs from `ref`. The reference oracle flushes denormals differently from
 * the hardware in a handful of stores; where the native byte equals the hardware image it is
 * the reference that is off, so it is counted apart (`hw` may be NULL). */
static int compare_ram(const uint8_t *ram, const char *path, const char *hw_path)
{
    uint8_t *ref = load_ram_image(path);
    uint8_t *hw = hw_path ? load_ram_image(hw_path) : NULL;
    if (!ref || (hw_path && !hw)) { free(ref); free(hw); return -1; }

    unsigned bytes = 0, runs = 0, quirks = 0;
    uint32_t start = 0, last = 0;
    int open = 0;
    for (uint32_t i = 0; i <= VF3_NATIVE_RAM_LEN; ++i) {
        int differs = i < VF3_NATIVE_RAM_LEN && ram[i] != ref[i];
        if (differs && hw && ram[i] == hw[i]) { ++quirks; differs = 0; }
        if (differs) {
            ++bytes;
            if (!open) { start = i; open = 1; }
            else if (i - last > 16) {
                if (runs++ < MAX_REPORTED_RUNS) printf("  ram diff %08x..%08x\n", VF3_NATIVE_RAM_BASE + start, VF3_NATIVE_RAM_BASE + last);
                start = i;
            }
            last = i;
        }
    }
    if (open && runs++ < MAX_REPORTED_RUNS) printf("  ram diff %08x..%08x\n", VF3_NATIVE_RAM_BASE + start, VF3_NATIVE_RAM_BASE + last);
    printf("ram vs %s: %u bytes differ in %u runs", path, bytes, runs);
    if (hw) printf(" (%u more are the reference's, native equals hardware)", quirks);
    printf("\n");
    free(ref);
    free(hw);
    return (int)bytes;
}

/* 16 hex words of the REIOS command state (tools/watch GD log "S" rows), as vf3_aica_stub_adapter reads them */
static int load_gd_words(vf3_gdrom *gd, const char *path)
{
    FILE *f = fopen(path, "r");
    unsigned w[16];
    int n = 0;
    if (!f) return 0;
    while (n < 16 && fscanf(f, "%x", &w[n]) == 1) ++n;
    fclose(f);
    if (n != 16) return 0;
    vf3_gd_state *st = &gd->st;
    st->last_request_id = w[0]; st->next_request_id = w[1]; st->status = (int32_t)w[2]; st->command = w[3];
    for (int i = 0; i < 4; ++i) { st->params[i] = w[4 + i]; st->result[i] = w[8 + i]; }
    st->cur_sector = w[12]; st->multi_read_sector = w[13]; st->multi_read_offset = w[14]; st->multi_read_count = w[15];
    st->multi_read_total = w[15];
    return 1;
}

int main(int argc, char **argv)
{
    const char *capture = NULL, *expect = NULL, *hw = NULL, *ta_out = NULL, *gdi_path = NULL, *gd_state = NULL;
    int vs_exit = 0;
    unsigned pair = 0, ticks = 1;
    uint32_t gbr = DEFAULT_GBR, entry = VF3_NATIVE_SCHED_ENTRY;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--entry") && i + 1 < argc) { entry = (uint32_t)strtoul(argv[++i], NULL, 0); continue; }
        if (!strcmp(argv[i], "--pair") && i + 1 < argc) pair = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--ticks") && i + 1 < argc) ticks = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--gbr") && i + 1 < argc) gbr = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--expect") && i + 1 < argc) expect = argv[++i];
        else if (!strcmp(argv[i], "--hw") && i + 1 < argc) hw = argv[++i];
        else if (!strcmp(argv[i], "--ta-out") && i + 1 < argc) ta_out = argv[++i];
        else if (!strcmp(argv[i], "--vs-exit")) vs_exit = 1;
        else if (!strcmp(argv[i], "--gdi") && i + 1 < argc) gdi_path = argv[++i];
        else if (!strcmp(argv[i], "--gd-state") && i + 1 < argc) gd_state = argv[++i];
        else if (argv[i][0] != '-' && !capture) capture = argv[i];
        else { capture = NULL; break; }
    }
    if (!capture) {
        fprintf(stderr, "usage: vf3 <tick-capture.bin> [--pair N] [--entry ADDR] [--gbr ADDR] [--expect RAM [--hw RAM]] [--ta-out FILE]\n");
        return 2;
    }

    uint32_t regs[37];
    uint8_t *ram;
    hal_log("vf3: loading tick state\n");
    if (!vf3_native_load_snapshot(capture, pair, regs, &ram)) {
        fprintf(stderr, "vf3: no entry state %u in %s\n", pair, capture);
        return 2;
    }

    vf3_gdi gdi;
    vf3_gdrom gd;
    if (gdi_path) {
        if (vf3_gdi_open(&gdi, gdi_path) != 0) { fprintf(stderr, "vf3: cannot open %s\n", gdi_path); return 2; }
        vf3_gd_init(&gd, &gdi, NULL, NULL);
        if (gd_state && !load_gd_words(&gd, gd_state)) { fprintf(stderr, "vf3: bad GD state %s\n", gd_state); return 2; }
        vf3_native_attach_gdrom(&gd);
    }

    vf3_native_tick_result r;
    vf3_native_tick_run(ram, regs, entry, gbr, &r);
    if (gdi_path) printf("bios syscalls served: %u\n", r.bios_calls);
    printf("tick %s: pc %08x, %u blocks, %u readable-port calls, %u unowned calls, %u oob accesses\n",
           r.ok ? "completed" : "FAILED", r.pc, r.steps_budget_used, r.readable_calls, r.unowned_calls, r.oob);
    printf("hardware: %u device reads, %u writes outside RAM, %u TA words\n",
           r.device_reads, r.device_writes, r.ta_words);
    if (!r.ok) printf("  failed at %08x%s\n", r.failed_pc, r.unowned_calls ? " (call into unported code)" : "");
    if (r.unowned_calls) printf("  first unowned entry %08x\n", r.first_unowned);

    int status = r.ok && !r.unowned_calls ? 0 : 1;
    if (vs_exit) {
        /* the recorded exit is the reference: every byte the native run left different is a finding */
        uint8_t *ref;
        uint32_t xregs[37] = { 0 };
        if (!vf3_native_load_exit(capture, pair, xregs, &ref)) { fprintf(stderr, "vf3: no exit state in %s\n", capture); status = 1; }
        else {
            unsigned bytes = 0, clusters = 0;
            uint32_t last = 0;
            for (uint32_t i = 0; i < VF3_NATIVE_RAM_LEN; ++i) {
                if (ram[i] == ref[i]) continue;
                if (bytes++ < 16) printf("  ram %08x: native %02x, recorded %02x\n", VF3_NATIVE_RAM_BASE + i, ram[i], ref[i]);
                if (!(i - last < 4096)) ++clusters;
                last = i;
            }
            if (clusters) printf("%u 4 KiB-separated difference clusters\n", clusters);
            printf("ram vs recorded exit: %u bytes differ; exit pc native %08x, recorded %08x\n", bytes, r.pc, xregs[16]);
            if (bytes) status = 1;
            free(ref);
        }
    }
    if (expect && compare_ram(ram, expect, hw) != 0) status = 1;
    if (ta_out) {
        FILE *f = fopen(ta_out, "wb");
        if (!f || fwrite(r.ta, 4, r.ta_words, f) != r.ta_words) { fprintf(stderr, "vf3: cannot write %s\n", ta_out); status = 1; }
        if (f) fclose(f);
    }
    /* More ticks run back to back on the RAM the last one left, from the same entry registers: no
     * interrupts or main-loop code in between, so this only shows whether the readable ports and the
     * call-target table keep holding on state the capture never saw. There is no reference for it. */
    for (unsigned t = 2; t <= ticks && status == 0; ++t) {
        vf3_native_tick_run(ram, regs, entry, gbr, &r);
        printf("tick %u %s: pc %08x, %u blocks, %u readable-port calls, %u unowned calls, %u oob accesses\n", t,
               r.ok ? "completed" : "FAILED", r.pc, r.steps_budget_used, r.readable_calls, r.unowned_calls, r.oob);
        if (!r.ok || r.unowned_calls) {
            printf("  failed at %08x, first unowned entry %08x\n", r.failed_pc, r.first_unowned);
            status = 1;
        }
    }
    free(ram);
    return status;
}
