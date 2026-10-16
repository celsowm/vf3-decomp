/* printf_core.c - 0x8C04A6C8  the engine's vfprintf-style formatter.
 *
 *   r4 = destination object, r5 = size limit, r6 = stream handle, r7 = format string,
 *   the fifth argument (first stack word) is the argument cursor (a pointer into the caller's
 *   stack-passed arguments; every value occupies 4 bytes, doubles 8, floats are passed as singles).
 *   Returns r0 = characters produced (the count at state+8), or -1 on a bad destination.
 *
 * Conversion state (a 44 byte record on the stack):
 *     +0 flags    0x01 error  0x02 '-'  0x04 '#'  0x08 '+'  0x10 ' '
 *     +1 pad char (' ' or '0')     +4 width     +8 precision (-1 none)     +12 size h/l/L/' '
 *     +16 start of prefix/sign text   +20 start of digits   +28 zeros before the prefix
 *     +32 zeros between prefix and digits   +36 zeros after   +40 trailing/leading pad spaces
 * The produced text is written to a 148 byte scratch buffer and handed to the output helper
 * (0x8C04B952: pointer, count, output state) piecewise; integers go through format_int
 * (0x8C04AF04), strings/characters/%% are laid out here, floats through the float formatter
 * (0x8C04B178, after widening the single to a double with 0x8C05339C).
 *
 * The output state record is { dest, stream, count @8, limit @12 }; the helper at 0x8C04B9BE
 * answers non-zero when the stream has gone bad and 0x8C04B9AC flushes it. A bad conversion,
 * or a width/precision over 512, sets the error flag and stores an error code at 0x0C1A5A60. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

#define R(n) (s->v[(n)])

enum {
    SAVED_BYTES = 32, FRAME_BYTES = 216,
    OFF_SPEC = 0x9C, OFF_STATE = 0xC8, OFF_DOUBLE = 0x94, OFF_ARGS = 0xF8, SCRATCH = 20,
    CLASS_TABLE = 0x8C0D2420, ERRNO_CELL = 0x8C1A5A60,
    IS_DIGIT = 4, LIMIT = 0x200,
    E_NO_STREAM = 0x452, E_BAD_MODE = 0x514, E_NOT_WRITABLE = 0x516, E_RANGE = 0x518,
    DIV_S32 = 0x8C042C20, OUT = 0x8C04B952, FORMAT_INT = 0x8C04AF04, FLOAT_FMT = 0x8C04B178, WIDEN = 0x8C05339C,
    STREAM_BAD = 0x8C04B9BE, FLUSH = 0x8C04B9AC, STRLEN = 0x8C05342C, BEGIN = 0x8C04B9BE,
    F_ERROR = 1, F_LEFT = 2, F_ALT = 4, F_PLUS = 8, F_SPACE = 16,
    S_FLAGS = 0, S_PAD = 1, S_WIDTH = 4, S_PREC = 8, S_SIZE = 12, S_PREFIX = 16, S_DIGITS = 20,
    S_Z0 = 28, S_Z1 = 32, S_Z2 = 36, S_PAD_N = 40
};

typedef struct {
    vf3_matrix_state *s;
    const vf3_ram_map *ram;
    uint32_t frame, spec, state, scratch;
    uint32_t cursor;      /* r13: the argument cursor */
    uint32_t fmt;         /* r11: the format cursor */
} pf;

static uint32_t m32(pf *p, uint32_t a) { return vf3_mem_u32(p->ram, a); }
static void set32(pf *p, uint32_t a, uint32_t v) { vf3_mem_set_u32(p->ram, a, v); }
static uint32_t m8(pf *p, uint32_t a) { return vf3_mem_u8(p->ram, a); }
static int32_t s8(pf *p, uint32_t a) { return (int8_t)vf3_mem_u8(p->ram, a); }
static void fail(pf *p, uint32_t code) { set32(p, ERRNO_CELL, code); }

static void sync(pf *p)
{
    vf3_matrix_state *s = p->s;
    R(8) = p->scratch; R(9) = p->state; R(10) = 0; R(11) = p->fmt; R(12) = 3; R(13) = p->cursor; R(14) = p->spec;
    R(15) = p->frame;
}

