# Coverage roadmap — next batches (2026-09-25)

## Recalibration (2026-09-28)

- Refreshed starting baseline: **290/2398 (12.1%)**. The requested +10
  percentage-point floor is **530 functions** (22.1%), so the remaining gap is
  **240 unique baseline functions**. Use 550 as the working target to leave a
  20-function margin.
- The earlier Campaign A/B/C forecast of 455–465 functions does not meet that
  floor; it leaves a further 65–75 functions to source. Do not treat the
  forecast as completion criteria.
- Investigated the E3 executable as another attribution corpus. Its bytes are
  exactly `1ST_READ.unsc.bin[0x10000:]` (the E3 image is the same retail byte
  span at a shifted load base). This confirms build identity but contributes
  **zero independent decomp coverage** and must not be credited.
- `sdk053_regmask_matches.csv` contains 258 matches, but only one uncovered
  full-body structural match (`0x8C074AFE`, 16 B); that match changes a register
  operand (`mov r3,r14` vs `mov r4,r14`) and is not equivalent evidence. The
  other full-body structural hits are already covered by stronger attribution;
  partial opcode fragments remain uncredited. Keep the existing conservative
  SDK counts.
- The current captured hot queue has no remaining simple call-free function
  with both a verified `rts` exit and a usable golden set. The next useful
  coverage tranche must add a scenario/capture campaign or a new attributable
  SDK corpus; the current hot-port list alone cannot reach 530.
- Added the first port from the fresh register-only candidate sweep:
  `0x8C0CBEFC` (200 B), verified against 64 paired register+RAM cases after
  adding the SDK `__divls` helper's observable stack saves; `0x8C040F1E`
  (74 B), verified against its one captured allocation call including AICA
  memory; and `0x8C0747D8` (40 B), verified against 64 paired cases over
  seven RAM windows. The full gate now reports **293/2398 (12.2%)** rigorous,
  leaving **237 functions** to the 530-function floor and **257** to the 550
  working target. Campaign E's 44 archived states exposed `0x8C0747D8` in
  states 26-29. The next candidate (`0x8C070832`) has 64 RAM captures but is a
  32-byte FPU block with no `rts` in its inventory span, so it is not yet a
  complete function candidate.
- Campaign E follow-up: the four high-yield archived states produced captures
  for 42 of 120 watched A/B PCs in states 26-29. `0x8C0935F4` is the only
  remaining new complete leaf in that batch, but it did not execute in any of
  the 44 archived states. `0x8C06951A` appeared in states 28-29; its closure
  includes `0x8C068DE4` and an unresolved dynamic helper at `0x8C0695EC`
  (runtime target `0x0C087ACE`), so track it as a closure-chain task.
  `0x8C070852` now has more contexts but remains outside the gate until its
  loop-carried FPU results can be explained and verified.
- Campaign C follow-up: recovered and swept the SDK 8 Europe SHINOBI core
  libraries (15 libraries, 2,005 objects). The corpus produced 30 complete
  SDK body matches, all already credited by stronger evidence. The only extra
  exact interval was an incomplete 4-byte function prefix and is excluded.
  A separate Japan SDK 1.0 Joliet/Mode-2 sweep extracted 3,608 objects and
  found 87 full-body matches, also all already credited. Both sweeps add zero
  functions, leaving 237 to the requested floor. See `docs/re/sdk8_eu.md`.
- Campaign C follow-up: recovered SDK9 Europe Disc1/2. Disc1's release
  libraries produced 4,020 modules; the full file-tree sweep found 48 complete
  baseline bodies, all already credited. Disc2 produced six partial matches
  and no full bodies. No new function credit; details in `docs/re/sdk9_eu.md`.
