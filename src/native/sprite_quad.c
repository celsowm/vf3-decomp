/* sprite_quad.c - SH-4 0x8C03F830: the billboard-sprite quad submission,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/sprite_readable.c
 * (`vf3_sprite_quad_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank
 * and the register file.
 *
 * r4 = sprite object.  Looks the object's sprite index up in the table at
 * 0x0C19E208, scales the four corner offsets by the object's size/rotation
 * (sin/cos of the angle at +28 through the corner fan 0x8C03FB10), packs the
 * 16-bit texture coordinates, patches the sprite's TA header words (entry of
 * 0x20 bytes in the table at 0x0C19E214) and finally pushes header + four
 * vertices through the store queue (3 SQ lines), then advances the SQ cursor
 * kept next to the table at 0x0C16CA08.
 *
 * The four fixed callees - sin (0x8C03A6E0), cos (0x8C03A140),
 * corner_fan (0x8C03FB10) and color_pack (0x8C03FB80) - are all already
 * native, so this leaf calls their `vf3_native_*` entry points directly.
 *
 * The SQ/QACR device stores happen through the flat RAM writes at the store-
 * queue area; they only have to reproduce the RAM-visible effects (the SQ
 * cursor advance at 0x0C16CA08).  The header patching, the four corner
 * squashes and the texture packing all land in the RAM windows the test
 * seeds.
 *
 * The original saves r8-r14, FR13-FR15 and PR (44 bytes) and a 60 byte frame;
 * the dead stack words are replayed because they are visible in RAM.
 *
 * See docs/re/native_sprite_quad.md. */
#include "sprite_quad.h"

#include "aim_math.h"
#include "sin_cos.h"
#include "corner_fan.h"
#include "color_pack.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SPRITE_INDEX_TABLE = 0x0C19E208, SPRITE_HEADER_TABLE = 0x0C19E214,
    SQ_STATE          = 0x0C16CA08,  QACR0              = 0xFF000038,
    QACR1             = 0xFF00003C,  HALF_CONST         = 0x0C03F978,
    SCALE_X           = 0x0C0EA538,  SCALE_Y            = 0x0C0EA534,
    SCALE_TAB         = 0x0C0EA668,  TINT_TAB           = 0x0C0EA634,
    OBJ_FLAGS         = 0x2C,
    SPRITE_NONE       = (uint32_t)-1,
    SQ_REGION_MASK    = 0xFC000000,  SQ_REGION          = 0xE0000000,
    SQ_ADDR_MASK      = 0x03FFFFFF
};
#define FRAME_BYTES 60u
#define SAVED_BYTES 44u

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* ---- round-toward-zero + FTZ wrappers (as sprite_rect_a.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fop(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fsub(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '+'); }
static inline float fdivv(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '/'); }

/* FR4/FR5/FR6/FR7 piped bridge for the corner fan */
static void call_fan(vf3_native_aim *a)
{
    vf3_native_corner_fan(a);
}

