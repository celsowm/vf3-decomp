/* text_cursor.c - 0x8C0C1754  walk a string, tracking a text cursor and drawing each printable character.
 *
 *   r4 = text object (halfword at +0x20 passed to the glyph routine, halfword at +0x24 receives r7),
 *   r5 = packed cursor: column in bits 1-6, row in bits 7-12; r6 = string, r7 = control-character flag.
 *   Returns the packed cursor in r0 (column << 1 | row << 7).
 *
 *   With the flag set, backspace (8) returns to the starting column, tab (9) rounds the column up to the next
 *   multiple of 8, and newline / carriage return / backslash (10, 13, 92) step the row and return to the
 *   starting column. Every other character is drawn by 0x8C0C13C4 (r4 = object, r5 = packed cursor, r6 = the
 *   character, r7 = the halfword), which hands back the new cursor.
 *
 *   Frame: eight saved registers (r14..r8, pr), nothing else. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 32, COLUMN_MASK = 63 };

static uint32_t pack_cursor(uint32_t col, uint32_t row)
{
    return ((uint32_t)(int32_t)(int16_t)col << 1) | (uint32_t)((int32_t)(int16_t)row * 128);
}

int vf3_text_cursor_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    const uint32_t saved_r[8] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8), pr0 };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
    const uint32_t obj = R(4), flag = R(7);

    for (int i = 0; i < 8; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    R(15) = sp0 - SAVED;

    uint32_t col = (R(5) >> 1) & COLUMN_MASK, row = (R(5) >> 7) & COLUMN_MASK;
    const uint32_t home = col;
    uint32_t str = R(6);
    vf3_mem_set_u16(ram, obj + 0x24, (uint16_t)flag);
    R(9) = flag; R(11) = obj; R(8) = home;
    R(3) = 0xFFFFFFF9u;

    uint32_t ch;
    while ((ch = vf3_mem_u8(ram, str)) != 0) {
        R(2) = (uint32_t)(int32_t)(int8_t)ch;
        R(12) = str + 1;
        str += 1;
        R(10) = ch;
        if (flag) {
            if (ch == 8) { col = home; continue; }
            if (ch == 9) { col = (col & ~7u) + 8; continue; }
            if (ch == 10 || ch == 13 || ch == 92) { row += 1; col = home; continue; }
        }
        {
            const uint32_t half = vf3_mem_u16(ram, obj + 0x20);
            R(0) = 32; R(3) = 7;
            R(13) = (uint32_t)((int32_t)(int16_t)row << 7);             /* the row, already shifted into place */
            R(14) = col;
            R(4) = obj; R(5) = pack_cursor(col, row);
            R(6) = ch; R(7) = half;
            if (!vf3_guest_call(s, ram, 0x8C0C13C4u, 0x8C0C17F8u)) return 0;
            R(15) = sp0 - SAVED;
            R(5) = R(0) >> 7;
            row = R(5) & COLUMN_MASK;
            col = (R(0) >> 1) & COLUMN_MASK;
            R(13) = row; R(14) = col;
        }
    }
    R(2) = 0;
    R(3) = 7;
    R(5) = pack_cursor(col, row);
    R(0) = R(5);
    R(VF3_REG_SR) |= 1u;                                    /* the last tst r2,r2 found the terminator */
    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;                                    /* the guest calls leave their return address in pr */
    s->pc = pr0;
    return 1;
}
