/* max_walk.c - SH-4 0x8C061910: the four-list gated max walk.
 *
 * A self-contained leaf (body 0x0C061910..0x0C061994), call-free, integer-only
 * (no FP at all).  It reads the fight structure's pointer from the literal
 * pool at 0x0c061a0c, searches four linked lists, and writes two maxima out:
 *
 *   [r4] = r7  = max of (list A  at struct+0x08, ungated)  over [node+16],
 *                    then (list B at struct+0x00, gated)    over [node+16]
 *   [r5] = r14 = max of (list C at struct+0x1c, ungated)  over [node+16],
 *                    then (list D at struct+0x14, gated)    over [node+16]
 *
 * A node is a 20-byte record: u16 gate at +0, u32 next at +8, u32 value at
 * +16.  A "gated" list only lets a node's value compete for the max when
 * (node.gate & 4) == 0.  The two maxima start at 0 (r14 is zeroed on entry,
 * and r7 starts from that r14).
 *
 * The guest's stack conventions are what the harness compares: it pushes r14,
 * r13, r12 (entry r15 = SP0), allocates a 4-byte scratch slot at SP0-16 that
 * briefly holds struct+0x14, and pops r12/r13/r14 back at the end, so r15 is
 * net back at SP0 and r12/r13/r14 are restored to their entry values.  The
 * registers the body leaves are r0 = 0, r1 = the last gated node's value
 * [node+16] read, r2 = the last node's gate halfword (low 16 bits), r6 = 0
 * (the walk's terminator), r7 = the first max, and SR's T bit = 1 (the
 * walk-exit test (r6==0) is the last comparison).
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static inline uint32_t r16_gate(const vf3_ram_map *ram, uint32_t node)
{
    /* 0x0c06193a/972: mov.w @r6,r2 -> sign extend to 32, then & 0xffff. */
    return (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, node) & 0xffffu;
}

int vf3_max_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15);
    const uint32_t r4i = R(4);
    const uint32_t r5i = R(5);
    const uint32_t r12i = R(12);
    const uint32_t r13i = R(13);
    const uint32_t r14i = R(14);

    /* 0x0c061910/914/916: push r14, r13, r12. */
    vf3_mem_set_u32(ram, sp0 - 4u, r14i);
    vf3_mem_set_u32(ram, sp0 - 8u, r13i);
    vf3_mem_set_u32(ram, sp0 - 12u, r12i);

    /* 0x0c061918: the fight structure's address from the pool. */
    const uint32_t st = vf3_mem_u32(ram, 0x0c061a0cu);

    /* r14 = 0 (0x0c061912); both maxima start at 0.  r1 and r2 hold their
     * entry values until a loop overwrites them (r1 only on a gated pass,
     * r2 only when a non-empty list runs). */
    uint32_t r7 = 0;
    uint32_t r14 = 0;
    uint32_t r1 = R(1), r2 = R(2), r6;
    const uint32_t r13 = 4u;            /* the gate mask, set at 0x0c061936 */

    /* 0x0c06191c..931: list A (st+8), ungated.  r7 = max over [node+16]. */
    r6 = vf3_mem_u32(ram, st + 8u);
    while (r6 != 0) {
        r2 = vf3_mem_u32(ram, r6 + 16u);
        if ((int32_t)r2 > (int32_t)r7)
            r7 = r2;
        r6 = vf3_mem_u32(ram, r6 + 8u);
    }

    /* 0x0c061932..94f: list B (st), gated by (node.gate & 4) == 0. */
    r6 = vf3_mem_u32(ram, st);
    while (r6 != 0) {
        r2 = r16_gate(ram, r6);
        if ((r2 & r13) == 0) {
            r1 = vf3_mem_u32(ram, r6 + 16u);
            if ((int32_t)r1 > (int32_t)r7)
                r7 = r1;
        }
        r6 = vf3_mem_u32(ram, r6 + 8u);
    }

    /* 0x0c061950..969: list C (st+0x1c), ungated.  r14 = max over [node+16].
     * The scratch slot at SP0-16 holds st+0x14 on the way (0x0c061954). */
    vf3_mem_set_u32(ram, sp0 - 16u, st + 0x14u);
    r6 = vf3_mem_u32(ram, st + 0x1cu);
    while (r6 != 0) {
        r2 = vf3_mem_u32(ram, r6 + 16u);
        if ((int32_t)r2 > (int32_t)r14)
            r14 = r2;
        r6 = vf3_mem_u32(ram, r6 + 8u);
    }

    /* 0x0c06196a..987: list D (list at st+0x14), gated. */
    r6 = vf3_mem_u32(ram, st + 0x14u);
    while (r6 != 0) {
        r2 = r16_gate(ram, r6);
        if ((r2 & r13) == 0) {
            r1 = vf3_mem_u32(ram, r6 + 16u);
            if ((int32_t)r1 > (int32_t)r14)
                r14 = r1;
        }
        r6 = vf3_mem_u32(ram, r6 + 8u);
    }

    /* 0x0c061988/98c: write the two maxima.  0x0c06198a: r0 = 0. */
    vf3_mem_set_u32(ram, r4i, r7);
    vf3_mem_set_u32(ram, r5i, r14);

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
    R(17) = (R(17) & ~1u) | 1u;         /* SR.T = 1: the walk-exit test */

    s->pc = R(16);
    return ram->oob == 0;
}
