/* mem_fill.c - 0x8C095604  fill memory with a value: whole words first, then the odd bytes.
 *
 *   r4 = destination, r5 = value, r6 = byte count   ->   r0 = end pointer
 *
 * The count is split with the engine's signed divide (r6 / 4 words, r6 & 3 tail bytes); the
 * words store r5 as a whole, the tail bytes store its low byte. */
#include "fight/readable.h"
#include "fight/readable_fp.h"

enum { DIV_S32 = 0x8C042C20, DIV_S32_LITERAL = 0x0C042C20, RET_AFTER_DIV = 0x8C095610, SR_T = 1u };

int vf3_mem_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t entry_sp = s->v[15], entry_pr = s->v[VF3_REG_PR], saved_r14 = s->v[14];
    const uint32_t value = s->v[5], length = s->v[6];

    vf3_mem_set_u32(ram, entry_sp - 4u, saved_r14);
    vf3_mem_set_u32(ram, entry_sp - 8u, entry_pr);
    s->v[15] = entry_sp - 8u;
    s->v[0] = 4;
    s->v[1] = length;
    s->v[3] = DIV_S32_LITERAL;
    if (!vf3_guest_call(s, ram, DIV_S32, RET_AFTER_DIV)) return 0;
    s->v[15] = entry_sp;

    const int32_t words = (int32_t)s->v[0];
    uint32_t dest = s->v[4], done = 0;
    for (int32_t i = 0; i < words; ++i) {
        vf3_mem_set_u32(ram, dest, value);
        dest += 4;
        ++done;
    }
    s->v[4] = done;
    s->v[7] = dest;

    const uint32_t tail = length & 3u;
    uint32_t end = dest;
    if (tail != 0) {
        for (uint32_t i = 0; i < tail; ++i) vf3_mem_set_u8(ram, end++, (uint8_t)value);
        s->v[4] = tail;
        s->v[6] = end;
    }
    s->v[0] = end;
    s->v[14] = saved_r14;
    s->v[VF3_REG_SR] |= SR_T;
    s->v[VF3_REG_PR] = entry_pr;
    s->pc = entry_pr;
    return 1;
}
