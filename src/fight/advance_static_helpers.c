/* Original calendar, numeric text, object-command and record helpers. */
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

static int call(vf3_matrix_state *s, const vf3_ram_map *ram,
                uint32_t target, uint32_t continuation)
{
    R(16) = continuation;
    return vf3_matrix_family(target, s, ram) && s->pc == continuation;
}

static void condition(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

int vf3_advance_static_helpers(uint32_t entry, vf3_matrix_state *s,
                              const vf3_ram_map *ram)
{
    switch (entry & 0x1fffffffu) {
    case 0x0c04f304: /* Find an active record using the installed word getter. */
        push(s, ram, R(16));
        push(s, ram, R(19));
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(5), 4);
        R(12) = 0x148;
        R(3) = 0x0c1b34d8;
        R(19) = (uint32_t)((int32_t)(int16_t)R(12) * (int32_t)(int16_t)R(4));
        R(11) = 0x0c1b34d4;
        R(12) = (uint32_t)(int32_t)(int16_t)R(19);
        R(12) += R(3);
        R(14) = vf3_matrix_read(ram, R(12) + 40, 4);
        R(13) = 0;
        for (;;) {
            if (!s->budget--) { s->failed_pc = 0x0c04f342; return 0; }
            R(2) = vf3_matrix_read(ram, R(12) + 28, 4);
            R(3) = vf3_matrix_read(ram, R(2) + 48, 4);
            condition(s, (int32_t)R(13) >= (int32_t)R(3));
            if (R(17) & 1u) { R(0) = 0; break; }
            R(4) = vf3_matrix_read(ram, R(14), 1) & 255u;
            condition(s, R(4) == 0);
            if (!(R(17) & 1u)) {
                R(2) = vf3_matrix_read(ram, R(11), 4);
                R(5) = 2;
                R(3) = vf3_matrix_read(ram, R(2) + 12, 4);
                R(4) = R(14);
                if (!call(s, ram, R(3), 0x0c04f332)) return 0;
                R(2) = vf3_matrix_read(ram, R(15), 4);
                R(0) &= 65535u;
                condition(s, R(0) == R(2));
                if (R(17) & 1u) { R(0) = R(14); break; }
            }
            R(14) += 32;
            ++R(13);
        }
        R(15) += 4;
        R(19) = pop(s, ram);
        R(16) = pop(s, ram);
        for (unsigned reg = 11; reg < 15; ++reg) R(reg) = pop(s, ram);
        break;

    case 0x0c09a758: /* Scene timeout and secondary mode byte. */
        push(s, ram, R(16));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(13) + R(0), 1);
        R(14) = 0x0c29b864;
        condition(s, R(0) == 1);
        if (!(R(17) & 1u)) {
            R(3) = 0x0c0a00b6;
            if (!call(s, ram, R(3), 0x0c09a768)) return 0;
            R(2) = vf3_matrix_read(ram, R(14) + 12, 4);
            condition(s, (int32_t)R(2) > 0);
            if (R(17) & 1u) goto scene_return;
            R(0) = 0x8b;
            R(1) = 1;
            R(2) = 45;
            vf3_matrix_write(ram, R(13) + R(0), R(1), 1);
            R(0) = 16;
            R(3) = 256;
            vf3_matrix_write(ram, R(14) + 12, R(3), 4);
            vf3_matrix_write(ram, R(14) + R(0), R(2), 1);
        }
        R(3) = vf3_matrix_read(ram, R(14) + 12, 4);
        condition(s, (int32_t)R(3) > 0);
        if (!(R(17) & 1u)) {
            R(0) = vf3_matrix_read(ram, R(13) + 8, 4);
            condition(s, (R(0) & 4u) == 0);
            if (!(R(17) & 1u)) R(0) = 18;
            else {
                R(0) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(14) + 10, 1);
                ++R(0);
            }
            vf3_matrix_write(ram, R(14) + 10, R(0), 1);
        }
