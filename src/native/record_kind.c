/* record_kind.c - SH-4 0x8C078044: a record's kind byte, and the flag word that
 * goes with it, natively.
 *
 * A plain-C transcription of the readable port src/fight/record_kind.c
 * (`vf3_record_kind_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody and uses no FPU,
 * but it keeps a **frame**: it saves r13/r14 at sp-4/-8 and restores them (r14
 * in the delay slot of the return), and it reads the caller's three frame words
 * at the *entry* sp + 0/+4/+8 (i.e. at r15+8/+12/+16 after its own push).
 *
 * The function is handed a record - r5 is its base and r7 an index into it -
 * and the flag word the caller left in its frame.  The record keeps three
 * bytes that matter:
 *
 *   * the **kind** byte, at the offset in the pool (0x0c07815A) plus the
 *     index.  It counts down: it is set to one when the record gets a kind,
 *     and taken down to zero again when the record is finished.
 *   * the **state** byte, at the offset in the pool (0x0c07815C) plus the
 *     index.  It holds the low four bits of the flag word.
 *   * the byte at the third offset (0x0c07815E), which the guest copies into
 *     two places: the fourth offset (0x0c078160) plus the index, and the
 *     third offset plus 51.
 *
 * The pool's values are read at run time, not baked in, so the port follows
 * the image.  When the kind byte is still zero the record has no kind yet:
 * the flag word's low four bits decide (zero or fifteen mean the record is
 * already complete; anything else starts a kind).  When the record has a
 * kind the gate mask (0x0c07816C) is tested against the caller's gate word,
 * and when it holds the byte is copied and the kind cleared.  Otherwise the
 * state byte joins the flag word and the kind counts down (or clears).
 *
 * See docs/re/native_record_kind.md. */
#include "record_kind.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

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

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_aim_h16(a, addr);
}

/* the guest's byte: eight bits, sign extended */
static int32_t byte(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int8_t)vf3_aim_u8(a, addr);
}

/* The guest's first copy (at 0x8C07807C): the byte at the third offset goes to
 * the fourth offset plus the index and to the third offset plus 51.  The byte
 * it copies lands in r4 - the flag word's low four bits - and the address it
 * writes to lands in r7. */
static void copy_state(vf3_native_aim *a)
{
    R(0) = (uint32_t)half(a, SOURCE);
    R(3) = (uint32_t)half(a, DEST);
    R(4) = (uint32_t)byte(a, R(5) + R(0));
    R(0) += SECOND_PLACE;
    R(3) += R(5);
    R(7) += R(3);
    R(4) &= 0xffu;
    w8(a, R(7), (uint8_t)R(4));
    w8(a, R(5) + R(0), (uint8_t)R(4));
}

/* The guest's second copy (at 0x8C0780B4): the same byte, but it lands in r14 -
 * the kind - and the address it writes to lands in r3. */
static void copy_kind(vf3_native_aim *a)
{
    R(0) = (uint32_t)half(a, SOURCE);
    R(3) = (uint32_t)half(a, DEST);
    R(14) = (uint32_t)byte(a, R(5) + R(0));
    R(0) += SECOND_PLACE;
    R(3) += R(5);
    R(3) += R(7);
    R(14) &= 0xffu;
    w8(a, R(3), (uint8_t)R(14));
    w8(a, R(5) + R(0), (uint8_t)R(14));
}

/* The guest's end at 0x8C0780FC: the kind byte goes back to zero and the flag
 * word keeps the four bits. */
static void clear_kind(vf3_native_aim *a)
{
    R(1) = (uint32_t)half(a, KIND);
    R(3) = 0u;
    R(6) |= R(4);
    R(1) += R(5);
    R(7) += R(1);
    w8(a, R(7), (uint8_t)R(3));
}

/* The guest's return: the saved r13 comes back, the flag word is the answer,
 * and the saved r14 comes back in the delay slot of the return. */
static void leave(vf3_native_aim *a)
{
    R(13) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
    R(0) = R(6);
    R(14) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
}

