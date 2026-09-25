/* scalemap.h — warping scale-map sampler, SH-4 0x8C068E16. */
#ifndef VF3_FIGHT_SCALEMAP_H
#define VF3_FIGHT_SCALEMAP_H

#include <stdint.h>

#include "fight/poly_classify.h"

/* selector = entry r13 (masked in-function by [0x0C29B880]), sp = entry r15,
 * pr = entry pr (stored by the prologue); ctx is read from [0x0C1B9610].
 * The port mirrors the original's stack writes, so the replay's RAM-shadow
 * diff covers them. Returns fr0. */
float vf3_scalemap_8c068e16(uint32_t selector_in, uint32_t sp, uint32_t pr,
                            float fr4, float fr5, const vf3_ram_map *ram);

uint32_t vf3_scalemap_f32bits(float f);

#endif /* VF3_FIGHT_SCALEMAP_H */
