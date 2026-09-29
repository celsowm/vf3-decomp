#ifndef VF3_FIGHT_F9F6DC_H
#define VF3_FIGHT_F9F6DC_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Baseline loop at 0x8C09F6DC, including its local helper calls. */
void vf3_f9f6dc_8c09f6dc(const uint32_t in[37], uint32_t out[37],
                         const vf3_ram_map *ram);

#endif
