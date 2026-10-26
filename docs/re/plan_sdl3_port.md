# Plan: the SDL3 native port (2026-10-26)

Decision taken 2026-10-26, after the oracle recovery:

* **Rendering**: we write our own PVR2 model (TA decoder + rasterizer).  The
  native tick already captures the game's TA FIFO word stream, so the model
  consumes real command streams rather than a guess.
* **First milestone**: one rendered fight frame, diffed pixel-wise against the
  reference frame the emulator produces.
* **Start point**: a savestate, not the disc.  The loader path comes later.

## Where the ground truth stands today

| piece | state |
|---|---|
| game logic in C | ported - 2,398 baseline functions, `src/fight/**` |
| native tick harness | works - `build/vf3 <tick-capture> --ticks N`, 13 fight states |
| TA FIFO capture | works - `machine.ta[]`, dumped with `--ta-out` |
| AICA register model | works - the fight audio modules drive `0xA05F8000` |
| GD-ROM service model | works - `src/sys/gdrom_hle.c` |
| Maple (controller bus) | works - `src/sys/maple_hle.c` |
| BIOS syscalls, GDFS | works - `src/sys/bios_syscall.c`, `src/sys/gdfs.c` |
| **PVR2 (TA + rasterizer)** | **missing** |
| **AICA PCM output** | **missing** (commands only) |
| **frame loop / interrupts** | **missing** (one tick per process) |
| **input from a host** | **missing** (Maple has no host side) |
| tick captures (`golden_tickx_vf3_*.bin`) | **gone** with the artefact bundle |
| Katana / KAMUI SDKs, `refs/dream-recomp` | **gone** (gitignored trees) |
| SDL3 3.4.16 | installed in MSYS2 `ucrt64` (our compiler) |

The two "gone" rows matter: the SDKs were the reference for the TA command
layout, and `refs/dream-recomp` was the 100 %-coverage scaffold.  Both are
re-downloadable; the Katana/KAMUI SDK is what the game itself was built
against, and it defines the TA command structs.

## Architecture

```
  SDL3 host  (src/host/**)        window, events, audio stream, gamepad
        |
  machine (src/fight/native_tick.c + src/sys/**)
        |      game code (ported C), GD/Maple/BIOS models, TA + AICA sinks
        v
  platform models (src/render/**)  PVR2: TA decode -> raster -> framebuffer
                                   AICA: registers -> PCM -> SDL3 audio
```

The host owns no game logic.  The game code keeps talking to the Dreamcast's
addresses; the models intercept the regions it writes to (the TA area
`0x10000000-0x14000000`, the AICA registers `0xA05F8000`), exactly as the
native tick already does for the TA.

## The phases

### P0 - SDL3 skeleton
`src/host/sdl3_host.c`: SDL3 init, a window, an event loop, `--dump-frame
FILE` so the app can run without a display.  CMake option `VF3_SDL3=ON`
builds the `vf3sdl` target against the MSYS2 `ucrt64` SDL3.
*Done (2026-10-26)*: SDL3 3.4.16 installed (`pacman -S
mingw-w64-ucrt-x86_64-sdl3`); `src/render/pvr2.{c,h}` (the model's shape and
the TA word histogram) and `src/host/sdl3_host.c` (the host) added;
`vf3sdl.exe` builds and runs - it loads a state, runs the tick, feeds the TA
stream to the model and writes a 640x480 PPM frame.

### P1 - a machine state the port can load
The tick captures are gone, so the port needs its own state input.  Two
options, in order of cost:
1. **the emulator writes it**: upstream Flycast (built with the SDL3 we just
   installed) gets two small patches - dump the machine state (RAM, registers,
   VRAM) and dump the rendered frame - so one run produces both the port's
   input and the reference image, frame-aligned by construction;
2. **the port reads the savestate**: Flycast's savestate format carries the
   RAM, the registers and the VRAM, so a reader in the port gives the state
   *and* a free reference frame (the last frame the emulator drew), at the
   cost of exact frame alignment.
*Verification*: the loaded state reproduces the tick's entry registers.

