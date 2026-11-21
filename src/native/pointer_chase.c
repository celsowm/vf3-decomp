/* pointer_chase.c - SH-4 0x8C035264: the pointer-chase leaf, natively.
 *
 * A plain-C transcription of the readable port src/fight/pointer_chase.c
 * (`vf3_pointer_chase_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained integer leaf (call-free, no FP, no
 * stack frame), so there are no guest callees to inline and no FPU wrappers.
 *
 * The function:
 *
 *   r3 = [0x0c03548c]       the literal pool holds a pointer
 *   r0 = [r3]               dereference it -> the object
 *   r0 = [r0 + 40]          read the field at offset 40
 *   (tail transfer to pr)
 *
 * Every path is a tail transfer to pr (r16 in the readable's numbering, the
 * caller's return address), so the native port leaves pr untouched and simply
 * returns.  r0 ends up the field value, r3 the pool-loaded pointer.  No
 * comparisons, so SR's T bit, r4..r15 and r15 are all untouched.
 *
 * See docs/re/native_pointer_chase.md. */
#include "pointer_chase.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

void vf3_native_pointer_chase(vf3_native_aim *a)
{
    /* the literal pool address holding the pointer to chase */
    const uint32_t pool_addr = 0x0c03548cu;

    /* r3 = read(pool_addr) */
    R(3) = vf3_aim_u32(a, pool_addr);

    /* r0 = read(r3) */
    R(0) = vf3_aim_u32(a, R(3));

    /* r0 = read(r0 + 40) */
    R(0) = vf3_aim_u32(a, R(0) + 40u);

    /* tail-transfer to pr: the C return leaves pr untouched */
}
