/* strip_light.h - native port of the strip transform-light-emit driver
 * 0x8C0487A0 on the `vf3_native_aim` context.
 *
 * See strip_light.c and docs/re/native_strip_light.md. */
#ifndef VF3_NATIVE_STRIP_LIGHT_H
#define VF3_NATIVE_STRIP_LIGHT_H

#include "motion_aim.h"

/* Run 0x8C0487A0 (strip_light).  A self-contained FP leaf (call-free - the
 * light_vertex / vertex_locate helpers are inlined, no guest dispatch): it
 * reads a strip of vertex records (r4), transforms and lights each through
 * XMTRX (diffuse via FV12 + ambient FR15, specular via FV8 and the power
 * ladder selected by r8) and writes 32-byte store-queue vertex slots at r6,
 * chaining strips through a trailer.  Runs with FPSCR.SZ clear.  Returns 1 on
 * success, 0 on a rejected FPSCR (SZ set) or a malformed specular selector
 * (r8 < 0). */
int vf3_native_strip_light(vf3_native_aim *a);

#endif /* VF3_NATIVE_STRIP_LIGHT_H */
