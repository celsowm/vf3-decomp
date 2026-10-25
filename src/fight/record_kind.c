/* record_kind.c - SH-4 0x8C078044: a record's kind byte, and the flag word
 * that goes with it.
 *
 * The function is handed a record - r5 is its base and r7 an index into it -
 * and the flag word the caller left in its frame.  The record keeps three
 * bytes that matter:
 *
 *   * the **kind** byte, at the offset in the pool (0x8C07815A) plus the
 *     index.  It counts down: it is set to one when the record gets a kind,
 *     and taken down to zero again when the record is finished.
 *   * the **state** byte, at the offset in the pool (0x8C07815C) plus the
 *     index.  It holds the low four bits of the flag word.
 *   * the byte at the third offset (0x8C07815E), which the guest copies into
 *     two places: the fourth offset (0x8C078160) plus the index, and the
 *     third offset plus 51.
 *
 * The pool's values are read at run time, not baked in, so the port follows
 * the image: the offsets are 0x1BB0 (kind), 0x1BB2 (state), 0x1B83 (the byte
 * that is copied) and 0x1BB4 (where it lands), the flag bit the second kind
 * adds is 0x0100 and the gate mask is 0x40000000.
 *
 * When the kind byte is still zero the record has no kind yet.  The flag
 * word's low four bits decide: zero or fifteen mean the record is already
 * complete, and anything else starts a kind - the kind byte becomes one, the
 * state byte takes the four bits, and the flag word's low four bits are
 * cleared.  Then the byte at the third offset is copied.
 *
 * When the record has a kind the guest looks at the state byte and at two
 * more words of the caller's frame.  The **gate** mask in the pool
 * (0x8C07816C) is tested against the first of them: when the caller's word
 * has none of the gate's bits, three further tests have to hold - the state
 * byte is four, the caller's mode word has bit two *clear*, and the flag word's
 * low four bits are one.  When they do, the byte at the third offset is
 * copied and the kind is cleared.
 *
 * Everything else ends in the second block: the state byte is merged into
 * the flag word's low four bits, and if the result is fifteen - or if the
 * kind byte was one - the kind is cleared as well.  Otherwise the kind byte
 * counts down, the state byte takes the merged value, and the flag word's low
 * four bits are cleared.
 *
 * Details the port has to keep: the `bf/s` branches when the T bit is
 * *clear*, so the guest's "the kind byte is not zero" path is the one the
 * branch takes; the plain `bf` branches when the T bit is clear too, so the
 * three tests above fall through when they hold; the plain `bt` branches
 * when the T bit is *set*; the delay slot of a `/s` branch runs on both
 * paths, so the flag word's low four bits are masked before the branch is
 * resolved; and the two copies leave the address they write to in different
 * registers - the first in r7, the second in r3 - which the guest's own
 * register file shows.
 *
 * The caller's three frame words sit at the *entry* stack pointer + 0, + 4
 * and + 8: the callee's prologue takes its own r15 eight bytes below the
 * entry, and it reads them at @(8,r15), @(12,r15) and @(16,r15) - so the
 * first frame word is the last one the caller pushed.
 *
 * Three things about this function cannot be observed, and the port says so
 * rather than pretending otherwise:
 *
 *   * the **sign extension** of the bytes it reads.  The guest's `mov.b`
 *     sign-extends, but every byte it reads is masked back to eight bits
 *     before it is used, and the one place the mask is not applied again -
 *     the second copy's r14 - reaches the RAM only through a byte store and
 *     is overwritten by the return;
 *   * the **T bit of the kind test**, of the gate test and of the mode test.
 *     The guest writes the T bit three more times before it returns, so the
 *     value those three tests leave behind is never the caller's.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool: the five offsets and the gate mask */
#define KIND   0x0c07815au   /* the kind byte's offset */
#define STATE  0x0c07815cu   /* the state byte's offset */
#define SOURCE 0x0c07815eu   /* the byte that is copied */
#define DEST   0x0c078160u   /* where the copy lands */
#define EXTRA  0x0c078162u   /* the flag bit the second kind adds */
#define GATE   0x0c07816cu   /* the mask the caller's word is tested against */

/* the second place the copied byte lands */
#define SECOND_PLACE 51u

