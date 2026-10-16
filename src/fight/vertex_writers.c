/* vertex_writers.c - the first two vertex writers of the triangle-strip builder (tri_strip.c).
 *
 *   0x8C056AA0  writer 0: the first vertex of a strip, written in place at the cursor
 *   0x8C056AE0  writer 1: the second vertex, in the slot behind it
 *   (0x8C056B20, writer 2 = push_offset in geom_readable.c, writes the third vertex)
 *
 * Register-passed helpers: r8 -> the stream record of the strip's first vertex (three s16 per
 * vertex: index, u, v; writer n reads the (u, v) of vertex n), r12 = store-queue cursor,
 * r6 = parameter control word, FR3 = texture scale, and the vertex itself in FR4..FR7 (writer 0)
 * or FR8..FR11 (writer 1). Each fills one 32 byte TA vertex slot:
 *     +00 r6   +04 x  +08 y  +0C z   +10 u*scale  +14 v*scale  +18 w  +1C 0
 * Writer 0 leaves the cursor where it is (the slot is flushed later by the next writer's PREF),
 * writer 1 flushes the slot at the old cursor and moves the cursor on by one slot. r0 = 0, r8 is
 * unchanged. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum { SLOT = 32, UV_OFFSET_VERTEX0 = 2, UV_OFFSET_VERTEX1 = 8 };

static void write_slot(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t slot,
                       uint32_t src_uv, int vertex_fr)
{
    const float scale = vf3_fr_get(s, 3);
    const int32_t u = (int16_t)vf3_mem_u16(ram, src_uv);
    const int32_t v = (int16_t)vf3_mem_u16(ram, src_uv + 2u);
    const float us = vf3_f_mul(s, vf3_f_from_int(s, u), scale);
    const float vs = vf3_f_mul(s, vf3_f_from_int(s, v), scale);
    vf3_fr_set(s, 2, us);
    vf3_fr_set(s, 1, vs);
    s->v[3] = (uint32_t)u;
    s->v[VF3_REG_FPUL] = (uint32_t)v;

    vf3_mem_set_u32(ram, slot + 12u, VF3_FR(s, vertex_fr + 2));
    vf3_mem_set_u32(ram, slot + 8u, VF3_FR(s, vertex_fr + 1));
    vf3_mem_set_u32(ram, slot + 4u, VF3_FR(s, vertex_fr));
    vf3_mem_set_u32(ram, slot, s->v[6]);
    vf3_mem_set_u32(ram, slot + 20u, vf3_f32_bits(vs));
    vf3_mem_set_u32(ram, slot + 16u, vf3_f32_bits(us));
    vf3_mem_set_u32(ram, slot + 24u, VF3_FR(s, vertex_fr + 3));
    vf3_mem_set_u32(ram, slot + 28u, 0);
    s->v[0] = 0;
}

int vf3_vertex_writer0_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    write_slot(s, ram, s->v[12], s->v[8] + UV_OFFSET_VERTEX0, 4);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_vertex_writer1_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t previous = s->v[12];
    vf3_matrix_pref(ram, previous);
    write_slot(s, ram, previous + SLOT, s->v[8] + UV_OFFSET_VERTEX1, 8);
    s->v[12] = previous + SLOT;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
