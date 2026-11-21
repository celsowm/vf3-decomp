/* color_unpack.c - SH-4 0x8C0562E0: unpack three halfword-packed byte
 * triples into scaled floats, natively.
 *
 * A plain-C transcription of the readable port src/fight/color_unpack.c
 * (`vf3_color_unpack_entry`).  A call-free FP leaf with no guest callees and
 * no stack frame - the only control transfer is the final tail transfer to
 * pr.  The single device-free register it touches beyond the FR/FPUL bank is
 * GBR (its +96 write of the packed halfwords).
 *
 *   r4 -> the record (4 bytes skipped, then three halfwords).  The 3-float
 *   vector at [0x0C19D5C8] is multiplied by the factor at 0x0C056508; the
 *   first two halfwords are packed (halfword 2 over halfword 1) into
 *   GBR+0x60, and each halfword's two bytes are converted to float and
 *   scaled by the vector.  Six floats are stored at 0x0C16B82C and downwards
 *   (three, then 28 bytes back up for the last three).
 *
 *   Out: r4 advanced by 10, r1 = the last store address, the results in
 *   FR0..FR2, the scale in FR4..FR7.
 *
 * The FLOAT conversions (FPUL -> float) and the multiplies are FPSCR-aware
 * (rounding = fpscr & 1, FTZ when bit 0x40000), same wrapper as the other FP
 * leaves.  See docs/re/native_color_unpack.md. */
#include "color_unpack.h"
#include "aim_math.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define SCALE_PTR 0x0C19D5C8u
#define FACTOR    0x0C056508u
#define OUT       0x0C16B82Cu
#define PACK_GBR  96u

/* ---- FPSCR-aware FPU wrappers (as vertex_writer.c) ---- */
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
/* FLOAT: FPUL -> float, honouring the FPSCR rounding and FTZ */
static inline float f2f(vf3_native_aim *a)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = (float)(int32_t)a->fpul;
    fesetround(saved);
    return flush(a, z);
}

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ uint32_t u; memcpy(&u, gb(a, addr), 4); return u; }
static uint32_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint16_t)((uint16_t)gb(a, addr)[0] | ((uint16_t)gb(a, addr)[1] << 8)); }
static uint32_t sext16(vf3_native_aim *a, uint32_t addr)
{ return (uint32_t)(int32_t)(int16_t)rd16(a, addr); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }

/* pre-decrementing store: the guest writes the run of floats downwards */
static void store_pre(vf3_native_aim *a, int n)
{
    R(1) -= 4;
    wr32(a, R(1), vf3_aim_ubits(F(n)));
}

void vf3_native_color_unpack(vf3_native_aim *a)
{
    R(2) = SCALE_PTR;
    R(4) += 4;
    F(7) = vf3_aim_fbits(rd32(a, FACTOR));
    R(5) = sext16(a, R(4)); R(4) += 2;
    R(6) = sext16(a, R(4)); R(4) += 2;
    F(4) = vf3_aim_fbits(rd32(a, R(2))); R(2) += 4;
    F(5) = vf3_aim_fbits(rd32(a, R(2))); R(2) += 4;
    F(6) = vf3_aim_fbits(rd32(a, R(2)));
    R(0) = (R(6) << 16) | (R(5) & 0xFFFFu);
    F(4) = fmul(a, F(4), F(7));
    F(5) = fmul(a, F(5), F(7));
    wr32(a, a->gbr + PACK_GBR, R(0));
    F(6) = fmul(a, F(6), F(7));

    R(2) = R(5) & 0xFFu;
    a->fpul = R(2);
    R(5) = (uint32_t)((int32_t)R(5) >> 8);
    F(0) = f2f(a);
    R(1) = OUT;
    R(5) &= 0xFFu;
    a->fpul = R(5);
    F(1) = f2f(a);
    F(0) = fmul(a, F(0), F(6));
    R(5) = sext16(a, R(4)); R(4) += 2;
    R(2) = R(6) & 0xFFu;
    a->fpul = R(2);
    F(2) = f2f(a);
    R(6) = (uint32_t)((int32_t)R(6) >> 8);
    F(1) = fmul(a, F(1), F(5));
    wr32(a, R(1), vf3_aim_ubits(F(0)));
    R(6) &= 0xFFu;
    a->fpul = R(6);
    F(0) = f2f(a);
    R(6) = sext16(a, R(4)); R(4) += 2;
    R(2) = R(5) & 0xFFu;
    F(2) = fmul(a, F(2), F(4));
    R(5) = (uint32_t)((int32_t)R(5) >> 8);
    a->fpul = R(2);
    R(5) &= 0xFFu;
    store_pre(a, 1);
    F(1) = f2f(a);
    a->fpul = R(5);
    F(0) = fmul(a, F(0), F(7));
    store_pre(a, 2);
    R(6) &= 0xFFu;
    F(2) = f2f(a);
    a->fpul = R(6);
    store_pre(a, 0);
    F(0) = f2f(a);
    R(1) += 28;
    F(1) = fmul(a, F(1), F(6));
    F(2) = fmul(a, F(2), F(5));
    F(0) = fmul(a, F(0), F(4));
    wr32(a, R(1), vf3_aim_ubits(F(1)));
    store_pre(a, 2);        /* rts delay slot */
    store_pre(a, 0);
    /* tail-transfer to pr: the C return leaves pr untouched */
}
