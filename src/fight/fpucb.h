/* vf3 FPU callback — SH-4 0x8C09553C (gap unit, U2 of the af734 cascade).
 *
 * Body (all FPU ops honour entry FPSCR via fpu_tz.h + fpu_dn_fix):
 *   spill fr15/pr, frame F = r15-24; [F+8]=r4 [F]=r5 [F+4]=r6
 *   r4 = exts.w [F+8]; [F+12] = r4 (jsr delay slot, pre-call)
 *   jsr U1-0x8C03A6E0(r1,r4,r5,r6,r15=F,sr,fpscr) -> o1  (nested port call)
 *   fr15save = o1.fr0; r4 = [F+12] (jsr delay slot, pre-call)
 *   jsr U1-0x8C03A140(r1=o1.r1,r4,r14,r5=o1.r5,r6=o1.r6,r15=F,
 *                     sr=o1.sr,fpscr) -> o2                   (nested call)
 *   r2 = [F]; fr7 = o2.fr0; fr6 = [r2]; r3 = [F+4];
 *   fr7 = fr6*fr7; fr4 = o2.fr0; fr5 = [r3]; fr0 = fr5;
 *   fr4 = fr5*fr4; fr7 = fmac(fr0,fr15save,fr7); fr15x = fr6*fr15save;
 *   fr5 = fr7; [r2] = fr5; fr4 -= fr15x; [entry r6] = fr4 (pre-rts);
 *   rts (+fr15 round-trip delay).
 * Exit: r0/r1/r4/r5/r6/fr1/fr2/fr3/sr from o2; r2 = in_r5; r3 = in_r6;
 * fr0/fr4/fr5/fr6/fr7/fr15 per above; rest (r7-r15, pr, macl/mach, fpscr)
 * untouched.
 *
 * Validated against extract/analysis/goldens_s8b/f_0c09553c.cases
 * (64 pairs / 64 RAM cases over 1 stack window, byte-exact shadow diff;
 * 3 caller contexts incl. af734-RUN).
 */
#ifndef VF3_FIGHT_FPUCB_H
#define VF3_FIGHT_FPUCB_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7, fr15;
    uint32_t sr;
} vf3_fpucb_out;

void vf3_fpucb_8c09553c(uint32_t in_r1, uint32_t in_r4, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r14, uint32_t in_r15,
                        uint32_t in_pr, uint32_t in_sr, uint32_t in_fpscr,
                        float in_fr15, vf3_fpucb_out *o,
                        const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FPUCB_H */
