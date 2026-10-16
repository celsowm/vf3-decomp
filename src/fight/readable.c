/* readable.c - registry and guest-memory helpers for readable ports. */
#include "fight/readable.h"
#include <string.h>

int vf3_task_sched_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_tri_winding_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_cos_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_push_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_quad_node_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_emit_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_emit_ring_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clip_emit_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_strip_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_quad_strip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_concat_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_premul_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_concat_save_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_concat_parent_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_frame_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_frame_c_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clip_edge_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_corner_fan_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sprite_quad_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_display_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_tri_strip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_color_pack_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec3_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define B(r) (1ull << (r))
#define FR(n) B(21 + (n))
#define MATRIX_FP (((1ull << 32) - 1) << 21)
#define MATRIX_XF (((1ull << 16) - 1) << 37)
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
    { 0x0c048600u, "quad_strip", vf3_quad_strip_entry,
      B(0) | B(1) | B(2) | B(4) | B(5) | B(6) | B(9) | B(14) },
    /* FR0..FR15 and XF0..XF15 (v[21..52]) are all defined on exit */
    { 0x0c03b620u, "matrix_store", vf3_matrix_store_entry, B(0) | B(4) },
    { 0x0c03c4f0u, "matrix_push", vf3_matrix_push_entry, B(0) | B(4) | B(17) | MATRIX_XF },
    { 0x0c03c140u, "matrix_concat_save", vf3_matrix_concat_save_entry, B(4) | B(15) | B(18) | MATRIX_FP },
    { 0x0c03c200u, "matrix_concat_parent", vf3_matrix_concat_parent_entry, B(4) | B(15) | B(18) | MATRIX_FP },
    { 0x0c03c4a0u, "matrix_pop", vf3_matrix_pop_entry, B(0) | B(2) | B(3) | B(4) | B(6) | B(7) | B(17) | MATRIX_XF },
#define FRAME_OUT (B(0) | B(2) | B(3) | B(4) | B(6) | B(7) | B(17) | B(18) | MATRIX_FP)
    { 0x0c03d260u, "matrix_frame_a", vf3_matrix_frame_a_entry, FRAME_OUT },
    { 0x0c03d280u, "matrix_frame_b", vf3_matrix_frame_b_entry, FRAME_OUT | B(53) },
    { 0x0c03d2b0u, "matrix_frame_c", vf3_matrix_frame_c_entry, FRAME_OUT },
    { 0x0c03c0e0u, "matrix_concat", vf3_matrix_concat_entry, B(4) | B(15) | B(18) | B(53) | MATRIX_FP },
    { 0x0c03c1c0u, "matrix_premul", vf3_matrix_premul_entry, B(4) | B(15) | MATRIX_FP },
    { 0x0c042c20u, "div_s32", vf3_div_s32_entry, B(0) | B(1) | B(2) | B(3) | B(17) },
    { 0x0c042cd4u, "div_u32", vf3_div_u32_entry, B(0) | B(1) | B(2) | B(17) },
    { 0x0c056b20u, "push_offset", vf3_push_offset_entry, B(0) | B(12) | FR(1) | FR(2) },
    { 0x0c03fb10u, "corner_fan", vf3_corner_fan_entry,
      B(1) | B(3) | B(5) | B(6) | B(7) | B(17) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) |
      FR(6) | FR(7) | FR(8) | FR(9) | FR(10) | FR(11) },
    { 0x0c03f830u, "sprite_quad", vf3_sprite_quad_entry, B(15) | B(16) },
    { 0x0c048260u, "display_list", vf3_display_list_entry, B(4) | B(5) | B(6) },
    { 0x0c0568a0u, "tri_strip", vf3_tri_strip_entry, B(4) | B(12) | B(19) | B(20) },
    { 0x0c03cc90u, "vec3_load", vf3_vec3_load_entry,
      B(0) | B(3) | FR(4) | FR(5) | FR(6) | FR(7) | B(49) | B(50) | B(51) | B(52) },
    { 0x0c03fb80u, "color_pack", vf3_color_pack_entry,
      B(0) | B(1) | B(4) | B(5) | B(6) | B(7) | B(17) | B(53) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) | FR(9) },
    { 0x0c03a140u, "cos_u16", vf3_cos_u16_entry, B(16) | FR(0) },
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
