# P1: reference frames and a state the port can load

Phase P1 of `docs/re/plan_sdl3_port.md` asks for two things: a *reference frame*
to diff the port's rendering against, and a *machine state* the port can start
from.  Both now exist.  This note records how, what was wrong on the way, and
what is still open.

## The reference emulator

`tools/emu/flycast` is upstream Flycast (`e88b0ced`) plus the two hooks
described in `docs/re/patches/reference_frame_dump.md`, and the instrument
itself is ours (`tools/refemu/vf3dump.c`):

1. Upstream's `TEST_AUTOMATION` input-replay code does not compile on
   Windows: it compares a 64-bit signed value with a `long` in one `std::max`
   call, and `long` is 32 bits there, so the overload does not resolve.  The
   fix is one explicit template argument.

2. `tools/refemu/vf3dump.c` (new, ours) - two instruments, both driven by the
   environment:
   * `VF3_DUMP_STATE=<file>`, `VF3_DUMP_PC=<pc>`, `VF3_DUMP_SKIP=<n>` - write
     the SH-4 machine state at a guest PC, in the *port's own recording
     format* (see `src/fight/native_tick.c`): a `0xFA30` marker with 37
     registers, a `0xFA70` marker with the XF bank, and a `0xFA50` marker with
     one 16 MiB window at `0x0C000000`.  Flycast's Dreamcast RAM is 16 MiB
     (`settings.platform.ram_size`), which is exactly the window the port
     expects (`VF3_NATIVE_RAM_LEN`).
   * `VF3_HITS=<file>` - how often each instruction of the game image is
     executed.  The observer has the same instrument, but see below.

3. One call per instruction into the above, from the interpreter's loop.

The reference frames come from upstream's own `TEST_AUTOMATION` hook
(`core/rend/gles/gles.cpp`): with `-DTEST_AUTOMATION=ON` the renderer writes
every swapped frame to `config::loadStr("record", "rawvid")` as raw RGB, and
`core/input/gamepad_device.cpp` can replay a recorded input script
(`scripts/<rom>input`, `record:replay_input=1`).

## Two configuration traps

Both cost hours, so they are written down:

* **Flycast's `Option<>` values live in the `[config]` section, keyed by the
  option's full name.**  `Option<bool> DynarecEnabled("Dynarec.Enabled", true)`
  is read from `[config] Dynarec.Enabled=0`, *not* from `[Dynarec] Enabled=0`.
  The latter parses and is silently ignored, so the emulator kept using the
  dynamic recompiler (and never auto-loaded the savestate).  Values read
  directly with `config::loadStr("record", "rawvid")` do use the section they
  name - the two kinds coexist.* **The ini file is read from the exe directory when the user config
  directory has none.**  `core/linux-dist/main.cpp` resolves the config dir
  from `$XDG_CONFIG_HOME` / `$HOME`; with neither set it falls back to `.`,
  and `config::open()` then falls back to the *system* config dirs, which
  include the exe directory.  So `tools/emu/flycast-ref-build/emu.cfg` is the
  file that is read, and the data directory is the same place's `data/`.

## The observer's guest is broken; the reference build's is not

This is the finding that unlocked the phase.

The recovered v3 observer (`tools/emu/flycast-build/flycast_v3.exe`) loads the
six surviving savestates and runs them, but its guest *stalls*: the hits probe
counts 14,724 executions of `0x8C0434D0` - the return address of
`0x8C0434C8`, the game's GD exec-server wrapper (`src/fight/gd_syscall_stub.c`)
- in 240 frames, and **zero** executions of the game's frame loop.  A disc
  boot stalls the same way: 6,000 frames and not one hit on the BIOS vectors,
let alone on the game.

The same savestate in a pristine Flycast runs the game.  From `vf3_26.state`
the emulator reaches VF3tb's "Press Start Button" attract screen within a
second and, two minutes later, the **demo fight** - a fully rendered fight
frame with two characters, the stage, the HUD and the Am2D logo.

So the stall is in the observer's own patches, not in the state and not in the
disc.  That also explains why only *synthetic* captures ever worked: the
observer's probe machinery redirects a call and captures the specimen, which
needs the guest to reach the probe, not to run on its own.  The disc boot
stalling in the observer is the same failure.

The consequence for the port: **the state has to come from the reference
build**, and the reference build is where the reference frames come from too -
one run produces both, which is what makes the frame and the state
frame-aligned.

## The savestates we have

| state | what the reference build shows |
|-------|-------------------------------|
| `vf3_26.state` | the game running: "Press Start Button" attract screen, then the demo fight |
| `vf3_27/28/29/45/46.state` | the Dreamcast boot logo - the game has not loaded yet |

Only `vf3_26.state` is in the game.  The other five are early enough that
the loader is still reading the disc, which is exactly what the observer's
exec-server stall was showing.

## The frame diff

`tools/pvr2_frame_diff.py` compares two frames pixel by pixel (binary PPM or
a raw RGB dump) and reports the number of differing pixels, the largest
channel error and the first differing pixel; it can write a difference image.
Its self-test is the same frame twice: 0 of 307,200 pixels differ.

## What is still open

* The dump at `0x8C09616A` (the fight scheduler the port's tick runs) has to
  be caught *during a fight*.  The attract screen never calls it; the demo
  fight has to be reached first.
* The port still needs the TA command layout to decode the stream
  (phase P3), and the Katana/KAMUI headers that carry it are gone.
* VRAM is not dumped yet: the PVR2 model needs the textures the game uploaded,
  and the TA stream only carries the ones uploaded after the state was taken.
