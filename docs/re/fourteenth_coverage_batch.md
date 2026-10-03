# Fourteenth C coverage batch

Drains the **last owned-partial-cover cohort** by running strict-replay on
every unpromoted entry whose body contains an owned PC. Of 43 candidates,
28 pass and are promoted.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 967/2398 (40.3%) | 995/2398 (41.5%) | **+28 fns (+1.2 pp)** |
| rigorous bytes | 195,554/434,656 (45.0%) | 202,574/434,656 (46.6%) | **+7,020 B (+1.6 pp)** |

## Promoted leaves (28 entries, body cover 30–77%)

| entry | frozen | dir | cases | body cover | owner |
|---|---|---|---|---|---|
| `0x8C0CA240` | 66 B | fight_all | 1 | 78.9% | fight_adapters |
| `0x8C0406B8` | 250 B | fifth_combined | 5 | 76.0% | fifth_adapters |
| `0x8C0AE6F6` | 182 B | device_adapters (5th_combined) | 22 | 73.6% | device_adapters |
| `0x8C0C9DC8` | 294 B | motion_final | 7 | 73.5% | fifth_adapters |
| `0x8C0ABEB8` | 114 B | fifth_combined | 14 | 71.9% | fifth_adapters |
| `0x8C0865D6` | 178 B | fifth_combined | 60 | 69.7% | fifth_adapters |
| `0x8C0AA208` | 436 B | fight_dev | 2 | 67.4% | fight_adapters |
| `0x8C0AC114` | 48 B | fifth_combined | 13 | 66.7% | fifth_adapters |
| `0x8C08B204` | 246 B | fifth_combined | 21 | 63.4% | fifth_adapters |
| `0x8C08CDC4` | 162 B | fifth_combined | 25 | 63.0% | fifth_adapters |
| `0x8C0601D0` | 774 B | next_dev | 1 | 61.2% | next_adapters |
| `0x8C093270` | 244 B | fight_holdout | 8 | 60.7% | fight_adapters |
| `0x8C09183A` | 298 B | fifth_combined | 60 | 57.0% | fifth_adapters |
| `0x8C0AA9F0` | 214 B | fifth_combined | 17 | 56.1% | fifth_adapters |
| `0x8C0C6348` | 236 B | motion_final | 2 | 53.4% | motion_adapters |
| `0x8C08C51A` | 72 B | fight_release | 64 | 50.0% | fight_adapters |
| `0x8C074930` | 210 B | fifth_combined | 5 | 47.6% | fifth_adapters |
| `0x8C07137C` | 76 B | eighth_dev | 54 | 47.4% | eighth_adapters |
| `0x8C086618` | 296 B | fifth_combined | 80 | 45.3% | fifth_adapters |
| `0x8C0AA638` | 200 B | fifth_combined | 8 | 43.0% | fifth_adapters |
| `0x8C09518C` | 70 B | motion_final | 4 | 42.9% | motion_adapters |
| `0x8C08C494` | 86 B | fight_release | 64 | 39.5% | fight_adapters |
| `0x8C0AAEBE` | 180 B | fifth_combined | 8 | 35.6% | fifth_adapters |
| `0x8C04BF3C` | 172 B | device_adapters | 30 | 33.7% | device_adapters |
| `0x8C0AAFB0` | 404 B | fifth_combined | 36 | 30.2% | fifth_adapters |
| `0x8C0AAC20` | 344 B | fight_all | 1 | 22.1% | fight_adapters |
| `0x8C053460` | 680 B | next_dev | 1 | 19.7% | next_adapters |
| `0x8C0B20A8` | 488 B | motion_final | 5 | 7.4% | motion_adapters |

**Subtotal**: 7,020 frozen bytes; **601 strict cases** across dev/holdout/fresh corpora.

## The 15 failures (recorded, not promoted)

| entry | size | dir | cases | result | reason |
|---|---|---|---|---|---|
| `0x8C04853A` | 120 B | device_adapters | 989 | 549/989 FAIL | 989 captured, 549 pass — wide-input seed extension needed |
| `0x8C0C7810` | 78 B | fight_all | 1 | 0/1 FAIL | dispatch falls through (fight adapter doesn't own) |
| `0x8C0460A6` | 42 B | device_adapters | 128 | 36/128 FAIL | 92 cases fail strict replay |
| `0x8C08B5DC` | 68 B | next_dev | 37 | 16/37 FAIL | 21 cases fail strict replay |
| `0x8C03B364` | 62 B | device_adapters | 24 | 0/24 FAIL | dispatch falls through |
| `0x8C0431EA` | 128 B | device_adapters | 114 | FAIL | partial-match not promoted |
| `0x8C0352DC` | 38 B | fifth_leaf_dev_v6 | 128 | FAIL | partial-match not promoted |
| `0x8C048480` | 180 B | device_adapters | 1209 | FAIL | wide-input seed extension needed |
| `0x8C064246` | 508 B | device_adapters | 1276 | FAIL | PC 0x0C001006 AICA stub (per advance plan) |
| `0x8C035518` | 118 B | fifth_ab | 32 | FAIL | partial-match not promoted |
| `0x8C0A7F68` | 186 B | fifth_combined | 6 | FAIL | partial-match not promoted |
| `0x8C096650` | 72 B | fifth_leaf_dev_v6 | 128 | FAIL | partial-match not promoted |
| `0x8C09425E` | 60 B | device_adapters | 128 | FAIL | partial-match not promoted |
| `0x8C0432E2` | 108 B | fifth_combined | 6 | FAIL | partial-match not promoted |
| `0x8C09635A` | 616 B | fifth_combined | 1027 | FAIL | large cohort, mostly AICA-stub pollution |

## Bindings and build

- `tools/golden_bindings.json` — 28 new bindings (781 total).
- `tools/watch/vf3_fourteenth_batch.txt` — 28 pc-roots.
- `docs/decomp_status.csv` — 28 new `ported` rows, sorted by entry address.

## How this advances the decomp

The advance plan in `docs/re/advance_plan.md` separates "100% body cover" (the
full promotion gate for Phase 3 named closures) from "passes strict replay"
(the standard promotion gate for capture-driven ports). The ninth, tenth,
eleventh, twelfth, and thirteenth batches drained every 100% cover cohort
and the no-owner partial cohorts via adapter generation. This fourteenth
batch finishes the owned-partial cohort.

After this batch, **the only unpromoted entries with case dirs are the 15
failures listed above** plus the 31 trace entries without case dirs and the
5 Phase 3 named closures. The capture-driven pool is now exhausted, and
the next lever to reach the remaining ~50% baseline is **Phase 3 synthetic
entry** — re-measure masks against a verified scratch page, then either
fix the existing pilot (`0x8C05B20E`) or capture the larger named closures
(`0x8C0C321E` 1574B, `0x8C09C1F4` 2084B, `0x8C0C438E` 1694B).