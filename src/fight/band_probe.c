/* band_probe.c - SH-4 0x8C0B0F28: a point against a band, and the flags it
 * writes.
 *
 * The function is handed a point in three registers - r4, r5 and r6 - and a
 * band in the literal pool.  It takes the two differences the point makes with
 * its third coordinate, masks them, and asks whether they are inside the
 * band.
 *
 *   r4 - r6 and r5 - r6 are the two differences.  The mask from the pool
 *   (0x8C0B0F90) is xored into them and the low halfword is read back as a
 *   signed number, so the pool alone decides what a masked difference is.
 *
 *   The band is two halfwords in the pool: the low one at 0x8C0B0F64 and the
 *   high one at 0x8C0B0F66.  The guest tests the high bound first and the low
 *   one second, so a value below the low bound is never tested against the
 *   high one.
 *
 * When both differences are inside the band the guest sets the inside bit
 * (0x8C0B0F68) in the word it was handed and answers one.  When one of them
 * is outside, the guest asks the seventh register about a word in the pool
 * (0x8C0B1088): if the two have no bit in common the answer is zero and the
 * guest stops there.  Otherwise it looks at the second difference once as it
 * is and once under the mask, and sets the first outside bit (0x8C0B108C) or
 * the second one (0x8C0B1090) for the ones that are inside the band.
 *
 * The word the flags go into is not in a register: the caller hands it over in
 * its own frame, under the two words the callee pushes.
 *
 * Three details the port has to keep: the seventh register and the word in
 * the pool are tested with `tst`, which sets the T bit; the plain `bt`/`bf`
 * the guest branches with have *no* delay slot, so the instruction after them
 * runs only on the path that falls through; and the saved r13 comes back in
 * the delay slot of the return, after the return itself has started.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define BAND_LO 0x0c0b0f64u   /* the band's low bound  (a halfword) */
#define BAND_HI 0x0c0b0f66u   /* the band's high bound (a halfword) */
#define IN_BIT  0x0c0b0f68u   /* the bit for "inside"   (a halfword) */
#define MASK    0x0c0b0f90u   /* the mask on the differences (a word) */
#define GATE    0x0c0b1088u   /* the word the seventh register is asked about */
#define OUT_A   0x0c0b108cu   /* the first outside bit  (a word) */
#define OUT_B   0x0c0b1090u   /* the second outside bit (a word) */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(const vf3_ram_map *ram, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

/* the guest's band test: the high bound first, then the low one.  A value
 * below the low bound is never tested against the high one, and the T bit the
 * caller sees is the one of the last comparison the guest made. */
static int in_band(vf3_matrix_state *s, int32_t value, int32_t high, int32_t low)
{
    const int above = (value > high);
    set_t(s, above);
    if (above) return 0;
    const int at_least = (value >= low);
    set_t(s, at_least);
    return at_least;
}

/* the guest's flag word: the bit goes into the word the caller handed over */
static void set_flag(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t bit)
{
    R(2) = vf3_mem_u32(ram, R(13));
    R(3) = bit;
    R(2) |= R(3);
    vf3_mem_set_u32(ram, R(13), R(2));
}

/* the guest's return: the frame word is dropped, the saved r13 comes back in
 * the delay slot of the return, and the return address is taken. */
static void leave(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t answer)
{
    R(0) = answer;
    R(15) += 4u;                            /* the frame word */
    R(13) = vf3_mem_u32(ram, R(15));        /* the delay slot of the return */
    R(15) += 4u;
    s->pc = R(16);
}

int vf3_band_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves r13 and opens an eight byte frame */
    vf3_mem_set_u32(ram, sp - 4u, R(13));
    R(15) = sp - 8u;

    /* the word the caller handed the guest: where the flags go */
    R(13) = vf3_mem_u32(ram, R(15) + 8u);

    /* the two differences the guest takes off the third number */
    R(5) -= R(6);
    R(4) -= R(6);

    /* and the one it keeps on the stack */
    vf3_mem_set_u32(ram, R(15), R(5));

    /* the mask, the band and the two masked differences */
    R(1) = vf3_mem_u32(ram, MASK);
    R(4) ^= R(1);
    R(6) = (uint32_t)(int32_t)(int16_t)R(4);
    R(4) = (uint32_t)half(ram, BAND_HI);
    R(5) ^= R(1);
    R(0) = (uint32_t)(int32_t)(int16_t)R(5);
    R(5) = (uint32_t)half(ram, BAND_LO);

    const int32_t high = (int32_t)R(4);
    const int32_t low = (int32_t)R(5);

    /* the two differences against the band */
    if (in_band(s, (int32_t)R(6), high, low) &&
        in_band(s, (int32_t)R(0), high, low)) {
        /* inside: the inside bit goes into the word, and the answer is one */
        set_flag(s, ram, (uint32_t)half(ram, IN_BIT));
        leave(s, ram, 1u);
        return ram->oob == 0;
    }

    /* outside: the guest asks the seventh register about a word in the pool */
    R(0) = vf3_mem_u32(ram, GATE);
    set_t(s, (R(7) & R(0)) == 0);
    if ((R(7) & R(0)) == 0) {
        /* no bit in common: the answer is zero and nothing is written */
        leave(s, ram, 0u);
        return ram->oob == 0;
    }

    /* the guest looks at the second difference once as it is and once under
     * the mask, and sets a bit for the ones that are inside the band */
    R(6) = vf3_mem_u32(ram, R(15));
    R(7) = (uint32_t)(int32_t)(int16_t)R(6);
    if (in_band(s, (int32_t)R(7), high, low))
        set_flag(s, ram, vf3_mem_u32(ram, OUT_A));

    R(6) ^= R(1);
    R(6) = (uint32_t)(int32_t)(int16_t)R(6);
    if (in_band(s, (int32_t)R(6), high, low))
        set_flag(s, ram, vf3_mem_u32(ram, OUT_B));

    leave(s, ram, 1u);
    return ram->oob == 0;
}