- Behavioral follow-up: isolated the hidden closure behind the 32-byte
  `0x8C09F6DC` loop. Forced Ghidra entry `0x8C09F6FC` and captured 252 calls /
  64 unique paired cases across states 26-29 with data+stack RAM windows.
  Ported the helper and caller, then passed 64/64 helper and 18/18 caller
  paired register+RAM replays. Only the 32-byte baseline caller is counted;
  current rigorous coverage is 294/2398 (12.3%), leaving 236 to the 530
  function floor and 256 to the 550 working target. Details:
  `docs/re/f9f6dc_closure.md`.
- Recovered the parked `0x8C0AF734` port by pairing its entry with the watched
  caller return PC named by saved PR. The old trace-depth exit included caller
  stack cleanup and could not validate the function. New chronological pairing
  produced 64 unique cases over 14 RAM windows; the corrected caller-stack
  epilogue and rare FPU path pass all 64. Rigorous coverage is now
  **295/2398 (12.3%)**, leaving **235** functions to the 530 floor and **255**
  to the 550 working target. See `docs/re/af734_probe.md`.
- Campaign B closure: captured `0x8C0CC148` from 18 archived states (304 calls,
  64 unique inputs), then widened the data and stack windows until the register
  and RAM replay passed all 64 cases. The port reuses both verified range-
  reduction entries at `0x8C03A6E0` and `0x8C03A140`. Rigorous coverage is now
  **296/2398 (12.3%)**, leaving **234** functions to the 530-function floor and
  **254** to the 550 working target. See `src/fight/cc148.c` and
  `extract/analysis/goldens_cc148_ram3/`.
- Campaign A candidate check: recaptured `0x8C071668` with 1,400 invocations,
  64 unique paired register+RAM cases, and no unpaired exits. The 44-byte
  fragment tail-jumps to `0x8C071400`, inside the neighboring FPU routine
  `0x8C0713F0`; its traced outputs therefore include that shared FPU closure.
  The data window is unchanged and stack writes are captured, but the shared
  FPU body still needs its own verified model. Keep `0x8C071668` out of the
  coverage ledger until that closure is modeled; capture recipe and notes:
  `docs/re/candidate_71668.md`.
- Campaign E follow-up: ported `0x8C0C5DBE`, a guarded resource lookup that
  updates a per-index table and delegates allocation to verified `0x8C040F1E`.
  The capture covers 56 paired calls; all 54 distinct register+RAM cases pass
  across eight windows, including the AICA pool and the full table span.
  Rigorous coverage is now 297/2398 (12.4%), leaving 233 functions to the 530
  floor and 253 to the 550 working target. See `src/fight/c5dbe.c` and
  `extract/analysis/goldens_c5dbe_ram4/`.
- Campaign B follow-up: ported `0x8C0B10AA`, a complete 138-byte object and
  flag update. Its nested `0x8C09553C` callback was replayed over 64 additional
  state-37 pairs; both caller and helper match register and RAM exits. Rigorous
  coverage is now 298/2398 (12.4%), leaving 232 functions to the 530 floor and
  252 to the 550 working target. See `src/fight/b10aa.c` and
  `extract/analysis/goldens_b10aa_ram3/`.
- Campaign E follow-up: ported `0x8C0C6EC4`, a 306-byte flag-selected vector
  update using the already verified `0x8C0C7050` helper. All 64 paired
  register+RAM cases pass across six windows. Rigorous coverage is now
  299/2398 (12.5%), leaving 231 functions to the 530 floor and 251 to the
  550 working target. See `src/fight/c6ec4.c` and
  `extract/analysis/goldens_c6ec4_ram/`.
- Follow-up candidate check: captured `0x8C0C674A` and its `0x8C0C678E`
  callee with 64 unique paired cases and the wider RAM windows required by the
  existing body port. The body replay passes 41/64; 23 contexts still disagree
  on FR9 (`0x40400000` vs `0x40000000`), so the wrapper is not creditable yet.
  `0x8C0C6E7E` also has 64 unique captures, but its `0x8C09EA58` dynamic entry
  has no separate baseline-function attribution. Keep both out of the count
  until their closure behavior is resolved; captures are in
  `extract/analysis/goldens_c674a_full/` and
  `extract/analysis/goldens_c6e7e/`.
