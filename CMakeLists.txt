cmake_minimum_required(VERSION 3.20)
project(vf3decomp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vf3core STATIC
    src/fight/frame.c
    src/fight/frameseq.c
    src/fight/mt_play.c
    src/fight/mt_mount.c
    src/fight/orient2.c
    src/fight/poly_classify.c
    src/fight/mesh_node.c
    src/fight/d0fa.c
    src/fight/c788.c
    src/fight/fvecadd.c
    src/fight/fvecmix.c
    src/fight/fvecmix2.c
    src/fight/fvecnorm070x.c
    src/fight/fvecnorm070a84.c
    src/fight/fvecnorm070120.c
    src/fight/fvecnorm07030c.c
    src/fight/fvecnorm070cf0.c
    src/fight/fvecmix0706c4.c
    src/fight/fvecmix070852.c
    src/fight/fvecmix070832.c
    src/fight/fdivker.c
    src/fight/fpucb.c
    src/fight/af734.c
    src/fight/afb76.c
    src/fight/fminmax.c
    src/fight/tailpath.c
    src/fight/g78044.c
    src/fight/g77e4e.c
    src/fight/f076c00.c
    src/fight/c678e.c
    src/fight/g782ea.c
    src/fight/fvectail.c
    src/fight/fcmpsel.c
    src/fight/scaler3.c
    src/fight/scalemap.c
    src/fight/maplookup.c
    src/fight/tailcall.c
    src/fight/vecpush.c
    src/fight/cntup.c
    src/fight/cbefc.c
    src/fight/f040f1e.c
    src/fight/f0747d8.c
    src/fight/f096258.c
    src/fight/d9ec.c
    src/fight/sh4_matrix.c
    src/fight/sh4_fpu.c
    src/fight/matrix_family.c
    src/fight/matrix_adapters.c
    src/fight/fight_adapters.c
    src/fight/fight_adapters_0.c
    src/fight/fight_adapters_1.c
    src/fight/fight_adapters_2.c
    src/fight/fight_adapters_3.c
    src/fight/fight_helpers.c
    src/fight/motion_adapters.c
    src/fight/motion_helpers.c
    src/fight/motion_adapters_0.c
    src/fight/motion_adapters_1.c
    src/fight/motion_adapters_2.c
    src/fight/motion_adapters_3.c
    src/fight/next_adapters.c
    src/fight/next_adapters_0.c
    src/fight/next_adapters_1.c
    src/fight/next_adapters_2.c
    src/fight/next_adapters_3.c
    src/fight/device_adapters.c
    src/fight/device_adapters_0.c
    src/fight/device_adapters_1.c
    src/fight/fifth_adapters.c
    src/fight/sixth_loader_adapters.c
    src/fight/seventh_adapters.c
    src/fight/seventh_c_adapters.c
    src/fight/seventh_c3_adapters.c
    src/fight/seventh_c4_adapters.c
    src/fight/seventh_c5_adapters.c
    src/fight/seventh_c6_adapters.c
    src/fight/seventh_c7_adapters.c
    src/fight/seventh_c8_adapters.c
    src/fight/seventh_c9_adapters.c
    src/fight/seventh_c10_adapters.c
    src/fight/seventh_c11_adapters.c
    src/fight/seventh_c12_adapters.c
    src/fight/seventh_c13_adapters.c
    src/fight/seventh_c14_adapters.c
    src/fight/eighth_adapters.c
    src/fight/vf3_motion_final_adapter.c
    src/fight/vf3_fifth_leaf_unowned_adapter.c
    src/fight/vf3_motion_unowned_extra_adapter.c
    src/fight/vf3_fifth_leaf_extra_adapter.c
    src/fight/vf3_ultimate_adapter.c
    src/fight/tenpp_asset_adapters.c
    src/fight/tenpp_complex_adapters.c
    src/fight/tenpp_expanded_adapters.c
    src/fight/advance_closure_adapters.c
    src/fight/advance_worker_adapters.c
    src/fight/advance_dynamic_06129c.c
    src/fight/advance_resource_descriptor.c
    src/fight/advance_scene_commands.c
    src/fight/advance_static_helpers.c
    src/fight/advance_controller_adapters.c
    src/fight/advance_render_helpers.c
    src/fight/advance_vector_adapters.c
    src/fight/advance_record_render.c
    src/fight/advance_config_editors.c
    src/fight/advance_client_wrappers.c
    src/fight/advance_state_helpers.c
    src/fight/continuation_input_controls.c
    src/fight/command_encoders.c
    src/fight/task_callback_selectors.c
    src/fight/resource_ranges.c
    src/fight/target_family_adapters.c
    src/fight/target_extra_adapters.c
    src/fight/target_broad_adapters.c
    src/fight/target_extended_adapters.c
    src/fight/target_closure_adapters.c
    src/fight/target_scene_adapters.c
    src/fight/target_remaining_adapters.c
    src/fight/target_retained_scene_adapters.c
    src/fight/target_dependency_adapters.c
    src/fight/target_record_adapters.c
    src/fight/target_configuration_adapters.c
    src/fight/target_action_selector_adapters.c
    src/fight/continuation_allocator_helpers.c
    src/fight/continuation_matrix_adapters.c
    src/fight/advance_small_tail_adapters.c
    src/fight/advance_medium_adapters.c
    src/fight/advance_client_helper_adapters.c
    src/fight/advance_branch_adapters.c
    src/fight/advance_leaf_ranked_more_adapters.c
    src/fight/advance_leaf_041b94_adapters.c
    src/fight/advance_05b20e_adapters.c
    src/fight/tenpp_leaf_adapters.c
    src/fight/tenpp_leaf_adapters_0.c
    src/fight/tenpp_leaf_adapters_1.c
    src/fight/tenpp_leaf_adapters_2.c
    src/fight/tenpp_leaf_adapters_3.c
    src/fight/tenpp_survey_adapters.c
    src/fight/tenpp_survey_adapters_0.c
    src/fight/tenpp_survey_adapters_1.c
    src/fight/tenpp_survey_adapters_2.c
    src/fight/tenpp_survey_adapters_3.c
    src/fight/tenpp_survey_adapters_4.c
    src/fight/vf3_aica_stub_adapter.c
    src/fight/phase1_adapters.c
    src/fight/phase1_adapters_0.c
    src/fight/phase2_adapters.c
    src/fight/phase2_adapters_0.c
    src/fight/fifth_adapters_0.c
    src/fight/fifth_adapters_1.c
    src/fight/fifth_adapters_2.c
    src/fight/fifth_adapters_3.c
    src/fight/fifth_leaf_adapters.c
    src/fight/fifth_leaf_adapters_0.c
    src/fight/fifth_leaf_adapters_1.c
    src/fight/f9f354.c
    src/fight/f9f9a8.c
    src/fight/f9f6fc.c
    src/fight/f9f6dc.c
    src/fight/cc148.c
    src/fight/c5dbe.c
    src/fight/b10aa.c
    src/fight/c6ec4.c
    src/fight/g06f6f8.c
    src/fight/walker.c
    src/fight/walker2.c
    src/fight/scene_predicate.c
    src/fight/sd_slot_lookup.c
    src/fight/state_index.c
    src/fight/task_run_c.c
    src/fight/task_vm.c
    src/media/aica_adpcm.c
    src/media/dtpk.c
    src/media/mt.c
    src/media/pol.c
    src/sys/gdfs.c
    src/sys/hal.c
    src/sys/mainloop.c
    src/lib/sh4rt.c
    src/sys/taskvm.c
    src/sys/soundcmd.c
    src/render/dl.c
)
target_include_directories(vf3core PUBLIC src)
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(src/fight/sh4_fpu.c PROPERTIES
      COMPILE_OPTIONS "-frounding-math;-ffp-contract=off")
  # Explicit ABI control flow is large; algorithm kernels retain Release
  # optimization while adapter builds stay fast enough for batch iteration.
  set_source_files_properties(src/fight/matrix_adapters.c src/fight/fight_adapters.c
      src/fight/fight_adapters_0.c src/fight/fight_adapters_1.c
      src/fight/fight_adapters_2.c src/fight/fight_adapters_3.c
      src/fight/motion_adapters.c src/fight/motion_adapters_0.c
      src/fight/motion_adapters_1.c src/fight/motion_adapters_2.c
      src/fight/motion_adapters_3.c
      src/fight/next_adapters.c src/fight/next_adapters_0.c
      src/fight/next_adapters_1.c src/fight/next_adapters_2.c
      src/fight/next_adapters_3.c
      src/fight/device_adapters.c src/fight/device_adapters_0.c
      src/fight/device_adapters_1.c
      src/fight/fifth_adapters.c
      src/fight/sixth_loader_adapters.c
      src/fight/seventh_adapters.c
      src/fight/seventh_c_adapters.c
      src/fight/seventh_c3_adapters.c
      src/fight/seventh_c4_adapters.c
      src/fight/seventh_c5_adapters.c
      src/fight/seventh_c6_adapters.c
      src/fight/seventh_c7_adapters.c
      src/fight/seventh_c8_adapters.c
      src/fight/seventh_c9_adapters.c
      src/fight/seventh_c10_adapters.c
      src/fight/seventh_c11_adapters.c
      src/fight/seventh_c12_adapters.c
      src/fight/seventh_c13_adapters.c
      src/fight/seventh_c14_adapters.c
      src/fight/eighth_adapters.c
      src/fight/vf3_motion_final_adapter.c
      src/fight/vf3_fifth_leaf_unowned_adapter.c
      src/fight/vf3_motion_unowned_extra_adapter.c
      src/fight/vf3_fifth_leaf_extra_adapter.c
      src/fight/vf3_ultimate_adapter.c
      src/fight/tenpp_asset_adapters.c
      src/fight/tenpp_complex_adapters.c
      src/fight/tenpp_expanded_adapters.c
      src/fight/advance_closure_adapters.c
      src/fight/advance_worker_adapters.c
      src/fight/advance_leaf_ranked_more_adapters.c
      src/fight/tenpp_leaf_adapters.c
      src/fight/tenpp_leaf_adapters_0.c
      src/fight/tenpp_leaf_adapters_1.c
      src/fight/tenpp_leaf_adapters_2.c
      src/fight/tenpp_leaf_adapters_3.c
      src/fight/tenpp_survey_adapters.c
      src/fight/tenpp_survey_adapters_0.c
      src/fight/tenpp_survey_adapters_1.c
      src/fight/tenpp_survey_adapters_2.c
      src/fight/tenpp_survey_adapters_3.c
      src/fight/tenpp_survey_adapters_4.c
      src/fight/vf3_aica_stub_adapter.c
      src/fight/fifth_adapters_0.c
      src/fight/fifth_adapters_1.c
      src/fight/fifth_adapters_2.c
      src/fight/fifth_adapters_3.c
      src/fight/fifth_leaf_adapters.c
      src/fight/fifth_leaf_adapters_0.c
      src/fight/fifth_leaf_adapters_1.c PROPERTIES
      COMPILE_OPTIONS "-O0;-frounding-math;-ffp-contract=off")
