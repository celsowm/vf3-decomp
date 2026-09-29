/* SH-4 0x8C09F354 in-place 18-vector helper. */
#ifndef VF3_FIGHT_F9F354_H
#define VF3_FIGHT_F9F354_H

#include <stdint.h>
#include "fight/poly_classify.h"

int vf3_f9f354(const uint32_t in[37], uint32_t out[37],
               const vf3_ram_map *ram);

#endif
