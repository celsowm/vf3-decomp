# Coverage roadmap — next batches (2026-09-25)

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
- Coverage: rigorous **280/2398 (11.7%) / 44,660 B (10.3%)**.

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
| now | 275 | 11.5 | 44,212 | 10.2 |
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
| 0x8C0AC252 | 1528 | 488 |
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