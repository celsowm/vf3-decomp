/* vertex_emit.c - SH-4 0x8C048C20: the clip-ring transformed-vertex emitter,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/vertex_emit.c
 * (`vf3_vertex_emit_ring_entry`).  A call-free integer leaf: no FPU
 * arithmetic, no guest callees, no stack frame and no device access - the
 * only control transfer is the final tail transfer to pr.
 *
 * `vertex_light` (0x8C048B00) leaves a lit, transformed vertex in registers:
 *
 *     FR4 = w'  FR5 = y'  FR6 = z'  FR7 = 1/x'   FR2 = diffuse  FR3 = specular
 *     r1, r2 = the record's two trailing words (w1, w2)
 *
 * This emitter packs it into one 32-byte slot of the 4-slot ring at
 * 0x0C1A5960, chosen by (r11 & 3):
 *
 *     +00 FR4  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
 *
 * It leaves r0 = offset (slot * 32) and r10 = the slot's low address.  The
 * readable guards the FPSCR's SZ bit (the code assumes SZ=0 on entry); a
 * rejected FPSCR is a dispatcher concern, not a port concern here.  See
 * docs/re/native_vertex_emit.md. */
#include "vertex_emit.h"
#include "aim_math.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define SLOT_SIZE       32u
#define RING_BASE       0x0C1A5960u
#define RING_SLOTS_MASK 3u

static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy((uint8_t *)a->ram + (addr - a->ram_base), &u, 4); }

void vf3_native_vertex_emit_ring(vf3_native_aim *a)
{
    const uint32_t offset = (R(11) & RING_SLOTS_MASK) * SLOT_SIZE;
    const uint32_t base = RING_BASE + offset;

    wr32(a, base + 0x00, vf3_aim_ubits(F(4)));
    wr32(a, base + 0x04, vf3_aim_ubits(F(5)));
    wr32(a, base + 0x08, vf3_aim_ubits(F(6)));
    wr32(a, base + 0x0C, vf3_aim_ubits(F(7)));
    wr32(a, base + 0x10, R(1));
    wr32(a, base + 0x14, R(2));
    wr32(a, base + 0x18, vf3_aim_ubits(F(2)));
    wr32(a, base + 0x1C, vf3_aim_ubits(F(3)));

    R(0) = offset;
    R(10) = base;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
