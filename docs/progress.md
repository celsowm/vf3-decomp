# VF3tb decomp — progress log

## Campaign B: cntup port 0x8C08B7EE (2026-09-26)
- [x] Triaged the 3-diff candidates: both `0x8C08B7EE` (68 B) and `0x8C0AF734`
  (168 B) carry hidden calls the static `calls.csv` misses (bsr pair /
  RAM-vector jsr), so `port_plan`'s leaf/closure_ok overclaims them; true
  0-call leaves with goldens are the Campaign-A `0x8C070x` FPU family.
  `0x8C0AF734` (dynamic jsr + FPU fsub pair) deferred; `0x8C0B1560` (1090 B)
  audited as non-leaf (jsr @lit).
- [x] Port `0x8C08B7EE` -> `src/fight/cntup.{c,h}` + `tests/cntup_replay.c`
  (**8/8 RAM-shadow cases PASS**): own guard pair + final store with the
  callee-1 ladder (`0x8C08B89C..0x8C08BB06`: `[r14+36]/[r14+38]` +1,
  `[r14+22]` -1 with `0x0A` reload from `[r14+46]`, `[r14+28]/[r14+34]`
  zeroed) modelled with a private frame; callee-2 `0x8C08BB14` (+ nested
  calls) delegated with verified zero checked-window footprint (r0-r7, sr,
  fr3 forced from oracle).
