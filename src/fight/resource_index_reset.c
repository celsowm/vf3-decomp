/* Reset sentinel entries in the resource index table, then run the real
 * per-index helper. The original caller supplies first=10, last=82, value=0. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
static void condition(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}
static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t value = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
    return value;
}
int vf3_resource_index_reset(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
    R(12) = 0xffff;
    R(10) = 0x0c2a620c;
    do {
        R(4) = (R(14) & 0xffffu) * 2 + R(10);
        R(3) = vf3_matrix_read(ram, R(4), 2) & 0xffffu;
        condition(s, R(3) == R(12));
        if (R(17) & 1u) vf3_matrix_write(ram, R(4), R(13), 2);
        R(4) = R(14);
        R(16) = 0x0c07ac12;
        if (!vf3_matrix_family(0x0c07b5f0, s, ram) || s->pc != 0x0c07ac12)
            return 0;
        ++R(14);
        R(2) = R(14) & 0xffffu;
        condition(s, (int32_t)R(2) > (int32_t)R(11));
    } while (!(R(17) & 1u));
    R(16) = pop(s, ram);
    for (unsigned reg = 10; reg <= 14; ++reg) R(reg) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
