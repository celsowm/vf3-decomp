cmake_minimum_required(VERSION 3.20)
project(vf3decomp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vf3core STATIC
    src/fight/mt_play.c
    src/fight/scene_predicate.c
    src/fight/sd_slot_lookup.c
    src/fight/state_index.c
    src/fight/task_run_c.c
    src/media/aica_adpcm.c
    src/media/dtpk.c
    src/media/mt.c
    src/media/pol.c
    src/sys/hal.c
)
target_include_directories(vf3core PUBLIC src)

add_executable(vf3 src/main.c)
target_link_libraries(vf3 PRIVATE vf3core)

add_executable(vf3tool tools/vf3tool.c)
target_link_libraries(vf3tool PRIVATE vf3core)

add_executable(vf3test tests/mt_oracle.c)
