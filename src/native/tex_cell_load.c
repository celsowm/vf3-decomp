/* tex_cell_load.c - SH-4 0x8C07B4D4: the texture-cell loader, natively.
 *
 * A plain-C transcription of the readable port src/fight/sprite_uv.c
 * (`vf3_tex_cell_load_entry`).  A call-free leaf (integer field extraction
 * plus a float / from-int / multiply pipeline; no guest callees, no FPU
 * branch -> the only control transfer is the final rts).  It operates on
 * `vf3_native_aim`: the flat RAM, the FR bank and the register file.
 *
 * `r4` = cell id.  A cell id selects a record from one of two tables: ids
 * with bit 0x4000 set index the six-byte records at 0x0C11ABB0 (u16 id, four
 * byte fields), others the pair table at 0x0C11AA60 (two u16 per entry).
 * The cell's rectangle in texels (x8 as floats) lands at SCRATCH+0..+12, the
 * reciprocal-scaled UV extents at +0x30/+0x34 and +0x38/+0x3C, and the id at
 * 0x0C1B9640.  The reciprocal pair comes from the *id's* pair-table entry.
 *
 * The float pipeline uses the same round-toward-zero + FTZ wrappers (fdiv /
 * fmul) the other FP native ports use, so the stored floats match the guest
 * bit for bit.
 *
 * Register contract: r0 = SCRATCH, r1 = SCRATCH_RECIP_W, r2 = SCRATCH_RECIP_H,
 * r3 = SCRATCH_V, r4 = pw, r5 = ph, FPUL = ph; FR2 = v, FR3 = FR4 = recip_h.
 * SR's T bit is set when the id is not cell-flagged and clear when it is.
 * Tail-transfer to pr (untouched).
 *
 * See docs/re/native_tex_cell_load.md. */
#include "tex_cell_load.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    CELL_RECORDS = 0x0C11ABB0u, CELL_PAIRS = 0x0C11AA60u,
    CELL_FLAG = 0x4000u, CELL_INDEX_MASK = 0x3FFFu,
    SCRATCH = 0x0C1B9620u,
    SCRATCH_RECIP_W = 0x0C1B9630u, SCRATCH_RECIP_H = 0x0C1B9634u,
    SCRATCH_U = 0x0C1B9638u, SCRATCH_V = 0x0C1B963Cu,
    SCRATCH_ID = 0x0C1B9640u
};

/* ---- round-toward-zero FPU wrappers (as sprite_rect_b.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
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
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fdivv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint16_t)((gb(a, addr)[0]) | ((uint16_t)gb(a, addr)[1] << 8)); }
static uint8_t rd8(vf3_native_aim *a, uint32_t addr)
{ return gb(a, addr)[0]; }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ uint32_t u = vf3_aim_ubits(f); memcpy(gb(a, addr), &u, 4); }

static uint32_t u16_shl3(uint32_t v) { return (v & 0xFFFFu) << 3; }

void vf3_native_tex_cell_load(vf3_native_aim *a)
{
    const uint32_t sp = R(15), saved_r14 = R(14), saved_r13 = R(13);
    wr32(a, sp - 4u, saved_r14);          /* dead spills */
    wr32(a, sp - 8u, saved_r13);

    const uint32_t id = R(4) & 0xFFFFu;
    uint32_t first, x, y, w, h, T;
    if (id & CELL_FLAG) {
        const uint32_t rec = CELL_RECORDS + 6u * (id & CELL_INDEX_MASK);
        first = (uint32_t)(int32_t)(int16_t)rd16(a, rec);
        x = rd8(a, rec + 2u);
        y = rd8(a, rec + 3u);
        w = rd8(a, rec + 4u);
        h = rd8(a, rec + 5u);
        T = 0;
    } else {
        const uint32_t pair = CELL_PAIRS + 4u * id;
        first = R(4);
        x = y = 0;
        w = (uint32_t)(int32_t)(int16_t)rd16(a, pair);
        h = (uint32_t)(int32_t)(int16_t)rd16(a, pair + 2u);
        T = 1;
    }
    R(6) = u16_shl3(x);
    R(7) = u16_shl3(y);
    w = u16_shl3(w);
    h = u16_shl3(h);
    a->sr = (a->sr & ~1u) | (T ? 1u : 0u);

    wr32(a, SCRATCH_ID, first & 0xFFFFu);
    wr32f(a, SCRATCH + 0u, (float)(int32_t)R(6));
    wr32f(a, SCRATCH + 4u, (float)(int32_t)R(7));
    wr32f(a, SCRATCH + 8u, (float)(int32_t)w);
    wr32f(a, SCRATCH + 12u, (float)(int32_t)h);

    const uint32_t pair = CELL_PAIRS + 4u * (first & 0xFFFFu);
    const uint32_t pw = u16_shl3((uint32_t)(int32_t)(int16_t)rd16(a, pair)) & 0xFFFFu;
    const uint32_t ph = u16_shl3(rd16(a, pair + 2u)) & 0xFFFFu;
    const float one = 1.0f;
    const float recip_w = fdivv(a, one, (float)(int32_t)pw);
    const float recip_h = fdivv(a, one, (float)(int32_t)ph);
    wr32f(a, SCRATCH_RECIP_W, recip_w);
    wr32f(a, SCRATCH_RECIP_H, recip_h);
    const float u = fmul(a, vf3_aim_fbits(vf3_aim_u32(a, SCRATCH + 8u)), recip_w);
    const float v = fmul(a, vf3_aim_fbits(vf3_aim_u32(a, SCRATCH + 12u)), recip_h);
    wr32f(a, SCRATCH_U, u);
    wr32f(a, SCRATCH_V, v);

    R(1) = SCRATCH_RECIP_W;
    R(2) = SCRATCH_RECIP_H;
    R(3) = SCRATCH_V;
    R(0) = SCRATCH;
    R(4) = pw;
    R(5) = ph;
    a->fpul = ph;
    F(2) = v;
    F(3) = recip_h;
    F(4) = recip_h;
    R(14) = saved_r14;
    R(13) = saved_r13;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
