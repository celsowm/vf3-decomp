/* vf3 fcmp select-store — SH-4 0x8C0C7050 (52 B, flag-gated FPU select).
 *
 * Decoder-visible body (tools/sh4.py):
 *   r7 = [0x0C2D0190]                 ; flag-struct base (literal)
 *   fr6 = fr4
 *   r3 = [r7+28]; tst r3,r3
 *   P1 ([r7+28]==0): fr6 -= fr5; fr4 = fr6; goto store      (fsub delay slot
 *     of bf/s always executes, so fr6 -= fr5 on every path)
 *   r3 = [r7+24]; tst r3,r3
 *   P2 ([r7+24]==0): fr3 = 0; T = (fr5 > 0); fr4 = fr6 (bf/s delay slot,
 *     always executes); fr5 <= 0 -> rts with NO store; fr5 > 0 -> store
 *   P3 ([r7+24]!=0): fr6 = [r6]; fr5 = [r5]; fr5 -= fr6; T = (fr4 > fr5);
 *     fr4 <= fr5 -> fr4 -= fr5 (bt delay slot, always executes); store
 *   store: fmov.s fr4,@r4 ; rts
 *
 * All fsub honour FPSCR.RM=1 (fpu_tz.h); fcmp/gt is exact. Exit: r3/r7/fr3
 * (P2 only)/fr4/fr5 (P3 only)/fr6/sr(T) per path, [r4] stored except P2-low;
 * r4/r5/r6/r14/r15/pr untouched.
 *
 * Validated against extract/analysis/goldens_s5b/f_0c0c7050.cases
 * (64 pairs / 64 RAM cases, byte-exact shadow diff).
 */
#ifndef VF3_FIGHT_FCMPSEL_H
#define VF3_FIGHT_FCMPSEL_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r3, r7;
    uint32_t fr3, fr4, fr5, fr6;
    uint32_t sr;
} vf3_fcmpsel_out;

void vf3_fcmpsel_8c0c7050(uint32_t in_sr, float in_fr3, float in_fr4,
                          float in_fr5, float in_fr6, uint32_t in_r4,
                          uint32_t in_r5, uint32_t in_r6,
                          vf3_fcmpsel_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FCMPSEL_H */
