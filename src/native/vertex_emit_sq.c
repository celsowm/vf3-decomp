/* vertex_emit_sq.c - SH-4 0x8C048BE0: the store-queue transformed-vertex
 * emitter, natively.
 *
 * A plain-C transcription of the readable port src/fight/vertex_emit.c
 * (`vf3_vertex_emit_sq_entry`).  A call-free FP leaf with no guest callees
 * and no stack frame - the only control transfer is the final tail transfer
 * to pr.
 *
 * `vertex_light` (0x8C048B00) leaves a lit, transformed vertex in registers:
 *
 *     FR4 = w'  FR5 = y'  FR6 = z'  FR7 = 1/x'   FR2 = diffuse  FR3 = specular
 *     r1, r2 = the record's two trailing words (w1, w2)
 *
 * In:  r6 = slot start in the store queue, r5 = input cursor, r3 = vertices
 * left in the strip.  The emitter perspective-scales y',z' by FR7 (the
 * FPSCR-aware multiply), packs the vertex into the 32-byte slot:
 *
 *     +00 ctrl +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
 *
 * and overwrites the control word: the slot address for a vertex inside the
 * strip, or (slot + 0x14) >> 1 (the end-of-strip flag) for the last one.
 *
 * Out: r3-- (T = it reached 0), r2 = (slot + 0x14) >> 1, r5 += 32, r6 one
 * slot on.  The final PREF of the slot is a store-queue write-back - a no-op
 * without SQ modeling.  See docs/re/native_vertex_emit_sq.md. */
#include "vertex_emit_sq.h"
#include "aim_math.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define SLOT_SIZE       32u
#define PCW_VERTEX_EOS  0u   /* not used directly: tail is (slot+0x14)>>1 */

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

static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy((uint8_t *)a->ram + (addr - a->ram_base), &u, 4); }

void vf3_native_vertex_emit_sq(vf3_native_aim *a)
{
    /* perspective-scale y', z' by 1/x' */
    F(6) = fmul(a, F(6), F(7));
    F(5) = fmul(a, F(5), F(7));

    const uint32_t slot = R(6);
    wr32(a, slot + 0x00, vf3_aim_ubits(F(4)));
    wr32(a, slot + 0x04, vf3_aim_ubits(F(5)));
    wr32(a, slot + 0x08, vf3_aim_ubits(F(6)));
    wr32(a, slot + 0x0C, vf3_aim_ubits(F(7)));
    wr32(a, slot + 0x10, R(1));
    wr32(a, slot + 0x14, R(2));
    wr32(a, slot + 0x18, vf3_aim_ubits(F(2)));
    wr32(a, slot + 0x1C, vf3_aim_ubits(F(3)));

    const uint32_t tail = (uint32_t)((int32_t)(slot + 0x14) >> 1);
    const int last = (R(3) - 1u) == 0;
    R(3) -= 1u;
    R(2) = tail;
    wr32(a, slot, last ? tail : slot);
    a->sr = (a->sr & ~1u) | (last ? 1u : 0u);

    R(5) += SLOT_SIZE;
    R(6) = slot + SLOT_SIZE;

    /* PREF of the flushed slot: a store-queue write-back, a no-op without
     * SQ modeling.  Tail-transfer to pr: the C return leaves pr untouched. */
}