- FR9 follow-up: repeated the saved fight-state capture for `0x8C0C678E` with
  the mesh root span added (`0x0CBC0000..0x0CC20000`). It yielded 164 pairs,
  64 unique cases, and zero unpaired exits. The window now contains the lookup
  root at `0x0CBCE800` and its selected relative-node records. The replay still
  needs the final `0x8C06912A` FPU path modeled; no coverage credit is claimed.
  Reproduce with `tools/watch/vf3_c678e2_cbc.txt` and the same saved state used
  for `goldens_c674a_full`.
- FR9 return probe: sampled `0x8C069296` with a 512-case cap and captured 512
  unique returns. The `0x8C0C6CB0` call site contributes 29 unique contexts;
  FR9 changes from 3.0 to 2.0 at its tenth distinct context, where the helper's
  selected local mesh record changes from `0x0CBD9618` to `0x0CBD9640`. The
  `0x8C0C6BC2` call site remains at 3.0 for all 29 contexts. This narrows the
  remaining port work to the helper's record-selection path, but still does
  not earn coverage credit. Reproduce with
  `tools/watch/vf3_c678e2_fr9ret.txt`, `--ramn 512 --max-samples 512`, and the
  saved fight state.
- FR9 paired-entry follow-up: captured `0x8C06912A` and its return `0x8C069296`
  together, producing 351 row-aligned entry/return cases. The second
  `0x8C0C6CB0` call changes FR9 from 3.0 to 2.0 while staying in grid cell
  `(22,18)`. The helper's table base is `[0x0C29BCC4+0x1F0]` (`0x0CBCE818`);
  the selected cell stores a root-relative mesh offset. A further nested probe
  of `0x8C068FE4` yielded 7,899 calls / 512 unique entry-return cases, with
  result codes 0/2/4. This isolates the remaining discrepancy to polygon
  selection within one cell, rather than a cell-index or root-pointer error.
  No coverage credit yet. Reproduce with
  `tools/watch/vf3_c678e2_helperpath.txt` and
  `tools/watch/vf3_c678e2_polywalk.txt`, each using the saved fight state and
  `--ramn 512 --max-samples 512`.
- FR9 lookup-table follow-up: widened the `0x8C0C678E` RAM capture through
  `0x0C29D7C0` to include the table pointer at `0x0C29BEB4`. The helper selects
  a cell by `(trunc(16+fr4)&31) | ((trunc(16-fr5)&31)<<5)`; for the first
  `0x0C0C6CB0` contexts that is cell `0x256`, whose root-relative list starts
  at `0x0CBD9608`. Nested `0x8C0691EA` captures show the walk stopping at
  `0x0CBD9618` (FR9 = p0.y = 3.0) early and `0x0CBD9640` (p0.y = 2.0) later.
  A dynamic lookup model removed the earlier stack-window mismatch and raised
  the widened replay from 41/64 to 59/64. Five odd-numbered edge contexts still
  disagree on final FR4; the selected descriptor alone does not explain those
  exits. Keep `0x8C0C678E` uncredited until all registers and RAM match. The
  widened capture is 168 paired calls, 64 unique cases, zero unpaired;
  reproduce with the saved fight state and `tools/watch/vf3_c678e2_cbc.txt`.
  The post-classifier capture is 717 unique paired cases at `0x8C0691EA`; use
  `tools/watch/vf3_c678e2_walkafter.txt`.

## Status checkpoint (end of campaign-0/A-first-port session)
- Campaign 0 (infrastructure): **done** (`96dbf4f`) — batch capture, per-PC
  windows, `port_plan`, `verify_all`, shared harness; plus three fork
  capture-integrity fixes and the game's FPSCR.RM=1 truncation semantics
  (`e451afc`, documented in `port_oracle.md`).
