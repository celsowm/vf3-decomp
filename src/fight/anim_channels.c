/* anim_channels.c - 0x8C09D670  sample a 63-channel animation record at a time value.
 *
 *   r4 = animation object, r5 -> a cell holding the output float cursor, r6 = time (in 1/256 units)
 *   The record at obj+0x1D00 is { u8 *stream @0, u8 *key_counts @4, float *data @8, u8 type[63] @12 }.
 *   Each of the 63 channels yields one float written at the output cursor (which advances by 4):
 *
 *     type 0   0.0
 *     type 1   the next float of the data stream
 *     type 2   keyed, linear:  n keys (count from the stream, key times from the key_counts bytes);
 *              data is v[0..n] and the value is v[i] + (v[i+1]-v[i]) * (t-t0)/(t1-t0)
 *     type 3+  keyed, cubic Hermite: data is triples (value, tangent in, tangent out) per key
 *
 *   When the object's frame length (u16 @obj+0x1A00) exceeds 255 the original takes a second copy of
 *   the routine (0x8C09D838) written for 16-bit key times; that copy is never reached in the captured
 *   fights and is tail-called unchanged. The routine ends by calling 0x8C09D408 on the cell's target
 *   and storing the advanced cursor back into the cell.
 *
 * Register leftovers (r0/r1/r2/r7/r11/r13 and FR0-FR11) are reproduced per path because the
 * following call and the caller observe them. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    LEN_OFF = 0x1A00, REC_OFF = 0x1D00, CHANNELS = 63, WIDE_COPY = 0x8C09D838,
    FINISH = 0x8C09D408, RET_FINISH = 0x8C09D816,
    LIT_SCALE = 0x8C09D830, LIT_MINUS_ONE = 0x8C09D834,
    SAVED_BYTES = 28, FRAME_BYTES = 20
};

#define R(n) (s->v[(n)])
#define F(n) VF3_FR(s, (n))
#define SET_F(n, x) vf3_fr_set(s, (n), (x))
#define GET_F(n) vf3_fr_get(s, (n))

int vf3_anim_channels_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t t = R(6), obj = R(4);
    const uint32_t frame_len = vf3_mem_u16(ram, obj + LEN_OFF);

    R(0) = LEN_OFF; R(2) = 0xFF; R(3) = frame_len;
    if (frame_len > 0xFF) {
        R(VF3_REG_SR) |= 1u;
        return vf3_guest_call(s, ram, WIDE_COPY, pr0);
    }
    R(VF3_REG_SR) &= ~1u;

    const uint32_t saved[6] = { R(14), R(13), R(12), R(11), R(9), R(8) };
    for (int i = 0; i < 6; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_mem_set_u32(ram, sp0 - 28u, pr0);
    R(15) = frame;

    const uint32_t cell = R(5);
    vf3_mem_set_u32(ram, frame, cell);
    R(0) = REC_OFF;
    const uint32_t rec = vf3_mem_u32(ram, obj + REC_OFF);
    R(8) = rec;
    uint32_t stream = vf3_mem_u32(ram, rec);               /* frame+16 */
    vf3_mem_set_u32(ram, frame + 16, stream);
    R(14) = vf3_mem_u32(ram, rec + 8);                     /* data cursor */
    R(12) = vf3_mem_u32(ram, rec + 4);                     /* key counts cursor */
    R(3) = cell;
    uint32_t out = vf3_mem_u32(ram, cell);                 /* frame+4 */
    R(2) = out;
    vf3_mem_set_u32(ram, frame + 4, out);

    for (uint32_t ch = 0; ch < CHANNELS; ++ch) {
        R(9) = ch;
        R(5) = rec + 12u + ch;
        const uint32_t type_raw = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, rec + 12u + ch);
        const uint32_t type = type_raw & 0xFF;
        R(5) = type_raw; R(7) = type; R(0) = type;
        vf3_mem_set_u8(ram, frame + 8, (uint8_t)(type_raw + 0xFE));

        if (type == 1) {
            SET_F(4, vf3_mem_f32(ram, R(14)));
            R(14) += 4;
        } else if (type < 1) {
            R(5) = 1;
            F(4) = 0;
        } else {
            const uint32_t linear = (type_raw + 0xFEu) & 0xFF;   /* 0 for type 2 */
            const int is_linear = (int8_t)linear == 0;
            stream += 1;
            vf3_mem_set_u32(ram, frame + 16, stream);
            R(13) = 0;
            const uint32_t n = vf3_mem_u8(ram, stream);
            R(5) = n;
            uint32_t prev = 0x100;
            vf3_mem_set_u32(ram, frame + 12, prev);
            R(0) = LEN_OFF;
            R(7) = (uint32_t)vf3_mem_u16(ram, obj + LEN_OFF) << 8;

            int hit = 0;
            if (n != 0) {
                for (;;) {
                    R(7) = vf3_mem_u8(ram, R(13) + R(12));
                    if ((int32_t)n > (int32_t)R(13)) {
                        R(7) <<= 8;
                    } else {                                   /* ran out of keys: use the length */
                        R(7) = (uint32_t)vf3_mem_u16(ram, obj + LEN_OFF) << 8;
                        break;
                    }
                    if ((int32_t)R(7) > (int32_t)t) break;     /* key time past t */
                    if (R(7) == t) { hit = 1; break; }
                    R(13) += 1;
                    prev = R(7);
                    vf3_mem_set_u32(ram, frame + 12, prev);
                }
            }

            R(0) = (uint32_t)(int32_t)(int8_t)linear;
            if (hit) {
                R(12) += n;
                R(7) = R(13) + 1;
                if (!is_linear) {
                    R(13) = n; R(11) = R(7);
                    R(13) += n; R(5) = n + R(13);
                    R(11) <<= 1; R(5) += 2; R(7) += R(11);
                }
                R(7) = (R(7) << 2) + R(14);
                F(4) = vf3_mem_u32(ram, R(7));
                R(5) += 2;
                R(14) += R(5) << 2;
            } else {
                R(11) = R(7) - prev;                           /* key interval */
                R(1) = t - prev;                               /* time into it */
                if (is_linear) {
                    SET_F(3, vf3_f_from_int(s, (int32_t)R(11)));
                    R(7) = (R(13) << 2) + R(14);
                    SET_F(2, vf3_f_from_int(s, (int32_t)R(1)));
                    F(4) = vf3_mem_u32(ram, R(7));
                    R(7) += 4;
                    R(12) += n;
                    F(5) = vf3_mem_u32(ram, R(7));
                    SET_F(5, vf3_f_sub(s, GET_F(5), GET_F(4)));
                    F(6) = F(2);
                    SET_F(6, vf3_f_div(s, GET_F(6), GET_F(3)));
                    F(0) = F(5);
                    F(7) = F(2);
                    SET_F(4, vf3_f_mac(s, GET_F(0), GET_F(6), GET_F(4)));
                } else {
                    R(7) = R(13) * 3;
                    R(2) = R(13);
                    SET_F(3, vf3_f_from_int(s, (int32_t)R(1)));
                    R(7) = (R(7) << 2) + R(14);
                    SET_F(2, vf3_f_from_int(s, (int32_t)R(11)));
                    F(8) = vf3_mem_u32(ram, R(7) + 4);          /* tangent in */
                    F(5) = F(3);
                    F(9) = vf3_mem_u32(ram, R(7) + 8);          /* tangent out */
                    F(1) = vf3_mem_u32(ram, R(7) + 12);         /* next value */
                    R(0) = LIT_SCALE & 0x0FFFFFFFu;
                    SET_F(5, vf3_f_div(s, GET_F(5), GET_F(2)));  /* u = (t-t0)/(t1-t0) */
                    F(4) = vf3_mem_u32(ram, LIT_SCALE);
                    F(10) = F(3);
                    SET_F(9, vf3_f_mul(s, GET_F(9), GET_F(4)));
                    R(0) = LIT_MINUS_ONE & 0x0FFFFFFFu;
                    F(7) = vf3_mem_u32(ram, LIT_MINUS_ONE);
                    SET_F(8, vf3_f_mul(s, GET_F(8), GET_F(4)));
                    F(11) = vf3_mem_u32(ram, R(7));             /* this value */
                    F(4) = F(9); F(0) = F(8); F(6) = F(5);
                    SET_F(4, vf3_f_mul(s, GET_F(4), GET_F(5)));
                    SET_F(6, vf3_f_add(s, GET_F(6), GET_F(7)));
                    F(3) = F(4);
                    SET_F(3, vf3_f_mac(s, GET_F(0), GET_F(6), GET_F(3)));
                    F(0) = F(10);
                    F(8) = F(11);
                    R(2) = n; R(1) = n;
                    R(2) <<= 1;
                    R(12) += n;
                    F(4) = F(3);
                    SET_F(4, vf3_f_mul(s, GET_F(4), GET_F(6)));
                    R(2) += R(1);
                    R(5) = R(2);
                    SET_F(8, vf3_f_mac(s, GET_F(0), GET_F(4), GET_F(8)));
                    F(4) = F(6);
                    SET_F(4, vf3_f_add(s, GET_F(4), GET_F(6)));
                    F(6) = F(11);
                    SET_F(6, vf3_f_sub(s, GET_F(6), GET_F(1)));
                    F(0) = F(5);
                    SET_F(4, vf3_f_add(s, GET_F(4), GET_F(7)));
                    SET_F(4, vf3_f_mul(s, GET_F(4), GET_F(6)));
                    SET_F(4, vf3_f_mul(s, GET_F(4), GET_F(5)));
                    SET_F(8, vf3_f_mac(s, GET_F(0), GET_F(4), GET_F(8)));
                    F(4) = F(8);
                    R(5) += 2;
                }
                R(5) += 2;
                R(14) += R(5) << 2;
            }
        }

        vf3_mem_set_u32(ram, out, F(4));                      /* the channel's value */
        out += 4;
        vf3_mem_set_u32(ram, frame + 4, out);
        R(3) = out;
        R(5) = CHANNELS;
    }

    R(9) = CHANNELS;
    R(5) = CHANNELS;
    R(VF3_REG_SR) |= 1u;
    R(4) = vf3_mem_u32(ram, vf3_mem_u32(ram, frame));
    R(15) = frame;
    if (!vf3_guest_call(s, ram, FINISH, RET_FINISH)) return 0;

    R(3) = vf3_mem_u32(ram, frame + 4);
    R(2) = vf3_mem_u32(ram, frame);
    vf3_mem_set_u32(ram, R(2), R(3));
    R(15) = sp0;
    static const int pushed[6] = { 14, 13, 12, 11, 9, 8 };
    for (int i = 0; i < 6; ++i) R(pushed[i]) = saved[i];
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
