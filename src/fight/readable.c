/* readable.c - registry and guest-memory helpers for readable ports. */
#include "fight/readable.h"
#include <string.h>

int vf3_task_sched_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_tri_winding_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_cos_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mod_u32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mod_s32_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
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
int vf3_vertex_writer0_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_writer1_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_color_pack_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec3_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mem_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_tex_cell_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sprite_rect_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sprite_rect_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_glyph_quad_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_pool_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_glyph_cache_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_project_verts_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_format_int_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_rotate_y_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_rotate_z_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_xform_point_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_mem_move_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_rotate_x_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_xform_axis_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_rotate_euler_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_set_translation_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_translate_by_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_rotate_sc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_scale_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_invert_rigid_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_store_keep_translation_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_axis_extract_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_xform_vector_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_transpose_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_invert_scaled_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_world_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_bone_transforms_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_anim_channels_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_flat_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_height_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_printf_core_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_bone_pose_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_body_capsule_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_chain_frames_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_hitbox_overlap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_capsule_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_identity_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_load_wxyz_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_negate_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_edge_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_word_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_div_signed_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_extent_flip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_frame_counter_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_extent_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_text_cursor_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_probe_flip_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_quad_test_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_terrain_plane_hit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_sphere_segment_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_byte_sink_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_pass_prep_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_concat_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_atan_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_unit_triple_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_count_leading_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_scene_link_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_slot_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_node_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_aim_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_point_contact_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_shift_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_pose_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_flush_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_seven_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_slot_scan_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_poly_clip_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_aim_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_aim_frame_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_id_bytes_submit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_classify_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_poly_header_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_fight_tick_driver_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_submit_object_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clip_near_triangle_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_strip_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_joint_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_color_unpack_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_facing_update_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_trampoline_3ecb0_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_trampoline_a7662_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_xf_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec3_sub_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_rotation_xmtrx_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_record_flag40_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_strlen_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_negate_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_float_to_short_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_handler_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_record_run_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_clamp_cell_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_record_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_frame_call_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_offset3_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_call_with_stack_arg_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_scene_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_wall_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_fighter_refresh_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_steer_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_record_sweep_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_segment_delta_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_point_wrap_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_matrix_basis_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_axis_angle_matrix_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_ring_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_lerp21_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_vec_add_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_gate_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_call_seq_da1e_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_atan_turn_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_timecode_digits_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_scaled_vec_add_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_gd_status_wrapper_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_gd_get_cmd_stat_stub_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

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
    { 0x0c095604u, "mem_fill", vf3_mem_fill_entry, B(0) | B(1) | B(2) | B(3) | B(4) | B(6) | B(7) | B(17) },
    { 0x0c07b4d4u, "tex_cell_load", vf3_tex_cell_load_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(7) | B(17) | B(53) | FR(2) | FR(3) | FR(4) },
    { 0x0c07b35cu, "sprite_rect_a", vf3_sprite_rect_a_entry,
      B(0) | B(2) | B(3) | B(5) | B(6) | FR(3) | FR(4) | FR(5) | FR(9) | FR(10) | FR(11) },
    { 0x0c07b398u, "sprite_rect_b", vf3_sprite_rect_b_entry, B(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) },
    { 0x0c0c13c4u, "glyph_quad", vf3_glyph_quad_entry,
      B(0) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | FR(13) | FR(14) | FR(15) },
    { 0x0c07b2beu, "pool_alloc", vf3_pool_alloc_entry,
      B(0) | B(2) | B(3) | B(5) | B(6) | B(7) | B(17) },
    { 0x0c0c1fbau, "glyph_cache", vf3_glyph_cache_entry,
      B(0) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | FR(12) | FR(13) | FR(14) | FR(15) },
    { 0x0c058ea0u, "project_verts", vf3_project_verts_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(17) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) |
      FR(8) | FR(9) | FR(10) | FR(11) | FR(12) | FR(13) | FR(14) | FR(15) },
    { 0x0c04af04u, "format_int", vf3_format_int_entry,
      B(5) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) },
    { 0x0c03c880u, "rotate_y", vf3_rotate_y_entry,
      B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03c940u, "rotate_z", vf3_rotate_z_entry,
      B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03b450u, "xform_point", vf3_xform_point_entry, B(4) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c043018u, "mem_move", vf3_mem_move_entry, B(0) | B(17) },
    { 0x0c03ee40u, "axis_extract", vf3_axis_extract_entry,
      B(0) | B(4) | B(5) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c09d4e6u, "store_keep_translation", vf3_store_keep_translation_entry,
      B(0) | B(3) | B(4) | B(13) | B(14) | B(15) | B(16) | FR(3) },
    { 0x0c03cbd0u, "matrix_set_translation", vf3_matrix_set_translation_entry, B(4) | MATRIX_XF },
    { 0x0c03cc60u, "matrix_translate_by", vf3_matrix_translate_by_entry, FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03c970u, "matrix_rotate_sc", vf3_matrix_rotate_sc_entry,
      FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03cb70u, "matrix_scale", vf3_matrix_scale_entry, B(53) | MATRIX_XF },
    { 0x0c03c5b0u, "matrix_invert_rigid", vf3_matrix_invert_rigid_entry, B(53) | MATRIX_XF },
    { 0x0c03c6c0u, "rotate_x", vf3_rotate_x_entry,
      B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c09d52eu, "xform_axis", vf3_xform_axis_entry,
      B(0) | B(3) | B(4) | B(5) | B(15) | B(16) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c09d480u, "rotate_euler", vf3_rotate_euler_entry,
      B(0) | B(3) | B(4) | B(15) | B(16) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03b4b0u, "xform_vector", vf3_xform_vector_entry, B(4) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c03cc30u, "matrix_transpose", vf3_matrix_transpose_entry, B(53) | MATRIX_XF },
    { 0x0c03b5c0u, "matrix_invert_scaled", vf3_matrix_invert_scaled_entry, B(53) | MATRIX_XF },
    { 0x0c03e980u, "world_reset", vf3_world_reset_entry,
      B(2) | B(3) | B(4) | B(5) | B(15) | B(16) | B(53) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c03e8c0u, "bone_transforms", vf3_bone_transforms_entry,
      B(0) | B(2) | B(3) | B(4) | B(6) | B(7) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | B(53) | FR(4) | FR(5) | FR(6) | FR(7) | MATRIX_XF },
    { 0x0c09d670u, "anim_channels", vf3_anim_channels_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(7) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | MATRIX_FP },
    { 0x0c068d54u, "terrain_wrap", vf3_terrain_wrap_entry,
      B(0) | B(4) },
    { 0x0c068de4u, "terrain_flat", vf3_terrain_flat_entry,
      B(0) | B(17) | FR(0) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c068e0eu, "terrain_height", vf3_terrain_height_entry,
      B(0) | B(2) | B(3) | B(4) | B(5) | B(6) | B(13) | B(14) | B(15) | B(16) | B(17) | B(53) |
      FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) },
    { 0x0c04a6c8u, "printf_core", vf3_printf_core_entry,
      B(0) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) },
    { 0x0c091438u, "bone_pose", vf3_bone_pose_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | B(53) |
      FR(3) | FR(4) | FR(5) | FR(6) | FR(14) | FR(15) | MATRIX_XF },
    { 0x0c06e31cu, "edge_probe", vf3_edge_probe_entry,
      B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) },
    { 0x0c0cc4dcu, "slot_scan", vf3_slot_scan_entry,
      0 },
    { 0x0c09da72u, "seven_pass", vf3_seven_pass_entry,
      0 },
    { 0x0c03ffd0u, "queue_flush", vf3_queue_flush_entry,
      0 },
    { 0x0c091de6u, "pose_blend", vf3_pose_blend_entry,
      B(0)|B(1)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|FR(3)|FR(4)|FR(5) },
    { 0x0c03ecb0u, "trampoline_3ecb0", vf3_trampoline_3ecb0_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0a7662u, "trampoline_a7662", vf3_trampoline_a7662_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c03b820u, "xf_store", vf3_xf_store_entry,
      0 },
    { 0x0c03cee0u, "vec3_sub", vf3_vec3_sub_entry,
      B(4)|B(5)|B(6)|FR(0)|FR(1)|FR(2)|FR(4)|FR(5)|FR(6) },
    { 0x0c03c8b0u, "rotation_xmtrx", vf3_rotation_xmtrx_entry,
      FR(0)|FR(1)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6)|FR(7)|B(37)|B(38)|B(39)|B(40)|B(45)|B(46)|B(47)|B(48) },
    { 0x0c04b9beu, "record_flag40", vf3_record_flag40_entry,
      B(0)|B(17) },
    { 0x0c05342cu, "strlen", vf3_strlen_entry,
      B(0)|B(3)|B(4)|B(5)|B(17) },
    { 0x0c09d408u, "negate_run", vf3_negate_run_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c09d590u, "float_to_short", vf3_float_to_short_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0b1b2eu, "handler_list", vf3_handler_list_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0c1296u, "record_run", vf3_record_run_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c055b28u, "clamp_cell", vf3_clamp_cell_entry,
      B(0)|B(1)|B(4)|B(17) },
    { 0x0c08b5acu, "record_select", vf3_record_select_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0c1208u, "frame_call", vf3_frame_call_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c074702u, "vec_offset", vf3_vec_offset_entry,
      B(0)|B(5)|B(6)|B(17)|FR(2)|FR(3)|FR(4)|FR(5) },
    { 0x0c074854u, "vec_offset3", vf3_vec_offset3_entry,
      B(0)|B(5)|B(6)|B(17)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6) },
    { 0x0c043064u, "call_stack_arg", vf3_call_with_stack_arg_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0a7750u, "scene_slot", vf3_scene_slot_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0ca6c6u, "ring_probe", vf3_ring_probe_entry,
      B(0)|B(4)|B(17) },
    { 0x0c0430a0u, "gd_get_cmd_stat_stub", vf3_gd_get_cmd_stat_stub_entry,
      B(0)|B(2)|B(4)|B(5)|B(6)|B(7)|B(17) },
    { 0x0c0432deu, "gd_status_wrapper", vf3_gd_status_wrapper_entry,
      B(0)|B(4)|B(5)|B(6)|B(17) },
    { 0x0c09302au, "scaled_vec_add", vf3_scaled_vec_add_entry,
      B(0)|B(2)|B(3)|B(4)|B(5)|B(17)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26) },
    { 0x0c0a04dcu, "timecode_digits", vf3_timecode_digits_entry,
      B(0)|B(17)|B(19) },
    { 0x0c039fd0u, "atan_turn", vf3_atan_turn_entry,
      B(0)|B(3)|B(4)|B(5)|B(17)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(53) },
    { 0x0c09da1eu, "call_seq_da1e", vf3_call_seq_da1e_entry,
      B(0)|B(17)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c08b5dau, "gate_dispatch", vf3_gate_dispatch_entry,
      B(0)|B(17) },
    { 0x0c092a70u, "vec_add_pair", vf3_vec_add_pair_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26) },
    { 0x0c09f354u, "vec_lerp21", vf3_vec_lerp21_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32) },
    { 0x0c03c750u, "axis_angle_matrix", vf3_axis_angle_matrix_entry,
      B(0)|B(3)|B(4)|B(5)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c09e4c8u, "matrix_basis", vf3_matrix_basis_entry,
      B(0)|B(17)|B(21)|B(22)|B(23)|B(24)|B(28)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c09f5f8u, "point_wrap", vf3_point_wrap_entry,
      B(0)|B(17)|B(21)|B(22)|B(23)|B(24)|B(31)|B(32) },
    { 0x0c092b4au, "segment_delta", vf3_segment_delta_entry,
      B(0)|B(17) },
    { 0x0c0927e6u, "record_sweep", vf3_record_sweep_entry,
      B(0)|B(17) },
    { 0x0c0c6770u, "steer_flags", vf3_steer_flags_entry,
      B(0)|B(17) },
    { 0x0c0b1550u, "fighter_refresh", vf3_fighter_refresh_entry,
      B(0)|B(17) },
    { 0x0c0cab30u, "wall_flags", vf3_wall_flags_entry,
      B(0)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(34)|B(35)|B(36)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c09dcdcu, "facing_update", vf3_facing_update_entry,
      B(0)|B(1)|B(3)|B(4)|B(5)|B(6)|B(17)|B(53)|FR(0)|FR(1)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6)|FR(7)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0562e0u, "color_unpack", vf3_color_unpack_entry,
      B(0)|B(1)|B(2)|B(4)|B(5)|B(6)|B(53)|FR(0)|FR(1)|FR(2)|FR(4)|FR(5)|FR(6)|FR(7) },
    { 0x0c091c20u, "joint_chain", vf3_joint_chain_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(7)|B(17)|B(53)|FR(4)|FR(5)|FR(6)|FR(13)|FR(14)|FR(15) },
    { 0x0c048f60u, "strip_vertex_lit", vf3_strip_vertex_lit_entry,
      B(0)|B(1)|B(2)|B(3)|B(4)|B(5)|B(6)|B(9)|B(14)|B(17)|B(18)|B(21)|B(22)|B(23)|B(24)|B(25)|B(26)|B(27)|B(28)|B(29)|B(30)|B(31)|B(32)|B(33)|B(34)|B(35)|B(36)|B(53) },
    { 0x0c04a320u, "clip_near_triangle", vf3_clip_near_triangle_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(11) | B(14) | B(17) | B(21) | B(22) | B(23) | B(24) | B(25) | B(26) | B(27) | B(28) | B(29) | B(30) | B(31) | B(32) | B(33) | B(34) | B(35) | B(36) | B(53) },
    { 0x0c055646u, "submit_object", vf3_submit_object_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(7) | B(17) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) | FR(9) | FR(10) | FR(11) },
    { 0x0c055be0u, "fight_tick_driver", vf3_fight_tick_driver_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(7) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | B(18) | B(19) | B(20) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) | FR(9) | FR(10) | FR(11) },
    { 0x0c055e00u, "poly_header_sq", vf3_poly_header_sq_entry,
      B(0) | B(1) | B(2) | B(3) | B(4) | B(5) | B(6) | B(12) | B(17) },
    { 0x0c047ea0u, "vertex_lit", vf3_vertex_lit_entry,
      B(0) | B(1) | B(2) | B(4) | B(17) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(11) },
    { 0x0c048ec0u, "vertex_classify", vf3_vertex_classify_entry,
      B(0) | B(1) | B(4) | B(9) | B(17) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) },
    { 0x0c0a045cu, "id_bytes_submit", vf3_id_bytes_submit_entry,
      B(12) | B(13) | B(14) | B(15) | B(16) },
    { 0x0c09e6b2u, "aim_frame_b", vf3_aim_frame_b_entry,
      B(15) | B(16) },
    { 0x0c09e060u, "aim_frame", vf3_aim_frame_entry,
      B(15) | B(16) },
    { 0x0c0488e0u, "poly_clip_walk", vf3_poly_clip_walk_entry,
      B(0) | B(3) | B(4) | B(5) | B(6) | B(9) | B(10) | B(11) | B(12) | B(15) | B(16) | B(17) },
    { 0x0c0748e0u, "vec_shift", vf3_vec_shift_entry,
      B(0)|B(5)|B(6)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6) },
    { 0x0c09363au, "point_contact", vf3_point_contact_entry,
      0 },
    { 0x0c093768u, "aim_step", vf3_aim_step_entry,
      B(0)|B(3)|B(4)|B(5)|FR(0)|FR(1)|FR(2)|FR(3)|FR(4)|FR(5) },
    { 0x0c0a76ecu, "node_pass", vf3_node_pass_entry,
      B(0)|B(4)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0a756cu, "slot_pass", vf3_slot_pass_entry,
      B(0)|B(4)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c0b1a46u, "scene_link", vf3_scene_link_entry,
      B(0) },
    { 0x0c0769c6u, "count_leading", vf3_count_leading_entry,
      B(0)|B(3)|B(5)|B(6)|B(17) },
    { 0x0c09dc34u, "unit_triple", vf3_unit_triple_entry,
      B(0)|B(2)|B(3)|FR(0)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c069624u, "atan_table", vf3_atan_table_entry,
      B(0)|B(4)|B(53)|FR(2)|FR(3)|FR(6)|FR(7)|FR(8) },
    { 0x0c03dd00u, "matrix_concat_pair", vf3_matrix_concat_pair_entry,
      B(4)|B(5)|FR(0)|FR(1)|FR(2)|FR(3)|FR(4)|FR(5)|FR(6)|FR(7)|FR(8)|FR(9)|FR(10)|FR(11)|B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c09dbc0u, "pass_prep", vf3_pass_prep_entry,
      B(0)|B(4)|
      B(37)|B(38)|B(39)|B(40)|B(41)|B(42)|B(43)|B(44)|B(45)|B(46)|B(47)|B(48)|B(49)|B(50)|B(51)|B(52) },
    { 0x0c04b952u, "byte_sink", vf3_byte_sink_entry,
      B(0) },
    { 0x0c09382au, "sphere_segment", vf3_sphere_segment_entry,
      B(0) },
    { 0x0c0692a6u, "terrain_plane_hit", vf3_terrain_plane_hit_entry,
      B(0)|B(1) },
    { 0x0c068fe4u, "terrain_quad_test", vf3_terrain_quad_test_entry,
      B(0) },
    { 0x0c06911cu, "terrain_probe_flip", vf3_terrain_probe_flip_entry,
      B(0) },
    { 0x0c06938cu, "terrain_probe", vf3_terrain_probe_entry,
      B(0) },
    { 0x0c0c1754u, "text_cursor", vf3_text_cursor_entry,
      B(0)|B(2)|B(3)|B(5)|B(17) },
    { 0x0c0cc432u, "extent_list", vf3_extent_list_entry,
      B(0)|B(17) },
    { 0x0c0cc334u, "frame_counter_step", vf3_frame_counter_step_entry,
      B(0)|B(1)|B(2)|B(3)|B(5)|B(17)|FR(0)|FR(2)|FR(3)|FR(6)|FR(7)|FR(8)|B(53) },
    { 0x0c0cc3f0u, "extent_flip", vf3_extent_flip_entry,
      B(0)|B(2)|B(3)|B(17)|FR(2)|FR(3)|FR(5)|FR(6)|FR(7) },
    { 0x0c042d7cu, "div_signed", vf3_div_signed_entry,
      B(0)|B(17) },
    { 0x0c042f08u, "word_copy", vf3_word_copy_entry,
      B(0) },
    { 0x0c072b02u, "negate_copy", vf3_negate_copy_entry,
      0 },
    { 0x0c073aacu, "hitbox_overlap", vf3_hitbox_overlap_entry,
      B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) },
    { 0x0c071694u, "chain_frames", vf3_chain_frames_entry,
      B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) },
    { 0x0c06f450u, "body_capsule", vf3_body_capsule_entry,
      B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | B(19) |
      FR(12) | FR(13) | FR(14) | FR(15) },
    { 0x0c070008u, "capsule_chain", vf3_capsule_chain_entry,
      B(0) | B(1) | B(7) | B(8) | B(9) | B(10) | B(11) | B(12) | B(13) | B(14) | B(15) | B(16) | B(17) | B(53) |
      FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) | FR(6) | FR(7) | FR(8) | FR(9) | FR(10) | FR(11) | FR(12) | FR(13) | FR(14) | FR(15) },
    { 0x0c03bd80u, "matrix_load", vf3_matrix_load_entry, B(4) | MATRIX_XF },
    { 0x0c03ccb0u, "matrix_identity", vf3_matrix_identity_entry, FR(0) | FR(1) | FR(2) | FR(3) | MATRIX_XF },
    { 0x0c03efb0u, "matrix_load_wxyz", vf3_matrix_load_wxyz_entry, B(4) | MATRIX_XF },
    { 0x0c03b530u, "matrix_copy", vf3_matrix_copy_entry, B(4) | B(5) | B(6) | B(14) | FR(3) | MATRIX_XF },
    { 0x0c03c4a0u, "matrix_pop", vf3_matrix_pop_entry, B(0) | B(2) | B(3) | B(4) | B(6) | B(7) | B(17) | MATRIX_XF },
