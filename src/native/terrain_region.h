#ifndef VF3_NATIVE_TERRAIN_REGION_H
#define VF3_NATIVE_TERRAIN_REGION_H

#include "motion_aim.h"

/* Select the stage-11 terrain region containing (fr4, fr5), 0x8c087a40.
 * Uses the same register, floating-point and flat-memory contract as the guest. */
void vf3_native_terrain_region(vf3_native_aim *a);

#endif
