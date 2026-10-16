/* aim_step.c - 0x8C093768  push a point along the direction between two points.
 *
 *   r4 -> a context whose float at +36 is the step length, r5 -> point A (vec3, updated in place),
 *   r6 -> point B (vec3), r7 -> vec3 receiving the unit direction.
 *
 *   d = A - B is stored to *r7; its inverse length comes from fsrra (zero when d is zero or its squared
 *   length is below 1e-7). Then A = d * (inverse length * step) + B and *r7 = d * inverse length, so A ends
 *   up the step length away from B on the same line and *r7 is the unit direction from B to A.
 *
 *   Frame (8 bytes under r14, r13 and FR15): +0 the second point, +4 the context. */
#include <string.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 12, FRAME = 8, LIT = 0x33D6BF94u, STEP = 36 };

static float lit(void) { const uint32_t b = LIT; float x; memcpy(&x, &b, 4); return x; }

int vf3_aim_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r14 = R(14), saved_r13 = R(13), saved_f15 = F(15);
    const uint32_t ctx = R(4), a = R(5), b = R(6), out = R(7);

    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, saved_r13);
    w32(ram, sp0 - 12, saved_f15);
    R(14) = out; R(13) = a;
    R(15) = f;
    w32(ram, f + 4, ctx);
    w32(ram, f, b);

    F(0) = m32(ram, a); F(3) = m32(ram, b);
    F(1) = m32(ram, a + 4); F(4) = m32(ram, b + 4);
    FSUB(0, 3);
    F(2) = m32(ram, a + 8); F(5) = m32(ram, b + 8);
    FSUB(1, 4);
    FSUB(2, 5);
    w32(ram, out + 8, F(2));
    w32(ram, out + 4, F(1));
    w32(ram, out, F(0));

    F(0) = m32(ram, out); F(1) = m32(ram, out + 4); F(2) = m32(ram, out + 8); F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    FMOV(0, 3);
    F(3) = 0;
    FMOV(15, 0);
    if (fl(s, 15) != fl(s, 3)) {
        R(0) = 0x0C0937D0u;
        F(2) = LIT;
        if (fl(s, 2) > fl(s, 15)) FMOV(15, 3);
        else if (!vf3_fpu_fsrra(F(15), R(VF3_REG_FPSCR), &F(15))) return 0;
    }

    R(3) = m32(ram, f + 4);
    R(0) = STEP;
    FMOV(4, 15);
    F(3) = m32(ram, R(3) + STEP);
    FMUL(4, 3);

    F(0) = m32(ram, out); F(1) = m32(ram, out + 4); F(2) = m32(ram, out + 8);
    FMUL(2, 4); FMUL(1, 4); FMUL(0, 4);
    w32(ram, a + 8, F(2)); w32(ram, a + 4, F(1)); w32(ram, a, F(0));

    FMOV(4, 15);
    F(0) = m32(ram, out); F(1) = m32(ram, out + 4); F(2) = m32(ram, out + 8);
    FMUL(2, 4); FMUL(1, 4); FMUL(0, 4);
    w32(ram, out + 8, F(2)); w32(ram, out + 4, F(1)); w32(ram, out, F(0));

    const uint32_t bp = m32(ram, f);
    F(0) = m32(ram, a); F(3) = m32(ram, bp);
    F(1) = m32(ram, a + 4); F(4) = m32(ram, bp + 4);
    F(2) = m32(ram, a + 8); F(5) = m32(ram, bp + 8);
    FADD(0, 3); FADD(2, 5); FADD(1, 4);
    w32(ram, a + 8, F(2)); w32(ram, a + 4, F(1)); w32(ram, a, F(0));

    R(4) = a;
    R(5) = bp + 12;
    R(14) = saved_r14; R(13) = saved_r13; F(15) = saved_f15;
    R(15) = sp0;
    s->pc = R(VF3_REG_PR);
    return 1;
}
