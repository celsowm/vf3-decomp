/* clip_edge.c - SH-4 0x8C048CC0 (clip_edge), natively.
 *
 * Mirror of the readable authority src/fight/vertex_clip.c
 * (`vf3_clip_edge_entry`).  It pushes the point where the strip edge
 * ring[r0&3] -> ring[r11&3] crosses the plane w' = r12, finishing a vertex in
 * the 32-byte store-queue block at r6.
 *
 *   r0   ring slot index of the edge start (a 32-byte slot in the 4-slot
 *        ring at RING_BASE 0x0C1A5960),
 *   r11  ring slot index of the edge end,
 *   r12  the clip plane w' (compared as a bit pattern / float),
 *   r7   a scale float (bits) applied to the interpolated y' and z',
 *   r6   the store-queue slot (advanced by 32 on return),
 *   r5   an input/block cursor (advanced by 32 on return),
 *   SR.T the strip-end flag (0xF0000000 control word) vs an address.
 *
 * The body derives t = (plane - w0) / (w1 - w0), interpolates every
 * attribute lerp(a0, a1, t) = a0 + t * (a1 - a0) with a *fused* multiply-add
 * (the hardware rounds once; the C port must use fmaf, not `a + t*d`), scales
 * y' and z' by the r7 float, writes the 32-byte block, and leaves FR0..FR5 =
 * (t, scale, y', z', d4, d5).  It runs only with FPSCR.SZ clear and the FPU
 * enabled; it returns 0 when the entry FPSCR would be rejected.
 *
 * The observable flat-RAM contract is the 32-byte slot written at r6 plus the
 * register file (r0, r2, r5, r6, r10, fpul) and FR0..FR5.  The ring slots live
 * in flat RAM (the fixture seeds them), and the pref flush is a store-queue
 * device side effect, inert when r6 is a RAM pointer.
 */
#include "clip_edge.h"

#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SLOT_SIZE = 32u, RING_BASE = 0x0C1A5960u, RING_MASK = 3u,
    FPSCR_SZ = 0x00100000u, FPSCR_FTZ = 0x00040000u,
    SQ_REGION_MASK = 0xFC000000u, SQ_REGION = 0xE0000000u,
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
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = 0;
    switch (op) {
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flushz(a, z);
}
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fdiv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }
static inline float fmac(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flushz(a, z);
}

static uint32_t ring_slot(uint32_t index) { return RING_BASE + (index & RING_MASK) * SLOT_SIZE; }

static void pref_sq(vf3_native_aim *a, uint32_t slot)
{
    (void)a; (void)slot;      /* store-queue flush, inert on flat RAM */
}

int vf3_native_clip_edge(vf3_native_aim *a)
{
    if ((a->fpscr & 0x80000u) || (a->fpscr & 3u) > 1u || (a->fpscr & FPSCR_SZ)) return 0;

    const uint32_t p = ring_slot(R(0));              /* edge start */
    const uint32_t q = ring_slot(R(11));             /* edge end */
    const uint32_t base = R(6);                      /* start of the store-queue slot */

    /* t = (plane - w0) / (w1 - w0) */
    const float sw0 = fbits(vf3_aim_u32(a, p + W));
    const float plane_gap = fsub(a, fbits(R(12)), sw0);
    const float edge_gap = fsub(a, fbits(vf3_aim_u32(a, q + W)), sw0);
    const float t = fdiv(a, plane_gap, edge_gap);
    const float scale = fbits(R(7));

    float d4, d5, shade, spec, u, v, y, z;
    /* a0 + t*(a1-a0), fused */
    shade = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + DIFFUSE)), fbits(vf3_aim_u32(a, p + DIFFUSE))),
                 fbits(vf3_aim_u32(a, p + DIFFUSE)));
    d4 = fsub(a, fbits(vf3_aim_u32(a, q + DIFFUSE)), fbits(vf3_aim_u32(a, p + DIFFUSE)));
    spec = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + SPECULAR)), fbits(vf3_aim_u32(a, p + SPECULAR))),
                fbits(vf3_aim_u32(a, p + SPECULAR)));
    d5 = fsub(a, fbits(vf3_aim_u32(a, q + SPECULAR)), fbits(vf3_aim_u32(a, p + SPECULAR)));
    vf3_aim_set_u32(a, base + DIFFUSE, ubits(shade));
    vf3_aim_set_u32(a, base + SPECULAR, ubits(spec));

    u = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + W1)), fbits(vf3_aim_u32(a, p + W1))),
             fbits(vf3_aim_u32(a, p + W1)));
    d4 = fsub(a, fbits(vf3_aim_u32(a, q + W1)), fbits(vf3_aim_u32(a, p + W1)));
    v = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + W2)), fbits(vf3_aim_u32(a, p + W2))),
             fbits(vf3_aim_u32(a, p + W2)));
    d5 = fsub(a, fbits(vf3_aim_u32(a, q + W2)), fbits(vf3_aim_u32(a, p + W2)));
    vf3_aim_set_u32(a, base + W1, ubits(u));
    vf3_aim_set_u32(a, base + W2, ubits(v));
    vf3_aim_set_u32(a, base + INV_X, ubits(scale));

    y = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + Y)), fbits(vf3_aim_u32(a, p + Y))),
             fbits(vf3_aim_u32(a, p + Y)));
    d4 = fsub(a, fbits(vf3_aim_u32(a, q + Y)), fbits(vf3_aim_u32(a, p + Y)));
    z = fmac(a, t, fsub(a, fbits(vf3_aim_u32(a, q + Z)), fbits(vf3_aim_u32(a, p + Z))),
             fbits(vf3_aim_u32(a, p + Z)));
    d5 = fsub(a, fbits(vf3_aim_u32(a, q + Z)), fbits(vf3_aim_u32(a, p + Z)));
    y = fmul(a, y, scale);
    z = fmul(a, z, scale);
    vf3_aim_set_u32(a, base + Z, ubits(z));
    vf3_aim_set_u32(a, base + Y, ubits(y));

    /* this path stores the control word with a pre-decrement, so the address
     * it records is the previous word's (the y' field) rather than the slot's.
     * The T bit is read here before any of the writes below touch it. */
    R(2) = (a->sr & 1u) ? STRIP_END_FLAG : (base + Y);
    vf3_aim_set_u32(a, base, R(2));
    pref_sq(a, base);

    F(0) = t;
    F(1) = scale;
    F(2) = y;
    F(3) = z;
    F(4) = d4;
    F(5) = d5;
    a->fpul = R(7);
    R(0) = (R(11) & RING_MASK) * SLOT_SIZE;
    R(10) = p + Y;
    R(5) += SLOT_SIZE;
    R(6) = base + SLOT_SIZE;
    return 1;
}
