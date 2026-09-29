#ifndef VF3_FIGHT_F9F9A8_H
#define VF3_FIGHT_F9F9A8_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Returns 1 for the captured signed-guard return, 0 on RAM failure, and -1
 * for the remaining FPU continuation, which is not ported yet. */
int vf3_f9f9a8_guard(const uint32_t in[37], uint32_t out[37],
                     const vf3_ram_map *ram);

#endif
