/* vf3 branch-tree classifier — SH-4 0x8C0AFB76 (762 B, integer + FPU tail).
 *
 * Entry is mid-prologue: the 9 register saves (r14/r13-r8/fr15/fr14) at
 * 0x8C0AFB62-B74 already ran, so in_r15 is post-push; the body pushes pr
 * then reserves 28 bytes (frame X = in_r15-32). r14 is repurposed as the
 * struct base (r14 = in_r4 at 0x8C0AFB64); the exit pops restore the
 * saved regs, so r8-r14/fr14/fr15 are passthrough and only r0-r7, sr,
 * fr0-fr7 and RAM carry computed state.
 *
 * Shape: guard ladder on [r14]/[r14+72]/[r5+72] bitfields -> per-path
 * scratch stores in the frame -> clamp section (E4C: r13 = exts([r14+106]
 * - [r14+0x1394]) clamped to [-r6,r6] then [-r4,r4], optional 0x8000 flip)
 * -> conditional FPU section (E82: fr5/fr4 = [r14+16/24] - [r14+0x430/438],
 * nested U2 call jsr 0x0C09553C(r4=r13,r5=X+16,r6=X+12,r15=X), accumulate
 * back into [r14+16]/[r14+24]) -> [r14+30] += r13 -> shared epilogue.
 * All /s delay slots and the jsr/rts delay slots are honored; bf/bt
 * (no /s) have no delay slot per the emulator convention.
 *
 * Validated against extract/analysis/goldens_ab/f_0c0afb76.cases.
 */
#ifndef VF3_FIGHT_AFB76_H
#define VF3_FIGHT_AFB76_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t sr;
} vf3_afb76_out;

void vf3_afb76_8c0afb76(uint32_t in_r0, uint32_t in_r1, uint32_t in_r4,
                        uint32_t in_r5, uint32_t in_r15, uint32_t in_pr,
                        uint32_t in_sr, uint32_t in_fpscr, float in_fr0,
                        float in_fr1, float in_fr2, float in_fr3,
                        float in_fr4, float in_fr5, float in_fr6,
                        float in_fr7, float in_fr14, float in_fr15,
                        vf3_afb76_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_AFB76_H */
