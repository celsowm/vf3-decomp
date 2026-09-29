#ifndef VF3_FIGHT_FVECMIX0706C4_H
#define VF3_FIGHT_FVECMIX0706C4_H

#include <stdint.h>
#include "fight/poly_classify.h"

/* Execute 0x8C0706C4 through its first observed tail transfer. */
int vf3_fvecmix0706c4_8c0706c4(const uint32_t in[37], uint32_t out[37],
                               uint32_t *transfer_pc,
                               const vf3_ram_map *ram);

#endif
