/* record_lookup.c - SH-4 0x8C037788: the record the engine looks up.
 *
 * The entry picks the record: the index 1 and the table behind the global
 * at 0x8C0377A4.  The lookup then asks the record predicate (0x8C03772A)
 * whether the record fits - the predicate gets the index and the table -
 * and, when it does, asks the table's own getter (the function pointer in
 * the literal pool at 0x8C037798) for the record itself.
 *
 * The answer is 0 when the record was found and the record's pointer is
 * left in r4, and -1 when the predicate says the record does not fit.  When
 * the getter answers a negative value, that value is the answer.
 *
 * The guest keeps the index and the table in a two-word frame on the stack
 * and the getter's arguments in three words below it; the readable port
 * keeps the same words in the same places, so the stack traffic it leaves
 * in RAM is the one the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the globals, in the literal pool */
#define G_TABLE  0x0c0377a4u   /* the table the record is looked up in */
#define G_GETTER 0x0c037798u   /* the table's getter */

/* the record predicate */
#define PREDICATE 0x0c03772au

/* the continuations the guest leaves in pr */
#define CONT_PREDICATE 0x0c0376ecu
#define CONT_GETTER    0x0c037710u

/* the getter's arguments: the size of a record */
#define RECORD_SIZE 48u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_record_lookup_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the entry picks the record */
    R(5) = vf3_mem_u32(ram, G_TABLE);
    R(4) = 1u;

    /* the frame: the index and the table */
    vf3_mem_set_u32(ram, sp - 4u, R(16));
    R(15) = sp - 12u;
    vf3_mem_set_u32(ram, R(15), R(4));
    vf3_mem_set_u32(ram, R(15) + 4u, R(5));

    /* the predicate decides whether the record fits */
    R(4) = vf3_mem_u32(ram, R(15));
    if (!vf3_guest_call(s, ram, PREDICATE, CONT_PREDICATE)) return 0;
    set_t(s, R(0) == 0);
    if (R(0) == 0) {
        /* no record fits: the answer is -1 */
        R(15) += 8u;
        R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
        R(0) = 0xffffffffu;
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* the record fits: the table's getter answers it.  Its arguments are
     * the size of a record, the table and the index */
    R(3) = RECORD_SIZE;
    vf3_mem_set_u32(ram, R(15) - 4u, R(3));
    R(15) -= 4u;
    R(1) = 0u;
    R(2) = vf3_mem_u32(ram, R(15) + 8u);      /* the table out of the frame */
    R(5) = 4u;
    R(6) = R(1);
    R(7) = R(1);
    vf3_mem_set_u32(ram, R(15) - 4u, R(2));    /* the table */
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15) - 4u, R(1));    /* the zero */
    R(15) -= 4u;

    R(2) = vf3_mem_u32(ram, G_GETTER);
    R(4) = vf3_mem_u32(ram, R(15) + 12u);      /* the index out of the frame */
    if (!vf3_guest_call(s, ram, R(2), CONT_GETTER)) return 0;
    R(4) = R(0);
    set_t(s, (int32_t)R(4) >= 0);

    /* the getter's arguments go, and with them the frame */
    R(15) += 12u;
    R(15) += 8u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    if ((int32_t)R(4) < 0) {
        /* the getter found nothing either: its answer is the answer */
        s->pc = R(16);
        return ram->oob == 0;
    }
    R(0) = 0u;
    s->pc = R(16);
    return ram->oob == 0;
}
