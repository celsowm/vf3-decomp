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
add_port_test(vf3scaler3 tests/scaler3_replay.c)
add_port_test(vf3frameseq tests/frameseq_replay.c)
add_port_test(vf3cntup tests/cntup_replay.c)
add_port_test(vf3cbefc tests/cbefc_replay.c)
add_port_test(vf3f040f1e tests/f040f1e_replay.c)
add_port_test(vf3f0747d8 tests/f0747d8_replay.c)
add_port_test(vf3f096258 tests/f096258_replay.c)
add_port_test(vf3fd9ec tests/d9ec_replay.c)
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
