/* vertex_writer.c - SH-4 0x8C056AA0 / 0x8C056AE0: the first two TA-vertex
 * writers of the triangle-strip builder, natively.
 *
 * A plain-C transcription of the readable port src/fight/vertex_writers.c
 * (`vf3_vertex_writer0_entry` / `vf3_vertex_writer1_entry`).  Call-free FP
 * leaves with no guest callees and no stack frame - the only control transfer
 * is the final tail transfer to pr.
 *
 * Register-passed helpers: r8 -> the stream record of the strip's first
 * vertex (three s16 per vertex: index, u, v; writer n reads the (u, v) of
 * vertex n), r12 = the store-queue cursor, r6 = the parameter control word,
 * FR3 = the texture scale, and the vertex itself in FR4..FR7 (writer 0) or
 * FR8..FR11 (writer 1).  Each fills one 32-byte TA vertex slot:
 *
 *     +00 r6   +04 x  +08 y  +0C z   +10 u*scale  +14 v*scale  +18 w  +1C 0
 *
 * Writer 0 leaves the cursor where it is (the slot is flushed later by the
 * next writer's PREF); writer 1 flushes the slot at the old cursor and moves
 * the cursor on by one slot.  r0 = 0, r8 is unchanged.
 *
 * The two uv values are s16, converted to float and scaled by FR3 with the
 * FPSCR-aware multiply (rounding = fpscr & 1, FTZ when bit 0x40000).  See
 * docs/re/native_vertex_writer.md. */
#include "vertex_writer.h"
#include "aim_math.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* ---- FPSCR-aware FPU wrappers (as float_blend.c) ---- */
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

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint16_t)((gb(a, addr)[0]) | ((uint16_t)gb(a, addr)[1] << 8)); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }

enum { SLOT = 32, UV_OFFSET_VERTEX0 = 2, UV_OFFSET_VERTEX1 = 8 };

static void write_slot(vf3_native_aim *a, uint32_t slot, uint32_t src_uv,
                       int vertex_fr)
{
    const float scale = F(3);
    const int32_t u = (int16_t)rd16(a, src_uv);
    const int32_t v = (int16_t)rd16(a, src_uv + 2u);
    const float us = fmul(a, (float)u, scale);
    const float vs = fmul(a, (float)v, scale);
    F(2) = us;
    F(1) = vs;
    R(3) = (uint32_t)u;
    a->fpul = (uint32_t)v;

    wr32(a, slot + 12u, vf3_aim_ubits(F(vertex_fr + 2)));
    wr32(a, slot + 8u, vf3_aim_ubits(F(vertex_fr + 1)));
    wr32(a, slot + 4u, vf3_aim_ubits(F(vertex_fr)));
    wr32(a, slot, R(6));
    wr32(a, slot + 20u, vf3_aim_ubits(vs));
    wr32(a, slot + 16u, vf3_aim_ubits(us));
    wr32(a, slot + 24u, vf3_aim_ubits(F(vertex_fr + 3)));
    wr32(a, slot + 28u, 0);
    R(0) = 0;
}

void vf3_native_vertex_writer0(vf3_native_aim *a)
{
    write_slot(a, R(12), R(8) + UV_OFFSET_VERTEX0, 4);
    /* tail-transfer to pr: the C return leaves pr untouched */
}

void vf3_native_vertex_writer1(vf3_native_aim *a)
{
    const uint32_t previous = R(12);
    /* PREF of the previous slot: a store-queue write-back.  Without SQ-model
     * modeling this is a no-op (the readable's vf3_matrix_pref returns
     * immediately when vf3_sq_model is off). */
    write_slot(a, previous + SLOT, R(8) + UV_OFFSET_VERTEX1, 8);
    R(12) = previous + SLOT;
    /* tail-transfer to pr */
}
