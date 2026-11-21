#ifndef VF3_NATIVE_COLOR_UNPACK_H
#define VF3_NATIVE_COLOR_UNPACK_H

/* Native port of the three-halfword colour unpack 0x8C0562E0. */
#include "motion_aim.h"

/* Unpack three halfword-packed byte triples into scaled floats.  r4 -> the
 * record; out: r4 += 10, r1 = the last store address, results in FR0..FR2,
 * the scale in FR4..FR7.  The single GBR write needs a->gbr set.  See
 * color_unpack.c. */
void vf3_native_color_unpack(vf3_native_aim *a);

#endif /* VF3_NATIVE_COLOR_UNPACK_H */
