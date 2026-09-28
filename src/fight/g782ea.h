/* vf3 fight-dispatcher worker - SH-4 0x8C0782EA (4472 B baseline).
 *
 * Threaded-VM dispatcher with a BRAF switch (0x8C078396, 64-arm word
 * table at 0x0C0783B0; 19 arms tripped by the 8 oracle cases). Prologue
 * builds a ~1660 B frame and links r4-r7 into it; the dispatch loop at
 * 0x8C078376 fetches opcode bytes and BRAF-dispatches; the shared
 * epilogue at 0x8C07A758 tears the frame down (r15 += 0x87C, pop
 * pr/r12-r14) and rtses to the caller (out.r15 = in.r15+12).
 *
 * Interrupt footprint (oracle-derived): B-path calls (caller
 * 0x8C0782D0) are hit mid-call by an async exception serviced through
 * the 0x0C00FA00 vector (rte resumes at 0x8C07A5E0); the stub pushes r0/r1
 * onto the game stack and the handler leaves those 8 bytes in the frame
 * work area (0x0C31F020 window). The service routine itself is transparent
 * to this function's prompt exit state - verified 12/12 on full-RAM
 * goldens with the service body skipped - so the port models only the
 * stub pushes, counter-gated at the oracle-observed firing points
 * (7A5DE#7, 07891A#10-if-7A5DE-count<=10, B-path only).
 * Literal pools + BRAF table are baked from the image (verified read-only
 * across captures); pool misses, untripped branch edges (22), unhit BRAF
 * arms (45) and out-of-window traffic gate loud.
 *
 * Validated 8/8 against extract/analysis/goldens_782en_rts/f_0c0782ea.cases
 * (regs + exit RAM, zero out-of-window).
 */
#ifndef VF3_FIGHT_G782EA_H
#define VF3_FIGHT_G782EA_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13;
    uint32_t r14, r15, pr, sr;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t fr8, fr9, fr10, fr11, fr12, fr13, fr14, fr15;
    int gated;
} vf3_g782ea_out;

void vf3_g782ea_8c0782ea(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                          uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                          uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                          uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                          uint32_t in_fpscr,
                          uint32_t in_fr0, uint32_t in_fr1, uint32_t in_fr2,
                          uint32_t in_fr3, uint32_t in_fr4, uint32_t in_fr5,
                          uint32_t in_fr6, uint32_t in_fr7, uint32_t in_fr8,
                          uint32_t in_fr9, uint32_t in_fr10, uint32_t in_fr11,
                          uint32_t in_fr12, uint32_t in_fr13, uint32_t in_fr14,
                          uint32_t in_fr15,
                          vf3_g782ea_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_G782EA_H */
