/* format_int.c - SH-4 0x8C04AF04: the integer conversion of the engine's
 * printf, natively.  A plain-C transcription of the readable port
 * vf3_format_int_entry (src/fight/format_int.c) onto `vf3_native_aim`.  It is
 * an integer leaf whose only callees are the two natively-ported unsigned
 * division helpers (mod_u32 0x8C042E44, div_u32 0x8C042CD4), so the guest
 * calls become direct native calls into div_helpers.c.
 *
 *   r4 = value, r5 = output cursor, r6 = conversion character (d i u o x X),
 *   r7 = the conversion spec:
 *        { u8 flags @0 (0x04 '#', 0x08 '+', 0x10 ' '), u8 pad char @1,
 *          width @4, precision @8, text start @20, zero pad count @32,
 *          space pad count @40 }
 *   -> the spec's start/pad fields filled and the number's characters (sign,
 *      "0x" prefix, digits) written at the output cursor, NUL terminated.
 *
 * The digits are produced least significant first into a 16 byte scratch on
 * the stack with mod_u32 (r0 = base, r1 = value) and div_u32, then copied out
 * in reverse.  The sign/prefix is written first, so the first character at
 * the original cursor tells the pad logic whether a sign was emitted.
 *
 * The register contract the observable mask carries (B(5), B(8..15), B(16),
 * B(17)) is reproduced exactly: r5 = the end of the output, r8..r14 restored
 * from the stack, r15 = sp0, pr restored, SR's T bit cleared.  The dead stack
 * words (the saved registers, pr, the frame words) are written so the RAM
 * compare has teeth.  See docs/re/native_format_int.md. */
#include "format_int.h"

#include "aim_math.h"
#include "div_helpers.h"

enum {
    REM_LITERAL = 0x0C042E44u, QUO_LITERAL = 0x0C042CD4u,
    SAVED_BYTES = 32, FRAME_BYTES = 16, DIGITS = 4,
    SPEC_FLAGS = 0, SPEC_PAD = 1, SPEC_WIDTH = 4, SPEC_PRECISION = 8,
    SPEC_START = 20, SPEC_ZEROS = 32, SPEC_SPACES = 40,
    FLAG_ALT = 0x04, FLAG_PLUS = 0x08, FLAG_SPACE = 0x10
};

static int is_sign(int c)
{
    return c == '+' || c == '-' || c == ' ';
}

