/* state_resolve.c - SH-4 0x8C08E68C: resolve the two fighters' records into
 * the output struct.
 *
 * The guest is called with r4 = the output struct.  It picks two records - the
 * "first" and the "second" - out of a table, copies a handful of words out of
 * each into the output struct and resolves one 3-float vector for each record.
 *
 *  * **the records.**  The output struct's flag word (its word 48) chooses the
 *    row: the bit 0x40 picks the second table's row at 452, the bits 0x80 and
 *    0x100 pick the row at 456, and with none of them set the first table's
 *    entry at 16 is used.  The second record follows the first: the row that was
 *    picked is the first table's entry at 20 ? entry at 20 : entry at 16.  With
 *    no flag set the pair is the entry at 16 and the entry at 20.
 *
 *  * **the words the records share with the output struct.**  The word at 6340
 *    (the first record's goes to the output's word 52, the second record's to the
 *    output's word 56), the words at 0x48 and 0x4c, the word at 6660 and the
 *    halfword at 0x3e.
 *
 *  * **the vectors.**  Each vector comes from one of three places in the record:
 *    its own words at 0x10, the words at the pool's offset 1072, or the words at
 *    the pool's offset 496.  The third component is always negated.  A helper,
 *    called through a pointer in the pool, may add a correction to the vector.
 *
 * The guest keeps the two records in r4 and r13, the output struct in r14, and
 * works on a 36-byte private frame below the stack.  The port does the same, so
 * the stack words it leaves in RAM are the ones the original left and the
 * helper sees the frame where the original put it.
 *
 * The literal pool is read at run time, the way the guest reads it: the table
 * addresses, the masks, the offsets into the records and the helper's address
 * are the image's, and this port does not bake them in.  The pool lives in ROM,
 * so a replay has to supply it as a window - see tests/state_resolve_replay.c.
 *
 * Details the port has to keep:
 *
 *   * the **T bit** is the guest's branch condition.  A plain `bf` branches when
 *     the T bit is *clear* and a plain `bt` when it is *set*, so the tests below
 *     read the other way round from what the mask suggests: the "the mask is
 *     absent" case is the one that carries on.  The T bit is also part of the
 *     contract - the guest leaves it behind, and the port has to leave the same
 *     value behind, so the order of the tests matters as much as their result;
 *   * a **`/s` branch runs its delay slot on both paths**, so the word the delay
 *     slot spills into the guest's scratch frame is written whether the branch is
 *     taken or not.  The port writes those words too - they are the guest's RAM,
 *     and the test compares it;
 *   * the **correction's 0.4 is negated only sometimes**: the guest negates it
 *     when the record's count carries the mask 0x08000000, and leaves it alone
 *     otherwise.  The helper then adds the correction to the vector's third
 *     component;
 *   * the **helper is called only when the record's count carries the bit 8192**
 *     and the correction would not be zero - the "both" word (the two counts
 *     that are neither equal nor different) has to say so.  The bit the count
 *     shares with the "both" word is the one that decides the last test;
 *   * the **return** pops the saved registers - r14 in the delay slot of the
 *     `rts` - so the caller sees its own r8..r14 back, and the guest leaves its
 *     return address in pr.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]
#define FR(n) s->v[21 + (n)]

/* The guest's literal pool.  Every entry is read from RAM at run time. */
#define POOL_FLAG_128     0x0c08e756u /* the flag bit 0x80 */
#define POOL_FLAG_256     0x0c08e758u /* the flag bit 0x100 */
#define POOL_ROW_452      0x0c08e75au /* the second table's row at 452 */
#define POOL_ROW_456      0x0c08e75cu /* the second table's row at 456 */
#define POOL_OFF_6340     0x0c08e75eu /* the word at 6340 in a record */
#define POOL_OFF_6660     0x0c08e760u /* the word at 6660 in a record */
#define POOL_OFF_1072     0x0c08e762u /* the second source of a vector */
#define POOL_TABLE        0x0c08e764u /* the first table */
#define POOL_TABLE2       0x0c08e768u /* the second table */
#define POOL_MASK_HI      0x0c08e76cu /* the mask 0x08000000 */
#define POOL_MASK_LO      0x0c08e770u /* the mask 0x04000000 */
#define POOL_OFF_496      0x0c08e848u /* the third source of the first vector */
#define POOL_OFF_6672_1   0x0c08e84au /* the word at 6672 in the first record */
#define POOL_BIT_8192_1   0x0c08e84cu /* the bit 8192, for the first record */
#define POOL_OFF_5268_1   0x0c08e84eu /* the word at 5268 in the first record */
#define POOL_OFF_1072_2   0x0c08e850u /* the second source of the second vector */
#define POOL_F40_1        0x0c08e854u /* the float 0.4, for the first vector */
#define POOL_HELPER_1     0x0c08e858u /* the helper, for the first vector */
#define POOL_MASK_LO_2    0x0c08e85cu /* the mask 0x04000000, for the second record */
#define POOL_OFF_496_2    0x0c08e8feu /* the third source of the second vector */
#define POOL_OFF_6672_2   0x0c08e900u /* the word at 6672 in the second record */
#define POOL_BIT_8192_2   0x0c08e902u /* the bit 8192, for the second record */
#define POOL_OFF_5268_2   0x0c08e904u /* the word at 5268 in the second record */
#define POOL_OFF_196      0x0c08e906u /* the output's word at 196 */
#define POOL_F40_2        0x0c08e908u /* the float 0.4, for the second vector */
#define POOL_HELPER_2     0x0c08e90cu /* the helper, for the second vector */

