/* timecode_digits.c - 0x8C0A04DC  split a frame-based clock into six decimal digits and hand them to a text builder.
 *
 * r4 = x position (in cells), r5 = the clock source passed to 0x0C0C66C8, which returns the time in 1/64 s units. With
 * u = value & 63 (the fraction of a second) and s = value >> 6 (whole seconds, arithmetic):
 *     centis = 100 * u >> 6          -> centis tens / ones via 0x0C042C20 (r1 / r0 division by 10)
 *     min    = s / 60 (division by 60 through the same helper), sec = s - 60 * min -> sec tens / ones
 *     min    -> min tens / ones
 * The six digits go to 0x0C0C1208 on the stack, deepest first: [sp+0] = 0x0C0E946C (the format pointer), +4 min tens,
 * +8 min ones, +12 sec tens, +16 sec ones, +20 centis tens, +24 centis ones, with r4 = ((x + 12) << 7) | 46. The routine
 * keeps macl across its multiplies (pushed and popped), so macl leaves unchanged. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define CALL(target, ret) do { R(VF3_REG_PR) = (ret); if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = sp; } while (0)
#define DIV_HELPER 0x0C042C20u

int vf3_timecode_digits_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 28, macl0 = R(19);
    const uint32_t save14 = R(14), save13 = R(13), save12 = R(12);
    uint32_t sp = f;
    w32(ram, sp0 - 4, save14);
    w32(ram, sp0 - 8, save13);
    w32(ram, sp0 - 12, save12);
    w32(ram, sp0 - 16, pr0);
    w32(ram, sp0 - 20, macl0);
    R(15) = sp;
    w32(ram, f, R(4));
    w32(ram, f + 4, R(5));

    R(4) = R(5);
    R(3) = 0x0C0C66C8u;
    CALL(0x0C0C66C8u, 0x8C0A04F2u);
    R(14) = 63;
    R(4) = R(0);
    R(14) &= R(4);
    R(2) = 100;
    R(19) = R(2) * R(14);
    R(3) = (uint32_t)-6;
    R(5) = 10;
    R(7) = 60;
    R(14) = R(19);
    R(14) = (uint32_t)((int32_t)R(14) >> 6);
    R(3) = DIV_HELPER;
    R(1) = R(14);
    R(0) = R(5);
    CALL(DIV_HELPER, 0x8C0A050Eu);
    R(1) = R(0) << 2;
    R(3) = R(0);
    R(1) += R(3);
    R(3) = (uint32_t)-6;
    R(12) = R(0);
    R(4) = (uint32_t)((int32_t)R(4) >> 6);
    R(3) = DIV_HELPER;
    R(1) <<= 1;
    R(14) -= R(1);
    R(1) = R(4);
    R(0) = R(7);
    CALL(DIV_HELPER, 0x8C0A0528u);
    R(6) = R(0);
    R(13) = R(4);
    R(19) = R(7) * R(6);
    R(3) = DIV_HELPER;
    R(7) = R(19);
    R(13) -= R(7);
    R(1) = R(13);
    R(0) = R(5);
    CALL(DIV_HELPER, 0x8C0A053Au);
    R(1) = R(0) << 2;
    R(3) = R(0);
    R(1) += R(3);
    R(1) <<= 1;
    R(3) = DIV_HELPER;
    R(13) -= R(1);
    R(7) = R(0);
    R(1) = R(6);
    R(0) = R(5);
    CALL(DIV_HELPER, 0x8C0A0550u);
    R(1) = R(0);
    R(4) = m32(ram, f);
    R(1) <<= 2;
    sp -= 4; w32(ram, sp, R(14));
    R(3) = R(0);
    sp -= 4; w32(ram, sp, R(12));
    R(1) += R(3);
    sp -= 4; w32(ram, sp, R(13));
    R(3) = 7;
    sp -= 4; w32(ram, sp, R(7));
    R(4) += 12;
    R(5) = R(0);
    R(1) <<= 1;
    R(4) <<= 7;
    R(6) -= R(1);
    sp -= 4; w32(ram, sp, R(6));
    R(1) = 46;
    R(4) |= R(1);
    sp -= 4; w32(ram, sp, R(5));
    R(3) = 0x0C0C1208u;
    R(2) = 0x0C0E946Cu;
    sp -= 4; w32(ram, sp, R(2));
    R(15) = sp;
    R(VF3_REG_PR) = 0x8C0A057Eu;
    if (!vf3_guest_call(s, ram, 0x0C0C1208u, 0x8C0A057Eu)) return 0;

    R(19) = macl0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(12) = save12;
    R(13) = save13;
    R(14) = save14;
    s->pc = pr0;
    return 1;
}
