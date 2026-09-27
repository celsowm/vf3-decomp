/* vf3 fight-engine worker — SH-4 0x8C076C00 (4138 B baseline).
 *
 * Prologue spills r4/r5/r6 + struct bytes to a 160 B frame; path (a)
 * (flag clear) zeroes words and tail-jumps (jmp @r3 = 0x0C077E12) into
 * gap code; path (b) runs a large branch tree with nested calls and
 * converges on the same shared epilogue (rts at 0x8C077E4A,
 * out.r15 = in.r15+12). Nested oracle-verified ports: g78044 at the
 * 0x8C0770D2 dyn site (edges-proven constant target 0x8C078044) and the
 * 0x8C077706 loop, g77e4e at 0x8C0774AE (r4 = r12 delay modelled;
 * g77e4e preserves r4/r7, returned to the caller). The 0x0C0F3A88
 * pointer table (076EB4/076EFC sites) is baked from the image (words
 * 0..15 verified); indices beyond the baked slice are a loud gate.
 * Never/rare-fired callees (0x8C07825E/0x8C07829A/0x8C0781BA/0x8C078170
 * sites, g77e4e's 0x8C078110 site, data-block 0x8C077ED4) are loud gates.
 *
 * Validated 8/8 against extract/analysis/goldens_cascade/f_0c076c00.cases
 * (regs + exit RAM, zero out-of-window).
 */
#ifndef VF3_FIGHT_F076C00_H
#define VF3_FIGHT_F076C00_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13;
    uint32_t r14, r15, pr, sr;
    int gated;
} vf3_f076c00_out;

void vf3_f076c00_8c076c00(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                          uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                          uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                          uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                          vf3_f076c00_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_F076C00_H */
