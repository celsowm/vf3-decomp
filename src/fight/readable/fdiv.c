/* fdiv.c - SH-4 0x8C0533A4: the float division / reciprocal helper.
 *
 * The engine calls this off-baseline leaf with the dividend's float
 * bit-pattern already waiting in fr0, and a pointer to a two-word result cell
 * sat in the caller's frame at sp+16.  The entry stores fr0 on the stack and
 * pops it into r0 (so the input arrives through a transient stack slot, and
 * the store's width follows FPSCR - single here), then runs a fixed-point
 * software reciprocal driven by the four IEEE-754 scratch constants in its
 * own literal pool:
 *
 *     0x0c053418 = 0x000000ff    the 8-bit exponent mask
 *     0x0c053424 = 0x7ff00000    the quiet-NaN constant
 *     0x0c053420 = 0x000007ff    the infinity exponent
 *     0x0c053428 = 0x00000380    the exponent bias adjustment
 *
 * The answer is written into the caller's two-word cell:
 *
 *     cell[0] <- r3   the exponent / status word
 *     cell[1] <- r0   the packed result word
 *
 * and the four caller-saved registers are restored from the stack before the
 * return, so r0..r3 come back holding the caller's saved values, not the
 * computed ones.
 *
 * The three decisions the body makes are all about the input's exponent byte
 * (the top byte of 2*r0 masked with 0xff):
 *
 *   * exponent 0xff -> infinity or NaN: a zero mantissa takes the infinity
 *     exponent (0x7ff) and the shared pack; anything else takes the
 *     quiet-NaN constant (0x7ff00000) with status 1, straight to the tail;
 *   * exponent 0    -> zero or denormal: a zero mantissa takes exponent 0 and
 *     the shared pack; a non-zero one is shifted left, counting down r1, until
 *     a one leaves the top, then re-enters the ordinary path (which is why the
 *     denormal re-enters at the exponent-bias point);
 *   * anything else  -> the ordinary path: r1 is biased by the pool's 0x380,
 *     and the pack's rotate/accumulate turns the mantissa and the bias into
 *     the result.
 *
 * The pack itself (the shared tail) is carried-rotate arithmetic on r0/r2/r3
 * with the T bit as the rotate-through bit, so the whole guest register file
 * - including SR and the caller-saved registers - is part of the contract.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* The rotate-through-carry step the guest's `rotcr Rn` performs: the bit
 * shifted out goes into T and the old T comes in at bit 31.  `R(17)&1` is the
 * live T bit, which set_t keeps in step. */
static void rotcr(vf3_matrix_state *s, uint32_t *x)
{
    uint32_t out = (*x) & 1u;
    *x = ((*x) >> 1u) | (((R(17) & 1u) != 0) << 31u);
    set_t(s, out);
}

/* The function's tail: hand the computed result (res_r3, res_r0) to the
 * caller's cell, then restore the four caller-saved registers from the stack
 * and return.  r15 comes in at the entry sp and leaves S+20. */
static int tail(vf3_matrix_state *s, const vf3_ram_map *ram,
                uint32_t res_r0, uint32_t res_r3, uint32_t r15)
{
    uint32_t r2 = vf3_mem_u32(ram, r15 + 16u);   /* the result cell */
    vf3_mem_set_u32(ram, r2, res_r3);
    vf3_mem_set_u32(ram, r2 + 4u, res_r0);

    uint32_t rr;
    rr = vf3_mem_u32(ram, r15); r15 += 4u; R(3) = rr;
    rr = vf3_mem_u32(ram, r15); r15 += 4u; R(2) = rr;
    rr = vf3_mem_u32(ram, r15); r15 += 4u; R(1) = rr;
    rr = vf3_mem_u32(ram, r15); r15 += 4u; R(0) = rr;
    r15 += 4u;                                  /* the rts delay slot */

    R(15) = r15;
    s->pc = R(16);                              /* the caller's return address */
    return ram->oob == 0;
}

/* The shared pack: from the unpacked mantissa/result accumulator r0, the
 * exponent/status word r1 (already biased) and the raw input r2, do the
 * carry-rotate accumulate and the exponent pack, then fall into the tail.
 * r3 is the rotate accumulator and is zero on every path that reaches it. */
