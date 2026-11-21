/* corner_fan.h - native port of the four-corner offset-fan (0x8C03FB10),
 * operating on the `vf3_native_aim` context.
 *
 * See corner_fan.c and docs/re/native_corner_fan.md. */
#ifndef VF3_NATIVE_CORNER_FAN_H
#define VF3_NATIVE_CORNER_FAN_H

#include "aim_math.h"

/* Run 0x8C03FB10.  A self-contained FP leaf (call-free, no tail-transfer).
 * r4 = object (flags word at +0x2C: low 2 bits select the base column A, the
 * next 2 bits the base row B), r5/r6 = output arrays of 4 floats, FR4..FR7 =
 * (a,b,c,d).  A, B come from the flags; each of the 4 table corners (u,v) in
 * 0x0C0EA670 gives
 *     du = u - A, dv = v - B
 *     out5 = obj[+4] + du*(a*d) + dv*(b*c)
 *     out6 = obj[+8] - (a*c)*du + dv*(b*d)
 * in the order of the original: the macs round once, and the du (dv) terms
 * are skipped entirely when du (dv) is zero.  This entry also writes the
 * entry FR14 (a dead push) to sp-4.  See docs/re/native_corner_fan.md. */
void vf3_native_corner_fan(vf3_native_aim *a);

#endif /* VF3_NATIVE_CORNER_FAN_H */
