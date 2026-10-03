# Twelfth C coverage batch

Promotes **29 partial-body-cover leaves** that pass strict-replay end-to-end.
These entries had captures that exercised 80–99% of their bodies; strict
replay on the most-case-rich corpus passed, so the existing adapter
dispatch is correct and the missing coverage is reachable in principle from
more captures rather than from a missing capability.

## Net delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 930/2398 (38.8%) | 959/2398 (40.0%) | **+29 fns (+1.2 pp)** |
| rigorous bytes | 190,968/434,656 (43.9%) | 194,502/434,656 (44.7%) | **+3,534 B (+0.8 pp)** |

This is the **first batch to cross the 40% rigorous-function threshold**.

## Strict invocation replay

### Promoted leaves (29 entries, body cover 80–99%)

| entry | frozen | dev/holdout/fresh dir | strict | body cover |
|---|---|---|---|---|
| `0x8C0A7A1C` | 194 B | fifth_ab_cases (24) | PASS | 99.0% |
| `0x8C0A81FC` | 160 B | fight_all_cases (1) | PASS | 96.2% |
| `0x8C07AD68` | 46 B | next_dev_cases (2) | PASS | 95.7% |
| `0x8C03E442` | 182 B | fifth_primary_cases (27) | PASS | 95.6% |
| `0x8C0C7E2A` | 332 B | motion_final_cases (2) | PASS | 94.0% |
| `0x8C0715F4` | 76 B | phase1_dev_cases (22) | PASS | 92.1% |
| `0x8C0CC0DC` | 94 B | fight_release_cases (64) | PASS | 91.5% |
| `0x8C0A062C` | 200 B | fifth_combined_cases (63) | PASS | 91.0% |
| `0x8C06EF4A` | 238 B | motion_release_cases (33) | PASS | 90.8% |
| `0x8C0ABF54` | 86 B | fifth_ab_cases (6) | PASS | 90.7% |
| `0x8C07287C` | 64 B | phase1_dev_cases (51) | PASS | 90.6% |
| `0x8C0944A4` | 78 B | fifth_combined_cases (64) | PASS | 89.7% |
| `0x8C070874` | 56 B | fifth_leaf_fresh_v6_cases (64) | PASS | 89.3% |
| `0x8C03F3F0` | 230 B | fifth_combined_cases (63) | PASS | 88.7% |
| `0x8C0A7798` | 70 B | fight_release_cases (2) | PASS | 88.6% |
| `0x8C0C120C` | 66 B | fight_release_cases (64) | PASS | 87.9% |
| `0x8C08C132` | 48 B | fight_release_cases (64) | PASS | 87.5% |
| `0x8C0AA426` | 30 B | phase1_dev_cases (13) | PASS | 86.7% |
| `0x8C0C5D86` | 56 B | fight_release_cases (58) | PASS | 85.7% |
| `0x8C08C0F8` | 54 B | fight_release_cases (64) | PASS | 85.2% |
| `0x8C04C768` | 408 B | next_dev_cases (1) | PASS | 83.8% |
| `0x8C0CC4EA` | 86 B | fifth_combined_cases (32) | PASS | 83.7% |
| `0x8C0400C2` | 86 B | fight_release_cases (4) | PASS | 83.7% |
| `0x8C0AF95C` | 86 B | fight_release_cases (3) | PASS | 83.7% |
| `0x8C0AD17C` | 60 B | fight_release_cases (57) | PASS | 83.3% |
| `0x8C0B1C94` | 48 B | fifth_combined_cases (103) | PASS | 83.3% |
| `0x8C07C634` | 48 B | fifth_leaf_dev_v6_cases (128) | PASS | 83.3% |
| `0x8C0A058E` | 88 B | fifth_combined_cases (64) | PASS | 81.8% |
| `0x8C0AF9E4` | 264 B | fifth_combined_cases (5) | PASS | 80.3% |

**Subtotal**: 3,534 frozen bytes; **1,297 strict cases** across dev/holdout/fresh corpora.

## How this advances the decomp

The advance plan in `docs/re/advance_plan.md` separates "100% body cover" (the
full promotion gate for Phase 3 named closures) from "passes strict replay"
(the standard promotion gate for capture-driven ports). The eleventh batch
exhausted the 100% cover cohort; this twelfth batch widens the gate to the
next-best cohort — entries whose corpus does not exercise every PC, but
whose adapter dispatch is correct and whose captured cases replay
identically.

The 5 failed entries (`0x8C04853A` 549/989, `0x8C0C7810` 0/1,
`0x8C0460A6` 36/128, `0x8C08B5DC` 16/37, `0x8C03B364` 0/24) are excluded —
they need additional captures or a body-cover extension to clear strict
replay. `0x8C04853A` in particular shows the value of more cases: at 989
captured but only 549 pass strict replay, the entry needs wider input
seeding.

## Bindings and build

- `tools/golden_bindings.json` — 29 new bindings (753 total).
- `tools/watch/vf3_twelfth_batch.txt` — 29 pc-roots.
- `docs/decomp_status.csv` — 29 new `ported` rows, sorted by entry address.