/* mem_move.c - SH-4 0x8C043018 (mem_move), natively.
 *
 * A plain-C transcription of the readable port src/fight/leaf_math.c
 * (`vf3_mem_move_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained integer leaf (call-free, no stack frame): r4 =
 * destination, r5 = source, r6 = byte count.  Copies `count` bytes from src
 * to dst, overlap-safe - forward when dst < src, backward otherwise, a no-op
 * when dst == src.  Leaves r0 = dst and SR.T set.  See
 * docs/re/native_mem_move.md. */
#include "mem_move.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint8_t rd8(vf3_native_aim *a, uint32_t addr)
{ return ((const uint8_t *)a->ram)[addr - a->ram_base]; }
static void wr8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

void vf3_native_mem_move(vf3_native_aim *a)
{
    const uint32_t dst = R(4), src = R(5), count = R(6);
    if (dst != src) {
        if (dst < src) {
            for (uint32_t i = 0; i < count; ++i)
                wr8(a, dst + i, rd8(a, src + i));
        } else {
            for (uint32_t i = count; i-- > 0;)
                wr8(a, dst + i, rd8(a, src + i));
        }
    }
    R(0) = dst;
    a->sr |= 1u;
}
