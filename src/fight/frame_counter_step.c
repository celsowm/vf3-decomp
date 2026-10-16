/* frame_counter_step.c - 0x8C0CC334  step a looping frame counter and the two values it drives.
 *
 *   r4 -> object (word counter at +0x1E, word table value at +0x1C, floats at +0x10 / +0x0C / +0x14),
 *   r5 -> flag word, r6 / r7 -> two halfword tables, [the caller's sp] -> a third, FR4 / FR5 = speeds.
 *
 *   The counter is decremented. If that goes negative the routine only clears flag bit 0 and stops.
 *   Otherwise the counter is stored back, its low five bits index a halfword table (r6 when flag bit 1 is
 *   set, r7 when bit 2 is clear, else the stack-passed one) and the entry goes to +0x1C. The float at +0x10
 *   is advanced by -0.0018 and floored at -0.006. A non-zero FR4 then also moves the floats at +0x0C and
 *   +0x14 by FR4 / FR5 times (31 - counter) * 0.032. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define LIT_ADVANCE 0xBAEBEDFAu     /* -0.0018f */
#define LIT_FLOOR   0xBBC49BA5u     /* -0.006f */
#define LIT_SCALE   0x3D03126Eu     /* 0.032f */

static uint32_t half_s(const vf3_ram_map *ram, uint32_t a) { return (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, a); }

int vf3_frame_counter_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15), obj = R(4), flags_at = R(5);

    w32(ram, sp - 4, R(13));                                /* push r13 */
    F(8) = LIT_ADVANCE;
    F(7) = LIT_FLOOR;

    const uint32_t counter = half_s(ram, obj + 0x1E) - 1u;
    R(1) = counter;
    if ((int32_t)counter < 0) {
        R(2) = m32(ram, flags_at) & 0xFFFFFFFEu;
        R(3) = 0xFFFFFFFEu;
        w32(ram, flags_at, R(2));
        R(0) = half_s(ram, obj + 0x1E);                     /* the word read that started the routine */
        R(VF3_REG_SR) &= ~1u;                               /* cmp/pz was false */
        R(13) = m32(ram, sp - 4);
        s->pc = R(VF3_REG_PR);
        return 1;
    }

    vf3_mem_set_u16(ram, obj + 0x1E, (uint16_t)counter);
    const uint32_t flags = m32(ram, flags_at);
    R(13) = 31;
    R(1) = counter & 31u;
    uint32_t table;
    if (flags & 2u)       table = R(6);
    else if (flags & 4u)  table = m32(ram, sp);   
    else                  table = R(7);
    R(5) = table;
    R(0) = (counter & 31u) << 1;
    R(5) = half_s(ram, table + R(0));
    R(0) = R(5);
    vf3_mem_set_u16(ram, obj + 0x1C, (uint16_t)R(5));

    R(0) = 16;
    F(6) = m32(ram, obj + 0x10);
    FADD(6, 8);
    const int below = GT(6, 7);                             /* fcmp/gt FR6,FR7 */
    if (below) FMOV(6, 7);
    F(3) = 0;
    const int still = (fl(s, 4) == 0.0f);                   /* fcmp/eq FR3,FR4 */
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (still ? 1u : 0u);
    w32(ram, obj + 0x10, F(6));
    if (!still) {
        R(0) = 12;
        R(3) = 31;
        F(8) = m32(ram, obj + 0x0C);
        F(7) = m32(ram, obj + 0x14);
        R(5) = half_s(ram, obj + 0x1E) & 31u;
        R(3) = 31u - R(5);
        R(5) = R(3);
        R(VF3_REG_FPUL) = R(5);
        set_fl(s, 2, (float)(int32_t)R(5));                 /* float fpul,fr2 */
        FMOV(6, 2);
        F(2) = LIT_SCALE;
        FMUL(6, 2);
        FMOV(0, 6);
        FMAC(8, 4);                                         /* FR8 += FR0 * FR4 */
        FMAC(7, 5);
        w32(ram, obj + 0x0C, F(8));
        R(0) = 20;
        w32(ram, obj + 0x14, F(7));
    }
    R(13) = m32(ram, sp - 4);
    s->pc = R(VF3_REG_PR);
    return 1;
}
