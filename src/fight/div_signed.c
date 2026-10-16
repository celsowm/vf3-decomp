/* div_signed.c - 0x8C042D7C  signed 32-bit division, r1 / r0, by the SH-4 div1 step sequence.
 *
 *   In:  r1 = dividend, r0 = divisor.   Out: r1 = quotient, r0 = remainder.   r2-r4 are saved and restored.
 *   A zero divisor stores 0x44E at 0x0C1A5A60 (the game's divide-by-zero flag), returns r0 = 0 and leaves
 *   r1 alone. Otherwise a negative dividend is lowered by one, divided one bit at a time with 32 div1
 *   steps, and the remainder is corrected for the signs. The Q, M and T bits of SR are modelled exactly
 *   because the routine leaves them behind. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SR_T = 1u, SR_Q = 0x100u, SR_M = 0x200u, DIV_ZERO_FLAG = 0x0C1A5A60u, DIV_ZERO_CODE = 0x44Eu };

typedef struct { uint32_t q, m, t; } divbits;

static void div0s(divbits *b, uint32_t rm, uint32_t rn)
{
    b->q = rn >> 31;
    b->m = rm >> 31;
    b->t = b->q ^ b->m;
}

/* one non-restoring step: shift T into rn, subtract or add the divisor, derive the new Q and T */
static void div1(divbits *b, uint32_t rm, uint32_t *rn)
{
    const uint32_t old_q = b->q, shifted = *rn >> 31, before = (*rn << 1) | b->t;
    uint32_t after, tmp1;
    if (old_q == b->m) { after = before - rm; tmp1 = after > before; }
    else               { after = before + rm; tmp1 = after < before; }
    b->q = tmp1 ^ shifted ^ b->m;
    b->t = (b->q == b->m);
    *rn = after;
}

static void rotcl(divbits *b, uint32_t *r)
{
    const uint32_t out = *r >> 31;
    *r = (*r << 1) | b->t;
    b->t = out;
}

static void subc(divbits *b, uint32_t rm, uint32_t *rn)
{
    const uint32_t before = *rn, diff = before - rm, after = diff - b->t;
    *rn = after;
    b->t = (before < diff) || (diff < after);
}

int vf3_div_signed_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15), divisor = R(0);
    divbits b = { (R(VF3_REG_SR) >> 8) & 1u, (R(VF3_REG_SR) >> 9) & 1u, R(VF3_REG_SR) & 1u };

    w32(ram, sp - 4, R(2));                                 /* push r2 */
    if (divisor == 0) {
        w32(ram, DIV_ZERO_FLAG, DIV_ZERO_CODE);
        R(0) = 0;
        b.t = 1;                                            /* tst r0,r0 */
    } else {
        uint32_t quotient = R(1), rem = R(3), zero_extend;
        w32(ram, sp - 8, R(3));                             /* push r3, r4 */
        w32(ram, sp - 12, R(4));

        div0s(&b, 0, quotient);                             /* T = dividend sign */
        const uint32_t neg = b.t;                           /* movt r4 */
        subc(&b, rem, &rem);                                /* r3 = -T */
        subc(&b, 0, &quotient);                             /* dividend - T */
        div0s(&b, divisor, rem);
        for (int i = 0; i < 32; ++i) {
            rotcl(&b, &quotient);
            div1(&b, divisor, &rem);
        }
        div0s(&b, 0, rem);                                  /* div0s r2(=0),r3 */
        zero_extend = b.t ^ neg;                            /* movt r2 ; xor r4,r2 */
        b.t = zero_extend & 1u;                             /* rotcr r2 */
        if (b.t) {                                          /* bf skips this when T is clear */
            div0s(&b, divisor, rem);
            b.t = rem & 1u;                                 /* shar r3 */
            rem = (uint32_t)((int32_t)rem >> 1);
            div1(&b, divisor, &rem);
        }
        rem += neg;                                         /* add r4,r3 */
        R(0) = rem;
        R(1) = quotient;
    }
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~(SR_T | SR_Q | SR_M)) | (b.t ? SR_T : 0) | (b.q ? SR_Q : 0) | (b.m ? SR_M : 0);
    s->pc = R(VF3_REG_PR);
    return 1;
}
