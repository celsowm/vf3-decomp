/* vf3 fvec mixdown — SH-4 0x8C071668 (44 B) + sibling entry points.
 *
 * Decoder-visible bodies (tools/sh4.py):
 *
 * 0x8C071668 (22 words, "71668"):
 *   fmov.s fr0,@-r4 ; nop ; r9 -= 1 ; cmp/gt r10,r9 (T = r10 > r9 signed)
 *   r12 += 24
 *   bf/s 0x8C07167C
 *   (delay) r14 += 24
 *   taken-path: add #52,r15 ; fr12-15 = pop ; r9-r13 = pop ; rts
 *               (delay) r14 = pop
 *   fall-through (0x8C071676): r3 = [lit 0x8C0716F8] ; jmp @r3 (tail)
 *
 * 0x8C071694 (next head, same file region): mov #88,r0 ; ... (TBD).
 *
 * STATUS: entry->exit oracle replay only. The r9/r10 compare selects the
 * epilogue-pop path vs the tail jump; both are straight-line from the
 * entry snapshot and need no interior point. Register/FPU/memory effects
 * are taken from the golden .cases (register-only goldens exist in
 * goldens_abreg; RAM windows TBD via derive_windows).
 */
#ifndef VF3_FIGHT_FVECMIX_H
#define VF3_FIGHT_FVECMIX_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r4, r9, r12, r14, r15;
    uint32_t pr; /* return-pc, or tail target when the bf/s is not taken */
} vf3_fvecmix_out;

void vf3_fvecmix_8c071668(uint32_t in_r4, uint32_t in_r9, uint32_t in_r10,
                          uint32_t in_r12, uint32_t in_r14, uint32_t in_r15,
                          float in_fr0, vf3_fvecmix_out *o,
                          const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FVECMIX_H */
