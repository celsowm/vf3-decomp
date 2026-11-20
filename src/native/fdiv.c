/* fdiv.c - SH-4 0x8C0533A4: the float division / reciprocal helper, natively.
 *
 * A plain-C transcription of the readable port src/fight/readable/fdiv.c
 * (`vf3_fdiv_entry`).  An off-baseline leaf (116 B, 0x0C0533A4..0x0C053418),
 * call-free and FPU-free (beyond reading fr0's bits).  It operates on
 * `vf3_native_aim`: the flat RAM, the FR bank, the register file and SR's T
 * bit.
 *
 * The dividend's bits arrive in fr0; the entry stores them through a transient
 * stack slot (store width follows FPSCR) and pops them into r0.  A fixed-point
 * software reciprocal driven by four IEEE-754 scratch constants from the
 * literal pool then turns them into a two-word answer written to the caller's
 * two-word cell at sp+16:
 *
 *     cell[0] <- r3   the exponent / status word
 *     cell[1] <- r0   the packed result word
 *
 * The four caller-saved registers r3 r2 r1 r0 are restored from sp+0/+4/+8/+12
 * and the stack pointer ends at sp+20.  The branch is the input's exponent
 * byte (the top byte of 2*r0 masked with the pool's 0xff): 0xff -> infinity or
 * NaN, 0 -> zero or denormal, anything else -> the ordinary path.  SR's T bit
 * is part of the contract (the shared pack's carry-rotate).
 *
 * See docs/re/native_fdiv.md. */
#include "fdiv.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ uint32_t v; memcpy(&v, gb(a, addr), 4); return v; }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ memcpy(gb(a, addr), &v, 4); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ uint32_t u = vf3_aim_ubits(f); memcpy(gb(a, addr), &u, 4); }
static void wr64f(vf3_native_aim *a, uint32_t addr, double d)
{ memcpy(gb(a, addr), &d, 8); }

static void set_t(vf3_native_aim *a, int value)
{ a->sr = (a->sr & ~1u) | (value != 0); }

/* The rotate-through-carry step the guest's `rotcr Rn` performs: the bit
 * shifted out goes into T and the old T comes in at bit 31.  `a->sr & 1` is
 * the live T bit, which set_t keeps in step. */
static void rotcr(vf3_native_aim *a, uint32_t *x)
{
    uint32_t out = (*x) & 1u;
    *x = ((*x) >> 1u) | (((a->sr & 1u) != 0) << 31u);
    set_t(a, out);
}

/* The function's tail: hand the computed result (res_r3, res_r0) to the
 * caller's cell, then restore the four caller-saved registers from the stack
 * and advance r15 from the entry sp to S+20. */
static void tail(vf3_native_aim *a, uint32_t res_r0, uint32_t res_r3,
                 uint32_t r15)
{
    uint32_t r2 = rd32(a, r15 + 16u);   /* the result cell */
    wr32(a, r2, res_r3);
    wr32(a, r2 + 4u, res_r0);

    uint32_t rr;
    rr = rd32(a, r15); r15 += 4u; R(3) = rr;
    rr = rd32(a, r15); r15 += 4u; R(2) = rr;
    rr = rd32(a, r15); r15 += 4u; R(1) = rr;
    rr = rd32(a, r15); r15 += 4u; R(0) = rr;
    r15 += 4u;                                  /* the rts delay slot */

    R(15) = r15;
}

/* The shared pack: from the unpacked mantissa/result accumulator r0, the
 * exponent/status word r1 (already biased) and the raw input r2, do the
 * carry-rotate accumulate and the exponent pack, then fall into the tail. */
