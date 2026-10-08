/* Install one of nine original task callbacks. The selector chooses both
 * the callback literal and its slot in the task; invalid selectors do nothing. */
#include "fight/matrix_family.h"

int vf3_task_callback_select(uint32_t entry, vf3_matrix_state *s,
                             const vf3_ram_map *ram)
{
    uint32_t selector = s->v[5];
    if ((entry & 0x1fffffffu) != 0x0c059400u) {
        s->failed_pc = entry;
        return 0;
    }
    if (!s->budget--) {
        s->failed_pc = entry;
        return 0;
    }

    s->v[0] = selector;
    s->v[17] = (s->v[17] & ~1u) | (selector <= 8);
    if (selector <= 8) {
        unsigned scratch = selector == 0 ? 3 : (selector & 1) ? 1 : 2;
        uint32_t literal = 0x0c059490u + selector * 4;
        uint32_t offset_literal = 0x0c059476u + selector * 2;
        s->v[scratch] = vf3_matrix_read(ram, literal, 4);
        s->v[0] = (uint32_t)(int32_t)(int16_t)
            vf3_matrix_read(ram, offset_literal, 2);
        vf3_matrix_write(ram, s->v[4] + s->v[0], s->v[scratch], 4);
    }
    s->pc = s->v[16];
    return ram->oob == 0;
}
