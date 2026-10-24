/* record_match.c - SH-4 0x8C03772A: does the object match the record the
 * engine expects?
 *
 * The function asks two helpers and then checks what they said:
 *
 *  - the first helper - the function pointer in the literal pool at
 *    0x8C03779C - gets the caller's r4, the object, and answers a pointer
 *    to a record;
 *  - the second helper - the pointer at 0x8C0377A0 - gets the second word
 *    of a twelve-byte header on the stack and answers a status.
 *
 * The answer is 1 when the status is not negative and everything else is the
 * one the engine expects:
 *
 *  - the record's first word is 14;
 *  - the header's words are 1, the global halfword at 0x8C03778E, 1;
 *  - the header's last two bytes are 0.
 *
 * Every other case answers 0.
 *
 * The guest keeps the header on the stack, saves r14 and pr around the
 * work, and the first helper's delay slot saves the caller's r4 in the
 * header's first word.  The readable port does the same, so the stack
 * words it leaves in RAM are the ones the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the helpers, in the literal pool */
#define G_FIRST_HELPER  0x0c03779cu
#define G_SECOND_HELPER 0x0c0377a0u

/* the global halfword the header's third word has to match */
#define G_EXPECTED 0x0c03778eu

/* the continuations the guest leaves in pr */
#define CONT_FIRST  0x0c037736u
#define CONT_SECOND 0x0c037742u

/* the record's kind the engine expects */
#define RECORD_KIND 14u

/* the header's words and the values they have to carry */
#define HDR_FIRST  4u
#define HDR_SECOND 6u
#define HDR_THIRD  8u
#define HDR_FLAG_A 10u
#define HDR_FLAG_B 11u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

/* The checks, in the guest's order.  Each one leaves its value in r0 and
 * sets the T flag, and the first one that fails ends the chain. */
static int record_matches(vf3_matrix_state *s, const vf3_ram_map *ram,
                          uint32_t header, uint32_t record, uint32_t status)
{
    /* the status has to be a non-negative one */
    set_t(s, (int32_t)status >= 0);
    if ((int32_t)status < 0) return 0;

    /* the record has to be the kind the engine expects */
    R(0) = vf3_mem_u32(ram, record);
    set_t(s, R(0) == RECORD_KIND);
    if (R(0) != RECORD_KIND) return 0;

    /* the header's first word */
    R(0) = vf3_mem_u16(ram, header + HDR_FIRST);
    set_t(s, R(0) == 1u);
    if (R(0) != 1u) return 0;

    /* the header's second word has to match the global */
    R(0) = vf3_mem_u16(ram, header + HDR_SECOND);
    R(3) = vf3_mem_u16(ram, G_EXPECTED);
    set_t(s, R(0) == R(3));
    if (R(0) != R(3)) return 0;

    /* the header's third word */
    R(0) = vf3_mem_u16(ram, header + HDR_THIRD);
    set_t(s, R(0) == 1u);
    if (R(0) != 1u) return 0;

    /* the header's two flag bytes have to be clear */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, header + HDR_FLAG_A);
    set_t(s, R(0) == 0u);
    if (R(0) != 0u) return 0;

    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, header + HDR_FLAG_B);
    set_t(s, R(0) == 0u);
    return R(0) == 0u;
}

int vf3_record_match_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the guest saves r14 and pr and keeps a twelve-byte header on the
     * stack below them */
    const uint32_t sp = R(15);
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    vf3_mem_set_u32(ram, sp - 8u, R(16));
    R(15) = sp - 20u;

    /* the first helper: it gets the object and answers a record */
    R(3) = vf3_mem_u32(ram, G_FIRST_HELPER);
    vf3_mem_set_u32(ram, R(15), R(4));       /* the call's delay slot */
    if (!vf3_guest_call(s, ram, R(3), CONT_FIRST)) return 0;
    R(14) = R(0);
    R(5) = R(0);

    /* the second helper: it fills the header and answers a status */
    R(2) = vf3_mem_u32(ram, G_SECOND_HELPER);
    R(4) = R(15);
    R(4) += 4u;
    if (!vf3_guest_call(s, ram, R(2), CONT_SECOND)) return 0;
    R(4) = R(0);

    R(0) = record_matches(s, ram, R(15), R(14), R(4)) ? 1u : 0u;

    /* the epilogue: the header goes, pr comes back and the rts restores r14 */
    R(15) += 12u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
