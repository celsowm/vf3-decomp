/* vf3 FPU min/max vertex ladder + table walk — SH-4 0x8C073FB4.
 *
 * True body runs 0x8C073FB4-0x8C074138 (rts; Ghidra size 350 is truncated)
 * with pool words after 0x8C0740F6; no calls (the bsr words at 0x8C074004+
 * are unreachable pool bytes). Prologue pushes r14/r12 only (no frame);
 * both are restored at exit, so r14/r12/r4/r6 are passthrough-ish and only
 * r0/r1/r3/r5/r7, sr, fr4-fr10 and RAM carry computed state.
 *
 * Shape: fr6/fr8/fr9/fr10 = [r4+0x430/0x438/16/24]; two min/max ladders
 * against pool floats +13.5 (mova #1) / -13.5 (mova #2) with write-back; [r4+0x1890]&36 gate (nonzero
 * exits); r12 = (15&[0x0C29B880])<<1; two outer iterations selecting a
 * vertex-table walk (bound r5=28) over [r4+0x138C] by ([entry]&7):
 *   2 -> min(fr7[i+8]-fr5) loop, acc fr10/fr8;
 *   3 -> min(fr5-fr7[i]) loop, acc fr6/fr9;
 *   0/1 -> min(fr7[i]-fr5) loop, acc fr9/fr6;
 *   >3 -> min(fr5-fr7[i+8]) loop, acc fr8/fr10.
 * (selector 0 short-circuits at 0x8C07405C straight to the next outer
 * iteration; the dispatch ladder only runs for nonzero selectors.)
 * All fsub/fadd honor entry FPSCR via fpu_tz.h + fpu_dn_fix (RM=1/DN=1).
 *
 * Validated against extract/analysis/goldens_73fb4/f_0c073fb4.cases.
 */
#ifndef VF3_FIGHT_FMINMAX_H
#define VF3_FIGHT_FMINMAX_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r3, r5, r7, r15;
    uint32_t fr4, fr5, fr6, fr7, fr8, fr9, fr10;
    uint32_t sr;
} vf3_fminmax_out;

void vf3_fminmax_8c073fb4(uint32_t in_r1, uint32_t in_r3, uint32_t in_r4,
                          uint32_t in_r7, uint32_t in_r12, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr,
                          uint32_t in_sr, uint32_t in_fpscr, float in_fr4,
                          vf3_fminmax_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FMINMAX_H */
