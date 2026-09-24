# VF3tb decomp — progress log

## M25 — Boot chain + frame dispatcher (2026-09-23)
- [x] True-image boot chain: entry 0x8C010000 copy loop -> 0x8C020000 CRT0
      -> 0x8C09574E startup (trace-anchored; first hit rec 97,856,826).
- [x] f_8c034852 = per-frame task-node dispatcher decoded & ported:
      src/sys/mainloop.{c,h} with guest-arena memory + host registry.
- [x] tests/mainloop_replay.c (vf3loop): all five result classes + empty
      chain asserted field-exact — PASS.
- [x] docs/re/mainloop_m25.md; quarantines pre-M23 main-loop notes.

## M24 — MT motion VM semantics SOLVED (2026-09-23)
- [x] Full channel-evaluator decode from the corrected image (f_8c09d690):
      63 channels/frame, op0=zero, op1=literal, op2=scalar keyframe lerp,
      op>=3 = vec3 Hermite spline (slopes ×1/256), phase in 1/256 units,
      unconditional z-plane negate post-pass (0x8C09D408).
- [x] src/fight/mt_play.c replaced with the true interpreter + mt_play.h.
- [x] tests/mt_vm_interp.c (vf3vm): value-level parity incl. exact-key and
      mid-span cases — PASS. (mt_oracle window test still PASS.)
- [x] Fixed sh4.py register-field bugs (jsr/lds/ldc families take n=[11:8]).
- [x] docs/re/mt_vm.md; open thread: pack mount-time relocation (+0x27B0
      linear record shift + slot-table rewrite in vf3_7).

## M23 — Image truth + corrected static foundation (DONE 2026-09-23)
- [x] Discovered retail VF3tb ships UNSCRAMBLED binaries; the M1 "descramble"
      was actively permuting the analysis image (32B slice shuffle).
- [x] `tools/image_truth.py`: 100.00% identity vs 106,995 executed op pairs.
- [x] Images repaired (raw gamedata -> extract/exe), Ghidra re-import +
      prologue sweep + baseline: 2,398 fns, 434,656 body bytes on true code.
- [x] MT motion evaluator now statically decodable (63-channel bytecode VM:
      op0->0.0, op1->stream float, op>=2->keyframe lerp; mirror-negate at
      0x8C09D408 for fighter 2). Port lands as M24.
- [x] New durable tools: sh4.py (full SH-4 decoder incl. FPU), sh4full.py,
      m14_seq.py (--vdis trace-code reconstructor), overlay_hunt.py.

## M1 — Ground truth & environment (COMPLETE)
- [x] git repo + ignore rules (no copyrighted data tracked)
- [x] `tools/extract_iso.py`: track-3 ISO9660 → **412 files** → `extract/gamedata/`, manifest `docs/files.md` (+ sha1 csv)
- [x] `tools/extract_ip.py`: IP.BIN parsed → `docs/ip.md` (MK-51001 V1.002 1999-08-20, area U)
- [x] `tools/dc_scramble.py`: descramble verified (**rescramble == original, byte-exact**);
      outputs: `extract/exe/{1ST_READ,VF3TBE3,RELOAD}.unsc.bin`
- [x] Executables identified: SH-4 main + E3 build + RELOAD module + ARM7 `SNDDRV.BIN` (`docs/executables.md`)
- [x] `DATELIST.ASC` (416 NUL-separated records) parsed → dev-tree taxonomy in `docs/build_manifest_notes.md`
- [x] Katana SDK 1.0B2 extracted via idecomp (IS3 `.Z`) → `tools/katana/`; Kamui → `tools/kamui/` (`docs/sdk_inventory.md`)
- [x] Ghidra 12.1.3 in-workspace; project `extract/ghidra_proj/VF3` with 1ST_READ + VF3TBE3 @ 0x8C010000;
      prologue-sweep script → **2,403 / 2,398 functions** created, CSVs in `extract/analysis/`