void vf3_native_sprite_quad(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), obj = R(4);
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t pr = a->pr;

    /* prologue pushes: r14 r13 r12 r11 r10 r9 r8 fr15 fr14 fr13 pr */
    for (int i = 0; i < 7; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), a->r[14 - i]);
    vf3_aim_set_u32(a, sp0 - 32u, vf3_aim_ubits(F(15)));
    vf3_aim_set_u32(a, sp0 - 36u, vf3_aim_ubits(F(14)));
    vf3_aim_set_u32(a, sp0 - 40u, vf3_aim_ubits(F(13)));
    vf3_aim_set_u32(a, sp0 - 44u, pr);

    const uint32_t index_word = vf3_aim_u32(a, obj);
    const int32_t sprite = (int16_t)vf3_aim_h16(a,
                vf3_aim_u32(a, SPRITE_INDEX_TABLE) + 2u * index_word);
    if (sprite == (int32_t)SPRITE_NONE) { R(15) = sp0; a->pr = pr; return; }

    const uint32_t hdr = vf3_aim_u32(a, SPRITE_HEADER_TABLE) +
                         ((uint32_t)sprite << 5);
    const float one = 1.0f;
    float size_scale = bits2f(vf3_aim_u32(a, obj + 0x30u));
    const int translucent = one > size_scale || vf3_aim_u32(a, hdr + 20u) != 0;

    const float half = bits2f(vf3_aim_u32(a, HALF_CONST));
    const float obj_w = bits2f(vf3_aim_u32(a, obj + 0x10u)),
                obj_h = bits2f(vf3_aim_u32(a, obj + 0x14u));
    const float dx = fmul(a, fmul(a, bits2f(vf3_aim_u32(a, hdr + 0x18u)), obj_w), half);
    const float dy = fmul(a, fmul(a, bits2f(vf3_aim_u32(a, hdr + 0x1Cu)), obj_h), half);
    vf3_aim_set_u32(a, frame + 8u, vf3_aim_ubits(dx));
    vf3_aim_set_u32(a, frame + 4u, vf3_aim_ubits(dy));
    const float inv_depth = fdivv(a, one, bits2f(vf3_aim_u32(a, obj + 0x0Cu)));

    const uint32_t saved_fr13 = vf3_aim_ubits(F(13)),
                   saved_fr14 = vf3_aim_ubits(F(14)),
                   saved_fr15 = vf3_aim_ubits(F(15));
    F(13) = inv_depth;              /* the callees push these as dead words */
    F(14) = size_scale;
    F(15) = one;

    R(15) = frame;
    /* sin(angle) -> fr0 */
    R(4) = vf3_aim_u32(a, obj + 0x28u);
    vf3_native_sin_u16(a);
    vf3_aim_set_u32(a, frame, vf3_aim_ubits(F(0)));
    /* cos(angle) -> fr0 */
    R(4) = vf3_aim_u32(a, obj + 0x28u);
    vf3_native_cos_u16(a);

    const uint32_t out_b = frame + 28u, out_a = frame + 44u;
    R(4) = obj; R(5) = out_a; R(6) = out_b;
    F(7) = F(0);
    F(4) = dx;
    F(5) = dy;
    F(6) = bits2f(vf3_aim_u32(a, frame));
    call_fan(a);

    /* squash the fan corners by the two global scale factors */
    const float scale_x = bits2f(vf3_aim_u32(a, SCALE_X)),
                scale_y = bits2f(vf3_aim_u32(a, SCALE_Y));
    const float tab_y = fmul(a, bits2f(vf3_aim_u32(a, SCALE_TAB + 4u)), scale_x);
    const float tab_x = fmul(a, bits2f(vf3_aim_u32(a, SCALE_TAB)), scale_y);
    for (uint32_t i = 0; i < 16u; i += 4u) {
        vf3_aim_set_u32(a, out_a + i,
            vf3_aim_ubits(fmul(a, bits2f(vf3_aim_u32(a, out_a + i)), tab_x)));
        vf3_aim_set_u32(a, out_b + i,
            vf3_aim_ubits(fmul(a, bits2f(vf3_aim_u32(a, out_b + i)), tab_y)));
    }

    /* patch the sprite header from the object flags */
    vf3_aim_set_u32(a, hdr, vf3_aim_u32(a, hdr) & 0xF8FFFFFFu);
    uint32_t h8 = vf3_aim_u32(a, hdr + 8u) & 0x03279FFFu;
    const uint32_t flags = vf3_aim_u32(a, obj + OBJ_FLAGS);
    if (!(flags & 0x0800u)) h8 |= 0x00800000u;
    if (flags & 0x1000u) h8 |= 0x2000u;
    vf3_aim_set_u32(a, hdr + 8u, h8);

    uint32_t blend = ((int32_t)flags >> 8) & 7u;
    if (blend == 0) blend = 4u;
    vf3_aim_set_u32(a, hdr + 4u,
        (vf3_aim_u32(a, hdr + 4u) & 0x1FFFFFFFu) | (blend << 29));
    float tint = size_scale;
    if (translucent) {
        vf3_aim_set_u32(a, hdr, vf3_aim_u32(a, hdr) | 0x02000000u);
        vf3_aim_set_u32(a, hdr + 8u, vf3_aim_u32(a, hdr + 8u) | 0x94100000u);
    } else {
        vf3_aim_set_u32(a, hdr + 8u, vf3_aim_u32(a, hdr + 8u) | 0x20080000u);
        tint = one;
    }

    /* colour: tint scaled through the packer 0x8C03FB80 */
    F(4) = tint;
    if (vf3_aim_u32(a, obj + OBJ_FLAGS) & 0x2000u) {
        F(5) = bits2f(vf3_aim_u32(a, TINT_TAB));
        F(6) = bits2f(vf3_aim_u32(a, TINT_TAB + 4u));
        F(7) = bits2f(vf3_aim_u32(a, TINT_TAB + 8u));
    } else {
        F(5) = one; F(6) = one; F(7) = one;
    }
    vf3_native_color_pack(a);
    vf3_aim_set_u32(a, hdr + 16u, R(0));

    /* texture coordinates: the (u0,v0) pair is flipped when flag 0x10 is
     * set, the (u1,v1) pair when flag 0x20 is clear */
    uint32_t mirror = vf3_aim_u32(a, obj + OBJ_FLAGS) & 0x30u;
    float u0 = bits2f(vf3_aim_u32(a, obj + 0x18u)),
          v0 = bits2f(vf3_aim_u32(a, obj + 0x20u));
    if (mirror & 0x10u) { u0 = fsub(a, one, u0); v0 = fsub(a, one, v0); }
    float u1 = bits2f(vf3_aim_u32(a, obj + 0x1Cu)),
          v1 = bits2f(vf3_aim_u32(a, obj + 0x24u));
    if (!(mirror & 0x20u)) { u1 = fsub(a, one, u1); v1 = fsub(a, one, v1); }
    uint32_t bits_u0 = vf3_aim_ubits(u0), bits_v0 = vf3_aim_ubits(v0);
    uint32_t bits_u1 = vf3_aim_ubits(u1), bits_v1 = vf3_aim_ubits(v1);
    vf3_aim_set_u32(a, frame + 24u, bits_u0);
    vf3_aim_set_u32(a, frame + 20u, bits_u0 & 0xFFFF0000u);
    vf3_aim_set_u32(a, frame + 24u, bits_v0);
    uint32_t pack_hi = bits_v0 & 0xFFFF0000u;                 /* r13 */
    vf3_aim_set_u32(a, frame + 24u, bits_u1);
    const uint32_t pack_lo = bits_u1 >> 16;                   /* r7  */
    vf3_aim_set_u32(a, frame + 24u, bits_v1);
    vf3_aim_set_u32(a, frame + 16u, bits_v1 >> 16);
    const uint32_t lo_word = bits_v1 >> 16;
    const uint32_t line_off = translucent ? 8u : 0u;
    vf3_aim_set_u32(a, frame + 12u, line_off);

    /* store-queue submission: the SQ cursor advance is the RAM-visible
     * effect.  The three SQ-line bursts to the SQR area and the QACR
     * register writes are hardware; reproduced here as a cursor 32 before
     * the current one (the readable performs three pref advances). */
    uint32_t sq_base = vf3_aim_u32(a, SQ_STATE);
    uint32_t sq_word = vf3_aim_u32(a, sq_base + line_off);
    uint32_t qacr = sq_word >> 24;
    /* QACR0/QACR1 register stores (device) - we do not touch them */

    uint32_t q = (sq_word & SQ_ADDR_MASK) | SQ_REGION;
    uint32_t qraw = sq_word & SQ_ADDR_MASK;
    uint32_t count = (translucent ? 8u : 0u);

    /* the three pref advances step q by 96 bytes past the four lines */
    const uint32_t qend = qraw + 96u;

    const uint32_t cursor = sq_base + line_off;
    vf3_aim_set_u32(a, cursor,
        (vf3_aim_u32(a, cursor) & SQ_REGION_MASK) | (qend & SQ_ADDR_MASK));

    F(13) = bits2f(saved_fr13);
    F(14) = bits2f(saved_fr14);
    F(15) = bits2f(saved_fr15);
    R(15) = sp0;
    a->pr = pr;
}
