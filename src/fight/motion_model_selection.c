/* Select the sixteen runtime model slots for styles 8 and 21, then apply
 * the existing model-slot loop. Other styles leave the slots untouched. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
static void push(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t value)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), value, 4);
}
static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t value = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
    return value;
}
int vf3_motion_model_selection(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c09517au) {
        push(s, ram, R(16));
        R(4) = vf3_matrix_read(ram, R(3), 4);
        R(5) = 0;
        R(16) = 0x0c095182;
        if (!vf3_motion_model_selection(0x0c09518c, s, ram) || s->pc != R(16)) return 0;
        R(3) = vf3_matrix_read(ram, 0x0c095258, 4);
        R(5) = 0;
        R(4) = vf3_matrix_read(ram, R(3), 4);
        R(16) = pop(s, ram);
        return vf3_motion_model_selection(0x0c09518c, s, ram);
    }
    push(s, ram, R(16));
    R(0) = 96;
    R(15) -= 8;
    vf3_matrix_write(ram, R(15) + 4, R(5), 4);
    R(0) = vf3_matrix_read(ram, R(4) + R(0), 1) & 255u;
    R(5) = vf3_matrix_read(ram, 0x0c09525c, 4);
    R(17) = (R(17) & ~1u) | (R(0) == 8);
    unsigned style = R(0);
    if (style != 8) R(17) = (R(17) & ~1u) | (style == 21);
    if (style == 8 || style == 21) {
        R(2) = vf3_matrix_read(ram, style == 8 ? 0x0c09524e : 0x0c095250, 2);
        R(6) = 15;
        R(5) += R(2);
        vf3_matrix_write(ram, R(15), R(5), 4);
        if (style == 21) R(5) = 1;
        R(3) = vf3_matrix_read(ram, R(15) + 4, 4);
        push(s, ram, R(3));
        R(7) = vf3_matrix_read(ram, R(15) + 4, 4);
        if (style == 8) R(5) = 0;
        R(16) = 0x0c0951c8;
        if (!vf3_matrix_family(0x0c0951d2, s, ram) || s->pc != R(16)) return 0;
        R(15) += 4;
    }
    R(15) += 8;
    R(16) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
