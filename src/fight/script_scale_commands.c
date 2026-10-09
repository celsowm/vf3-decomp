/* Fight-script opcodes 35/36 and 43: a scaled word and a bounded decrement
 * of the fighter's byte parameter at +0x201c. The latter also refreshes the
 * existing style-dependent model slots. Keep the original callable ABI and
 * advance through the real script dispatcher. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
#define word(a) vf3_matrix_read(ram, (a), 4)
#define byte(a) vf3_matrix_read(ram, (a), 1)
static void condition(vf3_matrix_state *s, int value)
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
    uint32_t value = word(R(15));
    R(15) += 4;
    return value;
}
static uint32_t signed_shift(uint32_t value, uint32_t count)
{
    if (!(count & 0x80000000u)) return value << (count & 31);
    unsigned amount = (-count) & 31;
    if (!amount) return (value & 0x80000000u) ? 0xffffffffu : 0;
    return (value >> amount) | ((value & 0x80000000u) ?
           (0xffffffffu << (32 - amount)) : 0);
}
static int scaled_word(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c0af448) {
        R(7) = word(R(6) + 8);
        R(3) = word(0x0c0af4f0);
        R(0) = (uint32_t)(int32_t)(int8_t)byte(R(7) + 4);
    }
    push(s, ram, R(16));
    R(0) = ((R(0) & 255u) << 8) & R(3);
    R(2) = R(0);
    R(0) = (uint32_t)(int32_t)(int8_t)byte(R(7) + 3);
    R(7) = R(2);
    R(2) = word(0x0c0af4f4);
    R(0) &= 255u;
    R(7) |= R(0);
    R(0) = 0x201c;
    push(s, ram, R(19));
    R(1) = (uint32_t)(int32_t)(int8_t)byte(R(5) + R(0));
    R(0) = 100;
    R(1) = (R(1) & 255u) + 100;
    R(19) = R(1) * R(7);
    R(7) = R(19);
    R(1) = R(7);
    R(16) = 0x0c0af476;
    if (!vf3_matrix_family(R(2), s, ram) || s->pc != R(16)) return 0;
    R(7) = R(0);
    R(0) = 0x2006;
    R(19) = pop(s, ram);
    vf3_matrix_write(ram, R(4) + R(0), R(7), 2);
    R(2) = word(R(6) + 8) + 5;
    vf3_matrix_write(ram, R(6) + 8, R(2), 4);
    R(1) = word(0x0c0af4ec);
    R(16) = pop(s, ram);
    return vf3_matrix_family(R(1), s, ram);
}
static int decrement(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c0af608) {
        push(s, ram, R(14)); R(14) = R(6);
        push(s, ram, R(13)); push(s, ram, R(12));
    }
    push(s, ram, R(16)); push(s, ram, R(19));
    R(15) -= 36;
    vf3_matrix_write(ram, R(15), R(4), 4);
    R(3) = word(R(14) + 4);
    R(2) = word(R(14));
    R(12) = word(0x0c0af708);
    R(4) = word(0x0c0af70c);
    condition(s, R(2) == R(3));
    R(13) = R(5);
    if (!(R(17) & 1u)) goto advance;
    R(1) = word(R(12) + 4);
    R(3) = word(0x0c0af710);
    condition(s, !(R(1) & R(3)));
    if (!(R(17) & 1u)) goto advance;
    R(2) = word(R(4) + 20);
    condition(s, (int32_t)R(2) > 0);
    if (!(R(17) & 1u)) goto advance;
    R(4) = word(R(14) + 8) + 3;
    R(4) = (uint32_t)(int32_t)(int8_t)byte(R(4));
    condition(s, R(4) == 0);
    if (!(R(17) & 1u)) {
        R(0) = 0x13d4;
        R(3) = word(R(15));
        R(2) = word(0x0c0af714);
        R(3) = signed_shift(word(R(3) + R(0)), R(4));
        condition(s, !(R(3) & R(2)));
        if (R(17) & 1u) goto advance;
    }
    R(4) = word(R(14) + 8) + 4;
    R(0) = 0x201c;
    R(3) = word(0x0c0af718);
    R(4) = (uint32_t)(int32_t)(int8_t)byte(R(4));
    R(5) = (uint32_t)(int32_t)(int8_t)byte(R(13) + R(0));
    R(0) = 10;
    R(4) &= 255u; R(5) &= 255u;
    R(19) = R(4) * R(5);
    R(4) = R(19); R(1) = R(4);
    R(16) = 0x0c0af666;
    if (!vf3_matrix_family(R(3), s, ram) || s->pc != R(16)) return 0;
    R(6) = 1; R(4) = R(0);
    condition(s, (int32_t)R(4) >= (int32_t)R(6));
    if (!(R(17) & 1u)) R(4) = R(6);
    R(5) -= R(4);
    condition(s, (int32_t)R(5) >= 0);
    if (!(R(17) & 1u)) R(5) = 0;
    R(0) = 0x201c;
    vf3_matrix_write(ram, R(13) + R(0), R(5), 1);
    R(3) = word(0x0c0af71c);
    R(4) = R(13); R(16) = 0x0c0af682;
    if (!vf3_matrix_family(R(3), s, ram) || s->pc != R(16)) return 0;
    R(0) = 97;
    R(4) = (uint32_t)(int32_t)(int8_t)byte(R(13) + R(0));
    R(0) = R(4) & 255u;
    condition(s, R(0) == 8); R(4) = R(0);
    if (!(R(17) & 1u)) {
        R(0) = R(4); condition(s, R(0) == 9);
        if (!(R(17) & 1u)) goto advance;
    }
    R(0) = byte(R(12) + 8) & 255u;
    condition(s, R(0) == 7);
    if (!(R(17) & 1u)) goto advance;
    R(2) = word(R(12) + 4);
    R(3) = word(0x0c0af720);
    condition(s, !(R(2) & R(3)));
    if (!(R(17) & 1u)) {
        R(0) = (uint32_t)(int32_t)(int8_t)byte(R(13) + 4);
        condition(s, R(0) == 0);
    }
advance:
    R(2) = word(R(14) + 8);
    R(5) = R(13); R(6) = R(14); R(2) += 5;
    vf3_matrix_write(ram, R(14) + 8, R(2), 4);
    R(3) = word(0x0c0af724);
    R(4) = word(R(15)); R(16) = 0x0c0af6b8;
    if (!vf3_matrix_family(R(3), s, ram) || s->pc != R(16)) return 0;
    R(15) += 36;
    R(19) = pop(s, ram); R(16) = pop(s, ram);
    R(12) = pop(s, ram); R(13) = pop(s, ram); R(14) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
int vf3_script_scale_command(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c0af448 || entry == 0x0c0af44e) return scaled_word(entry, s, ram);
    return decrement(entry, s, ram);
}
