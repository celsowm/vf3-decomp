/* Resource acquisition and linked allocation-range lookup. */
#include "fight/matrix_family.h"

#define R(n) s->v[n]
#define read_word(a) vf3_matrix_read(ram, (a), 4)

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

int vf3_resource_ranges(uint32_t entry, vf3_matrix_state *s,
                         const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
    switch (entry & 0x1fffffffu) {
    case 0x0c05cace:
        R(5) = read_word(0x0c16ca70);
        R(4) = read_word(0x0c16ca6c);
        R(3) = 0x0c061644;
        if (!call(s, ram, R(3), 0x0c05cadc)) return 0;
        R(4) = R(0);
        condition(s, R(4) == 0);
        if (R(17) & 1u) {
            R(4) = 0x0c16ca74;
            R(7) = 5;
            R(5) = R(6) = 0;
            do {
                vf3_matrix_write(ram, R(4), R(6), 4);
                ++R(5);
                condition(s, (int32_t)R(5) >= (int32_t)R(7));
                R(4) += 4;
            } while (!(R(17) & 1u));
            R(0) = 0;
        } else {
            R(0) = R(4);
        }
        break;

    case 0x0c061ba8:
        R(7) = R(5) + R(6);
        R(3) = 0x0c042d7c;
        R(1) = R(6);
        R(0) = 32;
        if (!call(s, ram, R(3), 0x0c061bb6)) return 0;
        condition(s, R(0) == 0);
        R(0) = 0x0c0eae10;
        R(3) = R(4);
        R(4) = (uint32_t)(int32_t)(int8_t)(R(4) * 20);
        R(4) = read_word(R(0) + R(4));
        condition(s, R(4) == 0);
        R(1) = 0;
        while (!(R(17) & 1u)) {
            if (!s->budget--) { s->failed_pc = 0x0c061bcc; return 0; }
            R(6) = read_word(R(4) + 12);
            condition(s, (int32_t)R(6) > (int32_t)R(5));
            if (!(R(17) & 1u)) {
                R(3) = read_word(R(4) + 16) + R(6);
                condition(s, (int32_t)R(3) > (int32_t)R(5));
                if (R(17) & 1u) {
                    condition(s, (int32_t)R(6) > (int32_t)R(7));
                    if (!(R(17) & 1u)) {
                        R(2) = read_word(R(4) + 16) + R(6);
                        condition(s, (int32_t)R(2) >= (int32_t)R(7));
                        if (R(17) & 1u) {
                            R(1) = R(4);
                            R(4) = 0;
                        } else {
                            R(4) = read_word(R(4) + 8);
                        }
                    } else {
                        R(4) = read_word(R(4) + 8);
                    }
                } else {
                    R(4) = read_word(R(4) + 8);
                }
            } else {
                R(4) = read_word(R(4) + 8);
            }
            condition(s, R(4) == 0);
        }
        condition(s, R(1) == 0);
        R(0) = (R(17) & 1u) ? 3 : 0;
        break;

    default:
        s->failed_pc = entry;
        return 0;
    }
    R(16) = read_word(R(15));
    R(15) += 4;
    s->pc = R(16);
    return ram->oob == 0;
}
