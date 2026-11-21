/* terrain_wrap.c - SH-4 0x8C068D54 (terrain_wrap), natively.
 *
 * A plain-C transcription of the readable port src/fight/terrain_height.c
 * (`vf3_terrain_wrap_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.  A self-contained FP leaf: r4 = stage type, r5 -> x, r6 -> z (floats).
 *
 *   type 2/7 : x *= 0.769, z *= 0.769     (LIT_SCALE  0x8C068E50)
 *   type 13  : x and z are folded into a 10-unit repeating cell:
 *                n = trunc(v * 0.1);  rounded half-away to an even cell
 *                count;  v -= n * 10
 *   other    : x and z left alone
 *
 * The fold ("round half away to an even count of cells") is the shared
 * `fold_axis` step: it reads the count from a register (r4 for x, r7 for z),
 * makes it even (adding or subtracting 1 when odd), scales it by ten and
 * subtracts that from the stored value, so the value lands in a 10-unit cell.
 *
 * The float arithmetic goes through the round-toward-zero + FTZ wrappers (the
 * corpus FPSCR 0x00024001 is in force) for the mul/sub, and the trunc is the
 * SH-4's toward-zero float-to-int.  See docs/re/native_terrain_wrap.md. */
#include "terrain_wrap.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as terrain_flat.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = (op == '*') ? x * y : x - y;
    fesetround(saved);
    return flz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }

static float load_f(vf3_native_aim *a, uint32_t addr) { return vf3_aim_fbits(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, vf3_aim_ubits(f)); }

#define NEG_ZERO 0x80000000u
#define LIT_SCALE 0x0C068E50u   /* 0.769, the 0x0C mirror of 0x8C068E50 */
#define LIT_TENTH 0x0C068E54u   /* 0.1,   the 0x0C mirror of 0x8C068E54 */

/* the "round half away to an even count of cells" step shared by both axes of
 * type 13: cnt is read from r[cnt_reg], made even, scaled by ten, and the
 * stored value at addr is reduced by it. */
static void fold_axis(vf3_native_aim *a, int cnt_reg, uint32_t addr)
{
    uint32_t cnt = R(cnt_reg);
    if (cnt == 0) return;
    R(2) = 1;
    if ((cnt & 1u) != 0) {
        R(1) = NEG_ZERO;
        if ((cnt & NEG_ZERO) == 0) cnt += 1; else cnt -= 1;
        R(cnt_reg) = cnt;
    }
    uint32_t c = R(cnt_reg);
    R(3) = c;
    c = (c << 2) + c;            /* * 5 */
    float v = load_f(a, addr);
    c <<= 1;                     /* * 10 */
    R(cnt_reg) = c;
    a->fpul = c;
    float ic;
    {
        const int saved = fegetround();
        fesetround(FE_TOWARDZERO);
        volatile float conv = (float)(int32_t)c;
        fesetround(saved);
        ic = conv;
    }
    F(3) = ic;
    F(4) = F(3);
    float r = fsub(a, v, ic);
    store_f(a, addr, r);
    F(2) = r;
}

void vf3_native_terrain_wrap(vf3_native_aim *a)
{
    uint32_t type = R(4);
    R(0) = type;
    if (type == 2 || type == 7) {
        R(0) = LIT_SCALE & 0x0FFFFFFFu;
        F(3) = load_f(a, R(5));
        F(4) = load_f(a, LIT_SCALE);
        F(3) = fmul(a, F(3), F(4));
        store_f(a, R(5), F(3));
        F(2) = load_f(a, R(6));
        F(2) = fmul(a, F(2), F(4));
        store_f(a, R(6), F(2));
    } else if (type == 13) {
        R(0) = LIT_TENTH & 0x0FFFFFFFu;
        F(4) = load_f(a, R(5));
        F(5) = load_f(a, LIT_TENTH);
        F(4) = fmul(a, F(5), F(4));
        F(3) = F(5);
        F(5) = load_f(a, R(6));
        F(5) = fmul(a, F(3), F(5));
        /* trunc fpul <- fr4, then r4 = fpul */
        {
            const int saved = fegetround();
            fesetround(FE_TOWARDZERO);
            volatile float tx = F(4);
            volatile float tz = F(5);
            fesetround(saved);
            a->fpul = (uint32_t)(int32_t)tx;
            R(4) = a->fpul;
            a->fpul = (uint32_t)(int32_t)tz;
            R(7) = a->fpul;
        }
        uint32_t px = R(5), pz = R(6);
        fold_axis(a, 4, px);
        fold_axis(a, 7, pz);
    }
}
