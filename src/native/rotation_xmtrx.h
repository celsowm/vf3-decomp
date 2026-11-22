/* rotation_xmtrx.h - native port of the rotation-XMTRX leaf 0x8C03C8B0 on the
 * `vf3_native_aim` context.
 *
 * See rotation_xmtrx.c and docs/re/native_rotation_xmtrx.md. */
#ifndef VF3_NATIVE_ROTATION_XMTRX_H
#define VF3_NATIVE_ROTATION_XMTRX_H

#include "motion_aim.h"

/* Run 0x8C03C8B0 (rotation_xmtrx).  Self-contained FP leaf (call-free, no
 * stack).  It builds two FV vectors out of FR4 (sin) and FR5 (cos) --
 * {cos, 0, -sin, 0} and {sin, 0, cos, 0} -- runs each through XMTRX via
 * ftrv (column-major: out = XMTRX * v), lands the results in FR0..FR3 and
 * FR4..FR7, and writes them into XMTRX columns 0 and 2 (XF0..XF3 and
 * XF8..XF11); columns 1 and 3 are untouched.  FR8..FR15 and r15/SR are
 * untouched. */
int vf3_native_rotation_xmtrx(vf3_native_aim *a);

#endif /* VF3_NATIVE_ROTATION_XMTRX_H */
