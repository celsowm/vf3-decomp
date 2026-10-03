# Phase 3 Calibration Status (Campaign D analysis output)

`tools/oracle/gate_scan.py` produces the gate/selector tables for the five
Phase 3 named closures. The masks below are straight off the disassembly
and **need calibration** before they are usable as seeds, per the
warning in `docs/re/entry_patch.md` lines 9–16 and 156–185.

The calibration constant problem stated there:

> The values that open a gate in the emulator are not the values the
> sh4dump disassembly prints. Measured on `0x8C0C321E`:
> `mov.w <lit> # lit.w=0300` opens as **`0x0030`**, not `0x0300`;
> `tst #10,r0` opens as **`0x0A00`** (which actually agrees with the
> encoded imm8, so the disasm is right but the runtime reads it
> byte-swapped); and `mov.w <lit>` (B gate) opens as **`0x0018`**
> (matches the disasm).
> Treat the values above as calibration constants to re-verify, not as
> a rule to apply to other functions.

So the masks below are disasm-side. Each function needs a single-variant
per-function patch plus a per-gate byte to verify the actual emulator
behavior before any seed plan can be trusted.

## `0x8C05B20E` — descriptor worker, 1322 B

`gate_scan_8c05b20e.txt` lists **19 flag-word gates** with masks
`0x0002, 0x0020, 0x0040, 0x0080, 0x0100, 0x0400, 0x0800, 0x2000,
0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x100000, 0x200000,
0x8000000, 0x10000000, 0x1fffffff, 0xfdffffff` plus **31 descriptor
offsets read through r13**: `0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x20,
0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c,
0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x90, 0xa0, 0xb4,
0xb8, 0xbc`. Each mask AND a descriptor offset pair opens a body PC.

`entry_patch.md` line 244–245: **9 bytes of `0x8C05B20E` are not
seed-reachable at all**. They sit behind `mov.l @(24,r4),r7` at
`0x8C05B63C` and require the dispatch table to compare equal to
`0x28000000` at `0x8C05B66E`. This is dispatch-table reconstruction,
not a seed-plan problem.

## `0x8C0C321E` — geometry byte-swapper, 1574 B

`gate_scan_8c0c321e.txt`: **0 gates** found by the naive scan. The
disassembly has a `mov.w lit.w=0300,r3` then `tst r3,r2` at
`0x8C0C322A–0x8C0C3232`; the `gate_scan.py` heuristic misses the
`mov.w` literal pool form for this target. **2 descriptor offsets**:
`0x08, 0x2c`.

Per-function calibration per `entry_patch.md` line 162–166:
- Gate A (descriptor+0x08): disasm `0x0300`, opens as `0x0030`
- Gate B (descriptor+0x2c): disasm `0x0018`, opens as `0x0018` (matches)
- Gate C (`tst #10,r0`): opens as `0x0A00` (matches the encoded imm8)

`body_cover` for the clean capture is currently 35.6 % (560/1574 B)
after the calibrated 1064-executed-PC sweep. Re-measurement would
target 100 % body cover.

## `0x8C09C1F4` — pose evaluator, 2084 B

`gate_scan_8c09c1f4.txt`: **3 gates** at `0x8C09C280, 0x8C09CA16,
0x8C09CA30` all using masks `0x0234, 0x0238`. **2 descriptor offsets**:
`0x234, 0x238` (register-loaded).

## `0x8C0C438E` — descriptor-dispatch, 1694 B

`gate_scan_8c0c438e.txt`: **0 gates** found. **6 descriptor offsets**:
`0x20, 0x24, 0x28, 0x2c` (literal displacement) plus `0x61, 0x98`
(register-loaded).

## `0x8C0A1658` — descriptor worker, 1176 B

`gate_scan_8c0a1658.txt`: **0 gates, 0 descriptor offsets** found by
the naive scan. The function body has gates/selectors that the
`gate_scan.py` heuristic misses; per-function disasm review is
required before any seed plan can be built.

## SCRATCH placeholder

`SCRATCH = 0x0C400000` (the constant used by `tools/oracle/seed_plan.py`)
is live game heap. Per `entry_patch.md` lines 187–197, this must be
re-chosen against the live state at game init. The selection criteria
recorded there: the page's first word must not be a live code pointer,
and the natural game loop must not write to it during a 1000-frame
test. The new constant is per (game init state, fight phase).

## What this analysis proves vs. what it doesn't

This output is the **planning artefact** for Campaign D's seed plan
construction. It does not generate byte credit. The gates and
descriptors above can be combined with `tools/oracle/seed_plan.py` to
produce an entry-patch, but only after per-function calibration
against a fresh capture confirms the actual mask bytes. Calibration
requires the flycast oracle to run, which requires ROM access and a
working emulator — neither of which can produce more than the
existing captures from this session.

## Files

```
extract/analysis/gate_scan_8c05b20e.txt  1053 B  771 insns / 19 gates / 31 offsets
extract/analysis/gate_scan_8c0c321e.txt   289 B  1570 insns /  0 gates /  2 offsets
extract/analysis/gate_scan_8c09c1f4.txt   381 B  2305 insns /  3 gates /  2 offsets
extract/analysis/gate_scan_8c0c438e.txt   311 B  2458 insns /  0 gates /  6 offsets
extract/analysis/gate_scan_8c0a1658.txt   279 B  1537 insns /  0 gates /  0 offsets
extract/analysis/tmp_8c05b20e.dis       771 insns disassembly
extract/analysis/tmp_8c0c321e.dis      1570 insns disassembly
extract/analysis/tmp_8c09c1f4.dis      2305 insns disassembly
extract/analysis/tmp_8c0c438e.dis      2458 insns disassembly
extract/analysis/tmp_8c0a1658.dis      1537 insns disassembly
```