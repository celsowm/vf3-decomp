/* format_int.c - 0x8C04AF04  the integer conversion of the engine's printf: renders one number.
 *
 *   r4 = value, r5 = output cursor, r6 = conversion character (d i u o x X), r7 = the conversion
 *   spec { u8 flags @0 (0x04 alternate form '#', 0x08 '+', 0x10 ' '), u8 pad char @1, width @4,
 *          precision @8, -> text start @20, zero pad count @32, space pad count @40 }
 *   -> the spec's start/pad fields filled and the number's characters (sign, "0x" prefix,
 *      digits) written at the output cursor, NUL terminated.
 *
 * The digits are produced least significant first into a 16 byte scratch on the stack with the
 * engine's unsigned remainder (0x8C042E44) and quotient (0x8C042CD4) helpers (r0 = base,
 * r1 = value), then copied out in reverse. The sign/prefix is written first, so the first
 * character at the original cursor tells the pad logic whether a sign was emitted. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    REM_HELPER = 0x8C042E44, REM_LITERAL = 0x0C042E44, RET_AFTER_REM = 0x8C04AFA4,
    QUO_HELPER = 0x8C042CD4, QUO_LITERAL = 0x0C042CD4, RET_AFTER_QUO = 0x8C04AFE6,
    SAVED_BYTES = 32, FRAME_BYTES = 16, DIGITS = 4,
    SPEC_FLAGS = 0, SPEC_PAD = 1, SPEC_WIDTH = 4, SPEC_PRECISION = 8, SPEC_START = 20,
    SPEC_ZEROS = 32, SPEC_SPACES = 40,
    FLAG_ALT = 0x04, FLAG_PLUS = 0x08, FLAG_SPACE = 0x10
};

static int is_sign(int c) { return c == '+' || c == '-' || c == ' '; }

int vf3_format_int_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR];
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const int32_t value = (int32_t)s->v[4];
    const uint32_t spec = s->v[7], conv = s->v[6], start = s->v[5];
    const uint32_t saved[7] = { s->v[14], s->v[13], s->v[12], s->v[11], s->v[10], s->v[9], s->v[8] };
    const uint32_t digits = frame + DIGITS;
    uint32_t out = start;

    for (int i = 0; i < 7; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_mem_set_u32(ram, sp0 - 32u, pr0);
    vf3_mem_set_u8(ram, start, 0);

    uint32_t base = saved[5];         /* r9 keeps the caller's value for an unknown conversion */
    switch (conv) {
    case 'X': case 'x': base = 16; break;
    case 'd': case 'i': case 'u': base = 10; break;
    case 'o': base = 8; break;
    default: break;
    }
    const int is_signed = conv == 'd' || conv == 'i';
    uint32_t mag = (is_signed && value < 0) ? 0u - (uint32_t)value : (uint32_t)value;

    uint32_t count = 0, prefix = 0;
    const uint32_t precision = vf3_mem_u32(ram, spec + SPEC_PRECISION);
    s->v[15] = frame;

    if (mag == 0 && precision != 0) {
        vf3_mem_set_u8(ram, digits, '0');
        count = 1;
    } else if (mag != 0) {
        do {
            const uint32_t slot = digits + count;
            s->v[0] = base; s->v[1] = mag; s->v[2] = slot; s->v[3] = REM_LITERAL;
            s->v[8] = 0; s->v[9] = base; s->v[10] = start; s->v[11] = 0;
            s->v[12] = mag; s->v[13] = count; s->v[14] = digits;
            vf3_mem_set_u32(ram, frame, slot);
            if (!vf3_guest_call(s, ram, REM_HELPER, RET_AFTER_REM)) return 0;
            uint8_t digit = (uint8_t)s->v[0];
            vf3_mem_set_u8(ram, slot, digit);
            uint32_t left = digit;                     /* r2: the digit as the quotient call sees it */
            if ((int8_t)digit > 9) {
                vf3_mem_set_u32(ram, frame, slot);
                digit = (uint8_t)(digit + (conv == 'x' ? 87 : 55));
                if (conv != 'x') left = digit;
            } else {
                digit = (uint8_t)(digit + 48);
                left = digit;
            }
            vf3_mem_set_u8(ram, slot, digit);
            s->v[2] = left;
            s->v[0] = base; s->v[1] = mag; s->v[3] = QUO_LITERAL;
            if (!vf3_guest_call(s, ram, QUO_HELPER, RET_AFTER_QUO)) return 0;
            mag = s->v[0];
            ++count;
        } while (mag != 0);
    }

    const uint32_t flags = vf3_mem_u8(ram, spec + SPEC_FLAGS);
    if ((flags & FLAG_ALT) != 0) {
        if (conv == 'o') {
            if (value != 0) vf3_mem_set_u8(ram, digits + count++, '0');
        } else if ((conv == 'X' || conv == 'x') && value != 0) {
            vf3_mem_set_u8(ram, out++, '0');
            vf3_mem_set_u8(ram, out++, (uint8_t)conv);
            prefix = 2;
        }
    }
    vf3_mem_set_u32(ram, frame, count);
    uint32_t used = prefix + count;       /* characters before the zero padding */

    if (is_signed && (vf3_mem_u32(ram, spec + SPEC_PRECISION) != 0 || value != 0)) {
        if (value < 0) {
            ++used; vf3_mem_set_u8(ram, out++, '-');
        } else if ((flags & FLAG_PLUS) != 0) {
            ++used; vf3_mem_set_u8(ram, out++, '+');
        } else if ((flags & FLAG_SPACE) != 0) {
            ++used; vf3_mem_set_u8(ram, out++, ' ');
        }
    }

    const int first = (int8_t)vf3_mem_u8(ram, start);
    if (is_sign(first))                                  vf3_mem_set_u32(ram, spec + SPEC_START, start + 1);
    else if ((flags & FLAG_ALT) == 0)                    vf3_mem_set_u32(ram, spec + SPEC_START, start);
    else if (conv == 'X' || conv == 'x')                 vf3_mem_set_u32(ram, spec + SPEC_START, start + 2);
    else if (conv == 'o')                                vf3_mem_set_u32(ram, spec + SPEC_START, start + 1);

    uint32_t total = used;
    if (precision > used) {
        total = precision;
        vf3_mem_set_u32(ram, spec + SPEC_ZEROS, precision - used);
    } else {
        vf3_mem_set_u32(ram, spec + SPEC_ZEROS, 0);
    }

    const int sign_now = (int8_t)vf3_mem_u8(ram, start);
    const uint32_t width = vf3_mem_u32(ram, spec + SPEC_WIDTH);
    if (is_sign(sign_now) && width > total && (int8_t)vf3_mem_u8(ram, spec + SPEC_PAD) == '0') {
        vf3_mem_set_u32(ram, spec + SPEC_ZEROS, vf3_mem_u32(ram, spec + SPEC_ZEROS) + (width - total));
        vf3_mem_set_u32(ram, spec + SPEC_SPACES, 0);
    } else if (width > total) {
        vf3_mem_set_u32(ram, spec + SPEC_SPACES, width - total);
    } else {
        vf3_mem_set_u32(ram, spec + SPEC_SPACES, 0);
    }

    for (int32_t i = (int32_t)count - 1; i >= 0; --i)
        vf3_mem_set_u8(ram, out++, vf3_mem_u8(ram, digits + (uint32_t)i));
    vf3_mem_set_u8(ram, out, 0);

    s->v[5] = out;
    s->v[VF3_REG_SR] &= ~1u;          /* the copy loop ends on a failed cmp/pz */
    s->v[15] = sp0;
    for (int i = 0; i < 7; ++i) s->v[14 - i] = saved[i];
    s->v[VF3_REG_PR] = pr0;
    s->pc = pr0;
    return 1;
}
