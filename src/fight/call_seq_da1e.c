/* call_seq_da1e.c - 0x8C09DA1E  rebuild a small camera/record state from a pair of halfword inputs.
 *
 * r4 = pointer to three halfwords (a, b, c), r5 = owner record. A 16-byte stack scratch (its first word keeps r5, the
 * words from +4 are the working block) is run through this sequence of helpers:
 *     0x0C03B820(block)                    init the block
 *     0x0C03CCB0()
 *     0x0C03C880(owner.s16[+30])
 *     0x0C03C940(a)
 *     0x0C03C880(b)
 *     0x0C03C6C0(owner.s16[+0x22E6] + c)
 *     0x0C03CBD0(block)                    finish
 * with the 16-bit values zero-extended on the way in, except the first 0x0C03C880 argument, which is sign-extended. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define CALL(target, ret) do { R(VF3_REG_PR) = (ret); if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define S16(a)      ((uint32_t)(int32_t)(int16_t)(vf3_mem_u8(ram, (a)) | (vf3_mem_u8(ram, (a) + 1) << 8)))

int vf3_call_seq_da1e_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 24;
    const uint32_t saved_r14 = R(14), owner = R(5);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(14) = R(4);
    const uint32_t in = R(14);
    R(15) = f;
    R(4) = f;
    w32(ram, f, owner);
    R(4) = f + 4;
    R(3) = 0x0C03B820u;
    CALL(0x0C03B820u, 0x8C09DA30u);
    R(2) = 0x0C03CCB0u;
    CALL(0x0C03CCB0u, 0x8C09DA36u);
    R(4) = m32(ram, f);
    R(3) = 0x0C03C880u;
    R(0) = S16(R(4) + 30);
    R(4) = R(0);
    CALL(0x0C03C880u, 0x8C09DA40u);
    R(2) = 0x0C03C940u;
    R(4) = S16(in);
    R(4) &= 0xFFFFu;
    CALL(0x0C03C940u, 0x8C09DA48u);
    R(3) = 0x0C03C880u;
    R(0) = S16(in + 2);
    R(4) = R(0) & 0xFFFFu;
    CALL(0x0C03C880u, 0x8C09DA50u);
    R(4) = m32(ram, f);
    R(2) = 0x22E6u;
    R(0) = S16(in + 4);
    R(2) += R(4);
    R(3) = 0x0C03C6C0u;
    R(4) = S16(R(2));
    R(0) &= 0xFFFFu;
    R(4) += R(0);
    CALL(0x0C03C6C0u, 0x8C09DA64u);
    R(2) = 0x0C03CBD0u;
    R(4) = f + 4;
    CALL(0x0C03CBD0u, 0x8C09DA6Au);
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(14) = saved_r14;
    s->pc = pr0;
    return 1;
}
