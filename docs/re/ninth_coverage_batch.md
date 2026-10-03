# Ninth C coverage batch

Drains a further **9 complete functions** that the previous batches had to skip
because the strict-replay dispatch was unattributed in the ledger. Each entry was
re-captured (or already captured in `fifth_leaf_*` / `phase1_*` / `motion_*` /
`fight_*` runs), replayed under `vf3matrixfamily.exe` against the untouched
identity image, and proved under `VF3_STRICT_REPLAY=1`.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 788/2398 (32.9%) | 797/2398 (33.2%) | +9 fns |
| rigorous bytes | 176,958/434,656 (40.7%) | 177,952/434,656 (40.9%) | +994 B |
| verified C address union | 135,964 B | 136,958 B | +994 B |

`tools/portcheck.py` passes across all 589 bindings (was 580; +9).

## Strict invocation replay

### Promoted leaves (9 entries, distributed across existing adapters)

| entry | frozen | dev / holdout / fresh | strict | owner |
|---|---|---|---|---|
| `0x8C0AD878` | 314 B | 24 / 7 / 6 | PASS | `fifth_adapters.c` |
| `0x8C093BFA` | 152 B | 3 / – / 4 | PASS | `motion_adapters.c` |
| `0x8C08D0B4` | 58 B | 64 / 64 / – | PASS | `fight_adapters.c` |
| `0x8C08C162` | 56 B | 64 / 21 / – | PASS | `fight_adapters.c` |
| `0x8C08D9CA` | 42 B | – / 4 / – | PASS | `device_adapters.c` |
| `0x8C0AC144` | 32 B | 2 / 3 / 1 | PASS | `fifth_adapters.c` |
| `0x8C0A7750` | 32 B | 60 / 61 / – | PASS | `matrix_adapters.c` |
| `0x8C08CCFC` | 160 B | 3 / 3 / 3 | PASS | `phase1_adapters.c` |
| `0x8C091B60` | 148 B | 4 / – / 4 | PASS | `motion_adapters.c` |

**Subtotal**: 994 frozen bytes; **366 strict cases** across dev/holdout/fresh corpora.

### Discovery mechanism

The eighth batch had already written the full per-case `*.cases` and `*.ops.json`
for these entries (the capsule survey that produced the eighth `pc`-watched
kernel). The remaining gap was that some leaf-sized bodies had a working
adapter dispatch (each `vf3_*_adapter_contains(entry)` returns 1) but were
missing the oracle-verified binding row. Each leaf was validated end-to-end
under `VF3_STRICT_REPLAY=1` (full register + banked XF + FPUL + GBR + return-PC
+ touched RAM + device-tape equality) against the directory holding the most
distinct case lines.

The adapter-corpus intersection was confirmed via `tools/find_owner.py` (read
each adapter's `owned_pcs[]` and check `entry in addrs` after stripping the
P1/P2 mirror bit). The dominant observation: **the dispatch chain is already
correct for these bodies** — the lift was bookkeeping.

## Bindings and build

- `tools/golden_bindings.json` — 9 new bindings (589 total). Labelled
  `{owner}:0x8c…` to match the existing format and avoid the strict-replay
  silent-fallthrough trap that removed 13 stale entries in the eighth-batch
  pass. Each binding links `build/vf3matrixfamily.exe <entry>` to its dev
  cases (`extract/analysis/<owner>_*dev*_cases/f_<entry>.cases`) and requires
  `VF3_STRICT_REPLAY=1`.
- `tools/watch/vf3_ninth_batch.txt` — 9 pc-roots for traceability.
- `docs/decomp_status.csv` — 9 new `ported` rows, sorted by entry address.

## How this advances the decomp

The advance plan in `docs/re/advance_plan.md` ranked the remaining levers as
(0) freeze census, (1) drain the executed pool, (2) build the synthetic-entry
+ scenario levers, (3) Phase 3 named closures. The ninth promotion is a
**Phase 1-style drain** of the executed pool: every entry has ≥1 strict-replay
corpus, ≥1 distinct scenario, and an adapter in the dispatch chain. The
corpus origin (which `*_cases/` directory holds the most case lines per entry)
is reported per row above.

The 7 trace-executed entries that remain (after this batch's 9 promotions
removed 10 from the trace-claim cohort) are still behind code paths no current
scenario exercises; Phase 3 synthetic-entry capture and new scenario
campaigns (the levers ranked (2)/(3) in the plan) remain the only way to
reach them.