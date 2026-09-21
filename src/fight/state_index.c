/* fight/state_index.c — per-slot index helper
 *
 * Provenance: 1ST_READ 0x8C0597C2 (FUN_8c0597c2), 16 bytes:
 *   mov.l r14,@-r15              ; save r14
 *   and    r3,r4                 ; idx = r4 & r3
 *   mov.l  <lit>,r2              ; r2 = *(u32*)0x8C059858 (runtime value: state-table base)
 *   shll   r4                    ; idx *= 2
 *   mov    r4,r14
 *   shll2  r14                   ; idx *= 4   (net x20)
 *   add    r2,r14                ; r14 = base + idx*20
 *   mov.l  @r14,r1               ; r1 = *r14    (u32 slot entry head)
 * Runtime probe (M10, 240 frames, fight state): inputs pinned to
 * r13=0x28, r14=5, r4=0 — consistent with a fixed companion struct and
 * idx unmasked. Hottest fn in the fight trace (3.95M records).
 */
#include <stdint.h>

/* The 20-byte stride state table. Its live base pointer is loaded from the
 * literal at 0x8C059858 (a RAM cell written by an init function; exact
 * address depends on stage layout). */
typedef struct {
    uint32_t head;      /* value returned by the helper */
    uint8_t  pad[16];   /* remaining 16 bytes per record — semantic TBD */
} VF3_StateSlot;

/* registers expressed as parameters for traceability:
 *   r4 = caller-requested index, r3 = caller mask, base = live table base */
static inline uint32_t vf3_state_slot_head(const VF3_StateSlot *base,
                                           uint32_t r4, uint32_t r3)
{
    const uint32_t idx = (r4 & r3) * 5;   /* (r4&r3) then x5 -> +20B (shll+shll2) */
    return base[idx].head;
}

uint32_t vf3_state_slot_head_reg(const VF3_StateSlot *base, uint32_t r4,
                                 uint32_t r3)
{
    return vf3_state_slot_head(base, r4, r3);
}
