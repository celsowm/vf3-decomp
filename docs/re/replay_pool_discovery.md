# Replay pool discovery (2026-10-19)

## The bug that made the pool look drained

`tools/replay_scan.py` and `tools/promote_replay.py` discovered corpora with
`extract/analysis/*cases`. Several real, shadowed corpora live in directories that do
not end in `cases`:

- `coverage_65_09970a_nested_probe_v7`
- `advance_05cc38_dev_fp/advance_05cc38_dev_fp_8c05cc38`
- `percentage_family_dev*`, `target_final_dev_*`, `advance_*_dev`, ...

Those directories have `f_<pc>.cases`, `f_<pc>_0.in.bin`/`.out.bin`, and a
`batch_manifest.json`; they are valid replay inputs. Both tools now find every
`f_*.cases` sidecar and use its parent directory, then require the `_0.in.bin` shadow.

## Pool

Intersecting the **true ledger-unported** entries (baseline 2,398 minus the 1,667
already `ported`) with the recovered corpora gives **381 unique entries / 60,716 B**.
This is the capture-possible pool the previous scans never saw.

## Promoted (strict replay, all corpora)

Batches 1-5 ran the top 108 candidates through `promote_replay.py`; **28 entries /
9,448 B** passed every corpus with `VF3_STRICT_REPLAY=1` and `0 skipped`. The largest:

| entry | bytes | router |
|---|---:|---|
| `0x8C05CC38` | 1,290 | `tenpp_expanded_adapters.c` |
| `0x8C09CADA` | 764 | `target_family_adapters.c` |
| `0x8C07F894` | 704 | `target_retained_scene_adapters.c` |
| `0x8C09BC2E` | 664 | `target_family_adapters.c` |
| `0x8C0C8334` | 638 | `target_closure_adapters.c` |
| `0x8C09B6E4` | 490 | `target_family_adapters.c` |
| `0x8C0C15F8` | 342 | `fight_adapters.c` |
| `0x8C085E44` | 316 | `target_extended_adapters.c` |
| `0x8C03A50E` | 314 | `tenpp_expanded_adapters.c` |
| `0x8C07F722` | 312 | `target_retained_scene_adapters.c` |

The full set is in `docs/decomp_status.csv` (method `capture-driven port (batch replay_scan)`)
and `tools/golden_bindings.json`.

Coverage: **316,778 B (72.8802%) -> 326,226 B (75.0538%)**, +9,448 B. `final_status.py`
reads `extract/analysis/coverage.json`; regenerate it with `tools/decomp_stats.py` after a
promotion or the number stays stale.

## Rejected in these batches

- Most failures are `unsupported helper/state at <pc> PC ...`: the generated adapter is
  incomplete, not a capture problem. Examples: `0x8C09970A`, `0x8C097ABC`, `0x8C09B37E`.
- Some are real state mismatches: `FPUL: ...`, `device access mismatch`, or a memory-window
  address with the wrong `0c`/`8c` alias.
- A few have no shadowed corpus (the capsule is gone), e.g. `0x8C04D020`.

## Next

Remaining true-unported entries with a shadowed corpus: **301 entries / 42,266 B**.
Continue `promote_replay.py` batches over them; the observed pass rate is about 20%, and
the tool refuses anything that fails a single corpus. Batch selection should prefer entries
whose router source exists and whose corpora have shadows.