static void pack(vf3_native_aim *a, uint32_t r0, uint32_t r1, uint32_t r2,
                 uint32_t r3, uint32_t r15)
{
    r0 >>= 8u;                                  /* 0x533c6 */
    set_t(a, r0 & 1u); r0 >>= 1u;               /* 0x533c8 */
    set_t(a, r0 & 1u); r0 >>= 1u;               /* 0x533ca */
    rotcr(a, &r3);                              /* 0x533cc */
    set_t(a, r0 & 1u); r0 >>= 1u;               /* 0x533ce */
    rotcr(a, &r3);                              /* 0x533d0 */
    set_t(a, r2 >> 31); r2 <<= 1u;              /* 0x533d2 shll r2 */
    rotcr(a, &r0);                              /* 0x533d4 */
    rotcr(a, &r3);                              /* 0x533d6 */
    r1 <<= 16u; r1 <<= 2u; r1 <<= 2u;           /* r1 <<= 20 */
    r0 |= r1;                                   /* 0x533de */
    tail(a, r0, r3, r15);
}

void vf3_native_fdiv(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    uint32_t r0, r1, r2, r3, r15;

    /* the entry: fmov.s fr0,@-r15 / mov.l @r15+,r0 - the input travels
     * through a transient stack slot exactly as the guest stores and reloads
     * it (the store width follows FPSCR; single here). */
    r15 = R(15);
    const unsigned w = (a->fpscr & 0x100000u) ? 8u : 4u;
    r15 -= w;
    if (w == 4) wr32f(a, r15, F(0));
    else        { double d = F(0); wr64f(a, r15, d); }
    r0 = rd32(a, r15);
    r15 += 4u;

    r3 = rd32(a, 0x0c053418u);                  /* 0xff  the exponent mask */
    r2 = r0;                                    /* keep the raw input */
    set_t(a, r0 >> 31); r0 <<= 1u;              /* 0x533ac shll r0 */
    r1 = r0;
    r1 >>= 16u;
    r1 >>= 8u;                                  /* r1 = top byte of 2*r0 */
    r1 &= r3;
    r0 <<= 8u;                                  /* r0 = the unpacked mantissa */

    set_t(a, r1 == r3);                         /* exponent all ones? */
    if (a->sr & 1u) {
        /* infinity or NaN */
        set_t(a, r0 == 0);                      /* is the mantissa zero? */
        if (r0 != 0) {
            /* NaN: quiet-NaN constant, status 1, straight to the tail */
            r0 = rd32(a, 0x0c053424u);          /* 0x7ff00000 */
            r3 = 1u;
            tail(a, r0, r3, r15);
            return;
        }
        /* infinity: exponent becomes 0x7ff, then the shared pack */
        r1 = rd32(a, 0x0c053420u);              /* 0x7ff */
        pack(a, r0, r1, r2, 0u, r15);
        return;
    }

    set_t(a, r1 == 0);                          /* exponent zero? */
    if (a->sr & 1u) {
        /* zero or denormal */
        set_t(a, r0 == 0);
        if (r0 == 0) {
            /* zero: exponent stays 0, then the shared pack */
            pack(a, r0, 0u, r2, 0u, r15);
            return;
        }
        /* normalize: shift the mantissa up until a one leaves the top,
         * counting the shift down in r1.  The lead-out shift and its test
         * (0x53406/0x53408) run once; the loop body is dec, shift, test
         * (0x5340a/0x5340c/0x5340e), and the loop back edge returns to the
         * *decrement*, not to the lead-out shift. */
        set_t(a, r0 >> 31); r0 <<= 1u;          /* 0x53406 */
        if (a->sr & 1u) goto normalized;        /* 0x53408 */
        for (;;) {
            r1 += 0xffffffffu;                  /* 0x5340a */
            set_t(a, r0 >> 31); r0 <<= 1u;      /* 0x5340c */
            if (!(a->sr & 1u)) continue;        /* 0x5340e -> 0x5340a */
            break;
        }
    normalized:                                 /* 0x53410 */
        ;
    }

    /* ordinary path: bias the exponent, then the shared pack */
    r3 = rd32(a, 0x0c053428u);                  /* 0x380 */
    r1 += r3;
    pack(a, r0, r1, r2, 0u, r15);
}
