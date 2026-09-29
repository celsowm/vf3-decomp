/* SH-4 0x8C0CC148 FPU transform plus range-reduction helpers. */
#ifndef VF3_FIGHT_CC148_H
#define VF3_FIGHT_CC148_H

#include <stdint.h>

#include "fight/poly_classify.h"

typedef struct {
    uint32_t r[16];
    uint32_t pr, sr, fpscr;
    uint32_t fr[16];
} vf3_cc148_state;

void vf3_cc148_8c0cc148(const vf3_cc148_state *in, vf3_cc148_state *out,
                        const vf3_ram_map *ram);

#endif
