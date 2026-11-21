/* xf_store.c - SH-4 0x8C03B820: store the XF12..XF14 shadow-bank words, natively.
 *
 * A plain-C transcription of the readable port vf3_xf_store_entry
 * (src/fight/small_leaves.c) onto `vf3_native_aim`.  A call-free, no-stack
 * leaf that moves three machine words out of the XMTRX shadow bank into RAM:
 *
 *   r4 -> RAM.  Writes XF12 at r4+0, XF13 at r4+4, XF14 at r4+8.
 *   r4 ends unchanged (the guest does r4 += 12, then three decrement-and-store
 *   steps land back at the entry value).
 *
 * The guest gates on `plain_fpu` (it models the fschg-adjacent pair moves that
 * read the shadow bank), but the body itself performs no FPU arithmetic - each
 * XF word is copied as a raw 32-bit value - so the native leaf is a straight
 * three-word copy.  XF0..15 are the XMTRX bank (a->xm[16]).
 *
 * See docs/re/native_xf_store.md. */
#include "xf_store.h"

#include "aim_math.h"

void vf3_native_xf_store(vf3_native_aim *a)
{
    const uint32_t dst = a->r[4];
    vf3_aim_set_u32(a, dst,          vf3_aim_ubits(a->xm[12]));
    vf3_aim_set_u32(a, dst + 4u,     vf3_aim_ubits(a->xm[13]));
    vf3_aim_set_u32(a, dst + 8u,     vf3_aim_ubits(a->xm[14]));
    /* r4, all other registers, the XM bank and the FR bank are left as-is */
}
