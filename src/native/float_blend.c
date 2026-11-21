/* float_blend.c - SH-4 0x8C03E810: the four-float blend leaf, natively.
 *
 * A plain-C transcription of the readable port src/fight/float_blend.c
 * (`vf3_float_blend_entry`).  A call-free FP leaf: it copies four floats out
 * of an array (r4) and into a structure of four slots, then writes a weighted
 * sum over three of the slots back into the first one:
 *
 *     slot0 = weight_a * slot2 + weight_b * slot1 + weight_c * slot3
 *
 * The structure's address is a word in the literal pool (0x0C03E8A4) and the
 * three weights are pool floats (0x0C03E8A8 / _A C / _B0).  The blend is a
 * multiply followed by two *fused* multiply-adds, so the port uses fmaf (via
 * the fmac wrapper), rounding once per step under the FPSCR's rounding mode
 * (bit 0: 1 = toward-zero, 0 = nearest) with the FPSCR's FTZ flush applied.
 *
 * The only control transfer is the final rts, so this is a tail transfer to
 * pr (untouched).  The call pushes an 8-byte frame below sp for the two slot
 * addresses the blend reads back; the round trip is net zero on r15, so the
 * port writes the two frame words at sp-8 / sp-4 and leaves r15 unchanged.
 *
 * The FPSCR's double-precision bit (0x100000) makes the float loads/stores
 * eight bytes wide and the array's step eight bytes; single precision (the
 * evidenced corpus FPSCR 0x00040001) is four.  The register bank the
 * loads/stores use is the FR bank; the double-width pairing (odd registers
 * through the XF half) is carried only for fidelity and is not evidenced by
 * any captured state (the corpus exercises single precision only).
 *
 * See docs/re/native_float_blend.md. */
#include "float_blend.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* the literal pool: the structure and the three weights */
#define G_DEST 0x0c03e8a4u
#define G_A    0x0c03e8a8u
#define G_B    0x0c03e8acu
#define G_C    0x0c03e8b0u

/* the frame the function pushes */
#define FRAME 8u

/* the FPSCR's double-precision bit: it makes the float loads eight bytes
 * wide and the array's step eight bytes long */
#define FPSCR_WIDE 0x100000u

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{
    uint8_t *p = gb(a, addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static float rd32f(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_fbits(rd32(a, addr)); }

/* copy the register's word(s) between the FR bank and RAM: width 4 in single
 * precision, 8 in double (the paired FR word; carried for fidelity only) */
static float *fbank(vf3_native_aim *a, unsigned reg)
{
    if (a->fpscr & FPSCR_WIDE) return &F(reg & ~1u);
    return &F(reg);
}
static void fload(vf3_native_aim *a, unsigned reg, uint32_t addr)
{
    const unsigned n = (a->fpscr & FPSCR_WIDE) ? 2u : 1u;
    uint32_t *p = (uint32_t *)fbank(a, reg);
    for (unsigned i = 0; i < n; ++i) p[i] = rd32(a, addr + 4u * i);
}
static void fstore(vf3_native_aim *a, unsigned reg, uint32_t addr)
{
    const unsigned n = (a->fpscr & FPSCR_WIDE) ? 2u : 1u;
    uint32_t *p = (uint32_t *)fbank(a, reg);
    for (unsigned i = 0; i < n; ++i) {
        uint32_t u = p[i];
        memcpy(gb(a, addr + 4u * i), &u, 4);
    }
}
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }

/* ---- FPSCR-aware FPU wrappers ----
 * Rounding mode is bit 0 of the FPSCR (1 = toward-zero, 0 = nearest); the
 * result is flushed (FTZ) when bit 0x40000 is set. */
static inline float flush(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fmul(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x * y;
    fesetround(saved);
    return flush(a, z);
}
static inline float fmac(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flush(a, z);
}

/* one step along the array */
static inline uint32_t fstep(vf3_native_aim *a)
{ return (a->fpscr & FPSCR_WIDE) ? 8u : 4u; }

void vf3_native_float_blend(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the structure */
    R(5) = rd32(a, G_DEST);

    /* the first weight's address */
    R(0) = G_A;

    /* the array's first float, into the slot at +0 */
    fload(a, 3, R(4));
    R(4) += fstep(a);

    /* the frame: the two slot addresses the blend reads back */
    R(6) = R(5);
    R(3) = R(6);
    fstore(a, 3, R(6));
    R(3) = R(6) + 4u;
    R(7) = R(6) + 8u;
    R(5) = R(6) + 12u;
    wr32(a, sp - 8u, R(3));

    /* the array's second float, into the slot at +4 */
    fload(a, 3, R(4));
    R(4) += fstep(a);
    fstore(a, 3, R(3));

    /* the array's third float, into the slot at +8 */
    fload(a, 3, R(4));
    R(4) += fstep(a);
    fstore(a, 3, R(7));

    wr32(a, sp - 4u, R(5));

    /* the array's fourth float, into the slot at +12 */
    fload(a, 3, R(4));
    fstore(a, 3, R(5));

    /* and the blend over the three slots that are not the first */
    fload(a, 3, R(7));                    /* FR3: the slot at +8 */
    fload(a, 0, R(0));                    /* FR0: the first weight */
    R(0) = G_B;
    R(2) = rd32(a, sp - 8u);              /* the slot at +4 */
    F(3) = fmul(a, F(3), F(0));

    fload(a, 0, R(0));                    /* FR0: the second weight */
    fload(a, 2, R(2));                    /* FR2: the slot at +4 */
    R(0) = G_C;
    R(3) = rd32(a, sp - 4u);              /* the slot at +12 */
    F(3) = fmac(a, F(0), F(2), F(3));

    fload(a, 0, R(0));                    /* FR0: the third weight */
    fload(a, 2, R(3));                    /* FR2: the slot at +12 */
    F(3) = fmac(a, F(0), F(2), F(3));

    /* and back into the slot at +0 */
    fstore(a, 3, R(6));

    /* r15 round trip is net zero: the frame words stay at sp-8 / sp-4 */
    /* tail-transfer to pr: the C return leaves pr untouched */
}
