/* slot_claim.c - SH-4 0x8C062490: the slot-claim scan, natively.
 *
 * A plain-C transcription of the readable port
 * src/fight/readable/slot_claim.c (`vf3_slot_claim_entry`).  A self-contained
 * leaf (body 0x0C062490..0x0C0624B6), call-free, integer-only (no FP) and
 * no-stack (it tail-returns through r16 and never touches r15), so there are
 * no guest callees to inline and no FPU wrappers.  It operates on
 * `vf3_native_aim`: the flat RAM and the register file.
 *
 * It reads its two parameters from the literal pool:
 *
 *   base  = [0x0c062590]      a pointer to the first slot
 *   count = (int16)[0x0c06258a]   the number of slots (signed)
 *
 * then scans `count` slots at stride 0x18, reading each slot's 16-bit tag at
 * the slot start; the first slot whose low bit is clear is marked by writing
 * 1 (u16) to it and its address is returned in r0.  If none of the slots is
 * free within `count`, r0 = 0 is returned.  The loop is a do-while (no
 * pre-loop guard), so the first slot is always tested even when count <= 0.
 * The mark and the tag read both go through the slot pointer (r4 == r6
 * throughout).
 *
 * Left registers: r0 = the found slot's address (or 0), r3 = the last tag
 * read (masked to 16 bits), r4/r6 = the found slot (or one past the run),
 * r5 = 1, r7 = the scan index, SR.T = 1 on both arms.  r1, r2, r8..r14,
 * r15 and r16 are untouched.
 *
 * See docs/re/native_slot_claim.md. */
#include "slot_claim.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_h16(a, addr); }
static void wr16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{ vf3_aim_set_u16(a, addr, v); }
/* a byte-width store (only the mutation gate turns the mark store into this;
 * the mark is really a 16-bit store) */
static void wr8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

void vf3_native_slot_claim(vf3_native_aim *a, uint32_t sp0)
{
    /* 0x0c062490/492/494: base and count from the literal pool; the counters
     * start at base. */
    const uint32_t base = rd32(a, 0x0c062590u);
    const int32_t count = (int32_t)(int16_t)rd16(a, 0x0c06258au);

    R(7) = 0u;                       /* the scan index */
    R(0) = (uint32_t)count;          /* r0 carries count for the exit test */
    R(4) = base;                     /* the slot pointer (mark side) */
    R(6) = base;                     /* the slot pointer (read side) */
    R(5) = 1u;                       /* the mark value / test mask */

    /* 0x0c06249c..4a0: the scan loop (do-while). */
    for (;;) {
        const uint32_t v = (uint32_t)(int32_t)(int16_t)rd16(a, R(6));
        R(3) = v & 0xffffu;

        /* 0x0c0624a0/4a2: T = ((v & 1) == 0); a clear low bit is free. */
        if ((R(3) & 1u) == 0u) {
            /* 0x0c0624a4/4a6: mark the slot and answer with its address. */
            wr16(a, R(4), (uint16_t)1u);
            R(0) = R(4);
            a->sr = (a->sr & ~1u) | 1u;   /* SR.T = 1 */
            return;
        }

        /* 0x0c0624aa..4b0: next slot; the exit test is (r7 >= count). */
        R(7) += 1u;
        R(4) += 0x18u;
        R(6) += 0x18u;
        if ((int32_t)R(7) < (int32_t)R(0))
            continue;

        /* 0x0c0624b4/4b6: none was free; r0 = 0, SR.T = 1. */
        R(0) = 0u;
        a->sr = (a->sr & ~1u) | 1u;
        return;
    }
}
