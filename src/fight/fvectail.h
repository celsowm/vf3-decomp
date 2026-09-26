/* vf3 fvec epilogue tail — SH-4 0x8C0930D4 (10 B straight line).
 *
 * Decoder-visible body (tools/sh4.py):
 *   fmov.s fr0,@-r4            ; spill entry fr0 (caller scratch, r4 -= 4)
 *   nop ; r15 += 16 ; rts
 *   delay: fmov.s @r15+,fr15   ; restore fr15 from the caller frame, r15 += 4
 *
 * This is the shared tail fvecadd (0x8C0930B6) falls through into. Exit
 * (all 64 oracle cases agree): r4 -= 4, r15 += 20 (0x14), fr15 reloaded
 * from [r15(entry)+16], all other regs/FPU untouched, pr unchanged.
 *
 * Validated against extract/analysis/goldens_s5b/f_0c0930d4.cases
 * (64 pairs / 64 RAM cases, byte-exact shadow diff).
 */
#ifndef VF3_FIGHT_FVECTAIL_H
#define VF3_FIGHT_FVECTAIL_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r4, r15;
    uint32_t fr15;
} vf3_fvectail_out;

void vf3_fvectail_8c0930d4(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_fvectail_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FVECTAIL_H */
