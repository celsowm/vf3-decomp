# 0x8C0706C4 weighted-vector pipeline

`0x8C0706C4` is a 208-byte baseline function. The readable C model follows the
entry through its first tail transfer, including the weighted-vector dot
products, cross-product path, branch decisions, and the observed normalization
path. The transfer boundary is the verified slice boundary; downstream
functions are not included in this port.

The 600-frame fight capture produced 2,128 entry-to-first-transfer pairs:

| Boundary PC | Count | Transfer target |
|---|---:|---|
| `0x8C070734` | 1,095 | `0x8C070878` |
| `0x8C070766` | 469 | `0x8C0707B2` |
| `0x8C070774` | 27 | `0x8C070878` |
| `0x8C0707AE` | 537 | `0x8C070854` |

`tools/pair_cases.py` pairs an entry only with a boundary hit before the next
entry hit, preventing a later invocation's interior PC from being mistaken
for the current call's exit. The unobserved zero-length `0x8C0706E8` route is
rejected. The 12-entry FSRRA scale catalog accepts only observed
`(norm2, threshold) -> scale` keys. The replay compares all modeled registers
and the captured RAM windows; all 2,128 cases pass.

## Reproduce the capture and replay

From the repository root, capture the relevant vector and stack windows:

```powershell
python tools/golden_batch.py --name golden_0706c4_narrow `
  --watch tools/watch/vf3_0706c4_boundary.txt `
  --out extract/analysis/goldens_0706c4_narrow `
  --ramn 2200 --max-samples 2200 --no-extract `
  --run fight:extract/analysis/vf3_fight_keep.state::600
```

Run `tools/pair_cases.py` on the resulting trace once per `--at` address
(`0x8C070734`, `0x8C070766`, `0x8C070774`, `0x8C0707AE`), using entry
`0x8C0706C4` and separate output prefixes in
`extract/analysis/pairs_0706c4_narrow`. Combine the route files in boundary
order with:

```powershell
python tools/merge_case_sets.py `
  --out extract/analysis/goldens_0706c4_narrow/f_0c0706c4_boundary.cases `
  extract/analysis/pairs_0706c4_narrow/8c070734.cases `
  extract/analysis/pairs_0706c4_narrow/8c070766.cases `
  extract/analysis/pairs_0706c4_narrow/8c070774.cases `
  extract/analysis/pairs_0706c4_narrow/8c0707ae.cases
```

Build and run `build/vf3fvecmix0706c4.exe` against that `.cases` file, or run
`python tools/verify_all.py` for the repository gate.