static int call(pf *p, uint32_t target, uint32_t ret)
{
    sync(p);
    if (!vf3_guest_call(p->s, p->ram, target, ret)) return 0;
    p->s->v[15] = p->frame;
    return 1;
}

/* out(ptr, count) through the output helper */
static int out(pf *p, uint32_t ptr, uint32_t count, uint32_t ret)
{
    p->s->v[4] = ptr; p->s->v[5] = count; p->s->v[6] = p->state;
    return call(p, OUT, ret);
}

/* the 4-byte argument fetch with the original's alignment dance */
static uint32_t va_word(pf *p)
{
    const uint32_t n = p->cursor + 4;
    if ((n & 3) == 0) p->cursor = n; else p->cursor += 8;
    uint32_t at = p->cursor - 4;
    if ((at & 3) != 0) at = p->cursor - 8;
    return m32(p, at);
}

static int is_digit(pf *p, uint32_t c) { return (m8(p, CLASS_TABLE + (c & 0xFF)) & IS_DIGIT) != 0; }

/* decimal field (width or precision) with the 512 cap; returns the new value */
static int read_number(pf *p, uint32_t at)
{
    vf3_matrix_state *s = p->s;
    uint32_t v = 0;
    while (is_digit(p, m8(p, p->fmt))) {
        const int32_t d = s8(p, p->fmt) - 48;
        s->v[0] = 10; s->v[1] = (uint32_t)(LIMIT - d); s->v[3] = 0x0C042C20u; s->v[4] = (uint32_t)d;
        if (!call(p, DIV_S32, 0x8C04A8A2)) return 0;
        const int32_t limit = (int32_t)s->v[0];
        p->fmt++;
        if (limit >= (int32_t)v) {
            v = v * 10u + (uint32_t)d;
        } else {
            vf3_mem_set_u8(p->ram, p->spec + S_FLAGS, (uint8_t)(m8(p, p->spec + S_FLAGS) | F_ERROR));
            fail(p, E_RANGE);
        }
        set32(p, at, v);
    }
    return 1;
}

static void flag_error(pf *p)
{
    vf3_mem_set_u8(p->ram, p->spec + S_FLAGS, (uint8_t)(m8(p, p->spec + S_FLAGS) | F_ERROR));
    fail(p, E_RANGE);
}

