/* byte_sink.c - 0x8C04B952  push a run of bytes into an output descriptor.
 *
 *   r4 -> the bytes, r5 = count, r6 -> descriptor: +0 mode, +4 the destination (or the sink's context), +8 the
 *   running total, +12 the per-byte sink routine (mode other than 1).
 *
 *   Mode 1 is a block copy: 0x8C043018 (r4 = destination, r5 = source, r6 = count) copies everything at once,
 *   and then the destination and the total both advance by the count. Any other mode feeds the bytes one at a
 *   time (sign-extended in r4, the context in r5) to the sink routine; the total grows by one for each byte
 *   taken, and a result of -1 from the routine stops the run early.
 *
 *   Frame: none, just four saved registers and pr. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { MODE_BLOCK = 1 };

int vf3_byte_sink_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    const uint32_t saved_r[4] = { R(14), R(13), R(12), R(11) };
    static const int pushed[4] = { 14, 13, 12, 11 };

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 20, pr0);

    const uint32_t desc = R(6), count = R(5);
    R(14) = desc; R(11) = R(4); R(13) = count;
    R(15) = sp0 - 20;

    R(0) = m32(ram, desc);
    if (R(0) == MODE_BLOCK) {
        R(2) = 0x8C043018u;
        R(6) = count; R(5) = R(11); R(4) = m32(ram, desc + 4);
        if (!vf3_guest_call(s, ram, 0x8C043018u, 0x8C04B972u)) return 0;
        R(15) = sp0 - 20;
        w32(ram, desc + 4, m32(ram, desc + 4) + count);
        w32(ram, desc + 8, m32(ram, desc + 8) + count);
    } else if ((int32_t)count > 0) {
        R(12) = 0;
        for (;;) {
            R(0) = m32(ram, desc + 12);
            R(5) = m32(ram, desc + 4);
            R(4) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(11));
            R(11) += 1;
            if (!vf3_guest_call(s, ram, R(0), 0x8C04B98Eu)) return 0;
            R(15) = sp0 - 20;
            if (R(0) == 0xFFFFFFFFu) break;
            w32(ram, desc + 8, m32(ram, desc + 8) + 1);
            R(12) += 1;
            if ((int32_t)R(12) >= (int32_t)R(13)) break;
        }
    } else {
        R(12) = 0;
    }

    for (int i = 0; i < 4; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
