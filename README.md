# VF3tb decomp

![recorded C coverage](https://img.shields.io/badge/recorded%20C%20coverage-91.30%25-blue)
![native port](https://img.shields.io/badge/native%20PC%20port-in%20development-orange)
![language](https://img.shields.io/badge/language-C99-informational)

A clean-room, readable C source port of **Virtua Fighter 3tb** (Sega Dreamcast, MK-51001 V1.002). Byte-matching is not
the goal; a readable C mirror of the game's behavior is. Every port is checked against captured hardware-form state
(strict register/RAM replay), not just compiled.

The repo carries no game data. You supply your own disc dump; `rom/` and `extract/` are gitignored.

## Status

**There is no complete playable native PC port yet.** The current game executables run captured states. The optional
SDL3 target is a host-platform diagnostic, not VF3tb gameplay. See [the completion plan](docs/PC_PORT_PLAN.md) for
cold boot, continuous runtime, renderer, sound, content and 1:1 acceptance gates.

| Metric | Recorded state | Qualification |
|---|---|---|
| Verified C address union | 396,830 / 434,656 bytes (**91.30%**) | Historical `docs/coverage.md`; frozen inventory and replay corpora must be supplied to reproduce it |
| Ported entries | 2,220 unique ledger entries | Body ranges overlap; summing ledger sizes overcounts |
| Native fight tick | 13 captured states reported RAM-exact by the author | Local captures are required; not a disc-only game |
| Boot experiments | 15 recorded states reach the frame budget | Their rows also record an unowned call; not a clean full-boot pass |
| SDL3 host foundation | Window/framebuffer presentation, events, two host pads, clock | Integration into the native game loop, renderer and sound remains open |

`python3 tools/port_preflight.py` reports missing local evidence. Missing evidence, a capped run and a passing replay
are separate outcomes. `docs/re/oracle_device_reads.md` explains the modified device policy of some synthetic probes;
those results are not proof of unmodified device behavior. Code coverage does not measure overall playability.

## The disc these numbers were measured on

Virtua Fighter 3tb (USA), GD-ROM, product MK-51001 V1.002, GDI dump with three tracks. Verify yours before comparing
anything; a different dump will give different sector addresses and hashes.

| File | SHA-1 |
|---|---|
| `Virtua Fighter 3tb (USA) (Track 1).bin` | `bb30bc9d46c58c14475895ccc9bdba3cc7184f36` |
| `Virtua Fighter 3tb (USA) (Track 2).bin` | `a3705cb0ce53c7adf906c5af76887406984de6a9` |
| `Virtua Fighter 3tb (USA) (Track 3).bin` | `831b616be8eb2ed2f98bbeea271a4e8a9e3c152a` |
| `vf3.gdi` (track list used by the tools) | `cfc65b63e7878fe4fda033c88246f7eb1b8e5c2d` |
| `1ST_READ.BIN` (retail executable, unscrambled, loads at 0x8C010000) | SHA-1 `bd327fc8ffb0411883abeb9b925b4660973f160e` |
| `1ST_READ.BIN` | SHA-256 `37f38dd9a47b785f526157c4a1674ca75322f0de1342f64bbf33c88d128e4b32` |

These are hashes of the author's dump; they have not been compared against a preservation database, so no claim is made
that they match any particular catalogue entry.

## Layout

- `src/` the port (C99): `fight/` (task VM, scheduler, motion, collision, render lists), `render/`, `media/` (DTPK, AICA
  ADPCM), `sys/` (BIOS syscall and GD-ROM models), `lib/`, `boot_sim.c`, `main.c`
- `tools/` Python RE tools (py3.12, no dependencies) and Ghidra headless scripts (`tools/gscripts/`)
- `docs/` progress, format specs and the RE ledger (`docs/re/`)
- `rom/`, `extract/`, `refs/`, `build/` local only, never committed

## Prepare the local disc

```sh
python3 tools/prepare_rom.py --zip /path/to/rom_compactado.zip --verify-only
python3 tools/prepare_rom.py --zip /path/to/rom_compactado.zip
```

The offline importer checks the exact image identities below, extracts 412 files, identity-copies the three executable
images into `extract/exe/`, and writes `extract/rom_manifest.json`. It refuses differing existing files. These retail
binaries are already unscrambled: do not run the MIL-CD descrambler on them. ROMs, extracted assets and captures stay local.

## Build and test

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
python3 tools/port_preflight.py
```

The ROM-free Python checks run on a clean checkout. CTest explicitly skips `gdrom_disc` when the disc is absent; with the
disc installed it exercises DMA/BIOS reads and reports unavailable optional saved-state checks. Missing strict replay
fixtures remain a preflight failure. These checks do not certify gameplay fidelity.

With an installed SDL3 development package discoverable by CMake:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DVF3_BUILD_SDL3=ON
cmake --build build --parallel
build/vf3platform-smoke --frames 120
ctest --test-dir build --output-on-failure
```

`vf3platform-smoke` displays a synthetic diagnostic pattern and polls input; it does not load the game. See
[src/platform/README.md](src/platform/README.md) for the host API and controls. SDL3 package/build integration follows the
[official SDL CMake guide](https://wiki.libsdl.org/SDL3/README-cmake). CI builds the source and ROM-free diagnostics on
Windows, Linux and macOS; actual game validation requires the local evidence package.

Captured-state regression tools (only after supplying their local inputs):

```sh
build/vf3 <golden_tickx_vf3_N.bin> --expect ...
python3 tools/check_new_bindings.py --pc 0x8c064246
python3 tools/boot_states.py --states 21 22 23 24 25 26 27 28 29 30 42 43 44 45 46 --cap 700 --timeout 3600
```

Boot reports default to ignored `extract/analysis/boot_states.csv`; `--csv` and `--exe` override output/binary locations.
Capped or failed runs exit nonzero. The historical `docs/boot_states.csv` is retained as evidence, not rewritten by tests.
See `AGENTS.md` for the analysis pipeline and the completion plan for the missing evidence handoff.

## Solved formats

DTPK container and AICA ADPCM audio, TEX (RGB565 + PVR twiddle), MT motion tables, POL models, and the GD-ROM FAD
addressing the loader depends on. Specs in `docs/`; the drive notes are in `docs/re/gdrom_lowlevel.md`.

## Conventions

Byte offsets in hex; addresses include the 0x8C010000 base; every decode ships with a verification artifact; one commit
per milestone. See `AGENTS.md` for the full repo guide and `docs/re/phase4_findings.md` for the current frontier.

## Legal

This is an independent reimplementation for research and preservation. It contains no Sega code or assets. You need your
own legally obtained copy of the game to run any of the tooling.
