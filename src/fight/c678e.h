/* vf3 fight-engine worker — SH-4 0x8C0C678E (1772 B body, rts 0x8C0C6E7A).
 *
 * Mid-prologue entry: the r8-r14/fr12-fr15 saves at 0x8C0C6762-6C78 already
 * ran, so in_r15 is post-push; the body pushes pr then reserves 64 bytes
 * (frame X = in_r15-68). r14 stays the struct base throughout; the exit
 * pops restore r8-r14/fr12-fr15/pr, so those outs are modeled as shadow
 * reads (r10 genuinely differs from entry: the caller scratches r10=4
 * after pushing, exit restores the saved 0).
 *
 * Shape: prologue spills + flag stores to the [0x0C2D0190] globals (backed
 * by a tiny local mirror: every read follows an in-function write, and the
 * region sits outside the golden windows) -> 28-iteration FPU loop, each
 * pass calling the 0x0C068E0E scalemap wrapper (selector forced to 15 by
 * the wrapper; inlined here as a register-complete twin of
 * vf3_scalemap_8c068e16 with sp = X-8 and site pr — same RAM writes
 * bit-for-bit, plus the fr1/fr2/fr6/fr7/fr8 and r1/r5/r6 residues the
 * verified port drops but these goldens check) -> integer branch tree (odd samples exit early at 0x693C) ->
 * deep FPU chain (even samples) with nested 0x0C069624 calls (ported as
 * c_9624 with the 0x0C0EAF60 atan ramp baked in c678e_tbl.h) and
 * 0x0C06911C calls (c_6911c: wrapper pushes + 06912A mesh-walk path with
 * OOB mesh words as documented stub constants; zero/0x9180 tails;
 * multi-node loop and immediate-done are loud gates) -> shared FPU
 * tail (0x6E06) -> epilogue.
 *
 * Game FPSCR is RM=1/DN=1: every FPU op goes through fpu_tz.h helpers.
 * bf/bt have no delay slot; bf/s bt/s bra have one (always executes);
 * jsr delay slots always execute (modeled explicitly).
 *
 * Validated 8/8 against extract/analysis/goldens_c678e2/f_0c0c678e.cases
 * (regs + exit RAM, zero out-of-window; 56 skipped).
 */
#ifndef VF3_FIGHT_C678E_H
#define VF3_FIGHT_C678E_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7;
    uint32_t r8, r9, r10, r11, r12, r13, r14, r15;
    uint32_t pr, sr;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t fr8, fr9, fr10, fr11, fr12, fr13, fr14, fr15;
    int gated;
} vf3_c678e_out;

void vf3_c678e_8c0c678e(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                        uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                        uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                        uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                        uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                        uint32_t in_fpscr,
                        float in_fr0, float in_fr1, float in_fr2,
                        float in_fr3, float in_fr4, float in_fr5,
                        float in_fr6, float in_fr7, float in_fr8,
                        float in_fr9, float in_fr10, float in_fr11,
                        float in_fr12, float in_fr13, float in_fr14,
                        float in_fr15, vf3_c678e_out *o,
                        const vf3_ram_map *ram);

#endif /* VF3_FIGHT_C678E_H */
