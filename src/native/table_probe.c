/* table_probe.c - SH-4 0x8C040378: the indexed table probe, natively.
 *
 * A plain-C transcription of the readable port
 * src/fight/readable/table_probe.c (`vf3_table_probe_entry`).  A self-contained
 * 62 B leaf (0x0C040378..0x0C0403B6), call-free, integer-only (no FP) and
 * no-stack in the r15 sense - it stores r4 at a transient stack slot at sp-4
 * and restores sp at the return.  It operates on `vf3_native_aim`: the flat
 * RAM and the register file.
 *
 * r4 is an index.  The body stores r4 at sp-4, reads it back into r2, and
 * returns a status in r0:
 *
 *   * r4 < 0   -> -1, T clear (r1 and r3 keep their entry values);
 *   * r4 >= 8  -> -1, T set   (r1 is left as 8, r3 = r4);
 *   * otherwise-> val = tbl[12 * r4] (stride twelve, base from the pool at
 *               0x0c0403bc), r1 = the table base, r3 = r4: val == 0xffffffff
 *               gives -2 with T set, any other entry gives 0 with T clear.
 *
 * See docs/re/native_table_probe.md. */
#include "table_probe.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ vf3_aim_set_u32(a, addr, v); }

void vf3_native_table_probe(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    uint32_t r4 = R(4);

    /* 0x0c04037a: the transient stack slot gains the entry value of r4. */
    wr32(a, R(15) - 4u, r4);

    /* 0x0c04037c: r2 = the pushed r4. */
    R(2) = r4;

    /* 0x0c04037e: T = (r2 >= 0); below range returns -1 with T clear.  On this
     * path r1 and r3 keep their entry values (the branch is taken before the
     * body reads the slot into r3). */
    if ((int32_t)r4 < 0) {
        R(0) = 0xffffffffu;
        a->sr = (a->sr & ~1u);                  /* T = 0 */
        return;
    }

    /* 0x0c040382/384: on any r4 >= 0 path r3 = the slot value = r4, and the
     * above-range test sets r1 = 8 before it decides. */
    R(3) = r4;
    R(1) = 8u;
    if ((int32_t)r4 >= 8) {
        R(0) = 0xffffffffu;
        a->sr = (a->sr & ~1u) | 1u;             /* T = 1 */
        return;
    }

    /* 0x0c040392..3a0: r4 in [0,8): val = tbl[12 * r4].  r1 = the table base. */
    {
        const uint32_t tbl = rd32(a, 0x0c0403bcu);
        R(1) = tbl;
        R(0) = rd32(a, tbl + 12u * r4);
    }

    /* 0x0c0403a2/3a4: the entry selects the answer and the T bit. */
    if (R(0) == 0xffffffffu) {
        R(0) = 0xffffffffu - 1u;                /* -2 */
        a->sr = (a->sr & ~1u) | 1u;             /* T = 1 */
    } else {
        R(0) = 0u;
        a->sr = (a->sr & ~1u);                  /* T = 0 */
    }
}
