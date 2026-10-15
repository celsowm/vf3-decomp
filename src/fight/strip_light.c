/* strip_light.c - transform, light and emit one strip of vertices, SH-4 0x8C0487A0.
 *
 * The strip transformer with the per-vertex routine (vertex_light.c) and the store-queue
 * emitter (vertex_emit.c) inlined and software-pipelined: while vertex i is being
 * written, vertex i+1 is already being fetched.
 *
 * In:  r4 = strip: { u32 count; vertex records... } then a trailer { u32 flags; u32 count; }
 *           with the next strip's first record right behind it
 *      r5 = output cursor (advanced 32 per vertex)
 *      r6 = start of the store-queue area; each vertex takes one 32-byte slot
 *      r8 = specular selector (0 = none), XMTRX, FV12 / FV8 lights, as in vertex_light.c
 * Out: r4 = the trailer, r5, r6 = end of the last slot, r14, r3 = the trailer's count word.
 *
 * Slot layout (the TA vertex parameter): the first word is the parameter control word,
 *   0xE0.. (any address in the SQ window: "vertex") for a vertex inside the strip and
 *   0xFFFFFFFF ("vertex, end of strip") for the last one; then
 *     +04 y'/x'   +08 z'/x'   +0C 1/x'   +10 w1   +14 w2   +18 diffuse   +1C specular
 * Each slot is flushed with PREF. The trailer's flags word chains strips:
 *   flags <= 0 (signed) or bit 0x80 clear: stop, otherwise a new strip starts at
 *   trailer + 8 and the output carries on in the following slots.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vertex_light.h"

#define SLOT_SIZE        32u
#define TRAILER_SIZE      8u
#define STRIP_CHAIN_FLAG 0x80u
#define PCW_VERTEX_EOS   0xFFFFFFFFu
#define FPSCR_SZ         0x00100000u
#define SQ_REGION_MASK   0xFC000000u
#define SQ_REGION        0xE0000000u

enum { SLOT_CTRL = 0x00, SLOT_Y = 0x04, SLOT_Z = 0x08, SLOT_INV = 0x0C,
       SLOT_W1 = 0x10, SLOT_W2 = 0x14, SLOT_DIFFUSE = 0x18, SLOT_SPECULAR = 0x1C };

int vf3_strip_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;
    const int32_t selector = (int32_t)s->v[8];
    if (selector < 0) return 0;                        /* this path jumps into the table with a bad index */

    uint32_t cursor = s->v[4];
    uint32_t count = vf3_mem_u32(ram, cursor);
    cursor += 4;
    uint32_t slot = s->v[6];                           /* low address of the slot being written */
    uint32_t next, body = vf3_vertex_locate(ram, cursor, &next);
    cursor = next;

    uint32_t trailer, flags = 0, w2 = 0;
    vf3_lit_vertex lv = { 0 };
    for (;;) {
        if (!vf3_light_vertex(s, ram, body, selector, 1, &lv)) return 0;
        s->v[5] += SLOT_SIZE;
        w2 = lv.w2;
        --count;

        const int last = count == 0;
        if (last) {
            trailer = cursor;                          /* the original has already stepped r4 past it */
        } else {
            body = vf3_vertex_locate(ram, cursor, &next);
            cursor = next;
        }

        const float inv = lv.inv_depth;
        vf3_mem_set_f32(ram, slot + SLOT_SPECULAR, lv.specular);
        vf3_mem_set_f32(ram, slot + SLOT_DIFFUSE, lv.intensity);
        vf3_mem_set_u32(ram, slot + SLOT_W2, lv.w2);
        vf3_mem_set_u32(ram, slot + SLOT_W1, lv.w1);
        vf3_mem_set_f32(ram, slot + SLOT_INV, inv);
        vf3_mem_set_f32(ram, slot + SLOT_Z, vf3_f_mul(s, vf3_bits_f32(lv.z), inv));
        vf3_mem_set_f32(ram, slot + SLOT_Y, vf3_f_mul(s, vf3_bits_f32(lv.y), inv));
        vf3_mem_set_u32(ram, slot + SLOT_CTRL, lv.depth);
        if (!last) {
            vf3_mem_set_u32(ram, slot, slot);          /* control word: the slot's own address */
            if ((slot & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, slot);
            slot += SLOT_SIZE;
            continue;
        }

        vf3_mem_set_u32(ram, slot, PCW_VERTEX_EOS);
        if ((slot & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, slot);
        slot += SLOT_SIZE;
        flags = vf3_mem_u32(ram, trailer);
        if ((int32_t)flags <= 0) { s->v[3] = count; s->v[14] = trailer + 4; break; }
        count = vf3_mem_u32(ram, trailer + 4);
        s->v[3] = count;
        s->v[14] = trailer + TRAILER_SIZE;
        if (!(flags & STRIP_CHAIN_FLAG)) break;
        body = vf3_vertex_locate(ram, trailer + TRAILER_SIZE, &next);
        cursor = next;
    }

    s->v[0] = flags;
    s->v[1] = PCW_VERTEX_EOS;
    s->v[2] = w2;
    s->v[4] = trailer;
    s->v[6] = slot;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
