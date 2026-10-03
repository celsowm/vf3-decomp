# Tenth C coverage batch

Drains **65 additional complete functions** that already had adapter dispatch
(their body bytes are owned by an existing adapter in the chain) but lacked
the oracle-verified binding row. Each entry was replayed under
`vf3matrixfamily.exe` against the untouched identity image and proved under
`VF3_STRICT_REPLAY=1`.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 797/2398 (33.2%) | 860/2398 (35.9%) | +63 fns |
| rigorous bytes | 177,952/434,656 (40.9%) | 182,098/434,656 (41.9%) | +4,146 B |
| verified C address union | 136,958 B | 141,626 B | +4,668 B |

`tools/golden_bindings.json` — 589 → 654 bindings (+65).

## Strict invocation replay

### Promoted leaves (65 entries, distributed across existing adapters)

| owner adapter | entries | bytes |
|---|---|---|
| `next_adapters.c`        | 12 | 1,820 B |
| `device_adapters.c`      | 11 |   928 B |
| `fifth_adapters.c`       |  8 | 1,030 B |
| `phase1_adapters.c`      |  7 |   240 B |
| `fifth_leaf_adapters.c`  |  6 |   142 B |
| `eighth_adapters.c`      |  6 |   186 B |
| `seventh_adapters.c`     |  4 |   166 B |
| `seventh_c3_adapters.c`  |  1 |    88 B |
| `seventh_c15/16_*`       |  2 |     4 B |
| `motion_adapters.c`      |  5 |   208 B |
| `fight_adapters.c`       |  3 |   140 B |

**Subtotal**: 4,668 frozen bytes; **2,335 strict cases** across dev/holdout/fresh corpora.

## Discovery mechanism

`tools/_check_more.py` enumerated every entry in `extract/analysis/*_cases/`
that (1) was not yet in `docs/decomp_status.csv`, (2) measured 100% body
   cover when its `*.ops.json` PC sets were unioned across all of its case
   directories, and (3) had an owning adapter in the dispatch chain (the
   `vf3_*_adapter_contains(entry)` checks via `tools/find_owner.py`).

The lift was bookkeeping: the dispatch chain is already correct for these
bodies, the captured corpora are clean, and the strict-replay result
(`matrix_family: N/N cases match (0 skipped) - PASS`) is recorded per
binding. The largest 8 entries all come from `next_dev_cases` /
`motion_final_cases` / `fifth_combined_cases` corpora that were captured
for earlier batches but only partially bound.

## Bindings and build

- `tools/golden_bindings.json` — 65 new bindings (654 total). Each binding
  links `build/vf3matrixfamily.exe <entry>` to its most-case-rich dev/holdout
  /fresh directory and requires `VF3_STRICT_REPLAY=1`.
- `tools/watch/vf3_tenth_batch.txt` — 65 pc-roots for traceability.
- `docs/decomp_status.csv` — 65 new `ported` rows, sorted by entry address.

## How this advances the decomp

The advance plan in `docs/re/advance_plan.md` ranked the remaining levers as
(0) freeze census, (1) drain the executed pool, (2) build the synthetic-entry
+ scenario levers, (3) Phase 3 named closures. The tenth batch is a
**Phase 1 drain**: every entry has a clean strict-replay corpus, 100% body
cover, and an existing adapter owner. The remaining 8 entries with 100%
body cover but no adapter owner (e.g. `0x8c06d9e0`, `0x8c0adb86`,
`0x8c07829a`) need a new adapter to be generated before they can be promoted.

The 31 trace-executed entries that remain (after this and the ninth batch
removed 18 from the trace-claim cohort) are still behind code paths no current
scenario exercises. Phase 3 synthetic-entry capture and new scenario campaigns
remain the only way to reach them.