- Campaign A: first port landed — `0x8C068E16` -> `src/fight/scalemap.c`,
  **32/32 RAM-shadow cases PASS**. Campaign A list refreshed by `port_plan`
  (42 fns / 12,466 B remaining).
- Capture sets refreshed with the fixed fork: `goldens_abreg` (85 fns regs),
  `goldens_ab` (85 fns, 8 RAM cases each).
- `0x8C06951A` (single-lookup sibling of scalemap): real function, but it
  does not execute in the fight state nor in the old fight savestates
  (`vf3_1..30`, 120 frames) — needs a menu/attract/particle capture
  (Campaign E). Draft port removed until it can be golden-verified.
- Campaign A, S-batch part 1 (landed): `0x8C0930B6` -> `src/fight/fvecadd.c`,
  **8/8 RAM-shadow cases PASS** (S2 batch: `tools/watch/vf3_s2*.txt` ->
  `extract/analysis/goldens_s2b/`); bound in `golden_bindings.json`,
  row in `decomp_status.csv`, `portcheck` green (14 tests + 8 binds).
- Campaign A, S-batch part 1 (parked): `0x8C070852` (`src/fight/fvecmix2.c`)
  is NOT verifiable in its capture window — float exits carry loop-carried
  FPU pipeline state (448+ ULP gaps vs any single rounding of the entry
  bytes) and the exit RAM holds stores from below-window code
  (`0x8C0708B4+` reload/fsqrt path, `0x8C06F948+` epilogue). Kept in-tree
  as a documented skeleton, out of the `portcheck` gate and unbound until
  re-captured with tighter windows (S3/sbatch provenance kept in
  `tools/watch/vf3_s3*.txt`, `vf3_sbatch*.txt`, `vf3_s3pair.txt`).
- Campaign A, S-batch part 2 (landed): `0x8C092BC6` -> `src/fight/scaler3.c`,
  **8/8 RAM-shadow cases PASS**. Re-captured with a 4th window covering the
  caller scratch page (0x8c092bc6's scale input at `[r2+20]` was outside
  the old 3-window slice), so RM=truncate products verify byte-exact via
  `fpu_tz.h`. New tool/watch set `tools/watch/vf3_s4.txt` ->
  `extract/analysis/goldens_s4/`.
- Campaign B, first port (landed): `0x8C0C2B80` -> `src/fight/frameseq.c`,
  **8/8 RAM-shadow cases PASS**. Bounded linear sequencer (6 bsr/jsr into
  scene/particle helpers + frame counter RMW + tail-pop); the port owns the
  prologue/sequencing register state while the 6 sub-steps' FPU churn is
  (documented) delegated-match. New test `vf3frameseq`.
- Coverage: rigorous **282/2398 (11.7%) / 44,844 B (10.3%)**.

Baseline snapshot (`tools/decomp_stats.py`, HEAD `0bbd92c`):
rigorous **275/2398 fns (11.5%) / 44,212 B (10.2%)**; identified
executed-but-unaccounted **161 fns / 63,662 B**; hot backlog (>=10k hits)
**45 fns / 13,396 B** (44 unaccounted; 0x8C063D36 is SDK-attributed).

Two KPI families:
- **rigorous** = ported + SDK-attributed (fns and body bytes),
- **executed-universe** = of the 161 traced fns / 63,662 B, how many bytes are
  rigorous (currently ~0 — all 161 are in the trace bucket).

## Milestone math (disjoint target sets, no double counting)

| after | fns | fn % | body bytes | byte % |
|---|---|---|---|---|
| recalibrated now | 291 | 12.1 | 57,294 | 13.2 |
| + Campaign A (42 new hot fns, 12,816 B) | 317 | 13.2 | 57,028 | 13.1 |
| + Campaign B top-25 (35.0 KB, incl. 3 giants) | 342 | 14.3 | 92,006 | 21.2 |
| + Campaign B rest (102 fns, 17.0 KB) | 444 | 18.5 | 108,992 | 25.1 |
| + Campaign C (SDK normalized/archive, +10-20 fns) | 455-465 | 19-19.4 | 113-119 KB | 26-27 |

