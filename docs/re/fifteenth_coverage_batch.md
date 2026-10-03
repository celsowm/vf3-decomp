# Fifteenth C coverage batch

Generates the broadest adapter yet (`src/fight/vf3_ultimate_adapter.c`,
5,452 guest statements, 0 unsupported) and promotes **3 entries that the
existing adapters could not reach**. The ultimate adapter covers every
non-Phase-3 case dir (`motion_final`, `motion_acceptance`, `fight_*`,
`fifth_*`, `device_*`, `next_*`, `seventh_*`, `eighth_*`, `phase1_*`,
`phase2_*`, etc.) under a single dispatch entry.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 995/2398 (41.5%) | 998/2398 (41.6%) | **+3 fns (+0.1 pp)** |
| rigorous bytes | 202,574/434,656 (46.6%) | 202,782/434,656 (46.7%) | **+208 B (+0.1 pp)** |

## Promoted leaves (3 entries)

| entry | frozen | dir | cases | owner |
|---|---|---|---|---|
| `0x8C0C7810` | 78 B | fifth_leaf_fresh_v6 | 1 | ultimate adapter |
| `0x8C08B5DC` | 68 B | fifth_leaf_holdout_v6 | 37 | ultimate adapter |
| `0x8C03B364` | 62 B | fifth_leaf_fresh_v6 | 24 | ultimate adapter |

**Subtotal**: 208 frozen bytes; **62 strict cases** across dev/holdout/fresh corpora.

## What the ultimate adapter does not save

Twelve of the fifteen failures from the fourteenth batch are still failing.
The ultimate adapter does dispatch to all of them (each entry's entry
PC is in `vf3_ultimate_adapter_contains`), but the underlying
implementation either:

- Falls into "unsupported helper/state" because the function calls a
  helper not in any adapter (`0x8C0431EA` 0/114, `0x8C0352DC` 0/128,
  `0x8C035518` 0/32, `0x8C0A7F68` 0/6, `0x8C096650` 0/128,
  `0x8C0432E2` 0/6, `0x8C09635A` 0/1027) — the function has
  callees that no adapter implements
- Reaches the AICA stub `PC 0x0C001006` (per advance plan), e.g.
  `0x8C04853A` 549/989 and `0x8C064246` 939/1276 — most cases
  replay, a few hit the stub and fail strict replay
- Has wide-input seed extension needed for full strict replay,
  e.g. `0x8C048480` 1158/1209 and `0x8C0460A6` 36/128 — needs
  more input variation in captures

These failures are **fundamentally not reachable from the existing
capture pipeline**. The advance plan documents Phase 2's bigger lever
(new scenario campaigns, function-pointer reachability, synthetic-entry
capture) and Phase 3 (named closures, currently parked on seed
calibration) as the only paths to drain them.

## Bindings and build

- `tools/golden_bindings.json` — 3 new bindings (784 total).
- `tools/watch/vf3_fifteenth_batch.txt` — 3 pc-roots.
- `docs/decomp_status.csv` — 3 new `ported` rows.
- `src/fight/matrix_family.{c,h}` — adds `vf3_ultimate_adapter` /
  `vf3_ultimate_adapter_contains` dispatch entries.
- `CMakeLists.txt` — adds `vf3_ultimate_adapter.c` to both the default
  `vf3core` library and the `-O0;-frounding-math;-ffp-contract=off`
  compile group.

## Final session state

| metric | start of session | end of session | delta |
|---|---|---|---|
| rigorous accounted | 788/2398 (32.9%) | 998/2398 (41.6%) | **+210 fns (+8.7 pp)** |
| rigorous bytes | 176,958/434,656 (40.7%) | 202,782/434,656 (46.7%) | **+25,824 B (+6.0 pp)** |

Crossed 40% functions, 45% bytes, and committed seven batches (ninth
through fifteenth) plus generated five new adapter modules
(`vf3_motion_final_adapter`, `vf3_fifth_leaf_unowned_adapter`,
`vf3_motion_unowned_extra_adapter`, `vf3_fifth_leaf_extra_adapter`,
`vf3_ultimate_adapter`).