void vf3_native_record_kind(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the guest saves r14 and r13 */
    vf3_aim_set_u32(a, sp - 4u, R(14));
    vf3_aim_set_u32(a, sp - 8u, R(13));
    R(15) = sp - 8u;

    /* the kind byte of the record, and the flag word the caller left */
    R(4) = NIBBLE;
    R(14) = (uint32_t)half(a, KIND);
    R(6) = vf3_aim_u32(a, R(15) + 8u);
    R(14) += R(5);
    R(14) += R(7);
    R(14) = (uint32_t)byte(a, R(14));
    R(14) &= 0xffu;
    set_t(a, R(14) == 0);
    R(4) &= R(6);                    /* the delay slot of the branch */

    if (R(14) == 0) {
        /* the record has no kind yet: the flag word's low four bits decide */
        set_t(a, R(4) == 0);
        if (R(4) != 0) {
            set_t(a, R(4) == NIBBLE);
            if (R(4) != NIBBLE) {
                /* a new kind: the record keeps the kind and the four bits */
                R(2) = (uint32_t)half(a, KIND);
                R(3) = 1u;
                R(2) += R(5);
                R(2) += R(7);
                w8(a, R(2), (uint8_t)R(3));
                R(3) = 0xfffffff0u;
                R(2) = (uint32_t)half(a, STATE);
                R(6) &= R(3);
                R(2) += R(5);
                R(2) += R(7);
                w8(a, R(2), (uint8_t)R(4));
            }
        }
        copy_state(a);
        leave(a);
        return;
    }

    /* the record has a kind: the state byte and the caller's words decide */
    R(13) = (uint32_t)half(a, STATE);
    R(3) = vf3_aim_u32(a, GATE);
    R(13) += R(5);
    R(2) = vf3_aim_u32(a, R(15) + 12u);
    R(13) += R(7);
    R(13) = (uint32_t)byte(a, R(13));
    set_t(a, (R(2) & R(3)) == 0);
    R(13) &= 0xffu;                 /* the delay slot of the branch */

    if ((R(2) & R(3)) == 0) {
        /* the gate is closed: three tests have to hold */
        R(0) = R(13);
        set_t(a, R(0) == 4u);
        if (R(0) == 4u) {
            R(0) = vf3_aim_u32(a, R(15) + 16u);
            set_t(a, (R(0) & 4u) == 0);
            if ((R(0) & 4u) == 0) {
                R(0) = R(4);
                set_t(a, R(0) == 1u);
                if (R(0) == 1u) {
                    /* the byte is copied and the kind is cleared */
                    copy_kind(a);
                    clear_kind(a);
                    leave(a);
                    return;
                }
            }
        }
    }

    /* the second block: the state byte joins the flag word */
    R(0) = R(13);
    set_t(a, R(0) == 6u);
    if (R(0) == 6u) {
        R(0) = vf3_aim_u32(a, R(15) + 16u);
        R(0) &= NIBBLE;
        set_t(a, R(0) == 2u);
        if (R(0) == 2u) {
            R(2) = (uint32_t)half(a, EXTRA);
            R(6) |= R(2);
        }
    }
    R(4) |= R(13);
    R(0) = R(4);
    set_t(a, R(0) == NIBBLE);
    if (R(0) == NIBBLE) {
        clear_kind(a);
        leave(a);
        return;
    }

    /* the kind counts down */
    R(14) += 0xffffffffu;            /* the guest's "dec r14" */
    set_t(a, R(14) == 0);
    if (R(14) == 0) {
        clear_kind(a);
        leave(a);
        return;
    }
    R(3) = (uint32_t)half(a, KIND);
    R(3) += R(5);
    R(3) += R(7);
    w8(a, R(3), (uint8_t)R(14));
    R(3) = 0xfffffff0u;
    R(2) = (uint32_t)half(a, STATE);
    R(2) += R(5);
    R(7) += R(2);
    w8(a, R(7), (uint8_t)R(4));
    R(6) &= R(3);                    /* the delay slot of the branch */
    leave(a);
}