- [x] Kamui fingerprint tool built (639-function corpus; negligible matches → **VF3tb does not use Kamui2**)
- [x] Library stack identified in-binary: `NAOMI LIBRARY Ver 0.8`, `GDFS 0.53`, `syCache/syCbl`, `pd 1.07`, `bu 1.03`, `kd 1.20`
- [x] Asset inventory + first format signatures: `DTPK` container magic (u32 + u32 size),
      `CP_*` raw RGBA5551, raw PVR `*.TEX`, `POL` model packet streams, `.CLI` collision tables
      → `docs/formats/INVENTORY.md`
- [x] `src/` + cmake skeleton builds green (gcc, native stub)

## M2 — Naming & structure (IN PROGRESS)
- [x] Katana SDK 1.0B2 **extracted** (idecomp) — Shinobi + SHC Ver5.0R28 present
- [x] `tools/fingerprint.py` corpus widened (Kamui 25 maps + Katana `ip`/`mw_wav`): **1,171 functions**; 58 hits in 1ST_READ (SHC runtime helpers + Shinobi GD + NEC/Kamui driver tails)
- [x] `Vf3ApplyNames.java` applied 57/58 names into Ghidra project (`cand_`/`an_` prefixes mark pending verification)
- [x] RELOAD.BIN imported into Ghidra alongside 1ST_READ + VF3TBE3
- [x] Verify fingerprint matches — `_memset` (correct byte-fill loop) & `_gdFsDaPlaySct` (driver vtable dispatch) verified by disassembly
- [x] Syscall block mapped (0x8C0000Ax-FF block + labels; first ref: 0x8C0000BC at 0x8C011E02) — deeper xref analysis pending
- [x] Cross-build diff v1 (mnemonic streams): 604 identical lib/stable functions, 3,092 game-code candidates cataloged (extract/analysis/build_diff_map.csv)
- [ ] Shinobi rich symbol set: `shc.exe` runs but hits "Memory overflow" on modern-RAM machines — alternative: parse Hitachi `.lib` members or link anchor binaries with `lnk.exe`
- [ ] Hitachi LBR1-MW `.lib` format reverse (shinobi.lib directory seen at low offsets: name+timestamp+two u16 records)
- [x] Offline call-graph v1 (`tools/callgraph.py`): 1,352 resolved call edges; register-indirect handling incl. callee-saved lifetime; caller fn attribution via func CSV
- [x] Hotspots report regenerated per program (docs/re/hotspots_*.md)
- [x] DTPK probe: 69 packages, header fields laid out (`docs/formats/DTPK.md`)
- [ ] Indirect-call group discovery: jsr sites whose target reg is a *caller argument* - cluster by containing function (task-runner pattern at f_8c0198e4 etc.)
- [x] TEX format broken: RGB565 + PVR twiddle — first visually verified decoded asset (AKI face)
- [x] POL format v1: tagged structure + offset map (docs/formats/POL.md)
- [x] **M3-D: DTPK fully parsed + AICA ADPCM audio decoded** (69/69 packages split; all voice packs playable WAV + waveform-verified; BGM kits partial)
- [x] **M3-C: architecture mapped** — struct-dispatch VM model, 146 switch tables, loader chain named, boot region characterized (docs/re/architecture.md)
- [x] **M3-A/B: fuzzy matching done** (964 xbuild pairs) + fnptr/xref miners
- [ ] POL packet dissector (first bytes `00 02 00 00 21 10 98 19 ...`)
- [ ] Investigate `.CLI` = collision (COLI_S dev path), MOTHEAD/MT* motion tables
- [ ] docs/re/: write-up of entry/GDFS init/main-loop/task system once identified

## M3 — "Boot to Battle" core RE (DONE 2026-09-17)
- [x] A fuzzy matching pipeline: 964 cross-build function pairs
- [x] B switch/struct-dispatch topology: 146 tables, ~80 runners, loader fns named
- [x] C architecture doc (docs/re/architecture.md); boot region surveyed & documented
- [x] D DTPK container fully decoded + AICA ADPCM audio extraction (all voice packs)

