/* scene_walk.c - SH-4 0x8C06233E: the scene list walk with an enable flag,
 * natively.
 *
 * A plain-C transcription of the readable port
 * src/fight/readable/scene_walk.c (`vf3_scene_walk_entry`).  A self-contained
 * leaf (body 0x0C06233E..0x0C062378, 62 B), call-free and integer-only (no
 * FP, no gbr, no fipr), so there are no guest callees to inline and no FPU
 * wrappers.  It operates on `vf3_native_aim`: the flat RAM (every guest
 * address resolves through `ram_base`) and the register file.
 *
 *   p1      = [0x0c06238c]    a pointer
 *   thr     = [p1]            the threshold
 *   enabled = (r4 >= thr)     signed comparison, SR.T
 *   [r5]    = enabled ? 1 : 0 a 16-bit enable flag
 *   byte    = (int8)[r5]      reads the flag back (0 or 1)
 *   node    = [base + 20*byte]   base = [0x0c062384]
 *
 * When node != 0 the body walks the linked list (a node holds its value at
 * +12 and its next pointer at +8), recording in r6 the first node whose value
 * equals r4 and otherwise following next until the list ends.  The answer is
 * a tail jmp @r16: r0 = r6 (the found node, or 0), and the function neither
 * pushes pr nor touches r15/r16.
 *
 * The registers the body leaves are r0 = r6, r1 = 1 on an enabled empty table
 * (or the last value the walk read), r2 = byte, r3 = 20 * byte (the table
 * stride), r5 = 0 (the walk's terminator), r6 = the found node and SR.T = 1
 * (the walk-exit test (r5 == 0) is the last comparison).  r4 and r15 are
 * untouched.
 *
 * See docs/re/native_scene_walk.md. */
#include "scene_walk.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static uint32_t rd8(vf3_native_aim *a, uint32_t addr)
{ return (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, addr); }
static void wr16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{ vf3_aim_set_u16(a, addr, v); }
/* a byte-width store (only the mutation gate turns the enable flag store into
 * this; the flag is really a 16-bit store) */
static void wr8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

void vf3_native_scene_walk(vf3_native_aim *a, uint32_t sp0)
{
    const uint32_t r4i = R(4);
    const uint32_t r5i = R(5);

    /* 0x0c06233e/340: p1 = the threshold pointer; thr = *p1. */
    const uint32_t p1 = rd32(a, 0x0c06238cu);
    const uint32_t thr = rd32(a, p1);

    /* 0x0c062344: r6 = 0.  The enable flag written to [r5] is 1 when
     * r4 >= thr (the signed comparison at 0x0c062342) and 0 otherwise. */
    R(6) = 0u;
    const uint32_t enabled =
        ((int32_t)r4i >= (int32_t)thr) ? 1u : 0u;
    wr16(a, r5i, (uint16_t)enabled);

    /* 0x0c062352: byte = (int8)[r5], then (0x0c062354..35e) the table stride
     * 20*byte.  r2 = byte, r3 = 20*byte. */
    const uint32_t byte = rd8(a, r5i);
    const uint32_t base = rd32(a, 0x0c062384u);
    R(2) = byte;
    R(3) = 20u * byte;

    /* The enable=1 path sets r1 = 1 (0x0c06234e) before the flag write; only
     * the walk (r1 = [node+12], 0x0c062366) can change it again.  So r1 is 1
     * on an enabled empty table, and keeps its entry value on the enable=0
     * path. */
    if (enabled)
        R(1) = 1u;

    /* 0x0c062360: the table gives the first node. */
    const uint32_t first = rd32(a, base + 20u * byte);

    /* 0x0c062362/364: an empty table returns straight away (r6 stays 0). */
    if (first != 0u) {
        uint32_t cur = first;
        for (;;) {
            const uint32_t value = rd32(a, cur + 12u); /* 0x0c062366 */
            R(1) = value;
            if (value == r4i) {          /* 0x0c062368/36a: found */
                R(6) = cur;              /* 0x0c06236c */
                R(5) = 0u;               /* 0x0c06236e */
                break;
            }
            cur = rd32(a, cur + 8u);     /* 0x0c062372: next */
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
    a->sr = (a->sr & ~1u) | 1u;
}
