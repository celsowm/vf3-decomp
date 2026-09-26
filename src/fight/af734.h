/* vf3 flag-twiddle + FPU pair store — SH-4 0x8C0AF734 (168 B).
 *
 * Top of the af734 cascade (U1 fdivker + U2 fpucb, both nested port calls).
 * Body (FPU ops honour entry FPSCR via fpu_tz.h + fpu_dn_fix):
 *   prologue sts.l pr / frame F = r15-12
 *   r4 = 0x0C29B864; [r0+r14] = r3(entry)
 *   guard-1: r2 = [r13+12]; T = !(r2 & 0x0800) -> L762
 *     r1 = [r13+12] & 0xF7FF -> [r13+12]
 *     guard-2: r2 = [r4+4]; T = !([r4+4] & 0xC0000) ... r3 = [r4];
 *     T = !([r4] & 0xC0000) -> L762
 *     r0 = [r14+30].w + 0x8000 -> [r14+30].w
 *   L762: r3 = [r13+16]; r4 = 0x01000000; T = !(r3 & r4) -> L772
 *     [r13+12] |= 0x04000000
 *   L772: r1 = [r13+12]; T = !(r1 & 0x01000000) -> L7B6 (SKIP, 63/64)
 *   RUN block (1/64): [r13+12] &= ~0x01000000... (see below); spills
 *     fr3a/fr3b ([r14+0x1D04]/[r14+0x1D0C]) to [F+4]/[F]; nested
 *     U2(in_r1=r1, in_r4=0x01000000, in_r5=F+4, in_r6=F, in_r14, in_r15=F,
 *     in_pr, in_sr, in_fpscr, in_fr15) -> ou; fr2 = [F]; fr5 = [r14+0x430];
 *     fr4 = [r14+0x438]; fr3 = [F+4]; fr4 -= fr2; fr5 -= fr3;
 *     [r14+16] = fr5; [r14+24] = fr4
 *   L7B6: r3 = 0x00080000; r4 = [r14]; T = !(r4 & r3) -> L7CC
 *     [r14] &= ~0x00080000... ([r14] &= 0xFFF7FFFF); [r13+12] |= 0x80000000
 *   L7CC: r2 = [r13+12]; [r14+72] = r2; epilogue (pr/r14 restore, rts).
 * Exit: integer regs per path above; fr (SKIP: entry; RUN: fr2/fr3/fr4/fr5
 * chained, fr0/fr1/fr6/fr7 from ou, fr15+ entry); sr T from 7ba; fpscr kept.
 *
 * Validated against extract/analysis/goldens_s6b/f_0c0af734.cases
 * (64 pairs / 64 RAM cases over 13 windows, byte-exact shadow diff).
 */
#ifndef VF3_FIGHT_AF734_H
#define VF3_FIGHT_AF734_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r14, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t sr;
} vf3_af734_out;

void vf3_af734_8c0af734(uint32_t in_r0, uint32_t in_r3, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r13, uint32_t in_r14,
                        uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                        uint32_t in_fpscr, float in_fr0, float in_fr1,
                        float in_fr2, float in_fr3, float in_fr4, float in_fr5,
                        float in_fr6, float in_fr7, float in_fr15,
                        vf3_af734_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_AF734_H */