static int pack(vf3_matrix_state *s, const vf3_ram_map *ram,
                uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3,
                uint32_t r15)
{
    r0 >>= 8u;                                  /* 0x533c6 */
    set_t(s, r0 & 1u); r0 >>= 1u;               /* 0x533c8 */
    set_t(s, r0 & 1u); r0 >>= 1u;               /* 0x533ca */
    rotcr(s, &r3);                              /* 0x533cc */
    set_t(s, r0 & 1u); r0 >>= 1u;               /* 0x533ce */
    rotcr(s, &r3);                              /* 0x533d0 */
    set_t(s, r2 >> 31); r2 <<= 1u;              /* 0x533d2 shll r2 */
    rotcr(s, &r0);                              /* 0x533d4 */
    rotcr(s, &r3);                              /* 0x533d6 */
    r1 <<= 16u; r1 <<= 2u; r1 <<= 2u;           /* r1 <<= 20 */
    r0 |= r1;                                   /* 0x533de */
    return tail(s, ram, r0, r3, r15);
}

int vf3_fdiv_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t r0, r1, r2, r3, r15;

    /* the entry: fmov.s fr0,@-r15 / mov.l @r15+,r0 - the input travels
     * through a transient stack slot exactly as the guest stores and reloads
     * it (the store width follows FPSCR; single here). */
    r15 = R(15);
    r15 -= (R(18) & 0x100000u) ? 8u : 4u;
    vf3_matrix_store(s, ram, 0, r15);
    r0 = vf3_mem_u32(ram, r15);
    r15 += 4u;

    r3 = vf3_mem_u32(ram, 0x0c053418u);         /* 0xff  the exponent mask */
    r2 = r0;                                    /* keep the raw input */
    set_t(s, r0 >> 31); r0 <<= 1u;              /* 0x533ac shll r0 */
    r1 = r0;
    r1 >>= 16u;
    r1 >>= 8u;                                  /* r1 = top byte of 2*r0 */
    r1 &= r3;
    r0 <<= 8u;                                  /* r0 = the unpacked mantissa */

    set_t(s, r1 == r3);                         /* exponent all ones? */
    if (R(17) & 1u) {
        /* 0x533f2: infinity or NaN */
        set_t(s, r0 == 0);                      /* is the mantissa zero? */
        if (r0 != 0) {
            /* NaN: quiet-NaN constant, status 1, straight to the tail */
            r0 = vf3_mem_u32(ram, 0x0c053424u);         /* 0x7ff00000 */
            r3 = 1u;
            return tail(s, ram, r0, r3, r15);
        }
        /* infinity: exponent becomes 0x7ff, then the shared pack */
        r1 = vf3_mem_u32(ram, 0x0c053420u);             /* 0x7ff */
        return pack(s, ram, r0, r1, r2, 0u, r15);
    }

    set_t(s, r1 == 0);                          /* exponent zero? */
    if (R(17) & 1u) {
        /* 0x53402: zero or denormal */
        set_t(s, r0 == 0);
        if (r0 == 0) {
            /* zero: exponent stays 0, then the shared pack */
            return pack(s, ram, r0, 0u, r2, 0u, r15);
        }
        /* normalize: shift the mantissa up until a one leaves the top,
         * counting the shift down in r1.  The lead-out shift and its test
         * (0x53406/0x53408) run once; the loop body is dec, shift, test
         * (0x5340a/0x5340c/0x5340e), and the loop back edge returns to the
         * *decrement*, not to the lead-out shift. */
        set_t(s, r0 >> 31); r0 <<= 1u;              /* 0x53406 */
        if (R(17) & 1u) goto normalized;            /* 0x53408 */
        for (;;) {
            r1 += 0xffffffffu;                      /* 0x5340a */
            set_t(s, r0 >> 31); r0 <<= 1u;          /* 0x5340c */
            if (!(R(17) & 1u)) continue;            /* 0x5340e -> 0x5340a */
            break;
        }
    normalized:                                     /* 0x53410 */
        ;
    }

    /* ordinary path: bias the exponent, then the shared pack */
    r3 = vf3_mem_u32(ram, 0x0c053428u);         /* 0x380 */
    r1 += r3;
    return pack(s, ram, r0, r1, r2, 0u, r15);
}
