/* cache_wb_stub.h - native port of the operand-cache write-back stub
 * 0x8C062E8E on the `vf3_native_aim` context.
 *
 * See cache_wb_stub.c and docs/re/native_cache_wb_stub.md. */
#ifndef VF3_NATIVE_CACHE_WB_STUB_H
#define VF3_NATIVE_CACHE_WB_STUB_H

#include "motion_aim.h"

/* Run 0x8C062E8E (cache_wb_stub): `ocbwb @r4; rts`.  The operand cache is
 * not modelled (RAM is always coherent), so the instruction has no effect -
 * every register is left as it was. */
void vf3_native_cache_wb_stub(vf3_native_aim *a);

#endif /* VF3_NATIVE_CACHE_WB_STUB_H */
