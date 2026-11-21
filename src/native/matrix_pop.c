/* matrix_pop.c - SH-4 0x8C03C4A0 matrix_pop, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_lib.c
 * (`vf3_matrix_pop_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no FPU math).  It drops
 * r4 matrices (at least one, never below an empty stack) and loads the new
 * top into XMTRX:
 *
 *   - the control block is at 0x0C19D2E4: {int16 count, int16 limit,
 *     u32 base, u32 top} - base at +4, top at +8;
 *   - `drop` = r4 if positive else 1;  new_count = count - drop if the stack
 *     has enough, else 0;
 *   - addr = base + new_count*64;  the count is rewritten to new_count; the
 *     top pointer is only rewritten (to addr) while new_count < limit;
 *   - XMTRX is loaded from addr;  r0 = (count >= drop), r2 = limit,
 *     r3 = MATRIX_STACK_CTL, r4 = new_count<<6, r6 = new_count,
 *     r7 = addr + 64;  SR.T = (new_count >= limit).
 *
 * No FPU, no FR, no stack frame.  See docs/re/native_matrix_pop.md. */
#include "matrix_pop.h"

#include "aim_math.h"

#define R(n) (a->r[(n)])

#define MATRIX_WORDS 16
#define MATRIX_BYTES 64u
#define MATRIX_STACK_CTL 0x0C19D2E4u

void vf3_native_matrix_pop(vf3_native_aim *a)
{
    const int32_t drop = (int32_t)R(4) > 0 ? (int32_t)R(4) : 1;
    const uint32_t ctl = vf3_aim_u32(a, MATRIX_STACK_CTL);
    const int32_t count = (int16_t)(uint16_t)(ctl & 0xFFFFu);
    const int32_t limit = (int16_t)(uint16_t)(ctl >> 16);
    const uint32_t base = vf3_aim_u32(a, MATRIX_STACK_CTL + 4u);

    const int enough = count >= drop;
    const int32_t new_count = enough ? count - drop : 0;
    const uint32_t addr = base + ((uint32_t)new_count << 6);
    vf3_aim_set_u16(a, MATRIX_STACK_CTL, (uint16_t)((uint32_t)new_count & 0xFFFFu));
    if (new_count < limit) vf3_aim_set_u32(a, MATRIX_STACK_CTL + 8u, addr);

    for (int i = 0; i < MATRIX_WORDS; ++i)
        a->xm[i] = vf3_aim_fbits(vf3_aim_u32(a, addr + 4u * (uint32_t)i));

    R(0) = (uint32_t)enough;
    R(2) = (uint32_t)limit;
    R(3) = MATRIX_STACK_CTL;
    R(4) = (uint32_t)new_count << 6;
    R(6) = (uint32_t)new_count;
    R(7) = addr + MATRIX_BYTES;
    a->sr = (a->sr & ~1u) | (uint32_t)(new_count >= limit);
}
