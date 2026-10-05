/* Scene indicator commands and repeated transforms through verified helpers. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]

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
static void condition(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}
static int call(vf3_matrix_state *s, const vf3_ram_map *ram,
                uint32_t target, uint32_t continuation)
{
    R(16) = continuation;
    return vf3_matrix_family(target, s, ram) && s->pc == continuation;
}

int vf3_advance_render_helpers(uint32_t entry, vf3_matrix_state *s,
                              const vf3_ram_map *ram)
{
    switch (entry & 0x1fffffffu) {
    case 0x0c06c4a2: /* Choose an indicator callback and append two commands. */
        push(s, ram, R(16));
        R(4) = vf3_matrix_read(ram, R(5) + 40, 4);
        R(14) = 0x0c29f2f0;
        R(4) = vf3_matrix_read(ram, R(4), 4);
        R(15) -= 4;
        condition(s, (R(4) & R(6)) == 0);
        if (!(R(17) & 1u)) {
            R(4) = vf3_matrix_read(ram, R(5) + 44, 4);
            R(4) = vf3_matrix_read(ram, R(4), 4);
            condition(s, (R(4) & R(6)) == 0);
        }
        if (R(17) & 1u) {
            R(3) = 0x0c1fd758;
            R(2) = 63;
            R(6) = 0x0c29bcc4;
            R(7) = 1;
            R(0) = 0x358;
            R(5) = vf3_matrix_read(ram, R(3), 4);
            R(4) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(6) + R(0), 1);
            R(5) &= R(2);
            condition(s, R(5) == 0);
            R(4) &= R(7);
            if (R(17) & 1u) {
                R(4) ^= R(7);
                vf3_matrix_write(ram, R(6) + R(0), R(4), 1);
            }
            R(0) = 0x0c0f2520;
            R(4) <<= 2;
            R(7) = 1;
            R(3) = vf3_matrix_read(ram, R(4) + R(0), 4);
            vf3_matrix_write(ram, R(15), R(3), 4);
            R(0) = 0x354;
            R(3) = 0x0c10b80c;
            R(4) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(6) + R(0), 1);
            R(6) = vf3_matrix_read(ram, R(3), 4);
            R(2) = vf3_matrix_read(ram, R(15), 4);
            R(6) += 5;
            R(5) = 39;
            if (!call(s, ram, R(2), 0x0c06c4ec)) return 0;
        }
        R(3) = 0x0c10b80c;
        R(1) = 32;
        R(2) = 0x1700;
        R(6) = 21;
        R(5) = vf3_matrix_read(ram, R(3), 4);
        R(7) = 1;
        push(s, ram, R(1));
        R(5) += 5;
        R(3) = 0x0c0c1836;
        condition(s, R(5) >> 31);
        R(5) <<= 1;
        R(5) |= R(2);
        R(4) = R(14);
        if (!call(s, ram, R(3), 0x0c06c506)) return 0;
        R(2) = 32;
        R(5) = 0x174e;
        R(6) = 21;
        push(s, ram, R(2));
        R(3) = 0x0c0c1836;
        R(7) = 1;
        R(4) = R(14);
        if (!call(s, ram, R(3), 0x0c06c516)) return 0;
        R(15) += 12;
        R(16) = pop(s, ram);
        R(14) = pop(s, ram);
        break;

    case 0x0c08aa64: /* Transform each record, preserving the matrix stack. */
        push(s, ram, R(16));
        R(3) = vf3_matrix_read(ram, R(2), 4);
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(3), 4);
        R(14) = (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram, R(4), 2);
        R(13) = 256;
        condition(s, (int32_t)R(14) > 0);
        R(13) += R(4);
        if (!(R(17) & 1u)) {
            R(15) += 4;
            R(16) = pop(s, ram);
            for (unsigned reg = 10; reg < 15; ++reg) R(reg) = pop(s, ram);
            break;
        }
        R(2) = 0x0c03c4f0;
        R(4) = 0;
        if (!call(s, ram, R(2), 0x0c08aa7c)) return 0;
        R(4) = vf3_matrix_read(ram, R(15), 4);
        R(2) = 0xfffffff3u;
        R(3) = 0x1000;
        R(1) = 3;
        R(0) = (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram, R(4) + 30, 2);
        R(12) = 0xf5e;
        R(4) = R(0) + R(3);
        R(4) = (uint32_t)((int32_t)R(4) >> 13);
        R(2) = 0x0c03ccb0;
        R(4) &= R(1);
        R(12) += R(4);
        if (!call(s, ram, R(2), 0x0c08aa96)) return 0;
        R(11) = 0x0c0a7662;
        R(10) = 0x0c03cbd0;
        for (;;) {
            condition(s, R(14) == 0);
            if (R(17) & 1u) break;
            if (!s->budget--) { s->failed_pc = 0x0c08aa9e; return 0; }
            R(4) = R(13);
            if (!call(s, ram, R(10), 0x0c08aaa2)) return 0;
            R(4) = R(12);
            if (!call(s, ram, R(11), 0x0c08aaa6)) return 0;
            --R(14);
            R(13) += 16;
        }
        R(15) += 4;
        R(3) = 0x0c03c4a0;
        R(16) = pop(s, ram);
        R(4) = 1;
        for (unsigned reg = 10; reg < 15; ++reg) R(reg) = pop(s, ram);
        return vf3_matrix_family(R(3), s, ram);

    default:
        s->failed_pc = entry;
        return 0;
    }
    s->pc = R(16);
    return ram->oob == 0;
}
