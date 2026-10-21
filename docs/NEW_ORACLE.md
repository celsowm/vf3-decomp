# New pinned reference: independent of historical seals

The original instrumented Flycast build is not recoverable from the supplied
bundle alone. `ORACLE_REPRODUCIBILITY_AUDIT.md` remains the historical audit;
none of its missing artifacts or old seals is replaced by this work.

A new, isolated reference now builds from official
[flyinghead/flycast commit 31697241b7c57c52df8382493e896667e654242c](https://github.com/flyinghead/flycast/commit/31697241b7c57c52df8382493e896667e654242c).
The official GitHub API and Git transport established that pin on 2026-10-21.
`tools/oracle/new_reference/discovery.md` records retrieval. Local verification
used macOS arm64, Apple clang, CMake and Ninja already installed on the host.
The bootstrap has a Linux path, but Linux has not been built or validated here.
It does not claim a Windows reference build.

The current default reference enables upstream `STRICT_MODE`, including the
interpreter's instruction/operand cache handlers and strict instruction behavior.
It also defines upstream `TARGET_NO_REC`, compiling out SH-4/ARM/DSP recompilers;
the pinned ARM64 recompiler otherwise fails to compile with strict MMU headers
(`mmuAddressLUT` is unavailable). This chooses supported upstream interpreter
paths instead of changing the guest instructions or patching that backend.
Build products go to `build-strict`; an explicit `--cache-bypass` diagnostic
control goes to `build-bypass`. The manifest records this policy and the exact
driver path. Version 3 snapshots additionally report whether the operand-cache
handler is actually connected at capture time.

This reference uses the upstream SH-4 interpreter, HLE BIOS, neutral input,
single-threaded rendering and the `NO_REND` renderer. It downloads no Dreamcast
BIOS, game or protected SDK. The local GDI and its tracks remain read-only local
inputs, hashed by the capture manifest. Emulator source, build products and
captures live in `../vf3-oracle-new`, outside this repository. Nothing from that
workspace is a shipping native-runtime dependency.

## Build and capture

From the repository root, with Python 3.11+, Git, CMake, Ninja and a C++17 compiler:

```sh
python3 tools/oracle/new_reference/bootstrap.py --work-dir ../vf3-oracle-new --jobs 4
python3 tools/oracle/new_reference/test_reference.py
python3 tools/oracle/new_reference/capture.py \
  --work-dir ../vf3-oracle-new --gdi rom/vf3.gdi \
  --out ../vf3-oracle-new/captures/boot-handoffs-recheck \
  --pc 0x8c010000 --pc 0x8c004000 --pc 0x8c020000 --pc 0x8c09574e \
  --snapshots 4 --frames 1200 --instructions 1000000000 --timeout 180
```

Only the pinned Asio, libchdr and tinygettext dependencies are initialized;
tinygettext also requires its pinned tinycmmc submodule. Existing source trees
at another revision are rejected, never reset. Build concurrency is capped at
eight. A 4 GiB free-space reserve is required. Capture limits are 1–20,000
frontend frames, 1–2 billion instructions, 1–1,800 seconds and 1–16 snapshots.
Existing capture output directories are rejected.

The build manifest records the pin, submodule SHAs, compiler, commands and
SHA-256/size of the actual driver, shared core, CMake cache, patch and observer
sources. `git diff` does not contain the newly copied observer files: reproducing
the overlay requires `observer.cpp`, `observer.h` **and** `install.py`, not the
patch alone. `capture.py` verifies every recorded dependency before running,
copies the build manifest and preserves its exact inputs under
`reference-inputs/`, with a `reference-inputs.json` index. This prevents later
reference changes from destroying the source/binary closure of a prior capture.

The CLI driver loads the GDI from a new private data directory and calls
`retro_run`. Multi-PC mode records the first occurrence of every unique
canonical address (`PC & 0x1fffffff`) in one uninterrupted boot. Its manifest
requires both the requested snapshot count and actual target coverage. A frame,
instruction or wall-clock limit is an incomplete capture, never acceptance.

Single-PC mode alternates entry and return observations. It follows a natural
RTS with the entry PR and a recovered stack, observes the delay slot, then waits
for the caller's actual PC before recording exit. This is a return heuristic,
not a general call-depth proof. Version 2 additionally records interrupt and
exception totals and events during the armed interval; a pair with asynchronous
events requires those device effects to be modeled before a differential claim.

## Snapshot contract

The hook is in `Sh4Interpreter::ReadNexOp`, **after opcode fetch and before its
execution**. JSON `pc` and the first binary context word are the fetched PC;
the upstream internal context already has `pc + 2`. Instruction fetch can change
instruction-cache state. No operand-cache flush, guest-memory read, seed-state
injection, guest code patch or native C replay occurs in the observer.

Every snapshot has raw physical main RAM (`.ram.bin`, 16 MiB), untouched
serialized instruction/operand caches (`.cache.bin`, 30,744 bytes on this ABI),
metadata JSON and `.context.bin`. The latter is exactly 64 little-endian uint32
words: fetched PC, then these 63 register words:

| Index in JSON `registers` | Value |
|---|---|
| 0–15 | r0–r15 |
| 16–20 | PR, full SR including T, FPSCR, MACL, MACH |
| 21–36 | active FR0–FR15 bit patterns |
| 37–52 | inactive XF0–XF15 bit patterns |
| 53–54 | FPUL, GBR |
| 55–62 | inactive integer bank 0–7 |

VBR, SPC, SSR, SGR, DBR, CCR, MMUCR, serializer version, instruction ordinal and
scheduled cycles are separate JSON fields. The GD array contains 22 explicit
words: last request, next request, status, command, params[4], result[4], current
sector, multi-read sector/offset/count/total, callback, callback argument, DMA
ended flag, transfer end time low/high. It uses named upstream fields, not a
historical serializer byte offset.

Version 2 adds direct raw VRAM (8 MiB), AICA RAM (2 MiB), PVR/AICA/Holly register
arrays, and the pinned upstream complete `dc_serialize` output (`.machine.bin`).
That machine serialization preserves additional scheduler, interrupt, MMU,
Maple, drive, audio and graphics state for inspection. It is taken at the fetched
opcode boundary and retains internal PC `pc + 2`; restoring it has **not** been
validated. It is not offered as an immediately resumable savestate, and it does
not replace a device-event trace or output capture.

## Cache interpretation

`cache_overlay.py SNAPSHOT.json` derives a separate `.p1-ram.bin` with the
privileged canonical P1 data view at `0x8c000000..0x8cffffff`. It never changes
the raw RAM/cache files or flushes the emulator. The pinned ABI has an 8-byte
serializer header, 256 instruction lines of 40 bytes, 512 operand lines of 40
bytes, then two 64-bit write-buffer timings. Unexpected size, version or flags
is rejected. The projection applies valid matching operand lines when CCR.OCE
is set, respecting CCR.OIX/ORA and the current line index. **Clean** cached lines
can also differ from RAM after DMA and must be included. Invalid, disabled or
nonmatching lines are not applied.

This view is not a general MMU resolver, other mirrored aliases, instruction
cache model or device model. P2 accesses use raw RAM. P0 uses the same canonical
data view only when address translation is off. Synthetic tests check dirty and
clean lines, disabled caching, index conflicts, ORA/OIX and malformed layouts.

## Verified early boot captures

`../vf3-oracle-new/captures/boot-handoffs-v1` contains one continuous HLE boot:

| Stem | Fetched PC | Instruction ordinal | SR | FPSCR |
|---|---:|---:|---:|---:|
| `0000_entry_ac010000` | AC010000 | 94,346,656 | 700000F0 | 40000 |
| `0001_entry_ac004000` | AC004000 | 94,370,854 | 700000F1 | 40000 |
| `0002_entry_0c020000` | 0C020000 | 96,574,135 | 600000E0 | 40001 |
| `0003_entry_0c09574e` | 0C09574E | 97,856,493 | 600000E1 | 40001 |

All four have CCR=0, MMUCR=0 and no valid cached RAM lines. Independently derived
P1 images differ from raw RAM by **zero bytes**. The supplementary
`derived-manifest.json` records input/tool/report/output hashes without rewriting
the original capture manifest. The prior `coldboot_8c010000` directory is an
unsealed smoke test without CCR metadata and is not reused as this evidence.

The v1 handoffs were built before `STRICT_MODE` was enabled. Their caches were
off in the guest as well, so the demonstrated relocation/CRT0 comparisons remain
valid in this recorded domain. The original binaries and all eleven build inputs
are preserved with `reference-inputs.json`; subsequent builds leave their original
`build/` binaries intact. The later `scheduler-first-v2` and `gameframe-first-v2`
explorations were also non-strict: although the guest sets CCR=0x105, those builds
bypass the SH-4 caches. They are explicitly **not** architectural cache reference
results. Both retained their first entry but reached the one-billion instruction
limit before observing the requested return, so their manifests are incomplete.

The subsequent `boot-handoffs-strict-v3b` capture completes all four targets
with `STRICT_MODE` and `TARGET_NO_REC` enabled. Every snapshot confirms
`operand_cache_handler_active=true`, CCR=0 and MMUCR=0. The four instruction
ordinals are 289,120,446; 289,144,644; 291,347,925; and 292,630,283. Thus the
relocation and CRT0 intervals still contain exactly 24,198 and 1,282,358
instructions respectively. Raw/P1 RAM differs by zero bytes at all four
boundaries. Capture hashes, preserved build inputs and the 64-word context
exports were verified. The earlier strict attempt with a 200-million-instruction
cap correctly recorded zero snapshots and an incomplete result; strict mode's
different boot timing requires the larger documented bound.

`scheduler-first-strict-v3` independently reaches the first scheduler entry at
`0x0c09616a`, instruction 390,308,191, with PR=`0x0c095cfc`, CCR=`0x105`, MMUCR=0,
245 prior interrupts and no exceptions. The operand-cache handler is active;
the preserved cache contains 512 matching operand lines, including 19 dirty
lines. Its derived canonical P1 image differs from raw RAM by 40 bytes. This
shows that this observer retains dirty cache data instead of flushing it into
RAM. The run does **not** observe the scheduler return before the one-billion
instruction bound, and its manifest remains incomplete. Its entry state,
VRAM/AICA/device snapshots and interrupt event log are useful for bounded native
reachability investigation, not an accepted input/output equivalence pair.

These new captures qualify CPU boot-segment comparisons. `NO_REND` can affect
scheduling at graphics boundaries and produces no rendered reference frames.
No graphics, audio, full gameplay, Windows/Linux native equivalence or historical
seal is established by this bootstrap. A later reference with actual rendering,
controlled device input/event tapes, frame/PCM capture and independent observer
controls is still required for full 1:1 acceptance.
