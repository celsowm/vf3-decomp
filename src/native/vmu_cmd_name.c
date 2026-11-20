/* vmu_cmd_name.c - SH-4 0x8C0374B0: the save-operation name selector,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/readable/
 * vmu_cmd_name.c (`vf3_vmu_cmd_name_entry`).  A self-contained leaf: no calls,
 * no FPU, no stack frame.  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.
 *
 * The engine hands the command id in r4 and the function answers with the
 * *address* of the ASCII string that names that operation, read from the
 * literal pool.  The pool holds one word per known command (the string's
 * address at 0x0c03754c..0x0c037564) and one for the fallback (0x0c037568).
 * The body copies r4 into r0, tests it against the seven known ids in order,
 * and takes the first match, falling back to "UNKNOWN OPERATION".
 *
 * Two details the port keeps: r0 is overwritten twice (the entry `mov r4,r0`,
 * then the pool word), so the answer in r0 is the string address, never the
 * id; and the T bit it leaves is the last test's - set on a match (the
 * matching compare just made it), clear on the fallback (the last compare,
 * r0 == 0xc, has just failed).
 *
 * See docs/re/native_vmu_cmd_name.md. */
#include "vmu_cmd_name.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])

static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ uint32_t v; memcpy(&v, gb(a, addr), 4); return v; }

static void set_t(vf3_native_aim *a, int value)
{ a->sr = (a->sr & ~1u) | (value != 0); }

/* The command ids the guest matches, in the order it tests them. */
static const uint32_t keys[7] = { 0u, 1u, 2u, 3u, 7u, 0xbu, 0xcu };

/* The pool word that holds each id's string address, in the same order. */
static const uint32_t pool[7] = {
    0x0c03754cu, 0x0c037550u, 0x0c037554u, 0x0c037558u,
    0x0c03755cu, 0x0c037560u, 0x0c037564u,
};

/* The fallback: "UNKNOWN OPERATION". */
#define POOL_DEFAULT 0x0c037568u

void vf3_native_vmu_cmd_name(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    R(0) = R(4);                       /* the command id */

    uint32_t pool_addr = POOL_DEFAULT;
    for (unsigned i = 0; i < 7; ++i) {
        set_t(a, R(0) == keys[i]);     /* the guest's cmp/eq keeps the id */
        if (R(0) == keys[i]) {
            pool_addr = pool[i];
            break;
        }
    }
    /* The fallback keeps the T bit of the last compare (r0 == 0xc), which is
     * clear - the id matched none of the seven. */

    R(0) = rd32(a, pool_addr);         /* the string's address */
}
