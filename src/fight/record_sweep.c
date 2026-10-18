/* record_sweep.c - 0x8C0927E6  walk a list of motion-segment records and run the per-segment update helpers on each.
 *
 * r4 = owner record (r13), r5 = second record (r11), r6 = first segment (r14), r7 = stored at f+C; the caller's own
 * stack arguments are the segment budget at sp+8 (decremented once per segment that carries the 2 flag) and two more
 * words handed on to the helpers (sp+0 and sp+4).
 *
 * Each segment starts with three floats (a position); the halfword at +0x34 holds its flags (bit 0 = live, 2 = take
 * a step from the budget, 4 = skip the helpers, 0x20 = copy the previous result, 0x40 = flag the helper call), the
 * byte at +0x37 selects a 24-byte descriptor in the table at 0x0C0FBB98. Segments are 0x58 bytes long, or 0x38
 * when the 2 flag is clear. For a segment that goes through the helpers the sequence is
 *   0x8C0930DE, 0x8C092F1C, 0x8C09302A, 0x8C092A70, 0x8C09363A, 0x8C093768, 0x8C092E54, 0x8C092B4A, 0x8C092C3E
 * and the three results are copied back over the segment's position (+0..+0x14); the previous segment (r10) and its
 * descriptor stay available for the next iteration.
 *
 * The routine replays the original's pushes (the helpers read their extra arguments off the stack), so the frame it
 * leaves is the original's. Frame (f = sp - 96): f+0 flag word, f+4 .. f+C helper outputs, f+8 helper result, f+10 the
 * previous descriptor, f+20 / f+32 / f+44 float triples, f+38 / f+3C / f+40 the segment's position copy. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { FLAGS_OFF = 52, KIND_OFF = 55, BUDGET_ARG = 104, TABLE = 0x0C0FBB98u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)
/* Calls leave the stack pointer where the caller put it (the helpers' stack arguments stay pushed until the
 * original's own cleanup). */
#define CALLK(target, ret) do { const uint32_t keep_ = R(15); \
        if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = keep_; } while (0)
#define PUSH(v)     do { R(15) -= 4; w32(ram, R(15), (v)); } while (0)
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))

