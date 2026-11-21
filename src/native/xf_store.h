/* xf_store.h - native port of the shadow-bank store (0x8C03B820), operating
 * on the `vf3_native_aim` context.
 *
 * See xf_store.c and docs/re/native_xf_store.md. */
#ifndef VF3_NATIVE_XF_STORE_H
#define VF3_NATIVE_XF_STORE_H

#include "motion_aim.h"

/* Run 0x8C03B820.  Self-contained call-free leaf: writes XF12/13/14 (the
 * XMTRX shadow bank, a->xm[12..14]) as 32-bit words at r4+0/+4/+8, leaving r4
 * and every other register and bank untouched. */
void vf3_native_xf_store(vf3_native_aim *a);

#endif /* VF3_NATIVE_XF_STORE_H */
