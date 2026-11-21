/* record_state_get.c - SH-4 0x8C035A20: the record's state getter, natively.
 *
 * A plain-C transcription of the readable port src/fight/record_state_field.c
 * (`vf3_record_state_get_entry`).  A call-free integer leaf: no guest callees,
 * no FP and no stack frame - the only control transfer is the final tail
 * transfer to pr.  It answers the record's state word at +0x4C, but only when
 * the busy word at +0x48 says the record carries one; a record that is not
 * busy - and a null record - answers -10, the "no state" answer the record
 * walk turns into -25.
 *
 * It leaves the busy word in r2, the state (or -10) in r0 and the T flag
 * (SR bit 0) says whether the record was empty (set) or carried a state
 * (clear - the final test is "state word non-zero" first, then "busy
 * non-zero" in the no-carried-state branch).  See
 * docs/re/native_record_state_get.md. */
#include "record_state_get.h"
#include "aim_math.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* the record's fields */
#define NODE_BUSY  0x48u
#define NODE_STATE 0x4cu

/* the "no state" answer */
#define RESULT_NO_STATE 0xfffffff6u   /* -10 */

void vf3_native_record_state_get(vf3_native_aim *a)
{
    const uint32_t record = R(4);

    /* T = (record == 0) */
    a->sr = (a->sr & ~1u) | (record == 0);
    if (record == 0) {
        R(0) = RESULT_NO_STATE;
        return;              /* tail transfer to pr (untouched) */
    }

    /* r2 = sign-extended halfword at record + 0x48 (the busy word) */
    R(2) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, record + NODE_BUSY);

    /* T = (busy == 0) */
    a->sr = (a->sr & ~1u) | (R(2) == 0);
    if (R(2) == 0) {
        R(0) = RESULT_NO_STATE;
        return;              /* tail transfer to pr (untouched) */
    }

    /* r0 = sign-extended halfword at record + 0x4C (the state word) */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, record + NODE_STATE);

    /* tail-transfer to pr: the C return leaves pr untouched */
}
