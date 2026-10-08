/* Update color and position fields in existing model descriptor chains.
 * These helpers write model RAM; they do not submit commands to hardware. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
static void flag(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}
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
int vf3_model_render_fields(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c09528cu) {
        R(4) = vf3_matrix_read(ram, R(4) + 12, 4);
        flag(s, R(4) == 0);
        if (R(4)) {
            R(6) <<= 8;
            R(0) = R(6) | R(7);
            vf3_matrix_write(ram, R(4) + 4, R(0), 2);
            R(0) = 0xffffff00u | R(5);
            vf3_matrix_write(ram, R(4) + 6, R(0), 2);
        }
    } else {
        push(s, ram, R(12));
        R(1) = R(4);
        push(s, ram, R(11));
        R(3) = 0xfffffff8u;
        push(s, ram, R(10));
        R(1) += 24;
        R(11) = vf3_matrix_read(ram, R(15) + 12, 4);
        R(10) = 32;
        R(12) = 0xffffffcfu;
        R(11) = (uint32_t)((int32_t)R(11) >> 8);
        for (;;) {
            if (!s->budget--) { s->failed_pc = 0x0c0952b8; return 0; }
            R(3) = vf3_matrix_read(ram, R(1), 4);
            flag(s, R(3) == 0);
            if (!R(3)) break;
            R(2) = vf3_matrix_read(ram, R(1), 4);
            R(4) = R(1) + 40;
            R(2) &= R(12);
            R(3) = R(2) | R(10);
            R(0) = 0xfffffffeu;
            vf3_matrix_write(ram, R(1), R(3), 4);
            R(2) = vf3_matrix_read(ram, R(4), 4) & R(0);
            vf3_matrix_write(ram, R(4), R(2), 4);
            R(4) = vf3_matrix_read(ram, R(1) + 32, 4);
            R(0) = R(4);
            int position = R(11) ?
                (R(4) == 3 || R(4) == 5 || R(4) == 6 || R(4) == 8) :
                (R(4) == 5 || R(4) == 8 || R(4) == 9 || R(4) == 12);
            if (position) {
                vf3_matrix_write(ram, R(1) + 48, R(5), 4);
                vf3_matrix_write(ram, R(1) + 52, R(6), 4);
                vf3_matrix_write(ram, R(1) + 56, R(7), 4);
            }
            R(0) = 76;
            R(3) = R(1) + 80;
            R(1) = vf3_matrix_read(ram, R(1) + 76, 4) + R(3);
        }
        for (unsigned reg = 10; reg <= 12; ++reg) R(reg) = pop(s, ram);
    }
    s->pc = R(16);
    return ram->oob == 0;
}