int vf3_printf_core_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    pf p = { s, ram, frame, frame + OFF_SPEC, frame + OFF_STATE, frame + SCRATCH, 0, R(7) };
    uint32_t result;

    for (int i = 0; i < 7; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_mem_set_u32(ram, sp0 - 32u, pr0);
    R(15) = frame;
    p.cursor = vf3_mem_u32(ram, frame + OFF_ARGS);
    const uint32_t dest = R(4), limit = R(5), stream = R(6);

    set32(&p, p.state, 0); set32(&p, p.state + 4, 0); set32(&p, p.state + 8, 0);
    for (uint32_t off = 0; off <= 40; off += 4) if (off != S_SIZE) set32(&p, p.spec + off, 0);
    vf3_mem_set_u8(ram, p.spec + S_PAD, 0);
    vf3_mem_set_u8(ram, p.spec + S_FLAGS, 0);

    int bad = 0;
    if (dest == 0) {
        if (stream == 0) { fail(&p, E_NO_STREAM); bad = 1; }
        else if ((vf3_mem_u8(ram, stream + 16) & 7) == 0) { fail(&p, E_BAD_MODE); bad = 1; }
        else {
            const uint32_t mode = vf3_mem_u8(ram, stream + 16);
            if ((mode & 4) == 0 && (mode & 1) != 0) { fail(&p, E_NOT_WRITABLE); bad = 1; }
            else set32(&p, p.state + 12, limit);
        }
    }
    if (bad) { result = (uint32_t)-1; goto done; }

    set32(&p, p.state, dest);
    set32(&p, p.state + 4, stream);
    set32(&p, p.state + 8, 0);
    vf3_mem_set_u8(ram, p.spec + S_FLAGS, 0);
    vf3_mem_set_u8(ram, frame + 8, '0');
    R(4) = p.state; R(3) = 0x0C04B9BEu; R(0) = 48;
    if (!call(&p, BEGIN, 0x8C04A762)) return 0;
    if (R(0) != 0) { result = (uint32_t)-1; goto done; }
    set32(&p, frame + 16, p.scratch);

    for (;;) {
        if (s8(&p, p.fmt) == 0) break;
        R(4) = p.state;
        if (!call(&p, STREAM_BAD, 0x8C04AED4)) return 0;
        if (R(0) != 0 || (m8(&p, p.spec + S_FLAGS) & F_ERROR)) break;

        if (m8(&p, p.fmt) != '%') {                               /* a literal run */
            uint32_t end = p.fmt;
            set32(&p, frame, end);
            while (s8(&p, end) != 0 && s8(&p, end) != '%') { ++end; set32(&p, frame, end); }
            if (!out(&p, p.fmt, end - p.fmt, 0x8C04AEC6)) return 0;
            p.fmt = end;
            continue;
        }

        /* --- a conversion: flags -------------------------------------------------------- */
        vf3_mem_set_u8(ram, p.spec + S_FLAGS, 0);
        p.fmt++;
        set32(&p, p.spec + S_PREFIX, p.scratch);
        set32(&p, p.spec + S_DIGITS, p.scratch);
        for (uint32_t off = 24; off <= 40; off += 4) set32(&p, p.spec + off, 0);
        for (;;) {
            const int c = s8(&p, p.fmt);
            uint32_t f = m8(&p, p.spec + S_FLAGS);
            if (c == '-') f |= F_LEFT;
            else if (c == '+') f |= F_PLUS;
            else if (c == '#') f |= F_ALT;
            else if (c == ' ') { if (!(f & F_PLUS)) f |= F_SPACE; }
            else break;
            vf3_mem_set_u8(ram, p.spec + S_FLAGS, (uint8_t)f);
            p.fmt++;
        }
        /* --- width ---------------------------------------------------------------------- */
        vf3_mem_set_u8(ram, p.spec + S_PAD, ' ');
        if (s8(&p, p.fmt) == '0') { vf3_mem_set_u8(ram, p.spec + S_PAD, '0'); p.fmt++; }
        set32(&p, p.spec + S_WIDTH, 0);
        if (s8(&p, p.fmt) == '*') {
            const int32_t v = (int32_t)va_word(&p);
            set32(&p, p.spec + S_WIDTH, (uint32_t)v);
            if (v < 0) {
                vf3_mem_set_u8(ram, p.spec + S_FLAGS, (uint8_t)(m8(&p, p.spec + S_FLAGS) | F_LEFT));
                set32(&p, p.spec + S_WIDTH, (uint32_t)-v);
            }
            p.fmt++;
            if ((int32_t)m32(&p, p.spec + S_WIDTH) > LIMIT) flag_error(&p);
        }
        if (is_digit(&p, m8(&p, p.fmt))) {
            set32(&p, p.spec + S_WIDTH, 0);
            if (!read_number(&p, p.spec + S_WIDTH)) return 0;
        }
        /* --- precision ------------------------------------------------------------------ */
        set32(&p, p.spec + S_PREC, (uint32_t)-1);
        if (s8(&p, p.fmt) == '.') {
            p.fmt++;
            if (s8(&p, p.fmt) == '*') {
                const int32_t v = (int32_t)va_word(&p);
                set32(&p, p.spec + S_PREC, (uint32_t)(v < 0 ? -1 : v));
                p.fmt++;
                if ((int32_t)m32(&p, p.spec + S_PREC) > LIMIT) flag_error(&p);
            }
            if (is_digit(&p, m8(&p, p.fmt))) {
                set32(&p, p.spec + S_PREC, 0);
                if (!read_number(&p, p.spec + S_PREC)) return 0;
            }
        }
        /* --- size ----------------------------------------------------------------------- */
        set32(&p, p.spec + S_SIZE, ' ');
        {
            const int c = s8(&p, p.fmt);
            if (c == 'h' || c == 'l' || c == 'L') { set32(&p, p.spec + S_SIZE, (uint32_t)c); p.fmt++; }
        }

        /* --- conversion ----------------------------------------------------------------- */
        const int conv = s8(&p, p.fmt);
        const uint32_t size = m32(&p, p.spec + S_SIZE);
        uint32_t text_len = 0;
        int have_text = 1;
        switch (conv) {
        case '%':
            vf3_mem_set_u8(ram, p.scratch, '%');
            goto one_char;
        case 'c':
            vf3_mem_set_u8(ram, p.scratch, (uint8_t)va_word(&p));
        one_char:
            set32(&p, frame + 4, p.scratch);
            text_len = 1;
            set32(&p, p.spec + S_DIGITS, p.scratch);
            set32(&p, p.spec + S_Z1, 0);
            set32(&p, p.spec + S_PAD_N, m32(&p, p.spec + S_WIDTH) - 1);
            break;
        case 's': {
            const uint32_t str = va_word(&p);
            set32(&p, frame + 4, str);
            R(4) = str;
            if (!call(&p, STRLEN, 0x8C04ACAA)) return 0;
            text_len = R(0);
            const int32_t prec = (int32_t)m32(&p, p.spec + S_PREC);
            if (prec != -1 && prec < (int32_t)text_len) text_len = (uint32_t)prec;
            set32(&p, p.spec + S_DIGITS, p.scratch);
            set32(&p, p.spec + S_Z1, 0);
            set32(&p, p.spec + S_PAD_N, m32(&p, p.spec + S_WIDTH) - text_len);
            break;
        }
        case 'n': {
            const uint32_t dst = va_word(&p);
            set32(&p, dst, m32(&p, p.state + 8));
            have_text = 0;
            break;
        }
        case 'p': {
            const uint32_t v = va_word(&p);
            if ((int32_t)m32(&p, p.spec + S_PREC) == -1) set32(&p, p.spec + S_PREC, 1);
            R(4) = v; R(5) = p.scratch; R(6) = 'x'; R(7) = p.spec;
            if (!call(&p, FORMAT_INT, 0x8C04AD16)) return 0;
            set32(&p, frame + 4, p.scratch);
            R(4) = p.scratch;
            if (!call(&p, STRLEN, 0x8C04AD1E)) return 0;
            text_len = R(0);
            break;
        }
        case 'E': case 'G': case 'e': case 'f': case 'g': {
            if (size == 'L') {
                const uint32_t n = p.cursor + 8;
                if ((n & 3) == 0) p.cursor = n; else p.cursor += 12;
                uint32_t at = p.cursor - 8;
                if ((at & 3) != 0) at = p.cursor - 12;
                set32(&p, frame + OFF_DOUBLE, m32(&p, at));
                set32(&p, frame + OFF_DOUBLE + 4, m32(&p, at + 4));
            } else {
                const uint32_t n = p.cursor + 4;
                if ((n & 3) == 0) p.cursor = n; else p.cursor += 8;
                uint32_t at = p.cursor - 4;
                if ((at & 3) != 0) at = p.cursor - 8;
                const uint32_t dst = frame + OFF_DOUBLE;
                set32(&p, frame - 4u, dst);
                VF3_FR(s, 0) = m32(&p, at);
                sync(&p);
                R(2) = dst;
                R(15) = frame - 4u;
                if (!vf3_guest_call(s, ram, WIDEN, 0x8C04AC1E)) return 0;
                R(15) = frame;
            }
            if ((int32_t)m32(&p, p.spec + S_PREC) == -1) set32(&p, p.spec + S_PREC, 6);
            set32(&p, frame - 4u, m32(&p, frame + OFF_DOUBLE + 4));
            set32(&p, frame - 8u, m32(&p, frame + OFF_DOUBLE));
            sync(&p);
            R(4) = p.scratch; R(5) = (uint32_t)conv; R(6) = p.spec;
            R(15) = frame - 8u;
            if (!vf3_guest_call(s, ram, FLOAT_FMT, 0x8C04AC3E)) return 0;
            R(15) = frame;
            set32(&p, frame + 4, p.scratch);
            R(4) = p.scratch;
            if (!call(&p, STRLEN, 0x8C04AC46)) return 0;
            text_len = R(0);
            break;
        }
        case 'X': case 'd': case 'i': case 'o': case 'u': case 'x': {
            uint32_t v;
            const int unsigned_conv = conv == 'u' || conv == 'X' || conv == 'x' || conv == 'o';
            v = va_word(&p);
            if (size == 'h' && !unsigned_conv) v = (uint32_t)(int32_t)(int16_t)v;
            if ((int32_t)m32(&p, p.spec + S_PREC) == -1) set32(&p, p.spec + S_PREC, 1);
            R(4) = v; R(5) = p.scratch; R(6) = (uint32_t)conv; R(7) = p.spec;
            if (!call(&p, FORMAT_INT, 0x8C04AB9A)) return 0;
            set32(&p, frame + 4, p.scratch);
            R(4) = p.scratch;
            if (!call(&p, STRLEN, 0x8C04ABA2)) return 0;
            text_len = R(0);
            break;
        }
        default:
            vf3_mem_set_u8(ram, p.spec + S_FLAGS, (uint8_t)(m8(&p, p.spec + S_FLAGS) | F_ERROR));
            fail(&p, E_RANGE);
            have_text = 0;
            break;
        }
        if (have_text) set32(&p, frame + 12, text_len);

        /* --- lay the pieces out --------------------------------------------------------- */
        if (conv != 'n' && !(m8(&p, p.spec + S_FLAGS) & F_ERROR)) {
            const uint32_t flags = m8(&p, p.spec + S_FLAGS);
            const uint32_t text = m32(&p, frame + 4), len = m32(&p, frame + 12);
            if (!(flags & F_LEFT))
                while ((int32_t)m32(&p, p.spec + S_PAD_N) > 0) {
                    if (!out(&p, p.spec + S_PAD, 1, 0x8C04ADAA)) return 0;
                    set32(&p, p.spec + S_PAD_N, m32(&p, p.spec + S_PAD_N) - 1);
                }
            if (m32(&p, p.spec + S_Z0) == 0 && m32(&p, p.spec + S_Z1) == 0 && m32(&p, p.spec + S_Z2) == 0) {
                if (!out(&p, text, len, 0x8C04ADD8)) return 0;
            } else {
                int32_t prefix = (int32_t)(m32(&p, p.spec + S_PREFIX) - text);
                set32(&p, frame, (uint32_t)prefix);
                if (prefix > 0 && !out(&p, text, (uint32_t)prefix, 0x8C04ADEE)) return 0;
                while ((int32_t)m32(&p, p.spec + S_Z0) > 0) {
                    if (!out(&p, frame + 8, 1, 0x8C04AE06)) return 0;
                    set32(&p, p.spec + S_Z0, m32(&p, p.spec + S_Z0) - 1);
                }
                int32_t mid = (int32_t)(m32(&p, p.spec + S_DIGITS) - m32(&p, p.spec + S_PREFIX));
                set32(&p, frame, (uint32_t)((int32_t)m32(&p, frame) + mid));
                if (mid > 0 && !out(&p, m32(&p, p.spec + S_PREFIX), (uint32_t)mid, 0x8C04AE2A)) return 0;
                while ((int32_t)m32(&p, p.spec + S_Z1) > 0) {
                    if (!out(&p, frame + 8, 1, 0x8C04AE38)) return 0;
                    set32(&p, p.spec + S_Z1, m32(&p, p.spec + S_Z1) - 1);
                }
                if (!out(&p, m32(&p, p.spec + S_DIGITS), m32(&p, frame + 12) - m32(&p, frame), 0x8C04AE52)) return 0;
                while ((int32_t)m32(&p, p.spec + S_Z2) > 0) {
                    if (!out(&p, frame + 8, 1, 0x8C04AE60)) return 0;
                    set32(&p, p.spec + S_Z2, m32(&p, p.spec + S_Z2) - 1);
                }
            }
            if (flags & F_LEFT)
                while ((int32_t)m32(&p, p.spec + S_PAD_N) > 0) {
                    if (!out(&p, p.spec + S_PAD, 1, 0x8C04AE8C)) return 0;
                    set32(&p, p.spec + S_PAD_N, m32(&p, p.spec + S_PAD_N) - 1);
                }
        }
        p.fmt++;                                                 /* past the conversion character */
    }

    R(4) = p.state;
    if (!call(&p, FLUSH, 0x8C04AEEA)) return 0;
    result = m32(&p, p.state + 8);

done:
    R(0) = result;
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved[i];
    }
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
