/* empty_rts.h - native port of the render-callback slot's empty function
 * 0x8C0597CA on the `vf3_native_aim` context.
 *
 * See empty_rts.c and docs/re/native_empty_rts.md. */
#ifndef VF3_NATIVE_EMPTY_RTS_H
#define VF3_NATIVE_EMPTY_RTS_H

#include "motion_aim.h"

/* Run 0x8C0597CA (render_callback_stub): `rts`.  The guest body is exactly
 * `pc = pr; return;` - it changes no register.  The native port is the same
 * no-op: every register is left as it was. */
void vf3_native_empty_rts(vf3_native_aim *a);

#endif /* VF3_NATIVE_EMPTY_RTS_H */
