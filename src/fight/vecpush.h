/* vf3 vecpush — counter-gated vec3-subtract head block (SH-4 0x8C071A76).
 *
 * This function is the head of a large unrolled vertex pipeline (the block
 * spans 0x8C071A76..0x8C071ABC; the routine continues for ~1 KB through the
 * f_8c071aXX chunks and tail-transfers, so it is validated piecewise against
 * an interior oracle point at 0x8C071ABE — see tools/pair_cases.py).
 *
 * Inputs (caller registers / frame):
 *   in_r4  scratch pointer (entry fr0 is spilled to *(r4-4) pre-decrement)
 *   in_r8  loop cursor, bumped by 24 on the main path
 *   in_r9  capacity gate
 *   in_r11 blend-source triple base (also becomes the new r14)
 *   in_r13 destination triple base
 *   in_r14 blend-source triple base (becomes r5)
 *   in_r15 caller frame: [r15]=cursor, [r15+4] saved, [r15+8] saved,
 *          [r15+20] count
 *   in_fr0 value spilled to the scratch slot
 *
 * Behaviour:
 *   r2 = [r15+20]; [r15+8] = r2;
 *   if (!(r2 > r9 signed)) -> VF3_VECPUSH_FULL (out-of-range handler jump
 *       to 0x8C2A1C2A; not modelled, documented only)
 *   [r15] += 24; r8 += 24; r11 += 24; r14 = in_r11;
 *   r5 = in_r14; r6 = in_r11; r4 = in_r13;
 *   dst[0..2] = A[0..2] - B[0..2] with A = in_r14, B = in_r11, dst = in_r13
 *       (stored high-to-low: [r4+8]=f2, [r4+4]=f1, [r4]=f0, leaving r4=dst)
 *
 * Validated 7/7 against paired oracle cases (entry -> 0x8C071ABE):
 * registers, FPU regs and every watched memory word, via
 * extract/analysis/goldens_vpb/f_0c071a76_head.cases.
 */
#ifndef VF3_FIGHT_VECPUSH_H
#define VF3_FIGHT_VECPUSH_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

enum {
    VF3_VECPUSH_MAIN = 0,
    VF3_VECPUSH_FULL = 1
};

typedef struct {
    uint32_t r4, r5, r6, r8, r11, r14;
    float fr[6];
} vf3_vecpush_out;

int vf3_vecpush_sub3_head(uint32_t in_r4, uint32_t in_r8, uint32_t in_r9,
                          uint32_t in_r11, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, float in_fr0,
                          vf3_vecpush_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_VECPUSH_H */
