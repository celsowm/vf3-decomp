/* state_flag.c - SH-4 0x8C0B0FD2: the fight engine's state flag.
 *
 * The function sets **one of two bits** in a word it finds through r7 - a word
 * that belongs to the fight engine's state.  Which bit it sets depends on two
 * things: the band the value falls into, and one parity bit.
 *
 * The value comes out of a structure the caller hands over in r5: a halfword
 * at the offset the pool names (0x8C0B1070).  The guest subtracts r6 from it
 * and flips the sign bit with the pool's xor constant (0x8C0B1098), so the
 * value is signed and, in the game's own numbers, roughly the negated
 * difference between the halfword and r6.
 *
 * The bands are two, and they are mirror images of each other:
 *
 *   * the **middle band**, from the pool's middle bound (0x8C0B1074) up to
 *     the pool's low bound (0x8C0B1072) - both negative, -27300 to -5460 in
 *     the game's own pool;
 *   * the **high band**, from the pool's high bound (0x8C0B1078) up to the
 *     pool's second high bound (0x8C0B107A) - the same numbers, positive.
 *
 * A value between the two bands is in neither, and the function leaves the
 * word alone.  So does a value outside both bands.
 *
 * The parity bit is the low bit of two words the guest shifts out of the
 * structure r4 points at: the first word shifted right by 25 and the second
 * one - 72 bytes further on - shifted right by 10, and the two exclusive-ored.
 *
 * Details the port has to keep:
 *
 *   * the pool's entries are **read at run time**, the way the guest reads
 *     them: the bounds and the two bits are halfwords, the gate's mask and the
 *     xor constant are words;
 *   * the **two bands answer the opposite way round**.  In the middle band a
 *     zero parity bit sets the low bit and a set one sets the high bit; in the
 *     high band it is the other way round.  A port that reads one of them the
 *     wrong way round passes every case that only ever reaches one of them;
 *   * the **T bit is the guest's branch condition**, and the guest leaves the
 *     last test it made behind - so the bit depends on the path;
 *   * the guest's `shad` with a **negative count shifts right**, and the count
 *     is the count's two's complement masked to five bits.  The corpus pins
 *     it: the word 0xa6000000 comes out as 0xffe98000, which is an arithmetic
 *     shift right by ten;
 *   * the **gate**: the word at r7 carries the mask's bits, and then the
 *     function does nothing at all - it does not even write the word back.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The literal pool.  Every entry is read at run time. */
#define POOL_TABLE    0x0c0b1070u  /* the offset of the value's halfword */
#define POOL_LOW      0x0c0b1072u  /* the middle band's upper bound */
#define POOL_MID      0x0c0b1074u  /* the middle band's lower bound */
#define POOL_BIT_LOW  0x0c0b1076u  /* the bit the low answer sets */
#define POOL_HIGH     0x0c0b1078u  /* the high band's lower bound */
#define POOL_HIGH2    0x0c0b107au  /* the high band's upper bound */
#define POOL_BIT_HIGH 0x0c0b107cu  /* the bit the high answer sets */
#define POOL_MASK     0x0c0b1094u  /* the gate's mask */
#define POOL_XOR      0x0c0b1098u  /* the xor constant */

/* The second of the two words the parity bit comes from sits this far on. */
#define WORD_OFFSET 72u

/* The counts of the two shifts, the way the guest keeps them in r2. */
#define COUNT_FIRST  0xffffffe7u  /* -25 */
#define COUNT_SECOND 0xfffffff6u  /* -10 */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* The guest's halfword: sixteen bits, sign extended. */
static int32_t half(const vf3_ram_map *ram, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

/* The guest's `exts.w`: the low sixteen bits of a register, sign extended. */
static uint32_t sext16(uint32_t value)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)value;
}

/* An arithmetic shift right: the fill is the sign bit. */
static uint32_t asr(uint32_t value, unsigned bits)
{
    if (bits == 0u) return value;
    if (value & 0x80000000u) return (value >> bits) | ~(0xffffffffu >> bits);
    return value >> bits;
}

/* The guest's `shad Rm,Rn`: a negative count shifts the word right, and the
 * count is the count's two's complement masked to five bits.  A positive count
 * shifts it left. */
static uint32_t shad(uint32_t value, uint32_t count)
{
    if (count & 0x80000000u) {
        const unsigned bits = (0u - count) & 31u;
        if (bits == 0u) return (value & 0x80000000u) ? 0xffffffffu : 0u;
        return asr(value, bits);
    }
    return value << (count & 31u);
}

/* The guest's return: the exit PC is the return address, and the function
 * fails only when it read outside the captured windows. */
