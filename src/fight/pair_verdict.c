/* pair_verdict.c - SH-4 0x8C074E7C: two structures compared, and a word set.
 *
 * The function is handed two structures - r4 and r5 - and writes a word into
 * the first one: zero, or minus one.
 *
 *   Both structures keep a word at the same offset, 0x48.  The second
 *   structure's word has to share a bit with the first mask in the pool
 *   (0x8C074F60) and must *not* share a bit with the second one (0x8C074F64)
 *   - that is the gate.  The first structure's word is then masked with two
 *   more (0x8C074F68 and 0x8C074F6C) and the byte the second structure holds
 *   at the offset in the pool (0x8C074F50) decides the rest.
 *
 * The byte can be 2, 4 or 5, and the first structure has to have a field
 * (the offset in the pool is 0x8C074F52) for the answer to be anything but
 * zero.  The last mask in the pool (0x8C074F70) has the last word.
 *
 * The port follows the guest's own decision tree, because the tree is what
 * the T bit follows too: the guest's last test is the one the caller sees.
 *
 * Three details the port has to keep: the byte is read *signed* and then
 * masked to eight bits by the delay slot of the first branch, so the value
 * the tree compares is the unsigned one; the two masks are and-ed with the
 * first structure's word in the delay slot of a branch, so they are and-ed
 * on both paths; and the saved r13 comes back in the delay slot of the
 * return, after the return itself has started.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool: the three offsets and the five masks */
#define OFF_BYTE   0x0c074f50u   /* the byte of the second structure */
#define OFF_FIELD  0x0c074f52u   /* the field of the first structure */
#define OFF_RESULT 0x0c074f54u   /* the word the answer goes into */
#define MASK_A     0x0c074f60u   /* the first gate */
#define MASK_B     0x0c074f64u   /* the second gate */
#define MASK_C     0x0c074f68u   /* the first mask of the first structure */
#define MASK_D     0x0c074f6cu   /* the second mask of the first structure */
#define MASK_E     0x0c074f70u   /* the last mask */

/* the offset both structures keep their word at */
#define WORD_OFFSET 0x48u

/* the answer that is not zero */
#define MINUS_ONE 0xffffffffu

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(const vf3_ram_map *ram, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

/* The guest's block at 0x8C074EB4: the field of the first structure has to
 * be *empty*, and the mask has to be clear of it.  It answers whether the
 * tree goes on; the T bit it leaves is the one of the last test it made. */
static int field_is_empty(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = (uint32_t)half(ram, OFF_FIELD);
    R(3) = vf3_mem_u32(ram, R(4) + R(0));
    set_t(s, R(3) == 0);
    if (R(3) != 0) return 0;
    set_t(s, R(7) == 0);
    return R(7) == 0;
}

/* The guest's block at 0x8C074ECC: the second mask decides, and the last
 * mask has the last word.  It answers the word to write. */
static uint32_t last_test(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    set_t(s, R(1) == 0);
    if (R(1) != 0) return MINUS_ONE;
    R(2) = vf3_mem_u32(ram, MASK_E);
    set_t(s, (R(6) & R(2)) == 0);
    return ((R(6) & R(2)) != 0) ? MINUS_ONE : 0u;
}

int vf3_pair_verdict_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves r13 */
    vf3_mem_set_u32(ram, sp - 4u, R(13));
    R(15) = sp - 4u;

    /* the word each of the two structures keeps at the same offset */
    R(0) = WORD_OFFSET;
    R(6) = vf3_mem_u32(ram, R(4) + R(0));
    R(13) = 0u;
    R(7) = vf3_mem_u32(ram, R(5) + R(0));

    /* the byte of the second structure, and the first of the masks */
    R(0) = (uint32_t)half(ram, OFF_BYTE);
    R(3) = vf3_mem_u32(ram, MASK_A);
    R(5) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(5) + R(0));

    /* the first gate: the word of the second structure and the first mask
     * have to share a bit */
    set_t(s, (R(3) & R(7)) == 0);
    R(5) &= 0xffu;                       /* the delay slot of the branch */

    if ((R(3) & R(7)) != 0) {
        /* the second gate: this one is the other way round - the word of the
         * second structure must *not* share a bit with the second mask */
        R(2) = vf3_mem_u32(ram, MASK_B);
        set_t(s, (R(7) & R(2)) == 0);
        if ((R(7) & R(2)) == 0) {
            /* the two masks, and-ed with the word of the first structure */
            R(7) = vf3_mem_u32(ram, MASK_C);
            R(1) = vf3_mem_u32(ram, MASK_D);
            R(7) &= R(6);
            set_t(s, R(7) == 0);
            R(1) &= R(6);                /* the delay slot of the branch */

            if (R(7) == 0) {
                /* the first arm: the byte and the field decide */
                if (field_is_empty(s, ram)) {
                    R(0) = R(5);
                    set_t(s, R(0) == 2u);
                    if (R(0) == 2u) {
                        R(13) = last_test(s, ram);
                    } else {
                        R(0) = R(5);
                        set_t(s, R(0) == 5u);
                        if (R(0) == 5u) R(13) = last_test(s, ram);
                    }
                }
            } else {
                /* the second arm: only a byte that is neither 4 nor 5 makes
                 * the answer minus one */
                int minus_one = 0;
                set_t(s, R(1) == 0);
                if (R(1) == 0) {
                    R(0) = R(5);
                    set_t(s, R(0) == 4u);
                    if (R(0) != 4u) {
                        R(0) = R(5);
                        set_t(s, R(0) == 5u);
                        if (R(0) != 5u) minus_one = 1;
                    }
                }
                if (minus_one) {
                    R(13) = MINUS_ONE;
                } else {
                    (void)field_is_empty(s, ram);
                }
            }
        }
    }

    /* the answer goes into the first structure */
    R(0) = (uint32_t)half(ram, OFF_RESULT);
    vf3_mem_set_u32(ram, R(4) + R(0), R(13));

    /* the delay slot of the return puts the saved r13 back */
    R(13) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
