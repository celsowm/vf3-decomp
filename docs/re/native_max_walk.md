# native_max_walk (0x8C061910)

The four-list gated max walk, ported natively in `src/native/max_walk.c`
(`vf3_native_max_walk`) as a plain-C transcription of the readable port
`src/fight/readable/max_walk.c` (`vf3_max_walk_entry`).

## Why this leaf

The readable authority is a self-contained leaf (body 0x0C061910..0x0C061994,
136 B), **call-free and integer-only** - no FP, no gbr, no fipr.  That makes it
the cleanest kind of native target: there are no guest callees to inline and
no FPU round-toward-zero wrappers to worry about.  The native port is a direct
reflection of the readable logic (the same locals, the same walk order, the
same restored registers), merely routed through `vf3_native_aim`'s flat RAM
instead of the guest's ram map.

## The body

It reads the fight structure's address from the literal pool at `0x0c061a0c`,
searches four linked lists and writes two signed maxima out:

```
[r4] = r7  = max of (list A at struct+0x08, ungated)  over [node+16],
             then    (list B at struct+0x00, gated)    over [node+16]
[r5] = r14 = max of (list C at struct+0x1c, ungated)  over [node+16],
             then    (list D at struct+0x14, gated)    over [node+16]
```

A node is a 20-byte record: `u16 gate` at `+0`, `u32 next` at `+8`, `u32 value`
at `+16`.  A walk starts at a head field in the structure and steps a node via
its `next` word until null.  A "gated" list only lets a node's value compete
for the max when `(node.gate & 4) == 0`.  The two maxima start at 0 (`r14` is
zeroed on entry, and `r7` starts from that zeroed `r14`).

The guest's stack contract is part of what the harness compares: it pushes
`r14`, `r13`, `r12` (entry `r15` = SP0), allocates a 4-byte scratch slot at
SP0-16 that briefly holds `struct+0x14` on the way to list D, and pops
`r12`/`r13`/`r14` back at the tail, so `r15` is net back at SP0 and the three
saved registers are restored to their entry values.  The body leaves `r0 = 0`,
`r1` = the last gated node's value read, `r2` = the last node's gate halfword
(low 16 bits), `r6 = 0` (the walk's terminator), `r7` = the first max, and
`SR.T = 1` (the walk-exit test `(r6==0)` is the last comparison).

Details the native port keeps (unchanged from the readable authority):

* **`r7` starts from the zeroed `r14`, not the entry `r14`.**
* **Lists B and D are gated by `(node.gate & 4) == 0`; A and C are not.**
* **The gate halfword is sign-extended then masked to 16 bits** (`rd16`).
* **The comparisons are signed** (`cmp/gt`): a negative value never wins over
  0, and `0xfffffffe` loses to any positive one.
* **The scratch slot at SP0-16 is part of the captured RAM** - it holds
  `struct+0x14`; both sides write it, so the byte-for-byte stack comparison
  sees it.
* **The leftover `r1`/`r2`/`r6` are real outputs** and are written back.

## Evidence

The **differential** (`tests/max_walk_native_replay.c`, target
`vf3nativemaxwalk`) runs the native port against the readable guest port from
the same seed over six list layouts (four populated lists, gates hiding the
high values, negative values with open gates, all lists empty, only the gated
lists populated, and A empty with a longer C) and compares byte for byte the
pool, the fight structure, the node region, the stack and the two output
words, plus the contract registers and SR's T bit.  It also recomputes the two
maxima with an independent fixture walk and checks them against `[r4]`/`[r5]`.
**6/6 PASS.**  The **mutation gate** (`tests/max_walk_native_mutations.json`)
applies the same 16 mutations the readable gate does (both gated lists made
ungated, both gate tests inverted, list A made a min, list C accumulating into
`r7`, the two output words swapped, `r7` starting at 1, the struct/head offsets
off by 4, the walk stepping by value instead of next, the T bit left clear and
the restored registers/r15 wrong) and the differential catches **all 16**.

```
build\vf3nativemaxwalk.exe ->
  max_walk_native_replay: PASS
python tools/mutate.py --port src/native/max_walk.c --exe build/vf3nativemaxwalk.exe \
    --mutations tests/max_walk_native_mutations.json --target vf3nativemaxwalk
  16/16 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus
`advance_resume_061910_dev/advance_resume_061910_dev_8c061910/f_8c061910.cases`
at 512/512 (see docs/re/max_walk.md).

## Notes

* The scratch slot's value (`struct+0x14`) is the same on both sides because
  both compute it the same way - the two maxima are also cross-checked against
  the fixture, so a wrong scratch write that still matched the guest would not
  make the outcome test pass.
* `vf3_aim_h16` returns the little-endian halfword; `rd16` here mirrors the
  guest's `mov.w` (sign-extend) then `& 0xFFFF` masking.  The high-bit effects
  are masked away, exactly as in the readable authority.
