# M63/M65 — fight handlers + tight ring (2026-09-25)

## Spawn matrix (extract/analysis/fight_spawn_edges.csv, 445 rows)

```
073f08->073c2a 341354; 073c2a->073cc6 330064; 068f86->069078 243380
073cc6->073f08 233392; 069078->068f86 121690; 06f6c6->06f720 108531
073cc6->073d56 96672; 073d56->073f08 92339; 09d6e0<->09d69a 70433/70431
0693b4->068f86 69997; 069078->0693b4 69997
```

Tight ring `073c2a↔073f08↔073cc6↔073d56` = ~340K activations (~3/frame),
fed via `073d80/073952` mova-dispatchers. Sound pair
`069078↔068f86↔0693b4` = 69–243K. MT pair `09d6e0↔09d69a` = 70K symmetric.
First-seen: `8c0b1ac0#0, 058e92#2, 091c42#9, 03effc#17(AICA), 091cf2#30,
091d80#50 … 068f86#343`.

## Handler enumeration (M63)

Intersect `fight_hits.csv × fight_first_seen.csv × fight_spawn_edges.csv`.
Do NOT use fntables (0/146 hit fight). Resolve `jsr @r14` via VF3_WATCH
pc+r13/r14/r4-7 probe groups from vf3_7 (fight-live) / vf3_6 (pre-fight).
One-shots (`bjload_run 0x8C0CBC40` 950 hits, `coli_run`, `mt_loader
0x8C02DCEC` 0 hits post-init) need csel→fight transition trace.

## Ring decode (M65)

`tools/sh4full.py 8c073c2a/8c073f08/8c073cc6/8c073d56 + feeders
8c073d80/8c073952`: annotate literal pools (|0x80000000 normalize per M28),
follow mova+braf per ref_dreamcastrecompiled + braf_tables.py.
Input cues: FreeTag→`8c09D*E2` around KEY + spooler `8c0b1ac0`; correlate
KEYF script vs task_vm `0x12/0x20/0x24 strategy, 0x30 timer, 0x52 part,
0x56 tag`. Collision = `ST*.CLI` (`ST*_COLI.BIN`) + `coli_run 0x8C09AAE2`;
anim = MT record 5093 `+0x736/+0x7A4`.

## M48 removal path (f_8c03492c data island)

`src/sys/mainloop.c` case 7 `er==0` path left as marker discipline (data
island `0x8c03492c` over removal code). Next: trace-window dump of that
island + `sh4full.py 8c03492c` linear sweep to transliterate unlink/free.
State-6 aux now wired (M50: `vf3_node_finalize` in mainloop.c).
