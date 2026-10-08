/* Packed motion command: select a transition from the current motion flags,
 * then advance the bytecode cursor through the original motion dispatcher. */
#include "fight/matrix_family.h"
#include <string.h>

#define R(n) s->v[n]
#define FR(n) s->v[21 + (n)]
#define word(a) vf3_matrix_read(ram, (a), 4)

static void condition(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

static float as_float(uint32_t bits)
{
    float value;
    memcpy(&value, &bits, sizeof value);
    return value;
}

/* The bytecode is unaligned little-endian data. Keep the original scratch
 * register effects as well as the decoded word for architectural replay. */
static void packed_word(vf3_matrix_state *s, const vf3_ram_map *ram,
                        uint32_t address, unsigned destination)
{
    R(0) = vf3_matrix_read(ram, address + 3, 1) << 24;
    R(destination) = R(0) & R(10);
    R(0) = vf3_matrix_read(ram, address + 2, 1) << 16;
    R(0) &= R(9);
    R(destination) |= R(0);
    R(0) = vf3_matrix_read(ram, address + 1, 1) << 8;
    R(0) &= R(12);
    R(destination) |= R(0);
    R(0) = vf3_matrix_read(ram, address, 1);
    R(destination) |= R(0);
}

static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t value = word(R(15));
    R(15) += 4;
    return value;
}

int vf3_motion_flag_command(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
    R(15) -= 16;
    R(7) = R(15) + 8;
    vf3_matrix_write(ram, R(15) + 4, R(7), 4);
    vf3_matrix_write(ram, R(15), R(7), 4);

    R(7) = word(R(6) + 8);
    R(10) = 0xff000000;
    R(9) = 0x00ff0000;
    R(13) = vf3_matrix_read(ram, R(7) + 3, 1);
    R(12) = 0x0000ff00;
    packed_word(s, ram, R(7) + 4, 14);
    R(3) = word(R(15) + 4);
    packed_word(s, ram, R(7) + 8, 2);
    vf3_matrix_write(ram, R(3), R(2), 4);
    R(3) = word(R(15));
    vf3_matrix_load(s, ram, 4, R(3));
    R(3) = R(13) << 24;
    R(7) = 0x80000000;
    condition(s, (R(3) & R(7)) == 0);
    R(1) = 127;
    if (R(17) & 1u) {
        R(0) = 76;
        R(3) = 0xfeffffff;
        R(2) = word(R(4) + R(0)) & R(3);
        vf3_matrix_write(ram, R(4) + R(0), R(2), 4);
    }

    R(0) = 80;
    R(3) = word(R(4) + R(0));
    R(13) &= R(1);
    R(3) <<= R(13) & 31u;
    condition(s, (R(3) & R(7)) == 0);
    if (R(17) & 1u) goto advance;
    R(2) = word(R(5));
    R(11) = 0x04000000;
    condition(s, (R(2) & R(11)) == 0);
    if (!(R(17) & 1u)) goto advance;
    FR(3) = 0;
    condition(s, as_float(FR(4)) == as_float(FR(3)));
    if (!(R(17) & 1u)) {
        R(0) = 92;
        vf3_matrix_load(s, ram, 3, R(4) + R(0));
        condition(s, as_float(FR(3)) > as_float(FR(4)));
        if (R(17) & 1u) goto advance;
    }

    R(7) = word(R(6) + 8);
    packed_word(s, ram, R(7) + 4, 3);
    R(7) = R(3) & 65535u;
    R(3) = 0x2b9;
    condition(s, R(7) == R(3));
    if (R(17) & 1u) goto first_pair;
    R(2) = 0x2c5;
    condition(s, R(7) == R(2));
    if (R(17) & 1u) goto first_pair;
    R(3) = 0x2bd;
    condition(s, R(7) == R(3));
    if (R(17) & 1u) goto second_pair;
    R(2) = 0x2c0;
    condition(s, R(7) == R(2));
    if (R(17) & 1u) goto second_pair;
    goto previous_motion;

first_pair:
    R(0) = 80;
    R(1) = word(R(4) + R(0));
    condition(s, (R(1) & R(11)) == 0);
    R(14) = (R(17) & 1u) ? 0x0c0002b9 : 0x0c0002c5;
    goto previous_motion;

second_pair:
    R(0) = 80;
    R(2) = word(R(4) + R(0));
    condition(s, (R(2) & R(11)) == 0);
    R(14) = (R(17) & 1u) ? 0x0c0002bd : 0x0c0002c0;

previous_motion:
    R(0) = 60;
    R(3) = 0xb66;
    R(7) = vf3_matrix_read(ram, R(4) + R(0), 2);
    R(0) = 80;
    R(10) = word(R(4) + R(0));
    R(13) = 0x02000000;
    R(12) = R(10) & R(11);
    condition(s, R(7) == R(3));
    R(13) &= R(10);
    if (R(17) & 1u) {
        condition(s, R(12) == 0);
        if (!(R(17) & 1u)) goto advance;
        condition(s, R(13) == 0);
        if (!(R(17) & 1u)) goto advance;
    } else {
        R(2) = 0xb68;
        condition(s, R(7) == R(2));
        if (R(17) & 1u) {
            condition(s, R(12) == 0);
            if (R(17) & 1u) goto advance;
            condition(s, R(13) == 0);
            if (R(17) & 1u) goto advance;
        } else {
            R(3) = 0xb65;
            condition(s, R(7) == R(3));
            if (R(17) & 1u) {
                condition(s, R(12) == 0);
                if (!(R(17) & 1u)) goto advance;
                condition(s, R(13) == 0);
                if (R(17) & 1u) goto advance;
            } else {
                R(2) = 0xb67;
                condition(s, R(7) == R(2));
                if (R(17) & 1u) {
                    condition(s, R(12) == 0);
                    if (R(17) & 1u) goto advance;
                    condition(s, R(13) == 0);
                    if (R(17) & 1u) goto advance;
                }
            }
        }
    }
    vf3_matrix_write(ram, R(4) + 48, R(14), 4);

advance:
    R(2) = word(R(6) + 8);
    R(3) = 0x0c0ae29c;
    R(2) += 12;
    R(16) = 0x0c0af352;
    vf3_matrix_write(ram, R(6) + 8, R(2), 4);
    if (!vf3_matrix_family(R(3), s, ram) || s->pc != 0x0c0af352) return 0;
    R(15) += 16;
    R(16) = pop(s, ram);
    for (unsigned reg = 9; reg <= 14; ++reg) R(reg) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
