/* Research observer only. PC is assigned by the x64 ARM compiler before
 * each memory instruction, including interpreter fallback instructions.
 *
 * Two research streams, both gated to a scheduler-cycle window so a headless
 * run can capture just the melody:
 *   - vf3ArmTraceMemory : per memory-access (load+store) records (VF3ARM1),
 *     PC-attributed, written to VF3_ARM_TRACE.
 *   - vf3ArmHist        : per-instruction execution histogram, window-gated,
 *     written to VF3_ARM_HIST at exit.  The recompiler emits an increment of
 *     hist[pc>>2] for every executed instruction when vf3ArmWinActive is set.
 */
#pragma once
extern unsigned vf3ArmTracePc;
void vf3ArmTraceMemory(unsigned addr, unsigned data, unsigned size, bool store);

/* Per-instruction execution histogram (window-gated).  Sized to hold the
 * 64 KiB ARM firmware as ~16k words, rounded up to a power of two. */
constexpr int VF3_ARM_HIST_N = 1 << 16;
extern unsigned vf3ArmHist[VF3_ARM_HIST_N];
extern unsigned vf3ArmWinActive;