/* the continuations the guest leaves in pr */
#define CONT_HELPER_1 0x0c08e7e6u
#define CONT_HELPER_2 0x0c08e8c6u

/* the output struct's flag word */
#define OUT_FLAGS 48u

/* the words the two records and the output struct share */
#define REC_FLAGS 0x48u
#define REC_COUNT 0x4cu
#define REC_HALF  0x3eu

/* the private frame: the words the guest spills into it */
#define FRAME_LEN    36u
#define FRAME_ZERO   0u  /* the correction's first float */
#define FRAME_Y      4u  /* the correction's second float */
#define FRAME_BOTH   8u  /* the two counts, masked */
#define FRAME_SEC    12u /* the second record's word at 6340 */
#define FRAME_FLAG   16u /* the output struct's flag bit 0 */
#define FRAME_THIRD2 20u /* the second call's third float */
#define FRAME_THIRD1 24u /* the first call's third float */
#define FRAME_SEC2   28u /* the second record's word at 6660 */
#define FRAME_ARG    32u /* the word the helper is given */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(uint32_t v)
{
    return (int32_t)(int16_t)(uint16_t)v;
}

/* A pool halfword: the guest reads it and sign extends it. */
static uint32_t pool_half(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint32_t)half(vf3_mem_u16(ram, addr));
}

/* Where a vector comes from.
 *
 * The guest tests three things, in this order:
 *
 *  - the output struct's flag bit 0: when it is clear the "both" word decides;
 *  - the "both" word's bit 2: when it is clear the third source is taken;
 *  - the record's flags word against the high mask: when it carries that bit
 *    the third source is taken;
 *  - the record's flags word against the low mask: when it is clear the first
 *    source is taken, otherwise the second one.
 *
 * The three sources are the record's own words at 0x10, the record's words at
 * the pool's 1072 and the record's words at the pool's 496.
 *
 * The two masks are loaded into registers before they are used, and the
 * registers differ between the two vectors: the first vector puts the bit-2
 * mask into r3, the record's flags into r2 and the low mask into r3 again;
 * the second one puts the bit-2 mask into r1, the record's flags into r3 and
 * the low mask into r2.  The port keeps that traffic, because the guest
 * leaves the registers behind.
 */
static uint32_t vector_source(vf3_matrix_state *s, uint32_t flag_bit0,
                              uint32_t both, uint32_t rec_flags,
                              uint32_t mask_hi, uint32_t mask_lo,
                              uint32_t off_first, uint32_t off_second,
                              uint32_t off_third,
                              unsigned bit2_reg, unsigned hi_reg,
                              unsigned low_reg)
{
    set_t(s, flag_bit0 == 0u);
    if (R(17) & 1u) {
        /* the flag bit is clear: the "both" word decides */
        R(bit2_reg) = 4u;
        set_t(s, (both & R(bit2_reg)) == 0u);
        if (R(17) & 1u) return off_third;
    }
    R(hi_reg) = rec_flags;
    set_t(s, (R(hi_reg) & mask_hi) == 0u);
    if (!(R(17) & 1u)) return off_third;
    R(low_reg) = mask_lo;
    set_t(s, (rec_flags & R(low_reg)) == 0u);
    if (R(17) & 1u) return off_first;
    return off_second;
}

