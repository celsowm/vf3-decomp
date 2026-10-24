/* record_state_field.c - SH-4 0x8C035A20: the record's state getter.
 *
 * The getter answers the record's code halfword at +0x4C, but only when the
 * flag halfword at +0x48 says the record carries one.  A record without a
 * flag - and a null record - answers -10, the "no code" answer the record
 * walk turns into -25.
 *
 * The function has no frame: it pushes nothing and pops nothing, so the
 * readable port does not either.  It leaves the flag in r2, the code in r0
 * and the T flag says whether the record was empty (set) or carried a code
 * (clear).
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the record's fields */
#define NODE_FLAG 0x48u
#define NODE_CODE 0x4cu

/* the "no code" answer */
#define RESULT_NO_CODE 0xfffffff6u   /* -10 */

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_record_state_get_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t record = R(4);
    set_t(s, record == 0);
    if (record == 0) {
        R(0) = RESULT_NO_CODE;
        s->pc = R(16);
        return ram->oob == 0;
    }
    R(0) = NODE_FLAG;
    R(2) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, record + R(0));
    set_t(s, R(2) == 0);
    if (R(2) == 0) {
        R(0) = RESULT_NO_CODE;
        s->pc = R(16);
        return ram->oob == 0;
    }
    R(0) = NODE_CODE;
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, record + R(0));
    s->pc = R(16);
    return ram->oob == 0;
}
