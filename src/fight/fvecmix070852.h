#ifndef VF3_FIGHT_FVECMIX070852_H
#define VF3_FIGHT_FVECMIX070852_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Execute the 0x8C070852 34-byte fragment through 0x8C070874. */
void vf3_fvecmix070852_8c070852(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram);

#endif
