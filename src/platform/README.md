# SDL3 host platform

This library is the host boundary for the planned native VF3tb runtime. It does not run the game, emulate SH-4, decode PVR lists or mix AICA audio.

Build with `-DVF3_BUILD_SDL3=ON` and an installed SDL3 CMake package (3.2 or later). `vf3platform` links `SDL3::SDL3`; the core remains usable without SDL. `vf3platform-smoke --frames 120` displays a generated diagnostic pattern. `ctest --test-dir build -R '^platform_' --output-on-failure` tests the dummy video/software renderer and virtual gamepads without game assets.

The main-thread API in `sdl_platform.h` owns a window, renderer and streaming texture. `vf3_platform_poll` drains SDL events, returns two `vf3_maple_pad` states and signals quit. `vf3_platform_present` accepts exactly 640×480 native `uint32_t` ARGB8888 pixels with byte pitch; resizing uses 4:3 letterboxing and nearest-neighbor sampling. Monotonic nanosecond clock and sleep helpers do not advance game simulation.

| Input | Player 1 | Player 2 |
|---|---|---|
| Direction | Arrow keys | I / K / J / L |
| Dreamcast A / B / X / Y | Z / X / A / S | V / B / F / G |
| Start | Enter | Right Shift |
| Quit | Escape or window close | Escape or window close |

Gamepad south/east/west/north positions map to Dreamcast A/B/X/Y. D-pad, two sticks and triggers are converted to the active-low Maple representation. Slots remain stable when one controller disconnects. Focus loss clears keyboard input and neutralizes both pads. The pure conversion layer imposes no deadzone; calibration is a later frontend concern.

The current `src/sys/maple_hle.c` still models one controller port, and the boot harness supplies a fixed pad. Runtime integration must consume the host states at the original Maple sampling boundary and add second-port responses. Merely returning two host pads does not implement two-player gameplay.

Audio output, persistent settings, remapping UI and a game renderer are future work tracked in `docs/PC_PORT_PLAN.md`. Do not use the synthetic smoke pattern as evidence of game graphics or fidelity.
