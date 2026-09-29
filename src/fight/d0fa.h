#ifndef VF3_FIGHT_D0FA_H
#define VF3_FIGHT_D0FA_H

#include <stdint.h>
#include "fight/poly_classify.h"

uint32_t vf3_d0fa_update(uint32_t slot_offset, uint32_t limit,
                         uint32_t index, uint32_t object,
                         uint32_t state, uint32_t stack,
                         uint32_t saved_pr, const vf3_ram_map *ram);

#endif