*Status (2026-10-26)*: option 1's build works - `tools/emu/flycast-ref-build/
flycast.exe` is a MinGW/ucrt64 build of upstream Flycast with SDL3, OpenGL
only.  The state format the port reads is known (64-bit records: the marker
`0xFA30` with a non-zero high half carries the 37 entry registers, `0xFA50`
the RAM windows as `<count>`, `<base>`, `<len>` and `len/4` words), so the
dump patch writes exactly that.

*Status (2026-10-26, later)*: option 1 is done.  `tools/refemu/vf3dump.c`
(ours) writes that recording - the 37 registers, the XF bank and one 16 MiB
window at `0x0C000000`, which is exactly the window the port expects - and
counts how often each instruction of the game image runs.  Upstream's own
`TEST_AUTOMATION` hook writes every rendered frame raw, so one run produces
the state and the reference frames together.  The two hooks and the two
configuration traps are in `docs/re/patches/reference_frame_dump.md` and
`docs/re/p1_reference_frames.md`.

The finding that unblocked the phase: **the observer's guest is stalled by the
observer's own patches**, not by the savestate.  The v3 observer sits in the
GD exec-server wrapper and never reaches the frame loop, while a pristine
Flycast plays the same savestate - the attract screen, then the demo fight.
Only synthetic captures ever noticed, because a probe needs the guest to reach
the probe, not to run on its own.

### P2 - the frame loop
One scheduler tick (`0x8C09616A`) per frame, plus the vblank handler and the
timers, in a loop with a clock.  The pieces exist: `src/fight/native_tick.c`
(the tick), `src/fight/frame.c` (the six-slot per-frame ladder), `src/boot_sim.c`
(the vblank pair).
*Verification*: the RAM after N frames matches the oracle's tick captures;
the divergence the multi-tick probe already reports (3 ticks clean, tick 114
of state 7 hits an unowned entry) is the coverage ledger for P7.

### P3 - the PVR2 model
`src/render/pvr2.c`: a TA command decoder and a rasterizer.
*Scope is not guessed*: the game's TA word stream is captured, so the set of
commands the game actually emits is a finite list, and the SDK headers
(re-downloadable) give their layout.  The rasterizer needs the primitives,
the texture formats and the blending the game uses - again visible in the
stream.
*Verification*: the rasterized frame is diffed against the reference frame;
the first target is "the framebuffer in the savestate's VRAM looks like ours"
(loose), then pixel-exactness against the aligned reference.

### P4 - the reference frame and the diff
The emulator-side dump (P1) plus `tools/pvr2_frame_diff.py`: same size, the
fraction of pixels within +/-1 per channel, and the first differing pixel.
*Verification*: the tool reports the mismatch count for a known-good pair
(the emulator's own frame dumped twice) as 0.
*Status (2026-10-26)*: the tool is written and its self-test passes (0 of
307,200 pixels differ for the same frame twice).  The reference frames
themselves are real: the emulator's raw video holds VF3tb's "Press Start
Button" attract screen and the demo fight.

### P5 - audio
The AICA model already records the commands; add the PCM generator (the
channel mixer, ADPCM, the stereo FIFO) and feed an SDL3 audio stream.
*Verification*: the oracle's recorded audio checkpoints (we have eight, in the
release) are the reference PCM - the same diff tool, in samples.

### P6 - input
SDL3 gamepad -> the Maple/ADX packet the game reads (the Maple model exists).
*Verification*: the captured controller state in the oracle's capsules.

### P7 - boot from the disc
The loader path: `gdrom_hle` + `gdfs` + the boot wait loop (`boot_sim.c`).
The disc is in `rom/`.

### P8 - coverage closure
The native tick's call-target table covers the entries the 13 captured ticks
executed.  The full game needs the rest: the repo's own translator
(`tools/oracle/translate_adapters.py`) can generate a module for any entry
from the image - the gap batch proved it on 237 bodies - and the static
recompiler (re-downloadable) is the 100 %-coverage reference.

## Risks

* **The PVR2 subset is bigger than expected.**  Mitigation: the TA stream is
  captured, so the scope is measurable before it is written.  Fallback: render
  the subset and leave the rest as a documented gap (the frame diff shows
  exactly which lanes are missing).
* **The emulator build.**  Upstream Flycast with MinGW is not its usual
  configuration; if it fails, fall back to the MSVC/Clang path or to the
  savestate reader (P1 option 2), which needs no emulator build at all.
* **Coverage gaps in the native path** (the unowned entries) - P8's problem,
  and the same translator that produced the gap batch can close them.
* **Licence**: our own PVR2 model keeps the port clean; Flycast stays in
  `tools/emu/` (gitignored) and is only a reference and a measurement tool.

## Immediate next steps

1. `src/host/sdl3_host.c` + the `vf3sdl` CMake target (P0).
2. Build upstream Flycast with the state/frame dump patches (P1 option 1), and
   in parallel read the savestate format for the fallback.
3. Dump a real tick's TA stream and list the PVR2 commands the game emits -
   that list is the PVR2 model's scope (P3).
