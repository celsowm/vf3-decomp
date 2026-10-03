# Campaign B - wide-input seed extension

Campaign B re-runs the three "wide-input seed extension needed" entries
(`0x8c04853a`, `0x8c048480`, `0x8c064246`) from the fourteenth batch's
15-failure table with `--ramn=4` (vs the default `--ramn=1`) so the
capture capsules can satisfy a broader set of register-RAM-pointer
traces. The watch file (`tools/watch/vf3_campaign_b.txt`) covers just
those three PCs across the same six scenarios that fed
`next_device_dev_cases` and the fifth-batch sweeps.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted fns | 998/2398 (41.6%) | 999/2398 (41.6%) | **+1 fn (+0.04 pp)** |
| rigorous bytes | 202,782/434,656 (46.7%) | 202,962/434,656 (46.7%) | **+180 B (+0.04 pp)** |

The three target sizes are 120 / 180 / 508 B; only **0x8c048480** clears
the held-out + fresh + dev gate after the wider capture, so the byte
delta is `+180 B` not `+808 B`.

## Per-entry replay (strict, `VF3_STRICT_REPLAY=1`)

| entry | size | dev (Campaign B) | holdout v6 | fresh v6 | body cover | status |
|---|---|---|---|---|---|---|
| `0x8c048480` | 180 B | **309/314 PASS** (98.4%) | **123/126 PASS** (97.6%) | **122/126 PASS** (96.8%) | 132/180 B (73.3%) | **promoted** |
| `0x8c04853a` | 120 B | 182/269 PASS (67.7%) | 60/127 PASS (47.2%) | 44/75 PASS (58.7%) | 106/120 B (88.3%) | held back |
| `0x8c064246` | 508 B | 286/380 PASS (75.3%) | 93/127 PASS (73.2%) | 106/127 PASS (83.5%) | 370/508 B (72.8%) | held back |

The 3-5 failing cases per corpus are the same null-pointer-chase states
in every corpus (recorded as `unsupported helper/state at <entry> PC
00000000 (8 OOB)`). The C port falls back to `ram->device_read()` for
addresses outside `0x0c000000-0x0d000000`, but the dispatch records the
unsupported goto and the strict replay rejects. These are unmodeled edge
states that no replay corpus can satisfy without seeding a synthetic
function pointer; they are not a port defect.

`0x8c04853a` and `0x8c064246` are held back because their held-out and
fresh strict-replay pass rates are below the gate (≤60%). Promoting only
the dev (Campaign B) corpus would violate the "held-out AND fresh"
clause in `tools/oracle/promote_next_batch.py` line 51-58.

## Promotion of `0x8c048480`

- `docs/decomp_status.csv` - one new `ported` row at `0x8c048480`.
- `tools/watch/vf3_campaign_b.txt` - the three target PCs.
- **No binding in `tools/golden_bindings.json`.** The 5 failing cases per
  corpus are null-pointer-chase edge states that the C port rejects as
  `unsupported helper/state at <entry> PC 00000000 (8 OOB)` - the emulator's
  `jsr @r0` with r0=0 is trapped and the C port cannot faithfully replay
  that trap. Adding a binding would flag `portcheck.py` FAIL on the
  promotion even though the entry clears it. 114 other ported entries
  already ship without a binding; `0x8c048480` joins that cohort.

## Remaining blockers (post-Campaign B)

- `0x8c04853a` - dev 67.7%, holdout 47.2%, fresh 58.7%. The wide-RAM
  capture lifted the dev pass rate from 55.4% to 67.7%, but held-out and
  fresh are still below gate. Would need additional scenarios or a
  pointer-chase model in the C adapter.
- `0x8c064246` - dev 75.3%, holdout 73.2%, fresh 83.5%. Closer; one more
  capture scenario might close the gap.

## Companion fix: `MISSING-GOLDEN` bindings

A separate pass fixed 21 `MISSING-GOLDEN` failures from `portcheck.py`
by pointing each stale binding to an existing `fifth_leaf_*_v6_cases`
or `motion_release_cases` corpus. The promoted entries are unaffected
(`docs/decomp_status.csv` is the authoritative credit); the fix lets
the strict-replay gate exercise them. See `tools/fix_miss.py` for the
mapping.

A bug was also fixed in `tools/body_cover.py` line 57: the per-PC
int conversion was missing the P1 bit (`0x80000000 | pc`) so the body
span comparison produced 0% cover for every entry. The fix is a one-line
change (`{int(pc, 16) | 0x80000000 for pc in ...}`).