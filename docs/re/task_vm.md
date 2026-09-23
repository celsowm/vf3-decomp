# Task VM — field schema (M19)

The fight engine works on a per-frame **task struct** at `r14` (probe-pinned
0x0CBEFBE0 during fight scenes; the same struct envelope is reused for menu /
attract scenes at other RAM addresses — the code is position-independent).

Static enumeration of `mov.[blw] @(disp,r14)` / stores across all
task-run/slot functions (tools/task_vm_map.py over 1ST_READ):
1,196 accesses, 26 used offsets.

## Field map (offsets → rd/wr histogram → hypothesis)

| off | rd | wr | role hypothesis |
|---|---|---|---|
| 0x00 | 1 | 7 | state tag written at subdued points (init only) |
| 0x04 | 23 | 20 | primary counter / frame stamp |
| 0x08 | 20 | 14 | scene slot pointer (work cursor) |
| 0x10 | 1 | 6 | task id (rd sparse, write at init) |
| 0x11 | 4 | 5 | u8 sub-slot index |
| 0x12 | 19 | 18 | strategy / mode flag word |
| 0x16 | 28 | 16 | module tick counter (hottest rd) |
| 0x20 | 17 | 14 | strategy enum A |
| 0x24 | 7 | 11 | strategy enum B |
| 0x28 | 8 | 13 | packed pair |
| 0x30 | 3 | 4 | timer (low count key on RD) |
| 0x32 | 12 | 23 | HIGH write rate — die-current instruction slot |
| 0x36 | 9 | 6 | u16 chain count |
| 0x40 | 6 | 13 | task back-pointer (written mostly) |
| 0x44 | 17 | 13 | callback/state hook |
| 0x48 | 18 | 18 | ring counter (hot loop) |
| 0x52 | 8 | 12 | packed per-part counter |
| 0x56 | 14 | 7 | stream tag byte |

Offsets ∈ {0x04, 0x16, 0x12, 0x48, 0x32, 0x08, 0x44, 0x20} dominate.
Layout sings a per-part stride (8 parts, as the byte streams show): offsets
0x16/0x1A/0x1C/0x24/0x28 …

## Known strong facts (trace-supported)
- `task_run_C` jsr-slot ids to call: `0x0C0E, 0x76AC, 0x0C0E, 0x76B8,
  0x0C0E, 0x76C4` (six; the 8-call tail writes default since reset).
- The walker/predicate (scene-0x0A gate) selects WHICH r14 chain is active,
  which is why attract vs fight scenes differ in effective task ids.
- r14 struct is position-independent (moveable by base assignment).

## Next probe
The wf-ranging probe (fight-vs-attract mem-watch around the resolved base)
will name each field via write-bursts. That was M19's original plan and is
now tracked as a future probe (savestate-first known target: `vf3.state`).
