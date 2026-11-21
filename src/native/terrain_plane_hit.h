#ifndef VF3_NATIVE_TERRAIN_PLANE_HIT_H
#define VF3_NATIVE_TERRAIN_PLANE_HIT_H

/* Native port of the terrain plane-height solver 0x8C0692A6. */
#include "motion_aim.h"

/* Height of a terrain triangle's plane at (x, z), plus its normal.  r4 ->
 * triangle record, r5 -> float for the height, r6 -> three floats for the
 * normal, r7 = 4 selects the second vertex triple.  FR4 / FR5 = x / z.
 * See terrain_plane_hit.c. */
void vf3_native_terrain_plane_hit(vf3_native_aim *a);

#endif /* VF3_NATIVE_TERRAIN_PLANE_HIT_H */
