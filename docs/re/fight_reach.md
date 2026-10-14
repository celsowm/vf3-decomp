# Fight-trace reachability of the unported owners

## Status (2026-10-14)

`tools/fight_reach.py` scans a vf3trace u64 record stream for how many
records land inside each still-unported baseline body (instruction-level,
recorders' trace format: `pc=rec>>16`, bit16 = exception marker, P2 alias
folded). Scanning `extract/analysis/trace_fight1.bin` (197,487,160 records)
answers the question the entry-PC hit screens could not: the large owners
are entered **mid-body** through dispatch-table/dyn targets, never through
their function start, so earlier screens reported zero hits.

**26 unported owners execute in the fight trace, 4,334 bytes:**

| Owner | Bytes | Hits | First hit (record, PC) |
|---|---:|---:|---|
| 0x8c059aea | 494 | 86,134,985 | 106,637 pc=0x8c059af6 |
| 0x8c04853a | 120 | 603,591 | 1,160 pc=0x8c048578 |
| 0x8c064246 | 508 | 37,382 | pc=0x8c064264 (REIOS; blocked) |
| 0x8c0a037c | 98 | 16,991 | pc=0x8c0a0398 |
| 0x8c059a2e | 170 | 11,317 | pc=0x8c059ab8 |
| 0x8c09425e | 60 | 7,815 | pc=0x8c09426a |
| 0x8c045f62 | 28 | 7,186 | pc=0x8c045f74 |
| 0x8c07b216 | 172 | 7,118 | pc=0x8c07b2be |
| 0x8c070fba | 28 | 4,645 | pc=0x8c070fc4 |
| 0x8c09575c | 1,780 | 4,627 | 87,528 pc=0x8c095cfc |
| 0x8c062ec4 | 50 | 4,106 | pc=0x8c062ecc |
| 0x8c0a03f0 | 48 | 3,043 | pc=0x8c0a041e |
| 0x8c07023a | 24 | 2,948 | pc=0x8c070240 |
| 0x8c08b586 | 62 | 2,056 | pc=0x8c08b5ac |
| 0x8c038cb0 | 48 | 1,544 | 106,533 pc=0x8c038cb0 |
| 0x8c03523c | 50 | 1,028 | pc=0x8c035248 |
| 0x8c0460a6 | 42 | 1,028 | pc=0x8c0460b4 |
| 0x8c07c8cc | 48 | 1,028 | 2,631,330 pc=0x8c07c8d4 |
| 0x8c07c8fe | 48 | 1,008 | 101,112,319 pc=0x8c07c906 |
| 0x8c0abc08 | 154 | 263 | 341,388 pc=0x8c0abc10 |
| 0x8c0ab870 | 48 | 184 | 341,380 pc=0x8c0ab870 |
| 0x8c08c12e | 4 | 172 | pc=0x8c08c12e |
| 0x8c0782e4 | 6 | 51 | pc=0x8c0782e4 |
| 0x8c07829a | 62 | 48 | 12,892,644 pc=0x8c07829a |
| 0x8c078112 | 72 | 2 | 82,952,926 pc=0x8c078152 |
| 0x8c0b244c | 110 | 2 | 35,000,253 pc=0x8c0b24aa |

Reproducible report: `extract/analysis/fight_reach_r76.json` / `.csv`. This is
reachability evidence only — no owner earns coverage credit from it.

## Consequences for the next push

- None of the largest C-campaign owners (`0x8c0831f8`, `0x8c08231c`,
  `0x8c04d020` C; `0x8c09575c`'s B family trio) is cleanly callable from the
  front: they execute via mid-body dispatch targets. A capture campaign for
  these needs either a whole-session observer at a fight-active savestate or
  an invoker patch at the *dispatch* site (e.g. `0x8c095cfc` for
  `0x8c09575c`), not at the Ghidra function entry.
- The small 48-170 B fight-hot owners (`0x8c0a037c`, `0x8c059a2e`,
  `0x8c07023a`, `0x8c08b586`, `0x8c0a03f0`, …) are the cheapest full
  pipeline targets: state-45/46-adjacent bounded probes should find them.
- OF THE ONES WITH EXISTING CORPORA: `0x8c09425e` and `0x8c03523c` stay
  parked (device-tape `0x1f000038` divergence and REIOS GET_CMD_STAT resp.).

## 2026-10-14 follow-up: the mid-body sites are scheduler continuations

PC-predecessor analysis of the first trace hits corrected the "mid-body
entry" picture: `0x8c095cfc` is reached by `rts` from helper `0x8c096170` —
it is a **stacked return address**, not a call target. The cluster bodies
(`0x8c09575c`, `0x8c096170`, `0x8c07829a`→`0x8c0782e4`, trampoline table
`0x8c0786c4`+, vtable trampoline `0x8c0ab870` via image table
`0x0c10f414`) form one interconnected family: the **task-VM / scheduler
core** already flagged in docs/re/task_vm.md (M19). Corpora-bearing
members re-triaged against scan r75 remain walled: `0x8c08c12e` (41/41
pass but 66 shadows lost with the tenpp capsules), `0x8c062ec4` (thunk
that `jsr`s a RAM-resident function pointer — needs the task VM modeled),
`0x8c07829a` (chains into the unmodeled trampoline table at
`0x8c0786c4`). Consequences:

- Every cheap front-door capture on this family collapses into the same
  requirement: model the scheduler's save/resume mechanics FIRST. That is
  the Phase-2 campaign: field schema (M19 tools/task_vm_map.py), resume
  path, then fixture capture through the natural scheduler entry.
- Non-cluster outliers still probeable cheaply: none material among the
  26 — even `0x8c038cb0` (48 B, clean entry) tails into the `0x8c059xxx`
  polling family (`0x8c059aea`, 86M hits, no corpus).