Executed-universe KPI: A ∩ executed (11,632 B) + B top-25 (34,978 B) =
46,610 / 63,662 = **73% of hot-executed bytes verified**.

Excluded from campaign math: `0x8C0C148E` (2 B, vestigial segmentation),
`0x8C092F12` (10 B, trivially verifiable), and the 100 baseline fns <= 8 B
(486 B total). Denominator stays the frozen 2398-fn baseline for continuity.

## Campaign 0 — port infrastructure (enablers, do first)

| # | item | why |
|---|---|---|
| 0.1 | fork: `VF3_RAMPC` 8 -> 32 PCs; `VF3_RAMWIN` 4 -> 8; per-PC window spec (`rampc <pc> <base> <len>`) in the watch file | capture 30+ fns' goldens in one run without 700 MB dumps |
| 0.2 | fork: `VF3_FULL=2` call-edge log (caller, callee, depth) CSV | closure checks + static call-graph validation of ports |
| 0.3 | `tools/golden_batch.py`: scenario runner + manifest (boot / menu->fight / training / soak), one watch file per batch | scales golden capture from 6 PCs/run to whole campaigns |
| 0.4 | `golden_extract.py` v2: manifest-driven batch extraction, entry+exit RAM pairing, window diffs, `.cases` + `.meta` | removes per-port manual extraction |
| 0.5 | `tests/port_harness.h` + CMake `add_port_test()`: generic `.cases` runner (r0-r15/PR/SR/FPSCR/MACL/MACH/FR + byte-exact RAM diff + OOB counter) | port test drops to ~30 lines; makes 40+ ports tractable |
| 0.6 | `tools/port_plan.py`: join backlog x executed x SDK claims x static calls -> `extract/analysis/port_plan.csv` (closure_ok, effort, campaign) | keeps the target list honest and regenerable |
| 0.7 | `tools/verify_all.py`: build + portcheck + decomp_stats + union verify in one command | per-batch gate |
| 0.8 | refresh `disasm_*.calls.csv` / callgraph outputs; resolve indirect call targets where statically known | closure correctness |

## Campaign A — hot small fns (45 hot; 42 new / 12,816 B)

### A1 — hot <= 400 B (35 fns / 5,400 B; excludes 2 B junk)

| entry | size | hits | leaf | out | exec |
|---|---|---|---|---|---|
| 0x8C0738FC | 336 | 2029489 | 0 | 4 | Y |
| 0x8C068E16 | 352 | 872981 | 1 | 0 | - |
| 0x8C03EFF4 | 66 | 340812 | 1 | 0 | Y |
| 0x8C06F6F8 | 88 | 321482 | 1 | 0 | Y |
| 0x8C071A76 | 66 | 227290 | 1 | 0 | Y | (head ported; finish routine) |
| 0x8C070852 | 34 | 163826 | 1 | 0 | Y |
| 0x8C068C72 | 156 | 163686 | 0 | 1 | Y |
| 0x8C09D480 | 48 | 135905 | 0 | 1 | Y |
| 0x8C0708B0 | 208 | 130078 | 1 | 0 | Y |
| 0x8C06939E | 354 | 121723 | 0 | 2 | Y |
| 0x8C091C3A | 344 | 120627 | 0 | 2 | Y |
| 0x8C09D452 | 46 | 96645 | 0 | 1 | Y |
| 0x8C06951A | 228 | 90068 | 1 | 0 | - |
| 0x8C06912A | 350 | 82125 | 1 | 0 | Y |
| 0x8C0C148E | 2 | 58424 | 1 | 0 | - | junk segmentation |
| 0x8C070120 | 206 | 50109 | 1 | 0 | Y |
| 0x8C092F12 | 10 | 39743 | 1 | 0 | - |
| 0x8C09D9EC | 50 | 39267 | 1 | 0 | Y |
| 0x8C071E3A | 60 | 34270 | 0 | 2 | Y |
| 0x8C070A84 | 208 | 30339 | 1 | 0 | - |
| 0x8C092BC6 | 76 | 27941 | 1 | 0 | Y |
| 0x8C092ABE | 24 | 27185 | 1 | 0 | - |
| 0x8C06FF64 | 164 | 23549 | 0 | 1 | Y |
| 0x8C071668 | 44 | 17135 | 1 | 0 | - |
| 0x8C058D88 | 146 | 16884 | 1 | 0 | - |
| 0x8C07030C | 208 | 16573 | 1 | 0 | Y |
| 0x8C0935F4 | 30 | 15310 | 0 | 1 | Y |
| 0x8C09F6DC | 32 | 14538 | 1 | 0 | - |
| 0x8C096258 | 178 | 13600 | 0 | 1 | Y |
| 0x8C0CC148 | 210 | 12020 | 1 | 0 | Y |
| 0x8C08DEF0 | 208 | 11710 | 0 | 1 | Y |
| 0x8C0B1144 | 140 | 11684 | 1 | 0 | - |
| 0x8C0CB9F0 | 316 | 10992 | 0 | 1 | Y |
| 0x8C0A9E6A | 208 | 10512 | 1 | 0 | Y |
| 0x8C070CF0 | 204 | 10167 | 1 | 0 | Y |

