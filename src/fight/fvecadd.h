/* vf3 fvec3 add block — SH-4 0x8C0930B6 (30 B, select-less straight line).
 *
 * Decoder-visible body (tools/sh4.py):
 *   fmov.s fr0,@-r4            ; spill entry fr0 (caller scratch, r4 -= 4)
 *   r4 = [r15+20]              ; destination triple base
 *   r5 = r15 + 4               ; source-B triple base (frame slot)
 *   a0 = [r4++]; b0 = [r5++]; a1 = [r4++]; b1 = [r5++]; a2 = [r4++]; b2 = [r5++]
 *   fr0 = a0+b0; fr2 = a2+b2; fr1 = a1+b1   (fadd, RM=truncate per fpu_tz.h)
 *   [r4-4] = fr2; [r4-8] = fr1; [r4-12] = fr0   ; store high-to-low
 *   nop ; r15 += 16 ; rts
 *
 * Exit (all 64 oracle cases agree): r4 += 92 (0x5C), r5 = r15(entry)+16+4,
 * r15 += 20 (0x14), fr0-fr2 hold the sums, fr3-fr5 echo the B triple
 * (b0,b1,b2), other regs/FPU untouched, pr unchanged.
 *
 * Validated against extract/analysis/goldens_s2b/f_0c0930b6.cases
 * (64 pairs / 8 RAM cases, byte-exact shadow diff).
 */
#ifndef VF3_FIGHT_FVECADD_H
#define VF3_FIGHT_FVECADD_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r4, r5, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5;
} vf3_fvecadd_out;

void vf3_fvecadd_8c0930b6(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                          vf3_fvecadd_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FVECADD_H */
