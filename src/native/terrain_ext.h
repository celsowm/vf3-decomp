/* terrain_ext.h - native port of the terrain "EXTRA" body 0x8C087ACE and its
 * three private helpers (0x8C087A40, 0x8C0876F2, 0x8C087734), operating on
 * the `vf3_native_aim` context.
 *
 * See terrain_ext.c and docs/re/native_terrain_ext.md. */
#ifndef VF3_NATIVE_TERRAIN_EXT_H
#define VF3_NATIVE_TERRAIN_EXT_H

#include "motion_aim.h"

/* Run 0x8C087ACE.  The terrain stage-11 "EXTRA" pass: given a frame of
 * pointer words (r4/r6 = the x/z source, r5 the result, r7 a third pointer,
 * [sp+0] and [sp+4] the remaining pointers) it resolves the height/normal
 * correction that 0x8C068E0E hands to the probe.  Pushes XMTRX, loads the
 * matrix 0x8C087A40 returned, corrects five floats, calls the two helpers and
 * pops the matrix (r4=1).  Returns matching the reference (no value is
 * meaningful; the FR/register/RAM effects are the contract). */
void vf3_native_terrain_ext(vf3_native_aim *a);

#endif /* VF3_NATIVE_TERRAIN_EXT_H */
