#ifndef VF3_FIGHT_F9F9A8_H
#define VF3_FIGHT_F9F9A8_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Returns 1 for modeled paths, 0 on RAM failure, and -1 for unsupported
 * FPSCR modes or a zero conversion denominator. */
int vf3_f9f9a8(const uint32_t in[37], uint32_t out[37],
               const vf3_ram_map *ram);

#endif
