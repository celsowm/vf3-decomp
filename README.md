# VF3tb native decomp port

This project aims to produce a playable, readable C port of Virtua Fighter 3tb
for Dreamcast. The runtime is native C: it does not run the Dreamcast program,
execute generated guest adapters, emulate a CPU, boot firmware, or load a disc.

The disc is used once, offline, to extract the game data. The extracted assets
are packed into a VFA archive; `vf3port` reads that archive and SDL input at
runtime. The standalone executable does not need `rom/`,
`extract/gamedata/`, an emulator, a savestate, or the original disc.

## Current state

The standalone runtime can open its VFA asset pack, parse the Akira, Jacky,
and ST01 stage POL/TEX data in native C, render their extracted meshes and
textures, and run a basic Akira-versus-Jacky match loop. The asset readers and
native match shell are an early vertical slice, not yet a minimum playable
port. Character motion is not wired to the fighter models, combat values are
still blockout rules, and game audio is not connected.

The minimum playable target is a full one-player-versus-CPU best-of-three
match, with working movement, attacks, guard, hit reactions, extracted fighter
motion, stage presentation, audible asset-based sound, and rematch. Work and
remaining gates are tracked in [the native port plan](docs/re/native_decomp_port.md).

## Build and run the native port

SDL3 and the previously extracted asset files are required to build. CMake
packs `extract/gamedata/` into an asset-only VFA archive; this step reads the
extracted files and does not access the disc.

```powershell
cmake -S . -B build -DVF3_NATIVE_PORT=ON
cmake --build build --target vf3port
build\vf3port.exe
```

By default, `vf3port` looks for `vf3_assets.vfa` beside the executable, then
in the current directory and `build/`. Pass an archive path as the first
argument to select a different VFA file. This lets the executable and archive
run together from any working directory.

Keyboard controls: arrows move, Z punches, X kicks, V throws, C guards, Enter
advances between rounds or starts a rematch, and R restarts a match. Gamepad
controls use the D-pad/stick, South punch, East kick, West guard, Right
Shoulder throw, Start to advance, and North to rematch.

To create the archive separately from the build, run:

```powershell
python tools\pack_assets.py --source extract\gamedata --output build\vf3_assets.vfa
```

## Decompilation and research tools

The repository also contains offline decompilation, capture, and differential
replay tools. They help recover behavior and compare readable C against the
reference. The `vf3` research harness and the optional legacy `vf3sdl` host are
not the native port, are not linked into `vf3port`, and are not needed to play
the eventual port. The generated-adapter coverage ledger measures that
research track; it does not count as completion of the playable native port.

Reference captures and reverse-engineering notes live under `docs/re/`. Build
and trace recipes for the research tools remain there so they stay out of the
player-facing workflow.

## Repository data

`rom/`, `extract/`, and `refs/` are local research inputs and are gitignored.
The VFA asset pack is generated locally from the extracted data files; it
contains game assets but excludes the guest executable and firmware images.
The program is a clean-room source reconstruction and contains no bundled
game data.
