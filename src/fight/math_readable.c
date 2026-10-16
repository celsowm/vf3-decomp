/* math_readable.c - integer division helpers of the fight engine.
 *
 *   0x8C042C20  signed 32-bit divide     r1 / r0 -> r0 (and r1)
 *   0x8C042CD4  unsigned 32-bit divide   r1 / r0 -> r0 (and r1)
 *
 * Both are the SH-4 non-restoring division idiom: prime the Q/M/T flags (div0s / div0u),
 * then rotate the dividend through T 32 times with one DIV1 step between rotations.
 * Dividing by zero stores the error code 0x44E at 0x0C1A5A60 and returns r0 = 0.
 * The originals push the scratch registers they use (r2, and r3 for the signed one);
 * those dead stack words are replayed because they are visible in RAM. */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define DIV_ERROR_ADDR 0x0C1A5A60u
#define DIV_ERROR_CODE 0x0000044Eu

typedef struct { int q, m, t; } div_flags;

/* One DIV1 step: shift the partial remainder left taking T in, then subtract or add the
 * divisor depending on whether Q and M agree. Q becomes tmp1 ^ Q' ^ M, T = (Q == M). */
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

/* The shared body: rotcl, then (div1, rotcl) 32 times. Returns the dividend register. */
static uint32_t divide_core(uint32_t dividend, uint32_t divisor, uint32_t rem, div_flags *f)
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
static void set_flags(vf3_matrix_state *s, int q, int m, int t)
{
    s->v[17] = (s->v[17] & ~0x301u) | ((uint32_t)q << 8) | ((uint32_t)m << 9) | (uint32_t)t;
}

static int divide_by_zero(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t r1)
{
    set_flags(s, (s->v[17] >> 8) & 1, (s->v[17] >> 9) & 1, 1);   /* tst r0,r0 found zero */
    vf3_mem_set_u32(ram, DIV_ERROR_ADDR, DIV_ERROR_CODE);
    s->v[0] = 0;
    s->v[1] = r1;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_div_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = s->v[15], divisor = s->v[0];
    vf3_mem_set_u32(ram, sp - 4u, s->v[2]);
    if (divisor == 0) return divide_by_zero(s, ram, DIV_ERROR_ADDR);
    vf3_mem_set_u32(ram, sp - 8u, s->v[3]);

    uint32_t dividend = s->v[1];
    const int negative = (int32_t)dividend < 0;
    dividend -= (uint32_t)negative;                  /* subc: a negative dividend loses 1 */
    div_flags f = { negative, (int)(divisor >> 31), 0 };
    f.t = f.q ^ f.m;                                 /* div0s r0, sign(dividend) */
    uint32_t quotient = divide_core(dividend, divisor, negative ? 0xFFFFFFFFu : 0u, &f);
    const int carry = quotient + (uint32_t)f.t < quotient;
    quotient += (uint32_t)f.t;                       /* addc: final carry */
    set_flags(s, f.q, f.m, carry);
    s->v[0] = s->v[1] = quotient;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_div_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    vf3_mem_set_u32(ram, s->v[15] - 4u, s->v[2]);
    if (s->v[0] == 0) return divide_by_zero(s, ram, DIV_ERROR_CODE);

    div_flags f = { 0, 0, 0 };                       /* div0u */
    const uint32_t quotient = divide_core(s->v[1], s->v[0], 0u, &f);
    set_flags(s, f.q, f.m, f.t);
    s->v[0] = s->v[1] = quotient;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C042E44 and 0x8C042D7C leave the *remainder*: the same 32 DIV1 steps as the divides, but the
 * result is the partial remainder (r3) instead of the rotated dividend. The unsigned one fixes a
 * negative partial remainder by adding the divisor back; the signed one (below) restores the
 * dividend's sign. Zero divisors report the same error word as the divides. */
static int remainder_by_zero(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    set_flags(s, (s->v[17] >> 8) & 1, (s->v[17] >> 9) & 1, 1);
    vf3_mem_set_u32(ram, DIV_ERROR_ADDR, DIV_ERROR_CODE);
    s->v[0] = 0;
    s->v[1] = DIV_ERROR_ADDR;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_mod_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = s->v[15], divisor = s->v[0];
    if (divisor == 0) {
        vf3_mem_set_u32(ram, sp - 4u, s->v[2]);
        return remainder_by_zero(s, ram);
    }
    vf3_mem_set_u32(ram, sp - 4u, s->v[3]);
    vf3_mem_set_u32(ram, sp - 8u, s->v[4]);

    div_flags f = { 0, 0, 0 };                       /* div0u */
    uint32_t dividend = s->v[1], rem = 0;
    for (int i = 0; i < 32; ++i) {
        const int carry = (int)(dividend >> 31);
        dividend = (dividend << 1) | (uint32_t)f.t;
        f.t = carry;
        div1_step(&rem, divisor, &f);
    }
    set_flags(s, f.q, f.m, f.t);
    s->v[0] = f.t ? rem : rem + divisor;             /* T clear: the partial remainder went negative */
    s->v[1] = dividend;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_mod_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = s->v[15], divisor = s->v[0];
    vf3_mem_set_u32(ram, sp - 4u, s->v[2]);
    if (divisor == 0) return remainder_by_zero(s, ram);
    vf3_mem_set_u32(ram, sp - 8u, s->v[3]);
    vf3_mem_set_u32(ram, sp - 12u, s->v[4]);

    uint32_t dividend = s->v[1];
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
    set_flags(s, f.q, f.m, f.t);
    s->v[0] = rem;
    s->v[1] = dividend;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
