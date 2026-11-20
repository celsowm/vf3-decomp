/* mode_index.c - SH-4 0x8C038990: the fight engine's mode-index switch,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/mode_index.c
 * (`vf3_mode_index_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody, uses no FPU and
 * keeps no stack frame.
 *
 * The engine passes a mode **flag** in r4 and this function turns it into an
 * **index** into some table.  Eight flags are known: four are constants and
 * four live in the literal pool.  A flag that is none of them is left alone.
 *
 *   flag  8   -> index 0
 *   flag 16   -> index 1
 *   flag 32   -> index 2
 *   flag 64   -> index 3
 *   flag pool[0x8C038AF2] -> index 4
 *   flag pool[0x8C038AF4] -> index 5
 *   flag pool[0x8C038AF6] -> index 6
 *   flag pool[0x8C038AF8] -> index 7
 *
 * The pool's values are not recoverable offline, so the port reads the same
 * addresses the guest reads (as sign-extended halfwords).
 *
 * Two details the port keeps: the guest compares the four constants against a
 * **copy** of the flag it made in r0, and the four pool values against the
 * flag (r4) itself; and the T bit the caller sees is the one of the comparison
 * that answered, so it is set on a hit and cleared when no flag matched.
 *
 * See docs/re/native_mode_index.md. */
#include "mode_index.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* the literal pool: the four flags that are not constants */
#define G_CASE4 0x0c038af2u
#define G_CASE5 0x0c038af4u
#define G_CASE6 0x0c038af6u
#define G_CASE7 0x0c038af8u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the pool's flag, as a signed halfword (the guest reads it with `mov.w`) */
static uint32_t pool_flag(vf3_native_aim *a, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, addr);
}

void vf3_native_mode_index(vf3_native_aim *a)
{
    /* the flag, and a copy of it to compare the constants against */
    R(0) = R(4);

    if (R(0) == 8u) {
        R(4) = 0u;
        set_t(a, 1);
    } else if (R(0) == 16u) {
        R(4) = 1u;
        set_t(a, 1);
    } else if (R(0) == 32u) {
        R(4) = 2u;
        set_t(a, 1);
    } else if (R(0) == 64u) {
        R(4) = 3u;
        set_t(a, 1);
    } else {
        /* the four flags the pool holds, read in the order the guest reads
         * them: the first lands in r3, the second in r2, the third in r1 and
         * the fourth in r3 again */
        R(3) = pool_flag(a, G_CASE4);
        if (R(4) == R(3)) {
            R(4) = 4u;
            set_t(a, 1);
        } else {
            R(2) = pool_flag(a, G_CASE5);
            if (R(4) == R(2)) {
                R(4) = 5u;
                set_t(a, 1);
            } else {
                R(1) = pool_flag(a, G_CASE6);
                if (R(4) == R(1)) {
                    R(4) = 6u;
                    set_t(a, 1);
                } else {
                    R(3) = pool_flag(a, G_CASE7);
                    if (R(4) == R(3)) {
                        R(4) = 7u;
                        set_t(a, 1);
                    } else {
                        /* no flag matched: the flag is left alone */
                        set_t(a, 0);
                    }
                }
            }
        }
    }

    /* and the answer */
    R(0) = R(4);
}