/* the flag word's low four bits */
#define NIBBLE 15u

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(const vf3_ram_map *ram, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

/* the guest's byte: eight bits, sign extended */
static int32_t byte(const vf3_ram_map *ram, uint32_t addr)
{
    return (int32_t)(int8_t)vf3_mem_u8(ram, addr);
}

/* The guest's first copy (at 0x8C07807C): the byte at the third offset goes
 * to the fourth offset plus the index and to the third offset plus 51.  The
 * byte it copies lands in r4 - the flag word's low four bits - and the
 * address it writes to lands in r7. */
static void copy_state(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = (uint32_t)half(ram, SOURCE);
    R(3) = (uint32_t)half(ram, DEST);
    R(4) = (uint32_t)byte(ram, R(5) + R(0));
    R(0) += SECOND_PLACE;
    R(3) += R(5);
    R(7) += R(3);
    R(4) &= 0xffu;
    vf3_mem_set_u8(ram, R(7), (uint8_t)R(4));
    vf3_mem_set_u8(ram, R(5) + R(0), (uint8_t)R(4));
}

/* The guest's second copy (at 0x8C0780B4): the same byte, but it lands in
 * r14 - the kind - and the address it writes to lands in r3. */
static void copy_kind(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = (uint32_t)half(ram, SOURCE);
    R(3) = (uint32_t)half(ram, DEST);
    R(14) = (uint32_t)byte(ram, R(5) + R(0));
    R(0) += SECOND_PLACE;
    R(3) += R(5);
    R(3) += R(7);
    R(14) &= 0xffu;
    vf3_mem_set_u8(ram, R(3), (uint8_t)R(14));
    vf3_mem_set_u8(ram, R(5) + R(0), (uint8_t)R(14));
}

/* The guest's end at 0x8C0780FC: the kind byte goes back to zero and the flag
 * word keeps the four bits. */
static void clear_kind(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(1) = (uint32_t)half(ram, KIND);
    R(3) = 0u;
    R(6) |= R(4);
    R(1) += R(5);
    R(7) += R(1);
    vf3_mem_set_u8(ram, R(7), (uint8_t)R(3));
}

/* The guest's return: the saved r13 comes back, the flag word is the answer,
 * and the saved r14 comes back in the delay slot of the return. */
static void leave(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(13) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(0) = R(6);
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    s->pc = R(16);
}

int vf3_record_kind_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves r14 and r13 */
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    vf3_mem_set_u32(ram, sp - 8u, R(13));
    R(15) = sp - 8u;

    /* the kind byte of the record, and the flag word the caller left */
    R(4) = NIBBLE;
    R(14) = (uint32_t)half(ram, KIND);
    R(6) = vf3_mem_u32(ram, R(15) + 8u);
    R(14) += R(5);
    R(14) += R(7);
    R(14) = (uint32_t)byte(ram, R(14));
    R(14) &= 0xffu;
    set_t(s, R(14) == 0);
    R(4) &= R(6);                    /* the delay slot of the branch */

    if (R(14) == 0) {
        /* the record has no kind yet: the flag word's low four bits decide */
        set_t(s, R(4) == 0);
        if (R(4) != 0) {
            set_t(s, R(4) == NIBBLE);
            if (R(4) != NIBBLE) {
                /* a new kind: the record keeps the kind and the four bits */
                R(2) = (uint32_t)half(ram, KIND);
                R(3) = 1u;
                R(2) += R(5);
                R(2) += R(7);
                vf3_mem_set_u8(ram, R(2), (uint8_t)R(3));
                R(3) = 0xfffffff0u;
                R(2) = (uint32_t)half(ram, STATE);
                R(6) &= R(3);
                R(2) += R(5);
                R(2) += R(7);
                vf3_mem_set_u8(ram, R(2), (uint8_t)R(4));
            }
        }
        copy_state(s, ram);
        leave(s, ram);
        return ram->oob == 0;
    }

    /* the record has a kind: the state byte and the caller's words decide */
    R(13) = (uint32_t)half(ram, STATE);
    R(3) = vf3_mem_u32(ram, GATE);
    R(13) += R(5);
    R(2) = vf3_mem_u32(ram, R(15) + 12u);
    R(13) += R(7);
    R(13) = (uint32_t)byte(ram, R(13));
    set_t(s, (R(2) & R(3)) == 0);
    R(13) &= 0xffu;                 /* the delay slot of the branch */

    if ((R(2) & R(3)) == 0) {
        /* the gate is closed: three tests have to hold */
        R(0) = R(13);
        set_t(s, R(0) == 4u);
        if (R(0) == 4u) {
            R(0) = vf3_mem_u32(ram, R(15) + 16u);
            set_t(s, (R(0) & 4u) == 0);
            if ((R(0) & 4u) == 0) {
                R(0) = R(4);
                set_t(s, R(0) == 1u);
                if (R(0) == 1u) {
                    /* the byte is copied and the kind is cleared */
                    copy_kind(s, ram);
                    clear_kind(s, ram);
                    leave(s, ram);
                    return ram->oob == 0;
                }
            }
        }
    }

    /* the second block: the state byte joins the flag word */
    R(0) = R(13);
    set_t(s, R(0) == 6u);
    if (R(0) == 6u) {
        R(0) = vf3_mem_u32(ram, R(15) + 16u);
        R(0) &= NIBBLE;
        set_t(s, R(0) == 2u);
        if (R(0) == 2u) {
            R(2) = (uint32_t)half(ram, EXTRA);
            R(6) |= R(2);
        }
    }
    R(4) |= R(13);
    R(0) = R(4);
    set_t(s, R(0) == NIBBLE);
    if (R(0) == NIBBLE) {
        clear_kind(s, ram);
        leave(s, ram);
        return ram->oob == 0;
    }

    /* the kind counts down */
    R(14) += 0xffffffffu;            /* the guest's "dec r14" */
    set_t(s, R(14) == 0);
    if (R(14) == 0) {
        clear_kind(s, ram);
        leave(s, ram);
        return ram->oob == 0;
    }
    R(3) = (uint32_t)half(ram, KIND);
    R(3) += R(5);
    R(3) += R(7);
    vf3_mem_set_u8(ram, R(3), (uint8_t)R(14));
    R(3) = 0xfffffff0u;
    R(2) = (uint32_t)half(ram, STATE);
    R(2) += R(5);
    R(7) += R(2);
    vf3_mem_set_u8(ram, R(7), (uint8_t)R(4));
    R(6) &= R(3);                    /* the delay slot of the branch */
    leave(s, ram);
    return ram->oob == 0;
}
