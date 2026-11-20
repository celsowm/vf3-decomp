/* vmu_cmd_name.h - native port of the save-operation name selector
 * (0x8C0374B0), operating on the `vf3_native_aim` context.
 *
 * See vmu_cmd_name.c and docs/re/native_vmu_cmd_name.md. */
#ifndef VF3_NATIVE_VMU_CMD_NAME_H
#define VF3_NATIVE_VMU_CMD_NAME_H

#include "aim_math.h"

/* Run 0x8C0374B0.  A self-contained leaf: no calls, no FPU, no stack frame.
 * The engine hands the command id in r4 and the function answers with the
 * *address* of the ASCII string that names that operation, read from the
 * literal pool (the pool word at 0x0c03754c..0x0c037564 for the seven known
 * ids 0,1,2,3,7,0xb,0xc; the fallback 0x0c037568 for anything else).  r0 is
 * overwritten twice (the entry copies r4, then the pool word), so the answer
 * in r0 is the string address, never the id.  The T bit it leaves is the last
 * test's: set on a match, clear on the fallback.  See
 * docs/re/native_vmu_cmd_name.md. */
void vf3_native_vmu_cmd_name(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_VMU_CMD_NAME_H */