scene_return:
        R(16) = pop(s, ram);
        R(13) = pop(s, ram);
        R(14) = pop(s, ram);
        break;

    case 0x0c0376a0: /* Calendar arithmetic with original division helpers. */
        push(s, ram, R(16));
        R(2) = 2;
        R(3) = R(5) & 255u;
        push(s, ram, R(19));
        condition(s, (int32_t)R(3) > (int32_t)R(2));
        if (!(R(17) & 1u)) { R(5) += 12; --R(4); }
        R(3) = 13;
        R(2) = 0x0c042c20;
        R(1) = R(5) & 255u;
        R(19) = (R(1) & 65535u) * (R(3) & 65535u);
        R(1) = R(19) + 8;
        R(0) = 5;
        if (!call(s, ram, R(2), 0x0c0376c0)) return 0;
        R(7) = R(4) & 65535u;
        R(2) = 0x0c042d7c;
        R(1) = R(7);
        for (unsigned shift = 0; shift < 2; ++shift) {
            condition(s, R(1) & 1u);
            R(1) = (uint32_t)((int32_t)R(1) >> 1);
        }
        R(1) += R(0);
        R(6) &= 255u;
        R(1) += R(7);
        R(1) += R(6);
        R(1) -= 15;
        R(0) = 7;
        if (!call(s, ram, R(2), 0x0c0376d8)) return 0;
        R(19) = pop(s, ram);
        R(16) = pop(s, ram);
        break;

    case 0x0c03ada4: /* Generate digits in reverse, then copy to the output. */
        push(s, ram, R(16));
        R(15) -= 32;
        R(14) = R(15);
        R(6) = 0;
        condition(s, R(4) == 0);
        while (!(R(17) & 1u)) {
            if (!s->budget--) { s->failed_pc = 0x0c03adb0; return 0; }
            R(2) = 0x0c042d7c;
            R(3) = R(6);
            R(1) = R(4);
            R(3) += R(14);
            R(0) = R(7);
            if (!call(s, ram, R(2), 0x0c03adbc)) return 0;
            R(0) += 48;
            vf3_matrix_write(ram, R(3), R(0), 1);
            R(0) = R(7);
            R(3) = 0x0c042c20;
            R(1) = R(4);
            if (!call(s, ram, R(3), 0x0c03adc8)) return 0;
            ++R(6);
            R(4) = R(0);
            condition(s, R(4) == 0);
        }
        R(4) = R(6);
        condition(s, R(6) == 0);
        while (!(R(17) & 1u)) {
            if (!s->budget--) { s->failed_pc = 0x0c03ade0; return 0; }
            R(0) = R(6) - 1;
            R(3) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(14) + R(0), 1);
            --R(6);
            vf3_matrix_write(ram, R(5), R(3), 1);
            ++R(5);
            condition(s, R(6) == 0);
        }
        R(15) += 32;
        R(0) = R(4);
        R(16) = pop(s, ram);
        R(14) = pop(s, ram);
        break;

    case 0x0c0469c0: /* Validate an object, set its mode and submit arguments. */
        push(s, ram, R(16));
        R(15) -= 8;
        vf3_matrix_write(ram, R(15), R(5), 4);
        vf3_matrix_write(ram, R(15) + 4, R(6), 4);
        R(3) = 0x0c04c47c;
        R(4) = R(14);
        if (!call(s, ram, R(3), 0x0c0469ce)) return 0;
        condition(s, R(0) == 0);
        if (!(R(17) & 1u)) {
            R(0) = 0xffffffff;
        } else {
            R(3) = 0x0c04c48c;
            R(5) = 17;
            R(4) = R(14);
            if (!call(s, ram, R(3), 0x0c046a0c)) return 0;
            R(13) = 0;
            R(5) = R(14);
            for (unsigned argument = 0; argument < 3; ++argument) push(s, ram, R(13));
            R(3) = 0x0c04c49c;
            R(6) = vf3_matrix_read(ram, R(15) + 12, 4);
            R(7) = vf3_matrix_read(ram, R(15) + 16, 4);
            R(4) = R(14);
            if (!call(s, ram, R(3), 0x0c046a20)) return 0;
            R(0) = R(13);
            R(15) += 12;
        }
        R(15) += 8;
        R(16) = pop(s, ram);
        R(13) = pop(s, ram);
        R(14) = pop(s, ram);
        break;

    case 0x0c0853a2: /* Populate records from immutable tables and the RNG. */
        push(s, ram, R(16));
        R(10) = 0x0c0f558c;
        R(9) = 0x0c03a5a0;
        R(13) = 0x0c0f55c4;
        R(35) = 0; /* FR14: zero component */
        do {
            if (!s->budget--) { s->failed_pc = 0x0c0853ac; return 0; }
            R(0) = 16;
            vf3_matrix_load(s, ram, 13, R(13) + R(0));
            R(0) = 20;
            vf3_matrix_load(s, ram, 15, R(13) + R(0));
            R(13) += 32;
            R(11) = vf3_matrix_read(ram, R(10), 4);
            R(10) += 4;
            if (!call(s, ram, R(9), 0x0c0853ba)) return 0;
            vf3_matrix_write(ram, R(14) + 12, R(0), 2);
            R(4) = R(0);
            R(0) = 4;
            vf3_matrix_write(ram, R(14) + 20, R(11), 4);
            --R(12);
            condition(s, R(12) == 0);
            vf3_matrix_store(s, ram, 13, R(14));
            vf3_matrix_store(s, ram, 14, R(14) + R(0));
            R(0) = 8;
            vf3_matrix_store(s, ram, 15, R(14) + R(0));
            R(14) += 24;
        } while (!(R(17) & 1u));
        R(16) = pop(s, ram);
        for (unsigned floating = 13; floating < 16; ++floating) {
            vf3_matrix_load(s, ram, floating, R(15));
            R(15) += (R(18) & 0x100000u) ? 8 : 4;
        }
        for (unsigned reg = 9; reg < 15; ++reg) R(reg) = pop(s, ram);
        break;

    default:
        s->failed_pc = entry;
        return 0;
    }
    s->pc = R(16);
    return ram->oob == 0;
}
