# Differential port oracle (Phase B) + first oracle-verified port (Phase C)

## Why
The repo's hot fight functions are FPU/memory heavy; the earlier buckets could
identify them but not *verify* a C port. This adds a flycast-side golden
capture and a replay harness that validates ports against real execution.

## Flycast instrumentation (local fork; `tools/emu/` is gitignored)
`core/vf3trace.{h,cpp}` + `core/hw/sh4/interpr/sh4_interpreter.cpp`:

- `VF3_FULL=1` upgrades watched PCs (`VF3_WATCH`) to full entry/exit snapshots:
  - entry `(pc<<16)|0xFA30`, 37 values, close `0xFA31`
  - exit  `(pc<<16)|0xFA32`, 37 values, close `0xFA33`
  - values = `r0-r15, pr, sr, fpscr, macl, mach, fr0-fr15` (FPU bit patterns).
- Call-depth tracking in `vf3TraceDepthOp`; exits are emitted **two fetched
  instructions after rts** so the rts delay slot (which often stores r0) has
  executed. A taken `bf/bt` in this emulator skips an rts delay slot, so no
  exit is emitted in that case.
- Build: `cmake --build tools/emu/flycast-build -j8` (MinGW/msys64 ucrt64).

## Capture recipe
```
VF3_INTERPRETER=1 VF3_STATE=<.../vf3_7.state> VF3_FULL=1 \
VF3_WATCH=tools/watch/vf3_oracle_fpu.txt \
VF3_TRACE=extract/analysis/golden_fpu2.bin VF3_TRACE_FRAMES=120 \
  tools/emu/flycast-build/flycast.exe rom/vf3.gdi
```
120 frames from the mid-fight savestate produce ~150 MB and 11k samples of
`0x8C068F92`, 2.2k of `0x8C068FF6`, 737 of `0x8C068E16`.

## Tools
- `tools/golden_extract.py` — pairs entry/exit groups per PC, dedupes, writes
  `extract/analysis/goldens/<fn>.{json,txt}` + `goldens_index.csv`
  (fingerprints, unpaired counts). `.txt` = 74 hex words per line for C tests.
- `tools/portcheck.py` — validates goldens, runs every `build/vf3*.exe` test,
  and runs each bound port (`tools/golden_bindings.json`: pc -> test, golden)
  as `<test> <golden.txt>` requiring exit 0.
- `tools/port_backlog.py` — ranks the 2,181 unclaimed functions by trace heat
  (mapping internal trace labels to the containing baseline fn), call count and
  leaf-ness; `extract/analysis/port_backlog.csv`.

## First oracle-verified port
`0x8C068F92` (54 B, ~11k calls/120 fight frames, called 5x by the #2 hottest
function `0x8C068FF6`). FPU-only register helper:

```
a = (fr7 - fr5) * (fr8 - fr6)
b = (fr6 - fr4) * (fr9 - fr7)
d = a - b
return d > 0 ? 2 : (d == 0 ? 1 : 4)     // bit-per-outcome
```

Shipped as `src/fight/orient2.{c,h}` + `tests/orient2_replay.c`.
`vf3orient2` replays all 64 unique golden vectors: **64/64 match - PASS**;
`tools/portcheck.py` binds it and reports PASS.

## Second oracle-verified port (Phase C, continued)
`0x8C068FF6` — the #2 hottest function (288 B, ~1.4M summed trace hits),
`src/fight/poly_classify.{c,h}`. It classifies a sample point `(fr4,fr5)`
against a quad (`p0..p3`) reached through a descriptor + base pointer:

```
flags    = *(u32*)r4;                  if (flags & 1) return 1;
rec      = *(u32*)(r4+4) + *(u32*)r3;
stored   = *(u32*)rec & 1;
if (*(float*)(rec+24) == 0) return 0;
h1..h5   = orient2 of (fr4,fr5) vs edges p0p1, p1p2, p2p0, p2p3, p3p0
m        = h3 | (h1&6) | (h2&6)
if (bit2(m) != bit4(m)) return 2;
if (stored != 0)        return 0;
a        = h1 | (h2&6) | (h4&6) | (h5&6);
return (bit2(a) != bit4(a)) ? 4 : 0;
```

- RAM oracle support: `VF3_RAMPC=<pc list>`, `VF3_RAMN=<count>`,
  `VF3_RAMWIN=<base len [base len ...]>` dumps up to 4 address windows at
  entry (for this port: one 16 MB window `0c000000 1000000`).
- `tools/golden_extract.py` now also writes `<fn>.cases`:
  `37 in words, 37 out words, ram-file, up to two window pairs`; the C
  replay test maps SH-4 P1/P2 aliases into the window.
- `tests/poly_classify_replay.c`: **16/16 RAM-backed oracle cases PASS**
  (`build/vf3poly.exe`).
- Disassembly notes: on SH-4 `bf`/`bt` are non-delayed while `bf/s`/`bt/s`
  are delayed; the earlier confusion about the helper's `rts` in a `bf`
  delay slot was a decoder artifact. The real control flow is straightforward.

## Findings
- Trace "function" labels in `trace_fn_hits.csv` are mostly **internal loop
  points**, not entries; `port_backlog.py` maps them to containing baseline
  functions and shows the real hot set (`0x8C0738FC` 2.0M, `0x8C068FF6` 1.4M,
  `0x8C068E16` 0.87M summed hits).
- There is **no pure integer function** in the hot set (scan of all 2398:
  exactly one, size 8 B, zero heat): a register-only oracle is insufficient
  for this engine; memory-window capture is the next oracle increment.
- Exit snapshots must be taken after the rts delay slot: the helper sets its
  return value in that slot (previously captured r0 was the stale `0x8`).
- The helper's `bf`-with-`rts`-delay-slot is undefined behaviour on real
  SH-4; the emulator's choice (skip delay slot when taken) matches the
  intended `{2,1,4}` semantics and the golden vectors.