- [x] Capture `tools/watch/vf3_b7_ram.txt` -> `extract/analysis/goldens_b7/`
  (70 pairs, 10 windows incl. structB/C + far pages found by simulating the
  ladder's reads); new `tools/cases_dropwin.py` derives the 9-window test
  cases (drops the callee-2-owned stack page); `VF3H_MAXWIN` 8 -> 16 in the
  shared harness. Bound in `golden_bindings.json`, row in
  `decomp_status.csv`, `verify_all` green.
- [x] Coverage: rigorous **283/2398 (11.8%) / 44,854 B (10.3%)**.

## Campaign A start: scalemap port + capture integrity (2026-09-25)
- [x] **Fork capture bugs fixed** (three): trace file reopened/truncated per
  `Run()`; `vf3_seh` calling `vf3TraceFlush` from `DBG_PRINTEXCEPTION_C`
  context (lost ring contents); non-atomic RAM groups. Flush now checks
  `fwrite` count. Early pre-`flycast_init` trace open removed.
- [x] **Game FPSCR = 0x240001 (RM=1 round-toward-zero, DN=1)** discovered via
  golden snapshots; all FPU ports need truncating helpers (`f32_tz` etc.),
  otherwise ~1 ULP mismatches. Documented in docs/re/port_oracle.md.
- [x] Port `0x8C068E16` (352 B, 873k hits) -> `src/fight/scalemap.c`
  (bilinear 128x128 table sampler; helpers 0x8C068D54/0x8C068DE4 internal;
  memory-accurate stack writes): **vf3scalemap 32/32 RAM-shadow cases PASS**,
  bound in golden_bindings + decomp_status row.
- [x] Batch captures: 85 A/B fns with register snapshots and 4-window RAM
  cases (`goldens_abreg`, `goldens_ab`); wide-window recapture for the
  scalemap family (`goldens_e16`); interior-point captures (`goldens_e16int`,
  `goldens_eb4`) used to pin the FMAC/idx behaviour.
- Next: re-capture the A/B set with the fixed fork, then continue A-list ports
  (all FPU ports must use the truncation helpers).

## Campaign 0: batch port infrastructure (2026-09-25)
- [x] Fork: `VF3_RAMPC` up to 32, `rampc <pc> [base len]` watch lines with up
  to 64 per-PC windows (small dumps instead of 16 MB), `VF3_RAMWIN` up to 8,
  `VF3_EDGES` call-edge log with resolved JSR/BSR targets.
- [x] `tools/golden_batch.py` (scenario runner + manifest),
  `tools/golden_extract.py` (multi-trace merge, per-sample scenarios, v2
  `.cases`), `tools/derive_windows.py` (pointer->window watch writer),
  `tools/port_plan.py` (campaign/closure roadmap), `tools/verify_all.py`.
- [x] `tests/port_harness.h` shared replay harness + CMake `add_port_test()`;
  `vf3poly` migrated, harness parses legacy and v2 `.cases`; all tests PASS.
- [x] `tools/callgraph.py` refreshed; roadmap `docs/re/coverage_roadmap.md`
  with milestone math (A 43 fns/12.8 KB, B top-25 35.0 KB -> 21.2% bytes).
- Gate: `verify_all` PASS (build, portcheck, coverage 275/2398, union 31/31).

## Tranche 2: vecpush port + oracle hardening (2026-09-25)
- [x] Fork fixes: JSR/JMP mask (`jmp @Rn` no longer counted as a call);
  `bf`/`bt` have no delay slot (`tools/sh4.py` `DELAYED` set fixed, which
  had mislabelled the orient2 helper); exit-RAM dumps (`0xFA60/0xFA61`,
  `VF3_RAMNEXIT`); multi-window `VF3_RAMWIN` with in-trace base/len.
- [x] `tools/pair_cases.py`: positional entry->interior pairing for
  piecewise validation of tail-jumping/looping functions.
- [x] Port: `0x8C071A76` head block (counter-gated vec3-sub, entry to
  interior `0x8C071ABE`) -> src/fight/vecpush.{c,h};
  tests/vecpush_replay.c compares out-registers, FPU regs and a
  **byte-exact whole-window shadow-vs-interior diff with OOB counting:
  7/7 PASS**. Bound in portcheck; `decomp_status.csv` row added.
- [x] `docs/re/fight_geometry.md`: vec3 idiom, register conventions,
  orient2/poly_classify/vecpush semantics, pipeline + loop structure.
- [x] Naming yield measured (`tools/elf_symtab.py`): **0/213** — all SDK
  sample ELFs are stripped (30/30 whole-file ELFs symtab-free; DCSDK
  1.00J blob has 0 `.symtab`). Decision recorded in
  docs/re/sdk_names_yield.md: no ELF-symbol naming pass.
- [x] Rigorous coverage **275/2398 (11.5%), 44,212 B (10.2%)**; incl-trace
  431 (18.0%) / 106,930 B (24.6%).

## Phase B + C: golden oracle + first oracle-verified port (2026-09-25)
- [x] Flycast `VF3_FULL=1` oracle mode: entry/exit snapshots
  (r0-r15, pr, sr, fpscr, macl, mach, fr0-fr15), call-depth tracking, exit
  after the rts delay slot. `tools/emu/` is gitignored; recipe in
  docs/re/port_oracle.md.
- [x] `tools/golden_extract.py` -> extract/analysis/goldens/*.{json,txt} +
  index (5 fns, 0 unpaired exits; 11k samples for 0x8C068F92).
- [x] `tools/portcheck.py` (goldens + all build tests + golden-bound ports)
  and `tools/golden_bindings.json`.
- [x] `tools/port_backlog.py`: 2,181 unclaimed fns ranked by summed trace heat
  -> extract/analysis/port_backlog.csv; real hot set 0x8C0738FC / 0x8C068FF6 /
  0x8C068E16 (labels in trace_fn_hits are internal points, now mapped).
- [x] Phase C port: `0x8C068F92` (54 B FPU orientation-bits helper, called 5x
  by the #2 hottest fn) -> src/fight/orient2.{c,h}; tests/orient2_replay.c
  replays all 64 unique golden vectors **64/64 PASS**; portcheck PASS.
- [x] Phase C port 2: `0x8C068FF6` (288 B quad classifier, #2 hottest,
  ~1.4M hits) -> src/fight/poly_classify.{c,h}. Oracle grew RAM windows
  (VF3_RAMPC/VF3_RAMN/VF3_RAMWIN) + `.cases` format;
  tests/poly_classify_replay.c **16/16 RAM cases PASS**. Rigorous coverage
  **274/2398 (11.4%), 44,146 B (10.2%)**.
- [x] Finding: no pure-integer function exists in the hot set; hot engine is
  FPU+memory, so the next oracle increment is memory-window capture.

## Phase A: SDK union-corpus sweep (2026-09-25)
- [x] `tools/iso_carve.py`: ISO9660 carver (layout auto-detect) -> SH-4 ELF
  / SYSROF region blob + manifest. SDK release 8 `TOC122A.img`: 1,594 SH-4
  ELFs + 97 libs/objs (21.2 MB) -> extract/analysis/sdk_corpus/sdk8eu.*.
- [x] `tools/sdk_sweep.py`: union matcher over sdk8eu + DCSDK 1.00J samples +
  0.40 libs + Katana 1.0B2 + Kamui2. 362 matched / 213 full-body.
- [x] `tools/verify_union.py`: 31/31 new full-body matches, **0 concrete
  mismatch** (sdk_union_verify.txt, side-by-side disasm).
- [x] New transparent bucket: union corpus 29 fns / 1,184 B + 2 fragments.
  **Rigorous 273/2398 (11.4%) 43,804 B (10.1%); incl-trace 431 (18.0%) /
  106,876 B (24.6%).** Ceiling documented: game GDFS 0.53 vs release-8
  1.02-1.07; exact 0.53 only in DCSDK samples; remainder is custom engine.
  docs/re/sdk_union.md.

## Exact-version SDK acquisition (2026-09-25)
- [x] Downloaded Katana 0.40 Pre.2/Release.4 + SDK release 8 + Sega Library
  1.00J (tools/katana_raw/, gitignored). Version anchors: GDFS 0.46/0.49/
  0.53/1.00/1.06 across drops; game = GDFS 0.53 (1998/08/28).
- [x] Sega Library 1.00J ISO carries 14 SH-4 sample ELFs linked with the
  EXACT game libraries (GDFS 0.53, gdFs Build Sep 07 1998). tools/iso_list.py
  + tools/sdk053_match.py (mask+pool-wildcard full-body matcher).
- [x] 142 full-body matches, 0 concrete mismatch (+66 new fns). Verified
  0x8C064DA0 == blob 0xe5208 instruction-identical. docs/re/sdk053_exact.md.
- [x] Coverage: rigorous 209/2398 (8.7%) 37186 B (8.6%); incl-trace
  367/2398 (15.3%) 100258 B (23.1%). New decomp_stats bucket
  "GDFS 0.53 sample-ELF, exact version" (66 fns). Commit 5248b8a + this.
- [x] Extended to all 18 sample ELFs (carve 78 MB): 182 full-body matches,
  90 exact + 9 fragment new fns. **Rigorous 242/2398 (10.1%) 42178 B (9.7%);
  incl-trace 400/2398 (16.7%) 105250 B (24.2%) — SDK 10% target reached.**

## Coverage fast path (2026-09-25, L1+L4)
- [x] L1 trace bucket: tools/trace_attrib.py + decomp_stats row
  (trace-executed = execution-ID, not ported/matched). 161 baseline fns
  carry trace evidence; 126 unmapped waypoints. docs/re/coverage_fast.md.
- [x] Coverage now: rigorous 122/2398 (5.1%) 27238 (6.3%); incl-trace
  281/2398 (11.7%) 90326 (20.8%) — 10% gate PASSED on incl-trace.
- [ ] L4 top-10 large ports (0782ea=23-dispatch engine; 076c00/0673a8 etc.)
  ship as structural transliteration + replay in follow-up milestones.

## M41–M72 all-tracks sweep (2026-09-25)
- [x] M41 gap: _index.csv 2398 rows (2395 ok + 3 fail: 8c070022/8c08fe62/8c0a6642 FPU+data-island decompiler chokes, sh4full clean) — docs/re/decomp_gap_m41.md
- [x] M42 tiny tail: 1257 <100B / 394 ≤32B inventoried; libmask 596 rows (165 with fns, 431 zero-fn mid-body) — bulk credit needs trace, not statics
- [x] M43 callgraph v3 true image: 2336 edges / 4947 unresolved = 2.8% jsr (ceiling holds); hotspots/calls/dispatch regenerated — docs/re/callgraph_m43.md
- [x] M44 ledger schema: docs/decomp_status.csv gains method,oracle; backfilled; walker/runner rows added
- [x] M45 walker f_8c0b1a54 → src/fight/walker.{c,h} (slot map {1:112,5:0x756C,9:0x7662,14:0x8570,17:0xC4F0} + helpers + @r12 vcall); tests/walker_replay.c PASS; frame.c ladder vindicated
- [x] M47 differential spec: watchcount_boot3 anchor (dispatcher 292033, walker 2048, runner 0 boot-expected) — docs/re/diff_harness_m47.md
- [x] M48 removal island 0x8c03492c documented as marker-discipline TODO — docs/re/ring_m65.md
- [x] M49 task-VM probe spec (r14 0x0CBEFBE0 fight-vs-attract bursts) — docs/re/taskvm_probe_m49.md; task_vm.h hot names stand
- [x] M50 aux state-6 wired: mainloop.c calls vf3_node_finalize (was unported comment); mainloop_replay still PASS
- [x] M52/M53 MT mount: src/fight/mt_mount.{c,h} (slot parse + per-record scatter + hdr abs fixup) + tests/mtmount_replay.c PASS
- [x] M56 sound walkback: tools/snd_walkback.py → 0 pool refs (mova confirmed); snd_walkback.csv header-only; docs/re/sound_walkback_m56.md
- [x] M60/M61 POL+DL: pol_sections() parser + dl.c n_parts fix (lo=11, not lo+(hi<<16)=2686987) + bbox fill; vf3dl PASS (parts=11 triples=416)
- [x] M63/M65 fight handlers + ring matrix (341K/330K/243K edges) — docs/re/ring_m65.md
- [x] M66-M69 loader/CLI/splitter/RELOAD triage — docs/re/loader_m66.md
- [x] M71 top-50: extract/analysis/top50_m71.csv (largest unclaimed; head FUN_8c0750be 5432B, f_8c0782ea 4472B = top dispatcher 23)
- [x] Coverage: 122/2398 fns (5.1%), 27238/434656 bytes (6.3%) — walker +1 fn; build green (vf3dl/walker/mtmount/loop/taskvm/vm/frame/libutil all PASS)

## M30–M40 coverage arc (2026-09-24, docs/plan_m30.md)
- [x] M30 SDK attribution: exact+masked sweeps; 118/2398 fns lib-attributed
  (katana_matches_true.csv, libmask_matches.csv; tools/libmask_match.py).
- [x] M31 batch decompile 2395/2398 fns (Vf3DecompileAll) + coverage
  dashboard (tools/decomp_stats.py → docs/coverage.md).
- [x] M32 SHC runtime leaves ported (src/lib/sh4rt.c; vf3libutil PASS);
  f_8c03482a verified = 5-byte memcmp.
- [x] M33 GDFS/loader: name-ptr table bounded (no static refs → runtime
  linked); MT mount = per-record scatter, +0x27B0 falsified (mt_mount_m33.md).
- [x] M34 task-VM helpers ported (src/sys/taskvm.c; vf3taskvm PASS):
  finalize/unlink/getters/cursor-bump/thunk model.
- [x] M35 recon: walker/fight-runner structure decoded; frame.c ladder
  reinterpreted as offset words (walker_m35.md). Full body port remains.
- [x] M36 differential anchor: tools/trace_watchcount.py +
  watchcount_boot3.csv (dispatcher 292,033 hits in boot window).
- [x] M37 sound layer catalog: libsnd 0.82 mpdrv_* endpoints; framing model
  (src/sys/soundcmd.c); body borders are segmentation-dead-zone.
- [x] M38 DL assembly layer (src/render/dl.c + vf3dl PASS on GEN_DMY5).
- [x] M39 fight-logic catalog (docs/re/fight_tasks_m39.md).
- [x] M40 gate: coverage.md live — 5.0% fn / 6.2% byte attribution.
  Ceiling finding: the binary is ~90% custom engine (SDK ≈ 5%); the 50%
  shaping target in plan_m30 needs full engine port (multi-milestone).
  Gate tracked in coverage.md from now on.

## M29 — Scene walker + fight-runner re-verify (2026-09-24)
- f_8c0b1a54 decoded on true image; 0x8C0B1AA8/AC0 = inline bsrf dispatch
  table words (frame.c cites annotated stale). Walker switch keys {1,5,
  9,14,17} -> scene vcall. docs/re/scene_walker_m29.md.
- f_8c0796f4 = dynamic-entry fight runner (decodes clean; not in baseline
  funcs as expected).

## M28 — Task spawner + pointer-alias rule (2026-09-24)
- Literal dwords are physical (0x0C000000-mirror) addresses; alias rule.
- f_8c0349aa = task spawn/link (alloc f_8c035bf2, init f_8c0356cc,
  register f_8c0355a0 — dispatcher state-6 helper). docs/re/task_spawn_m28.md.

## M27 — Static maps regenerated on corrected image (2026-09-24)
- callgraph/hotspots/braf_tables re-run (11 braf sites, word? kind).
- frame.c ladder audit: pre-M23 addresses stale (table words inside
  f_8c0b1a54); header warning added.

## M26 — BGM kit boundary re-measured (2026-09-24)
- Second AICA ladder (resume vf3_6): kit write 0x17EA00..0x1D1100,
  low region <0x86E54 stable; streaming ring 0x00A000..0x00D000 only.
  docs/re/sound_bgm_m26.md; script tools/emu/vf3_play_m26.txt.

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
