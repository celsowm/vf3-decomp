/* vf3 tail-path setup + gap epilogue — SH-4 0x8C076C00 (path a only).
 *
 * 0x8C076C00 spills r4/r5/r6 + struct bytes to a 160 B frame, zeroes a
 * flag word, and — when [X+0x88]&0x10000000 is set — tail-jumps
 * (jmp @r3, r3 = 0x0C077E12 literal) into gap code that shuffles bytes
 * and runs the shared epilogue (rts at 0x8C077E4A). Call-free throughout.
 * The 0x8C076CD8 branch (path b: 5 static calls + dyn + tail) is a loud
 * gate: the port sets gated=1 and the test fails, so any future golden
 * taking path b trips the tripwire instead of silently passing. All 40
 * fight-scenario goldens take path a (out.r15 = in.r15+12 uniformly).
 *
 * Validated against extract/analysis/goldens_76c00/f_0c076c00.cases.
 */
#ifndef VF3_FIGHT_TAILPATH_H
#define VF3_FIGHT_TAILPATH_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r12, r13, r14, r15, pr, sr;
    int gated;
} vf3_tailpath_out;

void vf3_tailpath_8c076c00(uint32_t in_r4, uint32_t in_r5, uint32_t in_r6,
                           uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                           vf3_tailpath_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_TAILPATH_H */