Batching (by address cluster, 1 commit each): `0x8C068x` (6), `0x8C070x` (7),
`0x8C09Dx` (3), `0x8C09Ex` (5), `0x8C091x/92x/93x/96x` (8),
`0x8C0Cx` (3), misc (9).

### A2 — hot > 400 B (10 fns / 7,996 B; 0x8C063D36 already SDK)

| entry | size | hits | leaf | out | exec |
|---|---|---|---|---|---|
| 0x8C09E078 | 826 | 224276 | 0 | 3 | Y |
| 0x8C09144E | 766 | 81604 | 0 | 1 | Y |
| 0x8C09E6C8 | 778 | 77967 | 0 | 1 | Y |
| 0x8C09DCEA | 710 | 64531 | 1 | 0 | Y |
| 0x8C09EAF2 | 656 | 48336 | 0 | 1 | Y |
| 0x8C063D36 | 512 | 43802 | 1 | 0 | - | SDK-attributed, skip |
| 0x8C0C1FD8 | 606 | 31515 | 0 | 1 | Y |
| 0x8C0B08BC | 1374 | 23009 | 0 | 4 | Y |
| 0x8C0B1560 | 1090 | 12101 | 1 | 0 | Y |
| 0x8C0BF16A | 678 | 10559 | 0 | 1 | Y |

## Campaign B — executed clusters (top-25 = 34,978 B)

| entry | size | hits |
|---|---|---|
| 0x8C0750BE | 5432 | 19 | giant A |
| 0x8C0782EA | 4472 | 1065 | giant B |
| 0x8C076C00 | 4138 | 2827 | giant C |
| 0x8C0C5062 | 2236 | 6804 |
| 0x8C0BF50A | 2130 | 2919 |
| 0x8C081194 | 1744 | 2268 |
| 0x8C0AC252 | 1528 | 488 static / 73 instr-confirmed (trace_long P2-alias prologue hits, late-scenario bursts; footprint 242 PCs over 0xAC252..0xAD19A chain, tools/ac252_foot.py) |
| 0x8C0C678E | 1496 | 9661 |
| 0x8C0AB35A | 1118 | 10 |
| 0x8C0B011E | 1086 | 584 |
| 0x8C074158 | 970 | 1585 |
| 0x8C0C86EE | 960 | 674 |
| 0x8C0CAB46 | 920 | 184 |
| 0x8C0AFB76 | 762 | 6674 |
| 0x8C074B0E | 688 | 4 |
| 0x8C08E920 | 666 | 756 |
| 0x8C09635A | 616 | 3024 |
| 0x8C0BFEF4 | 566 | 109 |
| 0x8C0927FA | 556 | 1511 |
| 0x8C08E6A8 | 544 | 5493 |
| 0x8C0AD5AA | 492 | 163 |
| 0x8C0A9C52 | 478 | 3024 |
| 0x8C051F8E | 478 | 6 |
| 0x8C06F46A | 466 | 4774 |
| 0x8C0AA208 | 436 | 16 |

