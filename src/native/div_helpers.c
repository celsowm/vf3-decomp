/* div_helpers.c - the integer division helpers of the fight engine, natively.
 *
 * A plain-C transcription of the readable port src/fight/math_readable.c onto
 * `vf3_native_aim`: the flat RAM and the register file.
 *
 *  0x8C042C20  signed 32-bit divide     r1 / r0 -> r0 (and r1)
 *  0x8C042CD4  unsigned 32-bit divide   r1 / r0 -> r0 (and r1)
 *  0x8C042E44  unsigned 32-bit remainder r1 / r0 -> r0 = remainder, r1 = dividend
 *  0x8C042D7C  signed 32-bit remainder  r1 / r0 -> r0 = remainder, r1 = dividend
 *
 * All four are the SH-4 non-restoring division idiom: prime the Q/M/T flags
 * (div0s / div0u), then rotate the dividend through T 32 times with one DIV1
 * step between rotations.  Dividing by zero stores the error code 0x44E at
 * 0x0C1A5A60 and returns r0 = 0.
 *
 * The originals push the scratch registers they use (r2, r3, r4); those dead
 * stack words are replayed because they are visible in RAM.  SR keeps the DIV
 * flags: T = bit 0, Q = bit 8, M = bit 9.  See docs/re/native_div_helpers.md. */
#include "div_helpers.h"

#include <stdint.h>

#define R(n) (a->r[(n)])
#define SR  (a->sr)

#define DIV_ERROR_ADDR 0x0C1A5A60u
#define DIV_ERROR_CODE 0x0000044Eu

typedef struct { int q, m, t; } div_flags;

static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v) { vf3_aim_set_u32(a, addr, v); }

/* One DIV1 step: shift the partial remainder left taking T in, then subtract
 * or add the divisor depending on whether Q and M agree.  Q becomes
 * tmp1 ^ Q' ^ M, T = (Q == M). */
static void div1_step(uint32_t *rn, uint32_t divisor, div_flags *f)
{
    const int old_q = f->q;
    f->q = (int)(*rn >> 31);
    *rn = (*rn << 1) | (uint32_t)f->t;
    const uint32_t before = *rn;
    int overflow;
    if (old_q == f->m) { *rn -= divisor; overflow = *rn > before; }
    else               { *rn += divisor; overflow = *rn < before; }
    f->q = overflow ^ f->q ^ f->m;
    f->t = f->q == f->m;
}

/* The shared body: rotcl, then (div1, rotcl) 32 times.  Returns the dividend
 * register. */
static uint32_t divide_core(uint32_t dividend, uint32_t divisor, uint32_t rem,
                            div_flags *f)
{
    for (int i = 0; i < 33; ++i) {
        const int carry = (int)(dividend >> 31);
        dividend = (dividend << 1) | (uint32_t)f->t;
        f->t = carry;
        if (i < 32) div1_step(&rem, divisor, f);
    }
    return dividend;
}

/* SR keeps the DIV flags: T = bit 0, Q = bit 8, M = bit 9. */
static void set_flags(vf3_native_aim *a, int q, int m, int t)
{
    a->sr = (a->sr & ~0x301u) | ((uint32_t)q << 8) | ((uint32_t)m << 9) | (uint32_t)t;
}

/* The divide-by-zero tail (shared by the two divides; r1v is the error value
 * they leave in r1 - the error *address* for the signed one, the error code
 * for the unsigned one). */
static void div_zero(vf3_native_aim *a, uint32_t r1v)
{
    set_flags(a, (SR >> 8) & 1, (SR >> 9) & 1, 1);   /* tst r0,r0 found zero */
    wr32(a, DIV_ERROR_ADDR, DIV_ERROR_CODE);
    R(0) = 0;
    R(1) = r1v;
}

