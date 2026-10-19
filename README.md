# VF3tb decomp

![verified C](https://img.shields.io/badge/verified%20C-72.88%25-brightgreen)
![readable steps](https://img.shields.io/badge/readable%20ports%20%28fight%20tick%29-99.9%25-brightgreen)
![ported entries](https://img.shields.io/badge/ported%20entries-1671-blue)
![fight ticks](https://img.shields.io/badge/native%20fight%20ticks-13%2F13%20RAM--exact-brightgreen)
![boot states](https://img.shields.io/badge/boot%20states%20to%20frame%20loop-15%2F15-brightgreen)
![target](https://img.shields.io/badge/70%25%20milestone-sealed-success)
![platform](https://img.shields.io/badge/platform-Dreamcast%20SH--4-orange)
![language](https://img.shields.io/badge/language-C99-informational)

A clean-room, readable C source port of **Virtua Fighter 3tb** (Sega Dreamcast, MK-51001 V1.002). Byte-matching is not
the goal; a readable C mirror of the game's behavior is. Every port is checked against captured hardware-form state
(strict register/RAM replay), not just compiled.

The repo carries no game data. You supply your own disc dump; `rom/` and `extract/` are gitignored.

## Status

| Metric | Value | Where |
|---|---|---|
| Verified C coverage (bytes of the retail 1ST_READ.BIN) | **72.88%** (316,778 bytes; 70% target was 304,259) | `python tools/final_status.py` |
| Ported entries | 1,671 | `docs/decomp_status.csv` |
| Readable ports in the executed fight tick (state 7) | 159 entries, about 99.9% of executed steps; the rest are generated adapters | `docs/readable_status.csv` |
| Native fight tick (`build/vf3`) | 13 captured fight states, 0 unowned calls, RAM equal to the reference oracle | `sh tools/recomp/run_native.sh 7 13` |
| Boot states run natively (`build/vf3boot`) | 15 of 15 savestates (21-30, 42-46) reach the frame loop | `docs/boot_states.csv` |

Coverage numbers are the verified share of code bytes with a C port whose behavior was replay-checked; they move as the
capture-corpus work continues. The remaining unported owners are mostly blocked on BIOS/GD state or missing capture
windows (`docs/re/reios_exec_server.md`).

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

## Build and run

```sh
cmake -S . -B build
cmake --build build --target vf3 vf3boot
build/vf3 <golden_tickx_vf3_N.bin> --expect ...     # one native fight scheduler tick
sh tools/recomp/run_native.sh 7 13                   # fight regression
python tools/boot_states.py --states 21 22 23 24 25 26 27 28 29 30 42 43 44 45 46 --cap 700 --timeout 3600
```

Most tools need the extracted binaries under `extract/exe/` and `extract/gamedata/` (see `AGENTS.md` for the pipeline).
`tools/sh4dump.py` needs the venv in `tools/.venv`.

## Solved formats

DTPK container and AICA ADPCM audio, TEX (RGB565 + PVR twiddle), MT motion tables, POL models, and the GD-ROM FAD
addressing the loader depends on. Specs in `docs/`; the drive notes are in `docs/re/gdrom_lowlevel.md`.

## Conventions

Byte offsets in hex; addresses include the 0x8C010000 base; every decode ships with a verification artifact; one commit
per milestone. See `AGENTS.md` for the full repo guide and `docs/re/phase4_findings.md` for the current frontier.

## Legal

This is an independent reimplementation for research and preservation. It contains no Sega code or assets. You need your
own legally obtained copy of the game to run any of the tooling.
