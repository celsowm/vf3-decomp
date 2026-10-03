# Eleventh C coverage batch

Generates two new adapter modules and promotes **70 additional complete
functions** that previously had no owning adapter in the dispatch chain.
The captures existed (100% body cover) but no adapter owned their entry
points, so calls fell through to `vf3_matrix_adapter` which rejected them
as "unsupported helper/state".

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 860/2398 (35.9%) | 930/2398 (38.8%) | **+70 fns (+2.9 pp)** |
| rigorous bytes | 182,098/434,656 (41.9%) | 190,968/434,656 (43.9%) | **+8,870 B (+2.0 pp)** |

## Two new generated adapter modules

### `src/fight/vf3_motion_final_adapter.c`

Generated from `extract/analysis/motion_final_cases` against the watch
file `tools/watch/vf3_unowned_motion_final.txt` (28 pc-roots). 2,669 guest
statements, 0 unsupported instructions. Promotes **38 entries / 7,428 B** —
the largest single batch this session. Reused `motion_adapters.c`,
`fifth_adapters.c`, `seventh_*.c`, `eighth_adapters.c`, `phase*.c`,
`device_adapters.c`, `next_adapters.c`, `fight_adapters.c`,
`fifth_leaf_adapters.c`, and `matrix_adapters.c` to keep ownership claims
disjoint.

### `src/fight/vf3_fifth_leaf_unowned_adapter.c`

Generated from `extract/analysis/{fifth_leaf_holdout_v6, fifth_leaf_dev_v6,
fifth_leaf_fresh_v6, fifth_leaf_holdout, fifth_leaf_dev, fifth_leaf_fresh,
motion_acceptance, next_more, next_dev, seventh_c15, seventh_c16}_cases`
against the combined watch list. 6,342 guest statements, 0 unsupported
instructions. Promotes **32 entries / 1,442 B**.

## Bindings and build

- `tools/golden_bindings.json` — 70 new bindings (724 total).
- `tools/watch/vf3_eleventh_batch.txt` — 70 pc-roots.
- `CMakeLists.txt` — adds `vf3_motion_final_adapter.c` and
  `vf3_fifth_leaf_unowned_adapter.c` to both the default `vf3core` library
  and the `-O0;-frounding-math;-ffp-contract=off` compile group.
- `src/fight/matrix_family.{c,h}` — adds `vf3_motion_final_adapter` /
  `vf3_fifth_leaf_unowned_adapter` dispatch entries ahead of the
  `vf3_matrix_adapter` fallback.

## Strict invocation replay

Both new adapters pass `matrix_family: N/N cases match (0 skipped) - PASS`
on every promoted binding under `VF3_STRICT_REPLAY=1`. The seven remaining
failures (e.g. `0x8c07829a`/`0x8c07825e` at 3/4, `0x8c045f62`/`0x8c094242`
at <128 cases) are recorded in the test log but not promoted — they need
either more captures or a body cover that matches every PC.

## How this advances the decomp

The advance plan in `docs/re/advance_plan.md` ranked the remaining levers
as (0) freeze census, (1) drain the executed pool, (2) build the
synthetic-entry + scenario levers, (3) Phase 3 named closures. The eleventh
batch is a **Phase 1 drain that requires the missing lever**: the executed
pool's unowned entries were an iceberg the previous batches could not see.
Generating two new adapters (8,011 total guest statements, 0 unsupported)
exposes ~7 KB of credit the capture pipeline already had evidence for.

The 7 failures and the 31 trace entries that remain are still behind code
paths no current scenario exercises. Phase 3 synthetic-entry capture and
new scenario campaigns remain the only way to reach them.