void vf3_native_div_s32(vf3_native_aim *a)
{
    const uint32_t sp = R(15), divisor = R(0);
    wr32(a, sp - 4u, R(2));
    if (divisor == 0) { div_zero(a, DIV_ERROR_ADDR); return; }
    wr32(a, sp - 8u, R(3));

    uint32_t dividend = R(1);
    const int negative = (int32_t)dividend < 0;
    dividend -= (uint32_t)negative;                  /* subc: a negative dividend loses 1 */
    div_flags f = { negative, (int)(divisor >> 31), 0 };
    f.t = f.q ^ f.m;                                 /* div0s r0, sign(dividend) */
    uint32_t quotient = divide_core(dividend, divisor, negative ? 0xFFFFFFFFu : 0u, &f);
    const int carry = quotient + (uint32_t)f.t < quotient;
    quotient += (uint32_t)f.t;                       /* addc: final carry */
    set_flags(a, f.q, f.m, carry);
    R(0) = R(1) = quotient;
}

void vf3_native_div_u32(vf3_native_aim *a)
{
    wr32(a, R(15) - 4u, R(2));
    if (R(0) == 0) { div_zero(a, DIV_ERROR_CODE); return; }

    div_flags f = { 0, 0, 0 };                       /* div0u */
    const uint32_t quotient = divide_core(R(1), R(0), 0u, &f);
    set_flags(a, f.q, f.m, f.t);
    R(0) = R(1) = quotient;
}

void vf3_native_mod_u32(vf3_native_aim *a)
{
    const uint32_t sp = R(15), divisor = R(0);
    if (divisor == 0) {
        wr32(a, sp - 4u, R(2));
        set_flags(a, (SR >> 8) & 1, (SR >> 9) & 1, 1);
        wr32(a, DIV_ERROR_ADDR, DIV_ERROR_CODE);
        R(0) = 0;
        R(1) = DIV_ERROR_ADDR;
        return;
    }
    wr32(a, sp - 4u, R(3));
    wr32(a, sp - 8u, R(4));

    div_flags f = { 0, 0, 0 };                       /* div0u */
    uint32_t dividend = R(1), rem = 0;
    for (int i = 0; i < 32; ++i) {
        const int carry = (int)(dividend >> 31);
        dividend = (dividend << 1) | (uint32_t)f.t;
        f.t = carry;
        div1_step(&rem, divisor, &f);
    }
    set_flags(a, f.q, f.m, f.t);
    R(0) = f.t ? rem : rem + divisor;                /* T clear: the partial remainder went negative */
    R(1) = dividend;
}

void vf3_native_mod_s32(vf3_native_aim *a)
{
    const uint32_t sp = R(15), divisor = R(0);
    wr32(a, sp - 4u, R(2));
    if (divisor == 0) {
        set_flags(a, (SR >> 8) & 1, (SR >> 9) & 1, 1);
        wr32(a, DIV_ERROR_ADDR, DIV_ERROR_CODE);
        R(0) = 0;
        R(1) = DIV_ERROR_ADDR;
        return;
    }
    wr32(a, sp - 8u, R(3));
    wr32(a, sp - 12u, R(4));

    uint32_t dividend = R(1);
    const uint32_t negative = dividend >> 31;        /* r4: the dividend's sign */
    dividend -= negative;                            /* a negative dividend loses 1 first */
    uint32_t rem = 0u - negative;                    /* sign-extended into the partial remainder */
    div_flags f = { (int)negative, (int)(divisor >> 31), 0 };
    f.t = f.q ^ f.m;                                 /* div0s r0, r3 */
    for (int i = 0; i < 32; ++i) {
        const int carry = (int)(dividend >> 31);
        dividend = (dividend << 1) | (uint32_t)f.t;
        f.t = carry;
        div1_step(&rem, divisor, &f);
    }
    f.q = (int)(rem >> 31);                          /* div0s r2(=0), r3 */
    f.m = 0;
    f.t = f.q;
    const uint32_t mismatch = (f.t ^ negative) & 1u; /* remainder sign differs from the dividend's */
    f.t = (int)mismatch;                             /* rotcr */
    if (mismatch) {
        f.q = (int)(rem >> 31);                      /* div0s r0, r3 */
        f.m = (int)(divisor >> 31);
        f.t = f.q ^ f.m;
        f.t = (int)(rem & 1u);                       /* shar r3 */
        rem = (uint32_t)((int32_t)rem >> 1);
        div1_step(&rem, divisor, &f);                /* one more step restores the remainder */
    }
    rem += negative;
    set_flags(a, f.q, f.m, f.t);
    R(0) = rem;
    R(1) = dividend;
}
