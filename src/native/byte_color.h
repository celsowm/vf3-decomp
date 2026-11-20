/* byte_color.h - native port of the two-byte color scale into floats
 * (0x8C0563AC), operating on the `vf3_native_aim` context.
 *
 * See byte_color.c and docs/re/native_byte_color.md. */
#ifndef VF3_NATIVE_BYTE_COLOR_H
#define VF3_NATIVE_BYTE_COLOR_H

#include "aim_math.h"

/* Run 0x8C0563AC.  A self-contained 80 B leaf, call-free and branch-free
 * (straight-line; the only control transfer is the final rts).  It reads
 * three floats through a pointer from the literal pool, scales them by a
 * fourth, unpacks two packed bytes into three byte channels, converts them to
 * floats, scales those by the first three, and writes three floats down a
 * descending run of the output pointer.  The `w` below is FPSCR.PR ? 8 : 4
 * (single/double width).  See docs/re/native_byte_color.md. */
void vf3_native_byte_color(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_BYTE_COLOR_H */
