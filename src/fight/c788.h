#ifndef VF3_FIGHT_C788_H
#define VF3_FIGHT_C788_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* SH-4 0x8C08C788: guarded state update plus RNG and unsigned remainder. */
int vf3_c788_guard(const uint32_t in[37], uint32_t out[37],
                   const vf3_ram_map *ram);

#endif
