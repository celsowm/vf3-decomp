#ifndef VF3_FIGHT_D9EC_H
#define VF3_FIGHT_D9EC_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Replays the captured identity-XF / three-angle setup path at 0x8C09D9EC.
 * Returns zero for input outside the currently verified path. */
int vf3_d9ec_8c09d9ec(const uint32_t in[37], uint32_t out[37],
                      const uint32_t xf_in[16], uint32_t xf_out[16],
                      const vf3_ram_map *ram);

#endif
