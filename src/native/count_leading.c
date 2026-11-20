/* count_leading.c - SH-4 0x8C0769C6: the leading-zero count, natively.
 *
 * A plain-C transcription of the readable port src/fight/count_leading.c
 * (`vf3_count_leading_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained leaf (call-free, no FPU, no stack frame, no RAM).  r4 is a
 * word.  A probe bit starts at bit 31 and walks down; r6 counts the bits
 * passed, r5 is the probe left over and r3 a copy of r4:
 *
 *   for (;;) {
 *       if (word & probe) { t = 0; break; }   // tst r5,r3 found a set bit
 *       probe >>= 1;  ++count;                // walk down one bit
 *       if (probe == 0) { t = 1; break; }     // tst r5,r5 ran off the end
 *   }
 *
 * The answer is r0 (== count): the number of high bits clear before the first
 * set one, with 32 for an all-zero word.  r3 = word, r5 = the leftover probe,
 * r6 = count, and SR's T bit is the loop's exit test.  r4 and the stack
 * pointer and every other register are untouched.  The return pops pr (the
 * caller's return address).
 *
 * See docs/re/native_count_leading.md. */
#include "count_leading.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

void vf3_native_count_leading(vf3_native_aim *a)
{
    const uint32_t word = R(4);
    uint32_t probe = 0x80000000u;
    uint32_t count = 0;
    uint32_t t;

    for (;;) {
        if (word & probe) { t = 0; break; }     /* a set bit found: T = 0 */
        probe >>= 1;
        ++count;
        if (probe == 0) { t = 1; break; }       /* ran off the end: T = 1 */
    }

    R(3) = word;
    R(5) = probe;
    R(6) = count;
    R(0) = count;
    set_t(a, (int)t);
}
