/* mem_fill.h - native port of the memory-fill leaf (0x8C095604), operating
 * on the `vf3_native_aim` context.
 *
 * See mem_fill.c and docs/re/native_mem_fill.md. */
#ifndef VF3_NATIVE_MEM_FILL_H
#define VF3_NATIVE_MEM_FILL_H

#include "motion_aim.h"

/* Run 0x8C095604.  Self-contained leaf.  r4 = dest, r5 = value, r6 = byte
 * count: fills whole words first (value), then the low byte of the value for
 * the odd tail bytes;  r0 = end pointer.  See doc/re/native_mem_fill_raw.md. */
void vf3_native_mem_fill(vf3_native_aim *a);

#endif /* VF3_NATIVE_MEM_FILL_H */