/* Load the three floats of a vector out of a record and negate its third. */
static void load_vector(vf3_matrix_state *s, const vf3_ram_map *ram,
                        uint32_t record, uint32_t off)
{
    vf3_matrix_load(s, ram, 15, record + off);
    vf3_matrix_load(s, ram, 14, record + off + 4u);
    vf3_matrix_load(s, ram, 13, record + off + 8u);
    FR(13) ^= 0x80000000u;            /* the branch's delay slot: fneg fr13 */
}

/* Does the vector get a correction?
 *
 * The guest skips the helper when the record's count does not carry the bit
 * 8192.  Otherwise it looks at the "both" word: when the count's own bit (the
 * one the count shares with the "both" word) is set the correction happens, and
 * when it is clear the "both" word itself decides - a zero "both" word means
 * the correction happens too.
 *
 * The T bit is left as the guest leaves it, because the guest leaves it behind.
 */
static int correction_wanted(vf3_matrix_state *s, const vf3_ram_map *ram,
                              uint32_t frame, uint32_t count, uint32_t bit,
                              unsigned both_reg)
{
    set_t(s, (bit & count) == 0u);
    if (R(17) & 1u) return 0;          /* the count does not carry the bit */
    set_t(s, R(8) == 0u);
    if (!(R(17) & 1u)) return 1;        /* the count's own bit is set */
    R(both_reg) = vf3_mem_u32(ram, frame + FRAME_BOTH);
    set_t(s, R(both_reg) == 0u);
    return (R(17) & 1u) != 0;          /* the "both" word is zero */
}

/* Call the helper that corrects a vector.
 *
 * The helper is handed the record's word at 5268 - a halfword, negated - and
 * the frame; it writes the correction into the frame's fourth word.  The guest
 * then adds the frame's three floats to the vector.
 *
 * `arg_slot` is where the argument goes (the guest puts the first call's
 * argument at frame+32 and the second one's at frame+8) and `third_slot` is
 * where the correction's third float goes (frame+24 and frame+20).
 */
static int call_correction(vf3_matrix_state *s, const vf3_ram_map *ram,
                           uint32_t frame, uint32_t record, uint32_t count,
                           uint32_t arg_slot, uint32_t third_slot,
                           uint32_t pool_arg, uint32_t pool_f40,
                           uint32_t pool_helper, uint32_t cont)
{
    R(0) = pool_half(ram, pool_arg);            /* the record's word at 5268 */
    set_t(s, (count & R(12)) == 0u);             /* the guest's own test */
    R(1) = (uint32_t)half(vf3_mem_u16(ram, record + R(0)));
    R(0) = pool_f40;
    vf3_mem_set_u32(ram, frame + arg_slot, R(1));
    vf3_matrix_load(s, ram, 3, R(0));            /* fr3 = 0.4 */
    R(0) = third_slot;
    vf3_matrix_store(s, ram, 3, frame);          /* frame+0 = 0.4 */
    vf3_matrix_store(s, ram, 12, frame + R(0));  /* frame+third = fr12 */
    R(0) = FRAME_Y;
    vf3_matrix_store(s, ram, 12, frame + R(0));  /* frame+4 = fr12 */
    if (!(R(17) & 1u)) {
        /* the guest negates the 0.4 when the count carries the high mask */
        vf3_matrix_load(s, ram, 3, frame);
        FR(3) ^= 0x80000000u;
        vf3_matrix_store(s, ram, 3, frame);
    }

    R(4) = vf3_mem_u32(ram, frame + arg_slot);
    R(6) = frame + 4u;
    R(3) = vf3_mem_u32(ram, pool_helper);
    R(5) = frame;
    R(4) = 0u - R(4);
    if (!vf3_guest_call(s, ram, R(3), cont)) return 0;

    /* back: the frame's three floats join the vector */
    R(0) = third_slot;
    vf3_matrix_load(s, ram, 3, frame);
    vf3_matrix_load(s, ram, 2, frame + R(0));
    R(0) = FRAME_Y;
    vf3_matrix_load(s, ram, 1, frame + R(0));
    FR(15) = vf3_fpu_binary(FR(15), FR(3), R(18), '+');
    FR(14) = vf3_fpu_binary(FR(14), FR(2), R(18), '+');
    FR(13) = vf3_fpu_binary(FR(13), FR(1), R(18), '+');
    return 1;
}

