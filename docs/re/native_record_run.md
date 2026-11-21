# native record_run (0x8C0C1296)

`src/native/record_run.c` (`vf3_native_record_run`) is the plain-C port of the
readable `src/fight/misc_wrappers.c` (`vf3_record_run_entry`): 0x8C0C1296, the
record-run that zero-fills a spread of 120 consecutive 68-byte records and then
sets bit 0 of the record's +34 halfword.

## Why it is self-contained

The readable leaf's **one** callee - `mem_fill` (0x8C095604) - is already
natively ported (`src/native/mem_fill.c`).  It is therefore the same shape as
`format_int` (0x8C04AF04), `extent_list` (0x8C0CC432) and `quad_node`
(0x8C068FE4): the guest call becomes a **direct native call** into that leaf,
and the port stays self-contained on `vf3nativeview` with no runtime
dependency on the readable/guest modules.  Like `extent_list`, the native
`record_run` sets `R(15) = frame` and `a->pr` (the guest ret, in the 0x0C
form) to match what the readable `CALL` gives mem_fill, then hands control to
`vf3_native_mem_fill`.

## What it is

```
r4 -> a record:
    +12   word: the base of the 120 records (mem_fill's r4)
    +34   halfword: bit 0 is OR-ed in at the end
```

`record_run` walks `RECORDS = 120` consecutive `RECORD_BYTES = 68` byte
records, calling `mem_fill(record, 0, 68)` on each (r5 = 0 fill value, r6 =
68 byte count), stepping the base by 68 per iteration.  It is a `do/while`
loop over `R(13)` (counted 0..120 against `R(12) = 120`), so the final `SR.T`
is the last `cmp/ge` (true).  After the loop it reads the original `r4` back
out of its frame slot, and
`[orig_r4 + 34] = sign-extended([orig_r4+34]) | 1` (r0 = 34, r2 = 1), that is
bit 0 is set in the halfword.

The register contract (matching the observable `B(0..7)|B(17)|B(53)|B(21..52)`
mask): the low 8 registers come out of the last mem_fill and the OR loop -
r0 = 34, r1 = sign-extended halfword | 1, r2 = 1, r3 = orig r4, r4 = mem_fill's
word count (`17` for a 68-byte record), r5 = 0, r6 = 68, r7 = the last record's
end pointer; r8..r10 and FPUL/FR/XF pass through untouched (the function never
touches them); r11..r14 are restored from the saved words, r15 = sp0, pr is
restored, and SR's T bit is set.

## What must be kept

- **The frame and the saved words are visible in RAM.**  The four saved
  registers (r14, r13, r12, r11) at `sp0-4..-16`, the saved pr at `sp0-20`,
  and the frame's copy of the original `r4` at `sp0-24` are all written back
  byte for byte.  mem_fill's own four dead words land under the loop's frame
  (`R(15) = f` during the calls), and the differential compares them too.
- **`R(15) = f` before each mem_fill call**, and `a->pr = 0x0C0C12B6` (the
  readable `CALL` gives the callee its return address in the 0x0C form), so
  mem_fill sees the same frame and pr the guest path records.
- **The fill is mem_fill, not `memset`.**  On the guest side the `CALL`
  dispatches to the readable `vf3_mem_fill_entry` (registered in
  `readable.c`); natively it is the byte-exact `vf3_native_mem_fill`, which
  leaves its own r0/r4/r6/r7 and dead words that the registers above depend
  on.
- **The final `[r4+34]` write is sign-extend | 1.**  The halfword is read as
  a signed 16-bit and OR-ed with 1 (r2 = 1), then stored back as a u16.

## How it is proved

`tests/record_run_native_replay.c` (`vf3nativerecordrun`) runs the leaf on
both sides from the same seed - a record whose `[r4+12]` is the base of 120
records pre-filled with a per-case pattern, a distinctive `[r4+34]` halfword,
a junk register file and a patterned stack.  Five scenarios cover hw34 with
bit 0 clear/already set/high, zero and even, and fills from a counting pattern
to 0xff.  After the run every register (r0..r15, pr, sr), the FR bank, FPUL
and the record+stack RAM are compared against the guest, and an independent
fixture model checks that all 120 records are zeroed and that bit 0 of
`[r4+34]` is set.  The `tests/record_run_native_mutations.json` gate (`8/8`
caught, via `tools/mutate.py --keep-going`) breaks the record count, the fill
value, the byte count, the record base, the stride, the +34 offset, the OR
(→ AND) and the bit (1 → 2); every one changes an observable register or RAM
byte and fails the differential.
