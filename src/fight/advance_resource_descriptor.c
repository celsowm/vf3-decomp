/* Original resource descriptor selector at 0x8c05c7c6.
 * Keep architectural register effects so callers can be replayed strictly.
 * Reload global pointers in instruction order: fixture aliases are observable.
 */
#include "fight/matrix_family.h"

#define R(n) s->v[(n)]

static void set_condition(vf3_matrix_state *s, int condition)
{
    R(17) = (R(17) & ~1u) | (condition != 0);
}

int vf3_advance_resource_descriptor(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(14), 4);
    R(6) = 0x0c16ca04; /* selected descriptor pointer */
    R(5) = 0x0c16ca18; /* five-word descriptor table */
    R(3) = 0x0c16cdc4;
    R(0) = vf3_matrix_read(ram, R(3), 4);
    set_condition(s, R(0) == 1);
    if (R(17) & 1u) {
        vf3_matrix_write(ram, R(6), R(5), 4);
    } else {
        R(1) = R(4);
        R(2) = R(4);
        R(1) <<= 2;
        R(1) += R(2);
        R(1) <<= 2;
        R(1) = (uint32_t)(int32_t)(int8_t)R(1);
        R(1) += R(5);
        vf3_matrix_write(ram, R(6), R(1), 4);
    }

    R(14) = 0;
    R(5) = 0x0c16ca08; /* destination descriptor pointer */
    R(7) = 5;
    for (unsigned word = 0; word < 5; ++word) {
        if (word == 0) {
            R(2) = vf3_matrix_read(ram, R(6), 4);
            R(3) = vf3_matrix_read(ram, R(5), 4);
        } else {
            R(3) = vf3_matrix_read(ram, R(5), 4);
            R(2) = vf3_matrix_read(ram, R(6), 4);
        }
        R(1) = vf3_matrix_read(ram, R(2) + word * 4, 4);
        if (word == 4) R(6) = R(14);
        vf3_matrix_write(ram, R(3) + word * 4, R(1), 4);
    }

    /* Preserve original positions before applying the five ring offsets. */
    R(1) = 0x0c16ca54;
    do {
        R(0) = R(6);
        R(3) = vf3_matrix_read(ram, R(5), 4);
        ++R(14);
        R(3) = vf3_matrix_read(ram, R(3) + R(0), 4);
        R(2) = R(6);
        R(2) += R(1);
        set_condition(s, R(14) >= R(7));
        vf3_matrix_write(ram, R(2), R(3), 4);
        R(6) += 4;
    } while (!(R(17) & 1u));

    R(2) = 1;
    R(3) = 0x0c16ca00;
    R(6) = 0;
    R(14) = 0x0c16ca74;
    R(4) &= R(2);
    vf3_matrix_write(ram, R(3), R(4), 4);
    R(4) = R(6);
    do {
        R(2) = vf3_matrix_read(ram, R(5), 4);
        R(2) += R(4);
        R(0) = R(4);
        R(3) = vf3_matrix_read(ram, R(14) + R(0), 4);
        ++R(6);
        R(1) = vf3_matrix_read(ram, R(2), 4);
        R(3) <<= 2;
        R(1) += R(3);
        set_condition(s, R(6) >= R(7));
        vf3_matrix_write(ram, R(2), R(1), 4);
        R(4) += 4;
    } while (!(R(17) & 1u));

    R(14) = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
    s->pc = R(16);
    return ram->oob == 0;
}
