/* Nearest-cell scale-map worker at SH-4 0x8C06951A. */
#ifndef VF3_FIGHT_MAPLOOKUP_H
#define VF3_FIGHT_MAPLOOKUP_H

#include <stdint.h>

#include "fight/poly_classify.h"

/* Register vector uses the shared golden order: r0-r15, pr/sr/fpscr/macl/mach,
 * then fr0-fr15. Returns zero for the currently unmodeled ctx==0 and selector
 * 11 auxiliary-call paths; otherwise returns one. */
int vf3_maplookup_8c06951a(const uint32_t in[37], uint32_t out[37],
                           const vf3_ram_map *ram, int *gated);

#endif
