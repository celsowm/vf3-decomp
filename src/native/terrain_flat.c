/* terrain_flat.c - SH-4 0x8C068DE4 (terrain_flat), natively.
 *
 * A plain-C transcription of the readable port src/fight/terrain_height.c
 * (`vf3_terrain_flat_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.  A self-contained FP leaf: r4 -> a 3-float normal block, fr4/fr5 =
 * x/z.  It writes the up normal (0, 1, 0) to the block and returns 0 in fr0,
 * or -0.5 when |x| or |z| exceeds 6 (the stage edge).
 *
 *   LIT_SIX 0x8C068E5C -> 6.0f
 *   LIT_HALF 0x8C068E60 -> -0.5f (the literal's bits)
 *
 * The fabs of fr4/fr5 is done by masking the sign bit off the float's bits
 * (and-imm style), exactly as the guest does.  The far-off compare sets SR's
 * T bit and, when true, loads the -0.5 literal into fr4; otherwise fr4 = 0.
 *
 * See docs/re/native_terrain_flat.md. */
#include "terrain_flat.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

#define NEG_ZERO 0x80000000u
#define LIT_SIX  0x0C068E5Cu   /* the 0x0C mirror of 0x8C068E5C */
#define LIT_HALF 0x0C068E60u   /* the 0x0C mirror of 0x8C068E60 */

void vf3_native_terrain_flat(vf3_native_aim *a)
{
    float six = load_f(a, LIT_SIX);
    F(6) = six;                                   /* fmov.s @r0,FR6 */
    R(0) = LIT_SIX & 0x0FFFFFFFu;                 /* r0 = lit(6) */
    F(4) = vf3_aim_fbits(vf3_aim_ubits(F(4)) & ~NEG_ZERO);   /* fabs x */
    F(5) = vf3_aim_fbits(vf3_aim_ubits(F(5)) & ~NEG_ZERO);   /* fabs z */
    F(7) = 0.0f;
    int far_off = (F(4) > six);
    if (!far_off) far_off = (F(5) > six);
    set_t(a, far_off);
    if (far_off) {
        R(0) = LIT_HALF & 0x0FFFFFFFu;
        F(4) = load_f(a, LIT_HALF);               /* -0.5 */
    } else {
        F(4) = F(7);                              /* 0 */
    }
    R(0) = 8;
    store_f(a, R(4) + 8, F(7));                   /* normal z = 0 */
    R(0) = 4;
    store_f(a, R(4), F(7));                       /* normal x = 0 */
    F(3) = 1.0f;
    store_f(a, R(4) + 4, F(3));                   /* normal y = 1 */
    F(0) = F(4);
}
