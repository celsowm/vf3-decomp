cmake_minimum_required(VERSION 3.20)
project(vf3decomp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(vf3
    src/main.c
    src/sys/hal.c
)
target_include_directories(vf3 PRIVATE src)
