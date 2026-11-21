/* negate_run.c - SH-4 0x8C09D408: the negate-run, natively.
 *
 * A plain-C transcription of the readable port src/fight/small_leaves.c
 * (`vf3_negate_run_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained leaf (call-free, no stack frame).  It negates 7 + 14
 * floats - every float at r4+8, r4+20, ... (stride 12) for the first run,
 * then 14 more starting 8 bytes below the first run's end (stride 12 again).
 * Each negation is a sign-bit flip (fneg), so the body is pure integer in
 * native form.
 *
 * After the run r4 is one past the last written float, r5 is 0 (the loop
 * counter ran out), and SR's T bit is set.  r0..r3, r6..r15, the stack
 * pointer and pr are untouched.  The return pops pr (the caller's return
 * address).
 *
 * The readable's `plain_fpu` gate (which refuses to run when the FPU is not
 * usable) is a harness concern: the body is a pure sign flip with no real
 * float width, so the native leaf always runs.
 *
 * See docs/re/native_negate_run.md. */
#include "negate_run.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

#define SIGN 0x80000000u

static void run(vf3_native_aim *a, uint32_t *addr, uint32_t count)
{
    do {
        uint32_t v = vf3_aim_u32(a, *addr) ^ SIGN;
        vf3_aim_set_u32(a, *addr, v);
        *addr += 12u;
        --count;
    } while (count != 0);
}

void vf3_native_negate_run(vf3_native_aim *a)
{
    uint32_t addr = R(4) + 8u;

    run(a, &addr, 7u);
    addr -= 8u;
    run(a, &addr, 14u);

    R(4) = addr;
    R(5) = 0;
    a->sr |= 1u;            /* SET_T(1) */
}
