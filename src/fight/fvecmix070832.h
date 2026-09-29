#ifndef VF3_FIGHT_FVECMIX070832_H
#define VF3_FIGHT_FVECMIX070832_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Execute the 0x8C070832 32-byte fragment through 0x8C070852. */
void vf3_fvecmix070832_8c070832(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram);

#endif
