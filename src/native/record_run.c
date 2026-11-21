/* record_run.c - SH-4 0x8C0C1296 (record_run), natively.
 *
 * A plain-C transcription of the readable port src/fight/misc_wrappers.c
 * (`vf3_record_run_entry`) onto `vf3_native_aim`: the flat RAM, the register
 * file, SR and pr.
 *
 *   r4 -> a record; the word at [r4+12] is the base of 120 consecutive
 *   68-byte records, each zero-filled by a call to mem_fill (0x8C095604),
 *   and then bit 0 is OR-ed into the halfword at [orig r4 + 34].
 *
 * The single guest callee (mem_fill) is natively ported, so the guest call
 * becomes a direct native call into mem_fill.c, exactly the shape of
 * extent_list (0x8C0CC432), which calls its two native leaves directly.  The
 * dead stack words - the four saved registers, the saved pr, the frame's copy
 * of the original r4, and mem_fill's own four dead words under the loop's
 * frame - are written back byte for byte, because they are visible in RAM.
 *
 * Contract: r0 = 34, r1 = sign-extended(u16 at orig r4+34) | 1, r2 = 1,
 * r3 = orig r4, r4 = mem_fill's word count (17 for a 68-byte record, its last
 * call's), r5 = 0, r6 = 68, r7 = the last record's end pointer, r8..r10 and
 * FPUL/FR/XF pass through untouched, r11..r14 are restored, r15 = sp0, pr is
 * restored, and SR's T bit is set (the last `cmp/ge r13,r12` of the loop).
 *
 * See docs/re/native_record_run.md. */
#include "record_run.h"
#include "mem_fill.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

#define RECORDS      120u
#define RECORD_BYTES 68u
#define MEM_FILL     0x0C095604u
#define MEM_FILL_RET 0x0C0C12B6u

void vf3_native_record_run(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, f = sp0 - 24u;
    const uint32_t saved[4] = { R(14), R(13), R(12), R(11) };
    static const uint8_t pushed[4] = { 14, 13, 12, 11 };

    for (int i = 0; i < 4; ++i)
        vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_aim_set_u32(a, sp0 - 20u, pr0);
    R(15) = f;
    vf3_aim_set_u32(a, f, R(4));
    R(14) = vf3_aim_u32(a, R(4) + 12u);
    R(13) = 0;
    R(12) = RECORDS;
    R(11) = MEM_FILL;
    do {
        R(5) = 0;
        R(6) = RECORD_BYTES;
        R(4) = R(14);
        a->pr = MEM_FILL_RET;            /* the guest keeps its ret in the 0x0C form */
        vf3_native_mem_fill(a);
        R(15) = f;
        R(13) += 1;
        a->sr = (a->sr & ~1u) | ((R(13) >= R(12)) ? 1u : 0u);
        R(14) += RECORD_BYTES;
    } while (R(13) < R(12));
    R(3) = vf3_aim_u32(a, f);
    R(0) = 34;
    R(1) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(3) + R(0));
    R(2) = 1;
    R(1) |= R(2);
    vf3_aim_set_u16(a, R(3) + R(0), (uint16_t)R(1));
    R(15) = sp0;
    a->pr = pr0;
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3];
}