endif()

add_executable(vf3 src/main.c)
target_link_libraries(vf3 PRIVATE vf3core)

add_executable(vf3tool tools/vf3tool.c)
target_link_libraries(vf3tool PRIVATE vf3core)

add_executable(vf3test tests/mt_oracle.c)

add_executable(vf3frame tests/frame_replay.c)
target_link_libraries(vf3frame PRIVATE vf3core)

add_executable(vf3vm tests/mt_vm_interp.c)
target_link_libraries(vf3vm PRIVATE vf3core)

add_executable(vf3loop tests/mainloop_replay.c)
target_link_libraries(vf3loop PRIVATE vf3core)

add_executable(vf3libutil tests/libutil_replay.c)
target_link_libraries(vf3libutil PRIVATE vf3core)

add_executable(vf3taskvm tests/taskvm_replay.c)
target_link_libraries(vf3taskvm PRIVATE vf3core)

add_executable(vf3dl tests/dl_replay.c)
target_link_libraries(vf3dl PRIVATE vf3core)

add_executable(vf3walker tests/walker_replay.c)
target_link_libraries(vf3walker PRIVATE vf3core)

add_executable(vf3mtmount tests/mtmount_replay.c)
target_link_libraries(vf3mtmount PRIVATE vf3core)

add_executable(vf3orient2 tests/orient2_replay.c)
target_link_libraries(vf3orient2 PRIVATE vf3core)

