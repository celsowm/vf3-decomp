/* Observe actual ARM memory accesses and per-instruction execution; never
 * execute or replace driver code.  Time is the enclosing SH-4 scheduler
 * callback, not an exact ARM cycle. */
#include "vf3armtrace.h"
#include "hw/arm7/arm7.h"
#include "hw/aica/aica_if.h"
#include "hw/sh4/sh4_sched.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>

unsigned vf3ArmTracePc;
unsigned vf3ArmHist[VF3_ARM_HIST_N];
unsigned vf3ArmWinActive = 0;

namespace {
FILE *out;
bool histEnabled = false;
bool initialized, truncated;
uint64_t ordinal;
uint64_t gWinStart = 0, gWinEnd = 0;
bool gWinSet = false;

void finish() {
    std::fprintf(stderr, "[vf3armtrace] events=%llu truncated=%u\n",
        (unsigned long long)ordinal, unsigned(truncated));
    if (out && std::fclose(out)) std::abort();
    out = nullptr;
    if (histEnabled) {
        // Dump the window-gated per-instruction execution histogram.
        const char *path = std::getenv("VF3_ARM_HIST");
        FILE *h = path ? std::fopen(path, "wb") : nullptr;
        unsigned long total = 0;
        if (h) {
            for (int i = 0; i < VF3_ARM_HIST_N; i++) {
                unsigned c = vf3ArmHist[i];
                if (!c) continue;
                std::fprintf(h, "%04x %u\n", i << 2, c);
                total += c;
            }
            std::fclose(h);
        }
        std::fprintf(stderr, "[vf3armtrace] hist dump=%s total_insns=%lu\n",
            path ? "yes" : "no", total);
    }
}
void write(const void *p, size_t n) {
    if (std::fwrite(p, 1, n, out) != n) std::abort();
}
} // namespace

void vf3ArmTraceMemory(unsigned addr, unsigned data, unsigned size, bool store) {
    uint64_t cycle = sh4_sched_now64();
    if (!initialized) {
        initialized = true;
        if (const char *path = std::getenv("VF3_ARM_TRACE")) {
            out = std::fopen(path, "wb");
            if (!out) std::abort();
            write("VF3ARM1\0", 8);
            std::atexit(finish);
        }
        const char *hist = std::getenv("VF3_ARM_HIST");
        const char *win = std::getenv("VF3_ARM_WIN");
        if (hist) {
            histEnabled = true;
            if (!out) std::atexit(finish); // dump the histogram even with no mem trace
        }
        if (win) {
            unsigned long long a = 0, b = 0;
            if (std::sscanf(win, "%llu,%llu", &a, &b) == 2 && b > a) {
                gWinStart = a; gWinEnd = b; gWinSet = true;
            }
        }
    }
    if (histEnabled && gWinSet) {
        vf3ArmWinActive = (cycle >= gWinStart && cycle < gWinEnd) ? 1u : 0u;
        /* Headless self-stop: once the scheduler has left the window (plus a
         * margin), exit so atexit(finish) dumps the histogram.  Fires whether
         * or not a memory trace is open. */
        if (cycle > gWinEnd + 4535 * 64)
            std::exit(0);
    }
    if (!out) return;
    addr &= 0x00ffffff;
    // Retain all wave-RAM stores and protocol reads; hardware-register stores.
    if (!store && (addr & 0x1fffff) >= 0x600) return;
    if (addr >= 0x800000 && (!store || addr >= 0x808000)) return;
    if (ordinal >= 2000000) { truncated = true; return; }
    uint64_t seq = ++ordinal;
    unsigned pc = vf3ArmTracePc;
    unsigned opcode = *(const unsigned *)&aica::aica_ram[pc & 0x1ffffc];
    unsigned words[] = { pc, opcode, addr, data, size, unsigned(store) };
    write(&seq, 8); write(&cycle, 8); write(words, sizeof(words));
}
