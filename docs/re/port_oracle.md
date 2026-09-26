# Differential port oracle (Phase B) + oracle-verified ports

## Critical capture-integrity findings (2026-09-25)
Three fork bugs were corrupting traces; all fixed:
1. `vf3TraceInit` reopened (truncated) the trace file on every `Run()` —
   savestate load does `stop()/start()` so the stream got interleaved with
   stale data. Now one open per process.
2. `vf3_seh` intercepted `DBG_PRINTEXCEPTION_C` (0x40010006, from debug
   prints) and called `vf3TraceFlush()` from exception context, dropping ring
   contents (`flush wrote 64/65536` then `0/...`) and leaving partial groups.
   Debug-print exceptions now pass through and the SEH handler never touches
   the writer.
3. `emit_ram` built groups incrementally; a throwing read could leave a
   partial group. It now buffers a whole group and pushes it atomically.
Also: opening the trace before `flycast_init()` was removed (handle could be
invalidated); `flush` now checks the `fwrite` count.

## Game FPSCR: round toward zero (critical for any FPU port)
Golden entry/exit snapshots show **FPSCR = 0x240001** in fight code:
`RM=1` (round toward zero) and `DN=1` (denormals are zero). All SH-4 FPU
multiplies/adds/FMACs therefore **truncate**; C's default round-to-nearest
gives ~1 ULP differences and fails byte-exact comparison. Ports must use
truncating helpers (see `src/fight/scalemap.c` `f32_tz`/`fmul_tz`/`fadd_tz`/
`fsub_tz`/`fmac_tz`, which compute exactly in `long double` and step toward
zero). Flycast's `fmac` is `std::fma` (fused, single rounding) + the current
RM, so `fmal` + truncate matches it.

## Third oracle-verified port: warping scale-map (0x8C068E16 family)
`0x8C068E16` (352 B, 873k trace hits) -> `src/fight/scalemap.c`:
- entry `r0 == 8` convention: `[r15+8] = fr4`, `[r15+4] = fr5`; helper
  `0x8C068D54` rescales per selector (2/7: x10/13; 13: 0.1 quantize);
- clamp both coords to [-12,12] (fcmp/gt store form);
- `t = fma(5, coord, 64)`, `i = trunc(t)`, `idx = (i1&0x7F)|((i2&0x7F)<<7)`;
- bilinear over the 128x128 float table at `*(0x0C1B9610)` (table window
  0x0CBE0000+0x40000; pointer source [0x0C1B9610]; selector mask byte at
  [0x0C29B880] = 0x01 in the fight capture);
- port mirrors every stack write (slot stores, temporaries, result) so the
  RAM-shadow diff is byte-exact: **vf3scalemap 32/32 cases PASS** (entry+exit
  RAM, 4 windows).
- Documented gaps: selector 11 aux call 0x0C087ACE, the ctx==0 fallback and
  the 0.1 constant alignment (mova effective-address ambiguity) are not
  exercised by the captured cases.

## Batch infrastructure (campaign 0, 2026-09-25)
Fork (`tools/emu/flycast`, gitignored — rebuild with
`cmake --build tools/emu/flycast-build -j8`):
- `VF3_RAMPC` up to 32 PCs; the watch file accepts `rampc <pc> [<base> <len>]`
  lines — RAM dump on entry/exit with a per-PC window, and the PC is
  implicitly watched. Up to 64 per-PC windows (repeated `rampc` lines), so a
  function can get several small windows instead of a 16 MB dump.
- `VF3_RAMWIN` up to 8 global windows (fallback when a PC has none).
- `VF3_EDGES=<file>`: 16-byte call-edge records `kind(0=call,1=ret),
  caller_pc, target, depth`; targets resolved for JSR @Rn, JSR @@(d8,Rn),
  BSRF and BSR. Enables static closure checking against real calls.

Tools:
- `tools/golden_batch.py` — runs flycast once per scenario (run spec
  `name:state:play:frames`), collects `VF3_TRACE` + `VF3_EDGES`, then extracts
  all traces into one golden dir with `batch_manifest.json`.
- `tools/golden_extract.py` — now accepts multiple traces (merged per PC,
  per-sample scenario tags) and writes the v2 `.cases` format:
  `in*37 out*37 entryram nwin [base len]* exitram nwin [base len]*`
  (legacy fixed-2-window lines are still parsed by the harness).
- `tools/derive_windows.py` — reads register-only goldens, finds
  pointer-valued entry registers (canonical P2 0x0C...), pads/merges ranges
  and writes the `pc` + `rampc` watch file for the RAM capture pass.
- `tests/port_harness.h` — shared `.cases` runner: parses both formats,
  materializes writable window shadows, calls the port, checks the 37 output
  values (`vf3h_regs_ok`) and byte-exact shadow-vs-exit RAM (`vf3h_mem_ok`),
  reporting out-of-window accesses. A port test is now ~30 lines.
- `tools/port_plan.py` — regenerable roadmap (`extract/analysis/port_plan.csv`)
  joining backlog heat, executed set, static call edges, SDK claims and the
  port ledger; tags campaigns A/B/C/D + closure_ok + effort.
- `tools/verify_all.py` — build + portcheck + decomp_stats + union verify +
  port_plan in one gate.

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

## Fixes and extensions (tranche 2)
- Call-opener mask: `(op & 0xF0FF) == 0x400B` (JSR @Rn; bits 7-4 zero).
  The old `(op & 0xF00F)` mask conflated `JMP @Rn` (0x4n2B) with `JSR`,
  drifting call depth +1 on every computed tail jump. JSR @@(d8,Rn)
  (`0x4xxx` low nibble 3), BSRF and BSR unchanged.
- `jmp @Rn` is deliberately NOT an exit: it serves both computed loops
  (the `0x8C071A96` per-vertex loop jumps back every ~200 instructions)
  and noreturn tails, which are indistinguishable statically. Only `rts`
  closes an arm; tail-jumping functions validate at interior points.
- Exit RAM: same windows dumped at function exit (`0xFA60/0xFA61`,
  `VF3_RAMNEXIT`, independent counter), attached by `golden_extract.py`
  as `exit_ram` with an `exitram_trusted` flag (FIFO order, exact when
  `unpaired == 0`).
- RAM windows: `VF3_RAMWIN="<base len>..."` (up to 4); base/len travel in
  the trace so the extractor needs no out-of-band config.
- Piecewise validation: `tools/pair_cases.py TRACE --entry PC --at PC
  --out PREFIX [--gate "r2>r9"]` binds each gated entry hit to the first
  following interior hit (positional, not ordinal — interior points inside
  loops fire ~5x per call), emitting `.cases` + `.in/.out` bins + `.meta`.
  Used for `0x8C071A76` (entry -> `0x8C071ABE`, 7 cases).
- `tools/sh4.py`: `bf`/`bt` are direct jumps (no delay slot); only the
  `/s` forms and the unconditional transfers are delayed (fixed the
  `delay` flag that had mislabelled the orient2 helper's control flow).

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

## Giant/combined-unit port rules (all phases)
- Entry mechanics decide verifiability. A unit is standalone-portable only
  if its oracle exits terminate at its own matching-depth `rts`.
- Fallthrough/tail-called units are not standalone-verifiable, even with a
  complete body model. A combined unit is valid only when the extended
  region through the next `rts` contains a call that restores matching depth
  before exit.
- Piecewise ports must name the exact entry/exit slice, gate unresolved
  calls, and force unmodeled outputs from oracle.
- Nested verified ports may be called directly from larger ports.
- Parked rows must use non-`ported` status and never count toward rigorous
  coverage. Only `status` starting with `ported` counts.