void vf3_native_format_int(vf3_native_aim *a)
{
    const uint32_t sp0 = a->r[15], pr0 = a->pr;
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const int32_t value = (int32_t)a->r[4];
    const uint32_t spec = a->r[7], conv = a->r[6], start = a->r[5];
    const uint32_t saved[7] = { a->r[14], a->r[13], a->r[12], a->r[11],
                                a->r[10], a->r[9], a->r[8] };
    const uint32_t digits = frame + DIGITS;
    uint32_t out = start;

    for (int i = 0; i < 7; ++i)
        vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_aim_set_u32(a, sp0 - 32u, pr0);
    vf3_aim_set_u8(a, start, 0);

    uint32_t base = saved[5];   /* r9 keeps the caller's value for an unknown conversion */
    switch (conv) {
    case 'X': case 'x': base = 16; break;
    case 'd': case 'i': case 'u': base = 10; break;
    case 'o': base = 8; break;
    default: break;
    }
    const int is_signed = conv == 'd' || conv == 'i';
    uint32_t mag = (is_signed && value < 0) ? 0u - (uint32_t)value : (uint32_t)value;

    uint32_t count = 0, prefix = 0;
    const uint32_t precision = vf3_aim_u32(a, spec + SPEC_PRECISION);
    a->r[15] = frame;

    if (mag == 0 && precision != 0) {
        vf3_aim_set_u8(a, digits, '0');
        count = 1;
    } else if (mag != 0) {
        do {
            const uint32_t slot = digits + count;
            a->r[0] = base; a->r[1] = mag; a->r[2] = slot; a->r[3] = REM_LITERAL;
            a->r[8] = 0; a->r[9] = base; a->r[10] = start; a->r[11] = 0;
            a->r[12] = mag; a->r[13] = count; a->r[14] = digits;
            vf3_aim_set_u32(a, frame, slot);
            vf3_native_mod_u32(a);
            uint8_t digit = (uint8_t)a->r[0];
            vf3_aim_set_u8(a, slot, digit);
            uint32_t left = digit;                    /* r2: the digit as the quotient call sees it */
            if ((int8_t)digit > 9) {
                vf3_aim_set_u32(a, frame, slot);
                digit = (uint8_t)(digit + (conv == 'x' ? 87 : 55));
                if (conv != 'x') left = digit;
            } else {
                digit = (uint8_t)(digit + 48);
                left = digit;
            }
            vf3_aim_set_u8(a, slot, digit);
            a->r[2] = left;
            a->r[0] = base; a->r[1] = mag; a->r[3] = QUO_LITERAL;
            vf3_native_div_u32(a);
            mag = a->r[0];
            ++count;
        } while (mag != 0);
    }

    const uint32_t flags = vf3_aim_u8(a, spec + SPEC_FLAGS);
    if ((flags & FLAG_ALT) != 0) {
        if (conv == 'o') {
            if (value != 0) vf3_aim_set_u8(a, digits + count++, '0');
        } else if ((conv == 'X' || conv == 'x') && value != 0) {
            vf3_aim_set_u8(a, out++, '0');
            vf3_aim_set_u8(a, out++, (uint8_t)conv);
            prefix = 2;
        }
    }
    vf3_aim_set_u32(a, frame, count);
    uint32_t used = prefix + count;       /* characters before the zero padding */

    if (is_signed && (vf3_aim_u32(a, spec + SPEC_PRECISION) != 0 || value != 0)) {
        if (value < 0) {
            ++used; vf3_aim_set_u8(a, out++, '-');
        } else if ((flags & FLAG_PLUS) != 0) {
            ++used; vf3_aim_set_u8(a, out++, '+');
        } else if ((flags & FLAG_SPACE) != 0) {
            ++used; vf3_aim_set_u8(a, out++, ' ');
        }
    }

    const int first = (int8_t)vf3_aim_u8(a, start);
    if (is_sign(first))                                  vf3_aim_set_u32(a, spec + SPEC_START, start + 1);
    else if ((flags & FLAG_ALT) == 0)                    vf3_aim_set_u32(a, spec + SPEC_START, start);
    else if (conv == 'X' || conv == 'x')                 vf3_aim_set_u32(a, spec + SPEC_START, start + 2);
    else if (conv == 'o')                                vf3_aim_set_u32(a, spec + SPEC_START, start + 1);

    uint32_t total = used;
    if (precision > used) {
        total = precision;
        vf3_aim_set_u32(a, spec + SPEC_ZEROS, precision - used);
    } else {
        vf3_aim_set_u32(a, spec + SPEC_ZEROS, 0);
    }

    const int sign_now = (int8_t)vf3_aim_u8(a, start);
    const uint32_t width = vf3_aim_u32(a, spec + SPEC_WIDTH);
    if (is_sign(sign_now) && width > total && (int8_t)vf3_aim_u8(a, spec + SPEC_PAD) == '0') {
        vf3_aim_set_u32(a, spec + SPEC_ZEROS, vf3_aim_u32(a, spec + SPEC_ZEROS) + (width - total));
        vf3_aim_set_u32(a, spec + SPEC_SPACES, 0);
    } else if (width > total) {
        vf3_aim_set_u32(a, spec + SPEC_SPACES, width - total);
    } else {
        vf3_aim_set_u32(a, spec + SPEC_SPACES, 0);
    }

    for (int32_t i = (int32_t)count - 1; i >= 0; --i)
        vf3_aim_set_u8(a, out++, vf3_aim_u8(a, digits + (uint32_t)i));
    vf3_aim_set_u8(a, out, 0);

    a->r[5] = out;
    a->sr &= ~1u;                 /* the copy loop ends on a failed cmp/pz */
    a->r[15] = sp0;
    for (int i = 0; i < 7; ++i) a->r[14 - i] = saved[i];
    a->pr = pr0;
}