int vf3_state_resolve_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t frame;

    /* ---- the prologue: the seven general registers, the four FP registers
     * and pr, then the private frame ---- */
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(14));
    R(14) = R(4);                       /* r14 = the output struct */
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(13));
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(12));
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(11));
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(10));
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(9));
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(8));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 15, R(15));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 14, R(15));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 13, R(15));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 12, R(15));
    R(5) = vf3_mem_u32(ram, POOL_TABLE);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(16));
    R(15) -= FRAME_LEN;
    frame = R(15);

    /* ---- the two records ---- */
    R(6) = vf3_mem_u32(ram, R(14) + OUT_FLAGS);
    R(7) = vf3_mem_u32(ram, POOL_TABLE2);
    R(4) = vf3_mem_u32(ram, R(5) + 16u);       /* the first record, by default */
    R(13) = vf3_mem_u32(ram, R(5) + 20u);      /* the second record, by default */
    {
        uint32_t row = 0;
        int alternate = 0;

        set_t(s, (0x40u & R(6)) == 0u);
        if (!(R(17) & 1u)) {
            /* the flag bit 0x40: the second table's row at 452 */
            row = pool_half(ram, POOL_ROW_452);
            alternate = 1;
        } else {
            set_t(s, (pool_half(ram, POOL_FLAG_128) & R(6)) == 0u);
            if (!(R(17) & 1u)) {
                /* the flag bit 0x80: the second table's row at 456 */
                row = pool_half(ram, POOL_ROW_456);
                alternate = 1;
            } else {
                set_t(s, (pool_half(ram, POOL_FLAG_256) & R(6)) == 0u);
                if (!(R(17) & 1u)) {
                    /* the flag bit 0x100: the second table's row at 456 */
                    row = pool_half(ram, POOL_ROW_456);
                    alternate = 1;
                }
            }
        }
        if (alternate) {
            R(4) = vf3_mem_u32(ram, R(7) + row);
            set_t(s, R(4) == R(13));
            R(4) = vf3_mem_u32(ram, R(5) + ((R(17) & 1u) ? 20u : 16u));
            R(13) = R(4);
        }
    }

    /* ---- the words the two records share with the output struct ---- */
    R(0) = pool_half(ram, POOL_OFF_6340);
    R(12) = vf3_mem_u32(ram, R(4) + R(0));
    R(0) = REC_FLAGS;
    R(8) = vf3_mem_u32(ram, R(4) + R(0));
    R(0) = REC_COUNT;
    R(5) = vf3_mem_u32(ram, R(4) + R(0));
    R(0) = pool_half(ram, POOL_OFF_6660);
    R(7) = R(5);
    R(3) = vf3_mem_u32(ram, R(4) + R(0));
    vf3_mem_set_u32(ram, frame + FRAME_BOTH, R(3));
    R(0) = pool_half(ram, POOL_OFF_6340);
    R(2) = vf3_mem_u32(ram, R(13) + R(0));
    R(0) = REC_FLAGS;
    vf3_mem_set_u32(ram, frame + FRAME_SEC, R(2));
    R(10) = vf3_mem_u32(ram, R(13) + R(0));
    R(0) = REC_COUNT;
    R(11) = vf3_mem_u32(ram, R(13) + R(0));
    R(0) = pool_half(ram, POOL_OFF_6660);
    R(7) ^= R(11);                                  /* the two counts differ */
    R(3) = vf3_mem_u32(ram, R(13) + R(0));
    R(0) = 0x40u;
    vf3_mem_set_u32(ram, frame + FRAME_SEC2, R(3));
    R(9) = vf3_mem_u32(ram, frame + FRAME_SEC);
    vf3_mem_set_u32(ram, R(14) + 52u, R(12));
    R(9) &= R(12);
    vf3_mem_set_u32(ram, R(14) + 60u, R(8));
    vf3_mem_set_u32(ram, R(14) + R(0), R(5));
    R(0) = 0x44u;
    R(3) = vf3_mem_u32(ram, frame + FRAME_BOTH);
    vf3_mem_set_u32(ram, R(14) + R(0), R(3));

    /* ---- the first record's vector ---- */
    R(3) = 1u;
    R(12) = vf3_mem_u32(ram, POOL_MASK_HI);
    R(6) &= R(3);
    R(2) = R(6);
    set_t(s, R(2) == 0u);
    vf3_mem_set_u32(ram, frame + FRAME_FLAG, R(6));
    {
        uint32_t off = vector_source(s, R(6), R(9), R(8), R(12),
                                     vf3_mem_u32(ram, POOL_MASK_LO),
                                     0x10u, pool_half(ram, POOL_OFF_1072),
                                     pool_half(ram, POOL_OFF_496),
                                     3u, 2u, 3u);
        load_vector(s, ram, R(4), off);
    }

    /* ---- the first record's other words ---- */
    R(0) = pool_half(ram, POOL_OFF_6672_1);
    R(3) = (uint32_t)half(vf3_mem_u16(ram, R(4) + R(0)));
    R(0) = 0x54u;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(3));
    R(0) = REC_HALF;
    R(2) = (uint32_t)half(vf3_mem_u16(ram, R(4) + R(0)));
    R(0) = 0x56u;
    R(3) = R(7);
    R(3) &= R(12);
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(2));
    R(0) = 0x70u;
    vf3_matrix_store(s, ram, 15, R(14) + R(0));
    R(0) = 0x74u;
    vf3_matrix_store(s, ram, 14, R(14) + R(0));
    R(0) = 0x78u;
    vf3_matrix_store(s, ram, 13, R(14) + R(0));

    /* ---- the helper that may correct the first vector ---- */
    FR(12) = 0;
    R(8) = pool_half(ram, POOL_BIT_8192_1) & R(7);
    R(2) = pool_half(ram, POOL_BIT_8192_1);
    set_t(s, (R(2) & R(5)) == 0u);
    R(3) = R(7) & R(12);
    vf3_mem_set_u32(ram, frame + FRAME_BOTH, R(3));
    if (correction_wanted(s, ram, frame, R(5), R(2), 3u)) {
        if (!call_correction(s, ram, frame, R(4), R(5),
                             FRAME_ARG, FRAME_THIRD1,
                             POOL_OFF_5268_1, POOL_F40_1, POOL_HELPER_1,
                             CONT_HELPER_1))
            return 0;
    }
    R(0) = 0x7cu;
    vf3_matrix_store(s, ram, 15, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 14, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 13, R(14) + R(0));

    /* ---- the second record's words ---- */
    R(0) = 0x48u;
    R(3) = vf3_mem_u32(ram, frame + FRAME_SEC);
    vf3_mem_set_u32(ram, R(14) + 56u, R(3));
    vf3_mem_set_u32(ram, R(14) + R(0), R(10));
    R(0) = REC_COUNT;
    vf3_mem_set_u32(ram, R(14) + R(0), R(11));
    R(0) = 0x50u;
    R(3) = vf3_mem_u32(ram, frame + FRAME_SEC2);
    vf3_mem_set_u32(ram, R(14) + R(0), R(3));

    /* ---- the second record's vector ---- */
    R(2) = vf3_mem_u32(ram, frame + FRAME_FLAG);
    {
        uint32_t off = vector_source(s, R(2), R(9), R(10), R(12),
                                     vf3_mem_u32(ram, POOL_MASK_LO_2),
                                     0x10u, pool_half(ram, POOL_OFF_1072_2),
                                     pool_half(ram, POOL_OFF_496_2),
                                     1u, 3u, 2u);
        load_vector(s, ram, R(13), off);
    }
    R(0) = pool_half(ram, POOL_OFF_6672_2);
    R(3) = (uint32_t)half(vf3_mem_u16(ram, R(13) + R(0)));
    R(0) = 0x58u;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(3));
    R(0) = REC_HALF;
    R(2) = (uint32_t)half(vf3_mem_u16(ram, R(13) + R(0)));
    R(0) = 0x5au;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(2));
    R(0) += 0x5eu;                                     /* 0xb8 */
    vf3_matrix_store(s, ram, 15, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 14, R(14) + R(0));
    R(0) += 4u;

    /* ---- the helper that may correct the second vector ---- */
    R(3) = pool_half(ram, POOL_BIT_8192_2);
    set_t(s, (R(3) & R(11)) == 0u);
    vf3_matrix_store(s, ram, 13, R(14) + R(0));
    if (correction_wanted(s, ram, frame, R(11), R(3), 2u)) {
        if (!call_correction(s, ram, frame, R(13), R(11),
                             FRAME_BOTH, FRAME_THIRD2,
                             POOL_OFF_5268_2, POOL_F40_2, POOL_HELPER_2,
                             CONT_HELPER_2))
            return 0;
    }

    /* ---- the epilogue ---- */
    R(0) = pool_half(ram, POOL_OFF_196);
    R(15) += FRAME_LEN;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    vf3_matrix_store(s, ram, 15, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 14, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 13, R(14) + R(0));
    vf3_matrix_load(s, ram, 12, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    vf3_matrix_load(s, ram, 13, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    vf3_matrix_load(s, ram, 14, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    vf3_matrix_load(s, ram, 15, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    R(8) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(9) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(10) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(11) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(12) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(13) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    {
        const uint32_t target = R(16);
        R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
        s->pc = target;
    }
    return ram->oob == 0;
}