add_executable(vf3poly tests/poly_classify_replay.c)
target_link_libraries(vf3poly PRIVATE vf3core)

# Shared oracle .cases runner: add_port_test(<target> <test-source>)
function(add_port_test tname src)
  add_executable(${tname} ${src})
  target_link_libraries(${tname} PRIVATE vf3core)
  target_include_directories(${tname} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)
endfunction()

add_port_test(vf3scalemap tests/scalemap_replay.c)
add_port_test(vf3maplookup tests/maplookup_replay.c)
add_port_test(vf3meshnode tests/mesh_node_replay.c)
add_port_test(vf3d0fa tests/d0fa_replay.c)
add_port_test(vf3c788 tests/c788_replay.c)
add_port_test(vf3tailcall tests/tailcall_replay.c)
add_port_test(vf3walker2 tests/walker2_replay.c)
add_port_test(vf3fvecadd tests/fvecadd_replay.c)
add_port_test(vf3fvectail tests/fvectail_replay.c)
add_port_test(vf3fcmpsel tests/fcmpsel_replay.c)
add_port_test(vf3fdivker tests/fdivker_replay.c)
add_port_test(vf3fpucb tests/fpucb_replay.c)
add_port_test(vf3af734 tests/af734_replay.c)
add_port_test(vf3afb76 tests/afb76_replay.c)
add_port_test(vf3fminmax tests/fminmax_replay.c)
add_port_test(vf3tailpath tests/tailpath_replay.c)
add_port_test(vf3g78044 tests/g78044_replay.c)
add_port_test(vf3g77e4e tests/g77e4e_replay.c)
add_port_test(vf3f076c00 tests/f076c00_replay.c)
add_port_test(vf3c678e tests/c678e_replay.c)
add_port_test(vf3fvecmix2 tests/fvecmix2_replay.c)
add_port_test(vf3fvecnorm070x tests/fvecnorm070x_replay.c)
add_port_test(vf3fvecnorm070a84 tests/fvecnorm070a84_replay.c)
add_port_test(vf3fvecnorm070120 tests/fvecnorm070120_replay.c)
add_port_test(vf3fvecnorm07030c tests/fvecnorm07030c_replay.c)
add_port_test(vf3fvecnorm070cf0 tests/fvecnorm070cf0_replay.c)
add_port_test(vf3fvecmix0706c4 tests/fvecmix0706c4_replay.c)
add_port_test(vf3fvecmix070852 tests/fvecmix070852_replay.c)
add_port_test(vf3fvecmix070832 tests/fvecmix070832_replay.c)
add_port_test(vf3scaler3 tests/scaler3_replay.c)
add_port_test(vf3frameseq tests/frameseq_replay.c)
add_port_test(vf3cntup tests/cntup_replay.c)
add_port_test(vf3cbefc tests/cbefc_replay.c)
add_port_test(vf3f040f1e tests/f040f1e_replay.c)
add_port_test(vf3f0747d8 tests/f0747d8_replay.c)
add_port_test(vf3f096258 tests/f096258_replay.c)
add_port_test(vf3fd9ec tests/d9ec_replay.c)
add_port_test(vf3matrix tests/matrix_kernel_replay.c)
add_port_test(vf3fpu tests/sh4_fpu_replay.c)
add_port_test(vf3matrixfamily tests/matrix_family_replay.c)
add_port_test(vf3statehelpers tests/state_helpers_replay.c)
add_port_test(vf3d452 tests/d452_replay.c)
add_port_test(vf3bootmix tests/bootmix_helper_replay.c)
add_port_test(vf3f9f9a8 tests/f9f9a8_replay.c)
add_port_test(vf3f9f354 tests/f9f354_replay.c)
add_port_test(vf3f9f6fc tests/f9f6fc_replay.c)
add_port_test(vf3f9f6dc tests/f9f6dc_replay.c)
add_port_test(vf3cc148 tests/cc148_replay.c)
add_port_test(vf3c5dbe tests/c5dbe_replay.c)
add_port_test(vf3b10aa tests/b10aa_replay.c)
add_port_test(vf3c6ec4 tests/c6ec4_replay.c)
add_port_test(vf3g06f6f8 tests/g06f6f8_replay.c)
add_port_test(vf3g782ea tests/g782ea_replay.c)

add_executable(vf3vecpush tests/vecpush_replay.c)
target_link_libraries(vf3vecpush PRIVATE vf3core)
