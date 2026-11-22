/* pass_prep.h - native port of 0x8C09DBC0 (pass_prep), operating on the
 * `vf3_native_aim` context.
 *
 * See pass_prep.c and docs/re/native_pass_prep.md. */
#ifndef VF3_NATIVE_PASS_PREP_H
#define VF3_NATIVE_PASS_PREP_H

#include "aim_math.h"

/* Run 0x8C09DBC0 (pass_prep): a format_int-pattern sequencer whose four guest
 * callees are all natively ported.  It takes two arguments - r4 (the source
 * point) and r5 (the destination, where the transformed point is written) -
 * and runs the pass:
 *
 *   push(0)  (matrix push, 0x8C03C4F0, r4 = 0: no load)
 *   invert   (the rigid XMTRX inverse, 0x8C03C5B0, in place)
 *   xform    (transform the point at arg0 through the inverted XMTRX,
 *             0x8C03B450, writing three floats at arg1)
 *   pop      (matrix pop, 0x8C03C4A0, r4 = 1: a tail transfer)
 *
 * The frame is 72 bytes below the saved pr (f = sp0 - 76): arg0 at f,
 * arg1 at f+4.  The return saves pr at sp0-4 and restores r15 = sp0 and
 * pr on the way out, exactly as the readable port does.  The net XMTRX
 * effect is a restore (push then pop), and the transformed point at arg1
 * is inverse(X0) * arg0.  The matrix-stack control block (0x0C19D2E4) is
 * carried in the flat RAM by the native push/pop so the whole round trip is
 * comparable.  See docs/re/native_pass_prep.md. */
void vf3_native_pass_prep(vf3_native_aim *a);

#endif /* VF3_NATIVE_PASS_PREP_H */
