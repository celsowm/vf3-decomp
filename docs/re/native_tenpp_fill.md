# native_tenpp_fill (0x8C0C103C)

The tenpp leaf structure filler, ported natively in `src/native/tenpp_fill.c`
(`vf3_native_tenpp_fill`) as a plain-C transcription of the readable port
`src/fight/readable/tenpp_fill.c` (`vf3_tenpp_fill_entry`).

## Why this leaf

The readable authority is a self-contained 72 B leaf
(0x0C0C103C..0x0C0C1080), **call-free, no FPU, no stack frame** - the cleanest
kind of native target (no guest callees to inline, no FPU round-toward-zero
wrappers, no saved registers).

## The body

`r4` is a node structure, `r5` an auxiliary cell.  It fills the node with a
fixed pattern and clears the cell:

* the word at `r5+20` is cleared;
* the five bytes at `r4+16..+20` are set to `0xff` (the widened byte `r5`
  ends up `0xffffffff`);
* the halfwords `r4+22, +24, +26, +28, +30` and `r4+32, +34, +36, +38, +40`
  are cleared;
* the words `r4+44, +48, +52, +56` are cleared, and `r4+60` is cleared in the
  tail jump's delay slot.

The scan leaves four registers behind as its products: `r0` holds the last
offset touched (0x28), `r3` the node + 16 (0x10), `r5` the widened `0xff`
value (-1), and `r6` the zero accumulator.  `r4` (the node), the stack pointer
and every other register, plus all of SR, are untouched.  The return is a tail
jump through r16 (the caller's return address).

## Evidence

The **differential** (`tests/tenpp_fill_native_replay.c`, target
`vf3nativetenppfill`) runs the native port against the readable guest port
from the same seed over the same five node/cell pointer layouts as the
readable test (the corpus' own node, node before cell, node shifted up, cell
inside the node region, and large offsets).  It lays the 0x2000 window (node +
cell) into one flat window, patterns every byte, runs both sides, and compares
the whole RAM region byte for byte plus the output registers (r0, r3, r5, r6)
and the untouched ones (r4, r15).  It also checks the outcome against the
fixture itself (the five `0xff` bytes, the cleared halfwords and words, and
the cleared cell word).  **5/5 PASS.**

The **mutation gate** (`tests/tenpp_fill_native_mutations.json`) applies 10
single-site mutations - the readable gate's list minus its guest-PC-specific
`the_return_is_four_bytes_past`, which does not apply to the native port
(whose return is implicit): the cell offset +24, the zero accumulator 1, the
first/last node byte offsets, the first byte value 0xfe, the last cleared
halfword +0x26, the tail word +56, `r3 = r4+20`, `r5` narrowed to 0xff, and
`r0 = 0x27`.  The differential catches **all 10**.

```
build\vf3nativetenppfill.exe ->
  tenpp_fill_native_replay: PASS
python tools/mutate.py --port src/native/tenpp_fill.c --exe build/vf3nativetenppfill.exe \
    --mutations tests/tenpp_fill_native_mutations.json --target vf3nativetenppfill
  10/10 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus `tenpp_arch_third_cases/f_8c0c103c.cases` at
128/128 (see docs/re/tenpp_fill.md).

## Notes

* The differential's outcome check reads the cleared halfwords with a **16-bit
  read**, not a 32-bit one: the pattern byte immediately past a cleared `u16`
  keeps its pattern value, so a 32-bit check falsely reports "not cleared".
* The store order is immaterial (all addresses are disjoint), so no mutation
  in the gate targets order.
