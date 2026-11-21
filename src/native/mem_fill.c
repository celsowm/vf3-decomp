/* mem_fill.c - SH-4 0x8C095604 mem_fill, natively.
 *
 * A plain-C transcription of the readable port src/fight/mem_fill.c
 * (`vf3_mem_fill_entry`) onto `vf3_native_aim`.  A call-free leaf (the
 * readable version reaches the DIV_S32 compiler-runtime helper for the word
 * count; div-by-4 truncates, so `length / 4` in C is exactly that).
 *
 *   r4 = destination, r5 = value, r6 = byte count  ->  r0 = end pointer
 *
 * The count is split into `length / 4` whole words and `length & 3` tail
 * bytes; the words store r5 as a whole, the tail bytes store its low byte.
 *
 * Contract (matching the readable port): r0 = the end pointer; r4 = the word
 * count (== length/4) when there is no tail, else the tail count; r6 = the
 * end pointer when there is a tail, unchanged otherwise; r7 = the end of the
 * word region; SR.T is set.  r14 is saved/restored, r15 is restored (the
 * readable's two dead stack writes at sp-4/sp-8 are reproduced).
 *
 * See docs/re/native_mem_fill.md. */
#include "mem_fill.h"

#include "aim_math.h"

#define R(n) (a->r[(n)])

#define SR_T 1u
#define DIV_S32_LITERAL 0x0C042C20u

void vf3_native_mem_fill(vf3_native_aim *a)
{
    const uint32_t entry_sp = R(15), entry_pr = a->pr, saved_r14 = R(14);
    const uint32_t value = R(5), length = R(6);
    const uint32_t saved_r2 = R(2), saved_r3 = R(3);

    /* the readable port's call frame, and the nested divide helper's own
       dead stack words - all four are visible in RAM */
    vf3_aim_set_u32(a, entry_sp - 4u, saved_r14);
    vf3_aim_set_u32(a, entry_sp - 8u, entry_pr);
    vf3_aim_set_u32(a, entry_sp - 12u, saved_r2);      /* helper push r2 */
    vf3_aim_set_u32(a, entry_sp - 16u, DIV_S32_LITERAL); /* helper push r3 */

    /* inlined DIV_S32(length, 4): signed quotient, truncating;  r1 = r0 = q */
    const int32_t words = (int32_t)length / 4;
    R(0) = words;
    R(1) = words;
    R(3) = DIV_S32_LITERAL;

    uint32_t dest = R(4), done = 0;
    for (int32_t i = 0; i < words; ++i) {
        vf3_aim_set_u32(a, dest, value);
        dest += 4;
        ++done;
    }
    R(4) = done;
    R(7) = dest;

    const uint32_t tail = length & 3u;
    uint32_t end = dest;
    if (tail != 0) {
        for (uint32_t i = 0; i < tail; ++i)
            vf3_aim_set_u8(a, end++, (uint8_t)value);
        R(4) = tail;
        R(6) = end;
    }
    R(0) = end;
    R(14) = saved_r14;
    a->sr |= SR_T;
    a->pr = entry_pr;
}
