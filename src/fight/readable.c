/* readable.c - registry and guest-memory helpers for readable ports. */
#include "fight/readable.h"
#include <string.h>

int vf3_task_sched_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_tri_winding_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_quad_node_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_emit_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_emit_ring_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clip_emit_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_strip_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_concat_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_premul_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clip_edge_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define B(r) (1ull << (r))
#define FR(n) B(21 + (n))
#define MATRIX_FP (((1ull << 32) - 1) << 21)
const vf3_readable_entry vf3_readable_table[] = {
    /* callee-saved r12-r14, sp and pr are the whole contract of the scheduler */
    { 0x0c09616au, "task_sched", vf3_task_sched_entry, B(12) | B(13) | B(14) | B(15) | B(16) },
    { 0x0c068f92u, "tri_winding", vf3_tri_winding_entry, B(0) | B(16) },
    { 0x0c068fe4u, "quad_node", vf3_quad_node_entry,
      B(0) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | FR(14) | FR(15) },
    /* FR8..FR10 (specular direction) are inputs the routine leaves untouched */
    { 0x0c048b00u, "vertex_light", vf3_vertex_light_entry,
      B(0) | B(1) | B(2) | B(4) | B(16) | B(17) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) | FR(9) | FR(10) },
    /* r1/r2 are the vertex's trailing words, r2 is rewritten into the strip control word */
    { 0x0c048be0u, "vertex_emit_sq", vf3_vertex_emit_sq_entry,
      B(2) | B(3) | B(5) | B(6) | B(17) | FR(5) | FR(6) },
    { 0x0c048c20u, "vertex_emit_ring", vf3_vertex_emit_ring_entry, B(0) | B(10) },
    { 0x0c048c80u, "clip_emit_slot", vf3_clip_emit_slot_entry,
      B(0) | B(2) | B(5) | B(6) | B(10) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c048cc0u, "clip_edge", vf3_clip_edge_entry,
      B(0) | B(2) | B(5) | B(6) | B(10) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) },
    { 0x0c0487a0u, "strip_light", vf3_strip_light_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(14) },
    /* FR0..FR15 and XF0..XF15 (v[21..52]) are all defined on exit */
    { 0x0c03b620u, "matrix_store", vf3_matrix_store_entry, B(0) | B(4) },
    { 0x0c03c0e0u, "matrix_concat", vf3_matrix_concat_entry, B(4) | B(15) | B(18) | B(53) | MATRIX_FP },
    { 0x0c03c1c0u, "matrix_premul", vf3_matrix_premul_entry, B(4) | B(15) | MATRIX_FP },
    { 0x0c03a6e0u, "sin_u16", vf3_sin_u16_entry,
      B(16) | FR(0) },
};
const unsigned vf3_readable_count = sizeof vf3_readable_table / sizeof vf3_readable_table[0];

const vf3_readable_entry *vf3_readable_find(uint32_t entry)
{
    entry &= 0x1FFFFFFFu;
    for (unsigned i = 0; i < vf3_readable_count; ++i)
        if (vf3_readable_table[i].entry == entry) return &vf3_readable_table[i];
    return NULL;
}

int vf3_readable_override(uint32_t entry, vf3_matrix_state *s,
                          const vf3_ram_map *ram, int *handled)
{
    const vf3_readable_entry *e = vf3_readable_find(entry);
    if (!e) { *handled = 0; return 0; }
    *handled = 1;
    return e->fn(s, ram);
}

uint32_t vf3_mem_u32(const vf3_ram_map *ram, uint32_t a) { return vf3_matrix_read(ram, a, 4); }
uint16_t vf3_mem_u16(const vf3_ram_map *ram, uint32_t a) { return (uint16_t)vf3_matrix_read(ram, a, 2); }
uint8_t vf3_mem_u8(const vf3_ram_map *ram, uint32_t a) { return (uint8_t)vf3_matrix_read(ram, a, 1); }
float vf3_mem_f32(const vf3_ram_map *ram, uint32_t a)
{
    uint32_t b = vf3_matrix_read(ram, a, 4);
    float f;
    memcpy(&f, &b, 4);
    return f;
}
void vf3_mem_set_u32(const vf3_ram_map *ram, uint32_t a, uint32_t v) { vf3_matrix_write(ram, a, v, 4); }
void vf3_mem_set_u16(const vf3_ram_map *ram, uint32_t a, uint16_t v) { vf3_matrix_write(ram, a, v, 2); }
void vf3_mem_set_u8(const vf3_ram_map *ram, uint32_t a, uint8_t v) { vf3_matrix_write(ram, a, v, 1); }
void vf3_mem_set_f32(const vf3_ram_map *ram, uint32_t a, float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    vf3_matrix_write(ram, a, b, 4);
}

int vf3_guest_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                   uint32_t target, uint32_t ret_addr)
{
    s->v[16] = ret_addr;
    if (!vf3_matrix_family(target, s, ram)) return 0;
    return (s->pc & 0x1FFFFFFFu) == (ret_addr & 0x1FFFFFFFu);
}
