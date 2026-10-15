/* vertex_emit.c - transformed-vertex emitters of the strip transformers.
 *
 * vertex_light (0x8C048B00) leaves a lit, transformed vertex in registers:
 *   FR4 = w'  FR5 = y'  FR6 = z'  FR7 = 1/x'   FR2 = diffuse  FR3 = specular
 *   r1, r2 = the record's two trailing words (w1, w2)
 * These emitters pack it into a 32-byte output slot. The code writes the slot
 * backwards with pre-decrementing 64-bit moves (FPSCR.SZ=1 for the duration),
 * so the slot layout, from its low address, is
 *
 *     +00 FR4  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
 *
 * 0x8C048BE0  emit to the store queue at r6 (the vertex goes straight to the
 *             tile accelerator; r6 is advanced a slot, r5 a slot of input).
 * 0x8C048C20  emit into slot (r11 & 3) of the 4-slot ring at 0x0C1A5960 that
 *             the clipping code (0x8C048C40 and friends) reads back.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define SLOT_SIZE      32u
#define RING_BASE      0x0C1A5960u
#define RING_SLOTS_MASK 3u
#define FPSCR_SZ       0x00100000u
#define SQ_REGION_MASK 0xFC000000u
#define SQ_REGION      0xE0000000u

static void put_u32(const vf3_ram_map *ram, uint32_t a, uint32_t v) { vf3_mem_set_u32(ram, a, v); }

/* The slot's eight words, FR4.. first. Returns the slot's low address. */
static uint32_t write_slot(const vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t end)
{
    const uint32_t base = end - SLOT_SIZE;
    put_u32(ram, base + 0x00, VF3_FR(s, 4));
    put_u32(ram, base + 0x04, VF3_FR(s, 5));
    put_u32(ram, base + 0x08, VF3_FR(s, 6));
    put_u32(ram, base + 0x0C, VF3_FR(s, 7));
    put_u32(ram, base + 0x10, s->v[1]);
    put_u32(ram, base + 0x14, s->v[2]);
    put_u32(ram, base + 0x18, VF3_FR(s, 2));
    put_u32(ram, base + 0x1C, VF3_FR(s, 3));
    return base;
}

/* 0x8C048BE0: perspective-scale y',z' and write the vertex into the store queue.
 * In:  r6 = slot start in the store queue, r5 = input cursor,
 *      r3 = vertices left in the strip (decremented; T = it reached 0).
 * Out: r6 += 64 in total, r5 += 32, r3--, r2 = (slot address + 0x14) >> 1,
 *      FR5 and FR6 scaled by FR7.
 * The slot's first word is overwritten with a control word: the slot address
 * itself for a vertex inside the strip, or (slot address + 0x14) >> 1 for the
 * strip's last vertex (that is the end-of-strip flag the TA decodes). */
int vf3_vertex_emit_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;       /* the code assumes SZ=0 on entry */

    vf3_fr_set(s, 6, vf3_f_mul(s, vf3_fr_get(s, 6), vf3_fr_get(s, 7)));
    vf3_fr_set(s, 5, vf3_f_mul(s, vf3_fr_get(s, 5), vf3_fr_get(s, 7)));

    const uint32_t slot = write_slot(s, ram, s->v[6] + SLOT_SIZE);
    const uint32_t tail = (uint32_t)((int32_t)(slot + 0x14) >> 1);
    const int last = (s->v[3] - 1u) == 0;
    s->v[3] -= 1u;
    s->v[2] = tail;
    put_u32(ram, slot, last ? tail : slot);
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~1u) | (last ? 1u : 0u);

    s->v[5] += SLOT_SIZE;
    s->v[6] = slot;
    if ((slot & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, slot);
    s->v[6] = slot + SLOT_SIZE;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* 0x8C048C20: store the vertex in slot (r11 & 3) of the clip ring.
 * Out: r0 = slot * 32, r10 = slot's end address. */
int vf3_vertex_emit_ring_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;

    const uint32_t offset = (s->v[11] & RING_SLOTS_MASK) * SLOT_SIZE;
    const uint32_t end = RING_BASE + SLOT_SIZE + offset;
    write_slot(s, ram, end);
    s->v[0] = offset;
    s->v[10] = end - SLOT_SIZE;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