static int leave(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    s->pc = R(16);
    return ram->oob == 0;
}

/* The high band: the value has to be inside it, and then the parity bit
 * decides - the other way round than in the middle band. */
static int high_band(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = (uint32_t)half(ram, POOL_HIGH);
    set_t(s, (int32_t)R(6) >= (int32_t)R(0));
    if ((int32_t)R(6) < (int32_t)R(0))
        return leave(s, ram);           /* below the band: nothing to do */

    R(3) = (uint32_t)half(ram, POOL_HIGH2);
    set_t(s, (int32_t)R(6) > (int32_t)R(3));
    if ((int32_t)R(6) > (int32_t)R(3))
        return leave(s, ram);           /* above the band: nothing to do */

    set_t(s, R(5) == 0u);
    if (R(5) == 0u) {
        /* the high bit */
        R(2) = vf3_mem_u32(ram, R(7));
        R(3) = (uint32_t)half(ram, POOL_BIT_HIGH);
        R(2) |= R(3);
        vf3_mem_set_u32(ram, R(7), R(2));
    } else {
        /* the low bit */
        R(1) = vf3_mem_u32(ram, R(7));
        R(3) = (uint32_t)half(ram, POOL_BIT_LOW);
        R(1) |= R(3);
        vf3_mem_set_u32(ram, R(7), R(1));
    }
    return leave(s, ram);
}

int vf3_state_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* ---- the gate ----
     * The word at r7 carries the mask's bits.  When it carries any of them
     * the function does nothing: it does not even write the word back, and it
     * leaves every register but r2, r3 and the T bit alone. */
    R(2) = vf3_mem_u32(ram, R(7));
    R(3) = vf3_mem_u32(ram, POOL_MASK);
    set_t(s, (R(2) & R(3)) == 0u);
    if ((R(2) & R(3)) != 0u)
        return leave(s, ram);

    /* ---- the value ----
     * r5 points at the structure that holds the halfword, r6 is the offset the
     * value is measured from.  The guest reads the halfword signed, throws the
     * sign away again, subtracts r6 and flips the sign bit with the pool's
     * xor constant - so what is left is a signed number. */
    R(0) = (uint32_t)half(ram, POOL_TABLE);
    R(2) = COUNT_FIRST;                /* the count of the first shift */
    R(3) = vf3_mem_u32(ram, POOL_XOR);
    R(1) = 1u;
    R(5) = (uint32_t)half(ram, R(5) + R(0));
    R(0) = WORD_OFFSET;
    R(5) &= 0xffffu;                   /* the guest's `extu.w` */
    R(5) -= R(6);
    R(5) ^= R(3);
    R(3) = (uint32_t)half(ram, POOL_LOW);
    R(6) = sext16(R(5));               /* the guest's `exts.w` */

    /* ---- the parity bit ----
     * The two words out of the structure r4 points at: the first one, and the
     * second one 72 bytes further on.  They are shifted right and exclusive-
     * ored, and only the low bit of the result is kept. */
    R(5) = vf3_mem_u32(ram, R(4));
    R(4) = vf3_mem_u32(ram, R(4) + WORD_OFFSET);

    set_t(s, (int32_t)R(6) > (int32_t)R(3));
    R(5) = shad(R(5), R(2));
    R(2) = COUNT_SECOND;               /* the count of the second shift */
    R(4) = shad(R(4), R(2));
    R(5) ^= R(4);
    R(5) &= R(1);                      /* the delay slot of the branch */

    if ((int32_t)R(6) > (int32_t)R(3)) {
        /* above the low bound: the high band, or nothing at all */
        return high_band(s, ram);
    }

    /* ---- the middle band ----
     * The value is below the low bound.  It is in the middle band only when it
     * is not below the middle bound as well. */
    R(2) = (uint32_t)half(ram, POOL_MID);
    set_t(s, (int32_t)R(6) >= (int32_t)R(2));
    if ((int32_t)R(6) < (int32_t)R(2))
        return high_band(s, ram);      /* below the middle bound: the high band */

    set_t(s, R(5) == 0u);
    if (R(5) != 0u) {
        /* the high bit */
        R(2) = vf3_mem_u32(ram, R(7));
        R(3) = (uint32_t)half(ram, POOL_BIT_HIGH);
        R(2) |= R(3);
        vf3_mem_set_u32(ram, R(7), R(2));
    } else {
        /* the low bit */
        R(1) = vf3_mem_u32(ram, R(7));
        R(3) = (uint32_t)half(ram, POOL_BIT_LOW);
        R(1) |= R(3);
        vf3_mem_set_u32(ram, R(7), R(1));
    }
    return leave(s, ram);
}
