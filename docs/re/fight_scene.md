# Fight-scene dispatcher — evidence ledger (M5-a supplement, M6)

## Update 2026-09-19 — fight captured via savestate injection

Playable GUI sibling build (`tools/emu/flycast-build-gui/`) dropped the PR-safe tracing
macro-soup in favor of a file-driven script runner (`core/vf3script.{cpp,h}`, env
`VF3_PLAY=<file>`, timeline `KEY|SHOT|SAVE|EXIT`; active-low kcode bits).
That build reached a real fight and `dc_savestate(0)` captured
`flycast-build-gui/data/vf3.state` (VM image at a VS/ARCADE fight).

The headless build now supports `VF3_STATE=<path>`: stages the file into its data
dir as slot 0 and does stop→`dc_loadstate`→start before the frame loop
(winmain.cpp, ~“state loaded” line in stderr). A 6000-frame JIT trace
(`trace_fight1.bin`, 1.6 GB) was produced from that state, gated by the
function table of `1ST_READ.unsc.bin`.

## Quantitative result

| metric | attract/title run (`trace_jit2.bin`) | fight run (`trace_fight1.bin`) |
|---|---|---|
| distinct fns seen | 74 | 363 |
| `bjload_run` 0x8C0CBC40 hits | 0 | 950 |
| `scene_mgr_B` 0x8C063F58 hits | 272 | 29,819 |
| `load_mt_to_u_pai` 0x8C04BDA2 hits | 380 | 6,672 |
| `task_run_C` 0x8C0796F4 hits | 0 | 8 (first seen mid-fight, once) |

**)fight-only delta = 347 functions** — names `fight_f_0x%08x` applied into the
Ghidra project via `Vf3ApplyNames` (extract/analysis/fight_names.csv).

## What it confirms

- **The fight code region is contiguous: 0x8C02xxxx–0x8C0Cxxxx are all-in on the fight.**
  The bootstrap/title/attract never touches them; fight them all the time.
  Top fight-loop workers (by hits/frame):

  | fn | hits | region |
  |---|---|---|
  | f_8c069078 | 989K | runner/dispatch band 06 |
  | f_8c073cc6 | 843K | band 07 hot utility |
  | f_8c068f86 | 608K | band 06 |
  | f_8c09d6e0 | 330K | band 09 — same bank as `coli_run` (collision?) |
  | f_8c06f720 | 217K | band 06 |
  | f_8c071a82 | 153K | band 07 |

- **Fight-entry chain (post-loadstate resume order)** — first 25 fight-only activations
  in trace order: 8C0B1AC0 → 8C058E92 → 8C091C42 → 8C03EFFC → 8C091CF2 →
  8C091D80 → 8C0869DA → 8C0B1892 → 8C0C6732 → 8C072B72 → 8C091426 → 8C0914C2 →
  8C091788 → 8C068CC2 → 8C0693B4 → 8C068F86 → 8C069078 → 8C0694E8 …
  This is the *per-frame* fight chain (the state was mid-round): the scheduler
  (`f_8c0b1ac0`-ish region) runs the per-frame job list.

- `mt_loader` (0x8C02DCEC) and `coli_run` (0x8C09AAE2) still show **0 hits**:
  both are one-shot machine-load functions (mt_loader = MT files to buffers,
  coli_run = per-stage collision asset build) — already finished by the time the
  fight state got frozen. For their chains, trace must span the *load moment*
  (character/stage select → fight start transition), not steady-state rounds.

## Tool state after M6

- headless build: `flycast-build/flycast.exe` — `VF3_TRACE`, `VF3_INTERPRETER`,
  `VF3_TRACE_FRAMES`, `VF3_PLAY`, `VF3_STATE`.
- gui build: `flycast-build-gui/flycast.exe` — playable (SDL+OpenGL), same
  script runner + F1/F2 quick state keys (mappings/SDL_Keyboard.cfg).
- state handoff: `VF3_STATE=<gui data>/vf3.state` on the headless side.

## Next (M6 close-out)

1. A *transition* capture: savestate at title screen → script keys to actually
   trigger fight start → trace the csel→fight chain → name `mt_loader`/`coli_run`
   neighbors and the round-init functions (`task_run_C` seen 8× mid-fight).
2. First-seen ordering into sequence diagram form (fight_scene_flow.md).
3. Tick-rate math: `f_8c069078` at ~165/frame → main per-fighter frame work fn.

## Update 2026-09-19 (second session) — transition capture attempts