## M5 — Port modules + scene identification (DONE)
- [x] src/media/{dtpk,aica_adpcm,mt,pol}.c — clean-room C, parity-tested vs Python refs
- [x] Fight-scene suspects identified (see docs/re/fight_scene.md)

## M6 — Runtime tracing rig (IN PROGRESS)
- [x] flycast cloned + stripped (norend, headless main, VF3_TRACE byte-stream)
- [x] interpreter-mode trace pipeline working (427M instrs boot+title captured)
- [x] fn hit-counts + first-seen analysis (594 fns in 1200 frames)
- [x] **JIT path FIXED (2026-09-18)**: headless branch returned before
      `os_InstallFaultHandler()`, so the missing flycast VEH meant fpcb pages were never
      committed on demand → `bm_GetCodeByVAddr+0x27` AV at the fpcb base. Fix: install
      the fault handler inside the headless block (winmain.cpp).
- [x] Block-level JIT tracing: `vf3TraceInstr(addr,0)` hook in `bm_GetCodeByVAddr`
      (blockmanager.cpp) → ~67 blocks/frame; 12K frames ≈ 3 min wall.
- [x] Executor toggle: `VF3_INTERPRETER=1` env → interpreter (override re-asserted
      right before `emu.start()` since per-game settings reload at loadGame resets it)
- [x] JIT trace validated against interpreter (scene_mgr_B first-seen/hit pattern matches)
- [x] SEH diagnostic: `vf3_seh` logs faults to `extract/analysis/vf3_fault.log`
      (unbuffered writes, survives process teardown)
- [x] **FIGHT CAPTURED (2026-09-19)**: scripted GUI play (vf3script: file-driven
      KEY/SHOT/SAVE/EXIT timeline) → savestate at fight → headless `VF3_STATE` load
      → 6K-frame JIT trace: 363 fns, **fight-only delta = 347**, `bjload_run`
      950 hits, `scene_mgr_B` 29.8K hits; all 347 named `fight_f_*` in Ghidra
      (docs/re/fight_scene.md)
- [x] GUI sibling build `tools/emu/flycast-build-gui` (SDL+OpenGL, playable,
      mapping `F1/F2/F3/F4` = state save/load/slot+-)
- [~] transition capture: in-fight state confirmed (AKIRA vs JACKY on Jacky stage,
      loader strings in RAM); demo-fight ladder (15 states) shows fight code grows
      after t≈60s while mt_loader/coli_run stay dead (char-select loaders ≠ demo);
      **root-caused runaway SAVE crash** = racy dc_savestate on live SH4 → now
      serialized internally (vf3script SAVE)
- [~] RAM/VRAM raw dumps via SHOT; fight RAM strings land M_JACKY, MTJACKAG.BIN
- [ ] named `fight_f_*` are dispatch waypoints, not fn heads; needs a
      CFG-splitter pass keyed on trace entry points before any decompile pass
- [x] Fight-loop anatomy doc (docs/re/fight_loop.md): top-40 frame budget,
      struct field hints roll-up, input-chain note, fight artifacts inventory
- [x] VF3TB Model Extractor (NaomiMod) cloned and smoke-tested
      (extracts POL/TEX correctly; a 2nd source for the POL format spec)
- NOTE1: short interpreter runs may sit in the reios vblank-poll loop in the norend
      build; gate on the `[vf3] ran N frames` log line, not wall clock
- NOTE2: GL screenshots via `GetLastFrame` return empty on this host (no usable
      frames in GUI either); rely on fn-level trace telemetry instead of pixels

## M4 — Fight engine RE & port scaffold (next)
- [ ] Per-voice BGM decode (note-reset slicing from sec1/sec3)
- [ ] Fight-mode dispatcher identification (scene table idx by string-class)
- [ ] MT*.BIN motion table parser + model/animation linkage
- [ ] src/: AICA ADPCM module + DTPK loader as first clean-room port units
- [ ] Ghidra: CFG-aware splitter for DSGLH regions (replaces prologue sweep)
