/* mem_move.h - native port of 0x8C043018 (mem_move), operating on the
 * `vf3_native_aim` context.  See mem_move.c and docs/re/native_mem_move.md. */
#ifndef VF3_NATIVE_MEM_MOVE_H
#define VF3_NATIVE_MEM_MOVE_H

#include "aim_math.h"

/* Run 0x8C043018 (mem_move).  A self-contained integer leaf (call-free, no
 * stack frame): r4 = destination, r5 = source, r6 = byte count.  Copies
 * `count` bytes from src to dst, overlap-safe (forward when dst < src,
 * backward otherwise); a no-op when dst == src.  Leaves r0 = dst and SR.T
 * set.  See docs/re/native_mem_move.md. */
void vf3_native_mem_move(vf3_native_aim *a);

#endif /* VF3_NATIVE_MEM_MOVE_H */