int vf3_record_sweep_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 96;
    const uint32_t saved[6] = { R(14), R(13), R(12), R(11), R(10), R(9) };
    for (int i = 0; i < 6; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    w32(ram, sp0 - 28, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(14) = R(6);
    R(13) = R(4);
    R(11) = R(5);
    R(10) = 0;
    R(15) = f;
    w32(ram, f + 12, R(7));

next_segment:
    R(0) = FLAGS_OFF;
    R(3) = vf3_mem_u16(ram, R(14) + R(0));
    R(2) = 1;
    w32(ram, f, R(3));                                 /* delay slot of the bf/s below */
    TST(R(2), R(3));
    if (R(VF3_REG_SR) & 1u) goto done;
    R(0) = KIND_OFF;
    R(2) = TABLE;
    R(12) = S8(R(14) + R(0));
    R(0) = m32(ram, f);
    R(3) = R(12) << 2;
    R(12) <<= 1;
    R(12) += R(3);
    TST(R(0), 2);
    R(12) <<= 2;
    R(12) += R(2);                                     /* delay slot of the bt/s below */
    if (R(VF3_REG_SR) & 1u) { R(9) = 56; goto run_helpers; }

    /* flag 2: spend one step of the budget and decide between the full path and the copy */
    R(0) = BUDGET_ARG;
    R(3) = m32(ram, f + R(0));
    TST(R(3), R(3));
    if (R(3) == 0) goto done;
    R(0) = BUDGET_ARG;
    R(2) = m32(ram, f + R(0));
    R(0) = BUDGET_ARG;
    R(2) -= 1;
    w32(ram, f + R(0), R(2));
    R(0) = m32(ram, f);
    TST(R(0), 4);
    R(9) = 88;                                         /* delay slot of the bt/s below */
    if (!(R(VF3_REG_SR) & 1u)) goto store_flags;
    R(2) = 0x0C092AD6u;
    R(6) = R(15);
    R(5) = R(14);
    R(6) += 4;
    R(4) = R(13);
    CALLK(0x8C092AD6u, 0x8C092858u);
    w32(ram, f + 8, R(0));
    R(0) = m32(ram, f);
    TST(R(0), 64);
    R(4) = (R(VF3_REG_SR) & 1u) ? 1u : 0u;
    R(0) = m32(ram, f);
    TST(R(0), 32);
    if (R(VF3_REG_SR) & 1u) goto make_pose;
    /* flag 0x20: copy the previous pose into this one and move on */
    R(0) = 92;
    F(3) = m32(ram, R(13) + R(0));
    R(0) = 116;
    w32(ram, R(13) + R(0), F(3));
    R(0) = 96;
    F(3) = m32(ram, R(13) + R(0));
    R(0) = 120;
    w32(ram, R(13) + R(0), F(3));
    R(0) = 100;
    F(3) = m32(ram, R(13) + R(0));
    R(0) = 124;
    w32(ram, R(13) + R(0), F(3));
    R(0) = 32;
    F(3) = m32(ram, f + R(0));
    R(0) = 104;
    w32(ram, R(13) + R(0), F(3));
    R(0) = 36;
    F(3) = m32(ram, f + R(0));
    R(0) = 108;
    w32(ram, R(13) + R(0), F(3));
    R(0) = 40;
    F(3) = m32(ram, f + R(0));
    R(0) = 112;
    w32(ram, R(13) + R(0), F(3));
    R(14) += 88;
    goto next_segment;

make_pose:
    R(3) = R(15);
    PUSH(R(3));
    R(2) = R(15);
    R(2) += 36;
    PUSH(R(2));
    R(0) = 112;
    PUSH(R(4));
    R(5) = R(11);
    R(3) = 0x0C09341Eu;
    R(6) = R(14);
    R(7) = m32(ram, R(15) + R(0));
    R(4) = R(13);
    CALLK(0x8C09341Eu, 0x8C0928DAu);
    R(15) += 12;
    goto run_after_pose;

run_helpers:
run_after_pose:
    F(3) = m32(ram, R(14));
    R(0) = 56;
    R(3) = R(15);
    R(3) += 32;
    w32(ram, f + R(0), F(3));
    R(0) = 4;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 60;
    R(5) = R(14);
    R(6) = R(12);
    w32(ram, f + R(0), F(3));
    R(0) = 8;
    F(3) = m32(ram, R(14) + R(0));
    R(0) = 64;
    w32(ram, f + R(0), F(3));
    PUSH(R(3));
    R(2) = R(15);
    R(2) += 60;
    PUSH(R(2));
    R(3) = 0x0C0930DEu;
    R(7) = m32(ram, R(15) + 8);
    R(4) = R(11);
    CALLK(0x8C0930DEu, 0x8C092914u);

    R(2) = R(15);
    R(2) += 64;
    PUSH(R(2));
    R(5) = R(11);
    R(3) = R(15);
    R(3) += 16;
    PUSH(R(3));
    R(6) = R(14);
    PUSH(R(12));
    R(2) = 0x0C092F1Cu;
    R(7) = R(15);
    R(7) += 28;
    R(4) = R(13);
    CALLK(0x8C092F1Cu, 0x8C092930u);

    R(3) = R(15);
    R(3) += 76;
    PUSH(R(3));
    R(5) = R(11);
    R(3) = 0x0C09302Au;
    R(6) = R(12);
    R(7) = m32(ram, R(15) + 24);
    R(4) = R(13);
    CALLK(0x8C09302Au, 0x8C092942u);

    R(0) = 80;
    R(7) = R(15);
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 68;
    R(6) = R(12);
    R(5) = R(14);
    w32(ram, R(15) + R(0), F(3));
    R(0) = 84;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 72;
    R(7) += 68;
    w32(ram, R(15) + R(0), F(3));
    R(0) = 88;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 76;
    w32(ram, R(15) + R(0), F(3));
    R(4) = R(11);
    CALLK(0x8C092A70u, 0x8C092966u);

    R(2) = R(15);
    R(2) += 24;
    R(0) = 124;
    PUSH(R(2));
    R(3) = m32(ram, R(15) + R(0));
    R(5) = R(14);
    PUSH(R(3));
    R(2) = m32(ram, R(15) + 44);
    PUSH(R(2));
    R(6) = R(15);
    R(3) = 0x0C09363Au;
    R(7) = R(15);
    R(7) += 68;
    R(6) += 80;
    R(4) = R(13);
    CALLK(0x8C09363Au, 0x8C092986u);

    R(6) = R(15);
    R(5) = R(15);
    R(7) = R(15);
    R(2) = 0x0C093768u;
    R(5) += 80;
    R(7) += 56;
    R(6) += 68;
    R(4) = R(14);
    CALLK(0x8C093768u, 0x8C092998u);

    R(0) = 0x88;
    R(7) = R(15);
    R(3) = 0x0C092E54u;
    R(7) += 56;
    R(5) = m32(ram, R(15) + R(0));
    R(6) = m32(ram, R(15) + 36);
    R(4) = R(13);
    CALLK(0x8C092E54u, 0x8C0929A8u);

    R(2) = m32(ram, R(15) + 36);
    R(0) = 68;
    R(5) = R(10);
    R(6) = R(12);
    PUSH(R(2));
    R(3) = R(15);
    R(3) += 60;
    PUSH(R(3));
    R(2) = R(15);
    R(2) += 100;
    PUSH(R(2));
    R(3) = R(15);
    R(3) += 92;
    PUSH(R(3));
    R(3) = 0x0C092B4Au;
    R(7) = m32(ram, R(15) + R(0));
    R(4) = R(14);
    CALLK(0x8C092B4Au, 0x8C0929CCu);

    R(2) = m32(ram, R(15) + 52);
    R(5) = R(11);
    R(6) = R(14);
    PUSH(R(2));
    R(3) = R(15);
    R(3) += 88;
    PUSH(R(3));
    R(2) = 0x0C092C3Eu;
    R(7) = R(15);
    R(7) += 104;
    R(4) = R(13);
    CALLK(0x8C092C3Eu, 0x8C0929E4u);

    R(0) = 44;
    R(15) += 60;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 48;
    w32(ram, R(14), F(3));
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 4;
    w32(ram, R(14) + R(0), F(3));
    R(0) = 52;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 8;
    w32(ram, R(14) + R(0), F(3));
    R(0) = 32;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 12;
    w32(ram, R(14) + R(0), F(3));
    R(0) = 36;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 16;
    w32(ram, R(14) + R(0), F(3));
    R(0) = 40;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 20;
    w32(ram, R(14) + R(0), F(3));
    R(0) = 44;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 32;
    w32(ram, R(15) + R(0), F(3));
    R(0) = 48;
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 36;
    w32(ram, R(15) + R(0), F(3));
    R(0) = 52;
    R(10) = R(14);
    F(3) = m32(ram, R(15) + R(0));
    R(0) = 40;
    w32(ram, R(15) + R(0), F(3));
    w32(ram, R(15) + 16, R(12));
store_flags:
    R(3) = m32(ram, f);
    R(0) = FLAGS_OFF;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(3));
    R(14) += R(9);
    goto next_segment;

done:
    R(15) = sp0;
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3]; R(10) = saved[4]; R(9) = saved[5];
    s->pc = pr0;
    return 1;
}
