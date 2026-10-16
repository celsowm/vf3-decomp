/* bone_pose.c - 0x8C091438  build the world matrices of a fighter's 23 bones.
 *
 *   r4 = fighter object. Returns early unless the fighter is being drawn this frame (the pending
 *   flags at 0x0C29B864 / the object's own flags decide). Otherwise, with the matrix stack pushed:
 *   for each bone of the 23 (object +0x7C0 matrices, 64 bytes apart; +0x180 joints, advanced by a
 *   per-bone byte table at 0x0C119670; +0xE00 five-float pose records, 20 bytes apart):
 *     - identity, then multiply in the bone's parent matrix chain (0x03CC90 / 0x03C0E0 pairs)
 *     - 0x03B820 derives the bone's offset/axis angles into the local block at +0x94
 *     - the bone's cached pose record is either refreshed from 0x06938C or restored from the
 *       record (flag bit 0 of the pending word), giving the offset vector held at +0x88
 *     - a "ground contact" test (the bone type, the object's +0x380 height, 0.5) can zero the
 *       roll scale (fr14); the 12 words at 0x0C0D4600 / 0x0C0D460C are copied into local blocks
 *     - XMTRX = translate(-offset) then the chain again, scaled by fr14, and stored to the bone's
 *       matrix slot (+ a 0.035 lift on its Y translation for bone type 1)
 *   and the matrix stack is popped. Type 5/6/9/11/13 bones clear the pending flag's low bit. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

#define R(n) (s->v[(n)])
#define F(n) VF3_FR(s, (n))

enum {
    GLOBAL_A = 0x0C29BB84, FLAGS_CELL = 0x0C2A0978, DRAW_CELL = 0x0C29B864,
    ANGLES_TABLE = 0x0C11963C, BYTE_TABLE = 0x0C119670,
    SAVED_BYTES = 40, FRAME_BYTES = 184, BONES = 23,
    MATRIX_PUSH = 0x8C03C4F0, MATRIX_POP = 0x8C03C4A0, IDENTITY = 0x8C03CCB0,
    CHAIN_STEP = 0x8C03CC90, CONCAT = 0x8C03C0E0, DERIVE = 0x8C03B820, REFRESH = 0x8C06938C,
    WORD_COPY = 0x8C042F08, SET_TRANSLATION = 0x8C03CBD0, MATRIX_STORE = 0x8C03B620,
    MATRIX_LOAD = 0x8C03BD80, TRANSLATE_BY = 0x8C03CC60, MATRIX_SCALE = 0x8C03CB70,
    COPY_A = 0x0C0D4600, COPY_B = 0x0C0D460C
};

static uint32_t m32(const vf3_ram_map *ram, uint32_t a) { return vf3_mem_u32(ram, a); }
static void w32(const vf3_ram_map *ram, uint32_t a, uint32_t v) { vf3_mem_set_u32(ram, a, v); }

int vf3_bone_pose_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_fr15 = F(15), saved_fr14 = F(14);
    const uint32_t obj = R(4);
    const uint32_t V = frame + 0x88;                         /* offset vector (r14) */
    uint32_t late_call_ok = 1;

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    w32(ram, sp0 - 32u, saved_fr15);
    w32(ram, sp0 - 36u, saved_fr14);
    w32(ram, sp0 - 40u, pr0);
    R(15) = frame;
    w32(ram, frame + 32, 0);

    const uint32_t base = m32(ram, GLOBAL_A + 32);
    w32(ram, frame, base);
    uint32_t flag = m32(ram, base + 0x37C);
    R(9) = 1;
    if (obj != m32(ram, GLOBAL_A + 16)) {
        flag ^= 1u;
        w32(ram, base + 0x37C, flag);
    }
    R(13) = flag;
    R(4) = GLOBAL_A;
    if ((m32(ram, FLAGS_CELL) & 1u) != 0) goto epilogue;

    {
        const uint32_t draw0 = m32(ram, DRAW_CELL), draw1 = m32(ram, DRAW_CELL + 4), obj0 = m32(ram, obj);
        int go = 0;
        if ((draw0 & 0xC0000u) != 0) go = 1;
        else if ((draw0 & 0x3000000u) != 0 && (draw1 & 0xC0000u) != 0) go = 1;
        else if ((obj0 & 1u) != 0 && (obj0 & 0x1000000u) != 0 && (obj0 & 2u) == 0) go = 1;
        if (!go) goto epilogue;
    }
    R(12) = DRAW_CELL;
    R(11) = obj;
    R(14) = V;

    R(4) = 0;
    R(2) = 0x0C03C4F0u;
    if (!vf3_guest_call(s, ram, MATRIX_PUSH, 0x8C0914C0)) return 0;
    R(15) = frame;

    w32(ram, frame + 12, flag);
    const uint32_t type = vf3_mem_u8(ram, DRAW_CELL + 28) & 15u;
    R(12) = type;
    if (type == 5 || type == 6 || type == 9 || type == 11 || type == 13) w32(ram, frame + 12, flag & ~1u);

    const uint32_t entry = (uint32_t)vf3_mem_u8(ram, obj + 96) << 1;
    R(8) = ANGLES_TABLE - vf3_mem_u16(ram, ANGLES_TABLE + entry);
    w32(ram, frame + 20, base + 0x384);
    w32(ram, frame + 8, obj + 0x180);
    w32(ram, frame + 4, obj + 0x7C0);
    w32(ram, frame + 24, BYTE_TABLE);
    w32(ram, frame + 16, BONES);
    R(13) = obj + 0xE00;
    w32(ram, frame + 28, m32(ram, obj + 0x18C4));
    F(15) = 0;
    w32(ram, frame + 0xA8, 0); w32(ram, frame + 0xA0, 0); w32(ram, frame + 0xB4, 0); w32(ram, frame + 0xAC, 0);
    F(3) = m32(ram, obj + 0x1594);
    w32(ram, frame + 0xB0, F(3));
    F(3) ^= 0x80000000u;
    w32(ram, frame + 0xA4, F(3));
    R(9) = 1;

    while (m32(ram, frame + 16) > 0) {
        R(2) = 0x0C03CCB0u;
        if (!vf3_guest_call(s, ram, IDENTITY, 0x8C091596)) return 0;
        R(15) = frame;
        R(11) = 0x0C03CC90u;
        R(4) = 0xAC + frame;
        if (!vf3_guest_call(s, ram, CHAIN_STEP, 0x8C09159E)) return 0;
        R(15) = frame;
        R(10) = 0x0C03C0E0u;
        R(4) = m32(ram, frame + 20);
        if (!vf3_guest_call(s, ram, CONCAT, 0x8C0915A4)) return 0;
        R(15) = frame;
        R(4) = 0xA0 + frame;
        if (!vf3_guest_call(s, ram, CHAIN_STEP, 0x8C0915AA)) return 0;
        R(15) = frame;
        R(4) = m32(ram, frame + 8);
        if (!vf3_guest_call(s, ram, CONCAT, 0x8C0915AE)) return 0;
        R(15) = frame;
        R(4) = R(8);
        if (!vf3_guest_call(s, ram, CHAIN_STEP, 0x8C0915B2)) return 0;
        R(15) = frame;
        R(3) = 0x0C03B820u;
        R(4) = 0x94 + frame;
        if (!vf3_guest_call(s, ram, DERIVE, 0x8C0915BA)) return 0;
        R(15) = frame;

        R(14) = V;
        if ((m32(ram, frame + 12) & R(9)) == 0) {
            F(5) = m32(ram, frame + 0x9C) ^ 0x80000000u;
            R(5) = V;
            R(4) = frame + 0x98;
            R(3) = 0x0C06938Cu;
            F(4) = m32(ram, frame + 0x94);
            if (!vf3_guest_call(s, ram, REFRESH, 0x8C0915D4)) return 0;
            R(15) = frame;
            w32(ram, R(13), R(0));
            R(4) = R(0);
            F(3) = m32(ram, frame + 0x98);
            w32(ram, R(13) + 4, F(3));
            F(3) = m32(ram, V);      w32(ram, R(13) + 8, F(3));
            F(3) = m32(ram, V + 4);  w32(ram, R(13) + 12, F(3));
            F(3) = m32(ram, V + 8);  w32(ram, R(13) + 16, F(3));
        } else {
            R(4) = m32(ram, R(13));
            F(3) = m32(ram, R(13) + 4);  w32(ram, frame + 0x98, F(3));
            F(3) = m32(ram, R(13) + 8);  w32(ram, V, F(3));
            F(3) = m32(ram, R(13) + 12); w32(ram, V + 4, F(3));
            F(3) = m32(ram, R(13) + 16); w32(ram, V + 8, F(3));
        }

        /* ground-contact test: may zero the roll scale (fr14) */
        F(4) = 0x3F851EB8u;
        F(14) = F(4);
        int zero_roll = 0;
        if (R(12) == 1) {
            F(4) = m32(ram, base + 0x380);
            F(3) = m32(ram, frame + 0x98);
            zero_roll = !(vf3_bits_f32(F(3)) > vf3_bits_f32(F(4)));
        }
        if (!zero_roll) {
            const uint32_t pend = m32(ram, frame + 28);
            R(3) = pend;
            R(5) = 4;
            if ((pend & 4u) == 0 || (R(4) & 4u) == 0) zero_roll = 1;
            else {
                R(5) = 0x8008;
                if ((R(4) & 0x8008u) != 0) zero_roll = 1;
                else {
                    F(4) = 0x3F000000u;
                    F(3) = m32(ram, V + 4);
                    if (vf3_bits_f32(F(4)) > vf3_bits_f32(F(3))) zero_roll = 1;
                }
            }
        }
        if (zero_roll) F(14) = F(15);

        R(4) = frame + 48; R(2) = COPY_A; R(3) = 0x0C042F08u; R(1) = R(4); R(0) = 12;
        if (!vf3_guest_call(s, ram, WORD_COPY, 0x8C091680)) return 0;
        R(15) = frame;
        R(4) = frame + 36; R(2) = COPY_B; R(3) = 0x0C042F08u; R(1) = R(4); R(0) = 12;
        if (!vf3_guest_call(s, ram, WORD_COPY, 0x8C09168E)) return 0;
        R(15) = frame;
        R(1) = 0x0C03CCB0u;
        if (!vf3_guest_call(s, ram, IDENTITY, 0x8C091694)) return 0;
        R(15) = frame;
        R(3) = 0x0C03CBD0u;
        R(4) = 0x94 + frame;
        if (!vf3_guest_call(s, ram, SET_TRANSLATION, 0x8C09169C)) return 0;
        R(15) = frame;

        const uint32_t t = R(12);
        R(0) = t;
        if (!(t == 2 || t == 8 || t == 11 || t == 14 || t == 15)) {
            R(4) = frame;
            w32(ram, frame + 32, R(9));
            R(3) = 0x0C03B620u;
            R(4) = frame + 72;
            if (!vf3_guest_call(s, ram, MATRIX_STORE, 0x8C0916C4)) return 0;
            R(15) = frame;
            F(3) = m32(ram, V + 8) ^ 0x80000000u;  w32(ram, V + 8, F(3));
            F(3) = m32(ram, V + 4);  w32(ram, frame + 72, F(3));
            F(3) = m32(ram, V) ^ 0x80000000u;      w32(ram, frame + 76, F(3));
            w32(ram, frame + 80, F(15));
            F(3) = m32(ram, V);      w32(ram, frame + 88, F(3));
            F(3) = m32(ram, V + 4);  w32(ram, frame + 92, F(3));
            F(3) = m32(ram, V + 8);  w32(ram, frame + 96, F(3));
            w32(ram, frame + 104, F(15));
            F(3) = m32(ram, V + 8) ^ 0x80000000u;  w32(ram, frame + 108, F(3));
            R(4) = frame;
            F(3) = m32(ram, V + 4);  w32(ram, frame + 112, F(3));
            R(3) = 0x0C03BD80u;
            R(4) = frame + 72;
            if (!vf3_guest_call(s, ram, MATRIX_LOAD, 0x8C091714)) return 0;
            R(15) = frame;
        }
        R(3) = 0x0C03CC60u;
        F(6) = m32(ram, frame + 0x9C) ^ 0x80000000u;
        F(4) = m32(ram, frame + 0x94) ^ 0x80000000u;
        F(5) = F(15);
        if (!vf3_guest_call(s, ram, TRANSLATE_BY, 0x8C091726)) return 0;
        R(15) = frame;
        R(4) = m32(ram, frame + 20);
        if (!vf3_guest_call(s, ram, CONCAT, 0x8C09172A)) return 0;
        R(15) = frame;
        R(4) = 0xA0 + frame;
        if (!vf3_guest_call(s, ram, CHAIN_STEP, 0x8C091730)) return 0;
        R(15) = frame;
        R(4) = m32(ram, frame + 8);
        if (!vf3_guest_call(s, ram, CONCAT, 0x8C091734)) return 0;
        R(15) = frame;
        R(4) = R(8);
        if (!vf3_guest_call(s, ram, CHAIN_STEP, 0x8C091738)) return 0;
        R(15) = frame;
        R(11) = 0x0C03CB70u;
        F(5) = F(14); F(6) = F(14); F(4) = F(14);
        if (!vf3_guest_call(s, ram, MATRIX_SCALE, 0x8C091742)) return 0;
        R(15) = frame;
        R(4) = m32(ram, frame + 4);
        R(3) = 0x0C03B620u;
        if (!vf3_guest_call(s, ram, MATRIX_STORE, 0x8C091786)) return 0;
        R(15) = frame;

        R(0) = m32(ram, frame + 32);
        R(8) += 12;
        if (R(0) == 1) {
            R(0) = 0x0C0917F4u;
            F(4) = m32(ram, 0x8C0917F4);
            R(3) = m32(ram, frame + 4);
            F(3) = m32(ram, frame + 0x98);
            F(3) = vf3_f32_bits(vf3_f_add(s, vf3_bits_f32(F(3)), vf3_bits_f32(F(4))));
            w32(ram, R(3) + 52, F(3));
        }
        uint32_t cursor = m32(ram, frame + 24);
        R(13) += 20;
        w32(ram, frame + 24, cursor + 1);
        R(4) = vf3_mem_u8(ram, cursor);
        R(4) += m32(ram, frame + 8);
        w32(ram, frame + 8, R(4));
        R(3) = m32(ram, frame + 4) + 64;
        w32(ram, frame + 4, R(3));
        R(2) = m32(ram, frame + 16) - 1;
        w32(ram, frame + 16, R(2));
    }

    R(3) = 0x0C03C4A0u;
    R(4) = 1;
    if (!vf3_guest_call(s, ram, MATRIX_POP, 0x8C0917D0)) return 0;
    R(1) = 0xB8;
    (void)late_call_ok;

epilogue:
    R(15) = sp0;
    F(15) = saved_fr15;
    F(14) = saved_fr14;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved[i];
    }
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
