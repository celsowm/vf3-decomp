/* clip_emit_slot.c - SH-4 0x8C048C80 (clip_emit_slot), natively.
 *
 * Mirror of the readable authority src/fight/vertex_clip.c
 * (`vf3_clip_emit_slot_entry`).  It pushes ring slot r0&3 to the store queue
 * at r6, scaling its y' and z' by the reciprocal 1/x' first, and writes the
 * strip's control word in the first slot word.
 *
 *   r0   ring slot index (a 32-byte slot in the 4-slot ring at RING_BASE
 *        0x0C1A5960),
 *   r6   the store-queue slot (advanced by 32 on return),
 *   r5   an input/block cursor (advanced by 32 on return),
 *   SR.T the strip-end flag (0xF0000000 control word) vs the slot's own
 *        address.
 *
 * The body copies the ring slot's eight words at the addressed offsets into
 * the store-queue block, scaling y' and z' by the reciprocal (a single
 * fmul each, toward-zero rounding), writes the control word first, and
 * leaves FR0..FR7 carrying the eight words.  It runs only with FPSCR.SZ clear
 * and the FPU enabled; it returns 0 when the entry FPSCR would be rejected.
 *
 * The observable flat-RAM contract is the 32-byte slot written at r6 plus the
 * register file (r0, r2, r5, r6, r10) and FR0..FR7.  The ring slots live in
 * flat RAM (the fixture seeds them), and the pref flush is a store-queue
 * device side effect, inert when r6 is a RAM pointer.
 */
#include "clip_emit_slot.h"

#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SLOT_SIZE = 32u, RING_BASE = 0x0C1A5960u, RING_MASK = 3u,
    FPSCR_SZ = 0x00100000u, FPSCR_FTZ = 0x00040000u,
    STRIP_END_FLAG = 0xF0000000u,
    W = 0x00, Y = 0x04, Z = 0x08, INV_X = 0x0C, W1 = 0x10, W2 = 0x14,
    DIFFUSE = 0x18, SPECULAR = 0x1C,
};

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }

static float flushz(vf3_native_aim *a, float f)
{
    if (a->fpscr & FPSCR_FTZ) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x * y;
    fesetround(saved);
    return flushz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y); }

static uint32_t ring_slot(uint32_t index) { return RING_BASE + (index & RING_MASK) * SLOT_SIZE; }

int vf3_native_clip_emit_slot(vf3_native_aim *a)
{
    if ((a->fpscr & 0x80000u) || (a->fpscr & 3u) > 1u || (a->fpscr & FPSCR_SZ)) return 0;

    const uint32_t src = ring_slot(R(0));
    const uint32_t out = R(6);                   /* start of the store-queue slot */

    const uint32_t w = vf3_aim_u32(a, src + W);
    const float y = fbits(vf3_aim_u32(a, src + Y));
    const float z = fbits(vf3_aim_u32(a, src + Z));
    const float inv_x = fbits(vf3_aim_u32(a, src + INV_X));
    const float y_scaled = fmul(a, y, inv_x);
    const float z_scaled = fmul(a, z, inv_x);

    F(0) = fbits(w);
    F(1) = y_scaled;
    F(2) = z_scaled;
    F(3) = fbits(vf3_aim_u32(a, src + INV_X));
    F(4) = fbits(vf3_aim_u32(a, src + W1));
    F(5) = fbits(vf3_aim_u32(a, src + W2));
    F(6) = fbits(vf3_aim_u32(a, src + DIFFUSE));
    F(7) = fbits(vf3_aim_u32(a, src + SPECULAR));

    const uint32_t base = out;
    vf3_aim_set_u32(a, base + DIFFUSE, ubits(F(6)));
    vf3_aim_set_u32(a, base + SPECULAR, ubits(F(7)));
    vf3_aim_set_u32(a, base + W1, ubits(F(4)));
    vf3_aim_set_u32(a, base + W2, ubits(F(5)));
    vf3_aim_set_u32(a, base + Z, ubits(F(2)));
    vf3_aim_set_u32(a, base + INV_X, ubits(F(3)));
    vf3_aim_set_u32(a, base + W, ubits(F(0)));
    vf3_aim_set_u32(a, base + Y, ubits(F(1)));

    R(5) += SLOT_SIZE;
    R(2) = (a->sr & 1u) ? STRIP_END_FLAG : base;
    vf3_aim_set_u32(a, base, R(2));
    R(10) = src + SLOT_SIZE;
    R(0) = (R(0) & RING_MASK) * SLOT_SIZE;
    R(6) = base + SLOT_SIZE;
    return 1;
}
