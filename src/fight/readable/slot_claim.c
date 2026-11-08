/* slot_claim.c - SH-4 0x8C062490: scan a table of slots for one whose low bit
 * is clear, mark it, and return its address.
 *
 * A self-contained leaf (body 0x0C062490..0x0C0624B6), call-free, integer-only
 * (no FP), no stack (it tail-returns through r16 and never touches r15).
 *
 * It reads its two parameters from the literal pool:
 *
 *   base  = [0x0c062590]     a pointer to the first slot
 *   count = (int16)[0x0c06258a]   the number of slots (signed)
 *
 * then scans `count` slots at stride 0x18:
 *
 *   for (r7 = 0, r4 = r6 = base; ; ) {
 *       v   = (int16)[r6] & 0xffff        // the slot's 16-bit tag
 *       T   = ((v & 1) == 0)              // a clear low bit is a free slot
 *       if (T) { [r4] = 1 (u16); r0 = r4; return; }   // mark and answer
 *       r7++; r4 += 0x18; r6 += 0x18;     // next slot
 *       T = (r7 >= count); if (!T) continue;
 *       r0 = 0; return;                   // none of the slots was free
 *   }
 *
 * Because the loop is a do-while (there is no pre-loop guard), the first slot
 * is always tested, even when count <= 0.  The mark and the read both happen
 * through the slot pointer (r4 == r6 throughout), so a found slot is written
 * with 1 and its address is left in r0.
 *
 * The registers the body leaves are r0 = the found slot's address (or 0), r3 =
 * the last tag read (masked to 16 bits), r4 and r6 = the found slot (or the
 * slot one past the scanned run), r5 = 1 (the mark value), r7 = the scan index
 * that answered, and SR.T = 1 on both arms (the found test on the found arm,
 * the (r7 >= count) test on the exit arm).  r1, r2, r8..r14, r15 and r16 are
 * untouched.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_slot_claim_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* 0x0c062490/492/494: base and count from the literal pool; the counters
     * start at base. */
    const uint32_t base = vf3_mem_u32(ram, 0x0c062590u);
    const int32_t count =
        (int32_t)(int16_t)vf3_mem_u16(ram, 0x0c06258au);

    R(7) = 0u;                       /* the scan index */
    R(0) = (uint32_t)count;          /* r0 carries count for the exit test */
    R(4) = base;                     /* the slot pointer (mark side) */
    R(6) = base;                     /* the slot pointer (read side) */
    R(5) = 1u;                       /* the mark value / test mask */

    /* 0x0c06249c..4a0: the scan loop (do-while). */
    for (;;) {
        const uint32_t v = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(6));
        R(3) = v & 0xffffu;

        /* 0x0c0624a0/4a2: T = ((v & 1) == 0); a clear low bit is free. */
        if ((R(3) & 1u) == 0u) {
            /* 0x0c0624a4/4a6: mark the slot and answer with its address. */
            vf3_mem_set_u16(ram, R(4), (uint16_t)1u);
            R(0) = R(4);
            R(17) = (R(17) & ~1u) | 1u;   /* SR.T = 1 */
            s->pc = R(16);               /* tail jmp @r16 */
            return ram->oob == 0;
        }

        /* 0x0c0624aa..4b0: next slot; the exit test is (r7 >= count). */
        R(7) += 1u;
        R(4) += 0x18u;
        R(6) += 0x18u;
        if ((int32_t)R(7) < (int32_t)R(0))
            continue;

        /* 0x0c0624b4/4b6: none was free; r0 = 0, SR.T = 1. */
        R(0) = 0u;
        R(17) = (R(17) & ~1u) | 1u;
        s->pc = R(16);
        return ram->oob == 0;
    }
}
