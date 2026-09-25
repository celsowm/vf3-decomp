cmake_minimum_required(VERSION 3.20)
project(vf3decomp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vf3core STATIC
    src/fight/frame.c
    src/fight/mt_play.c
    src/fight/mt_mount.c
    src/fight/orient2.c
    src/fight/poly_classify.c
    src/fight/walker.c
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
