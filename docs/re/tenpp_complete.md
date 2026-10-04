# Ten-point C coverage milestone

The requested gain is complete: **37.38% → 47.41%**, an increase of
**10.024 percentage points** of verified readable C coverage.

| Measure | Bytes |
|---|---:|
| Frozen function-body denominator | 434,656 |
| Starting verified C address union | 162,490 |
| Required ending union | 205,956 |
| Verified ending union | **206,062** |
| New unique C bytes | **43,572** |
| Margin above target | 106 |

This is the union of ported addresses. SDK attribution and trace-only
identification do not count toward the gain. Legacy function-size sums
overlap by 878 bytes and are not used for this target. The inventory,
body ranges, executable image, starting spans and target are frozen in
`tools/oracle/tenpp_coverage_baseline.json`.

## Milestones

The sequence credits **157 functions**. Every addition has complete frozen
body execution, at least 64 distinct complete development inputs in two
source scenarios, strict complete-state replay with zero skipped cases,
and independent acceptance. Failed, incomplete and nondeterministic
specimens remain excluded.

| Proof manifest in `tools/oracle/` | Functions | Unique-byte gain | Ending union |
|---|---:|---:|---:|
| `tenpp_assets_milestone.json` | 25 | 18,602 | 181,092 |
| `tenpp_pack_milestone.json` | 8 | 4,004 | 185,096 |
| `tenpp_pack_remaining_milestone.json` | 3 | 1,440 | 186,536 |
| `tenpp_typed_milestone.json` | 15 | 3,298 | 189,834 |
| `tenpp_small_milestone.json` | 23 | 2,200 | 192,034 |
| `tenpp_large_milestone.json` | 4 | 2,490 | 194,524 |
| `tenpp_recovery_milestone.json` | 33 | 2,134 | 196,658 |
| `tenpp_recovery_small_milestone.json` | 19 | 552 | 197,210 |
| `tenpp_statistics_milestone.json` | 1 | 2,364 | 199,574 |
| `tenpp_medium_expanded_milestone.json` | 2 | 562 | 200,136 |
| `tenpp_floating_milestone.json` | 1 | 476 | 200,612 |
| `tenpp_boundary_milestone.json` | 6 | 3,312 | 203,924 |
| `tenpp_medium_final_milestone.json` | 5 | 1,286 | 205,210 |
| `tenpp_recovery_final_milestone.json` | 9 | 238 | 205,448 |
| `tenpp_vertex_final_milestone.json` | 1 | 292 | 205,740 |
| `tenpp_target_milestone.json` | 2 | 322 | **206,062** |

## Final implementation and evidence

The final expanded unit emits 9,162 static C statements; the recovery unit
emits 9,650. Both report zero unsupported instructions. Existing semantic
matrix/FPU helpers are reused, and statement ownership is explicit in the
dispatcher. Exploratory implementations without passing proof receive no
coverage credit.

Inputs now include original indexed character lists, finite floating values
near branch thresholds, signed arguments, argument masks, and established
prologue values at frozen fragment entries. Preserved-field fixtures vary
registers independently while retaining the inferred memory contract.
The matrix-buffer constructor at `0x8c03b874` receives its original writable
aligned-buffer contract; `0x8c05dfe6` receives signed boundary values.

The final two bodies pass **2,045/2,045 development** and **512/512 independent
acceptance** cases. Their manifest records `target_met: true`. The final
immutable replay executable is `build/vf3matrixfamily_tenpp_final.exe`.

The statistics oracle's bounded FTRC correction and fresh captures are
documented in [tenpp_expanded.md](tenpp_expanded.md). ROM tracks, game executable
images and original instruction/literal bytes were not changed.

All 16 milestone artifact-hash audits pass. The final full CMake build
passes. Final repository regression passes, including all **949 bound
replays** (901 strict bindings) and the native replay tests. Retained logs
are `extract/analysis/tenpp_final_regression.log` and
`extract/analysis/tenpp_goal_hash_audit.log`.

To reproduce an individual audit:

```text
python tools/oracle/audit_matrix_batch.py --manifest tools/oracle/tenpp_target_milestone.json --hashes
python tools/decomp_stats.py
cmake --build build --parallel 4
python tools/portcheck.py --jobs 4
```

Capture and replay artifacts stay in ignored `extract/analysis` and `build`.
Committed manifests and golden bindings retain their locations and hashes.
