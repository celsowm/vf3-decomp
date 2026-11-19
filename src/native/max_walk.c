/* max_walk.c - SH-4 0x8C061910: the four-list gated max walk, natively.
 *
 * A plain-C transcription of the readable port src/fight/readable/max_walk.c
 * (`vf3_max_walk_entry`).  The body is a self-contained leaf (body
 * 0x0C061910..0x0C061994, 136 B), call-free and integer-only (no FP, no gbr,
 * no fipr), so the native port is a direct reflection of the readable logic
 * with no guest callees to inline and no FPU wrappers to worry about.  It
 * operates on `vf3_native_aim`: the flat RAM (every guest address resolves
 * through `ram_base`) and the register file.
 *
 * It reads the fight structure's address from the literal pool at 0x0c061a0c,
 * searches four linked lists and writes two signed maxima out:
 *
 *   [r4] = r7  = max of (list A at struct+0x08, ungated) over [node+16],
 *                then    (list B at struct+0x00, gated)   over [node+16]
 *   [r5] = r14 = max of (list C at struct+0x1c, ungated) over [node+16],
 *                then    (list D at struct+0x14, gated)   over [node+16]
 *
 * A node is a 20-byte record: u16 gate at +0, u32 next at +8, u32 value at
 * +16.  A "gated" list only lets a node's value compete for the max when
 * (node.gate & 4) == 0.  The two maxima start at 0 (r14 is zeroed on entry,
 * and r7 starts from that r14).
 *
 * The guest's stack convention is part of what the harness compares: it
 * pushes r14, r13, r12 (entry r15 = SP0), allocates a 4-byte scratch slot at
 * SP0-16 that briefly holds struct+0x14 on the way to list D, and pops
 * r12/r13/r14 back at the tail, so r15 is net back at SP0 and the three saved
 * registers are restored to their entry values.  The registers the body
 * leaves are r0 = 0, r1 = the last gated node's value [node+16] read, r2 =
 * the last node's gate halfword (low 16 bits), r6 = 0 (the walk's
 * terminator), r7 = the first max, and SR's T bit = 1 (the walk-exit test
 * (r6==0) is the last comparison).
 *
 * See docs/re/native_max_walk.md. */
#include "max_walk.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static uint32_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, addr) & 0xFFFFu; }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ vf3_aim_set_u32(a, addr, v); }

void vf3_native_max_walk(vf3_native_aim *a, uint32_t sp0)
{
    const uint32_t r4i = R(4);
    const uint32_t r5i = R(5);
    const uint32_t r12i = R(12);
    const uint32_t r13i = R(13);
    const uint32_t r14i = R(14);

    /* 0x0c061910/914/916: push r14, r13, r12. */
    wr32(a, sp0 - 4u, r14i);
    wr32(a, sp0 - 8u, r13i);
    wr32(a, sp0 - 12u, r12i);

    /* 0x0c061918: the fight structure's address from the pool. */
    const uint32_t st = rd32(a, 0x0c061a0cu);

    /* r14 = 0 (0x0c061912); both maxima start at 0.  r1 and r2 hold their
     * entry values until a loop overwrites them (r1 only on a gated pass,
     * r2 only when a non-empty list runs). */
    uint32_t r7 = 0;
    uint32_t r14 = 0;
    uint32_t r1 = R(1), r2 = R(2), r6;
    const uint32_t r13 = 4u;            /* the gate mask, set at 0x0c061936 */

    /* 0x0c06191c..931: list A (st+8), ungated.  r7 = max over [node+16]. */
    r6 = rd32(a, st + 8u);
    while (r6 != 0) {
        r2 = rd32(a, r6 + 16u);
        if ((int32_t)r2 > (int32_t)r7)
            r7 = r2;
        r6 = rd32(a, r6 + 8u);
    }

    /* 0x0c061932..94f: list B (st), gated by (node.gate & 4) == 0. */
    r6 = rd32(a, st);
    while (r6 != 0) {
        r2 = rd16(a, r6);
        if ((r2 & r13) == 0) {
            r1 = rd32(a, r6 + 16u);
            if ((int32_t)r1 > (int32_t)r7)
                r7 = r1;
        }
        r6 = rd32(a, r6 + 8u);
    }

    /* 0x0c061950..969: list C (st+0x1c), ungated.  r14 = max over [node+16].
     * The scratch slot at SP0-16 holds st+0x14 on the way (0x0c061954). */
    wr32(a, sp0 - 16u, st + 0x14u);
    r6 = rd32(a, st + 0x1cu);
    while (r6 != 0) {
        r2 = rd32(a, r6 + 16u);
        if ((int32_t)r2 > (int32_t)r14)
            r14 = r2;
        r6 = rd32(a, r6 + 8u);
    }

    /* 0x0c06196a..987: list D (list at st+0x14), gated. */
    r6 = rd32(a, st + 0x14u);
    while (r6 != 0) {
        r2 = rd16(a, r6);
        if ((r2 & r13) == 0) {
            r1 = rd32(a, r6 + 16u);
            if ((int32_t)r1 > (int32_t)r14)
                r14 = r1;
        }
        r6 = rd32(a, r6 + 8u);
    }

    /* 0x0c061988/98c: write the two maxima.  0x0c06198a: r0 = 0. */
    wr32(a, r4i, r7);
    wr32(a, r5i, r14);

    /* 0x0c061990..994: pop r12, r13, r14; r15 returns to SP0. */
    R(0) = 0u;
    R(1) = r1;
    R(2) = r2;
    R(6) = 0u;
    R(7) = r7;
    R(12) = r12i;
    R(13) = r13i;
    R(14) = r14i;
    R(15) = sp0;
    a->sr = (a->sr & ~1u) | 1u;         /* SR.T = 1: the walk-exit test */
}