#define FRAME_OUT (B(0) | B(2) | B(3) | B(4) | B(6) | B(7) | B(17) | B(18) | MATRIX_FP)
    { 0x0c03d260u, "matrix_frame_a", vf3_matrix_frame_a_entry, FRAME_OUT },
    { 0x0c03d280u, "matrix_frame_b", vf3_matrix_frame_b_entry, FRAME_OUT | B(53) },
    { 0x0c03d2b0u, "matrix_frame_c", vf3_matrix_frame_c_entry, FRAME_OUT },
    { 0x0c03c0e0u, "matrix_concat", vf3_matrix_concat_entry, B(4) | B(15) | B(18) | B(53) | MATRIX_FP },
    { 0x0c03c1c0u, "matrix_premul", vf3_matrix_premul_entry, B(4) | B(15) | MATRIX_FP },
    { 0x0c042c20u, "div_s32", vf3_div_s32_entry, B(0) | B(1) | B(2) | B(3) | B(17) },
    { 0x0c042cd4u, "div_u32", vf3_div_u32_entry, B(0) | B(1) | B(2) | B(17) },
    { 0x0c042e44u, "mod_u32", vf3_mod_u32_entry, B(0) | B(1) | B(17) },
    { 0x0c042d7cu, "mod_s32", vf3_mod_s32_entry, B(0) | B(1) | B(17) },
    { 0x0c056b20u, "push_offset", vf3_push_offset_entry, B(0) | B(12) | FR(1) | FR(2) },
    { 0x0c03fb10u, "corner_fan", vf3_corner_fan_entry,
      B(1) | B(3) | B(5) | B(6) | B(7) | B(17) | B(53) | FR(0) | FR(1) | FR(2) | FR(3) | FR(4) | FR(5) |
      FR(6) | FR(7) | FR(8) | FR(9) | FR(10) | FR(11) },
    { 0x0c03f830u, "sprite_quad", vf3_sprite_quad_entry, B(15) | B(16) },
    { 0x0c048260u, "display_list", vf3_display_list_entry, B(4) | B(5) | B(6) },
    { 0x0c0568a0u, "tri_strip", vf3_tri_strip_entry, B(4) | B(12) | B(19) | B(20) },
    { 0x0c056aa0u, "vertex_writer0", vf3_vertex_writer0_entry, B(0) | FR(1) | FR(2) },
    { 0x0c056ae0u, "vertex_writer1", vf3_vertex_writer1_entry, B(0) | B(12) | FR(1) | FR(2) },
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
    s->v[16] = 0x0C000000u | (ret_addr & 0x0FFFFFFFu);   /* the guest keeps its return addresses in the 0x0C form */
    if (!vf3_matrix_family(target, s, ram)) return 0;
    return (s->pc & 0x1FFFFFFFu) == (ret_addr & 0x1FFFFFFFu);
}

/* A tail jump: the callee runs with the caller's own pr exactly as it was (the guest may hold it in the 0x8C form). */
int vf3_guest_tail_call(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t target, uint32_t pr)
{
    s->v[16] = pr;
    if (!vf3_matrix_family(target, s, ram)) return 0;
    return (s->pc & 0x1FFFFFFFu) == (pr & 0x1FFFFFFFu);
}
