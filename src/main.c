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

int main(int argc, char **argv)
{
    const char *capture = NULL, *expect = NULL, *hw = NULL, *ta_out = NULL;
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

    vf3_native_tick_result r;
    vf3_native_tick_run(ram, regs, entry, gbr, &r);
    printf("tick %s: pc %08x, %u blocks, %u readable-port calls, %u unowned calls, %u oob accesses\n",
           r.ok ? "completed" : "FAILED", r.pc, r.steps_budget_used, r.readable_calls, r.unowned_calls, r.oob);
    printf("hardware: %u device reads, %u writes outside RAM, %u TA words\n",
           r.device_reads, r.device_writes, r.ta_words);
    if (!r.ok) printf("  failed at %08x%s\n", r.failed_pc, r.unowned_calls ? " (call into unported code)" : "");
    if (r.unowned_calls) printf("  first unowned entry %08x\n", r.first_unowned);

    int status = r.ok && !r.unowned_calls ? 0 : 1;
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
