# Capture storage cleanup (2026-10-05)

The user requested removal of old files after the capture campaign exhausted
drive E. Cleanup reclaimed approximately **21.6 GiB**:

- The redundant `tools/ghidra.zip` archive (569,445,154 bytes), after checking
  that the installed Ghidra headless launcher exists.
- 1,738 old raw capsules (9.45 GiB allocated) whose corpus manifests contain
  zero valid specimens. Sources referenced by credited bindings were protected.
- 147,732 old decoded RAM input/output shadows (11.60 GiB allocated) from
  unbound corpora with successful, complete original captures. Their original
  raw capsules, manifests, case headers and operation tapes remain available.

ROM tracks, original executable images, SDK corpora and credited proof inputs
were preserved. Current `target` captures and the old development sources
selected for the retained-scene and body-gap campaigns were also excluded.
The decoded shadows can be regenerated with `merge_batches.py` from the
preserved original captures; direct replay of a pruned old corpus requires
regenerating these shadows first.

Reusable tools replace one-off cleanup scripts:

```powershell
python tools/oracle/capture_storage.py --out extract/analysis/cleanup_plan.json
./tools/oracle/apply_capture_cleanup.ps1 -Plan extract/analysis/cleanup_plan.json
python tools/oracle/decoded_storage.py --preserve-sources extract/analysis/target_gaps_sources.json --preserve-sources extract/analysis/target_retained_scene_sources.json --out extract/analysis/decoded_plan.json
./tools/oracle/apply_decoded_cleanup.ps1 -Plan extract/analysis/decoded_plan.json
```

Planning and application default to dry runs. Application requires `-Apply`;
both PowerShell tools validate every exact workspace path before deletion,
reject reparse points and changed sizes, and save a deletion journal. No
recursive deletion is used. Plans must be regenerated after bindings or
selected development sources change.

Evidence is retained in ignored analysis artifacts:
`target_cleanup_plan_checked.json`, `target_cleanup_applied.json`,
`target_cleanup_postcheck.json`, `target_decoded_cleanup_plan.json`, and
`target_decoded_cleanup_applied.json`. The raw-capsule postcheck found no
remaining eligible empty-corpus capsules and protected 1,574 bound sources.
`target_cleanup_tests_final.log` records **35 passing campaign-tool tests**,
including preservation rules, closure filtering and the low-space guard.

`isolate_planned.py` now stops between capture groups when less than 4 GiB
remains. Run one emulator capture process at a time: simultaneous large
groups can consume the reserve before any between-group guard runs. Failed
disk-full groups remain invalid evidence and require a fresh successful
capture; cleanup does not turn them into proofs or grant C coverage.
