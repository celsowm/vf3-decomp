/* vec_add_pair.c - SH-4 0x8C092A70 (vec_add_pair), natively.
 *
 * A plain-C transcription of the readable port src/fight/vec_add_pair.c
 * (`vf3_vec_add_pair_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.  A self-contained FP leaf:
 *
 *   r4 = object (its byte at +97 gates the first add)
 *   r5 = vector A, r6 = vector B, r7 = destination vector D (all x, y, z)
 *
 * Unless the global word at 0x0C29B868 carries bit 0x04000000 **and** the byte
 * at r4 + 97 is 11, D += A + 24 (the vector 24 bytes into A, the third of a
 * 12-byte-stride array).  Then, unconditionally, D.y += B.y.
 *
 * The float adds go through the round-toward-zero + FTZ wrapper (the corpus
 * FPSCR 0x00024001 - RM=truncate and FTZ - is in force).
 *
 * When the first add runs, r4 ends = D and r5 = A + 36; the FR bank leaves
 * fr0/fr1/fr2 = the D vector and fr3/fr4/fr5 = the (A+24) vector (the
 * `fadd`-or-kept operands), and the final `D.y += B.y` overwrites fr2 with the
 * combined y and fr3 with B.y.  When the add is skipped, r4/r5/fr0/fr1/fr4/fr5
 * stay as they came in.
 *
 * See docs/re/native_vec_add_pair.md. */
#include "vec_add_pair.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as float_scale.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fadd(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x + y;
    fesetround(saved);
    return flz(a, z);
}

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

#define GATE_GLOBAL 0x0C29B868u
#define GATE_BIT    0x04000000u

void vf3_native_vec_add_pair(vf3_native_aim *a)
{
    const uint32_t sp = R(15);
    const uint32_t A = R(5), B = R(6), D = R(7);
    vf3_aim_set_u32(a, sp - 4u, A);      /* a @ f + 8 */
    vf3_aim_set_u32(a, sp - 8u, B);      /* b @ f + 4 */
    vf3_aim_set_u32(a, sp - 12u, D);     /* d @ f + 0 */

    uint32_t gate = vf3_aim_u32(a, GATE_GLOBAL);
    set_t(a, (gate & GATE_BIT) == 0);
    int add_first = 1;
    if (!(a->sr & 1u)) {
        uint8_t b = vf3_aim_u8(a, R(4) + 97);
        set_t(a, b == 11);
        if (a->sr & 1u) add_first = 0;
    }

    if (add_first) {
        uint32_t pa = A + 24;
        uint32_t pd = D;
        F(0) = load_f(a, pd); pd += 4;
        F(3) = load_f(a, pa); pa += 4;
        F(1) = load_f(a, pd); pd += 4;
        F(4) = load_f(a, pa); pa += 4;
        F(2) = load_f(a, pd); pd += 4;
        F(5) = load_f(a, pa); pa += 4;
        F(0) = fadd(a, F(0), F(3));
        F(2) = fadd(a, F(2), F(5));
        F(1) = fadd(a, F(1), F(4));
        pd -= 4; store_f(a, pd, F(2));
        pd -= 4; store_f(a, pd, F(1));
        pd -= 4; store_f(a, pd, F(0));
        R(4) = D;
        R(5) = A + 36;
    }

    R(3) = B;                 /* r3 = b (the caller's B) */
    R(0) = 4;
    R(1) = R(0) + B;          /* r1 = B + 4 */
    R(2) = D;
    F(2) = load_f(a, R(2) + R(0));
    F(3) = load_f(a, R(1));
    F(2) = fadd(a, F(2), F(3));
    store_f(a, R(2) + R(0), F(2));
    R(15) = sp;
}
