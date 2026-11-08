# tenpp_fill (0x8C0C103C)

The tenpp leaf structure filler, ported readable in
`src/fight/readable/tenpp_fill.c` and registered as `tenpp_fill`.

## The body

A small self-contained leaf, 72 B (0x0C0C103C..0x0C0C1080), call-free, no
FPU, no stack frame.  `r4` is a node structure, `r5` an auxiliary cell.  It
fills the node with a fixed pattern and clears the cell:

* the word at `r5+20` is cleared;
* the five bytes at `r4+16..+20` are set to `0xff` (the widened byte `r5`
  ends up `0xffffffff`);
* the halfwords `r4+22, +24, +26, +28, +30` and `r4+32, +34, +36, +38, +40`
  are cleared;
* the words `r4+44, +48, +52, +56` are cleared, and `r4+60` is cleared in the
  tail jump's delay slot.

The scan leaves four registers behind as its products: `r0` holds the last
offset touched (0x28), `r3` the node + 16 (0x10), `r5` the widened `0xff`
value (-1), and `r6` the zero accumulator.  `r4` (the node), the stack
pointer and every other register, plus all of SR, are untouched.  The return
is a tail jump through r16 (the caller's return address), which the port
reproduces by handing control back to `R(16)`.

## Evidence

The **differential** (`tests/tenpp_fill_replay.c`) runs the three arms - the
generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` - over five node/cell pointer layouts
in a single 0x2000 window at 0x0c404000 (mirroring the captured corpus) with
every window byte patterned first, and compares the whole register file,
SR/T, the exit PC, the out-of-window counter and every RAM byte.  It also
checks the outcome against the fixture itself: the node's five `0xff` bytes,
the cleared halfwords/words, the cleared cell word, and the four output
registers.  **5/5 PASS.**  The **mutation gate**
(`tests/tenpp_fill_mutations.json`) applies 11 single-line mutations and
the differential catches all 11 - each wrong offset, wrong value, wrong
output register and the wrong return PC is visible.

The **oracle** leg closes directly: `tests/tenpp_fill_oracle.c`
(`vf3tenppfilloracle`) routes the readable port itself over the per-entry
`.cases` corpus `tenpp_arch_third_cases/f_8c0c103c.cases` and passes
**128/128 cases** (whole 37-register file, every byte of the single window,
the exit PC and the OOB counter):

```
build\vf3tenppfilloracle.exe ->
  tenpp_fill_oracle: 128/128 cases match (0 skipped) - PASS
```

The corpus' single window (0x0c404000, len 0x2000) carries both the node and
the cell as captured runtime state, and the leaf touches no device register
and no stack, so the oracle run needs no sidecars and no supplied pool -
exactly like `fdiv`.  The three-arm chain `readable == generated == oracle`
closes on all three legs: the generated translation replays the same corpus
(the ledger carries its `matrix_family: 128/128` row), and the readable port
replays that corpus itself.

## Notes

* Nothing here is FP or even bit-twiddling beyond the widened `0xff` byte, so
  unlike `fdiv` there is no FPSCR-width or T-bit subtlety: SR is untouched and
  the store widths are fixed integer widths.
* The store order is immaterial (all addresses are disjoint), so no mutation
  in the gate targets order.
* The entry is `ported-invocation` in the ledger, not `ported`: this readable
  port is the first source-level C for it.  It is **not** off-baseline
  (the inventory has it), so the 72 B are counted inside the baseline
  denominator, not added to the union.
