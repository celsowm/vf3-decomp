/* vf3 byte-table worker — gap unit at 0x8C078044 (~200 B to rts).
 *
 * Interior of baseline f_8c077e5c; called (jsr) from 0x8C0770D2 (dyn site,
 * edges-proven constant target) and 0x8C077706 (loop). Prologue pushes
 * r14/r13 only (leaf, no pr spill). Reads caller stack args [r15+8/12/16],
 * dispatches on table byte [r5+r7+0x1bb0] with three arms (zero-write,
 * masked-write, flag-or), merges r4|=r13 with a dt-r14 early-out, and
 * returns r0 = r6. All /s delay slots honored (incl. the dt at 0x8C0780E2,
 * which sh4full prints as .word).
 *
 * Validated against extract/analysis/goldens_78044/f_0c078044.cases.
 */
#ifndef VF3_FIGHT_G78044_H
#define VF3_FIGHT_G78044_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r3, r4, r6, r7, r15;
    uint32_t sr;
} vf3_g78044_out;

void vf3_g78044_8c078044(uint32_t in_r4, uint32_t in_r5, uint32_t in_r6,
                         uint32_t in_r7, uint32_t in_r13, uint32_t in_r14,
                         uint32_t in_r15, uint32_t in_sr,
                         vf3_g78044_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_G78044_H */
