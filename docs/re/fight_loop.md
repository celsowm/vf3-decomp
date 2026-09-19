# Fight-loop anatomy (M6 — second session)

Method: resume a mid-fight savestate (`vf3_fight_keep.state`) in the headless
build, trace 6,000 frames at block granularity with `bm_GetCodeByVAddr`, gate
on addresses in `funcs_1ST_READ.unsc.bin.csv`. 363 distinct functions fired.

## Per-frame cost of the top fight workers

Extracted from `trace_fight1.bin` via `trace_read2.py`,
length-normalized with 6,000 frames. Top 40 shown.

| addr | name | hits | /frame |
|---|---|---|---|
| 0x8C069078 | fight_f_8c069078 | 989,333 | 164.9 |
| 0x8C073CC6 | fight_f_8c073cc6 | 843,169 | 140.5 |
| 0x8C068F86 | fight_f_8c068f86 | 608,451 | 101.4 |
| 0x8C073F08 | fight_f_8c073f08 | 353,989 | 59.0 |
| 0x8C09D6E0 | fight_f_8c09d6e0 | 330,944 | 55.2 |
| 0x8C06F720 | fight_f_8c06f720 | 217,064 | 36.2 |
| 0x8C03EFFC | fight_f_8c03effc | 211,227 | 35.2 |
| 0x8C071A82 | fight_f_8c071a82 | 153,436 | 25.6 |
| 0x8C068CC2 | fight_f_8c068cc2 | 111,110 | 18.5 |
| 0x8C070870 | fight_f_8c070870 | 110,610 | 18.4 |
| 0x8C09D4AA | fight_f_8c09d4aa | 92,345 | 15.4 |
| 0x8C07091E | fight_f_8c07091e | 86,489 | 14.4 |
| 0x8C0693B4 | fight_f_8c0693b4 | 70,938 | 11.9 |
| 0x8C09D69A | fight_f_8c09d69a | 70,435 | 11.7 |
| 0x8C09D460 | fight_f_8c09d460 | 65,669 | 10.9 |
| 0x8C069656 | fight_f_8c069656 | 59,850 | 10.0 |
| 0x8C091CF2 | fight_f_8c091cf2 | 48,447 | 8.1 |
| 0x8C073D56 | fight_f_8c073d56 | 39,601 | 6.6 |
| 0x8C0C15A0 | fight_f_8c0c15a0 | 39,547 | 6.6 |
| 0x8C09E274 | fight_f_8c09e274 | 32,940 | 5.5 |

Interpretation guide: 0x8C069078 at ~165 hits/frame ~ per-branch / per-task
inner loop; numbers roll off monotonically to audio/interrupt friendlies
(`0x8C03EFFC` = AICA service; 35.2/frame). Transition-heavy routines like
`stage_load` (0x8C0B7302) sit near zero inside a stable fight, as expected.

## r4-relative field layout (best-effort, hypothesis class B)

Aggregated over the top 40 hot fight fns (raw counters in
`extract/analysis/struct_infer.txt`):

| offset | count-led observations | likely field |
|---|---|---|
| +0x00 (r4) | most fns ld directly | task "owner-object" ptr / vtable |
| +0x08 | hit-block start (ram+500) | anim frame index |
| +0x0C | common in matchers | next-state / target link |
| +0x18 | 0x8C09D69A reads | hp-texture slot |
| +0x20, +0x24 | float trio spread | position/velocity shadow |

The uniform `@r4`-and-deref style fits a `FightActor*` struct (known from the
task-list signature); the truly hot data path through `@r14` in `f_8c069078`
is the per-frame handler table.

**Todo for proper typing**: run the CFG-splitter on the 400 fight fns so
arguments come out, then read struct fields from decompile proper.

## Input-chain teaser

`FreeTag` inputs appear in the fight runs as low-rate asserts of
`0x8C09D*E2` rows around the moment scripted `KEY` events land; the spooler
`0x8C0B1AC0` keeps buffering demo/idle input between explicit polls.

## Data artifacts referenced here

- `trace_fight1.bin` (1.6 GB), `trace_attract.bin` etc — analysis bases
- `extract/analysis/fight_hits.csv` — full hit dump for every fn observed
- `extract/analysis/fight_first_seen.csv` — first-index ordering, same set
- `extract/analysis/struct_infer.txt` — keyed off `fight_hot_addrs.txt`

## Naomimod extractor note

`tools/emu/naomimod-extractors/` clones the `NaomiMod/games-ExtractTools`
repo locally. `VF3TB_Model_Extractor.py` proved functional on our own
`extract/gamedata` (e.g. `MKAO_AI2.POL` + `MKAO_AKI.POL` + matching `.TEX`
split into PVR1 files). Useful later once asset mapping work gets to POL→3D.
Don't currently need it for function-coverage purposes; `git keep`.

(Stale savestate-reset-leak incident recorded in progress.md under M6.)
