/* vf3 table-walk worker — gap unit at 0x8C077E4E (~550 B to rts).
 *
 * Interior of baseline f_8c076c00; called (bsr) from 0x8C0774AE every
 * 076C00 invocation. Prologue pushes r14-r8 + pr + 8 frame bytes; branch
 * tree over struct bytes/tables converging at 0x8C077FE6 (bra 0x8C078024,
 * delay mov #0,r0) into the shared epilogue (rts at 0x8C078034); the
 * 0x8C078022 entry sets r0 = 1. The single nested call (bsr 0x8C078110
 * at 0x8C077FCE, stack args) is a loud gate: the port sets gated=1 and
 * the test fails, so any golden reaching it trips the tripwire.
 *
 * Validated against extract/analysis/goldens_cascade/f_0c077e4e.cases.
 */
#ifndef VF3_FIGHT_G77E4E_H
#define VF3_FIGHT_G77E4E_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13;
    uint32_t r14, r15, pr, sr;
    int gated;
} vf3_g77e4e_out;

void vf3_g77e4e_8c077e4e(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                         uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                         uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                         uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                         uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                         uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                         vf3_g77e4e_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_G77E4E_H */