Order: mediums first (build the harness/closure muscle), giants as dedicated
milestones. Three giants alone = 14,042 B = 3.2% of all body bytes.
Page totals of the B set (127 fns / 51,964 B): 8c07 17.7 KB, 8c0a 9.5 KB,
8c0c 7.1 KB, 8c08 6.4 KB, 8c0b 4.8 KB, 8c09 4.3 KB, rest 2.1 KB.

Validation for giants: piecewise `pair_cases` per basic-block region, then a
whole-fn entry/exit RAM diff; callees must be ported or SDK-accounted
(`port_plan.py` closure flag) before whole-fn validation is claimed.

## Campaign C — SDK recovery (rigorous without behavior work)

- C1 archive hunt: catalog the sega-dreamcast-info library archive; download
  1998-era Katana/DCSDK drops with GDFS/mpdrv/pdmain/lib libs; inventory.
- C2 sweep each new corpus with `libmask2`/`sdk_sweep`, verify with
  `verify_union.py` (0 concrete mismatch requirement).
- C3 `tools/sdk_norm_match.py`: revision-equivalent matcher for same-source
  different-revision library code (canonicalize regs/literals, basic-block
  hashes, >=95% normalized alignment, identical call skeleton).
- C4 `tools/verify_sdk_norm.py`: per-fn evidence (diff list limited to
  reloc/literal/reg-allocation classes); new honest bucket
  `SDK-equivalent (normalized)` documented in `docs/re/sdk_norm.md`.
- C5 attach `.lib` module names to matched regions for readability.

## Campaign D — in-emulator port substitution (stretch, verification at scale)

- D1 `VF3_SUBST` registry: PC -> C function pointer, register/FPU bridge,
  shadow-run the interpreter and compare post-state; abort+log first
  divergence. Interpreter stays authoritative.
- D2 first substitute on an already-ported hot fn (poly_classify / vecpush)
  inside a real fight trace; thousands of invocations vs 16 golden cases.
- D3 use divergence reports to harden ports (edge cases goldens missed) and
  to rank unverified paths.

## Campaign E — capture diversification (grows the target universe)

- E1 scenario scripts beyond `vf3_play_m26`: training, replay playback,
  attract/demo loop, 2P mirror, character select, sound test (savestates).
- E2 soak run with `VF3_WATCH` over all campaign PCs; `goldens_b2/` manifest.
- E3 `docs/re/executed_universe.md`: fn map (hits, golden, port status) and
  the executed-coverage KPI.

## Rules and gates

- Every claim needs: golden/`.cases` artifact + replay PASS in `portcheck` +
  `decomp_status.csv` row + green build. Commit per batch, never mixed.
- Keep `ported` / `SDK-*` / `trace-executed` separate; add the normalized
  bucket only with per-fn evidence.
- Report both rigorous and executed-universe coverage in `docs/coverage.md`.

## Risks

- Giants may hide BRAF/indirect dispatchers -> `braf_tables.py` first,
  budget 2 sessions each.
- Campaign B mediums with unported callees -> closure order via `port_plan`,
  piecewise validation until closure completes.
- SDK scarcity persists; normalized matcher may be noisy -> require
  diff-class evidence and cap claims to full-fn equivalence.
- 42 small ports is derivation-heavy -> harness + batched goldens are the
  mitigation; if a batch stalls, skip and revisit after substitution lands.
