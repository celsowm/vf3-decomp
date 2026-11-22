/* empty_rts.c - SH-4 0x8C0597CA (render_callback_stub), natively.
 *
 * The render-callback slot's empty function is a bare `rts`: the guest body
 * is `pc = pr` with no register touched.  The native port is the same no-op -
 * it returns without moving anything.
 *
 * See docs/re/native_empty_rts.md. */
#include "empty_rts.h"

#include "aim_math.h"

void vf3_native_empty_rts(vf3_native_aim *a)
{
    (void)a;   /* `rts`; nothing moves */
}
