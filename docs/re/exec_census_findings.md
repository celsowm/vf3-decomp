# Execution census findings (Phase 0, 2026-10-15)

Tools: `tools/exec_census.py` (owner classification, writes
`docs/re/exec_census.md` + `extract/analysis/census/*`) and
`tools/gap_attrib.py` (control-flow attribution of uncatalogued code).
A vf3trace record is a **block entry**, not an instruction; all weights below
are block-entry weights. Traces: trace_fight1 (197M), trace_melee (290M),
trace_boot3 (330M).

## Headline numbers (fight_1 + melee)

| class | unique entries | hit share |
|---|---:|---:|
| inside ported baseline fn | 64% | 19-20% |
| inside unported baseline fn | 2% | 42-44% (one polling loop) |
| **outside every baseline fn** | **34%** | **36-37%** |

* The single unported owner `0x8c059aea` (the driver wait loop) is 43.6% of
  fight hits. It is an interrupt-synchronised poll, not game logic; the native
  port models it as a frame-sync boundary (Phase 2), not as a ported loop.
* Excluding that loop and the rts/nop stub chain at `0x8c0597ae..0x8c0597cc`
  (14% of hits, 8 empty callback slots), the *real work* in a fight is
  ~46% ported baseline code and ~49% **uncatalogued** code.
* Boot/title (trace_boot3): 29% of unique entries / 46% of hits are
  uncatalogued as well - this is a baseline hole, not a fight-only quirk.

## What the uncatalogued code is

`gap_attrib.py` on fight+melee: ~800 gap runs, ~16.8 KB.

| verdict | runs | span B | hit share |
|---|---:|---:|---:|
| stub (rts/nop only) | 10 | 40 | 14.2% |
| new-entry (bsr target or table/literal pointer) | 189 | 5,462 | 15.5% |
| orphan-only (dynamic entry, no static predecessor) | 545 | 10,132 | 7.0% |
| extent of a baseline fn (reached by local branch) | 27 | 1,244 | 0.3% |

So these are mostly **independent functions the Ghidra seeding never named**,
not extensions of known bodies. Hottest:

| entry | span | role |
|---|---:|---|
| `0x8c0487a0` | 216 | FPU vertex-transform loop (`ftrv xmtrx`, `fdiv`, `pref`) - hottest real code (47M hits) |
| `0x8c048a30` | 298 | bsr-ladder dispatcher around `0x8c048c80/0x8c048cc0` |
| `0x8c073cbc` | 298 | float clamp/min-max kernel on `@(r0,r15)` frame locals |
| `0x8c048bc4/f60` | 94/212 | continuation of the 0x8c048xxx geometry cluster |
| `0x8c03c4a0` | 44 | helper reached from the (ported) 0x8c03c4f0 neighbour |

`extract/analysis/census/gap_runs.csv` is the work list; `funcs_extended.csv`
is the same set as extension-baseline rows (the frozen baseline CSV and all
proof snapshots are untouched).

## Consequences for the plan

1. The 72.88% figure is of the *frozen baseline*; against what a fight actually
   executes the ported share is roughly half. The ledger needs a second
   denominator ("executed-weighted") reported next to bytes.
2. Phase 1/2 priority is the gap list, not the 26 unported baseline owners:
   the 0x8c0487a0 geometry cluster alone carries more fight weight than every
   unported baseline owner except the wait loop.
3. Wait loop `0x8c059aea` and the rts-stub chain are excluded from "work".
