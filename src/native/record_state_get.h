#ifndef VF3_NATIVE_RECORD_STATE_GET_H
#define VF3_NATIVE_RECORD_STATE_GET_H

/* Native port of the record-state getter leaf 0x8C035A20
 * (vf3_native_record_state_get). */
#include "motion_aim.h"

/* Answer the record's state word at +0x4C, but only when the busy word at
 * +0x48 says the record carries one.  A record that is not busy - and a null
 * record - answers -10, the "no state" answer.  r4 = the record (or 0).
 * Tail-transfer to pr (untouched). */
void vf3_native_record_state_get(vf3_native_aim *a);

#endif /* VF3_NATIVE_RECORD_STATE_GET_H */