**New rig bits** (all in flycast fork):
- `vf3script` (core/vf3script.{h,cpp}): timeline format `ms CMD [arg]`;
  `KEY hexmask`, `SHOT name`, `SAVE slot`, `EXIT`; runs on the UI thread.
  SAVE is now properly serialized (emu.stop → dc_savestate → emu.start) — the
  earlier save path raced the SH4 thread and raised empty `FlycastException`s
  dialog; fixed.
- `vf3script` SHOT dumps **raw VRAM+RAM** to `extract/analysis/shots/`
  (renderer-independent — GL presentation is broken in this build, so the
  builtin screenshot API never sees a frame).
- `tools/state_extract.py` (TMP): parses FLYSAVE1+RZip state files
  (`'#RZIPv1#'` 8B magic, u32 chunkSize=1MB, u64 total, zlib chunks).
  RAM image (16 MB) extracts at raw offset ≈0xB28291 in the fight states.

**Fight confirmed inside RAM by string audit**: `ram_r35` contains
`MTJACKAG.BIN`, `BGM_JACK.BIN`, `AU.AKIRA`, `M_JACKY` ⇒ current fight is
**AKIRA vs JACKY on Jacky's stage** (ATTRACT/demo + scripted keys drove it).

**Ladder captures** (GUI, scripted): vf3_1..vf3_15 under flycast-build-gui/data
at t≈60..110 s; headless triage traces `tr4_slot{1..15}.bin` show
`f_8c09d6e0` (fight loop) active in many, but `mt_loader`/`coli_run` remain
unfired in EVERY state: **MD loader + char resource loads happen strictly
between char-select-confirm and round-1 start, which demo-loop paths never
redo**. The in-fight state resumes the function stack entirely in fight loop
context, never touching loaders.

**`bjload_run` normally executes per fight — at trace record 8,751 out of the
state-resume preamble.** And `0x8C0B1AC0` (resume dispatcher) is its caller
chain entry 0. Both bjload & co are **inner-loop dispatch targets**, NOT
function heads — disasm at `bjload_run` 0x8C0CBC40 begins mid-struct
(`mov.w 0x8c0cbd4c,r4; jsr @r14` with r11/r13/r14 pre-set). Consequence for
Ghidra work: `fight_f_*` names mark dispatch waypoint ADDRESSES, not fn heads;
a CFG splitter pass that splits at each traced-entry will decompose properly.

**Battle-frame chain observed post-resume (first 25 traced entries)**:
```
8C0B1AC0 → 8C058E92 → 8C091C42 → 8C03EFFC → 8C091CF2 → 8C091D80 →
8C0869DA → 8C0B1892 → 8C0C6732 → 8C072B72 → 8C091426 → 8C0914C2 →
8C091788 → 8C068CC2 → 8C0693B4 → 8C068F86 → 8C069078 → 8C0694E8 → ...
```

**Animation file load differencing** (from fights/ram): `8C16CDD*-8C228*xx`
block re-times per attack (u32 7→0, 9→3/4 pattern sweepers) — matches "frame
countdown per animated node" under current MT player hypothesis.

## Open items / blockers

- `mt_loader` & `coli_run` remain **UNOBSERVED** — they need a REAL csel→fight
  transition: humans navigate title→arcade in ~10 s, script attempts stall at
  title attract. Resolve by one manual savestate capture from char-select +
  ROUND-1 start (option A), or extend script with more menu traversals
  (estimate ~30 more min of retired blind retries; debugging is visible-only).
- VF3 fight-context struct not yet pinned: follow `FUN_8c069078` dereferences.
- Loading-screen red band VRAM pattern visible at 0x1f0000 (raw VRAM view works;
  fb geometry = 640×480 × 2BPT at that base, values at RGB565).

(Previous ledger content preserved below — pre-savestate era.)

---

## Candidates re-scored from live traces (historic)

fntables_1ST_READ.csv reports these jump-table hosts in the 0x8C02-0x8C07 block.
Now overlaid with trace_fn_first_seen (run1+run2):

| function | size | first seen (run2) | hits | veredict |
|---|---|---|---|---|
| **f_8c063f58** | 222B | 100,665,172 | 299,055 | **likely the scene/state manager**: enters right at game-image start, hits continuously every ~4K instructions (== frame-rate) |
| f_8c0516a8 | 196B | — | 0 | unused in boot/menu |
| f_8c07d368 | 256B | — | 0 | unused in boot/menu |
| task_run_A (0x8C05E64E) | ? | 100,665,151 | 21 | fires once (scene init) |
| stage_load(0x8C0B7302) | ? | 136,608,074 | 58 | called at demo/attract phase start (fight views) |
