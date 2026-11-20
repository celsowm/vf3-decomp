/* band_probe.h - native port of the band probe (0x8C0B0F28), operating on the
 * `vf3_native_aim` context.  See band_probe.c and docs/re/native_band_probe.md. */
#ifndef VF3_NATIVE_BAND_PROBE_H
#define VF3_NATIVE_BAND_PROBE_H

#include "aim_math.h"

/* Run 0x8C0B0F28.  A point in r4/r5/r6 and a band in the literal pool: the two
 * differences the point makes with its third coordinate, masked and asked
 * whether they are inside the band; the flags go into a word the caller hands
 * over in its own frame.  A self-contained integer leaf that keeps a two-word
 * frame and restores r13 in the delay slot of the return. */
void vf3_native_band_probe(vf3_native_aim *a);

#endif /* VF3_NATIVE_BAND_PROBE_H */
