/* scene_walk.c - SH-4 0x8C06233E: the scene list walk with an enable flag.
 *
 * A self-contained leaf (body 0x0C06233E..0x0C062378), call-free, integer-only
 * (no FP).  It reads the threshold pointer from the literal pool at
 * 0x0c06238c (a pointer to a word that holds the threshold) and a table base
 * at 0x0c062384.
 *
 *   p1      = [0x0c06238c]           a pointer
 *   thr     = [p1]                   the threshold
 *   enabled = (r4 >= thr)            signed comparison, SR.T
 *   [r5]    = enabled ? 1 : 0        a 16-bit enable flag
 *   byte    = (int8)[r5]             reads the flag back (0 or 1)
 *   node    = [base + 20 * byte]     base = [0x0c062384]
 *
 * If node != 0 it walks the linked list (a node holds its value at +12 and its
 * next pointer at +8), recording in r6 the first node whose value equals r4
 * and otherwise following next until the list ends.  The answer r6 is left
 * back in r0 on the return (a tail `jmp @r16`, so the function neither pushes
 * pr nor touches r15/r16).
 *
 * The registers the body leaves are r0 = r6 (the found node, or 0), r1 = the
 * last value read in the walk (or its entry value when the table is empty),
 * r2 = the enable byte (0 or 1), r3 = 20 * byte (the table stride it used),
 * r5 = 0 (the walk's terminator), r6 = the found node and SR.T = 1 (the
 * walk-exit test (r5 == 0) is the last comparison).  r4 and r15 are left
 * untouched.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_scene_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t r4i = R(4);
    const uint32_t r5i = R(5);

    /* 0x0c06233e/340: p1 = the threshold pointer; thr = *p1. */
    const uint32_t p1 = vf3_mem_u32(ram, 0x0c06238cu);
    const uint32_t thr = vf3_mem_u32(ram, p1);

    /* 0x0c062344: r6 = 0.  The enable flag written to [r5] is 1 when
     * r4 >= thr (the signed comparison at 0x0c062342) and 0 otherwise. */
    R(6) = 0u;
    const uint32_t enabled =
        ((int32_t)r4i >= (int32_t)thr) ? 1u : 0u;
    vf3_mem_set_u16(ram, r5i, (uint16_t)enabled);

    /* 0x0c062352: byte = (int8)[r5], then (0x0c062354..35e) the table stride
     * 20*byte.  r2 = byte, r3 = 20*byte. */
    const uint32_t byte = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, r5i);
    const uint32_t base = vf3_mem_u32(ram, 0x0c062384u);
    R(2) = byte;
    R(3) = 20u * byte;

    /* The enable=1 path sets r1 = 1 (0x0c06234e) before the flag write; only
     * the walk (r1 = [node+12], 0x0c062366) can change it again.  So r1 is 1
     * on an enabled empty table, and keeps its entry value on the enable=0
     * path. */
    if (enabled)
        R(1) = 1u;

    /* 0x0c062360: the table gives the first node. */
    const uint32_t first = vf3_mem_u32(ram, base + 20u * byte);

    /* 0x0c062362/364: an empty table returns straight away (r6 stays 0). */
    if (first != 0u) {
        uint32_t cur = first;
        for (;;) {
            const uint32_t value = vf3_mem_u32(ram, cur + 12u); /* 0x0c062366 */
            R(1) = value;
            if (value == r4i) {          /* 0x0c062368/36a: found */
                R(6) = cur;              /* 0x0c06236c */
                R(5) = 0u;               /* 0x0c06236e */
                break;
            }
            cur = vf3_mem_u32(ram, cur + 8u);   /* 0x0c062372: next */
            if (cur == 0u) {             /* 0x0c062374/376: end of the list */
                R(5) = 0u;
                break;
            }
        }
    } else {
        R(5) = 0u;
    }

    /* 0x0c062378: r0 = r6 and a tail jmp @r16; SR.T is the walk-exit test,
     * which is always 1 when control reaches the return. */
    R(0) = R(6);
    R(17) = (R(17) & ~1u) | 1u;
    s->pc = R(16);
    return ram->oob == 0;
}
