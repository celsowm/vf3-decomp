/* Oracle-checked mirror of SH-4 0x8C0CBEFC, a per-frame state update. */
#ifndef VF3_FIGHT_CBEFC_H
#define VF3_FIGHT_CBEFC_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

/* State vectors use the port harness order: r0-r15, pr, sr, fpscr, macl,
 * mach, fr0-fr15.  The function writes only architectural outputs. */
void vf3_cbefc_8c0cbefc(const uint32_t in[37], uint32_t out[37],
                        const vf3_ram_map *ram);

#endif
