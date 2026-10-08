/* Two task commands select display style and use the real text command path.
 * Their final parameter comes from adjacent task fields. */
#include "fight/matrix_family.h"

#define R(n) s->v[n]
#define byte(a) ((uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, (a), 1))

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

int vf3_task_text_command(uint32_t entry, vf3_matrix_state *s,
                               const vf3_ram_map *ram)
{
    int second = (entry & 0x1fffffffu) == 0x0c06cea2u;
    uint32_t continuation;
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
    R(3) = byte(R(4) + R(0));
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(3), 4);
    R(0) = 0x92;
    R(11) = byte(R(4) + R(0));
    R(0) = 0x346;
    R(6) = byte(R(4) + R(0));
    ++R(0);
    R(7) = byte(R(4) + R(0));
    R(0) += second ? 15 : 13;
    R(5) = byte(R(4) + R(0));
    R(0) = R(3);
    condition(s, R(0) == 1);
    if (R(17) & 1u) {
        R(0) = R(11);
        condition(s, R(0) == 1);
        R(14) = 5;
        R(13) = R(6);
        R(12) = R(7);
        if (R(17) & 1u) {
            R(0) = 0x34a;
            R(14) = 39;
            R(13) = byte(R(4) + R(0));
            ++R(0);
            R(12) = byte(R(4) + R(0));
        }
    } else {
        R(0) = R(11);
        condition(s, R(0) == 1);
        R(14) = (R(17) & 1u) ? 39 : 5;
        R(13) = R(6);
        R(12) = R(7);
    }
    R(3) = 0x1700;
    R(4) = R(14) * 2 | R(3);
    R(11) = R(5);
    continuation = second ? 0x0c06cef2 : 0x0c06c57a;
    R(16) = continuation;
    if (!vf3_matrix_family(0x0c06c360, s, ram) || s->pc != continuation) return 0;
    condition(s, R(0) == 0);
    if (!(R(17) & 1u)) {
        R(6) = R(13);
        R(5) = 46;
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(11), 4);
        R(7) = R(12);
        R(4) = R(14);
        continuation = second ? 0x0c06cf02 : 0x0c06c58a;
        R(16) = continuation;
        if (!vf3_matrix_family(0x0c06cae6, s, ram) || s->pc != continuation) return 0;
        R(15) += 4;
    }
    R(15) += 4;
    R(16) = pop(s, ram);
    for (unsigned reg = 11; reg <= 14; ++reg) R(reg) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
