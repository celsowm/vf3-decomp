/* cache_wb_stub.c - SH-4 0x8C062E8E (cache_wb_stub), natively.
 *
 * `ocbwb @r4; rts`: operand-cache write-back of the line holding r4.  The
 * cache is not modelled (RAM is always coherent in the port), so the
 * instruction has no architectural effect - every register is left as it
 * was and control returns to the caller.  A near-trivial leaf.
 *
 * See docs/re/native_cache_wb_stub.md. */
#include "cache_wb_stub.h"

#include "aim_math.h"

void vf3_native_cache_wb_stub(vf3_native_aim *a)
{
    (void)a;   /* the write-back has no effect; nothing moves */
}
