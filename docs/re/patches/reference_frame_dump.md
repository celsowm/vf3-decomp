# The reference emulator's two hooks

The reference frames and the machine state come from a Flycast build.  Flycast
is GPL and this repository is not, so the diff against it is **not** kept
here: what follows is the description of the two hooks, and the instrument
itself is ours (`tools/refemu/vf3dump.c`, `tools/refemu/vf3dump.h`).

A Flycast checkout (upstream `e88b0ced`) needs three edits to carry the
instrument.  In `core/hw/sh4/`:

1. Copy `tools/refemu/vf3dump.c` and `tools/refemu/vf3dump.h` next to
   `sh4_mem.h` (the sources use the emulator's own include paths).

2. In `core/hw/sh4/CMakeLists.txt`, add the two file names to the
   `target_sources` list.

3. In `core/hw/sh4/interpr/sh4_interpreter.cpp`, include the header and call
   `vf3DumpCheck(ctx->pc)` once per instruction, between the opcode fetch and
   its execution.  The check is a single comparison against a masked address
   plus an optional table increment, so the interpreter stays usable.

The build itself needs `-DTEST_AUTOMATION=ON` (upstream's own switch) for the
raw frame dump and the input replay.

## One upstream bug has to be fixed to build at all

`TEST_AUTOMATION` pulls in upstream's input-replay code, which computes a
"swirl time" offset with `std::max` over two arguments of different types: a
64-bit signed value and a `long`.  On Windows `long` is 32 bits, so the
overload does not resolve and the build fails.  Give the call an explicit
64-bit template argument and use a 64-bit zero.

## Configuration traps

Both were found the hard way; see `docs/re/p1_reference_frames.md`.

* Flycast's `Option<>` values live in the **`[config]` section**, keyed by the
  option's full name: `[config] Dynarec.Enabled=0` switches the dynamic
  recompiler off, `[config] Dreamcast.AutoLoadState=1` loads the savestate at
  start-up.  Writing `[Dynarec] Enabled=0` parses and is silently ignored.
  Values read with `config::loadStr("record", "rawvid")` do use the section
  they name - the two kinds coexist in the same file.
* The ini file is read from the **exe directory** when the user config
  directory has none (no `$XDG_CONFIG_HOME` and no `$HOME`), and the data
  directory sits next to it.  So the build directory holds both `emu.cfg` and
  `data/` (with `dc_flash.bin`, `dc_boot.bin` and the savestate named after
  the rom, `vf3.state`).
